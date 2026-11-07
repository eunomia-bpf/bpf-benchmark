# Native-only trusted service on AArch64

The full-system QEMU control passed: guest exit 0, QEMU exit 0, source program 3, bound native program 8, actual native TEST_RUN return value 2, prebuilt_proof=false. The original BPF control and native fixture both return 2. The application invokes the public REQUIRE_BOUND_PROOF=1 path (with legacy REQUIRE_PREBUILT_PROOF=1 also set by the portable client), submitting only its native ELF/entry/typed metadata. The unchanged common service receives the kernel-owned copy, generates and compiles a fresh AArch64 proof, activates the request capability, loads and verifies the proof, binds the native payload, and completes before the application reopens and executes it.

The compressed successful run includes the kernel request bytes/entry/metadata, queried source facts, fresh source/proof/native artifacts, generation/load logs and completion receipt. Summary pins the Image, module, broker, bridge, worker, portable client, generator and native-link; all recorded input hashes stayed unchanged through execution. The first bootstrap stopped because the retained runtime lacks make, before service registration. That failure is kept separately; the retry invokes Python directly from the host Make target and reuses the already-built binaries.

Reproduce from the retained caches:

```
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-service-arm64-build
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-service-arm64-run
```

Both static/shared ARM loader libraries, service bridge, portable application client and ARM native-link build incrementally in their canonical existing caches. QEMU uses CPUs 20-23, two vCPUs and 2 GiB with the retained v35 root read-only and the new canonical Image/module. No kernel/root/image rebuild or copy was needed. Temporary live state is archived and removed automatically. QEMU time is functional only. This is a small control, not six-application end-to-end acceptance; real Katran is next.
