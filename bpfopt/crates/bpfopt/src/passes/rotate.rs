// SPDX-License-Identifier: MIT
use crate::analysis::{BlockId, InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: "bpf_x86_rolq_imm",
        register_uses: rotate_register_uses,
        register_defs: rotate_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_x86_rorxl_imm",
        register_uses: rotate_register_uses,
        register_defs: rotate_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_extr_x",
        register_uses: rotate_register_uses,
        register_defs: rotate_register_defs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_extr_w",
        register_uses: rotate_register_uses,
        register_defs: rotate_register_defs,
    },
];

fn rotate_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[4])
}

fn rotate_register_defs(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}
pub struct RotatePass;

impl BpfPass for RotatePass {
    fn run(&self, prog: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        let mut skipped = Vec::new();
        let prog_ref: &ProgramCFG = prog;
        let candidates: Vec<(InsnSite, RotateSite)> = prog_ref
            .scan_block_starts(7, |window| {
                Ok(rotate_site_at(
                    prog_ref,
                    window.block,
                    &window.bpf_insns(),
                    window.start_idx,
                )
                .map(|site| (site.start_idx, site.old_len, site)))
            })?
            .into_iter()
            .map(|hit| (hit.start, hit.value))
            .collect();

        if candidates.is_empty() {
            return Ok(PassResult::with_sites(0, skipped));
        }

        // tmp_reg liveness pre-check: skip sites whose replacement drops the
        // original tmp_reg value while it is still read after the window.
        let mut applicable = Vec::with_capacity(candidates.len());
        for (start, site) in candidates {
            if site.clobbers_tmp
                && prog
                    .live_out_after_window(start, site.old_len)?
                    .contains(&site.tmp_reg)
            {
                skipped.push(SiteSkipReason::new(
                    start,
                    format!("tmp_reg r{} is live after site", site.tmp_reg),
                ));
            } else {
                applicable.push((start, site));
            }
        }

        let applied =
            apply_candidates_reverse(prog, &applicable, &mut skipped, |prog, _start, site| {
                let shift_amount = u8::try_from(site.shift_amount).map_err(|_| {
                    anyhow::anyhow!(
                        "rotate shift amount {} exceeds packed payload width",
                        site.shift_amount
                    )
                })?;
                Ok((site.old_len, emit_rotate_replacement(prog, ctx.arch, site, shift_amount)?))
            })?;

        Ok(PassResult::with_sites(applied, skipped))
    }
}

fn rotate_site_at(
    prog: &ProgramCFG,
    block: BlockId,
    insns: &[BpfInsn],
    idx: usize,
) -> Option<RotateSite> {
    let [i0, i1, i2] = insns.get(idx..idx + 3)? else {
        return None;
    };
    try_match_rotate(prog, block, insns, i0, i1, i2, idx)
}

pub(super) struct RotateSite {
    pub(super) start_idx: usize,
    pub(super) old_len: usize,
    pub(super) dst_reg: u8,
    pub(super) val_reg: u8,
    pub(super) tmp_reg: u8,
    pub(super) shift_amount: u32,
    pub(super) width: RotateWidth,
    pub(super) clobbers_tmp: bool,
}
#[repr(u8)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(super) enum RotateWidth {
    W32 = BPF_ALU,
    W64 = BPF_ALU64,
}

impl RotateWidth {
    const MATCH_ORDER: [Self; 2] = [Self::W64, Self::W32];

    fn bits(self) -> u32 {
        match self {
            Self::W32 => 32,
            Self::W64 => 64,
        }
    }

    fn alu_class(self) -> u8 {
        self as u8
    }

    fn target_name(self, arch: Arch) -> &'static str {
        match (arch, self) {
            (Arch::X86_64, Self::W32) => "bpf_x86_rorxl_imm",
            (Arch::X86_64, Self::W64) => "bpf_x86_rolq_imm",
            (Arch::Aarch64, Self::W32) => "bpf_arm64_extr_w",
            (Arch::Aarch64, Self::W64) => "bpf_arm64_extr_x",
        }
    }
}

