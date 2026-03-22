# AWS ARM64 benchmark resume report

Date resumed: 2026-03-20
Task: #266

## Summary

- The previous attempt left a usable local staging area under `.cache/aws-arm64/`, but no cached live-instance state.
- `aws sts get-caller-identity` was executed on 2026-03-20 and failed with `NoCredentials`.
- Per task constraints, no EC2 instance was launched and no benchmark was run in this resume.
- Fallback deliverables were completed instead:
  - root `Makefile` targets for AWS ARM64 launch/setup/benchmark/terminate/full lifecycle
  - helper script `scripts/aws_arm64.sh`
  - documentation in this report

## Existing local state

Observed under `.cache/aws-arm64/`:

- `config-al2023-arm64`
  - cached Amazon Linux 2023 ARM64 stock kernel config (`6.1.163-186.299.amzn2023.aarch64`)
- `artifacts/vmlinuz-7.0.0-rc2.efi`
- `artifacts/vmlinux-7.0.0-rc2`
- `artifacts/modules-7.0.0-rc2.tar.gz`
- `micro-bundle/` and `micro-bundle.tar.gz`
  - contains ARM64 `micro_exec`, BPF objects, generated inputs, policies, and runtime libs
- `scanner-bundle/` and `scanner-bundle.tar.gz`
  - leftover from the earlier attempt; current smoke flow does not require the standalone scanner CLI
- `tool-src-overlay.tar.gz`
- `linux-framework-src/`
  - scratch source tree from the prior attempt

Not found:

- no instance-id or public-ip state file
- no launch log or termination record
- no remote benchmark result bundle

## AWS CLI check

Executed:

```bash
aws sts get-caller-identity
```

Result:

```text
An error occurred (NoCredentials): Unable to locate credentials.
You can configure credentials by running "aws login".
```

Because credentials were not configured on 2026-03-20, the EC2 phases were intentionally skipped.

## Added targets

New root `Makefile` targets:

- `make aws-arm64-launch`
- `make aws-arm64-setup INSTANCE_IP=x`
- `make aws-arm64-benchmark INSTANCE_IP=x`
- `make aws-arm64-terminate INSTANCE_ID=i-xxx`
- `make aws-arm64`

Implementation details:

- `scripts/aws_arm64.sh launch`
  - checks AWS identity
  - launches or reuses a tagged ARM64 EC2 instance
  - records state in `.cache/aws-arm64/state/instance.env`
- `scripts/aws_arm64.sh setup <instance_ip>`
  - builds/stages ARM64 kernel artifacts locally
  - uploads `vmlinuz.efi` + modules tarball
  - installs with `dracut`/`grubby`
  - performs one-shot reboot into the custom kernel
  - verifies `uname -r`, network, and default boot entry
- `scripts/aws_arm64.sh benchmark <instance_ip>`
  - assembles a minimal ARM64 `micro_exec` bundle from local build outputs
  - uploads it to the remote host
  - runs bare-metal smoke samples directly via `micro_exec run-kernel`
  - collects JSON/log files into `.cache/aws-arm64/results/`
- `scripts/aws_arm64.sh full`
  - wraps launch -> setup -> benchmark -> terminate
  - uses an `EXIT` trap so termination still runs on failure

## Required environment

For `launch` / `full`:

- `AWS_REGION` or `AWS_DEFAULT_REGION`
- `AWS_ARM64_KEY_NAME`
- `AWS_ARM64_KEY_PATH`
- `AWS_ARM64_SECURITY_GROUP_ID`
- `AWS_ARM64_SUBNET_ID`

Optional:

- `AWS_ARM64_INSTANCE_TYPE`
  - defaults to `t4g.micro`
- `AWS_ARM64_NAME_TAG`
  - defaults to `bpf-benchmark-arm64`
- `AWS_ARM64_AMI_ID`
  - overrides the default AL2023 ARM64 SSM parameter lookup
- `AWS_ARM64_BENCH_ITERATIONS`
- `AWS_ARM64_BENCH_WARMUPS`
- `AWS_ARM64_BENCH_REPEAT`

## Expected usage once AWS is configured

Minimal manual path:

```bash
make aws-arm64-launch \
  AWS_REGION=us-west-2 \
  AWS_ARM64_KEY_NAME=... \
  AWS_ARM64_KEY_PATH=~/.ssh/...pem \
  AWS_ARM64_SECURITY_GROUP_ID=sg-... \
  AWS_ARM64_SUBNET_ID=subnet-...

make aws-arm64-setup INSTANCE_IP=x.x.x.x \
  AWS_ARM64_KEY_PATH=~/.ssh/...pem

make aws-arm64-benchmark INSTANCE_IP=x.x.x.x \
  AWS_ARM64_KEY_PATH=~/.ssh/...pem

make aws-arm64-terminate INSTANCE_ID=i-...
```

Full lifecycle:

```bash
make aws-arm64 \
  AWS_REGION=us-west-2 \
  AWS_ARM64_KEY_NAME=... \
  AWS_ARM64_KEY_PATH=~/.ssh/...pem \
  AWS_ARM64_SECURITY_GROUP_ID=sg-... \
  AWS_ARM64_SUBNET_ID=subnet-...
```

## Important caveats

- This resume did not validate the new AWS targets end-to-end because AWS credentials were unavailable.
- The setup flow assumes the remote AMI is Amazon Linux 2023 ARM64 with `ec2-user`, `dracut`, and `grubby`.
- The full lifecycle target is intentionally termination-first: if an instance is launched or reused by the script, the script will terminate it on exit.
- The local kernel setup path prefers the cached AL2023 config at `.cache/aws-arm64/config-al2023-arm64` when the ARM64 build tree has no `.config`.

## Status

- EC2 benchmark run: blocked by missing AWS credentials
- Makefile targets: added
- Documentation: added
- Instance termination requirement: enforced in the full-lifecycle script
