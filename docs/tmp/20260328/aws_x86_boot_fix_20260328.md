# AWS x86 Boot Fix Report (2026-03-29)

## Summary

- Selected fix: `Option A`, keep AL2023/dracut happy by building the root-storage and runtime-critical drivers as modules instead of builtin.
- Code status: implemented.
- Local validation status: passed.
- AWS lifecycle status: not completed yet.
- Benchmark status: blocked by an already-running local performance benchmark in the same workspace, which the repo policy forbids running in parallel with AWS benchmark work.

## Root Cause

`runner/scripts/aws_x86.sh` was overriding the x86 AWS kernel config back to builtin for drivers that AL2023 expects `dracut` to package from `.ko` files. That defeated the modular settings in `vendor/bpfrejit_defconfig` and recreated the original boot problem:

- `dracut` wants `xfs`, `ext4`, and NVMe module artifacts under `/lib/modules/<release>/`.
- the AWS setup path was forcing those settings to `=y`
- builtin drivers do not leave the `.ko` files `dracut` expects
- the generated initramfs was therefore incomplete

## Changes Made

### `runner/scripts/aws_x86.sh`

- bumped `AWS_X86_KERNEL_CACHE_VERSION` from `2` to `3` so old builtin-oriented AWS kernel artifacts are not reused
- changed the AWS x86 config override path to require these as modules:
  - `CONFIG_ENA_ETHERNET=m`
  - `CONFIG_NVME_CORE=m`
  - `CONFIG_BLK_DEV_NVME=m`
  - `CONFIG_XFS_FS=m`
  - `CONFIG_EXT4_FS=m`
  - `CONFIG_VIRTIO_NET=m`
  - `CONFIG_VIRTIO_BLK=m`
- changed artifact verification from "must be builtin" to "must have installable module artifact"
- made module verification accept either raw `.ko` or compressed module files such as `.ko.zst`

### `vendor/bpfrejit_defconfig`

- changed `CONFIG_EXT4_FS=y` -> `m`
- changed `CONFIG_VIRTIO_NET=y` -> `m`
- changed `CONFIG_VIRTIO_BLK=y` -> `m`

## Local Validation

### Syntax

- `bash -n runner/scripts/aws_x86.sh`
  - result: `pass`

### Effective Config

Current `vendor/linux-framework/.config` after the AWS x86 config refresh shows:

- `CONFIG_ENA_ETHERNET=m`
- `CONFIG_NVME_CORE=m`
- `CONFIG_BLK_DEV_NVME=m`
- `CONFIG_EXT4_FS=m`
- `CONFIG_XFS_FS=m`
- `CONFIG_VIRTIO_NET=m`
- `CONFIG_VIRTIO_BLK=m`

## AWS State

- tagged instances named `bpf-benchmark-x86`: `0`
- `.cache/aws-x86/state/instance.env`: absent

## Benchmark Blocker

The repo-level `AGENTS.md` says performance benchmark runs must not execute in parallel with other performance benchmarks.

At the time of this report, the workspace already has an active x86 corpus benchmark:

- PID `1076284`: `/bin/bash -c make vm-corpus TARGET=x86 REPEAT=50 > docs/tmp/20260328/vm_corpus_round2_host.log 2>&1`
- PID `1076285`: `make vm-corpus TARGET=x86 REPEAT=50`
- PID `1076286`: `make -C /home/yunwei37/workspace/bpf-benchmark/runner vm-corpus ... TARGET=x86 REPEAT=50`

Because of that:

- I did not start a fresh AWS benchmark run in parallel with the existing corpus performance run
- there is currently no valid AWS benchmark JSON to report
- kernel boot verification on EC2 and final AWS performance numbers are still pending the workspace becoming benchmark-idle

## Next Step

Once the existing `vm-corpus` run finishes, rerun:

```bash
make aws-x86-full
```

and then record:

- `uname -r == 7.0.0-rc2+`
- benchmark result JSON path under `.cache/aws-x86/results/`
- instance termination confirmation
- final performance numbers
