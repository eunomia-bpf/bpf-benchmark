# P3 Matcher Design: kop-Class Pattern Matchers

Date: 2026-05-11

Scope: read-only architecture audit and API design for the current hand-written
pattern matchers in kop-class replacement passes.

Inspected files:

- `bpfopt/crates/bpfopt/src/passes/rotate.rs`
- `bpfopt/crates/bpfopt/src/passes/extract.rs`
- `bpfopt/crates/bpfopt/src/passes/endian.rs`
- `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs`
- `bpfopt/crates/bpfopt/src/passes/wide_mem.rs`
- `bpfopt/crates/bpfopt/src/passes/cond_select.rs`
- `bpfopt/crates/bpfopt/src/passes/ccmp.rs`
- `bpfopt/crates/bpfopt/src/insn.rs`
- `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs`

## Executive Verdict

A shared matcher API is worthwhile, but only at the mechanical scanning layer.

The current code does **not** support a broad claim that a generic matcher will
remove 50-70% of total matcher logic. It can remove about 45-65% of repeated
walker/scanner scaffolding, but that scaffolding is only part of the audited
matcher code. The realistic total reduction is about 240-400 physical LOC after
adding helper code.

Recommended:

- Add a small `BBProgram` block-body/window scanning API.
- Keep pass-specific semantic matching as ordinary Rust.
- Add only a few generic `BpfInsn` predicates.
- Leave `cond_select` and `ccmp` mostly hand-rolled.

Rejected:

- A declarative instruction-pattern DSL.
- A generic CFG matcher DSL.
- Folding `rep_admit_kop_site_window` into matching.

## Counting Convention

Counts below are physical source lines.

For each pass:

- **Entry LOC** is the primary named matcher function.
- **Cluster LOC** includes the primary matcher plus directly related local
  matcher helpers, cross-block skip probes, and lane/run helpers where those
  helpers are part of recognizing candidate sites.

This separates removable scanner boilerplate from pass-specific optimization
logic.

## Current Shared Primitives

Existing `BBProgram` primitives already provide most raw ingredients:

- `copied_body_insns(block)` clones block body instructions:
  `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:191`.
- `sites_in_block(block)` builds body `InsnSite`s:
  `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:562`.
- `insn_at(site)` fetches body or terminator instructions:
  `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:625`.
- `rep_admit_kop_site_window(start, old_len, replacement_len, skipped)`
  performs replacement admission:
  `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:1684`.

Admission is not pattern matching. It enforces replacement legality and returns
an end site used by passes such as `rotate` for liveness checks:
`bpfopt/crates/bpfopt/src/passes/rotate.rs:93`.

## Current BpfInsn Predicate Surface

Already available:

- Field accessors `code()`, `dst_reg()`, `src_reg()`, `regs()`:
  `bpfopt/crates/bpfopt/src/insn.rs:263`.
- Free decoders `bpf_class`, `bpf_size`, `bpf_mode`, `bpf_op`, `bpf_src`:
  `bpfopt/crates/bpfopt/src/insn.rs:128`.
- `class()`, `is_jmp_class()`, `is_cond_jmp()`, `is_ja()`:
  `bpfopt/crates/bpfopt/src/insn.rs:310`.
- `is_call()`, `is_exit()`, `is_ldimm64()`, `is_ldx_mem()`:
  `bpfopt/crates/bpfopt/src/insn.rs:377`.
- `is_mov64_reg()`, `is_mov64_imm()`, `is_mov32_reg()`,
  `is_mov32_imm()`:
  `bpfopt/crates/bpfopt/src/insn.rs:415`.
- Payload pack/unpack helpers:
  `bpfopt/crates/bpfopt/src/insn.rs:529`.

Repeated direct opcode checks still appear in several passes, for example
`LSH64_IMM`, `OR64_REG`, and `LDX_MEM` plus size checks.

## A. Pass Audit

### rotate.rs

- Pattern entry: `rotate_site_at(insns, idx)` at
  `bpfopt/crates/bpfopt/src/passes/rotate.rs:152`.
- Entry LOC: 9.
- Cluster LOC: 236.
- Counted cluster: `rotate_site_at`, `find_provenance_mov`,
  `is_reg_mov_for_width`, `try_match_rotate`,
  `try_match_split_copy_rotate`, `try_match_split_copy_rotate_width`,
  `try_match_rotate_width`, `rotate_site`.
