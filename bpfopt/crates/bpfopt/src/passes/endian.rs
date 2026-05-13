// SPDX-License-Identifier: MIT
use crate::analysis::{insn_use_def_set, InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: "bpf_endian_load16",
        register_uses: endian_register_uses,
        register_defs: endian_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_endian_load32",
        register_uses: endian_register_uses,
        register_defs: endian_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_endian_load64",
        register_uses: endian_register_uses,
        register_defs: endian_register_defs,
    },
];
pub struct EndianFusionPass;
const BPF_TO_LE: u8 = 0x00;
const MAX_NARROW_SCAN: usize = 32;

fn endian_target(w: BpfMemWidth) -> Option<&'static str> {
    match w {
        BpfMemWidth::H => Some("bpf_endian_load16"),
        BpfMemWidth::W => Some("bpf_endian_load32"),
        BpfMemWidth::DW => Some("bpf_endian_load64"),
        BpfMemWidth::B => None,
    }
}
fn endian_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[4])
}
fn endian_register_defs(payload: u64) -> RegSet {
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
    (endian_target(width).is_some()).then(|| width.size_opcode())
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
            if endian_target(width).is_none() {
                return false;
            }
            let shift = width.aarch64_shift();
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
            Ok(scan_endian_site_in_window(window.lookahead)
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
                let kfunc_name = BpfMemWidth::from_size_opcode(site.size)
                    .and_then(endian_target)
                    .ok_or_else(|| {
                        anyhow::anyhow!("unsupported endian fusion size {}", site.size)
                    })?;
                let (btf_id, kfunc_off) = prog.kinsn_call(kfunc_name)?;
                let preserved = preserved_body_insns(prog, start, old_len.saturating_sub(2))?;
                let mut replacement = emit_endian_fusion_call(
                    site.dst_reg,
                    site.src_reg,
                    site.offset,
                    btf_id,
                    kfunc_off,
                    ctx.arch,
                    site.size,
                );
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
        .to_vec())
}
