# Round 6 VM Verify - 2026-04-22

## Scope

Validate the Round 6 fixes on real x86 KVM by running:

1. `make -C daemon release`
2. `make vm-e2e E2E_SMOKE=1`
3. `make vm-corpus SAMPLES=1`

Required baseline from Round 5:

- `vm-e2e`: `6/6 PASS`
- program counts: `tracee 37 / tetragon 35 / scx 13 / bcc 1 / bpftrace 1 / katran 1`
- `vm-corpus`: `20/20 ok`
- `applied_sample_count = 23`
- `no_programs_changed_in_loader = 38`

## Daemon Release

- Command: `make -C daemon release`
- Result: `PASS`
- Binary: `daemon/target/release/bpfrejit-daemon`

## VM E2E Smoke

### Attempt 1

- Command: `make vm-e2e E2E_SMOKE=1`
- Run token: `run.x86-kvm.e2e.a678ce5a`
- Result: `FAIL`
- Artifact roots:
  - `e2e/results/tracee_20260423_060326_063157`
  - `e2e/results/tetragon_20260423_060534_115862`
  - `e2e/results/bpftrace_20260423_060632_360395`
  - `e2e/results/scx_20260423_060704_542204`
  - `e2e/results/bcc_20260423_060741_288625`
  - `e2e/results/katran_20260423_060809_358985`

Per-case status:

- `tracee`: `FAIL` — `tracee_default encountered malformed Tracee event-file lines: 4`
- `tetragon`: `PASS`
- `bpftrace`: `PASS`
- `scx`: `PASS`
- `bcc`: `PASS`
- `katran`: `PASS`

Tracee malformed-line signal:

- suite error message reported `4` malformed event-file lines
- artifact phase metadata preserved `3` representative parse-error samples in `preflight`
- `primary_events_total = 94482`
- `events_total = 94482`
- sample excerpts were all truncated JSON tails rather than complete malformed objects:
  - `invalid JSON (Expecting property name enclosed in double quotes): value\":\"/usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2\"...`
  - `invalid JSON (Extra data): ool\",\"value\":false},{\"name\":\"prev_comm\"...`
  - `invalid JSON (Extra data): 2},{\"name\":\"inode\",\"type\":\"uint64\"...`

Judgment:

- This looked like collector-side partial-line reads at EOF while Tracee was still appending to `events.json`, not evidence that Tracee emitted stable fully-malformed event objects.
- I did not find evidence of dropped events in this failing preflight snapshot; the workload still recorded `94482` primary/runtime events and the saved samples are mid-object fragments.

Minimal fix applied after attempt 1:

- file: `runner/libs/app_runners/tracee.py`
- change: `consume_event_file()` now buffers newline-less partial reads and only parses them once the line is completed or the file is definitively being rolled/replaced/closed
- validation: `python3 -m py_compile runner/libs/app_runners/tracee.py`

### Attempt 2

- Rerun command: `make vm-e2e E2E_SMOKE=1`
- Run token: `run.x86-kvm.e2e.5106ac73`
- Result: `PASS`
- Artifact roots:
  - `e2e/results/tracee_20260423_063045_530810`
  - `e2e/results/tetragon_20260423_063348_563674`
  - `e2e/results/bpftrace_20260423_063447_343693`
  - `e2e/results/scx_20260423_063517_601825`
  - `e2e/results/bcc_20260423_063554_257629`
  - `e2e/results/katran_20260423_063621_674972`

Per-case status / program count:

- `tracee`: `PASS`, requested programs `37`, applied `36`
- `tetragon`: `PASS`, requested programs `35`
- `bpftrace`: `PASS`, requested programs `1`
- `scx`: `PASS`, requested programs `13`
- `bcc`: `PASS`, requested programs `1`
- `katran`: `PASS`, requested programs `1`

Tracee parse-error check after the fix:

- successful artifact recorded `event_parse_errors = 0` in all captured `tracee_default` phase records
- no malformed-line failure remained

