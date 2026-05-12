# cond_select diamond external-predecessor fix

Date: 2026-05-12

## Root cause

`validate_diamond()` in `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs` rejects any diamond whose join block has a predecessor outside this set:

- `pattern.predecessor`
- `pattern.true_branch`
- `pattern.false_branch`

The failing check is the strict external-predecessor guard around `bbprogram_api.rs:790-803`. That guard was left unchanged.

`cond_select` can detect a local mov diamond whose apparent join is also reachable from another block. `pattern_a_for_site()` selects the shared successor of the taken/fallthrough blocks, and `pattern_c_for_site()` uses the taken block as the join. Before this fix, `run_on_bbprogram()` passed that pattern directly into `replace_diamond_with_insns()`, so `validate_diamond()` surfaced the invalid join as a hard bpfopt failure.

## Fix

Changed `bpfopt/crates/bpfopt/src/passes/cond_select.rs` only:

- `cond_select.rs:126-132`: after deriving the trial `DiamondPattern`, pre-check whether the selected join has an external predecessor. If yes, record a skipped site and do not call `replace_diamond_with_insns()`.
- `cond_select.rs:152-158`: repeat the same pre-check immediately before final replacement on the real program, and count only actually applied sites.
- `cond_select.rs:257-273`: added `external_join_predecessor_skip()`, which mirrors `validate_diamond()`'s allowed predecessor rule and returns the same diagnostic shape as a skip reason.

Added regression coverage:

- `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:148-164`: `cond_select_skips_diamond_join_with_external_predecessor` builds a cond-select pattern whose join also has an external predecessor, then verifies the pass returns `sites_applied == 0`, records an `external predecessor` skip, and leaves bytecode unchanged.

## Host Reproduction

Before the fix, this host-side testbin command reproduced the cilium failure:

```sh
cargo run -q --manifest-path bpfopt/Cargo.toml -p bpfopt -- \
  --pass cond_select \
  --input bpfopt/testbin/cilium_agent/159_cil_xdp_entry/canonicalize_output.bin \
  --output /tmp/cond_select_159_before.bin \
  --report /tmp/cond_select_159_before.json \
  --kinsns bpf_select64:5555
```

Observed pre-fix error:

```text
error: diamond join BlockId(28) has external predecessor BlockId(1)
```

After the fix, the same input succeeds and reports the site as skipped:

```json
{
  "pass": "cond_select",
  "sites_applied": 0,
  "sites_matched": 1,
  "sites_skipped": 1,
  "skip_reasons": {
    "diamond join BlockId(28) has external predecessor BlockId(1)": 1
  },
  "insn_count_before": 276,
  "insn_count_after": 276,
  "insn_delta": 0
}
```

I also scanned `bpfopt/testbin/cilium_agent/*/canonicalize_output.bin` with `cond_select`; all entries completed without bpfopt failure after the fix.

## Test Results

Targeted regression test:

```text
cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt --lib cond_select_skips_diamond_join_with_external_predecessor
test result: ok. 1 passed; 0 failed; 165 filtered out
```

Full requested lib test:

```text
cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt --lib
test result: ok. 166 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out
```
