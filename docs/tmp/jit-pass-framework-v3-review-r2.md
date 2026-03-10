# JIT Pass Framework v3 设计评审 R2

日期：2026-03-09
评审对象：`docs/tmp/jit-pass-framework-v3-design.md`
对照文档：
- `docs/paper-comparison.md`
- `docs/kernel-jit-optimization-plan.md`

## Overall Score

**7.5 / 10**

这是目前为止最清晰、最诚实的一版。最大的进步是边界终于收紧到了正确层次：`xlated_prog_len` 不变、只做 `JIT_LOWERING`、明确拒绝 verifier rewrite / raw machine code upload / verifier override，这些都与 POC v2 证明出来的核心不变量一致，也与 characterization 论文“gap 在 backend lowering，不在 bytecode”这一主叙事一致。

但我不建议直接按这版开工实现。主要不是方向错，而是还有几处会在实现时立刻变成设计分歧：
- `userspace controls policy` 与 overlap arbitration / priority ownership 还没有完全对齐
- constant blinding / late rewrite 的最终 contract 还不够具体
- 与 `kernel-jit-optimization-plan.md` 的关系还没有彻底收束，尤其是 `branch_reorder` / Hybrid / “5+ rules” 的旧叙事仍然在计划文档里占很重位置
- `WIDE_MEM` 的 exact legality 边界还需要再写实一点，避免实现时回到“看起来像 JIT-only，实际偷偷依赖 bytecode rewrite 假设”

**结论：needs another revision，接近 implementation-ready，但还差一轮收口。**

## Section-by-Section Assessment

### §1 摘要

这一节很强。核心 invariant、与论文的关系、与 POC v1/v2 的切割、以及 4 个 family 的定位都写清楚了。尤其是把 `callee-saved` 明确降格为“应该直接 upstream 的 fixed kernel heuristic”，这和 `paper-comparison.md` 一致，也让 v3 的 scope 更诚实。

需要补的一点是：这里已经事实上改写了 `kernel-jit-optimization-plan.md` 里先前的 Hybrid / `branch_reorder` 方向，但没有显式写“哪些旧要求已被 supersede”。这会留下跨文档歧义。

### §2 设计边界与总体架构

这节对 `xlated_prog_len` 不变量的坚持是全篇最稳的部分。`plan materialization` 后移到所有 kernel-owned late rewrite 之后，这个方向也是正确的。

问题在于“所有 late rewrite”还不够具体。当前文档只给了原则，没有把 constant blinding 的行为 contract 写死。既然你已经在安全模型里引入了 `BPF_JIT_RJ_BLINDED_PROG`，这里就应该明确：
- blinded program 是否直接禁用 v3
- 如果不禁用，digest / `orig_idx` / remap 绑定到谁
- fail-closed 是 per-site 还是整 prog reject

### §3 可扩展基础设施设计

整体架构是技术上可行的，且比 v2 的 ad-hoc hook 明显更对。`dispatcher`、`plan`、`alt table`、`transport`、`addrs[] commit` 这五块作为 substrate 的划分也合理。

这里有两个主要设计缺口：
- `priority` 的所有权不清楚。`plan` 有 `priority`，`alt_desc` 有 `priority`，`family_ops` 还有 `default_priority`，但 record/action 侧没有一个明确的“用户态 policy priority / budget”入口。这样一来，overlap arbitration 很容易从“kernel 执行用户态 policy”滑成“kernel 替用户做 policy”。
- `prog_tag` 草图和真实 kernel UAPI 不一致。文档在 bundle header 里使用 `prog_tag[20]`，但当前内核 UAPI 的 `BPF_TAG_SIZE` 是 8。这个问题容易修，但应尽快统一，不然 transport 设计会和真实内核接口错位。

### §4 Pattern / Constraint / Action IR

这一节比旧稿成熟很多。把 width / mem mode 提升到 pattern 层是必要修正，能避免把 `wide_load` 的核心语义都塞进 family-private validator。

但它仍然更像“足够表达方向”，而不是“足够直接实现”。特别是：
- `WIDE_MEM` 还缺少“中间结果不可被使用 / 最终只有一个 liveout 聚合值”的显式约束
- `ADDR_MODE` 还缺少更明确的 flags-dependence 约束描述
- `ROTATE` 还缺少对 matched idiom 精确形状的 reject case 示例

换言之，IR 的限制性是对的，但 family 的 exact shape 还没有写到能直接 coding 的精度。

### §5 Rule 安全性验证模型

这是另一段写得很好的部分。四层安全模型是清楚的，`FATAL` 只保留给 invariant break 也比旧稿稳很多。

