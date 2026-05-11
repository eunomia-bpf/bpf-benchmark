# Fresh Phase 3 BBProgram Audit - 2026-05-10

Scope: fresh read-only audit of `CLAUDE.md`, `docs/bbprogram-architecture-design.md`, and `bpfopt/crates/bpfopt/src/**/*.rs`. I did not read prior `docs/tmp/p3_*.md` reports.

## 1. Executive Summary

- The `--pass` CLI path is mostly aligned with design section 3: `main.rs:292-317` reads bytecode, lifts once, runs a pass pipeline, lowers once, and writes output. The `--canonicalize-map-refs` path remains an explicit production `Vec<BpfInsn>` mutation path at `main.rs:246-264` and `main.rs:456-514`.
- Pass migration is real but not converged. `dce` and `noop` are A-level BBProgram-native. The other 13 passes are B-level: they enter through `BBProgram`, but still use PC maps, direct `prog.blocks[...]` access, or private linear views. I found no C/D pass that lowers inside the pass or wraps the old flat `BpfProgram` production path.
- The largest design drift is the bridge layer: `BBProgram::current_site_pcs`, `current_pc_sites`, `block_body_linear_view`, `program_linear_view`, and public `blocks`/`btf` fields keep PC-indexed and vector-indexed analysis alive (`analysis/bbprogram.rs:131-137`, `analysis/bbprogram.rs:369-443`).
- Fail-fast conformance is partial. Several production APIs silently default or drop information: invalid CFG successors are ignored (`analysis/bbprogram.rs:591-600`), invalid block site queries return empty (`analysis/bbprogram.rs:665-668`), BTF records for deleted/unknown sites are silently skipped (`analysis/bbprogram_btf.rs:63-68`, `analysis/bbprogram_btf.rs:105-110`), and verifier oracles default to empty in some pass paths (`passes/const_prop.rs:474`, `passes/wide_mem.rs:507`).
- Final verdict: **not-conformant**, with substantial progress. The pass bodies are no longer flat `BpfProgram` rewrites, but the Phase 3 design contract is not genuinely met because PC/linear bridges remain central, non-test LOC grew by the provided baseline, test count dropped from 402 to 217, and benchmark-tree files changed.

## 2. LOC Accounting

Current top-25 Rust source files by LOC, compared with `bfa802c9`:

| File | Current | `bfa802c9` | Delta |
|---|---:|---:|---:|
| `passes/map_inline.rs` | 5572 | 5356 | +216 |
| `main.rs` | 1471 | 1459 | +12 |
| `verifier_log.rs` | 1179 | 1179 | 0 |
| `analysis/bbprogram.rs` | 1139 | 0 | +1139 |
| `pass.rs` | 1121 | 1550 | -429 |
| `passes/const_prop.rs` | 990 | 819 | +171 |
| `passes/bulk_memory.rs` | 868 | 835 | +33 |
| `insn.rs` | 834 | 811 | +23 |
| `analysis/bbprogram_api.rs` | 832 | 0 | +832 |
| `passes/prefetch.rs` | 827 | 782 | +45 |
| `passes/wide_mem.rs` | 731 | 667 | +64 |
| `passes/map_inline/map_info.rs` | 712 | 571 | +141 |
| `passes/cond_select.rs` | 702 | 552 | +150 |
| `passes/branch_flip.rs` | 678 | 541 | +137 |
| `passes/bounds_check_merge.rs` | 640 | 549 | +91 |
| `passes/map_inline_tests.rs` | 635 | 3133 | -2498 |
| `passes/ccmp.rs` | 583 | 363 | +220 |
| `analysis/bbprogram_lift.rs` | 494 | 0 | +494 |
| `passes/endian.rs` | 493 | 455 | +38 |
| `passes/rotate.rs` | 486 | 499 | -13 |
| `passes/const_prop_tests.rs` | 396 | 408 | -12 |
| `pass_tests.rs` | 321 | 836 | -515 |
| `passes/skb_load_bytes.rs` | 313 | 335 | -22 |
| `test_helpers.rs` | 303 | 108 | +195 |
| `analysis/bbprogram_use_def.rs` | 292 | 0 | +292 |

Top 5 LOC growers:

| File | Delta | Assessment |
|---|---:|---|
| `analysis/bbprogram.rs` | +1139 | Partly justified as core IR, but bloated by PC bridge views and public mutable-ish fields. |
| `analysis/bbprogram_api.rs` | +832 | Partly justified as mutation API, but clone-then-mutate wrappers repeat heavily. |
| `analysis/bbprogram_lift.rs` | +494 | Justified; lift is inherently linear-bytecode boundary code. |
| `analysis/bbprogram_use_def.rs` | +292 | Mostly justified; central analysis replacing old cache pieces. |
| `passes/ccmp.rs` | +220 | Mostly pass migration and tests for new kinsn encoding; still PC-keyed. |

Total Rust LOC is down `26167 - 29528 = -3361`. That total reduction is misleading: it is driven by test deletion and old module removal, especially `passes/map_inline_tests.rs` (-2498), `pass_tests.rs` (-515), and `rewrite.rs` (-534). The provided non-test baseline says current non-test LOC is `22099` versus start `19357`, or **+2742 non-test LOC**. The growth is primarily new BBProgram infra (`bbprogram.rs`, API, lift/lower/BTF/use_def/helpers, about +3090 to +3250 depending classification) plus pass growth (`ccmp`, `map_inline`, `const_prop`, `cond_select`, `map_info`, `branch_flip`, `bounds_check_merge`), partially offset by `pass.rs` and deleted legacy analysis/rewrite modules.

## 3. Per-Pass Rating

| Pass | Rating | Evidence | Reason |
|---|---|---|---|
| `passes/dce.rs` | A | `run_on_bbprogram` uses `prog.use_def` and `prog.delete_insn` at `dce.rs:25-43`; instruction query uses `prog.insn_at` at `dce.rs:73-76`. | Native BBProgram mutation; no lower/flat scan/PC bridge in production. |
| `passes/noop.rs` | A | `BpfPass::run` returns unchanged at `noop.rs:104-110`. | Native no-op. `run_on_bbprogram` at `noop.rs:114-116` is redundant but harmless. |
| `passes/const_prop.rs` | B | Oracle maps verifier PCs to sites via `prog.current_site_pcs()` at `const_prop.rs:149`; pass uses `prog.current_site_pcs()` at `const_prop.rs:475`; applies via `prog.replace_range` at `const_prop.rs:511`. | BBProgram entry and mutation, but verifier planning remains PC/site bridged. |
| `passes/bounds_check_merge.rs` | B | Uses `current_site_pcs`, `current_pc_sites`, `branch_target_pcs` at `bounds_check_merge.rs:76-78`; still returns a legacy addr-map-shaped tuple at `bounds_check_merge.rs:61` and `bounds_check_merge.rs:65-68`; applies via `replace_range`/`delete_cond_branch` at `bounds_check_merge.rs:170-199`. | Native application, PC-keyed planning and leftover compatibility shape. |
| `passes/branch_flip.rs` | B | Fails fast on missing PMU data at `branch_flip.rs:225-235`; uses `branch_target_pcs` at `branch_flip.rs:254` and `current_site_pcs` at `branch_flip.rs:514`; rewrites terminators/block order at `branch_flip.rs:455-477`. | CFG-native rewrite but PC-keyed profile and detection. |
| `passes/map_inline.rs` + `map_info.rs` | B | Main pass enters BBProgram at `map_inline.rs:2497-2506`; local `site_pc` recomputes current PCs at `map_inline.rs:248-253`; more PC bridges at `map_inline.rs:2056`, `map_inline.rs:2620`, `map_inline.rs:3243`; applies through `replace_range`/`replace_terminator` at `map_inline.rs:3212-3238`. Map info production scans sites at `map_info.rs:142-167` and `map_info.rs:211-243`; old `BpfProgram` path is cfg(test) at `map_info.rs:135-139`, `map_info.rs:169-208`. | Production is BBProgram-based, but it is still deeply PC-bridged and large. |
| `passes/rotate.rs` | B | Uses `prog.current_site_pcs()` at `rotate.rs:83`; matches through block-local linear helper `try_match_rotate(&block.insns, ...)` at `rotate.rs:181` and `rotate.rs:260-283`; applies via `replace_range` at `rotate.rs:152`. | BBProgram mutation, private linear matching. |
| `passes/extract.rs` | B | Uses `current_site_pcs`/`current_pc_sites` at `extract.rs:119-120`; directly scans `prog.blocks[block.0].insns` at `extract.rs:129`; applies via `replace_range` at `extract.rs:178`. | BBProgram entry, direct vector scan and PC bridge. |
| `passes/endian.rs` | B | Block-local scan over `&[BpfInsn]` at `endian.rs:89`; direct `prog.blocks[block.0].insns` at `endian.rs:181`, `endian.rs:390`, `endian.rs:418`; PC bridges at `endian.rs:378-379`; applies via `replace_range` at `endian.rs:451`. | BBProgram entry, direct vector scan and PC bridge. |
| `passes/bulk_memory.rs` | B | Uses `current_site_pcs` at `bulk_memory.rs:296`; direct block instruction access at `bulk_memory.rs:303`; PC-indexed liveness map at `bulk_memory.rs:404`; local linear matchers at `bulk_memory.rs:401` and `bulk_memory.rs:482`; applies via `replace_range` at `bulk_memory.rs:279`. | BBProgram mutation, but private block-linear analysis. |
| `passes/prefetch.rs` | B | Uses `current_site_pcs` at `prefetch.rs:217`; PC-centric scan ranges at `prefetch.rs:353-387` and `prefetch.rs:459-467`; direct block access at `prefetch.rs:380`, `prefetch.rs:511-514`, `prefetch.rs:629`, `prefetch.rs:782`; applies via `replace_range` at `prefetch.rs:277`. | BBProgram mutation with PC-heavy planning. |
| `passes/wide_mem.rs` | B | Flat block scan helper `scan_wide_mem(insns: &[BpfInsn])` at `wide_mem.rs:62-83`; production uses `block_body_linear_view` and `view.insns` at `wide_mem.rs:513-515`; applies via `replace_range` at `wide_mem.rs:635`. | No full lower, but private linear view is central. |
| `passes/skb_load_bytes.rs` | B | Production scan uses `block_body_linear_view` at `skb_load_bytes.rs:125`; direct `view.insns[rel_pc]` at `skb_load_bytes.rs:133` and `skb_load_bytes.rs:152`; applies via `replace_range` at `skb_load_bytes.rs:111-115`. | BBProgram mutation, private linear view. |
| `passes/cond_select.rs` | B | Enters BBProgram at `cond_select.rs:112-121`; uses `current_site_pcs` at `cond_select.rs:299`; direct `block.insns` access at `cond_select.rs:411` and `cond_select.rs:459`; applies via `replace_diamond_with_insns` at `cond_select.rs:197`. | CFG-aware rewrite, but PC/site and direct-vector matching remain. |
| `passes/ccmp.rs` | B | Enters BBProgram at `ccmp.rs:156-165`; applies via `replace_terminator`, `merge_linear_chain`, `replace_range` at `ccmp.rs:276-296`; uses `current_site_pcs` at `ccmp.rs:398`; direct block length at `ccmp.rs:286`. | CFG-aware rewrite, but PC/site and direct-vector remnants remain. |

