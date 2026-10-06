# Phase 3 BBProgram Migration Code Review

Date: 2026-05-10
Branch: `main`
Scope: investigation and recommendation only. Source files were not edited.

## Executive Summary

The Phase 3 migration did not meet the design intent in
`docs/bbprogram-architecture-design.md`.

The design says the production path should be:

`Vec<BpfInsn> -> lift once -> pass.run(&mut BBProgram) -> lower once`

The current implementation still has this production path:

`BpfProgram<Vec<BpfInsn>> -> PassManager -> pass.run(&mut BpfProgram)`, with
most passes doing their own internal lift/lower. The `BpfPass` trait in
`bpfopt/crates/bpfopt/src/pass.rs:1048` still accepts `&mut BpfProgram`, and
the CLI still creates `BpfProgram` and runs `PassManager` at
`bpfopt/crates/bpfopt/src/main.rs:297-303`.

Only `dce` is fully BBProgram-native. `const_prop` and
`bounds_check_merge` are real partial migrations. `map_inline` is still a
linear `BpfProgram` pass that builds old-style PC-indexed edit plans and only
lifts inside `apply_map_inline_edit()`. Most kinsn passes flatten BBProgram back
to `Vec<BpfInsn>` for scanning and old analyses, then map original PCs back to
BBProgram for `replace_range()`.

This explains the LOC result. The migration added 2,158 LOC of BBProgram infra
but retained most legacy analysis and pass-local scan/apply structure.

## Measurement Check

Line counts against `bfa802c9` using `git show bfa802c9:<path>`:

| File | Start | Current | Delta |
|---|---:|---:|---:|
| `passes/dce.rs` | 373 | 81 | -292 |
| `passes/const_prop.rs` | 819 | 1054 | +235 |
| `passes/bounds_check_merge.rs` | 549 | 746 | +197 |
| `passes/cond_select.rs` | 552 | 624 | +72 |
| `passes/ccmp.rs` | 363 | 483 | +120 |
| `passes/rotate.rs` | 499 | 529 | +30 |
| `passes/extract.rs` | 194 | 223 | +29 |
| `passes/endian.rs` | 455 | 481 | +26 |
| `passes/bulk_memory.rs` | 835 | 865 | +30 |
| `passes/prefetch.rs` | 782 | 813 | +31 |
| `passes/wide_mem.rs` | 667 | 655 | -12 |
| `passes/branch_flip.rs` | 541 | 581 | +40 |
| `passes/map_inline.rs` | 5356 | 5473 | +117 |
| `passes/noop.rs` | 26 | 26 | 0 |
| `passes/skb_load_bytes.rs` | 335 | 372 | +37 |
| `pass.rs` | 1550 | 1461 | -89 |

New BBProgram infra:

| File | Current LOC |
|---|---:|
| `analysis/bbprogram.rs` | 315 |
| `analysis/bbprogram_api.rs` | 894 |
| `analysis/bbprogram_lift.rs` | 494 |
| `analysis/bbprogram_lower.rs` | 163 |
| `analysis/bbprogram_use_def.rs` | 292 |
| Total | 2158 |

## Per-Pass Migration Depth

Rating key:

- A: fully BBProgram-native
- B: meaningful BBProgram migration, but legacy patterns remain
- C: thin BBProgram wrapper around legacy linear scanning/edit planning
- D: barely changed or not really migrated

