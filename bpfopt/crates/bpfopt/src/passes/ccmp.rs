// SPDX-License-Identifier: MIT
//! ARM64 CCMP optimization pass.

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    emit_packed_kinsn_call_with_off, fixup_all_branches, kinsn_replacement_subprog_skip_reason,
    map_replacement_range, remap_kinsn_btf_metadata, resolve_kinsn_call_off_for_pass,
};

const MIN_CCMP_TERMS: usize = 2;
const MAX_CCMP_TERMS: usize = 4;
const CCMP_REPLACEMENT_LEN: usize = 3;

/// CCMP pass: folds same-target zero-test short-circuit AND chains into an
/// ARM64-only conditional-compare kinsn plus one final branch.
pub struct CcmpPass;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum CcmpFailMode {
    EqZero,
    NeZero,
}

impl CcmpFailMode {
    fn from_bpf_op(op: u8) -> Option<Self> {
        match op {
            BPF_JEQ => Some(Self::EqZero),
            BPF_JNE => Some(Self::NeZero),
            _ => None,
        }
    }

    fn payload_bit(self) -> u64 {
        match self {
            Self::EqZero => 0,
            Self::NeZero => 1,
        }
    }

    #[cfg(test)]
    fn from_payload_bit(bit: u64) -> anyhow::Result<Self> {
        match bit {
            0 => Ok(Self::EqZero),
            1 => Ok(Self::NeZero),
            _ => anyhow::bail!("invalid ccmp fail mode bit {bit}"),
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum CcmpWidth {
    Bpf64,
    Bpf32,
}

impl CcmpWidth {
    fn from_class(class: u8) -> Option<Self> {
        match class {
            BPF_JMP => Some(Self::Bpf64),
            BPF_JMP32 => Some(Self::Bpf32),
            _ => None,
        }
    }

    fn payload_bit(self) -> u64 {
        match self {
            Self::Bpf64 => 0,
            Self::Bpf32 => 1,
        }
    }

    #[cfg(test)]
    fn from_payload_bit(bit: u64) -> anyhow::Result<Self> {
        match bit {
            0 => Ok(Self::Bpf64),
            1 => Ok(Self::Bpf32),
            _ => anyhow::bail!("invalid ccmp width bit {bit}"),
        }
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct CcmpPayload {
    dst_reg: u8,
    fail_mode: CcmpFailMode,
    width: CcmpWidth,
    regs: Vec<u8>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct CcmpSite {
    start_pc: usize,
    old_len: usize,
    target_pc: usize,
    fail_mode: CcmpFailMode,
    width: CcmpWidth,
    regs: Vec<u8>,
}

struct SafeCcmpSite {
    site: CcmpSite,
    dst_reg: u8,
    payload: u64,
}

struct PendingCcmpBranch {
    branch_pc: usize,
    old_target_pc: usize,
    site_start_pc: usize,
}

struct BranchTerm {
    target_pc: usize,
    reg: u8,
    fail_mode: CcmpFailMode,
    width: CcmpWidth,
}

impl BpfPass for CcmpPass {
    fn name(&self) -> &str {
        "ccmp"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "liveness"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        if ctx.platform.arch != Arch::Aarch64 {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "ccmp is only valid on aarch64".into(),
                },
            ));
        }

        if ctx.kinsn_registry.ccmp64_btf_id < 0 {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_ccmp64 kfunc not available".into(),
                },
            ));
        }

        if !ctx.kinsn_registry.packed_supported_for_pass(self.name()) {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_ccmp64 packed ABI not available".into(),
                },
            ));
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = scan_ccmp_sites(&program.insns);
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            if site.regs.len() > MAX_CCMP_TERMS {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: format!(
                        "ccmp chain length {} exceeds maximum {}",
                        site.regs.len(),
                        MAX_CCMP_TERMS
                    ),
                });
                continue;
            }

            if site.target_pc <= site.start_pc + site.old_len {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "ccmp chain target is inside the chain boundary".into(),
                });
                continue;
            }

            let has_interior_target = (site.start_pc + 1..site.start_pc + site.old_len)
                .any(|pc| pc < bt.is_target.len() && bt.is_target[pc]);
            if has_interior_target {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "interior branch target".into(),
                });
                continue;
            }

            if let Some(reason) = kinsn_replacement_subprog_skip_reason(
                &program.insns,
                site.start_pc,
                site.old_len,
                CCMP_REPLACEMENT_LEN,
            )? {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason,
                });
                continue;
            }

            let Some(dst_reg) = choose_dead_dst_reg(&site, &liveness.live_out) else {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "no dead register available for ccmp predicate".into(),
                });
                continue;
            };

            let payload = encode_ccmp_payload(&CcmpPayload {
                dst_reg,
                fail_mode: site.fail_mode,
                width: site.width,
                regs: site.regs.clone(),
            })?;
            safe_sites.push(SafeCcmpSite {
                site,
                dst_reg,
                payload,
            });
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged(self.name())
            });
        }

        let btf_id = ctx.kinsn_registry.ccmp64_btf_id;
        let kfunc_off = resolve_kinsn_call_off_for_pass(ctx, self.name())?;
        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pending_branches = Vec::new();
        let mut pc = 0;
        let mut site_idx = 0;
        let mut applied = 0;

        while pc < orig_len {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].site.start_pc {
                let safe_site = &safe_sites[site_idx];
                let replacement =
                    emit_packed_kinsn_call_with_off(safe_site.payload, btf_id, kfunc_off);
                new_insns.extend_from_slice(&replacement);

                let branch_pc = new_insns.len();
                new_insns.push(BpfInsn::new(
                    BPF_JMP | BPF_JEQ | BPF_K,
                    BpfInsn::make_regs(safe_site.dst_reg, 0),
                    0,
                    0,
                ));
                pending_branches.push(PendingCcmpBranch {
                    branch_pc,
                    old_target_pc: safe_site.site.target_pc,
                    site_start_pc: safe_site.site.start_pc,
                });

                map_replacement_range(
                    &mut addr_map,
                    pc,
                    safe_site.site.old_len,
                    new_pc,
                    CCMP_REPLACEMENT_LEN,
                );

                pc += safe_site.site.old_len;
                site_idx += 1;
                applied += 1;
            } else {
                new_insns.push(program.insns[pc]);
                if program.insns[pc].is_ldimm64() && pc + 1 < orig_len {
                    pc += 1;
                    addr_map[pc] = new_insns.len();
                    new_insns.push(program.insns[pc]);
                }
                pc += 1;
            }
        }
        addr_map[orig_len] = new_insns.len();

        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);
        fixup_ccmp_branches(&mut new_insns, &addr_map, &pending_branches)?;

        program.insns = new_insns;
        remap_kinsn_btf_metadata(program, &ctx.kinsn_registry)?;
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry {
            sites_applied: applied,
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

fn scan_ccmp_sites(insns: &[BpfInsn]) -> Vec<CcmpSite> {
    let mut sites = Vec::new();
    let mut pc = 0;
    while pc < insns.len() {
        if let Some(site) = try_match_ccmp_chain(insns, pc) {
            pc += site.old_len;
            sites.push(site);
        } else {
            pc += 1;
        }
    }
    sites
}

fn try_match_ccmp_chain(insns: &[BpfInsn], pc: usize) -> Option<CcmpSite> {
    let first = branch_term(insns, pc)?;
    let mut regs = Vec::new();
    let mut cursor = pc;

    while let Some(term) = branch_term(insns, cursor) {
        if term.target_pc != first.target_pc
            || term.fail_mode != first.fail_mode
            || term.width != first.width
        {
            break;
        }
        regs.push(term.reg);
        cursor += 1;
    }

    if regs.len() < MIN_CCMP_TERMS {
        return None;
    }

    Some(CcmpSite {
        start_pc: pc,
        old_len: regs.len(),
        target_pc: first.target_pc,
        fail_mode: first.fail_mode,
        width: first.width,
        regs,
    })
}

fn branch_term(insns: &[BpfInsn], pc: usize) -> Option<BranchTerm> {
    let insn = insns.get(pc)?;
    if !insn.is_cond_jmp() || bpf_src(insn.code) != BPF_K || insn.imm != 0 {
        return None;
    }
    let fail_mode = CcmpFailMode::from_bpf_op(bpf_op(insn.code))?;
    let width = CcmpWidth::from_class(insn.class())?;
    let target_pc = relative_branch_target(pc, insn.off)?;
    if target_pc >= insns.len() || target_pc <= pc {
        return None;
    }
    Some(BranchTerm {
        target_pc,
        reg: insn.dst_reg(),
        fail_mode,
        width,
    })
}

fn relative_branch_target(pc: usize, off: i16) -> Option<usize> {
    let target = pc as i64 + 1 + i64::from(off);
    (target >= 0).then_some(target as usize)
}

fn choose_dead_dst_reg(site: &CcmpSite, live_out: &[std::collections::HashSet<u8>]) -> Option<u8> {
    let last_pc = site.start_pc + site.old_len - 1;
    let live_after = live_out.get(last_pc)?;
    (BPF_REG_0..=BPF_REG_9).find(|reg| !live_after.contains(reg) && !site.regs.contains(reg))
}

fn encode_ccmp_payload(payload: &CcmpPayload) -> anyhow::Result<u64> {
    if payload.regs.len() < MIN_CCMP_TERMS || payload.regs.len() > MAX_CCMP_TERMS {
        anyhow::bail!(
            "ccmp payload term count {} is outside {}..{}",
            payload.regs.len(),
            MIN_CCMP_TERMS,
            MAX_CCMP_TERMS
        );
    }
    if payload.dst_reg > BPF_REG_9 {
        anyhow::bail!("ccmp dst register r{} is invalid", payload.dst_reg);
    }
    if payload.regs.contains(&payload.dst_reg) {
        anyhow::bail!("ccmp dst register aliases a compare operand");
    }

    let mut encoded = u64::from(payload.dst_reg)
        | (((payload.regs.len() - 2) as u64) << 4)
        | (payload.fail_mode.payload_bit() << 6)
        | (payload.width.payload_bit() << 7);
    for (idx, &reg) in payload.regs.iter().enumerate() {
        if reg > BPF_REG_10 {
            anyhow::bail!("ccmp compare register r{reg} is invalid");
        }
        encoded |= u64::from(reg) << (8 + idx * 4);
    }
    Ok(encoded)
}

#[cfg(test)]
fn decode_ccmp_payload(encoded: u64) -> anyhow::Result<CcmpPayload> {
    if encoded >> 24 != 0 {
        anyhow::bail!("ccmp payload has non-zero reserved bits");
    }
    let dst_reg = (encoded & 0xf) as u8;
    let count_bits = ((encoded >> 4) & 0x3) as usize;
    if count_bits > MAX_CCMP_TERMS - 2 {
        anyhow::bail!("ccmp encoded term count exceeds maximum");
    }
    let count = count_bits + 2;
    let fail_mode = CcmpFailMode::from_payload_bit((encoded >> 6) & 0x1)?;
    let width = CcmpWidth::from_payload_bit((encoded >> 7) & 0x1)?;
    let mut regs = Vec::with_capacity(count);
    for idx in 0..MAX_CCMP_TERMS {
        let reg = ((encoded >> (8 + idx * 4)) & 0xf) as u8;
        if idx >= count {
            if reg != 0 {
                anyhow::bail!("ccmp unused register slot {idx} is non-zero");
            }
            continue;
        }
        regs.push(reg);
    }
    let payload = CcmpPayload {
        dst_reg,
        fail_mode,
        width,
        regs,
    };
    encode_ccmp_payload(&payload)?;
    Ok(payload)
}

fn fixup_ccmp_branches(
    insns: &mut [BpfInsn],
    addr_map: &[usize],
    pending: &[PendingCcmpBranch],
) -> anyhow::Result<()> {
    for branch in pending {
        let Some(&new_target) = addr_map.get(branch.old_target_pc) else {
            anyhow::bail!(
                "ccmp site at pc {} targets old pc {} outside address map",
                branch.site_start_pc,
                branch.old_target_pc
            );
        };
        let new_off = new_target as i64 - (branch.branch_pc as i64 + 1);
        let new_off = i16::try_from(new_off).map_err(|_| {
            anyhow::anyhow!(
                "ccmp site at pc {} branch offset {new_off} does not fit i16",
                branch.site_start_pc
            )
        })?;
        insns[branch.branch_pc].off = new_off;
    }
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::pass::{AnalysisCache, PassContext};

    fn exit_insn() -> BpfInsn {
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
    }

    fn jmp_zero(op: u8, class: u8, reg: u8, off: i16) -> BpfInsn {
        BpfInsn::new(class | op | BPF_K, BpfInsn::make_regs(reg, 0), off, 0)
    }

    fn sidecar_payload(insn: &BpfInsn) -> u64 {
        (u64::from(insn.dst_reg()) & 0xf)
            | (u64::from(insn.off as u16) << 4)
            | (u64::from(insn.imm as u32) << 20)
    }

    fn ccmp_ctx(arch: Arch) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.platform.arch = arch;
        ctx.kinsn_registry.ccmp64_btf_id = 77;
        ctx
    }

    #[test]
    fn ccmp_payload_roundtrips_canonical_encoding() {
        let payload = CcmpPayload {
            dst_reg: BPF_REG_0,
            fail_mode: CcmpFailMode::EqZero,
            width: CcmpWidth::Bpf64,
            regs: vec![BPF_REG_1, BPF_REG_2, BPF_REG_3],
        };

        let encoded = encode_ccmp_payload(&payload).unwrap();
        assert_eq!(decode_ccmp_payload(encoded).unwrap(), payload);
    }

    #[test]
    fn ccmp_payload_rejects_dst_alias() {
        let err = encode_ccmp_payload(&CcmpPayload {
            dst_reg: BPF_REG_1,
            fail_mode: CcmpFailMode::EqZero,
            width: CcmpWidth::Bpf64,
            regs: vec![BPF_REG_1, BPF_REG_2],
        })
        .unwrap_err();

        assert!(err.to_string().contains("aliases"));
    }

    #[test]
    fn scan_ccmp_chain_detects_three_term_nez_guard() {
        let insns = vec![
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 2),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            exit_insn(),
        ];

        let sites = scan_ccmp_sites(&insns);

        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].old_len, 3);
        assert_eq!(sites[0].target_pc, 4);
        assert_eq!(sites[0].fail_mode, CcmpFailMode::EqZero);
        assert_eq!(sites[0].regs, vec![BPF_REG_1, BPF_REG_2, BPF_REG_3]);
    }

    #[test]
    fn scan_ccmp_chain_rejects_mixed_fail_polarity_boundary() {
        let insns = vec![
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
            jmp_zero(BPF_JNE, BPF_JMP, BPF_REG_2, 2),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            exit_insn(),
        ];

        assert!(scan_ccmp_sites(&insns).is_empty());
    }

    #[test]
    fn ccmp_pass_arch_gate_skips_x86_64() {
        let mut program = BpfProgram::new(vec![
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 2),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            exit_insn(),
        ]);
        let pass = CcmpPass;
        let result = pass
            .run(
                &mut program,
                &mut AnalysisCache::new(),
                &ccmp_ctx(Arch::X86_64),
            )
            .unwrap();

        assert!(!result.changed);
        assert!(result.sites_skipped[0].reason.contains("aarch64"));
    }

    #[test]
    fn ccmp_pass_emits_kinsn_and_final_branch_on_aarch64() {
        let mut program = BpfProgram::new(vec![
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 2),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 0),
            exit_insn(),
        ]);
        let pass = CcmpPass;
        let result = pass
            .run(
                &mut program,
                &mut AnalysisCache::new(),
                &ccmp_ctx(Arch::Aarch64),
            )
            .unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert!(program.insns[0].is_kinsn_sidecar());
        assert_eq!(program.insns[1].src_reg(), BPF_PSEUDO_KINSN_CALL);
        assert_eq!(program.insns[1].imm, 77);
        assert_eq!(program.insns[2].code, BPF_JMP | BPF_JEQ | BPF_K);
        assert_eq!(program.insns[2].dst_reg(), BPF_REG_0);
        assert_eq!(program.insns[2].off, 1);

        let decoded = decode_ccmp_payload(sidecar_payload(&program.insns[0])).unwrap();
        assert_eq!(decoded.regs, vec![BPF_REG_1, BPF_REG_2, BPF_REG_3]);
        assert_eq!(decoded.fail_mode, CcmpFailMode::EqZero);
    }

    #[test]
    fn ccmp_pass_skips_overlong_chain_without_partial_rewrite() {
        let mut program = BpfProgram::new(vec![
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 5),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 4),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_3, 3),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_4, 2),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_5, 1),
            BpfInsn::mov64_imm(BPF_REG_0, 1),
            exit_insn(),
        ]);
        let pass = CcmpPass;
        let result = pass
            .run(
                &mut program,
                &mut AnalysisCache::new(),
                &ccmp_ctx(Arch::Aarch64),
            )
            .unwrap();

        assert!(!result.changed);
        assert!(result.sites_skipped[0].reason.contains("exceeds maximum"));
        assert_eq!(program.insns[0].code, BPF_JMP | BPF_JEQ | BPF_K);
    }

    #[test]
    fn ccmp_pass_skips_site_crossing_subprog_boundary() {
        let mut program = BpfProgram::new(vec![
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_1, 3),
            jmp_zero(BPF_JEQ, BPF_JMP, BPF_REG_2, 2),
            exit_insn(),
            BpfInsn::new(
                BPF_JMP | BPF_CALL,
                BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
                0,
                -2,
            ),
            exit_insn(),
        ]);
        let pass = CcmpPass;
        let result = pass
            .run(
                &mut program,
                &mut AnalysisCache::new(),
                &ccmp_ctx(Arch::Aarch64),
            )
            .unwrap();

        assert!(!result.changed);
        assert!(result.sites_skipped[0].reason.contains("subprog boundary"));
    }
}
