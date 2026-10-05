# BoundsCheckMergePass TDD Report

Date: 2026-03-26

## What I changed

- Read the requested design, research, and existing pass/test framework files first.
- Added `daemon/src/passes/bounds_check_merge.rs` with:
  - a stub `BoundsCheckMergePass`
  - `required_analyses()` matching the design (`cfg`, `branch_targets`, `liveness`)
  - a no-op `run()` implementation that returns the program unchanged
  - TDD unit tests covering the requested merge, skip, gating, and branch-fixup scenarios
- Registered the module in `daemon/src/passes/mod.rs` with `pub mod bounds_check_merge;`

## Test intent

The tests encode the expected v1 contract from the design doc:

- merge adjacent/ladder packet bounds checks on XDP/TC programs
- keep the largest surviving window on the dominant guard
- preserve/fix branch targets after check removal
- reject non-mergeable cases such as variable offsets, different roots, different slow sinks, and gapped windows
- remain safe on empty/non-packet/no-bounds-check programs

## Verification

Command run:

```bash
cd daemon && cargo test bounds_check
```

Observed result with the current stub:

- compilation succeeds
- `13` filtered tests ran
- `11` tests failed and `2` passed
- failing tests are the merge/skip-contract tests that expect real `BoundsCheckMergePass` behavior
- passing tests are the structural no-op cases (`empty_program`, `no_bounds_checks`)
- implementation is intentionally deferred to the next step
