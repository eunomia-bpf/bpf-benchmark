# SUB RSP writeback source draft

`Draft.lean` is **unvalidated**. It is not imported by the proof library and
adds no accepted refinement coverage. No Lean command was launched: the
shared timing lock was busy when this source continuation was prepared.

The draft continues the accepted `X86ProducerSubAfStore` execution from its
post-AF state to the next original header-to-GPR-table read. It retains the
original post-CF heap witness, actual temporary map, current post-AF heap,
six external SUB flag readbacks and caller/other-object/permission frames.
The existing Clight interpreter locates the source boundary; the existing
prefix builder must separately produce a kernel-checked generic execution.
The selected `_cells` read and continuation still require actual validation.

Resume with the focused protocol recorded in
`/workspaces/.agent-state/kprog-lanes/V/writeback-current.json`: direct draft
check, rename that same accepted file, focused library build, public type and
axiom queries, then ordinary commit/push. Keep the original proof/resource
limits and shared timing lock. Correct any failure at the actual source
boundary using fresh log names. No root import or full-suite claim is made.

Raw RSP pointer/tag stores, signed stack release, local freeing, returns,
complete SUB state refinement and all 149 universal operation/dispatcher
goals remain unfinished. The previous full semantic check is recorded in
`../m5-full-check-20261126/`; it does not validate this draft.
