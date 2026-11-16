# Actual raw producer allocation and cache initializer stage

`Arm64Producer.entry_valid` and `entry_internal` prove the actual exported raw
producer enters for arbitrary caller memory, context and continuation values.
All real declarations are allocated by imported Clight semantics; the initial
temporary environment binds the actual parameters. `entry_frame` preserves
every caller byte and both permission maps below the original frontier.

`cache_locals` derives the actual entry/base/validity bindings for either
selected cache. These are distinct fresh blocks, owned below the frontier
after producer allocation, with writable typed base and validity ranges.
No successful-allocation, writability or alias premise is supplied by the
caller. Two generic local-allocation laws expose the existing resource proof;
the deallocation proof now reuses them instead of duplicating its setup.

`cache_stage_exported` binds the initializer stage and its continuation to
actual statements of the exported raw producer. `initialize_caches` constructs
all four actual stores: STACK base zero, RETURN base zero, STACK validity zero
and RETURN validity zero. The stage executes 12 internal transitions with the
actual allocated environment and arbitrary temporaries/continuation. Both
cache words and bytes read back zero; access and allocation identity remain
unchanged and every original caller block is framed exactly. The zero base
words are invalid cache contents, not claimed native physical origins.

The stage allows earlier content writes through an explicit equality of its
memory's access map with the allocation memory. Its complete reachability
from the producer entry, the earlier ABI initialization, later provider calls,
header construction and continuation entry remain open. In particular this
step does not yet establish `BorrowedCacheStorage` at the consumer call.
Actual provider-to-native-origin, register/tag/compact/PC/native-memory and
compiled-control bindings remain M5, then the O1/O2/O4 recount and remaining
M6 closure. Complete ISA-handler refinement count remains zero.

Reproduce from `kprog/formal` with the lane CPU/memory allocation:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64Producer
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-cache/Query.lean
lake build
```

Raw attempts and query output stay in
`/workspaces/kprog-raw/formal/m5-producer-cache`. This step changes only Lean
proofs and documentation. Canonical C, generated exports, external semantics
and frozen benchmark paths remain unchanged. Last complete `make check`
passed at `5236c0e96`.

Validation: focused build passes 45 jobs; final whole `lake build` passes 271
jobs with zero failures, including all existing procedure/reader proofs that
depend on the shared memory lemmas. Nine public type/axiom queries pass at
unchanged default limits. Resource, binding and source-stage laws use at most
the three standard axioms. Internal-run laws additionally name clean's existing
opaque external/assembly semantic constants in `Step2`; neither boundary
executes. No external determinism axiom is used. All 23 exports (243,488,732
bytes) remain byte-identical with `9c617740f`. All development failures and
retries are retained in the raw directory; compact results are `validation.json`.
