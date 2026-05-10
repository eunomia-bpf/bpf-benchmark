// SPDX-License-Identifier: MIT
//! EXTRACT optimization pass.

use crate::analysis::{iter_sites, BranchTargetAnalysis};
use crate::insn::*;
use crate::pass::*;

use crate::rewrite::{BtfRemapPolicy, RewritePlan};
pub(super) const KINSN_TARGETS: &[KinsnDescriptor] = &[KinsnDescriptor {
    canonical_name: "bpf_extract64",
    aliases: &["extract64"],
    decode_proof: decode_extract_proof,
    register_uses: extract_register_uses,
}];

fn decode_extract_proof(payload: &[u8]) -> ProofRegion {
    ProofRegion::from_result(decode_packed_kinsn_payload(payload).and_then(extract_proof_len))
}

fn extract_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("extract dst", kinsn_payload_reg(payload, 0))?;
    let start = kinsn_payload_u8(payload, 8);
    let bit_len = kinsn_payload_u8(payload, 16);
    if start >= 64 || bit_len == 0 || bit_len > 32 || u16::from(start) + u16::from(bit_len) > 64 {
        anyhow::bail!("extract payload has invalid range start={start} bit_len={bit_len}");
    }
    Ok(usize::from(start != 0) + 1)
}

fn extract_register_uses(payload: u64) -> RegSet {
    [kinsn_payload_reg(payload, 0)].into_iter().collect()
}

/// EXTRACT optimization pass: replaces RSH+AND bitfield extraction patterns
/// with bpf_extract64() kfunc calls.
///
/// Pattern:
///   RSH64_IMM dst, shift
///   AND64_IMM dst, mask
///
/// Where `mask` is a contiguous bitmask (all 1s), i.e. `(1 << len) - 1`.
///
/// Replacement:
///   r1 = dst (value)
///   r2 = start (shift amount)
///   r3 = len (popcount of mask)
///   call bpf_extract64
///   dst = r0
pub struct ExtractPass;

pub(super) struct ExtractSite {
    pub(super) start_pc: usize,
    pub(super) old_len: usize,
    pub(super) dst_reg: u8,
    pub(super) shift_amount: u32,
    pub(super) bit_len: u32,
}

/// An extract site that has passed safety checks, ready for transformation.
struct SafeExtractSite {
    site: ExtractSite,
}

/// Check if a value is a contiguous bitmask of 1s starting from bit 0.
/// Returns the number of set bits (popcount) if valid, or None.
pub(super) fn contiguous_mask_len(mask: u64) -> Option<u32> {
    if mask == 0 {
        return None;
    }
    // A contiguous mask from bit 0 has the form (1 << n) - 1.
    // Check: mask & (mask + 1) == 0
    if mask & (mask.wrapping_add(1)) == 0 {
        Some(mask.count_ones())
    } else {
        None
    }
}

pub(super) fn scan_extract_sites(insns: &[BpfInsn]) -> Vec<ExtractSite> {
    iter_sites(insns, |insns, pc| {
        extract_site_at(insns, pc).map(|site| site.old_len)
    })
    .into_iter()
    .filter_map(|site| extract_site_at(insns, site.pc))
    .collect()
}

fn extract_site_at(insns: &[BpfInsn], pc: usize) -> Option<ExtractSite> {
    let i0 = insns.get(pc)?;
    let i1 = insns.get(pc + 1)?;
    let is_rsh = i0.code == (BPF_ALU64 | BPF_RSH | BPF_K);
    let is_and = i1.code == (BPF_ALU64 | BPF_AND | BPF_K);
    if !is_rsh || !is_and || i0.dst_reg() != i1.dst_reg() {
        return None;
    }
    let shift = i0.imm as u32;
    let mask = i1.imm as i64 as u64;
    let bit_len = contiguous_mask_len(mask)?;
    (shift + bit_len <= 64).then_some(ExtractSite {
        start_pc: pc,
        old_len: 2,
        dst_reg: i0.dst_reg(),
        shift_amount: shift,
        bit_len,
    })
}

impl BpfPass for ExtractPass {
    fn name(&self) -> &str {
        "extract"
    }
    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let bt = analyses.get::<BranchTargetAnalysis>(program);

        let sites = scan_extract_sites(&program.insns);
        let btf_id = ctx.kinsn_registry.btf_id_for_target_name("bpf_extract64")?;
        let mut safe_sites: Vec<SafeExtractSite> = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            // Safety check 1: interior branch target.
            let has_interior = (site.start_pc + 1..site.start_pc + site.old_len)
                .any(|pc| pc < bt.is_target.len() && bt.is_target[pc]);
            if has_interior {
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
                2,
            )? {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason,
                });
                continue;
            }

            safe_sites.push(SafeExtractSite { site });
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                sites_skipped: skipped,
                ..PassResult::unchanged()
            });
        }

        let kfunc_off = ctx
            .kinsn_registry
            .call_off_for_target_name("bpf_extract64")?;

        let mut plan = RewritePlan::new();
        for safe_site in &safe_sites {
            let site = &safe_site.site;
            let shift_amount = u8::try_from(site.shift_amount).map_err(|_| {
                anyhow::anyhow!(
                    "extract shift amount {} exceeds packed payload width",
                    site.shift_amount
                )
            })?;
            let bit_len = u8::try_from(site.bit_len).map_err(|_| {
                anyhow::anyhow!(
                    "extract bit length {} exceeds packed payload width",
                    site.bit_len
                )
            })?;
            let payload = BpfInsn::pack_u4(site.dst_reg, 0)
                | BpfInsn::pack_u8(shift_amount, 8)
                | BpfInsn::pack_u8(bit_len, 16);
            plan.replace_range(
                site.start_pc,
                site.old_len,
                emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off),
            )?;
        }

        let mut result = plan.commit(program, BtfRemapPolicy::RemapKinsn(&ctx.kinsn_registry))?;
        result.sites_applied = safe_sites.len();
        result.sites_skipped = skipped;
        Ok(result)
    }
}
