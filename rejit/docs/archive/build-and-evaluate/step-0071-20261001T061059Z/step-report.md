# Step 0071 — KVM x86 `make micro` full-suite refresh (29 benches, 3 runtimes)

- **Date:** 2026-10-01 06:10–06:18 UTC
- **Prev HEAD:** `b3d899262` (step-0070 KVM corpus `kinsn` commit)
- **Run:** `make micro SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 JOBS=8
  IMAGE_BUILD_JOBS=8` (default = `micro/config/micro_pure_jit.yaml` suite,
  empty `BENCH` = all 29 benches, runtimes `native/llvmbpf/kernel`),
  detached via `setsid nohup`. `MICRO_EXIT=0`, zero reaping lines, clean
  ACPI S5 power-down.
- **Why this step:** the KVM micro measurement layer had not been refreshed
  since the 09-30 09:33 tree (`x86_kvm_micro_20260930_093345_919079`), while
  the KVM corpus layer advanced through 0066–0070. This brings the KVM
  micro layer to the current tree (`b3d899262`) so both KVM layers share a
  tree generation.

## Result
- **New tree:** `micro/results/x86_kvm_micro_20261001_061549_699286/`
  (run_type `x86_kvm_micro`, status `completed`; in-VM suite 06:15:49 →
  06:18:05 ≈ 2m16s, matching the 09-30 tree's 2m14s window).
- **Benchmarks:** 29/29 present in both trees, same set. Runtimes per tree:
  `native` 29, `llvmbpf` 29, `kernel` 29.
- **Correctness:** all 261 samples (29 benches × 3 runtimes × 3 samples)
  match the suite's declared `expected_result`/`expected_retval` (261 ok, 0
  bad). Suite = `micro_staged_codegen`, defaults `inner_repeat 100000,
  samples 3, warmups 0, shuffle_seed None, perf_counters False` — identical
  in both trees.

## Raw-counter cross-check (new `20261001` vs 09-30 `20260930`)
Per-bench median `exec_ns` ratios (new/old), geomean over the 29 benches:
- **kernel** ×1.0014 (15 faster / 7 slower / 7 ~flat)
- **llvmbpf** ×1.0330 (6 faster / 10 slower / 13 ~flat)
- **native** ×0.9369 (11 faster / 13 slower / 5 ~flat)

These are within host-JIT run-to-run variance for a pure-jit suite; none
indicates a codegen regression. The structural invariance confirms it:
`bpf_bytecode_bytes` median-per-bench sum is **identical** (55,872 in both
trees, delta +0) — the JIT input has not changed between the two tree
generations. JIT codegen medians (`compile_ns`): llvmbpf 13.19 ms ≫
kernel 2.29 ms ≫ native 0.048 ms, the expected ordering.

- **Provenance:** host `virtme-ng`, `repo_dirty: False`,
  `cpu_model Intel(R) Core(TM) Ultra 9 285K`. (The in-VM VM records
  `repo_git_sha`/`kernel_commit` as `unknown` by design; the tree is tied to
  the launch's prev HEAD `b3d899262`.)

## Disposition
Scoped commit = the 3 structured tree files (`metadata.json`,
`details/result.json`, `details/progress.json`) + this report + a
forward-only research-log entry, following the step-0057 micro commit
precedent (5 files). The `details/code_compare/*.md` (29) and
`details/jit_dumps/*.bin` are not committed. No framework/app/runner/
Makefile change; no new gate. Remaining *run* blockers unchanged: AWS
credentials; Paper-B clean-source image rebuild
(`llvm_mapinline.hpp` still ` M`).
