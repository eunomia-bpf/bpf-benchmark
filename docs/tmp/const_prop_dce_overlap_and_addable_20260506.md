# const_prop / dce vs kernel verifier overlap

Date: 2026-05-06

Scope:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs`
- `bpfopt/crates/bpfopt/src/passes/dce.rs`
- `bpfopt/crates/bpfopt/src/passes/utils.rs`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- 6 个 x86 KVM smoke artifact:
  - `corpus/results/x86_kvm_corpus_20260506_223040_471337/details/apps/otelcol-ebpf-profiler__profiling.json`
  - `corpus/results/x86_kvm_corpus_20260506_223334_701834/details/apps/bcc__set.json`
  - `corpus/results/x86_kvm_corpus_20260506_223639_781587/details/apps/bpftrace__set.json`
  - `corpus/results/x86_kvm_corpus_20260506_223933_808849/details/apps/tracee__monitor.json`
  - `corpus/results/x86_kvm_corpus_20260506_231413_833842/details/apps/katran.json`
  - `corpus/results/x86_kvm_corpus_20260506_231737_864379/details/apps/cilium__agent.json`

## Bottom line

可以删的东西分两层：

1. `dce` pass 自己的 CFG-unreachable 和 `JA +0` NOP cleanup 可以删，只保留 dead-register-def removal。
2. `const_prop` 的 branch folding 可以删，但必须和它的 internal CFG cleanup 一起处理；如果保留 branch folding，就不能删 `const_prop.rs:251-259`，否则单独 `bpfopt --pass const_prop` 后的 ReJIT 可能在 kernel `check_cfg()` 阶段因为 raw unreachable insn 失败。

不能直接删 shared `utils.rs:789-887` / `utils.rs:889-906`，因为 `map_inline` 仍在复用这些 cleanup helper。要删的是 `DcePass` 的调用面，不是 shared utility 本体。

数据上，当前 artifacts 不能精确拆 `const_prop` 的 ALU materialization vs branch folding。原因很直接：`ConstPropPass` 返回 `diagnostics: vec![]`，只记录 `sites_applied = replacements.len()`：`bpfopt/crates/bpfopt/src/passes/const_prop.rs:264-273`。`PassReport` 会原样序列化 diagnostics：`bpfopt/crates/bpfopt/src/main.rs:1381-1396`。6 个 smoke 里 `const_prop` diagnostics length 全是 0。

`dce` 可以精确拆：6 个 smoke 合计 `dce` 2964 sites，其中 dead-def 2431，NOP 533，unreachable 0。按 `dce` 可分类 sites 算，唯一价值 dead-def 是 82.0%，重复的 NOP/unreachable 是 18.0%。

## Kernel behavior anchor

Kernel verifier 已覆盖的 bytecode rewrite：

- Branch direction oracle: `is_branch_taken()` 对常量 scalar / pointer-null branch 返回 taken/not-taken/unknown：`vendor/linux-framework/kernel/bpf/verifier.c:17199-17246`。
- Known branch 只走可行边：`vendor/linux-framework/kernel/bpf/verifier.c:17868-17910`。
- Privileged verifier hard-wire dead branch to `JA`: `vendor/linux-framework/kernel/bpf/verifier.c:22647-22670`。
- Privileged verifier removes unseen dead ranges: `vendor/linux-framework/kernel/bpf/verifier.c:22673-22695`。
- Privileged verifier removes `JA +0` and `may_goto +0` NOP: `vendor/linux-framework/kernel/bpf/verifier.c:22697-22722`。
- 这些 rewrite 在 verifier/JIT fixup 前执行：`vendor/linux-framework/kernel/bpf/verifier.c:26497-26508`。

Kernel verifier 不覆盖的 bytecode rewrite：

- General ALU materialization. Kernel tracks scalar bounds/tnum through ALU, e.g. `adjust_scalar_min_max_vals()` and `BPF_MUL/AND/OR/XOR/...` state updates: `vendor/linux-framework/kernel/bpf/verifier.c:16339-16491`, but it does not rewrite arbitrary `rX op= rY/imm` into `MOV/LD_IMM64` for final bytecode.
- General dead register def removal. Kernel's post-verify cleanup list here is branch hard-wire, unseen-code removal, and NOP removal; no equivalent of bpfopt's liveness-based `ALU/LDX/LD_IMM64 dst dead` deletion is present in that cleanup sequence: `vendor/linux-framework/kernel/bpf/verifier.c:26497-26508` vs `bpfopt/crates/bpfopt/src/passes/utils.rs:908-971`。

One important constraint:

- Kernel raw CFG pass rejects raw unreachable instructions before the later post-verify dead-code optimizer: comments at `vendor/linux-framework/kernel/bpf/verifier.c:56-66`, DFS edges at `vendor/linux-framework/kernel/bpf/verifier.c:19119-19237`, reject at `vendor/linux-framework/kernel/bpf/verifier.c:19303-19319`。
- Therefore, if bpfopt itself changes a conditional branch into `JA` and leaves the skipped block in the bytecode, the program can fail before `opt_remove_dead_code()` ever runs.

## A. const_prop exact overlap

### 1. Branch folding

Code:

- Dispatch: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:383-391`
- Rewrite: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:422-435`
- Branch condition evaluator: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:464-492`
- Folded jump remap: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:694-729`

Kernel duplicate:

- `is_branch_taken()` + one-edge verifier walk + `opt_hard_wire_dead_code_branches()`: `vendor/linux-framework/kernel/bpf/verifier.c:17199-17246`, `vendor/linux-framework/kernel/bpf/verifier.c:17868-17910`, `vendor/linux-framework/kernel/bpf/verifier.c:22647-22670`。

Delete answer:

- 可删，但不是 zero-risk cleanup。Final JIT 层面是重复的，因为 kernel 在 ReJIT 看到 bpfopt 输出后会 hard-wire 同类 branch。
- 风险是 bpfopt pipeline 内部 enablement：当前 `const_prop` branch folding 可以让后续 `dce` 在同一 userspace bytecode 上看见 dead path，从而暴露 dead-def。例子见 `dce_removes_dead_defs_exposed_by_const_prop`: `bpfopt/crates/bpfopt/src/passes/dce.rs:218-237`。
- 对 map_inline 之后的新 branch：kernel 会在 map_inline 后的 ReJIT 看到那些常量，所以 final JIT 不需要 bpfopt branch fold。bpfopt 自己是否需要，取决于后续 pass 是否还要在 userspace bytecode 上吃到这个 dead path。`const_prop_folds_branch_after_map_inline` 证明当前确实存在 map_inline -> const_prop branch fold path：`bpfopt/crates/bpfopt/src/passes/const_prop.rs:1037-1082`。

Data answer:

- 当前 6 个 artifact 不能确认 NEW vs OLD dead branch。`const_prop` summary 没有 per-kind diagnostic，只有总 `sites_applied`。
- 能看到的是 `const_prop` internal cleanup 的净删指令非常大，说明它确实在自己的输出里删除了大量 unreachable code；但这些 cleanup 来自哪些 branch fold site，现有 result 没有记录。

### 2. Internal CFG-unreachable cleanup

Code:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:251-259`