| Pass | Rating | Findings |
|---|---:|---|
| `dce` | A | `run_on_bbprogram()` uses `prog.use_def.defs`, `uses_for()`, `insn_at()`, and `delete_insn()` directly (`dce.rs:34-49`). No lowering inside the BB entry point. This is the model the design describes. |
| `const_prop` | B | Real BBProgram dataflow exists: `solve_block_entry_states()` and `simulate_block()` iterate blocks/sites (`const_prop.rs:521-628`). Mutation uses `prog.replace_range()` (`const_prop.rs:500-507`). However it retains `ConstPropRewritePlan`, manual replacement metadata, and a separate `replacement_addr_map()` for BTF/annotation remap (`const_prop.rs:397-409`, `989-1047`). |
| `bounds_check_merge` | B | The scanner walks `prog.blocks()` and `prog.logical_sites_in_block()` and uses `prog.use_def` for cursor liveness (`bounds_check_merge.rs:368-582`). It is a real partial migration. Legacy residue remains in `ProgramView`, manual PC maps, target-PC maps, and `addr_map_after_deletions()` (`bounds_check_merge.rs:253-347`). |
| `cond_select` | B | Applies with real multi-block BB APIs: `split_block()` and `replace_diamond_with_insns()` (`cond_select.rs:194-220`, `235-288`). But detection still lowers to `Vec<BpfInsn>`, runs old `LivenessAnalysis`, and scans with `iter_sites()` (`cond_select.rs:131-135`, `306-392`). |
| `ccmp` | B | Applies with BB APIs: `split_block()`, `merge_linear_chain()`, `replace_range()`, and `replace_terminator()` (`ccmp.rs:273-310`, `312-329`). Detection still lowers, runs old `LivenessAnalysis`, and scans `Vec<BpfInsn>` (`ccmp.rs:175-179`, `392-448`). |
| `rotate` | C | `run_on_bbprogram()` immediately calls `lower(prog)`, constructs `BpfProgram::new()`, runs `BranchTargetAnalysis` and `LivenessAnalysis`, scans a flat instruction slice, then maps original PCs back for `replace_range()` (`rotate.rs:89-195`). |
| `extract` | C | Same thin-shim pattern: lower, `BpfProgram::new()`, `BranchTargetAnalysis`, flat scan, then `replace_range()` via PC lookup (`extract.rs:126-215`). |
| `endian_fusion` | C | Same thin-shim pattern: lower, `BpfProgram::new()`, `BranchTargetAnalysis`, flat scan, PC-mapped `replace_range()` (`endian.rs:385-473`). |
| `bulk_memory` | C | Lowered flat scan plus old branch-target/liveness analyses (`bulk_memory.rs:211-221`). Most detection and state tracking remains `&[BpfInsn]` loops (`bulk_memory.rs:305-865`). Final edit is only a PC-mapped `replace_range()`. |
| `prefetch` | C | Lowered flat scan plus old `CFGAnalysis` and `BranchTargetAnalysis` (`prefetch.rs:239-255`). Insertion is a BB `replace_range()` at a PC-mapped site (`prefetch.rs:319-325`). The bulk of the pass remains flat CFG/PC logic (`prefetch.rs:398-813`). |
| `wide_mem` | C | Lowered flat scan plus old branch-target/liveness analyses (`wide_mem.rs:503-514`). Most safety checks remain PC-indexed, then final edit maps original PCs to `replace_range()` (`wide_mem.rs:518-643`). |
| `branch_flip` | B | Scan is still flat and uses `BranchTargetAnalysis` (`branch_flip.rs:257-263`, `512-564`). Application is meaningfully BBProgram-native: it rewrites terminators and permutes blocks (`branch_flip.rs:390-477`). |
| `map_inline` | D | No `run_on_bbprogram()` entry point exists. `MapInlinePass::run()` still operates on `BpfProgram`, clones `program.insns`, runs fixed-point rounds, and calls `run_map_inline_round(program, ...)` (`map_inline.rs:2228-2304`). The round builds `BTreeMap<usize, Vec<BpfInsn>>` replacements and `skip_pcs` (`map_inline.rs:2307-2763`). It only lifts inside `apply_map_inline_edit()` after all legacy PC-indexed edits are built (`map_inline.rs:2772-2794`). |
| `noop` | B | Trivial no-op has a `run_on_bbprogram()` but `BpfPass::run()` does not lift. This is harmless behaviorally but still reflects the old trait boundary (`noop.rs:19-25`). |
| `skb_load_bytes_spec` | C | `BpfPass::run()` scans the linear `BpfProgram` before lifting (`skb_load_bytes.rs:52-75`). `run_on_bbprogram()` lowers then scans with `BranchTargetAnalysis` (`skb_load_bytes.rs:83-97`). Application uses BB `replace_range()` only after flat detection. |

## BBProgram Infrastructure Audit

### `analysis/bbprogram.rs`

`BBProgram`, `Block`, `Terminator`, and `UseDefGraph` are functional, but the
representation is not enforcing the design boundary strongly.

Key issues:

- Most fields are public: `blocks`, `entry`, `use_def`, `oracle`, `btf`, and
  `kinsn_reg` (`bbprogram.rs:28-40`). Passes can bypass mutation APIs and read
  internal maps directly. The design says BBProgram should enforce invariants.
- `BtfMetadataMap` is really an original-PC map, not full BTF metadata. BTF
  remapping still lives in `pass.rs` and pass-local address maps.
- `Terminator::End` is an extra case not in the design. It is used to represent
  final falloff/empty state, but it broadens every terminator match.
- `site_for_original_pc()` scans `btf` linearly (`bbprogram.rs:123-127`). Eight
  passes duplicate the same helper instead of using it: `rotate`, `extract`,
  `endian`, `bulk_memory`, `prefetch`, `wide_mem`, `cond_select`, and `ccmp`.

