// SPDX-License-Identifier: MIT
//! ARM64 CCMP optimization pass.

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::rewrite::{BtfRemapPolicy, RewritePlan};
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[KinsnDescriptor {
    canonical_name: "bpf_ccmp64",
    aliases: &["ccmp64"],
    decode_proof: decode_ccmp_proof,
}];

const MIN_CCMP_TERMS: usize = 2;
const MAX_CCMP_TERMS: usize = 4;
const CCMP_REPLACEMENT_LEN: usize = 3;

fn decode_ccmp_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(ccmp_proof_len))
}

fn ccmp_proof_len(payload: u64) -> anyhow::Result<usize> {
    let dst_reg = kinsn_payload_reg(payload, 0);
    let count_bits = ((payload >> 4) & 0x3) as u8;
    let count = usize::from(count_bits) + 2;
    let mode = (payload >> 6) & 0x1;

    if payload >> 24 != 0 {
        anyhow::bail!("ccmp payload has non-zero reserved bits");
    }
    if count_bits > 2 {
        anyhow::bail!("ccmp count {} exceeds maximum 4", count);
    }
    if dst_reg > BPF_REG_9 {
        anyhow::bail!("ccmp dst register {dst_reg} is outside BPF_REG_0..BPF_REG_9");
    }
    if mode > 1 {
        anyhow::bail!("ccmp mode {mode} is invalid");
    }

    for idx in 0..4 {
        let reg = kinsn_payload_reg(payload, (8 + idx * 4) as u8);
        if idx >= count {
            if reg != 0 {
                anyhow::bail!("ccmp unused register slot {idx} is non-zero");
            }
            continue;
        }
        validate_bpf_reg("ccmp compare", reg)?;
        if reg == dst_reg {
            anyhow::bail!("ccmp dst register aliases compare operand r{reg}");
        }
    }

    Ok(count + 2)
}

/// CCMP pass: folds same-target zero-test short-circuit AND chains into an
/// ARM64-only conditional-compare kinsn plus one final branch.
pub struct CcmpPass;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(super) enum CcmpFailMode {
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
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(super) enum CcmpWidth {
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
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub(super) struct CcmpPayload {
    pub(super) dst_reg: u8,
    pub(super) fail_mode: CcmpFailMode,
    pub(super) width: CcmpWidth,
    pub(super) regs: Vec<u8>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub(super) struct CcmpSite {
    pub(super) start_pc: usize,
    pub(super) old_len: usize,
    pub(super) target_pc: usize,
    pub(super) fail_mode: CcmpFailMode,
    pub(super) width: CcmpWidth,
    pub(super) regs: Vec<u8>,
}

struct SafeCcmpSite {
    site: CcmpSite,
    dst_reg: u8,
    payload: u64,
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

        if !ctx.kinsn_registry.is_target_available("bpf_ccmp64") {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_ccmp64 kfunc not available".into(),
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

        let btf_id = ctx.kinsn_registry.btf_id_for_target_name("bpf_ccmp64")?;
        let kfunc_off = ctx
            .kinsn_registry
            .call_off_for_target_name("bpf_ccmp64")?;
        let mut plan = RewritePlan::new();
        for safe_site in &safe_sites {
            let mut replacement =
                emit_packed_kinsn_call_with_off(safe_site.payload, btf_id, kfunc_off);
            let branch_idx = replacement.len();
            replacement.push(BpfInsn::new(
                BPF_JMP | BPF_JEQ | BPF_K,
                BpfInsn::make_regs(safe_site.dst_reg, 0),
                0,
                0,
            ));
            plan.replace_range(safe_site.site.start_pc, safe_site.site.old_len, replacement)?;
            plan.add_internal_branch(
                safe_site.site.start_pc,
                branch_idx,
                safe_site.site.target_pc,
            );
        }

        let mut result = plan.commit(program, BtfRemapPolicy::RemapKinsn(&ctx.kinsn_registry))?;
        result.pass_name = self.name().into();
        result.sites_applied = safe_sites.len();
        result.sites_skipped = skipped;
        Ok(result)
    }
}

pub(super) fn scan_ccmp_sites(insns: &[BpfInsn]) -> Vec<CcmpSite> {
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

pub(super) fn encode_ccmp_payload(payload: &CcmpPayload) -> anyhow::Result<u64> {
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
