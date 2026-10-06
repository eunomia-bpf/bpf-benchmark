# bpfopt unit test cleanup executed - 2026-05-07

## Scope

Modified only the requested bpfopt test modules plus this requested report:

- `bpfopt/crates/bpfopt/src/pass_tests.rs`
- `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs`
- `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs`
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs`
- `bpfopt/crates/bpfopt/src/passes/mod_tests.rs`
- `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs`

## LoC delta

`git diff --stat` for the six test files:

```text
6 files changed, 903 insertions(+), 1711 deletions(-)
```

Net LoC removed: **808**.

Line counts across the six test files: **5318 before -> 4510 after**.

## Test counts

| File | Before | After |
| --- | ---: | ---: |
| `bpfopt/crates/bpfopt/src/pass_tests.rs` | 16 | 13 |
| `bpfopt/crates/bpfopt/src/passes/mod_tests.rs` | 13 | 9 |
| `bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs` | 21 | 11 |
| `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs` | 27 | 13 |
| `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs` | 31 | 18 |
| `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` | 59 | 48 |
| **Total** | **167** | **112** |

## Verification

Command:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/bpfopt/Cargo.toml
```

Result: **passed**, 351 tests passed, 0 failed.

Breakdown:

- `bpfopt` lib tests: 296 passed
- `bpfopt` bin tests: 9 passed
- `tests/cli_pipeline.rs`: 10 passed
- `bpfprof` bin tests: 7 passed
- `tests/cli.rs`: 4 passed
- `kernel_sys` lib tests: 23 passed
- `tests/prog_get_original.rs`: 1 passed
- `tests/prog_ids.rs`: 1 passed
- doctests: 0 tests

## Skipped audit recommendations

None. All 16 recommended deletions were removed, and all 47 recommended merges were folded into existing or new compact table-driven tests.
