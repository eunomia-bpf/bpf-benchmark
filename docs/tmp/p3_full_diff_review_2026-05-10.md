# Phase 3 Full Diff Review - 2026-05-10

Scope: full `bpfopt/crates/bpfopt/` review against Phase 3 baseline
`bfa802c9`, including the current staged/working-tree state. Source code was
not edited by this review.

Reviewed state:

- Baseline: `bfa802c9`.
- Current `HEAD`: `01115ca9`.
- `git diff bfa802c9..HEAD --stat bpfopt/crates/bpfopt/` is only
  `const_prop.rs` and `const_prop_tests.rs` (`157 insertions`, `4 deletions`).
- The real Phase 3 surface is staged/working-tree state: `git diff HEAD --stat
  bpfopt/crates/bpfopt/` reports `56 files changed`, `7809 insertions`,
  `11498 deletions`.
- `git status --short` also shows staged non-source artifacts under
  `corpus/results/...`, `target`, and `bpfopt/testbin/.../target.json`. That
  matters because design acceptance criterion 11.5 says `corpus/` should be
  untouched.

## Verdict

**Needs more work.**

The migration is boundary-complete: the CLI lifts to `BBProgram`, the trait
accepts `&mut BBProgram`, and the pass manager runs `BBProgram` passes. However,
the current tree is not production-ready:

1. `cargo test --release --manifest-path bpfopt/Cargo.toml --all-targets`
   currently does not compile because `analysis/mod.rs` re-exports
   `insn_use_def_set` and `RegUseDefSet` twice.
2. Several passes still immediately lower `BBProgram` into `Vec<BpfInsn>` /
   `BpfProgram`, run old analyses, and map old PCs back into BBProgram only for
   final edits.
3. Total src LOC is down only because tests were deleted. Non-test LOC increased
   by `+2672`.
4. `BpfProgram`, old analysis modules, public dead BTF remap helpers, and stale
   comments remain.
5. Some production mutation APIs still panic/assert instead of returning
   fallible errors.

## Blocking Findings

### P0: current test suite does not compile

Command:

```sh
cargo test --release --manifest-path bpfopt/Cargo.toml --all-targets
```

Current result: compile fails with `E0252` duplicate definitions.

- `analysis/mod.rs` re-exports `insn_use_def_set` and `RegUseDefSet` from
  `bbprogram_use_def` at `bpfopt/crates/bpfopt/src/analysis/mod.rs:22`.
- It re-exports the same names from `liveness` at
  `bpfopt/crates/bpfopt/src/analysis/mod.rs:25`.
- The first exported `RegUseDefSet` is defined at
  `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:49`.
- The second exported `RegUseDefSet` is defined at
  `bpfopt/crates/bpfopt/src/analysis/liveness.rs:24`.

This is a hard blocker before any Phase 3 acceptance discussion.

### P0: immediately prior green-compile state still had a failing BBProgram cascade

Before the latest `analysis/mod.rs` edit, a full release test run compiled and
then failed at `187 passed; 1 failed`. The failing test was
`passes::map_inline_tests::map_inline_pseudo_map_value_feeds_const_prop_and_dce_without_branch_cleanup`.

- Test fixture is
  `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:258`.
- The fixture runs `MapInlinePass -> ConstPropPass -> DcePass` on one lifted
  BBProgram at `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:274`.
- The shared test helper expects each pass to succeed at
  `bpfopt/crates/bpfopt/src/test_helpers.rs:69`.
- `ConstPropPass` requires every logical site to have a `prog.btf` original-PC
  entry at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:545`.
- The error is `missing original pc for InsnSite { block: BlockId(0), idx: 1 }`.

This is a real BBProgram metadata invariant break across passes, not a cosmetic
test issue.

### P1: map_inline remains structurally half-migrated

`MapInlinePass::run()` now accepts `&mut BBProgram`, but it still constructs a
linear `BpfProgram` view from `lower(prog)` at
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2297`, copies side inputs into
that linear carrier at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2299`, and
uses that view for map analysis and fixed-point rounds at
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2330` and
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2361`.

The round still calls flat map analysis and flat lookup scanning:
`analyze_map_info(program)` at
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2443` and
`find_map_lookup_sites(&program.insns)` at
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2454`.

It does finally apply edits to `BBProgram`, but through PC-keyed replacement maps
and skip sets:
`BTreeMap<usize, Vec<BpfInsn>>` at
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2926`,
`map_inline_addr_map()` at
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2950`, and
`apply_replacements_and_deletions()` at
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:3048`.

This is better than the earlier pure-linear version, but it is still not the
design's "pass logic operates on BBProgram" model.

