# bpfopt map_inline / const_prop / dce vs kernel verifier

Date: 2026-05-06

Scope: source read of:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs`
- `bpfopt/crates/bpfopt/src/passes/dce.rs`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- verifier-log support code where needed: `bpfopt/crates/kernel-sys/src/verifier_log.rs`, `vendor/linux-framework/kernel/bpf/log.c`

## Bottom line

`map_inline` is not redundant with the kernel verifier. It uses verifier state only as a key oracle; the actual optimization is replacing map lookups / map-value loads with constants from userspace-captured map snapshots. The kernel verifier cannot infer live map contents from bytecode.

`const_prop` is partially redundant. The kernel verifier already tracks scalar constants/ranges and already prunes constant branches, but bpfopt materializes constants by rewriting bytecode into `MOV32/MOV64/LD_IMM64` and `JA/NOP` forms. That can matter for the final JITed code and for later bpfopt passes, especially after `map_inline` exposes map values as constants. For pure scalar branch folds, many `sites_applied` are likely cases the kernel already prunes internally.

`dce` is mostly redundant for CFG-unreachable code and `ja +0` NOPs because the privileged verifier already removes dead code and NOPs before JIT. Its non-redundant part is dead register definition removal, plus keeping bpfopt's own intermediate bytecode structurally valid after earlier rewrites.

## 1. Why `map_inline` needs `log_level=2` verifier states

### What information it takes

`map_inline` reads three concrete verifier facts at each `bpf_map_lookup_elem()` call:

1. The call-site verifier state for `pc == call_pc`.
   It collects all verifier-state occurrences at the lookup call PC, runs extraction per occurrence, and rejects the site if occurrences disagree: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:345-387`.

2. `R2` as a fixed frame-pointer-relative stack pointer.
   `r2_stack_range_at_call()` requires `state.regs[2]`, requires type `"fp"`, and reads its fixed `offset`: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:445-469`.

3. Key bytes from verifier stack state.
   `constant_stack_bytes_for_range()` walks `[fp+off, fp+off+key_size)`: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:472-489`.
   `constant_stack_byte()` interprets verifier stack slot type bytes: `0` means literal zero, `r` means spilled scalar, anything else rejects the byte; spilled scalar bytes come from `state.value`: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:491-520`.

For scalar stack values, `map_inline` requires the verifier's explicit precise marker:

- `verifier_known_scalar_value()` accepts only `reg_type == "scalar"` and `precise == true`, then reads `exact_u64()` / `exact_u32()`: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:709-714`.
- There is a regression test that refuses an imprecise stack scalar even when the numeric bytes are present: `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1492-1528`.

So yes: it needs `R2` stack pointer offset, concrete key bytes, and precise scalar values for spilled key material. It does not use arbitrary scalar facts as optimization output; scalar facts are used to prove the stack key bytes.

After the key is known, the pass uses map snapshots:

- Direct lookup path reads `program.map_provider.lookup_elem(map_id, encoded_key, ...)`: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1297-1344`.
- Fixed loads from the returned value pointer become constant loads via `read_scalar_from_value()` and `emit_constant_load()`: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1393-1405`.
- Map-in-map resolves the outer key to a live inner map id from `program.map_inner_map_ids`, then snapshots the inner map value: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1694-1717`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1770-1805`.
- Pseudo-map-value direct loads are also constantized from snapshots: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1935-2002`.

### Why `log_level=2`

The local parser is explicitly for verifier logs captured with `log_level=2`: `bpfopt/crates/kernel-sys/src/verifier_log.rs:1-12`.

The kernel emits the relevant full states and mark-precision information only under level 2 in key places:

- Full verifier state before instruction processing is printed when `env->log.level & BPF_LOG_LEVEL2`: `vendor/linux-framework/kernel/bpf/verifier.c:21621-21627`.
- `mark_precise` backtracking trace and parent states are level-2-only: `vendor/linux-framework/kernel/bpf/verifier.c:4718-4726`, `vendor/linux-framework/kernel/bpf/verifier.c:5256-5374`.
- The kernel log printer emits `P` before precise scalar values: `vendor/linux-framework/kernel/bpf/log.c:673-685`.
- The stack slot type encoding used by bpfopt is printed as `r`, `0`, `?`, etc.: `vendor/linux-framework/kernel/bpf/log.c:538-545`, `vendor/linux-framework/kernel/bpf/log.c:768-798`.

The daemon also treats level 2 as the path for state chaining and `mark_precise` traces: `daemon/src/commands.rs:633-648`.

### Without those states

Official CLI behavior: `map_inline` requires `--verifier-states`, `--map-values`, and `--map-ids`; missing side inputs fail validation before the pass runs: `bpfopt/crates/bpfopt/src/main.rs:441-459`. The pass registry marks `map_inline` as needing verifier states and map values: `bpfopt/crates/bpfopt/src/passes/mod.rs:86-105`.

Internal behavior if invoked programmatically without usable states:

- Verifier-guided key extraction fails with "no verifier states available": `bpfopt/crates/bpfopt/src/passes/map_inline.rs:329-337`.
- Production `extract_site_constant_key()` has no static fallback. If `use_verifier_guided_keys` is false, it returns "verifier-guided key extraction is unavailable after a prior map_inline rewrite": `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1243-1287`.
- On the first round, `use_verifier_guided_keys` is true; later fixed-point rounds deliberately disable it because the old verifier states no longer match transformed bytecode: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:769-827`.
- If key extraction fails on a BPF-non-writable map, the pass can fall back to a runtime-key rewrite driven by snapshot entries: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:970-997`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1425-1510`.
- Pseudo-map-value direct loads do not need lookup-key verifier state: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:838-840`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1928-2002`.

