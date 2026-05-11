// SPDX-License-Identifier: MIT
use crate::analysis::{BBProgram, InsnSite};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        canonical_name: "bpf_rotate64",
        aliases: &["rotate64"],
        decode_proof: decode_rotate64_proof,
        register_uses: rotate_register_uses,
    },
    KinsnDescriptor {
        canonical_name: "bpf_rotate32",
        aliases: &["rotate32"],
        decode_proof: decode_rotate32_proof,
        register_uses: rotate_register_uses,
    },
];

fn decode_rotate64_proof(payload: &[u8]) -> ProofRegion {
    decode_rotate_proof(payload, 63)
}

fn decode_rotate32_proof(payload: &[u8]) -> ProofRegion {
    decode_rotate_proof(payload, 31)
}

fn decode_rotate_proof(payload: &[u8], shift_mask: u8) -> ProofRegion {
    ProofRegion::from_result(
        decode_packed_kinsn_payload(payload)
            .and_then(|payload| rotate_proof_len(payload, shift_mask)),
    )
}

fn rotate_proof_len(payload: u64, shift_mask: u8) -> anyhow::Result<usize> {
    let dst_reg = kinsn_payload_reg(payload, 0);
    let src_reg = kinsn_payload_reg(payload, 4);
    let shift = kinsn_payload_u8(payload, 8) & shift_mask;
    let tmp_reg = kinsn_payload_reg(payload, 16);

    validate_bpf_reg("rotate dst", dst_reg)?;
    validate_bpf_reg("rotate src", src_reg)?;
    validate_bpf_reg("rotate tmp", tmp_reg)?;
    if tmp_reg == dst_reg || tmp_reg == src_reg {
        anyhow::bail!("rotate tmp register aliases an operand");
    }
    if shift == 0 {
        Ok(1)
    } else if dst_reg == src_reg {
        Ok(4)
    } else {
        Ok(5)
    }
}

fn rotate_register_uses(payload: u64) -> RegSet {
    [kinsn_payload_reg(payload, 0), kinsn_payload_reg(payload, 4)]
        .into_iter()
        .collect()
}
pub struct RotatePass;

impl BpfPass for RotatePass {
    fn name(&self) -> &str {
        "rotate"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}

pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    let mut safe_sites: Vec<SafeRotateSite> = Vec::new();
    let mut skipped = Vec::new();

