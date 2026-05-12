// SPDX-License-Identifier: MIT
use crate::analysis::{BBProgram, InsnSite, MakeReplacement, Terminator};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        canonical_name: "bpf_endian_load16",
        aliases: &["endian_load16"],
        decode_proof: decode_endian_proof,
        register_uses: endian_register_uses,
    },
    KinsnDescriptor {
        canonical_name: "bpf_endian_load32",
        aliases: &["endian_load32"],
        decode_proof: decode_endian_proof,
        register_uses: endian_register_uses,
    },
    KinsnDescriptor {
        canonical_name: "bpf_endian_load64",
        aliases: &["endian_load64"],
        decode_proof: decode_endian_proof,
        register_uses: endian_register_uses,
    },
];
pub struct EndianFusionPass;
const BPF_TO_LE: u8 = 0x00;
const MAX_NARROW_SCAN: usize = 32;
#[derive(Clone, Copy)]
struct EndianWidth {
    size: u8,
    bits: i32,
    target: &'static str,
    aarch64_shift: i16,
}
const ENDIAN_WIDTHS: &[EndianWidth] = &[
    EndianWidth {
        size: BPF_H,
        bits: 16,
        target: "bpf_endian_load16",
        aarch64_shift: 1,
    },
    EndianWidth {
        size: BPF_W,
        bits: 32,
        target: "bpf_endian_load32",
        aarch64_shift: 2,
    },
    EndianWidth {
        size: BPF_DW,
        bits: 64,
        target: "bpf_endian_load64",
        aarch64_shift: 3,
    },
];
fn decode_endian_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(endian_proof_len))
}
fn endian_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("endian dst", kinsn_payload_reg(payload, 0))?;
    validate_bpf_reg("endian base", kinsn_payload_reg(payload, 4))?;
    Ok(2)
}
fn endian_register_uses(payload: u64) -> RegSet {
    [kinsn_payload_reg(payload, 0), kinsn_payload_reg(payload, 4)]
        .into_iter()
        .collect()
}
pub(super) struct EndianFusionSite {
    pub(super) dst_reg: u8,
    pub(super) src_reg: u8,
    pub(super) offset: i16,
    pub(super) size: u8,
}
fn scan_endian_site_in_window(insns: &[BpfInsn]) -> Option<(usize, EndianFusionSite)> {
    let load = insns.first()?;
    if !load.is_ldx_mem() {
        return None;
    }
    let load_size = bpf_size(load.code);
    let dst = load.dst_reg();
    if let Some(endian) = insns.get(1) {
        if endian.dst_reg() == dst {
            if let Some(fused_size) =
                endian_swap_size(endian).and_then(|size| fusion_size(load_size, size))
            {
                return Some((2, endian_site(load, fused_size)));
            }
        }
    }
    if !matches!(load_size, BPF_W | BPF_DW) {
        return None;
    }
    for (scanned, insn) in insns.iter().skip(1).take(MAX_NARROW_SCAN).enumerate() {
        let old_len = scanned + 2;
        if insn.dst_reg() == dst {
            if let Some(size) = endian_swap_size(insn) {
                if is_narrowing(load_size, size) {
                    return Some((old_len, endian_site(load, size)));
                }
            }
        }
        if is_window_barrier(insn) || reads_reg(insn, dst) || writes_reg(insn, dst) {
            break;
        }
    }
    None
}
fn endian_site(load: &BpfInsn, size: u8) -> EndianFusionSite {
    EndianFusionSite {
        dst_reg: load.dst_reg(),
        src_reg: load.src_reg(),
        offset: load.off,
        size,
    }
}
fn endian_swap_size(insn: &BpfInsn) -> Option<u8> {
    if insn.code != (BPF_ALU | BPF_END | BPF_TO_BE)
        && insn.code != (BPF_ALU64 | BPF_END | BPF_TO_LE)
    {
        return None;
    }
    ENDIAN_WIDTHS
        .iter()
        .find(|width| width.bits == insn.imm)
        .map(|width| width.size)
}
fn fusion_size(load_size: u8, endian_size: u8) -> Option<u8> {
    (load_size == endian_size || is_narrowing(load_size, endian_size)).then_some(endian_size)
}
fn is_narrowing(load_size: u8, endian_size: u8) -> bool {
    let load = endian_width(load_size);
    let endian = endian_width(endian_size);
    matches!((load, endian), (Some(load), Some(endian)) if load.aarch64_shift > endian.aarch64_shift)
}
fn find_blocked_narrow_sites(prog: &BBProgram) -> anyhow::Result<Vec<SiteSkipReason>> {
    let mut skips = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        let body = prog.block_body_view(block)?;
        for (start_idx, (&load_site, load)) in body.sites.iter().zip(body.insns).enumerate() {
            if !(load.is_ldx_mem_size(BPF_W) || load.is_ldx_mem_size(BPF_DW)) {
                continue;
            }
            let load_size = bpf_size(load.code);
            let dst = load.dst_reg();
            let mut read_before_endian = false;
            for insn in body.insns.iter().skip(start_idx + 1).take(MAX_NARROW_SCAN) {
                if insn.dst_reg() == dst
                    && endian_swap_size(insn).is_some_and(|size| is_narrowing(load_size, size))
                {
                    if read_before_endian {
                        skips.push(SiteSkipReason {
                            site: load_site,
                            reason: "narrow endian fusion blocked: possible upper bits read before endian".into(),
                        });
                    }
                    break;
                }
                if is_window_barrier(insn) || writes_reg(insn, dst) {
                    break;
                }
                read_before_endian |= reads_reg(insn, dst);
            }
        }
    }
    Ok(skips)
}
fn is_window_barrier(insn: &BpfInsn) -> bool {
    insn.is_ldimm64() || insn.is_jmp_class()
}
fn reads_reg(insn: &BpfInsn, reg: u8) -> bool {
    if insn.is_call() {
        return (BPF_REG_1..=BPF_REG_5).contains(&reg);
    }
    if insn.is_exit() {
        return reg == BPF_REG_0;
    }
    (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
        || (matches!(insn.class(), BPF_ALU64 | BPF_ALU | BPF_ST | BPF_STX) && insn.dst_reg() == reg)
        || (matches!(insn.class(), BPF_JMP | BPF_JMP32) && !insn.is_ja() && insn.dst_reg() == reg)
        || (insn.class() == BPF_LDX && insn.src_reg() == reg)
}
fn writes_reg(insn: &BpfInsn, reg: u8) -> bool {
    if insn.is_call() {
        return reg <= BPF_REG_5;
    }
    matches!(insn.class(), BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD) && insn.dst_reg() == reg
}
fn kfunc_name_for_size(size: u8) -> Option<&'static str> {
    endian_width(size).map(|width| width.target)
}
fn endian_width(size: u8) -> Option<EndianWidth> {
    ENDIAN_WIDTHS
        .iter()
        .find(|width| width.size == size)
        .copied()
}
pub(super) fn endian_payload(dst_reg: u8, base_reg: u8, offset: i16) -> u64 {
    BpfInsn::pack_u4(dst_reg, 0)
        | BpfInsn::pack_u4(base_reg, 4)
        | BpfInsn::pack_u16(offset as u16, 8)
}
fn offset_is_directly_encodable(arch: Arch, size: u8, offset: i16) -> bool {
    match arch {
        Arch::X86_64 => true,
        Arch::Aarch64 => {
            let shift = match endian_width(size) {
                Some(width) => width.aarch64_shift,
                None => return false,
            };
            (offset >= 0 && offset <= (0x0fff << shift) && (offset & ((1 << shift) - 1)) == 0)
                || (-256..=255).contains(&offset)
        }
    }
}
fn emit_endian_fusion_call(
    dst_reg: u8,
    src_reg: u8,
    offset: i16,
    btf_id: i32,
    kfunc_off: i16,
    arch: Arch,
    size: u8,
) -> Vec<BpfInsn> {
    let direct_offset = offset_is_directly_encodable(arch, size, offset);
    let mut out = Vec::with_capacity(if direct_offset || offset == 0 {
        2
    } else if src_reg != dst_reg && src_reg != 10 {
        4
    } else if dst_reg == src_reg {
        3
    } else {
        4
    });
    if direct_offset {
        out.extend_from_slice(&emit_packed_kinsn_call_with_off(
            endian_payload(dst_reg, src_reg, offset),
            btf_id,
            kfunc_off,
        ));
        return out;
    }
    let base_reg = if offset == 0 {
        src_reg
    } else if src_reg != dst_reg && src_reg != 10 {
        out.push(BpfInsn::alu64_imm(BPF_ADD, src_reg, offset as i32));
        out.extend_from_slice(&emit_packed_kinsn_call_with_off(
            endian_payload(dst_reg, src_reg, 0),
            btf_id,
            kfunc_off,
        ));
        out.push(BpfInsn::alu64_imm(BPF_ADD, src_reg, -(offset as i32)));
        return out;
    } else {
        if dst_reg != src_reg {
            out.push(BpfInsn::mov64_reg(dst_reg, src_reg));
        }
        out.push(BpfInsn::alu64_imm(BPF_ADD, dst_reg, offset as i32));
        dst_reg
    };
    out.extend_from_slice(&emit_packed_kinsn_call_with_off(
        endian_payload(dst_reg, base_reg, 0),
        btf_id,
        kfunc_off,
    ));
    out
}
impl BpfPass for EndianFusionPass {
    fn name(&self) -> &str {
        "endian_fusion"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}
pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    let mut skipped = Vec::new();
    skipped.extend(find_blocked_narrow_sites(prog)?);
    for block in prog.block_ids().collect::<Vec<_>>() {
        for start in prog.sites_in_block(block)? {
            if let Some(skip) = cross_block_endian_skip(prog, start)? {
                skipped.push(skip);
            }
        }
    }
    let raw_sites = prog.scan_block_starts(MAX_NARROW_SCAN + 1, |window| {
        Ok(scan_endian_site_in_window(window.lookahead)
            .map(|(old_len, site)| window.hit(window.start_idx, old_len, site)))
    })?;
    if raw_sites.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::unchanged()
        });
    }
    let mut applied = 0usize;
    for hit in raw_sites.iter().rev() {
        let site = &hit.value;
        let kfunc_name = kfunc_name_for_size(site.size)
            .ok_or_else(|| anyhow::anyhow!("unsupported endian fusion size {}", site.size))?;
        let (btf_id, kfunc_off) = prog.kinsn_call(kfunc_name)?;
        let preserved = preserved_body_insns(prog, hit.start, hit.old_len.saturating_sub(2))?;
        let mut replacement = emit_endian_fusion_call(
            site.dst_reg,
            site.src_reg,
            site.offset,
            btf_id,
            kfunc_off,
            ctx.platform.arch,
            site.size,
        );
        replacement.extend_from_slice(&preserved);
        if prog.try_replace_range_with_skips(
            hit.start,
            hit.old_len,
            replacement.len(),
            &mut skipped,
            || Ok(MakeReplacement::Use(replacement)),
        )? {
            applied += 1;
        }
    }
    Ok(PassResult {
        sites_applied: applied,
        site_skipped: skipped,
        ..Default::default()
    })
}
fn preserved_body_insns(
    prog: &BBProgram,
    start: InsnSite,
    len: usize,
) -> anyhow::Result<Vec<BpfInsn>> {
    let body = prog.block_body_view(prog.site_block(start))?;
    let preserve_start = start
        .idx
        .checked_add(1)
        .ok_or_else(|| anyhow::anyhow!("endian fusion preserve start overflows"))?;
    let preserve_end = preserve_start
        .checked_add(len)
        .ok_or_else(|| anyhow::anyhow!("endian fusion preserve end overflows"))?;
    Ok(body
        .insns
        .get(preserve_start..preserve_end)
        .ok_or_else(|| {
            anyhow::anyhow!(
                "endian fusion preserved window from {:?} exceeds block body",
                start
            )
        })?
        .to_vec())
}
fn cross_block_endian_skip(
    prog: &BBProgram,
    start: InsnSite,
) -> anyhow::Result<Option<SiteSkipReason>> {
    let load = prog
        .insn_at(start)
        .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", start))?;
    if !load.is_ldx_mem() {
        return Ok(None);
    }
    let body = prog.block_body_view(prog.site_block(start))?;
    if start.idx + 1 < body.sites.len() {
        return Ok(None);
    }
    let start_block = prog.site_block(start);
    let next_block = match prog.terminator_at_site(start)? {
        Terminator::Fallthrough { next } => next,
        _ => return Ok(None),
    };
    let successors = prog.successors(start_block);
    if successors.len() != 1 || successors[0] != next_block {
        anyhow::bail!(
            "fallthrough block {:?} has inconsistent successors",
            start_block
        );
    }
    let Some(next) = prog.sites_in_block(next_block)?.first().copied() else {
        return Ok(None);
    };
    let endian = prog
        .insn_at(next)
        .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", next))?;
    let load_size = bpf_size(load.code);
    let matches_cross_block = endian.dst_reg() == load.dst_reg()
        && endian_swap_size(endian)
            .and_then(|size| fusion_size(load_size, size))
            .is_some();
    Ok(matches_cross_block.then_some(SiteSkipReason {
        site: start,
        reason: "interior branch target".into(),
    }))
}
