# map_inline Issue 1+2 unlock diagnosis - 2026-05-06

Artifact: `corpus/results/x86_kvm_corpus_20260506_055112_303407/details/result.json`
and per-app detail `details/apps/tracee__monitor.json`.

## Summary

The Issue 1+2 smoke did not unlock helper lookup inlining because the stack
snapshot path is wired in code but still unreachable for Tracee's real verifier
side input. The daemon/kernel-sys JSON writer preserved `stack` and explicit
`precise`, but `kernel_sys::convert_verifier_states()` filtered out full-state
verifier snapshots whenever the log also contained instruction-delta states.
Tracee lookup keys are exposed at full-state call-PC snapshots, so bpfopt saw no
state at the helper call PCs and returned before the new stack-snapshot extractor
could run.

Issue 2 did run: the old `map type 13 not inlineable` bucket disappeared from
Tracee's map-in-map sites and became map-in-map-specific skip reasons. It still
did not apply because the same missing call-PC state blocked outer-key recovery,
and because `find_map_in_map_chains()` only followed R0 through registers, not
through a stack spill/reload before the inner helper call.

## Artifact facts

`tracee/monitor` has 158 programs in the ReJIT result: 121 `ok`, 37 `error`.
The same run has 35 snapshot errors of the form:

`build live map value snapshot for prog X: scan live keys for map 155: BPF_MAP_GET_NEXT_KEY for map 155 returned more than max_entries=10240`

For successful `map_inline` steps:

```
sites_applied = 133
sites_matched = 2515
sites_skipped = 2382
direct pseudo-map-value diagnostics = 133
helper "inlined successfully" diagnostics = 0
```

Grouped skip reasons from `bpfopt_summary.skip_reasons`:

```
1283  lookup key unavailable
 985  map-in-map outer no call-pc state
  61  map-in-map chain not inlineable
  53  map-in-map outer after prior rewrite
```

The 53 "after prior rewrite" sites are not a separate first-round root cause.
They are final-round fallout after direct pseudo-map-value rewrites changed the
program and `map_inline` correctly refused stale verifier-state key extraction
on the next fixpoint round.

## Code-path diagnosis

Daemon wiring is present. `daemon/src/commands.rs:770-772` writes
`rejit_report.verifier_states` after each successful log-level-2 ReJIT and then
uses that path as `${VERIFIER_STATES}` for the next pass. The `map_inline`
command receives `--verifier-states ${VERIFIER_STATES}` and `--map-values
${MAP_VALUES}` via `daemon/src/commands.rs:590-601`.

The JSON schema is also present. `bpfopt/crates/kernel-sys/src/lib.rs:194-202`
contains `VerifierInsnJson { pc, frame, stack, regs }`, and
`bpfopt/crates/kernel-sys/src/lib.rs:397-408` serializes stack slots. The
explicit precise flag is serialized in
`bpfopt/crates/kernel-sys/src/lib.rs:438-447`. bpfopt reads `stack` at
`bpfopt/crates/bpfopt/src/main.rs:931-943` and reads explicit `precise` at
`bpfopt/crates/bpfopt/src/main.rs:994-1001`.

The actual data loss is one layer earlier in the JSON writer selection.
Before this fix, `bpfopt/crates/kernel-sys/src/lib.rs:378-386` computed
`has_delta` and then dropped every non-`InsnDeltaState` when any instruction
delta was present. That removes `from ... to <call_pc>:` and `<pc>: R...`
full-state snapshots, exactly the forms documented by the parser at
`bpfopt/crates/kernel-sys/src/verifier_log.rs:4-8`.

bpfopt then filters for exact call-PC states before it can inspect stack bytes:
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:313-323` returns
`verifier log has no state snapshot at call pc N` when no state with
`state.pc == call_pc` survives. The stack-snapshot branch itself starts only
after that at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:378-386`.

Issue 2's map-in-map path is reached. `run_map_inline_round()` diverts
`HASH_OF_MAPS` / `ARRAY_OF_MAPS` sites through `build_map_in_map_chain_rewrite()`
at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:831-885`; the artifact's
map-in-map-specific skip reasons prove that path ran. The remaining chain
detector gap is in `find_map_in_map_chain_for_outer()`:
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:170-217` tracks aliases in
registers only. It lacks the stack spill/reload handling that
`classify_r0_uses_with_options()` already has at
`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2532-2600`.

## Fixes implied

1. Preserve non-branch full-state verifier snapshots in verifier-state JSON and
   carry their kind through the bpfopt reader so `const_prop` can continue to use
   only instruction deltas while `map_inline` can consume call-PC full states.
2. Add a regression test where `map_inline` extracts a stack-snapshot key from a
   full-state verifier snapshot, not only from the synthetic call-PC delta states
   used by existing tests.
3. Teach map-in-map chain detection to follow an outer R0 map-value alias through
   a stack spill/reload into R1 before the inner lookup.

Expected unlocked opportunity in this Tracee artifact is the 2,382 currently
skipped helper sites above, plus the 35 programs that become evaluable after the
inner-map snapshot overflow fix. Actual applied count can still be lower if a
site later fails value presence, use classification, or verifier acceptance.
