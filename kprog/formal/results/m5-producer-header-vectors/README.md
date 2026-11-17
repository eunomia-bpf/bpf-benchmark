# Actual null vector-pointer initialization

`Arm64ProducerHeaderVectors.lean` moves the previously checked 64-statement
source schema into the active proof library. The real composite puts vector_lo
at 96 and vector_hi at 352 in the 728-byte entry. Kernel-checked pointer arithmetic
binds each actual initializer address to offset 96 + 8*i for i in Fin64.

Each store is constructed from the actual allocated HeaderLocal writable range,
executes three internal transitions and reads back the imported null pointer
representation Vlong0. Disjointness preserves every other vector-pointer slot,
all twelve scalar header slots, other declared-local typed loads and caller
bytes/Cur/Max permissions, access and nextblock. The complete actual segment
executes in 192 internal transitions. Composing it with the twelve scalar
header stores gives 228 transitions with all 76 readbacks. Both existing
BorrowedCacheStorage contracts are reconstructed from the preserved scalar
pointers at this reached state.

The stage access map matching actual allocation remains explicit. The run uses
the Entry environment; the borrowed memory contracts use the actual Program
composite layout. Linked consumer execution, provider effects, native origins,
memory/control correspondence and full handler refinements remain M5. Complete
ISA-handler count stays zero, with M6 following M5.

Focused build passes 157 jobs, all six compiled public type/axiom queries pass,
and the final full build passes 283 jobs with zero failures. The new next-source
query checks all sixteen remaining header field names and prints the actual
following vector-pointer loop and consumer call. The updated prior Next query
also passes. All 23 exports remain byte-identical to 9c617740f (243488732 B).
All compilation runs under timing SH, one worker/32 GiB AS/CPU17, with default
200000 heartbeats and 512 recursion depth. Offsets use only propext; source and
layout facts use the three standard axioms, and internal-run facts additionally
mention imported external/assembly relations without executing either boundary.
No semantic or native-reflection axiom is added.

Reproduce from kprog/formal with the stated CPU/memory bounds:

```
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerHeaderVectors
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-header-vectors/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-header-vectors/Next.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

Raw attempts remain under /workspaces/kprog-raw/formal/m5-producer-header-vectors.
The first source check exposed normalization of pointer zero and target typeof;
the second passes after an explicit definitional equality and rewriting typeof
before reducing the cast/store. Canonical C, exports, imported semantics and
frozen benchmarks are unchanged by this proof step. Last complete native make
check passed at 5236c0e96; it is not repeated for these Lean-only additions.
