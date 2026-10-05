# v3 可扩展 JIT pass 框架设计审查

日期：2026-03-09

审查范围：

- [v3 设计文档](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md)
- [整体优化计划](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md)
- [POC v2 审查结果](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/poc-v2-design-conformance-review.md)
- [x86 JIT 当前实现](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c)
- [POC v2 verifier/JIT directive 实现](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/jit_directives.c)
- [verifier 当前实现](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c)

## 总体结论

v3 比 POC v2 明显更接近一个“可审计的受限框架”：它把用户态权限明确限制在 `family + pattern + constraints + action + alt preference` 的实例化上，而不是上传机器码；也把 `wide_load` 从错误的 verifier rewrite 路线纠回到 JIT lowering，把 `branch_reorder` 放回 verifier rewrite，方向上是对的（[v3设计#L9](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L9), [v3设计#L911](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L911), [v3设计#L968](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L968), [计划#L569](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L569)).

但这份文档把最难的两件事写得偏顺了。第一，verifier-stage rule 依赖的 retained facts、`orig_range` provenance、rewrite 后的 liveness/CFG 一致性，在当前内核里都没有现成闭环；第二，region dispatcher 只对“一个连续 BPF span 折成一个连续 native span”的局部 collapse 成立，不能自然外推成 general layout engine（[v3设计#L404](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L404), [v3设计#L430](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L430), [v3设计#L477](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L477), [verifier.c#L21927](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L21927), [verifier.c#L26047](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26047), [verifier.c#L26077](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26077), [bpf_jit_comp.c#L3026](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L3026)).

我的判断是：如果把 MVP 收窄到 `SELECT + ADDR_MODE + ROTATE + WIDE_MEM + digest/logging + x86 dispatcher`，这条路线现实；如果把 6 个 rule、x86+arm64、论文 novelty 和安全闭环一次性都算进来，当前设计还没有把最关键的 verifier 基础设施讲透。

## 单独列出的问题

1. `bounds_window` 依赖的 retained readable-window fact 当前没有来源。现有 verifier 的 packet bounds 证明存在于动态 `bpf_reg_state.range` 中，而不是稳定导出的 per-site facts；`do_check()` 之后 `explored_states` 会被释放，文档也没有定义新的 retained-fact side table（[v3设计#L1028](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1028), [v3设计#L1061](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1061), [bpf.h#L986](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf.h#L986), [verifier.c#L16576](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L16576), [verifier.c#L26066](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26066)).
2. `VERIFIER_REWRITE` 放在 `compute_scc/compute_live_registers` 之后，但文档没有要求 rewrite 后重算 liveness/SCC。后续 `JIT_LOWERING` 的 `LIVEOUT_ONLY`、CFG 约束可能读到陈旧数据（[v3设计#L211](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L211), [v3设计#L404](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L404), [verifier.c#L26047](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26047), [verifier.c#L26079](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26079), [bpf_verifier.h#L595](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L595)).
3. 当前内核只有 `orig_idx`，没有 v3 需要的 `orig_start/orig_end` provenance。`bpf_patch_insn_data()` 是 `1 -> N` patch，`adjust_insn_aux_data()` 只把同一个 `orig_idx` 扩展到被 patch 的新窗口，不支持 block permutation 的精细 remap（[v3设计#L387](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L387), [v3设计#L430](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L430), [bpf_verifier.h#L579](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L579), [verifier.c#L21923](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L21923), [verifier.c#L22013](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L22013)).
4. `Pattern IR` 缺少 load/store 宽度、mode、signedness 字段。`wide_load` 和 `bounds_window` 真正依赖的 `LDX.B`、`PROBE_MEM`、`MEMSX` 等区别，并不是通用 IR 自身表达出来的，而是被推给 family-specific exact validator（[v3设计#L147](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L147), [v3设计#L187](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L187), [v3设计#L917](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L917), [v3设计#L1033](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1033)).
5. `start_map`/dispatcher 没定义 overlap arbitration，也没把 “fatal error” 和 “per-site fallback” 的 emitter contract 写清。`emit()` 返回 `int`，`emit_result` 又有 `fallback` 位，但文档没说明何时应返回错误、何时应仅标记 fallback（[v3设计#L499](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L499), [v3设计#L514](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L514), [v3设计#L561](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L561), [v3设计#L729](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L729)).

## A. 架构评审

### A1. v3 的“受限 rule framework”定位是否合理？安全边界是否清晰？

结论：定位合理，边界也比 v2 清晰得多，但 verifier-stage rewrite 这半边还没有对应的现有内核基础，因此“边界清晰”目前更多是文档层，而不是实现层。

理由：

1. 文档明确把用户态权限限制在“实例化 kernel 已知 family”的范围内，禁止上传机器码、定义新 semantic family、绕过 exact validator；这和 POC v2 只允许请求 `cmov_select` 的方向一致，只是抽象层更好（[v3设计#L11](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L11), [v3设计#L29](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L29), [v3设计#L110](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L110), [v3设计#L1164](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1164)).
2. 这条边界和计划文档的 mechanism/policy 分离一致。计划把真正 novel 的部分定义为 “kernel 管 legality，userspace 管 profitability”，并把 digest binding、retained facts、exact validator、CPU gating 作为 substrate，而不是把用户态变成另一个编译器（[计划#L17](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L17), [计划#L42](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L42)).
3. 问题在于 verifier-stage rule 不是单纯“native emission 选择”，而是用户定点触发的 BPF rewrite。当前内核确实有 post-verifier rewrite 先例，但还没有“retained facts + exact validator + provenance range”这条闭环，所以这部分边界是正确方向，不是现成能力（[v3设计#L404](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L404), [计划#L491](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L491), [计划#L503](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L503), [verifier.c#L24409](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L24409)).

### A2. 两个 stage（`VERIFIER_REWRITE` + `JIT_LOWERING`）的分离是否正确？

结论：分离方向是对的，而且比 v2/v1 更诚实；但文档遗漏了 rewrite 后必须重建部分验证元数据这一要求。

理由：

1. `branch_reorder` 这类 CFG permutation 无法自然落在现有 x86 `do_jit()` 的线性 `addrs[]` 模型里，放到 verifier rewrite 是对的；`wide_load`、`lea_fusion`、`rotate_fusion` 则确实更像 target-specific lowering（[v3设计#L13](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L13), [v3设计#L964](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L964), [计划#L495](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L495), [计划#L499](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L499)).
2. 文档把 rewrite stage 放在 `do_check()` 之后、`convert_ctx_accesses()` 之前，也与现有 verifier pipeline 相容：当前 `optimize_bpf_loop()`、dead-code cleanup、ctx conversion、本就发生在 full verification 之后（[v3设计#L404](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L404), [verifier.c#L26077](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26077), [verifier.c#L26095](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26095)).
3. 但当前 `compute_scc()` 和 `compute_live_registers()` 在 rewrite 之前执行，rewrite 后不会自动重算；而 v3 的约束集又包含 `ONE_DIAMOND`、`LIVEOUT_ONLY`、`NO_INTERIOR_EDGE` 等结构/活性条件。这意味着 Step B 之后如果不重算或冻结新的 side tables，Step C 的 lower-plan materialization 有读旧元数据的风险（[v3设计#L205](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L205), [v3设计#L211](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L211), [verifier.c#L26047](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26047), [bpf_verifier.h#L596](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L596)).

### A3. “family + alt vocabulary” 的扩展模型是否真的比 v2 更好？量化：新增一个优化需要多少内核代码？

结论：比 v2 好，但只在“新增实例”层面显著更好；一旦跨 family，新增内核代码仍然不小。

量化判断：

1. v2 的扩展粒度基本是“一个 directive = 一套新 kind + payload + verifier matcher + JIT hook + emitter”，计划文档自己估的是约 `~300 行/directive`，POC v2 也确实把逻辑分别散落在 `jit_directives.c` 和 x86 `do_jit()` 的两个 hook 点里（[计划#L129](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L129), [jit_directives.c#L72](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/jit_directives.c#L72), [bpf_jit_comp.c#L2137](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2137), [bpf_jit_comp.c#L2964](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2964)).
2. v3 的优势在于：若只是“现有 family 的新实例”，理论上不需要新增 UAPI enum、不需要新增 userspace/kernel 双份 matcher，甚至不需要新增内核代码；若只是新增一个现有 family 的 alt，文档给出的量级是每个 arch `40-120 LOC` 级别（例如 `cmov_select` alt 表 `80-120 LOC`，`rotate` x86 alt `80-120 LOC`、arm64 alt `40-80 LOC`）（[v3设计#L628](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L628), [v3设计#L803](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L803), [v3设计#L904](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L904)).
3. 但这份文档列举的 6 个 rule 里，除了 `cmov_select` 是现有 `SELECT` family 的自然延伸，其他 5 个都相当于新 family 或新 verifier helper。按文档自己的估算，`ADDR_MODE`、`ROTATE`、`WIDE_MEM` 各要 `100-300+ LOC` 的 validator/emitter，`CFG_DIAMOND` 要 `250-400 LOC`，`GUARD_ELIDE` 要 `180-300 LOC`，而这些还没有算 retained facts/provenance/recompute（[v3设计#L855](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L855), [v3设计#L903](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L903), [v3设计#L960](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L960), [v3设计#L1022](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1022), [v3设计#L1068](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1068)).

我的量化结论：

- 现有 family 内新增实例：`0 LOC` 到很少。
- 现有 family 内新增 alt：约 `40-120 LOC/arch`。
- 新 JIT family：约 `150-350 LOC/family/arch`，不含测试。
- 新 verifier-stage family：至少 `300-800 LOC`，因为会带上 rewrite helper、provenance、元数据刷新。

### A4. pattern/constraint/action IR 的表达能力是否足够覆盖 6 个具体 rule？有没有无法表达的？

结论：它足够做“受限 site selector + family key”，但不足以独立表达 6 个 rule 的全部安全语义；其中 `bounds_window` 是最明显的缺口。

具体判断：

1. `cmov_select`、`lea_fusion`、`rotate_fusion` 的局部模式基本可由当前 IR 表达：都有有限窗口、局部寄存器捕获、简单结构约束、固定 lowering action（[v3设计#L137](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L137), [v3设计#L202](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L202), [v3设计#L232](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L232), [v3设计#L768](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L768), [v3设计#L815](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L815), [v3设计#L868](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L868)).
2. `wide_load` 只能部分表达。文档示意 pattern 是 `LDX.B` ladder，但 IR 里并没有显式区分 `B/H/W/DW`、`MEM`/`PROBE_MEM`/`MEMSX` 的字段，所以真正的“只接受 byte ladder、只接受 nonfaulting mem class”仍然要依赖 family-specific validator，而不是通用 IR 自己表达（[v3设计#L147](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L147), [v3设计#L187](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L187), [v3设计#L911](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L911)).
3. `branch_reorder` 也只是部分表达。IR 能表达 “one diamond + no calls + no interior edge + reorder action”，但真正的 “交换两个 arm、反转条件、保留 provenance” 并不在 action IR 里，而是完全隐含在 kernel helper 里（[v3设计#L973](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L973), [v3设计#L986](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L986)).
4. `bounds_window` 目前不能被安全地说成“已表达”。它依赖 `FACT_PRESENT`，但文档没有定义这个 fact 的 shape、来源、proof basis、失效条件，也没有把 guard/access 之间“哪些指令会破坏 proof basis”编码进 IR（[v3设计#L215](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L215), [v3设计#L1029](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1029), [v3设计#L1061](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1061)).

我的结论是：`6 个 rule` 里，大致 `4.5/6` 能靠现 IR 自洽，`branch_reorder` 和 `bounds_window` 明显依赖 family-specific out-of-band 语义，其中 `bounds_window` 目前尚未闭合。

### A5. region dispatcher 是否与 `do_jit()` 的线性模型兼容？`addrs[]` 收敛是否会被破坏？

结论：兼容，但兼容的前提非常窄。只要坚持“连续 span collapse、单入口、无 interior edge、emit 跨 pass 决定稳定、无额外 metadata side effect”，`addrs[]` 收敛不会被破坏；超出这个边界就不成立。

理由：

1. 当前 POC v2 的 compact 和 diamond 本质上已经是手写的 region dispatcher：它们把连续 BPF span 折成一个 native region，并把 `addrs[start ... end-1]` 都提交成 `region_start`，再把 `addrs[end]` 提交成 `region_end`；image pass 还会强断言 `region_start + ilen == addrs[end]`（[bpf_jit_comp.c#L2143](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2143), [bpf_jit_comp.c#L2166](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2166), [bpf_jit_comp.c#L2990](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2990), [bpf_jit_comp.c#L3010](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L3010)).
2. 这与 `do_jit()` 的 fixed-point 逻辑是相容的，因为当前 branch displacement 一律基于上一轮 `addrs[target] - addrs[i]` 计算，而 fused span 内部不允许外部跳进来（[bpf_jit_comp.c#L3026](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L3026), [bpf_jit_comp.c#L3077](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L3077), [jit_directives.c#L154](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/jit_directives.c#L154), [jit_directives.c#L396](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/jit_directives.c#L396)).
3. 风险在于文档把这个抽象写得太“通用”了。`addrs[]` 还有别的消费者：`bpf_prog_update_insn_ptrs()` 要求它指向 jitted insn 起点，而 `bpf_prog_fill_jited_linfo()` 走的是“下一条边界”；此外 `PROBE_MEM`/extable、tail-call poke、cleanup label 都有额外 metadata 语义。纯 `commit_region()` helper 并不会自动携带这些语义（[bpf_jit_comp.c#L4315](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L4315), [bpf_jit_comp.c#L4338](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L4338), [bpf_insn_array.c#L269](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/bpf_insn_array.c#L269), [core.c#L229](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/core.c#L229), [bpf_jit_comp.c#L2743](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2743), [bpf_jit_comp.c#L3145](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L3145)).
4. 文档也没有定义 overlap 处理。`start_map` 只存一个 `plan_idx`，若两个合法 span 发生重叠但起点不同，dispatcher 应该如何裁决并未说明（[v3设计#L499](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L499)).

## B. 安全性审查

### B1. “用户态不能提交机器码”这个边界是否被所有 action 类型遵守？

结论：就文档当前列出的 action 类型来看，遵守。

理由：

1. `Action IR` 只有 `LOWER_SELECT`、`FUSE_ADDR_MODE`、`FUSE_ROTATE`、`FUSE_WIDE_MEM`、`REORDER_DIAMOND`、`ELIDE_GUARD` 这些 kernel-owned semantic op，加上 `alt_id` 引用；没有任何承载原生 bytes 的字段（[v3设计#L232](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L232), [v3设计#L241](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L241)).
2. verifier-stage rule 也不是“用户给 patch bytes”，而是“用户请求某个 kernel helper 执行固定 rewrite”；例如 `branch_reorder` 只能做 diamond 两臂互换和条件反转，`bounds_window` 只能删除已被 retained fact 证明为 dead 的 guard（[v3设计#L457](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L457), [v3设计#L986](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L986), [v3设计#L1044](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1044)).
3. 真正的风险不在“用户能否提交机器码”，而在“family exact validator 是否足够强”。如果 future action 开始带 raw patch payload，这个边界会立即被破坏；当前文档没有这么做，所以安全边界本身没问题。

### B2. pattern interpreter 有没有潜在的 DoS/OOB 风险？

结论：有中等风险，主要是 parser/plan contract 还没写实；不是根本性否决点，但必须补静态上界和冲突规则。

具体问题：

1. 文档口头说默认 window `<= 8`，但 `rec` 中 `pat_cnt/constraint_cnt` 是可变长，`plan.caps[8]`、`action.alts[4]`、`emit_result.span` 等都是固定大小；若 Step A 不显式检查 `pat_cnt <= 8`、`capture_cnt <= 8`、`alt_cnt <= 4`，会有直接 OOB 风险（[v3设计#L137](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L137), [v3设计#L249](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L249), [v3设计#L288](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L288)).
2. `orig_start_off/orig_end_off`、`rec_len`、`cpu_off/cpu_len` 都是 blob 提供的偏移/长度，Step A 虽然写了 “size / bounds / reserved bytes”，但没有把具体的不变量列出来，例如 `orig_start_off < orig_end_off <= orig_insn_cnt`、`rec_len` 与 `pat_cnt + constraint_cnt + action` 一致、总长度不溢出等（[v3设计#L397](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L397), [v3设计#L666](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L666)).
3. DoS 方面，JIT hot path 已经被 `validated plan + start_map` 设计成 O(1) lookup，这部分是好的；但 verifier-stage 仍可能是 `raw_rec_cnt * pattern_window` 的负载。好消息是 transport 继续沿用 bounded blob 模式，v2 当前是 `64 KiB` 上限，这个思路应该保留（[v3设计#L16](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L16), [jit_directives.c#L13](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/jit_directives.c#L13), [jit_directives.c#L262](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/jit_directives.c#L262)).

### B3. verifier-stage rewrite 会不会破坏 verifier 已建立的类型/range 证明？

结论：会，除非新增 retained-fact 与 post-rewrite revalidation 基础设施；其中 `branch_reorder` 可控，`bounds_window` 高风险。

理由：

1. `branch_reorder` 只要严格限制在 closed diamond、无 duplication、无 helper call、无 side effect，本质上是 proof-preserving 的 CFG permutation；这和当前 `optimize_bpf_loop()` 这种 post-check structural rewrite 属于同类风险级别（[v3设计#L1013](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1013), [verifier.c#L24409](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L24409)).
2. `bounds_window` 不一样。当前 packet readable-window 证明存在 verifier state 的 `reg->range` 里，且是路径相关的；`do_check()` 后这些 explored states 会释放。仅靠 `FACT_PRESENT` 这个抽象约束，无法证明 “所有到达态都仍安全” 和 “guard 与 access 之间没有破坏 proof basis 的指令”（[v3设计#L1038](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1038), [v3设计#L1061](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1061), [bpf.h#L986](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf.h#L986), [verifier.c#L16637](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L16637), [verifier.c#L26066](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26066)).
3. 即便不是 `bounds_window`，任何 rewrite 也会让 `live_regs_before`、`scc` 等预先计算的元数据失真，所以至少需要对受影响区域重算或在 rewrite 后重新跑一遍 cheap validation pass（[bpf_verifier.h#L595](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L595), [verifier.c#L26047](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26047)).

### B4. digest binding 的设计是否足够防止 TOCTOU？

结论：比 v2 好很多，但还不够；它需要和更强的 provenance 绑定一起看。

理由：

1. 当前内核已经有 `prog->digest` 基础设施，而且 verifier 已在 map exclusivity 检查中使用；所以“把 blob 绑定到 program digest”这件事不是空想（[core.c#L303](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/core.c#L303), [verifier.c#L21591](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L21591)).
2. 但现有 `prog->digest` 不是“完全原样的用户字节流 hash”。它在 `bpf_prog_calc_tag()` 中会把 map fd 归零后再算 SHA，这对稳定性是好事，但文档必须明确 v3 的 `prog_digest` 到底复用这一定义，还是另起一套 exact-image hash（[core.c#L314](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/core.c#L314), [v3设计#L397](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L397), [v3设计#L684](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L684)).
3. 更关键的是，digest 只能绑定“源程序”，不能单独解决“源 site 到 rewrite 后 site 的 remap”问题。当前 verifier 只保留 `orig_idx`，而 v3 想按 `orig_range` 做 plan materialization；如果 provenance 还是只有单点 `orig_idx`，那么 TOCTOU 只是从“程序错配”降成了“program 对上了，但 range remap 仍然不精确”（[v3设计#L430](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L430), [bpf_verifier.h#L580](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L580), [verifier.c#L21932](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L21932)).

### B5. fail-closed 的定义和实现是否一致？

结论：定义比 v2 清晰，但实现 contract 还没闭合，因此目前只能说“目标一致，接口未落地”。

理由：

1. 文档已经把失败分成三层：fatal load error、whole-bundle drop、per-site fallback。这比 v2 明显更清楚（[v3设计#L729](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L729)).
2. 但 emitter contract 没写清。`emit()` 的类型是 `int`，`emit_result` 又有 `fallback`；如果沿用当前 x86 POC 的风格，一旦 emitter 返回错，整个 JIT 会失败并回退解释器，而不是 per-site fallback（[v3设计#L514](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L514), [v3设计#L565](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L565), [bpf_jit_comp.c#L2145](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2145), [bpf_jit_comp.c#L2990](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2990), [bpf_jit_comp.c#L4235](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L4235)).
3. POC v2 审查已经证明当前实现并非全面 fail-closed：parser/load error 是 hard-fail，validation miss 多数是静默忽略，emit error 则可能导致 JIT 整体失败。v3 文档如果不明确改 emitter API，这个问题会原样延续（[poc-v2审查#L121](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/poc-v2-design-conformance-review.md#L121), [jit_directives.c#L248](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/jit_directives.c#L248)).

## C. 实现可行性

### C1. 从 POC v2 到 v3 的渐进路径是否现实？能否增量实现而不是推倒重来？

结论：能增量实现，但前提是把 “JIT-only MVP” 和 “full hybrid v3” 分开；Step 4 不是简单的延续，而是一个新门槛。

判断：

1. 文档的 Step 0/1 合理：v2 blob 兼容 shim、`SELECT family`、x86 通用 dispatcher，都能直接复用 POC v2 的 transport 和 `cmov_select` emitter（[v3设计#L1079](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1079), [v3设计#L1121](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1121), [v3设计#L1123](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1123)).
2. Step 2/3 也现实：`ADDR_MODE`、`ROTATE`、stack/map-value `WIDE_MEM` 本质都是纯 JIT family；不需要先解决 retained facts 和 block permutation（[v3设计#L1083](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1083), [v3设计#L1085](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1085)).
3. 真正的问题是 Step 4。`GUARD_ELIDE` 和 `CFG_DIAMOND` 不是“再多两个 family”这么简单，而是需要 retained facts、better provenance、rewrite 后元数据一致性，计划文档自己其实也已经把这些列为额外基础设施（[v3设计#L1087](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1087), [计划#L503](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L503), [计划#L508](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L508)).

### C2. 6 个具体 rule 的实现难度估计是否合理？

结论：前 4 个大体合理，后 2 个明显低估。

判断：

1. `cmov_select` 迁移到 `SELECT family` 基本可信。现有 v2 代码已经具备 matcher、两类 emitter 和 `addrs[]` commit 经验，改成 plan 消费者主要是 plumbing（[v3设计#L803](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L803), [jit_directives.c#L360](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/jit_directives.c#L360), [bpf_jit_comp.c#L1313](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L1313)).
2. `lea_fusion`、`rotate_fusion` 的实现量也基本可信。它们都属于单窗口 peephole，且 x86 JIT 本来就已有不少 target-specific peephole 和 BMI2/short-jump 选择逻辑（[v3设计#L855](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L855), [v3设计#L903](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L903), [bpf_jit_comp.c#L930](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L930), [bpf_jit_comp.c#L1967](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L1967)).
3. `wide_load` 只要严格限在 stack/map-value、non-`PROBE_MEM` 子集，我认为也还算可信；但如果把 packet/ctx 或 extable 路径算进去，成本会高很多（[v3设计#L912](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L912), [bpf_jit_comp.c#L2670](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2670), [bpf_jit_comp.c#L2743](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2743)).
4. `branch_reorder` 的 `250-400 LOC` 偏低。当前 verifier 的 patch 基础设施是 `1 -> N`，而 block permutation 需要更强的 helper、provenance、rewrite 后元数据一致性；计划文档自己也承认需要 `block-permutation helper` 和 `better provenance`（[v3设计#L1022](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1022), [verifier.c#L22013](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L22013), [计划#L508](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L508)).
5. `bounds_window` 的 `180-300 LOC` 明显低估。问题不在删一个 guard 的 patch 大小，而在 retained fact 的提取、保存、失效条件和跨路径 soundness（[v3设计#L1068](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1068), [计划#L267](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L267)).

### C3. 跨架构 target description 是否过度设计？arm64 需要多少额外工作？

结论：`target_desc` 本身不过度设计，但 `cpu_contract` 里混入的 `model_group/policy_id/workload_class` 对首版 bring-up 来说偏重；arm64 的工作量也被低估了。

判断：

1. `target_desc { arch_id, alts, alt_cnt, feature_bits }` 这个核内抽象很合理，因为 arm64 也有线性的 `offset[]` 映射和 per-insn body builder，并不排斥 region dispatcher（[v3设计#L604](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L604), [arm64_jit#L1907](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/arm64/net/bpf_jit_comp.c#L1907)).
2. 过重的是 `cpu_contract` 的 control-plane 字段。如果首目标只是 “第二架构可运行”，`model_group/policy_id/workload_class` 并不是必须先内核化的字段（[v3设计#L611](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L611)).
3. 文档把 arm64 主要估成 “alt table `100-180 LOC`” 和 “Step 5 `250-450 LOC`”，我认为偏低。实际至少还包括 arm64 dispatcher glue、每个 family 的 emitter、feature gating、以及和固定宽度指令/分支编码的重新验证（[v3设计#L646](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L646), [v3设计#L1146](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1146)).

我的估计是：首个 arm64 bring-up 更接近 `300-600 LOC` dispatcher/plumbing，加上每个 family `100-250 LOC` emitter/validator 适配。

### C4. 工作量估计（LOC）是否可信？

结论：JIT-only MVP 的 LOC 估计有一定可信度；full six-rule hybrid 的总量偏乐观。

理由：

1. 文档总估算大约是 Step 0-5 `1900-3180 LOC`（[v3设计#L1139](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1139)).
2. 这对 “parser + x86 dispatcher + 3 个纯 JIT family + logging” 来说不离谱，因为大量代码可以直接复用 v2 的 transport 和 x86 `cmov_select` 经验（[v3设计#L1150](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1150), [计划#L555](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L555)).
3. 但它没有显式算入四类必需成本：rewrite 后 liveness/CFG/provenance 维护、overlap arbitration、retained-fact plumbing、测试/benchmark/tooling 更新。对 `branch_reorder + bounds_window + arm64` 来说，这些成本不是边角料，而是主体工作量。

我的判断是：

- JIT-only MVP：`1200-2000 LOC` 级别，可信。
- full v3（含 `branch_reorder`/`bounds_window`/arm64）：更接近 `3000-5000+ LOC`，文档当前估计偏低。

## D. 论文故事

### D1. 这个设计能否支撑 OSDI/SOSP 论文的 novelty？

结论：能，但前提是论文主角是“bounded backend policy substrate”，而不是几条 peephole；同时必须至少落地一条 verifier-stage structural rule。

理由：

1. 计划文档已经把 novelty 写得很清楚：真正 novel 的是 mechanism/policy 分离、fail-closed substrate、部署控制权、policy-sensitivity 证据；单个 peephole 和 validator template 只是增量贡献（[计划#L42](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L42), [计划#L48](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L48)).
2. 如果最终实现只有 `cmov + lea + rotate + wide_load` 这类局部 JIT peephole，计划文档自己已经指出 novelty 不够，因为“局部 peephole 不需要 userspace 框架，kernel 直接加就行”（[计划#L483](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L483), [计划#L514](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L514)).
3. 真正能撑住论文的是：`cmov_select` 证明 userspace policy 能决定同一合法 site 的 lowering，`branch_reorder` 证明框架不只是 JIT peephole，digest/facts/remap/fail-closed 证明它是一个安全 substrate（[计划#L254](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L254), [计划#L255](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L255), [v3设计#L1191](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1191)).

### D2. “用户态定义 rule + 内核安全执行”这个 framing 与 existing work 的差距够大吗？

结论：和 K2/Merlin/EPSO 这类 bytecode optimizer 的差距是够大的；和传统 compiler pass/peephole DSL 的差距则主要来自部署位置与安全模型，而不是“rule”二字本身。

判断：

1. 对现有 BPF 优化工作，差距确实清楚：那些系统主要在 BPF bytecode/LLVM IR 层，触不到 backend lowering；v3 的卖点是直接控制 kernel BPF JIT backend，而且 policy owner 是特权 loader（[计划#L33](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L33), [计划#L82](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L82), [计划#L164](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L164)).
2. 但如果只说“用户定义 rule”，这个 framing 还不够大。真正应该强调的是：rule 是有界的、kernel-owned semantics、digest-bound、fail-closed、可 fleet rollout 的 backend policy substrate。否则会像一个安全阉割版 peephole DSL，而不是系统论文贡献（[v3设计#L20](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L20), [v3设计#L1182](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1182)).

### D3. 需要几个 rule + 几个 benchmark + 几个架构才能讲一个完整的故事？

结论：建议至少 `4` 个 rule、`6-8` 个 benchmark/工作负载类别、`2` 个架构。

建议配置：

1. rule：至少要覆盖两层。
`cmov_select`：policy-sensitive JIT lowering。
`branch_reorder`：policy-sensitive verifier rewrite。
`wide_load`：高收益 substrate。
`lea_fusion` 或 `rotate_fusion`：证明 family 泛化不是只为 `cmov` 写死。
`bounds_window` 可以作为 stretch goal，不建议绑定论文首版成败。
2. benchmark：至少要覆盖计划文档要求的几类问题。
需要 branch predictability、byte ladder、smallmul/hash/rotate、真实多函数程序、以及一个 end-to-end deployment（[计划#L384](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L384), [计划#L392](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L392)).
3. 架构：`x86 + arm64` 足够完整。计划文档理想上还想要小核 x86，但对机制论文来说，第二 ISA 比第三台机器更有说服力（[计划#L402](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L402)).

### D4. 当前最大的 gap 是什么？

结论：最大的技术 gap 是 retained facts + provenance + post-rewrite revalidation；最大的论文 gap 是 fixed kernel baseline 和端到端部署评估还没补齐。

理由：

1. 技术上，如果 `branch_reorder` 和 `bounds_window` 不能安全落地，v3 会退化成一个“多 family 的 JIT peephole 框架”，而计划文档已经明确说这单独不够 novel（[计划#L491](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L491), [计划#L514](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L514)).
2. 论文上，即使机制落地了，若没有 fixed kernel baselines、真实程序接受率、至少一个 production-like deployment，就还达不到计划里给 OSDI/SOSP 设的门槛（[计划#L53](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L53), [计划#L374](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L374), [计划#L400](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L400)).

## E. 具体问题

### E1. `wide_load` 作为 JIT-level（不是 verifier rewrite）是否可行？

结论：可行，而且这是正确方向；但必须严格限在 stack/map-value、non-`PROBE_MEM`、non-packet/ctx 的安全子集。

理由：

1. v1 的问题在于它做的是 BPF bytecode rewrite，用户态也能做；v3 把它改成 native emission 选择，方向上与 `cmov_select` 一致（[计划#L536](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L536), [计划#L558](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L558), [v3设计#L911](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L911)).
2. 当前 verifier 的 `insn_aux_data` 已有 `ptr_type`、map 相关元数据，可以作为 materialization 时判定 mem class 的基础；虽然 JIT 阶段本身拿不到 `insn_aux_data`，但 v3 可以在 Step C 先把安全子集固化进 `plan`（[bpf_verifier.h#L525](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L525), [v3设计#L428](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L428)).
3. x86 JIT 当前对 `LDX|PROBE_MEM*` 会额外生成 extable/fixup；这说明 `wide_load` 一旦扩到 `PROBE_MEM` 或 packet/ctx，复杂度会陡增。文档现在把这些排除掉，是正确收窄（[bpf_jit_comp.c#L2670](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2670), [bpf_jit_comp.c#L2743](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L2743), [v3设计#L953](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L953)).

### E2. `branch_reorder` 作为 verifier-stage rule 是否需要新的 verifier 基础设施？

结论：需要。

至少需要：

1. block permutation helper 或等价的 `N -> M` rewrite helper。当前 `bpf_patch_insn_data()` 是围绕单点 patch 设计的，不是显式的 block permutation API（[verifier.c#L22013](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L22013), [计划#L508](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L508)).
2. 更强的 provenance。当前只有 `orig_idx`，不能精确表达 “两个 arm 被交换以后，每个新 insn 来自哪个原始区间”（[bpf_verifier.h#L580](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L580), [v3设计#L387](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L387)).
3. rewrite 后的 liveness/CFG 元数据刷新。否则后续 lower stage 的 `LIVEOUT_ONLY`、`NO_INTERIOR_EDGE` 可能用错数据（[verifier.c#L26047](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26047), [bpf_verifier.h#L596](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L596)).

### E3. `bounds_window` 的 retained facts 从哪来？verifier 现在暴露这些 facts 吗？

结论：当前没有稳定暴露。

理由：

1. verifier 的 packet bounds 证明是在动态 `bpf_reg_state` 里维护的，例如 `find_good_pkt_pointers()` 会把某个 `pkt(id=n, off=0)` 的安全窗口记录到 `reg->range`；这不是现成的 rule API（[bpf.h#L986](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf.h#L986), [verifier.c#L16576](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L16576)).
2. `insn_aux_data` 虽然保留了 `ptr_type`、`map_key_state`、`loop_inline_state`、`live_regs_before`、`scc` 等元数据，但没有 “某个 guard 已证明某个 access window 在所有到达态都安全” 这种 retained fact（[bpf_verifier.h#L525](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L525), [bpf_verifier.h#L596](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/include/linux/bpf_verifier.h#L596)).
3. `do_check()` 结束后 `explored_states` 会被释放，最终 `insn_aux_data` 也会在 verifier 结束时清掉。所以如果要支持 `bounds_window`，必须在 `do_check()` 期间主动抽取并保存新的 per-site retained-fact side table，而不是期待现有 API 直接可用（[verifier.c#L26066](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26066), [verifier.c#L26195](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/kernel/bpf/verifier.c#L26195)).

### E4. `lea_fusion` 和 `rotate_fusion` 是否可以用纯 JIT peephole 实现而不需要用户态 rule？如果可以，论文 story 是否被削弱？

结论：可以，而且从工程归宿看更像应该内建在 JIT 里；如果把它们当论文主角，story 会被削弱。

理由：

1. 计划文档自己就把 `lea_fusion`、`rotate_fusion`、`wide_load` 归入 “substrate 家族”，即主要是 kernel peephole，只是复用框架基础设施（[计划#L258](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L258)).
2. 当前 x86 JIT 本来就有不少 target-specific peephole：`mov imm32=0 -> xor`、`cmp imm0 -> test`、BMI2 shift 指令选择、short jump 选择等。继续往这层加 `lea`/`rotate` 在工程上完全自然（[bpf_jit_comp.c#L930](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L930), [bpf_jit_comp.c#L1276](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L1276), [bpf_jit_comp.c#L1967](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L1967), [bpf_jit_comp.c#L3027](/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/net/bpf_jit_comp.c#L3027)).
3. 这不会否定 v3 框架，但会影响论文 framing。更好的用法是把 `lea/rotate/wide_load` 当作“框架泛化与代码复用”的 supporting evidence，而把 novelty 主轴放在 `cmov_select + branch_reorder + fail-closed policy substrate` 上。

### E5. `cmov_select` 在 POC v2 中是负向性能（`+13.2%`），v3 框架如何解决这个问题？

结论：v3 解决的是“什么时候不该用 `cmov`”，不是“让 `cmov` 神奇变快”。机制上可解，证据链还没补齐。

理由：

1. POC v2 的 slowdown 已经证明 `cmov_select` 是 policy-sensitive，而不是 universally good：当前 benchmark 只有一个 site，代码尺寸只省 1 字节，且 workload 的分支并不随机，所以 `cmov` 完全可能比分支更慢（[poc-v2审查#L243](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/poc-v2-design-conformance-review.md#L243), [poc-v2审查#L271](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/poc-v2-design-conformance-review.md#L271)).
2. v3 的机制正好允许把 `cmov_select` 变成 “同一合法 site 上的多备选 lowering”：`X86_ALT_CMOV`、`X86_ALT_BRANCH_FALLBACK`、arm64 `CSEL`，再配上 CPU contract / policy metadata，由 userspace 选择何时请求哪种 alt（[v3设计#L768](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L768), [v3设计#L611](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L611), [v3设计#L1184](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/jit-pass-framework-v3-design.md#L1184)).
3. 但文档目前还没把 policy 证据闭环写实。计划文档要求 fixed kernel baselines、static/profiled advisor、以及在不同硬件/workload/program 上证明 userspace policy 确实优于固定 heuristic；这些实验现在还没完成（[计划#L376](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L376), [计划#L386](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L386), [计划#L566](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md#L566)).

## 总体评分

`6.5/10`

拆开看更准确：

- 如果按 “JIT-only extensible lowering MVP” 评分：`7.5/10`。
- 如果按 “包含两条 verifier-stage rule、可支撑论文 novelty 的 full v3” 评分：`5.5-6/10`。

## 核心建议

1. 把第一阶段 MVP 明确收窄到 `SELECT + ADDR_MODE + ROTATE + WIDE_MEM + digest/logging + x86 dispatcher`，先把 JIT-only substrate 做扎实。
2. 把 `branch_reorder` 单独拆成 verifier 基础设施里程碑：`block permutation helper + orig_range provenance + rewrite 后 liveness/CFG 刷新` 没落地前，不要把它算作“再加一个 family”。
3. 暂时把 `bounds_window` 从首版论文必选项里降级为 stretch goal；它依赖 retained facts，而当前文档对 facts 的来源、shape、失效条件都还没定义好。
4. 论文 story 要把 `lea/rotate/wide_load` 明确定位为 substrate/supporting evidence，把 novelty 主轴放在 `cmov_select + branch_reorder + fail-closed backend policy substrate + fixed kernel baselines + deployment`.
5. 在设计文档里补三个硬性不变量：`rewrite 后必须重算/刷新哪些元数据`、`overlap plan 如何裁决`、`emit failure 如何保证 per-site fallback 而不是整次 JIT 失败`。
