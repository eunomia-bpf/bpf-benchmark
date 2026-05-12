// SPDX-License-Identifier: MIT
use crate::analysis::{BBProgram, BlockId, FrameId, InsnSite};
use crate::insn::*;
use crate::pass::*;
use anyhow::{bail, Result};
pub(super) const HELPER_MAP_LOOKUP_ELEM: i32 = libbpf_sys::BPF_FUNC_map_lookup_elem as i32;
const HELPER_XDP_ADJUST_HEAD: i32 = libbpf_sys::BPF_FUNC_xdp_adjust_head as i32;
const PREFETCH_TARGET_NAME: &str = "bpf_prefetch";
const TARGET_PREFETCH_DISTANCE: usize = 8;
const MAX_PREFETCH_DISTANCE: usize = 16;
const MAP_VALUE_LOOKAHEAD: usize = 64;
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[KinsnDescriptor {
    canonical_name: PREFETCH_TARGET_NAME,
    aliases: &["prefetch"],
    decode_proof: decode_prefetch_proof,
    register_uses: prefetch_register_uses,
}];
fn decode_prefetch_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(prefetch_proof_len))
}
fn prefetch_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("prefetch ptr", kinsn_payload_reg(payload, 0))?;
    if BpfInsn::unpack_u4(payload, 4) != 0 {
        anyhow::bail!("prefetch payload has unsupported hint kind");
    }
    if payload >> 8 != 0 {
        anyhow::bail!("prefetch payload has non-zero reserved bits");
    }
    Ok(1)
}
fn prefetch_register_uses(payload: u64) -> RegSet {
    [kinsn_payload_reg(payload, 0)].into_iter().collect()
}
pub struct PrefetchPass;
impl PrefetchPass {
    pub fn from_cli_args(args: &[String]) -> Result<Box<dyn BpfPass>> {
        if let Some(arg) = args.first() {
            bail!(
                "prefetch pass-local profile arguments moved to BBProgram side inputs; unexpected arg: {arg}"
            );
        }
        Ok(Box::new(PrefetchPass))
    }
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum PrefetchKind {
    MapValue,
    Packet,
}
#[derive(Clone, Copy, Debug)]
struct PrefetchSite {
    anchor: InsnSite,
    target: InsnSite,
    ptr_reg: u8,
    ptr_def: InsnSite,
    kind: PrefetchKind,
}
#[derive(Clone, Debug)]
struct PrefetchCandidate {
    target: InsnSite,
    insert: InsnSite,
    ptr_reg: u8,
    score: u64,
}

enum PrefetchAdmission {
    Admit(u64),
    Skip(String),
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum TrackedValue {
    Unknown,
    Ctx,
    PacketData { ptr_def: InsnSite },
    PacketEnd,
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RegWriteKind {
    Explicit,
    CallClobber,
}
enum InsertReject {
    Plain(String),
    ControlFlow(InsnSite),
    RegWrite { reg: u8, site: InsnSite },
}
impl InsertReject {
    fn message(&self) -> String {
        match self {
            Self::Plain(reason) => reason.clone(),
            Self::ControlFlow(site) => format!(
                "prefetch window contains control-flow instruction at {:?}",
                site
            ),
            Self::RegWrite { reg, site } => format!(
                "r{reg} is redefined inside the prefetch window at {:?}",
                site
            ),
        }
    }
}
fn skip_at(prog: &BBProgram, site: InsnSite, reason: String) -> anyhow::Result<SiteSkipReason> {
    pf_skip_reason(prog, site, reason)
}
pub(super) fn prefetch_payload(ptr_reg: u8) -> anyhow::Result<u64> {
    if ptr_reg > BPF_REG_10 {
        anyhow::bail!("prefetch ptr register {ptr_reg} is outside BPF_REG_0..BPF_REG_10");
    }
    Ok(BpfInsn::pack_u4(ptr_reg, 0))
}
impl BpfPass for PrefetchPass {
    fn name(&self) -> &str {
        "prefetch"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}
pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    if prog.all_sites().next().is_none() {
        return Ok(PassResult::unchanged());
    }
    let mut candidates = Vec::new();
    let mut skipped = Vec::new();
    for site in scan_prefetch_sites(prog, ctx.prog_type)? {
        let score = match prefetch_score_for_site(prog, site)? {
            PrefetchAdmission::Admit(score) => score,
            PrefetchAdmission::Skip(reason) => {
                skipped.push(skip_at(prog, site.target, reason)?);
                continue;
            }
        };
        let insert_site = match choose_prefetch_insert_site(prog, site)? {
            Ok(insert) => insert,
            Err(reason) => {
                skipped.push(skip_at(prog, site.target, reason.message())?);
                continue;
            }
        };
        candidates.push(PrefetchCandidate {
            target: site.target,
            insert: insert_site,
            ptr_reg: site.ptr_reg,
            score,
        });
    }
    let candidates = dedup_candidates(candidates);
    if candidates.is_empty() {
        return Ok(PassResult {
            site_skipped: skipped,
            ..PassResult::unchanged()
        });
    }
    let btf_id = ctx
        .kinsn_registry
        .btf_id_for_target_name(PREFETCH_TARGET_NAME)?;
    let kfunc_off = ctx
        .kinsn_registry
        .call_off_for_target_name(PREFETCH_TARGET_NAME)?;
    for candidate in candidates.iter().rev() {
        let payload = prefetch_payload(candidate.ptr_reg)?;
        prog.replace_range_at(
            candidate.insert,
            0,
            emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
        )?;
    }
    Ok(PassResult {
        sites_applied: candidates.len(),
        site_skipped: skipped,
        ..Default::default()
    })
}
fn scan_prefetch_sites(prog: &BBProgram, prog_type: u32) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = scan_map_value_prefetch_sites(prog)?;
    if let Some(layout) = packet_ctx_layout(prog_type, PacketCtxLayoutScope::PacketAccess) {
        sites.extend(scan_packet_prefetch_sites(prog, layout)?);
    }
    Ok(sites)
}
fn prefetch_score_for_site(
    prog: &BBProgram,
    site: PrefetchSite,
) -> anyhow::Result<PrefetchAdmission> {
    let profile_hint = prog
        .prefetch_hint(site.target)
        .or_else(|| prog.prefetch_hint(site.anchor));
    let Some(profile_hint) = profile_hint else {
        return Ok(PrefetchAdmission::Admit(default_site_score(site)));
    };
    if profile_hint.cache_misses == 0 {
        return Ok(PrefetchAdmission::Skip(
            "prefetch site has no observed cache misses".into(),
        ));
    }
    let hotness = prog
        .site_hotness(site.target)
        .or_else(|| prog.site_hotness(site.anchor))
        .ok_or_else(|| {
            anyhow::anyhow!(
                "prefetch candidate at {:?} has profile hint but no execution count",
                site.target
            )
        })?;
    if hotness == 0 {
        return Ok(PrefetchAdmission::Skip(
            "prefetch site execution_count is zero".into(),
        ));
    }
    Ok(PrefetchAdmission::Admit(hotness))
}
fn default_site_score(site: PrefetchSite) -> u64 {
    match site.kind {
        PrefetchKind::MapValue => 2,
        PrefetchKind::Packet => 1,
    }
}
fn scan_map_value_prefetch_sites(prog: &BBProgram) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = Vec::new();
    for block in prog.block_ids().collect::<Vec<_>>() {
        for site in prog.sites_in_block(block)? {
            let insn = prog
                .insn_at(site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
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
    prog: &BBProgram,
    call_site: InsnSite,
) -> anyhow::Result<Option<PrefetchSite>> {
    let mut aliases = [None::<InsnSite>; 11];
    aliases[BPF_REG_0 as usize] = Some(call_site);
    for site in pf_sites_after_in_frame(prog, call_site, MAP_VALUE_LOOKAHEAD)? {
        let insn = prog
            .insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
        if let Some(base_reg) = memory_base_reg(insn) {
            if let Some(ptr_def) = aliases[base_reg as usize] {
                return Ok(Some(PrefetchSite {
                    anchor: call_site,
                    target: site,
                    ptr_reg: base_reg,
                    ptr_def,
                    kind: PrefetchKind::MapValue,
                }));
            }
        }
        if stops_map_value_scan(insn) {
            break;
        }
        apply_map_value_alias_transfer(insn, site, &mut aliases);
    }
    Ok(None)
}
fn stops_map_value_scan(insn: &BpfInsn) -> bool {
    insn.is_call()
        || insn.is_exit()
        || insn.is_ldimm64_pseudo_func()
        || (insn.is_ja() && insn.off != 0)
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
    prog: &BBProgram,
    layout: PacketCtxLayout,
) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = Vec::new();
    let mut regs = initial_packet_regs();
    for block in prog.block_ids().collect::<Vec<_>>() {
        if prog.should_reset_linear_state_at_block(block)? {
            regs = [TrackedValue::Unknown; 11];
        }
        for site in prog.sites_in_block_with_terminator(block)? {
            let insn = prog
                .insn_at(site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
            if let Some(base_reg) = memory_base_reg(insn) {
                if let TrackedValue::PacketData { ptr_def } = regs[base_reg as usize] {
                    sites.push(PrefetchSite {
                        anchor: site,
                        target: site,
                        ptr_reg: base_reg,
                        ptr_def,
                        kind: PrefetchKind::Packet,
                    });
                }
            }
            apply_packet_transfer(insn, site, layout, &mut regs);
        }
    }
    Ok(sites)
}
fn initial_packet_regs() -> [TrackedValue; 11] {
    let mut regs = [TrackedValue::Unknown; 11];
    regs[BPF_REG_1 as usize] = TrackedValue::Ctx;
    regs
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
    prog: &BBProgram,
    site: PrefetchSite,
) -> anyhow::Result<Result<InsnSite, InsertReject>> {
    let window = pf_prefetch_window_sites(prog, site.ptr_def, site.target, MAX_PREFETCH_DISTANCE)?;
    if window.is_empty() {
        return Ok(Err(InsertReject::Plain(
            "no valid prefetch insertion window".into(),
        )));
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
        return Ok(Err(InsertReject::Plain(
            "prefetch insertion window has no instruction boundary".into(),
        )));
    };
    Ok(Ok(insert_site))
}

fn pf_skip_reason(
    prog: &BBProgram,
    site: InsnSite,
    reason: String,
) -> anyhow::Result<SiteSkipReason> {
    prog.insn(site)?;
    Ok(SiteSkipReason { site, reason })
}

fn pf_sites_after_in_frame(
    prog: &BBProgram,
    anchor: InsnSite,
    max_slots: usize,
) -> anyhow::Result<Vec<InsnSite>> {
    prog.insn(anchor)?;
    let frame = prog.block_frame(anchor.block)?;
    let scan_start = pf_site_end_slot(prog, anchor)?;
    let scan_end = scan_start
        .checked_add(max_slots)
        .ok_or_else(|| anyhow::anyhow!("prefetch scan after {:?} overflows", anchor))?;
    let mut sites = Vec::new();
    for block in prog.subprog_blocks(frame) {
        for site in prog.sites_in_block_with_terminator(block)? {
            let site_start = pf_site_start_slot(prog, site)?;
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
    prog: &BBProgram,
    ptr_def: InsnSite,
    target: InsnSite,
    max_slots: usize,
) -> anyhow::Result<Vec<InsnSite>> {
    prog.insn(ptr_def)?;
    prog.insn(target)?;
    let frame = prog.block_frame(target.block)?;
    if prog.block_frame(ptr_def.block)? != frame {
        anyhow::bail!(
            "prefetch pointer definition {:?} and target {:?} are in different frames",
            ptr_def,
            target
        );
    }
    let (block_start, block_end) = block_slot_bounds(prog, target.block)?;
    let (frame_start, frame_end) = frame_slot_bounds(prog, frame)?;
    if block_start < frame_start || block_end > frame_end {
        anyhow::bail!(
            "prefetch block {:?} crosses frame {:?}: block {}..{}, frame {}..{}",
            target.block,
            frame,
            block_start,
            block_end,
            frame_start,
            frame_end
        );
    }
    let target_start = pf_site_start_slot(prog, target)?;
    let ptr_def_end = pf_site_end_slot(prog, ptr_def)?;
    let valid_start = block_start
        .max(target_start.saturating_sub(max_slots))
        .max(ptr_def_end);
    if valid_start > target_start {
        return Ok(Vec::new());
    }
    let mut sites = Vec::new();
    for site in prog.sites_in_block(target.block)? {
        let site_start = pf_site_start_slot(prog, site)?;
        if site_start >= valid_start && site_start <= target_start {
            sites.push(site);
        }
    }
    Ok(sites)
}

fn pf_nearest_prefetch_insert_site(
    prog: &BBProgram,
    sites: &[InsnSite],
    target: InsnSite,
    ideal_distance: usize,
) -> anyhow::Result<Option<InsnSite>> {
    let ideal = pf_site_start_slot(prog, target)?.saturating_sub(ideal_distance);
    let mut best = None;
    for &site in sites {
        let site_start = pf_site_start_slot(prog, site)?;
        let distance = site_start.abs_diff(ideal);
        if best.is_none_or(|(best_distance, best_start, _)| {
            distance < best_distance || (distance == best_distance && site_start < best_start)
        }) {
            best = Some((distance, site_start, site));
        }
    }
    Ok(best.map(|(_, _, site)| site))
}

fn pf_site_start_slot(prog: &BBProgram, site: InsnSite) -> anyhow::Result<usize> {
    prog.site_current_pc(site)
}

fn pf_site_end_slot(prog: &BBProgram, site: InsnSite) -> anyhow::Result<usize> {
    pf_site_start_slot(prog, site)?
        .checked_add(prog.insn_slot_width(site)?)
        .ok_or_else(|| anyhow::anyhow!("prefetch site {:?} end slot overflows", site))
}

fn block_slot_bounds(prog: &BBProgram, block: BlockId) -> anyhow::Result<(usize, usize)> {
    let mut pc = 0usize;
    for candidate in prog.block_ids() {
        let start = pc;
        for site in prog.sites_in_block_with_terminator(candidate)? {
            pc = pc
                .checked_add(prog.insn_slot_width(site)?)
                .ok_or_else(|| anyhow::anyhow!("prefetch block slot bounds overflow"))?;
        }
        if candidate == block {
            return Ok((start, pc));
        }
    }
    anyhow::bail!("invalid block id {:?}", block)
}

fn frame_slot_bounds(prog: &BBProgram, frame: FrameId) -> anyhow::Result<(usize, usize)> {
    let mut start = usize::MAX;
    let mut end = 0usize;
    for block in prog.subprog_blocks(frame) {
        let (block_start, block_end) = block_slot_bounds(prog, block)?;
        start = start.min(block_start);
        end = end.max(block_end);
    }
    if start == usize::MAX {
        anyhow::bail!("frame {:?} has no blocks", frame);
    }
    Ok((start, end))
}

fn reject_control_flow_between(
    prog: &BBProgram,
    window: &[InsnSite],
) -> anyhow::Result<Option<InsertReject>> {
    for &site in window {
        let insn = prog
            .insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
        if insn.is_call() || insn.is_exit() || insn.is_jmp_class() || insn.is_ldimm64_pseudo_func()
        {
            return Ok(Some(InsertReject::ControlFlow(site)));
        }
    }
    Ok(None)
}
fn reject_reg_write_between(
    prog: &BBProgram,
    window: &[InsnSite],
    reg: u8,
) -> anyhow::Result<Option<InsertReject>> {
    for &site in window {
        let insn = prog
            .insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
        if reg_write_kind(insn, reg).is_some() {
            return Ok(Some(InsertReject::RegWrite { reg, site }));
        }
    }
    Ok(None)
}
fn reg_write_kind(insn: &BpfInsn, reg: u8) -> Option<RegWriteKind> {
    if insn.is_call() && reg <= BPF_REG_5 {
        return Some(RegWriteKind::CallClobber);
    }
    if insn.is_ldimm64() {
        return (insn.dst_reg() == reg).then_some(RegWriteKind::Explicit);
    }
    match insn.class() {
        BPF_LD | BPF_LDX | BPF_ALU | BPF_ALU64 => {
            (insn.dst_reg() == reg).then_some(RegWriteKind::Explicit)
        }
        _ => None,
    }
}
fn dedup_candidates(mut candidates: Vec<PrefetchCandidate>) -> Vec<PrefetchCandidate> {
    candidates.sort_by(|a, b| {
        b.score
            .cmp(&a.score)
            .then_with(|| a.insert.cmp(&b.insert))
            .then_with(|| a.target.cmp(&b.target))
    });
    let mut kept = Vec::new();
    for candidate in candidates {
        if kept.iter().any(|existing: &PrefetchCandidate| {
            existing.insert == candidate.insert && existing.ptr_reg == candidate.ptr_reg
        }) {
            continue;
        }
        kept.push(candidate);
    }
    kept.sort_by_key(|candidate| candidate.insert);
    kept
}
