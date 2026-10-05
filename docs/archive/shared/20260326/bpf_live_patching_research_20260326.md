# BPF 程序漏洞热修复（Live Patching）深度调研

日期：2026-03-26  
作者视角：BpfReJIT / OSDI '26 论文调研  
调研口径：将“近 3 年”明确为 **2023-03-25 至 2026-03-25**，按 **NVD 公开日期** 统计，并结合 kernel stable 提交、官方 livepatch/kpatch 文档、Google 公开披露材料、Meta NetEdit 论文、以及 eBPF verifier 正确性论文进行人工分组。

## 1. 执行摘要

本文的核心结论有五点。

1. **问题真实且长期存在。** eBPF verifier 的安全边界一旦出错，危险并不只在“未来新的 load 会不会被接受”，而在于**已经通过错误 verifier 进入生产的 live BPF 程序**仍然继续运行。`CVE-2023-2163` 明确展示了这一点：错误的 path pruning 会把不安全路径标成安全，导致任意内核读写、LPE、容器逃逸。Google 的公开 advisory 时间线也很清楚：**2023-03-31 报告、2023-04-19 修复、2023-06-29 披露**，这期间生产系统若不能重启，只能带着已加载程序继续跑。[GHSA-j87x-j6mh-mv8v](https://github.com/google/security-research/security/advisories/GHSA-j87x-j6mh-mv8v) [NVD: CVE-2023-2163](https://nvd.nist.gov/vuln/detail/CVE-2023-2163)
2. **BpfReJIT 热修复的价值不是“修 verifier”，而是“硬化已加载字节码”。** 它不尝试在故障发生后重新证明旧程序是安全的，而是对匹配到的 live 程序插入更保守的运行时检查、null-guard、helper 参数净化、tail-call quarantine 等，使 exploit path 在字节码层面消失，然后再通过 `REJIT + re-verify` 提交新镜像。
3. **与 kernel livepatch 的关键区别是信任模型。** livepatch/kpatch 的官方文档反复强调：成功 build/livepatch module **不代表 patch 一定安全**，仍然需要人工逐 patch 分析；它修的是 kernel text，依赖 patch 作者和审核流程本身。[kpatch Patch Author Guide](https://github.com/dynup/kpatch/blob/master/doc/patch-author-guide.md) BpfReJIT 的研究亮点在于：**正确性在用户态，安全性仍然交给内核 verifier**。但这里必须加一条重要限定：**既然 verifier 本身有 bug，热补丁必须刻意避开该 bug 依赖的证明模式**，不能把“重新过一遍同一个有 bug 的 verifier”误当成万灵药。
4. **并非所有 verifier CVE 都适合 bytecode-level live patch。** 适合热缓解的，通常是“局部 contract bug”：缺少 nullability、helper write 权限、tail-call attach-kind、stale packet pointer、readonly map write 等。这类漏洞能被局部 guard/sanitization 模板覆盖。**不适合**的，多是 verifier 内部状态机、precision backtracking、OOB/UAF、warn-only、load-time crash 等 robustness 问题，它们影响 verifier 本身，不是已加载程序的局部 exploit gadget。
5. **当前仓库的用户态 daemon 已经具备相当强的控制面基础，但内核侧 live swap 仍需补齐 production 级安全语义。** 当前 `daemon/README.md`、`daemon/src/bpf.rs`、`daemon/src/commands.rs` 已支持 `enumerate/watch/serve/apply-all`、`BPF_PROG_REJIT`、verifier log 捕获、按 pass attribution 回滚；但 `docs/tmp/2026-03-11/rejit-rcu-safety-analysis.md` 也指出当前 REJIT kernel path 仍偏 POC，尚需更严格的 RCU retirement / metadata handoff / trampoline & kallsyms 一致性。

因此，从 OSDI 论文角度，最强的论证方式不是“BpfReJIT 可以完全替代 kernel 升级”，而是：

- **作为紧急缓解层**，在“不能立刻 reboot 或大规模滚动升级”的窗口内，自动识别并硬化已加载的危险 BPF 程序；
- **作为 verifier-backed mitigation**，比 kernel livepatch 更适合修 BPF 字节码层面的 verifier admission bug；
- **作为研究系统**，其 userspace control plane 已经有现实基础，但 kernel-side live replacement 仍需 productionize。

## 2. 问题场景与威胁模型

### 2.1 为什么 verifier CVE 会留下“活体风险”

eBPF 的安全边界在 load-time。程序一旦被 verifier 接受，它后续运行时默认被认为已经满足内核安全 contract。问题在于，当 verifier 的抽象解释、path pruning、nullability、helper/memory contract、callback/ref-state 推理有 bug 时，**危险程序会被当成安全程序缓存并长期运行**。

这与普通“用户态 JIT miscompile”不同。对 BPF 而言，verifier 的 bug 会直接破坏“哪些字节码被允许进入内核”的边界。Google 对 `CVE-2023-2163` 的 PoC 页面非常直接：branch pruning bug 可导致**arbitrary read/write in kernel memory, LPE, container escape**。[Google PoC](https://google.github.io/security-research/pocs/linux/cve-2023-2163/) [NVD: CVE-2023-2163](https://nvd.nist.gov/vuln/detail/CVE-2023-2163)

### 2.2 现有处置方式的缺口

生产处置通常只有三种：

1. **升级 kernel 并重启。**
2. **人工卸载/重启业务组件，尝试重载 BPF 程序。**
3. **临时禁用依赖 BPF 的功能。**

这些方式都不理想：

- 第一种对高可用环境代价最大；
- 第二种要求应用/agent 有可控的程序生命周期；
- 第三种往往是“杀功能”，不是补洞。

这正是 live patch 的切入点：**不改应用、不重启内核，只替换运行中的 BPF 程序镜像。**

### 2.3 BpfReJIT 热修复的正确威胁模型

这里必须把目标说清楚。BpfReJIT live patch 的对象是：

- 已经加载、正在运行的 BPF 程序；
- 漏洞可被映射到**局部字节码模式**或**有限控制流上下文**；
- 能用更保守的 bytecode rewrite 消除 exploit path；
- rewrite 后仍能通过 re-verify，并且不要求应用配合。

它**不是**：

- 通用“修 verifier”机制；
- 任何 verifier bug 都能自动修；
- 对运行中任意 BPF 程序保证零语义变化。

更准确地说，它提供的是两类热补丁：

- **透明硬化补丁**：语义基本不变，只在异常/攻击路径上新增检查。
- **保守缓解补丁**：在风险路径上 fail closed，例如直接 `return`、丢包、返回 `0/-EPERM`、取消 tail-call。

## 3. BpfReJIT 热修复方案

### 3.1 控制面流程

一个现实可行的 BpfReJIT live patch daemon 可以按如下流程工作：

1. 监控 CVE feed / vendor advisory / kernel stable fix。
2. 将 advisory 规范化成“漏洞签名 + 受影响 kernel 版本 + patch 模板”数据库。
3. 枚举 live BPF 程序，获取 `orig_prog_insns`、prog type、attach info、map IDs、BTF 依赖。
4. 运行漏洞 matcher，筛出受影响程序。
5. 生成补丁 bytecode。
6. 通过 `REJIT` 提交新镜像，并要求其通过 re-verify。
7. 记录 verifier log、patch provenance、失败回滚、运维告警。

当前仓库里已有三块现成基础：

- `daemon/README.md`：已支持 `enumerate`、`watch`、`serve`、`apply-all`；
- `daemon/src/bpf.rs`：已支持从 live kernel 取原始指令、调用 `BPF_PROG_REJIT`、抓 verifier log；
- `daemon/src/commands.rs`：已支持 pass attribution、verifier rejection 后禁用 pass 并重试。

因此，用户态控制面不是从零开始；真正新增的是**security hotpatch signature DB + mitigation pass family**。

### 3.2 一个更适合论文陈述的 trust model

这个方案的信任链应表述为：

- **不可信**：CVE feed parser、漏洞 matcher、patch synthesizer、userspace daemon。
- **可信**：内核 BPF verifier、内核最终替换机制、RCU/生命周期管理。

但要加上一个重要限制：

> verifier 出 bug 时，热补丁的安全性不能简单依赖“再跑一次相同 verifier”；补丁必须把程序改写到**不再依赖已知 buggy proof rule** 的形式。

例如：

- 针对 `PTR_MAYBE_NULL` 类 bug，补丁要显式插入 null-check；
- 针对 stale packet pointer 类 bug，补丁要在 helper/global subprog 调用后重新取 `data/data_end` 并重建 guard；
- 针对 tail-call attach-kind bypass，补丁要禁止或隔离危险 tail-call edge。

所以 re-verify 是**第二道门**，不是第一性原理。第一性原理仍然是：**补丁把 exploit gadget 从字节码里抹掉**。

### 3.3 daemon 侧 matcher 和 patch template 的数据模型

最实用的实现方式不是通用 synthesis，而是**按 CVE 建模板库**。建议每个漏洞签名记录：

```yaml
cve: CVE-2024-56702
window:
  published_after: 2024-12-28
  affected_kernel: "< fixed by distro backport map"
match:
  prog_type: raw_tracepoint
  pattern: "trusted raw_tp arg dereferenced without dominating null-check"
patch:
  template: ptr_maybe_null_guard
  safe_fallback: "return 0"
proof_shift:
  avoid_buggy_verifier_logic: true
  relies_on: ["explicit null guard", "simple branch", "direct return"]
```

这种设计有三个优点：

1. 与 CVE/advisory 的真实粒度一致；
2. 便于审计和 operator override；
3. 能把“安全证明重心”从复杂 verifier 状态转回显式 bytecode guard。

### 3.4 当前仓库对可行性的直接支撑

从仓库现状看，以下能力已经存在：

- 枚举 live 程序并取 `orig_prog_insns`；
- PassManager 架构、分析缓存、liveness/CFG 支撑；
- `BPF_PROG_REJIT` 调用与 verifier log 捕获；
- `watch` 模式；
- 失败 attribution 与回滚；
- kfunc/BTF fd 管理。

这意味着“漏洞热补丁 pass”完全可以作为一类特殊 pass 加入当前 daemon pipeline，而不必新造独立控制面。

## 4. 与 kernel livepatch 的对比

### 4.1 相同点

- 两者都服务于“**不重启修安全问题**”；
- 两者都需要运行中替换代码；
- 两者都需要处理并发执行与旧代码退役；
- 两者都属于 emergency mitigation / post-deployment repair。

### 4.2 关键不同点

| 维度 | kernel livepatch / kpatch | BpfReJIT live patch |
|---|---|---|
| 修补对象 | kernel text / C 函数 | 已加载 BPF program image |
| trust model | 主要信任 patch 作者、review、测试、运维流程 | 可把 userspace patcher 视为不可信，安全仍由 verifier 守门 |
| 安全验证 | 无通用机器验证；kpatch 官方明确要求“不要盲目应用 patch” | hot-patch bytecode 必须 re-verify |
| 一致性模型 | per-task consistency / function redirection / callback / stacktrace reliability | 更接近 per-program image replacement；需要 RCU/old image retirement，但不需要 livepatch 的 per-task function semantic switch |
| 数据语义变化 | kpatch 文档明确强调 data semantic / locking semantic 风险，需要人工分析 | BPF 补丁主要局限在字节码局部 guard/sanitization，更适合做 fail-closed mitigation |
| 能否直接修已加载 BPF 程序 | 不能 | 可以，这是其独特价值 |

官方/半官方文档对 livepatch 的限制其实非常适合拿来衬托 BpfReJIT：

- Linux 官方 livepatch 文档说明它本质是**运行中函数重定向**，并依赖一致性模型与可靠栈回溯。[Livepatch docs](https://docs.kernel.org/livepatch/livepatch.html) [Reliable stacktrace docs](https://docs.kernel.org/livepatch/reliable-stacktrace.html)
- kpatch patch author guide 更直接：**成功 build 并不意味着 patch 一定安全**，每个 patch 都必须由内核专家人工分析。[kpatch Patch Author Guide](https://github.com/dynup/kpatch/blob/master/doc/patch-author-guide.md)

这正好说明：

- livepatch 能解决“内核函数换版本”的问题；
- 但它没有 verifier，因此做不到“untrusted patch producer + trusted safety checker”。

### 4.3 livepatch 不能替代 BpfReJIT 的三个原因

1. **粒度错了。** verifier bug 的 exploit gadget 常常落在已加载的 BPF bytecode，而不是内核某个固定 C 函数。
2. **信任边界错了。** livepatch 不验证 patch 后的 kernel semantics；而 BPF 场景天然有 verifier 可复用。
3. **目标错了。** livepatch 目标是换 kernel implementation；BpfReJIT 目标是**把错误 admitted 的 BPF 程序重新硬化**。

## 5. 近三年 BPF verifier CVE 图谱

### 5.1 方法与筛选口径

我先用 NVD 2.0 API 在 `2023-03-25` 到 `2026-03-25` 时间窗内，以 `bpf` + `verifier` 关键词拉取候选，再人工剔除掉：

- 只是在 call trace 中出现 `verifier.c` 的普通 BPF/driver bug；
- 非 verifier 根因的 local storage / race / arch JIT bug；
- 与“已加载程序绕过安全检查”无关的纯噪声项。

按这个口径，最有价值的不是简单报“共多少个”，而是按三类来读：

1. **G1: 已加载程序安全相关，适合 live patch 分析；**
2. **G2: verifier robustness / load-time / diagnostics，通常不适合 live patch；**
3. **G3: NVD 候选中出现 verifier 关键词，但根因并不在 verifier。**

### 5.2 研究最相关的高风险条目

下表列出对“live BPF 热修复”最关键的一组高风险 CVE。

| CVE | 公开日期 | 根因摘要 | 影响 | bytecode-level 缓解可行性 |
|---|---:|---|---|---|
| [CVE-2023-2163](https://nvd.nist.gov/vuln/detail/CVE-2023-2163) | 2023-09-20 | incorrect verifier pruning | 任意内核 R/W、LPE、容器逃逸 | **部分可行**。只能覆盖可签名的 exploit bytecode 形态；模板是 branch canonicalization + 显式 guard |
| [CVE-2023-52452](https://nvd.nist.gov/vuln/detail/CVE-2023-52452) | 2024-02-22 | variable-offset stack depth 低估 / uninit stack slot | 栈越界读写 | **部分可行**。需围绕动态 stack access 插 guard，并强制走更保守 stack-growth |
| [CVE-2023-52676](https://nvd.nist.gov/vuln/detail/CVE-2023-52676) | 2024-05-17 | stack bounds 32-bit overflow | 栈 OOB | **部分可行**。可加 64-bit clamp / range guard，但模板要非常保守 |
| [CVE-2024-38566](https://nvd.nist.gov/vuln/detail/CVE-2024-38566) | 2024-06-19 | verifier 错误假设 `socket->sk` 非 NULL | kernel NULL deref / unsafe deref | **高可行**。null-check 模板最直接 |
| [CVE-2024-43910](https://nvd.nist.gov/vuln/detail/CVE-2024-43910) | 2024-08-26 | modified `CONST_PTR_TO_DYNPTR` 传入 global function | dynptr OOB | **高可行**。拒绝非零 reg_off / 重写为 stack temp |
| [CVE-2024-49861](https://nvd.nist.gov/vuln/detail/CVE-2024-49861) | 2024-10-21 | helper 可以写入只读 map | 绕过 `.rodata` / frozen map 只读约束 | **高可行**。把 helper 输出导向 stack temp，或直接 fail closed |
| [CVE-2024-50063](https://nvd.nist.gov/vuln/detail/CVE-2024-50063) | 2024-10-21 | 跨 hook tail-call 绕过 ctx/return 验证 | ctx access / return rule bypass | **部分可行**。可 quarantine 特定 tail-call edge，但可能改变行为 |
| [CVE-2024-50164](https://nvd.nist.gov/vuln/detail/CVE-2024-50164) | 2024-11-07 | `MEM_UNINIT` 语义重载导致写检查失效 | helper 写只读内存 | **高可行**。helper 参数净化模板可覆盖 |
| [CVE-2024-56702](https://nvd.nist.gov/vuln/detail/CVE-2024-56702) | 2024-12-28 | raw_tp 参数实际可为 NULL，verifier 当成 non-NULL | 删除空指针检查，导致 kernel crash | **高可行**。`PTR_MAYBE_NULL` guard 模板 |
| [CVE-2025-21852](https://nvd.nist.gov/vuln/detail/CVE-2025-21852) | 2025-03-12 | `trace_kfree_skb` 的 `rx_sk` 可为 NULL | raw_tp NPD | **高可行**。与上同一模板 |
| [CVE-2024-58098](https://nvd.nist.gov/vuln/detail/CVE-2024-58098) | 2025-05-05 | global function 中 `changes_pkt_data` 未传播 | stale packet pointer 被继续使用 | **高可行**。helper/subprog 后重新取 `data/data_end` 并重建 guard |
| [CVE-2024-58100](https://nvd.nist.gov/vuln/detail/CVE-2024-58100) | 2025-05-05 | extension program `changes_pkt_data` 属性未检查 | packet pointer invalidation bypass | **部分可行**。需要按 attach 关系隔离 extension / 强制 revalidation |
| [CVE-2022-49873](https://nvd.nist.gov/vuln/detail/CVE-2022-49873) | 2025-05-01 | `release_reference()` 后错误 reg type conversion | 内核指针泄漏 | **高可行**。release 后把寄存器显式清零/不可用化 |
| [CVE-2022-50650](https://nvd.nist.gov/vuln/detail/CVE-2022-50650) | 2025-12-09 | synchronous callback ref-state 管理不 sound | callback 多次执行导致 ref leak/UAF 风险 | **低到中**。局部模板难覆盖，通常需要更强语义知识 |

### 5.3 一个更实用的判断标准：哪些 bug 真适合 hot patch

适合 hot patch 的 verifier CVE，一般满足下列条件：

1. **root cause 可局部化**：危险发生在某段 BPF 指令附近，而不是 verifier 的全局状态机。
2. **存在保守 rewrite**：显式 null-check、bounds-check、helper 参数净化、tail-call 禁止、重新获取 packet root。
3. **re-verify 不再依赖同一 buggy proof rule**。
4. **fail-closed 仍可接受**：即使补丁轻微改变语义，也优先保命。

不适合的通常是：

1. verifier 自身 OOB/UAF/warn/crash；
2. precision backtracking / loop_entry / SCC bookkeeping 一类内部状态 bug；
3. 只影响 load-time 可用性或 false positive；
4. 需要全程序语义知识才能安全重写。

## 6. 哪些 CVE 可以通过 bytecode-level patch 缓解

### 6.1 可高把握缓解的类型

#### A. nullability / trusted-pointer 假设错误

代表：`CVE-2024-38566`、`CVE-2024-56702`、`CVE-2025-21852`、`CVE-2024-42151`。  
模板很统一：

- load pointer
- `if ptr == 0 goto safe_fallback`
- 再 dereference

这是最适合 BpfReJIT 的 hot patch 类型，因为：

- matcher 简单；
- rewrite 局部；
- 安全收益直接；
- 通过 re-verify 后不再依赖“verifier 误以为 non-NULL”的假设。

#### B. helper / map memory contract 错误

代表：`CVE-2024-49861`、`CVE-2024-50164`、`CVE-2022-49873`。  
模板通常是：

- helper 输出改写到 scratch stack；
- 对 size / alignment 做更保守的显式 guard；
- 对 release 后寄存器做 zero / poison；
- 必要时直接 suppress helper side effect。

这一类非常适合“保守缓解”叙事：补丁不一定完美保留原语义，但能**立即堵上写只读 map / 泄漏 pointer** 这类高风险路径。

#### C. packet-pointer invalidation 漏洞

代表：`CVE-2024-58098`、`CVE-2024-58100`。  
模板是：

- 在 helper/global function/extension return 之后，**重新读取** `ctx->data` / `data_end`；
- 重建新的 dominating bounds guard；
- 不再复用旧 packet pointer。

这类补丁和当前仓库中已有的 packet bounds 研究天然兼容，因为它依赖的就是 verifier 现有、最稳定的一类 direct packet access contract。

### 6.2 只能部分缓解的类型

#### D. tail-call / attach-kind / whole-chain compatibility

代表：`CVE-2024-50063`。  
可做的热缓解通常是：

- 禁掉危险 tail-call edge；
- 检查 attach hook cookie / program class；
- 在不兼容边上直接 return safe default。

问题是这类补丁可能更明显地改变行为。因此论文中更合适把它定位成**emergency mitigation**，而不是透明修复。

#### E. pruning / precision / state-copy bug，但 exploit gadget 仍局部

代表：`CVE-2023-2163`、`CVE-2023-52452`、`CVE-2023-52676`、`CVE-2024-43910`。  
这类漏洞不是完全不能 patch，而是要求补丁非常“反 verifier bug 形状”：

- 减少 verifier 需要做的抽象推理；
- 使危险值变成常量或更窄区间；
- 把复杂 path split 改成显式 guard + safe exit。

它们的难点在于：patch template 需要**按漏洞定制**，不适合统一框架一把梭。

### 6.3 基本不适合 hot patch 的类型

代表：`CVE-2022-48929`、`CVE-2024-45020`、`CVE-2025-39990`、`CVE-2025-40143`、`CVE-2023-54145`。  
这些问题的共同点是：

- 根因在 verifier 内部 memory safety / bookkeeping / warn path；
- 危险发生在 `BPF_PROG_LOAD` 时，而不是已加载程序运行时；
- 真正该修的是 verifier 本身，不是程序字节码。

对此 BpfReJIT 最多只能：

- 用 feed 检测并阻止继续加载某些程序；
- 对已加载程序不做动作；
- 强制运维进入升级/隔离流程。

## 7. Google / Meta 公开响应方式

### 7.1 Google：公开材料能看到的是“发现 -> 上游修复 -> 延迟披露”

Google 对 `CVE-2023-2163` 的公开材料足够清楚：

- GitHub GHSA 页面给出完整时间线：**2023-03-31 reported, 2023-04-19 fixed, 2023-06-29 disclosed**；[GHSA-j87x-j6mh-mv8v](https://github.com/google/security-research/security/advisories/GHSA-j87x-j6mh-mv8v)
- Google security-research 公开了 PoC；[Google PoC](https://google.github.io/security-research/pocs/linux/cve-2023-2163/)
- Bug Hunters 博客元数据明确写了他们会描述“发现过程、root-cause analysis、以及最终如何修复”。[Google Bug Hunters blog](https://bughunters.google.com/blog/a-deep-dive-into-cve-2023-2163-how-we-found-and-fixed-an-ebpf-linux-kernel-vulnerability)

据此可以相对有把握地概括 Google 的公开流程：

1. 通过研究/模糊测试发现 verifier bug；
2. 做 root-cause 分析和 PoC；
3. 先推动 upstream 修复与 backport；
4. 在披露窗口后公开 advisory/PoC。

**重要的是，这套公开流程没有暴露任何“已加载 BPF 程序在线热补丁”机制。** 它仍然是传统的 kernel 修复与滚动发布路径。这恰好给 BpfReJIT 留出论文空间：**Google 证明了问题严重性，但公开路径依然是 patch kernel，而不是 patch live bytecode。**

### 7.2 Meta：公开论文展示的是“集中编排 + 测试 + rollout + kill-switch”

我没有在公开资料中找到一份 Meta 明确写出的“BPF verifier CVE incident response playbook”。截至 **2026-03-25**，最接近的公开材料是 NetEdit 论文，因此下面这段应视为**基于公开论文的推断**，而不是 Meta 官方安全流程声明。

NetEdit 论文给出的信号很强：

- 它是 Meta 在大规模生产网络中部署多种 eBPF network functions 的编排平台；
- 强调 **safe deployment**、**extensive testing**、**staged-code rollouts**、**policy engine**、**complete disabling of a policy**、以及 **Prod A/B testing**；
- 文中还明确说“虽然 verifier 能保证单个程序安全，但 eBPF-kernel interaction 仍会暴露未知 bug，导致大规模 outage，因此他们建立了额外的测试框架”。[NetEdit, SIGCOMM 2024](https://cs.stanford.edu/~keithw/sigcomm2024/sigcomm24-final159-acmpaginated.pdf)

因此，对 Meta 更合理的公开推断是：

- 他们的公开治理能力偏向**集中编排、灰度 rollout、快速 disable/rollback**；
- 这适合“重新部署一版新的 BPF 程序”；
- 但仍不是“对已加载程序镜像做 verifier-backed emergency hot patch”。

这再次说明 BpfReJIT 的论文定位应当是：

- 不与 Meta/Google 的现有运维体系冲突；
- 而是给这类体系增加一个**更快、更小粒度的 emergency mitigation layer**。

## 8. 学术相关工作

### 8.1 verifier 正确性与替代 verifier

- **PREVAIL**：用户态 alternative verifier，目标是更 sound / scalable，强调 abstract interpretation，而不是 post-load hot patch。[PREVAIL, PLDI 2019](https://seahorn.github.io/papers/ebpf-pldi19.pdf)
- **Agni**：自动检查 Linux eBPF verifier range analysis 的 soundness；论文声称在多个内核版本上发现新 bug，并证明新版本 soundness。它是在“验证 verifier”，不是“修 live 程序”。[Agni, CAV 2023](https://people.cs.rutgers.edu/~sn349/papers/agni-cav2023.pdf)
- **State Embedding**：直接面向 eBPF verifier 逻辑 bug；论文报告发现 **27 个 bug，10 个已修复，其中 2 个可达 LPE**。这对我们的论点很重要：**verifier bug 不是偶发噪声，而是系统性研究对象**。[State Embedding, OSDI 2024](https://www.usenix.org/system/files/osdi24-sun-hao.pdf)
- **VEP**：两阶段验证，用户态 prover + kernel proof checker，重点是 full programmability，不是 post-load repair。[VEP, NSDI 2025](https://www.usenix.org/system/files/nsdi25-wu-xiwei.pdf)

这类工作的共同点是：它们强化的是**接受路径**或**verifier 本身**。BpfReJIT 的切入点不同：**假设 buggy verifier 已经把程序放进来了，现在怎样在不停机条件下把它补硬。**

### 8.2 JIT / runtime correctness

- **Jitterbug**：验证 BPF JIT backend correctness，报告发现并修复多个真实 JIT bug。它关注的是“BPF -> machine code translation 是否 faithful”，不是 live bytecode patch。[Jitterbug, OSDI 2020](https://unsat.cs.washington.edu/papers/nelson-jitterbug.pdf)
- **BpfChecker**：差分模糊测试 eBPF runtime implementations，报告 **28 个 bug、2 个 CVE、约 80 万美元 bounty**，说明 eBPF runtime correctness 仍然很脆弱。[BpfChecker, CCS 2024](https://www.yajin.org/papers/CCS2024_BpfChecker.pdf)

这些工作对论文写法的启发是：BpfReJIT 不必宣称“我们修复了 verifier correctness”；更稳健的说法是：**我们把危机窗口缩短，并把安全缓解前移到 live bytecode 层。**

## 9. 实现可行性评估

### 9.1 用户态 daemon：高可行

这部分最成熟。当前仓库已经证明：

- 枚举 live 程序；
- 拉取原始 bytecode；
- 跑 pass pipeline；
- 调用 `REJIT`；
- 处理 verifier log 和失败回滚；

都已经有原型。

如果要做 security hotpatch，最自然的路径是在现有 PassManager 里再加一类 pass：

- `CVE2024_56702RawTpNullGuardPass`
- `CVE2024_49861ReadonlyMapWritePass`
- `CVE2024_58098PktInvalidatePass`

以及一个比性能优化更严格的 policy 层：

- `mode = alert-only`
- `mode = patch-if-safe`
- `mode = patch-or-quarantine`

### 9.2 matcher：中高可行，但必须 CVE-specific

最现实的 matcher 不是“抽象所有 verifier bug”，而是**按漏洞出签名**。  
签名输入可包括：

- prog type / attach type / BTF hook；
- helper/kfunc id；
- 特定 basic block 形状；
- 是否缺 dominating null-check；
- 是否存在 stale packet pointer use；
- 是否 tail-call 到不同 hook class；
- 是否把 release 后寄存器用于 map store。

这类 matcher 与现有 scanner / CFG / liveness / instruction matcher 非常兼容。

### 9.3 patch synthesis：中等可行

建议把 patch template 分成四类：

1. **guard insertion**：null / bounds / size / attach-kind；
2. **sanitization**：zero / poison / scratch-stack redirect；
3. **pointer refresh**：重新获取 packet root / dynptr base；
4. **edge quarantine**：禁用危险 tail-call / helper / extension edge。

其中 1 和 2 最适合先做；4 最容易影响功能，应放在 emergency mitigation 模式。

### 9.4 kernel-side live replacement：当前仍是主要短板

这部分不能粉饰。仓库内已有分析指出：

- 当前 REJIT kernel path 仍更接近 benchmark/POC；
- 多 CPU / attached / trampoline / kallsyms / old image retirement 还需要更完整的 RCU 语义；
- 因而**今天可以证明控制面可行，但还不能把整个 kernel replacement path 描述成 production-safe**。

这对论文不是坏事，反而可以形成更可信的表述：

> BpfReJIT live patch 在用户态发现、匹配、重写、re-verify 这一层已经具备现实基础；其进入生产仍取决于 kernel-side image swap 机制是否达到 production-grade 的 RCU/metadata consistency。

### 9.5 总体结论

| 子问题 | 可行性 | 结论 |
|---|---|---|
| advisory feed + candidate selection | 高 | 现有 CVE/advisory 基础设施足够 |
| live program enumeration | 高 | 当前 daemon 已有 |
| vulnerable pattern matching | 中高 | 需按 CVE 维护模板 |
| patch bytecode synthesis | 中 | 先做 guard/sanitize 类 |
| re-verify + apply | 高 | 当前 daemon 已有，需补 security pass |
| production-safe kernel swap | 中低（当前） | 是现阶段最大的系统工程风险 |

## 10. 对论文写作的建议表述

最稳妥的论文 framing 应该是：

1. **问题陈述**：verifier CVE 的独特后果是“错误接受的 live BPF 程序继续运行”，这与普通 kernel patching 不同。
2. **系统目标**：BpfReJIT 不是在线修 verifier，而是在线硬化被 verifier 错误接受的程序。
3. **安全论证**：热补丁必须显式绕开已知 buggy verifier proof rule，并通过 re-verify 提交。
4. **与 livepatch 对比**：BpfReJIT 更像 verifier-backed livepatch；livepatch 依赖人工信任，而 BpfReJIT 可以把 patch producer 放在不可信域。
5. **诚实限制**：不是所有 verifier CVE 都能 hot patch；当前 kernel-side swap path 仍需 productionize。

一句可以直接进论文的摘要化表述是：

> BpfReJIT live patching does not attempt to repair the verifier itself; instead, it rewrites already-loaded BPF programs into more conservative verifier-simple forms that eliminate known exploit gadgets without rebooting the kernel or modifying applications.

## 附录 A：2023-03-25 至 2026-03-25 的 NVD 候选分组清单

以下分组基于 NVD 候选 + 人工 triage。它的作用不是给出法律意义上的“官方分类”，而是为 live patch 研究界定范围。

### A.1 G1：已加载程序安全相关，适合 live patch 分析

`CVE-2023-2163`, `CVE-2023-52452`, `CVE-2023-52676`, `CVE-2024-38566`, `CVE-2021-47607`, `CVE-2024-38662`, `CVE-2024-41003`, `CVE-2024-42072`, `CVE-2024-42151`, `CVE-2024-43910`, `CVE-2024-47703`, `CVE-2024-47728`, `CVE-2024-49861`, `CVE-2024-50063`, `CVE-2024-50164`, `CVE-2024-53125`, `CVE-2024-56702`, `CVE-2025-21852`, `CVE-2023-52928`, `CVE-2022-49873`, `CVE-2024-58098`, `CVE-2024-58100`, `CVE-2025-38060`, `CVE-2022-49961`, `CVE-2025-38591`, `CVE-2025-38607`, `CVE-2023-53645`, `CVE-2025-40050`, `CVE-2025-40078`, `CVE-2025-40169`, `CVE-2022-50650`

### A.2 G2：verifier robustness / load-time / diagnostics，通常不适合 live patch

`CVE-2021-47376`, `CVE-2023-52828`, `CVE-2024-43837`, `CVE-2022-48929`, `CVE-2024-45020`, `CVE-2023-52920`, `CVE-2022-49878`, `CVE-2025-38279`, `CVE-2025-39748`, `CVE-2025-39990`, `CVE-2025-40143`, `CVE-2025-68208`, `CVE-2023-54145`, `CVE-2023-54181`

### A.3 G3：NVD 候选里出现 verifier 关键词，但根因不在 verifier

`CVE-2024-35895`, `CVE-2024-42073`, `CVE-2022-49236`, `CVE-2024-58070`, `CVE-2025-22048`, `CVE-2025-38502`, `CVE-2023-53857`

## 参考资料

### 官方文档 / advisory

- Linux kernel livepatch 文档：<https://docs.kernel.org/livepatch/livepatch.html>
- Linux kernel reliable stacktrace 文档：<https://docs.kernel.org/livepatch/reliable-stacktrace.html>
- kpatch Patch Author Guide：<https://github.com/dynup/kpatch/blob/master/doc/patch-author-guide.md>
- Google `CVE-2023-2163` GHSA：<https://github.com/google/security-research/security/advisories/GHSA-j87x-j6mh-mv8v>
- Google `CVE-2023-2163` PoC：<https://google.github.io/security-research/pocs/linux/cve-2023-2163/>
- Google Bug Hunters 博客：<https://bughunters.google.com/blog/a-deep-dive-into-cve-2023-2163-how-we-found-and-fixed-an-ebpf-linux-kernel-vulnerability>

### 学术论文

- Jitterbug：<https://unsat.cs.washington.edu/papers/nelson-jitterbug.pdf>
- PREVAIL：<https://seahorn.github.io/papers/ebpf-pldi19.pdf>
- Agni：<https://people.cs.rutgers.edu/~sn349/papers/agni-cav2023.pdf>
- Validating the eBPF Verifier via State Embedding：<https://www.usenix.org/system/files/osdi24-sun-hao.pdf>
- VEP：<https://www.usenix.org/system/files/nsdi25-wu-xiwei.pdf>
- NetEdit：<https://cs.stanford.edu/~keithw/sigcomm2024/sigcomm24-final159-acmpaginated.pdf>
- BpfChecker：<https://www.yajin.org/papers/CCS2024_BpfChecker.pdf>

### 仓库内现有实现/分析

- `daemon/README.md`
- `daemon/src/bpf.rs`
- `daemon/src/commands.rs`
- `docs/tmp/2026-03-11/rejit-rcu-safety-analysis.md`
- `docs/tmp/20260324/safety_correctness_separation_survey_20260324.md`
- `docs/tmp/20260324/related_work_comprehensive_analysis_20260324.md`
