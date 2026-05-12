// SPDX-License-Identifier: MIT
//! COND_SELECT optimization pass.

use std::collections::HashSet;

use crate::analysis::{insn_use_def_set, BBProgram, BlockId, DiamondPattern, InsnSite, Terminator};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[KinsnDescriptor {
    canonical_name: "bpf_select64",
    aliases: &["select64"],
    proof_len: select_proof_len,
    register_uses: cond_select_register_uses,
}];

fn select_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("select dst", kinsn_payload_reg(payload, 0))?;
    validate_bpf_reg("select true", kinsn_payload_reg(payload, 4))?;
    validate_bpf_reg("select false", kinsn_payload_reg(payload, 8))?;
    validate_bpf_reg("select cond", kinsn_payload_reg(payload, 12))?;
    if kinsn_payload_reg(payload, 16) != 0 {
        anyhow::bail!("select condition mode is not KINSN_SELECT_COND_NEZ");
    }
    Ok(4)
}

fn cond_select_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0, 4, 8, 12])
}

/// COND_SELECT pass: replaces branch+mov diamond patterns with
/// bpf_select64() kfunc calls (lowered to branchless select by the JIT).
///
/// Pattern A (4-insn diamond):
///   Jcc r_cond, X, +2 ; MOV r_dst, val_false ; JA +1 ; MOV r_dst, val_true
///
/// Emit (when kfunc available):
///   MOV r1, <true_val>       // arg1 = a (returned when cond != 0)
///   MOV r2, <false_val>      // arg2 = b (returned when cond == 0)
///   MOV r3, <cond_reg>       // arg3 = condition value
///   CALL bpf_select64        // r0 = bpf_select64(a, b, cond)
///   MOV dst, r0              // dst = result
///
/// The kfunc signature is: `u64 bpf_select64(u64 a, u64 b, u64 cond)`
/// Semantics: returns `a` if `cond != 0`, otherwise returns `b`.
///
pub struct CondSelectPass;

/// A detected cond-select site.
pub(super) struct CondSelectSite {
    start_site: InsnSite,
    end_site: InsnSite,
    pub(super) old_len: usize,
    cond: BpfInsn,
    pub(super) dst_reg: u8,
    pub(super) true_val: CondSelectValue,
    pub(super) false_val: CondSelectValue,
}

struct CondSelectLowering {
    prefix: Vec<BpfInsn>,
    a_reg: u8,
    b_reg: u8,
    cond_reg: u8,
}

#[derive(Clone, Copy)]
struct CondBranchShape {
    block: BlockId,
    site: InsnSite,
    cond: BpfInsn,
    taken: BlockId,
    fallthrough: BlockId,
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub(super) enum CondSelectValue {
    Reg(u8),
    Reg32(u8),
    Imm(i32),
    Imm32(i32),
}

impl CondSelectValue {
    fn source_reg(self) -> Option<u8> {
        match self {
            Self::Reg(reg) | Self::Reg32(reg) => Some(reg),
            Self::Imm(_) | Self::Imm32(_) => None,
        }
    }
}

impl CondSelectSite {
    fn skip(&self, reason: impl Into<String>) -> SiteSkipReason {
        SiteSkipReason::new(self.start_site, reason)
    }
}

impl BpfPass for CondSelectPass {
    fn name(&self) -> &str {
        "cond_select"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}

pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    // Check if the target can lower bpf_select64 to branchless select
    // (CMOV on x86, CSEL on ARM64).
    if !ctx.has_branchless_select() {
        return PassResult::skipped_pass(prog, "platform lacks branchless select support");
    }

    let sites = scan_cond_select_sites(prog)?;
    let (btf_id, kfunc_off) = prog.kinsn_call("bpf_select64")?;
    let mut safe_sites = Vec::new();
    let mut skipped = Vec::new();

    for site in sites {
        let live_after = prog.live_out_site_checked(site.end_site)?;

        let lowering = match build_lowering(&site, &live_after) {
            Ok(lowering) => lowering,
            Err(reason) => {
                skipped.push(site.skip(reason));
                continue;
            }
        };

        if let Some(reason) =
            prog.admission_skip_reason(site.start_site, site.old_len)?
        {
            skipped.push(site.skip(reason));
            continue;
        }

        let mut trial = prog.clone();
        let pattern = diamond_pattern_for_site(&mut trial, &site)?;
        trial.replace_diamond_with_insns(pattern, vec![BpfInsn::nop()])?;

        safe_sites.push((site, lowering));
    }

    if safe_sites.is_empty() {
        return Ok(PassResult::with_sites(0, skipped));
    }