### P1: old flat analysis remains in production pass internals

Representative examples:

- `rotate` lowers, builds `BpfProgram`, runs `BranchTargetAnalysis` and
  `LivenessAnalysis` at `bpfopt/crates/bpfopt/src/passes/rotate.rs:81`, then
  maps original PCs back for `replace_range()` at
  `bpfopt/crates/bpfopt/src/passes/rotate.rs:181`.
- `cond_select` lowers and runs old liveness at
  `bpfopt/crates/bpfopt/src/passes/cond_select.rs:123`, then uses
  `replace_diamond_with_insns()` only at the final edit step at
  `bpfopt/crates/bpfopt/src/passes/cond_select.rs:198`.
- `ccmp` lowers and runs old liveness at
  `bpfopt/crates/bpfopt/src/passes/ccmp.rs:165`, then merges/replaces BB blocks
  later at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:271`.
- `prefetch` lowers, runs `CFGAnalysis` and `BranchTargetAnalysis` at
  `bpfopt/crates/bpfopt/src/passes/prefetch.rs:253`, then inserts by original
  PC at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:333`.
- `skb_load_bytes` lowers, builds `BpfProgram`, and runs old branch-target
  analysis at `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:58`.
- `branch_flip` lowers and scans flat sites at
  `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:272`, though its final
  permutation/edit step is BBProgram-native at
  `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:470`.

This preserves a large class of legacy PC-indexed behavior inside the new trait
boundary.

### P1: total LOC reduction hides non-test growth

Line counts for `bpfopt/crates/bpfopt/src/**/*.rs`:

| Scope | `bfa802c9` | current | delta |
|---|---:|---:|---:|
| total src LOC | 29,528 | 25,899 | -3,629 |
| non-test src LOC | 19,357 | 22,029 | +2,672 |

Definition used for non-test LOC: excludes `*_tests.rs`, `pass_tests.rs`,
`test_helpers.rs`, `mock_maps.rs`, and `tests/`.

So the total acceptance target is met only because test files were heavily
culled. The production implementation is larger.

Top absolute per-file deltas:

| file | base | current | delta |
|---|---:|---:|---:|
| `passes/map_inline_tests.rs` | 3133 | 488 | -2645 |
| `analysis/bbprogram.rs` | 0 | 802 | +802 |
| `analysis/bbprogram_api.rs` | 0 | 759 | +759 |
| `pass_tests.rs` | 836 | 266 | -570 |
| `rewrite.rs` | 534 | 0 | -534 |
| `analysis/bbprogram_lift.rs` | 0 | 494 | +494 |
| `passes/wide_mem_tests.rs` | 606 | 173 | -433 |
| `passes/endian_tests.rs` | 540 | 145 | -395 |
| `passes/extract_tests.rs` | 511 | 139 | -372 |
| `passes/map_inline.rs` | 5356 | 5717 | +361 |
| `passes/bulk_memory_tests.rs` | 548 | 230 | -318 |
| `passes/branch_flip_tests.rs` | 519 | 215 | -304 |
| `passes/rotate_tests.rs` | 438 | 134 | -304 |
| `passes/cond_select_tests.rs` | 487 | 185 | -302 |
| `analysis/bbprogram_use_def.rs` | 0 | 292 | +292 |
| `passes/dce.rs` | 373 | 89 | -284 |
| `passes/skb_load_bytes_tests.rs` | 352 | 136 | -216 |
| `test_helpers.rs` | 108 | 318 | +210 |
| `passes/mod_tests.rs` | 295 | 88 | -207 |
| `passes/bounds_check_merge.rs` | 549 | 729 | +180 |

## Design Contract Conformance