### `analysis/bbprogram_api.rs`

This file is too large for the current caller set. It is 894 LOC and contains
both necessary mutation logic and unused public APIs.

Production caller counts outside `bbprogram_api.rs`:

| API | Production callers |
|---|---:|
| `replace_insn()` | 0 |
| `delete_insn()` | 1 |
| `insert_insn()` | 0 |
| `replace_range()` | 13 |
| `delete_cond_branch()` | 1 |
| `replace_terminator()` | 8 |
| `permute_blocks()` | 1 |
| `merge_linear_chain()` | 1 |
| `delete_block()` | 0 |
| `delete_unreachable_blocks()` | 1 |
| `rewire_edge()` | 0 |
| `split_block()` | 3 |
| `replace_diamond_with_kinsn()` | 0 |
| `replace_diamond_with_insns()` | 3 |

Obvious cleanup candidates:

- Delete or make private the zero-caller APIs: `replace_insn()`, `insert_insn()`,
  `delete_block()`, `rewire_edge()`, and `replace_diamond_with_kinsn()`.
- Stop re-exporting `range_len`; it is only used by `bbprogram_api.rs`.
- Keep `replace_diamond_with_insns()` because `cond_select` uses it.
- Keep `split_block()`, `merge_linear_chain()`, `permute_blocks()`, and
  `replace_terminator()` because `cond_select`, `ccmp`, `branch_flip`, and
  `map_inline` use them.

This is not only dead surface area. The public API also makes it easier for
passes to be half-migrated: they can keep PC-indexed plans and use one final
mutation helper rather than moving matching/safety checks to BBProgram.

### `analysis/bbprogram_lift.rs`

Lift is useful and reasonably focused. It handles block splitting, ldimm64
second-slot metadata, pseudo calls, pseudo func targets, JA32, conditional
branches, frames, and original-PC mapping.

Design gaps:

- `lift()` itself has no production caller; production uses
  `lift_with_kinsn_registry()`. This is not clippy-dead because it is public.
- The design promised lift once at the CLI boundary. Current production invokes
  lift inside each pass, and `map_inline` invokes it inside its edit commit path.

### `analysis/bbprogram_lower.rs`

Lower is small, but it does not implement the design's general "topological
sort" lower. It emits blocks in current vector order (`bbprogram_lower.rs:12`).
That works only because mutation APIs preserve or explicitly permute physical
layout and then require fallthrough adjacency. This is pragmatic, but it means
passes still reason about physical block order in several places.

### `analysis/bbprogram_use_def.rs`

Use-def is compact and useful. `dce` and `bounds_check_merge` consume it. It
does not replace old `LivenessAnalysis`, so old liveness remains in production.
There is no `BBProgram::live_in()` or `BBProgram::live_out()` despite the
design calling for pure recomputed BBProgram methods.

### Old Analyses Still In Production

The design says `AnalysisCache`, CFG, liveness, branch targets, and map refs
should be folded into BBProgram methods. Current production still uses:

- `BranchTargetAnalysis`: `rotate`, `extract`, `endian`, `bulk_memory`,
  `prefetch`, `wide_mem`, `branch_flip`, `skb_load_bytes`, `map_inline`.
- `LivenessAnalysis`: `rotate`, `bulk_memory`, `wide_mem`, `cond_select`,
  `ccmp`.
- `CFGAnalysis`: `prefetch` and `pass.rs` kinsn BTF helper path.
- `MapRefsAnalysis`: `map_inline/map_info.rs`.
- `site_scan::iter_sites`: many migrated passes still scan `&[BpfInsn]`.

These old analysis modules total 613 LOC:

| File | LOC |
|---|---:|
| `analysis/branch_target.rs` | 49 |
| `analysis/cfg.rs` | 232 |
| `analysis/liveness.rs` | 219 |
| `analysis/map_refs.rs` | 86 |
| `analysis/site_scan.rs` | 27 |

### Clippy Dead-Code Run

Command run:

```bash
cargo clippy --release --manifest-path bpfopt/Cargo.toml -- -D dead_code -D warnings
```

Result:

```text
Checking bpfopt v0.1.0 (/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt)
Finished `release` profile [optimized] target(s) in 2.74s
```

No dead-code diagnostics were emitted. This does not prove public API is used:
Rust's `dead_code` lint does not flag exported public items such as the unused
BBProgram mutation APIs listed above.

## `const_prop.rs` Detail

