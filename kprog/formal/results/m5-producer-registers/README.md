# Actual raw producer register declaration initializers

`Arm64ProducerRegisterSource` extracts the 31 actual declaration blocks, local
names, temporaries and successor statements from `Clight.Arm64Entry`. Each
syntactic schema is kernel-checked against its actual source block. The source
laws also check the declared union/byte types, branch conditions and successor
chain. `first_register_stage` connects declaration 1 to the prior first-input
writeback endpoint. This is checked AST proof data, with no new evaluator,
reference ISA or generated C body.

`register_input_ready` proves five internal transitions from each actual
x0--x29 declaration to the existing kind-6 input function, using its real global
binding and saved continuation. `register_input_returns` follows each stated
scalar outcome of that external relation and nine internal transitions through
the real temporary assignments, union-word store and scalar-tag store. The
provider trace and post-memory are retained except for those two constructed
stores. Word and tag read back exactly; all other declared-local loads, caller
blocks, permissions and allocation frontier are preserved relative to that
post-memory. The explicit post-call ABI premise requires its access map to
retain the producer allocation's local permissions. Provider purity, earlier
register values surviving the provider, and physical native-origin correctness
are not inferred.

`register30_initialized` proves the actual zero branch in ten internal
transitions, without an external step. It stores the zero word and scalar tag,
with the same readback and noninterference properties. The later return-tag
assignment is separate. `producer_register_input_ready` connects the shared
continuation to the previously proved 594-transition raw-producer prefix,
including both cold caches; it reuses the existing theorem.

The proof reuses the existing scalar-local, store-construction and actual GPR
union-layout facts. A single store-resource proof serves both execution paths.
All proof limits remain at their defaults. Source checks are isolated in one
module so iterative execution proofs reuse their compiled results.

Reproduce from `kprog/formal`, with the lane's CPU and memory limits:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerRegisters
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-registers/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

Focused build passes 148 jobs; the full build passes 275 jobs under the shared
timing lock, and seven public queries pass. All 23 Clight exports remain
byte-identical to `9c617740f`. `validation.json` records the actual checks; all attempts and logs remain in
`/workspaces/kprog-raw/formal/m5-producer-registers`. This step changes no C,
export, external semantics or frozen benchmark path. Last complete `make check`
passed at `5236c0e96`.

These are per-declaration execution laws with their actual successor chain,
not a claim that all 30 external outcomes exist or preserve earlier state.
Cell/tag tables, flag/vector inputs, later context/header/cache pointers and
consumer continuation, native ABI/origin and memory/control correspondence,
full exported-handler refinement and O1/O2/O4 recount remain M5. Complete
ISA-handler refinements remain zero; M6 closure follows M5.
