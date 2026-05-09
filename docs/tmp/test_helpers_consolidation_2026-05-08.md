# test_helpers consolidation

## Extracted helpers

All extracted helpers now live in `bpfopt/crates/bpfopt/src/passes/test_helpers.rs`.
Test files import them with `use crate::passes::test_helpers::*;`.

| Helper | Before | After |
|---|---|---|
| `exit_insn` | `branch_flip_tests.rs`, `skb_load_bytes_tests.rs`, `prefetch_tests.rs`, `bounds_check_merge_tests.rs`, `endian_tests.rs`, `const_prop_tests.rs`, `ccmp_tests.rs`, `dce_tests.rs` | `test_helpers.rs` |
| `call_helper` | `const_prop_tests.rs` duplicate, already present in `test_helpers.rs` | `test_helpers.rs` |
| `jeq_imm` | `bulk_memory_tests.rs`, `wide_mem_tests.rs`, `branch_flip_tests.rs`, `skb_load_bytes_tests.rs`, `prefetch_tests.rs`, `mod_tests.rs`, `extract_tests.rs`, `map_inline_tests.rs`, `endian_tests.rs`, `cond_select_tests.rs`, `dce_tests.rs` | `test_helpers.rs` |
| `jne_imm` | `branch_flip_tests.rs`, `skb_load_bytes_tests.rs`, `map_inline_tests.rs`, `cond_select_tests.rs` | `test_helpers.rs` |
| `jgt_reg` | `skb_load_bytes_tests.rs`, `bounds_check_merge_tests.rs` | `test_helpers.rs` |
| `ld_imm64` | `wide_mem_tests.rs`, `prefetch_tests.rs`, `mod_tests.rs`, `const_prop_tests.rs`, `map_inline_tests.rs` | `test_helpers.rs` as `ld_imm64(dst, src, imm: i64)` |
| `mov32_reg` | `rotate_tests.rs`, `cond_select_tests.rs` | `test_helpers.rs` |
| `add64_imm` | `const_prop_tests.rs`, `map_inline_tests.rs` | `test_helpers.rs` |
| `st_mem` | `bulk_memory_tests.rs`, `mod_tests.rs`, `map_inline_tests.rs` | `test_helpers.rs` |
| `scalar_reg` | `mod_tests.rs`, `map_inline_tests.rs`, `const_prop_tests.rs`, `dce_tests.rs` | `test_helpers.rs` |
| `fp_reg` | `mod_tests.rs`, `map_inline_tests.rs` | `test_helpers.rs` |
| `verifier_delta_state` | `mod_tests.rs`, `map_inline_tests.rs`, `const_prop_tests.rs`, `dce_tests.rs` | `test_helpers.rs` |
| `verifier_delta_state_with_stack` | `mod_tests.rs`, `map_inline_tests.rs` | `test_helpers.rs` |
| `stack_snapshot_from_key` | `mod_tests.rs`, `map_inline_tests.rs` | `test_helpers.rs` |
| `install_map` | `mod_tests.rs`, `map_inline_tests.rs` | `test_helpers.rs` as `install_map(map_id, map_type, max_entries, values)` |
| `install_array_map` | `mod_tests.rs`, `map_inline_tests.rs` | `test_helpers.rs` |
| `make_program` | `bulk_memory_tests.rs`, `wide_mem_tests.rs`, `branch_flip_tests.rs`, `rotate_tests.rs`, `mod_tests.rs`, `extract_tests.rs`, `endian_tests.rs`, `cond_select_tests.rs` | `test_helpers.rs` |
| `sidecar_payload` | `prefetch_tests.rs`, `endian_tests.rs`, `ccmp_tests.rs`, `cond_select_tests.rs` | `test_helpers.rs` |

## Left local

These names appear in multiple files, but the implementations are different pass-local fixtures and depend on local builders. They were left local to avoid changing test input semantics or moving single-file fixture machinery:

| Helper | Files | Reason |
|---|---|---|
| `make_variable_offset_program` | `skb_load_bytes_tests.rs`, `bounds_check_merge_tests.rs` | Different programs for different passes |
| `make_different_base_regs_program` | `bulk_memory_tests.rs`, `bounds_check_merge_tests.rs` | Different programs for different passes |

## LOC

Before consolidation, `test_helpers.rs` plus pass test files totaled 9237 LOC.
After consolidation, they total 8823 LOC.

`git diff --numstat` for the touched pass test/helper files reports 639 deleted lines and 225 added lines, for a net reduction of 414 LOC.

## Validation

`cargo test -p bpfopt`

```text
test result: ok. 321 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 9 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 11 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

`cargo build --release -p bpfopt`

```text
Finished `release` profile [optimized] target(s) in 0.01s
```