| Design section | Status | Evidence | Deviation |
|---|---|---|---|
| §3 Architecture | Partial | CLI calls `lift_with_kop_registry()` at `bpfopt/crates/bpfopt/src/main.rs:303`, runs the pipeline at `bpfopt/crates/bpfopt/src/main.rs:315`, and lowers once for CLI output at `bpfopt/crates/bpfopt/src/main.rs:316`. | `PassManager` also lowers before and after every pass for accounting/oracle invalidation at `bpfopt/crates/bpfopt/src/pass.rs:1411` and `bpfopt/crates/bpfopt/src/pass.rs:1414`; many passes lower internally as listed above. |
| §4 Core Data Structures | Partial | `BBProgram`, `Block`, and `Terminator` exist at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:35`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:53`, and `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:61`. | Fields are public (`blocks`, `entry`, `use_def`, `oracle`, `btf`, `kop_reg`) at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:36`, so passes can bypass APIs. `Terminator::End` is an extra design case at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:82`. |
| §5 BBProgram API | Partial | Query APIs exist at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:116`; mutation APIs exist at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:20`. | Some design APIs were removed/renamed (`replace_insn`, `insert_insn`, `delete_block`, `rewire_edge`, `replace_diamond_with_kop` are absent). `split_block()` panics/asserts instead of returning `Result` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:307`. |
| §6 Lift Algorithm | Mostly yes | `lift_with_kop_registry()` implements block split/lift at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:17`, records original PCs at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:70`, and resolves JA/Jcc/pseudo-call at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:280`. | `VerifierOracle` is currently raw `Arc<[VerifierInsn]>` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:13`; there is no separate translated oracle structure. |
| §7 Lower Algorithm | Partial | `lower()` exists at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:7` and recomputes branch deltas at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:88`. | It emits physical block vector order at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:12`, not a topological sort. BTF output is not part of lower; it is separate `remapped_*` methods at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:331`. |
| §8 AnalysisCache deleted | Partial | `rg AnalysisCache bpfopt/crates/bpfopt/src` returns no hits. | Old analysis modules remain exported at `bpfopt/crates/bpfopt/src/analysis/mod.rs:23`, and production passes still consume `BranchTargetAnalysis`, `CFGAnalysis`, `LivenessAnalysis`, `MapRefsAnalysis`, and `iter_sites`. The comment at `bpfopt/crates/bpfopt/src/analysis/mod.rs:29` still mentions "analysis cache consumers". |
| §9 Pass Migration Model | Partial | `BpfPass::run` now takes `&mut BBProgram` at `bpfopt/crates/bpfopt/src/pass.rs:1048`. | The global `RewritePlan` is gone, but `ConstPropRewritePlan` remains at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:397`, and map_inline still builds PC-keyed edit maps at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2926`. |
| §10 Stage Plan | Partial | All registered CLI passes now dispatch through the BBProgram trait boundary in `bpfopt/crates/bpfopt/src/passes/mod.rs:22`. | Step 12 is incomplete: old analyses and `BpfProgram` remain, production LOC increased, and tests currently fail. |
| §11 Acceptance Criteria | No | Roundtrip integration exists in `bpfopt/crates/bpfopt/tests/bbprogram_roundtrip.rs`; CLI pipeline tests remain in `bpfopt/crates/bpfopt/tests/cli_pipeline.rs`. | The suite is not green. There are no per-pass 542-program equivalence integration tests; `bpfopt/crates/bpfopt/tests/` contains only `cli_pipeline.rs` and `bbprogram_roundtrip.rs`. |

## Specific Checks

### Production path

The production CLI path is now:

`read bytes -> lift_with_kop_registry -> attach_side_inputs -> pipeline.run(&mut BBProgram) -> lower -> write bytes`

Evidence:

- `bpfopt/crates/bpfopt/src/main.rs:299` reads bytecode.
- `bpfopt/crates/bpfopt/src/main.rs:303` lifts to `BBProgram`.
- `bpfopt/crates/bpfopt/src/main.rs:308` attaches side inputs.
- `bpfopt/crates/bpfopt/src/main.rs:315` runs the pipeline.
- `bpfopt/crates/bpfopt/src/main.rs:316` lowers once for CLI output.

This satisfies the external boundary. It does not mean pass internals are fully
BBProgram-native.

### BBProgram field encapsulation

`BBProgram` internals are public at
`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:36` through
`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:41`.

Passes use the public `btf` map directly instead of the shared helper in several
places:

- `cond_select`: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:283`
- `rotate`: `bpfopt/crates/bpfopt/src/passes/rotate.rs:189`
- `extract`: `bpfopt/crates/bpfopt/src/passes/extract.rs:207`
- `endian`: `bpfopt/crates/bpfopt/src/passes/endian.rs:465`
- `prefetch`: `bpfopt/crates/bpfopt/src/passes/prefetch.rs:337`
- `wide_mem`: `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:635`
- `ccmp`: `bpfopt/crates/bpfopt/src/passes/ccmp.rs:371`

There is already a central helper at
`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:244`; these copies should not
exist.

### AnalysisCache

`AnalysisCache` is gone by search. However, `BpfProgram` comments still describe
the old model:

- Top-level pass framework still lists `BpfProgram` as a core abstraction at
  `bpfopt/crates/bpfopt/src/pass.rs:5`.
- `BpfProgram` doc says it is "operated on by all passes" and mentions "analysis
  cache" at `bpfopt/crates/bpfopt/src/pass.rs:587`.
