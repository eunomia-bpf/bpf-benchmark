// SPDX-License-Identifier: MIT
//! PREFETCH optimization pass.

use std::collections::{BTreeMap, HashMap};
use std::fs;
use std::path::{Path, PathBuf};

use anyhow::{bail, Context, Result};
use serde::Deserialize;

use crate::analysis::{BranchTargetAnalysis, BranchTargetResult, CFGAnalysis, CFGResult};
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    emit_packed_kinsn_call_with_off, fixup_all_branches, insn_width, remap_kinsn_btf_metadata,
    resolve_kinsn_call_off_for_target,
};

pub(super) const HELPER_MAP_LOOKUP_ELEM: i32 = libbpf_sys::BPF_FUNC_map_lookup_elem as i32;
const HELPER_XDP_ADJUST_HEAD: i32 = libbpf_sys::BPF_FUNC_xdp_adjust_head as i32;
const PREFETCH_TARGET_NAME: &str = "bpf_prefetch";
const TARGET_PREFETCH_DISTANCE: usize = 8;
const MAX_PREFETCH_DISTANCE: usize = 16;
const MAP_VALUE_LOOKAHEAD: usize = 64;

const BPF_PROG_TYPE_SCHED_CLS: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_CLS;
const BPF_PROG_TYPE_SCHED_ACT: u32 = libbpf_sys::BPF_PROG_TYPE_SCHED_ACT;
pub(super) const BPF_PROG_TYPE_XDP: u32 = libbpf_sys::BPF_PROG_TYPE_XDP;
const BPF_PROG_TYPE_SK_SKB: u32 = libbpf_sys::BPF_PROG_TYPE_SK_SKB;
const BPF_PROG_TYPE_LWT_IN: u32 = libbpf_sys::BPF_PROG_TYPE_LWT_IN;
const BPF_PROG_TYPE_LWT_OUT: u32 = libbpf_sys::BPF_PROG_TYPE_LWT_OUT;
const BPF_PROG_TYPE_LWT_XMIT: u32 = libbpf_sys::BPF_PROG_TYPE_LWT_XMIT;

pub(super) const XDP_DATA_OFF: i16 = 0;
const XDP_DATA_END_OFF: i16 = 4;
const SKB_DATA_OFF: i16 = 76;
const SKB_DATA_END_OFF: i16 = 80;

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

    fn required_analyses(&self) -> Vec<&str> {
        PrefetchPass.required_analyses()
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        program.inject_profiling(&self.profiling);
        PrefetchPass.run(program, analyses, ctx)
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

fn read_json_file<T: for<'de> Deserialize<'de>>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&data)
        .with_context(|| format!("failed to parse {label} from {}", path.display()))
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
    ptr_reg: u8,
    ptr_def_end_pc: usize,
    kind: PrefetchKind,
}

#[derive(Clone, Debug)]
struct PrefetchCandidate {
    target_pc: usize,
    insert_pc: usize,
    ptr_reg: u8,
    score: u64,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct PacketCtxLayout {
    data_off: i16,
    data_end_off: i16,
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
    Ok(u64::from(ptr_reg))
}

impl BpfPass for PrefetchPass {
    fn name(&self) -> &str {
        "prefetch"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["cfg", "branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        if ctx.kinsn_registry.prefetch_btf_id < 0 {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_prefetch kfunc not available".into(),
                },
            ));
        }

        if !ctx
            .kinsn_registry
            .kinsn_registered_for_target_name(PREFETCH_TARGET_NAME)
        {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_prefetch packed ABI not available".into(),
                },
            ));
        }

        let cfg_analysis = CFGAnalysis;
        let cfg = analyses.get(&cfg_analysis, program);
        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let mut candidates = Vec::new();
        let mut skipped = Vec::new();

        for site in scan_prefetch_sites(&program.insns, &cfg, &bt, ctx.prog_type) {
            let score = match prefetch_profile_for_site(program, site) {
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

            let insert_pc = match choose_prefetch_insert_pc(program, &cfg, site) {
                Ok(insert_pc) => insert_pc,
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
                ptr_reg: site.ptr_reg,
                score,
            });
        }

        let candidates = dedup_candidates(candidates);
        if candidates.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged(self.name())
            });
        }

        let btf_id = ctx.kinsn_registry.prefetch_btf_id;
        let kfunc_off = resolve_kinsn_call_off_for_target(ctx, PREFETCH_TARGET_NAME)?;
        let insertions = group_candidates_by_insert_pc(&candidates);

        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len + candidates.len() * 2);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0usize;

        while pc < orig_len {
            let new_pc = new_insns.len();
            if let Some(prefetches) = insertions.get(&pc) {
                addr_map[pc] = new_pc;
                for candidate in prefetches {
                    let payload = prefetch_payload(candidate.ptr_reg)?;
                    let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
                    new_insns.extend_from_slice(&replacement);
                }
            } else {
                addr_map[pc] = new_pc;
            }

            new_insns.push(program.insns[pc]);
            if program.insns[pc].is_ldimm64() && pc + 1 < orig_len {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(program.insns[pc]);
            }
            pc += 1;
        }
        addr_map[orig_len] = new_insns.len();

        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        remap_kinsn_btf_metadata(program, &ctx.kinsn_registry)?;
        program.remap_annotations(&addr_map);

        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied: candidates.len(),
            sites_skipped: skipped,
            ..Default::default()
        })
    }
}