仍需补强的是边界条件：
- `BPF_JIT_RJ_BLINDED_PROG` 被定义了，但没有配套 lifecycle 说明
- `pass_deterministic` 写成了 contract，但没有列出“哪些输入必须被冻结，哪些运行时 feature 不允许影响第二遍选择”
- “per-site fallback” 很清楚，但 transport/materialization 阶段的 reject 与 JIT 阶段的 fallback 边界还可以再用一小段文字写死

### §6 JIT Backend 抽象层（x86）

这个方向是可行的，也和当前 `do_jit()` 的真实痛点对上了：不要再把 pattern re-match、payload decode、冲突判断散落到多个 case/hook 里。

建议把“插入点”写得再具体一点。现在已经够说明思路，但实现者仍会问：
- region lookup 放在 `do_jit()` 主循环的哪个确切位置
- convergence loop 的 measure pass / final image pass 如何共享同一个 decision
- extra pass / padding pass 是否视为同一 deterministic contract

这些不一定要在本节放代码，但最好至少给一段更贴近现有 x86 JIT pass 模型的说明。

### §7 跨架构 Target Description

方向合理，作为 future-proof 抽象也值得保留。`SELECT` / `ADDR_MODE` / `ROTATE` / `WIDE_MEM` 都可以自然映射到 x86 与 arm64 的 semantic alt。

不过它当前更像“设计预留”而不是“MVP 必需件”。建议把叙述再收一下：x86 MVP 是实现重点，arm64 是证明 substrate 不是 x86-only hardcode 的下一步，不要让读者误以为两边成熟度接近。

### §8 四个具体 Rule

`SELECT` 最完整，也最能支撑 userspace-policy thesis。它和论文中的 `31 vs 0 cmov`、以及 no-cmov mixed result 是直接闭环的。

`WIDE_MEM` 方向也对，且终于把自己放在 JIT-only 层，而不是 verifier rewrite 层。但 exact validator 仍需更具体，尤其是：
- contiguous byte ladder 的精确 shape
- 中间 partial value 是否必须 dead
- map-value / stack 上的 alignment / fault / extable 语义依赖

`ADDR_MODE` 与 `ROTATE` 作为 substrate family 没问题，但从论文 story 上看，它们现在更像“证明框架可泛化的工程样本”，还不是强 policy-sensitive evidence。文档其实已经承认了这一点；下一步要做的是把这个定位写得更硬，不要再半隐含地把它们包装成 userspace 必须控制的代表例子。

### §9 从 v2 到 v3 的渐进实现路径

工程路径基本可信。先把 v2 的 `cmov_select` 迁成通用 substrate，再逐步挂 family，这比推倒重来靠谱得多。

LOC 估计我认为**对 kernel 核心改动本身是大体可信的**，但对“完整、可 hardened 的 MVP”略偏乐观。`1200-2000 LOC` 大概能覆盖：
- parser / validator / dispatcher / commit / x86 emitter 这些主干

但如果算上：
- blinding handling
- logging / observability
- multi-subprog hardening
- selftests / negative tests
- UAPI/documentation polish

那真实工作量大概率会更高。建议文档明确“这是 core implementation delta，不含测试与论文评估 plumbing”。

### §10 论文 Story

这一节比计划文档当前状态更成熟。它已经明确回答了“为什么不是只做 kernel peepholes”，也给出了 falsification condition。

但还有一个叙事风险没有完全消掉：MVP 的 4 个 family 里，真正有强 policy-sensitive 证据的目前基本只有 `SELECT`。`WIDE_MEM` 更像高价值 baseline recovery，`ADDR_MODE` / `ROTATE` 更像 extensibility exercise。这个结构并不致命，但论文 claim 必须和它匹配：
- 如果 evaluation 证明 fixed kernel heuristics 在后三者上足够好，那么 userspace thesis 只能由 `SELECT` 撑起
- 如果想让“userspace-guided framework”更强，就需要后续再引入至少一个第二个明确 policy-sensitive family，或者把 claim 收窄到“framework + one anchor policy-sensitive family”

## Issues Found

### Critical

**无 critical issue。**

核心 invariant 没有明显滑坡；文档没有再把 BPF bytecode rewrite 混进 v3，也没有再开放 raw machine code upload。

### Major

1. **Policy / safety split 在 overlap arbitration 上还不够闭合。**  
   `userspace controls policy` 是全文主张，但当前 `priority` 同时出现在 `plan`、`alt_desc`、`family_ops`，而用户态 record/action 没有明确的 policy priority / budget ownership。若不澄清，kernel 会在重叠候选之间实质性替用户做选择。

2. **与 `kernel-jit-optimization-plan.md` 的主叙事仍有明显不一致。**  
   计划文档仍把 `branch_reorder` / `subprog_inline` 视为 policy-sensitive 主角，并保留了 “Hybrid / Path B 更有前景” 的结论；v3 设计文档则明确把 `branch_reorder`、`bounds_window` 排除出范围。这一转向可能是对的，但必须显式写成“哪些计划条目已被 v3 supersede”，否则跨文档会自相矛盾。