`ConstPropRewritePlan` at `const_prop.rs:398` is not a new BBProgram concept.
The same pass-local type existed at Phase 3 start. In `bfa802c9`, it was:

```rust
struct ConstPropRewritePlan {
    replacements: BTreeMap<usize, Vec<BpfInsn>>,
    sites_skipped: Vec<SkipReason>,
}
```

Now it is:

```rust
struct ConstPropRewritePlan {
    replacements: BTreeMap<InsnSite, ConstReplacement>,
    sites_skipped: Vec<SkipReason>,
}
```

So this is a retained pass-local rewrite plan converted from PC keys to
`InsnSite` keys. It is not the deleted global `RewritePlan`, but it carries the
same old "scan first, collect replacements, commit later" shape.

How native it is:

- Native: state solving walks `prog.blocks()` and uses `dataflow_successors()`
  (`const_prop.rs:521-563`).
- Native: block simulation walks `prog.logical_sites_in_block()` and fetches
  instructions with `prog.insn_at()` (`const_prop.rs:578-628`).
- Native: LD_IMM64 value reads use `prog.ldimm64_second_slots`
  (`const_prop.rs:976-987`).
- Legacy residue: local rewrite plan, `ConstReplacement`, `AppliedReplacement`,
  manual BTF/annotation address map, and pass-local commit loop
  (`const_prop.rs:397-409`, `500-507`, `989-1047`).

The file grew because the migration kept the old verifier oracle and const
state logic, added BBProgram translation/metadata handling, and did not delete
the pass-local commit machinery.

One correctness-adjacent smell: `simulate_block()` passes `frame: None` into
`analyze_instruction()` (`const_prop.rs:599-607`), even though BBProgram tracks
`Block.frame`. The oracle then only uses frame-invariant facts. That may be
conservative, but it leaves BBProgram frame metadata unused by the pass.

## `map_inline.rs` Detail

`map_inline` was not ported to a BBProgram pass body.

Evidence:

- There is no `run_on_bbprogram()` entry point.
- `MapInlinePass::run()` still operates directly on `&mut BpfProgram`
  (`map_inline.rs:2228-2304`).
- It performs fixed-point rounds by cloning and comparing `program.insns`
  (`map_inline.rs:2244-2258`).
- `run_map_inline_round()` takes `&mut BpfProgram`, runs `BranchTargetAnalysis`,
  `analyze_map_info()`, and scans `program.insns` (`map_inline.rs:2307-2325`).
- Edits are still old-PC keyed: `BTreeMap<usize, Vec<BpfInsn>>`, `skip_pcs`,
  `ReplacementBranchPatch`, and `MapInlineEdit` (`map_inline.rs:1561-1577`,
  `2691-2758`, `2765-2770`).
- Only `apply_map_inline_edit()` lifts to BBProgram after the edit plan is
  already built (`map_inline.rs:2772-2794`).

The new BBProgram code in `map_inline` is an apply-layer adapter:

- `apply_replacements_and_deletions()` maps old PCs to sites and calls
  `replace_original_pc()` or `delete_original_pc()`
  (`map_inline.rs:2901-2933`).
- Terminator replacement is handled specially (`map_inline.rs:2936-3017`).
- Cleanup uses `delete_unreachable_blocks()` and `replace_terminator()`
  (`map_inline.rs:3039-3058`).

This is useful mechanically, but it is not a body migration. The pass's
recognition, dataflow, safety, conflict detection, branch patching, and
fixed-point orchestration remain legacy linear code.

## `pass.rs` Detail

`AnalysisCache` is gone from production `pass.rs`, but the file is still the
old linear pass framework.

Remaining bloat and design mismatch:

- Header comments still describe `BpfProgram` as the core IR and mention
  analysis cache invalidation (`pass.rs:3-7`, `pass.rs:589-591`,
  `pass.rs:1287-1290`).
- `BpfPass::run()` still accepts `&mut BpfProgram`, not `&mut BBProgram`
  (`pass.rs:1048`).
- `PassManager::run_single_pass()` still snapshots `program.insns`, calls the
  pass, clears verifier states, and syncs annotations if bytes changed
  (`pass.rs:1380-1397`).
- `BpfProgram` remains a large carrier for bytecode, annotations, map metadata,
  map values, overlays, hints, provider, verifier states, and BTF records
  (`pass.rs:592-832`).
- BTF remap helpers and kinsn subprogram layout helpers remain in `pass.rs`
  (`pass.rs:191-589`), so BBProgram has not absorbed BTF remapping as planned.

This file can shrink only after the trait boundary changes. Until then,
`BpfProgram` remains necessary as the CLI input/output carrier and side-input
container.

