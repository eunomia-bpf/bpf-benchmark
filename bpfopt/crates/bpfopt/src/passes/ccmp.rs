// SPDX-License-Identifier: MIT
//! ARM64 CCMP optimization pass.

use crate::analysis::{BlockId, InsnSite, ProgramCFG, Terminator};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[
    KinsnDescriptor {
        name: "bpf_arm64_cmp_x_imm0",
        register_uses: ccmp_single_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_cmp_w_imm0",
        register_uses: ccmp_single_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_ccmp_x_imm0",
        register_uses: ccmp_single_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_ccmp_w_imm0",
        register_uses: ccmp_single_register_uses,
        register_defs: no_regs,
    },
    KinsnDescriptor {
        name: "bpf_arm64_cset_x_cond",
        register_uses: ccmp_register_uses,
        register_defs: ccmp_register_defs,
    },
];

const MIN_CCMP_TERMS: usize = 2;
const MAX_CCMP_TERMS: usize = 4;

fn ccmp_register_uses(payload: u64) -> RegSet {
    let count = usize::from(BpfInsn::unpack_u4(payload, 4) & 0x3) + 2;
    (0..count)
        .map(|idx| kinsn_payload_reg(payload, (8 + idx * 4) as u8))
        .collect()
}

fn ccmp_register_defs(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}
fn ccmp_single_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}

/// CCMP pass: folds same-target zero-test short-circuit AND chains into an
/// ARM64-only conditional-compare kinsn plus one final branch.
pub struct CcmpPass;

#[repr(u8)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(super) enum CcmpFailMode {
    EqZero = 0,
    NeZero = 1,
}

#[repr(u8)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(super) enum CcmpWidth {
    Bpf64 = 0,
    Bpf32 = 1,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub(super) struct CcmpSite {
    start_site: InsnSite,
    pub(super) old_len: usize,
    target_block: BlockId,
    success_block: BlockId,
    blocks: Vec<BlockId>,
    pub(super) fail_mode: CcmpFailMode,
    pub(super) width: CcmpWidth,
    pub(super) regs: Vec<u8>,
}

struct BranchTerm {
    block: BlockId,
    target_block: BlockId,
    fallthrough: BlockId,
    reg: u8,
    fail_mode: CcmpFailMode,
    width: CcmpWidth,
}

impl CcmpSite {
    fn skip(&self, reason: impl Into<String>) -> SiteSkipReason {
        SiteSkipReason::new(self.start_site, reason)
    }
}

impl BranchTerm {
    fn matches_chain(&self, first: &Self) -> bool {
        self.target_block == first.target_block
            && self.fail_mode == first.fail_mode
            && self.width == first.width
    }
}

impl BpfPass for CcmpPass {
    fn run(&self, prog: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        if ctx.arch != Arch::Aarch64 {
            return PassResult::skipped_pass(prog, "ccmp requires aarch64 target");
        }
        let sites = scan_ccmp_sites(prog)?;
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            if site.regs.len() > MAX_CCMP_TERMS {
                skipped.push(site.skip(format!(
                    "ccmp chain length {} exceeds maximum {}",
                    site.regs.len(),
                    MAX_CCMP_TERMS
                )));
                continue;
            }

            if site.blocks.contains(&site.target_block) {
                skipped.push(site.skip("ccmp chain target is inside the chain boundary"));
                continue;
            }

            if let Some(reason) = prog.admission_skip_reason(site.start_site, site.old_len)? {
                skipped.push(site.skip(reason));
                continue;
            }

            let Some(dst_reg) = choose_dead_dst_reg(prog, &site)? else {
                skipped.push(site.skip("no dead register available for ccmp predicate"));
                continue;
            };

            let mut trial = prog.clone();
            let (chain, target, success) = ccmp_chain_blocks(&mut trial, &site)?;
            validate_chain_edges(&trial, &site, &chain, target, success)?;

            let payload = encode_ccmp_payload(dst_reg, site.fail_mode, site.width, &site.regs)?;
            safe_sites.push((site, dst_reg, payload));
        }

        if safe_sites.is_empty() {
            return Ok(PassResult::with_sites(0, skipped));
        }

        safe_sites.sort_by_key(|(site, _, _)| site.start_site);
        let mut applied = 0usize;
        for (site, dst_reg, payload) in safe_sites.iter().rev() {
            if apply_ccmp_site(prog, site, *dst_reg, *payload, &mut skipped)? {
                applied += 1;
            }
        }

        Ok(PassResult::with_sites(applied, skipped))
    }
}