Kernel duplicate:

- Dynamic dead-code cleanup duplicate：`vendor/linux-framework/kernel/bpf/verifier.c:22673-22695`。
- 但 raw CFG reject 发生更早：`vendor/linux-framework/kernel/bpf/verifier.c:19303-19319`。

Delete answer:

- 如果保留 `const_prop` branch folding，则不能删。原因是 `const_prop` 可以把 conditional jump 改成 `JA/NOP`，并立即制造 raw CFG-unreachable bytecode；单独运行 `bpfopt --pass const_prop` 后 daemon 会立刻 ReJIT，kernel 可能先在 `check_cfg()` reject。
- 如果删除 branch folding，则可以删。ALU materialization 本身不制造 CFG unreachable；此时 `const_prop` 不应该再承担 generic cleanup 职责。
- 测试 `const_prop_removes_dead_target_after_false_branch_fold` 正在覆盖这个 cleanup：`bpfopt/crates/bpfopt/src/passes/const_prop.rs:1084-1104`。

### 3. ALU materialization

Code:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:402-420`
- Local ALU evaluator: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:437-564`
- Verifier exact oracle feed: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:121-164`

Kernel duplicate:

- Kernel tracks scalar facts through ALU: `vendor/linux-framework/kernel/bpf/verifier.c:16339-16491`。
- Kernel does not generally rewrite ALU into `MOV/LD_IMM64` bytecode.

Delete answer:

- 保留。这是 `const_prop` 的非重复核心。
- `const_prop_folds_alu_chain_to_constant_mov` / `const_prop_folds_alu32_chain_to_mov32_imm` / `const_prop_tracks_ldimm64_constants` 覆盖了这个行为：`bpfopt/crates/bpfopt/src/passes/const_prop.rs:918-970`。

Data answer:

- 现有 artifact 无法拆出多少 ALU sites 来自 map_inline 暴露常量、多少来自原始 scalar bytecode。需要 per-replacement diagnostics 或一次离线 instrumented rerun。
- 现有 `sites_applied` 总数 28099 是 ALU materialization + branch folding 的混合；不能当作 unique value。

### 4. Constant LD_IMM64 emit

Code:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:661-670`

