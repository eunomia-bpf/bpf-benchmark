# Phase 3 BBProgram Migration Post-Cleanup Review

Date: 2026-05-10
Repository: `/home/yunwei37/workspace/bpf-benchmark`
Branch: `main`
Mode: read-only audit, except writing this report.

## State Caveat

The requested comparison command was run, but it is not the full Phase 3 source picture:

- `git status --short --branch` showed `main...origin/main [ahead 3]` with a dirty index/worktree.
- `git diff bfa802c9..HEAD --stat` was dominated by docs/results and did not include the current Phase 3 source cleanup in files such as `bpfopt/crates/bpfopt/src/pass.rs`.
- `git diff bfa802c9..HEAD -- bpfopt/crates/bpfopt/src/pass.rs` was empty, while the current worktree file is the slimmed 1115-line version.
- Therefore, source evidence below is from the current filesystem line numbers. The requested diff commands are still useful as evidence that the current source migration is not represented by `bfa802c9..HEAD` alone.

Verification commands used:

- `git diff bfa802c9..HEAD --stat`
- `git diff bfa802c9..HEAD <path>` on representative source paths
- `git diff --stat`, `git diff --cached --stat`, `git diff bfa802c9 --stat`
- `wc -l` on pass, BBProgram, `pass.rs`, and `main.rs` files
- `rg` for BBProgram/flat-mode patterns, panic/fallback patterns, comments, unsafe
- `cargo test --no-run` in `bpfopt` - passed
- `cargo clippy` in `bpfopt` - passed
- `cargo test -- --list` in `bpfopt` - 217 tests listed

## Executive Summary

Phase 3 is mechanically integrated and build-clean, but it is not a finished BBProgram-native migration.

The good news:

- The public pass trait now takes `&mut BBProgram`; tests exercise that wrapper path through `test_helpers.rs:36-42` and `test_helpers.rs:58-70`.
- `noop` and `dce` are truly BBProgram-native.
- `const_prop`, `bounds_check_merge`, and parts of `branch_flip` now operate over BBProgram structure rather than rebuilding a pure linear program.
- Lift/lower roundtrip has meaningful regression coverage over 542 testbin programs at `bpfopt/crates/bpfopt/tests/bbprogram_roundtrip.rs:10-30`.

The main unresolved issue:

- Many passes still do `lower(prog) -> flat scan -> PC-keyed replace_range(...)`.
- `map_inline` is still a flat `BpfProgram` pass behind a BBProgram adapter. It constructs a linear `BpfProgram` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2292-2308`, repeatedly lowers during fixed-point iteration at `map_inline.rs:2352-2372`, scans `program.insns` at `map_inline.rs:2431-2450`, and applies a PC-keyed edit plan at `map_inline.rs:2919-3132`.
- `PassManager` still lowers before and after every pass at `bpfopt/crates/bpfopt/src/pass.rs:1019-1037`, so the CLI has lift-once/lower-once at the boundary but not internally.

Largest correctness risks:

- `BBProgram::split_block` panics on invalid state and returns a non-`Result` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:307-360`.
- Several mutation APIs mutate first and rebuild use-def after, leaving the IR changed if rebuild fails. Examples: `replace_range` mutates at `bbprogram_api.rs:62-65` and rebuilds at `bbprogram_api.rs:105`; `replace_diamond_with_insns` mutates at `bbprogram_api.rs:416-429` before `remove_blocks` at `bbprogram_api.rs:441`.
- BTF output writing silently writes empty files through `unwrap_or_default()` at `bpfopt/crates/bpfopt/src/main.rs:702-715`.
- Unknown target features are warning-and-continue at `main.rs:843-850`.

## Per-Pass Audit

Rating key:

- A: production path is BBProgram-native; no lowering/flat scan in the pass.
- B: mostly BBProgram-native, but still has local plan/view structures or PC mapping debt.
- C: production path lowers to flat bytecode for scan/detection and applies via original/current PC shims.
- D: BBProgram wrapper around the old flat `BpfProgram` pass.

