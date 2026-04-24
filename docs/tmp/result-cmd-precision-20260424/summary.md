# Result / Cmd Precision Audit 2026-04-24

## Scope

- Workspace constraints respected:
  - did not touch `runner/libs/app_runners/tracee.py`
  - did not touch `e2e/cases/tracee/case.py`
  - did not touch `runner/containers/runner-runtime.Dockerfile`
  - did not touch `runner/mk/build.mk`
  - did not run `make vm-*`
- Verification run under:
  - `source /home/yunwei37/workspace/.venv/bin/activate`

## Layer A: Result JSON / metadata payload fields

- Removed from [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:840) and [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:877):
  - `workload`
  - `configured_workload_seconds`
  - `args`
  - `prog_ids`
  - `programs`
  - `baseline`
  - `baseline_workload`
  - `baseline_workloads`
  - `rejit_apply`
  - `rejit`
  - `rejit_workload`
  - `rejit_workloads`
  - `process`
  - replacement kept: `program_measurements`, `selected_workload`, `rejit_applied`
  - consumer proof: corpus summary/reporting only reads `selected_workload`, `status`, `error`, and `program_measurements` in [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:715) and [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:756)
  - exact zero-hit grep for unique removed keys: `daemon_socket`, `configured_workload_seconds`, `baseline_workload`, `baseline_workloads`, `rejit_workload`, `rejit_workloads` had no `result.get()/payload.get()/[...]` consumers under `runner e2e corpus micro tests Makefile`

- Removed suite-level `daemon_socket` from [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:952)
  - consumer proof: no `result.get("daemon_socket")` or `payload.get("daemon_socket")` hits under `runner e2e corpus micro tests Makefile`

- Removed from [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:661):
  - `scheduler_output`
  - `scan_results`
  - `rejit_result`
  - consumer proof: no `payload.get("scheduler_output")`, `payload.get("scan_results")`, or `payload.get("rejit_result")` hits under `runner e2e corpus micro tests Makefile`
  - retained because live markdown consumers exist:
    - `site_summary` in [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:425)
    - `baseline` in [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:433)
    - `post_rejit` in [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:443)

- Removed from [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:456) and [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:479):
  - `config`
  - `host`
  - `tetragon_launch_command`
  - `tetragon_programs`
  - `agent_logs`
  - `scan_results`
  - `rejit_result`
  - `site_summary`
  - error-path skeletons for `baseline`, `post_rejit`, `programs`
  - dead lifecycle artifact dict entries also removed at [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:493)
  - consumer proof: no `payload.get("tetragon_launch_command")`, `payload.get("agent_logs")`, `payload.get("scan_results")`, `payload.get("rejit_result")`, or `payload.get("config")` hits under `runner e2e corpus micro tests Makefile`
  - retained because markdown still reads:
    - `baseline` in [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:374)
    - `post_rejit` in [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:375)
    - `programs` in [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:404)

- Removed from [e2e/cases/katran/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py:153):
  - `daemon`
  - `host`
  - `programs`
  - `baseline`
  - `scan_results`
  - `rejit_result`
  - `post_rejit`
  - consumer proof: same-file markdown only reads `status`, `workload_spec`, `duration_s`, `comparison`, and `error_message` in [e2e/cases/katran/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py:75)

## Layer B: subprocess / run_command argv

- Removed `-p|--pretty` from machine-parsed `bpftool -j` calls:
  - [runner/libs/agent.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/agent.py:64)
  - [runner/libs/app_runners/katran.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/katran.py:77)
  - [runner/libs/app_runners/katran.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/katran.py:124)
- Upstream proof:
  - `bpftool -h` shows `{-j|--json} [{-p|--pretty}]`
  - `-p` is optional formatting only; JSON parsing behavior is unchanged
- Retained:
  - attach/detach mode tokens
  - explicit timeouts
  - all non-default bpftool subcommands

## Layer C: docker/runtime command builder

