# BBProgram Architecture Flip — Design Doc

Date: 2026-05-10
Status: Design pinned; implementation deferred (Stage 1 codex was stopped pending plan review)

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

## 10. Stage Plan

The original "Stage 1 = infra only" split has been collapsed. Stage 1 now does
**both** infrastructure and the first pass migration (`dce`) in a single codex
run. There is no isolated infra-only milestone; the foundation is validated
through `dce` actually running on the BBProgram instead of a synthetic
roundtrip alone.

| Stage | Scope                                                            | LOC delta |
|-------|------------------------------------------------------------------|-----------|
| 1     | bbprogram/ infra **+** migrate `dce` to BBProgram API + tests    | +1050     |
| 2     | Migrate `const_prop`                                             | -900      |
| 3     | Migrate `bounds_check_merge`                                      | -350      |
| 4     | Migrate `cond_select` (uses multi-block API)                     | -250      |
| 5     | Migrate `ccmp` (uses multi-block API)                            | -250      |
| 6-10  | Migrate 5 single-block kinsn passes + pattern DSL                | -1000     |
| 11    | Migrate `wide_mem`, `branch_flip`, `map_inline`                  | -700      |
| 12    | Delete `AnalysisCache`, `RewritePlan`, dead helpers              | -600      |
| **Total** |                                                              | **-3000** |

Each stage is an independent codex run. No commits between stages without
user approval.

## 11. Stage 1 Acceptance Criteria

`cargo build --release` is clean and all of the following hold simultaneously:

1. **Roundtrip integrity** (infra correctness):
   - Integration test `bbprogram_roundtrip.rs` walks every
     `bpfopt/testbin/<app>/<prog>/canonicalize_output.bin` (542 programs).
   - `lift(insns) → lower(...)` is byte-identical for all 542 programs.
   - Output: `542/542 programs roundtripped byte-identical`.

2. **dce migrated to BBProgram API**:
   - `bpfopt/crates/bpfopt/src/passes/dce.rs` no longer references
     `AnalysisCache`, `RewritePlan`, `LivenessAnalysis`, or `Vec<BpfInsn>`-based
     rewrite plans. It works on `&mut BBProgram` directly.
   - `dce::run` body is dramatically shorter (~50 LOC vs current ~500 LOC).
   - kinsn-aware register uses still respected (P1-F regression must not
     reappear): use-def graph reflects implicit kinsn payload register reads.

3. **dce equivalence** against current behavior:
   - For every testbin prog, lifting → running new `dce` → lowering produces
     **exactly the same applied/skipped sites** as the current `dce`
     implementation on the same input.
   - Implementation: integration test `dce_equivalence.rs` runs both old and
     new `dce` paths in the same process and diffs report counts. Zero
     divergence required.
   - The P1-F kinsn-aware regression test in `dce_tests.rs` still passes.

4. **Non-dce passes unchanged**:
   - `const_prop`, `wide_mem`, `bounds_check_merge`, `cond_select`, `ccmp`,
     `extract`, `endian_fusion`, `bulk_memory`, `prefetch`, `rotate`,
     `branch_flip`, `map_inline`, `noop` continue to operate on `Vec<BpfInsn>`
     via the legacy interface. They are not migrated in Stage 1.
   - Coexistence shim: `bpfopt --pass dce` lifts → runs → lowers; other
     `--pass <name>` invocations stay on the legacy path. The daemon protocol
     is unchanged.

5. **No `AnalysisCache` removal in Stage 1**:
   - `AnalysisCache` and `RewritePlan` continue to exist for legacy passes.
   - They are deleted only when the last consumer migrates (Stage 12).

6. **All 402 existing tests still pass** plus the new roundtrip and dce
   equivalence tests.

7. **No commit**. Working-tree only.

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