## 4. Cross-Pass Duplicate Code Inventory

- Terminator-site detection duplicated at `bounds_check_merge.rs:210-213` and `map_inline.rs:3250-3253`. Recommendation: add `BBProgram::is_terminator_site(site)` or a helper in `analysis/bbprogram_helpers.rs`.
- Current-PC lookup duplicated as shared `site_current_pc` (`analysis/bbprogram_helpers.rs:39-47`) and local `map_inline::site_pc` (`map_inline.rs:248-253`). Recommendation: delete the local helper and pass/precompute the shared map, or add `BBProgram::site_current_pc`.
- Block slot/slot-range helpers are scattered: `block_slot_offset` at `analysis/bbprogram_helpers.rs:28-37`, `block_slot_len` at `analysis/bbprogram.rs:554-564`, and prefetch frame/block slot bounds at `prefetch.rs:766-790`. Recommendation: hoist slot length/range queries into the BBProgram API.
- Kinsn proof decoders repeat the same shape: `rotate.rs:24-37`, `extract.rs:17-19`, `endian.rs:53-55`, `bulk_memory.rs:34-40`, `prefetch.rs:30-32`, `cond_select.rs:16-18`, `ccmp.rs:20-22`. Recommendation: add a small `decode_packed_proof(payload, proof_len_fn)` helper, or accept if local readability is preferred.
- Register-state simulation is partially shared but still repeated: shared `SimpleRegValue`/`advance_reg_state` at `analysis/bbprogram_helpers.rs:104-142`; pass-local state machines in `bulk_memory.rs:120-157`, `skb_load_bytes.rs:24-51`, `const_prop.rs:581-688`, `bounds_check_merge.rs:563-622`, and `prefetch.rs:423-608`. Recommendation: hoist traversal scaffolding, keep pass-specific lattices local.
- Subprogram-boundary replacement checks exist both as old linear helper `pass.rs:235-287` and BBProgram method `analysis/bbprogram.rs:485-552`. Recommendation: delete the linear helper if no production caller exists.
- JSON read helper duplicated in `main.rs:1048-1052` and `analysis/bbprogram_helpers.rs:80-84`. Recommendation: share one helper if the bin/lib boundary permits; otherwise accept this small duplication.
- Packet/prog-type layout logic is partly shared in `packet_ctx_layout` (`analysis/bbprogram_helpers.rs:49-78`) while `wide_mem.rs:421-454` maintains its own packet-unsafe classification. Recommendation: hoist or document why these policy sets intentionally differ.
- Single-block scan/reverse-apply scaffolding repeats across rotate/extract/endian/bulk/wide/skb. Recommendation: only abstract if a simple BBProgram window iterator can replace the private linear scans without adding another bridge layer.

