# Phase 3 BBProgram migration fresh-eyes review after fresh2

Date: 2026-05-10
Branch reviewed: `main`
Scope: read `CLAUDE.md`, `docs/bbprogram-architecture-design.md`, current `bpfopt/crates/bpfopt/src/**/*.rs`, plus the explicitly requested `runner/config/passes/dce/default.yaml` and gate inputs. I did not read prior `docs/tmp/p3_*.md` reports.

## Verdict

**NOT-CONVERGED.**

The build/test/clippy/smoke gates pass and the non-test LOC claim is correct at 19,230. However convergence criteria are not met:

- Issue (A1) is not fully fixed: `BBProgram.entry` is still public at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:30-36`.
- The 9-pass kinsn/admission dedup claim is only partially true: the shared helper exists and six kinsn replacement passes use it, but `prefetch` emits a kfunc without the helper at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:274-280`; `wide_mem` and `skb_load_bytes` are pure-BPF replacements rather than kinsn replacements.
- Per-pass convergence is not all A. Only `noop` and `dce` are A by the requested rubric; the other 13 passes still use PC bridge, current linear site order, branch-target site sets, block-local flat scans, or PC-keyed profile/oracle data.
- CLAUDE production scan found one production `expect()` in `bpfopt/crates/bpfopt/src/main.rs:438-441`.
- Short-file audit found six non-pass testing-infrastructure files <=80 LOC with <=30 tests that should be inlined.

## A. Six Issue Verification

### 1. Public field encapsulation

**FAIL.** Most target fields were restricted, but `entry` remains public.

- `BBProgram.blocks`, `use_def`, `oracle`, `btf`, and `kinsn_reg` are `pub(super)` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:30-36`.
- `BBProgram.entry` is still `pub entry: BlockId` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:30-36`.
- `Block.insns` and `Block.terminator` are `pub(super)` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:47-51`.

### 2. PC bridge API restricted

**PASS for the named raw bridge API.** The named raw bridge exists only inside analysis internals; pass bodies do not call `current_site_pcs` directly.

- `BBProgram::current_site_pcs` is `pub(super)` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:373-377`.
- The private helper is `fn current_site_pcs(...)` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1005-1025`.
- The BTF boundary caller is `old_pc_to_current_pc` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:130-134`.

Important residual: pass bodies still use the public PC bridge wrappers (`report_pc`, `ordered_site_pcs`, `current_sites`, `branch_target_sites`, `block_start_pc`). That does not fail this specific named-function check, but it prevents A-level convergence in section D.

### 3. 9 passes kinsn dedup

**PARTIAL / FAIL as written.**

Shared helper:

- `AdmittedKinsnWindow` and `admit_kinsn_site_window` live at `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:38-67`.
- The helper calls `prog.report_pc(start)` and `kinsn_replacement_subprog_skip_reason(...)` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:44-60`.

Passes that use the helper:

- `rotate`: import and call at `bpfopt/crates/bpfopt/src/passes/rotate.rs:6` and `bpfopt/crates/bpfopt/src/passes/rotate.rs:93-95`.
- `extract`: import and call at `bpfopt/crates/bpfopt/src/passes/extract.rs:6` and `bpfopt/crates/bpfopt/src/passes/extract.rs:130-132`.
- `endian_fusion`: import and call at `bpfopt/crates/bpfopt/src/passes/endian.rs:6` and `bpfopt/crates/bpfopt/src/passes/endian.rs:391-397`.
- `bulk_memory`: import and call at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:6-7` and `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:232-238`.
- `cond_select`: import and call at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:7` and `bpfopt/crates/bpfopt/src/passes/cond_select.rs:157-164`.
- `ccmp`: import and call at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:4` and `bpfopt/crates/bpfopt/src/passes/ccmp.rs:191-198`.

Passes that do not use the helper:

- `prefetch` emits `emit_packed_kinsn_call_with_off(...)` through a direct zero-length `replace_range` at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:274-280`.
- `wide_mem` is a pure-BPF replacement using `emit_wide_mem` at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:645-646`.
- `skb_load_bytes` is a pure-BPF replacement using `emit_replacement` at `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:105-115`.

If the requirement is literally "each of the nine listed files calls the shared kinsn admission helper", it is not satisfied. If `wide_mem` and `skb_load_bytes` are intentionally out of scope because they do not emit kinsn calls, the audit criterion should say that explicitly.

### 4. cond_select/ccmp error split

**PASS.** Pattern misses return `Ok(None)` / `Option`, while structural validation failures still `bail!`.

