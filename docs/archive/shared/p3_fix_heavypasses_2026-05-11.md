# Phase 3 Heavy Pass Migration Report - 2026-05-11

Scope:
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs`
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs` (in-scope subdir fix)
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs`
- `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs`

## Delete + Migrate Log

### map_inline

Delete:
- Removed `program_sites`, `control_flow_target_sites`, and `read_json_file` imports from `map_inline.rs`.
- Removed `oracle_at`-based verifier stack snapshot extraction and deleted the raw `VerifierInsn` / `StackState` byte recovery helpers.
- Removed `original_pc_to_site`, `program_slot_len`, and direct `BlockId.0` arithmetic uses from `map_inline.rs`.
- Removed `program_sites` from `map_inline/map_info.rs`.

Migrate:
- Replaced whole-program iteration with `prog.all_sites()`.
- Replaced branch target helper use with `prog.branch_target_entry_sites()`.
- Replaced raw verifier lookup during key extraction with typed `prog.site_is_dead_code`, `prog.reg_kind`, and `prog.reg_proven_bounds` queries plus existing bytecode materialization recovery.
- Replaced instruction count reporting with `prog.all_sites().count()`.
- Replaced fallthrough-adjacent block arithmetic with ordered block `windows(2)`.
- Replaced `read_json_file` call sites with a pass-local JSON reader named `read_json_from_path`.
- Replaced subdir `program_sites(program)` with `program.all_sites()`.

Self-rating: not-A. `map_inline.rs` is off the deleted raw verifier/helper APIs, but PC-addressed inline hints now fail fast inside the pass because the new contract has no pass-facing original-PC lookup; that should be resolved at the boundary by the API/main job.

### const_prop

Delete:
- Removed the local `VerifierExactConstOracle`, accumulator, raw verifier post-state, and `VerifierValueWidth` machinery.
- Removed direct `verifier_states_at` access and `program_sites` import.
- Removed all `BlockId.0` indexing by replacing block-indexed vectors with `BTreeMap<BlockId, ...>`.

Migrate:
- Replaced verifier facts with `prog.reg_known_constant`, `prog.reg_known_map_ptr`, `prog.reg_kind`, and `prog.site_is_dead_code`.
- Kept replacements at `prog.replace_range_at(site, 1, replacement)`.
- Reworked dataflow state storage to be keyed by opaque `BlockId`.

Self-rating: A. The pass no longer sees raw verifier state and uses typed BBProgram queries for verifier-derived facts.

### bulk_memory

Delete:
- Removed the remaining `block_body_len` use from range validation.
- Removed the old `analysis` import path for `advance_reg_state` / `SimpleRegValue`.

Migrate:
- Uses `prog.sites_in_block(block)?.len()` for range validation.
- Imports `advance_reg_state` / `SimpleRegValue` from `crate::insn` per the API contract.
- Existing site-based replacement flow remains `prog.replace_range_at(start, len, replacement)`.

Self-rating: not-A. The pass is clear of the required deleted patterns, but its variable-length run matcher still uses local body-index cursors rather than a full `sites_in_block(...).windows(N)` rewrite.

## Grep Results

All required greps over the three pass files returned no matches (rg exit 1):

```text
rg "VerifierInsn|PmuRecord|PrefetchProfile" map_inline.rs const_prop.rs bulk_memory.rs
rg "oracle_at\b|profile_at\b|oracle\(\)" map_inline.rs const_prop.rs bulk_memory.rs
rg "site_current_pc\b|site_pc\b|block_start_pc\b|original_pc\b" map_inline.rs const_prop.rs bulk_memory.rs
rg "block_slot_|frame_relative_slot|program_slot_len|site_for_block_slot|block_range_for_slots" map_inline.rs const_prop.rs bulk_memory.rs
rg "replace_range\b" map_inline.rs const_prop.rs bulk_memory.rs
rg "InsnSite\s*\{" map_inline.rs const_prop.rs bulk_memory.rs
rg "BlockId\(\d|FrameId\(\d" map_inline.rs const_prop.rs bulk_memory.rs
rg "\.idx\s*[+\-]" map_inline.rs const_prop.rs bulk_memory.rs
rg "\b(\w+_slot|target_slot|allowed_slot|expected_slot)\s*:\s*usize" map_inline.rs const_prop.rs bulk_memory.rs
rg "bbprogram_helpers" map_inline.rs const_prop.rs bulk_memory.rs
rg "read_json_file" map_inline.rs const_prop.rs bulk_memory.rs
```

Additional checks:

```text
rg "program_sites|bbprogram_helpers|read_json_file" bpfopt/crates/bpfopt/src/passes/map_inline
rg "block_body_len\b" map_inline.rs const_prop.rs bulk_memory.rs
```

Both returned no matches.

## Formatting

- Ran scoped formatting with:

```text
rustfmt --edition 2021 bpfopt/crates/bpfopt/src/passes/map_inline.rs bpfopt/crates/bpfopt/src/passes/const_prop.rs bpfopt/crates/bpfopt/src/passes/bulk_memory.rs
rustfmt --edition 2021 bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs
```

- `cd bpfopt && cargo fmt --all --check` currently exits 1 due only to out-of-scope files touched by parallel jobs: `analysis/bbprogram.rs`, `analysis/mod.rs`, and `pass.rs`. I did not run mutating workspace-wide fmt to avoid rewriting other jobs' files.

## Build

Command:

```text
cd bpfopt && cargo build --release
```

Final result: exits 101. Current errors are out of this job's pass-file scope:

```text
branch_flip.rs: hidden impl Iterator lifetime needs explicit capture
analysis/bbprogram.rs: block_slot_bounds missing
analysis/bbprogram.rs: frame_slot_bounds missing
analysis/bbprogram.rs: block_slot_bounds missing in rep_site_slot
wide_mem.rs: RegKind::is_btf_struct_ptr missing
```

An earlier build also exposed `map_inline/map_info.rs` importing deleted `program_sites`; that in-scope subdir issue was fixed before the final build above.

## LOC

Initial counts were captured before edits in this job.

```text
map_inline.rs: 5070 -> 4985 (-85)
const_prop.rs: 777 -> 488 (-289)
bulk_memory.rs: 788 -> 785 (-3)
map_inline/map_info.rs: 270 -> 270 (0)
```
