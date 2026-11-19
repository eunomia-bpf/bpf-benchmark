# Actual call entry and initial temporaries

The production wrapper's emitted signature is one __sk_buff* argument with
signed32 tint return. The proof checks that signature and its inequality
with the borrowed uint32 consumer signature. Actual local/parameter names
and parameter/temporary disjointness justify FunctionEntry2. One imported
internal step reaches the real function start, actual allocation environment,
initial context temporary and allocation memory, with caller framing and
all actual local Freeable ranges.

The wrapper symbol/function binds at block88; native_lab_entry_input binds
at block59 with the full existing external function/signature. Actual locals
do not shadow it. The old producer helper's block64 is not a production
binding. Symbol resolution and internal entry are packaged together.

All131 mapped initialization temporaries, including the named counter,
agree with the extracted producer entry and are initially undefined. Context
lookup also agrees for arbitrary context and source continuation values.
Source consumer-only t131 and the continuation parameter are outside this
compared domain. Generic lookup laws for declared names and context updates
avoid expanding the large concrete temporary trees during elaboration.

Final focused check passes172 jobs. One full Lake passes347 jobs. Fourteen
public type/axiom queries pass. Entry/binding/frame/temp laws use standard
logical axioms; internal execution inherits the Step2 abstract external
semantics. No new axiom, evaluator, C fixture or external transition is added.
Failed focused attempts are retained raw: concrete temporary-tree comparison
hit recursion limits, and zero-offset function lookup needed exposure.
The original heartbeat/recursion limits are unchanged.

Run from kprog/formal on CPU17, LEAN_NUM_THREADS=1, 32 GiB AS:

```
lake build KProgFormal.ClightRefinement.Arm64ProgramEntryCall
lake env lean -j1 results/m5-program-entry-call/Query.lean
lake env lean -j1 results/m5-program-entry-call/Inspect.lean
lake build
```

Host work follows the coordinator's2026-11-19T18:18:59Z CPU8–23 rule without
the timing lock. C/runtime/benchmark settings are unchanged. Export/native
checks remain historical receipts identified separately in validation.json.

Entry reaches fn_body; the existing638-step suffix starts at beforeHeader.
The intervening actual pre-header prefix still needs execution and supplies
initialized table/SP/register values and frontier equality. These results
are not composed by skipping that prefix, and do not establish native
original-context admission. Next is the initial189 ABI/local assignments
and four cache stores, then input setup/providers at the actual block59.
M5/M6 remain open, completed ISA-family count stays zero. Final M6 retirement
and fresh full Lake plus make check follow completed M5.

Raw: /workspaces/kprog-raw/formal/m5-program-entry-call