    for block in prog.block_ids().collect::<Vec<_>>() {
        let block_sites = prog.sites_in_block(block)?;
        let block_insns = prog.copied_body_insns(block)?;
        for (start_idx, _) in block_sites.iter().enumerate() {
            let Some(site) = rotate_site_at(&block_insns, start_idx) else {
                continue;
            };
            let replacement_start = block_sites
                .get(site.start_idx)
                .copied()
                .ok_or_else(|| anyhow::anyhow!("rotate start index {} missing", site.start_idx))?;
            let Some((_, admission_range)) =
                prog.rep_admit_kinsn_site_window(replacement_start, site.old_len, 2, &mut skipped)?
            else {
                continue;
            };

            let last_idx = admission_range
                .end
                .checked_sub(1)
                .ok_or_else(|| anyhow::anyhow!("rotate admission range is empty"))?;
            let last_site = block_sites
                .get(last_idx)
                .copied()
                .ok_or_else(|| anyhow::anyhow!("rotate last index {last_idx} missing"))?;
            if prog
                .live_out_site_checked(last_site)?
                .contains(&site.tmp_reg)
            {
                skipped.push(SiteSkipReason {
                    site: replacement_start,
                    reason: format!("tmp_reg r{} is live after site", site.tmp_reg),
                });
                continue;
            }

            safe_sites.push(SafeRotateSite {
                start: replacement_start,
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
        let btf_id = ctx
            .kinsn_registry
            .btf_id_for_target_name(site.width.target_name())?;
        let kfunc_off = ctx
            .kinsn_registry
            .call_off_for_target_name(site.width.target_name())?;
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
        prog.replace_range_at(
            safe_site.start,
            site.old_len,
            emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
        )?;
    }

    Ok(PassResult {
        sites_applied: safe_sites.len(),
        site_skipped: skipped,
        ..Default::default()
    })
}

fn rotate_site_at(insns: &[BpfInsn], idx: usize) -> Option<RotateSite> {
    if idx + 3 > insns.len() {
        return None;
    }
    let (Some(i0), Some(i1), Some(i2)) = (insns.get(idx), insns.get(idx + 1), insns.get(idx + 2))
    else {
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
struct SafeRotateSite {
    start: InsnSite,
    site: RotateSite,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(super) enum RotateWidth {
    W32,
    W64,
}

impl RotateWidth {
    fn bits(self) -> u32 {
        match self {
            Self::W32 => 32,
            Self::W64 => 64,
        }
    }

    fn alu_class(self) -> u8 {
        match self {
            Self::W32 => BPF_ALU,
            Self::W64 => BPF_ALU64,
        }
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
    let mov64 = insn.code == (BPF_ALU64 | BPF_MOV | BPF_X);
    let mov32 = insn.code == (BPF_ALU | BPF_MOV | BPF_X);
    mov64 || (width == RotateWidth::W32 && mov32)
}

fn try_match_rotate(
    insns: &[BpfInsn],
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    idx: usize,
) -> Option<RotateSite> {
    try_match_split_copy_rotate(insns, idx)
        .or_else(|| try_match_rotate_width(insns, i0, i1, i2, idx, RotateWidth::W64))
        .or_else(|| try_match_rotate_width(insns, i0, i1, i2, idx, RotateWidth::W32))
}
fn try_match_split_copy_rotate(insns: &[BpfInsn], idx: usize) -> Option<RotateSite> {
    try_match_split_copy_rotate_width(insns, idx, RotateWidth::W64)
        .or_else(|| try_match_split_copy_rotate_width(insns, idx, RotateWidth::W32))
}

fn try_match_split_copy_rotate_width(
    insns: &[BpfInsn],
    idx: usize,
    width: RotateWidth,
) -> Option<RotateSite> {
    if idx + 4 >= insns.len() {
        return None;
    }

    let mov0 = &insns[idx];
    let shift0 = &insns[idx + 1];
    let mov1 = &insns[idx + 2];
    let shift1 = &insns[idx + 3];
    let or_insn = &insns[idx + 4];

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

    let alu_class = width.alu_class();
    let shift0_is_lsh = shift0.code == (alu_class | BPF_LSH | BPF_K);
    let shift0_is_rsh = shift0.code == (alu_class | BPF_RSH | BPF_K);
    let shift1_is_lsh = shift1.code == (alu_class | BPF_LSH | BPF_K);
    let shift1_is_rsh = shift1.code == (alu_class | BPF_RSH | BPF_K);

    let (lsh_amount, rsh_amount) = if shift0_is_lsh && shift1_is_rsh {
        (shift0.imm as u32, shift1.imm as u32)
    } else if shift0_is_rsh && shift1_is_lsh {
        (shift1.imm as u32, shift0.imm as u32)
    } else {
        return None;
    };

    if lsh_amount + rsh_amount != width.bits() {
        return None;
    }

    if or_insn.code != (alu_class | BPF_OR | BPF_X) {
        return None;
    }

    let or_dst = or_insn.dst_reg();
    let or_src = or_insn.src_reg();
    let or_uses_both = (or_dst == reg0 && or_src == reg1) || (or_dst == reg1 && or_src == reg0);
    if !or_uses_both {
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
    let is_or = i2.code == (alu_class | BPF_OR | BPF_X);
    if !is_or {
        return None;
    }
    let is_rsh = i0.code == (alu_class | BPF_RSH | BPF_K);
    let is_lsh = i1.code == (alu_class | BPF_LSH | BPF_K);

    if is_rsh && is_lsh {
        let rsh_amount = i0.imm as u32;
        let lsh_amount = i1.imm as u32;

        if rsh_amount + lsh_amount == width.bits() {
            let rsh_reg = i0.dst_reg();
            let lsh_reg = i1.dst_reg();
            if rsh_reg != lsh_reg {
                let or_dst = i2.dst_reg();
                let or_src = i2.src_reg();
                let or_uses_both = (or_dst == rsh_reg && or_src == lsh_reg)
                    || (or_dst == lsh_reg && or_src == rsh_reg);
                if or_uses_both {
                    let result_reg = or_dst;
                    if let Some(mov_idx) = find_provenance_mov(insns, idx, rsh_reg, lsh_reg, width)
                    {
                        return rotate_site(
                            mov_idx,
                            (idx + 3) - mov_idx,
                            result_reg,
                            lsh_reg,
                            rsh_reg,
                            lsh_amount,
                            width,
                        );
                    }
                    if let Some(mov_idx) = find_provenance_mov(insns, idx, lsh_reg, rsh_reg, width)
                    {
                        return rotate_site(
                            mov_idx,
                            (idx + 3) - mov_idx,
                            result_reg,
                            rsh_reg,
                            lsh_reg,
                            lsh_amount,
                            width,
                        );
                    }
                }
            }
        }
    }
    let is_lsh_first = i0.code == (alu_class | BPF_LSH | BPF_K);
    let is_rsh_second = i1.code == (alu_class | BPF_RSH | BPF_K);

    if is_lsh_first && is_rsh_second {
        let lsh_amount = i0.imm as u32;
        let rsh_amount = i1.imm as u32;

        if lsh_amount + rsh_amount == width.bits() {
            let lsh_reg = i0.dst_reg();
            let rsh_reg = i1.dst_reg();
            if lsh_reg != rsh_reg {
                let or_dst = i2.dst_reg();
                let or_src = i2.src_reg();

                let or_uses_both = (or_dst == lsh_reg && or_src == rsh_reg)
                    || (or_dst == rsh_reg && or_src == lsh_reg);
                if or_uses_both {
                    let result_reg = or_dst;
                    if let Some(mov_idx) = find_provenance_mov(insns, idx, rsh_reg, lsh_reg, width)
                    {
                        return rotate_site(
                            mov_idx,
                            (idx + 3) - mov_idx,
                            result_reg,
                            lsh_reg,
                            rsh_reg,
                            lsh_amount,
                            width,
                        );
                    }
                    if let Some(mov_idx) = find_provenance_mov(insns, idx, lsh_reg, rsh_reg, width)
                    {
                        return rotate_site(
                            mov_idx,
                            (idx + 3) - mov_idx,
                            result_reg,
                            rsh_reg,
                            lsh_reg,
                            lsh_amount,
                            width,
                        );
                    }
                }
            }
        }
    }

    None
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