- `cond_select` scan calls `try_match_pattern_a` and `try_match_pattern_c`, both returning `anyhow::Result<Option<CondSelectSite>>`, at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:295-333` and `bpfopt/crates/bpfopt/src/passes/cond_select.rs:391-394`.
- `cond_select` pattern misses return `Ok(None)` through the matcher bodies at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:334-372` and `bpfopt/crates/bpfopt/src/passes/cond_select.rs:395-429`.
- `cond_select` real validation errors use `anyhow::bail!` in diamond construction at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:211-219`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:226-250`, and `bpfopt/crates/bpfopt/src/passes/cond_select.rs:260-278`.
- `ccmp` scan calls `try_match_ccmp_chain`, returning `anyhow::Result<Option<CcmpSite>>`, at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:368-392`.
- `ccmp` pattern misses return `Ok(None)` in `try_match_ccmp_chain` and `branch_term` at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:398-416` and `bpfopt/crates/bpfopt/src/passes/ccmp.rs:457-490`.
- `ccmp` real validation errors use `anyhow::bail!` at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:297-313`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:316-362`, and payload validation at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:516-538`.

### 5. Zero-caller deletions

**PASS for the named items.**

- `rg "BtfRecordsView|LinearInsnSite|PassManager" bpfopt/crates/bpfopt/src/` returned no matches.
- `PassManager` is not present. The remaining registry is `PassRegistryEntry` / `PASS_REGISTRY` at `bpfopt/crates/bpfopt/src/passes/mod.rs:46-57` and `bpfopt/crates/bpfopt/src/passes/mod.rs:129-147`.

Residual public API concern: `run_*_on_bbprogram` reexports exist at `bpfopt/crates/bpfopt/src/passes/mod.rs:22-40`, and exact-name search only found those definitions. If these are not consumed outside this workspace-internal crate, they are zero-caller public API debt.

### 6. yaml section 11.5

**PASS.** The YAML was not reverted; the architecture doc documents it as an accepted exception.

- `runner/config/passes/dce/default.yaml` passes `--target ${TARGET}` at `runner/config/passes/dce/default.yaml:4-6`.
- The design doc explicitly documents the accepted exception for `runner/config/passes/dce/default.yaml` at `docs/bbprogram-architecture-design.md:362-367`.

## B. Gates

All requested gates passed.

| Gate | Result | Evidence |
|---|---:|---|
| `cargo build --release --manifest-path bpfopt/Cargo.toml` | PASS | Finished release profile in 0.12s. |
| `cargo test --release --manifest-path bpfopt/Cargo.toml` | PASS | 217 total tests passed: 188 lib + 16 main + 1 roundtrip + 12 CLI. |
| `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings` | PASS | Finished release profile with no diagnostics. |
| `target/release/bpfopt list-passes` | PASS | Listed 15 passes: `noop`, `map-inline`, `const-prop`, `dce`, `skb-load-bytes`, `bounds-check-merge`, `wide-mem`, `bulk-memory`, `rotate`, `cond-select`, `ccmp`, `extract`, `endian`, `branch-flip`, `prefetch`. Registry source is `bpfopt/crates/bpfopt/src/passes/mod.rs:131-147`. |
| DCE smoke command | PASS | Exit code `0`. |
| Non-test LOC command | PASS | `19230 total`, under the 19,500 target. |

## C. Short-File Audit

Files <=80 LOC from `find bpfopt/crates/bpfopt/src -name '*.rs' -exec wc -l {} +`:

| File | LOC | Test count | Recommendation | Evidence |
|---|---:|---:|---|---|
| `bpfopt/crates/bpfopt/src/lib.rs` | 17 | n/a | keep | Crate root/module facade at `bpfopt/crates/bpfopt/src/lib.rs:8-17`. |
| `bpfopt/crates/bpfopt/src/passes/noop.rs` | 22 | n/a | keep | Per-pass file; implementation is `bpfopt/crates/bpfopt/src/passes/noop.rs:12-21`. |
| `bpfopt/crates/bpfopt/src/analysis/lower_tests.rs` | 35 | 3 | merge into `analysis/bbprogram_lower.rs` | Non-pass testing infrastructure; tests at `bpfopt/crates/bpfopt/src/analysis/lower_tests.rs:5`, `bpfopt/crates/bpfopt/src/analysis/lower_tests.rs:15`, `bpfopt/crates/bpfopt/src/analysis/lower_tests.rs:26`. |
| `bpfopt/crates/bpfopt/src/analysis/mod.rs` | 36 | n/a | keep | Module/reexport facade at `bpfopt/crates/bpfopt/src/analysis/mod.rs:4-23`. |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_map_refs_tests.rs` | 43 | 2 | merge into `analysis/bbprogram.rs` | Non-pass tests at `bpfopt/crates/bpfopt/src/analysis/bbprogram_map_refs_tests.rs:6` and `bpfopt/crates/bpfopt/src/analysis/bbprogram_map_refs_tests.rs:22`. |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_cfg_tests.rs` | 59 | 3 | merge into `analysis/bbprogram.rs` | Non-pass tests at `bpfopt/crates/bpfopt/src/analysis/bbprogram_cfg_tests.rs:7`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_cfg_tests.rs:26`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_cfg_tests.rs:42`. |
| `bpfopt/crates/bpfopt/src/insn_tests.rs` | 63 | 4 | merge into `insn.rs` | Non-pass tests at `bpfopt/crates/bpfopt/src/insn_tests.rs:3`, `bpfopt/crates/bpfopt/src/insn_tests.rs:21`, `bpfopt/crates/bpfopt/src/insn_tests.rs:36`, `bpfopt/crates/bpfopt/src/insn_tests.rs:51`. |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_site_scan_tests.rs` | 65 | 3 | merge into `analysis/bbprogram.rs` | Non-pass tests at `bpfopt/crates/bpfopt/src/analysis/bbprogram_site_scan_tests.rs:7`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_site_scan_tests.rs:24`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_site_scan_tests.rs:48`. |
| `bpfopt/crates/bpfopt/src/analysis/bbprogram_branch_target_tests.rs` | 70 | 3 | merge into `analysis/bbprogram.rs` | Non-pass tests at `bpfopt/crates/bpfopt/src/analysis/bbprogram_branch_target_tests.rs:7`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_branch_target_tests.rs:29`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_branch_target_tests.rs:50`. |
| `bpfopt/crates/bpfopt/src/passes/dce_tests.rs` | 75 | 2 | keep | Pass-test exception; tests at `bpfopt/crates/bpfopt/src/passes/dce_tests.rs:9` and `bpfopt/crates/bpfopt/src/passes/dce_tests.rs:42`. |

