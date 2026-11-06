# Preserve ARM stack provenance through SUB

The real helper113 startup proof rejected because SUB x0,x8,#7 converted a
STACK-relative source into a scalar. The new64-bit STACK-only SUB path uses
the existing pointer-add primitive with the negated operand. Existing ADD
routing, packet SUB scalarization and SP writeback semantics are unchanged.
The generated contract and independent full-state handler specification now
include this branch; the explicit -8 minus7 example retains STACK and -15.

Focused Lean checks, all336 handler predicate cases and all21688 operand/select
route cases pass. The shared full check passes all356 Lean modules and the
C/Rust/wire checks; its unchanged raw log and exit status are retained. Initial
focused attempts, including a wrong Lean target spelling, remain in the logs.

Both actual source/simulator/generation-bound QEMU controls pass. A native
32-byte frame saves X19/LR and puts value37 at SP+16; ADD then SUB selects that
slot for the real probe_read_kernel helper. Source and native both zero it,
return2 and report generation1, in stripped and preserved entry-ABI modes.
No unsafe old one-byte source-lifter frame is used. That separate allocation
repair remains required before regenerating the failed BCC startup artifact.

The replay archive contains exact assembly/native proof/source/simulator
inputs, frozen simulator headers, compiled objects, raw results and the built
matched kernel/initrd. Extract it and run `make -C runtime run`; on DGX Spark
use `make -C runtime run ACCEL=kvm CPU=host`. Rebuild with the dated Makefile's
`entry-abi-build PHASE=NEW_NAME ENTRY_ABI_ARGS=sub`, followed by
`fmov-bank-check PHASE=NEW_NAME KERNEL=/path/to/matched/Image`.
