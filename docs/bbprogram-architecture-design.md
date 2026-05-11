# BBProgram Architecture Flip — Design Doc

Date: 2026-05-10  
Status: Stage 1 (BBProgram infra + dce migration) done in working tree.
Remaining stages 2-12 to be executed as a single autonomous codex run that
finishes the migration end-to-end.

## File-layout rule

**NO new top-level `bbprogram/` subdirectory.** All new modules live under the
existing `bpfopt/crates/bpfopt/src/analysis/` directory:

```
analysis/
├── mod.rs                  (existing — re-exports analyses + bbprogram items)
├── cfg.rs                  (existing — gradually folded into bbprogram view)
├── liveness.rs             (existing — replaced by bbprogram::live_in/out method)
├── branch_target.rs        (existing — replaced by bbprogram::successors)
├── site_scan.rs            (existing — kept, pass-local)
├── map_refs.rs             (existing — folded into bbprogram method)
├── bbprogram.rs            (new — type defs: BBProgram, Block, Terminator, ...)
├── bbprogram_lift.rs       (new — lift())
├── bbprogram_lower.rs      (new — lower())
├── bbprogram_use_def.rs    (new — UseDefGraph + auto-maintenance)
└── bbprogram_api.rs        (new — single-insn / range / block-level mutation)
```

The Stage-1 working-tree currently has `bpfopt/crates/bpfopt/src/bbprogram/`.
Migration step zero relocates that directory's contents into `analysis/` with
`bbprogram_*.rs` filenames and updates the import paths.

## 1. Goal

Replace the current "13 passes each scan `Vec<bpf_insn>`" model with a unified
**lift → passes → lower** architecture. Passes operate on a BB-graph + use-def
chain (`BBProgram`). Lift and lower happen exactly once at `bpfopt` main entry
and exit.

Net target: ~3500 LOC reduction + DCE/const_prop/kinsn pass simplification +
elimination of branch-fixup bug class.

## 2. Non-Goals

- Not introducing a new instruction format. `Block.insns: Vec<BpfInsn>` stays
  raw libbpf-sys `bpf_insn`.
- Not introducing SSA. Use-def is plain `def_pc → uses[]` / `use_pc → defs[]`
  multi-graph.
- Not changing the daemon, runner, or corpus framework. BBProgram is internal
  to the `bpfopt` lib crate, hidden behind the existing CLI.
- Not changing benchmark policy (`benchmark_config.yaml`), pass list, or kinsn
  module ABI.

## 3. Architecture

```
bpfopt CLI:
  bytes (stdin / --input)
    → Vec<BpfInsn>
    → BBProgram (LIFT once: blocks + symbolic branches + use-def + oracle)

  for pass in policy:
    pass.run(&mut BBProgram)        // mutation goes through BBProgram API
                                     // use-def + derived analyses kept consistent

  BBProgram → Vec<BpfInsn>  (LOWER once: topological order + branch.off re-encode)
    → bytes (stdout / --output)
```

Per-pass `BPF_PROG_REJIT(log_level=2)` happens on the lowered bytes (not on
BBProgram). Verifier-state JSON is parsed back into `BBProgram.oracle` for the
next pass invocation.

## 4. Core Data Structures

```rust
pub struct BBProgram {
    pub blocks:      Vec<Block>,           // owns all insns
    pub entry:       BlockId,
    pub use_def:     UseDefGraph,           // primary, auto-maintained
    pub oracle:      Option<VerifierOracle>,// from prior pass's verifier log
    pub btf:         BtfMetadataMap,        // (BlockId, intra_idx) → original PC
    pub kinsn_reg:   Arc<KinsnRegistry>,
}

pub struct Block {
    pub id:          BlockId,
    pub insns:       Vec<BpfInsn>,          // straight-line body
    pub terminator:  Terminator,
    pub frame:       FrameId,                // 0 for entry; >0 for BPF-to-BPF subprog
}

pub enum Terminator {
    Fallthrough { next: BlockId },                      // synthetic (no branch insn)
    Jump        { target: BlockId },                    // BPF_JA
    CondBranch  {
        cond: BpfInsn,                                  // raw Jcc, but its `off` is unused
        taken: BlockId,
        fallthrough: BlockId,
    },
    Call        { callee: BlockId, return_to: BlockId },// pseudo_call (BPF-to-BPF)
    Exit,                                                // BPF_EXIT
}

pub struct UseDefGraph {
    pub defs: BTreeMap<DefSite, Vec<UseSite>>,
    pub uses: BTreeMap<UseSite, Vec<DefSite>>,
}
pub struct DefSite { pub block: BlockId, pub idx: usize, pub reg: u8 }
pub struct UseSite { pub block: BlockId, pub idx: usize, pub reg: u8 }
```

