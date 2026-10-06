# Phase 3 BBProgram Migration Fresh-Eyes Audit 2 (2026-05-10)

Inputs read: `CLAUDE.md`, `docs/bbprogram-architecture-design.md`, and current `bpfopt/crates/bpfopt/src/**/*.rs`.

Explicitly not read: `docs/tmp/p3_*.md` and prior Phase 3 review material.

Snapshot caveat: another editor was active while this audit ran. I observed line-count drift during the audit; the final counts below are from the last recount before writing this file. I audited the apparent intended structure where files looked actively edited.

Validation run: `CARGO_TARGET_DIR=/tmp/bpf-benchmark-cargo-check-fresh2 cargo check -p bpfopt --all-targets` completed successfully.

## 1. Executive Summary

- The production CLI now follows the intended lift/pass/lower boundary in `main.rs`: read bytes, lift to `BBProgram`, attach side inputs, run one pass, then lower once (`bpfopt/crates/bpfopt/src/main.rs:299`, `bpfopt/crates/bpfopt/src/main.rs:302`, `bpfopt/crates/bpfopt/src/main.rs:313`, `bpfopt/crates/bpfopt/src/main.rs:315`).
- No pass is a pure old `BpfProgram` wrapper, and I found no production `lower(prog)` in pass bodies. However, 13 of 15 passes still rely on current-PC maps, block-local linear scans, or PC-to-`InsnSite` bridge helpers. My pass ratings are 2 A, 13 B, 0 C, 0 D.
- Total LOC is down versus Phase 3 start, but non-test LOC is up. Current total is 25,951 LOC, down 3,577 from Phase 3 start, while current non-test is 20,680 LOC, up 1,323 from Phase 3 start.
- The largest architectural risk is that `BBProgram` exposes mutable internals and public PC bridge APIs (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:36`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:54`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:289`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:539`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:560`), which lets passes keep the old PC-indexed mental model.
- Final verdict: **not-conformant** to the full Phase 3 design contract, despite meaningful progress away from old flat `BpfProgram` pass execution.

## 2. LOC Accounting

### Baseline Comparison

| Snapshot | Total LOC | Non-Test LOC | Delta Total vs Current | Delta Non-Test vs Current |
|---|---:|---:|---:|---:|
| Phase 1 start `7d34960e` | 25,788 | 18,864 | +163 | +1,816 |
| Phase 3 start `bfa802c9` | 29,528 | 19,357 | -3,577 | +1,323 |
| Current | 25,951 | 20,680 | 0 | 0 |

Non-test exclusion used: `*_tests.rs`, `test_helpers.rs`, and `pass_tests.rs`.

### Top 25 Files by Current LOC

| Rank | LOC | File |
|---:|---:|---|
| 1 | 5,518 | `bpfopt/crates/bpfopt/src/passes/map_inline.rs` |
| 2 | 1,174 | `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs` |
| 3 | 1,096 | `bpfopt/crates/bpfopt/src/main.rs` |
| 4 | 1,024 | `bpfopt/crates/bpfopt/src/pass.rs` |
| 5 | 913 | `bpfopt/crates/bpfopt/src/passes/const_prop.rs` |
| 6 | 889 | `bpfopt/crates/bpfopt/src/verifier_log.rs` |
| 7 | 881 | `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs` |
| 8 | 828 | `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs` |
| 9 | 824 | `bpfopt/crates/bpfopt/src/insn.rs` |
| 10 | 751 | `bpfopt/crates/bpfopt/src/passes/prefetch.rs` |
| 11 | 738 | `bpfopt/crates/bpfopt/src/passes/wide_mem.rs` |
| 12 | 702 | `bpfopt/crates/bpfopt/src/passes/cond_select.rs` |
| 13 | 682 | `bpfopt/crates/bpfopt/src/passes/branch_flip.rs` |
| 14 | 635 | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` |
| 15 | 629 | `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs` |
| 16 | 563 | `bpfopt/crates/bpfopt/src/passes/ccmp.rs` |
| 17 | 490 | `bpfopt/crates/bpfopt/src/passes/endian.rs` |
| 18 | 486 | `bpfopt/crates/bpfopt/src/passes/rotate.rs` |
| 19 | 396 | `bpfopt/crates/bpfopt/src/passes/const_prop_tests.rs` |
| 20 | 374 | `bpfopt/crates/bpfopt/src/main_tests.rs` |
| 21 | 369 | `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs` |
| 22 | 369 | `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs` |
| 23 | 337 | `bpfopt/crates/bpfopt/src/passes/map_inline/map_info_tests.rs` |
| 24 | 323 | `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs` |
| 25 | 321 | `bpfopt/crates/bpfopt/src/pass_tests.rs` |

### Top LOC Growers vs Phase 3 Start

| Delta | Current LOC | File | Assessment |
|---:|---:|---|---|
| +1,174 | 1,174 | `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs` | Necessary core IR, but bloated by public mutable fields and PC bridge APIs (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:36`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:289`). |
| +828 | 828 | `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs` | Necessary mutation API, but clone-heavy validation and many narrow remappers suggest consolidation opportunities (`bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:1`). |
| +374 | 374 | `bpfopt/crates/bpfopt/src/main_tests.rs` | Test growth, acceptable only if it replaces higher-value historical coverage. |
| +369 | 369 | `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs` | Necessary lift boundary. |
| +337 | 337 | `bpfopt/crates/bpfopt/src/passes/map_inline/map_info_tests.rs` | Test growth. |

### Where Non-Test Growth Lives

- BBProgram infra added roughly +3.2k non-test LOC across `analysis/bbprogram*.rs` and `analysis/mod.rs` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:36`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:1`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:1`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:1`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:1`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:1`).
- Pass files are net larger, with notable growth in `ccmp`, `map_inline`, `cond_select`, and `branch_flip` (`bpfopt/crates/bpfopt/src/passes/ccmp.rs:160`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2513`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:121`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:225`).
- The total LOC reduction is mainly from test/source deletion elsewhere, not from a current non-test code-volume reduction.

## 3. Per-Pass Rating

Rating key:

- A: production path uses `BBProgram` methods directly, no flat scan/lower, no PC-keyed analysis.
- B: `BBProgram` entry but still has private linear view, PC-keyed analysis, or PC-to-site bridge.
- C: lowers to flat bytecode for scan/detection then PC-remaps.
- D: thin wrapper around old flat `BpfProgram` pass.

| Pass | Rating | Evidence |
|---|---|---|
| `passes/dce.rs` | A | Uses `prog.use_def` and `prog.delete_insn` directly (`bpfopt/crates/bpfopt/src/passes/dce.rs:25`, `bpfopt/crates/bpfopt/src/passes/dce.rs:30`, `bpfopt/crates/bpfopt/src/passes/dce.rs:42`). |
| `passes/noop.rs` | A | No mutation or scan (`bpfopt/crates/bpfopt/src/passes/noop.rs:19`). |
| `passes/const_prop.rs` | B | Uses `current_site_pcs` and verifier-PC remapping before BB simulation (`bpfopt/crates/bpfopt/src/passes/const_prop.rs:149`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:481`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:551`). |
| `passes/bounds_check_merge.rs` | B | Uses current PC maps, branch-target PC sets, and returns an old-PC address map (`bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:76`, `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:77`, `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:160`, `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:206`). |
| `passes/branch_flip.rs` | B | Mutates BB terminators and block order, but discovery/safety is PC-oriented (`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:254`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:255`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:281`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:459`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:481`). |
| `passes/map_inline.rs` + `map_inline/map_info.rs` | B | Large private PC/site bridge layer and direct BTF mutation (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:248`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:260`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:310`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2619`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3245`, `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:213`). |
| `passes/rotate.rs` | B | BB entry and `replace_range`, but site detection is PC/slot bridged (`bpfopt/crates/bpfopt/src/passes/rotate.rs:80`, `bpfopt/crates/bpfopt/src/passes/rotate.rs:83`, `bpfopt/crates/bpfopt/src/passes/rotate.rs:94`, `bpfopt/crates/bpfopt/src/passes/rotate.rs:152`). |
| `passes/extract.rs` | B | Scans `prog.blocks[block.0].insns` and uses cross-block PC checks (`bpfopt/crates/bpfopt/src/passes/extract.rs:119`, `bpfopt/crates/bpfopt/src/passes/extract.rs:128`, `bpfopt/crates/bpfopt/src/passes/extract.rs:191`, `bpfopt/crates/bpfopt/src/passes/extract.rs:199`). |
| `passes/endian.rs` | B | Scans block-local instruction vectors and carries preserved `Vec<BpfInsn>` chunks (`bpfopt/crates/bpfopt/src/passes/endian.rs:180`, `bpfopt/crates/bpfopt/src/passes/endian.rs:377`, `bpfopt/crates/bpfopt/src/passes/endian.rs:388`, `bpfopt/crates/bpfopt/src/passes/endian.rs:416`). |
| `passes/bulk_memory.rs` | B | Uses block-local vector scanning and `HashMap<usize, RegSet>` live-out state (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:296`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:303`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:383`). |
| `passes/prefetch.rs` | B | Heavily PC-window based (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:217`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:378`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:387`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:654`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:676`). |
| `passes/wide_mem.rs` | B | Keeps a flat slice scanner and cross-block `Vec<BpfInsn>` windows inside BB entry (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:499`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:504`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:527`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:642`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:693`). |
| `passes/skb_load_bytes.rs` | B | BB rewrite, but branch-target PC checks remain in the detection path (`bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:85`, `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:89`, `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:130`, `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:131`). |
| `passes/cond_select.rs` | B | Uses BB diamond mutation, but matching is PC-site shape matching with validation skips (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:121`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:166`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:197`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:299`). |
| `passes/ccmp.rs` | B | Uses BB mutation, but non-AArch64 pass skip and PC/block-start remapping remain (`bpfopt/crates/bpfopt/src/passes/ccmp.rs:160`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:161`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:214`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:378`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:381`). |

## 4. Cross-Pass Duplicate Code Inventory

- Repeated `run_on_bbprogram` public wrapper pattern exists across nearly every pass, e.g. `dce` (`bpfopt/crates/bpfopt/src/passes/dce.rs:20`, `bpfopt/crates/bpfopt/src/passes/dce.rs:25`), `rotate` (`bpfopt/crates/bpfopt/src/passes/rotate.rs:76`, `bpfopt/crates/bpfopt/src/passes/rotate.rs:80`), `extract` (`bpfopt/crates/bpfopt/src/passes/extract.rs:111`, `bpfopt/crates/bpfopt/src/passes/extract.rs:115`), `endian` (`bpfopt/crates/bpfopt/src/passes/endian.rs:370`, `bpfopt/crates/bpfopt/src/passes/endian.rs:374`), `bulk_memory` (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:241`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:245`), `wide_mem` (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:495`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:499`), `prefetch` (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:208`), `map_inline` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2509`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2513`), `branch_flip` (`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:215`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:225`), `cond_select` (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:117`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:121`), and `ccmp` (`bpfopt/crates/bpfopt/src/passes/ccmp.rs:155`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:160`). Recommendation: keep only test-needed wrappers private or move common construction to focused test helpers.
- Kinsn-class passes duplicate the same admission pipeline: collect `site_pcs`, compute `block_slot_offset`, call `kinsn_replacement_subprog_skip_reason`, collect safe sites, then reverse-apply `replace_range`. Examples: `rotate` (`bpfopt/crates/bpfopt/src/passes/rotate.rs:83`, `bpfopt/crates/bpfopt/src/passes/rotate.rs:94`, `bpfopt/crates/bpfopt/src/passes/rotate.rs:99`, `bpfopt/crates/bpfopt/src/passes/rotate.rs:152`), `extract` (`bpfopt/crates/bpfopt/src/passes/extract.rs:119`, `bpfopt/crates/bpfopt/src/passes/extract.rs:131`, `bpfopt/crates/bpfopt/src/passes/extract.rs:136`, `bpfopt/crates/bpfopt/src/passes/extract.rs:177`), `endian` (`bpfopt/crates/bpfopt/src/passes/endian.rs:377`, `bpfopt/crates/bpfopt/src/passes/endian.rs:391`, `bpfopt/crates/bpfopt/src/passes/endian.rs:402`, `bpfopt/crates/bpfopt/src/passes/endian.rs:449`), `bulk_memory` (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:255`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:279`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:341`), `wide_mem` (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:504`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:642`). Recommendation: introduce a BBProgram pattern-admission helper, not a PC-based helper.
- Interior branch-target safety logic is duplicated in several pass-local forms: `extract` (`bpfopt/crates/bpfopt/src/passes/extract.rs:191`, `bpfopt/crates/bpfopt/src/passes/extract.rs:199`), `endian` (`bpfopt/crates/bpfopt/src/passes/endian.rs:459`, `bpfopt/crates/bpfopt/src/passes/endian.rs:470`), `wide_mem` (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:652`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:658`), `branch_flip` (`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:279`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:281`), and `bounds_check_merge` (`bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:480`, `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:486`). Recommendation: add a BB-level query like `range_has_external_entry(site_range)` and remove pass-local PC windows.
- PC lookup wrappers are duplicated between generic helpers and pass-local wrappers: `analysis/bbprogram_helpers.rs:39`, `analysis/bbprogram.rs:303`, and `map_inline.rs:248`. Recommendation: do not add more wrappers; remove pass access to absolute PCs except CLI/profile boundary adapters.
- Packet/register state transfer is partly shared and partly reimplemented. Shared helper exists at `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:116`; `bulk_memory` uses it (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:8`), while `prefetch` carries specialized transfer functions (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:423`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:504`) and `bounds_check_merge` has a separate scan state (`bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:228`). Recommendation: only consolidate if the semantics are identical; otherwise rename helpers to make the intentional divergence obvious.

## 5. Meaningless Wrappers Inventory

- `map_inline` has trivial wrappers around `BBProgram` methods: `site_pc` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:248`), `site_insn` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:255`), `site_frame` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:267`), `first_site_in_block` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:306`), and `map_fd_bindings` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:310`). Recommendation: inline or replace with a single local planning object that carries already-computed site order and bindings.
- `current_site_position` recomputes all current sites every call (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:260`) and is used later in cleanup planning (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:4515`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4517`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:5395`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:5396`). Recommendation: build one ordered-site index in the planner or remove position-based logic.
- `analysis::site_current_pc` duplicates `BBProgram::site_current_pc` with a map parameter (`bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs:39`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:303`). Recommendation: remove both from pass-facing API where possible; keep only an internal profile/BTF adapter.
- `BtfRecordsView` is exported from `analysis/mod.rs` (`bpfopt/crates/bpfopt/src/analysis/mod.rs:17`) but is only produced by test-facing `BBProgram::btf_records`/`btf_records_checked` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:230`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:235`). Recommendation: make the view test-only or crate-private without re-export.
- `run_on_bbprogram` functions that are only thin `BpfPass::run` bodies are unnecessary public APIs in production pass modules, e.g. `noop` does not need one and `dce` could hide its helper (`bpfopt/crates/bpfopt/src/passes/noop.rs:19`, `bpfopt/crates/bpfopt/src/passes/dce.rs:25`). Recommendation: expose only APIs used outside the module for real composition.

