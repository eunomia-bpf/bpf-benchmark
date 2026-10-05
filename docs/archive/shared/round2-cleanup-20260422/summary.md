# 2026-04-22 Round 2 Cleanup

Status: completed

## Scope

This round removed the remaining cleanup debt after `delete-program-selection-20260422`, with the requested five source cleanups in order:

1. collapse the `applied/changed` family from 6 fields to 2
2. unify daemon protocol error keys
3. delete `legacy_total_sites_contract`
4. unify on `workload_spec`
5. remove dead YAML/config fields

During verification, Tracee exposed two separate runtime regressions:

- first rerun: event-file rollover/truncation could surface a mid-record JSON fragment
- second rerun: the rollover guard itself was too expensive and caused the collector to fall behind the writer, missing latency probes near the file tail

Both Tracee fixes are documented below because they were required to complete the requested verification loop.

## 1. `applied/changed` family: 6 -> 2

Kept:

- `applied`: apply request path succeeded
- `changed`: the kernel program actually changed

Deleted:

- `applied_any`
- `all_applied`
- `changed_any`
- `all_changed`

Changed files:

- `runner/libs/rejit.py:800-860`
  - `apply_daemon_rejit()` now returns only top-level `applied` and `changed`
  - removed `applied_any`, `all_applied`, `changed_any`, `all_changed`
  - profile-collection failure path now returns only `applied=False`, `changed=False`
- `runner/libs/case_common.py:327-380`
  - `_merge_group_rejit_results()` now aggregates only `applied` and `changed`
- `corpus/driver.py:907-965`
  - `_slice_rejit_result()` now emits only `applied` and `changed`

Caller/artifact cleanup:

- active source callers no longer read or echo the deleted 4 fields
- artifact slices now only carry the canonical pair

Verification:

- `rg -n --glob '!**/results/**' --glob '!runner/build-*/**' 'applied_any|all_applied|changed_any|all_changed' runner e2e corpus daemon`
  - no active source match
  - only unrelated vendored Katran `fetcher.py` still contains `all_changed`

## 2. Daemon error key unification

Canonical daemon protocol key:

- `error_message`

Daemon-side confirmation:

- `daemon/src/commands.rs:21-35`
  - `OptimizeOneResult` serializes optional `error_message`
- `daemon/src/commands.rs:42-56`
  - `ServeOptimizeResponse` serializes optional `error_message`

Changed files:

- `daemon/src/server.rs:296-330`
  - panic response and invalid-JSON response now emit `error_message`
- `daemon/src/server.rs:455-782`
  - all top-level `"status":"error"` socket responses now use `error_message`
- `daemon/src/server.rs:946-1055`
  - tests updated to assert `response["error_message"]`
- `runner/libs/rejit.py:580-605`
  - `scan_programs()` now reads only `error_message`
- `runner/libs/rejit.py:608-669`
  - `_apply_result_from_response()` now reads only `error_message`
- `runner/libs/rejit.py:773-797`
  - branch-flip profile helpers now read only `error_message`

Deleted fallback patterns:

- daemon-protocol fallback from `error_message -> message`
- daemon-protocol fallback from `error_message -> error`

Verification:

- `cargo test --manifest-path daemon/Cargo.toml server:: --quiet`
  - PASS
- `rg -n --glob '!**/results/**' --glob '!runner/build-*/**' 'get\\(\"error_message\"\\)|get\\(\"message\"\\)|get\\(\"error\"\\)|\\[\"message\"\\]|error_message' runner daemon e2e corpus`
  - daemon socket protocol paths now consistently use `error_message`
  - remaining `error` lookups are local runner/app result fields, not daemon fallback chains

## 3. Delete `legacy_total_sites_contract`

Daemon-side confirmation:

- `daemon/src/commands.rs:42-56`
  - `ServeOptimizeResponse` always includes non-optional `passes: Vec<PassDetail>`

Changed files:

- `runner/libs/rejit.py:536-577`
  - `_adjust_counts_from_raw()` signature simplified; removed `legacy_total_sites_contract`
  - deleted the legacy `counts.total_sites -> applied_sites` synthesis path
  - now raises if `counts.total_sites` is present without `counts.applied_sites`
  - `applied_site_totals_from_rejit_result()` now relies only on `debug_result.passes` or `result.passes`

Deleted:

- `legacy_total_sites_contract` parameter
- all legacy caller plumbing
- the branch that silently synthesized `applied_sites` from `total_sites`

Verification:

- `rg -n --glob '!**/results/**' --glob '!runner/build-*/**' 'legacy_total_sites_contract' runner e2e corpus daemon`
  - no active source match
- `rg -n --glob '!**/results/**' --glob '!runner/build-*/**' '\\bpasses\\b' daemon/src runner/libs/rejit.py`
  - daemon response contract and runner parser both use `passes`

