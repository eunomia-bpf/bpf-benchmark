# Rigorous Benchmarking Setup

## Purpose

`micro/run_rigorous.py` is the publication-grade microbenchmark driver for kernel JIT mode comparisons. It reuses:

- `micro/build/runner/micro_exec` as the execution primitive
- `config/micro_pure_jit.yaml` via `micro/benchmark_catalog.py`
- generated inputs from `micro/input_generators.py`

It adds:

- preflight validation for governor, turbo, pinning, and background load
- CPU pinning through `taskset` or `numactl`
- multi-mode kernel comparisons such as `stock`, `recompile-cmov`, `recompile-all`, and `recompile-v5`
- bootstrap confidence intervals, CV/noise flags, 3xIQR outlier flags, Wilcoxon signed-rank tests, and BH-adjusted p-values
- structured raw JSON plus machine-readable and Markdown summaries under `micro/results/rigorous/`

## Recommended Usage

Activate the project venv first:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
```

Dry-run the default quick kernel comparison:

```bash
python3 micro/run_rigorous.py --bench simple --runtime kernel --quick --dry-run
```

Run the actual quick smoke:

```bash
python3 micro/run_rigorous.py --bench simple --runtime kernel --quick
```

Run a broader mode matrix:

```bash
python3 micro/run_rigorous.py \
  --bench cmov_select \
  --bench rotate64_hash \
  --runtime kernel \
  --modes stock,recompile-cmov,recompile-all,recompile-v5 \
  --quick
```

## Preflight Expectations

The script requires:

- CPU governor = `performance`
- turbo boost disabled
- CPU pinning tool available
- no heavy competing processes above the configured threshold

If passwordless `sudo` is available, non-dry runs will try to set governor/turbo automatically unless `--no-system-fixes` is passed.

If the host has no isolated CPUs, the script falls back to the highest online CPU and records:

- `selected_cpu_source = highest-online-fallback`
- `selected_cpu_isolated = false`
- `publication_ready = false`

That is acceptable for smoke tests, but not for paper-quality numbers.

## Outputs

Each run writes:

- raw JSON: `micro/results/rigorous/<timestamp>_<benchmark-or-suite>.json`
- machine summary JSON: `micro/results/rigorous/<timestamp>_summary.json`
- Markdown summary: `micro/results/rigorous/<timestamp>_summary.md`

The optional `--kernel <bzImage>` argument is recorded in the output metadata for VM-oriented workflows. The current standalone script does not boot a VM by itself.

## Verified Commands

These commands were run on 2026-03-10:

```bash
python3 micro/run_rigorous.py --bench simple --runtime kernel --quick --dry-run
python3 micro/run_rigorous.py --bench simple --runtime kernel --quick
python3 micro/run_rigorous.py \
  --bench cmov_select \
  --bench rotate64_hash \
  --runtime kernel \
  --modes stock,recompile-cmov,recompile-all,recompile-v5 \
  --quick \
  --skip-build \
  --heavy-process-threshold 50
```

Generated examples:

- `micro/results/rigorous/20260310T203030Z_simple.json`
- `micro/results/rigorous/20260310T203030Z_summary.md`
- `micro/results/rigorous/20260310T203039Z_cmov_select-rotate64_hash.json`
- `micro/results/rigorous/20260310T203039Z_summary.json`