- Shape: sequential block-body matcher, but not pure fixed-N.
- Window sizes:
  - 3-insn shift/shift/or core.
  - 4-insn replacement when a provenance `MOV` at `idx - 1` is used.
  - 5-insn split-copy form.
- Current widths: `RotateWidth::W32` and `RotateWidth::W64` at
  `bpfopt/crates/bpfopt/src/passes/rotate.rs:177`.
- Captures: `start_idx`, `old_len`, `dst_reg`, `val_reg`, `tmp_reg`,
  `shift_amount`, `width`.
- Predicates/fields:
  - direct `MOV` opcode checks at
    `bpfopt/crates/bpfopt/src/passes/rotate.rs:225`;
  - direct shift/or opcode checks at
    `bpfopt/crates/bpfopt/src/passes/rotate.rs:277` and
    `bpfopt/crates/bpfopt/src/passes/rotate.rs:318`;
  - `dst_reg`, `src_reg`, `imm` at
    `bpfopt/crates/bpfopt/src/passes/rotate.rs:218`,
    `bpfopt/crates/bpfopt/src/passes/rotate.rs:266`,
    `bpfopt/crates/bpfopt/src/passes/rotate.rs:284`.
- State style: straight tuple alternatives plus one backward provenance lookup.
- Shared scanner today: block sites and copied body insns are collected at
  `bpfopt/crates/bpfopt/src/passes/rotate.rs:76`; local `start_idx` maps back
  to `InsnSite` at `bpfopt/crates/bpfopt/src/passes/rotate.rs:83`.
- Non-shared: width policy, shift relation, provenance, temp liveness,
  payload packing.

### extract.rs

- Pattern entry: `extract_site_from_pair(i0, i1)` at
  `bpfopt/crates/bpfopt/src/passes/extract.rs:43`.
- Entry LOC: 16.
- Cluster LOC: 76.
- Counted cluster: pair matcher, in-block pair scan, cross-block skip probe,
  and `next_body_site_in_block`.
- Shape: fixed 2-insn sliding window.
- Pattern: `RSH64_IMM` then `AND64_IMM` on same destination.
- Window size: fixed N = 2.
- Captures: `old_len = 2`, `dst_reg`, `shift_amount`, `bit_len`.
- Predicates/fields:
  - direct opcode checks at `bpfopt/crates/bpfopt/src/passes/extract.rs:44`;
  - destination equality at `bpfopt/crates/bpfopt/src/passes/extract.rs:46`;
  - `imm` shift/mask reads at `bpfopt/crates/bpfopt/src/passes/extract.rs:49`.
- State style: straight tuple match.
- Shared scanner today: `block_sites.windows(2)` at
  `bpfopt/crates/bpfopt/src/passes/extract.rs:77`.
- Non-shared: contiguous-mask calculation, range validation, cross-block skip
  policy, payload packing.

### endian.rs

- Pattern entry: `scan_endian_site_at(prog, start)` at
  `bpfopt/crates/bpfopt/src/passes/endian.rs:53`.
- Entry LOC: 51.
- Cluster LOC: 206.
- Counted cluster: primary scan, endian-size helpers, narrowing-block helpers,
  blocked-site finder, cross-block skip probe, and `next_body_site_in_block`.
- Shape: sequential matcher with fixed adjacent case plus variable forward scan.
- Window sizes:
  - Adjacent load+endian: N = 2.
  - Narrowing scan: variable, bounded by `MAX_NARROW_SCAN = 32` at
    `bpfopt/crates/bpfopt/src/passes/endian.rs:27`.
- Captures: `old_len`, `dst_reg`, `src_reg`, `offset`, `size`.
- Predicates/fields:
  - `is_ldx_mem` at `bpfopt/crates/bpfopt/src/passes/endian.rs:60`;
  - `bpf_size(load.code)` at `bpfopt/crates/bpfopt/src/passes/endian.rs:63`;
  - `dst_reg`, `src_reg`, `off` at
    `bpfopt/crates/bpfopt/src/passes/endian.rs:64` and
    `bpfopt/crates/bpfopt/src/passes/endian.rs:107`;
  - endian opcode and `imm` checks at
    `bpfopt/crates/bpfopt/src/passes/endian.rs:114`;
  - read/write/barrier checks at
    `bpfopt/crates/bpfopt/src/passes/endian.rs:188`.