Delete answer:

- 保留。它服务于 ALU materialization，尤其是 64-bit 常量超出 signed i32 `MOV64_IMM` 时。
- 例子：`const_prop_tracks_ldimm64_constants` 让 64-bit result 变成 two-slot `LD_IMM64`：`bpfopt/crates/bpfopt/src/passes/const_prop.rs:958-970`。

## B. dce exact overlap

### 1. CFG-unreachable removal

Code:

- `DcePass` call site: `bpfopt/crates/bpfopt/src/passes/dce.rs:43-49`
- Shared utility: `bpfopt/crates/bpfopt/src/passes/utils.rs:789-887`

Kernel duplicate:

- Raw CFG reject: `vendor/linux-framework/kernel/bpf/verifier.c:19303-19319`
- Dynamic unseen-code removal: `vendor/linux-framework/kernel/bpf/verifier.c:22673-22695`

Delete answer:

- 从 `DcePass` 删除 `dce.rs:43-49`。
- 不要现在删 `utils.rs:789-887`。`map_inline` 仍调用 `eliminate_unreachable_blocks()` after rewrite cleanup：`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1212`。`const_prop` 当前也调用 `eliminate_unreachable_blocks_with_cfg()`：`bpfopt/crates/bpfopt/src/passes/const_prop.rs:251-259`。
- 风险：如果还支持 in-process multi-pass test pipeline 且某个前序 pass 在不 ReJIT 的情况下制造 raw unreachable，删掉 DcePass cleanup 会改变这些测试期望；daemon v3 的 per-pass ReJIT 模式下不应依赖后续 dce 修 raw CFG。

### 2. `JA +0` NOP removal

Code:

- `DcePass` loop: `bpfopt/crates/bpfopt/src/passes/dce.rs:60-67`
- Shared utility: `bpfopt/crates/bpfopt/src/passes/utils.rs:889-906`

Kernel duplicate:

- `opt_remove_nops()` removes `JA +0`: `vendor/linux-framework/kernel/bpf/verifier.c:22697-22722`。

Delete answer:

- 从 `DcePass` 删除 `dce.rs:60-67`。
- 不要现在删 `utils.rs:889-906`，因为 `map_inline` 还用：`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1217`。
- 风险：后续 userspace passes 看见的 bytecode 可能多留 `JA +0`，但 final kernel JIT 会删；如果某些 scan pass 对 `JA +0` 敏感，需要先跑 targeted tests。

### 3. Dead register def removal

Code:

- `DcePass` call: `bpfopt/crates/bpfopt/src/passes/dce.rs:51-58`
- Implementation: `bpfopt/crates/bpfopt/src/passes/utils.rs:908-971`

Kernel duplicate:

- 未发现等价 kernel bytecode rewrite。Kernel verifier 有 liveness/state metadata，但 post-verify rewrite list 没有 general dead-def deletion：`vendor/linux-framework/kernel/bpf/verifier.c:26497-26508`。

Delete answer:

- 保留。这是 `dce` 当前唯一明确非重复价值。

## Exact delete list