**Key invariants** (BBProgram enforces):

- Branches in `Terminator` reference `BlockId`, never PC offsets. The `off`
  field of the held `BpfInsn` is **ignored** during BBProgram phase; lower
  recomputes it.
- `Block.insns` only contains straight-line non-branch insns (or single-insn
  bodies for blocks consisting of just a terminator).
- ldimm64 double-slot is treated as a single logical insn at one `idx`; the
  second slot is hidden inside the same `BpfInsn` representation.
- `pseudo_map_fd`, `pseudo_func`, `pseudo_btf_id` raw insns stay verbatim;
  their bytecode is unchanged across lift/lower.
- BTF func_info / line_info entries are remapped via `btf` field; lift records
  original PCs, lower re-emits at new PCs.

## 5. BBProgram API

```rust
impl BBProgram {
    // ---- queries (no mutation) ----
    pub fn blocks(&self) -> impl Iterator<Item = &Block>;
    pub fn predecessors(&self, b: BlockId) -> &[BlockId];
    pub fn successors(&self, b: BlockId) -> &[BlockId];
    pub fn dominance(&self) -> Dominance;                    // recomputed each call
    pub fn live_in(&self, b: BlockId) -> RegSet;             // recomputed
    pub fn live_out(&self, b: BlockId) -> RegSet;            // recomputed

    // ---- single-insn mutation (intra-block) ----
    pub fn replace_insn(&mut self, site: DefSite, new: BpfInsn);
    pub fn delete_insn(&mut self, site: DefSite);            // gap closes; use-def updated
    pub fn insert_insn(&mut self, before: UseSite, insn: BpfInsn);

    // ---- range mutation (intra-block) ----
    pub fn replace_range(
        &mut self,
        block: BlockId,
        range: Range<usize>,
        replacement: Vec<BpfInsn>,
    );

    // ---- block-level CFG mutation (cond_select / ccmp need this) ----
    pub fn merge_linear_chain(&mut self, blocks: &[BlockId]) -> BlockId;
    pub fn delete_block(&mut self, b: BlockId);              // panics if reachable
    pub fn rewire_edge(&mut self, from: BlockId, old_to: BlockId, new_to: BlockId);
    pub fn split_block(&mut self, at: UseSite) -> (BlockId, BlockId);

    // ---- emit kinsn replacement (multi-block diamond → single helper call) ----
    pub fn replace_diamond_with_kinsn(
        &mut self,
        diamond_blocks: DiamondPattern,
        kinsn_call: BpfInsn,
    );
}
```

All mutations **automatically update**:
- `use_def` (recompute affected def/use sites)
- `predecessors` / `successors` cache
- `btf` (when insn ranges shift)

There is **no `AnalysisCache`**. Derived analyses (dominance, loops, liveness)
are pure methods that recompute on call. BPF programs are small (avg ~6000
insn, max ~16000); recomputation is microseconds per call. If a pass needs a
result twice in a row it `let`-binds it locally.

## 6. Lift Algorithm

```rust
pub fn lift(insns: &[BpfInsn], oracle: Option<VerifierOracle>) -> Result<BBProgram> {
    // 1. Find block boundaries:
    //    - PC 0 starts entry
    //    - any branch target PC starts a block
    //    - PC after a branch/JA/exit/call insn starts a block
    //    - subprog entry (BPF-to-BPF call target) starts a new block (and frame)
    //
    // 2. Walk insns, splitting into Block bodies + terminators.
    //    - ldimm64 occupies 2 PC slots → represented as 1 logical insn; second
    //      slot is held inside BpfInsn.next_imm bytes (libbpf-sys gives this).
    //    - pseudo_call (BPF-to-BPF) → Terminator::Call; the call target PC →
    //      callee BlockId, fallthrough PC → return_to BlockId.
    //
    // 3. Resolve PC-offset branches → BlockId references.
    //    - JA  off    → Terminator::Jump { target = pc_to_block[pc + 1 + off] }
    //    - JA32 imm   → Terminator::Jump { target = pc_to_block[pc + 1 + imm as i32] }
    //    - Jcc off    → Terminator::CondBranch { taken = ..., fallthrough = ... }
    //    - Exit       → Terminator::Exit
    //
    // 4. Build use-def graph from straight-line dataflow within blocks; cross-
    //    block edges from reaching-def join over predecessors. (Simplest
    //    correct version first; refine if profiling shows hot.)
    //
    // 5. Build BTF map: original PC of each insn is recorded for each
    //    (block, intra_idx).
    //
    // 6. If verifier log was provided, parse oracle so passes see per-PC
    //    type evidence as before; oracle PCs are translated to (block, idx)
    //    via the same map.
}
```

