// SPDX-License-Identifier: MIT
//! EXTRACT optimization pass.

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::utils::{emit_kfunc_call, fixup_all_branches, KfuncArg};

/// EXTRACT optimization pass: replaces RSH+AND bitfield extraction patterns
/// with bpf_extract64() kfunc calls (lowered to BEXTR by the JIT).
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

struct ExtractSite {
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    shift_amount: u32,
    bit_len: u32,
}

/// Check if a value is a contiguous bitmask of 1s starting from bit 0.
/// Returns the number of set bits (popcount) if valid, or None.
fn contiguous_mask_len(mask: u64) -> Option<u32> {
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

fn scan_extract_sites(insns: &[BpfInsn]) -> Vec<ExtractSite> {
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
            // AND immediate is sign-extended from i32 to u64 in BPF.
            // For our purposes, interpret the mask as u64.
            let mask = i1.imm as u32 as u64;

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

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
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
        // Check if platform has BMI1 (BEXTR) support.
        if !ctx.platform.has_bmi1 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "platform lacks BMI1 (BEXTR) support".into(),
                }],
                diagnostics: vec![],
            ..Default::default() });
        }

        // Check if bpf_extract64 kfunc is available.
        if ctx.kfunc_registry.extract64_btf_id < 0 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "bpf_extract64 kfunc not available".into(),
                }],
                diagnostics: vec![],
            ..Default::default() });
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = scan_extract_sites(&program.insns);
        let btf_id = ctx.kfunc_registry.extract64_btf_id;
        let mut safe_sites = Vec::new();
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

            // Safety check 2: caller-saved register conflict.
            let site_end = site.start_pc + site.old_len;
            if site_end > 0 && site_end - 1 < liveness.live_out.len() {
                let live_after = &liveness.live_out[site_end - 1];
                let caller_saved_conflict = (1u8..=5)
                    .any(|r| r != site.dst_reg && live_after.contains(&r));
                if caller_saved_conflict {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason: "caller-saved register conflict".into(),
                    });
                    continue;
                }
            }

            safe_sites.push(site);
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![], ..Default::default() });
        }

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

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].start_pc {
                let site = &safe_sites[site_idx];

                // Emit kfunc call: bpf_extract64(val, start, len)
                let replacement = emit_kfunc_call(
                    site.dst_reg,
                    &[
                        KfuncArg::Reg(site.dst_reg),
                        KfuncArg::Imm(site.shift_amount as i32),
                        KfuncArg::Imm(site.bit_len as i32),
                    ],
                    btf_id,
                );
                new_insns.extend_from_slice(&replacement);

                // Map old PCs in the site range.
                for j in 1..site.old_len {
                    addr_map[pc + j] = new_pc;
                }

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
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry {
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(),
            details: vec![],
        });

        // Record module FDs needed for the kfunc calls we emitted.
        if applied > 0 {
            if let Some(fd) = ctx.kfunc_registry.module_fd_for_pass(self.name()) {
                if !program.required_module_fds.contains(&fd) {
                    program.required_module_fds.push(fd);
                }
            }
        }

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![], ..Default::default() })
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
    use crate::pass::{AnalysisCache, PassContext, PassManager};

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns, ProgMeta::default())
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn { code: BPF_JMP | BPF_EXIT, regs: 0, off: 0, imm: 0 }
    }

    fn ctx_with_extract_kfunc(btf_id: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kfunc_registry.extract64_btf_id = btf_id;
        ctx.platform.has_bmi1 = true;
        ctx
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    // ── contiguous_mask_len tests ──────────────────────────────────

    #[test]
    fn test_contiguous_mask_len() {
        assert_eq!(contiguous_mask_len(0), None);
        assert_eq!(contiguous_mask_len(0x1), Some(1));
        assert_eq!(contiguous_mask_len(0x3), Some(2));
        assert_eq!(contiguous_mask_len(0x7), Some(3));
        assert_eq!(contiguous_mask_len(0xf), Some(4));
        assert_eq!(contiguous_mask_len(0xff), Some(8));
        assert_eq!(contiguous_mask_len(0xffff), Some(16));
        assert_eq!(contiguous_mask_len(0xffffffff), Some(32));
        // Non-contiguous masks
        assert_eq!(contiguous_mask_len(0x5), None);  // 101
        assert_eq!(contiguous_mask_len(0xa), None);  // 1010
        assert_eq!(contiguous_mask_len(0x101), None); // 100000001
        // Additional edge cases
        assert_eq!(contiguous_mask_len(0x1f), Some(5));   // 11111
        assert_eq!(contiguous_mask_len(0x3f), Some(6));   // 111111
        assert_eq!(contiguous_mask_len(0x7f), Some(7));   // 1111111
        assert_eq!(contiguous_mask_len(0x1ff), Some(9));  // 9 bits
        assert_eq!(contiguous_mask_len(0xffffff), Some(24));
        // Non-contiguous: gaps in the middle
        assert_eq!(contiguous_mask_len(0x6), None);   // 110 — not from bit 0
        assert_eq!(contiguous_mask_len(0xfe), None);  // 11111110 — not from bit 0
        assert_eq!(contiguous_mask_len(0x10), None);  // single bit not at 0
        assert_eq!(contiguous_mask_len(0x80), None);  // single high bit
    }

    // ── Pattern scanning tests ─────────────────────────────────────

    #[test]
    fn test_scan_extract_basic() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),   // RSH r2, 8
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff), // AND r2, 0xff
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].old_len, 2);
        assert_eq!(sites[0].dst_reg, 2);
        assert_eq!(sites[0].shift_amount, 8);
        assert_eq!(sites[0].bit_len, 8);
    }

    #[test]
    fn test_scan_extract_16bit_mask() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 3, 16),     // RSH r3, 16
            BpfInsn::alu64_imm(BPF_AND, 3, 0xffff),  // AND r3, 0xffff
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].shift_amount, 16);
        assert_eq!(sites[0].bit_len, 16);
    }

    #[test]
    fn test_scan_extract_no_match_non_contiguous_mask() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0x5), // 0b101 - not contiguous
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_scan_extract_no_match_different_regs() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 3, 0xff), // different dst reg
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_scan_extract_multiple_sites() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            BpfInsn::alu64_imm(BPF_RSH, 3, 16),
            BpfInsn::alu64_imm(BPF_AND, 3, 0xf),
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert_eq!(sites.len(), 2);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].bit_len, 8);
        assert_eq!(sites[1].start_pc, 2);
        assert_eq!(sites[1].bit_len, 4);
    }

    #[test]
    fn test_scan_extract_zero_mask() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0), // mask = 0
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert!(sites.is_empty());
    }

    // ── Pass execution tests ───────────────────────────────────────

    #[test]
    fn test_extract_pass_skip_when_kfunc_unavailable() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let mut ctx = PassContext::test_default(); // extract64_btf_id = -1
        ctx.platform.has_bmi1 = true; // platform has BMI1, but kfunc is missing

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped[0].reason.contains("kfunc not available"));
    }

    #[test]
    fn test_extract_pass_emit_kfunc_call() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);

        // Verify a kfunc call exists.
        let has_kfunc_call = prog.insns.iter().any(|i| i.is_call() && i.src_reg() == 2);
        assert!(has_kfunc_call, "expected a kfunc call in the output");
        let call_insn = prog.insns.iter().find(|i| i.is_call() && i.src_reg() == 2).unwrap();
        assert_eq!(call_insn.imm, 7777);

        // Verify the last instruction is still EXIT.
        assert!(prog.insns.last().unwrap().is_exit());
    }

    #[test]
    fn test_extract_pass_caller_saved_conflict() {
        // r3 is live after the site (used in a later mov), so the pass
        // should skip since kfunc call clobbers r1-r5.
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),            // r3 = 99
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            BpfInsn::mov64_reg(0, 3),              // uses r3 after site
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("caller-saved")));
    }

    #[test]
    fn test_extract_pass_interior_branch_target() {
        // A branch targets the AND instruction inside the site.
        let mut prog = make_program(vec![
            jeq_imm(5, 0, 1),                      // if r5 == 0, jump to pc=2 (the AND)
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),     // pc=1
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),  // pc=2 -- branch target
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("interior branch")));
    }

    #[test]
    fn test_extract_pass_branch_fixup() {
        // Branch over a 2-insn extract site. After rewrite the site becomes
        // longer (kfunc call sequence), so branch offsets must be adjusted.
        let mut prog = make_program(vec![
            jeq_imm(5, 0, 2),                      // if r5==0, skip 2 insns to exit
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),     // pc=1: site start
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),  // pc=2: site end
            exit_insn(),                             // pc=3: branch target
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        // The branch at pc=0 should still reach the EXIT instruction.
        let last_pc = prog.insns.len() - 1;
        assert!(prog.insns[last_pc].is_exit());
        // The branch offset should be adjusted to skip the expanded kfunc sequence.
        let branch_target = (0i64 + 1 + prog.insns[0].off as i64) as usize;
        assert_eq!(branch_target, last_pc);
    }

    #[test]
    fn test_extract_pass_records_module_fd() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let mut ctx = ctx_with_extract_kfunc(7777);
        ctx.kfunc_registry.module_fd = Some(42);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert!(prog.required_module_fds.contains(&42));
    }

    #[test]
    fn test_extract_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(ExtractPass);

        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            exit_insn(),
        ]);
        let ctx = ctx_with_extract_kfunc(1234);

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
    }

    #[test]
    fn test_extract_pass_no_sites() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
    }

    // ── Edge case: width=1 (mask=1) ───────────────────────────────────

    #[test]
    fn test_scan_extract_width_1() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 4, 3),  // RSH r4, 3
            BpfInsn::alu64_imm(BPF_AND, 4, 0x1), // AND r4, 1 (width=1)
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].shift_amount, 3);
        assert_eq!(sites[0].bit_len, 1);
    }

    #[test]
    fn test_extract_pass_width_1() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 4, 3),
            BpfInsn::alu64_imm(BPF_AND, 4, 0x1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // Verify kfunc call with correct btf_id.
        let call = prog.insns.iter().find(|i| i.is_call() && i.src_reg() == 2).unwrap();
        assert_eq!(call.imm, 7777);
        assert!(prog.insns.last().unwrap().is_exit());
    }

    // ── Edge case: width=32 (mask=0xFFFFFFFF) ─────────────────────────

    #[test]
    fn test_scan_extract_width_32() {
        // 0xFFFFFFFF as i32 is -1.
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 16),
            BpfInsn::alu64_imm(BPF_AND, 2, -1), // mask = 0xFFFFFFFF → width=32
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].shift_amount, 16);
        assert_eq!(sites[0].bit_len, 32);
    }

    #[test]
    fn test_extract_pass_width_32() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 16),
            BpfInsn::alu64_imm(BPF_AND, 2, -1), // mask = 0xFFFFFFFF
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        let call = prog.insns.iter().find(|i| i.is_call() && i.src_reg() == 2).unwrap();
        assert_eq!(call.imm, 7777);
    }

    #[test]
    fn test_scan_extract_width_32_shift_too_large() {
        // shift=33 + width=32 = 65 > 64, should not match.
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 33),
            BpfInsn::alu64_imm(BPF_AND, 2, -1), // mask = 0xFFFFFFFF → width=32
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert!(sites.is_empty());
    }

    // ── Edge case: shift=0 ────────────────────────────────────────────

    #[test]
    fn test_scan_extract_shift_0() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 5, 0),    // RSH r5, 0 (no-op shift)
            BpfInsn::alu64_imm(BPF_AND, 5, 0xff),  // AND r5, 0xff
            exit_insn(),
        ];
        let sites = scan_extract_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].shift_amount, 0);
        assert_eq!(sites[0].bit_len, 8);
    }

    #[test]
    fn test_extract_pass_shift_0() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 5, 0),
            BpfInsn::alu64_imm(BPF_AND, 5, 0xff),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
    }

    // ── Edge case: two consecutive extract patterns (full pass) ───────

    #[test]
    fn test_extract_pass_two_consecutive_sites() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 6, 8),
            BpfInsn::alu64_imm(BPF_AND, 6, 0xff),
            BpfInsn::alu64_imm(BPF_RSH, 7, 16),
            BpfInsn::alu64_imm(BPF_AND, 7, 0xf),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 2);
        // Verify two kfunc calls exist.
        let call_count = prog.insns.iter()
            .filter(|i| i.is_call() && i.src_reg() == 2 && i.imm == 7777)
            .count();
        assert_eq!(call_count, 2);
        assert!(prog.insns.last().unwrap().is_exit());
    }

    // ── Edge case: rsh+and but mask is NOT (1<<n)-1 ───────────────────

    #[test]
    fn test_scan_extract_non_power_of_two_minus_one_masks() {
        // Mask = 0x6 = 0b110 — not contiguous from bit 0.
        let insns_a = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 4),
            BpfInsn::alu64_imm(BPF_AND, 2, 0x6),
            exit_insn(),
        ];
        assert!(scan_extract_sites(&insns_a).is_empty());

        // Mask = 0x10 = 0b10000 — single bit, not at position 0.
        let insns_b = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 4),
            BpfInsn::alu64_imm(BPF_AND, 2, 0x10),
            exit_insn(),
        ];
        assert!(scan_extract_sites(&insns_b).is_empty());

        // Mask = 0xfe = 0b11111110 — contiguous but not from bit 0.
        let insns_c = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 4),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xfe_u32 as i32),
            exit_insn(),
        ];
        assert!(scan_extract_sites(&insns_c).is_empty());

        // Mask = 0x80 = 0b10000000 — single high bit.
        let insns_d = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 4),
            BpfInsn::alu64_imm(BPF_AND, 2, 0x80),
            exit_insn(),
        ];
        assert!(scan_extract_sites(&insns_d).is_empty());
    }

    #[test]
    fn test_extract_pass_dst_is_r0() {
        // When dst_reg is r0, no trailing MOV should be emitted (result is
        // already in r0 after the call).
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 0, 4),
            BpfInsn::alu64_imm(BPF_AND, 0, 0xf),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_extract_kfunc(7777);

        let pass = ExtractPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // Count: should not have a trailing MOV r0, r0.
        let mov_r0_r0_count = prog.insns.iter().filter(|i| {
            i.code == (BPF_ALU64 | BPF_MOV | BPF_X) && i.dst_reg() == 0 && i.src_reg() == 0
        }).count();
        assert_eq!(mov_r0_r0_count, 0, "should not emit redundant MOV r0, r0");
    }
}
