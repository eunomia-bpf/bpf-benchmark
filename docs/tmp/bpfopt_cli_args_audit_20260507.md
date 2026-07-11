# bpfopt CLI Args Audit - 2026-05-07

Scope: `bpfopt/crates/bpfopt/src/main.rs`, `pass.rs`, `passes/*.rs`, `runner/libs/`, and `daemon/src/`.

## CLI args

| arg | current owner | current consumers | classification | notes |
| --- | --- | --- | --- | --- |
| `--pass` | `main.rs` | CLI dispatch | framework-shared | Selects exactly one pass. Not pass-local. |
| `--input` | `main.rs` | all passes through `BpfProgram::insns` | framework-shared | Raw bytecode input. |
| `--output` | `main.rs` | all passes through final bytecode write | framework-shared | Raw bytecode output. |
| `--report` | `main.rs` | all passes through `PassResult` serialization | framework-shared | Pass-agnostic reporting envelope. |
| `--platform` | `main.rs` -> `PassContext.platform.arch` | `ccmp`, `endian_fusion`; indirectly `cond_select` via `has_branchless_select` | framework-shared | Platform context, not a concrete pass flag. |
| `--prog-type` | `main.rs` -> `PassContext.prog_type` | `wide_mem`, `bounds_check_merge`, `skb_load_bytes_spec`, `prefetch` | framework-shared | Multiple pass safety filters. |
| `--koperation` | `main.rs` -> `PassContext.kop_registry` | kop passes: `rotate`, `cond_select`, `ccmp`, `extract`, `endian_fusion`, `bulk_memory`, `prefetch` | framework-shared | Target capability input. |
| `--target` | `main.rs` -> `PassContext.platform` / `KopRegistry` | same kop passes as `--koperation` | framework-shared | Target JSON side input. |
| `--verifier-states` | `main.rs` -> `BpfProgram.verifier_states` | `map_inline`, `const_prop`, `wide_mem` | framework-shared | Used by multiple passes. |
| `--func-info` | `main.rs` -> `BpfProgram.func_info` | BTF metadata remap helpers called by many rewriting passes | framework-shared | Remapped whenever instruction offsets change. |
| `--func-info-rec-size` | `main.rs` | paired with `--func-info` | framework-shared | ABI size for shared BTF side input. |
| `--line-info` | `main.rs` -> `BpfProgram.line_info` | BTF metadata remap helpers called by many rewriting passes | framework-shared | Remapped whenever instruction offsets change. |
| `--line-info-rec-size` | `main.rs` | paired with `--line-info` | framework-shared | ABI size for shared BTF side input. |
| `--map-values` | `main.rs` -> map snapshot fields on `BpfProgram` | `map_inline` only | pass-local | Move parsing and validation to `passes/map_inline.rs`; runner should place after `--`. |
| `--map-ids` | `main.rs` -> `BpfProgram.map_ids` / `map_fd_bindings` | `map_inline` / `MapInfoAnalysis` only | pass-local | Move to `passes/map_inline.rs`; only map-inline resolves pseudo-map references. |
| `--profile` | `main.rs` -> `ProfilingData` / annotations | `branch_flip`; optional `prefetch` profile filter | pass-local | Move profile parsing into `branch_flip.rs` and `prefetch.rs`; `main.rs` should not know profile schema. |

## `BpfProgram` fields

