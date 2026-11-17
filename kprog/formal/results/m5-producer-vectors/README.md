# Actual raw producer LR and vector initializers

The proof binds the real LR-zero declaration and all 64 vector word
initializers immediately after N/Z/C/V. The actual exported anonymous
composite has 16-byte elements with low/high fields at 0/8; its 32-element
local array is 512 bytes. Kernel-checked source and offset equations connect
each interleaved word to its actual input temporary, field, array index and
successor stage. No C body or ISA evaluator is copied or introduced.

`vector_local` derives the real allocated array binding and writable range.
For every word, `vector_input_ready` takes three internal transitions to the
actual kind-6 function. `vector_input_returns` follows each stated scalar
external outcome and four actual internal return/store transitions. It
constructs the Mint64 store and reads back every bit of the returned word;
all other lanes and all other declared-local loads are preserved relative
to provider post-memory, as are caller blocks, access and allocation frontier.
The provider trace is retained. Post-call local permissions remain an explicit
ABI premise. Neither provider purity/existence nor final native vector
correspondence is inferred.

`lr_initialized` constructs the preceding real zero store in three internal
transitions, preserving all other local loads. `lr_and_first_vector` reaches
the first vector input after six transitions with that zero word still
readable. This is the declaration initializer; later architectural LR/return
binding remains separate.

Focused Lake build passes 152 jobs; twelve compiled public type/axiom queries
pass. All 23 Clight exports remain byte-identical to `9c617740f`. The final
full build is queued under timing SH; its status is in `validation.json`.
The previous flags batch is fully confirmed at 278 jobs and its bit proof
uses ordinary arithmetic without native reflection assumptions. Last full
`make check` passed at `5236c0e96`; no native rerun for these Lean-only changes.

Reproduce from `kprog/formal` with the lane's CPU/memory limits:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerVectors
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-vectors/Query.lean
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-vectors/Next.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

`Next.lean` records the actual following 24 stack-tag byte clears, SP-zero
assignment and first helper-context store. It checks the actual byte-array
declaration rather than assuming a generic stack capacity. All attempts,
including result-side source checks before integration, stay under
`/workspaces/kprog-raw/formal/m5-producer-vectors`.

Stack/tag and later context/header/cache-pointer/consumer stages, native
ABI/origin/memory/control correspondence and O1/O2/O4 recount remain M5.
Complete ISA-handler refinements remain zero; M6 closure follows M5.
