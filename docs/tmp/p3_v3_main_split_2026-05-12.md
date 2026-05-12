# Phase 3 V3 main.rs split report

## LOC

Production LOC measured with:

```bash
rg --files bpfopt/crates/bpfopt/src | rg '\.rs$' | rg -v '(^|/)(.*tests\.rs|test_helpers\.rs)$' | xargs wc -l
```

| Area | Before | After | Delta |
| --- | ---: | ---: | ---: |
| `crates/bpfopt/src/main.rs` | 1815 | 710 | -1105 |
| `crates/bpfopt/src/passes/map_inline.rs` | 2945 | 2947 | +2 |
| `crates/bpfopt/src/passes/map_inline/cli.rs` | 0 | 844 | +844 |
| `crates/bpfopt/src/analysis/bbprogram_lift.rs` | 472 | 679 | +207 |
| `crates/bpfopt/src/analysis/bbprogram_lower.rs` | 229 | 229 | 0 |
| `crates/bpfopt/src/pass.rs` | 775 | 854 | +79 |
| Total production LOC | 17497 | 17527 | +30 |

`main.rs` is below the requested `<1100` LOC threshold.

## Moves

- Moved `map_inline` pass-local CLI parsing and bpftool/compressed map JSON parsing into `crates/bpfopt/src/passes/map_inline/cli.rs`.
- Added `bpfopt::passes::map_inline::attach_cli_side_input(common, ctx, pass_args)` as the CLI-facing pass entry.
- Moved FD-to-IDX canonicalization and target module call-offset shifting into `crates/bpfopt/src/analysis/bbprogram_lift.rs`.
- Moved shared `CommonArgs`, `TargetJson`, and `KinsnJson` into `pass.rs` so library pass code can accept the real common CLI args without a new side-input module.

## Gates

- `cargo build --release`: passed.
- `cargo test --release`: passed. Summary: 178 lib tests, 13 bin tests, 1 bbprogram roundtrip integration test, 12 CLI integration tests, 0 doc tests.
- `cargo clippy --release --all-targets -- -D dead_code -D warnings`: passed.
- `cargo fmt --all && cargo fmt --all --check`: passed.

## Sanity Checks

```text
$ wc -l crates/bpfopt/src/main.rs
710 crates/bpfopt/src/main.rs
```

```text
$ rg "read_map_values|read_bpftool_map_|parse_inline_hint|parse_compressed_map|decode_compressed_|canonicalize_map_refs_to_idx" crates/bpfopt/src/main.rs
bpfopt::analysis::canonicalize_map_refs_to_idx(&mut insns, None, &common.map_ids)?;
```

## Dedup

No optional decode-path dedup was done. The refactor intentionally preserves existing map snapshot parsing logic and error text while moving ownership to the `map_inline` pass module.
