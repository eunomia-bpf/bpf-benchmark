// SPDX-License-Identifier: MIT
//! PREFETCH optimization pass.

use std::collections::{BTreeMap, HashMap};
use std::path::{Path, PathBuf};

use anyhow::{bail, Context, Result};
use serde::Deserialize;

use crate::analysis::{
    annotations_from_profile, packet_ctx_layout, read_json_file, site_current_pc, BBProgram,
    BlockId, InsnSite, PacketCtxLayout, PacketCtxLayoutScope,
};
use crate::insn::*;
use crate::pass::*;
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

/// Packet/map-value prefetch pass.
///
/// The default mode is structural: emit `bpf_prefetch(ptr)` before direct packet
/// accesses and before the first dereference of a value returned by
/// `map_lookup_elem`. If real per-site PMU data is present for a candidate, it is
/// used as an admission filter; missing PMU data does not block structural
/// candidates.
pub struct PrefetchPass;

struct ProfiledPrefetchPass {
    profiling: ProfilingData,
}

impl PrefetchPass {
    pub fn from_cli_args(args: &[String]) -> Result<Box<dyn BpfPass>> {
        let Some(profile) = PrefetchCliArgs::parse(args)? else {
            return Ok(Box::new(PrefetchPass));
        };
        Ok(Box::new(ProfiledPrefetchPass {
            profiling: read_prefetch_profile(&profile)?,
        }))
    }
}

impl BpfPass for ProfiledPrefetchPass {
    fn name(&self) -> &str {
        "prefetch"
    }

    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        let annotations = annotations_from_profile(&self.profiling);
        run_on_bbprogram_with_prefetch_profiles(program, ctx, &annotations)
    }
}

struct PrefetchCliArgs;

impl PrefetchCliArgs {
    fn parse(args: &[String]) -> Result<Option<PathBuf>> {
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
                other => bail!("prefetch unknown pass-local arg: {other}"),
            }
        }
        Ok(profile)
    }
}

#[derive(Debug, Deserialize)]
struct PrefetchProfileJson {
    #[serde(default)]
    prefetch_sites: HashMap<String, PrefetchProfileSiteJson>,
}

#[derive(Debug, Deserialize)]
struct PrefetchProfileSiteJson {
    execution_count: u64,
    cache_references: u64,
    cache_misses: u64,
    miss_rate: f64,
}

