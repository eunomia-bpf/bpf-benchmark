# New Orchestrator Implementation Report

Date: 2026-03-29

## Scope

Implemented the new corpus benchmark architecture described in `docs/kernel-jit-optimization-plan.md` section 5.6:

- Python orchestrator is the only benchmark coordinator.
- App lifecycle moved into reusable Python app runners.
- `bpftool` handles load/pin/show/run paths.
- `micro_exec` remains a one-shot helper for the paths `bpftool` cannot cover.
- The daemon is used only for REJIT optimization.

No additional C++ `micro_exec` changes were required in this turn; the current minimal tool shape was already sufficient for the new Python-side orchestration.

No changes were made under `vendor/linux-framework`, and no docs/paper content was modified.

## Implemented Components

### 1. Python corpus orchestrator

File: `corpus/orchestrator.py`

Implemented a VM-oriented orchestrator that:

- loads `corpus/config/macro_corpus.yaml`
- dispatches `app_native` objects through per-repo app runners
- enables BPF stats through Python/libbpf
- reads runtime stats through `bpftool prog show -j -p`
- dispatches `test_run` objects through:
  - `bpftool prog loadall`
  - bpffs pinning
  - `bpftool prog run pinned ... repeat N`
  - daemon REJIT
  - second `bpftool prog run`
- falls back to `micro_exec test-run` only when `bpftool prog run` fails, and records the reason explicitly
- writes aggregated JSON output

Notable implementation details:

- added repo-root `sys.path` bootstrapping so direct execution as `python3 corpus/orchestrator.py` works inside the VM
- sanitized bpffs pin directory components because bpffs rejects `.` in directory names with `EPERM`

### 2. Shared app runner layer

Files:

- `runner/libs/app_runners/__init__.py`
- `runner/libs/app_runners/bcc.py`

Implemented `BCCRunner` with the requested interface:

- `start() -> list[int]`
- `run_workload(seconds: float)`
- `stop()`

The runner encapsulates:

- locating the staged BCC tool binary
- starting/stopping the userspace tool
- waiting for attached BPF programs
- collecting discovered program metadata
- generating workload through the existing workload helpers

`get_app_runner(repo)` currently supports `repo == "bcc"` and fails loudly for unsupported repos.

### 3. BPF stats helper

File: `runner/libs/bpf_stats.py`

Implemented:

- `enable_bpf_stats()`
- `read_program_stats(prog_ids)`

The helper:

- enables kernel BPF stats via libbpf `bpf_enable_stats`
- reads `run_cnt` and `run_time_ns` via `bpftool prog show -j -p`
- supplements per-program info via `bpf_prog_get_fd_by_id` and `bpf_prog_get_info_by_fd`
- returns `exec_ns` as `run_time_ns / run_cnt`

### 4. Daemon integration

Used existing `runner/libs/rejit.py` socket-based helpers. No protocol rewrite was required.

### 5. Makefile target

Files:

- `runner/Makefile`
- `Makefile`

Added `vm-corpus-new` while keeping the old `vm-corpus` target.

Important Makefile fixes made along the way:

- `vendor_bpftool` now builds the upstream `bootstrap` target explicitly
- `OUTPUT` now ends with `/`, so upstream bpftool writes to `.../vendor/bpftool/bootstrap/...` instead of the broken concatenated path `bpftoolbootstrap/...`
- runtime orchestrator no longer uses bootstrap bpftool
- `vm-corpus-new` now passes full runtime bpftool: `/usr/local/sbin/bpftool`

Reason: bootstrap bpftool does not support `prog` commands, so it is suitable for build-time corpus tooling but not for runtime orchestration.

### 6. E2E BCC integration

File: `e2e/cases/bcc/case.py`

Refactored the BCC E2E case to use the shared `BCCRunner` instead of duplicating lifecycle logic inside the case file.

### 7. Python tests

Files:

- `tests/python/test_bcc_case.py`
- `tests/python/test_corpus_orchestrator.py`

Added/updated tests covering:

- shared BCC runner usage from the E2E case
- orchestrator routing
- program phase delta calculations
- program type inference for `test_run`

## Validation

### Python validation

Command:

```bash
python3 -m py_compile $(rg --files -g '*.py' corpus runner/libs e2e tests/python)
```

Result: passed

Command:

```bash
python3 -m pytest tests/python -q
```

Result:

```text
65 passed in 0.29s
```

### VM validation

Command:

```bash
make vm-corpus-new REPEAT=10
```

Result: passed

Top-level output JSON:

- `corpus/results/vm_corpus_new.json`
- `status = ok`

Summary:

- measurements: `app_native=1`, `test_run=1`
- selected objects: `2`
- selected programs: `3`
- statuses: `ok=2`

Observed benchmark outputs from the successful VM run:

- app-native object: `execsnoop.bpf.o`
- baseline `exec_ns_mean`: `3347.024864864865`
- post-REJIT `exec_ns_mean`: `3564.8635359116024`

- test-run program: `xdp_prog_simple`
- baseline `exec_ns`: `81`
- post-REJIT `exec_ns`: `57`
- fallback used: `no`

This satisfies the required validation points:

- BCC `app_native` path produced `exec_ns`
- at least one `test_run` program produced `exec_ns` through the bpftool path

## Issues Found And Fixed

1. Direct orchestrator execution inside the VM failed with `ModuleNotFoundError: runner`.
   Fix: add repo-root `sys.path` bootstrap in `corpus/orchestrator.py`.

2. bpffs rejected pin root directory names containing `.` with `Operation not permitted`.
   Fix: sanitize bpffs path components before creating pin directories.

3. Upstream bpftool `OUTPUT` handling concatenated `bpftool` and `bootstrap` when `OUTPUT` had no trailing slash.
   Fix: set `BPFTOOL_BUILD_DIR := .../bpftool/`.

4. Bootstrap bpftool does not support `prog` subcommands.
   Fix: keep bootstrap bpftool only for build-time dependencies; use full runtime bpftool for orchestrator execution.

## Current Limits

- Only `BCCRunner` is implemented so far. Other app-native repos will currently fail loudly instead of silently degrading.
- `micro_exec` fallback remains available for `test_run` if `bpftool prog run` fails, but the successful VM validation path used native `bpftool` and did not need fallback.
- The existing `xdp-tutorial/experiment01-tailgrow` extra lesson still fails during corpus native build because of upstream `barrier_var` redefinition; the build script already skips that extra lesson and the staged xdp corpus used here remained valid.
