# Complete actual logical flags stage to the shared writer

The original logical flag stage now executes from the real old-CF load,
through all classifier gates, three complete width helper calls, five actual
flag stores and genuine nested loop/switch exits to the unchanged writer.
Execution takes145/153/161/161 steps for byte/word/dword/qword inputs and
supports all three logical operation codes. The final five flag bytes match
the single external x86lean logical-flags result for every AF oracle choice;
the original header loads are retained.

Every intermediate temporary and pointer observation is derived from actual
preceding executions and store frames. Heap store equations, header/data
separation and distinct flag byte addresses remain explicit. Arbitrary code
bodies and skipped tails share one checked8-step exit law; the existing SHL
resume interface retains its original statement and actual writer endpoint.

Focused77 jobs and five public type/axiom queries pass at200000/512 budgets,
j1,32GiB under shared timing. Register writeback, complete caller/native state
and ISA dispatcher composition continue next. Runtime and the shared external
specification retain their definitions. Latest whole confirmation remains
the DIV regression in `m5-xor-full-20261123`.