## 5. Meaningless Wrappers / Abstractions

- `noop.rs:114-116`: `run_on_bbprogram` is a second no-op entry point that duplicates `BpfPass::run`. Recommendation: delete unless tests need a uniform helper.
- `analysis/bbprogram_api.rs:358-360`: `try_split_block` is a one-line wrapper around `split_block`; `rg` shows no caller except the definition. Recommendation: delete.
- `analysis/bbprogram.rs:212-214`: `blocks()` just returns `self.blocks.iter()` while `BBProgram::blocks` is public at `analysis/bbprogram.rs:131-132`. Recommendation: make the field private and keep the iterator, or remove the wrapper.
- `analysis/bbprogram_use_def.rs:24-39`: `DefSite::site` and `UseSite::site` are trivial conversions. Recommendation: acceptable for readability if fields remain structured; otherwise inline after field privacy is decided.
- `map_inline.rs:1101-1104` and `map_inline.rs:1152-1155`: tiny `pc()` wrappers around local `site_pc`. Recommendation: delete if `site_pc` is removed; otherwise acceptable.
- `pass.rs:751-753`: `KinsnRegistry::unavailable()` is a trivial wrapper over `new()`. Recommendation: keep only if the semantic name is used to document "no target sidecar".
- `pass.rs:935-1043`: `PassManager` is a full policy/pipeline abstraction, but production `main.rs:334-347` builds it for a single explicit pass. Recommendation: inline single-pass execution in `main.rs` or keep only test/custom-pipeline support.
- `passes/const_prop.rs:447-450`: `RewriteOutputs` is not the old forbidden `RewriteOutput`, but it is a small mutable bundle used to thread vectors through `rewrite_alu_if_constant` (`const_prop.rs:488`, `const_prop.rs:587`). Recommendation: acceptable, or replace with a local closure/context if simplifying.

## 6. Non-Design-Conforming Patterns

- No production pass calls `lower(prog)`. The only production lower boundary is `main.rs:316`; test use appears at `analysis/bbprogram_lift.rs:364`.
- No production `BpfProgram::new(insns)` path was found. `BpfProgram` is `#[cfg(test)]` at `pass.rs:291-294`; `BpfProgram::new` is under that cfg at `pass.rs:535-558`; uses in `map_info.rs:204` are inside a `#[cfg(test)]` function (`map_info.rs:169-208`) and test modules.
- Production `Vec<BpfInsn>` mutation still exists outside `--pass`: `run_canonicalize_map_refs` reads and mutates `Vec<BpfInsn>` at `main.rs:246-264`; `canonicalize_map_refs_to_idx` mutates `&mut [BpfInsn]` and indexes `insns[i]` at `main.rs:456-514`. This may be allowed by the v3 canonicalization boundary, but it fails a literal "no production Vec mutation path" reading.
- Direct `prog.blocks[...]`/block-vector access remains in production pass planning: `extract.rs:129`, `endian.rs:181`, `endian.rs:390`, `endian.rs:418`, `bulk_memory.rs:303`, `bulk_memory.rs:393-396`, `bulk_memory.rs:844`, `prefetch.rs:380`, `prefetch.rs:511-514`, `prefetch.rs:629`, `prefetch.rs:782`, `ccmp.rs:286`, `cond_select.rs:411`, `cond_select.rs:459`.
- Private linear views remain production APIs: `BBProgram::block_body_linear_view` at `analysis/bbprogram.rs:417-440`, used by `wide_mem.rs:513-515` and `skb_load_bytes.rs:125-152`; `BBProgram::program_linear_view` at `analysis/bbprogram.rs:443-478`, used by `PassManager` for counts at `pass.rs:1031-1033`.
- PC-keyed bridge APIs remain central: `current_site_pcs`/`current_pc_sites` at `analysis/bbprogram.rs:369-377`; `branch_target_pcs` at `analysis/bbprogram.rs:384-405`; `live_out_current_pc` at `analysis/bbprogram.rs:271-278`; original-PC bridges at `analysis/bbprogram.rs:566-574`.
- PC-keyed production planning remains in pass code: `const_prop.rs:149`, `const_prop.rs:475`, `bounds_check_merge.rs:76-78`, `bounds_check_merge.rs:486`, `bounds_check_merge.rs:513`, `branch_flip.rs:254`, `branch_flip.rs:514`, `extract.rs:119-120`, `extract.rs:196`, `endian.rs:378-379`, `endian.rs:465`, `map_inline.rs:248-253`, `map_inline.rs:2056`, `map_inline.rs:2620`, `map_inline.rs:3243`, `prefetch.rs:217`, `wide_mem.rs:651`, `ccmp.rs:398`, `cond_select.rs:299`.
- `HashMap<usize, _>`/`BTreeMap<usize, _>` remain in planning: external profile data at `pass.rs:168-170` is defensible because profiles are PC-keyed side inputs; internal pass use includes `bulk_memory.rs:404`, `bounds_check_merge.rs:486`, `bounds_check_merge.rs:513`, `extract.rs:196`, `endian.rs:465`, and `map_info.rs:314`.