- State style: hand-rolled scan-until-barrier state machine.
- Shared scanner today: per-start `sites_in_block` loop at
  `bpfopt/crates/bpfopt/src/passes/endian.rs:321`.
- Non-shared: endian decoding, narrowing hazards, preserved instructions,
  architecture-specific replacement length, payload packing.

### bulk_memory.rs

- Pattern entry: `scan_sites(prog)` at
  `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:252`.
- Primary helpers:
  - `try_match_memcpy_run_at` at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:324`;
  - `try_match_memset_run_at` at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:401`;
  - `memcpy_lane_at` at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:454`;
  - `memset_lane_at` at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:480`.
- Cluster LOC: 383.
- Shape: variable-length sequential run matcher.
- Window sizes:
  - Memcpy lane: 2 instructions.
  - Memcpy run: variable pair count.
  - Memset lane: 1 instruction.
  - Memset run: variable store count.
  - Minimum bulk bytes: 32 at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:8`.
  - Max chunk bytes: 128 at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:9`.
- Captures:
  - memcpy: bases, offsets, temp reg, chunk sizes;
  - memset: base, offset, width, fill byte, chunk sizes;
  - common: `old_len`.
- Predicates/fields:
  - `is_ldx_mem`, width checks at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:457`;
  - store class/mode/width at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:461`;
  - `dst_reg`, `src_reg`, `off`, `imm` at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:465`,
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:473`,
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:492`;
  - stack-provenance `class`, `bpf_src`, `bpf_op` at
    `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:710`.
- State style: hand-rolled indexed scanner with `Apply`, `Skip`, `NoMatch`
  outcomes and mutable register state.
- Shared scanner today: copied insns/sites at
  `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:259`; start-site mapping at
  `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:267`.
- Non-shared: aliasing, overlap, temp liveness, register constants, chunking,
  fill-byte decoding, payload packing.

### wide_mem.rs

- Pattern entry: `scan_wide_mem(insns)` at
  `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:30`.
- Primary helpers:
  - `try_match_wide_mem_at` at
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:48`;
  - `match_wide_mem_low_first` at
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:115`;
  - `match_wide_mem_high_first` at
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:159`.
- Cluster LOC: 205.
- Cross-block skip cluster LOC: 74 at
  `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:443`.
- Shape: variable-length byte-load ladder matcher.
- Window sizes:
  - Widths scanned from 8 down to 2 at
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:57`.
  - Low-first length: `1 + 3 * (width - 1)` at
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:58`.
  - High-first length: `3 * width - 2` at
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:83`.
  - Maximum current ladder length: 22 instructions.
- Captures: `start_idx`, `old_len`, bindings for `dst_reg`, `base_reg`,
  `base_off`, `width`.
- Predicates/fields:
  - `is_ldx_mem` and byte width at
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:51`;
  - direct `LSH64_IMM` and `OR64_REG` checks at
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:141` and
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:150`;
  - `dst_reg`, `src_reg`, `off`, `imm` at
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:54`,
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:134`,
    `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:147`.
- State style: deterministic ladder loops, not a simple tuple match.
- Shared scanner today: block sites and copied body insns at
  `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:329`; start index mapping at
  `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:340`.
- Non-shared: high/low ladder semantics, alignment, packet/BTF pointer policy,
  scratch liveness, cross-block skip reporting. This is BPF-to-BPF and does
  not call `rep_admit_kop_site_window`.

### cond_select.rs

- Pattern entry: `scan_cond_select_sites(prog)` at
  `bpfopt/crates/bpfopt/src/passes/cond_select.rs:299`.
- Primary helpers: `try_match_pattern_a` at
  `bpfopt/crates/bpfopt/src/passes/cond_select.rs:331`;
  `try_match_pattern_c` at
  `bpfopt/crates/bpfopt/src/passes/cond_select.rs:381`.
- Matcher cluster LOC: 162.
- Diamond materialization/validation cluster LOC: 92.
- Shape: CFG diamond/partial-diamond matcher.
- Pattern A:
  - conditional branch;
  - taken block has one move;
  - fallthrough block has one move;
  - both branch arms share a join.
