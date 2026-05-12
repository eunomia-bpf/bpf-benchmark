// SPDX-License-Identifier: MIT
use std::collections::BTreeSet;

use crate::analysis::{BBProgram, BlockId, InsnSite, Terminator};
use crate::insn::*;
use crate::pass::*;
pub struct BranchFlipPass {
    pub min_bias: f64,
    pub max_branch_miss_rate: f64,
}

#[derive(Clone)]
pub(super) struct BranchFlipSite {
    cond_site: InsnSite,
    pred: BlockId,
    then_first: BlockId,
    then_last: BlockId,
    else_first: BlockId,
    else_last: BlockId,
    join: BlockId,
    then_blocks: Vec<BlockId>,
    else_blocks: Vec<BlockId>,
}

impl BranchFlipSite {
    fn body_blocks(&self) -> impl Iterator<Item = BlockId> + '_ {
        self.then_blocks
            .iter()
            .chain(self.else_blocks.iter())
            .copied()
    }
}

impl BpfPass for BranchFlipPass {
    fn name(&self) -> &str {
        "branch_flip"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(
            program,
            ctx.branch_miss_rate,
            self.min_bias,
            self.max_branch_miss_rate,
        )
    }
}

pub fn run_on_bbprogram(
    prog: &mut BBProgram,
    branch_miss_rate: Option<f64>,
    min_bias: f64,
    max_branch_miss_rate: f64,
) -> anyhow::Result<PassResult> {
    let Some(program_miss_rate) = branch_miss_rate else {
        anyhow::bail!("branch_flip requires real program-level branch_miss_rate data");
    };
    if !program_miss_rate.is_finite() || !(0.0..=1.0).contains(&program_miss_rate) {
        anyhow::bail!(
            "branch_flip program branch_miss_rate must be finite and within [0, 1], got {}",
            program_miss_rate
        );
    }
    if program_miss_rate > max_branch_miss_rate {
        return Ok(PassResult::skipped_site(SiteSkipReason {
            site: first_report_site(prog)?,
            reason: format!(
                "program branch_miss_rate {:.1}% exceeds threshold {:.1}% (unpredictable branches)",
                program_miss_rate * 100.0,
                max_branch_miss_rate * 100.0,
            ),
        }));
    }

    let branch_targets = prog.branch_target_entry_sites()?;
    let sites = scan_branch_flip_sites(prog)?;
    let mut safe_sites: Vec<BranchFlipSite> = Vec::new();
    let mut skipped = Vec::new();

    for site in &sites {
        let branch_count = prog.site_hotness(site.cond_site).ok_or_else(|| {
            anyhow::anyhow!(
                "branch_flip candidate at {:?} has no real per-site branch count",
                site.cond_site
            )
        })?;
        let site_miss_rate = prog.branch_miss_rate(site.cond_site).ok_or_else(|| {
            anyhow::anyhow!(
                "branch_flip candidate at {:?} has no real per-site branch miss rate",
                site.cond_site
            )
        })?;
        let taken_rate = prog.branch_taken_rate(site.cond_site).ok_or_else(|| {
            anyhow::anyhow!(
                "branch_flip candidate at {:?} has no real per-site branch direction data",
                site.cond_site
            )
        })?;
        validate_real_branch_profile(site.cond_site, branch_count, site_miss_rate, taken_rate)?;

        if has_exterior_interior_target(prog, &branch_targets, site)? {
            skipped.push(bf_skip_reason(
                prog,
                site.cond_site,
                "interior branch target from external source".into(),
            )?);
            continue;
        }
        let cond = match prog.terminator(site.pred)? {
            Terminator::CondBranch { cond, .. } => cond,
            term => anyhow::bail!(
                "branch_flip site at {:?} expected conditional terminator, got {:?}",
                site.cond_site,
                term
            ),
        };
        if invert_jcc_op(bpf_op(cond.code)).is_none() {
            skipped.push(bf_skip_reason(
                prog,
                site.cond_site,
                "cannot invert condition opcode".into(),
            )?);
            continue;
        }

        if f64::from(site_miss_rate) > max_branch_miss_rate {
            skipped.push(bf_skip_reason(
                prog,
                site.cond_site,
                format!(
                    "site branch_miss_rate {:.1}% exceeds threshold {:.1}% (unpredictable branch)",
                    f64::from(site_miss_rate) * 100.0,
                    max_branch_miss_rate * 100.0,
                ),
            )?);
            continue;
        }

        let should_flip = f64::from(taken_rate) >= min_bias;

        if !should_flip {
            skipped.push(bf_skip_reason(
                prog,
                site.cond_site,
                "branch not biased enough".into(),
            )?);
            continue;
        }
        bf_validate_flipped_branch_deltas(
            prog,
            site.cond_site,
            site.then_first,
            site.then_last,
            site.else_first,
            site.else_last,
            cond,
        )?;
        safe_sites.push(site.clone());
    }

    if safe_sites.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::unchanged()
        });
    }
    safe_sites.sort_by_key(|site| site.cond_site);
    for site in &safe_sites {
        apply_branch_flip_site(prog, site)?;
    }

    Ok(PassResult {
        sites_applied: safe_sites.len(),
        site_skipped: skipped,
        ..PassResult::unchanged()
    })
}

