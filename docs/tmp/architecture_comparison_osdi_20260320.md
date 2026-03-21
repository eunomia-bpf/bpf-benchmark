# BpfReJIT 架构比较与 OSDI 影响分析

日期：2026-03-20

## Executive Summary

结论先行：

1. **如果目标是当前这条 OSDI 论文线，不建议整体转向新架构。**
2. **最合理的选择是 C：混合方案。**
3. 这个混合方案的核心不是“把当前 re-JIT substrate 推倒重来”，而是：
   - 保留当前 **post-load backend re-JIT** 作为论文主机制；
   - 吸收新方案里真正有价值的部分：**live enumerate、runtime PGO daemon、以及 verifier-owned 轻量事实/annotation**；
   - **不要**把主线改成 `kinsn + live bytecode rewrite + full re-verify/reload`。

如果只允许在 A/B 两个纯选项里二选一，我建议 **B：保持当前架构**。

原因很直接：

- 当前架构与 K2/Merlin/EPSO 的差异最干净：**它是 backend-only、post-load、与 bytecode optimizer 正交**。
- 新架构虽然更“平台化”，但会把系统从 “backend lowering substrate” 变成 “live BPF rewriting framework”，从而**更直接地落入 K2/Merlin/EPSO 的比较面**。
- 新架构的安全故事并没有想象中那么“免费”：`kinsn verify callback` 本质上仍然是 **新的、每指令的 validator logic**，只是从 `jit_validators.c` 搬到了 verifier extension / kmodule。
- 延迟上，新架构很可能把当前 `~29.89us` 的 kernel recompile 路径，变成 **毫秒到几十毫秒** 的 full verify+JIT+replace 路径。
- 最关键的是：**时间线已经不支持大 pivot**。截至 **2026-03-20**，USENIX OSDI '26 的完整论文提交截止时间是 **2025-12-11**，通知时间是 **2026-03-26**，终稿截止 **2026-06-09**，而且 CFP 明确 **没有 author response period**。现在讨论整体换架构，意义只会是为条件接收修改或下一轮 venue 做准备，不是“赶上 OSDI '26 deadline”。

## 0. 时间线纠正

这点需要先说清楚：

- OSDI '26 abstract registration deadline: **2025-12-04 5:59 pm EST**
- OSDI '26 full paper submission deadline: **2025-12-11 5:59 pm EST**
- OSDI '26 notification: **2026-03-26**
- OSDI '26 final papers due: **2026-06-09**
- OSDI '26 CFP 明确写了：**removes the author response period**

所以，以 **2026-03-20** 的时间点看：

- **“能否在 OSDI deadline 前做完新架构”这个问题，答案已经不是工程问题，而是日历问题：不能。**
- 现在的架构决策只会影响：
  - 若论文条件接收，是否还能在 **2026-06-09** 前做可控的修改；
  - 或者这篇工作在 OSDI '26 之后的 revision / resubmission 路线。

## 1. 与已有工作的详细对比

### 1.1 高层 taxonomy