| Pass | Rating | Production entry and evidence | Legacy/flat debt |
| --- | --- | --- | --- |
| `noop.rs` | A | `BpfPass::run` ignores the program and returns unchanged at `bpfopt/crates/bpfopt/src/passes/noop.rs:14-21`; `run_on_bbprogram` is unchanged at `noop.rs:24-26`. | No flat scan, no local plan, no `BpfProgram::new`. |
| `dce.rs` | A | Uses `prog.use_def.defs` and `uses_for` at `bpfopt/crates/bpfopt/src/passes/dce.rs:28-33`, deletes through `prog.delete_insn(def)?` at `dce.rs:41-42`, and inspects with `prog.insn_at` at `dce.rs:72-88`. | No lowering, no PC-keyed rewrite plan. |
| `const_prop.rs` | B | Entry is BBProgram at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:420-437`; block iteration and simulation use `prog.blocks()` and `prog.logical_sites_in_block` at `const_prop.rs:439-446` and `const_prop.rs:533-578`. | Still has `ConstPropRewritePlan` and `ConstReplacement` at `const_prop.rs:396-405`, and applies a deferred replacement map with `prog.replace_range` at `const_prop.rs:461-465`. Also keeps PC-keyed verifier oracle maps at `const_prop.rs:51-53` and `const_prop.rs:148-153`. |
| `bounds_check_merge.rs` | B | Entry is BBProgram at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:85-102`; scanner iterates `prog.blocks()` and `prog.logical_sites_in_block` at `bounds_check_merge.rs:351-385`. | Has local `LadderRewrite` at `bounds_check_merge.rs:65-70`, local `ProgramView` with `site_to_pc`, `pc_to_insn`, `block_start_pc`, and `target_pcs` at `bounds_check_merge.rs:249-330`, and manual address-map construction at `bounds_check_merge.rs:236-247`. |
| `branch_flip.rs` | B | Applies with BBProgram block/terminator APIs: `block_for_original_pc` at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:403-411`, terminator checks and replacements at `branch_flip.rs:424-482`, and `prog.permute_blocks` at `branch_flip.rs:484-489`. | Detection still lowers and flat-scans: `lower(prog)?` at `branch_flip.rs:270`, `scan_branch_flip_sites(&insns)` at `branch_flip.rs:273-274`, and `linear_insn_sites` at `branch_flip.rs:525-531`. It also validates by discarding `lower(prog)?` at `branch_flip.rs:359`. |
| `bulk_memory.rs` | C | Entry immediately lowers at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:200-208`. | Flat scanner uses `while pc < insns.len()` at `bulk_memory.rs:302-345`; replacement is a `replace_flat_range` shim at `bulk_memory.rs:255-282`; local `site_for_original_pc` duplicates BBProgram API at `bulk_memory.rs:285-290`; replacement emits `Vec<BpfInsn>` at `bulk_memory.rs:550-565`. |
| `prefetch.rs` | C | Entry lowers at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:258-273`. | Builds local flat CFG `PrefetchCfg` from BBProgram plus `insns` at `prefetch.rs:366-409`, uses `linear_insn_sites` scanners at `prefetch.rs:461-473` and `prefetch.rs:556-588`, and inserts with `insert_flat_before`/`replace_range` at `prefetch.rs:321-344`. |
| `wide_mem.rs` | C | Entry lowers at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:492-501`. | Uses flat scan result plus BB liveness by PC at `wide_mem.rs:501-535`; applies through `replace_flat_range` at `wide_mem.rs:603-625`; duplicates `site_for_original_pc` at `wide_mem.rs:628-633`. |
| `rotate.rs` | C | Entry lowers at `bpfopt/crates/bpfopt/src/passes/rotate.rs:78-82`. | `scan_rotate_sites` uses `linear_insn_sites` at `rotate.rs:229-251`; replacement uses `replace_flat_range` at `rotate.rs:149-175`; duplicate `site_for_original_pc` at `rotate.rs:178-183`. |
| `endian.rs` | C | Entry lowers at `bpfopt/crates/bpfopt/src/passes/endian.rs:374-378`. | `scan_endian_fusion_sites` uses `linear_insn_sites` at `endian.rs:83-90`; replacement uses `replace_flat_range` at `endian.rs:436-461`; duplicate `site_for_original_pc` at `endian.rs:464-469`. |
| `extract.rs` | C | Entry lowers at `bpfopt/crates/bpfopt/src/passes/extract.rs:115-119`. | `scan_extract_sites` uses `linear_insn_sites` at `extract.rs:77-83`; replacement uses `replace_flat_range` at `extract.rs:177-203`; duplicate `site_for_original_pc` at `extract.rs:206-211`. |
| `skb_load_bytes.rs` | C | Entry lowers at `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:54-60`. | Scanner is flat and linear at `skb_load_bytes.rs:101-127`; apply path maps `call_pc` back through `prog.site_for_original_pc` and `replace_range` at `skb_load_bytes.rs:75-87`. |
| `cond_select.rs` | C | Entry lowers and flat-scans at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:122-124`. | Rewrite uses BBProgram diamond API at `cond_select.rs:184-190`, but pattern discovery starts as flat `linear_insn_sites` at `cond_select.rs:288-295`; local `site_for_original_pc` duplicate at `cond_select.rs:273-278`; `split_block` is used at `cond_select.rs:224` and `cond_select.rs:254`. |
| `ccmp.rs` | C | Entry lowers and flat-scans at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:163-164`. | Rewrite uses `merge_linear_chain`, `replace_range`, and terminator replacement at `ccmp.rs:266-294`, but scanner is `linear_insn_sites` at `ccmp.rs:377-383` and flat branch decoding at `ccmp.rs:416-433`; duplicate `site_for_original_pc` at `ccmp.rs:366-374`; `split_block` at `ccmp.rs:305-307`. |
| `map_inline.rs` | D | Entry calls `MapInlinePass::run_bbprogram` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2285-2290`, but that immediately builds a flat `BpfProgram` via `linear_program_view` at `map_inline.rs:2292-2308`. | Full flat-mode remains: fallback `build_map_fd_bindings(&lower(prog)?, ...)` at `map_inline.rs:2311-2320`; repeated lowering in fixed-point loop at `map_inline.rs:2352-2372`; round logic takes `program: &BpfProgram` at `map_inline.rs:2431-2439`; scans `program.insns` at `map_inline.rs:2450`; applies PC-keyed `BTreeMap<usize, Vec<BpfInsn>>` plans at `map_inline.rs:1029-1034`, `map_inline.rs:1579-1588`, and `map_inline.rs:2843-3132`. |

## Deep-Dive Findings By Pass

### `map_inline.rs`

`map_inline` is the major remaining migration debt. It is not BBProgram-native in any meaningful sense.

Evidence:

- `run_on_bbprogram` is only a thin dispatch at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2285-2290`.
- `linear_program_view` lowers the BBProgram and constructs `BpfProgram::new(insns)` at `map_inline.rs:2292-2298`, then copies every side input back into the flat structure at `map_inline.rs:2299-2308`.
- Stable map bindings still fall back to flat bytecode at `map_inline.rs:2311-2320`.
- The fixed-point loop lowers before each round and again after it at `map_inline.rs:2352-2372`.
- The round body is explicitly `program: &BpfProgram` at `map_inline.rs:2431-2439`.
- Map lookup scanning uses `find_map_lookup_sites(&program.insns)` at `map_inline.rs:2450`.
- The rewrite representation is PC-keyed: `DirectMapValueLoadRewrites = BTreeMap<usize, Vec<BpfInsn>>` at `map_inline.rs:1029-1034`, `SiteRewrite.replacements: BTreeMap<usize, Vec<BpfInsn>>` at `map_inline.rs:1579-1588`, and `ReplacementBranchPatch.target_old_pc` at `map_inline.rs:1590-1595`.
- The edit application builds an address map and patches replacement branches at `map_inline.rs:2919-3042`, then maps old PCs back to BBProgram sites/blocks at `map_inline.rs:3044-3132`.
- It still has flat subprogram helpers at `map_inline.rs:4838-4865`.
- Snapshot/diagnostic helpers still take `&BpfProgram` at `map_inline.rs:5148-5182`.

