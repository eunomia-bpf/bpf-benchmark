# M5 ARM SP and pointer reader views

The existing `Arm64RegisterReads` proof now covers the actual exported
`kprog_arm64_program_pointer` function for every GPR index 0–30. It shares
the raw/tag execution proof, with the actual union pointer-field offset and
pointer-sized load checked against the export. Each call takes 28 internal
transitions and preserves the exact loaded `Vptr` or `Vlong` representative,
complete memory and existing `ValueRep` binding. Existing raw/tag contracts
remain unchanged.

SP uses the actual C selector 32. The raw and pointer views each take 21
internal transitions, following the borrowed signed-long pointer at the
actual entry offset 40. Both return its same 64-bit relative offset. The
pointer cast does not invent a native physical address or a new Clight block.
The native SP correspondence retains the explicit invocation stack origin:
`nativeSP = offset + origins.stack`.

The SP tag view takes 15 internal transitions and returns STACK (4), with no
memory-read or entry-validity premise at its Callstate boundary. This is the
actual constant C branch; it does not fabricate an SP value. The executable
law covers every entry value, memory and continuation. The return law covers
every proposed top-level trace, result and complete memory.

The pointer-GPR and both SP value-view return laws likewise cover every
proposed return at `Kstop`, with empty trace and complete memory unchanged.
They use the existing register relation, M3 materialization and internal-run
uniqueness; no external determinism assumption or new semantics is added.
A small common projection of the existing endpoint theorem serves these
return proofs. Pointer-chunk normalization uses the imported target ABI;
pointer arithmetic operations and default proof limits remain intact.

These are C-reader component laws, adding zero complete ISA-handler
refinements. Actual producer initialization/compact maps/tag/cache/native
origins, full `program_read`, cold materialization, native memory and general
compiled control remain M5. All 2,065 migrations and O1/O2/O4 recount, then
M6 and final whole-package checks, remain. Canonical C and exports are
unchanged in this proof step.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64RegisterReads
lake env lean -j1 results/m5-sp-pointer-reads/Axioms.lean
```

All 23 exports and fourteen proofs pass 162 Lake jobs. Six axiom queries and
four public type prints pass. The executable SP tag law uses standard Lean
axioms only; relational laws additionally expose the existing opaque external
and assembly relations, without their determinism assumptions. Source comparison
to `93786f135` passes for C, exports, imported semantics and frozen paths.

Commands and output are retained here. Builds
use CPU 17, 32 GiB AS and `-j1`; queries use CPU 19 and 16 GiB AS. Raw logs
stay at `/workspaces/kprog-raw/formal/m5-sp-pointer-reads`.
