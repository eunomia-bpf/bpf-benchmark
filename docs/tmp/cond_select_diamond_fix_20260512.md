# cond_select diamond external-predecessor fix

Date: 2026-05-13

## Verdict Source

Read `docs/tmp/cilium_regression_full_20260512.md`, especially the Verdict section. The decisive signal is the current cilium run aborting `cond_select` with:

```text
diamond join BlockId(...) has external predecessor BlockId(...)
```

That abort marks the program failed for the pass chain, so remaining passes do not get a successful `cond_select` output for those programs.

## Fix

Implemented scan-time rejection in `bpfopt/crates/bpfopt/src/passes/cond_select.rs`.

- `scan_cond_select_sites()` now returns both candidate sites and scan-time skipped sites.
- `try_match_pattern_a()` checks the shared join after the mov-diamond shape is otherwise matched. The join may only have the taken and fallthrough branch blocks as predecessors.
- `try_match_pattern_c()` checks its join after the short pattern is otherwise matched. The join may only have the predecessor block and false branch block as predecessors.
- If an external predecessor is found, the pass records a `SiteSkipReason` with the same diagnostic shape as the validator error and does not call `replace_diamond_with_insns()` for that site.

`bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs` keeps the strict diamond invariant by rejecting joins with external predecessors in `validate_diamond()`. This preserves fail-fast behavior if another caller ever bypasses the pass-level scan guard.

## Regression Input

The new unit test builds this mini program:

```text
pc0: if r9 == 0 goto pc5      ; external edge to shared join
pc1: if r1 != 0 goto pc4      ; inner cond_select candidate
pc2: r0 = 0                   ; false mov
pc3: goto pc5
pc4: r0 = 1                   ; true mov
pc5: exit                     ; join has pc0 plus diamond predecessors
```

Without the scan guard, the inner diamond reaches `replace_diamond_with_insns()` and strict validation rejects the shared join. With the fix, `cond_select` returns successfully, leaves bytecode unchanged, reports `sites_applied == 0`, and records one skipped site. CLI `sites_matched` would count this as `applied + skipped == 1`.

## Test Results

Targeted regression:

```text
cargo test -p bpfopt --lib cond_select_skips_diamond_join_with_external_predecessor
test result: ok. 1 passed; 0 failed; 166 filtered out
```

Full requested lib suite:

```text
cargo test -p bpfopt --lib
test result: ok. 167 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```

Formatting:

```text
cargo fmt --all --check
cargo fmt --all
```

Both formatting commands completed successfully; `cargo fmt --all` was a no-op after the check passed.

## Code Diff Stat

```text
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs | 25 ++++++++++
bpfopt/crates/bpfopt/src/passes/cond_select.rs     | 55 +++++++++++++++++++---
bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs  | 16 ++++---
3 files changed, 84 insertions(+), 12 deletions(-)
```
