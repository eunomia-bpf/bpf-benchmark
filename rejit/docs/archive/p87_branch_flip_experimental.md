# P87 Branch Flip Experimental Restore

Date: 2026-04-29

## Decision

Paper A remains the kinsn track: `bulk_memory`, `rotate`, `cond_select`, `extract`, and `endian_fusion`.

Paper B is speculative runtime optimization based on profile/info. `branch_flip` is restored only as Paper B scaffolding and is marked experimental. It is not part of the default `bpfopt optimize` pass list.

## Changes

- Reverted the P84 Stage 1 removal of the Rust `branch_flip` pass and CLI plumbing.
- Restored `bpfprof` branch PMU scaffolding fields: `branch_miss_rate`, `branch_misses`, `branch_instructions`, and `per_insn`.
- Restored daemon `profile-start` / `profile-stop` socket commands backed by `bpfprof --output-dir`.
- Restored runner profile prep hooks, the `branch_flip_dense` micro benchmark entry/program, and the branch_flip unittest BPF program.
- Kept `DEFAULT_OPTIMIZE_PASS_ORDER` at 11 passes, excluding `branch_flip`.
- Kept `branch_flip` available for explicit CLI/manual use through `bpfopt branch-flip` and explicit pass lists.

## Experimental Status

`branch_flip` currently uses a PMU gate plus profile side-inputs. The restored implementation remains a Paper B placeholder until real per-site PGO is implemented; placeholder behavior must not be used as paper evidence.

## Verification

Passed:

- `cd bpfopt && cargo build --workspace`
- `cd bpfopt && cargo clippy --workspace --all-targets -- -D warnings`
- `cd bpfopt && cargo test --workspace`
- `cd daemon && cargo build`
- `cd daemon && cargo clippy --all-targets -- -D warnings`
- `cd daemon && cargo test`