Concrete removable subsystems:

- Delete `linear_program_view` once map metadata/value side inputs are consumed directly from `PassContext` and `BBProgram.map_bindings()` (`map_inline.rs:2292-2308`).
- Move map-reference analysis off `BpfProgram` and onto `BBProgram.map_bindings()` plus logical sites. Current flat dependency is in `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:127-139`.
- Replace `DirectMapValueLoadRewrites`, `SiteRewrite.replacements`, and `ReplacementBranchPatch` with site/block edits. Current plan types are at `map_inline.rs:1029-1034` and `map_inline.rs:1579-1595`.
- Delete `map_inline_addr_map`, `patch_replacement_branches`, and old-PC edit dispatch once replacements are expressed as BBProgram mutation operations (`map_inline.rs:2946-3042` and `map_inline.rs:3044-3132`).
- Replace `linear_subprog_bounds` and `linear_subprog_ranges` with `FrameId`/`subprog_blocks` APIs (`map_inline.rs:4838-4865` and `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:176-181`).
- Clean stale comments still referencing the old storage model at `map_inline.rs:28` and `map_inline.rs:92-94`.

Estimated LOC delta: large. Removing the flat adapter, PC-keyed planner, and address-map editor after a real port should plausibly remove 500-1000 LOC from `map_inline.rs` plus 200-300 LOC from `pass.rs`.

### `const_prop.rs`

This is substantially closer to native, but it still has a mini rewrite-plan layer.

Evidence:

- Production entry is BBProgram-native at `bpfopt/crates/bpfopt/src/passes/const_prop.rs:420-437`.
- It iterates BBProgram blocks and logical sites at `const_prop.rs:439-446` and `const_prop.rs:533-578`.
- The rewrite plan remains as `ConstPropRewritePlan` and `ConstReplacement` at `const_prop.rs:396-405`.
- The plan is filled from logical sites at `const_prop.rs:563-573` and applied with `prog.replace_range` at `const_prop.rs:461-465`.
- It still carries PC-keyed verifier frame maps in `VerifierExactConstOracle` at `const_prop.rs:51-53` and builds them at `const_prop.rs:148-153`.
- There is a production `expect` in the LD_IMM64 path at `const_prop.rs:591-596`.

Recommended next step: keep the block dataflow, but replace `ConstPropRewritePlan` with immediate collection of `InsnSite -> Vec<BpfInsn>` or a shared BBProgram rewrite batch API. The current plan is small, but it is a local version of the deleted generic plan.

Estimated LOC delta: 30-60 LOC.

### `bounds_check_merge.rs`

This pass is no longer a pure flat scan, but it re-creates BBProgram indexing internally.

Evidence:

- Entry is BBProgram at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:85-102`.
- Scanner walks blocks/sites at `bounds_check_merge.rs:351-385`.
- `ProgramView` duplicates site-to-PC, PC-to-insn, block start PCs, and target PCs at `bounds_check_merge.rs:249-330`.
- `LadderRewrite` is a local rewrite-plan struct at `bounds_check_merge.rs:65-70`.
- It manually computes an old-to-new address map at `bounds_check_merge.rs:236-247`.
- It mutates with repeated `replace_range`/`delete_cond_branch` calls at `bounds_check_merge.rs:178-228`.
- It has production `unwrap`/`expect` at `bounds_check_merge.rs:125`, `bounds_check_merge.rs:405-406`, and `bounds_check_merge.rs:496-497`.

Recommended next step: hoist the missing `ProgramView` capabilities into BBProgram: current PC for site, instruction at current/original PC, block-start PC, and target-PC predicates. Then reduce the pass to logical guard detection plus BBProgram mutations.

Estimated LOC delta: 60-120 LOC locally, more if shared with other passes.

### `bulk_memory.rs`, `prefetch.rs`, `wide_mem.rs`

These were not really re-ported.

Evidence:

- `bulk_memory` lowers at `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:200-208`, flat-scans at `bulk_memory.rs:302-345`, and uses `replace_flat_range` at `bulk_memory.rs:255-282`.
- `prefetch` lowers at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:258-273`, builds its own flat `PrefetchCfg` at `prefetch.rs:366-409`, scans through `linear_insn_sites` at `prefetch.rs:461-473` and `prefetch.rs:556-588`, and inserts through a PC shim at `prefetch.rs:321-344`.
- `wide_mem` lowers at `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:492-501`, scans flat, queries liveness by current PC at `wide_mem.rs:534-535`, and applies through `replace_flat_range` at `wide_mem.rs:603-625`.

Recommended next step: add BBProgram pattern iteration helpers, then port one of these passes fully as the template. The repeated pattern is:

1. Iterate logical sites in block order.
2. Match a bounded same-block instruction window.
3. Reject if the window crosses a block/terminator/subprogram boundary.
4. Query liveness at `InsnSite`.
5. Replace a same-block logical range.

Estimated LOC delta: 150-300 LOC across the three from deleting duplicated range/site helpers and flat CFG scaffolding.

### `branch_flip.rs`

The rewrite is good BBProgram code; the detector is not.

Evidence:

