# Actual cold RETURN Program reader

The cold RETURN reader now follows the actual tag-10 branch to the kind-3
native/host input call. `return_read_cold_prefix` retains its exact pending
stores, readback, addition and enclosing loops. `return_materialize_cold`
composes this prefix, the actual provider outcome and the internal suffix.
`gpr_read_return_cold` connects the complete exported reader for every GPR
index 0–30 to those executions.

Both cache branches share one checked extraction of their actual AST stages;
their continuations and temporaries retain their actual distinct identifiers.
The new path reuses `entry_cache_stores` and `BorrowedCacheStorage true`.
The base and validity writes are constructed from the supplied memory's
writable permissions and pointer/range bindings. They establish a warm cache
and preserve permissions and allocation identity relative to that memory.

The provider's trace and post-call memory are retained, including its right
to change the cache-pointer fields before returning. The payload is read
before the provider. The theorem constructs an execution for each stated
provider outcome under the imported external-call relation; native physical
origin and producer storage admissibility remain explicit obligations.
It asserts no provider purity or all-behaviors refinement for an unbound
provider. The stock mutable-map BPF provider remains a distinct ABI.

The original STACK and SP contracts remain and are included in the public
queries. These helper laws add zero complete ISA-handler refinements.
Actual producer/compact/PC/native-memory/control binding and the O1/O2/O4
recount remain M5, before remaining M6 closure.

Reproduce from `kprog/formal` with the lane's assigned CPU/memory limits:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64RegisterReads
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-program-return/Query.lean
lake build
```

Raw attempts and query output stay under
`/workspaces/kprog-raw/formal/m5-program-return`. This step changes no C,
external semantics or frozen benchmark path. The last complete native
`make check` passed at `5236c0e96`.

Validation: the RETURN materializer executes 23 internal transitions before
the actual provider call and 28 after its return. Focused build passes 143
jobs; final whole `lake build` passes 270 with zero failures. Nine public
type/axiom queries pass at unchanged default limits, including the six
retained STACK/storage laws. Executable/binding/store laws use only the three
standard axioms. Relational laws additionally name clean's existing opaque
external/assembly semantic constants in `Step2`; one external step follows
the stated provider relation and no assembly boundary executes. No external
determinism axiom is used. All 23 exports (243,488,732 bytes) remain
byte-identical with `9c617740f`. The first attempt's named-readback unfolding
and validity-byte errors are retained in the raw directory.
