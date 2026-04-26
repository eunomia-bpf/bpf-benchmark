# AWS x86 corpus run summary (2026-04-26)

## Scope

- Goal: run corpus on AWS x86 `t3.medium` with `AWS_X86_BENCH_MODE=corpus`.
- Repo HEAD at start:
  - `0be16ad5 Fix review-flagged bugs in P0 patches`
  - `cc762f62 Fix cilium program ID drift: rediscover programs on ID disappearance`
  - `db754540 Fix P0 bugs: error propagation, program discovery, workload triggers`
- Environment: sourced `~/.config/bpf-benchmark/local.env` and exported all `AWS_X86*` variables (`AWS_X86_KEY_NAME`, `AWS_X86_KEY_PATH`, `AWS_X86_PROFILE`, `AWS_X86_REGION`, `AWS_X86_SECURITY_GROUP_ID`, `AWS_X86_SUBNET_ID`).
- No commit was created.

## Execution notes

- Initial command: `make aws-x86-benchmark AWS_X86_BENCH_MODE=corpus`.
- Local execution hit an unrelated existing `x86-kvm corpus` artifact-build lock twice, so the host-side run never progressed past local prep.
- To keep the AWS run moving, I used the generated run contract and invoked the equivalent executor path directly:
  - `python -m runner.libs.aws_executor run .state/runner-contracts/run.aws-x86.corpus.8b77e80c/run-config.json .state/runner-contracts/run.aws-x86.corpus.8b77e80c/suite-args.json`
- The first real AWS attempt exposed a remote stage sync bug instead of a corpus/runtime bug:
  - `.cache/aws-x86/results/logs/corpus_run.aws-x86.corpus.7397c7d3_20260426_070613.remote.log`
  - failure: `ModuleNotFoundError: No module named 'runner'`
- Root cause: `runner/libs/aws_executor.py` synced the runtime image tar to the remote stage, but not the repo workspace content needed by `python -m runner.suites.corpus`.
- I patched `runner/libs/aws_executor.py` locally to stream the required workspace subset into the remote stage for corpus runs. The synced subset now includes:
  - `runner/__init__.py`
  - `runner/libs`
  - `runner/suites`
  - `corpus/config`
  - `corpus/driver.py`
  - `corpus/inputs`
  - `daemon/target/release/bpfrejit-daemon`
- A follow-up rerun exposed one more missing remote asset during app startup:
  - `missing upstream Tetragon policy dir: /home/.../e2e/cases/tetragon/policies`
- I extended the same remote sync patch to also include:
  - `e2e/cases/bpftrace/scripts`
  - `e2e/cases/tetragon/policies`

## Final corpus result

- Final AWS run used `t3.medium` and completed corpus execution far enough to produce synced local artifacts.
- Result artifact:
  - `corpus/results/aws_x86_corpus_20260426_091010_447576`
- Metadata:
  - `status: error`
  - `error_message: corpus suite reported errors`
  - `started_at: 2026-04-26T09:10:10.447576+00:00`
  - `generated_at: 2026-04-26T09:45:36.374031+00:00`
- Aggregate result from `details/result.json`:
  - `22` apps total
  - `21` `ok`
  - `1` `error`
- The only failing app was:
  - `tracee/monitor`
  - error: `prog 735: BPF_PROG_REJIT: Invalid argument (os error 22)`
- Relevant log and result files:
  - `.cache/aws-x86/results/logs/corpus_run.aws-x86.corpus.8b77e80c_20260426_091007.remote.log`
  - `corpus/results/aws_x86_corpus_20260426_091010_447576/metadata.json`
  - `corpus/results/aws_x86_corpus_20260426_091010_447576/details/result.json`
  - `corpus/results/aws_x86_corpus_20260426_091010_447576/details/result.md`
- Important note for this repo: this was a genuine ReJIT failure surfaced by the workload and should not be filtered. The final error is not a stage-sync issue.

## Other observations

- No OOM was observed during the successful corpus attempt.
- Manual checks on the instance during the run showed memory remained available and `dmesg` did not show OOM-killer messages.
- Non-fatal warnings seen in the final remote log:
  - `cilium/agent`: baseline rediscovery returned fewer programs than expected (`2/3`)
  - `tetragon/observer`: baseline rediscovery returned fewer programs than expected (`301/328`)

## Cleanup

- Ran `make aws-x86-terminate` after the run.
- The final AWS instance was terminated successfully.
