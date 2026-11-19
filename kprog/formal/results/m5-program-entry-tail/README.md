# Actual production header tail and callback binding

The sixteen remaining header stores execute in 48 imported Clight steps.
Their composition with the preceding twelve scalar and 64 vector-pointer
stores takes 276 steps in the actual exported function/world/allocation
environment. At one reached pre-loop memory, all 92 typed header readbacks,
other-local loads, caller framing, permissions and allocation frontier hold.
The combined theorem derives its header and nine tail-local resources;
it assumes only allocation permissions for otherwise arbitrary subsequent
contents, temporaries and continuation.

The actual payload load/store symbols resolve to blocks 60/61, with actual
exported function bodies. The extracted producer uses 184/185. Both symbol
and function lookups, non-shadowing and block inequality are proved. Tail
values therefore use the actual callbacks. The proof constructs actual
stores rather than asserting equal post-memory across distinct callback
pointers. Callback execution/refinement remains a later obligation.

Actual local binding comes from declaration/allocation correspondence. Field
lvalues use the checked allocated-header law without whole-world equality.
Imported evaluation/cast/store laws cover volatile union/array addresses,
callback pointers, size fields and remaining local addresses. All sixteen
mapped statements and the actual beforeLoop successor are kernel checked.
Provider initialization is not replayed and no substitute C body is added.

Final focused validation passes 169 jobs; one full Lake passes 344 jobs.
Eleven public type/axiom queries pass. Binding/evaluation/cast/source laws
use standard logical axioms. Execution laws retain the imported Step2
abstract external semantics; no new axiom or external transition is added.
Initial proof-construction failures are retained raw: broad/full reduction
hit existing heartbeat/recursion caps, metadata wrappers needed exposure,
and lookup witnesses needed concrete annotations. Small groups, constructor
normalization with shared identifiers/types, and narrow address-of rewrites
resolve these at unchanged 200000-heartbeat/512-recursion limits.

Run from kprog/formal on CPU17 with LEAN_NUM_THREADS=1 and 32 GiB AS:

```
lake build KProgFormal.ClightRefinement.Arm64ProgramEntryTail
lake env lean -j1 results/m5-program-entry-tail/Query.lean
lake env lean -j1 results/m5-program-entry-tail/Inspect.lean
lake build
```

Host checks follow the coordinator's 2026-11-19T18:18:59Z rule for CPUs 8–23
without the timing lock. C/runtime sources and benchmark settings are unchanged.
Export parity and whole make check are historical receipts identified in
validation.json, rather than newly repeated checks.

M5/M6 remain open; completed ISA-family count stays zero. Next is the actual
live vector-pointer loop, then full input-prefix/global/consumer/native/context
admission and the remaining semantics/O1/O2/O4 obligations. M6 and fresh full
Lake plus make check follow completed M5.

Raw: /workspaces/kprog-raw/formal/m5-program-entry-tail
