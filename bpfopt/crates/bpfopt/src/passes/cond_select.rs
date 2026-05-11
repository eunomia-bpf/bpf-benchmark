// SPDX-License-Identifier: MIT
//! COND_SELECT optimization pass.

use std::collections::HashSet;

use crate::analysis::{insn_use_def_set, BBProgram, BlockId, DiamondPattern, InsnSite, Terminator};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[KinsnDescriptor {
    canonical_name: "bpf_select64",
    aliases: &["select64"],
    decode_proof: decode_select_proof,
    register_uses: cond_select_register_uses,
}];

fn decode_select_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(select_proof_len))
}

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
    [
        kinsn_payload_reg(payload, 0),
        kinsn_payload_reg(payload, 4),
        kinsn_payload_reg(payload, 8),
        kinsn_payload_reg(payload, 12),
    ]
    .into_iter()
    .collect()
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
    pub(super) cond_reg: u8,
    pub(super) dst_reg: u8,
    pub(super) true_val: CondSelectValue,
    pub(super) false_val: CondSelectValue,
    /// The JCC opcode (BPF_JNE, BPF_JEQ, etc.).
    pub(super) jcc_op: u8,
    /// The JCC immediate (for BPF_K source).
    pub(super) jcc_imm: i32,
    /// The JCC source kind (BPF_K or BPF_X).
    pub(super) jcc_src: u8,
    /// The full JCC instruction code (BPF_JMP/BPF_JMP32 + op + source).
    pub(super) jcc_code: u8,
    /// The JCC source register for BPF_X conditions.
    pub(super) jcc_src_reg: u8,
}

/// A cond_select site that has passed safety checks, ready for transformation.
struct SafeCondSelectSite {
    site: CondSelectSite,
    lowering: CondSelectLowering,
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
        return Ok(PassResult::skipped_site(SiteSkipReason {
            site: first_report_site(prog)?,
            reason: "platform lacks branchless select support".into(),
        }));
    }

    let sites = scan_cond_select_sites(prog)?;
    let btf_id = ctx.kinsn_registry.btf_id_for_target_name("bpf_select64")?;
    let kfunc_off = ctx
        .kinsn_registry
        .call_off_for_target_name("bpf_select64")?;
    let mut safe_sites: Vec<SafeCondSelectSite> = Vec::new();
    let mut skipped = Vec::new();

    for site in sites {
        let live_after = prog.live_out_site_checked(site.end_site)?;

        let lowering = match build_lowering(&site, &live_after) {
            Ok(lowering) => lowering,
            Err(reason) => {
                skipped.push(SiteSkipReason {
                    site: site.start_site,
                    reason,
                });
                continue;
            }
        };

        if prog
            .rep_admit_kinsn_site_window(
                site.start_site,
                site.old_len,
                lowering.prefix.len() + 2,
                &mut skipped,
            )?
            .is_none()
        {
            continue;
        }

        validate_diamond_site(prog, &site)?;

        safe_sites.push(SafeCondSelectSite { site, lowering });
    }

    if safe_sites.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::unchanged()
        });
    }

    safe_sites.sort_by_key(|safe| safe.site.start_site);
    for safe_site in safe_sites.iter().rev() {
        let site = &safe_site.site;
        let payload = BpfInsn::pack_u4(site.dst_reg, 0)
            | BpfInsn::pack_u4(safe_site.lowering.a_reg, 4)
            | BpfInsn::pack_u4(safe_site.lowering.b_reg, 8)
            | BpfInsn::pack_u4(safe_site.lowering.cond_reg, 12);
        let kinsn_call = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
        let mut replacement =
            Vec::with_capacity(safe_site.lowering.prefix.len() + kinsn_call.len());
        replacement.extend_from_slice(&safe_site.lowering.prefix);
        replacement.extend_from_slice(&kinsn_call);
        let pattern = diamond_pattern_for_site(prog, site)?;
        prog.replace_diamond_with_insns(pattern, replacement)?;
    }

    Ok(PassResult {
        sites_applied: safe_sites.len(),
        site_skipped: skipped,
        ..Default::default()
    })
}

