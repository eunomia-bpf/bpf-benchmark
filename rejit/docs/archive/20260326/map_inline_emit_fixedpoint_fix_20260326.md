# map_inline emit + fixed-point fix report

Date: 2026-03-26

## Scope

Fixed two `map_inline`-related issues in the daemon pass pipeline:

1. `map_inline` now emits a one-slot `MOV64_IMM` when an inlined 64-bit scalar value fits in signed 32 bits.
2. `PassManager` now reruns `const_prop -> dce` to a fixed point, capped at 5 iterations.

## Changes

### Bug 1: 32-bit constants no longer force `LD_IMM64`

File: `daemon/src/passes/map_inline.rs`

- Updated `emit_constant_load()` so `BPF_DW` inlined values use `MOV64_IMM` when the decoded scalar is within `i32::MIN..=i32::MAX`.
- Values outside that range still use `LD_IMM64`.
- Narrower loads keep using `MOV64_IMM` only when their zero-extended value fits in positive `i32`; otherwise they still use `LD_IMM64` to preserve semantics.

### Bug 2: `const_prop + dce` now reaches a fixed point

File: `daemon/src/pass.rs`

- Refactored single-pass execution into `PassManager::run_single_pass()`.
- Added `const_prop`/`dce` pair detection in `PassManager::run()`.
- When the enabled pipeline contains adjacent `const_prop` then `dce`, the pair is rerun until both passes report no change, with `CONST_PROP_DCE_FIXED_POINT_MAX_ITERS = 5`.
- Added a unit test that proves the manager performs the extra stabilization rounds.

## Tests added

- `daemon/src/passes/map_inline.rs`
  - `map_inline_pass_emits_mov64_imm_for_dw_constants_that_fit_i32`
- `daemon/src/pass.rs`
  - `test_pass_manager_retries_const_prop_and_dce_to_fixed_point`

## Verification

Executed:

```bash
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml map_inline
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml const_prop
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml dce
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml cascade
cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml
```

Results:

- `map_inline`: passed
- `const_prop`: passed
- `dce`: passed
- `cascade`: passed
- full daemon test suite: passed (`503 passed, 12 ignored, 0 failed`)

## Notes

- Test runs emitted existing `dead_code` warnings in unrelated modules, but there were no test failures.
- The repository already had unrelated uncommitted changes outside this fix; they were left untouched.
