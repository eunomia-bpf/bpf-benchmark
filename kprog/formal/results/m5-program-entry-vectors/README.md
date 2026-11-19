# Actual production entry vector-pointer initialization

All 64 actual null vector-pointer stores execute in 192 imported Clight
transitions. Their composition with the preceding twelve header stores takes
228 transitions in the actual production function and allocation environment.
At the same reached memory, the proof derives all twelve scalar pointers,
all 64 null pointer readbacks, unchanged other-local loads, caller framing,
permissions and the allocation frontier. The combined theorem derives its
header storage; it adds no caller-supplied storage premise or provider replay.
Memory contents, temporaries and continuation remain arbitrary; subsequent
memory must retain the original allocation permissions.

The expression layer reuses imported pointer addition, binary evaluation,
field evaluation, dereference and assignment semantics. Element size, rather
than equality of composite worlds, justifies pointer arithmetic. The generic
laws retain failures and invalid operands. Null casts and source/actual stores
share one imported Mem.store witness. The source equation checks all 64
statements after the real afterHeader boundary and retains the actual
production successor afterNullVectors.

Focused validation passes 168 jobs. One full Lake build passes 343 jobs.
Eight public type/axiom queries pass. Scalar/expression/source laws have
standard logical axioms only. Execution laws retain the imported Step2
abstract external-function/inline-assembly semantics, documented in the
previous assignment receipt; no new axiom or external transition is added.
The first focused attempt's recursion-limit failures are retained. Generic
operand congruence and an explicit element-size proof fixed premature large
world unification at the unchanged 200000-heartbeat/512-recursion limits.

Run from kprog/formal on CPU17, LEAN_NUM_THREADS=1, 32 GiB AS:

```
lake build KProgFormal.ClightRefinement.Arm64ProgramEntryVectors
lake env lean -j1 results/m5-program-entry-vectors/Query.lean
lake build
```

Host work uses CPUs 8–23 without the timing lock under the coordinator's
2026-11-19T18:18:59Z notice. C sources, runtime inputs and benchmark settings
are unchanged. Export parity and whole make check are historical receipts,
identified separately in validation.json; they were not repeated here.

M5/M6 remain open and completed ISA-family count stays zero. Next: the
sixteen remaining header fields, including actual global callback bindings,
then the vector-pointer loop and complete input-prefix/native admission.
Callback addresses must come from the actual world; the extracted producer's
hard-coded callback blocks are not an actual binding proof. Recount O1/O2/O4,
finish M6 and run fresh full Lake plus make check before goal completion.

Raw: /workspaces/kprog-raw/formal/m5-program-entry-vectors
