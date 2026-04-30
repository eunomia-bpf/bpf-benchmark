// SPDX-License-Identifier: MIT
//! PREFETCH optimization pass.

use std::collections::BTreeMap;

use crate::analysis::CFGAnalysis;
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    emit_packed_kinsn_call_with_off, fixup_all_branches, remap_kinsn_btf_metadata,
    resolve_kinsn_call_off_for_target,
};

const HELPER_MAP_LOOKUP_ELEM: i32 = kernel_sys::BPF_FUNC_map_lookup_elem as i32;
const PREFETCH_TARGET_NAME: &str = "bpf_prefetch";
const PREFETCH_PTR_REG: u8 = BPF_REG_2;
const MIN_PREFETCH_DISTANCE: usize = 20;
const TARGET_PREFETCH_DISTANCE: usize = 32;
const MAX_PREFETCH_DISTANCE: usize = 50;
const PREFETCH_SITE_BUDGET: usize = 8;

/// Runtime-gated prefetch pass.
///
/// Phase 1 only handles `map_lookup_elem(map, key)` helper sites and emits
/// `bpf_prefetch(r2)` before the helper when real per-site memory PMU data says
/// the site is hot and missy. Direct map-value load prefetching is left for the
/// follow-up map-inline direct-load phase.
pub struct PrefetchPass;

#[derive(Clone, Debug)]
struct LookupPrefetchSite {
    call_pc: usize,
}

#[derive(Clone, Debug)]
struct PrefetchCandidate {
    target_pc: usize,
    insert_pc: usize,
    ptr_reg: u8,
    score: u64,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum RegWriteKind {
    Explicit,
    CallClobber,
}

#[derive(Clone, Copy, Debug)]
struct RegWrite {
    pc: usize,
    width: usize,
    kind: RegWriteKind,
}

fn prefetch_payload(ptr_reg: u8) -> anyhow::Result<u64> {
    if ptr_reg > BPF_REG_10 {
        anyhow::bail!("prefetch ptr register {ptr_reg} is outside BPF_REG_0..BPF_REG_10");
    }
    Ok(u64::from(ptr_reg))
}

#[cfg(test)]
fn decode_prefetch_payload(payload: u64) -> anyhow::Result<u8> {
    let ptr_reg = (payload & 0xf) as u8;
    if ptr_reg > BPF_REG_10 {
        anyhow::bail!("prefetch ptr register {ptr_reg} is outside BPF_REG_0..BPF_REG_10");
    }
    if ((payload >> 4) & 0xf) != 0 {
        anyhow::bail!("prefetch payload has unsupported hint kind");
    }
    if payload >> 8 != 0 {
        anyhow::bail!("prefetch payload has non-zero reserved bits");
    }
    Ok(ptr_reg)
}

fn scan_lookup_prefetch_sites(insns: &[BpfInsn]) -> Vec<LookupPrefetchSite> {
    let mut sites = Vec::new();
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        if insn.is_call() && insn.src_reg() == 0 && insn.imm == HELPER_MAP_LOOKUP_ELEM {
            sites.push(LookupPrefetchSite { call_pc: pc });
        }
        pc += insn_width(insn);
    }

    sites
}

impl BpfPass for PrefetchPass {
    fn name(&self) -> &str {
        "prefetch"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["cfg"]
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
            .packed_supported_for_target_name(PREFETCH_TARGET_NAME)
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
        let mut candidates = Vec::new();
        let mut skipped = Vec::new();

        for site in scan_lookup_prefetch_sites(&program.insns) {
            let Some(profile) = program
                .annotations
                .get(site.call_pc)
                .and_then(|ann| ann.prefetch_profile.as_ref())
            else {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: "missing real per-site prefetch PMU profile".into(),
                });
                continue;
            };

            if let Some(reason) = prefetch_profile_skip_reason(site.call_pc, profile)? {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason,
                });
                continue;
            }

            let insert_pc =
                match choose_lookup_insert_pc(program, &cfg, site.call_pc, PREFETCH_PTR_REG) {
                    Ok(insert_pc) => insert_pc,
                    Err(reason) => {
                        skipped.push(SkipReason {
                            pc: site.call_pc,
                            reason,
                        });
                        continue;
                    }
                };

            candidates.push(PrefetchCandidate {
                target_pc: site.call_pc,
                insert_pc,
                ptr_reg: PREFETCH_PTR_REG,
                score: profile.execution_count,
            });
        }

        let candidates = dedup_and_budget(candidates);
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
        program.log_transform(TransformEntry {
            sites_applied: candidates.len(),
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied: candidates.len(),
            sites_skipped: skipped,
            ..Default::default()
        })
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

