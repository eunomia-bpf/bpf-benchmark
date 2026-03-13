# Project Cleanup Report

Date: 2026-03-13

## Summary

Cleaned up the project to enforce a single benchmark entry point (Makefile) and canonical result locations.

## Changes Made

### 1. Root-level one-off scripts deleted

- `run_corpus_rerun.sh`
- `run_bextr_fix_validation.sh`
- `fix_tmp_and_run.sh`

### 2. docs/tmp one-off scripts deleted

All `.sh` and `.py` one-off scripts removed from `docs/tmp/`:
- `fix-and-run-all.sh`, `run-all-pending-tasks.sh`, `run-per-form-ablation.sh`
- `run-policy-iteration.sh`, `run-policy-rounds-6-10.sh`
- `ablation57_gap_factors.py`, `analyze_ablation_byte_recompose_callee_bmi.py`
- `check_jited.py`, `gap_decomposition.py`, `kernel_recompile_micro_resume.py`
- `kernel_recompile_micro_strict.py`, `measure_recompile_overhead.py`
- `regenerate_micro_v3_policies.py`, `render_post_fix_micro_62bench_report.py`
- `run_poc_v2_validation.py`, `run_poc_validation_in_vm.py`, `run_single_benchmark_modes.py`

### 3. JSON results moved to canonical locations

**To `micro/results/`:**
- `policy_round{1-4}.json` → `micro/results/policy_round{1-4}_20260313.json`
- `policy-iteration-demo-results.json` → `micro/results/policy_iteration_demo_20260313.json`
- `per-form-rerun-correct-policy.json` → `micro/results/per_form_rerun_correct_policy_20260313.json`
- `per_form_scan_micro.json` → `micro/results/per_form_scan_micro_20260313.json`
- `rigorous-benchmark-results.json` → `micro/results/rigorous_benchmark_results_early.json`
- `post_cmov_fix_smoke.json` → `micro/results/post_cmov_fix_smoke.json`
- `v5-iteration-raw-results.json` → `micro/results/v5_iteration_raw_results_early.json`
- `kernel_recompile_smoke.json`, `kernel_recompile_tolerant_smoke.json` → `micro/results/`
- `kernel_recompile_v2_tuned_fix.json` → `micro/results/`
- `poc-validation-results.json`, `poc-v2-validation-results.json` → `micro/results/`
- `code-size-by-progtype.json` → `micro/results/`
- `recompile_overhead_summary.json` → `micro/results/`
- All `ablation57_*.json` and `ablation_*.json` → `micro/results/ablation/`

**To `micro/results/kernel_recompile_per_bench_post_bextr_20260313/` (186 files):**
- Entire `docs/tmp/kernel_recompile_per_bench_post_bextr/` directory moved here

**To `micro/results/raw_data/`:**
- `kernel-fixed-baselines-*.jsonl` files
- `recompile_overhead_*.csv` files
- `kernel_recompile_v2_tuned_20260312.log`
- `micro_62bench_authoritative_20260313.run.log`

**To `corpus/results/`:**
- `corpus-perf-results.json`, `corpus-perf-smoke.json`, `corpus-perf-expanded-smoke.json`
- `corpus-v5-recompile-results.json`, `corpus-runnability-*.json`
- `corpus-tracing-*.json`, `corpus_v2_fixed_verify_*.json`
- `corpus-v2-policy-smoke-20260312.json`
- `new-corpus-v5-*.json` (results, smoke, calico, loxilb, suricata)
- `production-corpus-v5-*.json`
- `recompile_overhead_corpus_inventory.json`
- `corpus-expansion-round3-*.json` → `corpus/results/expansion/`
- `corpus-8families-persection.json`

**To `e2e/results/`:**
- `tracee-e2e-results.json`, `tracee-e2e-vm-results.json`
- `tracee-real-e2e-host-smoke.json`, `tracee-real-e2e-vm-smoke.json`
- `tracee-v2-policy-smoke-check.json`
- `tetragon-e2e-results.json`, `tetragon-e2e-vm-results.json`
- `bpftrace-e2e-results.json`, `bpftrace-e2e-vm-results.json`

### 4. Binary/temp artifacts deleted from docs/tmp

- `*.xlated.bin`, `*.bpf.o`, `bzImage.ablation.*`, `cmov_select.*.bin`
- `cmov_extract_*.log`, `kernel-config.ablation.*`
- `*.live.xlated`, `vng-*.txt`, `tmp_tuned_smoke.log`
- `kernel-recompile-micro-strict-run.log`
- `__pycache__/` directory

### 5. Per-bench run subdirectories deleted

These are old probe/debug run directories already summarized in `.md` files:
- `kernel_recompile_per_bench/`, `kernel_recompile_per_family_smoke/`
- `kernel_recompile_v2_tuned_resume_tmp/`, `kernel_recompile_v2_tuned_fix/`
- `kernel_recompile_v2_fixed_authoritative_per_bench/`, `kernel_recompile_v2_tuned_per_bench/`
- `kernel_recompile_per_family/`
- `micro_62bench_authoritative_per_bench/`, `micro_diag/`
- `post_fix_micro_62bench_20260313_per_bench/`, `post_fix_micro_62bench_20260313_per_bench_rerun/`
- `post_fix_micro_62bench_smoke/`, `post_fix_micro_6new_probe/`
- `tmp_*_family_probe/`, `tmp_probe_rotate_dense/`
- `rotate-v5-regression-jit/`, `rotate-v5-regression-runs/`
- `p0-figures-smoke/`, `bpftrace-artifacts/`, `vm-tmp/`
- `v4-round2-raw/`, `v4-round3-raw/`, `production-einval-debug/`
- `ablation_policies/` (4 ablation yaml variants, not part of active suite)

### 6. Makefile updated

- Output variables now point to canonical result directories:
  - `SMOKE_OUTPUT → micro/results/smoke.latest.json`
  - `VM_MICRO_OUTPUT → micro/results/vm_micro.latest.json`
  - `VM_CORPUS_OUTPUT_JSON → corpus/results/vm_corpus.latest.json`
  - `VM_TRACEE_OUTPUT_JSON → e2e/results/tracee.latest.json`
  - etc.
- Added `BENCH=` parameter support for `vm-micro`:
  - `make vm-micro BENCH="simple bitcount"` runs only those benchmarks
- Added `make help` target with full documentation
- `docs/tmp/` is no longer used for any output

### 7. CLAUDE.md updated

- "Run benchmarks" section now shows Makefile as the single entry point
- Added result directory documentation
- Added note that `docs/tmp/` is for analysis reports (.md) only, not JSON results

## Final State

```
docs/tmp/          - .md analysis reports only (no scripts, no JSON, no binaries)
micro/results/     - micro benchmark JSON results (154 files)
corpus/results/    - corpus benchmark JSON results (78 files)
e2e/results/       - e2e benchmark JSON results (30 files)
```

## Entry Points (After Cleanup)

| Task | Command |
|------|---------|
| Full micro suite | `make vm-micro` |
| Specific benchmarks | `make vm-micro BENCH="simple bitcount"` |
| Quick smoke test | `make smoke` |
| Corpus benchmark | `make vm-corpus` |
| E2E benchmarks | `make vm-e2e` |
| All VM benchmarks | `make vm-all` |
| Help / show targets | `make help` |
