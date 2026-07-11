# Phase 3 BBProgram Final Convergence Review

Date: 2026-05-10
Branch: main
Mode: read-only source review; only this report was written.

## 1. Independent Gate Verification

| Gate | Result | Evidence |
|---|---:|---|
| `cargo build --release --manifest-path bpfopt/Cargo.toml` | PASS | Finished release profile successfully. |
| `cargo test --release --manifest-path bpfopt/Cargo.toml` | PASS | 217 tests passed: 188 lib, 16 main, 1 roundtrip, 12 CLI, 0 doctests. |
| `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings` | PASS | Finished release profile successfully. |
| `target/release/bpfopt list-passes` | PASS | Printed 15 passes: `noop`, `map-inline`, `const-prop`, `dce`, `skb-load-bytes`, `bounds-check-merge`, `wide-mem`, `bulk-memory`, `rotate`, `cond-select`, `ccmp`, `extract`, `endian`, `branch-flip`, `prefetch`. |
| DCE smoke command | PASS | Command exited `0`. |
| Non-test LOC | PASS | `non-test LOC: 20680`, under the requested `<= 21099` cap. |

The fix-all report's gate claims are consistent with current verification (`docs/tmp/p3_fix_all_audits_2026-05-10.md:9`, `docs/tmp/p3_fix_all_audits_2026-05-10.md:10`).

## 2. Audit Reconciliation

Fresh2 section 12 lists ten broader cleanup tasks (`docs/tmp/p3_audit_fresh2_2026-05-10.md:181`). The fix-all report's "Fresh-Eyes Section 12" is not the same task list; it addresses older/narrower items such as deleting linear views, adding selected helpers, and documenting canonicalize-map-refs (`docs/tmp/p3_fix_all_audits_2026-05-10.md:25`, `docs/tmp/p3_fix_all_audits_2026-05-10.md:27`).

Full-address count against fresh2 section 12: **0/10**. Partial-address count: **3/10** (`#3`, `#8`, `#10`). Counting partials as half still gives only 1.5/10, well below 50%.

