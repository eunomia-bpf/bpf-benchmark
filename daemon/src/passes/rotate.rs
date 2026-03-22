// SPDX-License-Identifier: MIT
//! ROTATE optimization pass.

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::fixup_branches_inline;

/// ROTATE optimization pass: replaces shift+OR rotate patterns with
/// bpf_rotate64() kfunc calls. JIT inlines the kfunc as a RORX instruction.
pub struct RotatePass;

impl BpfPass for RotatePass {
    fn name(&self) -> &str {
        "rotate"
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
        // Prerequisite: check if bpf_rotate64 kfunc is available.
        if ctx.kfunc_registry.rotate64_btf_id < 0 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "bpf_rotate64 kfunc not available".into(),
                }],
                diagnostics: vec![],
            });
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = scan_rotate_sites(&program.insns);
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();
        let btf_id = ctx.kfunc_registry.rotate64_btf_id;

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
            // A kfunc call clobbers r1-r5. If any of those are live after
            // the site (excluding the value register), we cannot safely transform.
            let site_end = site.start_pc + site.old_len;
            if site_end > 0 && site_end - 1 < liveness.live_out.len() {
                let live_after = &liveness.live_out[site_end - 1];
                let caller_saved_conflict = (1u8..=5)
                    .any(|r| r != site.val_reg && live_after.contains(&r));
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
                diagnostics: vec![],
            });
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
                // Emit: r1 = val_reg, r2 = shift, call kfunc, dst = r0.
                if site.val_reg != 1 {
                    new_insns.push(BpfInsn::mov64_reg(1, site.val_reg));
                }
                new_insns.push(BpfInsn::mov64_imm(2, site.shift_amount as i32));
                new_insns.push(BpfInsn::call_kfunc(btf_id));
                if site.dst_reg != 0 {
                    new_insns.push(BpfInsn::mov64_reg(site.dst_reg, 0));
                }

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
        fixup_branches_inline(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        program.log_transform(TransformEntry {
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(),
            details: vec![],
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
        })
    }
}

struct RotateSite {
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    val_reg: u8,
    shift_amount: u32,
}

fn scan_rotate_sites(insns: &[BpfInsn]) -> Vec<RotateSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    let mut pc = 0;

    while pc + 2 < n {
        let i0 = &insns[pc];
        let i1 = &insns[pc + 1];
        let i2 = &insns[pc + 2];

        if let Some(site) = try_match_rotate(i0, i1, i2, pc) {
            let len = site.old_len;
            sites.push(site);
            pc += len;
        } else {
            pc += 1;
        }
    }

    sites
}

fn try_match_rotate(
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    pc: usize,
) -> Option<RotateSite> {
    // Pattern A: RSH64_IMM(dst, 64-S) ; LSH64_IMM(tmp, S) ; OR64_REG(dst, tmp)
    let is_rsh = i0.code == (BPF_ALU64 | BPF_RSH | BPF_K);
    let is_lsh = i1.code == (BPF_ALU64 | BPF_LSH | BPF_K);
    let is_or = i2.code == (BPF_ALU64 | BPF_OR | BPF_X);

    if is_rsh && is_lsh && is_or {
        let rsh_amount = i0.imm as u32;
        let lsh_amount = i1.imm as u32;

        if rsh_amount + lsh_amount == 64 {
            let dst = i0.dst_reg();
            let tmp = i1.dst_reg();

            if i2.dst_reg() == dst && i2.src_reg() == tmp {
                return Some(RotateSite {
                    start_pc: pc,
                    old_len: 3,
                    dst_reg: dst,
                    val_reg: dst,
                    shift_amount: lsh_amount,
                });
            }
        }
    }

    // Pattern B: LSH64_IMM(dst, S) ; RSH64_IMM(tmp, 64-S) ; OR64_REG(dst, tmp)
    let is_lsh_first = i0.code == (BPF_ALU64 | BPF_LSH | BPF_K);
    let is_rsh_second = i1.code == (BPF_ALU64 | BPF_RSH | BPF_K);

    if is_lsh_first && is_rsh_second && is_or {
        let lsh_amount = i0.imm as u32;
        let rsh_amount = i1.imm as u32;

        if lsh_amount + rsh_amount == 64 {
            let dst = i0.dst_reg();
            let tmp = i1.dst_reg();

            if i2.dst_reg() == dst && i2.src_reg() == tmp {
                return Some(RotateSite {
                    start_pc: pc,
                    old_len: 3,
                    dst_reg: dst,
                    val_reg: dst,
                    shift_amount: lsh_amount,
                });
            }
        }
    }

    None
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

    fn ctx_with_rotate_kfunc(btf_id: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kfunc_registry.rotate64_btf_id = btf_id;
        ctx
    }

    #[test]
    fn test_rotate_pass_pattern_match() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].old_len, 3);
        assert_eq!(sites[0].shift_amount, 8);
        assert_eq!(sites[0].dst_reg, 2);
    }

    #[test]
    fn test_rotate_pass_pattern_b_match() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_LSH, 2, 16),
            BpfInsn::alu64_imm(BPF_RSH, 3, 48),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].shift_amount, 16);
    }

    #[test]
    fn test_rotate_pass_no_match_wrong_sum() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 20),
            BpfInsn::alu64_imm(BPF_LSH, 3, 20),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_rotate_pass_emit_kfunc_call() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_rotate_kfunc(9999);

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        let has_kfunc_call = prog.insns.iter().any(|i| i.is_call() && i.src_reg() == 2);
        assert!(has_kfunc_call, "expected a kfunc call in the output");
        let call_insn = prog.insns.iter().find(|i| i.is_call() && i.src_reg() == 2).unwrap();
        assert_eq!(call_insn.imm, 9999);
    }

    #[test]
    fn test_rotate_pass_skip_when_kfunc_unavailable() {
        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(!result.sites_skipped.is_empty());
        assert!(result.sites_skipped[0].reason.contains("kfunc not available"));
        assert_eq!(prog.insns.len(), 4);
    }

    #[test]
    fn test_rotate_pass_caller_saved_conflict() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 4, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 4),
            BpfInsn::mov64_reg(0, 3),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_rotate_kfunc(9999);

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        let has_conflict = result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("caller-saved"));
        assert!(
            has_conflict,
            "expected caller-saved conflict skip reason, got: {:?}",
            result.sites_skipped
        );
    }

    #[test]
    fn test_rotate_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(RotatePass);

        let mut prog = make_program(vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            exit_insn(),
        ]);
        let ctx = ctx_with_rotate_kfunc(1234);

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
    }
}
