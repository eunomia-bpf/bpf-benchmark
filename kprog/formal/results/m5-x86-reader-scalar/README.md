# Complete actual ordinary scalar register reader

`call` executes the original four-parameter Clight reader through entry, the
linked width helper, scalar word and tag loads, lane selection and its actual
return. It returns the shared `X86.Value.trunc` view, uses the original ALU
call-site argument casts and preserves the complete caller memory. Counts are
77/81/85/85 transitions for byte/word/dword/qword.

`native_call` returns exactly `cpu.getReg size register high8` from the shared
whole-register representation, including legal AH/CH/DH/BH reads. The scope is
non-RSP scalar cells with tag zero. The general `call` theorem also permits
other non-stack tags when the loaded word is scalar. Used layout/header/word/
tag observations and linked helper identity are explicit; the effective-width
equation connects the actual input byte to the chosen architectural width.
RSP, pointer-valued cells and stack-tag materialization remain next work.

Focused167 jobs pass in2.90s and both direct-import type/axiom queries pass.
See [Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and the compressed focused log. Original200000/512 proof budgets, one worker,
32GiB and shared timing are unchanged. Root integration follows this accepted
component batch. Raw attempts remain under
`/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.

This is a complete reader call within its stated domain. Whole instruction
handlers and dispatcher composition remain open, and the recorded whole-check
DIV fault correspondence defect remains unresolved.

Root integration2026-11-23: one transitive Scalar import exposes this module.
The targeted root build passes404 jobs in3.22s and all31 owned actual-root
queries pass. This receipt’s query now imports `KProgFormal`;
[root-public.txt](root-public.txt) records its root output. The scalar-reader
validation receipt retains the shared invocation details.
