# Pass split/test/dead cleanup, 2026-05-08

Scope: handled the 14 requested non-`map_inline` passes under
`bpfopt/crates/bpfopt/src/passes/`. `map_inline.rs` / `map_inline_tests.rs`
were intentionally left alone because #258 is active there.

## LOC and test count

Counts include `<pass>.rs` plus `<pass>_tests.rs` when present. Test count is
the number of `#[test]` functions.

| pass | before LOC | before tests | after LOC | after tests |
|---|---:|---:|---:|---:|
| bounds_check_merge | 996 | 14 | 993 | 14 |
| branch_flip | 1067 | 16 | 1041 | 15 |
| bulk_memory | 1393 | 11 | 1392 | 11 |
| ccmp | 655 | 8 | 644 | 8 |
| cond_select | 1139 | 13 | 1137 | 13 |
| const_prop | 1267 | 15 | 1267 | 15 |
| dce | 150 | 1 | 147 | 1 |
| endian | 1149 | 25 | 1132 | 24 |
| extract | 762 | 27 | 747 | 26 |
| noop | 26 | 0 | 26 | 0 |
| prefetch | 1044 | 6 | 1041 | 6 |
| rotate | 960 | 23 | 958 | 23 |
| skb_load_bytes | 801 | 14 | 786 | 13 |
| wide_mem | 1352 | 18 | 1350 | 18 |
| **total** | **12761** | **191** | **12661** | **187** |

## Split summary

All inline `#[cfg(test)] mod tests { ... }` blocks in the scoped pass files were
moved to sibling `<pass>_tests.rs` files and declared from
`passes/mod.rs` as `#[cfg(test)] mod <pass>_tests;`.

Existing external test files (`bulk_memory_tests.rs`, `cond_select_tests.rs`,
`wide_mem_tests.rs`) were rewired from pass-child `#[path] mod tests` modules to
the same sibling module style.

Verification command:

```text
rg -n '#\[allow\(dead_code\)\]|allow\(dead_code\)|#\[cfg\(test\)\]|mod tests|#\[path = .*_tests.rs\]' \
  bpfopt/crates/bpfopt/src/passes/{bounds_check_merge,branch_flip,bulk_memory,ccmp,cond_select,const_prop,dce,endian,extract,noop,prefetch,rotate,skb_load_bytes,wide_mem}.rs \
  bpfopt/crates/bpfopt/src/passes/{bounds_check_merge,branch_flip,bulk_memory,ccmp,cond_select,const_prop,dce,endian,extract,prefetch,rotate,skb_load_bytes,wide_mem}_tests.rs

# no output
```

## Deleted meaningless tests

| test | reason |
|---|---|
| `branch_flip_tests::test_branch_flip_preserves_program_size` | Length-only assertion. `test_branch_flip_verifies_output_layout` covers the real bug surface: inverted opcode, branch offsets, and swapped bodies. |
| `endian_tests::test_endian_fusion_pass_no_sites` | Only asserted `sites_applied == 0` for a non-pattern. Scanner no-match and kfunc/shape negative tests cover actionable behavior. |
| `extract_tests::test_extract_pass_no_sites` | Only asserted `sites_applied == 0` for a non-pattern. Scanner no-match and pass skip/branch-fixup tests cover actionable behavior. |
| `skb_load_bytes_tests::test_output_fewer_or_equal_instructions` | Size-bound-only assertion, and weaker than exact rewrite/branch-fixup tests for the same successful specialization path. |

## Dead code / public surface cleanup

| item | action | grep verification |
|---|---|---|
| `ccmp.rs:CcmpFailMode::from_payload_bit` | Deleted test-only implementation helper. | `rg -n 'from_payload_bit' bpfopt/crates/bpfopt/src --glob '!target'` -> no output |
| `ccmp.rs:CcmpWidth::from_payload_bit` | Deleted test-only implementation helper. | `rg -n 'from_payload_bit' bpfopt/crates/bpfopt/src --glob '!target'` -> no output |
| `ccmp.rs:decode_ccmp_payload` | Removed from implementation; retained only as a test helper in `ccmp_tests.rs`. | `rg -n 'decode_ccmp_payload' bpfopt/crates/bpfopt/src/passes --glob '!ccmp_tests.rs'` -> no output |
| `prefetch.rs:decode_prefetch_payload` | Removed from implementation; retained only as a test helper in `prefetch_tests.rs`. | `rg -n 'decode_prefetch_payload' bpfopt/crates/bpfopt/src/passes --glob '!prefetch_tests.rs'` -> no output |
| `cond_select.rs:CondSelectSite`, `CondSelectValue`, `CondSelectPass::analyze` | Removed unused public surface by narrowing to `pub(super)`. | `rg -n 'pub struct CondSelectSite|pub enum CondSelectValue|pub fn analyze' bpfopt/crates/bpfopt/src/passes/cond_select.rs` -> no output |
| `wide_mem.rs:Binding`, `RewriteSite`, `RewriteSite::get_binding` | Removed unused public surface by narrowing to `pub(super)`. | `rg -n 'pub struct Binding|pub struct RewriteSite|pub fn get_binding' bpfopt/crates/bpfopt/src/passes/wide_mem.rs` -> no output |

No `#[allow(dead_code)]` targets remain in the scoped pass implementation/test
files.

## Cargo output

Baseline, before edits, from `bpfopt/`:

```text
cargo test -p bpfopt
Finished `test` profile [unoptimized + debuginfo] target(s) in 0.01s
running 325 tests
test result: ok. 325 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
running 9 tests
test result: ok. 9 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
running 11 tests
test result: ok. 11 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
Doc-tests bpfopt
test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

After cleanup:

```text
cargo test -p bpfopt
Finished `test` profile [unoptimized + debuginfo] target(s) in 0.93s
running 321 tests
test result: ok. 321 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
running 9 tests
test result: ok. 9 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
running 11 tests
test result: ok. 11 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
Doc-tests bpfopt
test result: ok. 0 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

Release build:

```text
cargo build --release -p bpfopt
Finished `release` profile [optimized] target(s) in 10.73s
```

No corpus benchmark was run.