fn scan_prefetch_sites(
    insns: &[BpfInsn],
    cfg: &CFGResult,
    bt: &BranchTargetResult,
    prog_type: u32,
) -> Vec<PrefetchSite> {
    let mut sites = scan_map_value_prefetch_sites(insns, cfg);
    if let Some(layout) = packet_ctx_layout(prog_type) {
        sites.extend(scan_packet_prefetch_sites(insns, bt, layout));
    }
    sites
}

fn prefetch_profile_for_site<'a>(
    program: &'a BpfProgram,
    site: PrefetchSite,
) -> Option<&'a PrefetchProfile> {
    program
        .annotations
        .get(site.target_pc)
        .and_then(|ann| ann.prefetch_profile.as_ref())
        .or_else(|| {
            program
                .annotations
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

fn scan_map_value_prefetch_sites(insns: &[BpfInsn], cfg: &CFGResult) -> Vec<PrefetchSite> {
    let mut sites = Vec::new();
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        if insn.is_call() && insn.src_reg() == 0 && insn.imm == HELPER_MAP_LOOKUP_ELEM {
            if let Some(site) = first_map_value_deref_after_lookup(insns, cfg, pc) {
                sites.push(site);
            }
        }
        pc += insn_width(insn);
    }

    sites
}

fn first_map_value_deref_after_lookup(
    insns: &[BpfInsn],
    cfg: &CFGResult,
    call_pc: usize,
) -> Option<PrefetchSite> {
    let (_, subprog_end) = subprog_bounds(cfg, insns.len(), call_pc)?;
    let scan_end = subprog_end.min(call_pc.saturating_add(MAP_VALUE_LOOKAHEAD));
    let mut aliases = [None::<usize>; 11];
    aliases[BPF_REG_0 as usize] = Some(call_pc + 1);
    let mut pc = call_pc + 1;

    while pc < scan_end {
        let insn = &insns[pc];
        let width = insn_width(insn);

        if let Some(base_reg) = memory_base_reg(insn) {
            if let Some(def_end_pc) = aliases[base_reg as usize] {
                return Some(PrefetchSite {
                    anchor_pc: call_pc,
                    target_pc: pc,
                    ptr_reg: base_reg,
                    ptr_def_end_pc: def_end_pc,
                    kind: PrefetchKind::MapValue,
                });
            }
        }

        if stops_map_value_scan(insn) {
            break;
        }
        apply_map_value_alias_transfer(insn, pc, width, &mut aliases);
        pc += width;
    }

    None
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
    insns: &[BpfInsn],
    bt: &BranchTargetResult,
    layout: PacketCtxLayout,
) -> Vec<PrefetchSite> {
    let mut sites = Vec::new();
    let mut regs = initial_packet_regs();
    let mut pc = 0usize;

    while pc < insns.len() {
        if pc > 0 && bt.is_target.get(pc).copied().unwrap_or(false) {
            regs = [TrackedValue::Unknown; 11];
        }

        let insn = &insns[pc];
        let width = insn_width(insn);
        if let Some(base_reg) = memory_base_reg(insn) {
            if let TrackedValue::PacketData { def_end_pc } = regs[base_reg as usize] {
                sites.push(PrefetchSite {
                    anchor_pc: pc,
                    target_pc: pc,
                    ptr_reg: base_reg,
                    ptr_def_end_pc: def_end_pc,
                    kind: PrefetchKind::Packet,
                });
            }
        }

        apply_packet_transfer(insn, pc, width, layout, &mut regs);
        pc += width;
    }

    sites
}

fn packet_ctx_layout(prog_type: u32) -> Option<PacketCtxLayout> {
    match prog_type {
        BPF_PROG_TYPE_XDP => Some(PacketCtxLayout {
            data_off: XDP_DATA_OFF,
            data_end_off: XDP_DATA_END_OFF,
        }),
        BPF_PROG_TYPE_SCHED_CLS
        | BPF_PROG_TYPE_SCHED_ACT
        | BPF_PROG_TYPE_SK_SKB
        | BPF_PROG_TYPE_LWT_IN
        | BPF_PROG_TYPE_LWT_OUT
        | BPF_PROG_TYPE_LWT_XMIT => Some(PacketCtxLayout {
            data_off: SKB_DATA_OFF,
            data_end_off: SKB_DATA_END_OFF,
        }),
        _ => None,
    }
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

fn choose_prefetch_insert_pc(
    program: &BpfProgram,
    cfg: &CFGResult,
    site: PrefetchSite,
) -> Result<usize, String> {
    let target_pc = site.target_pc;
    if target_pc >= program.insns.len() || target_pc >= cfg.insn_to_block.len() {
        return Err("prefetch target pc is outside the instruction stream".into());
    }

    let (subprog_start, subprog_end) = subprog_bounds(cfg, program.insns.len(), target_pc)
        .ok_or_else(|| "prefetch target pc is outside all subprograms".to_string())?;
    let block = &cfg.blocks[cfg.insn_to_block[target_pc]];
    if block.start < subprog_start || block.end > subprog_end {
        return Err(format!(
            "prefetch basic block crosses subprog boundary (block {}..{}, subprog {}..{})",
            block.start, block.end, subprog_start, subprog_end
        ));
    }

    let valid_start = block
        .start
        .max(subprog_start)
        .max(target_pc.saturating_sub(MAX_PREFETCH_DISTANCE))
        .max(site.ptr_def_end_pc);
    if valid_start > target_pc {
        return Err("no valid prefetch insertion window".into());
    }

    reject_control_flow_between(&program.insns, valid_start, target_pc)?;
    reject_reg_write_between(&program.insns, site.ptr_reg, valid_start, target_pc)?;

    let ideal = target_pc.saturating_sub(TARGET_PREFETCH_DISTANCE);
    let Some(insert_pc) = nearest_instruction_boundary(
        &program.insns,
        block.start,
        target_pc + 1,
        valid_start,
        target_pc,
        ideal,
    ) else {
        return Err("prefetch insertion window has no instruction boundary".into());
    };
    Ok(insert_pc)
}

fn subprog_bounds(
    cfg: &crate::analysis::CFGResult,
    program_len: usize,
    pc: usize,
) -> Option<(usize, usize)> {
    let idx = cfg
        .subprogs
        .iter()
        .rposition(|subprog| subprog.start <= pc)?;
    let start = cfg.subprogs[idx].start;
    let end = cfg
        .subprogs
        .get(idx + 1)
        .map(|subprog| subprog.start)
        .unwrap_or(program_len);
    (pc < end).then_some((start, end))
}

fn reject_control_flow_between(
    insns: &[BpfInsn],
    start_pc: usize,
    end_pc: usize,
) -> Result<(), String> {
    let mut pc = start_pc;
    while pc < end_pc {
        let insn = &insns[pc];
        if insn.is_call() || insn.is_exit() || insn.is_jmp_class() || insn.is_ldimm64_pseudo_func()
        {
            return Err(format!(
                "prefetch window contains control-flow instruction at pc {pc}"
            ));
        }
        pc += insn_width(insn);
    }
    Ok(())
}

fn reject_reg_write_between(
    insns: &[BpfInsn],
    reg: u8,
    start_pc: usize,
    end_pc: usize,
) -> Result<(), String> {
    let mut pc = start_pc;
    while pc < end_pc {
        let insn = &insns[pc];
        if reg_write_kind(insn, reg).is_some() {
            return Err(format!(
                "r{reg} is redefined inside the prefetch window at pc {pc}"
            ));
        }
        pc += insn_width(insn);
    }
    Ok(())
}

fn nearest_instruction_boundary(
    insns: &[BpfInsn],
    scan_start: usize,
    scan_end: usize,
    valid_start: usize,
    valid_end: usize,
    ideal: usize,
) -> Option<usize> {
    let mut pc = scan_start;
    let mut best = None;

    while pc < scan_end {
        if pc >= valid_start && pc <= valid_end {
            let distance = pc.abs_diff(ideal);
            let replace = best
                .map(|(best_distance, best_pc)| {
                    distance < best_distance || (distance == best_distance && pc < best_pc)
                })
                .unwrap_or(true);
            if replace {
                best = Some((distance, pc));
            }
        }
        pc += insn_width(&insns[pc]);
    }

    best.map(|(_, pc)| pc)
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

fn group_candidates_by_insert_pc(
    candidates: &[PrefetchCandidate],
) -> BTreeMap<usize, Vec<PrefetchCandidate>> {
    let mut grouped = BTreeMap::<usize, Vec<PrefetchCandidate>>::new();
    for candidate in candidates {
        grouped
            .entry(candidate.insert_pc)
            .or_default()
            .push(candidate.clone());
    }
    grouped
}