fn validate_real_branch_profile(
    report_site: InsnSite,
    branch_count: u64,
    miss_rate: f32,
    taken_rate: f32,
) -> anyhow::Result<()> {
    if branch_count == 0 {
        anyhow::bail!(
            "branch_flip candidate at {:?} has zero branch_count",
            report_site
        );
    }
    if !miss_rate.is_finite() || !(0.0..=1.0).contains(&miss_rate) {
        anyhow::bail!(
            "branch_flip candidate at {:?} has invalid miss_rate {}",
            report_site,
            miss_rate
        );
    }
    if !taken_rate.is_finite() || !(0.0..=1.0).contains(&taken_rate) {
        anyhow::bail!(
            "branch_flip candidate at {:?} has invalid taken_rate {}",
            report_site,
            taken_rate
        );
    }
    Ok(())
}

fn bf_skip_reason(
    prog: &BBProgram,
    site: InsnSite,
    reason: String,
) -> anyhow::Result<SiteSkipReason> {
    prog.insn(site)?;
    Ok(SiteSkipReason { site, reason })
}

fn bf_blocks_are_adjacent(prog: &BBProgram, left: BlockId, right: BlockId) -> anyhow::Result<bool> {
    prog.block_frame(left)?;
    prog.block_frame(right)?;
    // BlockId is a positional index into the lifted blocks vec; adjacency in
    // layout order is direct arithmetic on that index. This is structural, not
    // PC arithmetic — no lowering output is computed.
    Ok(left.0 + 1 == right.0)
}

fn bf_block_range_has_body_site(
    prog: &BBProgram,
    first: BlockId,
    last: BlockId,
) -> anyhow::Result<bool> {
    if first > last {
        anyhow::bail!(
            "branch_flip block range {:?}..={:?} is inverted",
            first,
            last
        );
    }
    for block_idx in first.0..=last.0 {
        if !prog.sites_in_block(BlockId(block_idx))?.is_empty() {
            return Ok(true);
        }
    }
    Ok(false)
}

fn bf_validate_flipped_branch_deltas(
    prog: &BBProgram,
    report_site: InsnSite,
    then_first: BlockId,
    then_last: BlockId,
    else_first: BlockId,
    else_last: BlockId,
    cond: BpfInsn,
) -> anyhow::Result<()> {
    let then_len = prog.block_range_slot_count(then_first, then_last)?.slots();
    let else_len = prog.block_range_slot_count(else_first, else_last)?.slots();
    let cond_delta = else_len.checked_add(1).ok_or_else(|| {
        anyhow::anyhow!(
            "branch_flip site {:?} else arm overflows branch delta",
            report_site
        )
    })?;
    let mut inverted = cond;
    inverted.set_branch_target_delta(i64::try_from(cond_delta).map_err(|_| {
        anyhow::anyhow!(
            "branch_flip site {:?} else arm length {} overflows branch delta",
            report_site,
            else_len
        )
    })?)?;
    let mut ja = BpfInsn::ja(0);
    ja.set_branch_target_delta(i64::try_from(then_len).map_err(|_| {
        anyhow::anyhow!(
            "branch_flip site {:?} then arm length {} overflows branch delta",
            report_site,
            then_len
        )
    })?)?;
    Ok(())
}

