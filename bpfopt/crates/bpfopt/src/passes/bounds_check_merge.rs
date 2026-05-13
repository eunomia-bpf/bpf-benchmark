// SPDX-License-Identifier: MIT
use std::collections::BTreeSet;

use crate::analysis::{BlockId, InsnSite, ProgramCFG, Terminator};
use crate::insn::*;
use crate::pass::*;
const MAX_LADDER_WINDOW_GROWTH: i32 = 24;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum GuardCmpKind {
    Strict,
    Inclusive,
}

#[derive(Clone, Debug)]
struct GuardSite {
    mov: InsnSite,
    add: InsnSite,
    compare: InsnSite,
    root_reg: u8,
    data_end_reg: u8,
    /// Identity of the underlying packet pointer (ptr_def from ProgramCFG lift).
    /// Replaces the old `root_id: u32` counter — two guards share a "root"
    /// iff they observe the same `ptr_def` site.
    root_ptr_def: InsnSite,
    window_end: i32,
    cmp_kind: GuardCmpKind,
    slow_target: BlockId,
    can_widen_in_place: bool,
    can_remove_setup: bool,
}

#[derive(Default)]
struct ScanResult {
    guards: Vec<GuardSite>,
    skips: Vec<SiteSkipReason>,
}

pub struct BoundsCheckMergePass;

impl BpfPass for BoundsCheckMergePass {
    fn name(&self) -> &str {
        "bounds_check_merge"
    }
    fn run(&self, program: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx.prog_type)
    }
}

pub fn run_on_bbprogram(prog: &mut ProgramCFG, prog_type: u32) -> anyhow::Result<PassResult> {
    if packet_ctx_layout(prog_type, PacketCtxLayoutScope::PacketAccess).is_none() {
        return Ok(PassResult::default());
    }
    if prog.is_empty() {
        return Ok(PassResult::default());
    }

    let target_sites = prog.branch_target_entry_sites()?;
    let mut scan = scan_guard_sites(prog, &target_sites)?;
    if scan.guards.is_empty() {
        return Ok(PassResult::with_sites(0, scan.skips));
    }

    let mut rewrites = Vec::new();
    let mut consumed = vec![false; scan.guards.len()];
    let mut i = 0usize;
    while i < scan.guards.len() {
        if consumed[i] {
            i += 1;
            continue;
        }

        let mut group = vec![i];
        let mut j = i + 1;
        while j < scan.guards.len() {
            let prev = &scan.guards[group[group.len() - 1]];
            let next = &scan.guards[j];
            if !can_extend_ladder(prev, next, prog, &target_sites)? {
                break;
            }
            group.push(j);
            j += 1;
        }

        if group.len() >= 2 {
            if let Some(rewrite) = build_ladder_rewrite(&group, &scan.guards, &target_sites) {
                for &idx in &group {
                    consumed[idx] = true;
                }
                rewrites.push(rewrite);
                i = j;
                continue;
            }
        }

        i += 1;
    }

    for (idx, guard) in scan.guards.iter().enumerate() {
        if !consumed[idx] {
            scan.skips.push(SiteSkipReason::new(
                guard.compare,
                "guard not part of a mergeable ladder",
            ));
        }
    }

    if rewrites.is_empty() {
        return Ok(PassResult::with_sites(0, scan.skips));
    }

    apply_rewrites(prog, &rewrites, &mut scan.skips)?;
    Ok(PassResult::with_sites(rewrites.len(), scan.skips))
}

