# Phase 3 Other Passes Migration, 2026-05-11

Scope: 12 lighter pass files only.

## Per-Pass Log

| pass file | delete log | migrate log | rating |
| --- | --- | --- | --- |
| `dce.rs` | No legacy helper/oracle/profile/range/identity patterns were present. | Already BBProgram-native through `def_sites`, `uses_for_def`, `sites_in_block`, and `delete_insn`. | A |
| `noop.rs` | No legacy patterns were present. | No mutation or query migration needed. | A |
| `wide_mem.rs` | Removed `control_flow_target_sites`, `oracle_at`, raw verifier `reg_type` inspection, old `replace_range`, direct `InsnSite` construction, and block `.0` adjacency. | Uses `branch_target_entry_sites`, `reg_kind`, `replace_range_at`, and `sites_in_block` site vectors for cross-block windows. | A |
| `extract.rs` | Removed old `replace_range` and `next_site_in_block` adjacency. | Uses `sites_in_block(...).windows(2)`, pass-local next-site window lookup, and `replace_range_at`. | A |
| `endian.rs` | Removed `BlockId`/`Range` safe-site fields, old `replace_range`, and `next_site_in_block` adjacency. | Safe sites carry `InsnSite`; matching uses site-window lookup; mutation uses `replace_range_at`. | A |
| `rotate.rs` | No required legacy grep patterns remained. | Existing migration keeps mutation at `replace_range_at`; local slice indices are pattern-local only, not BBProgram identity construction. | A |
| `skb_load_bytes.rs` | Removed analysis-helper imports for control-flow targets, packet layout, and simple-reg transfer alias. | Uses `branch_target_entry_sites`; packet layout/simple reg utilities are consumed through `insn::*` per contract. | A |
| `cond_select.rs` | Removed residual `block_body_len` dependency and body-first helper use. | Uses `sites_in_block` for body length and first body sites; existing reports are site-keyed. | A |
| `ccmp.rs` | Removed old `replace_range`, `block_body_len`, and pass-side remap helper dependency. | Uses `replace_range_at`; after split/merge it derives current `BlockId`s from BBProgram structure. | A |
| `branch_flip.rs` | Removed pass-local JSON reader, `read_json_file`, profile JSON structs, `HashMap` PC maps, `profile_at`, `control_flow_target_sites`, and all pass-side `BlockId.0` arithmetic/construction. | Uses typed `branch_taken_rate`, `branch_miss_rate`, `site_hotness`, `branch_target_entry_sites`, explicit `Vec<BlockId>` arm membership, and site-keyed skips. | A |
| `prefetch.rs` | Removed pass-local JSON reader, `read_json_file`, profile JSON structs, `PrefetchProfile` use, `profile_at`, and `program_sites`. | Uses `all_sites`, `prefetch_hint`, `site_hotness`, and `replace_range_at`; profile side inputs are expected to arrive attached to BBProgram. | A |
| `bounds_check_merge.rs` | Removed analysis-helper imports for control-flow targets and packet layout. | Uses `branch_target_entry_sites` and `sites_in_block_with_terminator` for entry-site checks. | A |

## Grep Results

All required greps were run over exactly the 12 scoped pass files. Every command returned zero matches (`rg` exit 1, no output):

- `rg "VerifierInsn|PmuRecord|PrefetchProfile|VerifierOracle" ...`
- `rg "oracle_at\b|profile_at\b|oracle\(\)" ...`
- `rg "site_current_pc\b|site_pc\b|block_start_pc\b|original_pc\b" ...`
- `rg "block_slot_|frame_relative_slot|program_slot_len|site_for_block_slot|block_range_for_slots" ...`
- `rg "replace_range\b" ...`
- `rg "InsnSite\s*\{" ...`
- `rg "BlockId\(\d|FrameId\(\d" ...`
- `rg "\.idx\s*[+\-]" ...`
- `rg "\b(\w+_slot|target_slot|allowed_slot|expected_slot)\s*:\s*usize" ...`
- `rg "bbprogram_helpers" ...`
- `rg "read_json_file" ...`

Additional contract hygiene grep also returned zero matches:

- `rg "next_site_in_block|block_first_body_site|first_site_in_block|block_body_len\b|\b[a-zA-Z_][a-zA-Z0-9_]*\.idx\b|\b[a-zA-Z_][a-zA-Z0-9_]*\.0\b|control_flow_target_sites|program_sites|advance_reg_state as|ctx\.verifier_states|verifier_states" ...`

## LOC

| file | before | after |
| --- | ---: | ---: |
| `dce.rs` | 92 | 92 |
| `noop.rs` | 22 | 22 |
| `wide_mem.rs` | 536 | 516 |
| `extract.rs` | 163 | 174 |
| `endian.rs` | 445 | 446 |
| `rotate.rs` | 441 | 441 |
| `skb_load_bytes.rs` | 299 | 296 |
| `cond_select.rs` | 667 | 670 |
| `ccmp.rs` | 516 | 530 |
| `branch_flip.rs` | 587 | 478 |
| `prefetch.rs` | 586 | 485 |
| `bounds_check_merge.rs` | 558 | 557 |
| total | 4912 | 4707 |

## Formatting

Formatted only the 12 scoped files with `rustfmt ...` to avoid touching parallel-job files outside this assignment.

## Build

`cd bpfopt && cargo build --release`: failed after scoped pass compile errors were resolved.

Latest failure is out of scope:

- `crates/bpfopt/src/main.rs:315`: `program.attach_side_inputs(...)` calls a private `BBProgram::attach_side_inputs` method (`E0624`), defined `pub(crate)` in `analysis/bbprogram.rs`.

The lib target also emitted dead-code warnings in out-of-scope API/lifecycle code (`map_ids`, old profile attach helpers, remap helpers, `pf_attach_prefetch_profiles`, etc.).
