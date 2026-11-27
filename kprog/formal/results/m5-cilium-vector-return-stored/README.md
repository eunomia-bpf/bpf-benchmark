# Same mature vector return/store execution over actual memory

vector_return_body_stored contains the SAME existing four internal steps:
return into the saved call continuation, resume the actual vector assignment,
perform its real store, and resume the original successor. Its actual block,
layout, caller environment binding and successful store evidence are explicit.

The old VectorLocal argument contributed only its block to that execution
proof. The new stored interface removes that old allocator coupling and
does not reconstruct an old producer resource for a different caller.
The original vector_return_body keeps its complete type and delegates ONCE
using localVector.block. All old consumers retain their original interfaces;
no prefix or suffix is re-executed and no evaluator/model/source AST changes.

Compatibility.lean captures the complete original universal type before
the edit and is checked by Lean. Query.lean checks new/old return and
existing input-return interfaces and their actual axioms. validation.json
records exact before/after source, original resource/timing policy and
focused, compatibility, dependent default-root and public-check receipts.

This is a shared execution-body interface, not a completed proof of actual
caller vector stores, all 64 visits, native/loaded-text execution or global/
universal refinement. Actual __5189 layout/allocation is established by the
separate caller vector source step; real store construction and sequential
provider effects are subsequent obligations. Counts and M6 stay unchanged.
