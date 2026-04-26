# AWS x86 corpus on t3.medium

Date: 2026-04-26 America/Vancouver

## HEAD and worktree

- HEAD under test: `7b67f722d6af5de07d4016146dbe0494053886e7`
- `git log --oneline -3` at run start:
  - `7b67f722 Add metadata files for various benchmark runs including bcc, bpftrace, katran, tetragon, and tracee`
  - `ed4a8c65 Add docs/tmp reports from app expansion work`
  - `a26db312 Add CLAUDE.md rules and rename /default app entries`
- Existing dirty worktree was present before this run and was left untouched:
  - `corpus/driver.py`
  - `e2e/cases/tetragon/case.py`
  - `e2e/cases/tracee/case.py`
  - `runner/libs/app_runners/process_support.py`
  - `runner/libs/aws_executor.py`
  - `runner/libs/benchmark_catalog.py`
  - `runner/targets/aws-arm64.env`
  - `runner/targets/aws-x86.env`
  - `docs/tmp/authoritative-corpus-20260426/`
  - `docs/tmp/code-review-new-runners-20260426/`

## Command

Loaded env:

```sh
source ~/.config/bpf-benchmark/local.env
```

Exported AWS x86 vars observed in the shell:

- `AWS_X86_KEY_NAME=codex-arm64-test-20260319121631`
- `AWS_X86_KEY_PATH=/home/yunwei37/.ssh/codex-arm64-test-20260319121631.pem`
- `AWS_X86_PROFILE=codex-ec2`
- `AWS_X86_REGION=us-east-1`
- `AWS_X86_SECURITY_GROUP_ID=sg-02dc8d8b61d78608c`
- `AWS_X86_SUBNET_ID=subnet-009460065a1cd946c`

Benchmark command:

```sh
make aws-x86-benchmark AWS_X86_BENCH_MODE=corpus
```

Resolved run config:

- Run token: `run.aws-x86.corpus.7397c7d3`
- Target name: `aws-x86`
- Suite: `corpus`
- Instance type: `t3.medium`
- Region: `us-east-1`
- Remote stage dir: `/var/tmp/bpf-benchmark-aws-x86/corpus/run.aws-x86.corpus.7397c7d3`
- Suite args: `--samples 1`

## Local prep

- The run initially waited on `.cache/runner-locks/artifact-build.x86_64.lock` because another local x86 build was already holding the shared artifact lock.
- After that lock released, this run rebuilt the local x86 runner runtime image and refreshed the image tar:
  - final runtime image id: `sha256:7775345d94cc4dad8cbd4827fb7bda51e89e32d2e577efa003ed159f5ea585d`
  - refreshed tar: `.cache/container-images/x86_64-runner-runtime.image.tar`
- `make` reported no rebuild needed for `daemon/target/release/bpfrejit-daemon`.

## AWS run

Provisioned instance:

- Instance id: `i-0e98c42cf3b8686f7`
- Name tag: `bpf-benchmark-x86-run.aws-x86.corpus.7397c7d3`
- Instance type: `t3.medium`
- AZ: `us-east-1f`
- Launch time: `2026-04-26T06:51:07+00:00`
- Public IP: `34.239.149.33`

Setup succeeded:

- Runtime image transfer completed and `docker load` succeeded:
  - `Loaded image: bpf-benchmark/runner-runtime:x86_64`
- Benchmark kernel setup succeeded and verified:
  - setup dir: `.cache/aws-x86/results/setup_7.0.0-rc2_20260426_070430`
  - verified kernel release: `7.0.0-rc2`
  - verified default kernel path: `/boot/vmlinuz-7.0.0-rc2`

## Result

Result: fail before corpus workload execution.

Authoritative remote log:

- `.cache/aws-x86/results/logs/corpus_run.aws-x86.corpus.7397c7d3_20260426_070613.remote.log`

Remote log contents:

```text
/usr/bin/python3: Error while finding module specification for 'runner.suites.corpus' (ModuleNotFoundError: No module named 'runner')
```

Observed behavior:

- The benchmark kernel booted and validated successfully.
- The runtime container image loaded successfully.
- The remote corpus suite then failed immediately because the remote Python environment could not import `runner.suites.corpus`.
- No corpus result session directory was produced under `corpus/results/`.

## OOM assessment

- This failure was **not** an OOM failure.
- During remote `docker load`, the instance still showed swap available and no OOM evidence was observed.
- Because the failure was a Python module import failure, there is no data-based reason from this run alone to recommend switching from `t3.medium` to `t3.large`.
- If a later rerun fails specifically with OOM, then `t3.large` would be the appropriate next recommendation.

## Termination

The failed run auto-terminated the `t3.medium` instance:

- `i-0e98c42cf3b8686f7`: `terminated`

Then `make aws-x86-terminate` was run as requested. Current implementation terminates **all** active `aws-x86` instances matching `Project=bpf-benchmark` and `Role=aws-x86`, not just the current run token.

Instances affected by `make aws-x86-terminate`:

- `i-047922053578f1b3f` (`bpf-benchmark-x86-run.aws-x86.corpus.3fd00460`): `terminated`
- `i-0d95b7859d869f9cc` (`bpf-benchmark-x86-run.aws-x86.e2e.5f819744`): `terminated`
- `i-0f3cdac85218db3a7` (`bpf-benchmark-x86-run.aws-x86.corpus.f7159702`): `terminated`
- After `make aws-x86-terminate` completed, there were no remaining active `aws-x86` instances in `us-east-1` for `Project=bpf-benchmark`.

## Debug artifacts

- Preserved contract dir: `.state/runner-contracts/run.aws-x86.corpus.7397c7d3`
- Preserved run-state dir: `.cache/aws-x86/run-state/run.aws-x86.corpus.7397c7d3`