- Lower and flat scan at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:270-274`.
- The actual rewrite uses block IDs and terminators at `branch_flip.rs:403-489`.
- Scanner is `linear_insn_sites` at `branch_flip.rs:525-531`.
- It has production `expect` conversions at `branch_flip.rs:536-540` and `branch_flip.rs:562-565`.
- Stale comment says offsets are adjusted "via an address map" at `branch_flip.rs:39-41`, but the current rewrite uses terminator replacement and block permutation.

Recommended next step: make scanner work from `Terminator::CondBranch` plus successor body blocks instead of raw `insns`.

Estimated LOC delta: neutral to -40 LOC.

### `cond_select.rs` and `ccmp.rs`

Both passes use BBProgram to rewrite multi-block patterns, but both still discover patterns by lowering and flat-scanning.

Evidence:

- `cond_select` lowers/scans at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:122-124` and `cond_select.rs:288-295`, then rewrites through `replace_diamond_with_insns` at `cond_select.rs:184-190`. It uses `split_block` at `cond_select.rs:224` and `cond_select.rs:254`.
- `ccmp` lowers/scans at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:163-164` and `ccmp.rs:377-383`, decodes branches from flat instructions at `ccmp.rs:416-433`, then rewrites through `merge_linear_chain`, `replace_range`, and `replace_terminator` at `ccmp.rs:266-294`. It uses `split_block` at `ccmp.rs:305-307`.

Recommended next step: introduce BBProgram diamond/linear-chain matchers that return block/site patterns directly. Also make `split_block` fallible before relying on it more heavily.

Estimated LOC delta: 50-100 LOC across both after shared helpers.

## BBProgram Infrastructure Audit

### Why `bbprogram.rs` Is 1016 LOC

`bbprogram.rs` is large because it is not just the core IR.

It contains:

- Core IDs, `BBProgram`, `Block`, and `Terminator` definitions at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:15-82`.
- Public query APIs such as block iteration, CFG, dominance, liveness, BTF view, unreachable blocks, and subprogram blocks at `bbprogram.rs:115-200`.
- Map binding collection and map-ID resolution at `bbprogram.rs:457-495`.
- Terminator successor and dataflow-successor logic at `bbprogram.rs:497-548`.
- Dominance and reaching-def wrappers at `bbprogram.rs:558-620`.
- BTF record view and remapping logic at `bbprogram.rs:623-761`.
- Current/old PC maps at `bbprogram.rs:763-815`.
- Block and site liveness computation at `bbprogram.rs:818-1016`.

This file has absorbed analysis logic that should probably be split into modules (`bbprogram_btf.rs`, `bbprogram_liveness.rs`, `bbprogram_maps.rs`) or exposed through focused APIs. The issue is not only LOC count; public fields and helper placement encourage passes to keep doing PC-keyed work.

### Public API Surface

BBProgram exposes many internals directly:

- `BBProgram.blocks`, `entry`, `use_def`, `oracle`, `btf`, and `kinsn_reg` are public at `bbprogram.rs:33-40`.
- `Block.insns`, `Block.terminator`, and `Block.frame` are public at `bbprogram.rs:51-57`.
- `InsnSite` has public raw fields at `bbprogram.rs:21-25`.

This makes migration easier but keeps pass-local rewrites unconstrained. Examples:

- `dce` directly reads `prog.use_def.defs` at `bpfopt/crates/bpfopt/src/passes/dce.rs:28-33`.
- `bounds_check_merge` reads `prog.btf` to build its `ProgramView` at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:259-275`.
- Multiple passes re-implement `site_for_original_pc` instead of using `BBProgram::site_for_original_pc`.

Likely zero-caller or test-only public API:

- `PassResult::skipped_with_diagnostics` is public at `bpfopt/crates/bpfopt/src/pass.rs:617-622` and had no `rg` caller.
- `BBProgram::live_out_site` is public at `bbprogram.rs:142-155`; current non-test use is only through `live_out_current_pc`.
- `BBProgram::unreachable_blocks` is public at `bbprogram.rs:192-200`; the observed caller is a test at `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:441-442`.
- `BtfRecordsView::line_type_ids` is public at `bbprogram.rs:644-649`; the observed caller is a test at `bpfopt/crates/bpfopt/src/pass_tests.rs:189`.

### Duplicated Helpers To Hoist

The same original-PC replacement shim is repeated across passes:

- `bulk_memory.rs:271-290`
- `wide_mem.rs:614-633`
- `rotate.rs:164-183`
- `endian.rs:450-469`
- `extract.rs:192-211`
- `cond_select.rs:273-278`
- `ccmp.rs:366-374`

Recommended shared API:

- `BBProgram::replace_original_pc_range(start_pc, old_len, replacement)`
- `BBProgram::insert_before_original_pc(pc, replacement)`
- `BBProgram::logical_window_from_original_pc(start_pc, len) -> Result<(BlockId, Range<usize>)>`
- `BBProgram::site_live_out(site) -> Result<RegSet>`
- `BBProgram::block_start_pc(block)`, `BBProgram::is_original_pc_target(pc)`

This should remove duplicate shims while forcing callers to use one consistent PC-to-site implementation.

### Mutation Atomicity

Mutation methods maintain use-def eventually, but they are not transactionally atomic.

Evidence:

- `delete_insn` removes the instruction at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:23-29`, mutates metadata at `bbprogram_api.rs:30-37`, and only then calls `rebuild_use_def_after_mutation()` at `bbprogram_api.rs:38`.
- `replace_range` validates some inputs at `bbprogram_api.rs:48-60`, mutates the block at `bbprogram_api.rs:62-65`, mutates metadata at `bbprogram_api.rs:67-103`, and only then rebuilds use-def at `bbprogram_api.rs:105`.
- `replace_terminator` mutates the terminator at `bbprogram_api.rs:135-142`, then rebuilds use-def at `bbprogram_api.rs:143`.
- `replace_diamond_with_insns` mutates predecessor instructions and terminator at `bbprogram_api.rs:416-429`, then calls `remove_blocks` at `bbprogram_api.rs:441`, which can still fail.
- `split_block` is non-fallible and panics/asserts on invalid inputs at `bbprogram_api.rs:307-360`.

