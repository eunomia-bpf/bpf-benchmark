## Executive Summary

Scope: reviewed the current working-tree contents of `bpfopt/crates/bpfopt/src/` only. I read all 49 `.rs` files under `src/` (`19095` total Rust LOC at review time), including `analysis/`, `passes/`, `pass.rs`, `main.rs`, `insn.rs`, and `verifier_log.rs`.

Validation run:

```text
$ cargo check -p bpfopt --all-targets
Finished `dev` profile [unoptimized + debuginfo] target(s) in 1.07s

$ cargo build -p bpfopt
Finished `dev` profile [unoptimized + debuginfo] target(s) in 1.98s

$ find bpfopt/crates/bpfopt/src -name '*.rs' | sort | wc -l
49
```

Found 7 concrete cleanup findings. The low-risk deletions are small, but they remove repeated names and false API surface. Estimated net deletion: about 45-75 LOC if only the concrete items are addressed; more if the BBProgram mutation wrappers are consolidated aggressively.

Explicitly not suggested for removal: `MapInlineHintMode::Soft`, bpftool snapshot JSON parsing, and map-in-map hint parsing. Those paths were reviewed but kept out of cleanup recommendations per the constraints.

## Findings

### 1. BBProgram mutation APIs have repeated transactional wrapper / private single-caller pairs

- 标题: seven public mutation methods only clone/commit around a private `_in_place` method
- 位置: `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:20`, `:27`, `:165`, `:172`, `:193`, `:204`, `:221`, `:228`, `:266`, `:273`, `:400`, `:407`, `:462`, `:473`
- 现状:

```rust
pub fn delete_insn(&mut self, site: DefSite) -> anyhow::Result<usize> {
    let mut next = self.clone();
    let removed_slots = next.delete_insn_in_place(site)?;
    *self = next;
    Ok(removed_slots)
}

fn delete_insn_in_place(&mut self, site: DefSite) -> anyhow::Result<usize> {
```

The same pattern repeats for `delete_cond_branch`, `replace_terminator`, `permute_blocks`, `merge_linear_chain`, `split_block`, and `replace_diamond_with_insns`.

- 问题: the rollback-on-error behavior is valuable, but the current shape creates two method names for every mutation. The `_in_place` methods are not an independent API; they exist only so the public method can call one private method after cloning.
- 证据:

```text
$ rg -n "fn (delete_insn|delete_insn_in_place|delete_cond_branch|delete_cond_branch_in_place|replace_terminator|replace_terminator_in_place|permute_blocks|permute_blocks_in_place|merge_linear_chain|merge_linear_chain_in_place|split_block|split_block_in_place|replace_diamond_with_insns|replace_diamond_with_insns_in_place)\b|\.(delete_insn|delete_cond_branch|replace_terminator|permute_blocks|merge_linear_chain|split_block|replace_diamond_with_insns)\(" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:20:    pub fn delete_insn(&mut self, site: DefSite) -> anyhow::Result<usize> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:27:    fn delete_insn_in_place(&mut self, site: DefSite) -> anyhow::Result<usize> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:165:    pub fn delete_cond_branch(&mut self, block: BlockId) -> anyhow::Result<()> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:172:    fn delete_cond_branch_in_place(&mut self, block: BlockId) -> anyhow::Result<()> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:193:    pub fn replace_terminator(
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:204:    fn replace_terminator_in_place(
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:221:    pub fn permute_blocks(&mut self, new_order: &[BlockId]) -> anyhow::Result<()> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:228:    fn permute_blocks_in_place(&mut self, new_order: &[BlockId]) -> anyhow::Result<()> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:266:    pub fn merge_linear_chain(&mut self, chain: &[BlockId]) -> anyhow::Result<BlockId> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:273:    fn merge_linear_chain_in_place(&mut self, chain: &[BlockId]) -> anyhow::Result<BlockId> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:400:    pub fn split_block(&mut self, at: InsnSite) -> anyhow::Result<(BlockId, BlockId)> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:407:    fn split_block_in_place(&mut self, at: InsnSite) -> anyhow::Result<(BlockId, BlockId)> {
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:462:    pub fn replace_diamond_with_insns(
bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:473:    fn replace_diamond_with_insns_in_place(
```

