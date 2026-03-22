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

            // Safety check 2: tmp_reg live-out check.
            // The original code destroys tmp_reg via the shift. After rewrite,
            // tmp_reg is not written at all. If tmp_reg is live after the site,
            // the rewrite would change semantics.
            let site_end = site.start_pc + site.old_len;
            if site_end > 0 && site_end - 1 < liveness.live_out.len() {
                let live_after = &liveness.live_out[site_end - 1];
                if live_after.contains(&site.tmp_reg) {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason: format!("tmp_reg r{} is live after site", site.tmp_reg),
                    });
                    continue;
                }

                // Safety check 3: caller-saved register conflict.
                // A kfunc call clobbers r1-r5. If any of those are live after
                // the site (excluding the value register), we cannot safely transform.
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

        // Record module FDs needed for the kfunc calls we emitted.
        if applied > 0 {
            if let Some(fd) = ctx.kfunc_registry.module_fd {
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
            diagnostics: vec![],
        })
    }
}

struct RotateSite {
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    val_reg: u8,
    tmp_reg: u8,
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

        if let Some(site) = try_match_rotate(insns, i0, i1, i2, pc) {
            let end = site.start_pc + site.old_len;
            sites.push(site);
            pc = end;
        } else {
            pc += 1;
        }
    }

    sites
}

/// Scan backwards from `pc` to find `MOV tmp, dst` proving provenance.
/// Returns the PC of the MOV instruction and the updated start_pc/old_len.
fn find_provenance_mov(insns: &[BpfInsn], shift_pc: usize, tmp: u8, dst: u8) -> Option<usize> {
    // Look back up to 8 instructions for the MOV tmp, dst.
    let search_start = if shift_pc >= 8 { shift_pc - 8 } else { 0 };
    for check_pc in (search_start..shift_pc).rev() {
        let insn = &insns[check_pc];
        // Must be MOV64_REG tmp, dst
        if insn.code == (BPF_ALU64 | BPF_MOV | BPF_X) && insn.dst_reg() == tmp && insn.src_reg() == dst {
            return Some(check_pc);
        }
        // If tmp is written by any other instruction, the chain is broken.
        let class = bpf_class(insn.code);
        match class {
            BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD => {
                if insn.dst_reg() == tmp {
                    return None; // tmp was overwritten by something else
                }
            }
            BPF_JMP | BPF_JMP32 => {
                if insn.is_call() {
                    // call clobbers r0-r5
                    if tmp <= 5 {
                        return None;
                    }
                }
                // Any branch means we can't trace linearly
                if insn.is_cond_jmp() || insn.is_ja() {
                    return None;
                }
            }
            _ => {}
        }
    }
    None
}

fn try_match_rotate(
    insns: &[BpfInsn],
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

            if i2.dst_reg() == dst && i2.src_reg() == tmp && dst != tmp {
                // Verify provenance: there must be a MOV tmp, dst before the RSH.
                let mov_pc = find_provenance_mov(insns, pc, tmp, dst)?;
                return Some(RotateSite {
                    start_pc: mov_pc,
                    old_len: (pc + 3) - mov_pc,
                    dst_reg: dst,
                    val_reg: dst,
                    tmp_reg: tmp,
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

            if i2.dst_reg() == dst && i2.src_reg() == tmp && dst != tmp {
                // Verify provenance: there must be a MOV tmp, dst before the LSH.
                let mov_pc = find_provenance_mov(insns, pc, tmp, dst)?;
                return Some(RotateSite {
                    start_pc: mov_pc,
                    old_len: (pc + 3) - mov_pc,
                    dst_reg: dst,
                    val_reg: dst,
                    tmp_reg: tmp,
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
        // Now requires MOV tmp, dst before the shift pattern.
        let insns = vec![
            BpfInsn::mov64_reg(3, 2),           // MOV r3, r2 (provenance)
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 0); // includes the MOV
        assert_eq!(sites[0].old_len, 4);
        assert_eq!(sites[0].shift_amount, 8);
        assert_eq!(sites[0].dst_reg, 2);
        assert_eq!(sites[0].tmp_reg, 3);
    }

    #[test]
    fn test_rotate_pass_pattern_b_match() {
        let insns = vec![
            BpfInsn::mov64_reg(3, 2),           // provenance
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
            BpfInsn::mov64_reg(3, 2),
            BpfInsn::alu64_imm(BPF_RSH, 2, 20),
            BpfInsn::alu64_imm(BPF_LSH, 3, 20),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_rotate_pass_no_match_without_provenance() {
        // Without the MOV tmp, dst, no match should occur.
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert!(sites.is_empty(), "should not match without provenance MOV");
    }

    #[test]
    fn test_rotate_pass_no_match_wrong_provenance() {
        // MOV r3, r4 instead of MOV r3, r2 -- wrong source
        let insns = vec![
            BpfInsn::mov64_reg(3, 4),  // wrong: copies from r4, not r2
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert!(sites.is_empty(), "should not match with wrong provenance");
    }

    #[test]
    fn test_rotate_pass_emit_kfunc_call() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_reg(3, 2),           // provenance
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
            BpfInsn::mov64_reg(3, 2),
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
    }

    #[test]
    fn test_rotate_pass_caller_saved_conflict() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),
            BpfInsn::mov64_reg(4, 2),           // provenance for tmp=r4
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 4, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 4),
            BpfInsn::mov64_reg(0, 3),           // r3 is live after site
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
    fn test_rotate_pass_tmp_live_out_conflict() {
        // tmp_reg (r6, callee-saved) is live after the site -- should skip.
        let mut prog = make_program(vec![
            BpfInsn::mov64_reg(6, 2),           // provenance
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 6, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 6),
            BpfInsn::mov64_reg(0, 6),           // r6 is used after site
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_rotate_kfunc(9999);

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed, "should skip when tmp_reg is live after site");
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("tmp_reg")));
    }

    #[test]
    fn test_rotate_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(RotatePass);

        let mut prog = make_program(vec![
            BpfInsn::mov64_reg(3, 2),           // provenance
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
