# AWS x86 Benchmark Report (2026-03-28)

## Summary

- Target request: run the full AWS x86 benchmark, collect complete performance data, and ensure the EC2 instance is terminated.
- Outcome: `benchmark not completed`.
- Performance data: `none`. No valid benchmark JSON was produced under `.cache/aws-x86/results/`.
- Cleanup status: `complete`. `bpf-benchmark-x86` tagged instances are `0`, and `.cache/aws-x86/state/instance.env` is absent.

## What Was Verified

1. `bzImage` exists:
   - `vendor/linux-framework/arch/x86/boot/bzImage`
2. Kernel build flock protection exists in the repo:
   - root `Makefile` uses `flock "$(KERNEL_BUILD_LOCK)" $(MAKE) __kernel-build-locked`
3. `make daemon` and `make runner` were completed before AWS attempts.
4. AWS x86 flow is remote-only:
   - the AWS path launches a real EC2 instance and does not depend on local VM runtime state
   - however, `make aws-x86-full` still blocks on the shared local `kernel-build.lock` during local artifact preparation

## AWS Attempts

### Attempt 1: cached full module tarball

- Cached artifact bundle originally contained:
  - `bzImage-7.0.0-rc2+`
  - `vmlinux-7.0.0-rc2+`
  - `modules-7.0.0-rc2+.tar.gz` at about `2.6G`
- Result:
  - EC2 booted into the custom kernel entry
  - SSH never came back
- Relevant log:
  - `docs/tmp/20260328/logs/make_aws_x86_full_retry_20260328.log`

### Attempt 2: minimal builtin-only module tarball

- Repacked `modules-7.0.0-rc2+.tar.gz` down to about `130K` using only:
  - `modules.builtin`
  - `modules.builtin.modinfo`
  - `modules.builtin.ranges`
  - `modules.order`
- Result:
  - custom kernel booted far enough to hit systemd
  - Amazon Linux 2023 entered emergency mode
  - console showed missing runtime module functionality around `rpc_pipefs`
- Relevant logs:
  - `docs/tmp/20260328/logs/aws_x86_repack_modules_minimal_20260328.log`
  - `docs/tmp/20260328/logs/aws_x86_manual_lifecycle_20260328.log`

### Attempt 3: reduced runtime module tarball

- Probed a stock AL2023 x86 instance to identify its loaded modular runtime set.
- Repacked `modules-7.0.0-rc2+.tar.gz` to about `28M`, adding actual `.ko` files for:
  - `sunrpc` / NFS chain
  - `nls_ascii`, `nls_utf8`
  - `sch_fq_codel`
  - `ghash-clmulni-intel`
  - `skx_edac_common`, `nfit`
  - `dmi-sysfs`
- Result:
  - runtime-module gap was reduced
  - but remote `dracut` still failed because it explicitly wanted `xfs` and `ext4` module files
- Relevant logs:
  - `docs/tmp/20260328/logs/aws_x86_stock_probe_20260328.log`
  - `docs/tmp/20260328/logs/aws_x86_repack_modules_reduced_20260328.log`
  - `docs/tmp/20260328/logs/aws_x86_manual_lifecycle_reduced_20260328.log`

### Attempt 4: no-initrd boot

- Tried bypassing `dracut` and booting the custom kernel without generating a new initramfs.
- Result:
  - GRUB still referenced `/boot/initramfs-7.0.0-rc2+.img`
  - boot failed with:
    - missing initramfs
    - `Kernel panic - not syncing: VFS: Unable to mount root fs on unknown-block(0,0)`
- Relevant logs:
  - `docs/tmp/20260328/logs/aws_x86_setup_noinitrd_20260328.log`
  - `docs/tmp/20260328/logs/aws_x86_setup_noinitrd_console_tail_20260328.log`

## Root Cause Summary

The benchmark did not fail because of AWS credentials, security group setup, or EC2 lifecycle management. It failed because the x86 kernel artifact packaging path is not yet producing a bootable-and-remotely-manageable Amazon Linux 2023 environment.

The specific blockers observed were:

1. The default cached x86 module artifact was far too large (`~2.6G`) and came from a stale/full module tree.
2. A builtin-only tarball is too small for AL2023 userspace because the distro still expects some runtime-loadable modules such as `sunrpc`.
3. A reduced runtime tarball still fails the current `dracut` path because `dracut` explicitly looks for `xfs` and `ext4` module files, even though the kernel config path is aiming to make core storage/network drivers builtin.
4. A naive no-initrd boot path is not currently viable with the way `grubby --copy-default` populates the boot entry.

## Current Clean State

- `.cache/aws-x86/state/instance.env`: absent
- AWS tagged instances named `bpf-benchmark-x86`: `0`
- No benchmark result artifacts were produced under `.cache/aws-x86/results/`

## Recommended Next Fix

To make AWS x86 benchmarking runnable, the repo needs one of these fixed end-to-end:

1. Make the x86 artifact packaging step produce a `dracut`-compatible module tree that includes the exact module files `dracut` expects on AL2023.
2. Or change the EC2 boot entry generation so the custom kernel truly boots without an initramfs and still gets the correct root device parameters.
3. After that, rerun the full lifecycle and only accept performance numbers from a successful post-reboot `uname -r == 7.0.0-rc2+` instance.
