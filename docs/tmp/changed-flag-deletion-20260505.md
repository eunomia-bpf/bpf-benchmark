# Changed Flag Deletion, 2026-05-05

Scope: current `main` after the changed-flag deletion that landed in ancestor commits `c510c646` and `45c7a647`, plus this follow-up that pins the exact noop bootstrap diagnostic.

## LoC Delta

Changed-flag deletion accounting across `c510c646` + `45c7a647`:

| File | Added | Deleted | Net |
| --- | ---: | ---: | ---: |
| `bpfopt/crates/bpfopt/src/main.rs` | 27 | 12 | +15 |
| `bpfopt/crates/bpfopt/src/pass.rs` | 1 | 0 | +1 |
| `bpfopt/crates/bpfopt/src/passes/map_inline.rs` | 2 | 0 | +2 |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | 3 | 0 | +3 |
| `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs` | 0 | 32 | -32 |
| `bpfopt/crates/bpfopt/tests/cli_pipeline.rs` | 4 | 3 | +1 |
| `corpus/driver.py` | 1 | 9 | -8 |
| `daemon/src/commands.rs` | 104 | 421 | -317 |
| `daemon/src/server.rs` | 0 | 2 | -2 |
| `runner/libs/rejit.py` | 12 | 263 | -251 |
| `scripts/p88_branch_flip_dense_pgo.sh` | 2 | 2 | 0 |
| `docs/tmp/opaque-passthrough-20260505.md` | 18 | 0 | +18 |
| `docs/tmp/full-decouple-and-sweep-20260505.md` | 61 | 0 | +61 |
| Total | 235 | 744 | -509 |

Total LoC deleted: 744. Total LoC added: 235. Net delta: -509.

This follow-up did not edit `runner/libs/`, `corpus/`, or `vendor/linux-framework`.

## Validation

- `cargo build --release --workspace --manifest-path bpfopt/Cargo.toml`: passed.
- `cargo build --release --workspace --manifest-path daemon/Cargo.toml`: passed.
- `cargo test --release --workspace --manifest-path bpfopt/Cargo.toml`: 406 tests passed.
- `cargo test --release --workspace --manifest-path daemon/Cargo.toml`: 23 tests passed.
- No `make vm-corpus`, `make vm-e2e`, `make vm-micro`, or `make aws-*` command was run.

## Confirmations

- Noop hint text is preserved as `PassDetail.error` for `PassStatus::SkippedMissingStates`: `daemon/src/commands.rs:477` in the committed tree.
- Every bpfopt-successful pass invocation now reaches `BPF_PROG_REJIT` when verifier-state prerequisites are satisfied: `daemon/src/commands.rs:494` reads the report, `daemon/src/commands.rs:527` decodes output bytecode, and `daemon/src/commands.rs:539` calls `rejit_program()` without a `changed` short-circuit.
- `rg -n "\\bchanged\\b|Unchanged|total_sites_applied|program_changed" bpfopt/crates/bpfopt/src daemon/src --glob '!target'` has no changed-flag schema hits; only unrelated prose/function names such as `replacement_if_changed` remain outside the deleted protocol path.
- Commit hash: recorded in the final response after commit creation. A commit cannot contain its own final Git object ID without changing that ID.
