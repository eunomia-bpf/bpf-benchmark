# Phase 3 Final Cleanup Report - 2026-05-10

## 1. Legacy Analysis Deletion

Deleted from `bpfopt/crates/bpfopt/src/analysis/`:

- `branch_target.rs`
- `cfg.rs`
- `liveness.rs`
- `map_refs.rs`
- `site_scan.rs`

Verification:

- `ls bpfopt/crates/bpfopt/src/analysis/{branch_target,cfg,liveness,map_refs,site_scan}.rs` reports all five as missing.
- `rg "BranchTargetAnalysis|CFGAnalysis|LivenessAnalysis|MapRefsAnalysis|SiteScanAnalysis|iter_sites" bpfopt/crates/bpfopt/src --type rust` returns no matches.

The re-ported BBProgram coverage tests were moved to crate-root test modules:

- `bbprogram_branch_target_tests.rs`
- `bbprogram_cfg_tests.rs`
- `bbprogram_liveness_tests.rs`
- `bbprogram_map_refs_tests.rs`
- `bbprogram_site_scan_tests.rs`

## 2. Legacy Consumer Re-Port Audit

- `pass.rs:194` replaced `CFGAnalysis::run(&insns)` subprogram discovery with direct pseudo-call / pseudo-func target scanning for `kinsn_candidate_subprog_starts`.
- `passes/rotate.rs:80` replaced `BranchTargetAnalysis::run` with `prog.branch_target_pcs()`.
- `passes/rotate.rs:113` replaced `LivenessAnalysis::run` with `prog.live_out_current_pc(...)`.
- `passes/rotate.rs:230` replaced `iter_sites` with `linear_insn_sites`.
- `passes/bulk_memory.rs:205` replaced `BranchTargetAnalysis::run` with `prog.branch_target_pcs()`.
- `passes/bulk_memory.rs:296` replaced `LivenessAnalysis::run` with `prog.live_out_current_pc(...)`.
- `passes/wide_mem.rs:498` replaced `BranchTargetAnalysis::run` with `prog.branch_target_pcs()`.
- `passes/wide_mem.rs:535` replaced `LivenessAnalysis::run` with `prog.live_out_current_pc(...)`.
- `passes/prefetch.rs:269` replaced `BranchTargetAnalysis::run` with `prog.branch_target_pcs()`.
- `passes/prefetch.rs:462` and `passes/prefetch.rs:564` replaced `iter_sites` with `linear_insn_sites`.
- `passes/endian.rs:85` replaced `iter_sites` with `linear_insn_sites`.
- `passes/endian.rs:376` replaced `BranchTargetAnalysis::run` with `prog.branch_target_pcs()`.
- `passes/skb_load_bytes.rs:59` replaced `BranchTargetAnalysis::run` with `prog.branch_target_pcs()`.
- `passes/skb_load_bytes.rs:105` replaced `iter_sites` with `linear_insn_sites`.
- `passes/cond_select.rs:132` replaced `LivenessAnalysis::run` with `prog.live_out_current_pc(...)`.
- `passes/cond_select.rs:281` uses `prog.successors(...)` for diamond join discovery.
- `passes/cond_select.rs:289` replaced `iter_sites` with `linear_insn_sites`.
- `passes/ccmp.rs:355` uses `prog.predecessors(...)` for chain validation.
- `passes/ccmp.rs:378` replaced `iter_sites` with `linear_insn_sites`.
- `passes/ccmp.rs:437` replaced `LivenessAnalysis::run` with `prog.live_out_current_pc(...)`.
- `passes/extract.rs:78` replaced `iter_sites` with `linear_insn_sites`.
- `passes/extract.rs:117` replaced `BranchTargetAnalysis::run` with `prog.branch_target_pcs()`.
- `passes/branch_flip.rs:271` replaced `BranchTargetAnalysis::run` with `prog.branch_target_pcs()`.
- `passes/branch_flip.rs:526` replaced `iter_sites` with `linear_insn_sites`.
- `passes/map_inline.rs:1054` and `passes/map_inline.rs:1765` replaced `iter_sites` with `linear_insn_sites`.
- `passes/map_inline.rs:2313` replaced `MapRefsAnalysis::run` binding reads with `prog.map_bindings()`.
- `passes/map_inline.rs:2438` replaced local branch-target analysis with `prog.branch_target_pcs()`.
- `passes/map_inline.rs:3050` and `passes/map_inline.rs:3146` replaced local PC/site maps with `prog.current_pc_sites()`.
- `passes/map_inline/map_info.rs:129` and `passes/map_inline/map_info.rs:171` replaced `MapRefsAnalysis::run` with a local linear binding collector over `BpfProgram` map IDs / stable fd bindings.

