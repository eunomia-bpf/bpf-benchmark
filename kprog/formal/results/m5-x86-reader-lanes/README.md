# Actual x86 register-reader lane suffix and return

The original width/shift selectors and mask expression produce
`X86.Value.trunc size (value >>> effectiveShift)` for every64-bit scalar value,
the four architectural widths and each byte shift below64. Only byte reads
use the shift; larger widths use zero. Exact transition counts are9/13/17/17
for byte/word/dword/qword. The final temporary map retains the source's repeated
mask assignments, with the complete heap and continuation unchanged.

The actual reader's loop exit and return take four further transitions. Its
empty local frame frees no caller block, and the return carries the actual
selected value. Complete caller/native composition remains next work.

Focused166 jobs pass in2.76s; the two scoped type/axiom queries pass. See
[Query.lean](Query.lean), [public.txt](public.txt), [validation.json](validation.json)
and the compressed focused log. All use the existing proof budgets200000/512,
one worker,32GiB and shared timing. No new root import at this checkpoint.
Raw diagnostics remain under `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
RSP/pointer/stack handling, full instruction/dispatcher composition and the
recorded full-check DIV fault correspondence defect remain open.

Root integration2026-11-23: one transitive Scalar import exposes this module.
The targeted root build passes404 jobs in3.22s and all31 owned actual-root
queries pass. This receipt’s query now imports `KProgFormal`;
[root-public.txt](root-public.txt) records its root output. The scalar-reader
validation receipt retains the shared invocation details.
