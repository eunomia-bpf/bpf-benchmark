# Actual caller whole-entry reader observations

The original VectorPointerLoopEntry.entry is invoked once. All original resource/postcondition witnesses, provider traces, reached heap, final_i32, other temporaries, caller frame, access and frontier remain in the conclusion. Both original TableInitialized run-store witnesses remain unchanged.

A Reads record collects actual31GPR word/tag pairs,32vector pairs,4arbitrary flag bytes, zero SP/LR and4numeric-base/validity reads on that same reached heap. The separate accepted allocation-independent reader proofs supply these facts from actual resources. No native-state matching or old allocator bridge is assumed.

The public entry query checks the composition. Native input correspondence, original instruction execution, loaded text and universal/global refinement remain separate obligations. Actual direct/focused/full/public logs are retained; CPU17/j1/nice0/32GiB and Lean caps remain fixed, outside timingSH per coordinator2026-11-28T05:43Z during x86 rotate, with formal-full-check exclusion.