## 7. Lower Algorithm

```rust
pub fn lower(prog: &BBProgram) -> Vec<BpfInsn> {
    // 1. Topologically sort blocks; tie-break by lift-time creation order to
    //    keep diff against input minimal (passes that don't change CFG produce
    //    byte-identical output with fewer differences for review).
    //
    // 2. Assign PC ranges to each block. Each block contributes len(insns) +
    //    Terminator-emitted insns (0..=1).
    //
    // 3. For each Terminator, emit the original branch insn but recompute
    //    `off` from `(target_block_pc - current_pc - 1)` (or `imm` for JA32).
    //    Reject if offset doesn't fit in i16 (Jcc) or i32 (JA32) — but this
    //    must not happen because lift preserves block reachability.
    //
    // 4. Re-emit ldimm64 second slot, pseudo_map_fd / pseudo_func / pseudo_btf_id
    //    raw bytes unchanged.
    //
    // 5. Update BTF func_info / line_info via the prog.btf map: each entry
    //    points to original PC; lower writes new PC at output position.
}
```

## 8. AnalysisCache: Deleted

Current `AnalysisCache` (~300 LOC) is removed entirely. Its consumers are
replaced as follows:

| Old `analysis/X.rs`           | New location                                 |
|-------------------------------|----------------------------------------------|
| `cfg.rs`                      | `BBProgram { blocks, predecessors, ... }`    |
| `liveness.rs`                 | `BBProgram::live_in/live_out` (pure method)  |
| `branch_target.rs`            | `BBProgram::successors`                      |
| `site_scan.rs`                | pass-local helper (kept)                     |
| `map_refs.rs`                 | `BBProgram::map_refs` (pure method)          |

There is no typed `cache.get::<X>()` polymorphism. No `TypeId` map. No
generation-based invalidation. Pure methods only.

## 9. Pass Migration Model

A migrated pass looks like:

```rust
impl BpfPass for Dce {
    fn name() -> &'static str { "dce" }

    fn run(&self, prog: &mut BBProgram, ctx: &PassCtx) -> PassReport {
        let mut applied = 0;
        let dead_defs: Vec<_> = prog.use_def.defs()
            .filter(|d| d.uses().is_empty() && !d.has_side_effect(prog))
            .collect();
        for d in dead_defs {
            prog.delete_insn(d.site());
            applied += 1;
        }
        PassReport { applied, ..Default::default() }
    }
}
```

`RewritePlan` (~600 LOC) is **deleted**. Its job (commit-based mutation,
addr_map, fixup_all_branches) is absorbed into BBProgram mutation methods +
the lower stage.

### Multi-block kinsn (cond_select / ccmp)

cond_select and ccmp match diamond / chain patterns spanning **multiple
blocks**. They use the BB-graph mutation API:

```rust
// cond_select pattern A: 4-insn diamond across 3 blocks
fn cond_select_run(prog: &mut BBProgram, ctx: &PassCtx) -> PassReport {
    let diamonds = scan_diamonds(prog);
    for d in diamonds {
        let kinsn_call = build_select64_call(d);
        prog.replace_diamond_with_kinsn(d, kinsn_call);
        // ↑ this:
        //   - merges the predecessor + true-mov-block + false-mov-block + join
        //   - inserts kinsn_call into the merged block
        //   - rewires successors of the join to be successors of merged block
    }
    ...
}
```

Single-block kinsn (rotate / extract / endian / bulk_memory / prefetch) use
`replace_range` only.

## 10. Stage Plan — single autonomous codex run

Stages 2-12 are executed as **one continuous codex run** that completes every
remaining migration end-to-end. There are no per-stage human gates between 2
and 12. Stage 1 (infra + dce) is done; the remaining work is enumerated below
so the codex tracks progress, but the deliverable is a single working tree
with all migrations finished and code-volume reduction verified.

