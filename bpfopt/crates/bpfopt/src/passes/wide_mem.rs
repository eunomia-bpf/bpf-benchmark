// SPDX-License-Identifier: MIT
use crate::analysis::{BlockId, InsnSite, ProgramCFG, Terminator};
use crate::insn::*;
use crate::pass::*;
use anyhow::{bail, Context};
use std::collections::BTreeSet;
const MAX_WIDE_MEM_LEN: usize = 22;
const WIDE_MEM_WIDTHS: [u32; 3] = [8, 4, 2];
#[derive(Clone, Debug)]
pub(super) struct RewriteSite {
    pub(super) start_idx: usize,
    pub(super) old_len: usize,
    dst_reg: u8,
    base_reg: u8,
    base_off: i64,
    width: u32,
}
fn try_match_wide_mem_at(insns: &[BpfInsn], idx: usize) -> Option<RewriteSite> {
    let n = insns.len();
    let first = &insns[idx];
    if !first.is_ldx_mem_size(BPF_B) {
        return None;
    }
    let dst = first.dst_reg();
    let base = first.src_reg();
    let first_off = first.off as i64;
    for width in WIDE_MEM_WIDTHS {
        let len_a = 1 + 3 * (width as usize - 1);
        if idx + len_a <= n && match_wide_mem_low_first(insns, idx, dst, base, first_off, width) {
            return Some(wide_mem_site(idx, len_a, dst, base, first_off, width));
        }
        let len_b = 3 * width as usize - 2;
        if idx + len_b <= n {
            if let Some(base_off) =
                match_wide_mem_high_first(insns, idx, dst, base, first_off, width)
            {
                return Some(wide_mem_site(idx, len_b, dst, base, base_off, width));
            }
        }
    }
    None
}
fn wide_mem_site(
    start_idx: usize,
    old_len: usize,
    dst: u8,
    base: u8,
    base_off: i64,
    width: u32,
) -> RewriteSite {
    RewriteSite {
        start_idx,
        old_len,
        dst_reg: dst,
        base_reg: base,
        base_off,
        width,
    }
}
fn match_wide_mem_low_first(
    insns: &[BpfInsn],
    start_idx: usize,
    dst: u8,
    base: u8,
    base_off: i64,
    width: u32,
) -> bool {
    for i in 1..width {
        let idx = start_idx + 3 * (i as usize - 1) + 1;
        let load = &insns[idx];
        let shift = &insns[idx + 1];
        let or = &insns[idx + 2];
        let Some(tmp) = byte_load_tmp(load, base, base_off + i as i64, dst) else {
            return false;
        };
        if !shifted_or_lane(shift, or, dst, tmp, (8 * i) as i32) {
            return false;
        };
    }
    true
}
fn match_wide_mem_high_first(
    insns: &[BpfInsn],
    start_idx: usize,
    dst: u8,
    base: u8,
    first_off: i64,
    width: u32,
) -> Option<i64> {
    let shift0 = &insns[start_idx + 1];
    if !shift0.is_alu_imm(BPF_ALU64, BPF_LSH) || shift0.dst_reg() != dst || shift0.imm != 8 {
        return None;
    }
    let load0 = &insns[start_idx + 2];
    let base_off = load0.off as i64;
    if first_off != base_off + 1 {
        return None;
    }
    let tmp0 = byte_load_tmp(load0, base, base_off, dst)?;
    let or0 = &insns[start_idx + 3];
    if !or_uses_tmp(or0, dst, tmp0) {
        return None;
    }
    for i in 2..width {
        let idx = start_idx + 3 * i as usize - 2;
        let load = &insns[idx];
        let shift = &insns[idx + 1];
        let or = &insns[idx + 2];
        let tmp = byte_load_tmp(load, base, base_off + i as i64, dst)?;
        if !shifted_or_lane(shift, or, dst, tmp, (8 * i) as i32) {
            return None;
        }
    }
    Some(base_off)
}

fn byte_load_tmp(load: &BpfInsn, base: u8, off: i64, forbidden: u8) -> Option<u8> {
    if load.is_ldx_mem_size(BPF_B) && load.src_reg() == base && load.off as i64 == off {
        let tmp = load.dst_reg();
        return (tmp != forbidden).then_some(tmp);
    }
    None
}

fn shifted_or_lane(shift: &BpfInsn, or: &BpfInsn, dst: u8, tmp: u8, amount: i32) -> bool {
    shift.is_alu_imm(BPF_ALU64, BPF_LSH)
        && shift.dst_reg() == tmp
        && shift.imm == amount
        && or_uses_tmp(or, dst, tmp)
}

