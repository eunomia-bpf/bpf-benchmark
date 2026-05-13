// SPDX-License-Identifier: MIT
use crate::analysis::{insn_use_def_set, BlockId, InsnSite, ProgramCFG, SlotDistance};
use crate::insn::*;
use crate::pass::*;
pub(super) const HELPER_MAP_LOOKUP_ELEM: i32 = libbpf_sys::BPF_FUNC_map_lookup_elem as i32;
const HELPER_XDP_ADJUST_HEAD: i32 = libbpf_sys::BPF_FUNC_xdp_adjust_head as i32;
const PREFETCH_TARGET_NAME: &str = "bpf_prefetch";
const TARGET_PREFETCH_DISTANCE: usize = 8;
const MAX_PREFETCH_DISTANCE: usize = 16;
const MAP_VALUE_LOOKAHEAD: usize = 64;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[KinsnDescriptor {
    name: PREFETCH_TARGET_NAME,
    register_uses: prefetch_register_uses,
}];
fn prefetch_register_uses(payload: u64) -> RegSet {
    regs_from_offsets(payload, &[0])
}
pub struct PrefetchPass;
#[derive(Clone, Copy, Debug)]
struct PrefetchSite {
    target: InsnSite,
    ptr_reg: u8,
    ptr_def: InsnSite,
}
#[derive(Clone, Debug)]
struct PrefetchCandidate {
    target: InsnSite,
    insert: InsnSite,
    ptr_reg: u8,
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum TrackedValue {
    Unknown,
    Ctx,
    PacketData { ptr_def: InsnSite },
    PacketEnd,
}
pub(super) fn prefetch_payload(ptr_reg: u8) -> anyhow::Result<u64> {
    if ptr_reg > BPF_REG_10 {
        anyhow::bail!("prefetch ptr register {ptr_reg} is outside BPF_REG_0..BPF_REG_10");
    }
    Ok(BpfInsn::pack_u4(ptr_reg, 0))
}
impl BpfPass for PrefetchPass {
    fn run(&self, prog: &mut ProgramCFG, ctx: &PassContext) -> anyhow::Result<PassResult> {
        if prog.all_sites().next().is_none() {
            return Ok(PassResult::default());
        }
        let mut candidates = Vec::new();
        let mut skipped = Vec::new();
        for site in scan_prefetch_sites(prog, ctx.prog_type)? {
            let insert_site = match choose_prefetch_insert_site(prog, site)? {
                Ok(insert) => insert,
                Err(reason) => {
                    skipped.push(checked_site_skip(prog, site.target, reason)?);
                    continue;
                }
            };
            candidates.push(PrefetchCandidate {
                target: site.target,
                insert: insert_site,
                ptr_reg: site.ptr_reg,
            });
        }
        let candidates = dedup_candidates(candidates);
        if candidates.is_empty() {
            return Ok(PassResult::with_sites(0, skipped));
        }
        let (btf_id, kfunc_off) = prog.kinsn_call(PREFETCH_TARGET_NAME)?;
        let pairs: Vec<(InsnSite, PrefetchCandidate)> =
            candidates.into_iter().map(|c| (c.insert, c)).collect();
        let applied = apply_candidates_reverse(prog, &pairs, &mut skipped, |_, _, candidate| {
            let payload = prefetch_payload(candidate.ptr_reg)?;
            Ok((
                0,
                emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
            ))
        })?;
        Ok(PassResult::with_sites(applied, skipped))
    }
}

fn scan_prefetch_sites(prog: &ProgramCFG, prog_type: u32) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = scan_map_value_prefetch_sites(prog)?;
    if let Some(layout) = packet_ctx_layout(prog_type, PacketCtxLayoutScope::PacketAccess) {
        sites.extend(scan_packet_prefetch_sites(prog, layout)?);
    }
    Ok(sites)
}
fn scan_map_value_prefetch_sites(prog: &ProgramCFG) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        for site in prog.sites_in_block(block)? {
            let insn = prog.insn(site)?;
            if insn.is_call() && insn.src_reg() == 0 && insn.imm == HELPER_MAP_LOOKUP_ELEM {
                if let Some(prefetch) = first_map_value_deref_after_lookup(prog, site)? {
                    sites.push(prefetch);
                }
            }
        }
    }
    Ok(sites)
}
fn first_map_value_deref_after_lookup(
    prog: &ProgramCFG,
    call_site: InsnSite,
) -> anyhow::Result<Option<PrefetchSite>> {
    let mut aliases = [None::<InsnSite>; 11];
    aliases[BPF_REG_0 as usize] = Some(call_site);
    for site in pf_sites_after_in_frame(prog, call_site, MAP_VALUE_LOOKAHEAD)? {
        let insn = prog.insn(site)?;
        if let Some(base_reg) = memory_base_reg(insn) {
            if let Some(ptr_def) = aliases[base_reg as usize] {
                return Ok(Some(PrefetchSite {
                    target: site,
                    ptr_reg: base_reg,
                    ptr_def,
                }));
            }
        }
        if insn.is_call()
            || insn.is_exit()
            || insn.is_ldimm64_pseudo_func()
            || (insn.is_ja() && insn.off != 0)
        {
            break;
        }
        apply_map_value_alias_transfer(insn, site, &mut aliases);
    }
    Ok(None)
}
fn apply_map_value_alias_transfer(
    insn: &BpfInsn,
    site: InsnSite,
    aliases: &mut [Option<InsnSite>; 11],
) {
    if insn.is_ldimm64() {
        aliases[insn.dst_reg() as usize] = None;
        return;
    }
    match insn.class() {
        BPF_ALU64 => apply_map_value_alu64_transfer(insn, site, aliases),
        BPF_ALU | BPF_LD | BPF_LDX => aliases[insn.dst_reg() as usize] = None,
        _ => {}
    }
}
fn apply_map_value_alu64_transfer(
    insn: &BpfInsn,
    site: InsnSite,
    aliases: &mut [Option<InsnSite>; 11],
) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => {
            aliases[dst] = aliases[insn.src_reg() as usize].map(|_| site);
        }
        (BPF_ADD | BPF_SUB, BPF_K) if aliases[dst].is_some() => {
            aliases[dst] = Some(site);
        }
        _ => aliases[dst] = None,
    }
}
fn scan_packet_prefetch_sites(
    prog: &ProgramCFG,
    layout: PacketCtxLayout,
) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = Vec::new();
    let mut regs = [TrackedValue::Unknown; 11];
    regs[BPF_REG_1 as usize] = TrackedValue::Ctx;
    for block in prog.block_ids().collect::<Vec<_>>() {
        if prog.should_reset_linear_state_at_block(block)? {
            regs = [TrackedValue::Unknown; 11];
        }
        for site in prog.sites_in_block_with_terminator(block)? {
            let insn = prog.insn(site)?;
            if let Some(base_reg) = memory_base_reg(insn) {
                if let TrackedValue::PacketData { ptr_def } = regs[base_reg as usize] {
                    sites.push(PrefetchSite {
                        target: site,
                        ptr_reg: base_reg,
                        ptr_def,
                    });
                }
            }
            apply_packet_transfer(insn, site, layout, &mut regs);
        }
    }
    Ok(sites)
}
fn apply_packet_transfer(
    insn: &BpfInsn,
    site: InsnSite,
    layout: PacketCtxLayout,
    regs: &mut [TrackedValue; 11],
) {
    if insn.is_call() {
        if insn.src_reg() == 0 && insn.imm == HELPER_XDP_ADJUST_HEAD {
            for reg in regs.iter_mut() {
                *reg = TrackedValue::Unknown;
            }
        } else {
            for reg in regs.iter_mut().take(6) {
                *reg = TrackedValue::Unknown;
            }
        }
        return;
    }
    if insn.is_ldimm64() {
        regs[insn.dst_reg() as usize] = TrackedValue::Unknown;
        return;
    }
    match insn.class() {
        BPF_LDX if bpf_mode(insn.code) == BPF_MEM => {
            apply_packet_ldx_transfer(insn, site, layout, regs);
        }
        BPF_ALU64 => apply_packet_alu64_transfer(insn, site, regs),
        BPF_ALU | BPF_LD => regs[insn.dst_reg() as usize] = TrackedValue::Unknown,
        _ => {}
    }
}
fn apply_packet_ldx_transfer(
    insn: &BpfInsn,
    site: InsnSite,
    layout: PacketCtxLayout,
    regs: &mut [TrackedValue; 11],
) {
    let dst = insn.dst_reg() as usize;
    regs[dst] = match regs[insn.src_reg() as usize] {
        TrackedValue::Ctx if bpf_size(insn.code) == BPF_W && insn.off == layout.data_off => {
            TrackedValue::PacketData { ptr_def: site }
        }
        TrackedValue::Ctx if bpf_size(insn.code) == BPF_W && insn.off == layout.data_end_off => {
            TrackedValue::PacketEnd
        }
        _ => TrackedValue::Unknown,
    };
}
fn apply_packet_alu64_transfer(insn: &BpfInsn, site: InsnSite, regs: &mut [TrackedValue; 11]) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => {
            regs[dst] = match regs[insn.src_reg() as usize] {
                TrackedValue::PacketData { .. } => TrackedValue::PacketData { ptr_def: site },
                value => value,
            };
        }
        (BPF_ADD | BPF_SUB, BPF_K) => {
            if let TrackedValue::PacketData { .. } = regs[dst] {
                regs[dst] = TrackedValue::PacketData { ptr_def: site };
            } else {
                regs[dst] = TrackedValue::Unknown;
            }
        }
        _ => regs[dst] = TrackedValue::Unknown,
    }
}
fn memory_base_reg(insn: &BpfInsn) -> Option<u8> {
    if bpf_mode(insn.code) != BPF_MEM {
        return None;
    }
    match insn.class() {
        BPF_LDX => Some(insn.src_reg()),
        BPF_ST | BPF_STX => Some(insn.dst_reg()),
        _ => None,
    }
}
fn choose_prefetch_insert_site(
    prog: &ProgramCFG,
    site: PrefetchSite,
) -> anyhow::Result<std::result::Result<InsnSite, String>> {
    let window = pf_prefetch_window_sites(prog, site.ptr_def, site.target, MAX_PREFETCH_DISTANCE)?;
    if window.is_empty() {
        return Ok(Err("no valid prefetch insertion window".into()));
    }
    if let Some(reason) = reject_control_flow_between(prog, &window)? {
        return Ok(Err(reason));
    }
    if let Some(reason) = reject_reg_write_between(prog, &window, site.ptr_reg)? {
        return Ok(Err(reason));
    }
    let Some(insert_site) =
        pf_nearest_prefetch_insert_site(prog, &window, site.target, TARGET_PREFETCH_DISTANCE)?
    else {
        return Ok(Err(
            "prefetch insertion window has no instruction boundary".into()
        ));
    };
    Ok(Ok(insert_site))
}

