// SPDX-License-Identifier: MIT
use crate::analysis::{InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;

const X86_LOADB_TARGET: &str = "bpf_x86_movzbl";
const X86_STOREB_REG_TARGET: &str = "bpf_x86_movb";
const X86_STOREB_IMM_TARGET: &str = "bpf_x86_movb";
const ARM64_LOADB_TARGET: &str = "bpf_arm64_ldrb_mem";
const ARM64_STOREB_REG_TARGET: &str = "bpf_arm64_strb_mem_reg";
const ARM64_STOREB_WZR_TARGET: &str = "bpf_arm64_strb_wzr_mem";
const MIN_BULK_BYTES: usize = 32;
const CHUNK_MAX_BYTES: usize = 128;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: ARM64_LOADB_TARGET,
        register_uses: load_register_uses,
        register_defs: load_register_defs,
    },
    KinsnDescriptor {
        name: ARM64_STOREB_REG_TARGET,
        register_uses: store_reg_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: ARM64_STOREB_WZR_TARGET,
        register_uses: store_imm_register_uses,
        register_defs: no_regs,
    },
];
fn load_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[4])
}
fn load_register_defs(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}
fn store_reg_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0, 4])
}
fn store_imm_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
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
    fn run(&self, prog: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        let scan = scan_sites(prog, ctx.arch)?;
        let mut skipped = scan.skips;
        if scan.sites.is_empty() {
            return Ok(PassResult::with_sites(0, skipped));
        }
        let applied =
            apply_candidates_reverse(prog, &scan.sites, &mut skipped, |prog, _, site| {
                Ok((site.old_len, emit_site_replacement(site, prog, ctx.arch)?))
            })?;
        Ok(PassResult::with_sites(applied, skipped))
    }
}

