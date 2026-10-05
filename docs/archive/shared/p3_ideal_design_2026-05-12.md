# bpfopt Ideal Architecture (Phase 3 Post-Mortem)

Date: 2026-05-12
Status: design target — not yet fully implemented
Audience: Phase 3 BBProgram migration team + OSDI '26 paper review

## Context

bpfopt is a BPF bytecode optimizer with 15 passes (7 kop-class, 8 bytecode-rewriting) sitting on a basic-block IR (`BBProgram`). Phase 3 moved the codebase from "flat instruction array + PC offset" to "BB IR + InsnSite". After two days of iterative cleanup we landed at ~17300 LOC (-8.7% vs Phase 3 baseline). The ideal architecture would go further by collapsing repeated workflow scaffolding, removing the PassContext god-struct, and putting CLI bloat in its rightful place.

This document captures the design we're aiming at, not the design we have.

## 1. Layered Architecture

```
┌─ Layer 4: CLI (main.rs, ≤700 LOC) ─────────────────────────────────┐
│   - clap argument parsing                                          │
│   - Pass orchestration (decode → lift → run pipeline → lower)      │
│   - JSON report serialization                                      │
│   - Calls bpfopt::side_input::load(args) to fetch typed inputs     │
└─────────────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─ Layer 3: lib (bpfopt::) ──────────────────────────────────────────┐
│   - bpfopt::side_input — JSON parsing for snapshots, hints,        │
│                          verifier logs (1100 LOC moved from main)  │
│   - bpfopt::pass — BpfPass trait, KopPass trait, executors       │
│   - bpfopt::passes — concrete pass implementations                 │
└─────────────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─ Layer 2: BBProgram IR (analysis::*) ──────────────────────────────┐
│   - Identity types (BlockId, FrameId, InsnSite) — opaque to passes │
│   - SlotDistance — layout query newtype                            │
│   - KopAdmissionWindow — admission result token                  │
│   - lift(insns, side_input) — single entry, builder-style          │
│   - mutation API (replace_range_at, replace_terminator, ...)       │
│   - typed verifier queries (reg_known_*, branch_*, site_*)         │
│   - lower(prog) — single exit                                      │
└─────────────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─ Layer 1: insn + verifier_log ─────────────────────────────────────┐
│   - BpfInsn (libbpf-sys), predicates (is_alu_imm, is_ldx_mem, ...) │
│   - Raw verifier types pub(crate) — invisible to passes            │
└─────────────────────────────────────────────────────────────────────┘
```

## 2. BBProgram Public API

### 2.1 Identity (passes hold but cannot construct)

```rust
pub struct BlockId(pub(crate) usize);
pub struct FrameId(pub(crate) usize);
pub struct InsnSite { pub(crate) block: BlockId, pub(crate) idx: usize }
```

Passes get these from BBProgram enumeration methods and pass them back. Reading `.0` / `.block` / `.idx` for positional reasoning (e.g., `block.0 + 1` for adjacency, `sites[i + 1]` for next site in block) is allowed — these are positional integer IDs and arithmetic on positions is structural, not PC.

Forbidden in passes:
- Constructing literal `BlockId(99)` or `InsnSite { block, idx: 5 }` — bypasses BBProgram invariants
- Writing to fields (identity is immutable)

### 2.2 Opaque tokens

```rust
pub struct SlotDistance(usize);     // layout distance in machine slots
pub struct MapPtr;                  // typed verifier query result
pub enum RegKind { Scalar, MapValue, MapKey, Packet, ... }
pub struct PrefetchHint { ... }
```

Each has narrow methods (e.g., `SlotDistance::slots()`, `KopAdmissionWindow::start_site()`). Internal representation hidden.

### 2.3 Query methods on BBProgram

