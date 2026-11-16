# M5 successful local deallocation

`ClightRefinement/Deallocation.lean` proves that the imported Clight allocator,
starting with an empty local environment, always produces an environment whose
listed locals can be freed. The result retains the entire old-block contents
and Cur/Max permission maps in `FrameBelow`. This holds for arbitrary caller
memory, composite environment, variable names and declared sizes. Overwritten
bindings remain outside the old frame; the theorem makes no claim that such
invalid duplicate declarations free every overwritten allocation. The actual
handler's declaration uniqueness is independently proved at function entry.

The proof maintains lookup facts: each bound block lies between the caller's
old `nextblock` and the current one, its whole declared range is Freeable, and
distinct bound names point to distinct blocks. Allocation preserves old block
permissions via the imported memory lemmas. The enumeration lemmas added to
`CCLib/Maps.lean` transfer these lookup properties and pairwise relations to the
actual `PTree.elements` values, in its actual order. Mapping `blockOfBinding`
therefore supplies every range and distinctness premise of the existing
`CC.freeList_isSome_of_rangePerm`. The existing raw frame composition finishes
the proof. No allocation/free interpreter or separate memory model is added.

The two map lemmas are universal in the map values and predicate/relation;
their private accumulator proofs do not assume an enumeration order or depend
on the encoded keys. Their consumer here uses the actual environment values.
No assumption about distinct declaration names or nonnegative composite sizes
is needed for deallocation itself: `alloc` grants precisely its declared range,
and the imported `rangePerm_intro` also covers empty ranges. These facts do not
assert that every arbitrary composite environment is a valid source ABI.

`Arm64NopCall.return_frame` now proves successful deallocation of the actual
266 locals. `call_returns` constructs a real return memory and a complete
Clight call/return execution for every initial memory, ignored argument value
and flags byte. `call_corresponds` no longer takes caller premises asserting
enumerated-local freshness or free success. Both are supplied by the allocator
proof and the imported free-list theorem. The private body/return execution
lemma consumes the resulting free equation; there is no alternate return path
or default memory on failure.

This upgrades the same conditional NOP correspondence. A concrete entry/native
heap relation, its domain and frame-stability law, compiled-label/PC embedding
and all-behaviors refinement remain in M5. Complete ISA-handler count remains
zero, and the 2,065 historical theorem migrations and O1/O2/O4 recount remain
open. M6 and the final whole-package `lake build` / `make check` follow.

Only mathematical proof interfaces change. Canonical C, all 23 export sources,
normalization/frontend code, frozen benchmark paths, compiler flags, base,
image, kernel and PERF tools stay unchanged. Raw diagnostics and bounded builds
are retained at `/workspaces/kprog-raw/formal/m5-local-deallocation`.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64NopCall
lake env lean -j1 results/m5-local-deallocation/Axioms.lean
```

The generic deallocation build passes 32 Lake jobs. The strengthened actual
NOP procedure build passes, and 18 axiom queries plus printed public types
confirm the removed premises. New map laws use only `propext`; deallocation
uses standard Lean axioms, and procedure relations additionally expose the
existing opaque external/assembly relations. No new axiom, native checker,
admission or external determinism assumption. The final unchanged-export
batch is recorded after it finishes; its logs stay in the raw jobs directory.