| file:line | action | reason | risk |
|---|---:|---|---|
| `bpfopt/crates/bpfopt/src/passes/dce.rs:43-49` | delete from `DcePass` | CFG-unreachable cleanup overlaps kernel `opt_remove_dead_code`; `DcePass` should be dead-def only | Low/medium: standalone in-process tests that expect dce to clean branch-folded code must change |
| `bpfopt/crates/bpfopt/src/passes/dce.rs:60-67` | delete from `DcePass` | `JA +0` cleanup overlaps kernel `opt_remove_nops` | Low: final ReJIT still removes NOPs; scan passes may see extra NOPs if run after dce in userspace |
| `bpfopt/crates/bpfopt/src/passes/dce.rs:73-83` | shrink diagnostics | After removing unreachable/NOP counters, keep only dead-def diagnostic | Low |
| `bpfopt/crates/bpfopt/src/passes/dce.rs:7-10` | update imports | Remove unused `compose_addr_maps`, `eliminate_nops`, `eliminate_unreachable_blocks_with_cfg` from DcePass path if no longer used | Low |
| `bpfopt/crates/bpfopt/src/passes/dce.rs:12-19` | update comment | Comment is stale: it says dead-def is future work while code already runs it | Low |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:389-391` | optional delete | Stops branch folding dispatch; kernel duplicates final branch hard-wire | Medium: loses userspace pipeline enablement for later passes |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:422-435` | optional delete | Direct overlap with `is_branch_taken` + `opt_hard_wire_dead_code_branches` | Medium: may reduce dce dead-def exposure in same userspace pipeline |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:193` / `206-210` / `244-249` | delete with branch folding | `nop_pcs` only exists to preserve false branch folds as NOP | Low if branch folding removed |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:243` and `694-729` | delete with branch folding | `fixup_folded_jumps()` only remaps folded conditional branches; `fixup_all_branches()` at `242` remains needed for LD_IMM64 growth | Low if branch folding removed |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:464-492` | delete with branch folding | `evaluate_jump_condition()` becomes dead code | Low if branch folding removed |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:574-588` and `598-604` | delete with branch folding | Jump operand helpers become dead code; keep `alu_imm_operand()` at `590-596` | Low if branch folding removed |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs:251-259` | delete only after branch folding is deleted | Internal CFG cleanup is duplicate only if const_prop no longer manufactures raw unreachable bytecode | High if branch folding remains: kernel `check_cfg()` can reject raw unreachable |
| `bpfopt/crates/bpfopt/src/passes/utils.rs:789-887` | keep for now | Shared helper still used by map_inline and current const_prop | Deleting globally would break map_inline cleanup |
| `bpfopt/crates/bpfopt/src/passes/utils.rs:889-906` | keep for now | Shared helper still used by map_inline | Deleting globally would touch map_inline, which is out of scope |
| `bpfopt/crates/bpfopt/src/passes/utils.rs:908-971` | keep | Unique dead-register-def removal | Removing loses the only clearly non-redundant dce value |

Test fallout to expect:

- Delete/rewrite `const_prop_folds_constant_branches_to_ja_and_nop`: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:982-1006`。
- Delete/rewrite branch-folding verifier-oracle and map-inline tests: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:1008-1082`。
- Delete/rewrite cleanup-specific const_prop tests: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:1084-1145`。
- Delete/rewrite dce unreachable/NOP tests: `bpfopt/crates/bpfopt/src/passes/dce.rs:168-215`。
- Keep dead-def test: `bpfopt/crates/bpfopt/src/passes/dce.rs:218-237`。

## Data validation

Extraction source:

- `passes[].bpfopt_summary` under `rejit_result.per_program`.
- Counting unit is the bpfopt pass report entry, not "accepted final ReJIT optimization"; a pass can have a `bpfopt_summary` even if the following ReJIT rejects that candidate.
- For `dce`, categories come from diagnostics strings emitted at `bpfopt/crates/bpfopt/src/passes/dce.rs:75-83`。
- For `const_prop`, categories cannot be extracted because diagnostics are empty by implementation: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:268-273`。

Table notes:

- `const_prop ALU` and `const_prop branch` are `n/a` because current reports do not classify replacements.
- `const_prop CFG` is a lower bound in removed instructions, not sites. It is `max(0, -sum(insn_delta))`; actual removed CFG instructions can be higher if any ALU materialization emitted 2-slot `LD_IMM64`.
- `const_prop total sites` is included because it is the only exact current count for `const_prop` replacements.

| app | const_prop ALU materialize | const_prop branch fold | const_prop CFG cleanup lower bound | const_prop total sites | dce unreachable | dce NOP | dce dead-def |
|---|---:|---:|---:|---:|---:|---:|---:|
| otel | n/a | n/a | >=26770 insns | 1672 | 0 | 185 | 1373 |
| bcc | n/a | n/a | >=9 insns | 14 | 0 | 2 | 28 |
| bpftrace | n/a | n/a | >=0 insns | 8 | 0 | 0 | 0 |
| tracee | n/a | n/a | >=75207 insns | 23658 | 0 | 328 | 855 |
| katran | n/a | n/a | >=0 insns | 167 | 0 | 0 | 0 |
| cilium | n/a | n/a | >=5530 insns | 2580 | 0 | 18 | 175 |
| total | n/a | n/a | >=107516 insns | 28099 | 0 | 533 | 2431 |

Exact shares:

- `dce` classified sites only: duplicate = 533 NOP/unreachable = 18.0%; unique = 2431 dead-def = 82.0%。
- All pass sites including `const_prop`: exact duplicate/unique share is not computable from current artifacts. The hard bounds are too wide to be useful:
  - If every `const_prop` site were branch fold, duplicate = `(28099 + 533) / (28099 + 2964) = 92.2%`。
  - If every `const_prop` site were ALU materialization, duplicate = `533 / (28099 + 2964) = 1.7%`。
- The lower-bound CFG cleanup count, `>=107516` instructions, proves `const_prop` is doing large cleanup work, but it is an instruction count and should not be mixed into site-count percentages.

Conclusion from data:

- `dce` data supports deleting only the redundant DcePass cleanup calls, not deleting DCE wholesale.
- `const_prop` data does not support a precise ALU-vs-branch deletion decision. Add per-kind instrumentation in `bpfopt` report or do an offline instrumented rerun before deleting branch folding if paper attribution needs exact numbers.

## Addable non-overlap candidates

Ranked by likely paper payoff, not by ease.

### 1. Dead spill/fill + stack-slot coalescing

- Kernel status: only removes a narrow fastcall spill/fill pattern: `vendor/linux-framework/kernel/bpf/verifier.c:24866-24897`。No general stack-slot coalescing / address-taken-safe spill lifetime compaction.
- Catch cost: Medium/high. Need stack def-use, address-taken detection, helper/kfunc memory argument alias gates, and verifier-state compatibility.
- Paper payoff estimate: High. Existing `dce` dead-def sites are numerous (2431 in 6 smoke), and stack traffic is a common JIT cost source. This is the most direct successor to dead-register-def removal.
- Risk: High if pointer/dynptr/refstate spills or helper-visible stack ranges are moved. Start with scalar-only, non-address-taken, single-def/single-use slots.

### 2. Strength reduction after const/map specialization

- Kernel status: verifier tracks `BPF_MUL`, shifts, bounds and tnum, e.g. `BPF_MUL` in `adjust_scalar_min_max_vals()`: `vendor/linux-framework/kernel/bpf/verifier.c:16392-16395`; it does not rewrite BPF bytecode `mul by power-of-two -> lsh`, `mod pow2 -> and`, or simple div/mul constant forms in the generic verifier cleanup.
- Catch cost: Low/medium. Use existing const facts and local instruction rewrite validators.
- Paper payoff estimate: Medium/high, especially after `map_inline` and ALU materialization expose constants.
- Risk: Medium. Signed vs unsigned, ALU32 vs ALU64, division-by-zero BPF semantics, and verifier range semantics must be exact.

### 3. PHI-style merge simplification

- Kernel status: verifier joins/prunes states; it does not rewrite bytecode at merge points into simpler MOV/select/store forms. Branch hard-wire only covers proven-dead edges.
- Catch cost: Medium. Need CFG, dominance/post-dominance-ish shape matching, liveness, and branch target safety.
- Paper payoff estimate: Medium. Good fit after map_inline/const_prop expose equal values across arms.
- Risk: Medium. Register type equality is not enough; pointer provenance and scalar precision must be preserved. Start scalar-only.

### 4. PGO branch layout / branch alignment hint

- Kernel status: kernel hard-wires dead branches, but it does not own profile-guided layout policy for live branches. Existing `branch_flip` is already a real per-site PGO path and enforces PMU fields in bpfopt code.
- Catch cost: Medium/high. Needs real `bpfprof --per-site` data and target-specific layout model; no heuristic fallback.
- Paper payoff estimate: Medium for branch-heavy apps; potentially high in Paper B, but not as a default runner policy yet.
- Risk: Medium/high. Bad profile data can regress branch prediction. Keep strict `branch_count`, `branch_misses`, `miss_rate`, `taken`, `not_taken` requirements.

### 5. Loop-invariant code motion

- Kernel status: kernel has `optimize_bpf_loop()` for inlining `bpf_loop` helper calls: `vendor/linux-framework/kernel/bpf/verifier.c:24729-24864`; that is not general LICM for open-coded loops.
- Catch cost: High. Need loop discovery, invariant proof, helper/memory side-effect model, and verifier-safe placement.
- Paper payoff estimate: Medium but app-dependent. Likely best for packet loops and repeated map/stack scalar calculations.
- Risk: High. Moving loads across helper calls or packet-bound checks can break verifier assumptions. Start with pure ALU over scalar constants and no helper/memory crossing.

### 6. Local instruction scheduling / register-pressure hints

- Kernel status: verifier validates and some JITs lower helpers; it is not a general instruction scheduler or register allocator for BPF bytecode. The generic verifier cleanup list is not scheduling: `vendor/linux-framework/kernel/bpf/verifier.c:26497-26508`。
- Catch cost: High. Need target model and strict dependency analysis.
- Paper payoff estimate: Low/medium unless targeted to known latency chains. More useful as small target-specific kinsn/layout hints than as broad reordering.
- Risk: High. Reordering across memory/helper/verifier-sensitive pointer ops is dangerous. Start with same-basic-block pure ALU scheduling only.

### 7. Helper specialization beyond map_inline

- Kernel status: the obvious examples are already partly covered. Kernel inlines `bpf_jiffies64`: `vendor/linux-framework/kernel/bpf/verifier.c:24384-24407`; x86 verifier path inlines `get_smp_processor_id` / current task helpers when supported: `vendor/linux-framework/kernel/bpf/verifier.c:18618-18632`, `vendor/linux-framework/kernel/bpf/verifier.c:24409-24443`; arch JITs can also claim helper inlining, e.g. arm64: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3213-3222`。
- Catch cost: Medium/high if targeting helpers not already covered. Requires a whitelist with per-invocation stability proof.
- Paper payoff estimate: Low/medium. Do not spend effort on `bpf_jiffies64`, `bpf_get_smp_processor_id`, or current-task helpers; those are duplicate on relevant kernels.
- Risk: High. Many helpers are time-, task-, CPU-, packet-, or map-state dependent. Treat this as a narrow whitelist project, not a general helper-inline pass.

