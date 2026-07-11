# Phase 3 BBProgram Migration Wave-5 Review

Date: 2026-05-10  
Repository: `/home/yunwei37/workspace/bpf-benchmark`  
Branch: `main`  
Mode: read-only audit, except writing this report.

## Evidence Commands

Commands used:

- `git status --short --branch`
- `rg` for the requested map-inline negative gates, pass BBProgram entry/mutation evidence, stale legacy names, helper duplication, TODO/FIXME, and panic-family scans
- `wc -l`
- `cargo test --release --manifest-path bpfopt/Cargo.toml`
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`
- `bpfopt/target/release/bpfopt list-passes`
- `bpfopt/target/release/bpfopt --pass dce ...`

State caveat: the tree remains dirty and branch state is `main...origin/main [ahead 3]`. Conclusions use current filesystem line numbers.

Verification:

- `cargo test --release --manifest-path bpfopt/Cargo.toml`: PASS, `217` tests (`188 + 16 + 1 + 12`)
- `cargo clippy --release --manifest-path bpfopt/Cargo.toml --all-targets -- -D dead_code -D warnings`: PASS
- `bpfopt/target/release/bpfopt list-passes | wc -l`: `15`
- DCE smoke on `otelcol-ebpf-profiler_profiling/47_perf_unwind_php/canonicalize_output.bin`: exit `0`

Current LOC:

- `rg --files bpfopt/crates/bpfopt/src | xargs wc -l`: `26167 total`
- `rg --files bpfopt/crates/bpfopt/src | rg -v '(_tests\.rs$|/tests/|test_helpers\.rs$)' | xargs wc -l`: `22099 total`
- `wc -l bpfopt/crates/bpfopt/src/passes/map_inline.rs`: `5572`
- `wc -l bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs`: `712`

## 1. map_inline A Verification

Requested negative gates:

- `rg -n "MapInlineView" ...`: no matches.
- `rg -n "program\.insns\[pc\]" ...`: no matches.
- `rg -n "HashMap<usize," ...`: no matches.
- `rg -n "sites_for_pc_iter" ...`: no matches.
- `rg -n "attach_constant_key_sites" ...`: no matches.
- `rg -n "call_pc:" ...`: no matches.
- `rg -n "map_load_pc:|inner_call_pc:|outer_alias_copy_pcs:|materialization_pcs:|alias_copy_pcs:|r2_.*_pc:|null_check_pc:" ...`: no matches.
- `rg -n "linear_insn_sites" ...`: no matches.
- `rg -n "BpfProgram::new" ...`: raw matches exist only in `#[cfg(test)]` / test code: `map_info.rs:204`, `map_info.rs:496`, `map_info.rs:540`, `map_info.rs:554`, `map_info.rs:576`. The production-gated path has zero `BpfProgram::new` use; the helper containing the first hit is `#[cfg(test)]` at `map_info.rs:194-205`, and the rest are under the test module.

Positive A evidence:

- Core records are site-first: `MapLookupSite` stores `call_site` / `map_load_site` at `map_inline.rs:1096-1099`; `MapInMapChain` stores `inner_call_site`, alias sites, and null-check site at `map_inline.rs:1110-1115`; `ConstantKey` stores materialization as `InsnSite` / `BTreeSet<InsnSite>` at `map_inline.rs:1119-1129`; `R0UseClassification` stores site vectors at `map_inline.rs:1159-1165`.
- PC values are boundary/diagnostic lookups: `site_pc()` derives current PC from `BBProgram::current_site_pcs()` at `map_inline.rs:248-253`; `FixedLoadUse::pc()` delegates to that boundary helper at `map_inline.rs:1152-1155`.
- The expensive analyses no longer walk a private flat instruction substrate. Map-in-map chain discovery starts from `current_sites_after_in_frame()` at `map_inline.rs:1256-1265`; direct map-load backtracking uses `current_sites_before_in_frame_rev()` at `map_inline.rs:4406-4417`; R0-use classification uses `current_sites_after_in_frame()` at `map_inline.rs:5104-5118`.
- PC hints are resolved at the pass boundary: `ResolvedInlineHints` is keyed by `InsnSite` at `map_inline.rs:1796-1798`; `MapInlineHintAnchor::Pc` is translated via `current_pc_sites()` once in `resolve_inline_hint_anchors()` at `map_inline.rs:2052-2080`.
- Edits are keyed and applied by site: `apply_replacements_and_deletions()` uses `BTreeMap<InsnSite, ...>` / `BTreeSet<InsnSite>` at `map_inline.rs:3177-3204`; `replace_site()` and `delete_site()` call `BBProgram::replace_range()` / `replace_terminator()` at `map_inline.rs:3208-3238`.
- Map metadata scanning is BBProgram-native in production: `analyze_map_info()` calls `collect_map_bindings_from_sites()` at `map_info.rs:142-152`; that helper iterates `program.current_sites()` and `program.insn_at(site)` at `map_info.rs:211-243`.

