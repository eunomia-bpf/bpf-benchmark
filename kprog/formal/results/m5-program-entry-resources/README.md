# Actual reached-body resources

The actual 638-step header/loop result now derives Freeable ranges for every
actual local using its actual declared type and world size. STACK and RETURN
borrowed cache-storage contracts refer to the same reached header block and
the actual allocation frontier. Original context-temp preservation is explicit.
All 92 readbacks, other temporaries/local loads, caller framing, permissions
and allocation frontier preservation remain at the same reached body memory.
No C steps or input-provider executions are added.

Resources contains exactly the derived permission and cache-address facts.
It does not claim initialized GPR table slots, an SP value or cold cache
contents from arbitrary starting contents. The cache frontier is the actual
allocation's nextblock. The transition preserves before.nextblock; equality
of that arbitrary starting frontier with the allocation frontier is still
for actual preceding-prefix execution to establish. Full register Storage,
architectural views and native admission therefore remain separate obligations.

The proof reuses imported AllocVariables/local-storage permission laws,
source/actual allocator memory equality and the checked header-cache law.
It assumes no equality of whole composite environments or new caller-supplied
storage outcome. The reached statement is the real EntrySource.body, with
actual callback values60/61 retained in the existing tail readbacks.

Focused validation passes171 jobs; one full Lake passes346 jobs. Six public
type/axiom queries pass. Permission/cache/resource laws use standard logical
axioms. The reached InternalRun retains the imported Step2 abstract external
semantics; no new axiom or external transition is added. Original heartbeat,
recursion, worker and memory limits are unchanged.

Run from kprog/formal on CPU17, LEAN_NUM_THREADS=1, 32 GiB AS:

```
lake build KProgFormal.ClightRefinement.Arm64ProgramEntryResources
lake env lean -j1 results/m5-program-entry-resources/Query.lean
lake build
```

Host work follows the coordinator's2026-11-19T18:18:59Z rule for CPUs8–23
without the timing lock. C/runtime/benchmark settings are unchanged. Historical
export/native checks are identified in validation.json and were not repeated.

Next is the actual one-argument call entry and initial temporaries, then real
pre-header table/input/scalar execution and value/frontier admission. M5/M6
remain open, completed ISA-family count stays zero. O1/O2/O4, M6 retirement
and final fresh full Lake plus make check remain before goal completion.

Raw: /workspaces/kprog-raw/formal/m5-program-entry-resources
