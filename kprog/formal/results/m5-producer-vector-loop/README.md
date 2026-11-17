# Actual vector-pointer loop

`Arm64ProducerVectorLoop.lean` binds and executes the exported 32-iteration
loop. Each iteration tests the actual uint32 counter, stores both vector
pointers, and increments that counter. Header slots are at 96+8*i and 352+8*i;
values point to the allocated 512-byte vector array at offsets 16*i and 16*i+8.
The signed literal initializers from the preceding stage are distinguished
from this loop's actual unsigned temporary and Ptrofs.of_intu conversion.

Actual HeaderLocal writable ranges construct each store and its result.
One iteration takes 11 internal transitions. Initialization takes 4, all 32
iterations take 352, and exit takes 6, totaling 362 to the actual consumer sequence.
The proof retains the complete states and counter 32, preserves every other
temporary binding, and frames arbitrary typed observations outside the two
written slots. Induction retains all 64 final pointer readbacks.

Composition with header initialization takes 638 transitions and retains all 92
typed field readbacks: twelve scalar pointers, 64 populated vector pointers,
and sixteen mixed-width tail fields. Both BorrowedCacheStorage contracts are
constructed at that reached state. Other allocated locals, including vector
contents, caller bytes and Cur/Max permissions, access and nextblock survive.
The stage access-map binding to actual allocation remains explicit.

The endpoint is the source continuation call/return sequence, before Scall.
The next query proves its actual source and evaluates &entry to the allocated
header block. The run uses Entry's environment, while the borrowed memory
contract uses actual Program composites. Linked consumer execution and
lifetime, producer/provider ABI and native origins/memory/control, complete
handler refinements and O1/O2/O4 recount remain M5. Complete handler count is 0;
remaining M6 follows M5. No external, assembly or callback executes here.

Focused Lake passes 159 jobs; sixteen public type/axiom queries and the next
source/argument query pass. Full Lake passes 285 jobs with zero failures.
All 23 exports remain byte-identical to 9c617740f, 243488732 bytes. Builds and
queries use timing SH, CPU 17, one worker, 32 GiB AS and default 200000 heartbeats
and 512 recursion depth. Offset proofs use propext; other facts use the three
standard axioms. Internal runs also depend on the imported opaque external
and assembly relations. No semantic or native-reflection axiom is added.

Reproduce from kprog/formal, with the stated CPU/memory bounds:

```
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerVectorLoop
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-vector-loop/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-vector-loop/Next.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

Raw attempts remain at /workspaces/kprog-raw/formal/m5-producer-vector-loop.
Canonical C, all exports, pinned semantics and frozen benchmark paths are
unchanged. Last complete native make check passed at 5236c0e96; it was not
repeated for these Lean-only additions.