fn read_prefetch_profile(path: &Path) -> Result<ProfilingData> {
    let profile: PrefetchProfileJson = read_json_file(path, "prefetch profile JSON")?;
    let mut data = ProfilingData::default();
    for (pc, counts) in profile.prefetch_sites {
        let pc = pc
            .parse::<usize>()
            .with_context(|| format!("invalid prefetch_sites pc key: {pc}"))?;
        if counts.cache_misses > counts.cache_references {
            bail!(
                "profile prefetch_sites[{pc}] cache_misses {} exceeds cache_references {}",
                counts.cache_misses,
                counts.cache_references
            );
        }
        if !counts.miss_rate.is_finite() || !(0.0..=1.0).contains(&counts.miss_rate) {
            bail!(
                "profile prefetch_sites[{pc}] miss_rate must be finite and within [0, 1], got {}",
                counts.miss_rate
            );
        }
        data.prefetch_profiles.insert(
            pc,
            PrefetchProfile {
                execution_count: counts.execution_count,
                cache_references: counts.cache_references,
                cache_misses: counts.cache_misses,
                miss_rate: counts.miss_rate,
            },
        );
    }
    Ok(data)
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum PrefetchKind {
    MapValue,
    Packet,
}

#[derive(Clone, Copy, Debug)]
struct PrefetchSite {
    anchor_pc: usize,
    target_pc: usize,
    target_site: InsnSite,
    ptr_reg: u8,
    ptr_def_end_pc: usize,
    kind: PrefetchKind,
}

#[derive(Clone, Debug)]
struct PrefetchCandidate {
    target_pc: usize,
    insert_pc: usize,
    insert_block: BlockId,
    insert_idx: usize,
    ptr_reg: u8,
    score: u64,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum TrackedValue {
    Unknown,
    Ctx,
    PacketData { def_end_pc: usize },
    PacketEnd,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RegWriteKind {
    Explicit,
    CallClobber,
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
        run_on_bbprogram_with_prefetch_profiles(program, ctx, &ctx.annotations)
    }
}

pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    run_on_bbprogram_with_prefetch_profiles(prog, ctx, &[])
}

fn run_on_bbprogram_with_prefetch_profiles(
    prog: &mut BBProgram,
    ctx: &PassContext,
    annotations: &[InsnAnnotation],
) -> anyhow::Result<PassResult> {
    let site_pcs = prog.current_site_pcs()?;
    if site_pcs.is_empty() {
        return Ok(PassResult::unchanged());
    }

    let mut candidates = Vec::new();
    let mut skipped = Vec::new();

    for site in scan_prefetch_sites(prog, &site_pcs, ctx.prog_type)? {
        let score = match prefetch_profile_for_site(annotations, site) {
            Some(profile) => {
                if let Some(reason) = prefetch_profile_skip_reason(site.target_pc, profile)? {
                    skipped.push(SkipReason {
                        pc: site.target_pc,
                        reason,
                    });
                    continue;
                }
                profile.execution_count
            }
            None => default_site_score(site),
        };

        let (insert_pc, insert_site) = match choose_prefetch_insert_site(prog, &site_pcs, site)? {
            Ok(insert) => insert,
            Err(reason) => {
                skipped.push(SkipReason {
                    pc: site.target_pc,
                    reason,
                });
                continue;
            }
        };

        candidates.push(PrefetchCandidate {
            target_pc: site.target_pc,
            insert_pc,
            insert_block: insert_site.block,
            insert_idx: insert_site.idx,
            ptr_reg: site.ptr_reg,
            score,
        });
    }

    let candidates = dedup_candidates(candidates);
    if candidates.is_empty() {
        return Ok(PassResult {
            sites_skipped: skipped,
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
        prog.replace_range(
            candidate.insert_block,
            candidate.insert_idx..candidate.insert_idx,
            emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
        )?;
    }

    Ok(PassResult {
        sites_applied: candidates.len(),
        sites_skipped: skipped,
        ..Default::default()
    })
}

fn scan_prefetch_sites(
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
    prog_type: u32,
) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = scan_map_value_prefetch_sites(prog, site_pcs)?;
    if let Some(layout) = packet_ctx_layout(prog_type, PacketCtxLayoutScope::PacketAccess) {
        sites.extend(scan_packet_prefetch_sites(prog, site_pcs, layout)?);
    }
    Ok(sites)
}

fn prefetch_profile_for_site(
    annotations: &[InsnAnnotation],
    site: PrefetchSite,
) -> Option<&PrefetchProfile> {
    annotations
        .get(site.target_pc)
        .and_then(|ann| ann.prefetch_profile.as_ref())
        .or_else(|| {
            annotations
                .get(site.anchor_pc)
                .and_then(|ann| ann.prefetch_profile.as_ref())
        })
}

fn default_site_score(site: PrefetchSite) -> u64 {
    match site.kind {
        PrefetchKind::MapValue => 2,
        PrefetchKind::Packet => 1,
    }
}

fn prefetch_profile_skip_reason(
    pc: usize,
    profile: &PrefetchProfile,
) -> anyhow::Result<Option<String>> {
    if profile.execution_count == 0 {
        return Ok(Some("prefetch site execution_count is zero".into()));
    }
    if profile.cache_misses > profile.cache_references {
        anyhow::bail!(
            "prefetch candidate at pc {pc} has cache_misses {} exceeding cache_references {}",
            profile.cache_misses,
            profile.cache_references
        );
    }
    if !profile.miss_rate.is_finite() || !(0.0..=1.0).contains(&profile.miss_rate) {
        anyhow::bail!(
            "prefetch candidate at pc {pc} has invalid cache miss_rate {}",
            profile.miss_rate
        );
    }
    if profile.cache_references == 0 {
        return Ok(Some("prefetch site has zero cache_references".into()));
    }
    if profile.cache_misses == 0 || profile.miss_rate == 0.0 {
        return Ok(Some("prefetch site has no observed cache misses".into()));
    }
    Ok(None)
}

fn scan_map_value_prefetch_sites(
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = Vec::new();
    for block in prog.blocks().map(|block| block.id).collect::<Vec<_>>() {
        for site in prog.sites_in_block(block)? {
            let insn = prog
                .insn_at(site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
            if insn.is_call() && insn.src_reg() == 0 && insn.imm == HELPER_MAP_LOOKUP_ELEM {
                if let Some(prefetch) = first_map_value_deref_after_lookup(prog, site_pcs, site)? {
                    sites.push(prefetch);
                }
            }
        }
    }
    Ok(sites)
}

fn first_map_value_deref_after_lookup(
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
    call_site: InsnSite,
) -> anyhow::Result<Option<PrefetchSite>> {
    let call_pc = site_current_pc(site_pcs, call_site)?;
    let call_width = prog.insn_slot_width(call_site)?;
    let frame = prog.block(call_site.block)?.frame;
    let (_, subprog_end) = prog.frame_slot_bounds(frame)?;
    let scan_end = subprog_end.min(call_pc.saturating_add(MAP_VALUE_LOOKAHEAD));
    let mut aliases = [None::<usize>; 11];
    aliases[BPF_REG_0 as usize] = Some(call_pc + call_width);

    for (pc, site) in
        prog.sites_in_frame_pc_range(site_pcs, frame, call_pc + call_width, scan_end)?
    {
        let insn = prog
            .insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
        let width = prog.insn_slot_width(site)?;

        if let Some(base_reg) = memory_base_reg(insn) {
            if let Some(def_end_pc) = aliases[base_reg as usize] {
                return Ok(Some(PrefetchSite {
                    anchor_pc: call_pc,
                    target_pc: pc,
                    target_site: site,
                    ptr_reg: base_reg,
                    ptr_def_end_pc: def_end_pc,
                    kind: PrefetchKind::MapValue,
                }));
            }
        }

        if stops_map_value_scan(insn) {
            break;
        }
        apply_map_value_alias_transfer(insn, pc, width, &mut aliases);
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
    pc: usize,
    width: usize,
    aliases: &mut [Option<usize>; 11],
) {
    if insn.is_ldimm64() {
        aliases[insn.dst_reg() as usize] = None;
        return;
    }

    match insn.class() {
        BPF_ALU64 => apply_map_value_alu64_transfer(insn, pc, width, aliases),
        BPF_ALU | BPF_LD | BPF_LDX => aliases[insn.dst_reg() as usize] = None,
        _ => {}
    }
}

fn apply_map_value_alu64_transfer(
    insn: &BpfInsn,
    pc: usize,
    width: usize,
    aliases: &mut [Option<usize>; 11],
) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => {
            aliases[dst] = aliases[insn.src_reg() as usize].map(|_| pc + width);
        }
        (BPF_ADD | BPF_SUB, BPF_K) if aliases[dst].is_some() => {
            aliases[dst] = Some(pc + width);
        }
        _ => aliases[dst] = None,
    }
}

fn scan_packet_prefetch_sites(
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
    layout: PacketCtxLayout,
) -> anyhow::Result<Vec<PrefetchSite>> {
    let mut sites = Vec::new();
    let mut regs = initial_packet_regs();

    for block in prog.blocks().map(|block| block.id).collect::<Vec<_>>() {
        if prog.should_reset_linear_state_at_block(block)? {
            regs = [TrackedValue::Unknown; 11];
        }

        for site in prog.sites_in_block_with_terminator(block)? {
            let pc = site_current_pc(site_pcs, site)?;
            let insn = prog
                .insn_at(site)
                .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
            let width = prog.insn_slot_width(site)?;
            if let Some(base_reg) = memory_base_reg(insn) {
                if let TrackedValue::PacketData { def_end_pc } = regs[base_reg as usize] {
                    sites.push(PrefetchSite {
                        anchor_pc: pc,
                        target_pc: pc,
                        target_site: site,
                        ptr_reg: base_reg,
                        ptr_def_end_pc: def_end_pc,
                        kind: PrefetchKind::Packet,
                    });
                }
            }

            apply_packet_transfer(insn, pc, width, layout, &mut regs);
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
    pc: usize,
    width: usize,
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
            apply_packet_ldx_transfer(insn, pc, width, layout, regs);
        }
        BPF_ALU64 => apply_packet_alu64_transfer(insn, pc, width, regs),
        BPF_ALU | BPF_LD => regs[insn.dst_reg() as usize] = TrackedValue::Unknown,
        _ => {}
    }
}

fn apply_packet_ldx_transfer(
    insn: &BpfInsn,
    pc: usize,
    width: usize,
    layout: PacketCtxLayout,
    regs: &mut [TrackedValue; 11],
) {
    let dst = insn.dst_reg() as usize;
    regs[dst] = match regs[insn.src_reg() as usize] {
        TrackedValue::Ctx if bpf_size(insn.code) == BPF_W && insn.off == layout.data_off => {
            TrackedValue::PacketData {
                def_end_pc: pc + width,
            }
        }
        TrackedValue::Ctx if bpf_size(insn.code) == BPF_W && insn.off == layout.data_end_off => {
            TrackedValue::PacketEnd
        }
        _ => TrackedValue::Unknown,
    };
}

fn apply_packet_alu64_transfer(
    insn: &BpfInsn,
    pc: usize,
    width: usize,
    regs: &mut [TrackedValue; 11],
) {
    let dst = insn.dst_reg() as usize;
    match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_MOV, BPF_X) => {
            regs[dst] = match regs[insn.src_reg() as usize] {
                TrackedValue::PacketData { .. } => TrackedValue::PacketData {
                    def_end_pc: pc + width,
                },
                value => value,
            };
        }
        (BPF_ADD | BPF_SUB, BPF_K) => {
            if let TrackedValue::PacketData { .. } = regs[dst] {
                regs[dst] = TrackedValue::PacketData {
                    def_end_pc: pc + width,
                };
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
    site_pcs: &BTreeMap<InsnSite, usize>,
    site: PrefetchSite,
) -> anyhow::Result<Result<(usize, InsnSite), String>> {
    let target_pc = site.target_pc;
    let block = site.target_site.block;
    let (block_start, block_end) = prog.block_slot_bounds(block)?;
    let frame = prog.block(block)?.frame;
    let (subprog_start, subprog_end) = prog.frame_slot_bounds(frame)?;
    if block_start < subprog_start || block_end > subprog_end {
        return Ok(Err(format!(
            "prefetch basic block crosses subprog boundary (block {}..{}, subprog {}..{})",
            block_start, block_end, subprog_start, subprog_end
        )));
    }

    let valid_start = block_start
        .max(subprog_start)
        .max(target_pc.saturating_sub(MAX_PREFETCH_DISTANCE))
        .max(site.ptr_def_end_pc);
    if valid_start > target_pc {
        return Ok(Err("no valid prefetch insertion window".into()));
    }

    if let Some(reason) =
        reject_control_flow_between(prog, site_pcs, block, valid_start, target_pc)?
    {
        return Ok(Err(reason));
    }
    if let Some(reason) =
        reject_reg_write_between(prog, site_pcs, block, site.ptr_reg, valid_start, target_pc)?
    {
        return Ok(Err(reason));
    }

    let ideal = target_pc.saturating_sub(TARGET_PREFETCH_DISTANCE);
    let Some((insert_pc, insert_site)) =
        nearest_instruction_boundary(prog, site_pcs, block, valid_start, target_pc, ideal)?
    else {
        return Ok(Err(
            "prefetch insertion window has no instruction boundary".into()
        ));
    };
    Ok(Ok((insert_pc, insert_site)))
}

fn reject_control_flow_between(
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
    block: BlockId,
    start_pc: usize,
    end_pc: usize,
) -> anyhow::Result<Option<String>> {
    for (pc, site) in prog.sites_in_block_pc_range(site_pcs, block, start_pc, end_pc)? {
        let insn = prog
            .insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
        if insn.is_call() || insn.is_exit() || insn.is_jmp_class() || insn.is_ldimm64_pseudo_func()
        {
            return Ok(Some(format!(
                "prefetch window contains control-flow instruction at pc {pc}"
            )));
        }
    }
    Ok(None)
}

fn reject_reg_write_between(
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
    block: BlockId,
    reg: u8,
    start_pc: usize,
    end_pc: usize,
) -> anyhow::Result<Option<String>> {
    for (pc, site) in prog.sites_in_block_pc_range(site_pcs, block, start_pc, end_pc)? {
        let insn = prog
            .insn_at(site)
            .ok_or_else(|| anyhow::anyhow!("missing instruction at {:?}", site))?;
        if reg_write_kind(insn, reg).is_some() {
            return Ok(Some(format!(
                "r{reg} is redefined inside the prefetch window at pc {pc}"
            )));
        }
    }
    Ok(None)
}

fn nearest_instruction_boundary(
    prog: &BBProgram,
    site_pcs: &BTreeMap<InsnSite, usize>,
    block: BlockId,
    valid_start: usize,
    valid_end: usize,
    ideal: usize,
) -> anyhow::Result<Option<(usize, InsnSite)>> {
    let mut best = None;

    for site in prog.sites_in_block(block)? {
        let pc = site_current_pc(site_pcs, site)?;
        if pc >= valid_start && pc <= valid_end {
            let distance = pc.abs_diff(ideal);
            if match best {
                Some((best_distance, best_pc, _)) => {
                    distance < best_distance || (distance == best_distance && pc < best_pc)
                }
                None => true,
            } {
                best = Some((distance, pc, site));
            }
        }
    }

    Ok(best.map(|(_, pc, site)| (pc, site)))
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
            .then_with(|| a.insert_pc.cmp(&b.insert_pc))
            .then_with(|| a.target_pc.cmp(&b.target_pc))
    });

    let mut kept = Vec::new();
    for candidate in candidates {
        if kept.iter().any(|existing: &PrefetchCandidate| {
            existing.insert_pc == candidate.insert_pc && existing.ptr_reg == candidate.ptr_reg
        }) {
            continue;
        }
        kept.push(candidate);
    }
    kept.sort_by_key(|candidate| candidate.insert_pc);
    kept
}
