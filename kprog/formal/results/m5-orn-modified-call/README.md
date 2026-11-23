# Actual LSL1 helper entry, scalar read and return

The five original arguments bind entry, register index, modifier1, shift1
and width4 in the real modified-register helper. Its complete 119-transition
execution derives the scalar value from the actual entry/table/cell/tag
loads, runs the checked 41-step modifier and executes the original output,
loop exit and function return. The entire incoming heap is preserved.

The statement accepts the actual pre-memory pointer/cell/tag observations
and imported layout, and derives the returned (value << 1) & 0xffffffff.
Function entry keeps the original empty local environment. Scalar reading
reuses the existing Read.scalar_bound proof, and modifier execution reuses
the original source body and new LSL1 theorem. Return evaluation uses only
the reached output observation supplied by that execution.

Focused build 238 and one public type/axiom query pass at original
200000-heartbeat/512-depth caps, CPU 17, one worker, 32 GiB and shared timing
lock. The prior LSL0 helper also recompiles as a dependency. Standard logic
and inherited external-function/assembly assumptions appear in the query.
The next proof connects this callee to the real ORN source call site, then
numeric calculation and writeback. The complete original program frontier
currently reaches eight calls. V coordinates whole confirmation. Raw evidence:
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
