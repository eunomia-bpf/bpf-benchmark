# Phase 3 Redundancy Audit: bpfopt

Date: 2026-05-12
Scope: read-only structural review of `bpfopt/crates/bpfopt/src`.

Current production Rust LOC by `wc -l`, excluding `*_tests.rs` and `test_helpers.rs`, is 17,623. The largest files are `passes/map_inline.rs` 2,847 LOC, `main.rs` 1,905 LOC, `analysis/bbprogram.rs` 1,825 LOC, `verifier_log.rs` 853 LOC, `analysis/bbprogram_api.rs` 848 LOC, `insn.rs` 836 LOC, and `pass.rs` 825 LOC.

## Executive Summary

**33% reduction is not honestly achievable as cleanup while preserving all current behavior.** A 33% cut is about 5,815 production LOC. The codebase has real redundancy, but not 5.8k LOC of pure fluff. A behavior-preserving cleanup target is closer to **1,700-2,600 LOC**. An aggressive scope cut that deletes non-working/premature surfaces can plausibly reach **4,300-5,200 LOC**. Getting all the way to 5.8k requires product decisions: delete raw verifier-log parsing, delete map snapshot compatibility formats, or remove/defer pieces of `map_inline`.

The main shrink opportunities are:

- `map_inline.rs`: non-working soft hints, non-inlineable map-in-map pipeline, duplicate map metadata layer, mixed orchestration/rewrite/diagnostic code.
- `main.rs`: map-inline-specific bpftool/snapshot/compression/hint parsing dominates the file; true CLI parsing is a small minority.
- `BBProgram`: core IR owns pass-specific `MapInlineSideInput`, test analyses, map binding logic, layout queries, verifier queries, and mutation API in one conceptual surface.
- `pass.rs`: global context and result/report types accumulate side inputs and report abstractions used by only one or two paths.

## A. Module Organization Mess

1. **`BBProgram` is not a clean IR boundary.** It imports `MapInlineSideInput` from a pass module and stores it directly (`analysis/bbprogram.rs:12`, `analysis/bbprogram.rs:86`, `analysis/bbprogram.rs:635`). The lift path imports map-inline hint types and attaches map-inline state while building the IR (`analysis/bbprogram_lift.rs:15`, `analysis/bbprogram_lift.rs:168`). Severity: **must-fix structural**. Estimated LOC delta: **180-280** by removing map-inline side input from the IR and consuming it only in `map_inline`.

2. **`bbprogram.rs` is several modules in one file.** It defines IDs and layout units (`analysis/bbprogram.rs:19`, `analysis/bbprogram.rs:34`), stores CFG/use-def/oracle/profile/BTF/map-inline fields in `BBProgram` (`analysis/bbprogram.rs:74`), exposes traversal APIs (`analysis/bbprogram.rs:214`, `analysis/bbprogram.rs:525`), implements layout scanning (`analysis/bbprogram.rs:895`), map binding collection (`analysis/bbprogram.rs:968`), test-only dominance/reaching-defs (`analysis/bbprogram.rs:1151`), and liveness engines (`analysis/bbprogram.rs:1339`, `analysis/bbprogram.rs:1410`). Severity: **high-value cleanup**. LOC delta: **0-120 production**; mostly a navigation problem unless test-only code is moved out.

3. **`main.rs` is not mostly CLI.** Clap structs are roughly lines 54-141, but map-inline side-input parsing starts at `attach_map_inline_cli_side_input` (`main.rs:771`), bpftool snapshot ingestion spans `read_map_values` (`main.rs:1047`), optional overlays and compressed formats span `main.rs:1278` through `main.rs:1488`, and report serialization spans `main.rs:1809` through `main.rs:1901`. Severity: **must-fix structural**. LOC delta: **650-1,100** if legacy formats are deleted; moving code alone saves 0.

4. **Most pass files are cohesive; `map_inline`, `cond_select`, and `ccmp` are exceptions.** `cond_select` validates by cloning and trial-mutating the program (`passes/cond_select.rs:199`) and helper names like `pattern_a_for_site` hide CFG mutation via `split_block` (`passes/cond_select.rs:217`, `passes/cond_select.rs:228`). `ccmp` repeats the same clone/trial pattern (`passes/ccmp.rs:243`) and mutates in `ccmp_chain_blocks` (`passes/ccmp.rs:300`, `passes/ccmp.rs:314`). Severity: **nice-to-have**. LOC delta: **80-160**.

