# Actual ALU operand reads through the arithmetic dispatcher

The original non-XOR gates, two linked reader calls, their complete scalar
bodies, both original assignments and sequence exits reach the real arithmetic
dispatcher. Both values follow the shared x86 width/shift semantics from actual
cell word/tag loads. The full input heap and continuation remain unchanged;
decoded operation and effective width remain available to arithmetic/flag proofs.
Counts from the original operand selector are177/185/193/193 transitions for
byte/word/dword/qword.

The domain is two non-RSP scalar cells with non-stack tags and byte shifts
below64. Layout, helper identities, live caller inputs and actual heap reads
are explicit. The imported actual reader-body proofs supply both results.
True handler entry/allocation and native full-state composition remain next.

Focused169 jobs pass in2.43s; two direct-import type/axiom queries pass. See
[Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and the compressed focused log. Original200000/512 budgets, one worker,32GiB
and shared timing are retained. No new root import at this checkpoint.
Raw attempts remain under `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
Full instruction/dispatcher step refinement and the recorded whole-check DIV
fault correspondence defect remain open.

Root integration2026-11-23: one transitive SelfXor import exposes this module.
The targeted root build passes408 jobs in2.93s and all42 owned actual-root
queries pass. This receipt’s query now imports `KProgFormal`;
[root-public.txt](root-public.txt) records its output. Shared invocation details
are in the same-register XOR validation receipt.
