# Actual x86 pointer-reader model boundary

The original qword lane suffix reaches its actual shift/mask assignment in
16 Clight steps. If the raw word there is `Vptr block offset`, that statement
has no executable successor and **no relational Clight step**, for any trace
or target. The latter result inverts the actual assignment and expression
rules; it does not infer relational failure from an incomplete interpreter.

The existing pointer-origin relation can represent that same input as the
native word `base + offset`. Its origin table is absent from Clight numeric
shift semantics, which rejects a pointer-valued left operand even for shift
zero. This is an explicit proof-model boundary to resolve before extending
the scalar reader/native correspondence to arbitrary pointer cells. It is
not a hardware/runtime counterexample, nor a complete pointer-reader call
counterexample: the theorem begins at the actual lane suffix with the stated
local observations. Existing scalar-reader theorems keep their `Vlong` domain.

No runtime, imported Clight semantics, external ISA specification, axiom or
check assertion was changed. The direct-import queries and their axiom
output, focused build and resource metadata are retained here. Proof caps
remain200000 heartbeats/512 recursion, one worker,32GiB and shared timing;
raw attempts remain in `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
This records an open obligation, not a completed instruction family.
