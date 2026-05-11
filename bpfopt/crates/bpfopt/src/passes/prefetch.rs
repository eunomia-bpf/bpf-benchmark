// SPDX-License-Identifier: MIT
use crate::analysis::{BBProgram, InsnSite};
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
    prog.pf_skip_reason(site, reason)
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
            Some(score) => score,
            None => {
                skipped.push(skip_at(
                    prog,
                    site.target,
                    "prefetch site execution_count is zero".into(),
                )?);
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
fn prefetch_score_for_site(prog: &BBProgram, site: PrefetchSite) -> anyhow::Result<Option<u64>> {
    let has_profile_hint = prog
        .prefetch_hint(site.target)
        .or_else(|| prog.prefetch_hint(site.anchor))
        .is_some();
    if !has_profile_hint {
        return Ok(Some(default_site_score(site)));
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
    Ok((hotness != 0).then_some(hotness))
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
    for site in prog.pf_sites_after_in_frame(call_site, MAP_VALUE_LOOKAHEAD)? {
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
    let window = prog.pf_prefetch_window_sites(site.ptr_def, site.target, MAX_PREFETCH_DISTANCE)?;
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
        prog.pf_nearest_prefetch_insert_site(&window, site.target, TARGET_PREFETCH_DISTANCE)?
    else {
        return Ok(Err(InsertReject::Plain(
            "prefetch insertion window has no instruction boundary".into(),
        )));
    };
    Ok(Ok(insert_site))
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