So the degradation is severe: normal writable lookup-site inlining stops; only pseudo-map-value loads and limited runtime-key snapshot rewrites remain.

### Why static bytecode analysis is not enough

The kernel verifier is a path-sensitive abstract interpreter. It tracks stack pointer offsets, initialized stack bytes, spilled scalar values, ranges, `tnum`s, helper effects, and branch-refined states. The source comment describes the exact `map_lookup_elem()` contract: `R2` must be a stack pointer to initialized key bytes, and verifier checks `[R2, R2 + key_size)`: `vendor/linux-framework/kernel/bpf/verifier.c:115-148`.

bpfopt's local backward resolver is intentionally much narrower:

- It finds a previous register definition by scanning backward in linear bytecode, bounded by subprogram start: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2480-2494`.
- It handles selected constant sources: plain `LD_IMM64`, stack reloads from statically found constant stores, `MOV`, and simple ALU: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2317-2438`.
- It only recognizes simple `R2 = R10; R2 += negative_imm` setup for removal: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2272-2293`.

That is not equivalent to verifier scalar tracking. It does not model path joins, helper/kfunc semantics, verifier branch refinements, stack invalidation, or the precise backtracking dependency chain. The verifier's `__mark_chain_precision()` explicitly backtracks through instruction history and parent verifier states to mark transitive scalar dependencies precise: `vendor/linux-framework/kernel/bpf/verifier.c:5125-5135`, `vendor/linux-framework/kernel/bpf/verifier.c:5397-5409`.

Even perfect bytecode scalar tracking still would not reveal map values. The actual map contents are outside the bytecode; `map_inline` gets them from `program.map_values` / map provider snapshots, not from verifier scalar analysis.

## 2. `bpfopt const_prop` vs kernel verifier const/range propagation

### bpfopt behavior

`ConstPropPass` builds a `VerifierExactConstOracle` from verifier states:

- It only consumes `VerifierInsnKind::InsnDeltaState`: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:121-135`.
- It records exact scalar constants per `(pc, reg)` if all observations agree; conflicting observations are dropped: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:31-117`.
- Unlike `map_inline`, it does not require `precise == true`; it only checks `reg.reg_type == "scalar"` and exact values: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:77-105`.

The pass then combines this oracle with its own forward constant simulation:

- It constructs the oracle from `program.verifier_states` and solves block-entry states: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:185-203`.
- It simulates instructions, applies verifier post-state after each PC, and records rewrites: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:324-399`.
- It rewrites ALU results to constant loads using the verifier oracle or local evaluation: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:402-420`.
- It folds conditional jumps to `JA` or `NOP`: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:422-435`.
- It emits `MOV32`, `MOV64`, or `LD_IMM64` constant loads: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:661-670`.
- It also runs a CFG-unreachable cleanup after replacements: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:251-259`.

