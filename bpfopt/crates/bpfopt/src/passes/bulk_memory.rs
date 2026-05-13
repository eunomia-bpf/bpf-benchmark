// SPDX-License-Identifier: MIT
use crate::analysis::{InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;
use std::collections::HashMap;

const MEMCPY_TARGET: &str = "bpf_bulk_memcpy";
const MEMSET_TARGET: &str = "bpf_bulk_memset";
const MIN_BULK_BYTES: usize = 32;
const CHUNK_MAX_BYTES: usize = 128;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: MEMCPY_TARGET,
        register_uses: memcpy_bulk_register_uses,
    },
    KinsnDescriptor {
        name: MEMSET_TARGET,
        register_uses: memset_bulk_register_uses,
    },
];
fn memcpy_bulk_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0, 4])
}
fn memset_bulk_register_uses(payload: u64) -> RegSet {
    let mut uses: RegSet = [kinsn_payload_reg(payload, 0)].into_iter().collect();
    if (BpfInsn::unpack_u4(payload, 34) & 0x1) != 0 {
        uses.insert(kinsn_payload_reg(payload, 4));
    }
    uses
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
    fn run(&self, prog: &mut ProgramCFG, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        let scan = scan_sites(prog)?;
        let mut skipped = scan.skips;
        if scan.sites.is_empty() {
            return Ok(PassResult::with_sites(0, skipped));
        }
        let applied =
            apply_candidates_reverse(prog, &scan.sites, &mut skipped, |prog, _, site| {
                Ok((site.old_len, emit_site_replacement(site, prog)?))
            })?;
        Ok(PassResult::with_sites(applied, skipped))
    }
}

fn scan_sites(prog: &ProgramCFG) -> anyhow::Result<ScanResult> {
    let mut scan = ScanResult::default();
    for block in prog.block_ids().collect::<Vec<_>>() {
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
                    let old_len = site.old_len;
                    scan.sites.push((start, site));
                    idx += old_len;
                    continue;
                }
                MatchOutcome::Skip(reason, advance) => {
                    let advance = advance.max(1);
                    scan.skips.push(SiteSkipReason {
                        site: start,
                        reason,
                    });
                    idx += advance;
                    continue;
                }
                MatchOutcome::NoMatch => {}
            }
            if let Some(site) = try_match_memset_run_at(prog, body.insns, &body.sites, idx)? {
                let old_len = site.old_len;
                scan.sites.push((start, site));
                idx += old_len;
                continue;
            }
            idx += 1;
        }
    }
    Ok(scan)
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
    // Only the consumed_bytes prefix is rewritten into a bulk kfunc; any tail
    // beyond consumed_bytes keeps executing the original byte-by-byte memcpy,
    // so its overlap (if any) is preserved by the unchanged code. Alias check
    // therefore only needs to guard the consumed prefix.
    if first.src_base == first.dst_base
        && ranges_overlap(first.src_off, first.dst_off, consumed_bytes)
    {
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
    prog: &ProgramCFG,
    insns: &[BpfInsn],
    sites: &[InsnSite],
    idx: usize,
) -> anyhow::Result<Option<BulkSite>> {
    let Some(first) = memset_lane_at(prog, insns, sites, idx)? else {
        return Ok(None);
    };
    let mut cursor = idx + 1;
    let mut widths = vec![first.width];
    let mut next_off = first.off as i32 + width_bytes(first.width)? as i32;
    while cursor < insns.len() {
        let Some(lane) = memset_lane_at(prog, insns, sites, cursor)? else {
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
    if BpfMemWidth::from_size_opcode(width).is_none() || !load.is_ldx_mem_size(width) {
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
    prog: &ProgramCFG,
    insns: &[BpfInsn],
    sites: &[InsnSite],
    idx: usize,
) -> anyhow::Result<Option<MemsetLane>> {
    let Some(insn) = insns.get(idx) else {
        return Ok(None);
    };
    let width = bpf_size(insn.code);
    if BpfMemWidth::from_size_opcode(width).is_none() || bpf_mode(insn.code) != BPF_MEM {
        return Ok(None);
    }
    let fill_byte = match insn.class() {
        BPF_ST => fill_byte_from_imm(width, insn.imm)?,
        BPF_STX => match prog.reg_fact_at(sites[idx], insn.src_reg())?.as_const() {
            Some(value) => fill_byte_from_lane(width_bytes(width)?, value as u64),
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
fn emit_site_replacement(site: &BulkSite, prog: &ProgramCFG) -> anyhow::Result<Vec<BpfInsn>> {
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
    prog: &ProgramCFG,
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
        | BpfInsn::pack_u4(decode_width(width)? as u8, 32)
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
fn width_bytes(width: u8) -> anyhow::Result<usize> {
    Ok(decode_width(width)?.bytes())
}
fn decode_width(width: u8) -> anyhow::Result<BpfMemWidth> {
    BpfMemWidth::from_size_opcode(width)
        .ok_or_else(|| anyhow::anyhow!("bulk_memory unsupported width opcode {width:#x}"))
}
