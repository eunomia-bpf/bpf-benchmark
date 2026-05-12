// SPDX-License-Identifier: MIT
use crate::analysis::{insn_use_def_set, BBProgram, InsnSite};
use crate::insn::{advance_reg_state as advance_simple_reg_state, SimpleRegValue, *};
use crate::pass::*;
use std::collections::HashMap;

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
    (i32::from(i16::MIN)..=i32::from(i16::MAX)).contains(&end)
}
fn validate_bulk_len(kind: &str, len: usize) -> anyhow::Result<()> {
    anyhow::ensure!(
        (1..=CHUNK_MAX_BYTES).contains(&len),
        "{kind} bulk length {len} is outside 1..128"
    );
    Ok(())
}
fn validate_bulk_offsets(kind: &str, ranges: &[(i16, usize)]) -> anyhow::Result<()> {
    anyhow::ensure!(
        ranges
            .iter()
            .all(|&(offset, len)| bulk_offset_range_valid(offset, len)),
        "{kind} bulk offset range is outside s16"
    );
    Ok(())
}
fn memcpy_bulk_proof_len(payload: u64) -> anyhow::Result<usize> {
    let dst_base = kinsn_payload_reg(payload, 0);
    let src_base = kinsn_payload_reg(payload, 4);
    let dst_off = kinsn_payload_s16(payload, 8);
    let src_off = kinsn_payload_s16(payload, 24);
    let len = usize::from(kinsn_payload_u8(payload, 40)) + 1;
    let tmp_reg = kinsn_payload_reg(payload, 48);
    anyhow::ensure!(
        payload >> 52 == 0,
        "memcpy bulk payload has non-zero reserved bits"
    );
    validate_bulk_len("memcpy", len)?;
    validate_bpf_reg("memcpy bulk dst", dst_base)?;
    validate_bpf_reg("memcpy bulk src", src_base)?;
    validate_bpf_reg("memcpy bulk tmp", tmp_reg)?;
    anyhow::ensure!(
        tmp_reg != BPF_REG_10 && tmp_reg != dst_base && tmp_reg != src_base,
        "memcpy bulk tmp register aliases an invalid operand"
    );
    validate_bulk_offsets("memcpy", &[(dst_off, len), (src_off, len)])?;
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
    anyhow::ensure!(
        payload >> 44 == 0,
        "memset bulk payload has non-zero reserved bits"
    );
    validate_bulk_len("memset", len)?;
    validate_bpf_reg("memset bulk dst", dst_base)?;
    if value_from_reg {
        validate_bpf_reg("memset bulk value", val_reg)?;
    }
    anyhow::ensure!(
        len % width_bytes == 0,
        "memset bulk length {len} is not a multiple of width {width_bytes}"
    );
    validate_bulk_offsets("memset", &[(dst_off, len)])?;
    anyhow::ensure!(
        !(zero_fill && fill_imm8 != 0),
        "memset bulk zero-fill payload has non-zero fill immediate"
    );
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
type RegValue = Option<u64>;
impl SimpleRegValue for RegValue {
    fn unknown() -> Self {
        None
    }
    fn const64(value: i64) -> Self {
        Some(value as u64)
    }
    fn const32(value: u32) -> Self {
        Some(u64::from(value))
    }
    fn mov32(value: Self) -> Self {
        value.map(|value| u64::from(value as u32))
    }
    fn xor_self() -> Self {
        Some(0)
    }
    fn alu64_imm(_value: Self, _op: u8, _imm: i32) -> Self {
        None
    }
    fn alu32_add_sub(_value: Self, _imm: i32, _is_add: bool) -> Self {
        None
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
#[derive(Default)]
struct ScanResult {
    sites: Vec<(InsnSite, BulkSite)>,
    skips: Vec<SiteSkipReason>,
}
enum MatchOutcome {
    Apply(BulkSite),
    Skip(String, usize),
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
pub fn run_on_bbprogram(prog: &mut BBProgram, _ctx: &PassContext) -> anyhow::Result<PassResult> {
    let scan = scan_sites(prog)?;
    let mut skipped = scan.skips;
    if scan.sites.is_empty() {
        return Ok(PassResult::with_sites(0, skipped));
    }
    let applied = apply_candidates_reverse(prog, &scan.sites, &mut skipped, |prog, _, site| {
        Ok((site.old_len, emit_site_replacement(site, prog)?))
    })?;
    Ok(PassResult::with_sites(applied, skipped))
}
fn scan_sites(prog: &BBProgram) -> anyhow::Result<ScanResult> {
    let mut scan = ScanResult::default();
    let mut regs = [None; 11];
    for block in prog.block_ids().collect::<Vec<_>>() {
        if prog.should_reset_linear_state_at_block(block)? {
            regs = [None; 11];
        }
        let body = prog.block_body_view(block)?;
        let mut live_out = HashMap::new();
        for &site in &body.sites {
            live_out.insert(site, prog.live_out_site_checked(site)?);
        }
        let mut idx = 0usize;
        while idx < body.insns.len() {
            let start = body.sites[idx];
            match try_match_memcpy_run_at(body.insns, &body.sites, idx, &live_out)? {
                MatchOutcome::Apply(site) => {
                    if let Some(reason) = memcpy_alias_skip_reason(&site, idx, body.insns) {
                        scan.skips.push(SiteSkipReason {
                            site: start,
                            reason,
                        });
                        advance_reg_state_range(prog, &body.sites, idx, site.old_len, &mut regs)?;
                        idx += site.old_len;
                        continue;
                    }
                    let old_len = site.old_len;
                    advance_reg_state_range(prog, &body.sites, idx, old_len, &mut regs)?;
                    scan.sites.push((start, site));
                    idx += old_len;
                    continue;
                }
                MatchOutcome::Skip(reason, advance) => {
                    let advance = advance.max(1);
                    advance_reg_state_range(prog, &body.sites, idx, advance, &mut regs)?;
                    scan.skips.push(SiteSkipReason {
                        site: start,
                        reason,
                    });
                    idx += advance;
                    continue;
                }
                MatchOutcome::NoMatch => {}
            }
            if let Some(site) = try_match_memset_run_at(body.insns, idx, &regs)? {
                let old_len = site.old_len;
                advance_reg_state_range(prog, &body.sites, idx, old_len, &mut regs)?;
                scan.sites.push((start, site));
                idx += old_len;
                continue;
            }
            advance_reg_state_at_site(prog, start, &mut regs)?;
            idx += 1;
        }
    }
    Ok(scan)
}
fn memcpy_alias_skip_reason(site: &BulkSite, idx: usize, insns: &[BpfInsn]) -> Option<String> {
    let BulkSiteKind::Memcpy {
        src_base, dst_base, ..
    } = &site.kind
    else {
        return None;
    };
    if src_base == dst_base {
        return None;
    }
    (is_likely_stack_ptr(*src_base, idx, insns) == is_likely_stack_ptr(*dst_base, idx, insns)).then(
        || {
            format!(
                "different-base memcpy alias not provably safe (src r{src_base}, dst r{dst_base})"
            )
        },
    )
}
fn try_match_memcpy_run_at(
    insns: &[BpfInsn],
    sites: &[InsnSite],
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
        let Some(lane) = memcpy_lane_at(insns, cursor).filter(|lane| {
            lane.width == first.width
                && lane.src_base == first.src_base
                && lane.dst_base == first.dst_base
                && lane.src_off as i32 == next_src_off
                && lane.dst_off as i32 == next_dst_off
        }) else {
            break;
        };
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
    let last_idx = idx + old_len - 1;
    let last_site = sites
        .get(last_idx)
        .copied()
        .ok_or_else(|| anyhow::anyhow!("bulk_memory last index {last_idx} missing"))?;
    if first.src_base == first.dst_base && ranges_overlap(first.src_off, first.dst_off, raw_bytes) {
        return Ok(MatchOutcome::Skip(
            "alias overlap in same-base memcpy run".into(),
            raw_len,
        ));
    }
    let live_after = live_out
        .get(&last_site)
        .ok_or_else(|| anyhow::anyhow!("bulk_memory missing live_out for {:?}", last_site))?;
    let mut seen = 0u16;
    for tmp_reg in tmp_regs.iter().take(consumed_pairs).copied() {
        let bit = 1u16 << tmp_reg;
        if seen & bit == 0 && live_after.contains(&tmp_reg) {
            return Ok(MatchOutcome::Skip(
                format!("temp tmp_reg r{tmp_reg} is live after site"),
                raw_len,
            ));
        }
        seen |= bit;
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
    let (chunk_sizes, consumed_lanes) =
        greedy_store_chunk_sizes(widths.iter().copied().map(width_bytes))?;
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
    if !is_supported_width(width) || !load.is_ldx_mem_size(width) {
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
        BPF_ST => fill_byte_from_imm(width, insn.imm)?,
        BPF_STX => match regs[insn.src_reg() as usize] {
            Some(value) => fill_byte_from_const(width, value)?,
            None => None,
        },
        _ => None,
    };
    let Some(fill_byte) = fill_byte else {
        return Ok(None);
    };
    Ok(Some(MemsetLane {
        width,
        base: insn.dst_reg(),
        off: insn.off,
        fill_byte,
    }))
}
fn emit_site_replacement(site: &BulkSite, prog: &BBProgram) -> anyhow::Result<Vec<BpfInsn>> {
    match &site.kind {
        BulkSiteKind::Memcpy {
            dst_base,
            src_base,
            dst_off,
            src_off,
            temp_reg,
            chunk_sizes,
        } => {
            let mut cur_dst_off = *dst_off as i32;
            let mut cur_src_off = *src_off as i32;
            emit_chunked_calls(prog, MEMCPY_TARGET, chunk_sizes, |chunk_size| {
                let payload = pack_memcpy_payload(
                    *dst_base,
                    *src_base,
                    cur_dst_off as i16,
                    cur_src_off as i16,
                    chunk_size as u8,
                    *temp_reg,
                );
                cur_dst_off += chunk_size as i32;
                cur_src_off += chunk_size as i32;
                Ok(payload)
            })
        }
        BulkSiteKind::Memset {
            base,
            dst_off,
            width,
            fill_byte,
            chunk_sizes,
        } => {
            let mut cur_dst_off = *dst_off as i32;
            emit_chunked_calls(prog, MEMSET_TARGET, chunk_sizes, |chunk_size| {
                let payload = pack_memset_payload(
                    *base,
                    cur_dst_off as i16,
                    chunk_size as u8,
                    *width,
                    *fill_byte,
                )?;
                cur_dst_off += chunk_size as i32;
                Ok(payload)
            })
        }
    }
}
fn emit_chunked_calls(
    prog: &BBProgram,
    target: &str,
    chunk_sizes: &[usize],
    mut pack_payload: impl FnMut(usize) -> anyhow::Result<u64>,
) -> anyhow::Result<Vec<BpfInsn>> {
    let (btf_id, call_off) = prog.kinsn_call(target)?;
    let mut out = Vec::with_capacity(chunk_sizes.len() * 2);
    for &chunk_size in chunk_sizes {
        out.extend_from_slice(&emit_packed_kinsn_call_with_off(
            pack_payload(chunk_size)?,
            btf_id,
            call_off,
        ));
    }
    Ok(out)
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
        | BpfInsn::pack_u4(width_props(width)?.0, 32)
        | BpfInsn::pack_u4(zero_fill as u8, 35)
        | BpfInsn::pack_u8(fill_byte, 36))
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
fn greedy_store_chunk_sizes(
    lane_bytes: impl IntoIterator<Item = anyhow::Result<usize>>,
) -> anyhow::Result<(Vec<usize>, usize)> {
    let mut chunks = Vec::new();
    let mut chunk_lanes = Vec::new();
    let mut current_bytes = 0usize;
    let mut current_lanes = 0usize;
    for lane_bytes in lane_bytes {
        let lane_bytes = lane_bytes?;
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
    Ok((chunks, chunk_lanes.into_iter().sum()))
}
fn fill_byte_from_imm(width: u8, imm: i32) -> anyhow::Result<Option<u8>> {
    let lane_bytes = width_bytes(width)?;
    let value = if lane_bytes == 8 {
        imm as i64 as u64
    } else {
        (imm as u64) & ((1u64 << (lane_bytes * 8)) - 1)
    };
    Ok(fill_byte_from_lane(lane_bytes, value))
}
fn fill_byte_from_const(width: u8, value: u64) -> anyhow::Result<Option<u8>> {
    Ok(fill_byte_from_lane(width_bytes(width)?, value))
}
fn fill_byte_from_lane(lane_bytes: usize, value: u64) -> Option<u8> {
    let fill = value as u8;
    (0..lane_bytes)
        .all(|byte_idx| ((value >> (byte_idx * 8)) & 0xff) as u8 == fill)
        .then_some(fill)
}
fn ranges_overlap(src_off: i16, dst_off: i16, len: usize) -> bool {
    let src_start = src_off as i32;
    let dst_start = dst_off as i32;
    let len = len as i32;
    src_start < dst_start + len && dst_start < src_start + len
}
fn is_supported_width(width: u8) -> bool {
    width_props(width).is_ok()
}
fn width_bytes(width: u8) -> anyhow::Result<usize> {
    Ok(width_props(width)?.1)
}
fn width_props(width: u8) -> anyhow::Result<(u8, usize)> {
    Ok(match width {
        BPF_B => (0, 1),
        BPF_H => (1, 2),
        BPF_W => (2, 4),
        BPF_DW => (3, 8),
        _ => anyhow::bail!("bulk_memory unsupported width opcode {width:#x}"),
    })
}
fn is_likely_stack_ptr(reg: u8, before_insn_count: usize, insns: &[BpfInsn]) -> bool {
    if reg == STACK_PTR_REG {
        return true;
    }
    const LOOKBACK: usize = 32;
    let start = before_insn_count.saturating_sub(LOOKBACK);
    let mut target_reg = reg;
    let mut cursor = before_insn_count;
    for _ in 0..LOOKBACK {
        let Some(def_idx) = (start..cursor)
            .rev()
            .find(|&idx| insn_use_def_set(&insns[idx]).defs.contains(&target_reg))
        else {
            return false;
        };
        let insn = &insns[def_idx];
        if insn.is_alu_reg(BPF_ALU64, BPF_MOV) && insn.dst_reg() == target_reg {
            let src_reg = insn.src_reg();
            if src_reg == STACK_PTR_REG {
                return true;
            }
            target_reg = src_reg;
            cursor = def_idx;
            continue;
        }
        if insn.dst_reg() == target_reg
            && (insn.is_alu_imm(BPF_ALU64, BPF_ADD) || insn.is_alu_imm(BPF_ALU64, BPF_SUB))
        {
            cursor = def_idx;
            continue;
        }
        return false;
    }
    false
}
fn advance_reg_state_range(
    prog: &BBProgram,
    sites: &[InsnSite],
    start_idx: usize,
    len: usize,
    regs: &mut [RegValue; 11],
) -> anyhow::Result<()> {
    let end_idx = start_idx.checked_add(len).ok_or_else(|| {
        anyhow::anyhow!("bulk_memory range start {start_idx} + len {len} overflows")
    })?;
    let range = sites.get(start_idx..end_idx).ok_or_else(|| {
        anyhow::anyhow!(
            "bulk_memory range {}..{} exceeds body length {}",
            start_idx,
            end_idx,
            sites.len()
        )
    })?;
    for &site in range {
        advance_reg_state_at_site(prog, site, regs)?;
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
