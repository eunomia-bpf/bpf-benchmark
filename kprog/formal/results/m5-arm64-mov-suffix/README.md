# Actual MOV-immediate scalar procedure

This M5 step continues the actual Numeric-linked generic handler from the
[dispatch prefix](../m5-arm64-mov-immediate/README.md). Its domain is opcode 1,
width 4 or 8, ordinary destination 0–30, SRC=NONE (255), a full immediate word,
and the same allocation-bound producer storage. Source2, source3 and aux
remain arbitrary Clight values. Native decoding/operand admissibility remains
an instruction-correspondence obligation.

`Arm64MovImmediate.read_none` (from `Arm64ReadNone.lean`) proves the
actual `program_read` procedure returns zero in 55 internal transitions for
NONE. It loads no entry field and preserves all memory, for arbitrary world,
entry value and continuation. The caller still performs its real pointer and
integer ABI casts; a direct callee theorem does not remove those casts.

`Suffix.writer_call` proves 78 actual transitions: five to the real reader
call, its 55 transitions, and 18 through return, immediate selection and the
real writer call. The actual Kcall continuation and all changed temporaries
are retained. `execute_stores_bound` generalizes the existing 67-transition
writer to a real caller continuation and an environment with equal composites.
Its final transition uses the imported relational skip-call rule. The old
standalone writer API is the Kstop projection, with its statement unchanged.
`Suffix.scalar_write` then proves 148 transitions through both scalar stores
and return to the generic handler's end statement.

`Storage.frame` carries the same tables, cells, SP, flag and vector roots
through actual allocation. Successful imported loads and writable permissions
supply their block bounds. `call_returns` composes the 54-transition dispatch,
148-transition scalar suffix and actual local-frame free into 203 transitions
from the real nine-argument call to the void return. Both successful stores
and their common writer result are constructed from those same write rights.
The final free derives Freeable permissions from allocation and unchanged
access, releases the real ranges, and frames every pre-call block relative to
the memory **after** the register stores. It preserves contents and nextblock;
it does not claim the modified register cells were unchanged by the call.

The source C, exported ASTs, runtime and benchmark are unchanged. The existing
writer result still supplies the full intermediate GPR/SP/SIMD/NZCV relation
against LNSym public register write. This step does not yet transport that
relation across generic-frame freeing at the original reader frontier, prove
the native MOVZ/MOVN/MOVK step and PC update, initialize the enlarged Numeric
world, or close provider, physical memory, events, fault and program-control
obligations. M5/M6 and O1/O2/O4 remain open; complete ISA-handler count is zero.

`Query.lean` checks the public types and axioms. `validation.json` records
focused attempts, final checks and retained raw logs. Concrete replay counts
are metadata only; the symbolic procedure is proved over imported Step2.