This leaves six unjustified short non-pass test files, above the convergence threshold of <=2.

## D. Per-Pass A/B/C/D Rating

Rubric used:

- A: BBProgram-native, no lower/flat-scan/PC-keyed analysis.
- B: BBProgram entry with private linear view / PC bridge.
- C: lowers to flat then PC-remaps.
- D: BpfProgram wrapper.

| Pass | Rating | Evidence |
|---|---:|---|
| `noop` | A | Pure BBProgram pass returning unchanged at `bpfopt/crates/bpfopt/src/passes/noop.rs:12-21`. |
| `map_inline` | B | BBProgram entry at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2255-2263`, but uses `current_sites`, `branch_target_sites`, and `report_pc` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2263-2269` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2358-2385`. |
| `const_prop` | B | Builds a PC-to-site oracle from `ordered_site_pcs` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:126-134` and uses `report_pc` at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:516-520`. |
| `dce` | A | Uses def/use sites and `delete_insn` directly at `bpfopt/crates/bpfopt/src/passes/dce.rs:25-43`. |
| `skb_load_bytes_spec` | B | BBProgram entry, but uses branch target sites and PC reporting at `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:85-97` and `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:120-130`. |
| `bounds_check_merge` | B | Uses branch target sites and `report_pc` at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:64-76` and `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:248-253`. |
| `wide_mem` | B | Runs block-local flat scans and PC bridge at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:511-534`; applies via BBProgram at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:645-646`. |
| `bulk_memory` | B | Copies block body into a flat vector and uses `report_pc` at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:264-280`. |
| `rotate` | B | BBProgram entry, but scans linear sites and uses the shared admission helper at `bpfopt/crates/bpfopt/src/passes/rotate.rs:80-95`; the helper uses `report_pc` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:44-53`. |
| `cond_select` | B | BBProgram diamond rewrite, but PC/layout checks remain at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:295-310`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:356-368`, and `bpfopt/crates/bpfopt/src/passes/cond_select.rs:431-435`. |
| `ccmp` | B | BBProgram chain rewrite, but uses PC bridge and block start PCs at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:457-489`. |
| `extract` | B | Uses block-local flat pair matching and admission helper at `bpfopt/crates/bpfopt/src/passes/extract.rs:119-132`; cross-block skip uses `report_pc` at `bpfopt/crates/bpfopt/src/passes/extract.rs:187-194`. |
| `endian_fusion` | B | Uses copied block body plus flat scan and admission helper at `bpfopt/crates/bpfopt/src/passes/endian.rs:373-397`. |
| `branch_flip` | B | PGO profile/branch site logic remains PC-keyed; uses branch targets at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:225-257` and `report_pc` at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:524-531`. |
| `prefetch` | B | Uses `current_sites`, PC-keyed annotations, and direct insertion at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:212-239` and `bpfopt/crates/bpfopt/src/passes/prefetch.rs:274-280`. |

