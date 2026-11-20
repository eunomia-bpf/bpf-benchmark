# Actual body SP/NZCV setup

`Arm64ProgramEntryBody.setup` executes the actual five-store prefix in the linked fixture: SP=-32, then N=mark&1, Z=priority&1, C=hash&1 and V=(hash>>1)&1. Its 27 silent transitions end at the original first MOV_IMM statement, with exact signed-SP/byte-flag readbacks, updated compiler temporaries and unchanged context temporary. Store success follows from allocated local permissions, rather than a post-state assumption.

Three original-context Mint32 loads at the imported __sk_buff offsets 8/32/68 supply the values. A real caller block and its frame preserve these loads through every local store; native-input provider outputs are not substituted for context data. The result retains caller bytes/permissions, other-local loads, access map and frontier. Native register-state/ABI transport and original context/native memory admission remain separate obligations.

Source statements and successors are cached from the imported actual AST and checked by small equations. The existing reached-body definition caches its source constructor; its production spine and prefix correspondence are rechecked. Original proof caps are unchanged. The source-equation retries in the raw record isolate deep normalization into smaller equations; integer and byte casts use imported semantics.

Focused 196 jobs and 14 public type/axiom queries pass on CPU17, one worker and 32 GiB address space. Imported execution axioms remain visible in validation.json. Whole proof-library confirmation is pending. C/runtime/toolchain/benchmark sources are unchanged.

Next transport the established borrowed storage and architectural relation through these five writes, then admit the actual first MOV_IMM with SRC=SP32 and the following MOVK with unrestricted u32 priority. Actual native/context ABI and final return, other families, the recount and M6 remain open.
