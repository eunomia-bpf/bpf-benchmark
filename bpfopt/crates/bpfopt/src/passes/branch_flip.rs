// SPDX-License-Identifier: MIT
use std::collections::HashMap;
use std::path::{Path, PathBuf};

use anyhow::{bail, Context, Result};
use serde::Deserialize;

use crate::analysis::{
    control_flow_target_sites, read_json_file, BBProgram, BlockId, InsnSite, Terminator,
};
use crate::insn::*;
use crate::pass::*;
pub struct BranchFlipPass {
    pub min_bias: f64,
    pub max_branch_miss_rate: f64,
}

struct ProfiledBranchFlipPass {
    inner: BranchFlipPass,
    profiling: ProfilingData,
}

impl BranchFlipPass {
    pub fn from_cli_args(args: &[String]) -> Result<Box<dyn BpfPass>> {
        let profile = BranchFlipCliArgs::parse(args)?;
        Ok(Box::new(ProfiledBranchFlipPass {
            inner: BranchFlipPass {
                min_bias: 0.7,
                max_branch_miss_rate: 0.05,
            },
            profiling: read_branch_flip_profile(&profile.profile)?,
        }))
    }
}

impl BpfPass for ProfiledBranchFlipPass {
    fn name(&self) -> &str {
        self.inner.name()
    }

    fn run(&self, program: &mut BBProgram, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        program.attach_profile_data(&self.profiling)?;
        run_on_bbprogram(
            program,
            self.profiling.branch_miss_rate,
            self.inner.min_bias,
            self.inner.max_branch_miss_rate,
        )
    }
}

struct BranchFlipCliArgs {
    profile: PathBuf,
}

impl BranchFlipCliArgs {
    fn parse(args: &[String]) -> Result<Self> {
        let mut profile = None;
        let mut iter = args.iter();
        while let Some(arg) = iter.next() {
            match arg.as_str() {
                "--profile" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow::anyhow!("--profile requires FILE"))?;
                    profile = Some(PathBuf::from(value));
                }
                other => bail!("branch_flip unknown pass-local arg: {other}"),
            }
        }
        Ok(Self {
            profile: profile.ok_or_else(|| anyhow::anyhow!("branch_flip requires --profile"))?,
        })
    }
}

#[derive(Debug, Deserialize)]
struct BranchProfileJson {
    branch_miss_rate: f64,
    #[serde(default)]
    per_site: HashMap<String, BranchProfileSiteJson>,
}

#[derive(Debug, Deserialize)]
struct BranchProfileSiteJson {
    branch_count: u64,
    branch_misses: u64,
    miss_rate: f64,
    taken: u64,
    not_taken: u64,
}

fn read_branch_flip_profile(path: &Path) -> Result<ProfilingData> {
    let profile: BranchProfileJson = read_json_file(path, "branch-flip profile JSON")?;
    if !profile.branch_miss_rate.is_finite() || !(0.0..=1.0).contains(&profile.branch_miss_rate) {
        bail!(
            "profile branch_miss_rate must be finite and within [0, 1], got {}",
            profile.branch_miss_rate
        );
    }
    let mut data = ProfilingData {
        branch_miss_rate: Some(profile.branch_miss_rate),
        ..ProfilingData::default()
    };
    for (pc, counts) in profile.per_site {
        let pc = pc
            .parse::<usize>()
            .with_context(|| format!("invalid per_site pc key: {pc}"))?;
        if counts.branch_count == 0 {
            bail!("profile per_site[{pc}] has zero branch_count");
        }
        if counts.branch_misses > counts.branch_count {
            bail!(
                "profile per_site[{pc}] branch_misses {} exceeds branch_count {}",
                counts.branch_misses,
                counts.branch_count
            );
        }
        if !counts.miss_rate.is_finite() || !(0.0..=1.0).contains(&counts.miss_rate) {
            bail!(
                "profile per_site[{pc}] miss_rate must be finite and within [0, 1], got {}",
                counts.miss_rate
            );
        }
        let direction_count = counts
            .taken
            .checked_add(counts.not_taken)
            .ok_or_else(|| anyhow::anyhow!("profile per_site[{pc}] direction counters overflow"))?;
        if direction_count > counts.branch_count {
            bail!(
                "profile per_site[{pc}] direction count {direction_count} exceeds branch_count {}",
                counts.branch_count
            );
        }
        data.branch_profiles.insert(
            pc,
            BranchProfile {
                branch_count: counts.branch_count,
                branch_misses: counts.branch_misses,
                miss_rate: counts.miss_rate,
                taken_count: counts.taken,
                not_taken_count: counts.not_taken,
            },
        );
    }
    Ok(data)
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
}

