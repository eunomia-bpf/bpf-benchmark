# Phase 3 BBProgram Migration Design Review - 2026-05-11

Verdict: NOT-CONVERGED

The filesystem-level delete happened and the main contract APIs mostly exist, but the migration is not converged. Production passes still contain PC/slot escape paths, local index arithmetic, pass-local JSON loading, direct BBProgram internals access, and no-op query/discard patterns. The release test gate also fails.

## Inputs Read

Read:
- `docs/tmp/p3_api_contract_2026-05-11.md`
- `docs/tmp/p3_fix_api_2026-05-11.md`
- `docs/tmp/p3_fix_heavypasses_2026-05-11.md`
- `docs/tmp/p3_fix_otherpasses_2026-05-11.md`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs`
- `bpfopt/crates/bpfopt/src/pass.rs`
- `bpfopt/crates/bpfopt/src/main.rs`
- `bpfopt/crates/bpfopt/src/insn.rs`
- `bpfopt/crates/bpfopt/src/analysis/mod.rs`

Pass files read end-to-end or by complete chunks:
- `passes/map_inline.rs`
- `passes/branch_flip.rs`
- `passes/ccmp.rs`
- `passes/const_prop.rs`
- `passes/wide_mem.rs`
- `passes/prefetch.rs`

## Part 1 - File Structure

- `ls bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs`: exit 2, file does not exist on disk.
- `analysis/mod.rs`: no `mod bbprogram_helpers` and no helper re-export.
- New helper-file check: `find ... '*helper*.rs' '*util*.rs' '*utilities*.rs'` found only existing `bpfopt/crates/bpfopt/src/test_helpers.rs`.
- `passes/` contains no `utilities.rs` or similar new helper file.

Assessment: filesystem delete phase is satisfied.

## Part 2 - Contract Forbidden-Pattern Greps

Commands were run exactly against `bpfopt/crates/bpfopt/src/passes/`.

Non-zero results:

1. `rg "VerifierInsn|PmuRecord|PrefetchProfile|VerifierOracle" bpfopt/crates/bpfopt/src/passes/`
   - `bpfopt/crates/bpfopt/src/passes/const_prop_tests.rs:8:fn run_const_prop(input: Vec<BpfInsn>, states: Vec<crate::pass::VerifierInsn>) -> PassRun {`
   - Assessment: test-only raw verifier fixture. Not a production pass violation, but it means the exact grep is not zero.

2. `rg "BlockId\(\d|FrameId\(\d" bpfopt/crates/bpfopt/src/passes/`
   - `bpfopt/crates/bpfopt/src/passes/map_inline/map_info_tests.rs:65:                site: InsnSite::for_test(BlockId(0), bindings.len()),`
   - Assessment: test-only and uses `InsnSite::for_test(...)`. Acceptable under the test exception.

Zero-result commands:

- `rg "oracle_at\b|profile_at\b|oracle\(\)" bpfopt/crates/bpfopt/src/passes/`
- `rg "site_current_pc\b|site_pc\b|block_start_pc\b|original_pc\b" bpfopt/crates/bpfopt/src/passes/`
- `rg "block_slot_|frame_relative_slot|program_slot_len|site_for_block_slot|block_range_for_slots" bpfopt/crates/bpfopt/src/passes/`
- `rg "replace_range\b" bpfopt/crates/bpfopt/src/passes/`
- `rg "block_body_len\b" bpfopt/crates/bpfopt/src/passes/`
- `rg "InsnSite\s*\{" bpfopt/crates/bpfopt/src/passes/`
- `rg "\.idx\s*[+\-]" bpfopt/crates/bpfopt/src/passes/`
- `rg "\b(\w+_slot|\w+_pc|\w+_offset|\w+_position|\w+_pos|pos_in_prog|prog_offset)\s*:\s*usize" bpfopt/crates/bpfopt/src/passes/`
- `rg "bbprogram_helpers" bpfopt/crates/bpfopt/src/`
- `rg "read_json_file" bpfopt/crates/bpfopt/src/passes/`

Important: the mandated greps miss several real production violations listed in Part 7.

## Part 3 - Escape, Bypass, Fallback Greps

Non-zero results:

1. `rg "\.ok\(\)" bpfopt/crates/bpfopt/src/`
   - `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:309:        let min = i64::try_from(state.range.umin?).ok()?;`
   - `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:310:        let max = i64::try_from(state.range.umax?).ok()?;`
   - Assessment: real violation of the no-`.ok()` rule. It silently turns conversion failure into absence of a typed verifier bound.

2. `rg "let _ =" bpfopt/crates/bpfopt/src/`
   - `bpfopt/crates/bpfopt/src/passes/const_prop.rs:345:        let _ = prog.reg_kind(site, reg);`
   - Assessment: real violation. This is a no-op typed-query discard.
   - `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1495:    let _ = prog;`
   - Assessment: real escape smell. It suppresses the unused argument in a pass-local PC-resolution stub that always bails.

3. `rg "fallback|FALLBACK|fall_back|fall-back" bpfopt/crates/bpfopt/src/`
   - `bpfopt/crates/bpfopt/src/verifier_log_tests.rs:303:fn extract_failure_pc_last_state_fallback() {`
   - `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:191:    // P1-H: operator hard hints are real side inputs, not fallback heuristics.`
   - `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:288:fn map_inline_pass_does_not_use_non_verifier_fixpoint_fallback() {`
   - Assessment: test-only wording, not production fallback logic.

Zero-result commands:

- `rg "unwrap_or_default\b" bpfopt/crates/bpfopt/src/`
- `rg "unwrap_or\(" bpfopt/crates/bpfopt/src/`
- `rg "#\[allow\(dead_code\)\]" bpfopt/crates/bpfopt/src/`
- `rg "#\[ignore\]" bpfopt/crates/bpfopt/src/`
- `rg "todo!\(\)|unimplemented!\(\)" bpfopt/crates/bpfopt/src/`

Additional escape findings not caught by the exact Part 3 patterns:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1228:    let _r2_kind = prog.reg_kind(call_site, BPF_REG_2);`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1229:    let _r2_bounds = prog.reg_proven_bounds(call_site, BPF_REG_2);`
- Assessment: no-op/discarded typed verifier queries.

## Part 4 - Gates

- `cd bpfopt && cargo build --release`: exit 0.
- `cd bpfopt && cargo test --release`: exit 101.
  - 188 lib tests ran before failure.
  - 171 passed, 17 failed, 0 ignored.
  - Failed tests:
    - `pass_tests::pipeline_pass_context_carries_verifier_states_between_passes`
    - `passes::const_prop_tests::const_prop_accepts_when_every_visit_agrees`
    - `passes::const_prop_tests::const_prop_folds_alu32_chain_to_mov32_imm`
    - `passes::const_prop_tests::const_prop_folds_alu_chain_to_constant_mov`
    - `passes::const_prop_tests::const_prop_post_state_guard_rejects_packet_pointer_copy_materialization`
    - `passes::const_prop_tests::const_prop_rejects_zero_divisor_without_panicking`
    - `passes::const_prop_tests::const_prop_tracks_ldimm64_constants`
    - `passes::const_prop_tests::const_prop_uses_verifier_exact_constants_for_alu_after_helper_calls`
    - `passes::dce_tests::dce_removes_dead_defs_exposed_by_const_prop_without_branch_cleanup`
    - `passes::map_inline_tests::map_inline_consumes_hint_when_verifier_state_unavailable`
    - `passes::map_inline_tests::map_inline_pass_does_not_use_non_verifier_fixpoint_fallback`
    - `passes::map_inline_tests::map_inline_rejects_hint_pointing_at_non_lookup_call`
    - `passes::map_inline_tests::map_inline_rejects_hint_with_wrong_key_size`
    - `passes::map_inline_tests::map_inline_route_a_rejects_missing_outer_entry_for_hint`
    - `passes::map_inline_tests::map_inline_soft_hint_requires_immediate_null_check_when_hard_fold_coexists`
    - `passes::mod_tests::map_inline_const_prop_dce_cascade_uses_one_bbprogram_pipeline`
    - `passes::prefetch_tests::prefetch_profile_filters_cold_map_value_site`
- `cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings`: exit 0.
- `cd bpfopt && cargo fmt --all --check`: exit 0.

## Part 5 - LOC Accounting

Command:

```text
find bpfopt/crates/bpfopt/src -name '*.rs' -not -name '*_tests.rs' -not -name 'test_helpers.rs' -not -name 'pass_tests.rs' -print0 | xargs -0 wc -l | tail -1
```

Result:

```text
18733 total
```

Baseline: 18994.

Net LOC delta: -261. This satisfies the strict-less-than-18994 LOC requirement.

## Part 6 - Design Goals Checklist

- [x] `bbprogram_helpers.rs` absent on disk.
- [x] No new helper file created under production source; only existing `test_helpers.rs` matched helper/util file search.
- [x] `BBProgram::all_sites()` exists and is public: `analysis/bbprogram.rs:131`.
- [x] `BBProgram::branch_target_entry_sites()` exists and is public: `analysis/bbprogram.rs:509`.
- [x] `BBProgram::replace_range_at(site, len, ...)` exists: `analysis/bbprogram_api.rs:49`.
- [x] Old public `replace_range(block, Range<usize>, ...)` is gone. Internal `replace_range_in_place` remains private.
- [x] `BBProgram::oracle_at` and `profile_at` are removed from public API.
- [x] Typed verifier queries exist: `reg_known_constant`, `reg_known_map_ptr`, `reg_proven_bounds`, `reg_kind`, `site_is_dead_code`.
- [x] Typed profile queries exist: `branch_taken_rate`, `branch_miss_rate`, `site_hotness`, `prefetch_hint`.
- [x] `PassReportSite`, `PassReportPc`, and `PassManager::finalize_reports` exist in `pass.rs`.
- [x] `BlockId.0`, `InsnSite.block`, `InsnSite.idx`, and `FrameId.0` are `pub(crate)`.
- [ ] `VerifierInsn / VerifierOracle / PmuRecord / PrefetchProfile / BtfMetadataMap` are all `pub(crate)`.
  - `VerifierOracle`, `BtfMetadataMap`, `PmuRecord`, and `PrefetchProfile` are crate-visible.
  - `VerifierInsn` is still public at `bpfopt/crates/bpfopt/src/verifier_log.rs:46`.
- [x] `block_slot_len`, `frame_relative_slot`, `program_slot_len`, `site_for_block_slot`, and `block_range_for_slots` are deleted from `analysis/`.
- [x] `site_current_pc`, `block_start_pc`, and `original_pc` are `pub(crate)`.
- [x] `main.rs` report serialization calls `PassManager::finalize_reports(...)` at `main.rs:1122` and `main.rs:1155`; `main.rs` does not call `site_current_pc` directly.
- [~] Part 2 production-pass greps are clean, but exact full `passes/` greps are not zero because of two test-only matches.
- [x] Net LOC is 18733, which is less than 18994.

## Part 7 - Remaining Lazy-Rename and Escape Patterns

These are production issues not caught, or not fully caught, by the contract greps.

### 1. `map_inline` Still Owns PC-Addressed Hints

Production lines:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:26:    Pc(usize),`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:146:        let pc = input`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:149:        return Ok(MapInlineHintAnchor::Pc(pc));`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:216:        MapInlineHintAnchor::Pc(pc) => pc.to_string(),`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1494:fn lookup_call_site_at_pc(prog: &BBProgram, pc: usize) -> anyhow::Result<Option<InsnSite>> {`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1497:        "pc-addressed map_inline hints must be resolved before pass execution; unresolved pc {pc}"`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1688:                MapInlineHintAnchor::Pc(call_pc) => {`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1689:                    let site = lookup_call_site_at_pc(prog, *call_pc)?.ok_or_else(|| {`

Assessment: real violation. Even though `lookup_call_site_at_pc` fails fast, the pass still parses, stores, and tries to resolve PC-addressed hints. The contract says passes never access PC/slot directly and PC conversion/reporting is single-point in `PassManager::finalize_reports`.

### 2. `map_inline/map_info.rs` Still Materializes Slots/PCs

Production lines:

- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:78:    pub slot: usize,`
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:110:    pc_load: usize,`
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:158:            let pc = program.rep_site_slot(site).map_err(|err| err.to_string())?;`
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:163:                pc_load: pc,`
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:218:                "negative pseudo-map index {} at pc {}",`
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:225:                    "pseudo-map index {} at pc {} out of range for {} map ids",`
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:246:            slot: binding.pc_load,`

Assessment: real violation. This is a renamed PC/slot channel inside production pass code. It also depends on `BBProgram::rep_site_slot`, a crate-visible method that computes slot/PC-like positions for passes.

### 3. `map_inline` Still Has Pass-Local JSON Loading

Production lines:

- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:6:use serde::Deserialize;`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:8:use std::fs;`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:19:fn read_json_from_path<T: serde::de::DeserializeOwned>(path: &Path, label: &str) -> Result<T> {`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:20:    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:21:    serde_json::from_slice(&data)`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:460:    let show: BpftoolMapShowJson = read_json_from_path(&show_path, "bpftool map show JSON")?;`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:478:        fs::read(&dump_path).with_context(|| format!("failed to read {}", dump_path.display()))?;`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:940:            read_json_from_path(Path::new(value), "prog_info JSON")?;`

Assessment: real violation. The exact grep for `read_json_file` is clean only because the function was renamed. The contract says passes that previously read JSON must consume side-input metadata already attached to `BBProgram` at lift time.

### 4. Production Passes Still Use Local `idx + N` / Position Arithmetic

Examples from targeted grep:

- `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:14:    pub(super) start_idx: usize,`
- `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:59:        if idx + len_a <= n && match_wide_mem_low_first(insns, idx, dst, base, first_off, width) {`
- `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:124:        let idx = start_idx + 3 * (i as usize - 1) + 1;`
- `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:346:            let end_idx = start_idx + site.old_len;`
- `bpfopt/crates/bpfopt/src/passes/rotate.rs:159:    if idx + 3 > insns.len() {`
- `bpfopt/crates/bpfopt/src/passes/rotate.rs:263:    let shift0 = &insns[idx + 1];`
- `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:334:    let mut cursor = idx + 2;`
- `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:366:    let last_idx = idx + old_len - 1;`
- `bpfopt/crates/bpfopt/src/passes/ccmp.rs:358:        let expected_fallthrough = match chain.get(idx + 1) {`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4078:    let sites = prog.all_sites().collect::<Vec<_>>();`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4087:    for &site in &sites[min_removed_pos..=lookup_pos] {`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4872:    let sites = prog.all_sites().collect::<Vec<_>>();`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4873:    let mut pos = position_in_sites(&sites, non_null_site)?;`

Assessment: real design drift. Some of this is pattern-local slice matching, but the design goal says passes never do `idx + N` arithmetic. `map_inline` is more severe because it builds whole-program order vectors and slices them by positions.

### 5. Passes Directly Access BBProgram Internal Fields

Production lines:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:478:        .ldimm64_second_slots`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4334:                .ldimm64_second_slots`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4454:        .ldimm64_second_slots`

Assessment: real API escape. `BBProgram` has a crate-visible `ldimm64_second_slot(...)` method, but production passes are reading the backing field directly.

### 6. Raw Verifier Surface Is Still Public at the Crate Boundary

Production lines:

- `bpfopt/crates/bpfopt/src/verifier_log.rs:46:pub struct VerifierInsn {`
- `bpfopt/crates/bpfopt/src/verifier_log.rs:17:pub enum VerifierInsnKind {`
- `bpfopt/crates/bpfopt/src/verifier_log.rs:24:pub enum VerifierValueWidth {`
- `bpfopt/crates/bpfopt/src/verifier_log.rs:30:pub struct Tnum {`
- `bpfopt/crates/bpfopt/src/verifier_log.rs:35:pub struct ScalarRange {`
- `bpfopt/crates/bpfopt/src/verifier_log.rs:56:pub struct RegState {`
- `bpfopt/crates/bpfopt/src/verifier_log.rs:96:pub struct StackState {`
- `bpfopt/crates/bpfopt/src/pass.rs:22:pub use crate::verifier_log::{`

Assessment: `VerifierInsn` fails the explicit checklist item. The related raw verifier types also remain publicly re-exported through `pass.rs`, which keeps broad raw verifier surface available even if production passes currently do not use it.

## Part 8 - Sample File Inspection

### `passes/map_inline.rs`

Subtle violations:

- PC hint path remains in the pass (`MapInlineHintAnchor::Pc`, `lookup_call_site_at_pc`).
- Pass-local JSON loader remains (`read_json_from_path`, `fs::read`, `serde_json::from_slice`).
- No-op typed verifier query discards remain (`_r2_kind`, `_r2_bounds`).
- Whole-program position vectors and `pos` loops remain in lookup-pattern/null-check windows.
- Direct `ldimm64_second_slots` field access remains.
- Tests demonstrate breakage from the PC-hint fail-fast stub: multiple map-inline tests fail with `pc-addressed map_inline hints must be resolved before pass execution; unresolved pc 5`.

### `passes/branch_flip.rs`

Subtle violations:

- Production file is clean against the mandatory greps and uses typed profile queries.
- It still depends on BBProgram pass-specific helpers (`bf_*`) and ordered `BlockId` comparisons. This is not an exact grep failure, but the branch-shape logic is still coupled to physical block adjacency/order through a renamed API layer.

### `passes/ccmp.rs`

Subtle violations:

- Mandatory greps are clean.
- It still does local `idx + 1` and `idx - 1` arithmetic over `chain` positions at `ccmp.rs:358` and `ccmp.rs:370`. This is not site `.idx`, but it violates the broad "passes never do idx + N arithmetic" goal.
- Uses `site.start_site.block` in production, which is allowed by `pub(crate)` but means opacity is enforced only by convention inside the crate.

## Top 5 Remaining Issues

1. Release tests fail: `cargo test --release` exits 101 with 17 failing tests.
2. `map_inline` still owns PC-addressed hint parsing/resolution and fails tests through the `lookup_call_site_at_pc` stub.
3. `map_inline/map_info.rs` still exposes and computes PC/slot-like values via `rep_site_slot`, `pc_load`, and `MapReference.slot`.
4. `map_inline` still reads JSON directly in pass code through a renamed helper, bypassing the BBProgram side-input boundary.
5. Multiple production passes still use local index/position arithmetic and some passes directly access BBProgram internals (`ldimm64_second_slots`).

## Final Assessment

The migration is structurally part-way complete: the old helper file is absent, the intended public BBProgram methods mostly exist, and build/clippy/fmt pass. It is not converged because core design goals remain violated and the release test suite fails.

