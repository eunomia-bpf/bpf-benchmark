# M5 actual entry reads and concrete NZCV preservation

`Arm64EntryMemory` observes the actual generic ARM dispatcher's entry layout
through the imported Ctypes and memory operations. It follows `cells` and
`tag_cells` through their pointer tables to individually supplied union/tag
locations. The vector pointer arrays are embedded in the entry; each half
then points to its supplied producer location. Borrowed scalar reads follow
the field pointer before loading its value. Kernel proofs check the eight
used field offsets and types, the union's `x` offset and the pointer size
against the actual exported composite environment. No dense register storage
or separately maintained layout is assumed.

Every checked load requires a pointer into a block below the fixed caller
frontier. A failed load, nonpointer or traversal beyond that frontier fails
the query. Successful union loads retain imported pointer/integer/undefined
values; undefined values are never replaced with zero. The query definitions
are proof-side observations, not additional C behavior or benchmark gates.
The raw `FrameBelow` theorem proves equal results before and after a call,
including failure and undefined results. Consequently the entire successful
query domain is preserved. The frontier remains the original caller's
`nextblock`, rather than the increased post-call value.

`Arm64NopEntry.call_preserves_entry` applies those laws to the existing actual
Callstate-to-Returnstate execution, including allocation, the internal width
call and successful local deallocation. It preserves field, borrowed scalar,
GPR/tag, vector and NZCV queries on the actual `ignored.entry` argument.

`FlagsRepresent` is a concrete partial native relation: four successfully
loaded scalar bytes equal the individual LNSym N/Z/C/V bits. The theorem
`call_flags_correspond` preserves that relation across the complete C call
and the checked LNSym/reference NOP step. Its native post-state is the full
input state with PC advanced by four, including all other native fields,
profiles and histories. It needs no opaque heap decoder or decoder-stability
premise. This claim applies to the materialized NZCV bytes only; the existing
full-state heap-decoder correspondence remains conditional.

This step does not prove that a producer's entry satisfies the successful
domain. In particular, the GPR query index names a storage cell, not a proof
of the producer's compact architectural-register mapping. Pointer/native
address provenance, SP/return representation, sparse stack payload and native
memory/permissions, producer admissibility, compiled-label control and
all-behaviors refinement remain M5 obligations. Query stability alone does
not supply these relations. The same conditional NOP correspondence now has
concrete NZCV preservation; complete ISA-handler count remains zero. All
2,065 migrations and O1/O2/O4 recount remain, followed by M6 and final whole
`lake build` / `make check`.

Validation passes all 23 unchanged export modules and ten proof modules in
143 Lake jobs, plus 13 axiom queries and two public type prints. New layout
and frame laws use only the standard Lean axioms; actual call relations also
expose the existing opaque external/assembly semantics. No axioms, admissions,
native checkers or determinism assumptions were added. One intermediate build
found a simplifier side condition and invalid section syntax, both corrected;
the diagnostics remain in raw. Builds used CPU 17, 32 GiB AS and default
recursion/heartbeat limits with `-j1`; queries used CPU 19 and 16 GiB AS.
Canonical C, all export sources, external semantics and frozen benchmark paths
remain exact to `9893cbabb`. No guest, kernel, image, base or compiler changed.
Raw: `/workspaces/kprog-raw/formal/m5-entry-reads`.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64NopEntry
lake env lean -j1 results/m5-entry-reads/Axioms.lean
```

The full focused target list and exit records are in `commands.json`; the
axiom results and public contracts are retained in `axioms.txt`.