| 系统 | 优化层 | 何时发生 | 是否 live/post-load | 安全/正确性主门槛 | 能否直接打 backend-only gap | 是否需内核新机制 |
|---|---|---|---|---|---|---|
| K2 (SIGCOMM'21) | BPF bytecode | pre-load / offline | 否 | SMT 等价性 + safety analysis + kernel checker fail-safe | 否 | 否 |
| Merlin (ASPLOS'24) | LLVM IR + BPF bytecode | pre-verification | 否 | 编译器变换正确性 + kernel verifier | 否 | 否 |
| EPSO (ASE'25 / arXiv'25) | BPF bytecode | rule discovery offline, application pre-load | 否 | rewrite rule correctness + kernel verifier | 否 | 否 |
| 当前 BpfReJIT | native backend lowering | post-load, same xlated program | 是 | kernel-owned validator + kernel-owned emitter | **是** | **是** |
| 新提案 | extended BPF ISA (`kinsn`) + bytecode rewrite | post-load, live rewrite + reload | 是 | verifier + `kinsn` verify callback + JIT emit callback | **间接地是** | **是，而且更深** |

### 1.2 K2：与新方案的相同点与根本差异

相同点：

- 两者都在 **BPF 语义层** 表达优化，而不是直接上传 native code。
- 两者都让最终程序走 kernel checker / verifier 这条标准加载路径。

差异：

1. **K2 是 base BPF ISA 内的等价程序搜索；新方案是扩展 ISA 后的程序重写。**
   - K2 从 clang 生成的 BPF bytecode 出发，搜索一个 **在原 BPF ISA 内** 更好、且等价的程序。
   - 新方案是把程序改写成含 `kinsn` 的新 bytecode。换句话说，**它不是在原语言中找更优程序，而是在引入新语言构件后重写程序**。

2. **K2 的强点是等价性；新方案的强点是 live adaptation。**
   - K2 的论文卖点之一是 **formal correctness / equivalence-checking**。
   - 新方案若只说“kernel verifier 保证安全”，并**不能**替代 K2 的“等价性保证”。
   - verifier 证明的是安全属性，不是“与原程序语义等价”。因此：
     - **K2 的 SMT 是 semantic equivalence oracle**
     - **新方案里的 verifier 只是 safety oracle**

3. **K2 是 pre-load；新方案是 post-load live。**
   - 这是新方案对 K2 最强、也最可信的差异。
   - 如果你要把新方案和 K2 对比，真正应强调的是：
     - K2 优化的是“待加载程序”
     - 新方案优化的是“已经 attach、已经在跑的 live program”

4. **K2 不需要内核扩展语言；新方案需要。**
   - K2 是 userspace compiler。
   - 新方案需要：
     - `kinsn` core
     - 每个优化对应 kmodule
     - verifier/JIT 对新 instruction 的理解

我的判断：

- 相对 K2，新方案最强的差异是 **post-load adaptation**。
- 但“我们不用 SMT，我们用 verifier”这个表述不够准确，甚至容易被 reviewer 打回来，因为它混淆了 **semantic equivalence** 和 **memory-safety validation**。

### 1.3 Merlin：新方案会从“正交”变成“直接竞争”

Merlin 的关键信息是：

- 它做 **custom LLVM passes + bytecode rewriting**
- 优化发生在 **before eBPF verification**
- 它明确定位在 **IR transformation + bytecode refinement**

与当前架构相比：

- 当前 BpfReJIT 是 backend-only，因此与 Merlin **正交**：
  - Merlin 改“BPF 长什么样”
  - 当前 BpfReJIT 改“同一份 BPF 最后怎样被 lowering 成 native”

与新架构相比：

- 新架构把自己移到了 **BPF semantic layer**。
- 于是 reviewer 会自然地问：
  - 为什么 Merlin 不能加一个 live daemon 周期性重编？
  - 为什么不能做 “Merlin/EPSO 优化后的程序 + `bpf_link` update”？

也就是说：

- **当前架构对 Merlin 的差异是 layer difference，容易 defend**
- **新架构对 Merlin 的差异会变成 timing difference（pre-load vs post-load），更弱**

这不是说 timing difference 不 novel，而是：

- 单独靠 “live” 这个点，系统区分度不如当前 “backend-only” 那么硬。

### 1.4 EPSO：新方案最容易被 reviewer 说成 “online EPSO + custom ISA”

EPSO 的核心点是：

- **offline superoptimization discover rules**
- **cache/reuse rules**
- 在应用阶段以较低额外开销做 bytecode optimization

与新方案的关系：

- EPSO 已经部分占据了“高质量 bytecode rewrite + better scalability than K2”这条线。
- 新方案若转到 `kinsn + bytecode rewrite`，它会非常像：
  - **live EPSO**
  - **plus a kernel-supported extended ISA**

这当然仍然可能是论文点，但 reviewer 的第一反应很可能是：

- “你不是 backend-only 了”
- “你是在做 post-load bytecode optimizer”
- “那你和 EPSO 的核心差异，除了 live 和 custom ISA，还有什么？”

能答上的强点有两个：

1. **live workload adaptation**
2. **optimization deployment as kmodule, not monolithic compiler release**

但这两个点都没有当前架构的 “backend-only gap recovery” 那么干净。

### 1.5 kfunc：是可信先例，但不是强 novelty

`kfunc` 对新提案的意义更像 **feasibility precedent**，不是 **paper novelty**。

支持点：

- kfunc 已经证明：BPF 生态接受 **kernel-owned typed extension points**。
- kfunc 也说明：verifier 可以对扩展入口做 program-type gating、trusted-arg checks、BTF-based typing。

但你不能把 “kinsn 像 kfunc” 直接当 novelty：

- kfunc 扩展的是 **callable function surface**
- kinsn 扩展的是 **BPF abstract machine / instruction set**

这两者的复杂度和风险不是一个量级：

- kfunc 不改变 BPF ISA
- kinsn 会改变 verifier/JIT 需要理解的指令语义空间

因此：

- `kfunc` 是 **接受度论据**
- 不是 **创新主张本身**

### 1.6 bpf_struct_ops：能证明 extensibility pattern 合理，但也会弱化机制 novelty

`bpf_struct_ops` 的价值在于：

- 内核已经接受 “kernel defines interface, BPF/user space supplies policy/implementation” 这一模式。
- 这对你们的 “optimization owner 不应是 kernel maintainer” 的叙事有帮助。

但它同样说明：

- **extension hook** 这件事本身在 BPF 里已经不是新鲜事。

所以它带来的效果是：

- **提高新架构的可信度**
- **降低新架构机制层 novelty**

### 1.7 Cilium 热替换/再生成：是工程先例，不是论文 novelty

两个事实要分开：

1. **production BPF 系统已经会做 program regeneration / replacement**
2. `bpf_link__update_program()` 明确支持把 link 关联的程序换成新程序，以避免 detach/re-attach 之间漏事件

这说明：

- “热替换 live BPF program” 作为工程机制是可信的
- 但 **它本身不能当成论文主要创新点**

因此新方案若写：

> “我们支持原子热替换”

这个表述只能是机制说明，不能是主贡献。

真正可以 claim 的只能是：

- **对 already-running live programs 做 workload-aware optimization**
- 而不是：
- **发明了热替换**

## 2. OSDI 论文故事分析

### 2.1 当前架构的故事很“直”

当前故事链条非常一致：

1. motivation: **kernel JIT backend 保守，存在 backend-only gap**
2. system: **在 backend lowering 这一层做 post-load re-JIT**
3. safety: **有限 canonical forms + kernel validator + kernel emitter**
4. evaluation: **gap recovery / policy sensitivity / live deployment**

优点：

- 问题层和解法层完全一致
- 与 K2/Merlin/EPSO 的差异简单
- 当前已有 characterization 和 micro/E2E 数据都能直接服务这个故事

缺点：

- custom validator TCB 较重
- kernel LOC 大
- “新增 form 需要 kernel 改动” 会被问 upstreamability

### 2.2 新架构的故事更“大”，但也更散

新故事会变成：

1. kernel JIT instruction selection 太保守
2. compile-time bytecode optimizer 无法做 post-load adaptation
3. 所以我们做一个 **live BPF rewriting framework**
4. 它有：
   - `kinsn` extensible ISA hook
   - privileged daemon
   - verifier-mediated safety
   - `bpf_link`-based hot replace

这个故事的优点：

- 更平台化
- 更容易讲 runtime PGO / hardening / deployability
- “新优化零 kernel 改动” 很吸引人

但它的问题也更明显：

1. **问题层与解法层不再同层。**
   - motivation 是 backend conservatism
   - solution 却是 semantic-layer rewrite + extended ISA

2. **更像框架 paper，而不是问题驱动的 backend systems paper。**
   - reviewer 容易问：为什么不直接做更强的 compiler / superoptimizer？

3. **容易 story creep。**
   - optimization
   - runtime PGO
   - security hardening
   - hot swap
   - multi-arch deployment
   - kernel ISA extensibility
   这六件事放在一篇 paper 里，很容易显得 thesis 不够收敛。

### 2.3 新故事最强的版本应该怎么改写

如果未来真的要走新架构，这个故事不能继续写成：

> “kernel JIT instruction selection 太保守，所以我们做 kinsn”

更强的写法会是：

> “BPF 缺少一个面向 live programs 的安全优化 substrate。已有工作只在 pre-load 阶段优化 bytecode/IR，无法在部署后根据 workload 和 attach context 重写并替换程序。我们提出 verifier-mediated live BPF transformation framework。”

也就是说：

- 新架构若要成文，题目应该从 **backend gap paper**
- 转成 **live BPF transformation / deployment framework paper**

这已经不是同一篇 OSDI story 了。

## 3. Novelty 分析

### 3.1 真正 novel 的点

就新架构本身而言，真正可能站得住的 novel 点只有三个：

1. **post-load live rewriting of already-attached BPF programs**
2. **workload-aware runtime adaptation loop**
3. **optimization deployment as loadable kernel extension rather than monolithic mainline JIT patch**

这三个里，最强的是第 1 个。

### 3.2 不够强或不应主卖的点

#### `kinsn` 像 kfunc

这是个 **natural extension**，不是强 novelty。

- reviewer 很容易理解，也意味着容易接受
- 但也意味着它更像“工程上的自然下一步”

#### `optimization as kmodule`

这是很好的 deployment story，但更像：

- operational advantage
- engineering modularity

除非你能证明：

- 模块化带来了此前做不到的跨 workload / cross-arch rollout
- 并且有非常强的真实系统结果

否则单独当 novelty 不够硬。

#### “Kernel verifier as safety oracle”

这个 framing 有潜力，但必须精确收缩。

更准确的说法是：

- **existing verifier infrastructure mediates safety of live transformed programs**

不准确、也不该写的说法是：

- **20 年 verifier 直接保证了第三方优化是安全且语义等价**

原因：

1. verifier 不是 equivalence checker
2. `kinsn verify callback` 和 `emit callback` 自己就是新 TCB
3. 因此安全模型不是 “零新增 validator code”，而是：
   - **把 validator logic 分散到 per-insn verifier extension**

### 3.3 这点需要特别澄清：新方案不是“零 validator”

你给的新方案描述里，最需要修正的一句是：

> “Kernel verifier 验证重写后的程序（零新 validator 代码）”

这句话从 systems/PL 角度是不成立的。

因为：

- 一旦有 `kinsn`
- verifier 必须知道这种 instruction 的：
  - type effect
  - pointer effect
  - memory access legality
  - side effects
  - return-state transfer

而这些逻辑恰恰就是 **validator logic**。

所以更准确的比较应该是：

| 说法 | 评价 |
|---|---|
| 当前方案：独立 `jit_validators.c` | 准确 |
| 新方案：零 validator | **不准确** |
| 新方案：validator logic 变成 verifier-integrated per-insn callbacks | **准确** |

这个修正非常重要，因为它直接影响 novelty 判断：

- 如果你真能做到“零新 validator”，那是巨大优势
- 但现实里你只是把 validator 从 **site validator**
- 换成 **instruction semantics validator**

这不是零，而是 **重新分布**

## 4. 风险分析

### 4.1 最大风险不是“能不能写出来”，而是“会不会把论文换赛道”

新架构最大的风险不是代码量，而是：

- 你会从一篇 **backend systems paper**
- 变成一篇 **live BPF transformation framework paper**

这意味着：

- prior work 版图变了
- 评估问题变了
- safety story 变了
- 当前 characterization 与 solution 的闭环也变弱了

### 4.2 实现复杂度：表面看 kernel 变少，实际系统工作量会变多

新方案的“`~200 LOC core + kmodule`”只统计了 **core kernel diff**，没有统计：

- kinsn verifier integration
- 每个优化的 verify callback
- 每个优化的 JIT emit callback
- userspace live rewriter
- program extraction / reconstruction
- link replacement coverage
- rollback / failure handling
- attach-type compatibility
- correctness testing

按 total system effort 看，我的判断是：

- **它不是“小修小改换个接口”**
- **而是一条新的系统实现线**

### 4.3 verifier 拒绝关键优化时，新架构不会自动更好

以 `WIDE_MEM` 为例，新架构会遇到三种可能：

1. **verifier 能证明 widened access 合法**
   - 这是最佳情况
   - 但很多时候未必能直接证明

2. **verifier 不能证明**
   - 那就要在 rewritten program 里显式加 bounds check
   - 这会侵蚀性能收益

3. **通过 `kinsn` verify callback 自定义说明其合法性**
   - 这又回到了“你写新的 verifier semantics”
   - 并不是真正省掉了安全证明工作

所以如果 verifier 拒绝关键优化：

- 新架构的 fallback 不是“verifier 自动搞定”
- 而是：
  - 加显式 guard
  - 或者把该优化降回当前 backend-only 机制
  - 或者承认这个优化仍然需要 custom semantics logic

### 4.4 upstream 接受度：`kinsn` 比 kfunc 难得多

我对 upstream 接受度的判断是：

- **kfunc / struct_ops 风格的 typed extension：中等可接受**
- **module-defined BPF instructions：低到中等**

原因：

- kfunc 扩的是 interface
- `kinsn` 扩的是 VM/ISA

这会碰到更多核心顾虑：

- verifier/JIT contract
- portability
- tooling
- debugability
- BPF language boundary
- module unload / ABI lifetime

也就是说：

- 把 kfunc 当先例是对的
- 但把它当“因此 kinsn 容易 upstream”是不对的

### 4.5 沉没成本：不仅是代码沉没，更是证据链沉没

当前已有的不是单纯 `~6400 LOC` 代码，而是一整条证据链：

- characterization
- safety model
- 30us recompile latency
- micro/E2E data
- selftests
- arm64 bring-up

如果整体转向新架构：

- 不是“代码白费一半”
- 而是：
  - **大部分 paper evidence 需要重新对齐**
  - **很多实验要重跑**
  - **比较对象会换**

这个代价远大于 LOC 本身。

### 4.6 还有一个实际的工程风险：`bpf_link` 覆盖面

新方案默认的热替换路径是：

- rewritten program
- `BPF_PROG_LOAD`
- `BPF_LINK_UPDATE`

但现实里：

- 并非所有 live BPF attachment 都天然是 link-backed
- 一些老 attach path / loader path 仍然不是统一的 `bpf_link` 模型

当前架构的优势是：

- 它直接对 **已加载、已 attach 的 program image** 做 in-place re-JIT
- 不需要依赖 attach-path 全面标准化

因此新架构在系统覆盖面上不一定比当前更强。

## 5. 两种架构的定量对比

### 5.1 结构性比较

| 指标 | 当前架构 | 新架构 | 我对 paper 的解读 |
|---|---|---|---|
| Core kernel 代码量 | `~6400 LOC` | `~200 LOC core + kmodules` | 新架构在 **核心内核 diff** 上好看，但 **总系统复杂度** 未必更低 |
| Per-form kernel 成本 | `~200-500 LOC` | `~30-50 LOC` verify/emit callback | 对 deployment 很有吸引力，但别把 userspace rewrite 逻辑漏算 |
| 安全验证位置 | 独立 validator | verifier + per-insn callback | 不是“零 validator”，而是 **分布式 validator** |
| Arch 扩展 | 改 `bpf_jit_comp.c` | 换 kmodule | 新架构更像 plugin model，这是它最好的工程点之一 |
| 优化表达能力 | backend-only | semantic-layer rewrite + ext-ISA | 新架构更强，但也因此更接近 Merlin/EPSO 版图 |
| Runtime PGO | 可以做 | 可以做 | **不是新架构独占能力**；当前架构也可以 live profile 后 re-JIT |
| 安全加固 | 基本不做 | 可以加 guards | 这是新架构的新增表达力，但会稀释“优化 paper”焦点 |

### 5.2 延迟：这是当前架构对新架构最硬的优势

当前实测：

- scanner latency median: **4.32 ms**
- kernel recompile syscall latency median: **29.89 us**
- scanner/syscall ratio: **207.8x**

这意味着：

- 当前架构下，控制面瓶颈几乎完全在 userspace scanner/policy side
- kernel data-plane replacement 开销非常小

而新架构若走：

- live read program
- bytecode rewrite
- `BPF_PROG_LOAD` full verify+JIT
- `BPF_LINK_UPDATE`

则它的延迟下界更接近现有 `object_load_ns` / `compile_ns`：

对当前微基准里 **实际 applied 的程序**，现有 load path 已测到：

- `object_load_ns` median: **2.57 ms**
- `compile_ns` median: **5.48 ms**

对当前 real-program corpus：

- all measured programs `object_load_ns` median: **43.54 ms**
- applied programs `object_load_ns` median: **60.48 ms**
- all measured programs `compile_ns` median: **57.51 ms**
- applied programs `compile_ns` median: **86.72 ms**

因此，对新架构的 recompile 延迟，最合理的量级估计不是 `~?ms`，而是：

- **small/live micro-like programs: 至少数毫秒**
- **real programs: 常见为几十毫秒，重一些可到上百毫秒**

这是基于你们现有 `BPF_PROG_LOAD` 路径测量的推断，不是拍脑袋。

### 5.3 这个延迟差异对论文是正面还是负面？

我的判断是：**默认是负面，只有在特定 framing 下才勉强中性。**

负面的原因：

1. 当前方案已经证明可以对 live program 做 post-load re-JIT，且 kernel-side 只要 **29.89us**
2. 新方案会把这个优势回退成 **ms / 10ms / 100ms** 级控制面操作
3. reviewer 会自然问：
   - 既然已有更快的 live adaptation substrate，为什么要换成更慢的？

只有在下面这个条件下，它才可能不是明显负面：

- 你能展示新架构做到了 **当前架构表达不了的优化**
- 且这些优化在长期运行中 **显著 amortize** 了几十毫秒的替换成本

否则这项差异不会帮 paper，反而会变成 tradeoff。

## 6. 明确建议

## 建议：**C. 混合方案**

### 6.1 推荐的混合方案长什么样

我建议的混合不是“当前一半、新方案一半”，而是：

1. **保留当前 backend re-JIT 架构作为论文主机制**
   - 这保留了你们最干净的差异化：
     - backend-only
     - post-load
     - same xlated program
     - ultra-low recompile latency

2. **立刻吸收新方案中的 control-plane 优点**
   - `live enumerate` 取代 offline object scan
   - daemon 做 runtime PGO / profile-aware policy
   - 更强调 workload-aware live policy，而不是静态 YAML

3. **往 verifier-owned 轻量 annotation / post-pass collector 方向演化**
   - 不是全面改成 `kinsn`
   - 而是：
     - 让 verifier 产出少量 durable facts / site metadata
     - 以此缩小当前 validator 体量
     - 强化安全故事

4. **若真要试新机制，只把 `kinsn` 限定成 future / narrow prototype**
   - 只做一个当前 substrate 明确做不到、但论文价值高的 case
   - 不要把整篇 paper 的主路径切过去

### 6.2 为什么不是 A：整体转向新架构

不建议 A 的核心理由：

- **时间上来不及**：对 OSDI '26 这篇线已经没有意义
- **故事会换赛道**：backend paper 变 live transformation framework
- **差异化会变弱**：从正交 prior work 变成直接竞争 prior work
- **安全论证并不免费**：`kinsn` 并没有消灭 validator，只是重分布
- **延迟会显著变差**
- **现有数据和实现沉没成本太大**

### 6.3 为什么不是纯 B：什么都不改

纯 B 也不是最优，因为新方案里确实有两点应该立即借过来：

1. **live program-first 的 control plane**
2. **更 verifier-centric 的 safety simplification方向**

这两点能提升当前 paper：

- 更强的 runtime policy story
- 更好的 safety/upstreamability narrative
- 不破坏当前 backend-only thesis

### 6.4 如果你必须对当前 paper 做一句最直接的决策

我的一句话建议是：

> **当前论文主线继续押当前架构；新架构不要作为主替代方案，只能作为 future direction 或者 very narrow side experiment。**

如果你要更硬一点：

> **对这条 OSDI 线，A 不该做；B 可以交；C 最优。**

## 7. 最终判断

### 7.1 新架构的真实价值

新架构不是坏想法。相反，它有很强的长期研究潜力：

- live post-load adaptation
- verifier-mediated deployment
- optimization modules
- hardening + optimization co-design

但它更像：

- **下一篇 paper**
- 或者 **当前系统的长期演化方向**

而不是当前这篇工作的替代实现。

### 7.2 当前这篇工作的最强版本

当前这篇 work 的最强版本仍然应该是：

- **backend-only**
- **post-load**
- **policy-sensitive**
- **fast re-JIT**
- **与 bytecode optimizers 正交**

然后再吸收：

- live enumerate
- runtime PGO daemon
- verifier facts / annotation

这样做，既不放弃已有 6400 LOC 和现有实验资产，也能把新方案里最有价值的思想收进来。

## Sources

本地文档：

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/2026-03-11/k2-merlin-epso-comparison.md`
- `docs/tmp/2026-03-12/recompile-overhead-measurement.md`
- `docs/tmp/verifier_extension_research_20260320.md`
- `docs/tmp/precompute_inject_research_20260320.md`
- `docs/tmp/pgo_policy_design_20260320.md`
- `corpus/results/corpus_authoritative_20260320.json`
- `micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json`

外部资料：

- K2 (SIGCOMM'21): <https://ar5iv.org/pdf/2103.00022>
- Merlin (ASPLOS'24): <https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf>
- EPSO (arXiv 2025 / ASE'25 line): <https://arxiv.org/abs/2511.15589>
- Linux kfunc docs: <https://docs.kernel.org/bpf/kfuncs.html>
- Linux sched_ext docs: <https://docs.kernel.org/6.14/scheduler/sched-ext.html>
- `BPF_PROG_TYPE_STRUCT_OPS` docs: <https://docs.ebpf.io/linux/program-type/BPF_PROG_TYPE_STRUCT_OPS/>
- `bpf_link__update_program()` docs: <https://docs.ebpf.io/ebpf-library/libbpf/userspace/bpf_link__update_program/>
- Cilium endpoint lifecycle docs: <https://docs.cilium.io/en/stable/security/policy/lifecycle/>
- OSDI '26 CFP: <https://www.usenix.org/conference/osdi26/call-for-papers>
