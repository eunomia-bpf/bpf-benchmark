# Ordinary local ARM memset in native proof inputs

The shared native-ELF memory-runtime preparation tool now selects AArch64
assembler/binutils from the ELF architecture. Its old x86 defaults and exact
x86 assembly remain unchanged. ARM uses a normal local byte-loop function:
return the original destination, write the low byte of the value for the actual
length, and perform no access at length zero. There is no synthetic trip bound.

Undefined memset references become calls to this real local function. Both
the native body and simulator now contain its ordinary instruction semantics.
No special binding exception or verifier-only libc effect is added. The
AArch64 BCC producer preserves entry ABI like the loader and accepts an explicit
prepared native-input directory.

All 23 captured BCC entries generate and compile, preserving all 32 runtime
selectors. ARM full-system Cortex-A72 QEMU and x86 host controls each pass
8,257 cases: offsets 0..15, lengths 0..128, values 0/-1/0x42/0x1234, exact return
pointer and all 192 bytes including surrounding canaries; one extra null-pointer
zero-length control. The x86 assembly is byte-identical to baseline 35d992c3e.

The first test-preparation script had a quoting SyntaxError before CPU execution;
the original source/log is retained. Corrected CPU results and all exact sources,
objects, commands, generated headers, static ARM executable and QEMU initramfs
are in cpu-replay-and-frozen-bcc-inputs.tar.gz. Replaying the built CPU bundle:

~~~sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/embedded-libc-v35/Makefile replay
~~~

Generate a fresh BCC package from prepared native ELF inputs:

~~~sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile bcc-memory-input
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile bcc-real-generate PHASE=bcc-memory-v35 BCC_NATIVE_DIR=/workspaces/repository/corpus/results/kprog_arm64_app_coverage_20261106/bcc-memory-input-v35/native
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile compile PHASE=bcc-memory-v35 COMPILE_ARGS='0 23 1200 1 8192'
~~~

These preparation commands require fresh output directories; immutable completed
attempts remain preserved. The workspace's captured application inventory is
the existing input. Actual standard-module BCC v35 startup is recorded separately;
CPU/compiler checks alone do not claim verifier admission or workload completion.