## B. Concept Duplication

1. **There are too many coordinate concepts without a single obvious story.** `InsnSite` is a logical block/index (`analysis/bbprogram.rs:24`), `SlotDistance` wraps physical slot counts (`analysis/bbprogram.rs:34`), current PCs are computed by `current_site_pcs` (`analysis/bbprogram.rs:1217`), and pass-level instruction slots are recomputed separately (`pass.rs:732`). Some distinction is real, but the API makes callers choose between “site”, “pc”, “slot”, “idx”, and “distance” too often. Severity: **high-value cleanup**. LOC delta: **40-90**.

2. **There are multiple ways to enumerate the same sites.** `all_sites` already exists (`analysis/bbprogram.rs:214`), but `sites_in_block` excludes terminators (`analysis/bbprogram.rs:525`), `sites_in_block_with_terminator` includes them (`analysis/bbprogram.rs:529`), and `logical_sites_for_block` implements another version (`analysis/bbprogram.rs:1313`). Passes repeatedly hand-roll loops over blocks and sites, for example `prefetch` (`passes/prefetch.rs:221`, `passes/prefetch.rs:309`), `map_inline` (`passes/map_inline.rs:256`, `passes/map_inline.rs:1988`), and `wide_mem` (`passes/wide_mem.rs:315`). Severity: **high-value cleanup**. LOC delta: **80-160**.

3. **Map metadata exists twice.** `MapMetadata` carries map layout plus name in `pass.rs:236`; `MapInfo` repeats type/key/value/max/id without name in `passes/map_inline/map_info.rs:21`; conversion happens in `snapshot_map_info` (`passes/map_inline.rs:63`) and again in `analyze_map_info` (`passes/map_inline/map_info.rs:123`). Severity: **must-fix structural**. LOC delta: **100-180**.

4. **Map reference resolution exists in several forms.** `BBProgram` collects loader FD/map-ID bindings (`analysis/bbprogram.rs:968`), `map_info` re-walks all sites and resolves map refs (`passes/map_inline/map_info.rs:140`), and `map_inline` has another direct map reference resolver (`passes/map_inline.rs:2127`). Severity: **high-value cleanup**. LOC delta: **150-260**.

5. **BTF remapping is duplicated for two output shapes.** Test view remapping in `bbprogram_btf.rs` and lowering remapping in `bbprogram_lower.rs` repeat validation, `old_to_new`, deletion, and monotonicity logic (`analysis/bbprogram_btf.rs:63`, `analysis/bbprogram_lower.rs:55`). Severity: **nice-to-have**. LOC delta: **40-70**.

6. **Inline hint validation and formatting are duplicated.** Main validates anchor/mode combinations (`main.rs:921`) and formats anchors (`main.rs:948`); lift repeats validation (`analysis/bbprogram_lift.rs:203`) and formatting (`analysis/bbprogram_lift.rs:268`); map_inline has a third formatter for resolved anchors (`passes/map_inline.rs:51`). Severity: **high-value cleanup**. LOC delta: **50-90**.

7. **Hex formatting is duplicated.** `pass.rs` has `hex_bytes` for map lookup errors (`pass.rs:303`) and `main.rs` has another `hex_bytes` for reports (`main.rs:1893`). Severity: **nice-to-have**. LOC delta: **10-20**.

## C. Over-Abstraction

1. **`PolicyConfig.enabled_passes` is dead policy surface.** `PassContext` carries `policy` (`pass.rs:445`) and `PolicyConfig` contains `enabled_passes` (`pass.rs:685`), but pass execution is registry-driven in `main.rs:339` and `run_pass_once` ignores policy (`pass.rs:691`). Severity: **high-value cleanup**. LOC delta: **25-50**.

