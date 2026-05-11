// SPDX-License-Identifier: MIT
//! Bounds-check merge optimization pass.

use std::collections::{BTreeMap, BTreeSet};

use crate::analysis::{
    packet_ctx_layout, BBProgram, BlockId, InsnSite, PacketCtxLayout, PacketCtxLayoutScope,
    Terminator,
};
use crate::insn::*;
use crate::pass::*;

/// Phase-1 heuristic: treat larger jumps as gapped windows and fail closed.
const MAX_LADDER_WINDOW_GROWTH: i32 = 24;

#[derive(Clone, Debug, PartialEq, Eq)]
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
    mov_pc: usize,
    compare_pc: usize,
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
    skips: Vec<SkipReason>,
}

/// Merge packet bounds-check ladders into a single dominant guard.
pub struct BoundsCheckMergePass;

impl BpfPass for BoundsCheckMergePass {
    fn name(&self) -> &str {
        "bounds_check_merge"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        Ok(run_on_bbprogram(program, ctx.prog_type)?.0)
    }
}

pub fn run_on_bbprogram(
    prog: &mut BBProgram,
    prog_type: u32,
) -> anyhow::Result<(PassResult, Option<Vec<usize>>)> {
    let Some(layout) = packet_ctx_layout(prog_type, PacketCtxLayoutScope::PacketAccess) else {
        return Ok((PassResult::unchanged(), None));
    };
    if prog.blocks.is_empty() {
        return Ok((PassResult::unchanged(), None));
    }

    let site_pcs = prog.current_site_pcs()?;
    let pc_sites = prog.current_pc_sites()?;
    let target_pcs = prog.branch_target_pcs()?;
    let old_len = current_program_len(prog, &site_pcs)?;
    let mut scan = scan_guard_sites(prog, &site_pcs, &target_pcs, layout)?;
    if scan.guards.is_empty() {
        return Ok((
            PassResult {
                sites_skipped: scan.skips,
                ..PassResult::unchanged()
            },
            None,
        ));
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
            if !can_extend_ladder(prev, next, prog, &pc_sites, &target_pcs) {
                break;
            }
            group.push(j);
            j += 1;
        }

        if group.len() >= 2 {
            if let Some(rewrite) = build_ladder_rewrite(&group, &scan.guards, &target_pcs) {
                for &idx in &group {
                    consumed[idx] = true;
                }
                rewrites.push(rewrite);
                i = group.last().copied().unwrap_or(i) + 1;
                continue;
            }
        }

        i += 1;
    }

    for (idx, guard) in scan.guards.iter().enumerate() {
        if !consumed[idx] {
            scan.skips.push(SkipReason {
                pc: guard.compare_pc,
                reason: "guard not part of a mergeable ladder".into(),
            });
        }
    }

    if rewrites.is_empty() {
        return Ok((
            PassResult {
                sites_skipped: scan.skips,
                ..PassResult::unchanged()
            },
            None,
        ));
    }

    let addr_map = apply_rewrites(prog, &rewrites, &site_pcs, old_len)?;
    Ok((
        PassResult {
            sites_applied: rewrites.len(),
            sites_skipped: scan.skips,
            ..Default::default()
        },
        Some(addr_map),
    ))
}

