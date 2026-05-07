# DCE simplify + const_prop counters - 2026-05-06

## Diff summary

- `bpfopt/crates/bpfopt/src/passes/dce.rs`
  - Removed DCE's local `eliminate_unreachable_blocks_with_cfg` pass and its `compose_addr_maps` plumbing.
  - Removed DCE's local fixed-point `eliminate_nops` pass.
  - DCE now only calls `eliminate_dead_register_defs`, reports only `removed N dead-def insns`, and no longer requires CFG analysis.
  - Removed stale DCE unit tests that asserted unreachable-block, NOP, subprog, and orphaned-subprog cleanup.
  - Kept `dce_removes_dead_defs_exposed_by_const_prop`; it now asserts `sites_applied == 4` and expects the folded `ja +0` to remain for kernel cleanup.

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs`
  - Added PassReport diagnostic counters:
    - `const_prop_alu_materialized=N`
    - `const_prop_branch_folded_taken=N`
    - `const_prop_branch_folded_not_taken=N`
    - `const_prop_cleanup_removed_insns=N`
  - Counters are derived from `replacements` and the internal unreachable cleanup delta.
  - Added unit coverage for ALU materialization and taken/not-taken branch folding counters.
  - Updated the folded-jump DCE test to keep `ja +0`, because DCE no longer removes NOPs.

- `bpfopt/crates/bpfopt/src/passes/mod_tests.rs`
  - Removed the stale cascade test that attributed dead-branch cleanup to DCE.
  - Updated the full-pipeline cascade expectation to keep `ja +0`.

- `bpfopt/crates/bpfopt/src/main.rs`
  - Verification unblocker: `--verifier-states` now accepts explicit JSON verifier-state files when the input starts with `{`; invalid JSON exits with an error. Raw verifier logs still use `kernel_sys::verifier_states_from_log`.
  - This was needed because existing CLI tests provide verifier-state JSON fixtures.

No changes were made to `passes/utils.rs`, `map_inline.rs`, or the daemon.

## Cargo verification

- `cargo build -p bpfopt --release`: passed.
  - Release binary path: `bpfopt/target/release/bpfopt`.
- `cargo test -p bpfopt`: passed.
  - lib tests: 360 passed.
  - main tests: 12 passed.
  - CLI tests: 10 passed.
  - doc tests: 0.

## Smoke result

Command:

```sh
BPFREJIT_CORPUS_APPS="cilium/agent" SAMPLES=1 make vm-corpus
```

Result: failed, exit code 2.

Artifact:

```text
corpus/results/x86_kvm_corpus_20260507_005728_910124
```

Runner error:

```text
BPF stats missing requested program IDs: 111, 114, 118, 119, 124, 127, 135, 136, 140
```

The app artifact has:

```json
{
  "app": "cilium/agent",
  "baseline": null,
  "post_rejit": null,
  "rejit_result": {},
  "status": "error"
}
```

The failed `result.json` contains no `bpfopt_summary`, no pass diagnostics, and no `const_prop_*` counters. Per fail-fast, I did not change smoke parameters or run a fallback workload.

## const_prop counter values

Smoke per-app values are not available from this run because the suite failed during baseline measurement before ReJIT/pass summaries were produced.

Unit-level counter checks passed:

| test | alu_materialized | branch_folded_taken | branch_folded_not_taken | cleanup_removed_insns |
| --- | ---: | ---: | ---: | ---: |
| `const_prop_folds_alu_chain_to_constant_mov` | 1 | 0 | 0 | 0 |
| `const_prop_folds_constant_branches_to_ja_and_nop` | 0 | 1 | 1 | 1 |

## DCE sites_applied comparison

Smoke before/after `dce.sites_applied` comparison is not available because this run did not produce `bpfopt_summary`.

Unit-level after-simplification check:

| test | dce sites_applied | note |
| --- | ---: | --- |
| `dce_removes_dead_defs_exposed_by_const_prop` | 4 | dead-def removal still fires; folded `ja +0` remains for kernel nop cleanup |

The removed DCE cleanup tests are intentionally not comparable after this change, because unreachable-block and NOP cleanup are no longer DCE responsibilities.

## Conclusion

No branch-folding policy decision should be made from this smoke run. The required cilium result did not reach ReJIT summaries, so the `branch_folded_taken/not_taken` share is unknown. Do not delete const_prop branch folding for next step #3 based on this run; rerun the same smoke once the `BPF stats missing requested program IDs` failure is resolved.
