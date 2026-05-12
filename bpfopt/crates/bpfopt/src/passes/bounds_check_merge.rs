// SPDX-License-Identifier: MIT
use std::collections::{BTreeMap, BTreeSet};

use crate::analysis::{BBProgram, BlockId, InsnSite, MakeReplacement, Terminator};
use crate::insn::*;
use crate::pass::*;
const MAX_LADDER_WINDOW_GROWTH: i32 = 24;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RegValue {
    Unknown,
    Scalar,
    PacketData { root_id: u32, const_off: i32 },
    PacketEnd { root_id: u32 },
}

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
    root_id: u32,
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
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx.prog_type)
    }
}

pub fn run_on_bbprogram(prog: &mut BBProgram, prog_type: u32) -> anyhow::Result<PassResult> {
    let Some(layout) = packet_ctx_layout(prog_type, PacketCtxLayoutScope::PacketAccess) else {
        return Ok(PassResult::unchanged());
    };
    if prog.is_empty() {
        return Ok(PassResult::unchanged());
    }

    let target_sites = prog.branch_target_entry_sites()?;
    let mut scan = scan_guard_sites(prog, &target_sites, layout)?;
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
    prog: &mut BBProgram,
    rewrites: &[(InsnSite, i32, Vec<InsnSite>)],
    skipped: &mut Vec<SiteSkipReason>,
) -> anyhow::Result<()> {
    let mut deleted_sites = BTreeSet::new();
    let mut deleted_branches = BTreeSet::new();

    for (dominant_add, merged_end, skip_sites) in rewrites {
        let mut widened = *prog
            .insn_at(*dominant_add)
            .ok_or_else(|| anyhow::anyhow!("missing dominant add at {:?}", dominant_add))?;
        widened.imm = *merged_end;
        prog.try_replace_range_with_skips(*dominant_add, 1, 1, skipped, || {
            Ok(MakeReplacement::Use(vec![widened]))
        })?;

        for &site in skip_sites {
            if prog.is_terminator_site(site)? {
                deleted_branches.insert(prog.site_block(site));
            } else {
                deleted_sites.insert(site);
            }
        }
    }

    let mut deletions_by_block: BTreeMap<BlockId, Vec<InsnSite>> = BTreeMap::new();
    for site in &deleted_sites {
        deletions_by_block
            .entry(prog.site_block(*site))
            .or_default()
            .push(*site);
    }
    for (_, mut sites) in deletions_by_block {
        sites.sort_unstable_by(|a, b| b.cmp(a));
        for site in sites {
            prog.try_replace_range_with_skips(site, 1, 0, skipped, || {
                Ok(MakeReplacement::Use(Vec::new()))
            })?;
        }
    }
    for block in deleted_branches {
        prog.delete_cond_branch(block)?;
    }
    Ok(())
}

fn scan_guard_sites(
    prog: &BBProgram,
    target_sites: &BTreeSet<InsnSite>,
    layout: PacketCtxLayout,
) -> anyhow::Result<ScanResult> {
    let mut states = vec![RegValue::Unknown; 11];
    let mut next_root_id = 1u32;
    let mut last_data_root = None;
    let mut result = ScanResult::default();

    for block in prog.blocks() {
        if prog
            .sites_in_block_with_terminator(block.id)?
            .first()
            .copied()
            .is_some_and(|site| target_sites.contains(&site))
        {
            states.fill(RegValue::Unknown);
            last_data_root = None;
        }

        let block_sites = prog.sites_in_block_with_terminator(block.id)?;
        for (idx, site) in block_sites.iter().copied().enumerate() {
            let Some(&insn) = prog.insn_at(site) else {
                continue;
            };
            let setup = (idx >= 2).then(|| (block_sites[idx - 2], block_sites[idx - 1]));
            if let Some(guard) =
                detect_guard_candidate(site, prog, target_sites, setup, &states, &mut result.skips)?
            {
                result.guards.push(guard);
            }

            apply_transfer(
                insn,
                &mut states,
                &mut next_root_id,
                &mut last_data_root,
                layout,
            );
        }
    }

    Ok(result)
}

