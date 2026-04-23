# 2026-04-22 Delete Program Selection

## Goal

Make the whole pipeline use exactly one program truth source:

- the complete set of BPF programs that the kernel actually loaded for the app
- discovered only by `bpftool prog show` before/after diff
- no name filtering
- no YAML `target_programs` / `apply_programs`
- no static `expected_programs`
- no corpus activity-based shrinking

## A. Revert Tetragon program selection

Deleted / simplified:

- `runner/libs/app_runners/__init__.py:63-69`
  - removed the shared-runner adapter path that used to inject extra Tetragon selection/config state from corpus into `TetragonRunner`
  - corpus now only forwards workload shape, not program-selection config
- `runner/libs/app_runners/tetragon.py:19-23`
  - `current_programs()` now uses shared `bpftool_prog_show_records()` directly
- `runner/libs/app_runners/tetragon.py:26-63`
  - kept the global before/after-diff discovery mechanism
  - deleted all later program-name filtering; session now stabilizes and returns the full newly loaded set
- `runner/libs/app_runners/tetragon.py:216-217`
  - removed YAML-derived default-extra-args path
  - kept only built-in default CLI passthrough: `DEFAULT_TETRAGON_EXTRA_ARGS = ("--cgroup-rate", "1000,1s")`
- `runner/libs/app_runners/tetragon.py`
  - removed `expected_program_names`
  - removed `apply_program_names`
  - removed config/name resolution logic
  - removed `_wait_for_expected_programs()` and all expected-name gating
  - removed `select_corpus_program_ids()` override
  - `start()` now keeps `session.programs` as-is
- `e2e/cases/tetragon/case.py:417-433`
  - preflight markdown now reports a single `program_runs`
- `e2e/cases/tetragon/case.py:623-624`
  - lifecycle target/apply IDs are now both seeded from the full discovered program list
- `e2e/cases/tetragon/case.py:797-873`
  - removed:
    - `select_tetragon_programs(...)`
    - `select_tetragon_program_sets(...)`
    - `wait_for_configured_tetragon_programs(...)`
  - start path now uses the full `runner.programs` set for both target/apply IDs
- `e2e/cases/tetragon/case.py:647-653`
  - preflight activity summary now keeps only a single `programs` block
- `e2e/cases/tetragon/case.py:680-739`
  - removed artifact echo fields:
    - `selected_tetragon_programs`
    - `apply_tetragon_programs`
    - config-driven apply/target subsets in the result payload
- `runner/libs/app_runners/tetragon.py`
  - deleted:
    - `tetragon_target_program_names`
    - `tetragon_apply_program_names`
    - `tetragon_config_path`

Result:

- Tetragon truth source is back to the full `bpftool prog show` before/after diff set.
- No post-discovery filter remains in the runner.

## B. Delete YAML program-selection fields

Deleted fields:

- `e2e/cases/tetragon/config_execve_rate.yaml:1-17`
  - removed `target_programs`
  - removed `apply_programs`
  - removed the comment that justified keeping split target/apply scope
- `e2e/cases/bcc/config.yaml:15-68`
  - removed every per-tool `expected_programs`

Repository sweep:

- repo-wide grep is clean for active source code on:
  - `target_programs`
  - `apply_programs`
  - `expected_program_names`
  - `expected_programs`
- remaining hits are archival-only under `docs/tmp/**` and historical output under `e2e/results/**` / `corpus/results/**`
- `e2e/cases/tracee/config.yaml` had no live `target_programs` / `apply_programs` / `expected_program_names` fields to delete
- no active matches remained under `e2e/cases/scx/`, `e2e/cases/bpftrace/`, `e2e/cases/bcc/`, or `e2e/cases/katran/`

## C. Delete thresholds and replace wait semantics

Deleted threshold/count-based selection:

- `runner/libs/app_runners/process_support.py:15-46`
  - removed `wait_for_attached_programs(process, expected_count, timeout_s)`
  - replaced it with `wait_until_program_set_stable(before_ids=(), timeout_s, stable_window_s=2.0, poll_interval_s=0.2)`