fn apply_ccmp_site(
    prog: &mut ProgramCFG,
    site: &CcmpSite,
    dst_reg: u8,
    payload: u64,
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<bool> {
    let mut trial = prog.clone();
    let (chain, target, success) = ccmp_chain_blocks(&mut trial, site)?;
    validate_chain_edges(&trial, site, &chain, target, success)?;
    for pair in chain.windows(2) {
        trial.replace_terminator(pair[0], Terminator::Fallthrough { next: pair[1] })?;
    }
    let merged = trial.merge_linear_chain(&chain)?;
    let (target, success) = match trial.terminator(merged)? {
        Terminator::CondBranch {
            taken, fallthrough, ..
        } => (taken, fallthrough),
        term => anyhow::bail!(
            "ccmp merged block {:?} expected conditional exit, got {:?}",
            merged,
            term
        ),
    };
    let merged_sites = trial.sites_in_block(merged)?;
    let replacement_start = match merged_sites.first().copied() {
        Some(site) => site,
        None => trial.terminator_site(merged)?.ok_or_else(|| {
            anyhow::anyhow!("ccmp merged block {:?} has no insertion site", merged)
        })?,
    };
    let replacement = emit_ccmp_kinsns(&trial, site, payload)?;
    if !trial.try_replace_range(replacement_start, merged_sites.len(), replacement, skipped)? {
        return Ok(false);
    }

    trial.replace_terminator(
        merged,
        Terminator::CondBranch {
            cond: BpfInsn::new(
                BPF_JMP | BPF_JEQ | BPF_K,
                BpfInsn::make_regs(dst_reg, 0),
                0,
                0,
            ),
            taken: target,
            fallthrough: success,
        },
    )?;
    *prog = trial;
    Ok(true)
}

fn emit_ccmp_kinsns(
    prog: &ProgramCFG,
    site: &CcmpSite,
    cset_payload: u64,
) -> anyhow::Result<Vec<BpfInsn>> {
    let cmp_target = match site.width {
        CcmpWidth::Bpf64 => "bpf_arm64_cmp_x_imm0",
        CcmpWidth::Bpf32 => "bpf_arm64_cmp_w_imm0",
    };
    let ccmp_target = match site.width {
        CcmpWidth::Bpf64 => "bpf_arm64_ccmp_x_imm0",
        CcmpWidth::Bpf32 => "bpf_arm64_ccmp_w_imm0",
    };
    let mut out = Vec::with_capacity(site.regs.len() * 2 + 2);
    out.extend_from_slice(&prog.kinsn_emit(cmp_target, BpfInsn::pack_u4(site.regs[0], 0))?);
    let fail_mode = BpfInsn::pack_u4(site.fail_mode as u8, 4);
    for &reg in site.regs.iter().skip(1) {
        out.extend_from_slice(&prog.kinsn_emit(ccmp_target, BpfInsn::pack_u4(reg, 0) | fail_mode)?);
    }
    out.extend_from_slice(&prog.kinsn_emit("bpf_arm64_cset_x_cond", cset_payload)?);
    Ok(out)
}

fn ccmp_chain_blocks(
    prog: &mut ProgramCFG,
    site: &CcmpSite,
) -> anyhow::Result<(Vec<BlockId>, BlockId, BlockId)> {
    let first = prog.site_block(site.start_site);
    if !prog.is_terminator_site(site.start_site)? {
        anyhow::bail!("ccmp branch site {:?} is not a block exit", site.start_site);
    }
    if prog.sites_in_block(first)?.is_empty() {
        return Ok((site.blocks.clone(), site.target_block, site.success_block));
    }

    let (_, tail) = prog.split_block(site.start_site)?;
    let Some(first_term) = branch_term(prog, tail)? else {
        anyhow::bail!("ccmp split tail {:?} has no branch term", tail);
    };
    let Some(updated) = try_match_ccmp_chain(prog, first_term)? else {
        anyhow::bail!("ccmp split tail {:?} no longer matches a chain", tail);
    };
    Ok((updated.blocks, updated.target_block, updated.success_block))
}

fn validate_chain_edges(
    prog: &ProgramCFG,
    site: &CcmpSite,
    chain: &[BlockId],
    target: BlockId,
    success: BlockId,
) -> anyhow::Result<()> {
    if chain.len() != site.old_len {
        anyhow::bail!(
            "ccmp chain block count {} does not match site length {}",
            chain.len(),
            site.old_len
        );
    }
    for (idx, &block) in chain.iter().enumerate() {
        let Terminator::CondBranch {
            taken, fallthrough, ..
        } = prog.terminator(block)?
        else {
            anyhow::bail!("ccmp chain block {:?} is not a conditional branch", block);
        };
        if taken != target {
            anyhow::bail!(
                "ccmp chain block {:?} branches to {:?}, expected {:?}",
                block,
                taken,
                target
            );
        }
        let expected_fallthrough = chain.get(idx + 1).copied().unwrap_or(success);
        if fallthrough != expected_fallthrough {
            anyhow::bail!(
                "ccmp chain block {:?} falls through to {:?}, expected {:?}",
                block,
                fallthrough,
                expected_fallthrough
            );
        }
        if idx > 0 && prog.predecessors(block) != [chain[idx - 1]] {
            anyhow::bail!(
                "ccmp chain block {:?} has unexpected predecessors {:?}",
                block,
                prog.predecessors(block)
            );
        }
    }
    Ok(())
}

pub(super) fn scan_ccmp_sites(prog: &ProgramCFG) -> anyhow::Result<Vec<CcmpSite>> {
    let mut sites = Vec::new();

    for block in prog.blocks() {
        let Some(first) = branch_term(prog, block.id)? else {
            continue;
        };
        if has_same_chain_predecessor(prog, &first)? {
            continue;
        }
        sites.extend(try_match_ccmp_chain(prog, first)?);
    }
    Ok(sites)
}

fn try_match_ccmp_chain(prog: &ProgramCFG, first: BranchTerm) -> anyhow::Result<Option<CcmpSite>> {
    let mut regs = Vec::new();
    let mut blocks = Vec::new();
    let mut cursor = first.block;

    while let Some(term) = branch_term(prog, cursor)? {
        if blocks.contains(&term.block) {
            break;
        }
        if !term.matches_chain(&first) {
            break;
        }
        regs.push(term.reg);
        blocks.push(term.block);
        cursor = term.fallthrough;
    }

    if regs.len() < MIN_CCMP_TERMS {
        return Ok(None);
    }

    let start_site = prog
        .terminator_site(first.block)?
        .ok_or_else(|| anyhow::anyhow!("ccmp block {:?} has no exit site", first.block))?;
    Ok(Some(CcmpSite {
        start_site,
        old_len: regs.len(),
        target_block: first.target_block,
        success_block: cursor,
        blocks,
        fail_mode: first.fail_mode,
        width: first.width,
        regs,
    }))
}

fn has_same_chain_predecessor(prog: &ProgramCFG, first: &BranchTerm) -> anyhow::Result<bool> {
    for &pred in prog.predecessors(first.block) {
        let Some(term) = branch_term(prog, pred)? else {
            continue;
        };
        if term.fallthrough == first.block && term.matches_chain(first) {
            return Ok(true);
        }
    }
    Ok(false)
}

fn branch_term(prog: &ProgramCFG, block: BlockId) -> anyhow::Result<Option<BranchTerm>> {
    let Terminator::CondBranch {
        cond: insn,
        taken,
        fallthrough,
    } = prog.terminator(block)?
    else {
        return Ok(None);
    };
    if !insn.is_cond_jmp() || bpf_src(insn.code) != BPF_K || insn.imm != 0 || taken == fallthrough {
        return Ok(None);
    }
    let fail_mode = match bpf_op(insn.code) {
        BPF_JEQ => CcmpFailMode::EqZero,
        BPF_JNE => CcmpFailMode::NeZero,
        _ => return Ok(None),
    };
    let width = match insn.class() {
        BPF_JMP => CcmpWidth::Bpf64,
        BPF_JMP32 => CcmpWidth::Bpf32,
        _ => return Ok(None),
    };
    let branch_site = prog
        .terminator_site(block)?
        .ok_or_else(|| anyhow::anyhow!("ccmp block {:?} has no exit site", block))?;
    prog.insn(branch_site)?;
    Ok(Some(BranchTerm {
        block,
        target_block: taken,
        fallthrough,
        reg: insn.dst_reg(),
        fail_mode,
        width,
    }))
}

fn choose_dead_dst_reg(prog: &ProgramCFG, site: &CcmpSite) -> anyhow::Result<Option<u8>> {
    let last_block = site
        .blocks
        .last()
        .copied()
        .ok_or_else(|| anyhow::anyhow!("ccmp site {:?} has no blocks", site.start_site))?;
    let last_site = prog
        .terminator_site(last_block)?
        .ok_or_else(|| anyhow::anyhow!("ccmp block {:?} has no exit site", last_block))?;
    let live_after = prog.live_out_site_checked(last_site)?;
    Ok((BPF_REG_0..=BPF_REG_9).find(|reg| !live_after.contains(reg) && !site.regs.contains(reg)))
}

pub(super) fn encode_ccmp_payload(
    dst_reg: u8,
    fail_mode: CcmpFailMode,
    width: CcmpWidth,
    regs: &[u8],
) -> anyhow::Result<u64> {
    if !(MIN_CCMP_TERMS..=MAX_CCMP_TERMS).contains(&regs.len()) {
        anyhow::bail!(
            "ccmp payload term count {} is outside {}..{}",
            regs.len(),
            MIN_CCMP_TERMS,
            MAX_CCMP_TERMS
        );
    }
    if dst_reg > BPF_REG_9 {
        anyhow::bail!("ccmp dst register r{} is invalid", dst_reg);
    }
    if regs.contains(&dst_reg) {
        anyhow::bail!("ccmp dst register aliases a compare operand");
    }

    let mut encoded = BpfInsn::pack_u4(dst_reg, 0)
        | BpfInsn::pack_u4((regs.len() - 2) as u8, 4)
        | BpfInsn::pack_u4(fail_mode as u8, 6)
        | BpfInsn::pack_u4(width as u8, 7);
    for (idx, &reg) in regs.iter().enumerate() {
        if reg > BPF_REG_10 {
            anyhow::bail!("ccmp compare register r{reg} is invalid");
        }
        encoded |= BpfInsn::pack_u4(reg, (8 + idx * 4) as u8);
    }
    Ok(encoded)
}
