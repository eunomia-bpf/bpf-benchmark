# M5: actual MOVK dispatch, destination read and merge

MOVK is opcode 5 and follows its own branch. `Dispatch.Keep.call_dispatch`
executes the actual nine-argument generic call through allocation, the
width procedure and the NOP/ADRP/MOV/MOVK decisions in 27 transitions.
The old MOV path selector is bypassed. The prefix preserves contents and
both permission maps below the original caller frontier.

`Arm64MovKeep.call_read` extends that prefix to 32 transitions, ending at
the actual combined reader call on DST in its real `Kcall` context. It does
not skip or assume that read. SRC/SRC2/SRC3 remain arbitrary unused values;
entry, raw destination, 16-bit immediate and AUX column are bound explicitly.
All symbols resolve in the already linked Numeric environment.

`after_read` proves 26 actual Clight transitions from the reader's returned
`Vlong old` and post-memory to the writer statement. Every 64-bit old value,
16-bit immediate and column 0/16/32/48 is covered. The source AUX extraction,
mask switch, insertion, final value assignment and loop exit are executed.
This suffix preserves the exact memory supplied by the reader. It does not
identify a reader's post-memory with its input memory.

`merge_eq_partInstall` relates the source mask/shift/OR expression directly
to LNSym's public `BitVec.partInstall`; it uses kernel-checked bitvector
lemmas, with no local ISA body or native-reflection axiom. The expression
proof is split at its actual left/right operands, and actual temp getters
are cached explicitly to stay within the normal recursion limit.

`writer_call` adds the real writer edge, making 27 transitions from the
reader return to the internal writer call with the merged value and actual
caller continuation. `zr_writer_call` composes the real DST31 reader's
55 transitions, deriving zero and unchanged memory, into an 87-transition
branch-to-writer execution. It supplies no assumed read result.

These are source prefix and merge contracts. The writer's subsequent stores
or no-cell return, generic free/return and checked MOVK native-step composition
remain next. For ordinary destinations, the complete reader must execute in
the same linked environment and continuation and derive its returned scalar
value and actual post-memory. A register `ValueRep` may hold a `Vptr`; it does
not by itself prove the `Vlong` return required by this bit-operation suffix.
Relative-origin/cache cases and pointer admission remain explicit. Native
W32 MOVK allows only columns 0/16; these source merge lemmas cover all four
columns and do not claim native legality for W32 columns 32/48.

`Emission.py` captures 24 actual live normalizer/encoder metadata records for
ordinary and zero destinations, both widths, legal native columns and the
immediate boundaries. The records retain distinct `ARM64_OP_MOVK`, unshifted
immediate and `ARM64_AUX_MOVK(shift)`. This is a source metadata audit, not a
sampled ISA oracle or a formal proof of Python frontend admission.

Validation and all failed attempts are in `validation.json`. One focused
proof worker uses CPU17; queries/edits use CPU18, 32 GiB address space,
200000 heartbeats and 512 recursion, with every host command under timing SH.
Eight public type/axiom queries cover the source boundaries, actual zero
read and library insertion equation. Full Lake runs once after focused
proofs pass. The 23 exports are compared directly with `9c617740f`.
C/runtime remain unchanged; native `make check` is not repeated for this
Lean-only step (last complete PASS `5236c0e9677f635526fdd515cde5195b2ba0810c`).

M5 and M6 remain open; complete ISA-handler/family count is **0**. Actual
frontend/provider/producer/caller admission, physical memory/alias/origin,
Numeric frontier204 initialization distinct from the old189 world, source
control and all-family O1/O2/O4 recount remain before M6 and fresh final checks.

Raw: `/workspaces/kprog-raw/formal/m5-arm64-mov-keep`.