    safe_sites.sort_by_key(|(site, _)| site.start_site);
    for (site, lowering) in safe_sites.iter().rev() {
        let payload = BpfInsn::pack_u4(site.dst_reg, 0)
            | BpfInsn::pack_u4(lowering.a_reg, 4)
            | BpfInsn::pack_u4(lowering.b_reg, 8)
            | BpfInsn::pack_u4(lowering.cond_reg, 12);
        let kinsn_call = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
        let mut replacement = Vec::with_capacity(lowering.prefix.len() + kinsn_call.len());
        replacement.extend_from_slice(&lowering.prefix);
        replacement.extend_from_slice(&kinsn_call);
        let pattern = diamond_pattern_for_site(prog, site)?;
        prog.replace_diamond_with_insns(pattern, replacement)?;
    }

    Ok(PassResult::with_sites(safe_sites.len(), skipped))
}

fn diamond_pattern_for_site(
    prog: &mut BBProgram,
    site: &CondSelectSite,
) -> anyhow::Result<DiamondPattern> {
    match site.old_len {
        4 => pattern_a_for_site(prog, site),
        3 => pattern_c_for_site(prog, site),
        old_len => anyhow::bail!("unsupported cond_select site length {old_len}"),
    }
}

fn pattern_a_for_site(
    prog: &mut BBProgram,
    site: &CondSelectSite,
) -> anyhow::Result<DiamondPattern> {
    let mut jcc_site = site.start_site;
    if !prog.is_terminator_site(jcc_site)? {
        anyhow::bail!(
            "pattern A branch site {:?} is not a block terminator",
            site.start_site
        );
    }
    if !prog.sites_in_block(prog.site_block(jcc_site))?.is_empty() {
        let (_, tail) = prog.split_block(jcc_site)?;
        jcc_site = prog
            .terminator_site(tail)?
            .ok_or_else(|| anyhow::anyhow!("split tail {:?} has no terminator site", tail))?;
    }
    let predecessor = prog.site_block(jcc_site);
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.terminator_at_site(jcc_site)?
    else {
        anyhow::bail!(
            "pattern A predecessor {:?} is not a conditional branch",
            predecessor
        );
    };
    let join = prog
        .successors(taken)
        .iter()
        .copied()
        .find(|succ| prog.successors(fallthrough).contains(succ))
        .ok_or_else(|| {
            anyhow::anyhow!(
                "blocks {:?} and {:?} do not share a join",
                taken,
                fallthrough
            )
        })?;
    Ok(DiamondPattern {
        predecessor,
        true_branch: taken,
        false_branch: fallthrough,
        join: Some(join),
    })
}

fn pattern_c_for_site(
    prog: &mut BBProgram,
    site: &CondSelectSite,
) -> anyhow::Result<DiamondPattern> {
    let start_site = site.start_site;
    let start_block = prog.site_block(start_site);
    let first_site = prog
        .sites_in_block_with_terminator(start_block)?
        .first()
        .copied();
    let predecessor = if first_site == Some(start_site) {
        start_block
    } else {
        prog.split_block(start_site)?.1
    };
    let branch_site = prog.terminator_site(predecessor)?.ok_or_else(|| {
        anyhow::anyhow!(
            "pattern C predecessor {:?} has no terminator site",
            predecessor
        )
    })?;
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.terminator_at_site(branch_site)?
    else {
        anyhow::bail!(
            "pattern C predecessor {:?} is not a conditional branch",
            predecessor
        );
    };
    Ok(DiamondPattern {
        predecessor,
        true_branch: predecessor,
        false_branch: fallthrough,
        join: Some(taken),
    })
}

fn scan_cond_select_sites(prog: &BBProgram) -> anyhow::Result<Vec<CondSelectSite>> {
    let mut sites = Vec::new();
    for block in prog.blocks() {
        let Terminator::CondBranch {
            cond,
            taken,
            fallthrough,
        } = prog.terminator(block.id)?
        else {
            continue;
        };
        let branch_site = prog.terminator_site(block.id)?.ok_or_else(|| {
            anyhow::anyhow!("conditional block {:?} has no terminator site", block.id)
        })?;
        let shape = CondBranchShape {
            block: block.id,
            site: branch_site,
            cond,
            taken,
            fallthrough,
        };
        sites.extend(try_match_pattern_a(prog, shape)?);
        sites.extend(try_match_pattern_c(prog, shape)?);
    }
    sites.sort_by_key(|site| site.start_site);
    Ok(sites)
}

fn try_match_pattern_a(
    prog: &BBProgram,
    shape: CondBranchShape,
) -> anyhow::Result<Option<CondSelectSite>> {
    if shape.block == shape.taken || shape.block == shape.fallthrough {
        return Ok(None);
    }
    let Some(mov_false) = prog.block_single_body_insn(shape.fallthrough)? else {
        return Ok(None);
    };
    let Some(mov_true) = prog.block_single_body_insn(shape.taken)? else {
        return Ok(None);
    };
    let (Some(false_val), Some(true_val)) =
        (select_mov_value(mov_false), select_mov_value(mov_true))
    else {
        return Ok(None);
    };
    if mov_false.dst_reg() != mov_true.dst_reg() {
        return Ok(None);
    }
    let (Some(false_join), Some(true_join)) = (
        single_successor(prog, shape.fallthrough)?,
        single_successor(prog, shape.taken)?,
    ) else {
        return Ok(None);
    };
    if false_join != true_join {
        return Ok(None);
    }
    let end_site = prog
        .sites_in_block(shape.taken)?
        .first()
        .copied()
        .ok_or_else(|| anyhow::anyhow!("true branch {:?} has no body site", shape.taken))?;
    Ok(Some(CondSelectSite {
        start_site: shape.site,
        end_site,
        old_len: 4,
        cond: shape.cond,
        dst_reg: mov_false.dst_reg(),
        true_val,
        false_val,
    }))
}

fn try_match_pattern_c(
    prog: &BBProgram,
    shape: CondBranchShape,
) -> anyhow::Result<Option<CondSelectSite>> {
    let Some(mov_true_site) = prog.sites_in_block(shape.block)?.last().copied() else {
        return Ok(None);
    };
    let mov_true = prog.insn(mov_true_site)?;
    let Some(mov_false) = prog.block_single_body_insn(shape.fallthrough)? else {
        return Ok(None);
    };
    let (Some(true_val), Some(false_val)) =
        (select_mov_value(mov_true), select_mov_value(mov_false))
    else {
        return Ok(None);
    };
    if mov_true.dst_reg() != mov_false.dst_reg() {
        return Ok(None);
    }
    if single_successor(prog, shape.fallthrough)? != Some(shape.taken) {
        return Ok(None);
    }
    if insn_use_def_set(&shape.cond)
        .uses
        .contains(&mov_true.dst_reg())
    {
        return Ok(None);
    }
    let end_site = prog
        .sites_in_block(shape.fallthrough)?
        .first()
        .copied()
        .ok_or_else(|| anyhow::anyhow!("false branch {:?} has no body site", shape.fallthrough))?;
    Ok(Some(CondSelectSite {
        start_site: mov_true_site,
        end_site,
        old_len: 3,
        cond: shape.cond,
        dst_reg: mov_true.dst_reg(),
        true_val,
        false_val,
    }))
}

fn single_successor(prog: &BBProgram, block: BlockId) -> anyhow::Result<Option<BlockId>> {
    Ok(match prog.terminator(block)? {
        Terminator::Fallthrough { next } | Terminator::Jump { target: next, .. } => Some(next),
        Terminator::CondBranch { .. }
        | Terminator::Call { .. }
        | Terminator::Exit { .. }
        | Terminator::End => None,
    })
}

fn select_mov_value(insn: &BpfInsn) -> Option<CondSelectValue> {
    if bpf_op(insn.code) != BPF_MOV {
        return None;
    }
    match (bpf_class(insn.code), bpf_src(insn.code)) {
        (BPF_ALU64, BPF_X) => Some(CondSelectValue::Reg(insn.src_reg())),
        (BPF_ALU64, BPF_K) => Some(CondSelectValue::Imm(insn.imm)),
        (BPF_ALU, BPF_X) => Some(CondSelectValue::Reg32(insn.src_reg())),
        (BPF_ALU, BPF_K) => Some(CondSelectValue::Imm32(insn.imm)),
        _ => None,
    }
}

fn build_lowering(
    site: &CondSelectSite,
    live_after: &HashSet<u8>,
) -> Result<CondSelectLowering, String> {
    let (mut prefix, cond_reg, inverted) = condition_prefix(site, live_after)?;
    let (a_val, b_val) = if inverted {
        (site.false_val, site.true_val)
    } else {
        (site.true_val, site.false_val)
    };

    let mut protected = vec![cond_reg];
    protected.extend(
        [a_val, b_val]
            .into_iter()
            .filter_map(CondSelectValue::source_reg),
    );

    let mut regs = [0; 2];
    let mut imm_regs = Vec::new();
    let mut allocated = Vec::new();
    for (reg, value) in regs.iter_mut().zip([a_val, b_val]) {
        *reg = materialize_value(
            site,
            value,
            live_after,
            &protected,
            &mut allocated,
            &mut imm_regs,
            &mut prefix,
        )?;
    }
    Ok(CondSelectLowering {
        prefix,
        a_reg: regs[0],
        b_reg: regs[1],
        cond_reg,
    })
}

fn condition_prefix(
    site: &CondSelectSite,
    live_after: &HashSet<u8>,
) -> Result<(Vec<BpfInsn>, u8, bool), String> {
    let cond = site.cond;
    let cond_reg = cond.dst_reg();
    let cond_src_reg = cond.src_reg();
    let cond_class = bpf_class(cond.code);
    let cond_src = bpf_src(cond.code);
    let cond_op = bpf_op(cond.code);
    let eq_ne = matches!(cond_op, BPF_JNE | BPF_JEQ);
    let inverted = cond_op == BPF_JEQ;

    if cond_src == BPF_K && cond.imm == 0 && eq_ne {
        if cond_class == BPF_JMP {
            return Ok((Vec::new(), cond_reg, inverted));
        }
        if cond_class == BPF_JMP32 {
            let forbidden = value_source_regs(site);
            let pred = choose_compare_pred_reg(site, live_after, &forbidden)?;
            return Ok((vec![BpfInsn::mov32_reg(pred, cond_reg)], pred, inverted));
        }
    }

    if cond_src == BPF_K && cond_class == BPF_JMP && eq_ne {
        let forbidden = value_source_regs(site);
        let pred = choose_compare_pred_reg(site, live_after, &forbidden)?;
        return Ok((
            vec![
                BpfInsn::mov64_reg(pred, cond_reg),
                BpfInsn::alu64_imm(BPF_XOR, pred, cond.imm),
            ],
            pred,
            inverted,
        ));
    }

    let mut forbidden = value_source_regs(site);
    forbidden.push(cond_reg);
    if cond_src == BPF_X {
        forbidden.push(cond_src_reg);
    }
    let pred = choose_compare_pred_reg(site, live_after, &forbidden)?;
    let cond_jmp = |code, off| {
        BpfInsn::new(
            code,
            BpfInsn::make_regs(cond_reg, cond_src_reg),
            off,
            cond.imm,
        )
    };
    if let Some(inverse_op) = invert_cond_jmp_op(cond_op) {
        return Ok((
            vec![
                BpfInsn::mov64_imm(pred, 0),
                cond_jmp((cond.code & !0xf0) | inverse_op, 1),
                BpfInsn::mov64_imm(pred, 1),
            ],
            pred,
            false,
        ));
    }

    let prefix = if site.old_len == 3 {
        vec![
            cond_jmp(cond.code, 2),
            BpfInsn::mov64_imm(pred, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(pred, 1),
        ]
    } else {
        vec![
            BpfInsn::mov64_imm(pred, 1),
            cond_jmp(cond.code, 1),
            BpfInsn::mov64_imm(pred, 0),
        ]
    };
    Ok((prefix, pred, false))
}

fn choose_compare_pred_reg(
    site: &CondSelectSite,
    live_after: &HashSet<u8>,
    forbidden: &[u8],
) -> Result<u8, String> {
    choose_temp_reg(site, live_after, forbidden, &[])
        .ok_or_else(|| "no dead register available for cond_select compare predicate".to_string())
}

fn materialize_value(
    site: &CondSelectSite,
    value: CondSelectValue,
    live_after: &HashSet<u8>,
    protected: &[u8],
    allocated: &mut Vec<u8>,
    imm_regs: &mut Vec<(CondSelectValue, u8)>,
    prefix: &mut Vec<BpfInsn>,
) -> Result<u8, String> {
    if let CondSelectValue::Reg(reg) = value {
        return Ok(reg);
    }
    if let Some((_, reg)) = imm_regs.iter().find(|(seen, _)| *seen == value) {
        return Ok(*reg);
    }
    let reg = choose_temp_reg(site, live_after, protected, allocated)
        .ok_or_else(|| "no dead register available to materialize immediate operand".to_string())?;
    match value {
        CondSelectValue::Imm(imm) => prefix.push(BpfInsn::mov64_imm(reg, imm)),
        CondSelectValue::Reg32(src) => prefix.push(BpfInsn::mov32_reg(reg, src)),
        CondSelectValue::Imm32(imm) => prefix.push(BpfInsn::mov32_imm(reg, imm)),
        CondSelectValue::Reg(reg) => return Ok(reg),
    }
    allocated.push(reg);
    imm_regs.push((value, reg));
    Ok(reg)
}

fn choose_temp_reg(
    site: &CondSelectSite,
    live_after: &HashSet<u8>,
    forbidden: &[u8],
    allocated: &[u8],
) -> Option<u8> {
    std::iter::once(site.dst_reg)
        .chain(BPF_REG_0..=BPF_REG_9)
        .find(|&reg| {
            !forbidden.contains(&reg)
                && !allocated.contains(&reg)
                && (reg == site.dst_reg || !live_after.contains(&reg))
        })
}

fn value_source_regs(site: &CondSelectSite) -> Vec<u8> {
    [site.true_val, site.false_val]
        .into_iter()
        .filter_map(CondSelectValue::source_reg)
        .collect()
}