fn or_uses_tmp(or: &BpfInsn, dst: u8, tmp: u8) -> bool {
    or.is_alu_reg(BPF_ALU64, BPF_OR) && or.dst_reg() == dst && or.src_reg() == tmp
}
pub(super) fn emit_wide_mem(site: &RewriteSite) -> anyhow::Result<Vec<BpfInsn>> {
    let off = i16::try_from(site.base_off).context("wide_mem base_off binding does not fit i16")?;
    let size = match site.width {
        2 => BPF_H,
        4 => BPF_W,
        8 => BPF_DW,
        _ => bail!(
            "WIDE_MEM: unsupported width {} (supports 2, 4, 8)",
            site.width
        ),
    };
    Ok(vec![BpfInsn::ldx_mem(
        size,
        site.dst_reg,
        site.base_reg,
        off,
    )])
}
pub struct WideMemPass;
impl BpfPass for WideMemPass {
    fn run(&self, prog: &mut ProgramCFG, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        let branch_targets = prog.branch_target_entry_sites()?;
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();
        let mut reported_starts = BTreeSet::new();
        let raw_sites = prog.scan_block_starts(MAX_WIDE_MEM_LEN, |window| {
            Ok(try_match_wide_mem_at(window.insns, window.start_idx)
                .map(|site| (site.start_idx, site.old_len, site)))
        })?;
        let mut last_hit_end = None;
        for hit in raw_sites {
            let hit_end = hit.start_idx + hit.old_len;
            if last_hit_end.is_some_and(|(block, end)| block == hit.block && hit.start_idx < end) {
                continue;
            }
            last_hit_end = Some((hit.block, hit_end));
            let body = prog.block_body_view(hit.block)?;
            let start_idx = hit.start_idx;
            let start_site = hit.start;
            let site = hit.value;
            reported_starts.insert(start_site);
            if hit_end > body.sites.len() {
                anyhow::bail!(
                    "wide_mem site at {:?} spans beyond block {:?} body",
                    start_site,
                    hit.block
                );
            }
            let has_interior_target = body.sites[start_idx + 1..hit_end]
                .iter()
                .any(|candidate| branch_targets.contains(candidate));
            if has_interior_target {
                skipped.push(SiteSkipReason::new(start_site, "interior branch target"));
                continue;
            }
            let live_after = prog.live_out_site_checked(body.sites[hit_end - 1])?;
            let has_live_scratch = body.insns[start_idx..hit_end].iter().any(|insn| {
                matches!(insn.class(), BPF_ALU64 | BPF_ALU | BPF_LDX)
                    && insn.dst_reg() != site.dst_reg
                    && live_after.contains(&insn.dst_reg())
            });
            if has_live_scratch {
                skipped.push(SiteSkipReason::new(
                    start_site,
                    "scratch register live after site",
                ));
                continue;
            }
            if site.base_off.rem_euclid(i64::from(site.width)) != 0 {
                skipped.push(SiteSkipReason::new(
                    start_site,
                    format!(
                        "wide load offset {} is not naturally aligned for width {}",
                        site.base_off, site.width
                    ),
                ));
                continue;
            }
            safe_sites.push((start_site, site));
        }
        add_cross_block_wide_mem_skips(prog, &branch_targets, &mut reported_starts, &mut skipped)?;
        if safe_sites.is_empty() {
            return Ok(PassResult::with_sites(0, skipped));
        }
        let applied = apply_candidates_reverse(prog, &safe_sites, &mut skipped, |_, _, site| {
            Ok((site.old_len, emit_wide_mem(site)?))
        })?;
        Ok(PassResult::with_sites(applied, skipped))
    }
}

fn add_cross_block_wide_mem_skips(
    prog: &ProgramCFG,
    branch_targets: &BTreeSet<InsnSite>,
    reported_starts: &mut BTreeSet<InsnSite>,
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<()> {
    for block in prog.block_ids().collect::<Vec<_>>() {
        let block_sites = prog.sites_in_block(block)?;
        for (idx, site) in block_sites.iter().copied().enumerate() {
            if reported_starts.contains(&site) {
                continue;
            }
            let first_block_remaining = block_sites.len() - idx;
            let (window, crossed_branch_target) =
                collect_wide_mem_window(prog, block, idx, branch_targets)?;
            if !crossed_branch_target {
                continue;
            }
            let Some(candidate) = try_match_wide_mem_at(&window, 0) else {
                continue;
            };
            if candidate.old_len <= first_block_remaining {
                continue;
            }
            reported_starts.insert(site);
            skipped.push(SiteSkipReason::new(site, "interior branch target"));
        }
    }
    Ok(())
}
fn collect_wide_mem_window(
    prog: &ProgramCFG,
    start_block: BlockId,
    start_idx: usize,
    branch_targets: &BTreeSet<InsnSite>,
) -> anyhow::Result<(Vec<BpfInsn>, bool)> {
    let mut insns = Vec::with_capacity(MAX_WIDE_MEM_LEN);
    let mut crossed_branch_target = false;
    let mut block = start_block;
    let mut idx = start_idx;
    while insns.len() < MAX_WIDE_MEM_LEN {
        let block_sites = prog.sites_in_block(block)?;
        while idx < block_sites.len() && insns.len() < MAX_WIDE_MEM_LEN {
            let site = block_sites[idx];
            insns.push(*prog.insn(site)?);
            idx += 1;
        }
        if insns.len() >= MAX_WIDE_MEM_LEN {
            break;
        }
        match prog.terminator(block)? {
            Terminator::Fallthrough { next } => {
                if let Some(site) = prog.sites_in_block(next)?.first().copied() {
                    crossed_branch_target |= branch_targets.contains(&site);
                }
                block = next;
                idx = 0;
            }
            _ => break,
        }
    }
    Ok((insns, crossed_branch_target))
}
