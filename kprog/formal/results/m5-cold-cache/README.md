# M5 cold ARM origin-cache readers

`Arm64OriginCache.input_binding` identifies the actual exported
`native_lab_entry_input` symbol, external signature and function lookup in
`Clight/Arm64Address.lean`. Its Clight block is 57. This binding was committed
first as `0cb94cfbc`, following the cleanup handoff.

`reader_cold_returns` executes both actual exported base readers from a cold
validity-byte load. Eleven internal transitions reach the external call with
kind 1 for stack or 3 for return. For each outcome of the imported external-call
relation, one external transition and eleven internal transitions return its
64-bit scalar and establish `WarmCache`. The theorem preserves that outcome's
trace and complete post-call memory as the starting point of the two cache
writes; it assumes neither provider purity nor determinism.

`cache_stores` constructs both successful typed writes from writable-access
premises on the provider's post-call memory. Imported memory laws establish
the cached word and validity byte, retain permissions and allocation identity,
and prove that the validity write preserves the base word. Field separation
holds for arbitrary wrapping pointer offsets. No initialized specimen heap,
caller-supplied successful-store equations or new execution semantics are used.
Closed statement fragments come from the actual exported AST by elaboration
reduction, with kernel-checked entry, layout and execution equations.

The formal export selects the host/native input ABI in
`kinsn/module/include/native_lab_input.h`. The stock verifier configuration
instead selects `kprog/stock-path/include/stock_native_input.h`, which reads
an ordinary mutable array-map element and ignores the input kind. These are
different boundaries. The theorem's actual external-call premise does not
establish either provider's relation to native SP/return origins. That binding,
pointer-valued materialization, producer/entry admissibility, native memory
and general compiled control remain M5 obligations. This step adds zero
complete ISA-handler refinements; all 2,065 migrations and O1/O2/O4 recount,
then M6 and final whole-package checks, remain outstanding.

Reproduce from `kprog/formal`:

```
lake build KProgFormal.ClightRefinement.Arm64OriginCache
lake env lean -j1 results/m5-cold-cache/Axioms.lean
```

The combined 23-export/13-proof build passes 161 Lake jobs. Three axiom
queries and three public type prints pass. Binding/store laws use only standard
Lean axioms; the relational call additionally exposes the existing opaque
external/assembly relations, with no external determinism assumptions. Commands
and output are recorded in `commands.json` and `axioms.txt`. Builds use CPU 17, 32 GiB AS and `-j1`;
queries use CPU 19 and 16 GiB AS. Heartbeat/recursion limits remain unchanged.
Canonical C, exports, imported semantic sources and frozen benchmark paths
stay exact to `0cb94cfbc`; image 6641a7e1 and the shared base remain untouched.
Raw diagnostics stay at `/workspaces/kprog-raw/formal/m5-cold-cache`.
