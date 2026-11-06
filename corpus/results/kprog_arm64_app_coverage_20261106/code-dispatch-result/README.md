# Finite ARM code-address dispatch on the native path

Native-link now relocates local ADR code addresses to the exact final linked
instruction, including shifts from expanded helper calls. ADR-referenced
subprograms join the reachable symbol set. A separate CODE mode reuses the
existing CFG target analysis, joins both branches and kills unknown, narrowed
or call-clobbered values. Proven finite BR/BLR sites retain their actual native
instructions; no comparison sequence alters flags. The generated simulator
uses its existing value/tag switches for those finite targets.

All76 Rust tests and both host/ARM release builds pass. Four actual source,
simulator and bound-native QEMU controls select both37/41 targets through BR
and BLR, return2 and report generation1. Each includes a real helper call
before the ADR sites. All eight final ADR targets are checked against their
actual MOV37/MOV41 instructions after helper expansion. Three unknown,
truncated and helper-clobbered targets reject before any native blob is written.
The first two negative-check attempts used the wrong CLI input or diagnostic
substring; their raw failures remain. No unsafe candidate was executed.

The replay archive includes exact assembly/ELFs/proofs/simulators, frozen
headers, raw checks and the built matched kernel/initrd. Extract and run
`make -C runtime run`; on DGX Spark add `ACCEL=kvm CPU=host`. Rebuild with
`make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile code-dispatch-build PHASE=NEW_NAME`,
then `fmov-bank-check PHASE=NEW_NAME KERNEL=/path/to/matched/Image`.

This increment covers same-function branches and ADR-selected subprogram
calls. ADRP/table-derived code pointers, internal call/return extent handling,
numeric address planes and whole-program certificates remain active repair
and validation obligations. It does not claim complete six-app execution.
The replay target now writes its tar outside the input directory before
moving it in; this fixes the retained first-create directory-mtime failure.
The v6 runtime retirement inventory records that only the successor v7 root
and image remain after committing all old raw evidence and exact payload.
