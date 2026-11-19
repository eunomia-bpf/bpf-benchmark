# Actual production vector-pointer loop

All 32 actual vector-pointer loop iterations execute in 362 imported Clight
steps: four initialization steps, eleven per iteration and six to exit. The
counter reaches 32, every other temporary is preserved, and both pointer
arrays contain the 64 actual vector-half addresses. The successor is proved
equal to Arm64ProgramEntrySource.body from the checked production prefix.

Composition with the preceding header construction takes 638 steps in the
actual function/world/allocation environment. At one reached memory, all
92 typed header readbacks hold: twelve scalar pointers, 64 vector pointers
and sixteen tail fields, including actual callback blocks 60/61. Other-local
loads, caller framing, permissions and allocation frontier are preserved.
The combined API derives header and vector storage from allocation, with
arbitrary contents/temporaries/continuation and allocation permissions.

The two anonymous vector record types share size16, while pointer-array
indexing uses stride8. Generic imported pointer addition transports different
element types by size and retains failures. Field/local/dereference/address
transport reuses prior laws. Each actual assignment reuses the existing
source store witness and all its readback/frame facts; memory construction
and input providers are not replayed. Comparison/increment arithmetic also
reuses the checked source laws, with environment independence.

Final focused check passes 170 jobs. One full Lake build passes 345 jobs.
Fifteen public type/axiom queries pass. Expression/source/store transport uses
standard logical axioms; execution laws retain the imported Step2 abstract
external semantics. No new axiom, interpreter, C fixture or external step is
added. Initial failed proof attempts remain raw. Explicit closed counter
facts and kernel-checked source-equation constructors resolve premature
large-term comparison at the original heartbeat/recursion limits. Initial
source-function references in control-state endpoints were fixed before
final validation.

Run from kprog/formal on CPU17, LEAN_NUM_THREADS=1, 32 GiB AS:

```
lake build KProgFormal.ClightRefinement.Arm64ProgramEntryLoop
lake env lean -j1 results/m5-program-entry-loop/Query.lean
lake build
```

Host work uses CPUs8–23 without the timing lock under the coordinator's
2026-11-19T18:18:59Z notice. C/runtime inputs and benchmark settings are
unchanged. Historical export comparison and whole make check are identified
in validation.json and were not repeated for this Lean-only batch.

M5/M6 remain open; completed ISA-family count stays zero. Next: derive the
reached body's storage/view/cache/freeable interface, then compose the real
input prefix and call-entry/global/provider/native/context bindings. Actual
body/callback execution and ISA refinements, O1/O2/O4 recount, M6 retirement
and final fresh full Lake plus make check remain.

Raw: /workspaces/kprog-raw/formal/m5-program-entry-loop
