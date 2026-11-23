# Original logical arithmetic call sites and dispatcher route

The actual ALU arithmetic call-site proof now handles every byte operation
code. It evaluates the original four arguments in2 steps and resumes through
the real return/assignment in3. The existing SHL interface instantiates this
shared source proof and retains its original statement.

The actual SBB/ADC gates select the shared arithmetic statement in3 steps
for XOR/OR/AND/SHL, with the original flag continuation. Existing SHL route
interfaces retain their statements. The logical helpers supply their complete
20-step source executions; caller composition reaches the actual flag stage
in29 steps for XOR, OR and AND, preserving all caller memory and exact
result temporaries. This covers arbitrary pairs of scalar words and all four
operand sizes. Width truncation, flag effects and writeback continue next.

Focused57 jobs and nine public type/axiom queries cover the shared control
proofs, prior SHL interfaces and all logical dispatcher APIs. Limits remain
200000/512,j1,32GiB under shared timing. Runtime and the external specification
retain their definitions. The latest whole confirmation remains the DIV
regression in `m5-xor-full-20261123`; root integration follows this batch.