```rust
impl BBProgram {
    // Iteration (always returning iterators, not Vec)
    pub fn blocks(&self) -> impl Iterator<Item = &Block> + '_;
    pub fn block_ids(&self) -> impl Iterator<Item = BlockId> + '_;
    pub fn all_sites(&self) -> impl Iterator<Item = InsnSite> + '_;
    pub fn sites_in_block(&self, block: BlockId) -> Result<&[InsnSite]>;  // borrow, not Vec

    // CFG
    pub fn predecessors(&self, block: BlockId) -> &[BlockId];
    pub fn successors(&self, block: BlockId) -> &[BlockId];
    pub fn terminator(&self, block: BlockId) -> Result<Terminator>;
    pub fn site_block(&self, site: InsnSite) -> BlockId;
    pub fn site_frame(&self, site: InsnSite) -> Result<FrameId>;
    pub fn branch_target_entry_sites(&self) -> Result<BTreeSet<InsnSite>>;

    // Instruction access (exactly one entry point per shape)
    pub fn insn(&self, site: InsnSite) -> Result<&BpfInsn>;  // fail-fast
    pub fn try_insn(&self, site: InsnSite) -> Option<&BpfInsn>;  // probe

    // Scanner (M's matcher)
    pub fn block_body_view(&self, block: BlockId) -> Result<BlockBodyView<'_>>;
    pub fn scan_block_starts<F, T>(&self, max_lookahead: usize, f: F) -> Result<Vec<WindowHit<T>>>
        where F: FnMut(BlockStartWindow<'_>) -> Result<Option<LocalWindowHit<T>>>;

    // Typed verifier queries
    pub fn reg_known_constant(&self, site: InsnSite, reg: u8) -> Option<i64>;
    pub fn reg_known_stack_bytes(&self, site: InsnSite, reg: u8, n: usize) -> Option<Vec<u8>>;
    pub fn reg_kind(&self, site: InsnSite, reg: u8) -> Option<RegKind>;
    pub fn site_is_dead_code(&self, site: InsnSite) -> bool;

    // Typed profile queries
    pub fn branch_taken_rate(&self, site: InsnSite) -> Option<f32>;
    pub fn branch_miss_rate(&self, site: InsnSite) -> Option<f32>;
    pub fn site_hotness(&self, site: InsnSite) -> Option<u64>;
    pub fn prefetch_hint(&self, site: InsnSite) -> Option<PrefetchHint>;

    // Layout queries (SlotDistance newtype)
    pub fn site_layout_offset(&self, site: InsnSite) -> Result<SlotDistance>;
    pub fn site_slot_width(&self, site: InsnSite) -> Result<SlotDistance>;
    pub fn block_range_slot_count(&self, first: BlockId, last: BlockId) -> Result<SlotDistance>;

    // Side input queries (after PassContext deconstruction)
    pub fn kop_registry(&self) -> &KopRegistry;
    pub fn kop_call(&self, target: &str) -> Result<(i32, i16)>;  // (btf_id, kfunc_off)
    pub fn platform(&self) -> PlatformCapabilities;
    pub fn prog_type(&self) -> u32;
    pub fn program_branch_miss_rate(&self) -> Option<f64>;
    pub fn map_inline_side_input(&self) -> Option<&MapInlineSideInput>;
}
```

### 2.4 Mutation methods

The single universal core for in-block instruction replacement is `try_replace_range`. It absorbs admission (subprog/branch-target/BTF), lazy payload generation, pass-specific skip decisions, and the actual mutation into one entry point. The old `replace_range_at` and `rep_admit_kop_site_window` + `KopAdmissionWindow` token are gone.