The user-cited oracle starts here: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:121`.

### Kernel verifier behavior

The kernel already propagates scalar facts:

- It updates bounds and `tnum` through ALU ops in `adjust_scalar_min_max_vals()`: `vendor/linux-framework/kernel/bpf/verifier.c:16339-16475`.
- Exact known bitwise results are marked with `__mark_reg_known()` when both operands have constant `tnum`s, for example AND/OR/XOR: `vendor/linux-framework/kernel/bpf/verifier.c:15868-15878`, `vendor/linux-framework/kernel/bpf/verifier.c:15931-15940`, `vendor/linux-framework/kernel/bpf/verifier.c:15991-16000`.
- Conditional branches are evaluated by `is_branch_taken()`: `vendor/linux-framework/kernel/bpf/verifier.c:17200-17246`.
- If a branch is known, verifier follows only the feasible side: `vendor/linux-framework/kernel/bpf/verifier.c:17868-17910`.
- Later, for privileged programs, it hard-wires dead branch directions and removes dead code/NOPs: `vendor/linux-framework/kernel/bpf/verifier.c:22647-22695`, `vendor/linux-framework/kernel/bpf/verifier.c:22700-22722`, `vendor/linux-framework/kernel/bpf/verifier.c:26497-26508`.

Important correction: the kernel does physically rewrite bytecode for dead branches/dead code/NOPs after verification in privileged mode. What it does not do is general bpfopt-style ALU constant materialization, e.g. replacing `r1 += r0` with `mov r1, IMM` just because verifier knows `r0`.

### Same oracle?

Not literally. The kernel's oracle is in-memory verifier state (`bpf_reg_state`, stack slots, ranges, `tnum`, precision marks). bpfopt consumes a lossy text serialization of some of that state from a previous `BPF_PROG_REJIT(log_level=2)` / verifier log.

It is the same source of truth in the sense that bpfopt's facts come from the kernel verifier. It is not the same object or full state:

- `VerifierInsn` keeps parsed `regs` and `stack`: `bpfopt/crates/kernel-sys/src/lib.rs:130-190`.
- The parser recovers `P` precise markers, exact values, `fp` offsets, ranges, and stack slots from text: `bpfopt/crates/kernel-sys/src/verifier_log.rs:82-138`, `bpfopt/crates/kernel-sys/src/verifier_log.rs:285-377`.
- `const_prop` uses only register exact constants; `map_inline` uses `R2` and stack bytes too.

### What value remains above verifier const_prop?

Real value:

- Materializing constants changes the bytecode the second verifier and JIT see. A known ALU result becomes an immediate `MOV32/MOV64/LD_IMM64`, which can reduce native JIT work even if the original verifier merely tracked it internally.
- Constants exposed by `map_inline` are outside the kernel verifier's reach because they come from map snapshots. Example: `map_inline` replaces a map-value load with `mov32 r6, 7`, then `const_prop` folds `if r6 == 7`: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:1037-1079`.
- Constants after helper calls can be used when the verifier log exposes exact `R0`; static bpfopt simulation alone marks caller-saved regs unknown after calls: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:383-388`, but the verifier oracle can fold the following branch: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:1008-1034`.

Redundant part:

- Branch feasibility and dead branch pruning from scalar facts is already done by the kernel verifier. For pure scalar chains ending in a branch, `const_prop` `sites_applied` can easily count cases that the kernel would already eliminate internally before JIT.
- bpfopt still has value if the transformed constant feeds later bpfopt passes or reduces live register work, but branch-only wins should be treated skeptically in pass attribution.

## 3. `bpfopt dce` vs kernel dead code elimination

### What bpfopt dce removes

`DcePass` currently removes three things:

- CFG-unreachable blocks: `bpfopt/crates/bpfopt/src/passes/dce.rs:36-49`.
- Dead register definitions: `bpfopt/crates/bpfopt/src/passes/dce.rs:51-58`.
- `ja +0` NOPs to a fixed point: `bpfopt/crates/bpfopt/src/passes/dce.rs:60-67`.

The diagnostic/accounting sum is `unreachable_removed + dead_defs_removed + nop_removed`: `bpfopt/crates/bpfopt/src/passes/dce.rs:73-83`.

Note: the comment says dead register definition elimination is "left for a later pass", but the code already calls it. The comment is stale: `bpfopt/crates/bpfopt/src/passes/dce.rs:12-19`, `bpfopt/crates/bpfopt/src/passes/dce.rs:51-58`.

Implementation details in shared utils:

- CFG reachability preserves only subprograms with reachable pseudo-callers, to avoid orphaned subprograms causing verifier unreachable errors: `bpfopt/crates/bpfopt/src/passes/utils.rs:789-887`.
- NOP removal deletes `JA +0`: `bpfopt/crates/bpfopt/src/passes/utils.rs:889-906`.
- Dead-def removal uses liveness and removes side-effect-free `ALU/ALU64/LDX/LD_IMM64` definitions whose destination register is dead: `bpfopt/crates/bpfopt/src/passes/utils.rs:908-971`.

### Kernel behavior

The kernel has two dead-code mechanisms:

1. Structural CFG validation before full verification:
   The first verifier pass rejects unreachable instructions in the raw CFG: `vendor/linux-framework/kernel/bpf/verifier.c:56-70`, `vendor/linux-framework/kernel/bpf/verifier.c:19119-19237`, `vendor/linux-framework/kernel/bpf/verifier.c:19303-19319`.

