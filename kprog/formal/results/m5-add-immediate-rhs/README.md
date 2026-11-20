# ADD_IMM RHS in the original generic handler

Arm64AddImmediate.rhs_from_handler checks the exact structural route through
the original generic function's NOP, ADRP, MOV, MOVK and ALU constructors to
its exported RHS loop. The proof uses that existing loop and original
statements, with no substitute handler body.

The real Numeric selector for opcode3 returns byte1 in 20 internal transitions.
The linked symbol and unchanged definition are checked at block100. rhs_bound
composes the actual call entry, those 20 transitions, result installation,
conditional selection, immediate assignment and loop exit in 29 transitions.
It applies in any world with the real selector binding; Linked.rhs instantiates
the one actual fixture/Program/Numeric world. The immediate has arbitrary64
bits, the call continuation and memory are arbitrary, and only the actual op,
immediate temporary and unshadowed function binding are required.

This proves the exported conditional selects IMM without evaluating SRC2 or
its modification loop. There is no entry-validity, SRC2-value, cache/provider
or memory-success premise. It corrects the earlier handoff's inference from
the runtime macro argument list. The following exported ALU result is an inline
switch (statement17); its arithmetic and selected pointer write remain next.

Focused checking passes 227 Lake jobs and five public type/axiom queries at
original200000-heartbeat/512-depth caps, CPU17, nice0, one worker, 32GiB address
space. Only standard logical axioms and inherited external/assembly relations
appear. Whole `lake build KProgFormal` confirmation passes 290 jobs including the root,
on CPUs16–23, nice19, one worker and 32GiB address space. Raw diagnostics:
/workspaces/kprog-raw/formal/m5-add-operands.

This is a source fragment proof with checked original-body provenance.
Opcode dispatch from generic entry, LHS read, tag/arithmetic/write, allocation
and free, original source continuation and fetched LNSym ADD composition are
still open M5 work. O1/O2/O4 and M6 remain open; completed ISA-family count0.