3. **constant blinding / final rewrite contract 仍然不够具体。**  
   文档说 materialization 要放到所有 late rewrite 之后，也定义了 `BPF_JIT_RJ_BLINDED_PROG`，但没有说明 blinded prog 的实际支持策略。考虑到旧 review 已把 blinding 识别为 must-fix，这里需要更具体的 pipeline contract，而不是原则性一句话。

4. **`WIDE_MEM` family 的 exact legality 还不够实现级。**  
   目前只写到了 contiguous offsets、same base、mem class 白名单、non-`PROBE_MEM`。还需要显式写出：中间值不得外泄、最终聚合值的单一 liveout、对 alignment/fault/extable 的依赖、以及为什么 stack/map-value 在 MVP 上可以安全 collapse。

5. **“为什么需要 userspace” 的实证支撑目前主要集中在 `SELECT`。**  
   文档已经诚实地把 `ADDR_MODE` / `ROTATE` 定位为 extensibility 证明、把 `WIDE_MEM` 定位为最大 gap 的正确层次修复；问题是这样一来，MVP family set 对 userspace-policy thesis 的支撑并不均衡。需要要么收窄 claim，要么在后续 evaluation 中补足第二个明确 policy-sensitive family。

### Minor

1. **bundle header 中的 `prog_tag[20]` 与真实 kernel UAPI 不一致。**  
   当前内核 `vendor/linux/include/uapi/linux/bpf.h` 的 `BPF_TAG_SIZE` 是 8，不是 20。若这里想表达“更强 digest”，就不要写成“复用 kernel prog tag 语义”；若确实复用现有 tag，就应使用真实尺寸。

2. **若干 pseudo-API 还没有完全归一。**  
   例如 `emit()` 的返回值与 `bpf_jit_emit_result.status` 双重表达 status；`priority` 在多个结构里重复出现但 precedence 未定义。这些不影响方向，但在实现前应先统一。

3. **LOC 估计略偏乐观。**  
   作为 kernel 核心改动估算可以接受；作为“完整 MVP”估算则偏小，尤其在计入 selftests、negative tests、observability、blinding handling 之后。

## Specific Recommendations

1. **在 v3 文档开头增加一段“supersedes / out-of-scope”说明。**  
   明确声明：`kernel-jit-optimization-plan.md` 中关于 `branch_reorder` / `bounds_window` / Hybrid Path B 的旧条目，对 v3 MVP 已不再适用；它们若保留，应被标记为 future verifier substrate，而不是当前 v3 目标。

2. **把 policy ownership 写成明确 contract。**  
   最好回答三个问题：
   - overlap 时谁拥有最终优先级
   - userspace 是否能显式提供 bounded priority / budget
   - kernel 在什么情况下可以推翻 userspace 选择，哪些属于 legality-only filter

3. **把 blinding path 单独写成一个小节。**  
   需要明确：
   - materialization 发生在哪个确切阶段
   - blinded prog 是否直接 reject
   - `prog_tag`、`orig_idx`、plan remap 分别绑定哪份 program image
   - reject 与 fallback 的边界

4. **把四个 family 的 exact validator 再写细一层，尤其是 `WIDE_MEM`。**  
   至少补上：
   - 正例形状
   - 反例形状
   - intermediate use / side effect / flags dependence 的 reject 条件
   - 每个 mem class 的 MVP 安全理由

5. **收紧论文 claim，让它与 MVP family set 精确匹配。**  
   一个稳妥写法是：
   - `SELECT` 是首个 policy-sensitive anchor
   - `WIDE_MEM` 是最大 backend gap 的 JIT-only recovery
   - `ADDR_MODE` / `ROTATE` 是 extensibility proof，不强行包装成同等强度的 why-userspace evidence

6. **统一 transport / UAPI 草图与真实内核常量。**  
   包括 `BPF_TAG_SIZE`、status contract、priority precedence、以及是否真的需要 `prog_tag + insn_cnt` 还是更强 digest。

7. **把 LOC 估算拆成两栏。**  
   建议区分：
   - core kernel implementation delta
   - hardening + selftests + evaluation plumbing

## Final Verdict

**Needs another revision before implementation.**

原因不是核心方向有问题，恰恰相反：JIT-only、`xlated_prog_len` 不变、policy/safety 分离、fail-closed substrate，这些关键决策已经基本站稳了。阻碍开工的主要是三类收口工作：
- 把 cross-doc story 彻底统一
- 把 arbitration / blinding / exact validator contract 写成实现级定义
- 把 userspace-policy claim 收敛到当前证据真正支撑的范围

如果把上面的 major issues 收掉，我会把这份设计判断为**可以开始实现 x86 MVP**；但以当前文字状态，直接实现仍然容易在关键边界上产生二义性。
