# Actual producer call through all 98 input visits

`Arm64ProducerGprInputs.gpr_inputs_initialized` traverses all 30 actual GPR
input declarations, including x0's call even though RAW context setup later
overwrites its payload. Each returned word and scalar tag 0 is read back from
the actual allocated cell. Both inputTemp and resultTemp updates are threaded;
other temporary names, previously initialized cells, source locals and caller
resources survive the explicitly framed provider outcomes and C stores.

`gpr_inputs_to_registers` composes those 30 visits with the actual x30-zero,
pointer-table, four-flag, 64-vector and RAW-header execution. It derives the
existing register relation in one reached memory with exactly 98 provider
traces in source order. No initial GPR/tag/table/flag/vector contents are
assumed. _ctx survives every actual input/result temporary update; x30's zero
payload materializes through the separate native return origin.

`producer_registers_initialized` starts at the actual producer Callstate with
ctx and continuation parameters. The existing 580-transition allocation/cache
prefix plus nine-transition RAW setup reaches declaration 0 before its call.
The 30-visit traversal therefore executes the first call prefix once. The
whole source execution reaches afterVectorLoop with the same register relation,
all 98 traces, exact caller contents/both permission maps, and the allocated
frame's access map and nextblock. This stops before calling the continuation;
no program-body edge or mismatched function ABI is fabricated.

Each provider condition retains the actual linked externalCall, returned word,
supplied post-memory and required frame/access/nextblock facts at the visited
memory. Supplied memory is not forced equal to input memory. These conditions
still need invocation witnesses. Native context/GPR input bits, stack/return
origins and pointer ValueRep remain explicit. Physical pointer aliasing/ABI,
native memory/events/fault/control, program continuation and complete handler
migration/recount remain open. M5/M6 remain open; complete ISA-handler refinement
count is 0.

Focused Lake passes 171 jobs and full Lake passes 298 jobs. Three public
type/axiom queries pass. Their axiom lists contain only ordinary
propext/Classical.choice/Quot.sound plus the existing imported external/assembly
semantics; provider returns are explicit premises. No new semantic axiom is
introduced. All 23 exports (243488732 bytes) remain byte-identical to 9c617740f.
The initial traversal and 98-visit composition passed directly. Adding the
entry prefix first exposed an unresolved metavariable in a simp argument;
an explicitly typed parameter-name inequality fixed it at unchanged limits.
All logs remain raw; full Lake ran once on final proof source. Unchanged
primitive source/ABI checks are not duplicated here.

From kprog/formal, under timing SH, CPU17 or18, `ulimit -v 33554432`,
LEAN_NUM_THREADS=1 and default 200000 heartbeats/512 recursion depth:

```
lake build KProgFormal.ClightRefinement.Arm64ProducerGprInputs
lake env lean -j1 results/m5-gpr-input-sequence/Query.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-gpr-input-sequence. C, exports and frozen
benchmark paths are unchanged. Last complete native make check passed at
5236c0e9677f635526fdd515cde5195b2ba0810c; it was not repeated for this Lean-only
step. Actual M5/M6 completion still requires fresh full Lake and make check.