fn pf_sites_after_in_frame(
    prog: &ProgramCFG,
    anchor: InsnSite,
    max_slots: usize,
) -> anyhow::Result<Vec<InsnSite>> {
    prog.insn(anchor)?;
    let frame = prog.site_frame(anchor)?;
    let scan_start = pf_site_end_offset(prog, anchor)?;
    let scan_end = scan_start
        .checked_add(SlotDistance::from_slots(max_slots))
        .ok_or_else(|| anyhow::anyhow!("prefetch scan after {:?} overflows", anchor))?;
    let mut sites = Vec::new();
    for block in prog.subprog_blocks(frame) {
        for site in prog.sites_in_block_with_terminator(block)? {
            let site_start = prog.site_layout_offset(site)?;
            if site_start < scan_start {
                continue;
            }
            if site_start >= scan_end {
                return Ok(sites);
            }
            sites.push(site);
        }
    }
    Ok(sites)
}

fn pf_prefetch_window_sites(
    prog: &ProgramCFG,
    ptr_def: InsnSite,
    target: InsnSite,
    max_slots: usize,
) -> anyhow::Result<Vec<InsnSite>> {
    prog.insn(ptr_def)?;
    prog.insn(target)?;
    let target_block = prog.site_block(target);
    let frame = prog.site_frame(target)?;
    if prog.site_frame(ptr_def)? != frame {
        anyhow::bail!(
            "prefetch pointer definition {:?} and target {:?} are in different frames",
            ptr_def,
            target
        );
    }
    let block_start = first_block_layout_offset(prog, target_block)?;
    let target_start = prog.site_layout_offset(target)?;
    let ptr_def_end = pf_site_end_offset(prog, ptr_def)?;
    let valid_start = block_start
        .max(target_start.saturating_sub(SlotDistance::from_slots(max_slots)))
        .max(ptr_def_end);
    if valid_start > target_start {
        return Ok(Vec::new());
    }
    let mut sites = Vec::new();
    for site in prog.sites_in_block(target_block)? {
        let site_start = prog.site_layout_offset(site)?;
        if site_start >= valid_start && site_start <= target_start {
            sites.push(site);
        }
    }
    Ok(sites)
}

