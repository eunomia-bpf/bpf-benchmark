// SPDX-License-Identifier: MIT
//! ARM64 CCMP optimization pass.

use crate::analysis::{
    admit_kinsn_site_window, block_start_slot, site_pc, BBProgram, BlockId, InsnSite, Terminator,
};
use crate::insn::*;
use crate::pass::*;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[KinsnDescriptor {
    canonical_name: "bpf_ccmp64",
    aliases: &["ccmp64"],
    decode_proof: decode_ccmp_proof,
    register_uses: ccmp_register_uses,
}];

const MIN_CCMP_TERMS: usize = 2;
const MAX_CCMP_TERMS: usize = 4;
const CCMP_REPLACEMENT_LEN: usize = 3;

fn decode_ccmp_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(ccmp_proof_len))
}

fn ccmp_proof_len(payload: u64) -> anyhow::Result<usize> {
    let dst_reg = kinsn_payload_reg(payload, 0);
    let count_bits = BpfInsn::unpack_u4(payload, 4) & 0x3;
    let count = usize::from(count_bits) + 2;

    if payload >> 24 != 0 {
        anyhow::bail!("ccmp payload has non-zero reserved bits");
    }
    if count_bits > 2 {
        anyhow::bail!("ccmp count {} exceeds maximum 4", count);
    }
    if dst_reg > BPF_REG_9 {
        anyhow::bail!("ccmp dst register {dst_reg} is outside BPF_REG_0..BPF_REG_9");
    }
    for idx in 0..4 {
        let reg = kinsn_payload_reg(payload, (8 + idx * 4) as u8);
        if idx >= count {
            if reg != 0 {
                anyhow::bail!("ccmp unused register slot {idx} is non-zero");
            }
            continue;
        }
        validate_bpf_reg("ccmp compare", reg)?;
        if reg == dst_reg {
            anyhow::bail!("ccmp dst register aliases compare operand r{reg}");
        }
    }

    Ok(count + 2)
}

fn ccmp_register_uses(payload: u64) -> RegSet {
    let count = usize::from(BpfInsn::unpack_u4(payload, 4) & 0x3) + 2;
    std::iter::once(kinsn_payload_reg(payload, 0))
        .chain((0..count).map(|idx| kinsn_payload_reg(payload, (8 + idx * 4) as u8)))
        .collect()
}

/// CCMP pass: folds same-target zero-test short-circuit AND chains into an
/// ARM64-only conditional-compare kinsn plus one final branch.
pub struct CcmpPass;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(super) enum CcmpFailMode {
    EqZero,
    NeZero,
}

impl CcmpFailMode {
    fn from_bpf_op(op: u8) -> Option<Self> {
        match op {
            BPF_JEQ => Some(Self::EqZero),
            BPF_JNE => Some(Self::NeZero),
            _ => None,
        }
    }