| # | Fresh2 cleanup task | Fix-all claim | Current verification | Status |
|---:|---|---|---|---|
| 1 | Make `BBProgram`/`Block`/`UseDefGraph` fields private (`docs/tmp/p3_audit_fresh2_2026-05-10.md:183`). | No direct fix-all claim. It added helpers, but did not claim field privacy (`docs/tmp/p3_fix_all_audits_2026-05-10.md:30`). | Fields remain public: `BBProgram.blocks/use_def/oracle/btf/kop_reg` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:36`), `Block.insns/terminator` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:54`), and `UseDefGraph.defs/uses` (`bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:43`). | Remaining |
| 2 | Remove/restrict pass-facing PC bridge APIs (`docs/tmp/p3_audit_fresh2_2026-05-10.md:184`). | Fix-all says `current_pc_sites` was deleted and remaining current-PC lookup goes through `site_at_current_pc` (`docs/tmp/p3_fix_all_audits_2026-05-10.md:63`). | Public PC APIs remain: `current_site_pcs`, `site_current_pc`, `branch_target_pcs`, `current_block_start_pc`, `sites_in_*_pc_range`, `site_for_original_pc` (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:289`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:303`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:310`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:343`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:539`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:560`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:592`). Passes still call them. | Remaining |
| 3 | Replace duplicate kop scan/admission loops with a BB-native pattern iterator/helper (`docs/tmp/p3_audit_fresh2_2026-05-10.md:185`). | Partially claimed: kop subprogram skip helper hoisted to BBProgram (`docs/tmp/p3_fix_all_audits_2026-05-10.md:51`). | Admission helper exists (`bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:348`), but duplicated pass loops remain: `rotate` (`bpfopt/crates/bpfopt/src/passes/rotate.rs:83`), `extract` (`bpfopt/crates/bpfopt/src/passes/extract.rs:119`), `endian` (`bpfopt/crates/bpfopt/src/passes/endian.rs:377`), `bulk_memory` (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:255`), `wide_mem` (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:504`). | Partial, remaining |
| 4 | Add BB-native range/external-entry query and delete pass-local PC-window checks (`docs/tmp/p3_audit_fresh2_2026-05-10.md:186`). | Fix-all claims use of `sites_in_frame_pc_range` and `site_at_current_pc` (`docs/tmp/p3_fix_all_audits_2026-05-10.md:44`, `docs/tmp/p3_fix_all_audits_2026-05-10.md:52`). | This centralizes some mechanics but keeps PC-window planning. Examples remain in `extract` (`bpfopt/crates/bpfopt/src/passes/extract.rs:199`), `endian` (`bpfopt/crates/bpfopt/src/passes/endian.rs:470`), `wide_mem` (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:652`), `branch_flip` (`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:280`), and `bounds_check_merge` (`bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:484`). | Remaining |
| 5 | Refactor `map_inline` planning wrappers and repeated current-site scans (`docs/tmp/p3_audit_fresh2_2026-05-10.md:187`). | Fix-all claims some wrappers/defaults were deleted (`docs/tmp/p3_fix_all_audits_2026-05-10.md:46`). | Several wrappers remain: `site_pc`, `site_insn`, `current_site_position`, `site_frame`, `first_site_in_block`, `map_fd_bindings` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:248`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:255`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:260`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:267`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:306`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:310`). Repeated position scans remain (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:4515`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:5395`). | Partial, remaining |
| 6 | Convert pass-local PC-keyed state to `InsnSite`/`BlockId` after boundary adapter (`docs/tmp/p3_audit_fresh2_2026-05-10.md:188`). | No direct fix-all claim. | PC-keyed state remains in `ProfilingData` (`bpfopt/crates/bpfopt/src/pass.rs:164`) and pass-local `bulk_memory` live-out (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:383`). | Remaining |
| 7 | Split recoverable pattern misses from real errors in `cond_select` and `ccmp` (`docs/tmp/p3_audit_fresh2_2026-05-10.md:189`). | No direct fix-all claim; only unrelated `cond_select` unreachable and ccmp wrapper/remap work (`docs/tmp/p3_fix_all_audits_2026-05-10.md:61`, `docs/tmp/p3_fix_all_audits_2026-05-10.md:62`). | Both still convert validation errors into skip reasons: `cond_select` (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:166`) and `ccmp` (`bpfopt/crates/bpfopt/src/passes/ccmp.rs:214`). | Remaining |
| 8 | Resolve BTF deletion semantics explicitly (`docs/tmp/p3_audit_fresh2_2026-05-10.md:190`). | Claimed yes: remap moved near lowering and deleted records are documented/drop-only (`docs/tmp/p3_fix_all_audits_2026-05-10.md:37`). | Lowering now comments the drop (`bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:73`) and bails on malformed surviving order (`bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:78`). However both lowering and view remap still silently `continue` on missing old PCs (`bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:75`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:63`). | Partial, remaining |
| 9 | Delete/test-gate unused public APIs: `BtfRecordsView`, `LinearInsnSite`, possibly `PassManager` (`docs/tmp/p3_audit_fresh2_2026-05-10.md:191`). | No direct fix-all claim. `PassManager` explicitly remains (`docs/tmp/p3_fix_all_audits_2026-05-10.md:33`). | APIs remain public/exported: `BtfRecordsView` (`bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:10`, `bpfopt/crates/bpfopt/src/analysis/mod.rs:17`), `LinearInsnSite` (`bpfopt/crates/bpfopt/src/insn.rs:192`), and `PassManager` (`bpfopt/crates/bpfopt/src/pass.rs:839`). | Remaining |
| 10 | Add acceptance evidence: 542 roundtrip and pass-equivalence harness/update (`docs/tmp/p3_audit_fresh2_2026-05-10.md:192`). | Fix-all skipped pass-equivalence by request (`docs/tmp/p3_fix_all_audits_2026-05-10.md:36`) but claimed tests pass (`docs/tmp/p3_fix_all_audits_2026-05-10.md:12`). | Roundtrip evidence now exists and passed: test asserts 542 programs (`bpfopt/crates/bpfopt/tests/bbprogram_roundtrip.rs:10`, `bpfopt/crates/bpfopt/tests/bbprogram_roundtrip.rs:13`). I found no old-vs-new pass-equivalence harness; fix-all explicitly skipped it. | Partial, remaining |

## 3. Per-Pass A/B/C/D Rating

Rating key reused from fresh2: A = BBProgram methods directly, no flat scan/lower, no PC-keyed analysis; B = BBProgram entry but private linear view, PC-keyed analysis, or PC-to-site bridge; C = lowers to flat bytecode for scan/detection then remaps; D = thin wrapper around old flat `BpfProgram` pass (`docs/tmp/p3_audit_fresh2_2026-05-10.md:79`).

| Pass | Rating | Evidence |
|---|---:|---|
| `noop` | A | No mutation or scan (`bpfopt/crates/bpfopt/src/passes/noop.rs:19`). |
| `dce` | A | Uses BB use-def/delete path without PC maps (`bpfopt/crates/bpfopt/src/passes/dce.rs:25`, `bpfopt/crates/bpfopt/src/passes/dce.rs:30`, `bpfopt/crates/bpfopt/src/passes/dce.rs:42`). |
| `const-prop` | B | Uses current-PC maps for oracle remap/simulation (`bpfopt/crates/bpfopt/src/passes/const_prop.rs:149`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:481`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:551`). |
| `bounds-check-merge` | B | Uses current PC maps, branch target PCs, and PC-range scans (`bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:76`, `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:77`, `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:484`). |
| `wide-mem` | B | Uses branch-target PCs and builds flat block/cross-block instruction windows (`bpfopt/crates/bpfopt/src/passes/wide_mem.rs:504`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:512`, `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:692`). |
| `bulk-memory` | B | Uses current PCs, direct block instruction slices, and `HashMap<usize, RegSet>` (`bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:296`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:303`, `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:383`). |
| `rotate` | B | BB replacement path, but site detection/admission still bridges through current PCs and direct block indexing (`bpfopt/crates/bpfopt/src/passes/rotate.rs:83`, `bpfopt/crates/bpfopt/src/passes/rotate.rs:95`, `bpfopt/crates/bpfopt/src/passes/rotate.rs:166`). |
| `cond-select` | B | BB diamond mutation, but scan/shape logic uses current PCs and PC block-start checks (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:298`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:365`, `bpfopt/crates/bpfopt/src/passes/cond_select.rs:375`). |
| `ccmp` | B | BB mutation, but scan uses current-PC/block-start maps; also has production arch skip (`bpfopt/crates/bpfopt/src/passes/ccmp.rs:160`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:377`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:381`). |
| `extract` | B | Uses current PCs and direct `prog.blocks[block].insns` scan (`bpfopt/crates/bpfopt/src/passes/extract.rs:119`, `bpfopt/crates/bpfopt/src/passes/extract.rs:128`, `bpfopt/crates/bpfopt/src/passes/extract.rs:199`). |
| `endian` | B | Uses block-local flat scans, preserved `Vec<BpfInsn>`, and current-PC cross-block checks (`bpfopt/crates/bpfopt/src/passes/endian.rs:180`, `bpfopt/crates/bpfopt/src/passes/endian.rs:388`, `bpfopt/crates/bpfopt/src/passes/endian.rs:416`, `bpfopt/crates/bpfopt/src/passes/endian.rs:470`). |
| `branch-flip` | B | Mutates BB terminators/order, but planning is PC/profile keyed (`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:254`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:255`, `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:280`). |
| `prefetch` | B | Heavily current-PC/range-by-PC driven (`bpfopt/crates/bpfopt/src/passes/prefetch.rs:217`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:378`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:386`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:654`). |
| `map-inline` | B | Large wrapper/current-site layer and direct BTF mutation remain (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:248`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:260`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2056`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2619`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3245`). |
| `skb-load-bytes` | B | BB rewrite path, but branch-target/current-PC checks remain (`bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:89`, `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:130`, `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:131`). |