## 4. `workload_spec` vs `workload_kind`

Canonical form:

- `workload_spec`

Reason:

- `workload_spec` can carry both `kind` and workload-specific parameters
- all live `workload_kind` callers only needed the `kind` string and fit cleanly into `workload_spec.kind`

Changed files:

- `runner/libs/workload.py`
  - `run_named_workload()` parameter renamed from `workload_kind` to `kind`
- `runner/libs/app_runners/__init__.py:21-40,63-77`
  - shared runner adapters now materialize `workload_spec={"kind": ...}` for BCC/BPFTrace/Katran
- `runner/libs/app_runners/bcc.py:167-234,370-509`
  - BCC spec/config/runner now use `workload_spec`
- `runner/libs/app_runners/bpftrace.py:17-55,94-198`
  - BPFTrace specs and runner now use `workload_spec`
- `runner/libs/app_runners/katran.py:666-753`
  - Katran runner now uses and validates `workload_spec`
- `e2e/driver.py:344-376`
  - suite-selected BCC workload overrides are rewritten into `workload_spec`
- `e2e/cases/bcc/case.py:53-83,137-143,230-248,496-499`
  - BCC case config and artifact echo now use `workload_spec`
- `e2e/cases/bpftrace/case.py:90-103,150-155`
  - BPFTrace selected scripts and runner payload now use `workload_spec`
- `e2e/cases/katran/case.py:83-99,107-116,165-170`
  - Katran markdown and artifact echo now use `workload_spec`
- `e2e/cases/bcc/config.yaml:15-60`
  - BCC YAML uses only `workload_spec`

Verification:

- `rg -n --glob '!**/results/**' --glob '!runner/build-*/**' '\\bworkload_kind\\b' runner e2e corpus`
  - no active source match

## 5. Dead YAML/config cleanup

Removed because code did not need them as config inputs:

- per-tool `description`
- per-tool `spawn_timeout_s: 15` when the value was uniform

Changed files:

- `runner/libs/app_runners/bcc.py:24-29,167-173,213-235,370-393`
  - built-in `DEFAULT_ATTACH_TIMEOUT_SECONDS = 15`
  - removed `spawn_timeout_s` from `BCCWorkloadSpec`
  - removed config parsing for per-tool `spawn_timeout_s`
- `e2e/cases/bcc/case.py:53-83,230-248`
  - removed `description` from BCC case config dataclasses and artifact echo
- `runner/libs/app_runners/bpftrace.py:17-22,24-55`
  - removed `description` from `ScriptSpec`
- `e2e/cases/bpftrace/case.py:90-103`
  - removed description echo from BPFTrace-selected script payload
- `e2e/cases/tetragon/case.py:57-63,102-123,205-224`
  - removed unused Tetragon workload `description`
- `e2e/cases/bcc/config.yaml:15-60`
  - removed all per-tool `description`
  - removed all per-tool `spawn_timeout_s`
- `e2e/cases/tetragon/config_execve_rate.yaml:7-11`
  - removed Tetragon workload `description`

Notes:

- there is no `e2e/cases/bpftrace/config.yaml`; BPFTrace uses in-code `SCRIPTS`
- Tetragon `description` removal was an extra dead-field cleanup beyond the prompt, because it had no live readers

Verification:

- `find e2e/cases/bpftrace -maxdepth 1 -type f | sort`
  - confirms there is no `config.yaml`
- `rg -n --glob '!**/results/**' --glob '!runner/build-*/**' 'spawn_timeout_s' runner e2e corpus daemon`
  - no active source match
- `rg -n --glob '!**/results/**' --glob '!runner/build-*/**' 'description:' e2e/cases runner/libs corpus/config`
  - no active source match in the cleaned paths

## Runtime regressions found during verification

### A. Tracee event-file rollover parse failure

Observed on the first smoke rerun:

- run token: `run.x86-kvm.e2e.524c0350`
- failing artifact: `e2e/results/tracee_20260423_002848_479754`
- failure:
  - `Tracee event file parse failed ... invalid JSON ... '_ctime"...'`

Fix:

- `runner/libs/app_runners/tracee.py:107-205`
  - collector now reopens the event-file handle when the file identity changes or the live size shrinks below the current offset
  - this avoids reading from a stale offset after truncate/recreate

### B. Tracee collector fell behind the writer

Observed on the next smoke rerun:

- run token: `run.x86-kvm.e2e.a130fac4`
- failing artifact: `e2e/results/tracee_20260423_005501_142008`
- failure:
  - latency probe markers existed in `docs/tmp/runtime-container-tmp/run.x86-kvm.e2e.a130fac4/tracee/events.json`
  - collector missed them before timeout because the rollover check was too expensive per line

Fix:

- `runner/libs/app_runners/tracee.py:107-205`
  - rollover detection is now low-frequency
  - forced checks still happen on EOF or parse error
  - normal line reads no longer pay a `stat/fstat/tell` cost on every event

Local confirmation:

- replaying `docs/tmp/runtime-container-tmp/run.x86-kvm.e2e.a130fac4/tracee/events.json`
  through the updated collector reached all three probe markers in about `5s`
  with no parse errors
- tracee-only rerun after the final fix:
  - run token: `run.x86-kvm.e2e.310a0417`
  - passing artifact: `e2e/results/tracee_20260423_012144_538746`
  - `result.json.status`: `ok`

## Verification

Completed:

- per-step `python3 -m py_compile`: PASS
- `cargo test --manifest-path daemon/Cargo.toml server:: --quiet`: PASS
- `make check`: PASS
- `make -C daemon release`: PASS
- `make vm-e2e E2E_SMOKE=1 E2E_CASE=tracee`: PASS
  - run token: `run.x86-kvm.e2e.310a0417`
  - artifact: `e2e/results/tracee_20260423_012144_538746`
- `make vm-e2e E2E_SMOKE=1`: PASS
  - run token: `run.x86-kvm.e2e.1119eb85`
  - artifacts:
    - `e2e/results/tracee_20260423_013140_279555`
    - `e2e/results/tetragon_20260423_013440_083708`
    - `e2e/results/bpftrace_20260423_013538_707621`
    - `e2e/results/scx_20260423_013609_172337`
    - `e2e/results/bcc_20260423_013645_893310`
    - `e2e/results/katran_20260423_013713_355326`
  - suite stdout: `tracee OK`, `tetragon OK`, `bpftrace OK`, `scx OK`, `bcc OK`, `katran OK`, `e2e: ALL PASSED`
- `make vm-corpus SAMPLES=1`: PASS
  - run token: `run.x86-kvm.corpus.de8f3027`
  - artifact: `corpus/results/x86_kvm_corpus_20260423_014406_869337`
  - top-level status: `ok`
  - top-level statuses: `{'ok': 20}`

## Before / After Numbers

Baseline reference:

- `docs/tmp/delete-program-selection-20260422/summary.md`
- smoke artifacts from that run:
  - `e2e/results/tracee_20260422_233334_731547`
  - `e2e/results/tetragon_20260422_233636_399091`
  - `e2e/results/bpftrace_20260422_233734_912238`
  - `e2e/results/scx_20260422_233806_791337`
  - `e2e/results/bcc_20260422_233843_715838`
  - `e2e/results/katran_20260422_233911_124208`
  - `corpus/results/x86_kvm_corpus_20260422_234543_434541`

Smoke counts, `delete-program-selection` vs round2:

| suite | delete-program-selection | round2 | delta |
| --- | ---: | ---: | ---: |
| `tracee` | 37 | 37 | 0 |
| `tetragon` | 35 | 35 | 0 |
| `bpftrace` | 1 | 1 | 0 |
| `scx` | 13 | 13 | 0 |
| `bcc` | 1 | 1 | 0 |
| `katran` | 1 | 1 | 0 |

Notes:

- `tracee` count source: `len(tracee_programs)` from `e2e/results/tracee_20260423_013140_279555/result.json`
- `tetragon` count source: `len(programs)` from `e2e/results/tetragon_20260423_013440_083708/result.json`
- `scx` count source: `len(scheduler_programs)` from `e2e/results/scx_20260423_013609_172337/result.json`
- `bcc` and `bpftrace` count source: `len(records[0].baseline.programs)` in their smoke artifacts
- round2 cleanup did not change any smoke discovered-program counts versus `delete-program-selection-20260422`

Corpus key metrics, `delete-program-selection` vs round2:

| metric | delete-program-selection | round2 | delta |
| --- | ---: | ---: | ---: |
| `summary.selected_apps` | 20 | 20 | 0 |
| `summary.applied_sample_count` | 23 | 23 | 0 |
| `summary.comparison_exclusion_reason_counts.no_programs_changed_in_loader` | 38 | 38 | 0 |
| `summary.comparison_exclusion_reason_counts.missing_baseline_exec_ns` | 61 | 61 | 0 |

Top-level corpus status stayed unchanged:

- `delete-program-selection`: `status=ok`, `summary.statuses={'ok': 20}`
- `round2`: `status=ok`, `summary.statuses={'ok': 20}`

## Not Removed

Fields intentionally left in place because they still have live readers:

- runner/app result `error`
  - this is the runner-local aggregate/apply error field consumed by corpus/E2E summaries
  - it is distinct from the daemon socket protocol key, which is now standardized to `error_message`
- lifecycle `target_prog_ids` / `apply_prog_ids`
  - they still exist as case-lifecycle containers even though program-selection meaning was removed in the prior round
  - callers still read `requested_prog_ids()` from them