fn emit_rotate_replacement(
    prog: &ProgramCFG,
    arch: Arch,
    site: &RotateSite,
    shift_amount: u8,
) -> anyhow::Result<Vec<BpfInsn>> {
    let mut replacement = Vec::new();
    let (call_dst, call_src) = if arch == Arch::X86_64 && site.width == RotateWidth::W64 {
        if site.dst_reg != site.val_reg {
            replacement.push(BpfInsn::mov64_reg(site.dst_reg, site.val_reg));
        }
        (site.dst_reg, site.dst_reg)
    } else {
        (site.dst_reg, site.val_reg)
    };
    let payload = BpfInsn::pack_u4(call_dst, 0)
        | BpfInsn::pack_u4(call_src, 4)
        | BpfInsn::pack_u8(shift_amount, 8)
        | BpfInsn::pack_u4(site.tmp_reg, 16);
    replacement.extend_from_slice(&prog.kinsn_emit(site.width.target_name(arch), payload)?);
    Ok(replacement)
}
fn find_provenance_mov(
    insns: &[BpfInsn],
    shift_idx: usize,
    tmp: u8,
    dst: u8,
    width: RotateWidth,
) -> Option<usize> {
    if shift_idx == 0 {
        return None;
    }

    let mov_idx = shift_idx - 1;
    let insn = &insns[mov_idx];
    if insn.dst_reg() != tmp || insn.src_reg() != dst {
        return None;
    }

    is_reg_mov_for_width(insn, width).then_some(mov_idx)
}

fn is_reg_mov_for_width(insn: &BpfInsn, width: RotateWidth) -> bool {
    insn.is_alu_reg(BPF_ALU64, BPF_MOV)
        || (width == RotateWidth::W32 && insn.is_alu_reg(BPF_ALU, BPF_MOV))
}

fn try_match_rotate(
    prog: &ProgramCFG,
    block: BlockId,
    insns: &[BpfInsn],
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    idx: usize,
) -> Option<RotateSite> {
    RotateWidth::MATCH_ORDER
        .into_iter()
        .find_map(|width| try_match_split_copy_rotate_width(insns, idx, width))
        .or_else(|| try_match_masked32_rotate(prog, block, insns, idx))
        .or_else(|| {
            RotateWidth::MATCH_ORDER
                .into_iter()
                .find_map(|width| try_match_rotate_width(insns, i0, i1, i2, idx, width))
        })
}

fn try_match_masked32_rotate(
    prog: &ProgramCFG,
    block: BlockId,
    insns: &[BpfInsn],
    idx: usize,
) -> Option<RotateSite> {
    let mov_rsh = insns.get(idx)?;

    if !mov_rsh.is_alu_reg(BPF_ALU64, BPF_MOV) {
        return None;
    }

    let val_reg = mov_rsh.src_reg();
    let rsh_reg = mov_rsh.dst_reg();
    let (and_idx, preserves_mask_load) =
        masked32_and_index(insns, idx + 1, val_reg, rsh_reg).unwrap_or((idx + 1, false));
    let [and_mask, rsh, i3, i4] = insns.get(and_idx..and_idx + 4)? else {
        return None;
    };
    let (start_idx, old_len, clobbers_tmp, lsh, or_insn, lsh_reg) =
        if i3.is_alu_reg(BPF_ALU64, BPF_MOV) {
            if i3.src_reg() != val_reg {
                return None;
            }
            let or_idx = and_idx + 4;
            let start_idx = if preserves_mask_load { and_idx } else { idx };
            (
                start_idx,
                or_idx + 1 - start_idx,
                true,
                i4,
                insns.get(or_idx)?,
                i3.dst_reg(),
            )
        } else {
            if !is_zero_extend32_pair(insns.get(and_idx + 4)?, insns.get(and_idx + 5)?, val_reg) {
                return None;
            }
            (and_idx + 2, 2, false, i3, i4, val_reg)
        };
    if rsh_reg == lsh_reg {
        return None;
    }

    if !and_mask.is_alu_reg(BPF_ALU64, BPF_AND)
        || and_mask.dst_reg() != rsh_reg
        || !rsh.is_alu_imm(BPF_ALU64, BPF_RSH)
        || rsh.dst_reg() != rsh_reg
        || !lsh.is_alu_imm(BPF_ALU64, BPF_LSH)
        || lsh.dst_reg() != lsh_reg
        || !or_insn.is_alu_reg(BPF_ALU64, BPF_OR)
    {
        return None;
    }

    let rsh_amount = u32::try_from(rsh.imm).ok()?;
    let lsh_amount = u32::try_from(lsh.imm).ok()?;
    if rsh_amount == 0 || lsh_amount == 0 || rsh_amount + lsh_amount != 32 {
        return None;
    }

    let mask = and_mask_value(prog, block, insns, and_idx, and_mask)?;
    if mask != high32_rotate_mask(rsh_amount)? {
        return None;
    }

    let or_dst = or_insn.dst_reg();
    let or_src = or_insn.src_reg();
    if !uses_both_regs(or_dst, or_src, lsh_reg, rsh_reg) {
        return None;
    }
    let tmp_reg = if or_dst == rsh_reg { lsh_reg } else { rsh_reg };

    let mut site = rotate_site(
        start_idx,
        old_len,
        or_dst,
        val_reg,
        tmp_reg,
        lsh_amount,
        RotateWidth::W32,
    )?;
    site.clobbers_tmp = clobbers_tmp;
    Some(site)
}