Summary: **2 A, 13 B, 0 C, 0 D**. Because any non-A pass fails the user-provided convergence rule, Phase 3 is not converged.

## 4. CLAUDE/AGENTS Rule Scan

### ReJIT Filtering Hints

No Phase 3 bpfopt ReJIT filtering path found. Repository search found the existing runner API, but not a filtering override: base returns all tracked programs (`runner/libs/app_runners/base.py:35`), case common only consumes it or falls back to artifacts (`runner/libs/case_common.py:76`), and corpus driver uses it as expected-program metadata (`corpus/driver.py:260`). No `LifecycleAbort`, `_EXCLUDED_PROGRAM_NAMES`, or pass-exclusion policy was found in active runner/corpus/bpfopt paths.

### Fallback / Legacy / Silenced Errors

No non-test bpfopt Rust hits for `fallback`, `legacy`, `.ok()`, `unwrap_or`, `unwrap_or_default`, `let _ =`, `todo!`, `unimplemented!`, `unreachable!`, or `#[allow(dead_code)]`.

Remaining fail-fast concerns:

- `parse_bytecode` still uses `expect("chunk is 8 bytes")` in production after checking length (`bpfopt/crates/bpfopt/src/main.rs:431`, `bpfopt/crates/bpfopt/src/main.rs:440`). Low risk, but still a literal panic path.
- `run_pass_once` returns a skipped result when required kop targets are missing (`bpfopt/crates/bpfopt/src/pass.rs:931`, `bpfopt/crates/bpfopt/src/pass.rs:948`, `bpfopt/crates/bpfopt/src/pass.rs:962`). The CLI validates koperation before running (`bpfopt/crates/bpfopt/src/main.rs:301`), but the library/pipeline path still downgrades to skip.
- `cond_select` and `ccmp` still turn validation errors into skip reasons (`bpfopt/crates/bpfopt/src/passes/cond_select.rs:166`, `bpfopt/crates/bpfopt/src/passes/ccmp.rs:214`).
- BTF remap explicitly documents deleted-instruction drops during lowering, but still continues rather than recording a mutation-side deletion or failing (`bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:73`, `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:75`).