2. **Report action abstractions do not earn their keep.** `PassAction`, `PassReportSite`, and `PassReportPc` are generic (`pass.rs:377`) but are only used to turn skips and diagnostics into PCs in `main.rs:1836` and `main.rs:1862` through `finalize_pass_reports` (`pass.rs:713`). Severity: **high-value cleanup**. LOC delta: **50-90**.

3. **`MapInfoAnalysis` is a production-exported test handle.** The marker struct is empty (`passes/map_inline/map_info.rs:100`) and exported from `passes/mod.rs:33`; test code adds methods to it. Severity: **nice-to-have**. LOC delta: **20-40 production**, plus test cleanup.

4. **`SimpleRegValue` is small and probably earned.** It has two implementations, `bulk_memory` and `skb_load_bytes` (`insn.rs:633`, `passes/bulk_memory.rs:107`, `passes/skb_load_bytes.rs:20`). Do not delete it for the sake of deletion. Severity: **no action**. LOC delta: **0**.

5. **Transactional clone-mutate wrappers are repetitive but intentional.** `delete_insn`, `replace_range_at`, `permute_blocks`, `split_block`, and `replace_diamond_with_insns` clone before mutating (`analysis/bbprogram_api.rs:20`, `analysis/bbprogram_api.rs:49`, `analysis/bbprogram_api.rs:205`, `analysis/bbprogram_api.rs:380`, `analysis/bbprogram_api.rs:436`). Removing transaction semantics would be risky; adding a generic transactional helper would add abstraction. Severity: **nice-to-have**. LOC delta: **0-80**.

## D. Coupling Smells

1. **`BBProgram` depends on a pass-specific type.** Evidence above: `MapInlineSideInput` import/storage/accessor (`analysis/bbprogram.rs:12`, `analysis/bbprogram.rs:86`, `analysis/bbprogram.rs:635`). Severity: **must-fix structural**. LOC delta included in A1.

2. **`PassContext` is a global side-input bag.** It includes kinsn state, platform, verifier states, PMU annotations, branch miss rate, map IDs, map metadata, map values, compressed overlays, inner map IDs, skipped snapshots, inline hints, and BTF records (`pass.rs:439` through `pass.rs:473`). Most passes use only a few fields. Severity: **must-fix structural**. LOC delta: **200-350** if map-inline side inputs are removed from the global context path.

3. **`main.rs` knows pass internals.** It special-cases `map_inline` before constructing the pass (`main.rs:305`) and parses map-inline-only args in main (`main.rs:771`). Severity: **must-fix structural**. LOC delta included in A3.

4. **`map_info` reaches through a sibling module into pass-private state.** `analyze_map_info` calls `super::map_inline_side_input(program)` (`passes/map_inline/map_info.rs:115`). That makes `map_info` neither a reusable analysis nor a clean private helper. Severity: **high-value cleanup**. LOC delta included in B3/B4.

5. **The library public surface is broader than its own comments imply.** `lib.rs` says the crate is workspace-internal (`lib.rs:5`) but exposes `analysis`, `insn`, `pass`, `passes`, and `verifier_log` as public modules (`lib.rs:8`). Severity: **nice-to-have**. LOC delta: **0-40**, but reduced coupling.

## E. Premature Generality

1. **Soft inline hints are not implemented but have full parsing, validation, resolution, and orchestration.** CLI defaults non-`!` hints to soft (`main.rs:861`), lift maps soft into runtime hints (`analysis/bbprogram_lift.rs:261`), mode conflicts are validated (`analysis/bbprogram_lift.rs:203`, `main.rs:921`), `run_map_inline_round` has a full soft branch (`passes/map_inline.rs:1307`), but `build_soft_hint_site_rewrite` always vetoes with “soft fold requires BBProgram CFG insertion” (`passes/map_inline.rs:1859`, `passes/map_inline.rs:1882`). Severity: **must-fix structural**. LOC delta: **300-500**.

2. **Map-in-map route logic exists mostly to say it cannot inline.** Chain detection spans `passes/map_inline.rs:276` through `passes/map_inline.rs:358`; deferred hint routing spans `passes/map_inline.rs:739` through `passes/map_inline.rs:834`; inner ID resolution spans `passes/map_inline.rs:1913` through `passes/map_inline.rs:1958`; final rewrite returns `site_level_inline_veto("map-in-map chain is not inlineable")` (`passes/map_inline.rs:1959`, `passes/map_inline.rs:1970`). Severity: **must-fix structural** if map-in-map inlining is not imminent. LOC delta: **450-750**.

