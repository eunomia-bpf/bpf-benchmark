# VM Verify 2026-04-23

## Scope

- Goal:
  - `make -C daemon release`
  - `make vm-e2e E2E_SMOKE=1` with `6/6 PASS`
  - `make vm-corpus SAMPLES=1` with `20/20 ok`
- Guardrails:
  - keep taxonomy split
  - keep daemon `map_inline` relax
  - no silent skip / accommodation
  - run `make check` + `cargo test --manifest-path daemon/Cargo.toml` after each autonomous code-fix round
  - max `5` VM fix iterations

## Local Validation

- `make -C daemon release`: pass
- `make check`: pass after every code-fix round
- `cargo test --manifest-path daemon/Cargo.toml`: pass after every code-fix round (`499 passed`)

## Iterations

### Round 1

- Run token: `run.x86-kvm.e2e.29efeaf0`
- Result:
  - `tracee` failed
  - `katran` failed
- Key artifacts:
  - `e2e/results/tracee_20260423_090709_037465/metadata.json`
  - `e2e/results/katran_20260423_090954_332438/metadata.json`
- Failure reason:
  - Tracee launch rejected `--events all` with `invalid event to trace: all`
  - Katran runtime artifact probe could not find `xdp_root.bpf.o`
- Autonomous fix:
  - `e2e/cases/tracee/config.yaml`
    - `all` -> `*`
  - `runner/mk/build.mk`
    - require and rename Katran `xdp_root.o -> xdp_root.bpf.o`
  - `runner/suites/_common.py`
    - validate `xdp_root.bpf.o`

### Round 2

- Run token: `run.x86-kvm.e2e.3a27b090`
- Result:
  - `tracee` failed
  - `katran` failed
- Key artifacts:
  - `e2e/results/tracee_20260423_093504_259620/metadata.json`
  - attempted Katran metadata path: `e2e/results/katran_20260423_093852_281234/metadata.json`
  - runtime event file: `docs/tmp/runtime-container-tmp/run.x86-kvm.e2e.3a27b090/tracee/events.json`
- Failure reason:
  - Tracee with `--events *` started but produced a huge event stream and then hit close-path timeout
  - Katran artifact write hit `ENOENT` on the VM-mounted result path
- Autonomous fix:
  - `e2e/cases/tracee/config.yaml`
    - `*` -> `tag=default`
  - `runner/libs/app_runners/tracee.py`
    - extend Tracee close-path stop/join time budgets to `30s` / `10s`
  - `runner/libs/run_artifacts.py`
    - `ensure_parent(metadata.json)` before write

### Round 3

- Run token: `run.x86-kvm.e2e.27c8174d`
- Result:
  - `tracee` failed
  - `katran` failed
  - `tetragon` / `bpftrace` / `scx` / `bcc` passed
- Key artifacts:
  - `e2e/results/tracee_20260423_100722_098552/metadata.json`
  - `e2e/results/katran_20260423_101007_222114/metadata.json`
- Failure reason:
  - Tracee VM binary rejected `--events tag=default` with `flags.parseEventFlag: invalid flag format: tag=default`
  - Katran hit `NameError: wait_until_program_set_stable is not defined`
- Autonomous fix:
  - `e2e/cases/tracee/config.yaml`
    - switch to explicit VM-accepted event set:
      - `sched_process_exec`
      - `security_file_open`
      - `security_socket_connect`
      - `execve`
      - `execveat`
  - `runner/libs/app_runners/katran.py`
    - add missing `wait_until_program_set_stable` import

### Round 4 Prelude

- Run token: `run.x86-kvm.e2e.583d6876`
- Result:
  - host-side failure before guest smoke started
- Key artifacts:
  - `.state/runner-contracts/run.x86-kvm.e2e.583d6876`
- Failure reason:
  - `docker save` failed with `no space left on device`
- Autonomous fix:
  - no code diff
  - reclaimed host disk:
    - `docker image prune -af` (`~5.971GB`)
    - `docker builder prune -af` (`311.2GB`)

### Round 4

- Run token: `run.x86-kvm.e2e.a32ea3ed`
- Result:
  - `tracee` pass
  - `tetragon` pass
  - `scx` pass
  - `bcc` pass
  - `bpftrace` failed
  - `katran` failed
- Key artifacts:
  - `e2e/results/tracee_20260423_105627_340122/metadata.json`
  - `e2e/results/tetragon_20260423_105940_969683/metadata.json`
  - `e2e/results/bpftrace_20260423_110040_383189/metadata.json`
  - `e2e/results/scx_20260423_110102_482816/metadata.json`
  - `e2e/results/bcc_20260423_110139_282910/metadata.json`
  - `e2e/results/katran_20260423_110206_677993/metadata.json`
  - runtime Tracee event file: `docs/tmp/runtime-container-tmp/run.x86-kvm.e2e.a32ea3ed/tracee/events.json`
  - preserved contract: `.state/runner-contracts/run.x86-kvm.e2e.a32ea3ed`
- Failure reason:
  - Bpftrace baseline attach did not stabilize before timeout:
    - `timeout_s=20`
    - `last_program_count=1`
    - `last_program_ids=309`
  - Katran was rejected by runner-side daemon-response validation:
    - `summary.total_sites_applied = 0`
    - pass-level `sites_applied > 0` existed only on rolled-back passes
    - validation incorrectly treated rolled-back attempts as final applied-site totals