fn pf_nearest_prefetch_insert_site(
    prog: &ProgramCFG,
    sites: &[InsnSite],
    target: InsnSite,
    ideal_distance: usize,
) -> anyhow::Result<Option<InsnSite>> {
    let ideal = prog
        .site_layout_offset(target)?
        .saturating_sub(SlotDistance::from_slots(ideal_distance));
    let mut best: Option<(SlotDistance, SlotDistance, InsnSite)> = None;
    for &site in sites {
        let site_start = prog.site_layout_offset(site)?;
        let distance = site_start.abs_diff(ideal);
        if best.is_none_or(|(best_distance, best_start, _)| {
            distance < best_distance || (distance == best_distance && site_start < best_start)
        }) {
            best = Some((distance, site_start, site));
        }
    }
    Ok(best.map(|(_, _, site)| site))
}

fn pf_site_end_offset(prog: &ProgramCFG, site: InsnSite) -> anyhow::Result<SlotDistance> {
    prog.site_layout_offset(site)?
        .checked_add(SlotDistance::from_slots(prog.insn_slot_width(site)?))
        .ok_or_else(|| anyhow::anyhow!("prefetch site {:?} end offset overflows", site))
}

fn first_block_layout_offset(prog: &ProgramCFG, block: BlockId) -> anyhow::Result<SlotDistance> {
    match prog.sites_in_block_with_terminator(block)?.first() {
        Some(&first) => prog.site_layout_offset(first),
        None => Ok(SlotDistance::ZERO),
    }
}