3. **Map snapshot ingestion supports too many formats in the optimizer CLI.** `read_map_values` reads bpftool show/dump, raw entries, compressed dumps, skipped-by-size markers, supplements, overlays, and synthesized empty LPM overlays (`main.rs:1047` through `main.rs:1121`). Optional overlays and three compression modes live in `main.rs:1278` through `main.rs:1488` and `pass.rs:245` through `pass.rs:272`. Severity: **high-value cleanup**. LOC delta: **700-1,000** if the daemon emits one normalized side-input JSON.

4. **`parse_map_type` supports a broad catalog while dumping only seven map types.** `needs_bpftool_map_dump` lists seven relevant map types (`main.rs:1558`), while `parse_map_type` maps many unrelated names through `arena` and `insn_array` (`main.rs:1571`). Severity: **nice-to-have**. LOC delta: **40-70**.

5. **Pass-local `--map-ids` duplicates global `--map-ids`.** `MapInlineCliArgs` has `map_ids` (`main.rs:789`) and `resolve_map_ids` cross-checks it against global state (`main.rs:836`). Severity: **nice-to-have**. LOC delta: **30-60**.

6. **Raw verifier log parsing is a large compatibility mode.** `read_verifier_states` accepts JSON or raw log text (`main.rs:1781`, `main.rs:1792`); `verifier_log.rs` is 853 LOC and includes raw log parser helpers such as `parse_verifier_log` (`verifier_log.rs:147`) and permissive attribute parsing (`verifier_log.rs:639`). Severity: **high-value cleanup only if the daemon always provides JSON**. LOC delta: **450-650**.

## F. Dead / Legacy Concepts

1. **`KinsnAdmissionWindow.end_site` is not dead.** It is returned from `rep_admit_kinsn_site_window` (`analysis/bbprogram.rs:1515`) and used by `rotate` for live-out checks (`passes/rotate.rs:87`). Severity: **no action**. LOC delta: **0**.

2. **`PolicyConfig.enabled_passes` is dead.** See C1 (`pass.rs:685`). Severity: **high-value cleanup**. LOC delta included in C1.

3. **`MapInfoAnalysis` is legacy/test-only shape in production.** See C3 (`passes/map_inline/map_info.rs:100`, `passes/mod.rs:33`). Severity: **nice-to-have**. LOC delta included in C3.

4. **`from_cli_args` methods that only reject old pass-local profile args are migration residue.** `branch_flip` errors that args moved to side inputs (`passes/branch_flip.rs:15`) and `prefetch` does the same (`passes/prefetch.rs:35`). Severity: **nice-to-have**. LOC delta: **20-40**.

5. **Verifier parser silently drops unknown fields.** `parse_reg_attributes` ignores unrecognized keys (`verifier_log.rs:651`, `verifier_log.rs:663`), and several conversion helpers intentionally return `None` (`verifier_log.rs:746`, `verifier_log.rs:764`). That is legacy parser tolerance, not fail-fast behavior. Severity: **high-value cleanup** if raw parser remains. LOC delta: **0-100** depending on strictness.

## G. Long Functions

Detected production functions over 80 LOC: **13**. Over 100 LOC: **5**.

Top 10:

