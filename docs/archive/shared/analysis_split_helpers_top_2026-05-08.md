# Analysis split + top-level test_helpers, 2026-05-08

## Changed files

- `bpfopt/crates/bpfopt/src/lib.rs`
- `bpfopt/crates/bpfopt/src/test_helpers.rs` moved from `bpfopt/crates/bpfopt/src/passes/test_helpers.rs`
- `bpfopt/crates/bpfopt/src/passes/mod.rs`
- `bpfopt/crates/bpfopt/src/pass_tests.rs`
- `bpfopt/crates/bpfopt/src/passes/*_tests.rs`
- `bpfopt/crates/bpfopt/src/passes/utils.rs`
- `bpfopt/crates/bpfopt/src/analysis/mod.rs`
- `bpfopt/crates/bpfopt/src/analysis/branch_target.rs`
- `bpfopt/crates/bpfopt/src/analysis/branch_target_tests.rs`
- `bpfopt/crates/bpfopt/src/analysis/cfg.rs`
- `bpfopt/crates/bpfopt/src/analysis/cfg_tests.rs`
- `bpfopt/crates/bpfopt/src/analysis/liveness.rs`
- `bpfopt/crates/bpfopt/src/analysis/liveness_tests.rs`

## test_helpers

`test_helpers` is now a crate-level test-only module:

```rust
#[cfg(test)]
pub mod test_helpers;
```

All old `crate::passes::test_helpers` imports were rewritten to `crate::test_helpers`.
The helper implementations were not changed.

## Analysis LOC

Counts include implementation plus sibling test file after the split.

| analysis | before LOC | after LOC |
|---|---:|---:|
| `branch_target` | 134 | 113 (`branch_target.rs` 53 + `branch_target_tests.rs` 60) |
| `cfg` | 235 | 196 (`cfg.rs` 195 + `cfg_tests.rs` 1) |
| `liveness` | 263 | 255 (`liveness.rs` 141 + `liveness_tests.rs` 114) |
| **total** | **632** | **564** |

## Deleted trivial tests / dead code

Deleted trivial tests:

| test | reason |
|---|---|
| `cfg_linear_program` | Only checked non-empty block list and first block start. |
| `cfg_branch_creates_blocks` | Length-only assertion on block count. |

Dead/public surface cleanup:

| item | action |
|---|---|
| `analysis::liveness::insn_use_def` | Narrowed from `pub` to `pub(super)`; production callers are inside `liveness`, tests access it from `analysis` sibling test module. |

No `#[allow(dead_code)]` targets remain in the touched analysis files.

## Validation

From `bpfopt/`:

```text
cargo test -p bpfopt
Finished `test` profile [unoptimized + debuginfo] target(s) in 1.17s
running 319 tests
test result: ok. 319 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
running 9 tests
test result: ok. 9 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
running 11 tests
test result: ok. 11 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
Doc-tests bpfopt
test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

```text
cargo build --release -p bpfopt
Finished `release` profile [optimized] target(s) in 10.43s
```

No corpus benchmark was run.