## Aggregate Findings

### Main Causes Of LOC Growth

1. BBProgram infra was added, but the old linear pass framework remains.
2. Most migrated passes still keep flat scanners and old analysis modules.
3. Several passes added BBProgram adapter code without deleting original
   PC-indexed scan/plan/apply logic.
4. `bbprogram_api.rs` exposes a wider mutation surface than current production
   uses.
5. BTF/annotation remap remains pass-local in `const_prop`,
   `bounds_check_merge`, and `map_inline`.

### Easy LOC Reduction Estimate

If all C/D-rated passes receive a proper second-pass migration, realistic
"easy" reduction from current code is about 1,500 to 2,200 LOC.

Likely contributors:

- `map_inline`: 500 to 800 LOC by deleting `MapInlineEdit`, manual addr-map
  construction, old-PC branch patching, and the lift-at-commit adapter.
- Flat kinsn passes (`rotate`, `extract`, `endian`, `bulk_memory`, `prefetch`,
  `wide_mem`, `skb_load_bytes`): 700 to 1,000 LOC total by moving scans and
  safety checks to BBProgram sites and deleting duplicated PC mapping helpers.
- `cond_select`, `ccmp`, `branch_flip`: 200 to 400 LOC total by moving scans to
  BB terminator/block patterns and replacing old liveness uses.

This would improve design adherence but probably would not hit the original
">= -2500 production LOC vs bfa802c9" target by itself.

### Dead/Stale Surface Reduction Estimate

Deleting obvious unused/stale APIs and duplicated helpers is worth about 800 to
1,200 LOC if done after the C/D pass migrations:

- old analysis modules: about 613 LOC once no production pass uses them;
- unused BBProgram public APIs and helper plumbing: about 150 to 250 LOC;
- duplicated `site_for_original_pc()` helpers and `replace_flat_range()`
  adapters: about 100 to 200 LOC;
- pass.rs comment/API cleanup and narrowed helper surface: about 100 to 200 LOC.

Doing only this without pass migrations is much smaller, because the old
analyses are still production dependencies today.

### Realistic Minimum Production LOC

Current measured production LOC: 21,522.

The original target was at most 16,857 LOC (`19,357 - 2,500`). Current code is
4,665 LOC above that target.

Honest projection:

- Targeted cleanup: about 19,500 to 20,500 LOC.
- Full real Phase 3 cleanup: about 17,300 to 18,300 LOC.
- Aggressive cleanup that also deeply rewrites `map_inline`, removes old
  analyses, and narrows `pass.rs`: about 16,800 to 17,300 LOC.

The design-doc projection near 15,100 LOC is not credible unless `map_inline`
is substantially simplified beyond just moving it to BBProgram.

## Recommendation

Recommend option B: targeted cleanup, with explicit scope and acceptance
criteria.

Do not accept the current state as Phase 3 complete. The production code grew,
the main trait boundary is still linear, and most pass bodies still use
`Vec<BpfInsn>` scanners or old analyses.

Do not full re-do immediately unless the LOC target is a hard gate before any
paper data work. A full re-port is the only path likely to approach the
original LOC target, but it will churn high-risk passes while tests are already
being repaired in another workstream.

Targeted cleanup should focus on the highest leverage items:

1. `map_inline`: either add a real `run_on_bbprogram()` or explicitly declare it
   out of Phase 3 scope. If it remains in scope, remove `MapInlineEdit`,
   PC-keyed replacements, manual addr maps, and lift-at-commit.
2. Flat kinsn scanners: migrate `rotate`, `extract`, `endian`, `bulk_memory`,
   `prefetch`, `wide_mem`, and `skb_load_bytes` away from `lower(prog) ->
   BpfProgram::new() -> old analyses -> PC remap`.
3. Analysis folding: add BBProgram-native branch target/liveness/subprog/map-ref
   queries, then delete `branch_target.rs`, `cfg.rs`, `liveness.rs`,
   `map_refs.rs`, and `site_scan.rs` when no production pass uses them.
4. API trimming: delete zero-caller BBProgram APIs or make them private until
   there is a real caller.
5. Pass boundary follow-up: plan a smaller separate change to make
   `BpfPass::run()` BBProgram-based. Without this, every pass can continue to
   hide a linear legacy path inside its own `run()`.

Expected outcome for option B: reduce 1,000 to 2,000 LOC, eliminate the most
cosmetic migrations, and make the remaining design gap explicit. It will not
fully satisfy the original LOC claim, but it is the best cost/risk tradeoff
while paper-data work continues.
