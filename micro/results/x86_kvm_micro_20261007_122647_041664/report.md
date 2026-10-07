# Fixed kinsn lab: default make micro passed

Default `make micro` exited 0 at checkout `76d76c29b5ab7cb3a77eb063812d02317dbfb8a3`, reusing the runtime image built from `f49c60b84` (benchmark source unchanged). All 29 benchmarks completed for native, llvmbpf and kernel with SAMPLES=3, WARMUPS=0, INNER_REPEAT=100000. All 261 measured samples matched expected result and retval; no benchmark errors were recorded. The unchanged VM was 8 vCPUs/64G RAM, with no extra CPU pinning. This default runtime selection does not execute kinsn; the requested kernel/kernel_rejit run follows separately.

Host governors stayed performance and turbo stayed disabled. Lowest sampled free workspace space: 17.259 GiB. `command-status.json` records exact checkout, command, exit and host snapshots; `runtime-image.json` identifies the compiled image source and hash; details preserve raw samples, progress and console output. No workload, launcher or Makefile edits were made.

Exact command:

```bash
make micro PLATFORM=kvm ARCH=x86 JOBS=8 IMAGE_BUILD_JOBS=8 HOST_KERNEL_BUILD_DIR_X86=/var/tmp/kinsn-runtime-test-20261007/linux X86_RUNTIME_KERNEL_IMAGE=/var/tmp/kinsn-runtime-test-20261007/linux/arch/x86/boot/bzImage NATIVE_KINSN_LLVM_BUILD_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn NATIVE_KINSN_LLVM_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/cmake/llvm NATIVE_KINSN_LLVM_TBLGEN=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/libLLVMBPFCodeGen.a --old-file=host-source-apps-x86 --old-file=host-native-bpf-x86 --old-file=x86-runner-runtime-image-tar RUN_TOKEN=kinsn-runtime-20261007-micro-default
```
