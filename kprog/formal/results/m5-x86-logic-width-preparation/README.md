# Complete original logical flags width preparation

The original branch now executes all three real helper calls: effective
width, width-truncated result and bit count. Each call includes its original
argument evaluation, complete helper body, return and caller assignment.
Their actual sequence/loop continuations compose to the original flag
storage sequence in42/50/58/58 steps for byte/word/dword/qword inputs.

The reached temporary map contains the exact native width, x86lean-truncated
input result and operand bit count. A general temporary-frame statement
retains every other input. The complete heap stays equal to the input heap;
every intermediate observation follows from the actual preceding execution.
Original source identities and all previously public prefix APIs are retained.

Focused62 jobs and four public type/axiom queries pass at200000/512 budgets,
j1,32GiB under shared timing. CF/ZF/SF/OF/PF stores, writeback and full native
handler/dispatcher composition continue next. Runtime and the single external
ISA specification retain their definitions. Latest whole confirmation remains
the DIV regression in `m5-xor-full-20261123`; root integration follows this batch.
