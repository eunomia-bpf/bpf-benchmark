# bpfopt Pass Side-Input Matrix

Date: 2026-05-01

结论：默认 pipeline 应恢复为 12 个 pass，daemon 不要求调用方 opt-in side-input。daemon 根据 pass 依赖自动准备：

- `verifier-states.json`：`map_inline`、`const_prop`
- `map-values.json` + `--map-ids`：`map_inline`
- `target.json` + ReJIT `fd_array` kinsn BTF fd/call offset：`rotate`、`cond_select`、`extract`、`endian_fusion`、`bulk_memory`、`prefetch`，以及非默认 `ccmp`
- PMU profile：非默认 `branch_flip` 必须显式 profile；`prefetch` 可消费 profile，但缺 profile 时按结构规则运行，不是 daemon 必需 side-input

## Matrix

| pass | default 12 | implementation dependencies | daemon side-input action |
|---|:---:|---|---|
| `wide_mem` | yes | bytecode; `branch_targets`; `liveness`; `ctx.prog_type` for packet pointer safety | Pass `--prog-type` from snapshot. No verifier states or map values. |
| `rotate` | yes | bytecode; `branch_targets`; `liveness`; `ctx.kinsn_registry`; kinsn call offsets | Probe `target.json`; build kinsn fd_array entries and call offsets. |
| `cond_select` | yes | bytecode; `branch_targets`; `ctx.platform.has_cmov`; `ctx.kinsn_registry`; kinsn call offsets | Probe `target.json`; build kinsn fd_array entries and call offsets. |
| `extract` | yes | bytecode; `branch_targets`; `ctx.kinsn_registry`; kinsn call offsets | Probe `target.json`; build kinsn fd_array entries and call offsets. |
| `endian_fusion` | yes | bytecode; `branch_targets`; `ctx.platform.arch`; endian kinsn availability/call offsets | Probe `target.json`; build kinsn fd_array entries and call offsets. |
| `map_inline` | yes | bytecode; `branch_targets`; `map_info`; `program.map_ids`; `program.map_fd_bindings`; live map metadata/values; `program.verifier_states` for lookup key extraction | Snapshot maps, write `map-values.json`, pass `--map-ids`, and capture `verifier-states.json` automatically. |
| `const_prop` | yes | bytecode; `cfg`; `program.verifier_states` exact scalar facts | Capture `verifier-states.json` automatically. |
| `dce` | yes | bytecode; `cfg`; optional offline func/line metadata remap if caller supplied it | No daemon side-input beyond bytecode. It does not read verifier states. |
| `bounds_check_merge` | yes | bytecode; `cfg`; `branch_targets`; `liveness`; `ctx.prog_type` packet layout | Pass `--prog-type` from snapshot. It does not read verifier states. |
| `skb_load_bytes_spec` | yes | bytecode; `branch_targets`; `ctx.prog_type` for TC skb layout | Pass `--prog-type` from snapshot. No verifier states. |
| `bulk_memory` | yes | bytecode; `branch_targets`; `liveness`; memcpy/memset kinsn availability/call offsets | Probe `target.json`; build kinsn fd_array entries and call offsets. |
| `prefetch` | yes | bytecode; `cfg`; `branch_targets`; `ctx.prog_type`; prefetch kinsn availability/call offsets; optional `prefetch_profile` annotations | Probe `target.json`; build kinsn fd_array entries and call offsets. Pass profile only when one is loaded. |
| `ccmp` | no | bytecode; `branch_targets`; `liveness`; `ctx.platform.arch == aarch64`; `ctx.kinsn_registry`; kinsn call offsets | If explicitly requested, probe `target.json`; build kinsn fd_array entries and call offsets. |
| `branch_flip` | no | bytecode; `branch_targets`; program-level `branch_miss_rate`; per-site `branch_profile` with count/miss/taken/not-taken | Requires loaded real PMU profile. Missing profile remains fail-fast. |

## Audit Notes

- `const_prop.rs` reads `program.verifier_states` through `VerifierExactConstOracle::from_states()`.
- `map_inline.rs` reads `program.verifier_states` in `try_extract_constant_key_verifier_guided()` for first-round lookup key extraction, and reads map metadata/value snapshots through `program.map_provider`.
- `dce.rs` only consumes CFG and performs optional BTF metadata remap on already-attached offline metadata; daemon no longer supplies BTF func/line metadata on the live path.
- `bounds_check_merge.rs` has its own local `RegValue` dataflow and does not consume verifier state snapshots.
- `prefetch.rs` uses profile data only when the caller loaded PMU data; lack of PMU data is not a failure for `prefetch`.
- `branch_flip.rs` remains outside default 12-pass policy and must fail if real program-level or per-site PMU data is missing.
