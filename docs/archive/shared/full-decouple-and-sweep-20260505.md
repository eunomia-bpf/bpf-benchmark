# Full Decouple And Sweep, 2026-05-05

Baseline: `c510c6465355f234dc2e1ec01a36be652e23f1d4` (`origin/main`, bgv5s8aii phase 1).

## LoC Delta

| File | Added | Deleted | Net |
| --- | ---: | ---: | ---: |
| `bpfopt/crates/bpfopt/src/main.rs` | 10 | 10 | 0 |
| `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs` | 0 | 32 | -32 |
| `bpfopt/crates/bpfopt/tests/cli_pipeline.rs` | 3 | 3 | 0 |
| `daemon/src/commands.rs` | 37 | 266 | -229 |
| `daemon/src/server.rs` | 0 | 1 | -1 |
| `scripts/p88_branch_flip_dense_pgo.sh` | 2 | 2 | 0 |
| `docs/tmp/full-decouple-and-sweep-20260505.md` | 61 | 0 | +61 |
| Total | 113 | 314 | -201 |

Net delta is `-201` lines on top of baseline `c510c6465355`.

## Opaque Boundary

Daemon has zero field-level reads of bpfopt summaries. `daemon/src/commands.rs:614`-`645` runs `bpfopt --pass` and reads the report file as one `serde_json::Value`; `daemon/src/commands.rs:656`-`667` stores that value verbatim in `PassDetail.bpfopt_summary`, or `null` when no bpfopt report exists.

Verification search returned no matches:
`rg -n "bpfopt_summary\\.get|Value::as_|collect_inlined_map_entries|InlinedMapEntry|inlined_map_entries" daemon/src runner/libs/rejit.py corpus/driver.py tests/python`

Remaining daemon `hex_bytes()` call sites only generate `map-values.json` side input for bpfopt; they do not parse or format bpfopt report content.

## Deleted Items

Baseline line references are from `c510c6465355`.

- `daemon/src/commands.rs:133`: `OptimizeOneResult.inlined_map_entries`
- `daemon/src/commands.rs:158`: `InlinedMapEntry`
- `daemon/src/commands.rs:262`: daemon-local `TargetJson`
- `daemon/src/commands.rs:298`: `collect_inlined_map_entries()`
- `daemon/src/commands.rs:341`: `required_json_string()`
- `daemon/src/commands.rs:731`: `pass_detail_from_report()`
- `daemon/src/commands.rs:745`: `pass_detail_without_report()`
- `daemon/src/commands.rs:868`: `missing_target_kops()`
- `daemon/src/commands.rs:906`: `target_has_any()`
- `daemon/src/commands.rs:910`: `push_missing_target()`
- `daemon/src/commands.rs:1088`: `push_unique()`
- `daemon/src/commands.rs:1094`: `canonical_pass()`
- `daemon/src/commands.rs:1207`: `timeout_for_stage()`
- `daemon/src/commands.rs:1260`: `duration_label()`
- `daemon/src/commands.rs:1269`: `stage_failure_message()`
- `daemon/src/commands.rs:1278`: `returncode_label()`
- `daemon/src/commands.rs:1286`: `stderr_summary()`
- `daemon/src/commands.rs:1309`: shallow ReJIT-chain test
- `daemon/src/server.rs:305`: deleted field construction in test
- `bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:594`: duplicate alias test

## Confirmations

- bpfopt emits `bpfopt_summary.inlined_map_entries[]` with `map_id`, `key_hex`, and `value_hex`; see `bpfopt/crates/bpfopt/src/main.rs:167` and `bpfopt/crates/bpfopt/src/main.rs:1170`-`1183`.
- noop bootstrap hint is preserved in `PassDetail.error` for `SkippedMissingStates`; see `daemon/src/commands.rs:473`-`480`.
- `cargo test --release --workspace --manifest-path bpfopt/Cargo.toml`: 405 tests passed.
- `cargo test --release --workspace --manifest-path daemon/Cargo.toml`: 25 daemon tests passed; `bpfget` has 0 tests.
- `python -m pytest tests/python/ -v`: 17 tests passed, 1 subtest passed.
- Commit hash: final pushed commit hash is in the task final response. Embedding a commit's own SHA in the committed file would change that SHA.
