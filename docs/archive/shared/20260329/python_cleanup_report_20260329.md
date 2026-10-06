# Python Cleanup Report 2026-03-29

## Summary

This cleanup removed the legacy Python corpus batch planner and attach-trigger execution logic from the requested files, and reduced the Python-side corpus shape to:

- `corpus/orchestrator.py` as the intended corpus entrypoint
- `runner/libs/app_runners/` as the intended shared lifecycle home
- `runner/libs/corpus.py` as manifest parsing + result helpers only
- `runner/libs/rejit.py` with socket-only `apply_daemon_rejit()`

Validation after the cleanup:

- Result: `61 passed`

## Removed

### `runner/libs/corpus.py`

Deleted the legacy execution/orchestration surface:

- `build_object_batch_plan_v2`
- `build_test_run_batch_job`
- `run_objects_locally_batch`
- `scan_program_site_counts`
- all `prepared_key` / `prepared_ref` / `prepared_group` logic
- all attach-trigger validation / trigger execution logic
- all host/guest batch execution code
- all app-native batch execution code

### `corpus/modes.py`

Deleted:

- `guest_batch_main`
- `run_guest_batch_mode`
- VM launch / guest script construction
- all batch-result aggregation logic

Replaced with a 20-line shim that only points callers at `corpus/orchestrator.py`.

### `corpus/config/macro_corpus.yaml`

Deleted:

- all `test_method` fields
- all `trigger` fields
- all `compile_only` fields
- all `io_mode` / `raw_packet` / `input_size` / `trigger_timeout_seconds` fields
- 7 object-only entries that no longer fit the measurement-only corpus model

Converted:

- `attach_trigger` -> `measurement: app_native`
- `bpf_prog_test_run` -> `measurement: test_run`

Final manifest counts:

- objects: `179` (from `186`)
- programs: `1112`
- `app_native`: `939` programs
- `test_run`: `173` programs

### `runner/libs/rejit.py`

Deleted:

- `apply_daemon_rejit()` auto-start / auto-stop daemon branch

Kept:

- socket communication
- branch-flip profiling path
- daemon request helpers


Deleted:

- all tests tied to batch plans, prepared state, guest batch mode, and attach-trigger behavior

Replaced with:


## Kept

### `runner/libs/corpus.py`

Retained only the pieces that still make sense before orchestrator lands:

- `ResolvedObject` / `ResolvedProgram`
- YAML parsing and filtering
- corpus build report loading
- resolved object serialization helpers
- packet/context materialization helpers shared with existing code
- lightweight result helpers such as size/speedup/exclusion summaries

TODO markers were added to make it explicit that orchestration moved out of this module.

### `e2e/case_common.py`

Kept the shared lifecycle helper, but added a TODO marking:

- `start`
- `workload`
- `stop`

as the future `runner/libs/app_runners/` extraction boundary.

## Line Counts

| Path | Old | New | Delta |
| --- | ---: | ---: | ---: |
| `corpus/config/macro_corpus.yaml` | 10990 | 9801 | -1189 |
| `corpus/driver.py` | 19 | 19 | 0 |
| `corpus/modes.py` | 863 | 20 | -843 |
| `corpus/orchestrator.py` | 0 | 26 | +26 |
| `e2e/case_common.py` | 762 | 763 | +1 |
| `runner/libs/corpus.py` | 3310 | 1029 | -2281 |
| `runner/libs/rejit.py` | 1129 | 1099 | -30 |
| `runner/libs/app_runners/__init__.py` | 0 | 6 | +6 |
| **Total** | **19158** | **13737** | **-5421** |

Diff-stat view for the tracked edits in this cleanup:

- insertions: `573`
- deletions: `5994`

## Follow-Up

These Python scripts still reference removed corpus batch APIs and were not part of the requested edit set:

- `runner/scripts/arm64_t4g_remote_benchmark.py`
- `runner/scripts/k2_comparison.py`
- `runner/scripts/x86_remote_benchmark.py`

They should be either retired or ported to the orchestrator + app-runner structure in a follow-up cleanup.