Recommended next step: validate on a clone or construct a replacement `BBProgram` and swap only after use-def/CFG rebuild succeeds. At minimum, make `split_block` return `anyhow::Result<(BlockId, BlockId)>` and update `cond_select.rs:224`, `cond_select.rs:254`, and `ccmp.rs:305-307`.

### Lift / Lower Correctness

Lift:

- Handles empty programs at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs:22-31`.
- Computes instruction boundaries, block starts, subprogram starts, and frame mapping at `bbprogram_lift.rs:34-40`.
- Preserves LD_IMM64 second slots and pseudo-func targets at `bbprogram_lift.rs:84-99`.
- Treats `exit`, `JA`, conditional jumps, and pseudo-calls as terminators at `bbprogram_lift.rs:311-317`.
- Resolves terminators at `bbprogram_lift.rs:257-309`.

Lift handles every BPF instruction class by storing non-terminators as raw body instructions at `bbprogram_lift.rs:61-103`; it is not a semantic decoder for every opcode. That is acceptable for IR lifting, but the API relies on later pass logic for opcode-specific semantics.

Lower:

- Assigns block PCs and emits blocks in order at `bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:7-17`.
- Emits LD_IMM64 second slots and fixes pseudo-func deltas at `bbprogram_lower.rs:18-35`.
- Rewrites terminator deltas and validates physical adjacency at `bbprogram_lower.rs:69-140`.

Roundtrip:

- Byte-identical lift/lower coverage exists for 542 testbin programs at `bpfopt/crates/bpfopt/tests/bbprogram_roundtrip.rs:10-30`.

Remaining concern:

- Liveness has silent invalid-site behavior: `site_successors` returns empty for invalid blocks at `bbprogram.rs:969-1004`, and public liveness methods return empty sets on missing entries at `bbprogram.rs:131-146`. That can hide broken transformations.

## `pass.rs` Audit

`pass.rs` is still more than a trait/context file.

What remains:

- `BpfProgram` still exists as a linear program view at `bpfopt/crates/bpfopt/src/pass.rs:290-323`.
- Map metadata, compressed map values, lookup errors, and `MapProvider` remain in `pass.rs` at `pass.rs:325-527`.
- `BpfProgram::new` and `set_map_ids` remain at `pass.rs:529-552`.
- `PassContext` is broad side-input storage at `pass.rs:672-708`.
- `PassManager` still exists at `pass.rs:920-1042`.

`BpfProgram` is not just a CLI input parser. It is used by `map_inline` and map snapshot analysis:

- `map_inline` constructs it in production at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2292-2308`.
- `map_info` consumes `&BpfProgram` in production at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:121-139`.

`PassManager` is still in active use:

- Defined at `pass.rs:929-1042`.
- `main.rs` imports and constructs it at `bpfopt/crates/bpfopt/src/main.rs:15` and `main.rs:334-341`.
- `passes/mod.rs` still has a custom pipeline builder using it at `bpfopt/crates/bpfopt/src/passes/mod.rs:43` and `passes/mod.rs:181-182`.

This conflicts with the v3 design direction if read strictly as "no PassManager". The current CLI still has a pass runner object that validates policy and lowers before/after each pass.

BTF helpers:

- BTF remapping is no longer in `pass.rs`.
- It is not in `bbprogram_lower.rs`; it lives in `bbprogram.rs` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:623-761`.
- Current PC mapping for BTF remap is also in `bbprogram.rs` at `bbprogram.rs:763-815`.

`PassContext` field usage:

- Fields are listed at `pass.rs:672-708`.
- No obviously unused field was found by `rg` across the 15 passes and CLI/tests. However, the shape is still broad: many fields are only used by one pass family (`branch_miss_rate` for `branch_flip`, map fields for `map_inline`, BTF fields for lift/lower side outputs).
- `policy` is used by `PassManager::pass_allowed` at `pass.rs:966-982`, not directly by passes.

## `main.rs` Audit

`main.rs` is 1467 LOC because it contains much more than CLI parsing:

- Pass aliases and CLI/global argument definitions at `bpfopt/crates/bpfopt/src/main.rs:28-132`.
- Main dispatch and canonicalization mode at `main.rs:210-265`.
- Single-pass orchestration, pipeline build, side-input validation, and pass name handling at `main.rs:292-424`.
- Bytecode parsing and I/O helpers at `main.rs:426-455`.
- BTF side-output writing at `main.rs:702-716`.
- Target platform feature parsing, including warning-and-continue on unknown features, at `main.rs:840-852`.
- A large embedded test module from roughly `main.rs:1093` onward.

The CLI boundary does implement lift-once/pass-loop/lower-once:

- Reads input at `main.rs:299`.
- Builds context at `main.rs:300`.
- Lifts once at `main.rs:303-307`.
- Attaches side inputs at `main.rs:308-313`.
- Runs the pipeline at `main.rs:314-315`.
- Lowers once for output at `main.rs:316`.

But the effective runtime is not lower-once:

- `PassManager::run_single_pass` lowers before and after every pass at `bpfopt/crates/bpfopt/src/pass.rs:1019-1037`.
- Many passes lower internally, including `bulk_memory.rs:200-208`, `wide_mem.rs:492-501`, `prefetch.rs:258-273`, `rotate.rs:78-82`, `endian.rs:374-378`, `extract.rs:115-119`, `skb_load_bytes.rs:54-60`, `cond_select.rs:122-124`, `ccmp.rs:163-164`, `branch_flip.rs:270-274`, and `map_inline.rs:2292-2372`.