```rust
pub enum MakeReplacement {
    Use(Vec<BpfInsn>),
    Skip(String),
}

pub enum TryReplaceOutcome {
    Applied,
    Skipped(String),
}

impl BBProgram {
    // Instruction-level: ONE universal mutation core.
    // - Runs structural admission first (subprog/branch-target/BTF).
    // - On admission failure, returns Skipped(reason) without calling the closure.
    // - On admission success, calls closure for lazy payload generation.
    //   Closure can return MakeReplacement::Skip(reason) to defer (e.g., live-out failed).
    // - Closure returning MakeReplacement::Use(insns) commits the replacement.
    pub fn try_replace_range<F>(
        &mut self,
        start: InsnSite,
        old_len: usize,
        new_len: usize,
        make_replacement: F,
    ) -> Result<TryReplaceOutcome>
    where
        F: FnOnce() -> Result<MakeReplacement>;

    // For unchecked low-level deletion (only def-site dead code elimination).
    pub fn delete_insn(&mut self, def_site: DefSite) -> Result<usize>;

    // CFG-level (orthogonal to instruction replace; kept as-is)
    pub fn replace_terminator(&mut self, block: BlockId, term: Terminator) -> Result<()>;
    pub fn delete_cond_branch(&mut self, block: BlockId) -> Result<()>;
    pub fn split_block(&mut self, at: InsnSite) -> Result<(BlockId, BlockId)>;
    pub fn merge_linear_chain(&mut self, chain: &[BlockId]) -> Result<BlockId>;
    pub fn permute_blocks(&mut self, order: &[BlockId]) -> Result<()>;
    pub fn delete_unreachable_blocks(&mut self) -> Result<usize>;
    pub fn replace_diamond_with_insns(&mut self, diamond: DiamondPattern, replacement: Vec<BpfInsn>) -> Result<()>;

    // Shared side-input accessor for kop passes
    pub fn kop_call(&self, target_name: &str) -> Result<(i32, i16)>;  // (btf_id, kfunc_off)

    // For rotate's "live-out at the last insn of a kop window" check
    pub fn live_out_after_window(&self, start: InsnSite, len: usize) -> Result<RegSet>;
}
```

**Removed entirely**:
- `replace_range_at` — every caller migrates to `try_replace_range`
- `rep_admit_kop_site_window` — admission is internal to `try_replace_range`
- `KopAdmissionWindow` — unused token type

Each mutation atomically:
1. Clones state (clone-swap idiom)
2. Performs the mutation
3. Rebuilds CFG edges + use-def graph
4. Shifts InsnSite-keyed metadata (oracle / profile / BTF) according to the mutation shape
5. Invalidates oracle (since verifier facts are tied to old PCs)

Passes never call rebuild / invalidate / shift directly.

## 3. Pass Model

### 3.1 BpfPass — generic pass trait

```rust
pub trait BpfPass {
    fn name(&self) -> &str;
    fn run(&self, prog: &mut BBProgram) -> Result<PassResult>;
}
```

**`ctx: &PassContext` is gone**. Pass-specific side inputs are queried from BBProgram (see §4).

### 3.2 Pass body — no new trait, no shared executor

Per L's design and user direction: do NOT add a trait. Do NOT add a `run_kop_pass<...>` shared executor function. Each pass writes its own scan + apply loop using `try_replace_range`. The shared shape is short (~10 lines of mutation loop) and not worth hiding behind another layer.

Concrete example — rotate.rs after V1:

```rust
// rotate.rs (~80-100 LOC total, was ~150-200 LOC)

fn rotate_scan(prog: &BBProgram) -> Result<Vec<RotateCandidate>> {
    let mut out = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        let sites = prog.sites_in_block(block)?;
        let insns: Vec<_> = sites.iter().map(|&s| prog.insn(s)).collect::<Result<_>>()?;
        for (i, window) in sites.windows(5).enumerate() {
            if let Some(site) = rotate_pattern(&insns[i..i + 5]) {
                out.push(RotateCandidate { start: window[0], old_len: site.old_len, site });
            }
        }
    }
    Ok(out)
}

impl BpfPass for RotatePass {
    fn name(&self) -> &str { "rotate" }

    fn run(&self, prog: &mut BBProgram) -> Result<PassResult> {
        let candidates = rotate_scan(prog)?;
        let (btf_id, kfunc_off) = prog.kop_call("bpf_rotate64")?;
        let mut skipped = Vec::new();
        let mut applied = 0usize;

        for c in candidates.iter().rev() {
            let outcome = prog.try_replace_range(c.start, c.old_len, 2, || {
                if prog.live_out_after_window(c.start, c.old_len)?.contains(&c.site.tmp_reg) {
                    return Ok(MakeReplacement::Skip("tmp_reg live".into()));
                }
                let payload = pack_rotate_payload(&c.site);
                Ok(MakeReplacement::Use(emit_packed_kop_call_with_off(
                    payload, btf_id, kfunc_off,
                )))
            })?;
            match outcome {
                TryReplaceOutcome::Applied => applied += 1,
                TryReplaceOutcome::Skipped(reason) => {
                    skipped.push(SiteSkipReason { site: c.start, reason });
                }
            }
        }

        Ok(PassResult { sites_applied: applied, site_skipped: skipped, ..PassResult::unchanged() })
    }
}
```