fn masked32_and_index(
    insns: &[BpfInsn],
    idx: usize,
    val_reg: u8,
    rsh_reg: u8,
) -> Option<(usize, bool)> {
    if is_and_insn(insns.get(idx)?) {
        return Some((idx, false));
    }

    let mask_load = insns.get(idx)?;
    let (mask_reg, and_idx) = if mask_load.is_ldimm64() {
        (mask_load.dst_reg(), idx + 1)
    } else if mask_load.is_alu_imm(BPF_ALU64, BPF_MOV) || mask_load.is_alu_imm(BPF_ALU, BPF_MOV) {
        (mask_load.dst_reg(), idx + 1)
    } else {
        return None;
    };
    if mask_reg == val_reg || mask_reg == rsh_reg {
        return None;
    }

    let and_insn = insns.get(and_idx)?;
    (and_insn.is_alu_reg(BPF_ALU64, BPF_AND) && and_insn.src_reg() == mask_reg)
        .then_some((and_idx, true))
}

fn is_and_insn(insn: &BpfInsn) -> bool {
    insn.is_alu_reg(BPF_ALU64, BPF_AND) || insn.is_alu_imm(BPF_ALU64, BPF_AND)
}

fn high32_rotate_mask(rsh_amount: u32) -> Option<u64> {
    (rsh_amount < 32).then_some((u64::from(u32::MAX) << rsh_amount) & u64::from(u32::MAX))
}

fn is_zero_extend32_pair(i0: &BpfInsn, i1: &BpfInsn, reg: u8) -> bool {
    i0.is_alu_imm(BPF_ALU64, BPF_LSH)
        && i0.dst_reg() == reg
        && i0.imm == 32
        && i1.is_alu_imm(BPF_ALU64, BPF_RSH)
        && i1.dst_reg() == reg
        && i1.imm == 32
}

fn and_mask_value(
    prog: &ProgramCFG,
    block: BlockId,
    insns: &[BpfInsn],
    and_idx: usize,
    and_insn: &BpfInsn,
) -> Option<u64> {
    if and_insn.is_alu_imm(BPF_ALU64, BPF_AND) {
        return Some((and_insn.imm as u32).into());
    }

    if !and_insn.is_alu_reg(BPF_ALU64, BPF_AND) {
        return None;
    }

    find_const_reg_value_before(prog, block, insns, and_idx, and_insn.src_reg())
}

fn find_const_reg_value_before(
    prog: &ProgramCFG,
    block: BlockId,
    insns: &[BpfInsn],
    idx: usize,
    reg: u8,
) -> Option<u64> {
    let mut scan = idx;
    while scan > 0 {
        scan -= 1;
        let insn = &insns[scan];
        if writes_reg(insn, reg) {
            if insn.is_ldimm64() {
                let hi = prog.ldimm64_second_slot(InsnSite { block, idx: scan })?;
                return Some(decode_ldimm64_value(insn, hi));
            }
            if insn.is_alu_imm(BPF_ALU64, BPF_MOV) || insn.is_alu_imm(BPF_ALU, BPF_MOV) {
                return Some((insn.imm as u32).into());
            }
            return None;
        }
    }
    None
}