`main.rs` does not do old `BpfProgram` pass dispatch. The only flat-only mode left in main is canonicalization:

- `run_canonicalize_map_refs` reads/writes flat bytecode at `main.rs:246-265`.
- `parse_bytecode` decodes raw 8-byte chunks at `main.rs:443-453`.

## Test Suite Audit

`cargo test -- --list` reported 217 tests:

- 188 lib tests
- 16 `main.rs` tests
- 1 `bbprogram_roundtrip` integration test
- 12 CLI tests

Per-pass distribution from the listed test names:

- `bounds_check_merge`: 9
- `branch_flip`: 10
- `bulk_memory`: 7
- `ccmp`: 6
- `cond_select`: 8
- `const_prop`: 17
- `dce`: 2
- `endian_fusion`: 8
- `extract`: 8
- `map_inline`: 28 total, including 17 main pass tests and 11 `map_info` tests
- `noop`: 0 direct pass tests
- `prefetch`: 5
- `rotate`: 7
- `skb_load_bytes`: 7
- `wide_mem`: 10

BBProgram/analysis-oriented tests:

- `bbprogram_branch_target`: 3
- `bbprogram_cfg`: 3
- `bbprogram_lift`: 6
- `bbprogram_liveness`: 5
- `bbprogram_map_refs`: 2
- `site_scan`: 3
- `lower`: 3
- `pass_tests`: 10
- `verifier_log` and instruction helper tests cover the rest

Are tests exercising BBProgram path?

- The shared helper lifts into BBProgram at `bpfopt/crates/bpfopt/src/test_helpers.rs:19-29`.
- Pass tests call `pass.run(&mut prog, ctx)` at `test_helpers.rs:36-42`.
- Pipeline tests also run passes over BBProgram at `test_helpers.rs:58-70`.

So tests exercise the BBProgram wrapper path. However, for C/D-rated passes, that wrapper still lowers internally and scans flat bytecode. The tests do not prove those passes are BBProgram-native.

Critical regression coverage:

- P1-F DCE kinsn-aware coverage is alive at `bpfopt/crates/bpfopt/src/passes/dce_tests.rs:9-40`.
- P1-K const-prop coverage is alive at `bpfopt/crates/bpfopt/src/passes/const_prop_tests.rs:112-147`, `const_prop_tests.rs:172-197`, and `const_prop_tests.rs:199-210`.
- P1-G JA32 target coverage is alive at `bpfopt/crates/bpfopt/src/analysis/bbprogram_branch_target_tests.rs:7-27` and `bpfopt/crates/bpfopt/src/analysis/bbprogram_cfg_tests.rs:26-39`.
- P1-G branch delta overflow coverage is alive at `bpfopt/crates/bpfopt/src/analysis/lower_tests.rs:5-34`.
- P1-H branch-flip pass/lower path coverage is alive at `bpfopt/crates/bpfopt/src/passes/branch_flip_tests.rs:167-180`.
- P1-H bounds-check branch fixup coverage is alive at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge_tests.rs:95-105`.
- P1-H bounds-check BTF remap coverage is alive at `bounds_check_merge_tests.rs:231-238`.
- P1-H map-inline hard hint side input coverage is alive at `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:183-200`.
- P1-H map-inline no non-verifier fallback coverage is alive at `map_inline_tests.rs:236-245`.
- P1-H map-inline mixed hard/soft CFG sanity coverage is alive at `map_inline_tests.rs:405-442`.
- P1-H wide-mem pseudo-func boundary and BTF struct pointer coverage is alive at `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs:123-148`.
- P1-H pseudo-call callback frame coverage is alive at `bpfopt/crates/bpfopt/src/analysis/bbprogram_cfg_tests.rs:42-55`.

Test quality concern:

- Many tests assert final lowered bytecode. That is useful for regressions, but it does not distinguish native BBProgram logic from flat shim logic.
- `noop` has no direct test, though it is trivial and probably covered indirectly by registry/CLI behavior.

## Hidden Technical Debt

### `unwrap`, `expect`, `panic`, `assert` In Production Paths

Excluded: `#[cfg(test)]` functions and test modules. Included: production code and public helper code used by production paths.

- `bpfopt/crates/bpfopt/src/main.rs:452` - `expect("chunk is 8 bytes")` after `chunks_exact(8)`. Low risk, but still a production `expect`.
- `bpfopt/crates/bpfopt/src/main.rs:707` and `main.rs:714` - `unwrap_or_default()` silently writes empty BTF records.
- `bpfopt/crates/bpfopt/src/pass.rs:828` - `assert!(previous.is_none(), "duplicate kinsn target name {name}")` in kinsn registry construction.
- `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:125` - `group.last().unwrap()`.
- `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:405-406` and `bounds_check_merge.rs:496-497` - `expect("setup site is valid")`.
- `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:540` and `branch_flip.rs:565` - `expect` on integer conversion invariants.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:595` - `expect("LD_IMM64 value is available")`.
- `bpfopt/crates/bpfopt/src/passes/endian.rs:148` - `expect("caller checked endian size")`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:181` - `expect("non-empty anchor checked above")`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3820` - `expect("slice length checked")`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4434` - `debug_assert!(value <= u32::MAX as u64)`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4582` - `expect("skipped_pcs non-empty (checked above)")`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:5206` - `expect("writing to String cannot fail")`.
- `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:189` - `expect("invariant: map pseudo instruction has a pseudo kind")`.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:132`, `bbprogram.rs:139`, and `bbprogram.rs:146` - `unwrap_or_default()` returns empty liveness for missing data.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:186` and `bbprogram.rs:188` - `expect` in `btf_records()`.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:486` - `.ok()?` silently drops negative map indices.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:685`, `bbprogram.rs:699`, and `bbprogram.rs:738` - `expect` after record-size checks.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:221` - `expect("chain is non-empty")`.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:310` - panic through `unwrap_or_else`.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:313-319` - `assert!` in `split_block`.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:329` and `bbprogram_api.rs:359` - `expect` in `split_block`.

