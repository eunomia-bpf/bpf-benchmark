// SPDX-License-Identifier: MIT
use crate::analysis::{
    advance_reg_state as advance_simple_reg_state, insn_use_def_set, BBProgram, BlockId, InsnSite,
    SimpleRegValue,
};
use crate::insn::*;
use crate::pass::*;
use std::collections::{HashMap, HashSet};
use std::ops::Range;
const MEMCPY_TARGET: &str = "bpf_bulk_memcpy";
const MEMSET_TARGET: &str = "bpf_bulk_memset";
const MIN_BULK_BYTES: usize = 32;
const CHUNK_MAX_BYTES: usize = 128;
const STACK_PTR_REG: u8 = 10;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        canonical_name: MEMCPY_TARGET,
        aliases: &["bulk_memcpy", "bpf_memcpy_bulk", "memcpy_bulk"],
        decode_proof: decode_memcpy_bulk_proof,
        register_uses: memcpy_bulk_register_uses,
    },
    KinsnDescriptor {
        canonical_name: MEMSET_TARGET,
        aliases: &["bulk_memset", "bpf_memset_bulk", "memset_bulk"],
        decode_proof: decode_memset_bulk_proof,
        register_uses: memset_bulk_register_uses,
    },
];
fn decode_memcpy_bulk_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(memcpy_bulk_proof_len))
}
fn decode_memset_bulk_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(memset_bulk_proof_len))
}
fn bulk_offset_range_valid(offset: i16, len: usize) -> bool {
    let end = i32::from(offset) + len as i32 - 1;
    end >= i32::from(i16::MIN) && end <= i32::from(i16::MAX)
}
fn memcpy_bulk_proof_len(payload: u64) -> anyhow::Result<usize> {
    let dst_base = kinsn_payload_reg(payload, 0);
    let src_base = kinsn_payload_reg(payload, 4);
    let dst_off = kinsn_payload_s16(payload, 8);
    let src_off = kinsn_payload_s16(payload, 24);
    let len = usize::from(kinsn_payload_u8(payload, 40)) + 1;
    let tmp_reg = kinsn_payload_reg(payload, 48);
    if payload >> 52 != 0 {
        anyhow::bail!("memcpy bulk payload has non-zero reserved bits");
    }
    if len == 0 || len > 128 {
        anyhow::bail!("memcpy bulk length {len} is outside 1..128");
    }
    validate_bpf_reg("memcpy bulk dst", dst_base)?;
    validate_bpf_reg("memcpy bulk src", src_base)?;
    validate_bpf_reg("memcpy bulk tmp", tmp_reg)?;
    if tmp_reg == BPF_REG_10 || tmp_reg == dst_base || tmp_reg == src_base {
        anyhow::bail!("memcpy bulk tmp register aliases an invalid operand");
    }
    if !bulk_offset_range_valid(dst_off, len) || !bulk_offset_range_valid(src_off, len) {
        anyhow::bail!("memcpy bulk offset range is outside s16");
    }
    Ok(len * 2)
}
fn memset_bulk_proof_len(payload: u64) -> anyhow::Result<usize> {
    let dst_base = kinsn_payload_reg(payload, 0);
    let val_reg = kinsn_payload_reg(payload, 4);
    let dst_off = kinsn_payload_s16(payload, 8);
    let len = usize::from(kinsn_payload_u8(payload, 24)) + 1;
    let width_class = u64::from(BpfInsn::unpack_u4(payload, 32) & 0x3);
    let value_from_reg = (BpfInsn::unpack_u4(payload, 34) & 0x1) != 0;
    let zero_fill = (BpfInsn::unpack_u4(payload, 35) & 0x1) != 0;
    let fill_imm8 = kinsn_payload_u8(payload, 36);
    let width_bytes = 1usize << width_class;
    if payload >> 44 != 0 {
        anyhow::bail!("memset bulk payload has non-zero reserved bits");
    }
    if len == 0 || len > 128 {
        anyhow::bail!("memset bulk length {len} is outside 1..128");
    }
    validate_bpf_reg("memset bulk dst", dst_base)?;
    if value_from_reg {
        validate_bpf_reg("memset bulk value", val_reg)?;
    }
    if len % width_bytes != 0 {
        anyhow::bail!("memset bulk length {len} is not a multiple of width {width_bytes}");
    }
    if !bulk_offset_range_valid(dst_off, len) {
        anyhow::bail!("memset bulk offset range is outside s16");
    }
    if zero_fill && fill_imm8 != 0 {
        anyhow::bail!("memset bulk zero-fill payload has non-zero fill immediate");
    }
    Ok(len)
}
fn memcpy_bulk_register_uses(payload: u64) -> RegSet {
    [kinsn_payload_reg(payload, 0), kinsn_payload_reg(payload, 4)]
        .into_iter()
        .collect()
}
fn memset_bulk_register_uses(payload: u64) -> RegSet {
    let mut uses: RegSet = [kinsn_payload_reg(payload, 0)].into_iter().collect();
    if (BpfInsn::unpack_u4(payload, 34) & 0x1) != 0 {
        uses.insert(kinsn_payload_reg(payload, 4));
    }
    uses
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RegValue {
    Unknown,
    Const(u64),
}
impl SimpleRegValue for RegValue {
    fn unknown() -> Self {
        Self::Unknown
    }
    fn const64(value: i64) -> Self {
        Self::Const(value as u64)
    }
    fn const32(value: u32) -> Self {
        Self::Const(u64::from(value))
    }
    fn mov32(value: Self) -> Self {
        match value {
            Self::Const(value) => Self::Const(u64::from(value as u32)),
            Self::Unknown => Self::Unknown,
        }
    }
    fn xor_self() -> Self {
        Self::Const(0)
    }
    fn alu64_imm(_value: Self, _op: u8, _imm: i32) -> Self {
        Self::Unknown
    }
    fn alu32_add_sub(_value: Self, _imm: i32, _is_add: bool) -> Self {
        Self::Unknown
    }
}
#[derive(Clone, Debug)]
enum BulkSiteKind {
    Memcpy {
        dst_base: u8,
        src_base: u8,
        dst_off: i16,
        src_off: i16,
        temp_reg: u8,
        chunk_sizes: Vec<usize>,
    },
    Memset {
        base: u8,
        dst_off: i16,
        width: u8,
        fill_byte: u8,
        chunk_sizes: Vec<usize>,
    },
}
#[derive(Clone, Debug)]
struct BulkSite {
    old_len: usize,
    kind: BulkSiteKind,
}
impl BulkSite {
    fn replacement_len(&self) -> usize {
        match &self.kind {
            BulkSiteKind::Memcpy { chunk_sizes, .. } | BulkSiteKind::Memset { chunk_sizes, .. } => {
                chunk_sizes.len() * 2
            }
        }
    }
}
#[derive(Clone, Debug)]
struct AppliedBulkSite {
    block: BlockId,
    range: Range<usize>,
    site: BulkSite,
}
#[derive(Default)]
struct ScanResult {
    sites: Vec<AppliedBulkSite>,
    skips: Vec<SiteSkipReason>,
}
enum MatchOutcome {
    Apply(BulkSite),
    Skip { reason: String, advance: usize },
    NoMatch,
}
#[derive(Clone, Copy)]
struct MemcpyLane {
    width: u8,
    tmp_reg: u8,
    src_base: u8,
    src_off: i16,
    dst_base: u8,
    dst_off: i16,
}
#[derive(Clone, Copy)]
struct MemsetLane {
    width: u8,
    base: u8,
    off: i16,
    fill_byte: u8,
}
pub struct BulkMemoryPass;
impl BpfPass for BulkMemoryPass {
    fn name(&self) -> &str {
        "bulk_memory"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}
pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    let block_ids = prog.block_ids().collect::<Vec<_>>();
    if block_ids
        .iter()
        .copied()
        .try_fold(true, |all_empty, block| {
            Ok::<_, anyhow::Error>(all_empty && prog.block_is_body_empty(block)?)
        })?
    {
        return Ok(PassResult::unchanged());
    }
    let scan = scan_sites(prog)?;
    let mut skipped = scan.skips;
    let mut safe_sites = Vec::new();
    for site in scan.sites {
        let start = InsnSite {
            block: site.block,
            idx: site.range.start,
        };
        if prog
            .rep_admit_kinsn_site_window(
                start,
                site.site.old_len,
                site.site.replacement_len(),
                &mut skipped,
            )?
            .is_none()
        {
            continue;
        }
        safe_sites.push(site);
    }
    if safe_sites.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::unchanged()
        });
    }
    for site in safe_sites.iter().rev() {
        prog.replace_range(
            site.block,
            site.range.clone(),
            emit_site_replacement(&site.site, &ctx.kinsn_registry)?,
        )?;
    }
    Ok(PassResult {
        sites_applied: safe_sites.len(),
        site_skipped: skipped,
        ..Default::default()
    })
}
fn scan_sites(prog: &BBProgram) -> anyhow::Result<ScanResult> {
    let mut scan = ScanResult::default();
    let mut regs = [RegValue::Unknown; 11];
    for block in prog.block_ids().collect::<Vec<_>>() {
        if prog.should_reset_linear_state_at_block(block)? {
            regs = [RegValue::Unknown; 11];
        }
        let insns = prog.copied_body_insns(block)?;
        let mut live_out = HashMap::new();
        for site in prog.sites_in_block(block)? {
            live_out.insert(site, prog.live_out_site_checked(site)?);
        }
        let mut idx = 0usize;
        while idx < insns.len() {
            let start = InsnSite { block, idx };
            match try_match_memcpy_run_at(&insns, block, idx, &live_out)? {
                MatchOutcome::Apply(site) => {
                    if let BulkSiteKind::Memcpy {
                        src_base, dst_base, ..
                    } = &site.kind
                    {
                        if src_base != dst_base {
                            let src_stack = is_likely_stack_ptr(*src_base, idx, &insns);
                            let dst_stack = is_likely_stack_ptr(*dst_base, idx, &insns);
                            if src_stack == dst_stack {
                                scan.skips.push(SiteSkipReason {
                                    site: start,
                                    reason: format!(
                                        "different-base memcpy alias not provably safe (src r{src_base}, dst r{dst_base})"
                                    ),
                                });
                                advance_reg_state_range(prog, block, idx, site.old_len, &mut regs)?;
                                idx += site.old_len;
                                continue;
                            }
                        }
                    }
                    let old_len = site.old_len;
                    advance_reg_state_range(prog, block, idx, old_len, &mut regs)?;
                    scan.sites.push(AppliedBulkSite {
                        block,
                        range: idx..idx + old_len,
                        site,
                    });
                    idx += old_len;
                    continue;
                }
                MatchOutcome::Skip { reason, advance } => {
                    let advance = advance.max(1);
                    advance_reg_state_range(prog, block, idx, advance, &mut regs)?;
                    scan.skips.push(SiteSkipReason {
                        site: start,
                        reason,
                    });
                    idx += advance;
                    continue;
                }
                MatchOutcome::NoMatch => {}
            }
            if let Some(site) = try_match_memset_run_at(&insns, idx, &regs)? {
                let old_len = site.old_len;
                advance_reg_state_range(prog, block, idx, old_len, &mut regs)?;
                scan.sites.push(AppliedBulkSite {
                    block,
                    range: idx..idx + old_len,
                    site,
                });
                idx += old_len;
                continue;
            }
            advance_reg_state_at_site(prog, start, &mut regs)?;
            idx += 1;
        }
    }
    Ok(scan)
}
fn try_match_memcpy_run_at(
    insns: &[BpfInsn],
    block: BlockId,
    idx: usize,
    live_out: &HashMap<InsnSite, RegSet>,
) -> anyhow::Result<MatchOutcome> {
    let Some(first) = memcpy_lane_at(insns, idx) else {
        return Ok(MatchOutcome::NoMatch);
    };
    let lane_bytes = width_bytes(first.width)?;
    let mut cursor = idx + 2;
    let mut pair_count = 1usize;
    let mut tmp_regs = vec![first.tmp_reg];
    let mut next_src_off = first.src_off as i32 + lane_bytes as i32;
    let mut next_dst_off = first.dst_off as i32 + lane_bytes as i32;
    while cursor + 1 < insns.len() {
        let Some(lane) = memcpy_lane_at(insns, cursor) else {
            break;
        };
        if lane.width != first.width
            || lane.src_base != first.src_base
            || lane.dst_base != first.dst_base
            || lane.src_off as i32 != next_src_off
            || lane.dst_off as i32 != next_dst_off
        {
            break;
        }
        pair_count += 1;
        tmp_regs.push(lane.tmp_reg);
        next_src_off += lane_bytes as i32;
        next_dst_off += lane_bytes as i32;
        cursor += 2;
    }
    let raw_len = pair_count * 2;
    let raw_bytes = pair_count * lane_bytes;
    let chunk_sizes = uniform_chunk_sizes(raw_bytes);
    if chunk_sizes.is_empty() {
        return Ok(MatchOutcome::NoMatch);
    }
    let consumed_bytes: usize = chunk_sizes.iter().sum();
    let consumed_pairs = consumed_bytes / lane_bytes;
    let old_len = consumed_pairs * 2;
    let last_site = InsnSite {
        block,
        idx: idx + old_len - 1,
    };
    if first.src_base == first.dst_base && ranges_overlap(first.src_off, first.dst_off, raw_bytes) {
        return Ok(MatchOutcome::Skip {
            reason: "alias overlap in same-base memcpy run".into(),
            advance: raw_len,
        });
    }
    let live_after = live_out
        .get(&last_site)
        .ok_or_else(|| anyhow::anyhow!("bulk_memory missing live_out for {:?}", last_site))?;
    let mut seen = HashSet::new();
    for tmp_reg in tmp_regs.iter().take(consumed_pairs).copied() {
        if seen.insert(tmp_reg) && live_after.contains(&tmp_reg) {
            return Ok(MatchOutcome::Skip {
                reason: format!("temp tmp_reg r{tmp_reg} is live after site"),
                advance: raw_len,
            });
        }
    }
    Ok(MatchOutcome::Apply(BulkSite {
        old_len,
        kind: BulkSiteKind::Memcpy {
            dst_base: first.dst_base,
            src_base: first.src_base,
            dst_off: first.dst_off,
            src_off: first.src_off,
            temp_reg: first.tmp_reg,
            chunk_sizes,
        },
    }))
}
fn try_match_memset_run_at(
    insns: &[BpfInsn],
    idx: usize,
    regs: &[RegValue; 11],
) -> anyhow::Result<Option<BulkSite>> {
    let Some(first) = memset_lane_at(insns, idx, regs)? else {
        return Ok(None);
    };
    let mut cursor = idx + 1;
    let mut widths = vec![first.width];
    let mut next_off = first.off as i32 + width_bytes(first.width)? as i32;
    while cursor < insns.len() {
        let Some(lane) = memset_lane_at(insns, cursor, regs)? else {
            break;
        };
        if lane.base != first.base
            || lane.fill_byte != first.fill_byte
            || lane.off as i32 != next_off
        {
            break;
        }
        widths.push(lane.width);
        next_off += width_bytes(lane.width)? as i32;
        cursor += 1;
    }
    let lane_bytes = widths
        .iter()
        .map(|&width| width_bytes(width))
        .collect::<anyhow::Result<Vec<_>>>()?;
    let (chunk_sizes, consumed_lanes) = greedy_store_chunk_sizes(&lane_bytes);
    if chunk_sizes.is_empty() {
        return Ok(None);
    }
    let consumed_widths = &widths[..consumed_lanes];
    let payload_width = if consumed_widths
        .iter()
        .all(|&width| width == consumed_widths[0])
    {
        consumed_widths[0]
    } else {
        BPF_B
    };
    Ok(Some(BulkSite {
        old_len: consumed_lanes,
        kind: BulkSiteKind::Memset {
            base: first.base,
            dst_off: first.off,
            width: payload_width,
            fill_byte: first.fill_byte,
            chunk_sizes,
        },
    }))
}
fn memcpy_lane_at(insns: &[BpfInsn], idx: usize) -> Option<MemcpyLane> {
    let load = insns.get(idx)?;
    let store = insns.get(idx + 1)?;
    let width = bpf_size(load.code);
    if !load.is_ldx_mem() || !is_supported_width(width) {
        return None;
    }
    if store.class() != BPF_STX || bpf_mode(store.code) != BPF_MEM || bpf_size(store.code) != width
    {
        return None;
    }
    if store.src_reg() != load.dst_reg() {
        return None;
    }
    if load.dst_reg() == load.src_reg() || load.dst_reg() == store.dst_reg() {
        return None;
    }
    Some(MemcpyLane {
        width,
        tmp_reg: load.dst_reg(),
        src_base: load.src_reg(),
        src_off: load.off,
        dst_base: store.dst_reg(),
        dst_off: store.off,
    })
}
fn memset_lane_at(
    insns: &[BpfInsn],
    idx: usize,
    regs: &[RegValue; 11],
) -> anyhow::Result<Option<MemsetLane>> {
    let Some(insn) = insns.get(idx) else {
        return Ok(None);
    };
    let width = bpf_size(insn.code);
    if !is_supported_width(width) || bpf_mode(insn.code) != BPF_MEM {
        return Ok(None);
    }
    let fill_byte = match insn.class() {
        BPF_ST => match fill_byte_from_imm(width, insn.imm)? {
            Some(fill) => fill,
            None => return Ok(None),
        },
        BPF_STX => match regs[insn.src_reg() as usize] {
            RegValue::Const(value) => match fill_byte_from_const(width, value)? {
                Some(fill) => fill,
                None => return Ok(None),
            },
            RegValue::Unknown => return Ok(None),
        },
        _ => return Ok(None),
    };
    Ok(Some(MemsetLane {
        width,
        base: insn.dst_reg(),
        off: insn.off,
        fill_byte,
    }))
}
fn emit_site_replacement(
    site: &BulkSite,
    kinsn_registry: &KinsnRegistry,
) -> anyhow::Result<Vec<BpfInsn>> {
    match &site.kind {
        BulkSiteKind::Memcpy {
            dst_base,
            src_base,
            dst_off,
            src_off,
            temp_reg,
            chunk_sizes,
        } => {
            let memcpy_btf_id = kinsn_registry.btf_id_for_target_name(MEMCPY_TARGET)?;
            let memcpy_off = kinsn_registry.call_off_for_target_name(MEMCPY_TARGET)?;
            let mut out = Vec::with_capacity(chunk_sizes.len() * 2);
            let mut cur_dst_off = *dst_off as i32;
            let mut cur_src_off = *src_off as i32;
            for &chunk_size in chunk_sizes {
                out.extend_from_slice(&emit_packed_kinsn_call_with_off(
                    pack_memcpy_payload(
                        *dst_base,
                        *src_base,
                        cur_dst_off as i16,
                        cur_src_off as i16,
                        chunk_size as u8,
                        *temp_reg,
                    ),
                    memcpy_btf_id,
                    memcpy_off,
                ));
                cur_dst_off += chunk_size as i32;
                cur_src_off += chunk_size as i32;
            }
            Ok(out)
        }
        BulkSiteKind::Memset {
            base,
            dst_off,
            width,
            fill_byte,
            chunk_sizes,
        } => {
            let memset_btf_id = kinsn_registry.btf_id_for_target_name(MEMSET_TARGET)?;
            let memset_off = kinsn_registry.call_off_for_target_name(MEMSET_TARGET)?;
            let mut out = Vec::with_capacity(chunk_sizes.len() * 2);
            let mut cur_dst_off = *dst_off as i32;
            for &chunk_size in chunk_sizes {
                out.extend_from_slice(&emit_packed_kinsn_call_with_off(
                    pack_memset_payload(
                        *base,
                        cur_dst_off as i16,
                        chunk_size as u8,
                        *width,
                        *fill_byte,
                    )?,
                    memset_btf_id,
                    memset_off,
                ));
                cur_dst_off += chunk_size as i32;
            }
            Ok(out)
        }
    }
}
fn pack_memcpy_payload(
    dst_base: u8,
    src_base: u8,
    dst_off: i16,
    src_off: i16,
    len: u8,
    temp_reg: u8,
) -> u64 {
    BpfInsn::pack_u4(dst_base, 0)
        | BpfInsn::pack_u4(src_base, 4)
        | BpfInsn::pack_u16(dst_off as u16, 8)
        | BpfInsn::pack_u16(src_off as u16, 24)
        | BpfInsn::pack_u8(len - 1, 40)
        | BpfInsn::pack_u4(temp_reg, 48)
}
fn pack_memset_payload(
    base: u8,
    dst_off: i16,
    len: u8,
    width: u8,
    fill_byte: u8,
) -> anyhow::Result<u64> {
    let zero_fill = fill_byte == 0;
    Ok(BpfInsn::pack_u4(base, 0)
        | BpfInsn::pack_u16(dst_off as u16, 8)
        | BpfInsn::pack_u8(len - 1, 24)
        | BpfInsn::pack_u4(width_class(width)?, 32)
        | BpfInsn::pack_u4(zero_fill as u8, 35)
        | BpfInsn::pack_u8(fill_byte, 36))
}
fn width_class(size: u8) -> anyhow::Result<u8> {
    Ok(match size {
        BPF_B => 0,
        BPF_H => 1,
        BPF_W => 2,
        BPF_DW => 3,
        _ => anyhow::bail!("bulk_memory unsupported width opcode {size:#x}"),
    })
}
fn uniform_chunk_sizes(total_bytes: usize) -> Vec<usize> {
    if total_bytes < MIN_BULK_BYTES {
        return Vec::new();
    }
    let full_chunks = total_bytes / CHUNK_MAX_BYTES;
    let tail = total_bytes % CHUNK_MAX_BYTES;
    let mut chunks = vec![CHUNK_MAX_BYTES; full_chunks];
    if tail >= MIN_BULK_BYTES {
        chunks.push(tail);
    } else if chunks.is_empty() {
        return Vec::new();
    }
    chunks
}
fn greedy_store_chunk_sizes(lane_bytes: &[usize]) -> (Vec<usize>, usize) {
    let mut chunks = Vec::new();
    let mut chunk_lanes = Vec::new();
    let mut current_bytes = 0usize;
    let mut current_lanes = 0usize;
    for &lane_bytes in lane_bytes {
        if current_bytes > 0 && current_bytes + lane_bytes > CHUNK_MAX_BYTES {
            chunks.push(current_bytes);
            chunk_lanes.push(current_lanes);
            current_bytes = 0;
            current_lanes = 0;
        }
        current_bytes += lane_bytes;
        current_lanes += 1;
    }
    if current_lanes > 0 {
        chunks.push(current_bytes);
        chunk_lanes.push(current_lanes);
    }
    if chunks.last().is_some_and(|&last| last < MIN_BULK_BYTES) {
        chunks.pop();
        chunk_lanes.pop();
    }
    (chunks, chunk_lanes.into_iter().sum())
}
fn fill_byte_from_imm(width: u8, imm: i32) -> anyhow::Result<Option<u8>> {
    let value = match width {
        BPF_B => imm as u8 as u64,
        BPF_H => imm as i16 as u16 as u64,
        BPF_W => imm as u32 as u64,
        BPF_DW => imm as i64 as u64,
        _ => anyhow::bail!("unsupported memset store width class {width:#x}"),
    };
    fill_byte_from_const(width, value)
}
fn fill_byte_from_const(width: u8, value: u64) -> anyhow::Result<Option<u8>> {
    let lane_bytes = width_bytes(width)?;
    let fill = value as u8;
    for byte_idx in 0..lane_bytes {
        if ((value >> (byte_idx * 8)) & 0xff) as u8 != fill {
            return Ok(None);
        }
    }
    Ok(Some(fill))
}
fn ranges_overlap(src_off: i16, dst_off: i16, len: usize) -> bool {
    let src_start = src_off as i32;
    let dst_start = dst_off as i32;
    let len = len as i32;
    src_start < dst_start + len && dst_start < src_start + len
}
fn is_supported_width(width: u8) -> bool {
    matches!(width, BPF_B | BPF_H | BPF_W | BPF_DW)
}
fn width_bytes(width: u8) -> anyhow::Result<usize> {
    Ok(match width {
        BPF_B => 1,
        BPF_H => 2,
        BPF_W => 4,
        BPF_DW => 8,
        _ => anyhow::bail!("bulk_memory unsupported width opcode {width:#x}"),
    })
}
fn is_likely_stack_ptr(reg: u8, before_slot: usize, insns: &[BpfInsn]) -> bool {
    if reg == STACK_PTR_REG {
        return true;
    }
    const LOOKBACK: usize = 32;
    let start = before_slot.saturating_sub(LOOKBACK);
    let mut target_reg = reg;
    let mut cursor = before_slot;
    for _ in 0..LOOKBACK {
        let mut found_def = false;
        for def_idx in (start..cursor).rev() {
            let insn = &insns[def_idx];
            if !insn_use_def_set(insn).defs.contains(&target_reg) {
                continue;
            }
            found_def = true;
            if insn.class() == BPF_ALU64
                && insn.dst_reg() == target_reg
                && bpf_src(insn.code) == BPF_X
                && bpf_op(insn.code) == BPF_MOV
            {
                let src_reg = insn.src_reg();
                if src_reg == STACK_PTR_REG {
                    return true;
                }
                target_reg = src_reg;
                cursor = def_idx;
                break;
            }
            if insn.class() == BPF_ALU64
                && insn.dst_reg() == target_reg
                && bpf_src(insn.code) == BPF_K
                && matches!(bpf_op(insn.code), BPF_ADD | BPF_SUB)
            {
                cursor = def_idx;
                break;
            }
            return false;
        }
        if !found_def {
            return false;
        }
    }
    false
}
fn advance_reg_state_range(
    prog: &BBProgram,
    block: BlockId,
    start_idx: usize,
    len: usize,
    regs: &mut [RegValue; 11],
) -> anyhow::Result<()> {
    let end_idx = start_idx.checked_add(len).ok_or_else(|| {
        anyhow::anyhow!("bulk_memory range start {start_idx} + len {len} overflows")
    })?;
    let block_len = prog.block_body_len(block)?;
    if end_idx > block_len {
        anyhow::bail!(
            "bulk_memory range {}..{} exceeds block {:?} body length {}",
            start_idx,
            end_idx,
            block,
            block_len
        );
    }
    for idx in start_idx..end_idx {
        advance_reg_state_at_site(prog, InsnSite { block, idx }, regs)?;
    }
    Ok(())
}
fn advance_reg_state_at_site(
    prog: &BBProgram,
    site: InsnSite,
    regs: &mut [RegValue; 11],
) -> anyhow::Result<()> {
    let insn = prog
        .insn_at(site)
        .ok_or_else(|| anyhow::anyhow!("invalid instruction site {:?}", site))?;
    let ldimm64_hi =
        if insn.is_ldimm64() {
            Some(prog.ldimm64_second_slot(site).ok_or_else(|| {
                anyhow::anyhow!("LD_IMM64 at {:?} is missing its second slot", site)
            })?)
        } else {
            None
        };
    advance_simple_reg_state(insn, ldimm64_hi, regs)
}
