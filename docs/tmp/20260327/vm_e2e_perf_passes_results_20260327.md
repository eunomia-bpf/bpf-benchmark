# VM E2E Perf-Pass Validation (20260327 artifact stamp)

## Date note

- Host local date during this check: 2026-03-26 (`America/Vancouver`)
- Latest E2E artifact directories are stamped `20260327` because their result metadata is recorded in UTC (`2026-03-27T01:*+00:00`)

## Step 1: Python compile verification

Activated `/home/yunwei37/workspace/.venv` and ran the requested `py_compile` sweep for:

- `e2e/cases/tracee/case.py`
- `e2e/cases/tetragon/case.py`
- `e2e/cases/katran/case.py`
- `e2e/cases/bpftrace/case.py`
- `e2e/cases/bcc/case.py`
- `e2e/cases/scx/case.py`
- `runner/libs/rejit.py`

Result: all seven files compiled successfully. No source changes were required.

## Step 2: Build and VM run attempt

### `make all`

`make all` built `micro` and `daemon`, then failed in the aggregate `kernel-tests` stage because the root `Makefile` points at a missing `tests/kernel` directory:

```text
make[2]: *** /home/yunwei37/workspace/bpf-benchmark/tests/kernel: No such file or directory.  Stop.
make[1]: *** [Makefile:192: kernel-tests] Error 2
make: *** [Makefile:152: all] Error 2
```

This failure is outside the modified E2E Python files.

### `make vm-e2e TARGET=x86`

I attempted `make vm-e2e TARGET=x86` separately because the runner's `vm-e2e` target does not depend on `tests/kernel`.

That invocation did not reach a fresh guest execution in this turn. The runner's global VM lock (`.cache/runner/vm-locks/vm_global.lock`) was already held by a pre-existing `vm-corpus` run in the same workspace, so `vm-e2e` stayed queued inside `with_vm_lock.py`. I interrupted that queued waiter to avoid leaving a delayed VM launch behind this session.

Because no fresh `vm-e2e` run started in this turn, the case summary below is based on the latest completed `20260327` E2E artifacts already present under `e2e/results/`.

## Step 3: Latest `20260327` E2E results

Latest directories found:

- `e2e/results/tracee_20260327_012734`
- `e2e/results/tetragon_20260327_013101`
- `e2e/results/bpftrace_20260327_013320`
- `e2e/results/scx_20260327_013800`
- `e2e/results/katran_20260327_013934`
- `e2e/results/bcc_20260327_014111`

### tracee

- Artifact: `e2e/results/tracee_20260327_012734`
- Case execution: `metadata.status=completed`, `details/result.json status=ok`
- REJIT outcome: not fully successful
- Verifier rejection: yes
- Failure: `prog 36 (lkm_seeker_modt)` failed with `BPF_PROG_REJIT: Invalid argument`; verifier reported `unreachable insn 252`
- Program summary: 13 programs seen, 12 `debug_result.status=ok`, 12 `applied=true`, 1 error
- `map_inline`: 0 hits
- Instruction delta: `+400` net across attempted programs, `+378` across the 12 successfully applied programs
- Exec result: baseline completed, but no post-REJIT comparison was produced (`comparison.comparable=false`, reason `rejit did not apply successfully`)

### tetragon

- Artifact: `e2e/results/tetragon_20260327_013101`
- Case execution: `metadata.status=completed`, `details/result.json status=ok`
- REJIT outcome: not fully successful
- Verifier rejection: yes
- Rejected programs:
  - `prog 151 (event_exit_acct)`
  - `prog 155 (event_wake_up_n)`
  - `prog 156 (execve_rate)`
  - `prog 157 (execve_send)`
  - `prog 158 (event_execve)`
- Program summary: 7 programs seen, 2 `debug_result.status=ok`, 1 `applied=true`, 5 errors
- `map_inline`: 5 hits total across 5 programs
- `map_inline` hit programs:
  - `event_exit_acct` (1 hit, pass delta `-8`)
  - `event_wake_up_n` (1 hit, pass delta `0`)
  - `execve_rate` (1 hit, pass delta `0`)
  - `execve_send` (1 hit, pass delta `0`)
  - `event_execve` (1 hit, pass delta `-124`)
- Instruction delta: `-472` net across attempted programs; only one program applied cleanly, with `+24` net delta in that applied subset
- Exec result: baseline completed, but no post-REJIT comparison was produced (`comparison.comparable=false`, reason `rejit did not apply successfully`)

### bpftrace

- Artifact: `e2e/results/bpftrace_20260327_013320`
- Case execution: `metadata.status=completed`
- REJIT outcome: partially successful
- Verifier rejection: no verifier rejection in the two successful REJIT records
- Record summary: 6 baseline successes, 2 REJIT successes (`tcpretrans`, `capable`)
- `map_inline`: 0 hits
- Instruction delta: `-21` total across the two successful REJIT records
  - `tcpretrans`: `-3`
  - `capable`: `-18`
- Exec result: artifact summary reports `speedup_geomean=2.9234063855823784`
- Note: the latest artifact only contains successful REJIT phases for `tcpretrans` and `capable`; `tcplife`, `biosnoop`, `runqlat`, and `vfsstat` are baseline-only in this result set

### scx

- Artifact: `e2e/results/scx_20260327_013800`
- Case execution: `metadata.status=completed`
- REJIT outcome: not fully successful
- Verifier rejection: no verifier rejection observed in the latest artifact
- Blocking errors: permission failures on
  - `prog 889 (rusty_init_task)`
  - `prog 890 (rusty_exit_task)`
  - `prog 891 (rusty_init)`
- Program summary: 13 programs seen, 10 `debug_result.status=ok`, 7 `applied=true`, 3 errors
- `map_inline`: 0 hits
- Instruction delta: `-7` net across applied programs
- Exec result: no post-REJIT measurement (`comparison.comparable=false`, reason `post-ReJIT measurements are unavailable`)

### katran

- Artifact: `e2e/results/katran_20260327_013934`
- Case execution: failed before `details/result.json` was produced
- REJIT outcome: no verdict from the latest artifact
- Verifier rejection: not reached
- Failure: `capture_map_state.py` was killed with exit `-9` while preparing map capture
- `map_inline`: unavailable
- Instruction delta: unavailable
- Exec result: failed

### bcc

- Artifact: `e2e/results/bcc_20260327_014111`
- Case execution: `metadata.status=completed`
- REJIT outcome: not exercised in the latest artifact
- Verifier rejection: none observed
- Tool summary: all 8 tools were skipped because the expected binaries were missing under `runner/repos/bcc/libbpf-tools`
- `map_inline`: 0 hits
- Instruction delta: unavailable
- Exec result: 0 baseline successes, 0 REJIT successes

Skipped tools:

- `tcplife`
- `biosnoop`
- `runqlat`
- `execsnoop`
- `opensnoop`
- `capable`
- `vfsstat`
- `tcpconnect`

## Bottom line

- The modified Python E2E case files and `runner/libs/rejit.py` compile cleanly.
- `make all` is currently blocked by a missing `tests/kernel` directory, not by the E2E Python changes.
- A fresh `make vm-e2e TARGET=x86` run could not be started in this turn because the workspace's global VM lock was already occupied by a pre-existing VM-backed benchmark.
- In the latest completed `20260327` E2E artifacts, only `tetragon` shows any `map_inline` hits (5 total). `tracee` and `tetragon` both show verifier rejections; `scx` fails for permission reasons instead; `katran` fails earlier during map capture; `bpftrace` has two successful REJIT records with no `map_inline` hits; `bcc` is effectively skipped because the tool binaries are missing.
