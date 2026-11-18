# M5: actual XZR writer and MOVZ/MOVN call

Register 31 selects XZR in the exported scalar writer. It is distinct from
SP selector 32. `Arm64RegisterWrite.execute_zr_bound` proves all 38 internal
transitions at either width, including the eager SP pointer/value load,
masking and destination/release tests. It returns the exact input memory
at the actual callee continuation. No word/tag store, fresh register cell,
or ordinary `Fin 31` witness substitutes for this path.

`Suffix.writer_call_register` generalizes only argument evaluation to a
64-bit destination selector. The existing `writer_call` statement remains
its ordinary-register projection, with the same 78 transitions. The same
real NONE reader (255) and immediate switch lead to the actual XZR writer
in its genuine `Kcall` context. The scalar suffix takes 119 transitions.

`call_zr_returns` executes the complete nine-argument generic handler in
174 transitions: actual allocation, 54-transition dispatch, scalar suffix,
and real free/return. Every allocated generic local loses both permission
kinds. Allocation/free preserves contents and both permission maps for
all blocks below the original pre-call frontier. The complete memory is
not identified with its pre-call value: the fresh allocation advances its
frontier. `call_zr_represents` transports the GPR/SP/SIMD/NZCV relation over
that original frontier without any register update.

`Zr.native_step`, `reference_step` and `call_corresponds` compose this run
with LNSym's actual checked MOVZ/MOVN execution: W32 columns 0..1,
X64 columns 0..3, all 16-bit immediates, and native Rd31. They use the real
instruction decoder certificate, fetched encoding, legal column condition
and initial no-error state. The entire native wrapper is retained with
PC+4, unchanged histories, no new event and no fault. No local ISA body,
local decoder or assumed step outcome is used.

`Emission.py` audits the live production alias normalizer and encoder at
WZR/XZR for all legal column/opcode pairs. Its 12 actual metadata records
are retained in raw storage; no sampled ISA outcome serves as a proof.
The source literal uses the preceding `Wide.literal` binding and its
modular equation. This does not formally verify Python frontend admission.

Validation and every failed attempt are recorded in `validation.json`.
The normal limits remain 200000 heartbeats and 512 recursion; one worker
on CPU17 (build) or CPU18 (query/edit), 32 GiB address space, timing SH.
Seven public theorem/axiom queries cover writer, raw caller edge, complete
call, final relation and native correspondence. The full Lake build is run
once after the final focused proof. The 23 C exports are compared directly
with reference `9c617740f`. C and runtime remain unchanged; the native
`make check` is not repeated for these Lean-only changes (last complete
PASS `5236c0e9677f635526fdd515cde5195b2ba0810c`).

M5 and M6 remain open. Complete ISA-handler/family count remains **0**.
Next is MOVK's distinct op5 destination-read/immediate/AUX merge and writer
path. Physical memory/origin/alias bindings, actual provider/producer/caller
admission, the enlarged Numeric initialization (frontier 204, distinct from
the old frontier 189), source control and all-family O1/O2/O4 recount remain
open before M6 and fresh final Lake/native checks.

Raw: `/workspaces/kprog-raw/formal/m5-arm64-mov-zr`.
