# Producer GPR tables to borrowed-entry reads

`Arm64ProducerGprView.lean` follows the existing consumer reader through the
actual header word/tag roots, both pointer-table slots and both cell loads.
The table stride is eight bytes, with 31 slots and a 248-byte extent. The
last slot begins at 240. All reader bounds come from successful imported
loads through the preceding checked-load theorem.

Allocation lookup uniqueness identifies the same table blocks across the
producer's independently chosen HeaderSourceLocal and TableLocals records.
The reader retains the loaded Clight value, including a pointer-valued union
cell, and all eight tag bits. It creates no pointer-to-number conversion or
architectural register map.

The actual 638-transition header/loop result now exposes all 31 value/tag
pairs through Arm64EntryMemory.gpr at the reached memory's nextblock. The
proof transports table/cell readbacks through the existing other-local
preservation and retains exact caller framing, access and nextblock.
Pre-header table/data readbacks at real allocation bindings remain explicit
source obligations. The intervening provider/initialization chain is not
silently composed.

The source query retains actual allocation bindings for register30's zero
word/tag cell and checks its real 196-transition initialization/table segment.
This is a C source fact, not native LR admissibility. Architectural cell maps,
physical origins, provider semantics and LR/SP/zero-register behavior still
need the actual invocation ABI. SP/vector source views, architectural memory/
events/faults/control, the real continuation and full handler migration/recount
remain M5, then remaining M6. Complete ISA-handler refinement count stays zero.

Focused Lake passes 164 jobs. Three public type/axiom queries and four source
queries pass: header/table ABI, all 31 slot offsets, the bound register30
source segment and explicit linked-world reached-memory readbacks. Two reader
facts use only propext/Classical.choice/Quot.sound; producer_gprs_initialized
also mentions the imported CC.externalFunctionsSem/CC.inlineAssemblySem.
Full Lake passes 291 jobs; all 23 exports (243488732 bytes) stay byte-identical
to 9c617740f. Default proof limits remain unchanged. Raw retains the first
local record-index normalization failure and both successful query versions.

From kprog/formal, run each command under timing SH, CPU17 or18,
`ulimit -v 33554432`, LEAN_NUM_THREADS=1 and default200000heartbeats/512recDepth:

```
lake build KProgFormal.ClightRefinement.Arm64ProducerGprView
lake env lean -j1 results/m5-producer-gpr-view/Query.lean
lake env lean -j1 results/m5-producer-gpr-view/Next.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-producer-gpr-view. Production C, exports
and frozen benchmark paths stay unchanged. Native make check last passed at
5236c0e96, not repeated for this Lean-only step; fresh full Lake and make check
are still required at actual M5/M6 completion.