### Silenced Errors / Fallback-Like Patterns

- BTF output silently becomes empty on missing records at `bpfopt/crates/bpfopt/src/main.rs:702-715`.
- Unknown target features are warning-and-continue at `main.rs:843-850`.
- `resolve_map_id` silently drops invalid IDX immediates through `.ok()?` at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:479-487`.
- `site_successors` and `first_logical_sites` return empty vectors on invalid blocks at `bbprogram.rs:969-1004`, hiding broken CFG references.
- `branch_flip` discards a validation lower result with `let _ = lower(prog)?;` at `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:359`.
- `bbprogram_use_def` discards a returned block state with `let _ = process_block_state(...)?;` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_use_def.rs:82`.

### Unsafe Blocks

No `unsafe { ... }` blocks were found in `bpfopt/crates/bpfopt/src` by `rg -n "unsafe\\s*\\{"`.

### TODO / FIXME

No exact `TODO` or `FIXME` comments were found in `bpfopt/crates/bpfopt/src` by `rg -n "(TODO|FIXME)"`.

There are still `IMPL:` breadcrumb comments that read like migration notes:

- `bpfopt/crates/bpfopt/src/mock_maps.rs:41` and `mock_maps.rs:50`
- `bpfopt/crates/bpfopt/src/test_helpers.rs:38`, `test_helpers.rs:52`, `test_helpers.rs:66`, and `test_helpers.rs:97-132`
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:441`

### Stale Old-Design Comments

- `bpfopt/crates/bpfopt/src/pass.rs:5` still documents `BpfProgram` as a linear instruction stream.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:28` says pass.rs re-exports hint types for a `BpfProgram` field.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:92-94` says hints are parsed into `BpfProgram.map_inline_hints`.
- `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:39-41` still says offsets are adjusted via an address map, while the current apply path uses BBProgram terminators and block permutation at `branch_flip.rs:403-489`.
- `docs/bbprogram-architecture-design.md:345-356` still describes temporarily retaining legacy implementations and deleting `legacy_cleanup`.

## Prioritized Fix List For Next Codex

### P0 - Correctness / Fail-Fast

1. Make `BBProgram::split_block` fallible.
   - Evidence: panics/asserts at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:307-360`.
   - Change: return `anyhow::Result<(BlockId, BlockId)>`; replace panic/assert/expect with `bail!`/`?`; update callers at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:224`, `cond_select.rs:254`, and `bpfopt/crates/bpfopt/src/passes/ccmp.rs:305-307`.
   - Estimated LOC delta: small positive initially, then neutral after cleanup.

2. Make BBProgram mutation methods transactional or clone-validate-swap.
   - Evidence: `replace_range` mutates at `bbprogram_api.rs:62-65` before use-def rebuild at `bbprogram_api.rs:105`; `replace_diamond_with_insns` mutates at `bbprogram_api.rs:416-429` before `remove_blocks` at `bbprogram_api.rs:441`.
   - Change: perform all validation before mutation where possible; for complex rewrites, clone the program, mutate clone, rebuild CFG/use-def, then swap.
   - Estimated LOC delta: +50 to +150, but prevents half-mutated IR.

3. Stop silently writing empty BTF output.
   - Evidence: `unwrap_or_default()` at `bpfopt/crates/bpfopt/src/main.rs:702-715`.
   - Change: if `--func-info` or `--line-info` is supplied, require the corresponding records to exist after remap; otherwise return an error.
   - Estimated LOC delta: neutral.

4. Make liveness/site successor invalid state fail-fast.
   - Evidence: empty defaults at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:131-146`; invalid block returns empty at `bbprogram.rs:969-1004`.
   - Change: return `Result<RegSet>` for `live_in`, `live_out`, and `live_out_site`, or add checked variants and use them in production passes.
   - Estimated LOC delta: +30 to +80 across call sites.

5. Reject unknown target features.
   - Evidence: warning-and-continue at `bpfopt/crates/bpfopt/src/main.rs:843-850`.
   - Change: replace `eprintln!` with `bail!("unknown target feature: {feature}")`.
   - Estimated LOC delta: neutral.

6. Replace production `expect`/`unwrap` sites with propagated errors where they depend on transform state.
   - Evidence: `bounds_check_merge.rs:125`, `bounds_check_merge.rs:405-406`, `bounds_check_merge.rs:496-497`, `const_prop.rs:595`, `endian.rs:148`, `branch_flip.rs:540`, `branch_flip.rs:565`, `map_inline.rs:181`, `map_inline.rs:3820`, `map_inline.rs:4582`, `map_inline/map_info.rs:189`, and `bbprogram_api.rs:221`.
   - Change: convert to `ok_or_else`/`try_from` with contextual errors unless the invariant is compile-time only.
   - Estimated LOC delta: +20 to +60.

### P1 - Design Contract

1. Re-port `map_inline` to native BBProgram.
   - Evidence: `linear_program_view` and `BpfProgram::new` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2292-2308`; flat fixed-point lowering at `map_inline.rs:2352-2372`; `program: &BpfProgram` round at `map_inline.rs:2431-2439`; PC-keyed planner at `map_inline.rs:1029-1034`, `map_inline.rs:1579-1595`, and `map_inline.rs:2843-3132`.
   - Change: use `BBProgram.map_bindings()` and `PassContext` directly; express lookup sites and rewrites as `InsnSite`/`BlockId` operations; delete address-map planner.
   - Estimated LOC delta: -500 to -1000 in `map_inline.rs`, -200 to -300 in `pass.rs` after `BpfProgram` removal.

2. Remove `BpfProgram` from the pass framework once `map_inline` is ported.
   - Evidence: `BpfProgram` and map provider stack at `bpfopt/crates/bpfopt/src/pass.rs:290-552`; production map_info accepts `&BpfProgram` at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:121-139`.
   - Change: move map provider types either into `map_inline` or convert them to context/BBProgram inputs; delete `BpfProgram`.
   - Estimated LOC delta: -250 to -350 in `pass.rs`.

