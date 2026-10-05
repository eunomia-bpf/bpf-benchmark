# P3 Wrapper Purge Report - 2026-05-12

## Result

Target was a strict >= 300 net LOC reduction in allowed production files.

Actual safe reduction found and applied: 136 LOC net.

Status: target not met. I stopped at the clear wrapper set instead of inventing broader refactors. The remaining larger candidates I found are either in the protected concurrent zones (`map_inline`, `pass.rs`, tests) or are real behavior/API boundaries.

## Evidence Before Deletion

All removals below were checked with `rg` for zero callers or a bounded single/tiny call surface before deletion. The worktree already had unrelated dirty files before this task; LOC deltas below are measured against the pre-edit `/tmp/p3_wrapper_purge_start` snapshot where available. `bbprogram.rs` was not present in that snapshot, so its delta is counted from the applied deletion hunks.

## Category 1 - Single-caller forwarders

- `main.rs`: inlined `build_pass()` into `run_single_pass()` (`main.rs:319`) after `rg` showed one caller.
- `main.rs`: deleted `open_text_output()` and called `open_binary_output()` directly from list and JSON output paths (`main.rs:288`, `main.rs:679`).
- `main.rs`: deleted `read_target()` and typed the two `read_json_file(..., "target.json")` call sites (`main.rs:264`, `main.rs:748`).
- `main.rs`: deleted one-call bpftool path builders and inlined `path.join(format!(...))` at show/dump/supplement readers (`main.rs:1082`, `main.rs:1100`, `main.rs:1168`).
- `main.rs`: deleted `round_up_8()` and inlined the one caller (`main.rs:1469`).
- `analysis/bbprogram.rs` and `analysis/bbprogram_api.rs`: deleted `range_len()` and inlined the checked subtraction at `bbprogram_api.rs:89`.
- `analysis/bbprogram_api.rs`: deleted `common_branch_terminator()` and inlined the only caller in the no-join diamond replacement path (`bbprogram_api.rs:511`).
- `analysis/bbprogram_lift.rs`: inlined `lift_with_side_inputs()` into `lift_with_pass_context()` (`bbprogram_lift.rs:137`).
- `passes/prefetch.rs`: deleted `skip_at()` and called `pf_skip_reason()` directly (`prefetch.rs:115`, `prefetch.rs:122`).
- `passes/endian.rs`: deleted `blocks_narrow_window()` and inlined the one expression at `endian.rs:75`.

## Category 2 - One-line accessors

- `analysis/bbprogram_use_def.rs`: deleted `DefSite::site()` and `UseSite::site()`. Their fields are public and all production call sites now construct `InsnSite` directly.
- `analysis/bbprogram_use_def.rs`: deleted unused `UseDefGraph::uses()`.
- `insn.rs`: deleted unused `BpfInsn::code()` and inlined the sole `regs()` call in `raw_bytes()` (`insn.rs:283`).
- `analysis/bbprogram.rs`: deleted unused `block_is_body_empty()` and `copied_body_insns()`.

## Category 3 - Identity wrappers

- `analysis/bbprogram_btf.rs` and `analysis/bbprogram_lower.rs`: deleted `BtfRecordRemap` plus `remap_btf_record_pc()`. Both remap paths now use `old_to_new.get(&old_pc).copied()` directly (`bbprogram_btf.rs:67`, `bbprogram_lower.rs:73`).

## Category 4 - Type aliases used once

- `passes/const_prop.rs`: deleted `type ConstPropReplacement` and inlined the tuple type in `RewriteOutputs` (`const_prop.rs:45`).

## Category 5 - Trivial trait impl passthroughs

None deleted. The remaining `BpfPass::run()` implementations are the trait contract and still provide the uniform pass entrypoint.

## Category 6 - Multi-level dispatch chains

- `passes/branch_flip.rs` and `passes/prefetch.rs`: deleted pass-local `from_cli_args()` wrappers that only rejected an argument and returned a default pass. The registry now uses the normal `pass_entry!` path (`passes/mod.rs:135`, `passes/mod.rs:136`).

## Category 7 - Tiny helper modules

None found in the allowed production files.

## Category 8 - Stub/marker types and re-exports

- `passes/mod.rs`: deleted unused `run_*_on_bbprogram` re-export aliases. `rg` showed no callers outside the re-export lines.
- `passes/mod.rs`: deleted `pass_entry_with_args!()` after only `map_inline` needed a custom constructor; that remaining entry is explicit (`passes/mod.rs:123`).

## Category 9 - Dead variants or unreachable arms

None deleted beyond `BtfRecordRemap`, which is counted under Category 3 because it was an identity wrapper over `Option`.

## Category 10 - Repeated boilerplate

None deleted. The repeated pass scan/apply shapes are real pass logic and would require a larger abstraction, not a wrapper purge.

## LOC Delta

| File | Delta |
| --- | ---: |
| `bpfopt/crates/bpfopt/src/main.rs` | -28 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs` | -13 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs` | -3 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs` | -16 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs` | -4 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs` | -12 |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs` | -22 |
| `bpfopt/crates/bpfopt/src/insn.rs` | -8 |
| `bpfopt/crates/bpfopt/src/passes/mod.rs` | -10 |
| `bpfopt/crates/bpfopt/src/passes/branch_flip.rs` | -15 |
| `bpfopt/crates/bpfopt/src/passes/prefetch.rs` | -14 |
| `bpfopt/crates/bpfopt/src/passes/const_prop.rs` | -1 |
| `bpfopt/crates/bpfopt/src/passes/endian.rs` | -3 |
| `bpfopt/crates/bpfopt/src/passes/dce.rs` | +7 |
| `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs` | +6 |
| **Total** | **-136** |

## Gates

- `cd bpfopt && cargo build --release`: pass.
- `cd bpfopt && cargo test --release`: pass. Counts observed: 178 lib tests, 13 main tests, 1 `bbprogram_roundtrip` test, 12 `cli_pipeline` tests, 0 doctests.
- `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`: pass.
- `cd bpfopt && cargo fmt --all && cargo fmt --all --check`: pass.

## Considered But Kept

- `passes/map_inline.rs`, `passes/map_inline/`, `pass.rs`, and test files: skipped because they are protected by concurrent codex ownership.
- `SlotDistance`, `KopAdmissionWindow`, and other documented invariant types: kept because they enforce semantic boundaries.
- BBProgram transaction-style mutation methods (`delete_insn`, `replace_range_at`, etc.): kept because clone/mutate/commit behavior is intentional.
- `PASS_ALIASES` and `cli_name_for_pass()`: kept because they encode CLI compatibility and are covered by CLI tests.
- `run_on_bbprogram()` pass entry functions: kept because deleting them would require moving full pass bodies for minimal net reduction and would churn real pass entrypoints.
- `verifier_log.rs` parser helpers: kept because they preserve parse boundaries and error context, not wrappers.
- `BpfInsn::as_kernel()`: kept because it is an ABI boundary used by tests and exposes the libbpf representation intentionally.