    fn payload_bit(self) -> u64 {
        match self {
            Self::EqZero => 0,
            Self::NeZero => 1,
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(super) enum CcmpWidth {
    Bpf64,
    Bpf32,
}

impl CcmpWidth {
    fn from_class(class: u8) -> Option<Self> {
        match class {
            BPF_JMP => Some(Self::Bpf64),
            BPF_JMP32 => Some(Self::Bpf32),
            _ => None,
        }
    }

    fn payload_bit(self) -> u64 {
        match self {
            Self::Bpf64 => 0,
            Self::Bpf32 => 1,
        }
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub(super) struct CcmpPayload {
    pub(super) dst_reg: u8,
    pub(super) fail_mode: CcmpFailMode,
    pub(super) width: CcmpWidth,
    pub(super) regs: Vec<u8>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub(super) struct CcmpSite {
    pub(super) start_pc: usize,
    start_site: InsnSite,
    pub(super) old_len: usize,
    pub(super) target_pc: usize,
    target_block: BlockId,
    success_block: BlockId,
    blocks: Vec<BlockId>,
    pub(super) fail_mode: CcmpFailMode,
    pub(super) width: CcmpWidth,
    pub(super) regs: Vec<u8>,
}

struct SafeCcmpSite {
    site: CcmpSite,
    dst_reg: u8,
    payload: u64,
}

struct BranchTerm {
    pc: usize,
    block: BlockId,
    target_pc: usize,
    target_block: BlockId,
    fallthrough: BlockId,
    reg: u8,
    fail_mode: CcmpFailMode,
    width: CcmpWidth,
}

impl BpfPass for CcmpPass {
    fn name(&self) -> &str {
        "ccmp"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}

pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    if ctx.platform.arch != Arch::Aarch64 {
        return Ok(PassResult::skipped(SkipReason {
            pc: 0,
            reason: "ccmp is only valid on aarch64".into(),
        }));
    }

    let sites = scan_ccmp_sites(prog)?;
    let mut safe_sites = Vec::new();
    let mut skipped = Vec::new();

    for site in sites {
        if site.regs.len() > MAX_CCMP_TERMS {
            skipped.push(SkipReason {
                pc: site.start_pc,
                reason: format!(
                    "ccmp chain length {} exceeds maximum {}",
                    site.regs.len(),
                    MAX_CCMP_TERMS
                ),
            });
            continue;
        }

        if site.target_pc <= site.start_pc + site.old_len {
            skipped.push(SkipReason {
                pc: site.start_pc,
                reason: "ccmp chain target is inside the chain boundary".into(),
            });
            continue;
        }

        if admit_kinsn_site_window(
            prog,
            site.start_site,
            site.old_len,
            CCMP_REPLACEMENT_LEN,
            &mut skipped,
        )?
        .is_none()
        {
            continue;
        }

        let Some(dst_reg) = choose_dead_dst_reg(prog, &site)? else {
            skipped.push(SkipReason {
                pc: site.start_pc,
                reason: "no dead register available for ccmp predicate".into(),
            });
            continue;
        };

        validate_ccmp_chain(prog, &site)?;

        let payload = encode_ccmp_payload(&CcmpPayload {
            dst_reg,
            fail_mode: site.fail_mode,
            width: site.width,
            regs: site.regs.clone(),
        })?;
        safe_sites.push(SafeCcmpSite {
            site,
            dst_reg,
            payload,
        });
    }

    if safe_sites.is_empty() {
        return Ok(PassResult {
            sites_skipped: skipped,
            ..PassResult::unchanged()
        });
    }

    let btf_id = ctx.kinsn_registry.btf_id_for_target_name("bpf_ccmp64")?;
    let kfunc_off = ctx.kinsn_registry.call_off_for_target_name("bpf_ccmp64")?;
    safe_sites.sort_by_key(|safe| safe.site.start_pc);
    for safe_site in safe_sites.iter().rev() {
        apply_ccmp_site(prog, safe_site, btf_id, kfunc_off)?;
    }

    Ok(PassResult {
        sites_applied: safe_sites.len(),
        sites_skipped: skipped,
        ..Default::default()
    })
}

fn validate_ccmp_chain(prog: &BBProgram, site: &CcmpSite) -> anyhow::Result<()> {
    let mut trial = prog.clone();
    let (chain, target, success) = ccmp_chain_blocks(&mut trial, site)?;
    validate_chain_edges(&trial, site, &chain, target, success)
}

fn apply_ccmp_site(
    prog: &mut BBProgram,
    safe_site: &SafeCcmpSite,
    btf_id: i32,
    kfunc_off: i16,
) -> anyhow::Result<()> {
    let (chain, target, success) = ccmp_chain_blocks(prog, &safe_site.site)?;
    validate_chain_edges(prog, &safe_site.site, &chain, target, success)?;
    for pair in chain.windows(2) {
        prog.replace_terminator(pair[0], Terminator::Fallthrough { next: pair[1] })?;
    }
    let removed_chain_blocks = chain[1..].to_vec();
    let merged = prog.merge_linear_chain(&chain)?;
    let target = BBProgram::remap_block_after_remove(target, &removed_chain_blocks)?;
    let success = BBProgram::remap_block_after_remove(success, &removed_chain_blocks)?;

    let block_len = prog.block_body_len(merged)?;
    prog.replace_range(
        merged,
        0..block_len,
        emit_packed_kinsn_call_with_off(safe_site.payload, btf_id, kfunc_off),
    )?;

    let branch = BpfInsn::new(
        BPF_JMP | BPF_JEQ | BPF_K,
        BpfInsn::make_regs(safe_site.dst_reg, 0),
        0,
        0,
    );
    prog.replace_terminator(
        merged,
        Terminator::CondBranch {
            cond: branch,
            taken: target,
            fallthrough: success,
        },
    )
}

fn ccmp_chain_blocks(
    prog: &mut BBProgram,
    site: &CcmpSite,
) -> anyhow::Result<(Vec<BlockId>, BlockId, BlockId)> {
    let mut chain = site.blocks.clone();
    let mut target = site.target_block;
    let mut success = site.success_block;
    let first = site.start_site.block;
    let block_len = prog.block_body_len(first)?;
    if site.start_site.idx != block_len {
        anyhow::bail!("ccmp branch pc {} is not a block terminator", site.start_pc);
    }
    if block_len > 0 {
        let (_, tail) = prog.split_block(site.start_site)?;
        for block in &mut chain {
            *block = BBProgram::remap_block_after_insert(*block, first, tail);
        }
        target = BBProgram::remap_block_after_insert(target, first, tail);
        success = BBProgram::remap_block_after_insert(success, first, tail);
        chain[0] = tail;
    }
    Ok((chain, target, success))
}

fn validate_chain_edges(
    prog: &BBProgram,
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
        let expected_fallthrough = match chain.get(idx + 1) {
            Some(&next) => next,
            None => success,
        };
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

pub(super) fn scan_ccmp_sites(prog: &BBProgram) -> anyhow::Result<Vec<CcmpSite>> {
    let mut sites = Vec::new();
    let mut next_allowed_pc = 0usize;

    for block in prog.blocks() {
        let Some(first) = branch_term(prog, block.id)? else {
            continue;
        };
        if first.pc < next_allowed_pc || has_same_chain_predecessor(prog, &first)? {
            continue;
        }
        if let Some(site) = try_match_ccmp_chain(prog, first)? {
            next_allowed_pc = site.start_pc + site.old_len;
            sites.push(site);
        }
    }
    Ok(sites)
}

fn try_match_ccmp_chain(prog: &BBProgram, first: BranchTerm) -> anyhow::Result<Option<CcmpSite>> {
    let mut regs = Vec::new();
    let mut blocks = Vec::new();
    let mut cursor = first.block;
    let mut expected_pc = first.pc;

    while let Some(term) = branch_term(prog, cursor)? {
        if term.pc != expected_pc {
            break;
        }
        if term.target_pc != first.target_pc
            || term.fail_mode != first.fail_mode
            || term.width != first.width
        {
            break;
        }
        regs.push(term.reg);
        blocks.push(term.block);
        cursor = term.fallthrough;
        expected_pc += 1;
    }

    if regs.len() < MIN_CCMP_TERMS {
        return Ok(None);
    }

    let start_site = InsnSite {
        block: first.block,
        idx: prog.block_body_len(first.block)?,
    };
    let success_block = cursor;
    Ok(Some(CcmpSite {
        start_pc: first.pc,
        start_site,
        old_len: regs.len(),
        target_pc: first.target_pc,
        target_block: first.target_block,
        success_block,
        blocks,
        fail_mode: first.fail_mode,
        width: first.width,
        regs,
    }))
}

fn has_same_chain_predecessor(prog: &BBProgram, first: &BranchTerm) -> anyhow::Result<bool> {
    for &pred in prog.predecessors(first.block) {
        let Some(term) = branch_term(prog, pred)? else {
            continue;
        };
        if term.fallthrough == first.block
            && term.target_block == first.target_block
            && term.fail_mode == first.fail_mode
            && term.width == first.width
            && term.pc + 1 == first.pc
        {
            return Ok(true);
        }
    }
    Ok(false)
}

fn branch_term(prog: &BBProgram, block: BlockId) -> anyhow::Result<Option<BranchTerm>> {
    let Terminator::CondBranch {
        cond: insn,
        taken,
        fallthrough,
    } = prog.terminator(block)?
    else {
        return Ok(None);
    };
    if !insn.is_cond_jmp() || bpf_src(insn.code) != BPF_K || insn.imm != 0 {
        return Ok(None);
    }
    let Some(fail_mode) = CcmpFailMode::from_bpf_op(bpf_op(insn.code)) else {
        return Ok(None);
    };
    let Some(width) = CcmpWidth::from_class(insn.class()) else {
        return Ok(None);
    };
    let branch_site = InsnSite {
        block,
        idx: prog.block_body_len(block)?,
    };
    let pc = site_pc(prog, branch_site)?;
    let target_pc = block_start_slot(prog, taken)?;
    if target_pc <= pc {
        return Ok(None);
    }
    let fallthrough_pc = block_start_slot(prog, fallthrough)?;
    if fallthrough_pc != pc + 1 {
        return Ok(None);
    }
    Ok(Some(BranchTerm {
        pc,
        block,
        target_pc,
        target_block: taken,
        fallthrough,
        reg: insn.dst_reg(),
        fail_mode,
        width,
    }))
}

fn choose_dead_dst_reg(prog: &BBProgram, site: &CcmpSite) -> anyhow::Result<Option<u8>> {
    let last_block = site
        .blocks
        .last()
        .copied()
        .ok_or_else(|| anyhow::anyhow!("ccmp site at pc {} has no blocks", site.start_pc))?;
    let last_site = prog
        .terminator_site(last_block)?
        .ok_or_else(|| anyhow::anyhow!("ccmp block {:?} has no terminator site", last_block))?;
    let live_after = prog.live_out_site_checked(last_site)?;
    Ok((BPF_REG_0..=BPF_REG_9).find(|reg| !live_after.contains(reg) && !site.regs.contains(reg)))
}

pub(super) fn encode_ccmp_payload(payload: &CcmpPayload) -> anyhow::Result<u64> {
    if payload.regs.len() < MIN_CCMP_TERMS || payload.regs.len() > MAX_CCMP_TERMS {
        anyhow::bail!(
            "ccmp payload term count {} is outside {}..{}",
            payload.regs.len(),
            MIN_CCMP_TERMS,
            MAX_CCMP_TERMS
        );
    }
    if payload.dst_reg > BPF_REG_9 {
        anyhow::bail!("ccmp dst register r{} is invalid", payload.dst_reg);
    }
    if payload.regs.contains(&payload.dst_reg) {
        anyhow::bail!("ccmp dst register aliases a compare operand");
    }

    let mut encoded = BpfInsn::pack_u4(payload.dst_reg, 0)
        | BpfInsn::pack_u4((payload.regs.len() - 2) as u8, 4)
        | BpfInsn::pack_u4(payload.fail_mode.payload_bit() as u8, 6)
        | BpfInsn::pack_u4(payload.width.payload_bit() as u8, 7);
    for (idx, &reg) in payload.regs.iter().enumerate() {
        if reg > BPF_REG_10 {
            anyhow::bail!("ccmp compare register r{reg} is invalid");
        }
        encoded |= BpfInsn::pack_u4(reg, (8 + idx * 4) as u8);
    }
    Ok(encoded)
}