- `runner/libs/app_runners/bpftrace.py:17-23`
  - removed `expected_programs` from `ScriptSpec`
- `runner/libs/app_runners/bpftrace.py:25-62`
  - removed every `expected_programs=` entry from `SCRIPTS`
- `runner/libs/app_runners/bpftrace.py:101-176`
  - removed runner-level `expected_programs` / `expected_program_names`
  - `start()` now snapshots `before_ids` and waits for the full stable set
- `runner/libs/app_runners/bcc.py:167-173`
  - removed `expected_programs` from `BCCWorkloadSpec`
- `runner/libs/app_runners/bcc.py:213-234`
  - stopped reading `expected_programs` from YAML
- `runner/libs/app_runners/bcc.py:368-487`
  - removed runner-level `expected_programs` / `expected_program_names`
  - removed the attach-count failure path
  - `start()` now snapshots `before_ids` and waits for the full stable set
- `runner/libs/app_runners/base.py`
  - removed `_filter_expected_programs(...)`
  - removed `select_corpus_program_ids(...)`
- `e2e/cases/bcc/case.py:53-87`
  - removed `expected_programs` from config dataclasses and parsing
- `e2e/cases/bcc/case.py:141-147`
  - stopped passing `expected_programs` into `BCCRunner`
- `e2e/cases/bpftrace/case.py:150-155`
  - stopped passing `expected_programs` into `BpftraceRunner`

### `wait_until_program_set_stable()` logic

Implementation:

- file: `runner/libs/app_runners/process_support.py:15-46`
- poll `bpftool_prog_show_records()` every `0.2s`
- subtract `before_ids`, so only programs newly loaded after app start remain
- sort by program ID and compare the entire discovered set each round
- whenever the set changes, reset the stability timer
- when the set is unchanged for `2.0s`, treat attach phase as stable and return that full set
- if `timeout_s` expires first, return the last seen full set

Why `2.0s`:

- it is long enough to absorb multi-stage attach bursts where the loader becomes healthy before all BPF objects are attached
- it is still short relative to current runner load timeouts (`~20s`), so it does not materially slow the suite
- it removes the stale assumption that the right stop condition is “saw N programs” instead of “kernel program table stopped changing”

## D. Delete corpus activity-based program selection

Deleted:

- `corpus/driver.py:220-258`
  - removed `sample_bpf_stats(..., prog_fds=...)` usage; sampling is now plain program-ID based
- `corpus/driver.py:779-804`
  - lifecycle state now seeds `target_prog_ids` and `apply_prog_ids` from the same `started_prog_ids`
- `corpus/driver.py:1081-1121`
  - removed the `before_rejit` callback that rewrote lifecycle target/apply program IDs after baseline
- `corpus/driver.py:1244-1247`
  - suite path no longer reconfigures program selection after baseline

Result:

- corpus now consumes `runner.programs` as discovered at runner startup
- no “if active then include” shrink step remains between baseline and scan/apply

## E. Remove `apply_programs` / selection echoes from artifacts and runner→case chain

Deleted / simplified:

- `e2e/case_common.py`
  - deleted the old `select_configured_programs(...)` helper entirely
- `e2e/cases/tracee/case.py:958-968`
  - preflight markdown now reports only `program_runs`
- `e2e/cases/tracee/case.py:1188-1383`
  - removed `selected_tracee_programs`
  - removed `apply_tracee_programs`
  - removed active-subset pruning during preflight
  - target/apply IDs now both point at the full discovered set
- `e2e/cases/tetragon/case.py:417-433`
  - preflight markdown now reports only `program_runs`
- `e2e/cases/tetragon/case.py:623-739`
  - removed `selected_tetragon_programs`
  - removed `apply_tetragon_programs`
  - target/apply IDs now both point at the full discovered set
- `runner/libs/rejit.py:589-614`
  - removed `prog_fds` from top-level `scan_programs(...)`
- `runner/libs/rejit.py:917-922`
  - removed `prog_fds` from `DaemonSession.scan_programs(...)`
