# Actual caller eight stack-tag initializers

The source certificate unfolds the original caller continuation immediately after its 64 vector input/store visits. Exactly eight original byte assignments initialize the actual uchar[8] local, then control reaches the original signed64 SP-zero statement. This module does not assert SP execution or whole-entry composition yet.

Storage is derived from the same actual 795-local caller allocation with a real binding, fresh block and writable range. It does not reconstruct the older producer's uchar[24] allocation. The actual original pointer expression has unsigned offset i for all eight indices. Each three-step sequence performs a real CompCert byte store, establishes its zero readback and preserves every other tag byte and every other declared local load. List induction composes all eight assignments into 24 genuine internal steps on the same temporary environment, with caller memory, permissions and allocation frontier preserved.

Six root queries check the source, offsets, storage, general execution body, actual bound continuation, and next SP source; their axiom lists allow only standard Lean and existing CompCert external semantics. Focused and default full builds use the original limits. The failed first check is retained: arithmetic simplification and noncomputable source identifiers were repaired without changing source statements or limits. The accepted second-stage bytes are the canonical module.

This advances M5 source-prefix migration. Native BL, loaded text, global or universal refinement, whole-P coverage and M6 are open. Runtime, captured frontend exports and benchmark evidence are unchanged.