fn apply_rewrites(
    prog: &mut BBProgram,
    rewrites: &[(InsnSite, i32, Vec<InsnSite>)],
    site_pcs: &BTreeMap<InsnSite, usize>,
    old_len: usize,
) -> anyhow::Result<Vec<usize>> {
    let mut deleted_sites = BTreeSet::new();
    let mut deleted_branches = BTreeSet::new();

    for (dominant_add, merged_end, skip_sites) in rewrites {
        let mut widened = *prog
            .insn_at(*dominant_add)
            .ok_or_else(|| anyhow::anyhow!("missing dominant add at {:?}", dominant_add))?;
        widened.imm = *merged_end;
        prog.replace_range(
            dominant_add.block,
            dominant_add.idx..dominant_add.idx + 1,
            vec![widened],
        )?;

        for &site in skip_sites {
            if is_terminator_site(prog, site)? {
                deleted_branches.insert(site.block);
            } else {
                deleted_sites.insert(site);
            }
        }
    }

    let mut deletions_by_block: BTreeMap<BlockId, Vec<usize>> = BTreeMap::new();
    for site in &deleted_sites {
        deletions_by_block
            .entry(site.block)
            .or_default()
            .push(site.idx);
    }
    for (block, mut indices) in deletions_by_block {
        indices.sort_unstable_by(|a, b| b.cmp(a));
        for idx in indices {
            prog.replace_range(block, idx..idx + 1, Vec::new())?;
        }
    }
    for block in deleted_branches {
        prog.delete_cond_branch(block)?;
    }

    let deleted_pcs = rewrites
        .iter()
        .flat_map(|(_, _, skip_sites)| skip_sites.iter())
        .filter_map(|site| site_pcs.get(site).copied())
        .collect::<BTreeSet<_>>();
    Ok(addr_map_after_deletions(old_len, &deleted_pcs))
}

fn is_terminator_site(prog: &BBProgram, site: InsnSite) -> anyhow::Result<bool> {
    let block = prog.block(site.block)?;
    Ok(site.idx == block.insns.len() && block.terminator.raw_insn().is_some())
}

fn addr_map_after_deletions(old_len: usize, deleted_pcs: &BTreeSet<usize>) -> Vec<usize> {
    let mut addr_map = vec![0usize; old_len + 1];
    let mut new_pc = 0usize;
    for (old_pc, slot) in addr_map.iter_mut().enumerate().take(old_len) {
        *slot = new_pc;
        if !deleted_pcs.contains(&old_pc) {
            new_pc += 1;
        }
    }
    addr_map[old_len] = new_pc;
    addr_map
}

fn current_program_len(
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
) -> anyhow::Result<usize> {
    let mut len = 0usize;
    for (&site, &pc) in site_pcs {
        len = len.max(pc + prog.insn_slot_width(site)?);
    }
    Ok(len)
}