| field | consumers | classification | action |
| --- | --- | --- | --- |
| `insns` | all analyses and passes | shared | Keep. |
| `annotations` | framework remap; currently profile payloads for `branch_flip` / `prefetch` | mixed | Keep vector for remapping, but branch/prefetch profile payloads are pass-local and should move out. |
| `transform_log` | written by many passes, not read | dead | Delete with `TransformEntry` / `log_transform`. |
| `map_ids` | `map_inline` and `MapInfoAnalysis` only | pass-local | Move to map-inline input. |
| `map_fd_bindings` | `map_inline` and `MapInfoAnalysis` only | pass-local | Move to map-inline input, computed from map-inline `--map-ids`. |
| `branch_miss_rate` | `branch_flip` only | pass-local | Move into `BranchFlipPass` profile input. |
| `cache_miss_rate` | parsed and stored, never read | dead | Delete. |
| `verifier_states` | `const_prop`, `map_inline`, `wide_mem`; invalidated by pass manager | shared | Keep. |
| `func_info` | BTF remap helpers used by kop/rewriting passes | shared | Keep. |
| `line_info` | BTF remap helpers used by kop/rewriting passes | shared | Keep. |
| `map_values` | `map_inline`, test mock provider | pass-local | Move to map-inline input. |
| `map_inner_map_ids` | `map_inline` only | pass-local | Move to map-inline input. |
| `map_bpf_writable` | `map_inline` only | pass-local | Move to map-inline input. |
| `map_snapshots_skipped_by_size` | `map_inline`, test mock provider | pass-local | Move to map-inline input. |
| `map_metadata` | `map_inline`, test mock provider | pass-local | Move to map-inline input. |
| `map_provider` | `map_inline`, test mock provider | pass-local | Move to map-inline input/test harness. |

## Pass input paths

| pass | current inputs read | notes |
| --- | --- | --- |
| `noop` | none | Produces verifier log only through daemon `log_level=2`. |
| `map_inline` | `program.verifier_states`, `program.map_*`, `MapInfoAnalysis` | Map snapshot and map ids are pass-local. Verifier states are shared. |
| `const_prop` | `program.verifier_states` | Shared verifier-state side input. |
| `dce` | instruction stream / analyses | No CLI-specific input. |
| `skb_load_bytes_spec` | `ctx.prog_type` | Shared program type. |
| `bounds_check_merge` | `ctx.prog_type` | Shared program type. |
| `wide_mem` | `ctx.prog_type`, optional `program.verifier_states` | Shared safety inputs. |
| `bulk_memory` | `ctx.kop_registry`, BTF remap metadata | Shared target/BTF inputs. |
| `rotate` | `ctx.kop_registry`, BTF remap metadata | Shared target/BTF inputs. |
| `cond_select` | `ctx.has_branchless_select()`, `ctx.kop_registry`, BTF remap metadata | Shared target/platform inputs. |
| `ccmp` | `ctx.platform.arch`, `ctx.kop_registry`, BTF remap metadata | Shared target/platform inputs. |
| `extract` | `ctx.kop_registry`, BTF remap metadata | Shared target input. |
| `endian_fusion` | `ctx.platform.arch`, `ctx.kop_registry`, BTF remap metadata | Shared target/platform inputs. |
| `branch_flip` | `program.branch_miss_rate`, `program.annotations[*].branch_profile` | Profile is pass-local; current main-level parsing leaks branch-flip schema. |
| `prefetch` | `ctx.prog_type`, `ctx.kop_registry`, optional `program.annotations[*].prefetch_profile` | Target/prog type shared; optional profile filter is pass-local. |

## Command assembly

| location | current behavior | required sync |
| --- | --- | --- |
| `runner/libs/rejit_plan.py::build_step_spec` | Builds `bpfopt --pass <name> ...` and appends `--map-values` / `--map-ids` before any `--`. | Insert `--` before pass-local args. Keep shared args before `--`. Add `${PASS_LOCAL_ARGS}` placeholder after `--` for future pass-local args. |
| `daemon/src/commands.rs` | Substitutes known `${VAR}` placeholders and executes runner-provided command through `sh -c`; no bpfopt-specific builder exists here. | Add a known empty `${PASS_LOCAL_ARGS}` substitution variable so command templates can reserve `-- ${PASS_LOCAL_ARGS}` without failing validation. |
| `runner/libs/rejit.py` | Uses `rejit_plan` payload; no direct bpfopt command assembly. | No direct change beyond generated plan. |