Round 5 baseline comparison:

- `6/6 PASS`: matched
- `tracee 37 / tetragon 35 / scx 13 / bcc 1 / bpftrace 1 / katran 1`: matched exactly on requested program counts
- `tetragon` startup remained healthy, so the explicit `setup_result` path is good on VM

## VM Corpus SAMPLES=1

- Command: `make vm-corpus SAMPLES=1`
- Run token: `run.x86-kvm.corpus.c8f3aae0`
- Result: `PASS`
- Artifact root: `corpus/results/x86_kvm_corpus_20260423_064352_754994`
- Artifact metadata: `corpus/results/x86_kvm_corpus_20260423_064352_754994/metadata.json`

Top-level summary:

- suite output status: `ok`
- artifact metadata status: `completed`
- `selected_apps = 20`
- `sample_count = 23`
- `applied_sample_count = 23`
- `comparison_exclusion_reason_counts.no_programs_changed_in_loader = 38`
- `comparison_exclusion_reason_counts.missing_baseline_exec_ns = 61`

Per-app status / program count / sample count:

- `bcc/capable`: `ok`, programs `1`, samples `1`
- `bcc/execsnoop`: `ok`, programs `2`, samples `0`
- `bcc/bindsnoop`: `ok`, programs `3`, samples `2`
- `bcc/biosnoop`: `ok`, programs `3`, samples `1`
- `bcc/vfsstat`: `ok`, programs `5`, samples `0`
- `bcc/opensnoop`: `ok`, programs `3`, samples `0`
- `bcc/syscount`: `ok`, programs `2`, samples `0`
- `bcc/tcpconnect`: `ok`, programs `3`, samples `0`
- `bcc/tcplife`: `ok`, programs `1`, samples `0`
- `bcc/runqlat`: `ok`, programs `3`, samples `1`
- `scx/rusty`: `ok`, programs `13`, samples `1`
- `tetragon/default`: `ok`, programs `35`, samples `6`
- `katran`: `ok`, programs `1`, samples `0`
- `tracee/default`: `ok`, programs `37`, samples `6`
- `bpftrace/capable`: `ok`, programs `1`, samples `1`
- `bpftrace/biosnoop`: `ok`, programs `2`, samples `1`
- `bpftrace/vfsstat`: `ok`, programs `2`, samples `0`
- `bpftrace/runqlat`: `ok`, programs `3`, samples `1`
- `bpftrace/tcplife`: `ok`, programs `1`, samples `1`
- `bpftrace/tcpretrans`: `ok`, programs `1`, samples `1`

Tracee corpus note:

- `tracee/default` stayed `ok`
- `program_count = 37`
- `applied_program_count = 36`
- one program still hit the long-standing per-program apply error:
  - `tracee/default:syscall__init_module#167`
  - `apply_error = BPF_PROG_REJIT: Invalid argument (os error 22)`
- this did not flip the app fatal because the run still had `6` comparable Tracee samples
- I did not find any new top-level fatal/degradation log that turned this into a suite failure

Round 5 baseline comparison:

- `20/20 ok`: matched
- `applied_sample_count = 23`: matched exactly
- `no_programs_changed_in_loader = 38`: matched exactly
- major app program counts still matched the Round 5 VM baseline: `tetragon 35`, `tracee 37`, `scx 13`

## Fix Diff

Round 6 VM-only repair:

- `runner/libs/app_runners/tracee.py`
  - added a partial-line buffer in `consume_event_file()`
  - newline-less EOF fragments are now held until completion instead of being parsed immediately as malformed JSON
  - incomplete buffered content is still surfaced on definite rollover/close, so the Round 6 structured-contract signal remains intact for real broken lines

## Final Diff State

- `git diff --shortstat -- . ':!docs/tmp'`
- `5 files changed, 95 insertions(+), 21 deletions(-)`

## Conclusion

`Round 6 validated on VM. Safe to commit.`
