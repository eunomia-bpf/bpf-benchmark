// SPDX-License-Identifier: MIT
//! EXTRACT optimization pass.

use crate::analysis::BranchTargetAnalysis;
use crate::insn::*;
use crate::pass::*;

use super::utils::{
    emit_packed_kinsn_call_with_off, fixup_all_branches, kinsn_replacement_subprog_skip_reason,
    map_replacement_range, remap_kinsn_btf_metadata, resolve_kinsn_call_off_for_pass,
};

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
    let mut sites = Vec::new();
    let n = insns.len();
    let mut pc = 0;

    while pc + 1 < n {
        let i0 = &insns[pc];
        let i1 = &insns[pc + 1];

        // RSH64_IMM dst, shift
        let is_rsh = i0.code == (BPF_ALU64 | BPF_RSH | BPF_K);
        // AND64_IMM dst, mask
        let is_and = i1.code == (BPF_ALU64 | BPF_AND | BPF_K);

        if is_rsh && is_and && i0.dst_reg() == i1.dst_reg() {
            let shift = i0.imm as u32;
            // AND immediate is sign-extended from i32 to 64-bit ALU semantics.
            let mask = i1.imm as i64 as u64;

            if let Some(bit_len) = contiguous_mask_len(mask) {
                // Ensure the extraction is within 64 bits.
                if shift + bit_len <= 64 {
                    sites.push(ExtractSite {
                        start_pc: pc,
                        old_len: 2,
                        dst_reg: i0.dst_reg(),
                        shift_amount: shift,
                        bit_len,
                    });
                    pc += 2;
                    continue;
                }
            }
        }

        pc += 1;
    }

    sites
}

impl BpfPass for ExtractPass {
    fn name(&self) -> &str {
        "extract"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // Check if bpf_extract64 kfunc is available.
        if ctx.kinsn_registry.extract64_btf_id < 0 {
            return Ok(PassResult::skipped(
                self.name(),
                SkipReason {
                    pc: 0,
                    reason: "bpf_extract64 kfunc not available".into(),
                },
            ));
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);

        let sites = scan_extract_sites(&program.insns);
        let btf_id = ctx.kinsn_registry.extract64_btf_id;
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
                ..PassResult::unchanged(self.name())
            });
        }

        let kfunc_off = resolve_kinsn_call_off_for_pass(ctx, self.name())?;

        // Build replacement instruction stream.
        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0;
        let mut site_idx = 0;
        let mut applied = 0;

        while pc < orig_len {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].site.start_pc {
                let safe_site = &safe_sites[site_idx];
                let site = &safe_site.site;

                let payload = (site.dst_reg as u64)
                    | ((site.shift_amount as u64) << 8)
                    | ((site.bit_len as u64) << 16);
                let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
                new_insns.extend_from_slice(&replacement);
                map_replacement_range(&mut addr_map, pc, site.old_len, new_pc, replacement.len());

                pc += site.old_len;
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

        // Branch fixup.
        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        remap_kinsn_btf_metadata(program, &ctx.kinsn_registry)?;
        program.remap_annotations(&addr_map);

        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
            ..Default::default()
        })
    }
}
