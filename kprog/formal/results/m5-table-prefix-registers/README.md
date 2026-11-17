# x30 zero and the pointer tables feed the register proof

`Arm64ProducerTablesToRegisters.tables_to_registers` starts before the actual
x30 declaration. Its 10-transition zero branch followed by 186 transitions of
real pointer-table stores supplies both complete 31-slot tables and x30's zero
payload. These are no longer initial-memory premises. The earlier x0 payload
is also unrestricted because RAW entry later overwrites it with context.

The proof composes register30_initialized and pointer_tables_initialized once
each, retaining their other-local readback preservation. Earlier x1..x29 scalar
words and tags survive both runs. Allocation lookup uniqueness identifies the
actual x30 block; its zero read feeds the existing GPR-source relation.
The real resultTemp update preserves _ctx through a checked distinct-name fact.

The resulting silent 196-transition prefix composes with the existing flag,
vector and RAW execution. Its 68 provider traces remain in source order, and
the existing register relation holds in one reached memory and frontier.
Caller contents, both permission maps, access and nextblock remain framed.
The x30 zero payload later receives RETURN tag 10 and materializes through the
explicit native return origin; this does not require a zero native address.

Earlier x1..x29 source data/tags, provider availability and native invocation
bits/origins remain explicit. Physical pointer aliasing/ABI, architectural
memory/events/fault/control, program continuation and complete handlers/recount
remain open. M5/M6 remain open; complete ISA-handler refinement count is 0.

Focused Lake passes 170 jobs and full Lake passes 297 jobs. The public theorem
type/axiom query passes. Its axiom list contains only ordinary
propext/Classical.choice/Quot.sound and the already imported external/assembly
semantics used by the suffix. No external call executes in the new prefix;
the suffix's returns remain explicit provider premises. Existing primitive
source/ABI queries cover the unchanged C, so no duplicate source test is added.
All 23 exports (243488732 bytes) remain byte-identical to 9c617740f. Initial
parsing rejected the reserved local name prefix; renaming it to prefixRun
fixed that attempt. All logs remain raw; full Lake ran once on final source.

From kprog/formal, under timing SH, CPU17 or18, `ulimit -v 33554432`,
LEAN_NUM_THREADS=1 and default 200000 heartbeats/512 recursion depth:

```
lake build KProgFormal.ClightRefinement.Arm64ProducerTablesToRegisters
lake env lean -j1 results/m5-table-prefix-registers/Query.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-table-prefix-registers. C, exports and frozen
benchmark paths are unchanged. Last complete native make check passed at
5236c0e9677f635526fdd515cde5195b2ba0810c; it was not repeated for this Lean-only
step. Actual M5/M6 completion still requires fresh full Lake and make check.