Conclusion: `map_inline` is genuinely A-rated. The wave-4 B substrate (`MapInlineView`, production PC-keyed maps, PC identity fields, and bridge helpers) is gone.

## 2. Per-Pass Rating

Rating key:

- A: production path operates on `BBProgram`; no old flat pass wrapper, no production `BpfProgram::new(insns)`, no full-program flat scan as edit identity, and mutations use BBProgram APIs.
- B: no old flat wrapper, but still carries a private linear/current-PC view, PC-keyed analysis state, or local address-plan compatibility layer.
- C: production path lowers to flat bytecode or relies on full-program flat rewrite shims.
- D: wrapper around the old flat `BpfProgram` pass.

| Pass | Wave 5 | Evidence |
| --- | --- | --- |
| `noop.rs` | A | Direct `BBProgram` entry at `noop.rs:19`; unchanged result only. |
| `dce.rs` | A | Direct `BBProgram` entry at `dce.rs:20`; deletes through `prog.delete_insn(def)?` at `dce.rs:42`. |
| `const_prop.rs` | A | Direct entry at `const_prop.rs:459`; replacements use `prog.replace_range(...)` at `const_prop.rs:511`; scans `logical_sites_in_block` at `const_prop.rs:590`. |
| `bounds_check_merge.rs` | A | Direct entry at `bounds_check_merge.rs:60`; mutates via `replace_range` / `delete_cond_branch` at `bounds_check_merge.rs:170-199`; scans logical sites at `bounds_check_merge.rs:257`. |
| `branch_flip.rs` | A | Direct entry at `branch_flip.rs:214`; mutates via `replace_terminator` / `permute_blocks` at `branch_flip.rs:455-477`; scans BBProgram blocks/sites at `branch_flip.rs:513-522`. |
| `rotate.rs` | A | Direct entry at `rotate.rs:75`; scans `sites_in_block` at `rotate.rs:85-87`; applies with `replace_range` at `rotate.rs:152-155`. |
| `extract.rs` | A | Direct entry at `extract.rs:110`; scans `sites_in_block` at `extract.rs:122-124`; applies with `replace_range` at `extract.rs:178-182`. |
| `endian.rs` | A | Direct entry at `endian.rs:370`; scans `sites_in_block` at `endian.rs:383-385`; applies with `replace_range` at `endian.rs:451`. |
| `bulk_memory.rs` | A | Direct entry at `bulk_memory.rs:240`; scans blocks/sites and checked liveness at `bulk_memory.rs:293-306`; applies with `replace_range` at `bulk_memory.rs:278-283`. |
| `prefetch.rs` | A | Direct entry at `prefetch.rs:203`; scans sites at `prefetch.rs:356-362`; applies insertion with `replace_range` at `prefetch.rs:275-280`. |
| `wide_mem.rs` | A | Direct entry at `wide_mem.rs:496`; per-block body view at `wide_mem.rs:513-515`; applies with `replace_range` at `wide_mem.rs:634-635`. |
| `skb_load_bytes.rs` | A | Direct entry at `skb_load_bytes.rs:80`; scans per-block BBProgram body views at `skb_load_bytes.rs:120-126`; applies with `replace_range` at `skb_load_bytes.rs:110-115`. |
| `cond_select.rs` | A | Direct entry at `cond_select.rs:116`; mutates through `replace_diamond_with_insns` at `cond_select.rs:196-197`; scans BBProgram branches at `cond_select.rs:298-306`. |
| `ccmp.rs` | A | Direct entry at `ccmp.rs:160`; uses `replace_terminator`, `merge_linear_chain`, and `replace_range` at `ccmp.rs:275-303`; scans blocks/sites at `ccmp.rs:398-408`. |
| `map_inline.rs` | A | Direct entry at `map_inline.rs:2501-2507`; core planning is site-first at `map_inline.rs:1096-1165`; edits are site-keyed at `map_inline.rs:3177-3238`. |

Result: `15A`.