fn scan_guard_sites(
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
    target_pcs: &BTreeSet<usize>,
    layout: PacketCtxLayout,
) -> anyhow::Result<ScanResult> {
    let mut states = vec![RegValue::Unknown; 11];
    let mut next_root_id = 1u32;
    let mut last_data_root = None;
    let mut result = ScanResult::default();

    for block in prog.blocks() {
        let block_start = prog.current_block_start_pc(block.id)?;
        if target_pcs.contains(&block_start) {
            clear_states(&mut states);
            last_data_root = None;
        }

        for site in prog.logical_sites_in_block(block.id) {
            let Some(&insn) = prog.insn_at(site) else {
                continue;
            };
            if let Some(skip) = detect_variable_guard(site, prog, site_pcs, &states)? {
                result.skips.push(skip);
            } else if let Some(site) = detect_guard_site(site, prog, site_pcs, target_pcs, &states)?
            {
                result.guards.push(site);
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

fn detect_guard_site(
    site: InsnSite,
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
    target_pcs: &BTreeSet<usize>,
    states: &[RegValue],
) -> anyhow::Result<Option<GuardSite>> {
    let Some(insn) = prog.insn_at(site) else {
        return Ok(None);
    };
    let Some((cursor_reg, data_end_reg, cmp_kind)) = normalize_slow_guard(insn) else {
        return Ok(None);
    };
    let Some((mov_site, add_site)) = guard_setup_sites(site, prog)? else {
        return Ok(None);
    };
    let mov = prog
        .insn_at(mov_site)
        .ok_or_else(|| anyhow::anyhow!("missing guard setup mov at {:?}", mov_site))?;
    let add = prog
        .insn_at(add_site)
        .ok_or_else(|| anyhow::anyhow!("missing guard setup add at {:?}", add_site))?;
    let Some(&mov_pc) = site_pcs.get(&mov_site) else {
        return Ok(None);
    };
    let Some(&add_pc) = site_pcs.get(&add_site) else {
        return Ok(None);
    };
    let Some(&compare_pc) = site_pcs.get(&site) else {
        return Ok(None);
    };

    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != cursor_reg {
        return Ok(None);
    }
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K) || add.dst_reg() != cursor_reg {
        return Ok(None);
    }

    let root_reg = mov.src_reg();
    let window_end = add.imm;
    if window_end <= 0 {
        return Ok(None);
    }

    let Some(RegValue::PacketData { root_id, const_off }) = reg_state(states, cursor_reg).cloned()
    else {
        return Ok(None);
    };
    let Some(RegValue::PacketData {
        root_id: root_base_id,
        const_off: root_off,
    }) = reg_state(states, root_reg).cloned()
    else {
        return Ok(None);
    };
    let Some(RegValue::PacketEnd {
        root_id: end_root_id,
    }) = reg_state(states, data_end_reg).cloned()
    else {
        return Ok(None);
    };

    if root_id != root_base_id || root_id != end_root_id || root_off != 0 || const_off != window_end
    {
        return Ok(None);
    }

    let slow_target = match prog.block(site.block)?.terminator {
        Terminator::CondBranch { taken, .. } if is_terminator_site(prog, site)? => taken,
        _ => return Ok(None),
    };
    let cursor_dead = cursor_dead_after_compare(prog, add_site, site, cursor_reg);
    let can_widen_in_place = !target_pcs.contains(&mov_pc)
        && !target_pcs.contains(&add_pc)
        && !target_pcs.contains(&compare_pc)
        && cursor_dead;
    let can_remove_setup =
        !target_pcs.contains(&mov_pc) && !target_pcs.contains(&add_pc) && cursor_dead;

    Ok(Some(GuardSite {
        mov: mov_site,
        add: add_site,
        compare: site,
        mov_pc,
        compare_pc,
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

fn detect_variable_guard(
    site: InsnSite,
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
    states: &[RegValue],
) -> anyhow::Result<Option<SkipReason>> {
    let Some(insn) = prog.insn_at(site) else {
        return Ok(None);
    };
    let Some((cursor_reg, data_end_reg, _)) = normalize_slow_guard(insn) else {
        return Ok(None);
    };
    let Some((mov_site, add_site)) = guard_setup_sites(site, prog)? else {
        return Ok(None);
    };
    let mov = prog
        .insn_at(mov_site)
        .ok_or_else(|| anyhow::anyhow!("missing variable guard setup mov at {:?}", mov_site))?;
    let add = prog
        .insn_at(add_site)
        .ok_or_else(|| anyhow::anyhow!("missing variable guard setup add at {:?}", add_site))?;

    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != cursor_reg {
        return Ok(None);
    }
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_X) || add.dst_reg() != cursor_reg {
        return Ok(None);
    }

    let root_reg = mov.src_reg();
    let (Some(root_state), Some(end_state)) =
        (reg_state(states, root_reg), reg_state(states, data_end_reg))
    else {
        return Ok(None);
    };
    let skip = match (root_state, end_state) {
        (
            RegValue::PacketData {
                root_id: left_root,
                const_off: 0,
            },
            RegValue::PacketEnd {
                root_id: right_root,
            },
        ) if left_root == right_root => site_pcs.get(&site).copied().map(|pc| SkipReason {
            pc,
            reason: "variable packet window is not mergeable in v1".into(),
        }),
        _ => None,
    };
    Ok(skip)
}

fn guard_setup_sites(
    compare: InsnSite,
    prog: &BBProgram,
) -> anyhow::Result<Option<(InsnSite, InsnSite)>> {
    let block = prog.block(compare.block)?;
    if compare.idx < 2 || compare.idx > block.insns.len() {
        return Ok(None);
    }
    Ok(Some((
        InsnSite {
            block: compare.block,
            idx: compare.idx - 2,
        },
        InsnSite {
            block: compare.block,
            idx: compare.idx - 1,
        },
    )))
}

fn cursor_dead_after_compare(
    prog: &BBProgram,
    add_site: InsnSite,
    compare_site: InsnSite,
    cursor_reg: u8,
) -> bool {
    let def = crate::analysis::DefSite {
        block: add_site.block,
        idx: add_site.idx,
        reg: cursor_reg,
    };
    prog.use_def
        .uses_for(def)
        .iter()
        .all(|use_site| use_site.site() == compare_site)
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
    pc_sites: &BTreeMap<usize, InsnSite>,
    target_pcs: &BTreeSet<usize>,
) -> bool {
    if prev.root_id != next.root_id
        || prev.root_reg != next.root_reg
        || prev.data_end_reg != next.data_end_reg
        || prev.cmp_kind != next.cmp_kind
        || prev.slow_target != next.slow_target
        || next.window_end <= prev.window_end
        || next.window_end - prev.window_end > MAX_LADDER_WINDOW_GROWTH
        || next.mov_pc <= prev.compare_pc
    {
        return false;
    }

    for pc in (prev.compare_pc + 1)..next.mov_pc {
        if !is_merge_safe_interleave(pc, prog, pc_sites, target_pcs) {
            return false;
        }
    }

    !target_pcs.contains(&next.compare_pc)
}

fn is_merge_safe_interleave(
    pc: usize,
    prog: &BBProgram,
    pc_sites: &BTreeMap<usize, InsnSite>,
    target_pcs: &BTreeSet<usize>,
) -> bool {
    if target_pcs.contains(&pc) {
        return false;
    }

    let Some(&site) = pc_sites.get(&pc) else {
        return false;
    };
    let Some(insn) = prog.insn_at(site) else {
        return false;
    };
    match insn.class() {
        BPF_JMP | BPF_JMP32 => false,
        BPF_ST | BPF_STX => insn.dst_reg() == 10,
        _ => true,
    }
}

fn build_ladder_rewrite(
    group: &[usize],
    guards: &[GuardSite],
    target_pcs: &BTreeSet<usize>,
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
        if target_pcs.contains(&site.compare_pc) {
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
            if is_ctx_data_load(&insn, layout) {
                let root_id = *next_root_id;
                *next_root_id += 1;
                states[dst] = RegValue::PacketData {
                    root_id,
                    const_off: 0,
                };
                *last_data_root = Some(root_id);
            } else if is_ctx_data_end_load(&insn, layout) {
                let root_id = last_data_root.unwrap_or_else(|| {
                    let root_id = *next_root_id;
                    *next_root_id += 1;
                    root_id
                });
                states[dst] = RegValue::PacketEnd { root_id };
            } else {
                states[dst] = RegValue::Scalar;
            }
        }
        BPF_ALU64 | BPF_ALU => {
            let op = bpf_op(insn.code);
            match (op, bpf_src(insn.code)) {
                (BPF_MOV, BPF_X) => {
                    states[dst] = states.get(src).cloned().unwrap_or(RegValue::Unknown)
                }
                (BPF_MOV, _) => states[dst] = RegValue::Scalar,
                (BPF_ADD, BPF_K) => {
                    states[dst] = match states.get(dst).cloned().unwrap_or(RegValue::Unknown) {
                        RegValue::PacketData { root_id, const_off } => RegValue::PacketData {
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
                clear_states(states);
                *last_data_root = None;
            }
        }
        _ => {}
    }
}

fn is_ctx_data_load(insn: &BpfInsn, layout: PacketCtxLayout) -> bool {
    insn.is_ldx_mem() && insn.src_reg() == 1 && insn.off == layout.data_off
}

fn is_ctx_data_end_load(insn: &BpfInsn, layout: PacketCtxLayout) -> bool {
    insn.is_ldx_mem() && insn.src_reg() == 1 && insn.off == layout.data_end_off
}

fn reg_state(states: &[RegValue], reg: u8) -> Option<&RegValue> {
    states.get(reg as usize)
}

fn clear_states(states: &mut [RegValue]) {
    for state in states {
        *state = RegValue::Unknown;
    }
}
