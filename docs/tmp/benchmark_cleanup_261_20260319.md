# Task #261: Benchmark Cleanup

Date: 2026-03-19

## Scope

Remove the kernel runner adaptive-repeat path, clean dead references, and verify the benchmark binary still builds and the smoke target still passes.

## Changes

### 1. Deleted adaptive-repeat logic

- Removed the adaptive probe / threshold logic from `micro/runner/src/kernel_runner.cpp`.
- `run-kernel` now uses the caller-provided CLI repeat directly when kernel-side repeat is supported.
- Removed the now-unused `kAdaptiveProbeRepeat`, `kAdaptiveRepeatThresholdNs`, `clamp_repeat_count()`, and the unused `<limits>` include.

### 2. Cleaned dead references

- Removed `adaptive_repeat` and `target_window_ns` from `micro/runner/include/micro_exec.hpp`.
- Removed `--adaptive-repeat`, `--no-adaptive-repeat`, and `--target-window-ns` from `micro/runner/src/common.cpp` usage text, argument parsing, and validation.
- Checked `micro/runner/src/main.cpp`; it had no adaptive-repeat references, so no code change was needed there.

## Verification

Executed from `/home/yunwei37/workspace/bpf-benchmark` after activating `/home/yunwei37/workspace/.venv/bin/activate`.

1. `make -C micro micro_exec`
   Result: passed

2. `make smoke`
   Result: passed
   Notes: smoke ran the `simple` benchmark and wrote `micro/results/dev/smoke.json`.

## Constraints Check

- No commit created
- No branch created
- No kernel code under `vendor/linux-framework` modified