## Recommendation

Delete now:

- Make `DcePass` dead-def only: remove `dce.rs:43-49` and `dce.rs:60-67`, keep `utils.rs:908-971`。
- Keep shared cleanup utilities because `map_inline` still uses them.
- Update dce diagnostics/tests accordingly.

Do not delete yet without instrumentation:

- `const_prop` branch folding and internal cleanup. Final JIT overlap is real, but current data cannot quantify ALU-vs-branch sites, and branch folding can enable userspace-side dead-def removal. First add an analysis-only rerun or temporary bpfopt report counters:
  - `const_prop_alu_materialized`
  - `const_prop_branch_folded_taken`
  - `const_prop_branch_folded_not_taken`
  - `const_prop_cleanup_removed_insns`
  - `const_prop_oracle_sourced` vs `const_prop_local_sourced`
- Keep that as analysis-side / temporary pass reporting; do not add benchmark-framework rollups or derived performance metrics.

Best add path:

1. Dead spill/fill + stack-slot coalescing, scalar-only first.
2. Strength reduction after const/map specialization.
3. PHI-style merge simplification.
4. PGO branch layout/hint under the strict branch_flip per-site PMU model.

Net estimate:

- DCE cleanup deletion removes 533/2964 measured dce sites of redundant work while preserving the 2431/2964 unique dead-def sites.
- Const_prop branch/cleanup deletion could remove a large amount of redundant userspace cleanup work (`>=107516` cleaned instructions in these smoke artifacts), but the exact final-performance cost/benefit is unknowable from current summaries. Treat it as an A/B after adding classification, not as an immediate blind deletion.