Every other replacing pass (extract, endian, bulk_memory, wide_mem, ccmp, cond_select, const_prop, skb_load_bytes, map_inline, bounds_check_merge, prefetch) follows the same shape: pass-specific `scan` returning a `Vec<XxxCandidate>`, then a uniform reverse-iter + try_replace_range + match outcome loop. No shared trait, no shared executor — the loop is 10 lines and reads cleanly.

Pass LOC ~80-120 each (was 150-200). Total kop savings across 6 passes ~300-450 LOC. Plus non-kop passes (const_prop / skb_load_bytes / bounds_check_merge / map_inline) get unified skip plumbing they didn't have before.

### 3.3 PassResult — generic, no pass-specific pollution

```rust
pub struct PassResult {
    pub sites_applied: usize,
    pub site_skipped: Vec<SiteSkipReason>,
    pub diagnostics: Vec<String>,
    pub insns_before: usize,
    pub insns_after: usize,
}
```

`map_inline_records` and other pass-specific output is returned via a separate channel (e.g., `MapInlinePass::run` returns `(PassResult, MapInlineReport)`).

## 4. PassContext deconstructed

### 4.1 Today

```rust
pub struct PassContext {
    pub kop_registry: KopRegistry,
    pub platform: PlatformCapabilities,
    pub prog_type: u32,
    verifier_states: Arc<[VerifierInsn]>,
    pub annotations: Vec<InsnAnnotation>,
    pub branch_miss_rate: Option<f64>,
    pub map_ids: Vec<u32>,                          // map_inline
    pub map_metadata: HashMap<u32, MapMetadata>,    // map_inline
    pub map_values: HashMap<(u32, Vec<u8>), Vec<u8>>,           // map_inline
    pub map_value_overlays: HashMap<u32, CompressedMapValues>,  // map_inline
    pub map_inner_map_ids: HashMap<(u32, Vec<u8>), u32>,        // map_inline
    pub map_snapshots_skipped_by_size: HashSet<u32>,            // map_inline
    pub map_inline_hints: Vec<MapInlineHintSpec>,               // map_inline
    pub func_info: Option<BtfInfoRecords>,
    pub line_info: Option<BtfInfoRecords>,
}
```

13 fields. 7 are map_inline-only, 1 is branch_flip-only, 5 are general lift inputs.

### 4.2 Target

```rust
// Only lift inputs left:
pub struct LiftInputs {
    pub kop_registry: KopRegistry,
    pub platform: PlatformCapabilities,
    pub prog_type: u32,
    pub verifier_states: Arc<[VerifierInsn]>,
    pub annotations: Vec<InsnAnnotation>,
    pub branch_miss_rate: Option<f64>,
    pub func_info: Option<BtfInfoRecords>,
    pub line_info: Option<BtfInfoRecords>,
    pub map_inline_side_input: Option<MapInlineSideInputSpec>,
}
```

`LiftInputs` is consumed once by `lift(insns, inputs) -> BBProgram`. After lift, all of these are attached to BBProgram as side inputs queryable via `prog.kop_call(...)` / `prog.platform()` / `prog.program_branch_miss_rate()` / `prog.map_inline_side_input()`.

Passes never see `LiftInputs`. The `BpfPass::run(&self, prog)` signature has no `ctx`.

## 5. main.rs and side-input loading

### 5.1 Today

main.rs is 1900 LOC. About 1100 LOC is map-inline-specific JSON parsing, bpftool snapshot ingestion, compressed-overlay decoding, and verifier log/JSON parsing. None of this is CLI logic — it's library data ingestion.

### 5.2 Target

