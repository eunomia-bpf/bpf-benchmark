# BLOCKER 2/3 Fix Summary 2026-04-23

## Scope

- Fixed `BLOCKER 3` without touching `corpus/driver.py` or `runner/libs/app_runners/base.py`.
- Fixed `BLOCKER 2` with **Scheme A**: single default authority lives in Python contract code (`runner/libs/suite_args.py`).
- Left `BLOCKER 1` untouched.

## BLOCKER 3: `make check` source inventory

- Replaced the hand-maintained `py_compile` allowlist in `Makefile` with one `find ... -exec $(PYTHON) -m py_compile {} +`.
- Source-discovery scope is now:
  - `corpus/`
  - `runner/`
  - `e2e/`
- Explicit exclusions:
  - `runner/repos/*`
  - `runner/build-*/*`
  - `corpus/results/*`
  - `e2e/results/*`
  - `*/__pycache__/*`
- Result: `make check` now compiles the live Python tree instead of a stale second file list.

## BLOCKER 2: micro default authority

### Chosen scheme

- Picked **Scheme A**.
- Reason:
  - `run_target_suite`, `run_contract`, and `kvm_executor` already converge on `suite_args_from_env(...)` when suite args are omitted.
  - Letting `Makefile` keep its own `3/1/100` defaults would preserve the split semantics the audit called out.
  - Making `Makefile` stop injecting micro defaults is smaller and cleaner than adding any merge or fallback layer.

### What changed

- Removed `SAMPLES ?= 3`, `WARMUPS ?= 1`, and `INNER_REPEAT ?= 100` from `Makefile`.
- Removed Makefile-side `VM_MICRO_*` default assembly for the normal `vm-micro` target.
- `vm-micro` now calls `python -m runner.libs.run_target_suite run x86-kvm micro` with no injected benchmark defaults.
- Kept `vm-micro-smoke` explicit because smoke mode is intentionally a separate preset, not the default benchmark contract.
- Centralized the default values in `runner/libs/suite_args.py` as:
  - `MICRO_BENCHMARK_DEFAULT_SAMPLES = "1"`
  - `MICRO_BENCHMARK_DEFAULT_WARMUPS = "0"`
  - `MICRO_BENCHMARK_DEFAULT_INNER_REPEAT = "10"`
- Left `runner/suites/micro.py` as `required=True` for `--samples/--warmups/--inner-repeat`.
  - This preserves loud failure when someone bypasses the contract and calls the suite entrypoint with incomplete args.

## Validation

- `make check`
  - Passed.
- Live Python count under the new `check` discovery scope:
  - `63`
- `make -n vm-micro`
  - `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm micro`
- `make -n vm-corpus`
  - `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm corpus -- --samples "30"`
- `make -n vm-e2e`
  - `"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite run x86-kvm e2e --`
- Contract default proof:
  - `suite_args_from_env("x86-kvm", "micro", env={})`
  - returns `['--samples', '1', '--warmups', '0', '--inner-repeat', '10']`
- Partial override proof:
  - `suite_args_from_env("x86-kvm", "micro", env={'SAMPLES': '7', 'BENCH': 'foo,bar'})`
  - returns `['--samples', '7', '--warmups', '0', '--inner-repeat', '10', '--bench', 'foo', '--bench', 'bar']`

## Result

- `BLOCKER 3` is fixed by removing the stale Python allowlist.
- `BLOCKER 2` is fixed by removing Makefile-owned micro defaults and keeping a single Python contract authority.