fn apply_branch_flip_site(prog: &mut BBProgram, site: &BranchFlipSite) -> anyhow::Result<()> {
    let pred = site.pred;
    let then_first = site.then_first;
    let then_last = site.then_last;
    let else_first = site.else_first;
    let else_last = site.else_last;

    if !bf_blocks_are_adjacent(prog, pred, then_first)?
        || then_first > then_last
        || !bf_blocks_are_adjacent(prog, then_last, else_first)?
        || else_first > else_last
    {
        anyhow::bail!(
            "branch_flip site at {:?} is not a contiguous BBProgram diamond",
            site.cond_site
        );
    }

    let (cond, taken, fallthrough) = match prog.terminator(pred)? {
        Terminator::CondBranch {
            cond,
            taken,
            fallthrough,
        } => (cond, taken, fallthrough),
        term => anyhow::bail!(
            "branch_flip site at {:?} expected conditional terminator, got {:?}",
            site.cond_site,
            term
        ),
    };
    if taken != else_first || fallthrough != then_first {
        anyhow::bail!(
            "branch_flip site at {:?} has unexpected cond targets taken={:?} fallthrough={:?}",
            site.cond_site,
            taken,
            fallthrough
        );
    }

    let (ja, join) = match prog.terminator(then_last)? {
        Terminator::Jump { insn, target } => (insn, target),
        term => anyhow::bail!(
            "branch_flip site at {:?} expected then-body JA terminator, got {:?}",
            site.cond_site,
            term
        ),
    };
    if join != site.join {
        anyhow::bail!(
            "branch_flip site at {:?} expected join {:?}, got {:?}",
            site.cond_site,
            site.join,
            join
        );
    }
    match prog.terminator(else_last)? {
        Terminator::Fallthrough { next } if next == join => {}
        term => anyhow::bail!(
            "branch_flip site at {:?} expected else-body fallthrough to {:?}, got {:?}",
            site.cond_site,
            join,
            term
        ),
    }

    let new_op = invert_jcc_op(bpf_op(cond.code))
        .ok_or_else(|| anyhow::anyhow!("branch_flip cannot invert condition"))?;
    let mut inverted = cond;
    inverted.code = (cond.code & 0x0f) | new_op;
    prog.replace_terminator(
        pred,
        Terminator::CondBranch {
            cond: inverted,
            taken: then_first,
            fallthrough: else_first,
        },
    )?;
    prog.replace_terminator(then_last, Terminator::Fallthrough { next: join })?;
    prog.replace_terminator(
        else_last,
        Terminator::Jump {
            insn: ja,
            target: join,
        },
    )?;

    let order = swapped_range_order(prog, &site.then_blocks, &site.else_blocks)?;
    prog.permute_blocks(&order)
}

fn swapped_range_order(
    prog: &BBProgram,
    first: &[BlockId],
    second: &[BlockId],
) -> anyhow::Result<Vec<BlockId>> {
    if first.is_empty() || second.is_empty() {
        anyhow::bail!("branch_flip cannot swap an empty block range");
    }
    let mut order = Vec::with_capacity(prog.block_ids().count());
    let mut emitted_swap = false;
    for block in prog.block_ids() {
        if first.contains(&block) || second.contains(&block) {
            if !emitted_swap {
                order.extend_from_slice(second);
                order.extend_from_slice(first);
                emitted_swap = true;
            }
        } else {
            order.push(block);
        }
    }
    if !emitted_swap {
        anyhow::bail!("branch_flip swap range was not present in BBProgram order");
    }
    Ok(order)
}
pub(super) fn scan_branch_flip_sites(prog: &BBProgram) -> anyhow::Result<Vec<BranchFlipSite>> {
    let mut sites = Vec::new();
    let mut covered_blocks = BTreeSet::new();
    for block in prog.blocks() {
        if covered_blocks.contains(&block.id) {
            continue;
        }
        if let Some(site) = branch_flip_site_at(prog, block.id)? {
            covered_blocks.extend(site.body_blocks());
            sites.push(site);
        }
    }
    Ok(sites)
}