fn scan_sites(prog: &mut ProgramCFG, arch: Arch) -> anyhow::Result<ScanResult> {
    let mut scan = ScanResult::default();
    for block in prog.block_ids().collect::<Vec<_>>() {
        // Snapshot body data and drop the `&prog` borrow before calling
        // `try_match_*` which takes `&mut prog` (for reg_fact_at).
        let (body_insns, body_sites, body_len) = {
            let body = prog.block_body_view(block)?;
            (body.bpf_insns(), body.sites.clone(), body.insns.len())
        };
        let mut idx = 0usize;
        while idx < body_len {
            let start = body_sites[idx];
            match try_match_memcpy_run_at(prog, &body_insns, &body_sites, idx, arch)? {
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
            if let Some(site) = try_match_memset_run_at(prog, &body_insns, &body_sites, idx, arch)?
            {
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
    prog: &mut ProgramCFG,
    insns: &[BpfInsn],
    sites: &[InsnSite],
    idx: usize,
    arch: Arch,
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
    let live_after = prog.live_out_site_checked(last_site)?;
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
    let site = BulkSite {
        old_len,
        kind: BulkSiteKind::Memcpy {
            dst_base: first.dst_base,
            src_base: first.src_base,
            dst_off: first.dst_off,
            src_off: first.src_off,
            temp_reg: first.tmp_reg,
            chunk_sizes,
        },
    };
    if !bulk_site_supported_on_arch(&site, arch) {
        return Ok(MatchOutcome::Skip(
            "bulk_memory machine kinsn offset is not encodable on target arch".into(),
            raw_len,
        ));
    }
    Ok(MatchOutcome::Apply(site))
}
fn try_match_memset_run_at(
    prog: &mut ProgramCFG,
    insns: &[BpfInsn],
    sites: &[InsnSite],
    idx: usize,
    arch: Arch,
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
    let site = BulkSite {
        old_len: consumed_lanes,
        kind: BulkSiteKind::Memset {
            base: first.base,
            dst_off: first.off,
            fill_byte: first.fill_byte,
            chunk_sizes,
        },
    };
    if !bulk_site_supported_on_arch(&site, arch) {
        return Ok(None);
    }
    Ok(Some(site))
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
    prog: &mut ProgramCFG,
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
fn bulk_site_supported_on_arch(site: &BulkSite, arch: Arch) -> bool {
    if arch == Arch::X86_64 {
        return true;
    }
    match &site.kind {
        BulkSiteKind::Memcpy {
            dst_off,
            src_off,
            chunk_sizes,
            ..
        } => {
            let total_bytes: usize = chunk_sizes.iter().sum();
            (0..total_bytes).all(|idx| {
                arm64_byte_offset_encodable(*src_off as i32 + idx as i32)
                    && arm64_byte_offset_encodable(*dst_off as i32 + idx as i32)
            })
        }
        BulkSiteKind::Memset {
            fill_byte,
            dst_off,
            chunk_sizes,
            ..
        } => {
            if *fill_byte != 0 {
                return false;
            }
            let total_bytes: usize = chunk_sizes.iter().sum();
            (0..total_bytes).all(|idx| arm64_byte_offset_encodable(*dst_off as i32 + idx as i32))
        }
    }
}
fn arm64_byte_offset_encodable(offset: i32) -> bool {
    (0..=0x0fff).contains(&offset) || (-256..=255).contains(&offset)
}
fn emit_site_replacement(
    site: &BulkSite,
    prog: &ProgramCFG,
    arch: Arch,
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
            let total_bytes: usize = chunk_sizes.iter().sum();
            emit_memcpy_byte_kinsns(
                prog,
                arch,
                *dst_base,
                *src_base,
                *dst_off,
                *src_off,
                *temp_reg,
                total_bytes,
            )
        }
        BulkSiteKind::Memset {
            base,
            dst_off,
            fill_byte,
            chunk_sizes,
        } => {
            let total_bytes: usize = chunk_sizes.iter().sum();
            emit_memset_byte_kinsns(prog, arch, *base, *dst_off, *fill_byte, total_bytes)
        }
    }
}
fn emit_memcpy_byte_kinsns(
    prog: &ProgramCFG,
    arch: Arch,
    dst_base: u8,
    src_base: u8,
    dst_off: i16,
    src_off: i16,
    temp_reg: u8,
    total_bytes: usize,
) -> anyhow::Result<Vec<BpfInsn>> {
    let (load_target, store_target) = match arch {
        Arch::X86_64 => (X86_LOADB_TARGET, X86_STOREB_REG_TARGET),
        Arch::Aarch64 => (ARM64_LOADB_TARGET, ARM64_STOREB_REG_TARGET),
    };
    let mut out = Vec::with_capacity(total_bytes * 4);
    for idx in 0..total_bytes {
        let src_off = checked_byte_offset(src_off, idx)?;
        let dst_off = checked_byte_offset(dst_off, idx)?;
        out.extend_from_slice(
            &prog.kinsn_emit(load_target, pack_mem_payload(arch, temp_reg, src_base, src_off))?,
        );
        out.extend_from_slice(&prog.kinsn_emit(
            store_target,
            pack_store_reg_payload(arch, temp_reg, dst_base, dst_off),
        )?);
    }
    Ok(out)
}
fn emit_memset_byte_kinsns(
    prog: &ProgramCFG,
    arch: Arch,
    base: u8,
    dst_off: i16,
    fill_byte: u8,
    total_bytes: usize,
) -> anyhow::Result<Vec<BpfInsn>> {
    let mut out = Vec::with_capacity(match arch {
        Arch::X86_64 => total_bytes * 2,
        Arch::Aarch64 => total_bytes * 2,
    });
    for idx in 0..total_bytes {
        let dst_off = checked_byte_offset(dst_off, idx)?;
        let payload = pack_store_imm_payload(arch, base, dst_off, fill_byte);
        match arch {
            Arch::X86_64 => {
                out.extend_from_slice(&prog.kinsn_emit(X86_STOREB_IMM_TARGET, payload)?)
            }
            Arch::Aarch64 if fill_byte == 0 => {
                out.extend_from_slice(&prog.kinsn_emit(ARM64_STOREB_WZR_TARGET, payload)?);
            }
            Arch::Aarch64 => anyhow::bail!(
                "arm64 nonzero memset has no single store-immediate machine instruction"
            ),
        }
    }
    Ok(out)
}
fn checked_byte_offset(base_off: i16, idx: usize) -> anyhow::Result<i16> {
    let off = base_off as i32 + idx as i32;
    i16::try_from(off).map_err(|_| anyhow::anyhow!("bulk_memory byte offset {off} exceeds i16"))
}
fn pack_mem_payload(arch: Arch, dst_reg: u8, base_reg: u8, offset: i16) -> u64 {
    match arch {
        Arch::X86_64 => {
            BpfInsn::pack_u4(4, 0)
                | BpfInsn::pack_u4(dst_reg, 4)
                | BpfInsn::pack_u4(base_reg, 8)
                | BpfInsn::pack_u16(offset as u16, 12)
        }
        Arch::Aarch64 => {
            BpfInsn::pack_u4(dst_reg, 0)
                | BpfInsn::pack_u4(base_reg, 4)
                | BpfInsn::pack_u16(offset as u16, 8)
        }
    }
}
fn pack_store_reg_payload(arch: Arch, src_reg: u8, base_reg: u8, offset: i16) -> u64 {
    match arch {
        Arch::X86_64 => {
            BpfInsn::pack_u4(6, 0)
                | BpfInsn::pack_u4(src_reg, 4)
                | BpfInsn::pack_u4(base_reg, 8)
                | BpfInsn::pack_u16(offset as u16, 12)
        }
        Arch::Aarch64 => {
            BpfInsn::pack_u4(src_reg, 0)
                | BpfInsn::pack_u4(base_reg, 4)
                | BpfInsn::pack_u16(offset as u16, 8)
        }
    }
}
fn pack_store_imm_payload(arch: Arch, base_reg: u8, offset: i16, fill_byte: u8) -> u64 {
    match arch {
        Arch::X86_64 => {
            BpfInsn::pack_u4(7, 0)
                | BpfInsn::pack_u4(base_reg, 4)
                | BpfInsn::pack_u16(offset as u16, 8)
                | BpfInsn::pack_u8(fill_byte, 24)
        }
        Arch::Aarch64 => {
            BpfInsn::pack_u4(base_reg, 0)
                | BpfInsn::pack_u16(offset as u16, 4)
                | BpfInsn::pack_u8(fill_byte, 20)
        }
    }
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