- Pattern C:
  - true move is the last body instruction in the branch block;
  - fallthrough block has one false move;
  - false block's successor is the branch's taken target.
- Captures: start/end sites, old length, condition/destination regs, true/false
  values, JCC metadata.
- Predicates/fields:
  - `Terminator::CondBranch` at
    `bpfopt/crates/bpfopt/src/passes/cond_select.rs:302`;
  - `is_cond_jmp` at
    `bpfopt/crates/bpfopt/src/passes/cond_select.rs:336`;
  - `block_single_body_insn` at
    `bpfopt/crates/bpfopt/src/passes/cond_select.rs:339`;
  - mov predicates at
    `bpfopt/crates/bpfopt/src/passes/cond_select.rs:447`;
  - JCC `bpf_op`, `bpf_src`, `code`, `imm`, regs at
    `bpfopt/crates/bpfopt/src/passes/cond_select.rs:373`.
- State style: hand-rolled CFG pattern.
- Non-shared: diamond semantics, value materialization, temp allocation,
  condition lowering, graph replacement.

### ccmp.rs

- Pattern entry: `scan_ccmp_sites(prog)` at
  `bpfopt/crates/bpfopt/src/passes/ccmp.rs:381`.
- Primary helpers: `try_match_ccmp_chain` at
  `bpfopt/crates/bpfopt/src/passes/ccmp.rs:398`;
  `has_same_chain_predecessor` at
  `bpfopt/crates/bpfopt/src/passes/ccmp.rs:438`;
  `branch_term` at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:454`.
- Matcher cluster LOC: 105.
- Chain materialization/validation cluster LOC: 80.
- Shape: CFG same-target zero-test chain matcher.
- Chain constraints:
  - conditional branch terminators;
  - immediate zero tests;
  - same taken target;
  - same fail mode;
  - same width;
  - fallthrough links form the success chain.
- Minimum terms: 2 at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:14`.
- Maximum terms: 4 at `bpfopt/crates/bpfopt/src/passes/ccmp.rs:15`.
- Captures: start site, old length, target block, success block, chain blocks,
  fail mode, width, compare regs.
- Predicates/fields:
  - `Terminator::CondBranch` at
    `bpfopt/crates/bpfopt/src/passes/ccmp.rs:455`;
  - `is_cond_jmp`, `bpf_src`, `imm` at
    `bpfopt/crates/bpfopt/src/passes/ccmp.rs:463`;
  - `bpf_op`, `class`, `dst_reg` at
    `bpfopt/crates/bpfopt/src/passes/ccmp.rs:469`,
    `bpfopt/crates/bpfopt/src/passes/ccmp.rs:472`,
    `bpfopt/crates/bpfopt/src/passes/ccmp.rs:484`.
- State style: hand-rolled CFG chain walk.
- Non-shared: fail-mode decoding, width decoding, dead destination register,
  chain validation/merge, payload encoding.

## B. Common Window-Based Structure

The window/run passes share this skeleton:

1. Iterate blocks.
2. Get body `InsnSite`s.
3. Get body `BpfInsn`s.
4. Iterate start indexes or `windows(N)`.
5. Call pass-local `try_match_*`.
6. Convert local `start_idx` to `InsnSite`.
7. Store an owned site record.
8. Later run admission/safety checks and replace in reverse order.

Evidence:

- `rotate`: sites + copied insns + enumerate:
  `bpfopt/crates/bpfopt/src/passes/rotate.rs:76`.
- `extract`: `block_sites.windows(2)`:
  `bpfopt/crates/bpfopt/src/passes/extract.rs:77`.
- `bulk_memory`: copied insns/sites + indexed while loop:
  `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:259`.
- `wide_mem`: manual `block_insns` construction from `block_sites`:
  `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:329`.

Shared result shape:

- `Option<SiteRecord>` for no-match vs match.
- `Result<Option<SiteRecord>>` where checked conversions or malformed program
  state can fail.
- Owned site records: no borrowed instruction slices should escape the scan.

Not shared:

- Opcode semantics.
- Variable-run termination.
- Liveness.
- Alias checks.
- Cross-block skip policy.
- Payload packing.

## C. Common CFG-Based Structure

`cond_select` and `ccmp` share only shallow CFG traversal:

- Walk blocks.
- Inspect `Terminator::CondBranch`.
- Capture local branch information.
- Follow successors.
- Return an owned CFG-site record.

Evidence:

- `cond_select` builds `CondBranchShape` from a conditional terminator at
  `bpfopt/crates/bpfopt/src/passes/cond_select.rs:299`.
- `ccmp` builds `BranchTerm` from a conditional terminator at
  `bpfopt/crates/bpfopt/src/passes/ccmp.rs:454`.

The graph semantics diverge too much for a shared matcher:

- `cond_select` needs diamonds and body moves.
- `ccmp` needs same-target chains and zero-test normalization.
- Replacements use different graph operations.

## D. Non-Shared Work Per Pass

Rotate:

- Width-specific opcode class.
- Shift relation.
- Previous-move provenance.
- Temporary-register liveness.
- Payload layout.

Extract:

- Contiguous mask detection.
- Extract-range validation.
- Cross-block skip reporting.
- Payload layout.

Endian:

- Endian-op decoding.
- Narrowing semantics.
- Barrier/read/write logic.
- Preserved interior instructions.
- Architecture-specific replacement length.

Bulk memory:

- Memcpy/memset lane decoding.
- Alias/overlap handling.
- Stack-pointer provenance.
- Register-value tracking.
- Chunk-size selection.
- Fill-byte decoding.

Wide mem:

- Low-first and high-first ladder semantics.
- Alignment policy.
- Packet-pointer and BTF-pointer exclusions.
- Scratch-register liveness.
- Cross-block skip reporting.

Cond select:

- Diamond semantics.
- Value materialization.
- Temporary-register allocation.
- Condition lowering.

Ccmp:

- Same-target chain semantics.
- Fail-mode/width decoding.
- Dead destination-register selection.
- Chain merge and final branch rewrite.

## S1. Window Matcher API

Do not build a pattern language. Build a small scanner API.

### Proposed Types

```rust
pub(crate) struct BlockBodyView<'a> {
    pub block: BlockId,
    pub sites: Vec<InsnSite>,
    pub insns: &'a [BpfInsn],
}

pub(crate) struct BlockStartWindow<'a> {
    pub block: BlockId,
    pub start_idx: usize,
    pub start_site: InsnSite,
    pub sites: &'a [InsnSite],
    pub insns: &'a [BpfInsn],
    pub lookahead: &'a [BpfInsn],
}

pub(crate) struct LocalWindowHit<T> {
    pub start_idx: usize,
    pub old_len: usize,
    pub value: T,
}

pub(crate) struct WindowHit<T> {
    pub block: BlockId,
    pub start_idx: usize,
    pub start: InsnSite,
    pub old_len: usize,
    pub value: T,
}
```

`LocalWindowHit.start_idx` is important because `rotate` can scan the 3-insn
shift/or core at one index but replace starting at the previous provenance move.

### Signature 1: Body View

```rust
impl BBProgram {
    pub(crate) fn block_body_view(&self, block: BlockId) -> anyhow::Result<BlockBodyView<'_>>;
}
```

This replaces repeated:

```rust
let block_sites = prog.sites_in_block(block)?;
let block_insns = prog.copied_body_insns(block)?;
```

with:

```rust
let body = prog.block_body_view(block)?;
```

Implementation notes:

- `sites` can be a `Vec<InsnSite>`.
- `insns` should borrow from the block body instead of cloning by default.
- Passes that need owned instructions can clone explicitly.

### Signature 2: Runtime Start Scanner

```rust
impl BBProgram {
    pub(crate) fn scan_block_starts<F, T>(
        &self,
        max_lookahead: usize,
        f: F,
    ) -> anyhow::Result<Vec<WindowHit<T>>>
    where
        F: FnMut(BlockStartWindow<'_>) -> anyhow::Result<Option<LocalWindowHit<T>>>;
}
```

Why runtime `max_lookahead`:

- Handles fixed pairs.
- Handles rotate's previous-start replacement.
- Handles endian and wide_mem variable lengths.
- Avoids const-generic array conversion noise.

### Rotate Sketch

Before, `rotate` performs block iteration, insn collection, and start mapping by
hand at `bpfopt/crates/bpfopt/src/passes/rotate.rs:76`:

```rust
let block_sites = prog.sites_in_block(block)?;
let block_insns = prog.copied_body_insns(block)?;
for (start_idx, _) in block_sites.iter().enumerate() {
    let Some(site) = rotate_site_at(&block_insns, start_idx) else {
        continue;
    };
    let replacement_start = block_sites
        .get(site.start_idx)
        .copied()
        .ok_or_else(|| anyhow::anyhow!("rotate start index {} missing", site.start_idx))?;
    ...
}
```

After:

```rust
let raw_sites = prog.scan_block_starts(5, |w| {
    Ok(rotate_site_at(w.insns, w.start_idx).map(|site| LocalWindowHit {
        start_idx: site.start_idx,
        old_len: site.old_len,
        value: site,
    }))
})?;

for hit in raw_sites {
    let Some(admit) =
        prog.rep_admit_kop_site_window(hit.start, hit.old_len, 2, &mut skipped)?
    else {
        continue;
    };
    ...
}
```

Estimated `rotate.rs` savings:

- 30-45 LOC from scanner/start mapping.
- 10-20 LOC from generic instruction predicates.
- 40-65 LOC total realistic savings.

## S2. CFG Matcher API for cond_select / ccmp

Verdict: leave both mostly hand-rolled.

Possible tiny helper:

```rust
pub(crate) struct CondBranchTerm {
    pub block: BlockId,
    pub site: InsnSite,
    pub cond: BpfInsn,
    pub taken: BlockId,
    pub fallthrough: BlockId,
}

impl BBProgram {
    pub(crate) fn cond_branch_terms(&self) -> anyhow::Result<Vec<CondBranchTerm>>;
}
```

Expected savings:

- `cond_select`: 10-20 LOC.
- `ccmp`: 10-15 LOC.

Do not prioritize this now. `cond_select` and `ccmp` have different graph
semantics, validation, and replacement flows.

## S3. BpfInsn Predicate Set

Add only these:

```rust
impl BpfInsn {
    pub fn is_alu_imm(&self, class: u8, op: u8) -> bool;
    pub fn is_alu_reg(&self, class: u8, op: u8) -> bool;
    pub fn is_ldx_mem_size(&self, size: u8) -> bool;
}
```

Why:

- `rotate`, `extract`, and `wide_mem` repeatedly compare ALU class/op/source.
- `bulk_memory`, `endian`, and `wide_mem` repeatedly test `LDX_MEM` plus size.
- These are generic instruction facts, not pass policy.

Do not add global pass-specific predicates:

- `is_endian_swap_size`
- `is_rotate_pair`
- `is_memcpy_lane`
- `is_select_mov`
- `is_ccmp_zero_test`

## S4. Per-Pass Adoption

### rotate

- Cluster LOC: 236.
- Estimated savings: 40-65 LOC.
- Fits `scan_block_starts`, not a fixed-window-only helper.
- Edge case: replacement start may be before the scanned core.

Before:

```rust
let block_sites = prog.sites_in_block(block)?;
let block_insns = prog.copied_body_insns(block)?;
for (start_idx, _) in block_sites.iter().enumerate() {
    let Some(site) = rotate_site_at(&block_insns, start_idx) else {
        continue;
    };
    let replacement_start = block_sites.get(site.start_idx).copied().ok_or_else(...)?;
}
```

After:

```rust
let raw = prog.scan_block_starts(5, |w| {
    Ok(rotate_site_at(w.insns, w.start_idx).map(|site| LocalWindowHit {
        start_idx: site.start_idx,
        old_len: site.old_len,
        value: site,
    }))
})?;
```

### extract

- Cluster LOC: 76.
- Estimated savings: 35-45 LOC.
- Best fit for fixed N=2.
- Edge case: cross-block skip reporting stays pass-local.

Before:

```rust
let block_sites = prog.sites_in_block(block)?;
for window in block_sites.windows(2) {
    let start = window[0];
    let next = window[1];
    let i0 = prog.insn_at(start).ok_or_else(...)?;
    let i1 = prog.insn_at(next).ok_or_else(...)?;
    let Some(site) = extract_site_from_pair(i0, i1) else { continue; };
}
```

After:

```rust
let raw = prog.scan_block_starts(2, |w| {
    if w.lookahead.len() < 2 {
        return Ok(None);
    }
    Ok(extract_site_from_pair(&w.lookahead[0], &w.lookahead[1]).map(|site| {
        LocalWindowHit {
            start_idx: w.start_idx,
            old_len: site.old_len,
            value: site,
        }
    }))
})?;
```

### endian

- Cluster LOC: 206.
- Estimated savings: 40-70 LOC.
- Fits `scan_block_starts` partially.
- Edge cases: variable scan, preserved instructions, cross-block skip reporting.

Before:

```rust
for start in prog.sites_in_block(block)? {
    if let Some(skip) = cross_block_endian_skip(prog, start)? {
        skipped.push(skip);
        continue;
    }
    let Some(site) = scan_endian_site_at(prog, start)? else { continue; };
}
```

After:

```rust
let raw = prog.scan_block_starts(MAX_NARROW_SCAN + 1, |w| {
    Ok(scan_endian_site_in_block(w.insns, w.sites, w.start_idx)?.map(|site| {
        LocalWindowHit {
            start_idx: w.start_idx,
            old_len: site.old_len,
            value: site,
        }
    }))
})?;
```

### bulk_memory

- Cluster LOC: 383.
- Estimated savings: 45-75 LOC.
- Use `block_body_view`; do not force the state machine into a window callback.
- Edge cases: mutable register state, custom idx advancement, alias/liveness.

Before:

```rust
let insns = prog.copied_body_insns(block)?;
let block_sites = prog.sites_in_block(block)?;
let mut idx = 0usize;
while idx < insns.len() {
    let start = block_sites.get(idx).copied().ok_or_else(...)?;
    match try_match_memcpy_run_at(&insns, &block_sites, idx, &live_out)? {
        ...
    }
}
```

After:

```rust
let body = prog.block_body_view(block)?;
let mut idx = 0usize;
while idx < body.insns.len() {
    let start = body.sites[idx];
    match try_match_memcpy_run_at(body.insns, &body.sites, idx, &live_out)? {
        ...
    }
}
```

### wide_mem

- Cluster LOC: 205 plus 74 cross-block skip LOC.
- Estimated savings: 60-100 LOC.
- Fits `scan_block_starts` for in-block matching.
- Edge cases: BPF-to-BPF replacement, no `rep_admit`, cross-block skip stays
  separate.

Before:

```rust
let block_sites = prog.sites_in_block(block)?;
let block_insns = block_sites
    .iter()
    .map(|&site| prog.insn_at(site).copied().ok_or_else(...))
    .collect::<anyhow::Result<Vec<_>>>()?;
for site in scan_wide_mem(&block_insns) {
    let start_site = block_sites.get(site.start_idx).copied().ok_or_else(...)?;
}
```

After:

```rust
let raw = prog.scan_block_starts(MAX_WIDE_MEM_LEN, |w| {
    Ok(try_match_wide_mem_at(w.insns, w.start_idx).map(|site| LocalWindowHit {
        start_idx: site.start_idx,
        old_len: site.old_len,
        value: site,
    }))
})?;
```

## S5. cond_select and ccmp

### cond_select

Verdict: leave hand-rolled.

Reasons:

- It is a CFG diamond matcher, not a body-window matcher.
- Pattern A and pattern C diverge.
- Replacement uses diamond-specific graph operations:
  `bpfopt/crates/bpfopt/src/passes/cond_select.rs:188`.
- Most remaining complexity is lowering and temp allocation.

Refactor only if adding `cond_branch_terms()` for multiple consumers.

### ccmp

Verdict: leave hand-rolled.

Reasons:

- `branch_term` encodes ccmp-specific zero-test constraints.
- `try_match_ccmp_chain` is already a compact chain loop.
- Validation and merge are transformation-specific.

Refactor only the shallow conditional-branch iteration if more CFG passes appear.

## S6. Risks and Pitfalls

Borrow checker:

- Do not return windows with references into `BBProgram`.
- Scanner callbacks may borrow block data.
- Collected `WindowHit<T>` must store only owned site records, indexes, lengths,
  and `InsnSite`s.

Closure captures:

- Keep global checks outside the scanner when possible.
- First collect raw matches.
- Then run admission, liveness, verifier metadata, and `PassContext` checks.

Const generics vs runtime N:

- Const generics are attractive for `extract`.
- Runtime `max_lookahead` handles every sequential pass.
- Start with runtime N; add fixed-window sugar only after migration proves it.

Admission:

- `rep_admit_kop_site_window` stays as the admission gate.
- It should run after raw pattern matching.
- It records skip reasons and exposes the end site.

Context outside the window:

- Rotate needs backward provenance.
- Bulk memory needs dataflow state.
- Wide mem needs lookback for packet-pointer heuristics.
- Endian needs cross-block skip reporting.
- Therefore the scanner must pass full block `insns` and `sites`, not only the
  narrow `lookahead` slice.

Interior branch targets:

- The default scanner must never cross blocks.
- Cross-block candidates should remain explicit skip/reporting logic.

Error handling:

- Scanner callbacks should return `anyhow::Result<Option<T>>`.
- Do not silently swallow malformed program state.

## S7. Recommended Migration Plan

1. Add `BlockBodyView` and `BBProgram::block_body_view`.
2. Add `BBProgram::scan_block_starts`.
3. Add meaningful boundary tests for empty blocks, truncated lookahead,
   replacement start before scan index, and out-of-range local start.
4. Convert `extract` first.
5. Convert `rotate` second.
6. Convert `wide_mem` in-block matching third; leave cross-block skip logic
   alone.
7. Convert `endian` after `wide_mem`; keep cross-block skip logic separate.
8. Convert `bulk_memory` last and only partially via `block_body_view`.
9. Add generic `BpfInsn` predicates during the first pass conversion that needs
   them.
10. Leave `cond_select` and `ccmp` out of the first migration.

Parallel safety:

- After the shared API lands, different workers can safely edit different pass
  files.
- Avoid concurrent edits to `bbprogram.rs` and `insn.rs`.
- Good split:
  - Worker A: `extract.rs`, `rotate.rs`.
  - Worker B: `wide_mem.rs`.
  - Worker C: `endian.rs`.
  - Worker D: `bulk_memory.rs`.

Estimated gross savings:

- `extract`: 35-45 LOC.
- `rotate`: 40-65 LOC.
- `wide_mem`: 60-100 LOC.
- `endian`: 40-70 LOC.
- `bulk_memory`: 45-75 LOC.
- Optional CFG helper: 20-35 LOC.
- Total pass-file savings: 220-355 LOC without CFG helper, 240-390 with it.

Estimated new helper code:

- `BlockBodyView`: 20-35 LOC.
- `scan_block_starts`: 45-70 LOC.
- Predicate helpers: 15-25 LOC.

Expected net reduction:

- About 150-280 LOC after adding helpers.
- More only if future passes reuse the same scanner.

## S8. Rejection of Broad Matcher DSL

The audit does not justify a broad matcher abstraction that removes 50-70% of
all matcher logic.

Reasons:

- `extract` is the only clean fixed tuple.
- `rotate` has backward provenance and variable replacement start.
- `endian` has barrier scanning and cross-block skip reporting.
- `bulk_memory` is a stateful run matcher with alias/liveness/dataflow logic.
- `wide_mem` is a variable-width ladder with policy-heavy safety checks.
- `cond_select` and `ccmp` are different CFG matchers.

Rejected shape:

```rust
Pattern::new()
    .insn(AluImm { class: BPF_ALU64, op: BPF_RSH })
    .insn(AluImm { class: BPF_ALU64, op: BPF_AND })
    .capture(...);
```

This would help `extract`, but every other pass would need escape hatches.

Recommended final API:

```rust
impl BBProgram {
    pub(crate) fn block_body_view(&self, block: BlockId) -> anyhow::Result<BlockBodyView<'_>>;

    pub(crate) fn scan_block_starts<F, T>(
        &self,
        max_lookahead: usize,
        f: F,
    ) -> anyhow::Result<Vec<WindowHit<T>>>
    where
        F: FnMut(BlockStartWindow<'_>) -> anyhow::Result<Option<LocalWindowHit<T>>>;
}

impl BpfInsn {
    pub fn is_alu_imm(&self, class: u8, op: u8) -> bool;
    pub fn is_alu_reg(&self, class: u8, op: u8) -> bool;
    pub fn is_ldx_mem_size(&self, size: u8) -> bool;
}
```

The right abstraction boundary is mechanical scanning, not semantic matching.