3. Port flat-scan C-rated passes to BBProgram logical-site scanning.
   - Evidence: `bulk_memory.rs:200-208`, `wide_mem.rs:492-501`, `prefetch.rs:258-273`, `rotate.rs:78-82`, `endian.rs:374-378`, `extract.rs:115-119`, `skb_load_bytes.rs:54-60`, `cond_select.rs:122-124`, and `ccmp.rs:163-164`.
   - Change: add BBProgram same-block window and pattern iteration helpers; convert each pass scanner to `InsnSite` windows; remove `replace_flat_range` copies.
   - Estimated LOC delta: -150 to -300 after shared helpers.

4. Replace `bounds_check_merge::ProgramView` with BBProgram APIs.
   - Evidence: local view at `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:249-330`.
   - Change: hoist current/original PC maps, block-start PCs, and target predicates into BBProgram.
   - Estimated LOC delta: -60 to -120 locally.

5. Revisit `PassManager`.
   - Evidence: `PassManager` at `bpfopt/crates/bpfopt/src/pass.rs:929-1042`; constructed by `bpfopt/crates/bpfopt/src/main.rs:334-341`; imported by `bpfopt/crates/bpfopt/src/passes/mod.rs:43`.
   - Change: if v3 design forbids a manager abstraction here, replace it with a minimal single-pass runner or rename it to avoid implying default pass orchestration. Remove before/after lowering if not needed for reports.
   - Estimated LOC delta: -50 to -120.

6. Move BTF remap out of `bbprogram.rs`.
   - Evidence: BTF remap is in `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:623-761`, not `bbprogram_lower.rs`.
   - Change: split into `bbprogram_btf.rs` or integrate with lower-side metadata emission.
   - Estimated LOC delta: no net LOC reduction, but `bbprogram.rs` drops about 140 LOC.

### P2 - LOC Reduction

1. Delete duplicate `site_for_original_pc` and `replace_flat_range` helpers.
   - Evidence: `bulk_memory.rs:271-290`, `wide_mem.rs:614-633`, `rotate.rs:164-183`, `endian.rs:450-469`, `extract.rs:192-211`, `cond_select.rs:273-278`, `ccmp.rs:366-374`.
   - Change: use shared BBProgram helpers.
   - Estimated LOC delta: -80 to -120.

2. Delete `PassResult::skipped_with_diagnostics`.
   - Evidence: definition at `bpfopt/crates/bpfopt/src/pass.rs:617-622`; no `rg` callers.
   - Change: remove method.
   - Estimated LOC delta: -6.

3. Collapse `PrefetchCfg`.
   - Evidence: local flat CFG at `bpfopt/crates/bpfopt/src/passes/prefetch.rs:366-409`.
   - Change: use BBProgram block/frame APIs and target predicates.
   - Estimated LOC delta: -40 to -60.

4. Split `bbprogram.rs` into focused modules.
   - Evidence: core IR at `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:15-82`, BTF at `bbprogram.rs:623-761`, liveness at `bbprogram.rs:818-1016`.
   - Change: move BTF, liveness, dominance/map-binding helpers to separate files.
   - Estimated LOC delta: net neutral, but `bbprogram.rs` becomes much easier to audit.

5. Remove map_inline flat subprogram helpers after BBProgram frame APIs are used.
   - Evidence: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:4838-4865`.
   - Change: replace with `FrameId`/`subprog_blocks`.
   - Estimated LOC delta: -30 to -50.

### P3 - Polish

1. Update stale comments that still describe `BpfProgram` as the pass IR.
   - Evidence: `bpfopt/crates/bpfopt/src/pass.rs:5`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:28`, and `map_inline.rs:92-94`.
   - Change: rewrite comments around current side-input ownership, or delete them with the old structures.

2. Update stale `branch_flip` address-map comment.
   - Evidence: `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:39-41`.
   - Change: describe terminator rewrite and block permutation.

3. Remove or resolve `IMPL:` migration breadcrumbs.
   - Evidence: `bpfopt/crates/bpfopt/src/test_helpers.rs:38`, `test_helpers.rs:52`, `test_helpers.rs:66`, `test_helpers.rs:97-132`, and `bpfopt/crates/bpfopt/src/mock_maps.rs:41-50`.
   - Change: convert to normal comments or delete where the migration is complete.

4. Add a direct `noop` test or explicitly accept no test.
   - Evidence: `cargo test -- --list` showed zero direct `noop` tests; `noop` implementation is at `bpfopt/crates/bpfopt/src/passes/noop.rs:14-26`.
   - Change: optional direct smoke test through `run_pass_on_insns`.

5. Rename misleading lower tests or add true lower-path tests.
   - Evidence: `bpfopt/crates/bpfopt/src/analysis/lower_tests.rs:5-34` tests `BpfInsn::set_branch_target_delta`, not `lower(&BBProgram)`.
   - Change: rename file/test names or add BBProgram lower fixtures.

## Final Assessment

The migration has a working BBProgram shell and meaningful regression coverage, but the cleanup stopped before the main design payoff. The next iteration should not spend time on broad test churn first. It should fix the P0 fail-fast/atomicity issues, then remove the `map_inline` flat adapter and shared flat-range shims. That is where both the correctness risk and the LOC reduction are concentrated.
