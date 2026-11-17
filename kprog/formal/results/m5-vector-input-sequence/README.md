# All 64 vector inputs feed the RAW register proof

`Arm64ProducerVectorInputs.vector_inputs_initialized` traverses the actual
vectorStage 0 through 64 in source order. It composes the existing per-visit
external-call and writeback proofs, derives every word in the real 512-byte
vector local, and retains a list of exactly 64 provider traces. The imported
Clight Star execution carries their concatenation; traces are not replaced
with an assumed empty trace. Independently chosen VectorLocal records identify
the same block through the actual allocation binding.

Every visit uses the actual linked input external and its Senv. The explicit
source-specific `Provider` condition supplies that visit's returned word and
post-memory, access/nextblock equalities, caller frame, and preservation of
allocated-local readbacks. It is an environment premise, not a proved runtime
capability. Post-memory need not equal pre-memory. The proof threads it through
the actual return/store continuation, preserving earlier vector words and
other source locals. Temporary updates are threaded too, with a law for names
outside the 64 input temporaries.

`vector_inputs_and_raw_registers` specializes the returned words to native
vector low/high halves and composes the traversal with the existing
728-transition RAW setup/header proof. The actual 64-visit execution now
derives the final vector data premise. All 32 low/high pairs are assembled
using actual 8*i = 16*lane + 0/8 offsets. The _ctx temporary survives every
input return. The combined result establishes the existing GPR/SP/vector/flag
relation in one reached memory and frames caller contents, both permission
maps, access and nextblock.

The provider condition still needs an actual invocation witness. Earlier
GPR/table/ordinary-tag/flag initialization, physical pointer/native origin
bindings, architectural memory/events/fault/control and the genuine program
continuation remain open. Host zero fixtures or stock unspecified-map reads
are not substituted for matching native input outcomes. M5/M6 and O1/O2/O4
recount remain open; complete ISA-handler refinement count is 0.

Focused Lake passes 168 jobs and full Lake passes 295 jobs. Two public
type/axiom queries and one source query over all 32 actual low/high target
fields and byte offsets pass. Both theorems use ordinary
propext/Classical.choice/Quot.sound plus the existing imported
CC.externalFunctionsSem/CC.inlineAssemblySem; each external return is an
explicit premise, not an added semantic axiom. All 23 exports (243488732 bytes)
remain byte-identical to 9c617740f. Initial focused attempts exposed existential
binder syntax and a missing CC.Eapp unfolding; those errors and the passing
core/final checks remain in raw. Full Lake ran once on final proof source.

From kprog/formal, under timing SH, CPU17 or18, `ulimit -v 33554432`,
LEAN_NUM_THREADS=1 and default 200000 heartbeats/512 recursion depth:

```
lake build KProgFormal.ClightRefinement.Arm64ProducerVectorInputs
lake env lean -j1 results/m5-vector-input-sequence/Query.lean
lake env lean -j1 results/m5-vector-input-sequence/Next.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-vector-input-sequence. C, exports and frozen
benchmark paths are unchanged. Last complete native make check passed at
5236c0e9677f635526fdd515cde5195b2ba0810c; it was not repeated for this Lean-only
step. Actual M5/M6 completion still requires fresh full Lake and make check.
