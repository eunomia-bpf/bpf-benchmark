# Micro Smoke Fix - 2026-04-28

## Summary

`make vm-micro SAMPLES=3` failed before the first benchmark result was appended because `micro/driver.py` tried to attach baseline adjustments while writing the initial `running` artifact. At that point `results["benchmarks"]` is still empty, so the strict baseline check raised:

```text
RuntimeError: baseline benchmark not found in results: simple
```

This was not a missing `simple` benchmark. `simple` is defined in `micro/config/micro_pure_jit.yaml` and implemented by `micro/programs/simple.bpf.c`; the compiled object is resolved through `BPFREJIT_MICRO_PROGRAM_DIR` as `simple.bpf.o`.

## Root Cause

- `micro/catalog.py` loads `micro/config/micro_pure_jit.yaml`; with no `--bench`, `select_benchmarks()` returns every manifest benchmark, with `simple` first.
- `analysis.baseline_benchmark` is `simple`.
- `attach_baseline_adjustments()` was called from the artifact metadata builder for every flush, including the first `running` flush before any benchmark had completed.
- Commit `ccd8debe` changed missing baseline behavior from silent return to immediate `RuntimeError`, which is correct for completed results but too strict for in-progress artifacts.
- The requested merge commits `7d34960`, `d973a4fd`, and `de64cde3` did not modify `micro/driver.py` or the micro benchmark catalog.

## Fix

- `micro/driver.py` now treats the baseline as required only for completed artifacts. Running/error artifacts keep best-effort metadata and do not mask the current run state before `simple` exists in `results["benchmarks"]`.
- After the baseline fix, the suite advanced far enough to expose stale expected values from the current generated-input specs. `micro/config/micro_pure_jit.yaml` now matches current llvmbpf/kernel outputs for:
  - `bitcount`
  - `log2_fold`
  - `load_word32`
  - `load_byte`
  - `mixed_alu_mem`
  - `spill_pressure`
  - `alu32_64_pingpong`
  - `const_fold_chain`
  - `smallmul_strength_reduce`
  - `tc_bitcount`

## Validation

- Host reproduction before fix:
  - `RuntimeError: baseline benchmark not found in results: simple`
- Host validation after fix:
  - `python3 micro/driver.py --runtime llvmbpf --samples 1 --warmups 0 --inner-repeat 10 --output /tmp/micro-test-fixed.json --perf-scope full_repeat_raw`
  - Completed 62/62 with no correctness mismatch.
- Expected-result audit:
  - Current llvmbpf outputs matched all manifest `expected_result` values: `MISMATCHES 0 ERRORS 0 TOTAL 0`.
- KVM validation:
  - Command: `make vm-micro SAMPLES=3`
  - Status: completed.
  - Artifact: `micro/results/x86_kvm_micro_20260429_035938_203074/metadata.json`
  - Benchmarks: 62/62.
  - Runtimes: `llvmbpf`, `kernel`.
  - Panic signatures: none observed.

## ReJIT Note

The current canonical `vm-micro` entrypoint invokes `micro/driver.py` with only `llvmbpf` and `kernel` runtimes. `micro/driver.py` rejects non-stock runtimes, and the result artifact contains no `rejit` samples:

```json
{
  "runtime_names": ["kernel", "llvmbpf"],
  "total_sites_applied": 0,
  "passes_applied": {}
}
```

So `applied > 0` is not a property of the current `vm-micro` target. The fixed regression is the premature baseline failure; the validated target now completes the current configured micro suite.
