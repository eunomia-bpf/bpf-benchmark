# Actual scalar register writer

`Arm64RegisterWrite.write` executes the actual exported
`Arm64Program.f_kprog_arm64_program_write` in the linked producer environment.
For every ordinary destination `Fin 31`, arbitrary 64-bit input and width 4 or
8, it derives successful stores from `ProducerRegisterStorage.Storage` and
proves all 67 internal Clight transitions through function entry, the eager SP
read, width masking, destination guards, word store, tag clear and return.
Source components are extracted from the export and checked by a definitional
body equation. Unexecuted SP alternatives remain opaque. No replacement C body
or instruction interpreter is introduced.

Width 4 zero-extends the low 32 bits into a full Mint64 store. Width 8 retains
all bits. The following Mint8unsigned store clears the scalar tag to zero.
`Result.word` and `Result.tag` prove both readbacks. The same result retains the
two successful stores, exact caller bytes and both permission maps below the
original producer frontier, the complete access map and unchanged nextblock.
`Result.other_cell` preserves all loads from every other register cell;
`Result.local_load` preserves loads from differently named actual allocated
locals, including header, pointer tables, SP, flags and vectors when their real
bindings and distinct names are supplied.

The kernel checks the symbolic execution at the normal 200000-heartbeat and
512-recursion limits. The proof composes individual imported `doStep_sound`
transitions. Finite guard/index/layout facts use kernel `decide`; the raw
interpreter count query only selected the count and is not proof evidence.
Public theorem types and axioms are recorded by `Query.lean`; full validation
and retained exploratory attempts are in `validation.json`. All work uses the
shared timing lock, CPU 17 for builds and CPU 18 for queries/publication, one
Lean worker and a 32 GiB address-space limit.

This is a standalone actual procedure boundary. The caller edge, preserved
borrowed-entry storage and mature native GPR-update relation are the next M5
step. SP/XZR destinations, other widths, pointer writes, native physical alias
admissibility, architectural memory/events/faults/control and full instruction
handler correspondence remain separate. No producer-pause/continuation edge is
invented. Complete ISA-handler refinements remain 0; M5 and M6 remain open.
The C sources and frozen runtime/benchmark paths are unchanged, so the native
primitive checks were not repeated for this Lean-only step. M5/M6 closure still
requires a fresh full `lake build` and `make check`.
