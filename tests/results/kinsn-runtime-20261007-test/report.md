# Fixed kinsn lab: make test passed

The completed invocation exited 0 at checkout `9e434b7269cb921b489cfbd6189dca4e40b93990`, using an image built from `f49c60b84`. The intervening commits change results and kprog Lean proofs only; benchmark source matches the image build. The unchanged KVM contract was 8 vCPUs and 64G RAM, with no extra CPU pinning. All 29 native_proof smoke samples matched expected result and retval; the unchecked_packet_read proof was rejected with EACCES as expected; valid_xdp_pass, invalid_opcode, stack_oob_write and uninitialized_register verifier smoke tests passed. There were no failing test names. This target loads the kinsn modules but does not exercise every operation; the kernel/kernel_rejit run remains necessary.

The kernel and 15 x86 module binaries were rebuilt from the fixed source. LLVM and unexercised shared-image app artifacts were reused read-only. Governors before and after were performance; no_turbo stayed 1. The lowest sampled free space during this successful invocation was 17.265 GiB. Two earlier setup/disk failures are preserved separately; the second crossed the disk floor because of concurrent workspace growth, and task-created source/build caches were moved to separate storage before this retry. No workload, Makefile or launch wiring was changed.

Exact command:

```bash
make test PLATFORM=kvm ARCH=x86 JOBS=8 IMAGE_BUILD_JOBS=8 HOST_KERNEL_BUILD_DIR_X86=/var/tmp/kinsn-runtime-test-20261007/linux X86_RUNTIME_KERNEL_IMAGE=/var/tmp/kinsn-runtime-test-20261007/linux/arch/x86/boot/bzImage NATIVE_KINSN_LLVM_BUILD_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn NATIVE_KINSN_LLVM_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/cmake/llvm NATIVE_KINSN_LLVM_TBLGEN=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/libLLVMBPFCodeGen.a --old-file=host-source-apps-x86 --old-file=host-native-bpf-x86 --old-file=x86-runner-runtime-image-tar RUN_TOKEN=kinsn-runtime-20261007-test
```

`metadata.json` records command, exit status, source and environment. `details/result.json` retains merged console output including expected rejection logs. The nested native_proof_micro artifact preserves all samples and progress. Image and module hashes identify the tested artifacts.