The `_in_place` names do not appear as callers outside their public wrapper pair.

- 建议: preserve all rollback semantics, but collapse the double API. The least invasive option is to inline each `_in_place` body into its public method, operating on `next` and committing at the end. If avoiding repeated clone/commit is preferred, add one private transaction helper and keep only public mutation method names.
- 预估 LOC: 20-35 LOC deletion if using one transaction helper; smaller but clearer if directly inlining.
- 风险: medium. These methods remap BTF metadata, rebuild CFG/use-def state, and preserve rollback behavior on error. Regression coverage should include `bbprogram_*_tests`, `pass_tests`, `bounds_check_merge_tests`, `branch_flip_tests`, `ccmp_tests`, and `cond_select_tests`.

### 2. `MapInfoBySite` is a public alias for a file-local map

- 标题: public type alias expands API surface without hiding meaningful structure
- 位置: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:3467`
- 现状:

```rust
pub type MapInfoBySite = HashMap<InsnSite, MapInfo>;

fn analyze_map_info(
    program: &BBProgram,
    side_input: &MapInlineSideInput<'_>,
) -> Result<MapInfoBySite> {
```

- 问题: all uses are inside `map_inline.rs`; the alias is not a cross-module contract. Making it `pub` advertises an API that has no external caller and hides that the structure is just `HashMap<InsnSite, MapInfo>`.
- 证据:

```text
$ rg -n "MapInfoBySite" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/passes/map_inline.rs:505:    map_info: &MapInfoBySite,
bpfopt/crates/bpfopt/src/passes/map_inline.rs:595:    map_info: &MapInfoBySite,
bpfopt/crates/bpfopt/src/passes/map_inline.rs:630:    map_info: &MapInfoBySite,
bpfopt/crates/bpfopt/src/passes/map_inline.rs:702:    map_info: &MapInfoBySite,
bpfopt/crates/bpfopt/src/passes/map_inline.rs:773:    map_info: &MapInfoBySite,
bpfopt/crates/bpfopt/src/passes/map_inline.rs:855:    map_info: &'a MapInfoBySite,
bpfopt/crates/bpfopt/src/passes/map_inline.rs:3467:pub type MapInfoBySite = HashMap<InsnSite, MapInfo>;
bpfopt/crates/bpfopt/src/passes/map_inline.rs:3472:) -> Result<MapInfoBySite> {
bpfopt/crates/bpfopt/src/passes/map_inline.rs:3530:fn unique_maps(map_info: &MapInfoBySite) -> Vec<MapInfo> {
```

- 建议: make it private (`type MapInfoBySite = ...`) at minimum. If the alias does not improve readability after that, inline `HashMap<InsnSite, MapInfo>` in the handful of signatures.
- 预估 LOC: 0-1 LOC deletion; main value is API cleanup.
- 风险: low. A build will catch any hidden external use, and current grep shows none under `src/`.

### 3. `AppliedRewriteSite` is a one-use tuple alias

- 标题: single-use type alias names a tuple that is only used in one field
- 位置: `bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:16`
- 现状:

```rust
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct RewriteSite {
    offset: i32,
    len: i32,
}

type AppliedRewriteSite = (InsnSite, RewriteSite);

#[derive(Default)]
struct ScanResult {
    sites: Vec<AppliedRewriteSite>,
```

- 问题: the alias is local and only used once. It adds an extra name without giving field names or a stronger type boundary.
- 证据:

```text
$ rg -n "AppliedRewriteSite" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:16:type AppliedRewriteSite = (InsnSite, RewriteSite);
bpfopt/crates/bpfopt/src/passes/skb_load_bytes.rs:20:    sites: Vec<AppliedRewriteSite>,
```

- 建议: replace `Vec<AppliedRewriteSite>` with `Vec<(InsnSite, RewriteSite)>`, or introduce a real struct only if the two fields need names.
- 预估 LOC: 1 LOC deletion.
- 风险: very low. This is compile-time-only cleanup.

### 4. BPF memory-width helpers duplicate `BpfMemWidth` conversions

- 标题: pass-local helpers wrap `BpfMemWidth::from_size_opcode` and `.bytes()`
- 位置: `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:507`, `:510`, `:515`; `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2242`
- 现状:

```rust
fn is_supported_width(width: u8) -> bool {
    BpfMemWidth::from_size_opcode(width).is_some()
}
fn width_bytes(width: u8) -> anyhow::Result<usize> {
    Ok(BpfMemWidth::from_size_opcode(width)
        .ok_or_else(|| anyhow::anyhow!("bulk_memory unsupported width opcode {width:#x}"))?
        .bytes())
}
fn width_class(width: u8) -> anyhow::Result<u8> {
```

And in `map_inline.rs`:

```rust
fn size_in_bytes(size: u8) -> Option<u8> {
    BpfMemWidth::from_size_opcode(size).map(|w| w.bytes() as u8)
}
```

- 问题: there is already a central `BpfMemWidth` abstraction in `insn.rs`. The pass-local wrappers create multiple names for the same conversion and make readers check whether each helper has special semantics. It does not.
- 证据:

```text
$ rg -n "is_supported_width\(|width_bytes\(|width_class\(|size_in_bytes\(|BpfMemWidth::from_size_opcode" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:173:    let lane_bytes = width_bytes(first.width)?;
bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:296:    if !is_supported_width(width) || !load.is_ldx_mem_size(width) {
bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:440:        | BpfInsn::pack_u4(width_class(width)?, 32)
bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:507:fn is_supported_width(width: u8) -> bool {
bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:510:fn width_bytes(width: u8) -> anyhow::Result<usize> {
bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:515:fn width_class(width: u8) -> anyhow::Result<u8> {
bpfopt/crates/bpfopt/src/passes/endian.rs:94:    let load = BpfMemWidth::from_size_opcode(load_size);
bpfopt/crates/bpfopt/src/passes/map_inline.rs:1943:                let size = match size_in_bytes(bpf_size(insn.code)) {
bpfopt/crates/bpfopt/src/passes/map_inline.rs:2242:fn size_in_bytes(size: u8) -> Option<u8> {
```

- 建议: in `bulk_memory.rs`, keep at most one local helper returning `anyhow::Result<BpfMemWidth>` with the pass-specific error message, then use `.bytes()` or `as u8` at call sites. In `map_inline.rs`, inline `BpfMemWidth::from_size_opcode(...).map(|w| w.bytes() as u8)` or reuse the enum value directly where possible.
- 预估 LOC: 8-15 LOC deletion.
- 风险: low. Main risk is changed wording for exact diagnostic assertions if any exist; `cargo test -p bpfopt bulk_memory map_inline` would catch behavior regressions.

### 5. Hex byte rendering is implemented twice

- 标题: `map_inline` manually formats bytes even though `pass.rs` already has `hex_bytes`
- 位置: `bpfopt/crates/bpfopt/src/pass.rs:296`; `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2352`
- 现状:

```rust
pub fn hex_bytes(bytes: &[u8]) -> String {
    const HEX: &[u8; 16] = b"0123456789abcdef";
    let mut out = String::with_capacity(bytes.len() * 2);
    for byte in bytes {
        out.push(HEX[(byte >> 4) as usize] as char);
        out.push(HEX[(byte & 0x0f) as usize] as char);
    }
    out
}
```

```rust
fn format_bytes_preview(bytes: &[u8]) -> String {
    let preview_len = bytes.len().min(VALUE_PREVIEW_BYTES);
    let mut out = String::with_capacity(preview_len.saturating_mul(2) + 6);
    out.push_str("0x");
    for byte in &bytes[..preview_len] {
        out.push_str(&format!("{byte:02x}"));
```

- 问题: `format_bytes_preview` needs prefix/truncation behavior, but its inner hex loop duplicates `hex_bytes` and allocates through `format!` for each byte.
- 证据:

```text
$ rg -n "format_bytes_preview\(|hex_bytes\(|format!\(\"\{byte:02x\}\"" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/pass.rs:296:pub fn hex_bytes(bytes: &[u8]) -> String {
bpfopt/crates/bpfopt/src/main.rs:625:        key_hex: hex_bytes(&record.key),
bpfopt/crates/bpfopt/src/passes/map_inline.rs:2352:fn format_bytes_preview(bytes: &[u8]) -> String {
bpfopt/crates/bpfopt/src/passes/map_inline.rs:2357:        out.push_str(&format!("{byte:02x}"));
```

- 建议: implement `format_bytes_preview` as `let mut out = format!("0x{}", hex_bytes(&bytes[..preview_len]));` or push `"0x"` plus `hex_bytes` output. Keep the existing truncation suffix.
- 预估 LOC: 3-6 LOC deletion and fewer small formatting allocations.
- 风险: low. Only diagnostic strings should change if there is a subtle formatting difference; expected output is still lowercase hex.

### 6. `BpfInsn::new_raw` is a private thin wrapper target

- 标题: `new()` only delegates to `new_raw()`, and `from_raw_bytes()` can call `new()` directly
- 位置: `bpfopt/crates/bpfopt/src/insn.rs:280`, `:284`, `:331`
- 现状:

```rust
#[inline]
pub fn new(code: u8, regs: u8, off: i16, imm: i32) -> Self {
    Self::new_raw(code, regs, off, imm)
}
#[inline]
fn new_raw(code: u8, regs: u8, off: i16, imm: i32) -> Self {
    let mut inner = libbpf_sys::bpf_insn {
        code,
```

```rust
#[inline]
pub fn from_raw_bytes(bytes: [u8; 8]) -> Self {
    Self::new_raw(
        bytes[0],
        bytes[1],
```

- 问题: `new_raw` does not preserve a separate invariant. It is private, has no caller except `new` and `from_raw_bytes`, and `from_raw_bytes` is already constructing the same four arguments.
- 证据:

```text
$ rg -n "fn new_raw|new_raw\(" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/insn.rs:281:        Self::new_raw(code, regs, off, imm)
bpfopt/crates/bpfopt/src/insn.rs:284:    fn new_raw(code: u8, regs: u8, off: i16, imm: i32) -> Self {
bpfopt/crates/bpfopt/src/insn.rs:332:        Self::new_raw(
```

- 建议: move the `libbpf_sys::bpf_insn` construction into `pub fn new`, delete `new_raw`, and have `from_raw_bytes` call `Self::new(...)`.
- 预估 LOC: 3-5 LOC deletion.
- 风险: very low. The ABI/raw byte test around `as_kernel()` and `raw_bytes()` should catch any field-packing regression.

### 7. Two `insn.rs` definitions have zero callers

- 标题: `BPF_PSEUDO_KFUNC_CALL` and `BpfMemWidth::ALL` are defined but unused
- 位置: `bpfopt/crates/bpfopt/src/insn.rs:64`, `:96`
- 现状:

```rust
pub const BPF_PSEUDO_CALL: u8 = libbpf_sys::BPF_PSEUDO_CALL as u8;
#[cfg(test)]
pub const BPF_PSEUDO_KFUNC_CALL: u8 = libbpf_sys::BPF_PSEUDO_KFUNC_CALL as u8;
pub const BPF_PSEUDO_KINSN_SIDECAR: u8 = 3;
```

```rust
impl BpfMemWidth {
    pub const ALL: [Self; 4] = [Self::B, Self::H, Self::W, Self::DW];

    pub fn from_size_opcode(size: u8) -> Option<Self> {
```

- 问题: both names are current dead code. `BPF_PSEUDO_KFUNC_CALL` is even test-only, but no test uses it. `BpfMemWidth::ALL` looks like a useful iterator source, but current passes use explicit conversions instead.
- 证据:

```text
$ rg -n "BPF_PSEUDO_KFUNC_CALL|BpfMemWidth::ALL|ALL:" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/insn.rs:64:pub const BPF_PSEUDO_KFUNC_CALL: u8 = libbpf_sys::BPF_PSEUDO_KFUNC_CALL as u8;
bpfopt/crates/bpfopt/src/insn.rs:96:    pub const ALL: [Self; 4] = [Self::B, Self::H, Self::W, Self::DW];
```

- 建议: delete both definitions unless an immediate new caller is added.
- 预估 LOC: 2-3 LOC deletion.
- 风险: very low. This is confirmed by grep and protected by build.

## Verified Dead Code

Confirmed 0-caller items under `bpfopt/crates/bpfopt/src/`:

1. `bpfopt/crates/bpfopt/src/insn.rs:64` - `BPF_PSEUDO_KFUNC_CALL`
2. `bpfopt/crates/bpfopt/src/insn.rs:96` - `BpfMemWidth::ALL`

The exact verification command was:

```text
$ rg -n "BPF_PSEUDO_KFUNC_CALL|BpfMemWidth::ALL|ALL:" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/insn.rs:64:pub const BPF_PSEUDO_KFUNC_CALL: u8 = libbpf_sys::BPF_PSEUDO_KFUNC_CALL as u8;
bpfopt/crates/bpfopt/src/insn.rs:96:    pub const ALL: [Self; 4] = [Self::B, Self::H, Self::W, Self::DW];
```

I did not classify `BranchProfile.branch_misses`, `PrefetchProfile.cache_references`, or `PrefetchProfile.miss_rate` as verified dead code because they may be part of external profile schema or policy validation, even though current production reads are absent or limited.

## Risky / 需进一步审查的

### A. PMU profile fields are written but not all read

- 位置: `bpfopt/crates/bpfopt/src/pass.rs:88-103`, `bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:441-454`, `bpfopt/crates/bpfopt/src/passes/prefetch.rs:116-129`
- 可疑点: `BranchProfile.branch_misses`, `PrefetchProfile.cache_references`, and `PrefetchProfile.miss_rate` have no direct production read in the current grep result. `BranchProfile.miss_rate`, `taken_count`, `not_taken_count`, `branch_count`, `PrefetchProfile.execution_count`, and `cache_misses` are read.
- 证据:

```text
$ rg -n "branch_misses|cache_references|\.miss_rate|execution_count|cache_misses" bpfopt/crates/bpfopt/src
bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:441:            .miss_rate;
bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:450:        let execution_count = record
bpfopt/crates/bpfopt/src/analysis/bbprogram.rs:453:            .map(|profile| profile.execution_count);
bpfopt/crates/bpfopt/src/pass.rs:90:    pub branch_misses: u64,
bpfopt/crates/bpfopt/src/pass.rs:100:    pub cache_references: u64,
bpfopt/crates/bpfopt/src/pass.rs:101:    pub cache_misses: u64,
bpfopt/crates/bpfopt/src/passes/prefetch.rs:116:    if profile_hint.cache_misses == 0 {
```

- 为什么不直接建议删: branch flip policy requires real per-site PMU fields including `branch_misses`, so deleting it could violate the benchmark contract even if the optimizer currently derives decisions from `miss_rate`. Safer next step is to validate required PMU fields at parse/admission time or document which fields are schema-only.

### B. `SiteRewriteResult<T>` hides control flow in nested `Result`

- 位置: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:470`, `:1685`, `:1786`, `:1841`, `:2184`
- 现状:

```rust
type SiteRewriteResult<T> = anyhow::Result<std::result::Result<T, String>>;

fn site_level_inline_veto<T>(reason: impl Into<String>) -> SiteRewriteResult<T> {
    Ok(Err(reason.into()))
}
```

- 证据:

```text
$ rg -n "fn site_level_inline_veto|type SiteRewriteResult|SiteRewriteResult<|Ok\(Err\(" bpfopt/crates/bpfopt/src/passes/map_inline.rs
470:type SiteRewriteResult<T> = anyhow::Result<std::result::Result<T, String>>;
1685:) -> SiteRewriteResult<Option<SiteRewrite>> {
1786:) -> SiteRewriteResult<SiteRewrite> {
1841:) -> SiteRewriteResult<u32> {
2184:fn site_level_inline_veto<T>(reason: impl Into<String>) -> SiteRewriteResult<T> {
```

- 为什么不列为确定 cleanup: this is inside core `map_inline` logic, and replacing it with an enum such as `InlineDecision<T>` may improve readability but may not reduce LOC. It is worth a focused map-inline-only review, not a drive-by cleanup.