2. Dynamic dead-code removal after verifier proves branches:
   Each instruction has `insn_aux_data.seen`: `vendor/linux-framework/include/linux/bpf_verifier.h:529-565`.
   Privileged mode hard-wires conditional branches when one side was not seen, removes unseen instruction ranges, and removes NOPs: `vendor/linux-framework/kernel/bpf/verifier.c:22647-22722`.
   These optimizations run before JIT fixups: `vendor/linux-framework/kernel/bpf/verifier.c:26497-26508`.
   Unprivileged mode sanitizes unseen dead code to traps instead of removing it: `vendor/linux-framework/kernel/bpf/verifier.c:22617-22631`, `vendor/linux-framework/kernel/bpf/verifier.c:26508-26510`.

So the JIT usually does not "skip" dead code on its own; the verifier rewrites/removes or sanitizes before the JIT receives the final program.

### What dce can catch after verifier

Mostly not kernel misses. For CFG-unreachable and NOPs, bpfopt overlaps with verifier behavior.

The real bpfopt-specific cases are:

- Dead code created by bpfopt's own rewrites before the next ReJIT. Example: after `const_prop` folds a branch, DCE removes dead blocks and an orphaned subprogram so the transformed bytecode does not hit "unreachable insn N": `bpfopt/crates/bpfopt/src/passes/dce.rs:301-337`.
- Dead register definitions. The kernel tracks liveness for verification/JIT metadata, but this code path does not generally remove arbitrary dead ALU/LDX definitions. bpfopt's `eliminate_dead_register_defs()` does: `bpfopt/crates/bpfopt/src/passes/utils.rs:908-971`. Example test: `dce_removes_dead_defs_exposed_by_const_prop`: `bpfopt/crates/bpfopt/src/passes/dce.rs:218-237`.
- Cleaner bytecode for the second verifier. Even if the kernel would remove dynamic dead code later, bpfopt can shorten and normalize the candidate before ReJIT. That can reduce verification/JIT work, but it should not be counted as a unique semantic optimization unless it is dead-def removal or it enables another pass.

## 4. Overall design: verifier oracle plus rewrite plus re-verify

The three passes fit this loop:

1. Run verifier/ReJIT with enough log detail.
2. Parse verifier states into bpfopt-side facts.
3. Rewrite bytecode in userspace.
4. Re-run kernel verifier via `BPF_PROG_REJIT`.

This design is reasonable for safety because bpfopt's oracle is advisory; the rewritten bytecode still has to pass kernel verification. It is also fragile because verifier-state side inputs are tied to exact PCs. The pass manager clears verifier states after any bytecode mutation: `bpfopt/crates/bpfopt/src/pass.rs:921-939`.

Paper-performance interpretation:

- The performance value is in the final JITed native code after bpfopt rewrites bytecode and the kernel verifies/JITs it again. It is not an optimization applied "inside" the original verifier.
- `map_inline` is the strongest non-redundant pass here: it uses verifier only to recover a safe key, then specializes using runtime map snapshots. Kernel verifier cannot derive map values from bytecode.
- `const_prop` is mixed: useful when it materializes constants the kernel would only carry internally, especially constants exposed by `map_inline` or helper-return exact states; redundant for branch pruning that the kernel already does.
- `dce` is mixed-to-weak: CFG/NOP DCE is mostly kernel-overlap; dead-def DCE is the distinct part.

It is very plausible that many `const_prop` and `dce` `sites_applied` are cases the kernel verifier already eliminates internally, especially branch folds and NOP/dead-block cleanup. That does not apply to `map_inline` map-value constants or to DCE dead register definitions. Pass attribution should separate these categories instead of treating all applied sites as equal optimization opportunities.

Concrete examples of bpfopt-only sites:

- Map lookup value load to constant: lookup key is verifier-proven, value bytes come from map snapshot, load becomes immediate constant: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1297-1405`.
- Map-in-map specialization: outer snapshot maps key to inner map id, inner map snapshot supplies value bytes: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1694-1805`.
- Pseudo-map-value load to constant: direct map-value pointer load is replaced with immediate from snapshot: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1935-2002`.
- Dead register definition removal after earlier simplification: `bpfopt/crates/bpfopt/src/passes/utils.rs:908-971`.

Concrete examples of likely-kernel-overlap sites:

- Pure scalar branch folded to `JA`/`NOP`: bpfopt does this in `const_prop`, but kernel `is_branch_taken()` and `opt_hard_wire_dead_code_branches()` cover the same class: `bpfopt/crates/bpfopt/src/passes/const_prop.rs:422-435`, `vendor/linux-framework/kernel/bpf/verifier.c:17200-17246`, `vendor/linux-framework/kernel/bpf/verifier.c:22647-22670`.
- CFG-unreachable and `JA +0` NOP cleanup: bpfopt DCE does it, but privileged verifier also removes unseen ranges and NOPs before JIT: `bpfopt/crates/bpfopt/src/passes/dce.rs:43-67`, `vendor/linux-framework/kernel/bpf/verifier.c:22673-22722`.
