// SPDX-License-Identifier: MIT
//! BRANCH_FLIP PGO-guided pass.

use std::collections::HashMap;
use std::fs;
use std::path::{Path, PathBuf};

use anyhow::{bail, Context, Result};
use serde::Deserialize;

use crate::analysis::{iter_sites, BranchTargetAnalysis};
use crate::insn::*;
use crate::pass::*;

use crate::rewrite::{
    commit_rewrite_output, fixup_all_branches as fixup_branches_inline, BtfRemapPolicy,
    RewriteOutput,
};

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
/// or where JSET is used (no simple inverse). Also adjusts internal branch
/// offsets within relocated bodies via an address map.
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

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        program.inject_profiling(&self.profiling);
        self.inner.run(program, analyses, ctx)
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

fn read_json_file<T: for<'de> Deserialize<'de>>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&data)
        .with_context(|| format!("failed to parse {label} from {}", path.display()))
}

/// A detected branch-flip site.
pub(super) struct BranchFlipSite {
    /// PC of the Jcc instruction.
    pub(super) pc: usize,
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
    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // Phase 0: check real program-level PMU branch miss rate. Missing PMU
        // data is a profile collection failure, not an optimization skip.
        let Some(program_miss_rate) = program.branch_miss_rate else {
            anyhow::bail!("branch_flip requires real program-level branch_miss_rate data");
        };
        if !program_miss_rate.is_finite() || !(0.0..=1.0).contains(&program_miss_rate) {
            anyhow::bail!(
                "branch_flip program branch_miss_rate must be finite and within [0, 1], got {}",
                program_miss_rate
            );
        }
        if program_miss_rate > self.max_branch_miss_rate {
            return Ok(PassResult::skipped(
                SkipReason {
                    pc: 0,
                    reason: format!(
                        "program branch_miss_rate {:.1}% exceeds threshold {:.1}% (unpredictable branches)",
                        program_miss_rate * 100.0,
                        self.max_branch_miss_rate * 100.0,
                    ),
                },
            ));
        }

        let bt = analyses.get::<BranchTargetAnalysis>(program);

        let n = program.insns.len();

        // Phase 1: scan for all candidate sites.
        let sites = scan_branch_flip_sites(&program.insns);

        // Phase 2: filter sites and collect safe ones to apply.
        let mut safe_sites: Vec<BranchFlipSite> = Vec::new();
        let mut skipped = Vec::new();

        for site in &sites {
            let jcc = &program.insns[site.pc];
            let own_target = jcc
                .branch_target_pc(site.pc)
                .ok_or_else(|| anyhow::anyhow!("branch_flip candidate has invalid target"))?;
            let site_end = site.pc + site.total_len();

            let Some(bp) = program.annotations[site.pc].branch_profile.as_ref() else {
                anyhow::bail!(
                    "branch_flip candidate at pc {} has no real per-site profile data",
                    site.pc
                );
            };
            let direction_total = validate_real_branch_profile(site.pc, bp)?;

            let has_exterior_interior = (site.pc + 1..site_end).any(|pc_inner| {
                pc_inner < bt.is_target.len() && bt.is_target[pc_inner] && pc_inner != own_target
            });

            if has_exterior_interior {
                skipped.push(SkipReason {
                    pc: site.pc,
                    reason: "interior branch target from external source".into(),
                });
                continue;
            }

            // Safety check: JSET cannot be inverted.
            if invert_jcc_op(bpf_op(jcc.code)).is_none() {
                skipped.push(SkipReason {
                    pc: site.pc,
                    reason: "cannot invert condition opcode".into(),
                });
                continue;
            }

            if bp.miss_rate > self.max_branch_miss_rate {
                skipped.push(SkipReason {
                    pc: site.pc,
                    reason: format!(
                        "site branch_miss_rate {:.1}% exceeds threshold {:.1}% (unpredictable branch)",
                        bp.miss_rate * 100.0,
                        self.max_branch_miss_rate * 100.0,
                    ),
                });
                continue;
            }

            let should_flip = bp.taken_count as f64 / (direction_total as f64) >= self.min_bias;

            if !should_flip {
                skipped.push(SkipReason {
                    pc: site.pc,
                    reason: "branch not biased enough".into(),
                });
                continue;
            }
            safe_sites.push(BranchFlipSite {
                pc: site.pc,
                then_len: site.then_len,
                else_len: site.else_len,
            });
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged()
            });
        }

        // Phase 3: apply rewrites.
        safe_sites.sort_by_key(|s| s.pc);

        let mut new_insns: Vec<BpfInsn> = Vec::with_capacity(n);
        let mut addr_map = vec![0usize; n + 1];
        let mut pc = 0;
        let mut site_idx = 0;
        let mut applied = 0;

        while pc < n {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].pc {
                let site = &safe_sites[site_idx];
                let then_start = site.pc + 1;
                let then_end = site.pc + 1 + site.then_len;
                let ja_pc = then_end;
                let else_start = ja_pc + 1;
                let else_end = else_start + site.else_len;

                // Emit inverted Jcc.
                // New layout: [Jcc'] [else M insns] [JA] [then N-1 insns]
                // Jcc' not-taken: fall through to else body (M insns) then JA
                // Jcc' taken: skip else+JA to reach then body
                // offset = else_len + 1 (skip M else insns + 1 JA insn)
                let old_jcc = program.insns[site.pc];
                let new_op = invert_jcc_op(bpf_op(old_jcc.code))
                    .ok_or_else(|| anyhow::anyhow!("branch_flip cannot invert condition"))?;
                let mut new_jcc = old_jcc;
                new_jcc.code = (old_jcc.code & 0x0f) | new_op;
                new_jcc.set_branch_target_delta(branch_delta(site.else_len + 1)?)?;
                new_insns.push(new_jcc);

                // Emit else body (was after JA, now first)
                for (i, &insn) in program.insns[else_start..else_end].iter().enumerate() {
                    addr_map[else_start + i] = new_insns.len();
                    new_insns.push(insn);
                }

                // Emit JA that skips over then body
                addr_map[ja_pc] = new_insns.len();
                new_insns.push(BpfInsn::ja(checked_off16(
                    site.then_len,
                    "branch_flip then-body skip",
                )?));

                // Emit then body (was first, now second)
                for (i, &insn) in program.insns[then_start..then_end].iter().enumerate() {
                    addr_map[then_start + i] = new_insns.len();
                    new_insns.push(insn);
                }

                pc = else_end;
                site_idx += 1;
                applied += 1;
            } else {
                new_insns.push(program.insns[pc]);
                if program.insns[pc].is_ldimm64() && pc + 1 < n {
                    pc += 1;
                    addr_map[pc] = new_insns.len();
                    new_insns.push(program.insns[pc]);
                }
                pc += 1;
            }
        }
        addr_map[n] = new_insns.len();

        // Phase 4: fix up internal branches (for instructions NOT part of rewritten sites).
        fixup_branches_inline(&mut new_insns, &program.insns, &addr_map)?;

        // Restore the manually-set JCC and JA offsets that fixup may have overwritten.
        for site in &safe_sites {
            let new_jcc_pc = addr_map[site.pc];
            new_insns[new_jcc_pc].set_branch_target_delta(branch_delta(site.else_len + 1)?)?;
            let old_ja_pc = site.pc + 1 + site.then_len;
            let new_ja_pc = addr_map[old_ja_pc];
            new_insns[new_ja_pc].set_branch_target_delta(branch_delta(site.then_len)?)?;
        }

        let mut result = commit_rewrite_output(
            program,
            RewriteOutput {
                insns: new_insns,
                addr_map,
                sites_applied: applied,
            },
            BtfRemapPolicy::Remap,
        )?;
        result.sites_skipped = skipped;
        Ok(result)
    }
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