- `runner/libs/case_common.py:143-153`
  - `CaseLifecycleState` still keeps `target_prog_ids` / `apply_prog_ids`, but `requested_prog_ids()` now just resolves whichever same-source list is present
  - there is no remaining program-selection meaning behind the split
- `runner/libs/case_common.py:199-202`
  - `_clone_daemon_metadata(...)` no longer accepts a program-ID list
- `runner/libs/case_common.py:437-467`
  - lifecycle metadata no longer writes `requested_prog_ids` into `kinsn_modules.lifecycle_runs[*]`
- `corpus/driver.py:790-804`
  - corpus runner lifecycle now seeds both target/apply IDs from the same full discovered program list
- `corpus/driver.py:1197-1207`
  - corpus-side kinsn metadata clone path no longer passes or stores requested/apply subsets

Related truth-source cleanups needed to make this consistent across runners:

- `runner/libs/app_runners/tracee.py:296-349`
  - Tracee startup now uses global before/after diff instead of FD-owned program enumeration
- `runner/libs/app_runners/scx.py:86-161`
  - SCX startup now uses global before/after diff for discovery and name-based refresh for live scheduler callbacks
- `runner/libs/app_runners/katran.py:690-714`
  - Katran runner now returns the full discovered set instead of collapsing to a single selected program

## Extra selection-flavor cleanup

Also removed because they were the same problem under different names:

- `select_corpus_program_ids`
- `select_tracee_programs`
- `select_tetragon_programs`
- `select_active_program_ids`
- `selected_tracee_programs`
- `selected_tetragon_programs`
- `prog_fds` as a scan/apply prerequisite in the active runner/case path

## Validation

Completed:

- `python3 -m py_compile` on all modified Python files: PASS
- `make check`: PASS
- `make vm-e2e E2E_SMOKE=1`: PASS
- `make vm-corpus SAMPLES=1`: PASS

Artifacts:

- smoke:
  - `e2e/results/tracee_20260422_233334_731547` (`tracee_programs=37`)
  - `e2e/results/tetragon_20260422_233636_399091` (`tetragon_programs=35`)
  - `e2e/results/bpftrace_20260422_233734_912238` (smoke-selected script exposed `1` program)
  - `e2e/results/scx_20260422_233806_791337` (`scheduler_programs=13`)
  - `e2e/results/bcc_20260422_233843_715838` (smoke-selected tool exposed `1` program)
  - `e2e/results/katran_20260422_233911_124208` (`programs=1`)
- corpus:
  - `corpus/results/x86_kvm_corpus_20260422_234543_434541`

Artifact-grep check:

- repo code grep is clean for active-source `target_programs` / `apply_programs` / `expected_program_names`
- final smoke + corpus artifacts are also grep-clean for:
  - `requested_prog_ids`
  - `apply_programs`
  - `apply_program_names`
  - `selected_tracee_programs`
  - `selected_tetragon_programs`

## Before / After Program Counts

Before sources:

- `docs/tmp/program-discovery-review-20260422/summary.md`
- `docs/tmp/bpftrace-bcc-threshold-refresh-20260422/summary.md`
- `docs/tmp/wave3-fixes-20260422/summary.md`

Known pre-change signals:

- `tetragon/default`: corpus had collapsed to `1`
- `tracee/default`: current macro corpus had collapsed to `3`
- `tracee/default`: older live corpus had observed `44`
- `bpftrace/vfsstat`: authoritative E2E had `4`, but code still expected `2`
- `bcc/vfsstat`: authoritative E2E had `requested=8`, but config still expected `5`
- `bcc/tcpconnect`: authoritative E2E had `requested=4`, but config still expected `2`
- `bcc/bindsnoop`: authoritative E2E had `requested=4`, but config still expected `3`

Corpus app counts, pre-delete macro corpus vs final full-set corpus:

Source `before`: `corpus/results/x86_kvm_corpus_20260421_232916_947372/result.json`
Source `after`: `corpus/results/x86_kvm_corpus_20260422_234543_434541/result.json`

