# Retained source allocation frontiers

The existing complete MOVK call derives a canonical producer-allocation bound
at its returned memory from actual allocation monotonicity, writer nextblock
and actual free nextblock. The source MOVK and two-call composition now retain
that same bound. Existing standalone native wrappers consume the stronger result.

The actual98-input/setup prefix already derived ready.nextblock equal to the
canonical producer allocation. Its source and native APIs now return that exact
equality, plus the derived canonical bound at the returned MOV-pair memory.
No premise, execution, provider choice, byte, source call, resource or trace is
changed. These facts allow the following ADD to reuse the reached heap without
supplying new lifetime/frontier admission assumptions.

Proof verification covers all affected source/native consumers at original
200000-heartbeat/512-depth/asyncfalse limits, one worker on CPU17/32GiB AS.
Raw /workspaces/kprog-raw/formal/m5-add-prefix-join retains actual results.
No runtime test/benchmark/measurement is run. Whole confirmation is at batch end.
M5/O1/O2/O4/M6 remain open; completed ISA families0.

Batch confirmation2026-11-21: lake build KProgFormal passes303 proof jobs
in3.513s; root artifact UTC2026-11-21T16:30:02.213988+00:00.
CPUs16-23/nice19/j1/32GiB AS, original proof caps. Native executables/tools,
runtime tests and measurements excluded. The actual original-entry/MOV/ADD
source composition is verified; production ABI/provider validity, remaining
handlers, whole-program outcomes/final return and M5/M6 remain open.
