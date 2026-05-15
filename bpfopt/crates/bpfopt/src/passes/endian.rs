// SPDX-License-Identifier: MIT
use crate::analysis::{insn_use_def_set, InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: "bpf_x86_movzwl_mem",
        register_uses: endian_load_register_uses,
        register_defs: endian_load_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_x86_movl_mem",
        register_uses: endian_load_register_uses,
        register_defs: endian_load_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_x86_movq_mem",
        register_uses: endian_load_register_uses,
        register_defs: endian_load_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_x86_rolw_imm",
        register_uses: endian_unary_register_uses,
        register_defs: endian_unary_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_x86_bswapl",
        register_uses: endian_unary_register_uses,
        register_defs: endian_unary_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_x86_bswapq",
        register_uses: endian_unary_register_uses,
        register_defs: endian_unary_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_ldrh_mem",
        register_uses: endian_load_register_uses,
        register_defs: endian_load_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_ldr_w_mem",
        register_uses: endian_load_register_uses,
        register_defs: endian_load_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_ldr_x_mem",
        register_uses: endian_load_register_uses,
        register_defs: endian_load_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_rev16_w",
        register_uses: endian_unary_register_uses,
        register_defs: endian_unary_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_rev_w",
        register_uses: endian_unary_register_uses,
        register_defs: endian_unary_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_rev_x",
        register_uses: endian_unary_register_uses,
        register_defs: endian_unary_register_defs,
    },
];
pub struct EndianFusionPass;
const BPF_TO_LE: u8 = 0x00;
const MAX_NARROW_SCAN: usize = 32;

