# E2E / Corpus Simplify Review

Date: `2026-04-24`

## Scope Read

I read the current contents of:

- `e2e/cases/tracee/case.py`
- `e2e/cases/bcc/case.py`
- `e2e/cases/bpftrace/case.py`
- `e2e/cases/scx/case.py`
- `e2e/cases/tetragon/case.py`
- `runner/libs/case_common.py`
- `runner/libs/bpf_stats.py`
- `runner/libs/app_runners/tracee.py`
- `e2e/driver.py`
- `corpus/driver.py`

I also checked the shared daemon path in `runner/libs/rejit.py`, the artifact writer in `runner/libs/run_artifacts.py`, importability, and repo-wide references to deleted functions.

## Findings

### 1. Duplicate artifact persistence was still present

This was a real simplify regression.

- `e2e/driver.py` was writing `result.json` and `result.md` twice for each run:
  once at the run root, and once again via `ArtifactSession` under `details/`.
- `corpus/driver.py` had the same duplication.

This violated the new rule of keeping only the canonical raw payload plus one `result.md`.

Fixed:

- [e2e/driver.py](/home/yunwei37/workspace/bpf-benchmark/e2e/driver.py:222)
- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:564)

Current canonical layout is:

- `metadata.json`
- `details/progress.json`
- `details/result.json`
- `details/result.md`

### 2. Shared lifecycle still had an unused dry-run scan phase

`run_lifecycle_sessions()` was still doing a full `scan_programs()` dry-run before every `apply_rejit()`, but nothing in live code consumed the resulting `scan_results`.

That meant extra daemon round-trips without any surviving output or control-path value.

Fixed:

- removed `LifecycleRunResult.scan_results`
- removed the unused dry-run scan call from [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:120)
- removed the dead `scan_programs()` wrapper from [runner/libs/rejit.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/rejit.py:903)

### 3. One dead helper remained in `case_common.py`

`summarize_numbers()` had no live callers.

Fixed by deleting it and the now-unused `statistics` import:

- [runner/libs/case_common.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/case_common.py:69)

### 4. `e2e/README.md` was stale

It still mentioned `metrics` and optional `report.md`, which no longer match the simplified path.

Fixed:

- [e2e/README.md](/home/yunwei37/workspace/bpf-benchmark/e2e/README.md:13)

## Lifecycle / Result Check

I did not find a live regression in the simplified execution flow.

- `tracee`, `tetragon`, and `scx` still go through shared lifecycle orchestration and preserve `baseline -> apply -> post_rejit`.
- `bcc` and `bpftrace` still run baseline and post-ReJIT phases through `run_app_runner_lifecycle()`.
- `TraceeRunner` still preserves startup/health/load/stop behavior and workload dispatch.
- `e2e/driver.py` and `corpus/driver.py` still generate `result.md`; they now do it once, through the artifact session.
- `corpus/driver.py` still preserves the multi-app session flow, shared daemon session, failure handling, and suite quiescence boundaries.

## Import / Reference Check

Import smoke passed for:

- `corpus.driver`
- `e2e.driver`
- all five reviewed case modules
- `runner.libs.case_common`
- `runner.libs.bpf_stats`
- `runner.libs.app_runners.tracee`
- `runner.libs.rejit`

Repo-wide grep checks:

- no live code references remain to `runner.libs.metrics`
- no live code references remain to removed `summarize_numbers()`
- no live code references remain to deleted simplify-era helper functions from the reviewed files
- the only remaining hits were historical documentation mentions, e.g. `_run_app` in `docs/kernel-jit-optimization-plan.md`

## Validation

Executed successfully:

```bash
python - <<'PY'
import corpus.driver
import e2e.driver
import e2e.cases.tracee.case
import e2e.cases.bcc.case
import e2e.cases.bpftrace.case
import e2e.cases.scx.case
import e2e.cases.tetragon.case
import runner.libs.case_common
import runner.libs.bpf_stats
import runner.libs.app_runners.tracee
import runner.libs.rejit
print("ok")
PY

make check
```

`make check` passed.

## Final Assessment

After the fixes above, the simplified e2e/corpus/runner path looks coherent:

- no lifecycle break found in the reviewed cases
- no broken import chain found
- no live references found to removed simplify-era helpers
- duplicated artifact storage removed
- one dead lifecycle dry-run path removed

I do not see another blocking issue in the reviewed scope.