No production pass appears to be C or D: production search found no pass-local `lower(...)` path, and `BpfProgram` remains in test helpers/test code (`bpfopt/crates/bpfopt/src/test_helpers.rs:16`, `bpfopt/crates/bpfopt/src/passes/map_inline/map_info_tests.rs:5-16`).

## E. CLAUDE.md Violation Scan

### ReJIT filtering

No P0 ReJIT filtering found in the focused framework scan.

- The only `live_rejit_programs` implementation found is the base method returning all stored programs at `runner/libs/app_runners/base.py:35-36`.
- Call sites consume that result in `runner/libs/case_common.py:73-80` and `corpus/driver.py:260-262`.
- Focused scan found no app-level `def live_rejit_programs` overrides, `LifecycleAbort`, or `_EXCLUDED_PROGRAM_NAMES` under `runner/libs`, `runner/config`, `corpus`, or `micro`.

### Fallback / legacy / silenced errors

No `.ok()`, `unwrap_or_default`, `let _ =`, `warn!`, or `#[allow(dead_code)]` matches were found in non-test `bpfopt/crates/bpfopt/src/**/*.rs` after excluding `*_tests.rs`, `test_helpers.rs`, and `pass_tests.rs`.

### unwrap / expect / panic in production

**Violation found.**

- Production `parse_bytecode` uses `.expect("chunk is 8 bytes")` at `bpfopt/crates/bpfopt/src/main.rs:438-441`.

Non-production/test-only matches:

- `BBProgram::live_in`, `live_out`, `live_out_site`, and `btf_records` panic wrappers are all under `#[cfg(test)]` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:198-225` and `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:321-327`.
- `KinsnRegistry::default` and `PassContext::baseline` `expect(...)` calls are under `#[cfg(test)]` at `bpfopt/crates/bpfopt/src/pass.rs:417-421` and `bpfopt/crates/bpfopt/src/pass.rs:678-682`.

### Dead code / zero-caller pub

- `cargo clippy --all-targets -- -D dead_code -D warnings` passed.
- Named stale types `BtfRecordsView`, `LinearInsnSite`, and `PassManager` are absent.
- Public field/API debt remains: `BBProgram.entry` is still public at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:30-36`, and the `run_*_on_bbprogram` public reexports at `bpfopt/crates/bpfopt/src/passes/mod.rs:22-40` have no in-crate exact-name callers in the current source scan.

## F. Final Verdict

**NOT-CONVERGED.**

Gates pass, but multiple convergence blockers remain:

1. Public field encapsulation is incomplete (`BBProgram.entry`).
2. Per-pass migration is not all A; 13/15 passes still use PC bridge or private linear/flat views.
3. Short-file audit exceeds the allowed threshold: six small non-pass test files should be inlined.
4. Production `expect()` remains in `main.rs`.
5. Kinsn admission dedup is only partially satisfied as written, because `prefetch` directly emits a kfunc without the shared helper and the criterion includes two pure-BPF passes.

## G. Next Fix Tasks

1. Make `BBProgram.entry` private or `pub(crate)` and route all non-analysis access through a narrow accessor/mutator API.
2. Migrate the 13 B-rated passes off `report_pc`, `current_sites`, `ordered_site_pcs`, `branch_target_sites`, `block_start_pc`, and block-local flat scans where possible; reserve PC mapping for true CLI/BTF/verifier-profile boundaries.
3. Decide and encode the kinsn admission policy for `prefetch`; either share/adapt `admit_kinsn_site_window` for zero-length kfunc insertions or document why insertions are outside the admission contract. Remove `wide_mem` and `skb_load_bytes` from that kinsn-specific criterion if they are intentionally pure-BPF.
4. Inline the six small non-pass test files into parent `#[cfg(test)] mod tests` modules.
5. Replace the production `.expect("chunk is 8 bytes")` in bytecode parsing with explicit fallible handling or a fixed-size array copy that does not use `expect`.