fn branch_flip_site_at(prog: &BBProgram, pred: BlockId) -> anyhow::Result<Option<BranchFlipSite>> {
    let Terminator::CondBranch {
        cond,
        taken: else_first,
        fallthrough: then_first,
    } = prog.terminator(pred)?
    else {
        return Ok(None);
    };
    if !cond.is_cond_jmp() {
        return Ok(None);
    }
    if !bf_blocks_are_adjacent(prog, pred, then_first)? {
        return Ok(None);
    }
    let Some((then_blocks, then_last, join)) = then_arm(prog, then_first, else_first)? else {
        return Ok(None);
    };
    let Some((else_blocks, else_last)) = else_arm(prog, else_first, join)? else {
        return Ok(None);
    };
    if !bf_blocks_are_adjacent(prog, then_last, else_first)? {
        return Ok(None);
    }
    if !bf_block_range_has_body_site(prog, then_first, then_last)? {
        return Ok(None);
    }
    if !bf_blocks_are_adjacent(prog, else_last, join)? {
        return Ok(None);
    }
    if !bf_block_range_has_body_site(prog, else_first, else_last)? {
        return Ok(None);
    }
    let Some(cond_site) = prog.terminator_site(pred)? else {
        return Ok(None);
    };
    Ok(Some(BranchFlipSite {
        cond_site,
        pred,
        then_first,
        then_last,
        else_first,
        else_last,
        join,
        then_blocks,
        else_blocks,
    }))
}

fn then_arm(
    prog: &BBProgram,
    start: BlockId,
    else_first: BlockId,
) -> anyhow::Result<Option<(Vec<BlockId>, BlockId, BlockId)>> {
    let mut block = start;
    let mut blocks = Vec::new();
    loop {
        if block >= else_first {
            return Ok(None);
        }
        blocks.push(block);
        match prog.terminator(block)? {
            Terminator::Fallthrough { next } if bf_blocks_are_adjacent(prog, block, next)? => {
                block = next
            }
            Terminator::Jump { insn, target } => {
                if !insn.is_ja() {
                    return Ok(None);
                }
                return Ok(Some((blocks, block, target)));
            }
            _ => return Ok(None),
        }
    }
}

fn else_arm(
    prog: &BBProgram,
    start: BlockId,
    join: BlockId,
) -> anyhow::Result<Option<(Vec<BlockId>, BlockId)>> {
    let mut block = start;
    let mut blocks = Vec::new();
    loop {
        if block >= join {
            return Ok(None);
        }
        blocks.push(block);
        match prog.terminator(block)? {
            Terminator::Fallthrough { next } if next == join => {
                return Ok(Some((blocks, block)));
            }
            Terminator::Fallthrough { next } if bf_blocks_are_adjacent(prog, block, next)? => {
                block = next
            }
            _ => return Ok(None),
        }
    }
}

fn has_exterior_interior_target(
    prog: &BBProgram,
    branch_targets: &std::collections::BTreeSet<InsnSite>,
    site: &BranchFlipSite,
) -> anyhow::Result<bool> {
    let own_target = prog
        .sites_in_block_with_terminator(site.else_first)?
        .first()
        .copied();
    for block in site.body_blocks() {
        for candidate in prog.sites_in_block_with_terminator(block)? {
            if branch_targets.contains(&candidate) && Some(candidate) != own_target {
                return Ok(true);
            }
        }
    }
    Ok(false)
}

pub(super) fn invert_jcc_op(op: u8) -> Option<u8> {
    match op {
        BPF_JEQ => Some(BPF_JNE),
        BPF_JNE => Some(BPF_JEQ),
        BPF_JGT => Some(BPF_JLE),
        BPF_JLE => Some(BPF_JGT),
        BPF_JGE => Some(BPF_JLT),
        BPF_JLT => Some(BPF_JGE),
        BPF_JSGT => Some(BPF_JSLE),
        BPF_JSLE => Some(BPF_JSGT),
        BPF_JSGE => Some(BPF_JSLT),
        BPF_JSLT => Some(BPF_JSGE),
        BPF_JSET => None,
        _ => None,
    }
}
