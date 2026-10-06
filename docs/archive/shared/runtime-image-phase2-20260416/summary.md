# Runtime Image Phase 2 Summary

Date: 2026-04-16 local, final verification crossed into 2026-04-17 local.

## Code Cleanup

- Deleted `runner/libs/kvm_executor.py::_kernel_modules_prelude_shell`, a 30-line helper that manually assembled `/lib/modules/$(uname -r)` from `.cache/repo-artifacts`.
- Removed the single KVM executor call site for that helper.
- Replaced KVM module/container setup with:
  - `runner/scripts/bpfrejit-install --image bpf-benchmark/runner-runtime:x86_64 .cache/container-images/x86_64-runner-runtime.image.tar`
  - the existing runtime container command after install completes.
- KVM dockerd setup now uses a host-backed sparse ext4 loop disk by default so `docker load` has enough VM storage.
- `runner/libs/workspace_layout.py` now extracts the KVM kernel to `.cache/runtime-kernel/x86_64/bzImage`; local KVM prep no longer depends on repo-artifact kernel modules.

## Build.mk Cleanup

- Verified these legacy names have zero remaining matches:
  - `_kernel_modules_prelude_shell`
  - `image-x86-kernel-artifacts`
  - `image-arm64-kernel-artifacts`
  - `image-arm64-aws-kernel-artifacts`
  - `HOST_*_KERNEL_BUILD_WORK_DIR`
  - `KERNEL_MODULE_BUILD_LINK`
  - `.virtme_mods/lib/modules/0.0.0`
- Current kernel artifact flow is one parameterized target: `image-kernel-artifacts`.
- Added the public alias target `image-runner-runtime-image-tar`.
- Forced runtime kernel built-ins needed by Phase 2 VM execution:
  - `BLK_DEV_LOOP`
  - `VIRTIO_CONSOLE`
  - `EXT4_FS`
  - `JBD2`
  - `FS_MBCACHE`

## Runtime Image Artifacts

Validated by `docker load` followed by `docker run --rm bpf-benchmark/runner-runtime:x86_64 ...`.

- Kernel image: `/artifacts/kernel/bzImage`
- Kernel modules: `/artifacts/modules/7.0.0-rc2/...`
- Kinsn modules:
  - `/artifacts/kinsn/bpf_bulk_memory.ko`
  - `/artifacts/kinsn/bpf_endian.ko`
  - `/artifacts/kinsn/bpf_extract.ko`
  - `/artifacts/kinsn/bpf_rotate.ko`
  - `/artifacts/kinsn/bpf_select.ko`
- Manifest: `/artifacts/manifest.json`
  - `kernel_release`: `7.0.0-rc2`
  - `target_arch`: `x86_64`
  - `kernel_image`: `bzImage`
- Runtime user artifact symlink: `/opt/bpf-benchmark -> /artifacts/user`
- Micro objects: `/opt/bpf-benchmark/micro-programs/x86_64/*.bpf.o`

Also verified these required VM built-ins are listed in `modules.builtin`:

- `kernel/drivers/char/virtio_console.ko`
- `kernel/drivers/block/loop.ko`
- `kernel/fs/ext4/ext4.ko`
- `kernel/fs/jbd2/jbd2.ko`
- `kernel/fs/mbcache.ko`

## Build Output

- Command: `make image-runner-runtime-image-tar RUN_TARGET_ARCH=x86_64`
- Latest successful log: `docs/tmp/runtime-image-phase2-20260416/build-x86-runtime-image-rerun10-fallback-variable-fix.log`
- Image: `bpf-benchmark/runner-runtime:x86_64`
- Image sha256: `46c6ff7faa915f324be5509f13b6a99961b3c399844acdb4945aa3623bfffc76`
- Tar: `.cache/container-images/x86_64-runner-runtime.image.tar`
- Tar size: `8.8G`
- Build time: `real 1203.75`, `user 7.12`, `sys 7.61`

## VM Validation

- Kernel extract command:
  - `make /home/yunwei37/workspace/bpf-benchmark/.cache/runtime-kernel/x86_64/bzImage RUN_TARGET_ARCH=x86_64`
  - Passed; extracted from runtime image tar with `bpfrejit-install --extract-kernel-only`.
- Minimal VM boot:
  - Booted `7.0.0-rc2`.
  - Guest printed `GUEST_OK`.
  - Guest saw `ext4` in `/proc/filesystems`.
  - `virtme-run` returned 255 after `poweroff -f`, but the guest script completed.
- Full `make vm-micro`:
  - Reached VM runtime container execution.
  - Loaded `bpf-benchmark/runner-runtime:x86_64`.
  - Completed benchmarks `simple`, `simple_packet`, and `memory_pair_sum`.
  - Failed at `bitcount/llvmbpf` with:
    - actual: `12830754992348206170`
    - expected: `3035568289764064166`
  - The actual value matches the current `runner/libs/input_specs.yaml` generator output for `bitcount`; `micro/config/micro_pure_jit.yaml` still has the older expected value. `micro/` is outside this task's allowed edit scope.
  - Log: `docs/tmp/runtime-image-phase2-20260416/vm-micro-rerun10.log`
  - Time: `real 408.70`, `user 132.57`, `sys 777.35`
- Minimal VM micro subset:
  - Command: `make vm-micro BENCH=simple SAMPLES=1 WARMUPS=0 INNER_REPEAT=50`
  - Passed end to end through the same KVM, `bpfrejit-install`, dockerd, `docker load`, and runtime container path.
  - `llvmbpf` result: `12345678`
  - `kernel` result: `12345678`
  - Log: `docs/tmp/runtime-image-phase2-20260416/vm-micro-simple-rerun10.log`
  - Time: `real 330.13`, `user 125.93`, `sys 726.35`

## Session Result Cleanup

- Removed tracked timestamped session results from 2026-04-15 and 2026-04-16.
- Final staged deletion count:
  - Directories: 7
  - Files: 21
  - Blob size: 20.7 MiB
  - Deleted lines in staged diff: 310137
- Deleted directories:
  - `corpus/results/aws_x86_corpus_20260416_055100_560760`
  - `corpus/results/aws_x86_corpus_20260416_070654_516299`
  - `corpus/results/aws_x86_corpus_20260416_074423_869999`
  - `corpus/results/x86_kvm_corpus_20260415_233812_499931`
  - `corpus/results/x86_kvm_corpus_20260416_003638_315881`
  - `corpus/results/x86_kvm_corpus_20260416_015034_325115`
  - `corpus/results/x86_kvm_corpus_20260416_015341_443741`
- Added ignore files in:
  - `corpus/results/.gitignore`
  - `e2e/results/.gitignore`
  - `micro/results/.gitignore`
- Ignore rule: `*_20[0-9][0-9][0-9][0-9][0-9][0-9]_*`
- Keep rules:
  - `!README.md`
  - `!.gitkeep`
  - `!.gitignore`

## Other Verification

- `python3 -m py_compile runner/libs/kvm_executor.py runner/libs/workspace_layout.py runner/libs/suite_commands.py`: passed.