fn writes_reg(insn: &BpfInsn, reg: u8) -> bool {
    if insn.code == 0 {
        return false;
    }
    if insn.dst_reg() != reg {
        return false;
    }

    matches!(bpf_class(insn.code), BPF_LD | BPF_LDX | BPF_ALU | BPF_ALU64)
}

fn try_match_split_copy_rotate_width(
    insns: &[BpfInsn],
    idx: usize,
    width: RotateWidth,
) -> Option<RotateSite> {
    let [mov0, shift0, mov1, shift1, or_insn] = insns.get(idx..idx + 5)? else {
        return None;
    };

    if !is_reg_mov_for_width(mov0, width) || !is_reg_mov_for_width(mov1, width) {
        return None;
    }

    let val_reg = mov0.src_reg();
    if mov1.src_reg() != val_reg {
        return None;
    }

    let reg0 = mov0.dst_reg();
    let reg1 = mov1.dst_reg();
    if reg0 == reg1 || shift0.dst_reg() != reg0 || shift1.dst_reg() != reg1 {
        return None;
    }

    let (lsh_amount, _, _) = checked_shift_pair(shift0, shift1, width)?;

    let alu_class = width.alu_class();
    if !or_insn.is_alu_reg(alu_class, BPF_OR) {
        return None;
    }

    let or_dst = or_insn.dst_reg();
    let or_src = or_insn.src_reg();
    if !uses_both_regs(or_dst, or_src, reg0, reg1) {
        return None;
    }

    rotate_site(idx, 5, or_dst, val_reg, or_src, lsh_amount, width)
}

fn try_match_rotate_width(
    insns: &[BpfInsn],
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    idx: usize,
    width: RotateWidth,
) -> Option<RotateSite> {
    let alu_class = width.alu_class();
    if !i2.is_alu_reg(alu_class, BPF_OR) {
        return None;
    }
    let (lsh_amount, lsh_reg, rsh_reg) = checked_shift_pair(i0, i1, width)?;
    let or_dst = i2.dst_reg();
    let or_src = i2.src_reg();
    if !uses_both_regs(or_dst, or_src, lsh_reg, rsh_reg) {
        return None;
    }

    for (tmp_reg, val_reg) in [(rsh_reg, lsh_reg), (lsh_reg, rsh_reg)] {
        if let Some(mov_idx) = find_provenance_mov(insns, idx, tmp_reg, val_reg, width) {
            return rotate_site(
                mov_idx,
                (idx + 3) - mov_idx,
                or_dst,
                val_reg,
                tmp_reg,
                lsh_amount,
                width,
            );
        }
    }

    None
}

fn checked_shift_pair(i0: &BpfInsn, i1: &BpfInsn, width: RotateWidth) -> Option<(u32, u8, u8)> {
    let alu_class = width.alu_class();
    let (lsh_amount, rsh_amount, lsh_reg, rsh_reg) =
        if i0.is_alu_imm(alu_class, BPF_RSH) && i1.is_alu_imm(alu_class, BPF_LSH) {
            (i1.imm as u32, i0.imm as u32, i1.dst_reg(), i0.dst_reg())
        } else if i0.is_alu_imm(alu_class, BPF_LSH) && i1.is_alu_imm(alu_class, BPF_RSH) {
            (i0.imm as u32, i1.imm as u32, i0.dst_reg(), i1.dst_reg())
        } else {
            return None;
        };
    (lsh_amount + rsh_amount == width.bits() && lsh_reg != rsh_reg)
        .then_some((lsh_amount, lsh_reg, rsh_reg))
}

fn uses_both_regs(dst: u8, src: u8, reg0: u8, reg1: u8) -> bool {
    (dst == reg0 && src == reg1) || (dst == reg1 && src == reg0)
}

fn rotate_site(
    start_idx: usize,
    old_len: usize,
    dst_reg: u8,
    val_reg: u8,
    tmp_reg: u8,
    shift_amount: u32,
    width: RotateWidth,
) -> Option<RotateSite> {
    (dst_reg != tmp_reg && val_reg != tmp_reg).then_some(RotateSite {
        start_idx,
        old_len,
        dst_reg,
        val_reg,
        tmp_reg,
        shift_amount,
        width,
        clobbers_tmp: true,
    })
}
