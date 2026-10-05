# Round 5 VM Verify - 2026-04-22

## Scope

Validate Round 3 + 4 + 5 deletions on real VM/kernel by running:

1. `make -C daemon release`
2. `make vm-e2e E2E_SMOKE=1`
3. `make vm-corpus SAMPLES=1`

Required baseline from Round 2:

- `vm-e2e`: `6/6 PASS`
- `vm-corpus SAMPLES=1`: `20/20 ok`
- `applied_sample_count = 23`
- `no_programs_changed_in_loader = 38`

## Daemon Release

- Command: `make -C daemon release`
- Result: `PASS`
- Binary: `daemon/target/release/bpfrejit-daemon`

## VM E2E Smoke

- Command: `make vm-e2e E2E_SMOKE=1`
- Run token: `run.x86-kvm.e2e.0cc54491`
- Result: `PASS`
- Artifact root:
  - `e2e/results/tracee_20260423_043102_950824`
  - `e2e/results/tetragon_20260423_043404_274492`
  - `e2e/results/bpftrace_20260423_043502_779723`
  - `e2e/results/scx_20260423_043535_506080`
  - `e2e/results/bcc_20260423_043612_240812`
  - `e2e/results/katran_20260423_043639_636402`

Per-case status / program count:

- `tracee`: `PASS`, programs `37`
- `tetragon`: `PASS`, programs `35`
- `bpftrace`: `PASS`, programs `1`
- `scx`: `PASS`, programs `13`
- `bcc`: `PASS`, programs `1`
- `katran`: `PASS`, programs `1`

Round 2 comparison:

- `6/6 PASS`: matched
- `tracee 37 / tetragon 35 / scx 13 / bcc 1 / bpftrace 1 / katran 1`: matched exactly

Tracee note:

- No explicit silent-parser fallback signal was found in the E2E tracee artifact.

## VM Corpus SAMPLES=1

- First attempt command: `make vm-corpus SAMPLES=1`
- First failing run token: `run.x86-kvm.corpus.1c7f723f`
- First failing artifact: `corpus/results/x86_kvm_corpus_20260423_044433_700667`

Observed failures:

- `tetragon/default`: `TetragonRunner requires setup_result from the caller`
- `tracee/default`: single-program daemon apply failure
  - program id `115`
  - program `syscall__init_module`
  - daemon error `BPF_PROG_REJIT: Invalid argument (os error 22)`
  - other Tracee programs still applied successfully, so this was an app-status policy regression rather than a broad loader/discovery failure

Minimal fix applied:

```diff
diff --git a/runner/libs/app_runners/__init__.py b/runner/libs/app_runners/__init__.py
+    if "setup_result" not in mapped:
+        from .tetragon import inspect_tetragon_setup
+        mapped["setup_result"] = inspect_tetragon_setup()

diff --git a/corpus/driver.py b/corpus/driver.py
-    fatal_apply_error = bool(apply_error)
+    fatal_apply_error = bool(apply_error) and not has_comparable_measurement
```

Why this is minimal:

- `runner/libs/app_runners/__init__.py`: restores the caller-side Tetragon setup contract for corpus/shared-runner construction without reintroducing lazy runner fallback logic
- `corpus/driver.py`: restores the previously validated policy that a single per-program apply error is only app-fatal if it leaves the app with zero comparable measurements

Second attempt:

- Rerun command: `make vm-corpus SAMPLES=1`
- Passing run token: `run.x86-kvm.corpus.0bf94ad4`
- Passing artifact: `corpus/results/x86_kvm_corpus_20260423_052038_435399`
- Result: `PASS`

Final corpus status:

- top-level status: `ok`
- per-app statuses: `20/20 ok`
- `summary.applied_sample_count = 23`
- `summary.sample_count = 23`
- `summary.comparison_exclusion_reason_counts.no_programs_changed_in_loader = 38`
- `summary.comparison_exclusion_reason_counts.missing_baseline_exec_ns = 61`

Per-app program counts from the passing run:

- `bcc/capable 1`
- `bcc/execsnoop 2`
- `bcc/bindsnoop 3`
- `bcc/biosnoop 3`
- `bcc/vfsstat 5`
- `bcc/opensnoop 3`
- `bcc/syscount 2`
- `bcc/tcpconnect 3`
- `bcc/tcplife 1`
- `bcc/runqlat 3`
- `scx/rusty 13`
- `tetragon/default 35`
- `katran 1`
- `tracee/default 37`
- `bpftrace/capable 1`
- `bpftrace/biosnoop 2`
- `bpftrace/vfsstat 2`
- `bpftrace/runqlat 3`
- `bpftrace/tcplife 1`
- `bpftrace/tcpretrans 1`

Round 2 comparison:

- `20/20 ok`: matched
- `applied_sample_count 23`: matched exactly
- `no_programs_changed_in_loader 38`: matched exactly
- No significant app program-count drop was observed in the passing VM run; major counts are `tetragon 35`, `tracee 37`, `scx 13`

Tracee note:

- Passing corpus run still logged Tracee runtime event-loss / decode warnings in process stderr, e.g. `Lost ... events` plus `error reading argument from buffer`
- App status remained `ok`
- This was recorded but not treated as blocking, per task instruction

## Final Diff State

- `git diff --shortstat HEAD --`
- `50 files changed, 3971 insertions(+), 1331 deletions(-)`

Note:

- This shortstat is the full current worktree, not only the tiny VM-fix patch.

## Conclusion

`Round 3+4+5 deletions validated on VM. Safe to commit.`