fn reject_control_flow_between(
    prog: &ProgramCFG,
    window: &[InsnSite],
) -> anyhow::Result<Option<String>> {
    for &site in window {
        let insn = prog.insn(site)?;
        if insn.is_call() || insn.is_exit() || insn.is_jmp_class() || insn.is_ldimm64_pseudo_func()
        {
            return Ok(Some(format!(
                "prefetch window contains control-flow instruction at {:?}",
                site
            )));
        }
    }
    Ok(None)
}
fn reject_reg_write_between(
    prog: &ProgramCFG,
    window: &[InsnSite],
    reg: u8,
) -> anyhow::Result<Option<String>> {
    for &site in window {
        let insn = prog.insn(site)?;
        if insn_use_def_set(insn).defs.contains(&reg) {
            return Ok(Some(format!(
                "r{reg} is redefined inside the prefetch window at {:?}",
                site
            )));
        }
    }
    Ok(None)
}
fn dedup_candidates(mut candidates: Vec<PrefetchCandidate>) -> Vec<PrefetchCandidate> {
    candidates.sort_by(|a, b| {
        a.insert
            .cmp(&b.insert)
            .then_with(|| a.target.cmp(&b.target))
    });
    let mut kept: Vec<PrefetchCandidate> = Vec::new();
    for candidate in candidates {
        if kept.iter().any(|existing| {
            existing.insert == candidate.insert && existing.ptr_reg == candidate.ptr_reg
        }) {
            continue;
        }
        kept.push(candidate);
    }
    kept
}
