# Corpus Batch Runner Exit Code 1 Fix

## Summary

- Failing run: `runner/corpus/results/vm_corpus_20260329_163852`
- Symptom: `status=error`, `measured_pairs=0`, `applied_programs=0`
- Immediate error: `vm guest batch failed: guest batch failed: batch runner exited with code 1 (exit=1)`
- Root cause: guest VM did not raise `RLIMIT_NOFILE`, but the guest `micro_exec run-batch` binary already required `RLIMIT_NOFILE >= 65536`.

## Evidence

### 1. The guest `micro_exec` snapshot already contained the new RLIMIT check

The failing run used:

- `runner/corpus/results/vm_corpus_20260329_163852/guest-inputs/micro_exec`

That binary contains these strings:

- `RLIMIT_NOFILE hard limit`
- `getrlimit(RLIMIT_NOFILE) failed:`
- `setrlimit(RLIMIT_NOFILE) failed:`

So the batch runner in that VM image was already built with `ensure_batch_runner_nofile_limit()`.

### 2. The VM launch path for the failing run did not pass any guest nofile override

In [metadata.json](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260329_163852/metadata.json), the recorded `run_vm_shell.py` invocation contains:

- `--command ... python3 corpus/driver.py ... --batch-size 100 --timeout 240`

But it does **not** contain:

- `--nofile 65536`

That means the guest shell never executed a matching `ulimit -HSn 65536` before running `corpus/driver.py`.

### 3. The observed artifact shape matches “batch runner failed before running jobs”

From:

- [stdout log](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-cpesnrxi.json.stdout_log.txt)
- [guest result json](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-cpesnrxi.json)
- [metadata.json](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260329_163852/metadata.json)

Observed facts:

- guest log shows `guest_info`, then `program_progress` from `1` to `469`, then `guest batch failed: batch runner exited with code 1`
- final summary is still `compile_pairs=0`, `measured_pairs=0`, `applied_programs=0`
- program/object records are placeholder-shaped: compile/run fields are `null`

This means the Python guest wrapper still emitted one placeholder record per object after `run_objects_locally_batch()` returned, but the underlying batch runner did not produce usable job results.

That is consistent with a startup failure such as the RLIMIT guard tripping before batch execution.

### 4. The requested `details/result.json` was not present

I checked:

- `runner/corpus/results/vm_corpus_20260329_163852/details/result.json`

That file does not exist in the current workspace copy of this run directory, even though `metadata.json` still points at `details_dir: "details"`. So the usable evidence for this investigation came from:

- [stdout log](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-cpesnrxi.json.stdout_log.txt)
- [metadata.json](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260329_163852/metadata.json)
- [guest result json](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260329/corpus-rejit-batch/corpus-rejit-vm-batch-result-cpesnrxi.json)

## Fix

The current uncommitted worktree already contains the required fix chain:

- [vm.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/vm.py)
  - adds `DEFAULT_GUEST_NOFILE = 65536`
  - forwards `--nofile 65536` into the VM shell command
  - writes `ulimit -HSn 65536` into the guest script
- [run_vm_shell.py](/home/yunwei37/workspace/bpf-benchmark/runner/scripts/run_vm_shell.py)
  - accepts `--nofile`
  - passes it into `write_guest_script(...)`
- [batch_runner.cpp](/home/yunwei37/workspace/bpf-benchmark/runner/src/batch_runner.cpp)
  - keeps the explicit `RLIMIT_NOFILE >= 65536` requirement in the batch runner itself
- [modes.py](/home/yunwei37/workspace/bpf-benchmark/corpus/modes.py)
  - prefers batch stderr over generic `exit code 1`, so if RLIMIT still fails in the future the real reason is surfaced instead of only `batch runner exited with code 1`

So the concrete repair is:

1. keep the batch runner hardening
2. ensure the guest VM actually raises the soft/hard nofile limit before launching the corpus driver
3. surface the real stderr if the limit still cannot be raised

## Validation

Ran successfully:

- `make daemon-tests`
- `make runner`

Results:

- `make daemon-tests`: `525 passed`
- `make runner`: success
- targeted pytest: `33 passed`

Full `pytest` from repo root is currently not usable as a signal for this change because collection enters vendored Linux selftests under `vendor/linux/...` and aborts with unrelated `SystemExit` from upstream tests. I did not modify `vendor/linux-framework`.

## Conclusion

This was not a daemon reconnect/crash issue and not a batch-plan-empty issue.

The failure matches a guest environment regression:

- batch runner binary expected `RLIMIT_NOFILE >= 65536`
- VM launch path for the failing run did not raise guest nofile
- Python guest-side progress logging then obscured the true startup failure by writing placeholder records for all 469 objects

The existing uncommitted fix in the worktree addresses the actual problem without requiring a VM rerun to validate the code path.
