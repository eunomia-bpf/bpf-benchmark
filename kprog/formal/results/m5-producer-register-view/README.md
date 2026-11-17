# One producer execution establishes the register view

`Arm64ProducerRegisterView.producer_registers_initialized` assembles the
existing `Arm64Registers.Represents` relation from one actual linked
638-transition header/loop execution. All 31 word/tag cells, SP, 32 vector
pairs and four flags use the same reached memory and its nextblock. Actual
allocation bindings identify the source data; pointer-valued cells and every
tag bit remain available to the existing provenance materialization.

SP uses header index 5, offset 40, and the signed-long local `___a64_sp`.
The unsigned numeric stack cache is a different source at index 2, offset 16.
The proof transports the SP load through the existing other-local preservation
and borrowed-field reader. Caller contents, both permission maps, access and
nextblock remain framed.

Provider data, pointer origins, the native architectural cell map, GPR
materialization and SP-origin equality are explicit premises. This proves a
conditional source-to-register relation, not production input admissibility
or complete architectural memory, events, faults or control correspondence.
The host environment fixture explicitly selects zero for kinds 1/3/6; the
stock B/checker input header supplies volatile mutable-map scalar reads.
These source routes do not establish equality with an arbitrary native entry
state. Their include selection, external-call outcomes and actual invocation
ABI must be traced before discharging the premises. No continuation body or
provider outcome is fabricated. M5 and remaining M6 are open; complete
ISA-handler refinement count is 0 and O1/O2/O4 recount remains pending.

Focused Lake passes 166 jobs and full Lake passes 293 jobs. The public
type/axiom query and the source SP/cache ABI example pass. The theorem uses
ordinary propext/Classical.choice/Quot.sound plus the already imported
CC.externalFunctionsSem/CC.inlineAssemblySem through InternalRun; no provider
or assembly body executes here. All 23 exports (243488732 bytes) remain
byte-identical to 9c617740f. All checks pass on their first attempt with
unchanged proof limits.

From kprog/formal, under timing SH, CPU17 or18, `ulimit -v 33554432`,
LEAN_NUM_THREADS=1 and default 200000 heartbeats/512 recursion depth:

```
lake build KProgFormal.ClightRefinement.Arm64ProducerRegisterView
lake env lean -j1 results/m5-producer-register-view/Query.lean
lake env lean -j1 results/m5-producer-register-view/Next.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-producer-register-view. Simulator C,
exports and frozen benchmark paths are unchanged. Last native make check
passed at 5236c0e96 and was not repeated for this Lean-only change. Fresh full
Lake and make check remain required at actual M5/M6 completion.
