# AWS ARM64 Corpus Run Attempt (2026-04-26)

## Scope

Goal: run `make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=corpus` on AWS ARM64 `t4g.medium` from the current repository HEAD, then clean up with `make aws-arm64-terminate`.

Latest commits confirmed before the run:

```text
724f68fb Fix remote workspace sync for AWS corpus runs
0be16ad5 Fix review-flagged bugs in P0 patches
cc762f62 Fix cilium program ID drift: rediscover programs on ID disappearance
```

## Environment

Loaded with:

```bash
source ~/.config/bpf-benchmark/local.env
export $(compgen -A variable | grep '^AWS_ARM64')
export AWS_ARM64_INSTANCE_TYPE=t4g.medium
```

Relevant values:

```text
AWS_ARM64_INSTANCE_TYPE=t4g.medium
AWS_ARM64_KEY_NAME=codex-arm64-test-20260319121631
AWS_ARM64_KEY_PATH=/home/yunwei37/.ssh/codex-arm64-test-20260319121631.pem
AWS_ARM64_PROFILE=codex-ec2
AWS_ARM64_REGION=us-east-1
AWS_ARM64_SECURITY_GROUP_ID=sg-0ebe13c1e4c0defc9
AWS_ARM64_SUBNET_ID=subnet-009460065a1cd946c
```

Run token:

```text
run.aws-arm64.corpus.626dc8ed
```

Preserved control artifact:

```text
.state/runner-contracts/run.aws-arm64.corpus.626dc8ed/run-config.json
```

## What Ran

Benchmark command:

```bash
make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=corpus
```

Observed entrypoint:

```text
"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite benchmark aws-arm64 "corpus"
```

Observed start time:

```text
2026-04-26T12:23:28-07:00
```

Cleanup command:

```bash
make aws-arm64-terminate
```

Observed terminate entrypoint:

```text
"/home/yunwei37/workspace/.venv/bin/python3" -m runner.libs.run_target_suite terminate aws-arm64
```

Observed terminate start time:

```text
2026-04-26T15:17:11-07:00
```

## Outcome

The run did **not** reach AWS instance launch or remote corpus execution.

For the entire observation window:

- `aws ec2 describe-instances ... Role=aws-arm64 ...` always returned `[]`
- `corpus/results/logs` stayed empty
- no AWS instance ID, public IP, or remote log was ever produced

The blocking stage was local ARM64 runtime image preparation inside:

```text
docker build --platform linux/arm64 --target runner-runtime ...
```

At the point I stopped the run, the local Docker build was still active after about `2h 53m` and had still not exited. The latest visible build state was:

```text
[+] Building 10403.0s (22/56)
[runner-runtime-userspace 1/11] ...
[ 97%] Built target folly_fibers_batch_semaphore
```

The build was not dead: repeated checks showed active `qemu-binfmt` ARM64 `clang++` workers at ~100% CPU compiling Folly/Katran objects, and the Docker progress advanced from `21/56` to `22/56`, with visible userspace progress moving through roughly `41%`, `53%`, `64%`, `73%`, `80%`, `91%`, and finally `97%`.

I manually interrupted the run because it still had not crossed from local prep into AWS launch after nearly three hours. The terminal ended with:

```text
[run-target-suite][ERROR] preserved debug artifact: /home/yunwei37/workspace/bpf-benchmark/.state/runner-contracts/run.aws-arm64.corpus.626dc8ed
...
KeyboardInterrupt
make: *** [Makefile:114: aws-arm64-benchmark] Interrupt
```

## OOM Check

No OOM was observed.

At roughly the one-hour mark, local memory remained healthy:

```text
Mem: 125Gi total, 6.5Gi used, 110Gi free, 118Gi available
Swap: 8.0Gi total, 0B used
```

There was no kernel OOM evidence in the captured benchmark output, and the local build workers remained CPU-bound rather than being killed. I could not read `dmesg` as an unprivileged user, so this conclusion is based on process continuity, memory snapshots, and the absence of kill/OOM messages in the terminal output.

## Cleanup Result

`make aws-arm64-terminate` exited with code `0`.

Post-cleanup checks:

- AWS ARM64 instance query still returned `[]`
- no local benchmark/build processes from this run remained alive

This means cleanup completed as a no-op on the AWS side, because the benchmark never progressed far enough to create an EC2 instance.

## Notes

- `docs/tmp/aws-arm64-corpus-20260426/benchmark.log` exists but is `0` bytes
- `docs/tmp/aws-arm64-corpus-20260426/terminate.log` exists but is `0` bytes

I observed the long-running commands through a live PTY instead of piping them through `tee`, so the authoritative record for this attempt is this summary plus the preserved control artifact above.

## Bottom Line

On this repository state and this host, `make aws-arm64-benchmark AWS_ARM64_BENCH_MODE=corpus` did not actually start an AWS `t4g.medium` corpus run on `2026-04-26`. It remained stuck in very long local ARM64 runtime image preparation, never launched an instance, and was manually interrupted after nearly three hours. `make aws-arm64-terminate` then completed successfully with nothing to terminate.