## 7. Fallback / Legacy / Silenced Error Inventory

- `analysis/bbprogram.rs:356-361`: invalid `BlockId` in `sites_in_block` silently becomes length 0. Recommendation: return `Result` or use checked block lookup.
- `analysis/bbprogram.rs:591-600`: `rebuild_cfg_edges` silently drops invalid successors. Recommendation: make CFG rebuild fallible and surface invalid terminators.
- `analysis/bbprogram.rs:635-641`: mutations replace verifier oracle with `Some(empty)` rather than `None` or an explicit invalid state. Recommendation: represent invalidated oracle distinctly and require producer passes to set it.
- `analysis/bbprogram.rs:665-668`: invalid block in `logical_sites_in_block` returns empty. Recommendation: make fallible.
- `analysis/bbprogram.rs:759-762`: canonical index beyond `map_ids` returns `Ok(None)`. Recommendation: fail on out-of-range canonical map index.
- `analysis/bbprogram_btf.rs:63-68` and `analysis/bbprogram_btf.rs:105-110`: BTF records whose old PC has no current site are skipped; duplicate line records are skipped. Recommendation: document as intentional deletion semantics, but consider failing for missing func records.
- `passes/const_prop.rs:474`: `prog.oracle.as_deref().unwrap_or(&[])` can turn missing verifier states into an empty oracle. `main.rs` validates side inputs for the CLI, but the pass API itself defaults. Recommendation: fail if required oracle is missing.
- `passes/wide_mem.rs:507`: same empty-oracle default. Recommendation: fail or make it explicit why wide_mem can run without states.
- `passes/cond_select.rs:166-171` and `passes/ccmp.rs:219-224`: validation errors are converted into skip reasons. Recommendation: distinguish structural non-match from invariant violation; malformed BBProgram should fail.
- `pass.rs:1027-1028`: missing required kinsn targets return a skipped pass. `main.rs:301` already validates required kinsns before execution, so this is redundant fallback behavior. Recommendation: delete or make it unreachable/assertive in production.
- `pass.rs:19-20`: re-export comment says existing `use crate::pass::*` consumers keep working. Recommendation: this compatibility smell is minor but should be cleaned once migration settles.
- `main.rs:452`: `expect("chunk is 8 bytes")` is an internal invariant after `chunks_exact(8)`. Low severity.
- `main.rs:947`, `main.rs:960`, `main.rs:974`, `main.rs:1007`: `unwrap_or` defaults in verifier JSON parsing. The string-prefix defaults are acceptable parsing convenience; missing verifier `kind`/`precise` defaults should be documented as schema compatibility or made explicit.
- `bulk_memory.rs:731`: `chunks.last().copied().unwrap_or(0)` defaults empty chunks to 0. Low severity if empty chunk list is already a non-match; otherwise fail.
- `bounds_check_merge.rs:584`, `bounds_check_merge.rs:598`, `bounds_check_merge.rs:602`: register-state defaults use `unwrap_or`/`unwrap_or_else`. Likely lattice defaults, but they should be reviewed against fail-fast policy.
- `prefetch.rs:718`: `.unwrap_or(true)` defaults an analysis predicate to conservative true. Low/medium severity; document or make explicit.
- `map_inline.rs:1686`: `.map(|byte| byte.unwrap_or(0))` turns unknown bytes into zero in key extraction. This is higher risk than diagnostic defaults and should be audited.
- `map_inline.rs:1706`, `map_inline.rs:1719`, `map_inline.rs:1738`, `map_inline.rs:3557`, `map_inline.rs:3944`: diagnostic-only `unwrap_or(usize::MAX)` PC formatting. Low severity but noisy.
- `rg` found no production `todo!`, `unimplemented!`, `TODO`, or `FIXME` in scoped source. Test-only fallback names exist in `verifier_log.rs:1152` and `map_inline_tests.rs:288`.