fn detect_guard_candidate(
    site: InsnSite,
    prog: &BBProgram,
    target_sites: &BTreeSet<InsnSite>,
    setup: Option<(InsnSite, InsnSite)>,
    states: &[RegValue],
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
    let mov = prog
        .insn_at(mov_site)
        .ok_or_else(|| anyhow::anyhow!("missing guard setup mov at {:?}", mov_site))?;
    let add = prog
        .insn_at(add_site)
        .ok_or_else(|| anyhow::anyhow!("missing guard setup add at {:?}", add_site))?;
    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != cursor_reg {
        return Ok(None);
    }
    if add.dst_reg() != cursor_reg {
        return Ok(None);
    }

    let root_reg = mov.src_reg();
    if add.code == (BPF_ALU64 | BPF_ADD | BPF_X) {
        if let (
            Some(RegValue::PacketData {
                root_id: left_root,
                const_off: 0,
            }),
            Some(RegValue::PacketEnd {
                root_id: right_root,
            }),
        ) = (
            states.get(root_reg as usize).copied(),
            states.get(data_end_reg as usize).copied(),
        ) {
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

    let (
        Some(RegValue::PacketData { root_id, const_off }),
        Some(RegValue::PacketData {
            root_id: root_base_id,
            const_off: root_off,
        }),
        Some(RegValue::PacketEnd {
            root_id: end_root_id,
        }),
    ) = (
        states.get(cursor_reg as usize).copied(),
        states.get(root_reg as usize).copied(),
        states.get(data_end_reg as usize).copied(),
    )
    else {
        return Ok(None);
    };

    if root_id != root_base_id || root_id != end_root_id || root_off != 0 || const_off != window_end
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
        root_id,
        window_end,
        cmp_kind,
        slow_target,
        can_widen_in_place,
        can_remove_setup,
    }))
}

fn cursor_dead_after_compare(
    prog: &BBProgram,
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
    prog: &BBProgram,
    target_sites: &BTreeSet<InsnSite>,
) -> anyhow::Result<bool> {
    if prev.root_id != next.root_id
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
    prog: &BBProgram,
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
            let insn = prog
                .insn_at(site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
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

fn apply_transfer(
    insn: BpfInsn,
    states: &mut [RegValue],
    next_root_id: &mut u32,
    last_data_root: &mut Option<u32>,
    layout: PacketCtxLayout,
) {
    let dst = insn.dst_reg() as usize;
    let src = insn.src_reg() as usize;

    match insn.class() {
        BPF_LDX => {
            if insn.is_ldx_mem() && insn.src_reg() == 1 && insn.off == layout.data_off {
                let root_id = *next_root_id;
                *next_root_id += 1;
                states[dst] = RegValue::PacketData {
                    root_id,
                    const_off: 0,
                };
                *last_data_root = Some(root_id);
            } else if insn.is_ldx_mem() && insn.src_reg() == 1 && insn.off == layout.data_end_off {
                let root_id = match *last_data_root {
                    Some(root_id) => root_id,
                    None => {
                        let root_id = *next_root_id;
                        *next_root_id += 1;
                        root_id
                    }
                };
                states[dst] = RegValue::PacketEnd { root_id };
            } else {
                states[dst] = RegValue::Scalar;
            }
        }
        BPF_ALU64 | BPF_ALU => {
            let op = bpf_op(insn.code);
            match (op, bpf_src(insn.code)) {
                (BPF_MOV, BPF_X) => {
                    states[dst] = states.get(src).copied().unwrap_or(RegValue::Unknown)
                }
                (BPF_MOV, _) => states[dst] = RegValue::Scalar,
                (BPF_ADD, BPF_K) => {
                    states[dst] = match states.get(dst).copied() {
                        Some(RegValue::PacketData { root_id, const_off }) => RegValue::PacketData {
                            root_id,
                            const_off: const_off + insn.imm,
                        },
                        _ => RegValue::Scalar,
                    };
                }
                _ => states[dst] = RegValue::Unknown,
            }
        }
        BPF_LD => states[dst] = RegValue::Scalar,
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                states.fill(RegValue::Unknown);
                *last_data_root = None;
            }
        }
        _ => {}
    }
}