```rust
// main.rs (≤700 LOC):
fn main() -> Result<()> {
    let args = Cli::parse();
    let insns = parse_bytecode(&args.input_bytes()?)?;
    let inputs = bpfopt::side_input::load(&args)?;  // ← parses all JSON, returns LiftInputs
    let mut prog = bpfopt::analysis::lift(&insns, inputs)?;
    for pass in bpfopt::passes::registry_select(&args.passes) {
        let result = pass.run(&mut prog)?;
        report(&pass, &result, &prog);
    }
    let out = bpfopt::analysis::lower(&prog)?;
    write_output(&args, &out)?;
    Ok(())
}
```

`bpfopt::side_input` lives in `lib.rs` (as `pub(crate) mod side_input` or inline in pass.rs). It owns:
- `read_map_values()` (bpftool dump parsing)
- `parse_compressed_map_values_json()`
- `parse_inline_hint_specs()`
- `read_verifier_states()` (both log and JSON paths)
- `read_btf_info_records()`

main.rs only does file IO + CLI flag mapping; the side-input module handles all data shape decisions.

## 6. Forbidden patterns (architecture invariants)

1. **No raw verifier types in pass code.** `VerifierInsn`, `RegState`, `Tnum`, `ScalarRange`, `StackState`, `VerifierOracle`, `PmuRecord`, `PrefetchProfile` are `pub(crate)`. Passes only see typed BBProgram queries.

2. **No PC in pass code.** `site_current_pc`, `block_start_pc`, `original_pc`, `insn_slot_width` are `pub(crate)`. Passes use `prog.site_layout_offset(site) -> SlotDistance` for layout reasoning, or stay agnostic.

3. **No pass-specific helpers on BBProgram.** No `bf_*` / `pf_*` / `bcm_*` methods. Layout-aware passes use the shared `SlotDistance` API.

4. **No identity construction in passes.** `BlockId(99)` / `InsnSite { ... }` literal construction is forbidden. Passes always obtain identities from BBProgram methods.

5. **No mutation outside the mutation API.** Direct writes to `prog.blocks[i].insns` are forbidden. Always go through `replace_range_at` / `replace_terminator` / etc.

6. **No JSON IO in pass code.** All file/JSON parsing is in `bpfopt::side_input` (called at lift time).

7. **No escape patterns.** `.ok()?`, `unwrap_or_default`, `unwrap_or(0)`, `let _ = ...`, `_var` discards of typed query results, `#[allow(dead_code)]`, `todo!()`, `unimplemented!()` are forbidden in production.

8. **No pass-specific fields on PassResult or PassContext.** Pass-specific outputs go through pass-specific return types (e.g., `(PassResult, MapInlineReport)`).

9. **No new helper files.** Library logic absorbs into existing modules: `analysis/`, `pass.rs`, `passes/<name>.rs`, `insn.rs`, `verifier_log.rs`, `main.rs`. `passes/map_inline/map_info.rs` is the only existing sub-file and contains map-info-specific code.

10. **No DSL for pattern matching.** Per L's design doc, every kop pass writes its own pattern recognition. The shared abstraction is at the SCAN/ADMIT/APPLY plumbing level (`run_kop_pass` executor + `scan_block_starts` window iterator), not at the predicate composition level.

## 7. Where we are vs ideal (2026-05-12)

| Goal | Status |
|------|--------|
| Identity opacity | ✅ |
| Typed verifier queries (no raw VerifierInsn in passes) | ✅ |
| SlotDistance for layout (no `site_current_pc` in passes) | ✅ |
| Single mutation API (no `replace_range(block, Range)`) | ✅ |
| No pass-specific helpers on BBProgram | ✅ (N1) |
| No JSON IO in passes | ✅ (S) |
| MapMetadata/MapInfo consolidated | ✅ (S) |
| BBProgram unowns MapInlineSideInput | ✅ (S, but stored under `prog.map_inline_side_input` accessor) |
| PolicyConfig deleted | ✅ (S) |
| PassManager → free function | ✅ (N2) |
| matcher API (block_body_view + scan_block_starts) | ✅ (M) |
| **KopPass trait + executor** | ❌ — biggest remaining win, ~-200-400 LOC |
| **PassContext god-struct deconstructed** | ❌ — ~-150-250 LOC |
| **main.rs side-input ingestion moved to lib** | ❌ — organization only, no LOC delta |
| **`ctx: &PassContext` removed from BpfPass::run** | ❌ — follows PassContext deconstruction |
| **PassResult.map_inline_records removed** | ❌ — pass-specific output channel |
| **`insn_at`/`insn` unified** | ❌ — ~-30 LOC |
| **`sites_in_block` returns borrow not Vec** | ❌ — perf + LOC |
| `try_replace_kop` collapses admit/apply/skip | ❌ — part of KopPass refactor |
| Skip-reason builder unified | ❌ — minor |
| BTF remap dedup (lower vs view) | ❌ — ~-40 LOC |
| map_inline silent `Err(_) => None` propagated | ❌ — P review #5 |
| bulk_memory full matcher migration | ❌ — P review #7 |
| bbprogram.rs sectioned within file | ❌ — readability, no LOC delta |