- `PassManager` still says it "manages analysis cache invalidation" at
  `bpfopt/crates/bpfopt/src/pass.rs:1313`.

### RewritePlan

The global `rewrite.rs` file is deleted. `rg RewritePlan` finds only
`ConstPropRewritePlan`:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:397`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:437`
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:538`

This is not the old global `RewritePlan`, but it preserves the same pass-local
"collect replacements, then commit" shape.

### BTF remap location

The CLI writes remapped BTF from `BBProgram` at
`bpfopt/crates/bpfopt/src/main.rs:702`. The underlying remap APIs are
`BBProgram::remapped_func_info_records()` and
`BBProgram::remapped_line_info_records()` at
`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:331`.

Old public BTF remap helpers still exist in `pass.rs` and have no production
callers after the latest map_inline rewrite:

- `remap_btf_metadata()` at `bpfopt/crates/bpfopt/src/pass.rs:191`
- `remap_kop_btf_metadata()` at `bpfopt/crates/bpfopt/src/pass.rs:341`

Those should either be deleted or moved behind test-only compatibility if truly
needed.

## Pass-by-Pass Migration Depth

| Pass | Rating | Evidence |
|---|---|---|
| `dce` | A | Uses `prog.use_def`, `uses_for()`, `insn_at()`, and `delete_insn()` directly at `bpfopt/crates/bpfopt/src/passes/dce.rs:25`. |
| `const_prop` | B | Dataflow walks `prog.logical_sites_in_block()` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:541` and mutates with `replace_range()` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:464`; retains `ConstPropRewritePlan` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:397`. |
| `bounds_check_merge` | B | Scans BBProgram sites at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:367` and mutates with `replace_range()` / `delete_cond_branch()` at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:191`; retains `ProgramView` PC maps at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:249`. |
| `cond_select` | B | Applies via `replace_diamond_with_insns()` at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:198`; detection still lowers and scans flat bytecode at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:123`. |
| `ccmp` | B | Applies with `merge_linear_chain()` and `replace_range()` at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:271`; detection still lowers and scans flat bytecode at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:165`. |
| `branch_flip` | B | Applies with terminator rewrites and `permute_blocks()` at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:470`; detection still lowers and scans flat bytecode at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:272`. |
| `map_inline` | C | Runs through BBProgram and applies final edits to BBProgram, but most matching/analysis still uses a linear `BpfProgram` view at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2297` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2443`. Current suite failure is in a map_inline cascade. |
| `rotate` | C | Lowers to `BpfProgram`, runs old analyses, then `replace_range()` by original PC at `bpfopt/crates/bpfopt/src/passes/rotate.rs:81`. |
| `extract` | C | Same flat pattern at `bpfopt/crates/bpfopt/src/passes/extract.rs:116`. |
| `endian_fusion` | C | Same flat pattern at `bpfopt/crates/bpfopt/src/passes/endian.rs:375`. |
| `bulk_memory` | C | Same flat pattern at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:204`. |
| `prefetch` | C | Same flat pattern plus old CFG at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:253`. |
| `wide_mem` | C | Same flat pattern at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:493`. |
| `skb_load_bytes_spec` | C | Same flat pattern at `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:58`. |
| `noop` | A | Trivial no-op BBProgram entry at `bpfopt/crates/bpfopt/src/passes/noop.rs:24`. |

## Test Suite Quality

Source scan count: `217` `#[test]` functions.

Distribution:

| File | tests |
|---|---:|
| `passes/map_inline_tests.rs` | 17 |
| `passes/const_prop_tests.rs` | 17 |
| `main.rs` | 16 |
| `verifier_log.rs` | 13 |
| `tests/cli_pipeline.rs` | 12 |
| `passes/map_inline/map_info.rs` | 11 |
| `passes/wide_mem_tests.rs` | 10 |
| `passes/branch_flip_tests.rs` | 10 |
| `pass_tests.rs` | 10 |
| `passes/bounds_check_merge_tests.rs` | 9 |
| `passes/extract_tests.rs` | 8 |
| `passes/endian_tests.rs` | 8 |
| `passes/cond_select_tests.rs` | 8 |
| `passes/skb_load_bytes_tests.rs` | 7 |
| `passes/rotate_tests.rs` | 7 |
| `passes/bulk_memory_tests.rs` | 7 |
| `passes/ccmp_tests.rs` | 6 |
| `passes/prefetch_tests.rs` | 5 |
| `passes/dce_tests.rs` | 2 |
| `tests/bbprogram_roundtrip.rs` | 1 |

Good:

- Pass tests generally use the lifted helper path. `run_pass_on_insns()` lifts
  at `bpfopt/crates/bpfopt/src/test_helpers.rs:38`, calls the trait at
  `bpfopt/crates/bpfopt/src/test_helpers.rs:41`, and lowers at
  `bpfopt/crates/bpfopt/src/test_helpers.rs:43`.
- P1-F DCE/kop coverage exists at
  `bpfopt/crates/bpfopt/src/passes/dce_tests.rs:11` and
  `bpfopt/crates/bpfopt/src/analysis/liveness_tests.rs:50`.
- P1-K const_prop regressions are explicitly represented at
  `bpfopt/crates/bpfopt/src/passes/const_prop_tests.rs:114`,
  `bpfopt/crates/bpfopt/src/passes/const_prop_tests.rs:174`, and
  `bpfopt/crates/bpfopt/src/passes/const_prop_tests.rs:201`.
- P1-G JA32 coverage exists at
  `bpfopt/crates/bpfopt/src/analysis/branch_target_tests.rs:9`,
  `bpfopt/crates/bpfopt/src/analysis/cfg_tests.rs:28`, and
  `bpfopt/crates/bpfopt/src/analysis/lower_tests.rs:6`.
- Several earlier wrongly-culled tests appear restored: branch_flip JSET at
  `bpfopt/crates/bpfopt/src/passes/branch_flip_tests.rs:109`, ccmp payload ABI
  at `bpfopt/crates/bpfopt/src/passes/ccmp_tests.rs:73`, and map_inline overlay
  conflict at `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:156`.

Weak:

- The test suite is currently red.
- DCE has only two tests. That is probably acceptable for the small pass, but it
  is still a narrow regression surface.
- Prefetch has five tests and no direct evidence of its old CFG/liveness
  interactions beyond the retained cases.
- Tests exercise the new trait boundary, but for C-rated passes they still
  exercise flat scanning inside the pass. This is visible in the pass code, not
  the test helper.
- `cargo test` emits dead-code warnings for test helpers:
  `install_map_value()` at `bpfopt/crates/bpfopt/src/mock_maps.rs:51`,
  `install_sparse_overlay()` at `bpfopt/crates/bpfopt/src/mock_maps.rs:74`,
  `ctx_with_map_snapshot()` at `bpfopt/crates/bpfopt/src/test_helpers.rs:108`,
  `add_map_overlay()` at `bpfopt/crates/bpfopt/src/test_helpers.rs:121`, and
  `regset()` at `bpfopt/crates/bpfopt/src/test_helpers.rs:297`.

## Runtime Risk

1. **Metadata drift across passes is already observable.** The failing
   map_inline -> const_prop -> dce test demonstrates that a pass can leave
   BBProgram in a state where the next pass cannot read required original-PC
   metadata. The failing lookup is in `const_prop.rs:545`.

2. **Panics remain in production APIs.** `split_block()` uses `panic!`/`assert!`
   at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:307` and
   `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:313`. `btf_records()`
   uses `expect()` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:171`.

3. **Physical-order lowering is a hidden invariant.** `lower()` emits
   `0..prog.blocks.len()` order at
   `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:12` and then rejects
   non-adjacent fallthrough at
   `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:77`. This is workable,
   but it means mutation methods and passes must preserve physical adjacency.

4. **Public stale APIs remain reachable.** `BpfProgram` and old BTF remap
   helpers remain public in `pass.rs`, and old analysis modules remain exported
   from `analysis/mod.rs:23`. Clippy does not catch exported public dead API.

5. **Error messages are generally informative.** The migration mostly uses
   `anyhow::bail!` with context, for example invalid block IDs at
   `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:339` and lower adjacency
   errors at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:80`.

## Final Assessment

Phase 3 is not done.

The current branch has the right outer shape, but the full design contract is not
met. To declare Phase 3 complete, at minimum:

1. Fix the duplicate `analysis/mod.rs` re-exports so the crate compiles.
2. Re-run the full suite; if the prior state reproduces, fix the failing
   map_inline cascade test.
3. Remove or privatize the dead public BTF remap helpers and stale BpfProgram
   comments.
4. Decide whether the acceptance target is total LOC or non-test LOC. If it is
   intended to measure real simplification, the current result fails because
   production LOC increased.
5. Either finish native BBProgram detection for C-rated passes or explicitly
   amend the design to allow lowered-flat analysis inside pass internals.
6. Convert production `split_block()` panics/asserts into `Result` errors.
7. Remove staged benchmark/result artifacts from the Phase 3 diff unless they are
   deliberately part of a separate artifact commit.