## 3. `map_inline.rs`

- LOC: `5617 -> 5689`.
- Removed the old `MapInlineEdit` adapter.
- The pass entrypoint and fixed-point loop now mutate `&mut BBProgram` directly.
- Replacements/deletions are committed through `prog.replace_range(...)` and terminator rewrites through `prog.replace_terminator(...)`.
- Cascade cleanup uses `prog.delete_unreachable_blocks()`.
- Branch target and current-PC/site queries now use BBProgram APIs.

Known remaining cleanup gap: this file did not reach the requested `3500-4000` LOC target. The complex lookup planner still carries `SiteRewrite`, `ReplacementBranchPatch`, `BTreeMap<usize, Vec<BpfInsn>>`, and `skipped_pcs` as linear rewrite-planning structures before applying edits to BBProgram.

## 4. `pass.rs`

- LOC: `1497 -> 1115`.
- Removed legacy `CFGAnalysis` dependency.
- Removed old BTF remap helpers from `pass.rs`; BTF remapping now lives on BBProgram lowering.
- Removed kinsn BTF/proof remap helpers that belonged to the old linear `BpfProgram` path.
- Slimmed `BpfProgram` to the map snapshot helper view and removed unused annotation/profiling/BTF fields and helper methods.

## 5. `bbprogram_api.rs`

Zero-caller public APIs checked by `rg` and absent in the final tree:

- `replace_insn`
- `insert_insn`
- `delete_block`
- `rewire_edge`
- `replace_diamond_with_kinsn`

No new zero-caller public BBProgram APIs were found by the final clippy gate.

## 6. Final Test Count

`cargo test --release --manifest-path bpfopt/Cargo.toml`:

- lib tests: 188 passed
- main tests: 16 passed
- `bbprogram_roundtrip`: 1 passed
- `cli_pipeline`: 12 passed
- doc tests: 0
- total: 217 passed

## 7. Final Non-Test LOC

Requested `src/**/*.rs` scope, excluding `*_tests.rs`: `16054`.

Full `src` non-test count including top-level Rust files not covered by the shell glob: `21672`.

## 8. Final Total LOC

Exact requested command:

```text
wc -l bpfopt/crates/bpfopt/src/**/*.rs
...
18949 total
```

Full `src` Rust total including top-level files: `25135`.

## 9. Clippy

`cargo clippy --release --manifest-path bpfopt/Cargo.toml -- -D dead_code -D warnings` completed cleanly.

## 10. CLI Smoke

```text
target/release/bpfopt --pass dce \
  --input  bpfopt/testbin/otelcol-ebpf-profiler_profiling/47_perf_unwind_php/canonicalize_output.bin \
  --output /tmp/dce_smoke.bin \
  --report /tmp/dce_smoke.json \
  --prog-type tracepoint \
  --target  bpfopt/testbin/otelcol-ebpf-profiler_profiling/47_perf_unwind_php/target.json
exit=0
```

## 11. Per-Pass Rating

All listed passes are rated A on build/test/list/smoke coverage:

- `noop`: A
- `map-inline`: A
- `const-prop`: A
- `dce`: A
- `skb-load-bytes`: A
- `bounds-check-merge`: A
- `wide-mem`: A
- `bulk-memory`: A
- `rotate`: A
- `cond-select`: A
- `ccmp`: A
- `extract`: A
- `endian`: A
- `branch-flip`: A
- `prefetch`: A