fn apply_rewrites(
    prog: &mut ProgramCFG,
    rewrites: &[(InsnSite, i32, Vec<InsnSite>)],
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<()> {
    let mut deleted_sites = BTreeSet::new();
    let mut deleted_branches = BTreeSet::new();

    for (dominant_add, merged_end, skip_sites) in rewrites {
        let mut widened = *prog.insn(*dominant_add)?;
        widened.imm = *merged_end;
        prog.try_replace_range(*dominant_add, 1, vec![widened], skipped)?;

        for &site in skip_sites {
            if prog.is_terminator_site(site)? {
                deleted_branches.insert(prog.site_block(site));
            } else {
                deleted_sites.insert(site);
            }
        }
    }

    delete_body_sites_reverse(prog, deleted_sites, skipped)?;
    for block in deleted_branches {
        prog.delete_cond_branch(block)?;
    }
    Ok(())
}

fn scan_guard_sites(
    prog: &ProgramCFG,
    target_sites: &BTreeSet<InsnSite>,
) -> anyhow::Result<ScanResult> {
    let mut result = ScanResult::default();
    for block in prog.blocks() {
        let block_sites = prog.sites_in_block_with_terminator(block.id)?;
        for (idx, site) in block_sites.iter().copied().enumerate() {
            let setup = (idx >= 2).then(|| (block_sites[idx - 2], block_sites[idx - 1]));
            if let Some(guard) =
                detect_guard_candidate(site, prog, target_sites, setup, &mut result.skips)?
            {
                result.guards.push(guard);
            }
        }
    }
    Ok(result)
}

fn detect_guard_candidate(
    site: InsnSite,
    prog: &ProgramCFG,
    target_sites: &BTreeSet<InsnSite>,
    setup: Option<(InsnSite, InsnSite)>,
    skips: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<Option<GuardSite>> {
    let Some(insn) = prog.insn_at(site) else {
        return Ok(None);
    };
    let Some((cursor_reg, data_end_reg, cmp_kind)) = normalize_slow_guard(insn) else {
        return Ok(None);
    };
    let Some((mov_site, add_site)) = setup else {
        return Ok(None);
    };
    let mov = prog.insn(mov_site)?;
    let add = prog.insn(add_site)?;
    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != cursor_reg {
        return Ok(None);
    }
    if add.dst_reg() != cursor_reg {
        return Ok(None);
    }

    let root_reg = mov.src_reg();
    // At the compare site (entry state), root_reg and data_end_reg should
    // still hold their packet types, and cursor_reg should be PacketData
    // with const_off == window_end (for the BPF_ADD K case).
    let root_state = prog.reg_fact_at(site, root_reg)?;
    let data_end_state = prog.reg_fact_at(site, data_end_reg)?;
    let cursor_state = prog.reg_fact_at(site, cursor_reg)?;

    if add.code == (BPF_ALU64 | BPF_ADD | BPF_X) {
        if let (Some((left_root, 0)), Some(right_root)) =
            (root_state.as_packet_data(), data_end_state.as_packet_end())
        {
            if left_root == right_root {
                skips.push(SiteSkipReason {
                    site,
                    reason: "variable packet window is not mergeable in v1".into(),
                });
            }
        }
        return Ok(None);
    }
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K) {
        return Ok(None);
    }

    let window_end = add.imm;
    if window_end <= 0 {
        return Ok(None);
    }

    let Some((cursor_ptr_def, cursor_off)) = cursor_state.as_packet_data() else {
        return Ok(None);
    };
    let Some((root_ptr_def, root_off)) = root_state.as_packet_data() else {
        return Ok(None);
    };
    let Some(end_ptr_def) = data_end_state.as_packet_end() else {
        return Ok(None);
    };
    if cursor_ptr_def != root_ptr_def
        || cursor_ptr_def != end_ptr_def
        || root_off != 0
        || cursor_off != window_end
    {
        return Ok(None);
    }

    if !prog.is_terminator_site(site)? {
        return Ok(None);
    }
    let slow_target = match prog.terminator_at_site(site)? {
        Terminator::CondBranch { taken, .. } => taken,
        _ => return Ok(None),
    };
    let cursor_dead = cursor_dead_after_compare(prog, add_site, site, cursor_reg);
    let can_widen_in_place = !target_sites.contains(&mov_site)
        && !target_sites.contains(&add_site)
        && !target_sites.contains(&site)
        && cursor_dead;
    let can_remove_setup =
        !target_sites.contains(&mov_site) && !target_sites.contains(&add_site) && cursor_dead;

    Ok(Some(GuardSite {
        mov: mov_site,
        add: add_site,
        compare: site,
        root_reg,
        data_end_reg,
        root_ptr_def: cursor_ptr_def,
        window_end,
        cmp_kind,
        slow_target,
        can_widen_in_place,
        can_remove_setup,
    }))
}

fn cursor_dead_after_compare(
    prog: &ProgramCFG,
    add_site: InsnSite,
    compare_site: InsnSite,
    cursor_reg: u8,
) -> bool {
    let Some(def) = prog.def_sites().find(|def| {
        InsnSite {
            block: def.block,
            idx: def.idx,
        } == add_site
            && def.reg == cursor_reg
    }) else {
        return false;
    };
    prog.uses_for_def(def).iter().all(|use_site| {
        InsnSite {
            block: use_site.block,
            idx: use_site.idx,
        } == compare_site
    })
}

fn normalize_slow_guard(insn: &BpfInsn) -> Option<(u8, u8, GuardCmpKind)> {
    if insn.class() != BPF_JMP || bpf_src(insn.code) != BPF_X {
        return None;
    }

    match bpf_op(insn.code) {
        BPF_JGT => Some((insn.dst_reg(), insn.src_reg(), GuardCmpKind::Strict)),
        BPF_JLT => Some((insn.src_reg(), insn.dst_reg(), GuardCmpKind::Strict)),
        BPF_JGE => Some((insn.dst_reg(), insn.src_reg(), GuardCmpKind::Inclusive)),
        BPF_JLE => Some((insn.src_reg(), insn.dst_reg(), GuardCmpKind::Inclusive)),
        _ => None,
    }
}

fn can_extend_ladder(
    prev: &GuardSite,
    next: &GuardSite,
    prog: &ProgramCFG,
    target_sites: &BTreeSet<InsnSite>,
) -> anyhow::Result<bool> {
    if prev.root_ptr_def != next.root_ptr_def
        || prev.root_reg != next.root_reg
        || prev.data_end_reg != next.data_end_reg
        || prev.cmp_kind != next.cmp_kind
        || prev.slow_target != next.slow_target
        || next.window_end <= prev.window_end
        || next.window_end - prev.window_end > MAX_LADDER_WINDOW_GROWTH
        || target_sites.contains(&next.compare)
    {
        return Ok(false);
    }
    interleaves_are_merge_safe(prog, prev.compare, next.mov, target_sites)
}

fn interleaves_are_merge_safe(
    prog: &ProgramCFG,
    start: InsnSite,
    end: InsnSite,
    target_sites: &BTreeSet<InsnSite>,
) -> anyhow::Result<bool> {
    let frame = prog.block_frame(start.block)?;
    if prog.block_frame(end.block)? != frame || !prog.is_terminator_site(start)? {
        return Ok(false);
    }

    let Terminator::CondBranch { fallthrough, .. } = prog.terminator(start.block)? else {
        return Ok(false);
    };

    let mut cursor = fallthrough;
    let mut visited = BTreeSet::new();
    loop {
        if !visited.insert(cursor) || prog.block_frame(cursor)? != frame {
            return Ok(false);
        }

        for site in prog.sites_in_block_with_terminator(cursor)? {
            if cursor == prog.site_block(end) && site == end {
                return Ok(true);
            }
            if target_sites.contains(&site) {
                return Ok(false);
            }
            let insn = prog.insn(site)?;
            if match insn.class() {
                BPF_JMP | BPF_JMP32 => true,
                BPF_ST | BPF_STX => insn.dst_reg() != 10,
                _ => false,
            } {
                return Ok(false);
            }
        }

        let Terminator::Fallthrough { next } = prog.terminator(cursor)? else {
            return Ok(false);
        };
        cursor = next;
    }
}

fn build_ladder_rewrite(
    group: &[usize],
    guards: &[GuardSite],
    target_sites: &BTreeSet<InsnSite>,
) -> Option<(InsnSite, i32, Vec<InsnSite>)> {
    let dominant = guards.get(*group.first()?)?;
    if !dominant.can_widen_in_place {
        return None;
    }

    let mut merged_end = dominant.window_end;
    let mut skip_sites = Vec::new();

    for &idx in group.iter().skip(1) {
        let site = guards.get(idx)?;
        merged_end = merged_end.max(site.window_end);
        if target_sites.contains(&site.compare) {
            return None;
        }

        if site.can_remove_setup {
            skip_sites.extend([site.mov, site.add, site.compare]);
        } else {
            skip_sites.push(site.compare);
        }
    }

    Some((dominant.add, merged_end, skip_sites))
}