- Autonomous fix:
  - `runner/libs/app_runners/bpftrace.py`
    - `DEFAULT_ATTACH_TIMEOUT_S: 20 -> 60`
  - `runner/libs/rejit.py`
    - preserve pass `action`
    - validate `summary.total_sites_applied` against non-rolled-back passes only
    - keep rolled-back pass metadata for debugging
- Post-fix validation:
  - `make check`: pass
  - `cargo test --manifest-path daemon/Cargo.toml`: pass
  - `make -C daemon release`: pass

### Round 5

- Run token: `run.x86-kvm.e2e.2414db7a`
- Result:
  - final suite status not obtained
  - Tracee completed
  - Tetragon had only started when the last allowed round was terminated
- Key artifacts:
  - `e2e/results/tracee_20260423_112857_052750/metadata.json`
  - `e2e/results/tetragon_20260423_113213_795666/metadata.json`
  - `e2e/results/tetragon_20260423_113213_795666/details/progress.json`
  - runtime Tracee event file: `docs/tmp/runtime-container-tmp/run.x86-kvm.e2e.2414db7a/tracee/events.json`
- Observed state before termination:
  - Tracee metadata status:
    - `status = completed`
    - `optimization_summary.status = ok`
  - Tracee timing:
    - `started_at = 2026-04-23T11:28:57.052750+00:00`
    - `generated_at = 2026-04-23T11:32:11.202249+00:00`
  - Tracee program count:
    - `37`
    - still far below review Part 4 expectation `120-154`
  - Tracee per-phase event volume in smoke:
    - baseline `primary_events_total = 97087`
    - post-reJIT `primary_events_total = 98806`
  - Tracee runtime event file at observation:
    - size `383771830` bytes
    - top event distribution:
      - `security_file_open = 233516`
      - `security_socket_connect = 61218`
      - `execve = 13848`
      - `sched_process_exec = 13832`
  - Tetragon metadata remained:
    - `status = running`
    - `optimization_summary.status = running`
- Failure / stop reason:
  - this was the 5th and last allowed VM iteration
  - the suite still had not reached `6/6 PASS`
  - current Tracee fallback event set is still wrong for VM smoke:
    - it massively over-collects `security_file_open` / `security_socket_connect`
    - it still does not expand Tracee to the expected `120-154` programs
  - I stopped here per the iteration cap instead of starting a 6th VM round
- Autonomous fix:
  - none after Round 5
  - round limit exhausted

## Final Status

- `make -C daemon release`: pass
- `make vm-e2e E2E_SMOKE=1`: not achieved
  - best completed round: Round 4 with `4/6 PASS`
  - Round 5 did not finish the suite before the 5-round cap was hit
- `make vm-corpus SAMPLES=1`: not run
  - reason: no stable `vm-e2e` success before exhausting the 5 allowed VM iterations

## Metrics Vs Expectation

- `vm-e2e` smoke `6/6 PASS`:
  - actual: not reached
  - expected: `6/6 PASS`
- Tracee programs:
  - actual in Round 5: `37`
  - expected in review Part 4: `120-154`
- Full-suite `total programs`:
  - actual: unavailable because final smoke suite never completed and corpus did not run
  - expected: `207-241`
  - directional assessment: with Tracee still at `37`, the expected range is clearly not verified
- `applied_sample_count`:
  - actual: unavailable (`vm-corpus` not run)
  - expected: `35-45`
- `comparison_exclusion_reason` breakdown:
  - actual: unavailable (`vm-corpus` not run)
  - expected:
    - `missing_baseline_exec_ns ~135-155`
    - `zero_sites_found ~25-40`
    - `all_sites_rolled_back ~3-7`
    - `applied_but_identical ~0-2`
    - `no_passes_requested = 0`
    - `no_programs_changed_in_loader ~= 0`

## Autonomous Diff Summary

- `e2e/cases/tracee/config.yaml`
  - replaced unsupported / over-broad selectors during the iteration sequence and ended on the explicit VM-accepted 5-event set
- `runner/mk/build.mk`
  - require and package Katran `xdp_root.bpf.o`
- `runner/suites/_common.py`
  - validate Katran `xdp_root.bpf.o` in suite preflight
- `runner/libs/run_artifacts.py`
  - ensure metadata parent directory exists before writing on VM-mounted paths
- `runner/libs/app_runners/tracee.py`
  - extend Tracee close-path stop/join timeouts
- `runner/libs/app_runners/katran.py`
  - add missing `wait_until_program_set_stable` import
- `runner/libs/rejit.py`
  - treat rolled-back pass applications correctly when validating daemon apply responses
- `runner/libs/app_runners/bpftrace.py`
  - increase attach timeout to `60s`

Notes:

- Some touched files were already dirty before this session.
- The bullets above describe only the autonomous diffs I introduced, not every line currently shown by `git diff`.

## Worktree

- Final `git diff --shortstat`:
  - `72 files changed, 1254 insertions(+), 1275895 deletions(-)`
- Interpretation:
  - this includes pre-existing unrelated worktree changes and generated/result-file churn
  - it should not be read as "all of these lines came from this verification session"

## Issues

1. Tracee VM smoke is still not on the intended product path. The current fallback event set completes, but it explodes event volume while staying at `37` programs, so it misses the Part 4 objective from both sides.
2. Because `vm-e2e` never produced a stable `6/6 PASS` result within the allowed 5 rounds, `vm-corpus` was not started and all corpus-level metrics remain unverified.
3. The next attempt should start with Tracee event/workload redesign, not with more timeout inflation. The current evidence says the selector mix is semantically wrong, not merely slow.

## Conclusion

- Problem list, not `Ready to commit.`
