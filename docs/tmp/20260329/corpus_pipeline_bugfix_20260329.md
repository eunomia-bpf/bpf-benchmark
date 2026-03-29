# Corpus Pipeline Bugfix Report (2026-03-29)

## Scope

This report covers three corpus pipeline fixes:

1. Preserve batch progress when one object fails in guest batch mode.
2. Aggregate already-emitted guest batch results even when the guest exits non-zero.
3. Remove raw verifier-log payloads from daemon serve JSON to prevent result-file bloat.

## Files Changed

- `corpus/modes.py`
- `runner/libs/run_artifacts.py`
- `daemon/src/commands.rs`
- `daemon/src/server.rs`
- `daemon/src/commands_tests.rs`
- `tests/python/test_corpus_modes.py`

## Fix Summary

### Bug 1: single-object failure no longer kills the whole corpus batch

The fix was made in guest/host batch orchestration, not in `runner/src/batch_runner.cpp`.

- `run_guest_batch_mode()` now keeps per-object/job failures visible on stderr but returns success for `completed_with_job_errors`, so already collected records are not discarded by a late single-object failure.
- `packet_main()` now preserves guest-emitted records when the guest exits non-zero after emitting all expected records.
- Artifact status becomes `completed_with_errors` instead of pretending the run was clean.

This keeps zero-silent-failure behavior while avoiding all-or-nothing data loss.

### Bug 2: host aggregation now survives guest partial failure

- `packet_main()` now attempts to parse and aggregate guest result JSON even when the VM command exits non-zero.
- If all expected records were emitted, aggregation proceeds and the failure is surfaced in `metadata.json:error_message`.
- If records are missing, the host still fails loudly.

### Bug 3: daemon optimize response no longer emits raw verifier logs

- Added a compact serve-response type for daemon socket `optimize` responses.
- Serve JSON now includes structured fields only, such as `passes_applied`, `sites_applied`, `summary`, `passes`, `timings_ns`, and concise `error_message`.
- Internal attempt/debug payloads are not serialized in serve responses.
- Error strings were reduced to concise headlines instead of full verifier-log dumps.

## Build And Test Validation

Executed successfully:

- `make daemon`
- `make runner`
- `make daemon-tests`
- `pytest tests/python/test_corpus_modes.py -q`

`make daemon-tests` passed with the new daemon response serialization test included.

## Corpus Re-run

Command:

```bash
make vm-corpus TARGET=x86 ITERATIONS=1 WARMUPS=0 REPEAT=10
```

Run artifact:

- `runner/corpus/results/vm_corpus_20260329_203055`

Final console summary:

```text
mode=vm objects=186 targets=1112 compile_pairs=135 measured_pairs=61 comparable=38 applied_comparable=15 applied=39
```

## Verification Results

### 1. `metadata.json` contains aggregated data

File:

- `runner/corpus/results/vm_corpus_20260329_203055/metadata.json`

Observed:

- `status = "completed_with_errors"`
- `objects_attempted = 186`
- `targets_attempted = 1112`
- `compile_pairs = 135`
- `measured_pairs = 61`
- `comparable_pairs = 38`
- `applied_comparable_pairs = 15`

The metadata was aggregated successfully despite a guest non-zero exit condition.

### 2. Single-object failure stayed visible but did not kill the run

Observed metadata error headline:

```text
vm guest batch completed with non-zero exit after emitting all records: guest batch failed: real_world_code_size:libbpf-bootstrap/kprobe.bpf.o:do_unlinkat baseline_run: bpf_program__attach failed: No such file or directory (exit=1)
```

This confirms:

- a concrete object/program failure remained visible
- the run still finished and produced aggregated metadata
- all `186` object records and `1112` program records were preserved

The final result JSON also contains `40` non-OK object records (`error` or `partial`) while still completing the run, which is the intended behavior for per-object failures.

### 3. Result JSON size is below 10 MB

Files:

- `runner/corpus/results/vm_corpus_20260329_203055/details/result.json`
- `runner/corpus/results/vm_corpus_20260329_203055/details/progress.json`

Sizes:

- `details/result.json = 9,358,396 bytes`
- `metadata.json = 196,901 bytes`
- `details/progress.json = 460 bytes`

`details/result.json` is below the required 10 MB limit.

### 4. Verifier-log bloat is gone

Post-run inspection of `details/result.json` showed:

- no `verifier_log` fields
- longest serialized string length: `831` bytes
- largest serialized program record: `33,041` bytes
- largest serialized object record: `26,696` bytes

This is consistent with the daemon no longer embedding raw verifier-log text in serve responses.

## Outcome

The corpus pipeline now:

- keeps successful measurements when some objects fail
- records those failures explicitly instead of silently dropping them
- aggregates metadata from guest batch output even after a recoverable non-zero guest exit
- avoids verifier-log explosion in batch result JSON

The requested rerun completed successfully and the validation checks passed.