## 8. Concrete next steps

To reach the ideal, three more codex passes are needed:

### V1: Universal mutation core + migrate every pass
- Add `MakeReplacement`, `TryReplaceOutcome` enums + `try_replace_range(start, old_len, new_len, closure)` to bbprogram_api.rs
- Add `BBProgram::kop_call(target) -> (btf_id, kfunc_off)` convenience
- Add `BBProgram::live_out_after_window(start, len) -> RegSet` for rotate-style live-out checks
- **Delete** `replace_range_at`, `rep_admit_kop_site_window`, `KopAdmissionWindow`
- Migrate every replacing pass to `try_replace_range`:
  - rotate, extract, endian, bulk_memory, ccmp, cond_select (currently `rep_admit_kop_site_window` + `replace_range_at`)
  - wide_mem, prefetch, const_prop, skb_load_bytes, map_inline, bounds_check_merge (currently only `replace_range_at`)
- No new trait, no shared executor. Each pass writes ~10-line uniform reverse-iter loop.
- Expected: -250 to -450 LOC across all 12 mutation-bearing passes

### V2: PassContext deconstruction
- Move map-inline fields to `MapInlineSideInputSpec` consumed by lift
- Move `branch_miss_rate` to BBProgram side-input (`prog.program_branch_miss_rate()`)
- Move `kop_registry`, `platform`, `prog_type` to BBProgram side-input
- Delete `PassContext` (or shrink to opaque platform/policy holder)
- Update `BpfPass::run` signature: drop `ctx` parameter
- Expected: -150 to -250 LOC

### V3: main.rs side-input ingestion to lib
- Create `pub(crate) mod side_input` in lib.rs (or pass.rs)
- Move 1100 LOC of JSON/snapshot parsing
- main.rs becomes thin orchestration (~700 LOC)
- Expected: 0 LOC delta (organization only), but clear ownership

### V4: Quality finish line
- map_inline silent error propagation (#5)
- bulk_memory matcher full migration
- `insn_at`/`insn` unification
- `sites_in_block` returns borrow
- BTF remap dedup
- Skip-reason builder unified
- Expected: -100 to -200 LOC

Total: -450 to -850 LOC additional, getting bpfopt to ~16500 LOC (-13% vs Phase 3 baseline 18994). That's the honest ceiling without deleting features.

## 9. What the ideal preserves

- All 15 passes' behavior (apply count, output bytes, skip semantics) is unchanged.
- All 7 corpus apps still get the same optimizations.
- All paper-grade benchmarks remain reproducible.
- All Phase 3 architectural goals (no PC in passes, no raw verifier types, single mutation path, identity opacity) hold.
- No new files added.
- No feature deleted.

## 10. Acceptance test

After all four V codexes:
- `cargo build --release` clean
- `cargo test --release` — at least 200 tests pass (no regressions vs current 204)
- `cargo clippy --release --all-targets -- -D dead_code -D warnings` clean
- `cargo fmt --all --check` 0 diff
- 542-prog testbin equivalence: apply / matched / skipped / output bytes unchanged
- Full 7-app corpus apply count: matches `docs/evaluation-05-07-2026.md` baseline within noise
- Total production LOC ≤ 16500
- Independent code-review codex returns CONVERGED verdict on goals A-N from `p3_api_contract_2026-05-11.md`