impl BranchFlipSite {
    fn body_blocks(&self) -> impl Iterator<Item = BlockId> {
        (self.then_first.0..=self.else_last.0).map(BlockId)
    }
}

impl BpfPass for BranchFlipPass {
    fn name(&self) -> &str {
        "branch_flip"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        program.attach_profile_from_annotations(&ctx.annotations)?;
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

    let branch_targets = control_flow_target_sites(prog)?;
    let sites = scan_branch_flip_sites(prog)?;
    let mut safe_sites: Vec<BranchFlipSite> = Vec::new();
    let mut skipped = Vec::new();

    for site in &sites {
        let Some(bp) = prog
            .profile_at(site.cond_site)
            .and_then(|record| record.branch_profile.as_ref())
        else {
            anyhow::bail!(
                "branch_flip candidate at {:?} has no real per-site profile data",
                site.cond_site
            );
        };
        let direction_total = validate_real_branch_profile(site.cond_site, bp)?;

        if has_exterior_interior_target(prog, &branch_targets, site)? {
            skipped.push(prog.bf_skip_reason(
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
            skipped.push(
                prog.bf_skip_reason(site.cond_site, "cannot invert condition opcode".into())?,
            );
            continue;
        }

        if bp.miss_rate > max_branch_miss_rate {
            skipped.push(prog.bf_skip_reason(
                site.cond_site,
                format!(
                    "site branch_miss_rate {:.1}% exceeds threshold {:.1}% (unpredictable branch)",
                    bp.miss_rate * 100.0,
                    max_branch_miss_rate * 100.0,
                ),
            )?);
            continue;
        }

        let should_flip = bp.taken_count as f64 / (direction_total as f64) >= min_bias;

        if !should_flip {
            skipped.push(prog.bf_skip_reason(site.cond_site, "branch not biased enough".into())?);
            continue;
        }
        prog.bf_validate_flipped_branch_deltas(
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

fn validate_real_branch_profile(report_site: InsnSite, bp: &BranchProfile) -> anyhow::Result<u64> {
    if bp.branch_count == 0 {
        anyhow::bail!(
            "branch_flip candidate at {:?} has zero branch_count",
            report_site
        );
    }
    if bp.branch_misses > bp.branch_count {
        anyhow::bail!(
            "branch_flip candidate at {:?} has branch_misses {} exceeding branch_count {}",
            report_site,
            bp.branch_misses,
            bp.branch_count
        );
    }
    if !bp.miss_rate.is_finite() || !(0.0..=1.0).contains(&bp.miss_rate) {
        anyhow::bail!(
            "branch_flip candidate at {:?} has invalid miss_rate {}",
            report_site,
            bp.miss_rate
        );
    }
    let direction_total = bp
        .taken_count
        .checked_add(bp.not_taken_count)
        .ok_or_else(|| {
            anyhow::anyhow!(
                "branch_flip candidate at {:?} direction counters overflow",
                report_site
            )
        })?;
    if direction_total == 0 {
        anyhow::bail!(
            "branch_flip candidate at {:?} has no real per-site direction data",
            report_site
        );
    }
    if direction_total > bp.branch_count {
        anyhow::bail!(
            "branch_flip candidate at {:?} direction count {direction_total} exceeds branch_count {}",
            report_site,
            bp.branch_count
        );
    }
    Ok(direction_total)
}

fn apply_branch_flip_site(prog: &mut BBProgram, site: &BranchFlipSite) -> anyhow::Result<()> {
    let pred = site.pred;
    let then_first = site.then_first;
    let then_last = site.then_last;
    let else_first = site.else_first;
    let else_last = site.else_last;

    if pred.0 + 1 != then_first.0
        || then_first.0 > then_last.0
        || then_last.0 + 1 != else_first.0
        || else_first.0 > else_last.0
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

    let order = swapped_range_order(
        prog.block_count(),
        then_first..=then_last,
        else_first..=else_last,
    );
    prog.permute_blocks(&order)
}

fn swapped_range_order(
    block_count: usize,
    first: std::ops::RangeInclusive<BlockId>,
    second: std::ops::RangeInclusive<BlockId>,
) -> Vec<BlockId> {
    let first_start = first.start().0;
    let first_end = first.end().0;
    let second_start = second.start().0;
    let second_end = second.end().0;
    let mut order = Vec::with_capacity(block_count);
    let mut block = 0usize;
    while block < block_count {
        if block == first_start {
            order.extend((second_start..=second_end).map(BlockId));
            order.extend((first_start..=first_end).map(BlockId));
            block = second_end + 1;
        } else if (first_start..=second_end).contains(&block) {
            block += 1;
        } else {
            order.push(BlockId(block));
            block += 1;
        }
    }
    order
}
pub(super) fn scan_branch_flip_sites(prog: &BBProgram) -> anyhow::Result<Vec<BranchFlipSite>> {
    let mut sites = Vec::new();
    let mut next_allowed_block = 0usize;
    for block in prog.blocks() {
        if block.id.0 < next_allowed_block {
            continue;
        }
        if let Some(site) = branch_flip_site_at(prog, block.id)? {
            next_allowed_block = site.join.0;
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
    if !prog.bf_blocks_are_adjacent(pred, then_first)? {
        return Ok(None);
    }
    let Some((then_last, join)) = then_arm(prog, then_first, else_first)? else {
        return Ok(None);
    };
    let Some(else_last) = else_arm(prog, else_first, join)? else {
        return Ok(None);
    };
    if !prog.bf_blocks_are_adjacent(then_last, else_first)? {
        return Ok(None);
    }
    if !prog.bf_block_range_has_body_site(then_first, then_last)? {
        return Ok(None);
    }
    if !prog.bf_blocks_are_adjacent(else_last, join)? {
        return Ok(None);
    }
    if !prog.bf_block_range_has_body_site(else_first, else_last)? {
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
    }))
}

fn then_arm(
    prog: &BBProgram,
    start: BlockId,
    else_first: BlockId,
) -> anyhow::Result<Option<(BlockId, BlockId)>> {
    let mut block = start;
    loop {
        if block.0 >= else_first.0 {
            return Ok(None);
        }
        match prog.terminator(block)? {
            Terminator::Fallthrough { next } if next.0 == block.0 + 1 => block = next,
            Terminator::Jump { insn, target } => {
                if !insn.is_ja() {
                    return Ok(None);
                }
                return Ok(Some((block, target)));
            }
            _ => return Ok(None),
        }
    }
}

fn else_arm(prog: &BBProgram, start: BlockId, join: BlockId) -> anyhow::Result<Option<BlockId>> {
    let mut block = start;
    loop {
        match prog.terminator(block)? {
            Terminator::Fallthrough { next } if next == join => {
                return Ok(Some(block));
            }
            Terminator::Fallthrough { next } if next.0 == block.0 + 1 => block = next,
            _ => return Ok(None),
        }
    }
}

fn has_exterior_interior_target(
    prog: &BBProgram,
    branch_targets: &std::collections::BTreeSet<InsnSite>,
    site: &BranchFlipSite,
) -> anyhow::Result<bool> {
    let own_target = prog.first_site_in_block(site.else_first)?;
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
