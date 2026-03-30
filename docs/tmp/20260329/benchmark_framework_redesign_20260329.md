# Benchmark Framework Redesign

Date: 2026-03-29

## Scope

- Refactor corpus and e2e around a shared app-runner lifecycle.
- Remove the `corpus/modes.py` compatibility shim.
- Add missing app-runner classes for current app-native repos.
- Rework `corpus/orchestrator.py` to operate on loader instances instead of repo batches.

## What Changed

### 1. Shared runner direction is now one-way

- `runner/libs/app_runners/` no longer imports `e2e`.
- `grep -R "from e2e" runner/libs/app_runners/` returns empty.
- `tracee`, `tetragon`, `bpftrace`, `scx`, and `katran` now use shared support modules from `runner/libs/app_runners/` instead of reverse-importing case files.

### 2. Added a generic native-process runner base

New shared helper:

- `runner/libs/app_runners/process_support.py`

It provides:

- managed subprocess lifecycle
- BPF program discovery from the loader PID
- common process-output collection
- a small default workload helper

This is the shared base for simple native app loaders.

### 3. Added missing app runners

New runner classes:

- `KubeArmorRunner`
- `CorootNodeAgentRunner`
- `DatadogAgentRunner`
- `LibbpfBootstrapRunner`
- `RealWorldCodeSizeRunner`
- `SystemdRunner`
- `TubularRunner`
- `XdpToolsRunner`
- `XdpTutorialRunner`

Registry wiring was added in `runner/libs/app_runners/__init__.py`.

### 4. Rewrote corpus orchestration around loader instances

`corpus/orchestrator.py` now:

- splits mixed objects by program-level `measurement`
- groups `app_native` work by loader instance instead of repo batch
- starts the daemon once per suite
- runs `start -> workload -> baseline stats -> daemon apply -> workload -> rejit stats -> stop`
- consumes manifest loader metadata when constructing runners
- validates that each expected program produces nonzero `run_cnt` and `exec_ns`
- rejects unsupported non-`app_native` execution units loudly instead of silently falling back to `bpftool prog loadall`

Result payload changes:

- `summary.measurements` is now program-level
- `summary.selected_manifest_objects` and `summary.selected_execution_units` are reported separately
- `app_native_batches` are loader-instance summaries, not repo-batch summaries

### 5. Removed old corpus shim

- Deleted `corpus/modes.py`
- `corpus/driver.py` already forwards directly to `corpus/orchestrator.py`
- Updated `corpus/README.md`

### 6. Updated tests

- `tests/python/test_corpus_orchestrator.py` now checks:
  - program-level measurement splitting
  - loader-instance grouping
  - explicit failure for unsupported `test_run` execution units
- `tests/python/test_run_artifacts.py` now compiles `corpus/orchestrator.py` instead of the deleted shim

## Validation

Passed:

- `python3 -m py_compile corpus/driver.py corpus/orchestrator.py runner/libs/app_runners/__init__.py runner/libs/app_runners/process_support.py runner/libs/app_runners/systemd.py runner/libs/app_runners/libbpf_bootstrap.py runner/libs/app_runners/real_world_code_size.py runner/libs/app_runners/xdp_tutorial.py runner/libs/app_runners/xdp_tools.py runner/libs/app_runners/kubearmor.py runner/libs/app_runners/coroot_node_agent.py runner/libs/app_runners/datadog_agent.py runner/libs/app_runners/tubular.py tests/python/test_corpus_orchestrator.py tests/python/test_run_artifacts.py`
- `pytest tests/python/ -q`
  - result: `73 passed`
- `grep -R "from e2e" runner/libs/app_runners/`
  - result: empty
- `make runner`
- `make daemon`

## Notes

- All newly added runner files are under 200 lines. Pre-existing `runner/libs/app_runners/bcc.py` remains larger than that limit and was not refactored in this change.
- The orchestrator no longer uses `bpftool prog loadall` as a corpus loader path.
- Manifest schema migration is not finished yet: `macro_corpus.yaml` still contains `test_run` and `compile_loader: bpftool_loadall` metadata. The new orchestrator now reports those execution units as explicit errors instead of executing an old fallback path.
- Katran still has legacy direct-load helper code in the e2e-side implementation path; that was not part of the validated corpus path in this change and still needs a follow-up native-loader migration if Katran is to fully satisfy the new loader-only design everywhere.