/// Scan for branch-flip candidate sites with correct if/else diamond shape.
///
/// True diamond:
///   pc:     Jcc +N          // N = jcc.off
///   pc+1..pc+N-1: then body (N-1 insns)
///   pc+N:   JA +M
///   pc+N+1..pc+N+M: else body (M insns)
pub(super) fn scan_branch_flip_sites(insns: &[BpfInsn]) -> Vec<BranchFlipSite> {
    iter_sites(insns, |insns, pc| {
        branch_flip_site_at(insns, pc).map(|site| site.then_len + site.else_len + 2)
    })
    .into_iter()
    .filter_map(|site| branch_flip_site_at(insns, site.pc))
    .collect()
}

fn branch_flip_site_at(insns: &[BpfInsn], pc: usize) -> Option<BranchFlipSite> {
    let n = insns.len();
    let jcc = insns.get(pc)?;
    if !jcc.is_cond_jmp() || jcc.off <= 1 {
        return None;
    }
    let off = usize::try_from(jcc.off).expect("invariant: jcc.off > 1 fits usize");
    // The Jcc target is pc + 1 + off = pc + N + 1 (else_start).
    // JA is at pc + off (the last instruction of the then block + JA).
    let ja_pc = pc + off;
    if ja_pc >= n || !insns[ja_pc].is_ja() {
        return None;
    }
    let then_len = off - 1; // N-1 instructions between Jcc and JA
    let else_len = positive_branch_delta(&insns[ja_pc])?;
    let site_end = ja_pc + 1 + else_len;
    if site_end > n {
        return None;
    }
    let valid = !has_straddling_ldimm64(insns, pc + 1, pc + 1 + then_len)
        && !has_straddling_ldimm64(insns, ja_pc + 1, ja_pc + 1 + else_len);
    valid.then_some(BranchFlipSite {
        pc,
        then_len,
        else_len,
    })
}

pub(super) fn checked_off16(delta: usize, label: &str) -> Result<i16> {
    i16::try_from(delta).with_context(|| format!("{label} {delta} exceeds i16"))
}

fn branch_delta(delta: usize) -> Result<i64> {
    i64::try_from(delta).context("branch_flip branch delta exceeds i64")
}

fn positive_branch_delta(insn: &BpfInsn) -> Option<usize> {
    let delta = insn.branch_target_offset()?.delta()?;
    (delta > 0)
        .then(|| usize::try_from(delta).expect("invariant: positive BPF branch delta fits usize"))
}

fn has_straddling_ldimm64(insns: &[BpfInsn], range_start: usize, range_end: usize) -> bool {
    if range_end == 0 || range_start >= range_end {
        return false;
    }
    let last = range_end - 1;
    if last < insns.len() && insns[last].is_ldimm64() {
        return true;
    }
    false
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
