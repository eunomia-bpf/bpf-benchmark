# D1 survives the actual ADD-SP prefix

The original-entry correspondence now exposes the MOV/MOVK D1 word and scalar tag at the final heap after ADD-SP. Both observations follow from the existing Kept2 evidence and the original pairWord/pairTag, with no new input or successful-load premise. All original provider traces, three real frame releases, native steps, storage, frontier and warm-cache evidence remain.

Kept.cell_load proves equality of arbitrary raw chunk/offset loads for any register outside the selected destination, including failed loads. Its actual before/after blocks are identified by the same typed canonical allocation bindings; name separation follows from existing Storage.cells_distinct. No new cell semantics or finite axiom.

The strengthened component build passed (255 jobs,323.658s); two public type/axiom queries passed. Exact hashes, timings and raw evidence are in validation.json. Only standard logic and inherited CompCert external/inline semantics occur, with original default proof limits and no admission or new axiom. The first finite attempt failed a projection rewrite, fixed by giving the block equality its explicit result type.

This supplies the actual LHS storage evidence needed by the fourth ADD-register instruction; it does not prove that complete handler/native correspondence. Whole-library confirmation and M5/O1/O2/O4/M6 remain open; complete ISA families0. No applications, runtime tests or measurements.

Whole-library/root confirmation passed: full2,306 jobs58.314s; import KProgFormal and both public type/axiom queries passed at explicit -j1, inherited axioms only. Source hashes match full2-source-hashes.json. Raw full2/public-d1-root1 evidence in validation.json; complete fourth handler/native and M5/M6 remain open.
