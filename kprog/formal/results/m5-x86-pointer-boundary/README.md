# Actual x86 pointer-reader model boundary

The original qword lane suffix reaches its actual shift/mask assignment in
16 Clight steps. If the raw word there is `Vptr block offset`, that statement
is **stuck in both executable and relational Clight semantics**, for every
trace and target. The relational result follows by inversion of the actual
assignment and expression rules.

The existing pointer-origin relation can represent that same input as the
native word `base + offset`. Clight numeric shift semantics
rejects a pointer-valued left operand even for shift zero; relating those
operations to numeric origins remains an explicit proof-model obligation.
The checked theorem starts at the actual lane suffix with the stated local
observations. Complete pointer-reader call reachability and concrete native
correspondence remain composition work. Existing scalar-reader theorems
keep their `Vlong` domain.

Runtime, imported Clight semantics, the external ISA specification, axioms
and check assertions retain their existing definitions. Direct-import queries and their axiom
output, focused build and resource metadata are retained here. Proof caps
remain200000 heartbeats/512 recursion, one worker,32GiB and shared timing;
raw attempts remain in `/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
This records an open obligation toward instruction-family completion.