## 8. ReJIT Filtering Violations

No P0 ReJIT filtering violations found in scoped source or the searched benchmark config. I found no `live_rejit_programs()`, no `LifecycleAbort`, no `_EXCLUDED_*` program lists, and no per-program ReJIT prefilter. Hits for "skip" are pass-site skip reporting, map snapshot size skip metadata (`pass.rs:316`, `pass.rs:496`, `map_inline.rs:5039-5050`), and map-type inlining policy (`map_info.rs:49-53`), not ReJIT program filtering.

## 9. Infra Audit Findings

### `analysis/bbprogram.rs` (1139 LOC)

- Stale header: `analysis/bbprogram.rs:2` says "staged bpfopt pass migration"; this should now describe the permanent IR contract.
- Public fields at `analysis/bbprogram.rs:131-137` allow direct pass access to `blocks`, `use_def`, `oracle`, `btf`, and `kinsn_reg`. This is the root of many direct-vector accesses. Recommendation: privatize at least `blocks`, `btf`, `oracle`, and expose checked methods.
- Bridge APIs dominate the file: `BlockBodyLinearView` at `analysis/bbprogram.rs:36-88`, `ProgramLinearView` at `analysis/bbprogram.rs:90-128`, current-PC maps at `analysis/bbprogram.rs:369-384`, and original-PC bridges at `analysis/bbprogram.rs:566-574`. These are useful migration scaffolding, not final design.
- Silent invalid/default behavior exists at `analysis/bbprogram.rs:356-361`, `analysis/bbprogram.rs:591-600`, `analysis/bbprogram.rs:635-641`, `analysis/bbprogram.rs:665-668`, and `analysis/bbprogram.rs:759-762`.
- LOC is bloated for a core IR because it mixes model types, bridge views, liveness wrappers, BTF side input attachment, map binding collection, CFG rebuild, site/PC mapping, and dominance.

### `analysis/bbprogram_api.rs` (832 LOC)

- The mutation API is valuable, but every public mutation clones the whole program before applying (`delete_insn` at `bbprogram_api.rs:20-25`, `replace_range` at `bbprogram_api.rs:49-59`, `delete_cond_branch` at `bbprogram_api.rs:127-132`, `replace_terminator` at `bbprogram_api.rs:155-164`, `permute_blocks` at `bbprogram_api.rs:183-188`, `merge_linear_chain` at `bbprogram_api.rs:228-233`, `split_block` at `bbprogram_api.rs:362-367`, `replace_diamond_with_insns` at `bbprogram_api.rs:418-427`). Recommendation: centralize transaction logic or mutate in-place after stronger invariant checks.
- `try_split_block` at `bbprogram_api.rs:358-360` is unused and redundant.
- `logical_replacement` at `bbprogram_api.rs:618-638` is necessary LD_IMM64 handling and should stay near mutation/lower logic.

### `analysis/bbprogram_lift.rs` (494 LOC)

- Linear `insns[pc]` scans are expected at the lift boundary (`bbprogram_lift.rs:61-103`, `bbprogram_lift.rs:124-225`, `bbprogram_lift.rs:257-309`). This is design-conforming.
- Roundtrip unit tests use `lower` at `bbprogram_lift.rs:363-364`; this is test-only.
- LOC is justified for lift complexity.

### `analysis/bbprogram_lower.rs` (163 LOC)

