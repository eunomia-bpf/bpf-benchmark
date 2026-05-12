// SPDX-License-Identifier: MIT
use crate::analysis::{BBProgram, InsnSite, Terminator};
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
    pub(super) old_len: usize,
    pub(super) dst_reg: u8,
    pub(super) src_reg: u8,
    pub(super) offset: i16,
    pub(super) size: u8,
}
struct SafeEndianFusionSite {
    start: InsnSite,
    preserved: Vec<BpfInsn>,
    site: EndianFusionSite,
}
fn scan_endian_site_at(
    prog: &BBProgram,
    start: InsnSite,
) -> anyhow::Result<Option<EndianFusionSite>> {
    let load = prog
        .insn_at(start)
        .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", start))?;
    if !load.is_ldx_mem() {
        return Ok(None);
    }
    let load_size = bpf_size(load.code);
    let dst = load.dst_reg();
    if let Some(next) = next_body_site_in_block(prog, start)? {
        let endian = prog
            .insn_at(next)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", next))?;
        if endian.dst_reg() == dst {
            if let Some(fused_size) =
                endian_swap_size(endian).and_then(|size| fusion_size(load_size, size))
            {
                return Ok(Some(endian_site(load, 2, fused_size)));
            }
        }
    }
    if !matches!(load_size, BPF_W | BPF_DW) {
        return Ok(None);
    }
    let mut old_len = 1usize;
    let mut cursor = start;
    while old_len <= MAX_NARROW_SCAN {
        let Some(next) = next_body_site_in_block(prog, cursor)? else {
            break;
        };
        old_len += 1;
        let insn = prog
            .insn_at(next)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", next))?;
        if insn.dst_reg() == dst {
            if let Some(size) = endian_swap_size(insn) {
                if is_narrowing(load_size, size) {
                    return Ok(Some(endian_site(load, old_len, size)));
                }
            }
        }
        if blocks_narrow_window(insn, dst) {
            break;
        }
        cursor = next;
    }
    Ok(None)
}
fn endian_site(load: &BpfInsn, old_len: usize, size: u8) -> EndianFusionSite {
    EndianFusionSite {
        old_len,
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
    match insn.imm {
        16 => Some(BPF_H),
        32 => Some(BPF_W),
        64 => Some(BPF_DW),
        _ => None,
    }
}
fn fusion_size(load_size: u8, endian_size: u8) -> Option<u8> {
    if matches!(
        (load_size, endian_size),
        (BPF_H, BPF_H) | (BPF_W, BPF_W) | (BPF_DW, BPF_DW)
    ) {
        return Some(load_size);
    }
    if is_narrowing(load_size, endian_size) {
        return Some(endian_size);
    }
    None
}
fn is_narrowing(load_size: u8, endian_size: u8) -> bool {
    matches!(
        (load_size, endian_size),
        (BPF_W, BPF_H) | (BPF_DW, BPF_H) | (BPF_DW, BPF_W)
    )
}
fn find_blocked_narrow_sites(prog: &BBProgram) -> anyhow::Result<Vec<SiteSkipReason>> {
    let mut skips = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        for load_site in prog.sites_in_block(block)? {
            let load = prog
                .insn_at(load_site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", load_site))?;
            if !load.is_ldx_mem() || !matches!(bpf_size(load.code), BPF_W | BPF_DW) {
                continue;
            }
            let load_size = bpf_size(load.code);
            let dst = load.dst_reg();
            let mut read_before_endian = false;
            let mut scanned = 0usize;
            let mut cursor = load_site;
            while scanned < MAX_NARROW_SCAN {
                let Some(next) = next_body_site_in_block(prog, cursor)? else {
                    break;
                };
                scanned += 1;
                let insn = prog
                    .insn_at(next)
                    .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", next))?;
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
                cursor = next;
            }
        }
    }
    Ok(skips)
}
fn blocks_narrow_window(insn: &BpfInsn, reg: u8) -> bool {
    is_window_barrier(insn) || reads_reg(insn, reg) || writes_reg(insn, reg)
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
    match size {
        BPF_H => Some("bpf_endian_load16"),
        BPF_W => Some("bpf_endian_load32"),
        BPF_DW => Some("bpf_endian_load64"),
        _ => None,
    }
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
            let shift = match size {
                BPF_H => 1,
                BPF_W => 2,
                BPF_DW => 3,
                _ => return false,
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
fn endian_fusion_replacement_len(
    dst_reg: u8,
    src_reg: u8,
    offset: i16,
    arch: Arch,
    size: u8,
) -> usize {
    if offset_is_directly_encodable(arch, size, offset) || offset == 0 {
        2
    } else if src_reg != dst_reg && src_reg != BPF_REG_10 {
        4
    } else if dst_reg == src_reg {
        3
    } else {
        4
    }
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
    let mut safe_sites: Vec<SafeEndianFusionSite> = Vec::new();
    let mut skipped = Vec::new();
    skipped.extend(find_blocked_narrow_sites(prog)?);
    for block in prog.block_ids().collect::<Vec<_>>() {
        for start in prog.sites_in_block(block)? {
            if let Some(skip) = cross_block_endian_skip(prog, start)? {
                skipped.push(skip);
                continue;
            }
            let Some(site) = scan_endian_site_at(prog, start)? else {
                continue;
            };
            let replacement_len = endian_fusion_replacement_len(
                site.dst_reg,
                site.src_reg,
                site.offset,
                ctx.platform.arch,
                site.size,
            ) + site.old_len.saturating_sub(2);
            if prog
                .rep_admit_kinsn_site_window(start, site.old_len, replacement_len, &mut skipped)?
                .is_none()
            {
                continue;
            }
            let preserved = preserved_body_insns(prog, start, site.old_len.saturating_sub(2))?;
            safe_sites.push(SafeEndianFusionSite {
                start,
                preserved,
                site,
            });
        }
    }
    if safe_sites.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::unchanged()
        });
    }
    for safe_site in safe_sites.iter().rev() {
        let site = &safe_site.site;
        let kfunc_name = kfunc_name_for_size(site.size)
            .ok_or_else(|| anyhow::anyhow!("unsupported endian fusion size {}", site.size))?;
        let btf_id = ctx.kinsn_registry.btf_id_for_target_name(kfunc_name)?;
        let kfunc_off = ctx.kinsn_registry.call_off_for_target_name(kfunc_name)?;
        let mut replacement = emit_endian_fusion_call(
            site.dst_reg,
            site.src_reg,
            site.offset,
            btf_id,
            kfunc_off,
            ctx.platform.arch,
            site.size,
        );
        replacement.extend_from_slice(&safe_site.preserved);
        prog.replace_range_at(safe_site.start, site.old_len, replacement)?;
    }
    Ok(PassResult {
        sites_applied: safe_sites.len(),
        site_skipped: skipped,
        ..Default::default()
    })
}
fn preserved_body_insns(
    prog: &BBProgram,
    start: InsnSite,
    len: usize,
) -> anyhow::Result<Vec<BpfInsn>> {
    let mut preserved = Vec::with_capacity(len);
    let mut cursor = start;
    for _ in 0..len {
        let Some(next) = next_body_site_in_block(prog, cursor)? else {
            anyhow::bail!(
                "endian fusion preserved window from {:?} exceeds block body",
                start
            );
        };
        preserved.push(*prog.insn(next)?);
        cursor = next;
    }
    Ok(preserved)
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
    if next_body_site_in_block(prog, start)?.is_some() {
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

fn next_body_site_in_block(prog: &BBProgram, site: InsnSite) -> anyhow::Result<Option<InsnSite>> {
    Ok(prog
        .sites_in_block(prog.site_block(site))?
        .windows(2)
        .find_map(|window| (window[0] == site).then_some(window[1])))
}