| Sub-step | Scope                                                          | LOC delta |
|----------|----------------------------------------------------------------|-----------|
| 0        | Relocate `bbprogram/` into `analysis/bbprogram_*.rs`            | 0         |
| 1 (done) | analysis/bbprogram_* infra + migrate `dce` + tests              | done      |
| 2        | Migrate `const_prop`                                            | -900      |
| 3        | Migrate `bounds_check_merge`                                    | -350      |
| 4        | Migrate `cond_select` (multi-block API)                         | -250      |
| 5        | Migrate `ccmp` (multi-block API)                                | -250      |
| 6        | Migrate `rotate`                                                 | -200      |
| 7        | Migrate `extract`                                                | -200      |
| 8        | Migrate `endian_fusion`                                          | -200      |
| 9        | Migrate `bulk_memory`                                            | -200      |
| 10       | Migrate `prefetch`                                               | -200      |
| 11       | Migrate `wide_mem`, `branch_flip`, `map_inline`, `noop`,         | -700      |
|          | `skb_load_bytes_spec`                                            |           |
| 12       | Delete `AnalysisCache`, `RewritePlan`, `RewriteOutput`,          | -800      |
|          | `commit_rewrite_output`, `compose_addr_maps`, `BtfRemapPolicy`,  |           |
|          | `legacy_cleanup`, dead helpers; collapse `analysis/cfg.rs`,      |           |
|          | `analysis/liveness.rs`, `analysis/branch_target.rs`,             |           |
|          | `analysis/map_refs.rs` into BBProgram methods if not already.    |           |
| **Total** |                                                              | **-4250** |

After step 12, the only mutation API is BBProgram. Every CLI pass invocation
(`bpfopt --pass <name>`) lifts → runs the migrated pass on `&mut BBProgram` →
lowers. There is no `Vec<bpf_insn>`-based mutation path in the lib crate.

## 11. Final Acceptance Criteria (after sub-step 12)

`cargo build --release` is clean and all of the following hold simultaneously:

1. **Roundtrip integrity** (already passing): 542/542 testbin programs
   roundtrip byte-identical via `lift→lower`.

2. **Pass-equivalence on every migrated pass**: for each of the 14 pass names,
   an integration test like `<pass>_equivalence.rs` shows the new BBProgram
   path produces exactly the same `applied/matched/skipped` counts and the
   same output bytecode as the legacy path on every testbin program.
   Zero divergence on all 542 programs.

   The legacy implementation may be kept temporarily inside an
   `#[cfg(test)]` module purely for the equivalence test, then deleted
   in sub-step 12 along with its support code (`RewritePlan`, etc.).

3. **No `Vec<BpfInsn>` mutation path in production**: the production code
   path for every `--pass <name>` invocation is `lift → migrated_pass →
   lower`. Search for `RewritePlan`, `RewriteOutput`, `AnalysisCache`,
   `commit_rewrite_output`, `compose_addr_maps`, `BtfRemapPolicy`,
   `legacy_cleanup` — all must be deleted (or live only inside
   `#[cfg(test)]` equivalence harnesses, deleted entirely in sub-step 12).

4. **No `bbprogram/` directory**: all BBProgram modules live in
   `analysis/bbprogram_*.rs`.

5. **No benchmark-framework changes**: `corpus/`, `runner/`, `e2e/`,
   `micro/`, `daemon/` untouched. The daemon socket protocol and per-pass
   CLI invocation contract are unchanged. `runner/config/passes/dce/default.yaml`
   etc. are NOT edited.

6. **Significant code-volume reduction**: total `bpfopt/crates/bpfopt/src/`
   line count after sub-step 12 must be at least **2500 LOC less** than at
   the start of this work. Report before/after numbers per file.

7. **All existing 402 tests still pass**, plus 14 equivalence tests, plus
   the roundtrip test. Cargo test suite is green at every step.

8. **No commit**. Working-tree only.

## 12. Risks

| Risk | Mitigation |
|------|------------|
| ldimm64 second slot mishandled at lift | unit test on every testbin prog with ldimm64 (most have at least one); roundtrip catches |
| pseudo_call (BPF-to-BPF) frame tracking | unit test on tetragon/cilium progs which have subprogs; lift assigns FrameId per call target |
| JA32 imm vs JA off divergence | already a known landmine (P1-G defect-2); handle in lift + lower symmetrically |
| Branch offset overflow on lower (i16 Jcc / i32 JA32) | currently can't happen because lift preserves graph and lower preserves reachability; assert on emit |
| BTF metadata desync | `btf` map is updated in every mutation method; assert in roundtrip test that BTF entries map to valid PCs |
| Multi-block kinsn (cond_select/ccmp) breaks reachability | pattern matcher must verify all intermediate blocks have exactly one predecessor inside the diamond before merging |
| 13-pass migration spans weeks | each stage is independent; paper data line continues on `main` between stages without depending on this work |

## 13. Out of Scope (Phase 4+ Later)

- e-graph / equality saturation (Phase 4)
- Verified rewriting (Phase 5)
- Pattern DSL proc-macro for kinsn passes (folded into Stage 7-11 if cheap)

## 14. Approval Gate

Stage 1 (BBProgram infra + roundtrip) must pass byte-identical roundtrip on
all 542 testbin progs before any pass migration starts. If even 1 program
fails roundtrip, fix lift/lower, do not skip the program.