- Lowering is compact and fail-fast for non-adjacent fallthrough/call return edges (`bbprogram_lower.rs:77-130`).
- It emits physical block order, not a computed topological order (`bbprogram_lower.rs:12-17`). This is probably acceptable if `permute_blocks` establishes physical order, but it should be stated against design section 7.
- BTF remap is not here; it lives in `analysis/bbprogram_btf.rs`. Since lower owns final PCs, co-locating or documenting the split would reduce confusion.

### `analysis/bbprogram_use_def.rs` (292 LOC)

- Public `UseDefGraph` fields and trivial site wrappers are functional but open to direct mutation (`bbprogram_use_def.rs:43-45`, `bbprogram_use_def.rs:24-39`).
- `uses_for` defaults missing defs to empty at `bbprogram_use_def.rs:93-95`. This is ergonomic but can hide wrong def keys; consider a checked variant for production.
- Overall size is justified for shared use-def analysis.

### `analysis/bbprogram_helpers.rs` (173 LOC)

- Good home for shared helpers: slot offset (`bbprogram_helpers.rs:28-37`), current-PC lookup (`bbprogram_helpers.rs:39-47`), packet layout (`bbprogram_helpers.rs:49-78`), profile annotations (`bbprogram_helpers.rs:86-102`), and simple register-state traversal (`bbprogram_helpers.rs:104-142`).
- `read_json_file` duplicates `main.rs:1048-1052`. Minor.

### `analysis/mod.rs`

- Re-exports include migration bridge types `BlockBodyLinearView` and `ProgramLinearView` at `analysis/mod.rs:12-15`. Recommendation: do not publicly re-export final-internal bridge views.
- `bbprogram_lift` and `bbprogram_lower` are public modules at `analysis/mod.rs:8-9`, while functions are also re-exported at `analysis/mod.rs:22-23`. Recommendation: keep only the intended public surface.

### `pass.rs`

- `BpfProgram` still exists but is `#[cfg(test)]` (`pass.rs:291-294`), so production is clean on that point. Long-term, tests should migrate off it and delete it.
- The old linear `kinsn_replacement_subprog_skip_reason(insns: &[BpfInsn], ...)` remains production-visible at `pass.rs:235-287`, while the BBProgram-native method exists at `analysis/bbprogram.rs:485-552` and is used by passes. Recommendation: delete or `cfg(test)` the old helper.
- `PassManager` remains at `pass.rs:935-1043`. It is not the forbidden daemon `PassManager`, but production bpfopt CLI only runs one explicit pass per invocation (`main.rs:292-317`). Recommendation: simplify production single-pass dispatch and keep multi-pass support only where tests/custom utilities need it.
- BTF remap helpers are not in `pass.rs`; they are in `bbprogram_btf.rs`. They likely belong closer to lower or need clear module docs.

### `main.rs`

- `run_single_pass` conforms to design section 3: read bytecode (`main.rs:299`), build context (`main.rs:300`), lift once (`main.rs:303-307`), attach side inputs (`main.rs:308-313`), run pass (`main.rs:315`), lower once (`main.rs:316`).
- `--canonicalize-map-refs` remains a separate flat mutation command at `main.rs:246-264` and `main.rs:456-514`. The v3 daemon design allows a canonicalization CLI boundary, but the Phase 3 acceptance criterion should explicitly exempt it if it is intended.
- CLI still uses `PassManager` for one pass (`main.rs:334-347`), which keeps extra policy/filter machinery alive.

### `insn.rs`, `verifier_log.rs`, `lib.rs`

- `lib.rs:1-12` clearly declares pure bytecode library modules and no kernel syscall dependency.
- `insn.rs` uses `libbpf_sys` ABI constants/types and has an ABI offset/raw bytes test; no custom syscall concern in scoped audit.
- `verifier_log.rs` is production parser code plus tests. Test-only fallback name appears at `verifier_log.rs:1152`; no production Phase 3 migration blocker found.

## 10. Design Contract Section 11 Conformance

