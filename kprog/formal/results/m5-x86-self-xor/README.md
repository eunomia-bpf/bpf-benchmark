# Actual same-register/lane XOR operand shortcut

Eleven original Clight transitions test XOR, equal register bytes and equal lane
shifts, then reach the real arithmetic dispatcher without reading a register
cell. Both actual zero initializations from aux decoding are retained; the
complete heap is unchanged.

`from_call` derives these comparisons from the original eight arguments and
decoded aux fields. Real entry, allocation and width-helper execution compose
with the shortcut in48 transitions. No cell pointer/tag/value or reader-symbol
premise is needed for this branch. The final heap is the actual nine-local
allocation. Arithmetic, flags, writeback and whole native-step correspondence
remain next work.

Focused171 jobs pass in2.72s and four type/axiom queries pass. See
[Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and the compressed focused log. The first attempt had one excess transition;
its retained diagnostic identified that dispatch was already reached. Original
200000/512 budgets, one worker,32GiB and shared timing are unchanged.
Root integration follows this accepted batch. All raw diagnostics remain under
`/workspaces/kprog-raw/V/x86-alu-read-site-20261122`. The existing whole-check DIV
fault correspondence defect remains open.

Root integration2026-11-23: one transitive SelfXor import exposes this module.
The targeted root build passes408 jobs in2.93s and all42 owned actual-root
queries pass. This receipt’s query now imports `KProgFormal`;
[root-public.txt](root-public.txt) records its output. Shared invocation details
are in the same-register XOR validation receipt.
