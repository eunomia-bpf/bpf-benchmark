# Actual x86 register-reader entry

The actual four-parameter reader has no local allocation. Its original register
and width casts narrow the long arguments to bytes, then call the linked
`x86_width_effective` helper. The real call and return reach the original
shift/cell-read statements in22 silent transitions, for every three input bytes,
arbitrary binding value, heap and continuation. The heap remains unchanged.
`arguments` connects the actual ALU call-site casts to these reader arguments.
The helper's symbol/function identity is explicit; its result follows from its
existing execution theorem. Cell reads and the reader result remain next work.

Focused163 jobs pass in3.23s; six direct-import type/axiom queries pass in1.50s.
One transitive root import exposes this module and the accepted ALU reader
call-site module. The targeted root build passes395 jobs in3.01s; the actual-root
eight call-site queries and six reader-entry queries pass in2.04s and2.01s.
All runs use the shared timing lock, one worker,32GiB and original proof budgets
(200000 heartbeats, recursion512). [Query.lean](Query.lean) now imports the root;
[public.txt](public.txt) records its output and existing axiom dependencies.
See [validation.json](validation.json) and the compressed focused/root logs.

Earlier diagnostics remain under
`/workspaces/kprog-raw/V/x86-alu-read-site-20261122`. The complete handler and
dispatcher refinements remain open. The full-check DIV fault correspondence
regression remains recorded in [the batch receipt](../m5-batch-20261122/README.md);
these focused/root checks do not establish that whole `make check` passes.
