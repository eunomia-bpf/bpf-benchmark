# Actual logical ALU helper execution

The original `x86_alu_result` helper executes each XOR, OR and AND switch arm,
assigns its real result, exits the original switch/loop and returns the exact
full64-bit word in20 steps. The result holds for every pair of input words,
every byte-valued width, arbitrary continuation and complete caller memory.
The width-specific truncation belongs to the following caller/flag stage.

One shared execution proof supplies the three public operation statements.
The imported source and external x86 specification retain their definitions.
Focused54 jobs and three type/axiom queries check these helper APIs. Flags,
writeback and complete native handler composition remain the next steps.
Original200000/512 budgets,j1,32GiB and shared timing are retained. Complete
whole-check status is recorded in `m5-xor-full-20261123` (DIV regression).
