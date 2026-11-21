# Fetched native ADD from SP

Arm64AddImmediateNative binds mature Add_sub_imm_cls fields for 64-bit ADD
from SP to any ordinary destination, all twelve-bit immediates and both
unshifted and twelve-bit-shifted forms, with flags disabled. Operand formation
is decoded metadata; execution reuses DPI.exec_add_sub_imm and LNSym's
carry-zero AddWithCarry theorem. It defines no local ISA interpreter.

native_step requires the actual fetched word, no incoming model error and the
Instruction.valid external-decoder certificate. reference_step identifies the
full resulting machine, actual PC+4, empty event delta and no fault. Memory,
permissions, all other registers/flags, prior histories and extra state are
retained through the mature native update.

pointer_update connects physical SP=rawOffset+stackOrigin to the existing
pointer-writer update with payload rawOffset+immediate and STACK4 tag, using
wrapped addition algebra. It adds the invocation origin exactly once. This
representation identity does not assume a new native result or replace the
fetched step proof.

Focused checking passes 228 Lake jobs and four public type/axiom queries at
original200000-heartbeat/512-depth caps, CPU17/nice0/one worker/32GiB address
space. Native statements depend only on standard logical axioms. Whole-library
confirmation follows at batch end; raw /workspaces/kprog-raw/formal/m5-add-dispatch.

The matching full Clight ADD call, generic frame/free, original source successor
and native composition remain M5 work. W/S/SP-destination variants and the
remaining handlers still need correspondence. O1/O2/O4 and M6 remain open;
completed ISA-family count0.

Batch confirmation (2026-11-21): `lake build KProgFormal` passed all 294 jobs
in 30.436 seconds, with the root artifact at 2026-11-21T15:24:43.564922+00:00.
CPUs16-23/nice19/one worker/32GiB AS; native tools/executables excluded.
This confirms the three changed proof steps together; no complete handler
count, O1/O2/O4 recount, final default Lake build or make check is claimed.