## 3. Remaining P0/P1

Wave 4 state was `0 P0, 1 P1` with the remaining P1 being `map_inline` B-rated.

Wave 5 state:

- P0: `0`
- P1: `0`

The wave-4 `map_inline` P1 is fixed. I found no new P0/P1 migration blocker.

## 4. Convergence Verdict

Verdict: **converged**.

Criteria:

- Pass ratings: `15A`
- P0/P1: `0/0`
- Tests: PASS, `217`
- Clippy: PASS with `-D dead_code -D warnings`
- CLI smoke: PASS, `15` listed passes and DCE smoke exit `0`

Phase 3 BBProgram migration is done. Further work should move to a follow-on per-pass cleanup/audit phase rather than another migration wave.

## 5. Cross-Pass Quality Scan

No convergence blockers were found in the cross-pass scan. Cleanup candidates for the next audit phase:

1. Hoist common slot/terminator helpers. `bounds_check_merge` has `is_terminator_site()` at `bounds_check_merge.rs:210-213`; `map_inline` has the same concept at `map_inline.rs:3250-3252`. Program-length and slot-bound helpers also overlap: `bounds_check_merge.rs:228-236`, `map_inline.rs:3299-3310`, and `prefetch.rs:766-790`. A small BBProgram API for terminator-site checks and slot/frame bounds would remove repeated local code.

2. Hoist ordered frame/site range helpers. `map_inline` carries `current_sites_after_in_frame()` / `current_sites_before_in_frame_rev()` at `map_inline.rs:271-304`; `prefetch` carries PC-range site collection at `prefetch.rs:728-764`. These are now legitimate site-first helpers, but they are reusable BBProgram traversal APIs rather than pass-specific logic.

3. Keep reducing linear-view surface. `ProgramLinearView` remains as a real production API at `bbprogram.rs:90-101` / `bbprogram.rs:443-476`, and the pass pipeline uses it only for before/after instruction counts at `pass.rs:1031-1033`. This is not an A-rating blocker, but a `BBProgram::program_slot_len()`-style API would let the pipeline stop materializing a full program linear view for counts.

4. Delete the remaining test-only `BpfProgram` facade when map-info tests are migrated. `BpfProgram`, `MapProvider`, and `SnapshotMapProvider` are `#[cfg(test)]` in `pass.rs:291-324` and `pass.rs:371-429`; `MapInfoAnalysis::run()` and flat test collection helpers are also test-only at `map_info.rs:135-138`, `map_info.rs:169-208`, and `map_info.rs:246-278`. They do not affect production convergence, but they are stale BBProgram-migration scaffolding.

5. Dedup the remaining CLI-local JSON reader. Passes now share `read_json_file()` from `bbprogram_helpers.rs:80-82`, and `map_inline` imports it at `map_inline.rs:12`. `main.rs` still has a local duplicate at `main.rs:1048-1052`; this is outside the per-pass migration path but is a straightforward cleanup.

6. Consider a small kop-proof helper audit. Several kop passes have similar proof decode / length / register-use boilerplate: `cond_select.rs:16-31`, `ccmp.rs:20-60`, `rotate.rs:24-60`, `extract.rs:17-31`, `endian.rs:53-63`, `prefetch.rs:30-45`, and `bulk_memory.rs:34-112`. The formats differ enough that this is not urgent, but the repetition is visible.

7. Review diagnostic `unwrap_or(...)` defaults in `map_inline`. There are no production `unwrap()` / `expect()` / `panic!()` hits in pass implementations; the panic-family `rg` hits are tests or `#[cfg(test)]`. Separate from that, `map_inline` uses diagnostic fallbacks like `site_pc(...).unwrap_or(usize::MAX)` at `map_inline.rs:1706`, `map_inline.rs:1719`, `map_inline.rs:1738`, `map_inline.rs:3557`, and `map_inline.rs:3944`. These do not change behavior, but the fail-fast audit phase should decide whether invariant failures should be propagated even for diagnostics.

8. TODO/FIXME scan is clean. `rg -n "TODO|FIXME" bpfopt/crates/bpfopt/src` returns no matches.

9. Stale deleted-type scan is clean for production migration blockers. `RewritePlan` and `AnalysisCache` have no source hits outside docs. `BpfProgram::new` in map-info is test-only, as listed above. `MapInlineView`, `MapInlineProgram`, `linear_insn_sites`, `sites_for_pc_iter`, and `attach_constant_key_sites` have no map-inline production hits.
