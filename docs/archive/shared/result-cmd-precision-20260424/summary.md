# Result / Cmd Precision Audit 2026-04-24

## Scope
- Guardrails respected: no edits to `runner/libs/app_runners/tracee.py`, `e2e/cases/tracee/case.py`, `runner/containers/runner-runtime.Dockerfile`, or `runner/mk/build.mk`; no `make vm-*`.
- This round produced code commits `d3988906`, `68d837a9`, `7e5ff83d`, `8ef8a196`.

## Layer A

- [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:715) summary/report consumers only read `selected_workload`, `status`, `error`, and `program_measurements`; [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:840) and [corpus/driver.py](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:877) therefore dropped write-only mirrors: `workload`, `configured_workload_seconds`, `args`, `prog_ids`, `programs`, `baseline`, `baseline_workload(s)`, `rejit_apply`, `rejit`, `rejit_workload(s)`, `process`, plus suite-level `daemon_socket`.
- [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:661) dropped `scheduler_output`, `scan_results`, `rejit_result`; exact `payload.get()/payload[...]` grep for those keys returned 0 consumers under `runner e2e corpus micro tests Makefile`.
- [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:456) and [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:479) dropped `config`, `host`, `tetragon_launch_command`, `tetragon_programs`, `agent_logs`, `scan_results`, `rejit_result`, `site_summary`, and dead error-path skeletons; unique-key consumer grep was 0, and dead lifecycle artifacts were removed at [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:493).
- [e2e/cases/katran/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py:153) dropped `daemon`, `host`, `programs`, `baseline`, `scan_results`, `rejit_result`, `post_rejit`; same-file markdown only reads `status`, `workload_spec`, `duration_s`, `comparison`, `error_message` at [e2e/cases/katran/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/case.py:75).

## Layer B

- Removed `-p|--pretty` from machine-parsed `bpftool -j` calls at [runner/libs/agent.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/agent.py:64), [runner/libs/app_runners/katran.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/katran.py:77), and [runner/libs/app_runners/katran.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/katran.py:124); `bpftool -h` shows `{-j|--json} [{-p|--pretty}]`, so `-p` was default-format noise only.

## Layer C

- [runner/libs/suite_commands.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_commands.py:84) now emits only canonical `--native-repos` / `--scx-packages`; callers/parsers are already canonical in [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:65), [runner/libs/suite_args.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_args.py:95), [runner/suites/corpus.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/corpus.py:43), [runner/suites/e2e.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/e2e.py:42), and [runner/suites/test.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/test.py:61).
- [runner/libs/suite_commands.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_commands.py:96), [runner/libs/kvm_executor.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/kvm_executor.py:90), and [runner/libs/aws_executor.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/aws_executor.py:651) now mount/create only the active suite result dir; runtime `-e BPFREJIT_IMAGE_WORKSPACE` and `-e PYTHONPATH` were removed because the image already sets them in [runner/containers/runner-runtime.Dockerfile](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:468).

## Layer D

- No extra dead argparse surface remained to delete in the allowed files: current canonical wrappers are [runner/suites/corpus.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/corpus.py:43), [runner/suites/e2e.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/e2e.py:42), and [runner/suites/test.py](/home/yunwei37/workspace/bpf-benchmark/runner/suites/test.py:61); `micro/driver.py`, `runner/suites/micro.py`, and `e2e/driver.py` args all still have direct reads.

## Retained

- Kept `metadata.kinsn_modules` because [docs/kernel-jit-optimization-plan.md](/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:994) marks it authoritative.
- Kept SCX `site_summary` / `baseline` / `post_rejit` because markdown reads them at [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:425), [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:433), [e2e/cases/scx/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/scx/case.py:443).
- Kept Tetragon `baseline` / `post_rejit` / `programs` because markdown reads them at [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:374), [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:375), [e2e/cases/tetragon/case.py](/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tetragon/case.py:404).
- Kept `/boot:ro` and `BPFREJIT_INSIDE_RUNTIME_CONTAINER`; `/boot:ro` remains documented in [docs/benchmark-runtime-architecture.md](/home/yunwei37/workspace/bpf-benchmark/docs/benchmark-runtime-architecture.md:128), and `inside_runtime_image()` still keys off `BPFREJIT_INSIDE_RUNTIME_CONTAINER` in [runner/libs/workspace_layout.py](/home/yunwei37/workspace/bpf-benchmark/runner/libs/workspace_layout.py:42).

## Verification

- `python3 -m py_compile corpus/driver.py e2e/cases/scx/case.py e2e/cases/tetragon/case.py e2e/cases/katran/case.py runner/libs/agent.py runner/libs/app_runners/katran.py runner/libs/suite_commands.py runner/libs/kvm_executor.py runner/libs/aws_executor.py`: pass.
- `make check`: pass.
- Per-commit net-negative proof for this change set: `files=9 insertions=15 deletions=138 net=-123` from `git show --shortstat` over `d3988906`, `68d837a9`, `7e5ff83d`, `8ef8a196`.

## Self Review

- No compat shim, warning wrapper, new env var, new config key, or new CLI flag was added in this change set.
- Unrelated concurrent dirt in `Makefile`, `e2e/driver.py`, `runner/libs/app_runners/tracee.py`, and untracked `e2e/results/*` was intentionally excluded.