| LOC | Function | Purpose | Assessment |
|---:|---|---|---|
| 402 | `passes/map_inline.rs:1142` `run_map_inline_round` | full scan, hint handling, rewrite assembly, conflict handling, diagnostics, apply | doing multiple unrelated jobs; strongest split/delete target |
| 129 | `passes/branch_flip.rs:63` `run_on_bbprogram` | profile validation, candidate filtering, safety checks, apply | cohesive but long |
| 117 | `passes/map_inline.rs:2583` `classify_r0_uses_with_options` | alias tracking/use classification after lookup | hard to read; separable from map-inline orchestration |
| 112 | `analysis/bbprogram_lift.rs:27` `lift_with_kinsn_registry` | linear bytecode to BBProgram | cohesive |
| 101 | `passes/map_inline.rs:1988` `build_direct_map_value_load_rewrites` | pseudo-map-value constantization | separable feature from lookup inlining |
| 100 | `passes/wide_mem.rs:209` `run_on_bbprogram` | scan, filter, skip, apply | moderately mixed |
| 99 | `analysis/bbprogram_api.rs:257` `merge_linear_chain_in_place` | CFG/body/metadata merge | cohesive but mutation-heavy |
| 97 | `passes/cond_select.rs:512` `condition_prefix` | multiple predicate lowering strategies | should be split by case if kept |
| 95 | `passes/map_inline.rs:1721` `build_site_rewrite` | value lookup, null removal, scalar replacement | mixed lookup/read/emit |
| 89 | `passes/branch_flip.rs:293` `apply_branch_flip_site` | CFG validation and block swap | cohesive but verbose |

The other >80 LOC functions are `passes/ccmp.rs:154`, `passes/bounds_check_merge.rs:221`, and `analysis/bbprogram_api.rs:447`.

## H. Repeated Patterns

1. **Kinsn passes repeat the same outer pass loop.** `rotate` scans, admits, checks liveness, reverses safe sites, then replaces (`passes/rotate.rs:72`); `extract` scans cross-block skips then admits and replaces (`passes/extract.rs:59`); `endian` does the same with extra preserved instructions (`passes/endian.rs:281`). Severity: **nice-to-have**. LOC delta: **120-220**, but removing this without adding a new abstraction is hard.

2. **Cross-block “interior branch target” diagnostics are repeated.** `extract` implements a cross-block two-instruction skip (`passes/extract.rs:125`), `endian` repeats the same shape (`passes/endian.rs:367`), and `wide_mem` has a more general version (`passes/wide_mem.rs:309`). Severity: **high-value cleanup** if diagnostics can be simplified. LOC delta: **80-140**.

3. **Skip reason construction repeats constantly.** `branch_flip` has `bf_skip_reason` (`passes/branch_flip.rs:222`), `prefetch` has `pf_skip_reason` (`passes/prefetch.rs:437`), `wide_mem` has `skip_site` (`passes/wide_mem.rs:168`), and `map_inline` has `record_skip` plus diagnostics (`passes/map_inline.rs:2546`). Severity: **nice-to-have**. LOC delta: **40-80**.

4. **`all_sites()` exists but is underused.** It is defined at `analysis/bbprogram.rs:214`; some code uses it (`passes/map_inline.rs:509`, `passes/map_inline/map_info.rs:148`), while many passes still write block/site loops (`passes/prefetch.rs:221`, `passes/skb_load_bytes.rs:113`, `passes/bounds_check_merge.rs:182`). Severity: **nice-to-have**. LOC delta: **50-100**.

## I. `map_inline.rs` Specific

Top-level responsibility map:

- Side-input and snapshot access: `MapInlineSideInput`, `snapshot_map_info`, `lookup_elem` (`passes/map_inline.rs:33`, `passes/map_inline.rs:63`, `passes/map_inline.rs:96`).
- Frame/site traversal helpers: `sites_after_site_in_frame`, `sites_before_site_in_frame_rev` (`passes/map_inline.rs:155`, `passes/map_inline.rs:174`).
- Map-in-map chain detection: `MapInMapChain`, `find_map_in_map_chains` (`passes/map_inline.rs:210`, `passes/map_inline.rs:276`).
- Key extraction and lookup setup: `try_extract_lookup_key_verifier_guided`, `lookup_key_setup_sites` (`passes/map_inline.rs:359`, `passes/map_inline.rs:401`).
- Hint resolution: `resolve_inline_hints` through `validate_resolved_site_hint_modes` (`passes/map_inline.rs:647`, `passes/map_inline.rs:1053`).
- Main orchestration: `run_on_bbprogram` and `run_map_inline_round` (`passes/map_inline.rs:1093`, `passes/map_inline.rs:1142`).
- Edit application and CFG cleanup: `apply_map_inline_edit` through `cleanup_map_inline_bbprogram` (`passes/map_inline.rs:1544`, `passes/map_inline.rs:1665`).
- Lookup rewrite emission: `build_site_rewrite`, hard-null rewrite, soft rewrite (`passes/map_inline.rs:1721`, `passes/map_inline.rs:1823`, `passes/map_inline.rs:1859`).
- Map-in-map resolution/rewrite: `resolve_inner_map_id_for_outer_key`, `build_map_in_map_chain_rewrite` (`passes/map_inline.rs:1913`, `passes/map_inline.rs:1959`).
- Pseudo-map-value constantization: `build_direct_map_value_load_rewrites` (`passes/map_inline.rs:1988`).
- Value encoding/decoding: `prepare_inline_value`, `read_scalar_from_value`, `round_up_8` (`passes/map_inline.rs:2150`, `passes/map_inline.rs:2184`, `passes/map_inline.rs:2199`).
- Diagnostics: `record_maps_skipped_by_size_counter`, `record_skip`, value formatting (`passes/map_inline.rs:2506`, `passes/map_inline.rs:2546`, `passes/map_inline.rs:2562`).
- R0 alias/use classification: `classify_r0_uses_with_options` and alias helpers (`passes/map_inline.rs:2583`).

