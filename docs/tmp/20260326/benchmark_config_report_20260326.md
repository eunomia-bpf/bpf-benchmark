# Benchmark Config Report

Date: 2026-03-26

## Summary

Implemented a unified corpus benchmark configuration at `corpus/config/benchmark_config.yaml` and wired `corpus/modes.py` to consume it with profile-aware defaults and per-request pass selection.

The selected daemon pass list now flows through:

1. `corpus/modes.py`
2. runner batch job JSON (`passes`)
3. `micro_exec` keep-alive parsing
4. runner daemon socket `optimize` request
5. daemon per-request pass selection

## Changes

### 1. New benchmark config

Added `corpus/config/benchmark_config.yaml` with:

- shared defaults
- `performance` and `security` pass groups
- active pass group selection
- profiles: `dev`, `strict`, `ablation_map_inline`, `ablation_wide_mem`

### 2. `corpus/modes.py`

Added:

- `load_benchmark_config(profile=None)`
- config/profile merge logic with fallback defaults when the config file is absent
- `--profile`
- `--passes` (comma-separated)

Updated behavior:

- `repeat`, `output_json`, and `output_md` now default from benchmark config
- CLI `--passes` overrides config-selected passes
- selected passes are forwarded into guest runs and batch jobs
- result metadata/markdown now record benchmark profile, config path, and requested pass list

### 3. Runner integration

Updated runner-side pass plumbing:

- `runner/include/micro_exec.hpp`: new `passes` field in `cli_options`
- `runner/src/common.cpp`: parse `--passes` and batch-job JSON `passes`
- `runner/src/kernel_runner.cpp`: include `passes` in daemon socket `optimize` JSON

### 4. Daemon pass compatibility

Updated `daemon/src/passes/mod.rs` so `skb_load_bytes` is accepted as an alias for canonical pass `skb_load_bytes_spec`, matching the benchmark config.

### 5. Makefiles

Updated:

- `runner/Makefile`: `vm-corpus` accepts `PROFILE=...` and only forwards `--repeat` / `--output-*` when explicitly overridden
- root `Makefile`: forwards `PROFILE` to runner `vm-corpus` and stops forcing default `REPEAT` into corpus runs

This lets `make vm-corpus PROFILE=dev` use the config-driven profile instead of the old Makefile defaults.

## Verification

Requested checks:

- `python3 -c 'import yaml; yaml.safe_load(open("corpus/config/benchmark_config.yaml"))'`
  - passed
- `python3 -m py_compile corpus/modes.py`
  - passed

Additional host-side build checks:

- `make daemon`
  - passed
- `make runner`
  - passed

Profile handoff inspection:

- inspected `make -n vm-corpus PROFILE=dev`
  - confirmed the top-level invocation forwards `PROFILE="dev"` to runner `vm-corpus`
  - confirmed no default `REPEAT=...` was injected by the root wrapper in that invocation
  - the recursive dry-run later descended into kernel build graph output and hit an unrelated kernel-link failure, so this was used only to inspect argument forwarding, not as a formal pass/fail build result

## Files Touched

- `corpus/config/benchmark_config.yaml`
- `corpus/modes.py`
- `runner/include/micro_exec.hpp`
- `runner/src/common.cpp`
- `runner/src/kernel_runner.cpp`
- `runner/Makefile`
- `Makefile`
- `daemon/src/passes/mod.rs`
