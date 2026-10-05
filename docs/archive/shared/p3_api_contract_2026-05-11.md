# BBProgram API Contract — Phase 3 Convergence (2026-05-11)

Authoritative API surface for bpfopt passes. All 3 parallel codex jobs (API + 2× passes) refer to this document. Workflow rule: **DELETE first, MIGRATE second**. No coexisting old+new API. Build may break between codex jobs; that is acceptable. Final consolidator + review will verify convergence.

## Core principle

> Passes read IR freely via std iterators; passes mutate IR only through BBProgram mutation API.

Identity types (`BlockId`, `InsnSite`, `FrameId`) are opaque to passes. Internal fields `pub(crate)`. Passes never construct identity from raw integers and never do arithmetic on them. They obtain identities from BBProgram enumeration methods and pass them back to BBProgram.

## What gets DELETED (no replacement, or replaced as noted)

### 1. Whole file deletion
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_helpers.rs` — file removed
- `bpfopt/crates/bpfopt/src/analysis/mod.rs` — `mod bbprogram_helpers` and any `pub(crate) use bbprogram_helpers::*` lines removed
- Helper contents redistributed:
  - `program_sites(prog)` → `BBProgram::all_sites()` inherent method
  - `control_flow_target_sites(prog)` → `BBProgram::branch_target_entry_sites()` inherent method
  - `packet_ctx_layout` + `PacketCtxLayout` + `PacketCtxLayoutScope` → moved into `bpfopt/crates/bpfopt/src/insn.rs`
  - `SimpleRegValue` trait + `advance_reg_state` + `advance_alu64_state` + `advance_alu32_state` → moved into `bpfopt/crates/bpfopt/src/insn.rs`
  - `read_json_file<T>(path, label)` → moved into `bpfopt/crates/bpfopt/src/main.rs` as a private fn. Passes that previously read JSON must instead consume side-input metadata already attached to BBProgram at lift time.

### 2. Public API deleted (or made `pub(crate)`)

| Item | New visibility | Notes |
|------|---------------|-------|
| `BBProgram::oracle()` | `pub(crate)` | Passes can no longer get the whole verifier map |
| `BBProgram::oracle_at(site)` | **DELETED** entirely (was `pub`) | No raw `VerifierInsn` access from passes |
| `BBProgram::verifier_states_at(site)` | already `pub(crate)` — keep | Internal use only |
| `BBProgram::profile_at(site)` | **DELETED** entirely (was `pub`) | No raw `PmuRecord` access from passes |
| `BBProgram::site_current_pc(site)` | `pub(crate)` | Only `PassManager::finalize_reports` calls it |
| `BBProgram::block_start_pc(block)` | `pub(crate)` | Only lower/main use it |
| `BBProgram::original_pc(site)` | `pub(crate)` | Only lift uses it |
| `BBProgram::original_pc_to_site(pc)` | `pub(crate)` | Only lift uses it |
| `BBProgram::block_slot_len(block)` | **DELETED** entirely | Slot is internal; use `block_body_len` or `sites_in_block().len()` |
| `BBProgram::block_slot_bounds(block)` | **DELETED** | Same |
| `BBProgram::block_range_for_slots(...)` | **DELETED** | Same |
| `BBProgram::site_for_block_slot(block, slot)` | **DELETED** | Passes never need raw slot indexing |
| `BBProgram::frame_relative_slot(block, slot)` | **DELETED** | Same |
| `BBProgram::frame_slot_bounds(frame)` | **DELETED** | Same |
| `BBProgram::program_slot_len()` | **DELETED** | Same |
| `BBProgram::remap_block_after_insert(...)` | `pub(crate)` | Internal mutation primitive only |
| `BBProgram::remap_block_after_remove(...)` | `pub(crate)` | Same |
| `BBProgram::attach_side_inputs(...)` | `pub(crate)` | Lifecycle, lift only |
| `BBProgram::reset_btf_to_current_pcs()` | `pub(crate)` | Lifecycle, lower only |
| `BBProgram::invalidate_oracle()` | already `pub(crate)` — keep | |
| `BBProgram::rebuild_use_def_after_mutation()` | already `pub(crate)` — keep | |
| `BBProgram::attach_prefetch_profile_from_original_pcs(...)` | already `pub(crate)` — keep | |
| `BBProgram::attach_profile_data(...)` | already `pub(crate)` — keep | |
| `BBProgram::raw_insn()` on something | check; if leaks `BpfInsn` reference at slot level, audit | |
| `BBProgram::insn_slot_width(site)` | `pub(crate)` | Width is internal; passes already get `&BpfInsn` via `insn_at` |
| `BBProgram::is_terminator_site(site)` | **keep** `pub` | Useful structural query |
| `BBProgram::replace_range(block, Range<usize>, ...)` | **DELETED** entirely | Replaced by `replace_range_at(site, len, ...)` |

### 3. Identity field visibility

| Field | Old | New |
|-------|-----|-----|
| `BlockId.0` (`pub usize`) | `pub` | `pub(crate)` |
| `InsnSite.block` | `pub` | `pub(crate)` |
| `InsnSite.idx` | `pub` | `pub(crate)` |
| `FrameId.0` (`pub usize`) | `pub` | `pub(crate)` |

After this, passes cannot do `BlockId(0)`, `site.idx + 1`, or `InsnSite { block, idx }` construction.

### 4. Pass-facing data type visibility

| Type | New visibility |
|------|---------------|
| `VerifierInsn` | `pub(crate)` |
| `VerifierOracle` (the `BTreeMap<InsnSite, ...>`) | `pub(crate)` |
| `PmuRecord` | `pub(crate)` |
| `PrefetchProfile` | `pub(crate)` |
| `BtfMetadataMap` | `pub(crate)` |

## What gets ADDED (passes' new toolkit)

### A. BBProgram inherent methods — query

```rust
impl BBProgram {
    // Iteration over all sites in deterministic block order.
    pub fn all_sites(&self) -> impl Iterator<Item = InsnSite> + '_;

