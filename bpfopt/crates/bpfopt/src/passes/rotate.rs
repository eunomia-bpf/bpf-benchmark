// SPDX-License-Identifier: MIT
use crate::analysis::{InsnSite, ProgramCFG};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: "bpf_rotate64",
        register_uses: rotate_register_uses,
    },
    KinsnDescriptor {
        name: "bpf_rotate32",
        register_uses: rotate_register_uses,
    },
];

fn rotate_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0, 4])
}
pub struct RotatePass;

impl BpfPass for RotatePass {
    fn name(&self) -> &str {
        "rotate"
    }
    fn run(&self, program: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}

pub fn run_on_bbprogram(prog: &mut ProgramCFG, _ctx: &PassContext) -> anyhow::Result<PassResult> {
    let mut skipped = Vec::new();
    let candidates: Vec<(InsnSite, RotateSite)> = prog
        .scan_block_starts(5, |window| {
            Ok(rotate_site_at(window.insns, window.start_idx)
                .map(|site| (site.start_idx, site.old_len, site)))
        })?
        .into_iter()
        .map(|hit| (hit.start, hit.value))
        .collect();

    if candidates.is_empty() {
        return Ok(PassResult::with_sites(0, skipped));
    }

    // tmp_reg liveness pre-check: skip sites whose tmp_reg is read after the
    // window, since the kinsn replacement does not preserve tmp_reg.
    let mut applicable = Vec::with_capacity(candidates.len());
    for (start, site) in candidates {
        if prog
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
            let (btf_id, kfunc_off) = prog.kinsn_call(site.width.target_name())?;
            let shift_amount = u8::try_from(site.shift_amount).map_err(|_| {
                anyhow::anyhow!(
                    "rotate shift amount {} exceeds packed payload width",
                    site.shift_amount
                )
            })?;
            let payload = BpfInsn::pack_u4(site.dst_reg, 0)
                | BpfInsn::pack_u4(site.val_reg, 4)
                | BpfInsn::pack_u8(shift_amount, 8)
                | BpfInsn::pack_u4(site.tmp_reg, 16);
            Ok((
                site.old_len,
                emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
            ))
        })?;

    Ok(PassResult::with_sites(applied, skipped))
}

fn rotate_site_at(insns: &[BpfInsn], idx: usize) -> Option<RotateSite> {
    let [i0, i1, i2] = insns.get(idx..idx + 3)? else {
        return None;
    };
    try_match_rotate(insns, i0, i1, i2, idx)
}

pub(super) struct RotateSite {
    pub(super) start_idx: usize,
    pub(super) old_len: usize,
    pub(super) dst_reg: u8,
    pub(super) val_reg: u8,
    pub(super) tmp_reg: u8,
    pub(super) shift_amount: u32,
    pub(super) width: RotateWidth,
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

    fn target_name(self) -> &'static str {
        match self {
            Self::W32 => "bpf_rotate32",
            Self::W64 => "bpf_rotate64",
        }
    }
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
    insns: &[BpfInsn],
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    idx: usize,
) -> Option<RotateSite> {
    RotateWidth::MATCH_ORDER
        .into_iter()
        .find_map(|width| try_match_split_copy_rotate_width(insns, idx, width))
        .or_else(|| {
            RotateWidth::MATCH_ORDER
                .into_iter()
                .find_map(|width| try_match_rotate_width(insns, i0, i1, i2, idx, width))
        })
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
    })
}