The responsibilities are separable, but the biggest shrink is not moving code around. It is deleting dead/premature branches: soft hints always veto (`passes/map_inline.rs:1882`), map-in-map chains always veto (`passes/map_inline.rs:1970`), and map metadata is duplicated with `MapMetadata`/`MapInfo` (`pass.rs:236`, `passes/map_inline/map_info.rs:21`). A realistic `map_inline.rs` reduction is **700-1,200 LOC** if those surfaces are cut; **300-500 LOC** if behavior is preserved.

## J. `main.rs` Specific

Approximate breakdown:

- Genuine CLI structs and entrypoint: `Cli`, `CommonArgs`, `Command`, `main` (`main.rs:54`, `main.rs:80`, `main.rs:129`, `main.rs:204`): about **160 LOC** including report/target structs.
- Pass orchestration and registry plumbing: `run_single_pass`, `build_pass`, pass-name aliases, side-input validation (`main.rs:296`, `main.rs:339`, `main.rs:351`, `main.rs:380`): about **250 LOC**.
- Context assembly and BTF/verifier/target parsing: `build_pass_context` (`main.rs:730`) plus target/prog-type parsing around `main.rs:1646`: about **350 LOC**.
- Map-inline-specific JSON/bpftool parsing: `attach_map_inline_cli_side_input` and `MapInlineCliArgs` (`main.rs:771`), snapshot structs (`main.rs:955`), `read_map_values` (`main.rs:1047`), overlays/compression (`main.rs:1278`): roughly **650-900 LOC**.
- Report serialization: `pass_report` through `hex_bytes` (`main.rs:1809`): about **90 LOC**.

Yes, **500+ LOC can leave `main.rs`**, but only if the CLI stops accepting old map snapshot shapes and map-inline-specific pass args are not parsed in main. Moving them to another module is organizational cleanup, not LOC reduction.

## K. Test Redundancy

The shared test helper already covers common pass execution (`test_helpers.rs:214`), skip materialization (`test_helpers.rs:258`), base contexts (`test_helpers.rs:270`), kinsn contexts (`test_helpers.rs:274`), map-inline setters (`test_helpers.rs:301`, `test_helpers.rs:317`), and skip assertions (`test_helpers.rs:479`). Tests still define many tiny per-pass context wrappers such as `ccmp_ctx`, `bulk_ctx`, `prefetch_ctx`, `rotate64_ctx`, `extract_ctx`, `endian_ctx`, and `select_ctx` (examples found at `passes/ccmp_tests.rs:12`, `passes/bulk_memory_tests.rs:7`, `passes/prefetch_tests.rs:8`, `passes/rotate_tests.rs:7`, `passes/extract_tests.rs:7`, `passes/endian_tests.rs:7`, `passes/cond_select_tests.rs:8`).

Severity: **nice-to-have**. Estimated test LOC delta: **250-450**. Production LOC delta: **0**. Do not chase this before production cleanup.

## L. Aggregate Cleanup Plan