- Canonicalized artifact args in [runner/libs/suite_commands.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_commands.py:84)
  - builder now emits only `--native-repos` and `--scx-packages`
  - canonical consumers/callers:
    - [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:65)
    - [runner/libs/suite_args.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_args.py:95)
    - [runner/suites/corpus.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/corpus.py:43)
    - [runner/suites/e2e.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/e2e.py:43)
    - [runner/suites/test.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/test.py:61)

- Narrowed runtime-container result mounts to the active suite only:
  - mount selection in [runner/libs/suite_commands.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_commands.py:27)
  - KVM mkdir path in [runner/libs/kvm_executor.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/kvm_executor.py:90)
  - AWS mkdir path in [runner/libs/aws_executor.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/aws_executor.py:651)
  - failure mode is explicit via `die("unsupported suite for runtime container result mount: ...")`

- Removed runtime `docker run -e` duplication for:
  - `BPFREJIT_IMAGE_WORKSPACE`
  - `PYTHONPATH`
  - reason: runner image already sets both in [runner/containers/runner-runtime.Dockerfile](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:468)

- Retained:
  - `BPFREJIT_INSIDE_RUNTIME_CONTAINER` because `inside_runtime_image()` consumes it in [runner/libs/workspace_layout.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/workspace_layout.py:42)
  - `/boot:ro` because runtime workloads still probe `/boot/config-*`; recent tetragon artifacts showed that access path and the architecture doc still documents `/boot:ro` in [docs/benchmark-runtime-architecture.md](/home/yunwei37/workspace/bpf-benchmark/docs/benchmark-runtime-architecture.md:128)

## Layer D: argparse audit

- No additional dead argparse surface remained in the allowed files after the current `main` cleanup state.
- Current canonical wrappers already expose only the kept flags:
  - [runner/suites/corpus.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/corpus.py:43)
  - [runner/suites/e2e.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/e2e.py:42)
  - [runner/suites/test.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/test.py:61)
- Not deleted because live consumers exist:
  - `--corpus-workload-seconds` is still emitted from [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:65) and [runner/libs/suite_args.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_args.py:95)
  - `micro/driver.py`, `runner/suites/micro.py`, and `e2e/driver.py` args all have direct reads in the same files

## Not Deleted

- `metadata.kinsn_modules` was kept.
  - authoritative reason: [docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:994) explicitly records `metadata.kinsn_modules` as a required E2E artifact fact

- SCX `site_summary`, `baseline`, `post_rejit` were kept.
  - reason: live markdown/report consumers still read them

- Tetragon `baseline`, `post_rejit`, `programs`, `comparison` were kept.
  - reason: same-file markdown builder still renders them

- Katran `comparison` and `workload_spec` were kept.
  - reason: same-file markdown builder still renders them

## Verification

- `python3 -m py_compile corpus/driver.py e2e/cases/scx/case.py e2e/cases/tetragon/case.py e2e/cases/katran/case.py runner/libs/agent.py runner/libs/app_runners/katran.py runner/libs/suite_commands.py runner/libs/kvm_executor.py runner/libs/aws_executor.py`
  - pass

- `make check`
  - pass

- Net negative proof for this change set:
  - commit set counted: `d3988906`, `68d837a9`, `7e5ff83d`, `8ef8a196`
  - summed `git show --shortstat` totals: `files=9 insertions=15 deletions=138 net=-123`
  - note: `main` received unrelated concurrent commits during execution, so branch-wide `git diff` was not a reliable per-author measure

## Self Review

- No backward-compat warning shims were added.
- No new env vars, config keys, or CLI flags were introduced by this change set.
- No silent failure paths were added; all retained `die()/RuntimeError` paths still fail loudly on invalid suite names, missing payload shapes, or missing runtime state.
- Did not touch `tracee.py`, `e2e/cases/tracee/case.py`, `runner/containers/runner-runtime.Dockerfile`, or `runner/mk/build.mk`.
- Current worktree still contains unrelated concurrent changes outside this change set, notably dirty `Makefile`, dirty `e2e/driver.py`, dirty `runner/libs/app_runners/tracee.py`, and untracked `e2e/results/*`; they were intentionally excluded from commits.