    // CFG branch / call target entry sites (replaces control_flow_target_sites).
    pub fn branch_target_entry_sites(&self) -> anyhow::Result<std::collections::BTreeSet<InsnSite>>;

    // -- Typed verifier queries (replace oracle_at). --
    // Passes never see VerifierInsn; they ask narrow facts.
    pub fn reg_known_constant(&self, site: InsnSite, reg: u8) -> Option<i64>;
    pub fn reg_known_map_ptr(&self, site: InsnSite, reg: u8) -> Option<MapPtr>;
    pub fn reg_proven_bounds(&self, site: InsnSite, reg: u8) -> Option<(i64, i64)>;
    pub fn reg_kind(&self, site: InsnSite, reg: u8) -> Option<RegKind>;
    pub fn site_is_dead_code(&self, site: InsnSite) -> bool;

    // -- Typed profile queries (replace profile_at). --
    pub fn branch_taken_rate(&self, site: InsnSite) -> Option<f32>;
    pub fn branch_miss_rate(&self, site: InsnSite) -> Option<f32>;
    pub fn site_hotness(&self, site: InsnSite) -> Option<u64>;
    pub fn prefetch_hint(&self, site: InsnSite) -> Option<PrefetchHint>;
}
```

Define `MapPtr`, `RegKind`, `PrefetchHint` as opaque or simply-typed structs in `pass.rs` or `analysis/mod.rs` (no raw verifier struct fields exposed).

### B. BBProgram inherent methods — mutation

```rust
impl BBProgram {
    /// Replace `len` consecutive insns starting at `site` with `replacement`.
    /// Atomic clone-swap; rebuilds CFG edges, use-def graph, and InsnSite-keyed metadata internally.
    pub fn replace_range_at(
        &mut self,
        site: InsnSite,
        len: usize,
        replacement: Vec<BpfInsn>,
    ) -> anyhow::Result<()>;
}
```

All existing CFG mutation methods stay public (`replace_terminator`, `delete_cond_branch`, `split_block`, `merge_linear_chain`, `permute_blocks`, `delete_unreachable_blocks`, `replace_diamond_with_insns`, `delete_insn`).

### C. Pass report boundary

```rust
// In pass.rs:

pub struct PassReportSite {
    pub site: InsnSite,    // pass-side report record
    pub action: PassAction,
    // ...
}

pub struct PassReportPc {
    pub pc: u64,           // serialized JSON record
    pub action: PassAction,
    // ...
}

impl PassManager {
    /// Single boundary where InsnSite → PC happens. Calls `prog.site_current_pc(site)`.
    pub fn finalize_reports(
        reports: Vec<PassReportSite>,
        prog: &BBProgram,
    ) -> anyhow::Result<Vec<PassReportPc>>;
}
```

`main.rs` calls `PassManager::finalize_reports(...)` and serializes the `PassReportPc` vector to JSON. `main.rs` does NOT call `site_current_pc` directly.

## Workflow rules for each codex job

**EVERY codex job follows DELETE → MIGRATE order:**

1. **DELETE phase**: remove old API, old fields, old visibility, old helpers. Do not worry about compile errors — leaving the tree broken is acceptable.
2. **MIGRATE phase**: introduce replacements (new methods, new fields, new types).

After all 3 codex jobs return, Claude (or final consolidator codex) reconciles the tree, runs all gates.

## Forbidden patterns in passes/*.rs after migration

These greps MUST be zero matches:

```
rg "VerifierInsn|PmuRecord|PrefetchProfile|VerifierOracle"      bpfopt/crates/bpfopt/src/passes/
rg "oracle_at\b|profile_at\b|oracle\(\)"                         bpfopt/crates/bpfopt/src/passes/
rg "site_current_pc\b|site_pc\b|block_start_pc\b|original_pc\b"  bpfopt/crates/bpfopt/src/passes/
rg "block_slot_|frame_relative_slot|program_slot_len|site_for_block_slot|block_range_for_slots" bpfopt/crates/bpfopt/src/passes/
rg "replace_range\b"                                             bpfopt/crates/bpfopt/src/passes/   # only replace_range_at allowed
rg "block_body_len\b"                                            bpfopt/crates/bpfopt/src/passes/   # use sites_in_block().len() instead
rg "InsnSite\s*\{"                                               bpfopt/crates/bpfopt/src/passes/   # no direct construction
rg "BlockId\(\d|FrameId\(\d"                                     bpfopt/crates/bpfopt/src/passes/   # no integer constructor
rg "\.idx\s*[+\-]"                                               bpfopt/crates/bpfopt/src/passes/   # no idx arithmetic
rg "\b(\w+_slot|\w+_pc|\w+_offset|\w+_position|\w+_pos|pos_in_prog|prog_offset)\s*:\s*usize" bpfopt/crates/bpfopt/src/passes/   # no renamed-PC fields
rg "bbprogram_helpers"                                           bpfopt/crates/bpfopt/src/
rg "read_json_file"                                              bpfopt/crates/bpfopt/src/passes/
```

If any of these match, the migration is incomplete.

## Gates (final consolidator + review)

```
cd bpfopt && cargo build --release                                                     # 0 exit
cd bpfopt && cargo test --release                                                      # 0 exit, ≥ 217 tests
cd bpfopt && cargo clippy --release --all-targets -- -D dead_code -D warnings           # 0 exit
cd bpfopt && cargo fmt --all && cargo fmt --all --check                                # 0 exit (no diff)
542-prog testbin equivalence test                                                       # 0 divergence
```

Net LOC: production source (`bpfopt/crates/bpfopt/src/` excluding `*_tests.rs`) must be strictly less than 18994 (the pre-Phase-3 baseline before today's work).