### Behavior-Preserving Cleanup

| Order | Cleanup | Evidence | Estimated production LOC delta |
|---:|---|---|---:|
| 1 | Remove `PolicyConfig`, generic report action wrappers, `MapInfoAnalysis` production marker | `pass.rs:445`, `pass.rs:377`, `passes/map_inline/map_info.rs:100` | 100-180 |
| 2 | Collapse duplicate hint validation/formatting and hex helpers | `main.rs:921`, `analysis/bbprogram_lift.rs:203`, `pass.rs:303`, `main.rs:1893` | 60-110 |
| 3 | Collapse `MapMetadata`/`MapInfo` and duplicate map-reference resolution | `pass.rs:236`, `passes/map_inline/map_info.rs:21`, `analysis/bbprogram.rs:968`, `passes/map_inline/map_info.rs:140` | 250-440 |
| 4 | Remove `BBProgram` ownership of map-inline side inputs | `analysis/bbprogram.rs:12`, `analysis/bbprogram.rs:86`, `analysis/bbprogram_lift.rs:168` | 180-280 |
| 5 | Slim repeated pass scan/skip code without adding large abstractions | `passes/extract.rs:125`, `passes/endian.rs:367`, `passes/wide_mem.rs:309` | 120-220 |
| 6 | Simplify `main.rs` pass aliases and map-inline pass-local `--map-ids` compatibility | `main.rs:24`, `main.rs:836` | 70-130 |
| 7 | Move/remove test-only production-file blocks where possible | `analysis/bbprogram.rs:1151`, `analysis/bbprogram.rs:1339` | 0-120 production |

Behavior-preserving total: **780-1,480 LOC** from the concrete removals above. With careful local simplification inside `map_inline` orchestration and `bbprogram_api`, stretch target is **1,700-2,600 LOC**.

### Aggressive Scope Cuts

| Order | Cleanup | Evidence | Estimated production LOC delta |
|---:|---|---|---:|
| 8 | Delete soft inline hint mode until implemented | `main.rs:861`, `analysis/bbprogram_lift.rs:261`, `passes/map_inline.rs:1307`, `passes/map_inline.rs:1882` | 300-500 |
| 9 | Delete map-in-map inline route/chain machinery until it can emit rewrites | `passes/map_inline.rs:276`, `passes/map_inline.rs:739`, `passes/map_inline.rs:1913`, `passes/map_inline.rs:1970` | 450-750 |
| 10 | Replace bpftool directory/overlay/compression compatibility with one normalized side-input JSON | `main.rs:1047`, `main.rs:1278`, `main.rs:1349`, `pass.rs:245` | 700-1,000 |
| 11 | Delete broad map-type name catalog not used by supported dumps | `main.rs:1558`, `main.rs:1571` | 40-70 |
| 12 | Require verifier-state JSON and delete raw verifier log parser | `main.rs:1781`, `main.rs:1792`, `verifier_log.rs:147`, `verifier_log.rs:639` | 450-650 |
| 13 | Cut map-inline diagnostic-only counters and duplicate site diagnostics if reports do not need them | `passes/map_inline.rs:2506`, `passes/map_inline.rs:2546`, `main.rs:1810` | 100-220 |
| 14 | Decide whether pseudo-map-value constantization belongs in `map_inline` or is a separate pass; deleting/defering it saves real code | `passes/map_inline.rs:1988`, `passes/map_inline.rs:2202` | 300-600 |

Aggressive additional total: **2,340-3,790 LOC**.

### Final Aggregate

- Conservative, behavior-preserving: **1,700-2,600 LOC**, about **10-15%**.
- Aggressive, with product-scope deletions: **4,300-5,200 LOC**, about **24-30%**.
- Required for 33%: about **5,815 LOC**. The remaining **600-1,500 LOC gap** is not obvious redundancy; it requires deleting a real subsystem or one or more passes, or introducing a new abstraction/code-generation layer, which conflicts with the removal-only cleanup goal.

Recommendation: treat **30% as the honest aggressive ceiling** unless the project is willing to drop raw verifier logs, map snapshot compatibility, and non-working map-inline features in one sweep.
