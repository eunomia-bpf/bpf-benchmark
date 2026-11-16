# Actual raw producer prefix to initialized caches

`Arm64Producer.cache_prefix_source` binds the actual exported function body
to its extracted 189-assignment prefix and the existing cache initializer
stage. This is an equation of actual Clight statements, not a copied handler
or an alternate interpreter. The ABI object's layout and full 216-byte size
are kernel checked from the exported composite environment.

Every preceding assignment is checked against the imported Clight l-value,
expression, cast and typed-store semantics. Permissions come from the actual
allocated ABI/context/kind locals and their declared ranges; stores preserve
all access and allocation identity and frame every caller block. Small
source-derived groups keep independent proofs within the unchanged default
heartbeat/recursion limits. Ordinary checked Lean elaboration exposes the
actual source statements; the kernel verifies the source equation and every
execution certificate.

`prefix_internal` connects the real producer call to the cache stage for
arbitrary caller memory, context, continuation value and control continuation.
`entry_caches_initialized` composes that execution with the existing four
initializer stores. Both cache words and validity bytes read back zero,
with complete caller memory framed. The previous stage-start access-map
premise is discharged by execution of the actual preceding assignments.
Zero words with invalid validity bytes do not represent native origins.

Later provider calls, header construction/vector loop and the actual consumer
continuation remain open. Native input/origin, raw/XDP/SKB producer state,
compact/PC/native-memory/control and the O1/O2/O4 recount remain M5 before
remaining M6 closure. These prefix/helper laws add zero complete ISA-handler
refinements.

Reproduce from `kprog/formal` with the lane CPU/memory limits:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerPrefix
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-prefix/Query.lean
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-prefix/Inspect.lean
lake build
```

Raw attempts remain under `/workspaces/kprog-raw/formal/m5-producer-prefix`.
This step changes no canonical C, external semantic source, generated export
or frozen benchmark. Last full `make check` passed at `5236c0e96`.

Validation: the 189 assignments take 567 internal transitions; entry reaches
the cache stage in 568, and completes cache initialization in 580. Focused
build passes 46 jobs; final whole `lake build` passes 272 with zero failures.
Five public type/axiom queries and the metadata inspection pass. Source and
resource laws use at most the standard three axioms. Internal-run laws also
name clean's existing opaque external/assembly semantic constants in `Step2`;
neither boundary executes and no external determinism axiom is used. All 23
exports (243,488,732 bytes) remain byte-identical with `9c617740f`.

One batch encountered a host thread-creation refusal. Synchronous declaration
elaboration keeps this proof within the assigned single worker; heartbeat,
recursion and memory limits stay unchanged. All failed development attempts,
including that refusal, remain in the raw directory. The source-derived write
groups and list equations are checked by the kernel; they add no alternative
C or ISA execution semantics.