| Item | Status | Evidence |
|---|---|---|
| 1. 542 testbin programs roundtrip byte-identical | PASS | Test asserts `paths.len() == 542` and byte identity at `bpfopt/crates/bpfopt/tests/bbprogram_roundtrip.rs:10-23`. I ran `cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt`; this test passed in 120.97s. |
| 2. Pass-equivalence legacy vs new | FAIL / obsolete but not replaced | I found no live equivalence harness comparing legacy and BBProgram pass output across 14/15 passes. Legacy flat pass infrastructure is deleted, so this acceptance item was not re-evaluated with an alternative oracle. |
| 3. No `Vec<BpfInsn>` production mutation path | PARTIAL / FAIL literal | No pass-body flat mutation or pass-body lower found. But `--canonicalize-map-refs` mutates `Vec<BpfInsn>` in production at `main.rs:246-264` and `main.rs:456-514`; pass mutation APIs still accept replacement `Vec<BpfInsn>` by design (`bbprogram_api.rs:49-53`, `bbprogram_api.rs:418-422`). Forbidden names `RewritePlan`, `RewriteOutput`, `AnalysisCache`, `commit_rewrite_output`, `compose_addr_maps`, `BtfRemapPolicy`, `legacy_cleanup` are absent except `RewriteOutputs` local bundle in `const_prop.rs:447`. |
| 4. No `bbprogram/` directory | PASS | `test -d bpfopt/crates/bpfopt/src/bbprogram` returned absent. |
| 5. No benchmark-framework changes | FAIL | `git diff bfa802c9 --name-only` includes `runner/config/passes/dce/default.yaml` and corpus result artifacts. The runner config changed the dce command to add `--target` (`runner/config/passes/dce/default.yaml:3-4` in diff). |
| 6. Significant code-volume reduction >= 2500 LOC | PARTIAL / intent FAIL | Total Rust LOC is down by 3361, technically meeting a total-LOC criterion. But provided non-test LOC is +2742, so the production code-volume goal fails in spirit; test deletion masks production growth. |
| 7. All existing 402 tests still pass | FAIL | Current `cargo test -- --list` reports 217 tests. I ran the current suite and 217 passed, but the count regressed from 402. |
| 8. No commit | PASS | No commit made by this audit. Worktree was already dirty/ahead on entry. |

## 11. Final Verdict

**Not-conformant.** Phase 3 has made real progress: the CLI pass path lifts once, runs BBProgram passes, and lowers once; production `BpfProgram` is gone; and all current 217 tests pass, including the 542-program roundtrip. But the design contract is not genuinely met because most passes still depend on PC-keyed bridge APIs or private linear views, core IR fields remain public enough to invite vector indexing, fail-fast behavior is inconsistent, production non-test LOC grew, the original test count dropped sharply, and benchmark-tree files changed.

## 12. Prioritized Cleanup Tasks

1. Privatize `BBProgram::blocks`, `btf`, and `oracle`; force pass code through checked `block`, `insn_at`, site iterators, and mutation APIs.
2. Delete or `cfg(test)` the old linear `pass.rs:235-287` kinsn subprogram helper.
3. Replace `program_linear_view` and `block_body_linear_view` with BBProgram-native window/site iterators; migrate `wide_mem` and `skb_load_bytes` first.
4. Add `BBProgram::is_terminator_site`, `site_current_pc`, slot range/length helpers, and remove duplicate local helpers.
5. Make CFG rebuild and site enumeration fail-fast: no silent invalid-successor `continue`, no invalid block -> empty iterator.
6. Decide canonicalize-map-refs contract: either explicitly exempt it from Phase 3 Vec-mutation criteria or lift it to BBProgram too.
7. Simplify production `PassManager` out of the single-pass CLI path; keep multi-pass pipeline only for tests/custom library helpers if still needed.
8. Make verifier oracle absence explicit for `const_prop` and `wide_mem`; remove `unwrap_or(&[])` defaults.
9. Audit `map_inline` unknown-byte/key defaults, especially `map_inline.rs:1686`, and split the 5572 LOC file around stable submodules without adding new abstractions.
10. Restore/replace deleted pass-equivalence coverage with current architecture checks; do not rely only on small hand-written pass tests.
11. Move or document BTF remap ownership near lowering, and decide whether missing func records should fail instead of silently dropping.
12. Remove benchmark-tree diffs and generated corpus artifacts from the Phase 3 migration branch unless they are explicitly part of the accepted change set.

## 13. Estimated LOC Delta If Cleanup Applied

Estimated net source reduction from the 12 tasks: **about -2200 to -3200 non-test LOC**, with the largest savings from deleting bridge APIs and old helpers (-500 to -800), simplifying single-pass `PassManager` policy/report plumbing (-150 to -300), removing private linear scan adapters after migrating wide/skb/rotate/extract/endian/bulk (-500 to -900), and splitting/deduplicating `map_inline` without behavior changes (-700 to -1200). That likely gets current non-test LOC close to the Phase 3 start, but not obviously below it; reaching a meaningful non-test reduction probably requires further simplification of `map_inline` and the mutation transaction boilerplate.