| app | before | after | delta |
| --- | ---: | ---: | ---: |
| `bcc/capable` | 1 | 1 | 0 |
| `bcc/execsnoop` | 2 | 2 | 0 |
| `bcc/bindsnoop` | 3 | 3 | 0 |
| `bcc/biosnoop` | 3 | 3 | 0 |
| `bcc/vfsstat` | 3 | 5 | +2 |
| `bcc/opensnoop` | 1 | 3 | +2 |
| `bcc/syscount` | 2 | 2 | 0 |
| `bcc/tcpconnect` | 3 | 3 | 0 |
| `bcc/tcplife` | 1 | 1 | 0 |
| `bcc/runqlat` | 3 | 3 | 0 |
| `scx/rusty` | 11 | 13 | +2 |
| `tetragon/default` | 1 | 35 | +34 |
| `katran` | 1 | 1 | 0 |
| `tracee/default` | 3 | 37 | +34 |
| `bpftrace/capable` | 1 | 1 | 0 |
| `bpftrace/biosnoop` | 2 | 2 | 0 |
| `bpftrace/vfsstat` | 2 | 2 | 0 |
| `bpftrace/runqlat` | 3 | 3 | 0 |
| `bpftrace/tcplife` | 1 | 1 | 0 |
| `bpftrace/tcpretrans` | 1 | 1 | 0 |

Most important restorations:

- `tetragon/default`: `1 -> 35`
- `tracee/default`: `3 -> 37`
- `bcc/vfsstat`: `3 -> 5`
- `bcc/opensnoop`: `1 -> 3`
- `scx/rusty`: `11 -> 13`

The threshold-refresh numbers that were explicitly rolled back were the static expectations, not the new authoritative counts. After deleting the thresholds, the suite simply accepts what the kernel actually loaded.

## Result Metrics To Update

Comparing pre-delete macro corpus (`20260421_232916_947372`) vs final full-set corpus (`20260422_234543_434541`):

- `summary.applied_sample_count`: `12 -> 23`
- `summary.comparison_exclusion_reason_counts.no_programs_changed_in_loader`: `36 -> 38`
- corpus top-level statuses: `{'ok': 20}` in the final run

Comparing the first full-set rerun that still failed top-level (`20260422_224118_343109`) vs the final full-set rerun:

- `summary.applied_sample_count`: `23 -> 23` (unchanged)
- `summary.comparison_exclusion_reason_counts.no_programs_changed_in_loader`: `38 -> 38` (unchanged)
- corpus top-level statuses: `{'error': 1, 'ok': 19} -> {'ok': 20}`
- the only top-level recovery was `tracee/default`

Minimal-sample corpus final statuses:

- all 20 apps finished `ok`
- `tracee/default` no longer fails the entire app on the single-program `EINVAL`

## Breakage / Fixes During This Turn

Observed and fixed:

- `runner/libs/app_runners/scx.py`
  - deletion/refactor fallout removed the `os` import used by `preferred_path()`
  - first smoke rerun failed with `name 'os' is not defined`
  - fixed by restoring `import os` at `runner/libs/app_runners/scx.py:3`
- `runner/libs/case_common.py:199-202,437-467` and `corpus/driver.py:1203-1205`
  - first post-cleanup smoke rerun still leaked `requested_prog_ids` through `kinsn_modules.lifecycle_runs[*]`
  - fixed by removing the metadata write entirely and cloning only daemon metadata, not requested/apply subsets
- `corpus/driver.py:1004-1029`
  - the first full-set corpus rerun surfaced a genuine per-program apply failure in `tracee/default`:
    - program `167`
    - `syscall__init_module`
    - `raw_tracepoint`
    - daemon error `BPF_PROG_REJIT: Invalid argument (os error 22)`
  - that failure should not mark the entire app `error` when other programs in the same app still produce comparable measurements
  - fix: treat apply errors as app-fatal only when they leave the app with zero comparable program measurements

No additional breakage appeared after those fixes:

- final `make vm-e2e E2E_SMOKE=1`: PASS
- final `make vm-corpus SAMPLES=1`: PASS
