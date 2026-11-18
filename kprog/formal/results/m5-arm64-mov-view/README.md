# Final MOV register relation and shift-zero MOVZ

The actual [203-transition procedure](../m5-arm64-mov-suffix/README.md) now
retains the complete GPR/SP/SIMD/NZCV relation after local deallocation, at
the original pre-call reader frontier. `call_represents` compares the actual
word/tag stores with the same stores over the original memory, using imported
raw contents and permission equations. The same producer tables/cells remain
bound throughout. The comparison provides register equations; the execution
certificate is the real Numeric-linked caller's 203 transitions. No standalone
Kstop execution is inserted into that caller.

The paired-store frame retains undefined bytes and both permission maps.
Composing it with the real free frame transports the existing full writer
register contract at the original frontier. It never frames a frontier that
includes freed generic locals. `call_all_behaviors` proves every arbitrary-trace
finite relational execution is a silent prefix of that same represented
return, each stuck endpoint is that return, and infinite execution is excluded.

`Movz.call_corresponds` specializes the actual Clight arguments to ordinary
destinations 0–30, source NONE255, a zero-extended 16-bit immediate and width4/8.
Source2/source3/aux remain arbitrary Clight values. It establishes the register
relation to the **actual** `Reference.AArch64.step` result and its empty new
events/fault. `Movz.reference_step` proves the complete native wrapper state,
including PC+4, preserved histories, extra flags and all other machine fields,
from LNSym's checked step and actual MOV-wide instruction body. Width32 writes
zero-extend, and SP, vectors and NZCV remain unchanged.

The native domain is MOVZ, shift0, ordinary W/X destinations. `fields` only
binds the mature decoded record. A `Reference.AArch64.Instruction` carries the
external decoder certificate; its decoded fields must equal that record,
the actual native fetch must return its encoding, and the native state must
be error-free. There is no local decoder, ISA operation body, assumed step
outcome or native-reflection proof. Closed field guards and width algebra are
proved separately to keep normal kernel limits.

Other halfword shifts, MOVN/MOVK, XZR, native physical memory/alias bindings,
actual producer/provider/caller admission and program control remain open.
The Numeric world's fresh initialized frontier204 remains distinct from the
old Entry/Program frontier189. This is a register-level MOVZ contract, not
whole-program or complete-family coverage. M5/M6 and O1/O2/O4 recount remain
open; complete ISA-handler count remains zero.

C/runtime/benchmark sources and all 23 Clight exports are unchanged. Query
and final validation evidence are in `Query.lean` and `validation.json`; raw
successful and failed attempts stay under the recorded persistent path.
