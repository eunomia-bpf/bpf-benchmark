# Fixed kinsn lab test: disk stop

At revision `aadeb1948468b9bbea4befda283aff25130d9a0b` (benchmark image built from `f49c60b84`), the corrected invocation booted its 8-vCPU/64G VM and reached runtime image installation using the VM-visible worktree tar. The disk supervisor observed free `/workspaces` space drop from 16.59 GiB to 12.65 GiB and terminated the make process group with SIGTERM. The host remained responsive, and no VM remains. Tests did not begin, so no correctness or kinsn speedup result is claimed.

The initial visibility failure was pushed as `aadeb1948`; its image tar was copied unchanged into the worktree. This attempt reused that image and did not rebuild components. Disk growth elsewhere exhausted the margin; only files created for this task may be reclaimed. The next invocation waits for free space above 15 GiB. No launcher/workload changes were made. Before/after CPU governors stayed performance and turbo stayed disabled.

Exact command:

```bash
make test PLATFORM=kvm ARCH=x86 JOBS=8 IMAGE_BUILD_JOBS=8 HOST_KERNEL_BUILD_DIR_X86=/var/tmp/kinsn-runtime-test-20261007/linux X86_RUNTIME_KERNEL_IMAGE=/var/tmp/kinsn-runtime-test-20261007/linux/arch/x86/boot/bzImage NATIVE_KINSN_LLVM_BUILD_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn NATIVE_KINSN_LLVM_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/cmake/llvm NATIVE_KINSN_LLVM_TBLGEN=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/libLLVMBPFCodeGen.a --old-file=host-source-apps-x86 --old-file=host-native-bpf-x86 --old-file=x86-runner-runtime-image-tar RUN_TOKEN=kinsn-runtime-20261007-test
```

`metadata.json` preserves command, revision, exit code and disk-stop snapshot. `details/result.json` retains the merged console output.

Disk recovery after this stop: the pristine kernel/LLVM source copies initialized by this task and its generated compiler caches were preserved under task-owned `/var/tmp/kinsn-runtime-test-20261007/preserved-caches`. The original worktree paths for the two source submodules were left empty; no external checkout or git history was changed. About 4.8 GiB was recovered, bringing free space to about 18 GiB. The completed runtime image still contains the fixed modules and all test/micro artifacts, so Make can reuse it without those host caches. See `relocated-caches.json` for paths.