### Dead Code

Compiler-level gate is clean: clippy with `-D dead_code -D warnings` passed. Architectural/test-facing public APIs remain because public exports are not compiler-dead: `BtfRecordsView` (`bpfopt/crates/bpfopt/src/analysis/bbprogram_btf.rs:10`, `bpfopt/crates/bpfopt/src/analysis/mod.rs:17`), `LinearInsnSite` (`bpfopt/crates/bpfopt/src/insn.rs:192`), and `PassManager` (`bpfopt/crates/bpfopt/src/pass.rs:839`).

## 5. Final Convergence Verdict

**Verdict: not-converged.**

Why:

- All requested gates pass.
- LOC cap passes: 20,680 non-test LOC.
- Clippy is clean.
- No P0 ReJIT filtering regression was found.
- Fresh2 section 12 is not sufficiently addressed: 0/10 fully addressed, 3/10 partial.
- Pass ratings are 2 A and 13 B, so the "15A passes" convergence condition fails.
- Remaining P1 architecture blockers: public mutable BBProgram internals, pass-facing PC bridge APIs, duplicated PC-window admission logic, and error-as-skip paths.

This is real progress on build health and several earlier cleanup items, but it is not final Phase 3 convergence.

## 6. Prioritized Remaining Tasks

1. Make `BBProgram`, `Block`, and `UseDefGraph` representation fields private; add focused queries/mutation APIs for the real call sites.
2. Remove pass-facing current-PC bridge APIs from optimization planning. Keep original/current PC conversion only at CLI/profile/BTF boundary adapters.
3. Replace duplicated kop scan/admission loops with a BB-native site-window/pattern helper.
4. Add a BB-native external-entry/branch-target-in-range query and delete pass-local PC-window checks.
5. Refactor `map_inline` around a planned ordered-site/index object so trivial wrappers and repeated `current_sites()` scans disappear.
6. Split match misses from invariant errors in `cond_select` and `ccmp`; propagate real validation failures.
7. Finish acceptance evidence: keep the 542 roundtrip test, then add or explicitly replace the old-vs-new pass-equivalence story in the design contract.