fn choose_lookup_insert_pc(
    program: &BpfProgram,
    cfg: &crate::analysis::CFGResult,
    target_pc: usize,
    ptr_reg: u8,
) -> Result<usize, String> {
    if target_pc >= program.insns.len() || target_pc >= cfg.insn_to_block.len() {
        return Err("lookup target pc is outside the instruction stream".into());
    }

    let (subprog_start, subprog_end) = subprog_bounds(cfg, program.insns.len(), target_pc)
        .ok_or_else(|| "lookup target pc is outside all subprograms".to_string())?;
    let block = &cfg.blocks[cfg.insn_to_block[target_pc]];
    if block.start < subprog_start || block.end > subprog_end {
        return Err(format!(
            "lookup basic block crosses subprog boundary (block {}..{}, subprog {}..{})",
            block.start, block.end, subprog_start, subprog_end
        ));
    }

    let valid_end = match target_pc.checked_sub(MIN_PREFETCH_DISTANCE) {
        Some(pc) => pc,
        None => return Err("prefetch window is shorter than minimum distance".into()),
    };
    if valid_end < subprog_start {
        return Err("prefetch window would cross subprog boundary".into());
    }

    let Some(last_write) = last_reg_write_before(&program.insns, ptr_reg, block.start, target_pc)
    else {
        return Err(format!(
            "r{ptr_reg} has no definition before map_lookup_elem"
        ));
    };
    if last_write.kind == RegWriteKind::CallClobber {
        return Err(format!(
            "r{ptr_reg} is clobbered by a helper before map_lookup_elem"
        ));
    }

    let valid_start = block
        .start
        .max(subprog_start)
        .max(target_pc.saturating_sub(MAX_PREFETCH_DISTANCE))
        .max(last_write.pc + last_write.width);
    if valid_start > valid_end {
        return Err("no valid prefetch insertion window".into());
    }

    reject_control_flow_between(&program.insns, valid_start, target_pc)?;
    reject_reg_write_between(&program.insns, ptr_reg, valid_start, target_pc)?;

    let ideal = target_pc.saturating_sub(TARGET_PREFETCH_DISTANCE);
    let Some(insert_pc) = nearest_instruction_boundary(
        &program.insns,
        block.start,
        target_pc,
        valid_start,
        valid_end,
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

fn last_reg_write_before(
    insns: &[BpfInsn],
    reg: u8,
    start_pc: usize,
    end_pc: usize,
) -> Option<RegWrite> {
    let mut pc = start_pc;
    let mut last = None;

    while pc < end_pc {
        let insn = &insns[pc];
        let width = insn_width(insn);
        if let Some(kind) = reg_write_kind(insn, reg) {
            last = Some(RegWrite { pc, width, kind });
        }
        pc += width;
    }

    last
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

fn dedup_and_budget(mut candidates: Vec<PrefetchCandidate>) -> Vec<PrefetchCandidate> {
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
        if kept.len() == PREFETCH_SITE_BUDGET {
            break;
        }
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

fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::analysis::CFGAnalysis;
    use crate::pass::{AnalysisCache, PassContext, PassManager};

    fn exit_insn() -> BpfInsn {
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
    }

    fn map_lookup_call() -> BpfInsn {
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, 0),
            0,
            HELPER_MAP_LOOKUP_ELEM,
        )
    }

    fn add64_imm(dst: u8, imm: i32) -> BpfInsn {
        BpfInsn::new(
            BPF_ALU64 | BPF_ADD | BPF_K,
            BpfInsn::make_regs(dst, 0),
            0,
            imm,
        )
    }

    fn ld_imm64(dst: u8, src: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst, src),
                0,
                imm,
            ),
            BpfInsn::new(0, 0, 0, 0),
        ]
    }

    fn pseudo_call_to(call_pc: usize, target_pc: usize) -> BpfInsn {
        let imm = target_pc as i64 - (call_pc as i64 + 1);
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
            0,
            imm as i32,
        )
    }

    fn filler(dst: u8, count: usize) -> Vec<BpfInsn> {
        (0..count)
            .map(|idx| BpfInsn::mov64_imm(dst, idx as i32))
            .collect()
    }

    fn ctx_with_prefetch_kfunc(btf_id: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kinsn_registry.prefetch_btf_id = btf_id;
        ctx
    }

    fn hot_prefetch_profile(execution_count: u64) -> PrefetchProfile {
        PrefetchProfile {
            execution_count,
            cache_references: execution_count * 2,
            cache_misses: execution_count,
            miss_rate: 0.5,
        }
    }

    fn sidecar_payload(insn: &BpfInsn) -> u64 {
        (u64::from(insn.dst_reg()) & 0xf)
            | (u64::from(insn.off as u16) << 4)
            | (u64::from(insn.imm as u32) << 20)
    }

    fn lookup_program(filler_count: usize) -> (BpfProgram, usize) {
        let mut insns = vec![BpfInsn::mov64_reg(BPF_REG_2, BPF_REG_10)];
        insns.push(add64_imm(BPF_REG_2, -4));
        insns.extend(filler(BPF_REG_3, filler_count));
        let call_pc = insns.len();
        insns.push(map_lookup_call());
        insns.push(exit_insn());
        (BpfProgram::new(insns), call_pc)
    }

    #[test]
    fn prefetch_payload_round_trips_register_and_rejects_reserved_bits() {
        let payload = prefetch_payload(BPF_REG_2).unwrap();

        assert_eq!(decode_prefetch_payload(payload).unwrap(), BPF_REG_2);
        assert!(decode_prefetch_payload(payload | (1 << 4)).is_err());
        assert!(decode_prefetch_payload(payload | (1 << 8)).is_err());
        assert!(prefetch_payload(11).is_err());
    }

    #[test]
    fn prefetch_pass_emits_key_prefetch_for_profiled_lookup_site() {
        let (mut program, call_pc) = lookup_program(32);
        program.annotations[call_pc].prefetch_profile = Some(hot_prefetch_profile(100));
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_prefetch_kfunc(7777);

        let result = PrefetchPass.run(&mut program, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert!(program.insns[2].is_kinsn_sidecar());
        assert_eq!(
            decode_prefetch_payload(sidecar_payload(&program.insns[2])).unwrap(),
            BPF_REG_2
        );
        assert!(program.insns[3].is_call());
        assert_eq!(program.insns[3].src_reg(), BPF_PSEUDO_KINSN_CALL);
        assert_eq!(program.insns[3].imm, 7777);
        assert!(program.insns.last().unwrap().is_exit());
    }

    #[test]
    fn prefetch_pass_skips_lookup_site_without_profile() {
        let (mut program, _call_pc) = lookup_program(32);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_prefetch_kfunc(7777);

        let result = PrefetchPass.run(&mut program, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped.iter().any(|skip| skip
            .reason
            .contains("missing real per-site prefetch PMU profile")));
    }

    #[test]
    fn prefetch_pass_inserts_only_at_instruction_boundaries() {
        let wide = ld_imm64(BPF_REG_3, 0, 123);
        let mut insns = vec![BpfInsn::mov64_reg(BPF_REG_2, BPF_REG_10)];
        insns.push(add64_imm(BPF_REG_2, -4));
        insns.extend_from_slice(&wide);
        insns.extend(filler(BPF_REG_4, 31));
        let call_pc = insns.len();
        insns.push(map_lookup_call());
        insns.push(exit_insn());
        let mut program = BpfProgram::new(insns);
        program.annotations[call_pc].prefetch_profile = Some(hot_prefetch_profile(100));
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_prefetch_kfunc(7777);

        let result = PrefetchPass.run(&mut program, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert!(program.insns[2].is_kinsn_sidecar());
        assert!(program.insns[4].is_ldimm64());
        assert_eq!(program.insns[5].code, 0);
    }

    #[test]
    fn prefetch_pass_rejects_window_that_would_cross_subprog_boundary() {
        let mut insns = Vec::new();
        insns.push(pseudo_call_to(0, 52));
        insns.push(exit_insn());
        insns.extend(filler(BPF_REG_6, 50));
        let subprog_start = insns.len();
        assert_eq!(subprog_start, 52);
        insns.push(BpfInsn::mov64_reg(BPF_REG_2, BPF_REG_10));
        insns.push(add64_imm(BPF_REG_2, -4));
        insns.extend(filler(BPF_REG_3, 8));
        let call_pc = insns.len();
        insns.push(map_lookup_call());
        insns.push(exit_insn());

        let mut program = BpfProgram::new(insns);
        program.annotations[call_pc].prefetch_profile = Some(hot_prefetch_profile(100));
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_prefetch_kfunc(7777);

        let result = PrefetchPass.run(&mut program, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert!(result
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("subprog boundary")));
    }

    #[test]
    fn prefetch_pass_integration_with_pass_manager() {
        let (mut program, call_pc) = lookup_program(32);
        let mut profile = ProfilingData::default();
        profile
            .prefetch_profiles
            .insert(call_pc, hot_prefetch_profile(100));
        profile.cache_miss_rate = Some(0.5);

        let mut pm = PassManager::new();
        pm.register_analysis(CFGAnalysis);
        pm.add_pass(PrefetchPass);
        let ctx = ctx_with_prefetch_kfunc(1234);

        let result = pm
            .run_with_profiling(&mut program, &ctx, Some(&profile))
            .unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
    }
}
