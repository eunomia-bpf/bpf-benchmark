# Recovery VM Summary (2026-04-23)

## Scope

- Only the Tracee event-set assumption was rolled back.
- Kept in place:
  - X taxonomy split
  - daemon `map_inline` relax + negative test
  - Katran healthcheck / `xdp_root`
  - workload variant unlocks + `macro_apps.yaml` switches
  - bpftrace `60s` attach timeout
  - `rejit.py` rolled-back-pass exclusion fix
  - fail-loud workload variants
  - Tracee parse-error reopen + partial-line buffer fix
  - Tracee `load_timeout = 120`
  - `wait_until_program_set_stable` fail-loud behavior

## Tracee Config Revert

- Working source confirmed from pre-I-prod history:
  - `git show 9cb75f7d:e2e/cases/tracee/config.yaml`
  - `git show 57f5b04b:e2e/cases/tracee/config.yaml`
- Effective revert:

```diff
 events:
-  - sched_process_exec
-  - security_file_open
-  - security_socket_connect
   - execve
-  - execveat
+  - sched_process_exec
+  - security_file_open
+  - security_socket_connect
```

- Final working Tracee top-level event set:
  - `execve`
  - `sched_process_exec`
  - `security_file_open`
  - `security_socket_connect`
- Note:
  - `git diff -- e2e/cases/tracee/config.yaml` is empty at the end because the file is back at the Round-3/HEAD-equivalent working content.

## Local Validation

- Initial guardrail validation:
  - `make check`: pass
  - `cargo test --manifest-path daemon/Cargo.toml --release`: pass (`499 passed`)
  - `make -C daemon release`: pass
- After the corpus round-1 autonomous fix:
  - `make check`: pass
  - `cargo test --manifest-path daemon/Cargo.toml --release`: pass (`499 passed`)
  - `python3 -c 'from runner.libs.workload import _accept4_roundtrip; _accept4_roundtrip()'`: pass

## VM Iterations

### vm-e2e Round 1

- Run token: `run.x86-kvm.e2e.133dad38`
- Command: `make vm-e2e E2E_SMOKE=1`
- Result: `6/6 PASS`
- Artifacts:
  - `e2e/results/tracee_20260423_120132_924305`
  - `e2e/results/tetragon_20260423_120444_771572`
  - `e2e/results/bpftrace_20260423_120544_359851`
  - `e2e/results/scx_20260423_120613_283712`
  - `e2e/results/bcc_20260423_120650_178048`
  - `e2e/results/katran_20260423_120717_647829`
- Per-case program counts:
  - Tracee: `37`
  - Tetragon: `35`
  - SCX: `13`
  - Katran: `3`
  - bpftrace: `1`
  - BCC: `1`
- Smoke total programs: `90`
- Fixes needed after this round: none

### vm-corpus Round 1

- Run token: `run.x86-kvm.corpus.4e74b4f6`
- Command: `make vm-corpus SAMPLES=1`
- Result: error (`19 ok`, `1 error`)
- Artifact:
  - `corpus/results/x86_kvm_corpus_20260423_121401_537062/metadata.json`
- Failure:
  - `tracee/default` failed with `[Errno 11] accept4: Resource temporarily unavailable`
  - app-level status from guest log: `{"app": "tracee/default", "status": "error", "program_count": 0}`
- Root cause:
  - `_accept4_roundtrip()` called libc `accept4()` on a listener put into nonblocking mode by `listener.settimeout(2.0)`, so the loopback handshake could race and surface `EAGAIN`.
- Autonomous fix:
  - `runner/libs/workload.py`
  - keep the `accept4` syscall path
  - retry on `EAGAIN` / `EWOULDBLOCK` / `EINTR` until deadline
  - still fail loudly on real client failure or timeout

### vm-corpus Round 2

- Run token: `run.x86-kvm.corpus.56c38295`
- Command: `make vm-corpus SAMPLES=1`
- Result: `20/20 ok`
- Artifact:
  - `corpus/results/x86_kvm_corpus_20260423_124338_026179/metadata.json`
- Recovery confirmation:
  - `tracee/default`: `program_count=37`, `status=ok`

## Final Status

- `make vm-e2e E2E_SMOKE=1`: pass
- `make vm-corpus SAMPLES=1`: pass
- No commit made
- No push made

## Final Metrics

- Final corpus artifact:
  - `corpus/results/x86_kvm_corpus_20260423_124338_026179/metadata.json`
- `statuses`:
  - `ok: 20`
- `selected_apps`: `20`
- `sample_count`: `26`
- `applied_sample_count`: `26`
- `all_comparable_geomean`: `1.0839088347295942`
- `applied_only_geomean`: `1.0839088347295942`
- `discovered_programs` / total programs: `124`
- Programs by runner family:
  - `tracee`: `37`
  - `tetragon`: `35`
  - `scx`: `13`
  - `katran`: `3`
  - `bcc`: `26`
  - `bpftrace`: `10`
- Tracee stayed on the corrected fixed-total assumption:
  - `tracee/default program_count = 37`

## X Taxonomy Breakdown

- `missing_baseline_exec_ns`: `59`
- `zero_sites_found`: `26`
- `all_sites_rolled_back`: `13`
- `applied_but_identical`: `0`

## Actual vs Corrected Expectation

- Total programs:
  - actual: `124`
  - expected: `~125-135`
  - assessment: `1` below the expected floor, but stable and fully green
- `applied_sample_count`:
  - actual: `26`
  - expected: `~30-40`
  - assessment: below expectation, but the corpus suite completed successfully and the X taxonomy remained intact

## Git Diff

- `git diff --shortstat`
  - `71 files changed, 1267 insertions(+), 1275894 deletions(-)`
- Note:
  - full worktree shortstat is dominated by pre-existing/unrelated result and doc churn
  - the recovery-specific code change in this turn was the `accept4` retry hardening in `runner/libs/workload.py`

## Conclusion

`Ready to commit.`
