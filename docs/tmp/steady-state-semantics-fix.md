# 128 Steady-State Default Semantics Fix

Date: 2026-03-12

## Summary

Steady-state default semantics are now aligned with the v2 design:

- no policy -> stock
- explicit policy file -> policy-driven recompile
- explicit `--blind-apply` -> blind all-apply auto-scan

The old implicit fallback from "policy miss" to `--recompile-v5 --recompile-all` was removed from the micro runtime, shared corpus helper, corpus framework/vm drivers, and E2E common recompile path.

## Code Changes

### `micro/orchestrator/commands.py`

- `build_micro_benchmark_command(..., runtime_mode="kernel-recompile")` no longer turns `policy is None and policy_file is None` into implicit `--recompile-v5 --recompile-all`.
- Added `blind_apply` plumbing so blind all-apply only happens when explicitly requested.

### `micro/_driver_impl_run_micro.py`

- Added CLI flag `--blind-apply`.
- `--blind-apply` is only accepted when a `kernel-recompile` runtime is selected.
- Default `kernel-recompile` behavior now uses manifest policy when present, otherwise stays stock.

### `corpus/common.py`

- `build_run_kernel_command()` no longer derives implicit all-apply from `recompile_v5=True` plus `policy_file is None`.
- Miss-policy default is now stock rather than blind recompile.

### `corpus/_driver_impl_run_corpus_v5_framework.py`

- Added CLI flag `--blind-apply`.
- `--use-policy` and `--blind-apply` are mutually exclusive.
- No matching policy now records `policy_mode: stock` and does not request recompile.
- Help text / markdown notes updated to document stock-by-default semantics.

### `corpus/_driver_impl_run_corpus_v5_vm_batch.py`

- Added CLI flag `--blind-apply`.
- `--use-policy` and `--blind-apply` are mutually exclusive.
- `--skip-families` now requires `--blind-apply`.
- No matching policy now records `policy_mode: stock` and does not request recompile.
- Guest invocation plumbing now forwards explicit blind-apply mode.
- Help text / markdown notes updated to document stock-by-default semantics.

### `e2e/common/recompile.py`

- `apply_recompile()` now treats no-policy as stock and returns a stock/no-op result instead of running `scanner apply --all`.
- Added optional `blind_apply=False` parameter for explicit debug/exploration callers.
- Blind apply and policy-file modes are now explicitly separated in result metadata.

## Validation

### 1. Python syntax

Command:

```bash
python3 -m py_compile \
  micro/orchestrator/commands.py \
  micro/_driver_impl_run_micro.py \
  micro/benchmark_catalog.py \
  corpus/common.py \
  corpus/_driver_impl_run_corpus_v5_framework.py \
  corpus/_driver_impl_run_corpus_v5_vm_batch.py \
  e2e/common/recompile.py
```

Result: passed.

### 2. `micro/run_micro.py --list`

Command:

```bash
python3 micro/run_micro.py --list
```

Result: passed.

### 3. `simple` should stay stock

Command:

```bash
python3 micro/run_micro.py \
  --runtime kernel-recompile \
  --bench simple \
  --iterations 1 \
  --warmups 0 \
  --repeat 5
```

Observed result:

```json
{
  "applied": false,
  "mode": "none",
  "policy_file": null,
  "requested": false
}
```

This confirms no-policy -> stock.

### 4. `cmov_dense` should use policy file

Command:

```bash
python3 micro/run_micro.py \
  --runtime kernel-recompile \
  --bench cmov_dense \
  --iterations 1 \
  --warmups 0 \
  --repeat 5
```

Observed result:

```json
{
  "applied": false,
  "error": "BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22)",
  "mode": "policy-file",
  "policy_file": "/home/yunwei37/workspace/bpf-benchmark/micro/policies/cmov_dense.yaml",
  "requested": true,
  "requested_families": [
    "rotate"
  ]
}
```

Semantics are correct: the run goes through `policy-file` rather than blind fallback. On this host/kernel the recompile syscall still returned `EINVAL`; that is separate from the steady-state default semantics fix.

### 5. Corpus driver help

Commands:

```bash
python3 corpus/_driver_impl_run_corpus_v5_framework.py --help
python3 corpus/_driver_impl_run_corpus_v5_vm_batch.py --help
```

Result: both passed; help now shows explicit `--blind-apply`.

### 6. E2E help

Command:

```bash
python3 e2e/run.py --help
```

Result: passed.

## Extra Smoke

Explicit blind apply still works:

```bash
python3 micro/run_micro.py \
  --runtime kernel-recompile \
  --bench simple \
  --iterations 1 \
  --warmups 0 \
  --repeat 5 \
  --blind-apply
```

Observed:

```json
{
  "simple_blind_mode": "auto-scan-v5",
  "simple_blind_requested": true
}
```

So the old blind path still exists, but only behind an explicit flag.