## 6. Non-Design-Conforming Patterns Inventory

- Production pass bodies do not call `lower(prog)`. The only production pass path lower boundary I found is the CLI-level boundary (`bpfopt/crates/bpfopt/src/main.rs:315`) plus the lower module itself (`bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:11`). This aspect passes.
- Production `BpfProgram::new(insns)` is not used by optimization passes. The remaining instance is test-gated map-info helper code (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:164`, `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:199`). This aspect passes.
- Production raw `Vec<BpfInsn>` still exists at the CLI snapshot boundary, explicitly documented as the only raw mutation path (`bpfopt/crates/bpfopt/src/main.rs:255`, `bpfopt/crates/bpfopt/src/main.rs:444`). That exception matches the v3 daemon snapshot story, but it means the literal "no raw Vec mutation path" acceptance is not absolute.
- Passes still create private flat or block-local `Vec<BpfInsn>` views: `wide_mem` cross-block windows (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:693`), `endian` preserved middle chunks (`bpfopt/crates/bpfopt/src/passes/endian.rs:84`, `bpfopt/crates/bpfopt/src/passes/endian.rs:416`), `cond_select` prefix construction (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:88`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:658`), and `map_inline` rewrite payload fields (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1194`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1786`). Recommendation: distinguish acceptable replacement payloads from unacceptable scan/mutation vectors in the design doc or move scan logic to BB site windows.
- Production PC-keyed maps remain in planning: profiling side inputs are `HashMap<usize, _>` (`bpfopt/crates/bpfopt/src/pass.rs:166`, `bpfopt/crates/bpfopt/src/pass.rs:168`) and `bulk_memory` uses `HashMap<usize, RegSet>` internally (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:383`). Recommendation: confine external profiles to a single original-PC ingestion adapter and convert pass-local state to `InsnSite` or `BlockId`.
- Direct block-instruction indexing and scanning persists: `bulk_memory` (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:303`), `extract` (`bpfopt/crates/bpfopt/src/passes/extract.rs:128`), `endian` (`bpfopt/crates/bpfopt/src/passes/endian.rs:180`, `bpfopt/crates/bpfopt/src/passes/endian.rs:388`, `bpfopt/crates/bpfopt/src/passes/endian.rs:416`), `cond_select` shape logic via direct block positions (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:365`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:375`), and `rotate` through direct block access (`bpfopt/crates/bpfopt/src/passes/rotate.rs:166`). Recommendation: add BBProgram pattern iterators over site windows.
- PC-to-`InsnSite` bridge helpers are pass-facing: `current_site_pcs` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:289`), `site_current_pc` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:303`), `branch_target_pcs` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:310`), `current_block_start_pc` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:343`), `absolute_pc_for_block_slot` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:528`), `sites_in_block_pc_range` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:539`), `sites_in_frame_pc_range` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:560`), `site_for_original_pc` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:592`), and `block_for_original_pc` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:599`). Recommendation: make these crate-private to boundary adapters and remove usage from pass planning.
- Public mutable internals let passes bypass BBProgram mutation contracts: `BBProgram.blocks`, `use_def`, `oracle`, `btf`, and `kinsn_reg` are public (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:36`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:37`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:39`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:40`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:41`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:42`), and `Block.insns`/`Block.terminator` are public (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:54`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:56`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:57`). Direct BTF assignment occurs in `map_inline` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:3245`). Recommendation: make fields private and force all structural changes through mutation APIs.

## 7. Fallback / Legacy / Silenced Errors / Dead Code Inventory

- Production `expect` remains in `parse_bytecode`, even though length is checked first (`bpfopt/crates/bpfopt/src/main.rs:431`, `bpfopt/crates/bpfopt/src/main.rs:440`). This is low risk but violates the literal fail-fast no-`expect` rule. Recommendation: use an infallible `[u8; 8]` copy or `map_err` path.
- `cond_select` converts validation errors into skip reasons and continues (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:166`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:171`). If these are ordinary pattern misses, the function name/type should reflect that; if they are invariant failures, they should propagate.
- `ccmp` has the same validation-error-as-skip pattern (`bpfopt/crates/bpfopt/src/passes/ccmp.rs:214`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:219`). Recommendation: split `MatchMiss` from `anyhow::Error`.
- `run_pass_once` skips passes when required kinsn targets are unavailable (`bpfopt/crates/bpfopt/src/pass.rs:931`, `bpfopt/crates/bpfopt/src/pass.rs:948`, `bpfopt/crates/bpfopt/src/pass.rs:962`), while the CLI also has a fail-fast kinsn validator (`bpfopt/crates/bpfopt/src/main.rs:301`, `bpfopt/crates/bpfopt/src/main.rs:382`, `bpfopt/crates/bpfopt/src/main.rs:408`). Recommendation: remove or test-gate the skip path if production should fail before pass execution.
- `ccmp` returns a normal skipped result on non-AArch64 (`bpfopt/crates/bpfopt/src/passes/ccmp.rs:160`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:161`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:162`). This may be policy-correct for an arm64-only pass, but it is still a production skip path. Recommendation: ensure the pass is not selected on unsupported arch or fail clearly.
- BTF remap drops records whose original instruction no longer exists (`bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:63`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:64`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:73`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:75`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:76`). The lowerer has a comment explaining the choice, but this is still a silent metadata deletion. Recommendation: either make deletion an explicit mutation-side record or fail when a surviving BTF record cannot be mapped.
- `BBProgram::invalidate_oracle` sets `oracle` to `Some(empty)` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:666`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:667`). `const_prop` treats `Some(states)` as usable oracle input (`bpfopt/crates/bpfopt/src/passes/const_prop.rs:477`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:480`). Recommendation: use `None` for invalidated verifier state unless an empty oracle has distinct intended semantics.
- No production `unimplemented!` or `todo!` was found in `bpfopt/crates/bpfopt/src/**/*.rs`.
- No production `#[allow(dead_code)]`, `.ok()`, `unwrap_or_default`, `unwrap_or`, or `let _ =` pattern was found by targeted search under the non-test source glob.
- Test-only `expect` and panic wrappers remain, e.g. `bbprogram.rs` test accessors (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:156`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:170`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:184`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:232`), `pass.rs` test/default paths (`bpfopt/crates/bpfopt/src/pass.rs:637`, `bpfopt/crates/bpfopt/src/pass.rs:1017`), and test pass construction (`bpfopt/crates/bpfopt/src/passes/mod.rs:223`). These are not production-path findings.

## 8. ReJIT Filtering Violations

Within current `bpfopt` source, I found no ReJIT program filtering constructs: no `live_rejit_programs`, `LifecycleAbort`, `_EXCLUDED_*`, or per-program exclusion lists.

Repository-wide source search did find existing runner APIs named `live_rejit_programs` (`runner/libs/app_runners/base.py:35`, `runner/libs/case_common.py:76`, `runner/libs/case_common.py:77`, `corpus/driver.py:260`). I did not inspect those files because this audit scope was bpfopt Phase 3 source, and these hits are not evidence of a Phase 3 bpfopt regression.

## 9. Infra Audit Findings

- `BBProgram` and `Block` expose too much mutable structure (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:36`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:37`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:54`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:56`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:57`). This prevents the API from enforcing design-compliant mutation paths.
- `UseDefGraph` public maps encourage callers to inspect representation instead of graph queries (`bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:43`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:44`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:45`). `dce` directly iterates the map keys (`bpfopt/crates/bpfopt/src/passes/dce.rs:30`). Recommendation: expose iterator/query methods and make maps private.
- PC reconstruction helpers are public pass-facing API even though design §3 says passes should not operate on PC-keyed views (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:289`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:303`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:310`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:343`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:528`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:539`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:560`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:592`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:599`).
- `BtfRecordsView` appears to be test-facing but is exported from `analysis/mod.rs` (`bpfopt/crates/bpfopt/src/analysis/mod.rs:17`) and implemented as public methods in production code (`bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:10`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:21`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:230`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:235`). Recommendation: test-gate or keep crate-private.
- `LinearInsnSite` and `linear_insn_sites` remain public in `insn.rs` with no non-test caller found (`bpfopt/crates/bpfopt/src/insn.rs:192`, `bpfopt/crates/bpfopt/src/insn.rs:197`). Recommendation: remove or test-gate if no longer part of the pass architecture.
- `PassManager` remains as a production type (`bpfopt/crates/bpfopt/src/pass.rs:839`, `bpfopt/crates/bpfopt/src/pass.rs:901`) while the CLI single-pass path uses `run_pass_once` directly (`bpfopt/crates/bpfopt/src/main.rs:313`, `bpfopt/crates/bpfopt/src/pass.rs:926`). Recommendation: confirm whether production still needs multi-pass in `bpfopt`; otherwise test-gate or delete it to align with v3 external per-pass orchestration.
- `bbprogram_lift` and `bbprogram_lower` necessarily use flat PC accounting at the boundaries (`bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:1`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:11`). This is design-conforming boundary code, but the same concepts leaking into passes is the main architecture problem.
- No `bbprogram/` subdirectory exists under `bpfopt/crates/bpfopt/src`; BBProgram is implemented as `analysis/bbprogram*.rs`.
- Stale comment: `wide_mem` still says it was "absorbed from matcher.rs" (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:4`), which reads like migration debris. Recommendation: update or remove once the pass is BB-native.

## 10. Design Contract §11 Conformance Check

| Acceptance Item | Status | Evidence |
|---|---|---|
| 1. 542 testbin roundtrip | PARTIAL / NOT VERIFIED | Lift/lower boundary exists (`bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:1`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:11`), but I found no `testbin`, `roundtrip`, or equivalence artifact under `bpfopt/crates/bpfopt/src` proving 542/542. `cargo check -p bpfopt --all-targets` passes, but that is not a roundtrip suite. |
| 2. Pass-equivalence coverage | FAIL / NOT VERIFIED | No source path matching `equivalence`, `testbin`, or `roundtrip` was found under `bpfopt/crates/bpfopt/src`. Existing per-pass tests exist, e.g. `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1` and `bpfopt/crates/bpfopt/src/passes/const_prop_tests.rs:1`, but I found no broad old-vs-new pass equivalence harness. |
| 3. No `Vec<BpfInsn>` mutation path in production | PARTIAL | Main pass path is BBProgram (`bpfopt/crates/bpfopt/src/main.rs:302`, `bpfopt/crates/bpfopt/src/main.rs:313`), but the CLI has a documented raw Vec mutation for map canonicalization (`bpfopt/crates/bpfopt/src/main.rs:255`, `bpfopt/crates/bpfopt/src/main.rs:444`) and passes still use private flat vectors for scanning/rewrite payloads (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:693`, `bpfopt/crates/bpfopt/src/passes/endian.rs:416`). |
| 4. No `bbprogram/` subdirectory | PASS | Directory check returned absent; files are `analysis/bbprogram*.rs` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1`). |
| 5. No benchmark-framework changes | FAIL | `git diff --name-only bfa802c9 -- corpus runner micro daemon` excluding `corpus/results` reports `runner/config/passes/dce/default.yaml`. This is path-level evidence only; I did not open the file because source-reading scope was limited. |
| 6. Code-volume reduction >= 2500 LOC | PARTIAL | Total LOC is down 3,577 versus Phase 3 start, but non-test LOC is up 1,323. If the contract is total LOC only, it passes; if it is architecture/code volume, it does not. |
| 7. All historical 402 tests still pass | NOT VERIFIED | `cargo check -p bpfopt --all-targets` passes. I did not run the full historical test suite, and no current evidence of 402 historical tests passing was available from the allowed source inputs. |
| 8. No commit, working tree only | PASS | I created no commit. Branch was already `main...origin/main [ahead 4]` before writing this report, with HEAD at `57cac8a0`. |

## 11. Independent Final Verdict

**Not-conformant.**

The migration has clearly moved the production CLI and all passes onto `BBProgram` entrypoints, and I did not find any D-rated old-`BpfProgram` wrappers. The design goal is still not met because pass-facing APIs preserve current-PC and flat-vector escape hatches, most passes continue to plan in PC space, public mutable fields bypass the BBProgram mutation contract, and the LOC acceptance is met only in total LOC while non-test code grew substantially.

## 12. Top 10 Prioritized Cleanup Tasks

1. Make `BBProgram.blocks`, `Block.insns`, `Block.terminator`, `BBProgram.btf`, `BBProgram.oracle`, and `UseDefGraph` maps private; add focused query/mutation methods (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:36`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:54`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:43`).
2. Remove pass-facing PC bridge APIs or restrict them to boundary adapters: `current_site_pcs`, `site_current_pc`, `branch_target_pcs`, range-by-PC helpers, and original-PC lookup helpers (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:289`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:303`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:310`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:539`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:560`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:592`).
3. Replace duplicate kinsn-pass scan/admission loops with a BB-native pattern iterator and admission helper (`bpfopt/crates/bpfopt/src/passes/rotate.rs:83`, `bpfopt/crates/bpfopt/src/passes/extract.rs:119`, `bpfopt/crates/bpfopt/src/passes/endian.rs:377`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:255`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:504`).
4. Add a BB-native "range has external entry / branch target" query and delete pass-local PC-window checks (`bpfopt/crates/bpfopt/src/passes/extract.rs:191`, `bpfopt/crates/bpfopt/src/passes/endian.rs:459`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:652`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:281`, `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:486`).
5. Refactor `map_inline` planning to remove trivial wrappers and repeated current-site scans (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:248`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:260`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:306`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:310`).
6. Convert pass-local PC-keyed state to `InsnSite`/`BlockId` after one explicit boundary adapter for external profiles (`bpfopt/crates/bpfopt/src/pass.rs:166`, `bpfopt/crates/bpfopt/src/pass.rs:168`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:383`).
7. Split recoverable pattern misses from real errors in `cond_select` and `ccmp`, then propagate real validation errors (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:166`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:214`).
8. Resolve BTF deletion semantics explicitly instead of silently continuing on missing old PCs (`bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:63`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:73`).
9. Delete or test-gate unused/test-facing public APIs: `BtfRecordsView`, `LinearInsnSite`, and possibly `PassManager` if no production multi-pass CLI remains (`bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:10`, `bpfopt/crates/bpfopt/src/analysis/mod.rs:17`, `bpfopt/crates/bpfopt/src/insn.rs:192`, `bpfopt/crates/bpfopt/src/pass.rs:839`).
10. Add the missing acceptance evidence: roundtrip testbin result and pass-equivalence harness, or update §11 to match the actual replacement tests (`bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:1`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:11`).

## 13. Estimated LOC Delta if Cleanup Tasks Are Applied

Estimated non-test reduction: **about 1,800 to 2,600 LOC**, centered around **2,200 LOC**.

Largest likely reductions:

- `map_inline` wrapper/planning consolidation: -300 to -500 LOC (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:248`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2513`).
- Shared BB-native kinsn pattern/admission helper across rotate/extract/endian/bulk/wide/ccmp/cond-select: -500 to -800 LOC (`bpfopt/crates/bpfopt/src/passes/rotate.rs:83`, `bpfopt/crates/bpfopt/src/passes/extract.rs:119`, `bpfopt/crates/bpfopt/src/passes/endian.rs:377`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:255`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:504`).
- Removing public PC bridge APIs and pass-local PC-window helpers after BB-native queries: -300 to -500 LOC (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:289`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:539`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:560`).
- Deleting/test-gating unused public views and legacy linear helpers: -150 to -250 LOC (`bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:10`, `bpfopt/crates/bpfopt/src/insn.rs:192`).
- Simplifying stale skip/validation and address-map plumbing: -150 to -300 LOC (`bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:160`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:166`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:214`).