fn validate_diamond_site(prog: &BBProgram, site: &CondSelectSite) -> anyhow::Result<()> {
    let mut trial = prog.clone();
    let pattern = diamond_pattern_for_site(&mut trial, site)?;
    trial.replace_diamond_with_insns(pattern, vec![BpfInsn::nop()])?;
    Ok(())
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
    if !prog.sites_in_block(jcc_site.block)?.is_empty() {
        let (_, tail) = prog.split_block(jcc_site)?;
        jcc_site = prog
            .terminator_site(tail)?
            .ok_or_else(|| anyhow::anyhow!("split tail {:?} has no terminator site", tail))?;
    }
    let predecessor = jcc_site.block;
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.terminator(predecessor)?
    else {
        anyhow::bail!(
            "pattern A predecessor {:?} is not a conditional branch",
            predecessor
        );
    };
    let join = common_successor(prog, taken, fallthrough)?;
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
    let first_site = prog
        .sites_in_block_with_terminator(start_site.block)?
        .first()
        .copied();
    let predecessor = if first_site == Some(start_site) {
        start_site.block
    } else {
        prog.split_block(start_site)?.1
    };
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.terminator(predecessor)?
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

fn common_successor(prog: &BBProgram, a: BlockId, b: BlockId) -> anyhow::Result<BlockId> {
    prog.successors(a)
        .iter()
        .copied()
        .find(|succ| prog.successors(b).contains(succ))
        .ok_or_else(|| anyhow::anyhow!("blocks {:?} and {:?} do not share a join", a, b))
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
        if let Some(site) = try_match_pattern_a(prog, shape)? {
            sites.push(site);
        }
        if let Some(site) = try_match_pattern_c(prog, shape)? {
            sites.push(site);
        }
    }
    sites.sort_by_key(|site| site.start_site);
    Ok(sites)
}

fn try_match_pattern_a(
    prog: &BBProgram,
    shape: CondBranchShape,
) -> anyhow::Result<Option<CondSelectSite>> {
    let jcc = shape.cond;
    if !jcc.is_cond_jmp() {
        return Ok(None);
    }
    let Some(mov_false) = prog.block_single_body_insn(shape.fallthrough)? else {
        return Ok(None);
    };
    let Some(mov_true) = prog.block_single_body_insn(shape.taken)? else {
        return Ok(None);
    };
    if !is_select_mov(mov_false) || !is_select_mov(mov_true) {
        return Ok(None);
    }
    let Some(false_join) = single_successor(prog, shape.fallthrough)? else {
        return Ok(None);
    };
    let Some(true_join) = single_successor(prog, shape.taken)? else {
        return Ok(None);
    };
    if false_join != true_join || mov_false.dst_reg() != mov_true.dst_reg() {
        return Ok(None);
    }
    let true_mov_site = prog
        .sites_in_block(shape.taken)?
        .first()
        .copied()
        .ok_or_else(|| anyhow::anyhow!("true branch {:?} has no body site", shape.taken))?;
    if shape.block == shape.taken || shape.block == shape.fallthrough {
        return Ok(None);
    }
    Ok(Some(CondSelectSite {
        start_site: shape.site,
        end_site: true_mov_site,
        old_len: 4,
        cond_reg: jcc.dst_reg(),
        dst_reg: mov_false.dst_reg(),
        true_val: extract_mov_value(mov_true),
        false_val: extract_mov_value(mov_false),
        jcc_op: bpf_op(jcc.code),
        jcc_imm: jcc.imm,
        jcc_src: bpf_src(jcc.code),
        jcc_code: jcc.code,
        jcc_src_reg: jcc.src_reg(),
    }))
}

