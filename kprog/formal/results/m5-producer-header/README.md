# Raw producer scalar header pointers and borrowed caches

The twelve exported scalar header-pointer assignments after context/tag setup
are bound to their actual field names, pointed-to types and source locals.
The layout certificate checks all twelve offsets against the actual composite.
Allocation supplies the real entry writable range and source-local bindings.
Each statement constructs its pointer store, executes three internal transitions
and reads back its exact pointer. `header_initialized` composes all twelve in
36 transitions, preserving all other declared-local loads, caller bytes and
Cur/Max permissions, access and nextblock.

`header_cache_storage` identifies the real stack/return cache blocks through
those same allocation bindings, derives their ownership and writable ranges,
and obtains the existing consumer `BorrowedCacheStorage` from the constructed
header readbacks. `header_initializes_caches` reaches both contracts after the
actual 36-transition segment. No successful header writes are supplied as
premises. The stage access map matching actual allocation remains explicit.

The internal run uses the Entry global environment; the memory contracts use
the Program composite layout, whose actual cache field offsets are checked.
Executing the linked consumer remains separate. No provider purity, native
memory/origin/control correspondence or complete ISA refinement is inferred.
The following 64 null vector-pointer assignments now execute in 192 transitions
in `Arm64ProducerHeaderVectors`; its layout proof binds the entry size of 728 B.
The source schema moved into that library, and `Next.lean` prints its successor.
The later sixteen volatile-storage/callback/scalar/ABI fields now execute in
48 transitions in `Arm64ProducerHeaderTail`; complete header setup takes 276.
The final vector-pointer loop and linked consumer continuation remain M5 work.
Complete ISA-handler count remains zero; M5 and M6 stay open.

Focused build passes 156 jobs, all eight compiled public type/axiom queries
pass, the next-source query passes, and the final full build passes 282 jobs
with zero failures. All run under timing SH on CPU 17, one worker, 32 GiB AS,
and default 200000 heartbeats / 512 recursion depth. Layout/allocation/storage
facts use the three standard axioms; offsets use only propext. Internal runs
also mention the imported opaque external and assembly relations without
executing either boundary. No semantic or native-reflection axiom is added.
All 23 exports remain byte-identical to `9c617740f` (243488732 B).

Reproduce from `kprog/formal` with the stated CPU/memory bounds:

```
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerHeader
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-header/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-header/Next.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

Raw attempts and final confirmation remain under
`/workspaces/kprog-raw/formal/m5-producer-header`. Preparation was moved into
the owning library after its source check passed. Last full native `make check`
passed at `5236c0e96`; it is not repeated for these Lean additions. Canonical C,
exports, pinned semantics and frozen benchmark paths are unchanged by this step.
