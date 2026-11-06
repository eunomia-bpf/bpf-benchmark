# Exact source-map identity for ARM proofs

The ARM generator accepts explicit source_map_bindings with native symbol,
source instruction, proof symbol, kind and actual value offset. It emits strong
incomplete-array externs and version1 .native_lab.source_maps metadata. A GOT
load uses the modeled address register and the canonical pointer-write primitive
with map-object or map-value provenance. Missing original map identity now
fails generation; automatic dummy one-element arrays are removed.

The actual captured five-instruction BCC map-value probe compiles through
AArch64 PIC LLVM, native-link proof, ARM simulator and clang BPF. The resulting
BPF is LDDW actual-map-base, ADD16, one8-byte store42 and EXIT. No .maps allocation,
guessed value size or application-map initialization is emitted. Six malformed/
missing identity cases reject; compiled socket/metadata sections remain equal
after those validation additions.

With T d25b4d7f4 loader AND native_lab module, actual full-system QEMU returns
generation1. Source and bound native both write42 at16; all neighboring0xa5
bytes are preserved and binding does not reset the original map. A generated
proof that erases16 rejects at BPF_PROG_LOAD; that candidate is never executed.
The first run's missing libgcc packaging failure remains beside the corrected
runs. All29 original micro cases recompile and pass full-system QEMU against the
matched context-v2 kernel. The first run used the old default kernel and was
stopped during verification; its log remains. Full app runs are still active.

Rebuild via the dated Makefile: source-map-arm64-build PHASE=NEW_NAME then
source-map-arm64-check PHASE=NEW_NAME. Extract replay.tar.gz and run
`make -C runtime run`; on Spark use `make -C runtime run ACCEL=kvm CPU=host`.
The matched built kernel/initrd includes the actual loader/module/artifacts.
The rebuild producer uses source-map-input beside its script; these exact
captured source bytes, IR, bindings and selector are committed independently
of mutable lane-C build directories.
