# Actual combined reader cold STACK path

`program_input_binding` binds the Program export's actual native/host input
symbol, external function and complete signature at Clight block 64. This is
a separate binding from the standalone address export. The stock BPF mutable
input map remains a different provider ABI.

The checked cold STACK prefix executes 22 internal transitions from the
actual combined reader's inlined materializer to its kind-1 external call.
Its continuation retains the pending stores, readback, addition and enclosing
loops. The suffix executes 28 internal transitions from the actual returned
provider value to the complete reader return. Both use stages extracted from
the generated function, not a second handler body.

`entry_cache_stores` constructs the two actual typed stores for either
selected cache from writable storage. Base and validity cells may share a
block with disjoint byte ranges; the entry has a separate block so its pointer
fields survive both stores. The stores establish `WarmEntryCache`, preserve
all permissions and allocation identity, and retain the actual intermediate
validity-pointer load and final base-pointer reload. These explicit storage
conditions remain producer obligations.

`stack_materialize_cold`, `gpr_read_stack_cold` and `sp_read_cold` follow every
specified outcome admitted by the actual imported external-call relation.
They retain its trace and post-call memory and construct the two cache stores
in that memory. Provider purity and header stability across the provider are
not assumed: `BorrowedCacheStorage` binds the actual pointers after it returns,
which may differ from their pre-call values. Payload/SP offsets were read
before the provider and remain in the actual temporary environment.

These are executions for each given provider outcome, not an all-behaviors
claim over an unbound provider. They do not establish a provider result's
native physical origin. The cold RETURN Program path, actual producer/cache/
compact/PC/native-memory bindings and general compiled control remain M5,
with the O1/O2/O4 recount before remaining M6 closure. Complete ISA-handler
refinements remain zero.

Reproduce from `kprog/formal`, using the lane's assigned CPU and memory caps:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64RegisterReads
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-program-cold/Query.lean
lake build
```

All attempts and query output are retained under
`/workspaces/kprog-raw/formal/m5-program-cold`. Canonical C, generated exports,
external semantic sources and frozen benchmark paths are unchanged. The last
full `make check` passed at `5236c0e96`; this step changes Lean proofs only.

Validation: focused build passes 143 jobs; final whole `lake build` passes
270 jobs with zero failures. Six public type/axiom queries pass at unchanged
default limits. Binding, store-construction and executable-prefix laws use
only the standard three axioms. Relational laws also name clean's existing
opaque external/assembly semantic constants in `Step2`: the provider executes
one actual external-function step under the stated relation; no assembly
boundary executes and no external determinism axiom is used. All 23 exports
(243,488,732 bytes) compare byte-identical with `9c617740f`. Failed development
attempts remain in the raw directory; compact results are `validation.json`.
