# Entry-name proof history

These two original Lean inputs retain the private declaration-number uniqueness
and parameter/temporary-prefix disjointness theorems from the earlier ARM entry
analysis. They moved intact from build/; each original theorem stays available
here. Active entry and allocation proofs live in ClightRefinement/.

The accompanying cleanup removed fifteen historical diagnostic import/axiom-print
and symbol/count-query sources from build/. Their commands inspect declarations;
semantic tests remain in oracles/, tools/ and the proof library. Original result
outputs and raw run evidence remain in their existing result locations.
`build/BpfABILayout.lean` stays with its generating Make target.

The exact path/size action inventory is retained in
`/workspaces/kprog-raw/V/x86-alu-decode-20261122/scratch-cleanup.json` and
[the cleanup log](../../../docs/cleanup-log.md). This source relocation preserves
the active make-check recipes and theorem statements.
