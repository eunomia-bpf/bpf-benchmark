# Actual SP preindex writer execution

This step extends the existing Arm64PointerWrite module with execute_sp_store_layout and instantiates it in Arm64CiliumCallerSPWriterExecute. It reuses the original private writer source decomposition, function entry checks and Clight step rules. It adds no writer model or copied procedure body.

The caller wrapper constructs SPWriteMemory.Store from the same actual 795-local allocation rights and initialized header. It supplies the same original and preserved header SP pointer, original SP zero, and the derived Mint64 store of -32 to the generic execution theorem. The returned witness retains the actual new borrowed SP read, initialized header pointers, all other blocks, caller frame, access and allocation frontier.

The candidate theorem states 42 actual internal helper steps for reg32/tag4. The original eager SP read, direct SP assignment, signed release comparison (-32 > 0 is false), loop breaks, empty-local release and original continuation remain in the source path. The step count and complete reduction are accepted only by the recorded Lean checks; preparing this README is not a validation result.

Validation is ordered: first rebuild the modified generic module, then check the caller draft, move its exact checked bytes to the canonical module, focused build, full root build, and three root-imported check/axiom queries (layout, execute, and the generic execution theorem). validation.json and the complete compressed logs record the actual outcomes. Publication uses a private index, normal hooks and normal push, followed by origin ancestry, peer staged patch equality and cumulative owned-path audit.

The original generic module bytes and both candidate snapshots remain in the raw directory. Before its first build the new docstring was moved below its local hygiene directive; the earlier unchecked snapshot remains. Existing module options were retained; no proof budgets or warning suppressions were added.

This step covers the helper body after the actual linked call boundary. Transport of the whole entry execution and provider trace into the linked global environment remains open. It establishes no whole native instruction, loaded text, whole program, global or universal refinement. The captured C/export and current runtime header remain distinct artifacts.

Resource authority is the coordinator's 2026-11-28T05:43Z CPU17 exemption outside the timing lock during the operator's x86 rotation. Lean keeps one worker, nice0, 32GiB address-space, existing heartbeat/recursion settings and the separate nonblocking exclusive full-build lock.

The first generic build failed at the actual SP assignment because the reducer unfolded integer representation in the store target before matching the local store fact. Its complete generic1 log and receipt/source hash are retained. The second candidate normalizes stored and newSP by the same representation equations before step reduction. Caller stage1 was not started by the failed generic build. No statement, source body, proof budget or warning option changed.

The normalized generic2 module passed its 178-job build without changing the candidate's 42-step statement. The first caller check then reached the existing 200000-heartbeat limit in its layout declaration using constructor/decide. Its stage1 log, receipt and source hash remain. Caller stage2 retains the same eight actual layout equalities and supplies Eq.refl terms for kernel checking, following the existing linked-program lookup proof pattern. This removes the expensive tactic-side decision construction; it adds no layout premise or proof-budget setting. Generic2 is retained and is not rerun by the next direct caller check.
