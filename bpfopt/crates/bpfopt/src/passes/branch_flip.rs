// SPDX-License-Identifier: MIT
//! BRANCH_FLIP PGO-guided pass.

use std::collections::HashMap;
use std::path::{Path, PathBuf};

use anyhow::{bail, Context, Result};
use serde::Deserialize;

use crate::analysis::{
    annotations_from_profile, read_json_file, BBProgram, BlockId, InsnSite, Terminator,
};
use crate::insn::*;
use crate::pass::*;

/// BRANCH_FLIP: PGO-guided reorder of if/else bodies.
///
/// True if/else diamond in BPF bytecode:
///   pc:             Jcc +N          // conditional jump; if taken, go to else_start
///   pc+1..pc+N:     [then body: N-1 insns]
///   pc+N:           JA +M           // unconditional jump over else-body
///   pc+N+1..pc+N+M: [else body: M insns]
///
/// Where:
///   - `N = jcc.off` (the Jcc offset)
///   - then_len = N - 1 (instructions between Jcc and JA, exclusive)
///   - else_start = pc + N + 1
///   - else_len = M = ja.off
///
/// After flip (inverted condition, bodies swapped):
///   pc:             J!cc +M         // inverted, jump over else-body (now first)
///   pc+1..pc+M:     [else body: M insns]
///   pc+M+1:         JA +(N-1)       // jump over then-body (now second)
///   pc+M+2..pc+M+N: [then body: N-1 insns]
///
/// **PGO-guided mode**: branch_flip requires real per-site `BranchProfile`
/// data. Program-level PMU data and each candidate site's PMU miss rate are
/// safety gates for unpredictable branches.
///
/// Safety: skips sites where external branches target interior instructions,
/// or where JSET is used (no simple inverse). The rewrite updates BBProgram
/// terminators and block order; lower recomputes branch offsets.
pub struct BranchFlipPass {
    /// Minimum taken rate to trigger a PGO-guided flip.
    pub min_bias: f64,
    /// Maximum branch miss rate (from PMU) to allow branch flipping.
    /// If the program's branch miss rate exceeds this threshold, branches are
    /// considered unpredictable and flipping is skipped to avoid CMOV-like
    /// regression on misprediction-heavy workloads.
    /// Default: 0.05 (5%).
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
        let annotations = annotations_from_profile(&self.profiling);
        run_on_bbprogram(
            program,
            &annotations,
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

/// A detected branch-flip site.
#[derive(Clone)]
pub(super) struct BranchFlipSite {
    /// PC of the Jcc instruction.
    pub(super) pc: usize,
    pred: BlockId,
    then_first: BlockId,
    then_last: BlockId,
    else_first: BlockId,
    else_last: BlockId,
    join: BlockId,
    /// Number of instructions in the then-body (N-1, between Jcc and JA).
    pub(super) then_len: usize,
    /// Number of instructions in the else-body (M = ja.off).
    pub(super) else_len: usize,
}

impl BranchFlipSite {
    /// Total number of instructions in the site (Jcc + then + JA + else).
    pub(super) fn total_len(&self) -> usize {
        1 + self.then_len + 1 + self.else_len
    }
}

impl BpfPass for BranchFlipPass {
    fn name(&self) -> &str {
        "branch_flip"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(
            program,
            &ctx.annotations,
            ctx.branch_miss_rate,
            self.min_bias,
            self.max_branch_miss_rate,
        )
    }
}

pub fn run_on_bbprogram(
    prog: &mut BBProgram,
    annotations: &[InsnAnnotation],
    branch_miss_rate: Option<f64>,
    min_bias: f64,
    max_branch_miss_rate: f64,
) -> anyhow::Result<PassResult> {
    // Phase 0: check real program-level PMU branch miss rate. Missing PMU
    // data is a profile collection failure, not an optimization skip.
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
        return Ok(PassResult::skipped(SkipReason {
            pc: 0,
            reason: format!(
                "program branch_miss_rate {:.1}% exceeds threshold {:.1}% (unpredictable branches)",
                program_miss_rate * 100.0,
                max_branch_miss_rate * 100.0,
            ),
        }));
    }

    let branch_targets = prog.branch_target_pcs()?;
    let site_pcs = prog.current_site_pcs()?;

    // Phase 1: scan for all candidate sites.
    let sites = scan_branch_flip_sites(prog)?;

    // Phase 2: filter sites and collect safe ones to apply.
    let mut safe_sites: Vec<BranchFlipSite> = Vec::new();
    let mut skipped = Vec::new();

    for site in &sites {
        let own_target = prog.current_block_start_pc(site.else_first)?;
        let site_end = site.pc + site.total_len();

        let Some(bp) = annotations
            .get(site.pc)
            .and_then(|annotation| annotation.branch_profile.as_ref())
        else {
            anyhow::bail!(
                "branch_flip candidate at pc {} has no real per-site profile data",
                site.pc
            );
        };
        let direction_total = validate_real_branch_profile(site.pc, bp)?;

        let frame = prog.block(site.pred)?.frame;
        let has_exterior_interior = prog
            .sites_in_frame_pc_range(&site_pcs, frame, site.pc + 1, site_end)?
            .into_iter()
            .any(|(pc_inner, _)| branch_targets.contains(&pc_inner) && pc_inner != own_target);

        if has_exterior_interior {
            skipped.push(SkipReason {
                pc: site.pc,
                reason: "interior branch target from external source".into(),
            });
            continue;
        }

        // Safety check: JSET cannot be inverted.
        let cond = match prog.block(site.pred)?.terminator {
            Terminator::CondBranch { cond, .. } => cond,
            term => anyhow::bail!(
                "branch_flip site at pc {} expected conditional terminator, got {:?}",
                site.pc,
                term
            ),
        };
        if invert_jcc_op(bpf_op(cond.code)).is_none() {
            skipped.push(SkipReason {
                pc: site.pc,
                reason: "cannot invert condition opcode".into(),
            });
            continue;
        }

        if bp.miss_rate > max_branch_miss_rate {
            skipped.push(SkipReason {
                pc: site.pc,
                reason: format!(
                    "site branch_miss_rate {:.1}% exceeds threshold {:.1}% (unpredictable branch)",
                    bp.miss_rate * 100.0,
                    max_branch_miss_rate * 100.0,
                ),
            });
            continue;
        }

        let should_flip = bp.taken_count as f64 / (direction_total as f64) >= min_bias;

        if !should_flip {
            skipped.push(SkipReason {
                pc: site.pc,
                reason: "branch not biased enough".into(),
            });
            continue;
        }
        validate_flipped_branch_deltas(site, cond)?;
        safe_sites.push(site.clone());
    }

    if safe_sites.is_empty() {
        return Ok(PassResult {
            sites_skipped: skipped,
            ..PassResult::unchanged()
        });
    }

    // Phase 3: apply rewrites.
    safe_sites.sort_by_key(|s| s.pc);
    for site in &safe_sites {
        apply_branch_flip_site(prog, site)?;
    }

    Ok(PassResult {
        sites_applied: safe_sites.len(),
        sites_skipped: skipped,
        ..PassResult::unchanged()
    })
}

fn validate_real_branch_profile(pc: usize, bp: &BranchProfile) -> anyhow::Result<u64> {
    if bp.branch_count == 0 {
        anyhow::bail!("branch_flip candidate at pc {pc} has zero branch_count");
    }
    if bp.branch_misses > bp.branch_count {
        anyhow::bail!(
            "branch_flip candidate at pc {pc} has branch_misses {} exceeding branch_count {}",
            bp.branch_misses,
            bp.branch_count
        );
    }
    if !bp.miss_rate.is_finite() || !(0.0..=1.0).contains(&bp.miss_rate) {
        anyhow::bail!(
            "branch_flip candidate at pc {pc} has invalid miss_rate {}",
            bp.miss_rate
        );
    }
    let direction_total = bp
        .taken_count
        .checked_add(bp.not_taken_count)
        .ok_or_else(|| {
            anyhow::anyhow!("branch_flip candidate at pc {pc} direction counters overflow")
        })?;
    if direction_total == 0 {
        anyhow::bail!("branch_flip candidate at pc {pc} has no real per-site direction data");
    }
    if direction_total > bp.branch_count {
        anyhow::bail!(
            "branch_flip candidate at pc {pc} direction count {direction_total} exceeds branch_count {}",
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
            "branch_flip site at pc {} is not a contiguous BBProgram diamond",
            site.pc
        );
    }

    let (cond, taken, fallthrough) = match prog.block(pred)?.terminator {
        Terminator::CondBranch {
            cond,
            taken,
            fallthrough,
        } => (cond, taken, fallthrough),
        term => anyhow::bail!(
            "branch_flip site at pc {} expected conditional terminator, got {:?}",
            site.pc,
            term
        ),
    };
    if taken != else_first || fallthrough != then_first {
        anyhow::bail!(
            "branch_flip site at pc {} has unexpected cond targets taken={:?} fallthrough={:?}",
            site.pc,
            taken,
            fallthrough
        );
    }

    let (ja, join) = match prog.block(then_last)?.terminator {
        Terminator::Jump { insn, target } => (insn, target),
        term => anyhow::bail!(
            "branch_flip site at pc {} expected then-body JA terminator, got {:?}",
            site.pc,
            term
        ),
    };
    if join != site.join {
        anyhow::bail!(
            "branch_flip site at pc {} expected join {:?}, got {:?}",
            site.pc,
            site.join,
            join
        );
    }
    match prog.block(else_last)?.terminator {
        Terminator::Fallthrough { next } if next == join => {}
        term => anyhow::bail!(
            "branch_flip site at pc {} expected else-body fallthrough to {:?}, got {:?}",
            site.pc,
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
        prog.blocks.len(),
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

/// Scan for branch-flip candidate sites with correct if/else diamond shape.
///
/// True diamond:
///   pc:     Jcc +N          // N = jcc.off
///   pc+1..pc+N-1: then body (N-1 insns)
///   pc+N:   JA +M
///   pc+N+1..pc+N+M: else body (M insns)
pub(super) fn scan_branch_flip_sites(prog: &BBProgram) -> anyhow::Result<Vec<BranchFlipSite>> {
    let site_pcs = prog.current_site_pcs()?;
    let mut sites = Vec::new();
    let mut next_allowed_pc = 0usize;
    for block in prog.blocks() {
        let branch_site = InsnSite {
            block: block.id,
            idx: block.insns.len(),
        };
        let Some(&pc) = site_pcs.get(&branch_site) else {
            continue;
        };
        if pc < next_allowed_pc {
            continue;
        }
        if let Some(site) = branch_flip_site_at(prog, &site_pcs, block.id, pc)? {
            next_allowed_pc = site.pc + site.total_len();
            sites.push(site);
        }
    }
    Ok(sites)
}

fn branch_flip_site_at(
    prog: &BBProgram,
    site_pcs: &std::collections::BTreeMap<InsnSite, usize>,
    pred: BlockId,
    pc: usize,
) -> anyhow::Result<Option<BranchFlipSite>> {
    let Terminator::CondBranch {
        cond,
        taken: else_first,
        fallthrough: then_first,
    } = prog.block(pred)?.terminator
    else {
        return Ok(None);
    };
    if !cond.is_cond_jmp() {
        return Ok(None);
    }
    if prog.current_block_start_pc(then_first)? != pc + 1 {
        return Ok(None);
    }
    let Some((then_last, join, ja_pc)) = then_arm(prog, site_pcs, then_first, else_first)? else {
        return Ok(None);
    };
    let Some((else_last, else_end_pc)) = else_arm(prog, site_pcs, else_first, join)? else {
        return Ok(None);
    };
    if then_last.0 + 1 != else_first.0 {
        return Ok(None);
    }
    let then_len = ja_pc
        .checked_sub(pc + 1)
        .ok_or_else(|| anyhow::anyhow!("branch_flip then length underflows at pc {pc}"))?;
    if then_len == 0 {
        return Ok(None);
    }
    let else_start = ja_pc + 1;
    if prog.current_block_start_pc(else_first)? != else_start {
        return Ok(None);
    }
    let else_len = else_end_pc
        .checked_sub(else_start)
        .ok_or_else(|| anyhow::anyhow!("branch_flip else length underflows at pc {pc}"))?;
    if else_len == 0 {
        return Ok(None);
    }
    Ok(Some(BranchFlipSite {
        pc,
        pred,
        then_first,
        then_last,
        else_first,
        else_last,
        join,
        then_len,
        else_len,
    }))
}

fn then_arm(
    prog: &BBProgram,
    site_pcs: &std::collections::BTreeMap<InsnSite, usize>,
    start: BlockId,
    else_first: BlockId,
) -> anyhow::Result<Option<(BlockId, BlockId, usize)>> {
    let mut block = start;
    loop {
        if block.0 >= else_first.0 {
            return Ok(None);
        }
        match prog.block(block)?.terminator {
            Terminator::Fallthrough { next } if next.0 == block.0 + 1 => block = next,
            Terminator::Jump { insn, target } => {
                if !insn.is_ja() {
                    return Ok(None);
                }
                let site = InsnSite {
                    block,
                    idx: prog.block(block)?.insns.len(),
                };
                let ja_pc = *site_pcs
                    .get(&site)
                    .ok_or_else(|| anyhow::anyhow!("missing current pc for {:?}", site))?;
                return Ok(Some((block, target, ja_pc)));
            }
            _ => return Ok(None),
        }
    }
}

fn else_arm(
    prog: &BBProgram,
    _site_pcs: &std::collections::BTreeMap<InsnSite, usize>,
    start: BlockId,
    join: BlockId,
) -> anyhow::Result<Option<(BlockId, usize)>> {
    let mut block = start;
    loop {
        match prog.block(block)?.terminator {
            Terminator::Fallthrough { next } if next == join => {
                return Ok(Some((block, prog.current_block_start_pc(join)?)));
            }
            Terminator::Fallthrough { next } if next.0 == block.0 + 1 => block = next,
            _ => return Ok(None),
        }
    }
}

fn validate_flipped_branch_deltas(site: &BranchFlipSite, cond: BpfInsn) -> anyhow::Result<()> {
    let mut inverted = cond;
    inverted.set_branch_target_delta(i64::try_from(site.else_len + 1).map_err(|_| {
        anyhow::anyhow!(
            "branch_flip site at pc {} else length {} overflows branch delta",
            site.pc,
            site.else_len
        )
    })?)?;
    let mut ja = BpfInsn::ja(0);
    ja.set_branch_target_delta(i64::try_from(site.then_len).map_err(|_| {
        anyhow::anyhow!(
            "branch_flip site at pc {} then length {} overflows branch delta",
            site.pc,
            site.then_len
        )
    })?)?;
    Ok(())
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
