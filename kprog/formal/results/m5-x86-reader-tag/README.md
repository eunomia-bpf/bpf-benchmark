# Actual x86 register-reader tag loop

For every non-RSP architectural register and every non-stack tag,23 actual
Clight transitions load the original cell tag and select the original lane
suffix. The full heap and incoming raw value, width and shift are retained.
`from_value` combines the scalar word and tag loads in42 transitions. Used
field offsets follow from the existing exported cell layout. RSP and stack-tag
materialization, width extraction and the final return remain open.

Focused165 jobs pass in3.04s and five direct-import type/axiom queries pass;
see [Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and the compressed focused log. Original200000/512 proof budgets, one worker,
32GiB and the shared timing lock are unchanged. This checkpoint has no new root
import. All diagnostic attempts remain under
`/workspaces/kprog-raw/V/x86-alu-read-site-20261122`. Full handler/dispatcher
composition and the recorded full-check DIV fault correspondence defect remain
open.

Root integration2026-11-23: one transitive Scalar import exposes this module.
The targeted root build passes404 jobs in3.22s and all31 owned actual-root
queries pass. This receipt’s query now imports `KProgFormal`;
[root-public.txt](root-public.txt) records its root output. The scalar-reader
validation receipt retains the shared invocation details.
