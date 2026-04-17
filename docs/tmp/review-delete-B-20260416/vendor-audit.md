# Vendor Audit - Review B

## Kept

- `vendor/linux-framework`: active kernel worktree used by the top-level build and VM flows. The current repository has a pre-existing gitlink for this path without a matching `.gitmodules` entry, so `git submodule status` still reports that mapping problem.
- `vendor/llvmbpf`: still referenced by the micro configuration and runner build paths for the LLVM BPF JIT toolchain.
- `vendor/libbpf`: still referenced by runner build logic, CMake inputs, and tests; keep.
- `vendor/bpfrejit_x86_defconfig` and `vendor/bpfrejit_arm64_defconfig`: still referenced by the top-level `Makefile` and container build flow; keep.

## Removed

- `vendor/bpftool`: no current build path uses this submodule. The active bpftool source is under `vendor/linux-framework/tools/bpf/bpftool`; the stale micro config metadata was removed.
- `vendor/linux`: no current build or test path outside historical docs/results depends on this submodule. Removed with `git submodule deinit -f` and `git rm -f`.
- `vendor/linux-baseline`: no current build or test path outside historical docs/results depends on this submodule. Removed with `git submodule deinit -f` and `git rm -f`.

## Documentation Drift

- `docs/kernel-jit-optimization-plan.md` still contains older wording that names `vendor/linux` and `vendor/linux-baseline` in the branch layout. That file was intentionally not edited because it is outside the allowed write scope for this pass.