fn endian_load_target(arch: Arch, w: BpfMemWidth) -> Option<&'static str> {
    match (arch, w) {
        (Arch::X86_64, BpfMemWidth::H) => Some("bpf_x86_movzwl_mem"),
        (Arch::X86_64, BpfMemWidth::W) => Some("bpf_x86_movl_mem"),
        (Arch::X86_64, BpfMemWidth::DW) => Some("bpf_x86_movq_mem"),
        (Arch::Aarch64, BpfMemWidth::H) => Some("bpf_arm64_ldrh_mem"),
        (Arch::Aarch64, BpfMemWidth::W) => Some("bpf_arm64_ldr_w_mem"),
        (Arch::Aarch64, BpfMemWidth::DW) => Some("bpf_arm64_ldr_x_mem"),
        (_, BpfMemWidth::B) => None,
    }
}
fn endian_swap_target(arch: Arch, w: BpfMemWidth) -> Option<&'static str> {
    match (arch, w) {
        (Arch::X86_64, BpfMemWidth::H) => Some("bpf_x86_rolw_imm"),
        (Arch::X86_64, BpfMemWidth::W) => Some("bpf_x86_bswapl"),
        (Arch::X86_64, BpfMemWidth::DW) => Some("bpf_x86_bswapq"),
        (Arch::Aarch64, BpfMemWidth::H) => Some("bpf_arm64_rev16_w"),
        (Arch::Aarch64, BpfMemWidth::W) => Some("bpf_arm64_rev_w"),
        (Arch::Aarch64, BpfMemWidth::DW) => Some("bpf_arm64_rev_x"),
        (_, BpfMemWidth::B) => None,
    }
}
fn endian_supported_width(w: BpfMemWidth) -> bool {
    !matches!(w, BpfMemWidth::B)
}
fn endian_load_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[4])
}
fn endian_load_register_defs(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}
fn endian_unary_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}
fn endian_unary_register_defs(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
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
    let make_site = |size: u8| EndianFusionSite {
        dst_reg: dst,
        src_reg: load.src_reg(),
        offset: load.off,
        size,
    };
    if let Some(endian) = insns.get(1) {
        if endian.dst_reg() == dst {
            if let Some(fused_size) = endian_swap_size(endian).and_then(|size| {
                (load_size == size || is_narrowing(load_size, size)).then_some(size)
            }) {
                return Some((2, make_site(fused_size)));
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
                    return Some((old_len, make_site(size)));
                }
            }
        }
        if insn.is_ldimm64() || insn.is_jmp_class() {
            break;
        }
        let ud = insn_use_def_set(insn);
        if ud.uses.contains(&dst) || ud.defs.contains(&dst) {
            break;
        }
    }
    None
}
fn endian_swap_size(insn: &BpfInsn) -> Option<u8> {
    if insn.code != (BPF_ALU | BPF_END | BPF_TO_BE)
        && insn.code != (BPF_ALU64 | BPF_END | BPF_TO_LE)
    {
        return None;
    }
    let width = BpfMemWidth::from_bytes((insn.imm / 8) as usize)?;
    endian_supported_width(width).then(|| width.size_opcode())
}
fn is_narrowing(load_size: u8, endian_size: u8) -> bool {
    let load = BpfMemWidth::from_size_opcode(load_size);
    let endian = BpfMemWidth::from_size_opcode(endian_size);
    matches!((load, endian), (Some(load), Some(endian)) if load.aarch64_shift() > endian.aarch64_shift())
}
fn find_blocked_narrow_sites(prog: &ProgramCFG) -> anyhow::Result<Vec<SiteSkipReason>> {
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
                        skips.push(SiteSkipReason::new(
                            load_site,
                            "narrow endian fusion blocked: possible upper bits read before endian",
                        ));
                    }
                    break;
                }
                if insn.is_ldimm64() || insn.is_jmp_class() {
                    break;
                }
                let ud = insn_use_def_set(insn);
                if ud.defs.contains(&dst) {
                    break;
                }
                read_before_endian |= ud.uses.contains(&dst);
            }
        }
    }
    Ok(skips)
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
            let Some(width) = BpfMemWidth::from_size_opcode(size) else {
                return false;
            };
            if !endian_supported_width(width) {
                return false;
            }
            let shift = width.aarch64_shift();
            (offset >= 0 && offset <= (0x0fff << shift) && (offset & ((1 << shift) - 1)) == 0)
                || (-256..=255).contains(&offset)
        }
    }
}
fn endian_reg_payload(dst_reg: u8) -> u64 {
    BpfInsn::pack_u4(dst_reg, 0)
}
fn endian_reg_imm_payload(dst_reg: u8, imm: u8) -> u64 {
    BpfInsn::pack_u4(dst_reg, 0) | BpfInsn::pack_u8(imm, 8)
}
fn append_endian_kinsns(
    out: &mut Vec<BpfInsn>,
    prog: &ProgramCFG,
    dst_reg: u8,
    base_reg: u8,
    offset: i16,
    arch: Arch,
    size: u8,
) -> anyhow::Result<()> {
    let width = BpfMemWidth::from_size_opcode(size)
        .ok_or_else(|| anyhow::anyhow!("unsupported endian fusion size {}", size))?;
    let load_name = endian_load_target(arch, width)
        .ok_or_else(|| anyhow::anyhow!("unsupported endian fusion load size {}", size))?;
    let swap_name = endian_swap_target(arch, width)
        .ok_or_else(|| anyhow::anyhow!("unsupported endian fusion swap size {}", size))?;

    out.extend_from_slice(&prog.kinsn_emit(load_name, endian_payload(dst_reg, base_reg, offset))?);
    let swap_payload = if matches!((arch, width), (Arch::X86_64, BpfMemWidth::H)) {
        endian_reg_imm_payload(dst_reg, 8)
    } else {
        endian_reg_payload(dst_reg)
    };
    out.extend_from_slice(&prog.kinsn_emit(swap_name, swap_payload)?);
    Ok(())
}
fn emit_endian_fusion_call(
    prog: &ProgramCFG,
    dst_reg: u8,
    src_reg: u8,
    offset: i16,
    arch: Arch,
    size: u8,
) -> anyhow::Result<Vec<BpfInsn>> {
    let direct_offset = offset_is_directly_encodable(arch, size, offset);
    let mut out = Vec::new();
    if direct_offset {
        append_endian_kinsns(&mut out, prog, dst_reg, src_reg, offset, arch, size)?;
        return Ok(out);
    }
    let base_reg = if offset == 0 {
        src_reg
    } else if src_reg != dst_reg && src_reg != 10 {
        out.push(BpfInsn::alu64_imm(BPF_ADD, src_reg, offset as i32));
        append_endian_kinsns(&mut out, prog, dst_reg, src_reg, 0, arch, size)?;
        out.push(BpfInsn::alu64_imm(BPF_ADD, src_reg, -(offset as i32)));
        return Ok(out);
    } else {
        if dst_reg != src_reg {
            out.push(BpfInsn::mov64_reg(dst_reg, src_reg));
        }
        out.push(BpfInsn::alu64_imm(BPF_ADD, dst_reg, offset as i32));
        dst_reg
    };
    append_endian_kinsns(&mut out, prog, dst_reg, base_reg, 0, arch, size)?;
    Ok(out)
}
impl BpfPass for EndianFusionPass {
    fn run(&self, prog: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        let mut skipped = Vec::new();
        skipped.extend(find_blocked_narrow_sites(prog)?);
        skipped.extend(collect_cross_block_pair_skips(
            prog,
            |load, endian| {
                if !load.is_ldx_mem() || endian.dst_reg() != load.dst_reg() {
                    return false;
                }
                let load_size = bpf_size(load.code);
                endian_swap_size(endian)
                    .map(|size| load_size == size || is_narrowing(load_size, size))
                    .unwrap_or(false)
            },
            "interior branch target",
        )?);
        let raw_sites = prog.scan_block_starts(MAX_NARROW_SCAN + 1, |window| {
            Ok(scan_endian_site_in_window(&window.bpf_lookahead())
                .map(|(old_len, site)| (window.start_idx, old_len, site)))
        })?;
        if raw_sites.is_empty() {
            return Ok(PassResult::with_sites(0, skipped));
        }
        let candidates: Vec<(InsnSite, (EndianFusionSite, usize))> = raw_sites
            .into_iter()
            .map(|hit| (hit.start, (hit.value, hit.old_len)))
            .collect();
        let applied =
            apply_candidates_reverse(prog, &candidates, &mut skipped, |prog, start, payload| {
                let (site, old_len) = payload;
                let preserved = preserved_body_insns(prog, start, old_len.saturating_sub(2))?;
                let mut replacement = emit_endian_fusion_call(
                    prog,
                    site.dst_reg,
                    site.src_reg,
                    site.offset,
                    ctx.arch,
                    site.size,
                )?;
                replacement.extend_from_slice(&preserved);
                Ok((*old_len, replacement))
            })?;
        Ok(PassResult::with_sites(applied, skipped))
    }
}

fn preserved_body_insns(
    prog: &ProgramCFG,
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
        .iter()
        .map(|n| n.insn)
        .collect::<Vec<_>>())
}
