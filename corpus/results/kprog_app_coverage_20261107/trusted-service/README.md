# Kernel-backed trusted service, x86-64

The actual kernel queue -> fresh native-link -> x86 renderer -> Clang -> authenticated loader -> verifier/binding -> application WAIT -> native TEST_RUN control passes. The application supplies only its native ELF and entry; both REQUIRE_BOUND_PROOF=1 and REQUIRE_PREBUILT_PROOF=1 are set, and the result reports prebuilt_proof=false. The fixture returns2. This is component acceptance; BCC, OTel, Cilium, Tetragon, Katran and Tracee application-level acceptance on this new service remains in progress.

| Check | Inputs/cases | Generated | Compiled | Kernel accepted | Native executed |
|---|---:|---:|---:|---:|---:|
| Native-only kernel/service control |1|1|1|1|1|
| Actual BCC vfsstat entries, direct-value bases0/8 |2entries/3cases|3|3|not run|not run|
| Metadata spoof/duplicate/shape/context/ABI regressions |8|n/a|n/a|n/a|n/a|

summary.json pins the exact kernel, module, native input and client. requests/1.success.tar.gz retains the kernel-copied spans, normalized kernel facts, generated C/native-proof/BPF objects, command logs, kernel-link artifacts and source/tool hashes. The first missing-clang PATH failure is retained compressed; the guest now explicitly uses LLVM18. control-logs.gz retains command output. No timing interpretation follows from functional CPU12-15/2GiB execution.

Commands from the repository root:

```
make -C kprog/libnativeloader trusted-service-check
make -C kprog/libnativeloader trusted-worker-check
make -C kprog/libnativeloader trusted-service-kvm
```

The KVM target reuses kprog/tv/build-kernel-x86 and build-x86. The Rust linker uses the shared incremental native_link/target build. No clean rebuild, second source tree, image replacement or application workload change was used. The service CLI is kprog/trusted_service.py; it registers once before applications and accepts requests only through its kernel capability FD.

Trusted map externs represent the native symbol's already-bound address: a map handle or a direct map value including the capsule's nullable base offset. Generated instruction/ELF addends are relative to that symbol. The x86 renderer reuses its existing source_pointer annotation; it emits no runtime lookup/check and fabricates no source instruction index. T owns the loader's corresponding map-ID relocation and kernel binding; application BCC integration follows that change. Historical application-prebuilt proofs are not acceptance evidence for this service.
