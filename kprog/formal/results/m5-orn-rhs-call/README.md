# Actual ORN modified-RHS call and return

The proof extracts the original ORN RHS call, copy and numeric suffix from
the generated Clight AST. Its actual entry decodes AUX65792 into modifier1
and shift1, casts the original entry/source2/width4 arguments and resolves
the linked modified helper. Three entry transitions, 119 original helper
transitions and four return/copy transitions yield the low32 bits of the
source word shifted left once, in the original RHS temporary.

The composed 126-step path uses actual pre-memory header, table, word and
tag loads. The entire heap and caller environment are preserved. The proof
also retains every original input, the real operation temporary and LHS.
The focused numeric-component build includes and accepts this RHS module
(264 jobs); five public type/axiom queries pass. Original 200000/512 caps,
CPU17, one worker, 32GiB and shared timing lock are used. Queries record the
existing Clight external-function/assembly assumptions and standard logic.
V coordinates whole confirmation; full ninth-call/native composition
continues after numeric and writer integration. Raw evidence:
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