fn try_match_pattern_c(
    prog: &BBProgram,
    shape: CondBranchShape,
) -> anyhow::Result<Option<CondSelectSite>> {
    let jcc = shape.cond;
    if !jcc.is_cond_jmp() {
        return Ok(None);
    }
    let block_sites = prog.sites_in_block(shape.block)?;
    let Some(mov_true_site) = block_sites.last().copied() else {
        return Ok(None);
    };
    let mov_true = prog
        .insn_at(mov_true_site)
        .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", mov_true_site))?;
    let Some(mov_false) = prog.block_single_body_insn(shape.fallthrough)? else {
        return Ok(None);
    };
    if !is_select_mov(mov_true) || !is_select_mov(mov_false) {
        return Ok(None);
    }
    if mov_true.dst_reg() != mov_false.dst_reg() {
        return Ok(None);
    }
    let Some(false_join) = single_successor(prog, shape.fallthrough)? else {
        return Ok(None);
    };
    if false_join != shape.taken {
        return Ok(None);
    }
    let mov_true_dst = mov_true.dst_reg();
    if insn_use_def_set(&jcc).uses.contains(&mov_true_dst) {
        return Ok(None);
    }
    let start_site = mov_true_site;
    let end_site = prog
        .sites_in_block(shape.fallthrough)?
        .first()
        .copied()
        .ok_or_else(|| anyhow::anyhow!("false branch {:?} has no body site", shape.fallthrough))?;
    Ok(Some(CondSelectSite {
        start_site,
        end_site,
        old_len: 3,
        cond_reg: jcc.dst_reg(),
        dst_reg: mov_true.dst_reg(),
        true_val: extract_mov_value(mov_true),
        false_val: extract_mov_value(mov_false),
        jcc_op: bpf_op(jcc.code),
        jcc_imm: jcc.imm,
        jcc_src: bpf_src(jcc.code),
        jcc_code: jcc.code,
        jcc_src_reg: jcc.src_reg(),
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

fn is_select_mov(insn: &BpfInsn) -> bool {
    insn.is_mov64_reg() || insn.is_mov64_imm() || insn.is_mov32_reg() || insn.is_mov32_imm()
}

fn extract_mov_value(insn: &BpfInsn) -> CondSelectValue {
    if bpf_class(insn.code) == BPF_ALU {
        if bpf_src(insn.code) == BPF_X {
            CondSelectValue::Reg32(insn.src_reg())
        } else {
            CondSelectValue::Imm32(insn.imm)
        }
    } else if bpf_src(insn.code) == BPF_X {
        CondSelectValue::Reg(insn.src_reg())
    } else {
        CondSelectValue::Imm(insn.imm)
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
    for value in [a_val, b_val] {
        match value {
            CondSelectValue::Reg(reg) | CondSelectValue::Reg32(reg) => protected.push(reg),
            CondSelectValue::Imm(_) | CondSelectValue::Imm32(_) => {}
        }
    }

    let mut allocated = Vec::new();
    let mut imm_regs = Vec::new();
    let a_reg = materialize_value(
        site,
        a_val,
        live_after,
        &protected,
        &mut allocated,
        &mut imm_regs,
        &mut prefix,
    )?;
    let b_reg = materialize_value(
        site,
        b_val,
        live_after,
        &protected,
        &mut allocated,
        &mut imm_regs,
        &mut prefix,
    )?;
    Ok(CondSelectLowering {
        prefix,
        a_reg,
        b_reg,
        cond_reg,
    })
}

fn condition_prefix(
    site: &CondSelectSite,
    live_after: &HashSet<u8>,
) -> Result<(Vec<BpfInsn>, u8, bool), String> {
    if site.jcc_src == BPF_K
        && site.jcc_imm == 0
        && bpf_class(site.jcc_code) == BPF_JMP
        && matches!(site.jcc_op, BPF_JNE | BPF_JEQ)
    {
        return Ok((Vec::new(), site.cond_reg, site.jcc_op == BPF_JEQ));
    }

    if site.jcc_src == BPF_K
        && site.jcc_imm == 0
        && bpf_class(site.jcc_code) == BPF_JMP32
        && matches!(site.jcc_op, BPF_JNE | BPF_JEQ)
    {
        let forbidden = value_source_regs(site);
        let pred = choose_temp_reg(site, live_after, &forbidden, &[]).ok_or_else(|| {
            "no dead register available for cond_select compare predicate".to_string()
        })?;
        return Ok((
            vec![BpfInsn::mov32_reg(pred, site.cond_reg)],
            pred,
            site.jcc_op == BPF_JEQ,
        ));
    }

    if site.jcc_src == BPF_K
        && bpf_class(site.jcc_code) == BPF_JMP
        && matches!(site.jcc_op, BPF_JNE | BPF_JEQ)
    {
        let forbidden = value_source_regs(site);
        let pred = choose_temp_reg(site, live_after, &forbidden, &[]).ok_or_else(|| {
            "no dead register available for cond_select compare predicate".to_string()
        })?;
        return Ok((
            vec![
                BpfInsn::mov64_reg(pred, site.cond_reg),
                BpfInsn::alu64_imm(BPF_XOR, pred, site.jcc_imm),
            ],
            pred,
            site.jcc_op == BPF_JEQ,
        ));
    }

    let mut forbidden = value_source_regs(site);
    forbidden.push(site.cond_reg);
    if site.jcc_src == BPF_X {
        forbidden.push(site.jcc_src_reg);
    }
    let pred = choose_temp_reg(site, live_after, &forbidden, &[]).ok_or_else(|| {
        "no dead register available for cond_select compare predicate".to_string()
    })?;
    if let Some(inverse_op) = inverse_jcc_op(site.jcc_op) {
        return Ok((
            vec![
                BpfInsn::mov64_imm(pred, 0),
                BpfInsn::new(
                    (site.jcc_code & !0xf0) | inverse_op,
                    BpfInsn::make_regs(site.cond_reg, site.jcc_src_reg),
                    1,
                    site.jcc_imm,
                ),
                BpfInsn::mov64_imm(pred, 1),
            ],
            pred,
            false,
        ));
    }

    let prefix = if site.old_len == 3 {
        vec![
            BpfInsn::new(
                site.jcc_code,
                BpfInsn::make_regs(site.cond_reg, site.jcc_src_reg),
                2,
                site.jcc_imm,
            ),
            BpfInsn::mov64_imm(pred, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(pred, 1),
        ]
    } else {
        vec![
            BpfInsn::mov64_imm(pred, 1),
            BpfInsn::new(
                site.jcc_code,
                BpfInsn::make_regs(site.cond_reg, site.jcc_src_reg),
                1,
                site.jcc_imm,
            ),
            BpfInsn::mov64_imm(pred, 0),
        ]
    };
    Ok((prefix, pred, false))
}

fn inverse_jcc_op(op: u8) -> Option<u8> {
    match op {
        BPF_JEQ => Some(BPF_JNE),
        BPF_JNE => Some(BPF_JEQ),
        BPF_JGT => Some(BPF_JLE),
        BPF_JGE => Some(BPF_JLT),
        BPF_JLT => Some(BPF_JGE),
        BPF_JLE => Some(BPF_JGT),
        BPF_JSGT => Some(BPF_JSLE),
        BPF_JSGE => Some(BPF_JSLT),
        BPF_JSLT => Some(BPF_JSGE),
        BPF_JSLE => Some(BPF_JSGT),
        _ => None,
    }
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
        .filter_map(|value| match value {
            CondSelectValue::Reg(reg) | CondSelectValue::Reg32(reg) => Some(reg),
            CondSelectValue::Imm(_) | CondSelectValue::Imm32(_) => None,
        })
        .collect()
}
