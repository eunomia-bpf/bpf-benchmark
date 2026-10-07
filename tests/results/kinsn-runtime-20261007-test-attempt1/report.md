# Fixed kinsn lab test: initial setup failure

At source `f49c60b84d184edef144b747934e53bc21c1e6cf`, the kernel (7.0.0-rc2+), 15 x86 kinsn module files, runner, micro programs, proof artifacts, shim and optimizer built. The 8-vCPU/64G VM booted and shut down normally, but `make test` exited 2 before tests ran: the runtime image tar under `/var/tmp` was not visible in the guest. No failing test names or module verifier rejections were observed because the suite was not reached. The host stayed responsive.

The kernel build remains on separate `/var/tmp` storage; the image tar will move to the VM-visible worktree cache before a corrected invocation. The recorded before/after governors stayed performance and turbo stayed disabled. Workspaces free space remained about 22 GiB, above the requested 15 GiB floor. Shared corpus app artifacts and patched LLVM were reused read-only; fixed modules and test/micro components built locally. The only unstaged trackable build change is the generated kernel-offset header source-path comment, excluded from this result commit.

Exact command:

```bash
make test PLATFORM=kvm ARCH=x86 JOBS=8 IMAGE_BUILD_JOBS=8 ARTIFACT_ROOT=/var/tmp/kinsn-runtime-test-20261007/artifacts HOST_KERNEL_BUILD_DIR_X86=/var/tmp/kinsn-runtime-test-20261007/linux X86_RUNTIME_KERNEL_IMAGE=/var/tmp/kinsn-runtime-test-20261007/linux/arch/x86/boot/bzImage NATIVE_KINSN_LLVM_BUILD_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn NATIVE_KINSN_LLVM_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/cmake/llvm NATIVE_KINSN_LLVM_TBLGEN=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/libLLVMBPFCodeGen.a --old-file=host-source-apps-x86 --old-file=host-native-bpf-x86 RUN_TOKEN=kinsn-runtime-20261007-test
```

`metadata.json` records command, source, exit status and environment. `details/result.json` preserves merged stdout/stderr for the VM failure; the local `.log` is ignored and is not committed. Direct redirection allowed vng to overwrite the earlier build stream; the retry supervisor will capture output through a pipe. The module/kernel hash manifest preserves built-artifact provenance.
