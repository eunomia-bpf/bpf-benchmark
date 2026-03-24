// SPDX-License-Identifier: MIT
//! ROTATE optimization pass.

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::utils::{emit_packed_kinsn_call_with_off, ensure_module_fd_slot, fixup_all_branches};

/// ROTATE optimization pass: replaces shift+OR rotate patterns with
/// bpf_rotate64() kfunc calls. JIT inlines the kfunc as a native rotate.
pub struct RotatePass;

impl BpfPass for RotatePass {
    fn name(&self) -> &str {
        "rotate"
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
                ..Default::default()
            });
        }

        if !ctx.kfunc_registry.packed_supported_for_pass(self.name()) {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "bpf_rotate64 packed ABI not available".into(),
                }],
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = scan_rotate_sites(&program.insns);
        let mut safe_sites: Vec<SafeRotateSite> = Vec::new();
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

                safe_sites.push(SafeRotateSite { site });
                continue;
            }

            safe_sites.push(SafeRotateSite { site });
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let kfunc_off = ctx
            .kfunc_registry
            .module_fd_for_pass(self.name())
            .map(|fd| ensure_module_fd_slot(program, fd))
            .unwrap_or(0);

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
                // Emit: bpf_rotate64(val_reg, shift_amount) -> dst_reg
                let payload = (site.dst_reg as u64)
                    | ((site.val_reg as u64) << 4)
                    | ((site.shift_amount as u64) << 8)
                    | ((site.tmp_reg as u64) << 16);
                let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
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
        program.log_transform(TransformEntry { sites_applied: applied });

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

struct RotateSite {
    start_pc: usize,
    old_len: usize,
    dst_reg: u8,
    val_reg: u8,
    tmp_reg: u8,
    shift_amount: u32,
}

/// A rotate site that has passed safety checks, ready for transformation.
struct SafeRotateSite {
    site: RotateSite,
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
    let search_start = shift_pc.saturating_sub(8);
    for check_pc in (search_start..shift_pc).rev() {
        let insn = &insns[check_pc];
        // Must be MOV64_REG tmp, dst
        if insn.code == (BPF_ALU64 | BPF_MOV | BPF_X)
            && insn.dst_reg() == tmp
            && insn.src_reg() == dst
        {
            // Found the MOV. Now verify that `dst` is NOT overwritten between
            // (check_pc, shift_pc) -- if dst is written after the MOV, then
            // tmp and dst no longer hold the same value at shift_pc.
            if is_reg_written_in_range(insns, check_pc + 1, shift_pc, dst) {
                return None; // dst was modified after the MOV
            }
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

/// Check if a register `reg` is written (as dst_reg) by any instruction in [start, end).
fn is_reg_written_in_range(insns: &[BpfInsn], start: usize, end: usize, reg: u8) -> bool {
    for pc in start..end {
        if pc >= insns.len() {
            break;
        }
        let insn = &insns[pc];
        let class = bpf_class(insn.code);
        match class {
            BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD => {
                if insn.dst_reg() == reg {
                    return true;
                }
            }
            BPF_JMP | BPF_JMP32 => {
                if insn.is_call() && reg <= 5 {
                    // call clobbers r0-r5
                    return true;
                }
            }
            BPF_ST | BPF_STX => {
                // Store instructions don't write to a register.
            }
            _ => {}
        }
    }
    false
}

fn try_match_rotate(
    insns: &[BpfInsn],
    i0: &BpfInsn,
    i1: &BpfInsn,
    i2: &BpfInsn,
    pc: usize,
) -> Option<RotateSite> {
    let is_or = i2.code == (BPF_ALU64 | BPF_OR | BPF_X);
    if !is_or {
        return None;
    }

    // Pattern A: RSH64_IMM(rA, S_rsh) ; LSH64_IMM(rB, S_lsh) ; OR64_REG(or_dst, or_src)
    // where S_rsh + S_lsh = 64.
    //
    // The two registers rA, rB hold copies of the same original value.
    // One was copied from the other via `MOV tmp, orig` before the shifts.
    // Either register could be the original or the copy — we try both.
    let is_rsh = i0.code == (BPF_ALU64 | BPF_RSH | BPF_K);
    let is_lsh = i1.code == (BPF_ALU64 | BPF_LSH | BPF_K);

    if is_rsh && is_lsh {
        let rsh_amount = i0.imm as u32;
        let lsh_amount = i1.imm as u32;

        if rsh_amount + lsh_amount == 64 {
            let rsh_reg = i0.dst_reg();
            let lsh_reg = i1.dst_reg();
            if rsh_reg != lsh_reg {
                let or_dst = i2.dst_reg();
                let or_src = i2.src_reg();

                // The OR must combine exactly these two registers.
                let or_uses_both = (or_dst == rsh_reg && or_src == lsh_reg)
                    || (or_dst == lsh_reg && or_src == rsh_reg);
                if or_uses_both {
                    let result_reg = or_dst;
                    // Try both provenance directions:
                    // Case 1: rsh_reg is the copy (tmp), lsh_reg is the original (dst)
                    //   => MOV rsh_reg, lsh_reg
                    if let Some(mov_pc) = find_provenance_mov(insns, pc, rsh_reg, lsh_reg) {
                        return Some(RotateSite {
                            start_pc: mov_pc,
                            old_len: (pc + 3) - mov_pc,
                            dst_reg: result_reg,
                            val_reg: lsh_reg,
                            tmp_reg: rsh_reg,
                            shift_amount: lsh_amount,
                        });
                    }
                    // Case 2: lsh_reg is the copy (tmp), rsh_reg is the original (dst)
                    //   => MOV lsh_reg, rsh_reg
                    if let Some(mov_pc) = find_provenance_mov(insns, pc, lsh_reg, rsh_reg) {
                        return Some(RotateSite {
                            start_pc: mov_pc,
                            old_len: (pc + 3) - mov_pc,
                            dst_reg: result_reg,
                            val_reg: rsh_reg,
                            tmp_reg: lsh_reg,
                            shift_amount: lsh_amount,
                        });
                    }
                }
            }
        }
    }

    // Pattern B: LSH64_IMM(rA, S_lsh) ; RSH64_IMM(rB, S_rsh) ; OR64_REG(or_dst, or_src)
    let is_lsh_first = i0.code == (BPF_ALU64 | BPF_LSH | BPF_K);
    let is_rsh_second = i1.code == (BPF_ALU64 | BPF_RSH | BPF_K);

    if is_lsh_first && is_rsh_second {
        let lsh_amount = i0.imm as u32;
        let rsh_amount = i1.imm as u32;

        if lsh_amount + rsh_amount == 64 {
            let lsh_reg = i0.dst_reg();
            let rsh_reg = i1.dst_reg();
            if lsh_reg != rsh_reg {
                let or_dst = i2.dst_reg();
                let or_src = i2.src_reg();

                let or_uses_both = (or_dst == lsh_reg && or_src == rsh_reg)
                    || (or_dst == rsh_reg && or_src == lsh_reg);
                if or_uses_both {
                    let result_reg = or_dst;
                    // Try both provenance directions:
                    if let Some(mov_pc) = find_provenance_mov(insns, pc, rsh_reg, lsh_reg) {
                        return Some(RotateSite {
                            start_pc: mov_pc,
                            old_len: (pc + 3) - mov_pc,
                            dst_reg: result_reg,
                            val_reg: lsh_reg,
                            tmp_reg: rsh_reg,
                            shift_amount: lsh_amount,
                        });
                    }
                    if let Some(mov_pc) = find_provenance_mov(insns, pc, lsh_reg, rsh_reg) {
                        return Some(RotateSite {
                            start_pc: mov_pc,
                            old_len: (pc + 3) - mov_pc,
                            dst_reg: result_reg,
                            val_reg: rsh_reg,
                            tmp_reg: lsh_reg,
                            shift_amount: lsh_amount,
                        });
                    }
                }
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
        BpfProgram::new(insns)
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }
    }

    fn ctx_with_rotate_kfunc(btf_id: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kfunc_registry.rotate64_btf_id = btf_id;
        ctx.platform.has_rorx = true;
        ctx
    }

    #[test]
    fn test_rotate_pass_pattern_match() {
        // Now requires MOV tmp, dst before the shift pattern.
        let insns = vec![
            BpfInsn::mov64_reg(3, 2), // MOV r3, r2 (provenance)
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
            BpfInsn::mov64_reg(3, 2), // provenance
            BpfInsn::alu64_imm(BPF_LSH, 2, 16),
            BpfInsn::alu64_imm(BPF_RSH, 3, 48),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].shift_amount, 16);
    }

    #[test]
    fn test_rotate_pass_pattern_or_reversed() {
        // clang emits OR tmp, dst instead of OR dst, tmp.
        // Result lands in tmp register (r3) instead of dst (r2).
        let insns = vec![
            BpfInsn::mov64_reg(3, 2),           // MOV r3, r2 (provenance: r3 is copy)
            BpfInsn::alu64_imm(BPF_RSH, 3, 56), // RSH r3 (copy), 56
            BpfInsn::alu64_imm(BPF_LSH, 2, 8),  // LSH r2 (orig), 8
            BpfInsn::alu64_reg(BPF_OR, 2, 3),   // OR r2, r3 — result in r2
        ];
        let sites = scan_rotate_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].shift_amount, 8);
        assert_eq!(sites[0].dst_reg, 2); // result register
        assert_eq!(sites[0].val_reg, 2); // original value register
        assert_eq!(sites[0].tmp_reg, 3); // copy register
    }

    #[test]
    fn test_rotate_pass_pattern_clang_style() {
        // Exact pattern from clang: MOV r2,r3 ; RSH r2,51 ; LSH r3,13 ; OR r3,r2
        // Here r3 is the original, r2 is the copy.
        let insns = vec![
            BpfInsn::mov64_reg(2, 3), // MOV r2, r3 (provenance: r2 = copy of r3)
            BpfInsn::alu64_imm(BPF_RSH, 2, 51), // RSH r2 (copy), 51
            BpfInsn::alu64_imm(BPF_LSH, 3, 13), // LSH r3 (orig), 13
            BpfInsn::alu64_reg(BPF_OR, 3, 2), // OR r3, r2 — result in r3
        ];
        let sites = scan_rotate_sites(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].shift_amount, 13);
        assert_eq!(sites[0].dst_reg, 3); // result register (r3, OR destination)
        assert_eq!(sites[0].val_reg, 3); // original value
        assert_eq!(sites[0].tmp_reg, 2); // copy register
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
            BpfInsn::mov64_reg(3, 4), // wrong: copies from r4, not r2
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
            BpfInsn::mov64_reg(3, 2), // provenance
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
        let has_kfunc_call = prog
            .insns
            .iter()
            .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL);
        assert!(has_kfunc_call, "expected a kfunc call in the output");
        let call_insn = prog
            .insns
            .iter()
            .find(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL)
            .unwrap();
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
        assert!(result.sites_skipped[0]
            .reason
            .contains("kfunc not available"));
    }

    #[test]
    fn test_rotate_pass_packed_keeps_live_regs() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),
            BpfInsn::mov64_reg(4, 2), // provenance for tmp=r4
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 4, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 4),
            BpfInsn::mov64_reg(0, 3), // r3 is live after site
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_rotate_kfunc(9999);

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(
            result.changed,
            "packed ABI should apply without save/restore"
        );
        assert_eq!(result.sites_applied, 1);
        let has_kfunc_call = prog
            .insns
            .iter()
            .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL);
        assert!(has_kfunc_call, "expected a kfunc call in the output");
    }

    #[test]
    fn test_rotate_pass_packed_no_callee_saved_dependency() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),
            BpfInsn::mov64_reg(4, 2), // provenance for tmp=r4
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 4, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 4),
            // Use r3, r6, r7, r8, r9 after site to make them all live
            BpfInsn::alu64_reg(BPF_OR, 0, 3),
            BpfInsn::alu64_reg(BPF_OR, 0, 6),
            BpfInsn::alu64_reg(BPF_OR, 0, 7),
            BpfInsn::alu64_reg(BPF_OR, 0, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 9),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_rotate_kfunc(9999);

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(
            result.changed,
            "packed ABI should not depend on free callee-saved regs"
        );
        assert_eq!(result.sites_applied, 1);
    }

    #[test]
    fn test_rotate_pass_tmp_live_out_conflict() {
        // tmp_reg (r6, callee-saved) is live after the site -- should skip.
        let mut prog = make_program(vec![
            BpfInsn::mov64_reg(6, 2), // provenance
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 6, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 6),
            BpfInsn::mov64_reg(0, 6), // r6 is used after site
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_rotate_kfunc(9999);

        let pass = RotatePass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(
            !result.changed,
            "should skip when tmp_reg is live after site"
        );
        assert!(result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("tmp_reg")));
    }

    #[test]
    fn test_rotate_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(RotatePass);

        let mut prog = make_program(vec![
            BpfInsn::mov64_reg(3, 2), // provenance
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

    // ── Issue 2: dst overwrite between MOV and shift ─────────────

    #[test]
    fn test_rotate_pass_no_match_dst_overwritten_after_mov() {
        // mov r3, r2; add r2, 1; rsh r2, 56; lsh r3, 8; or r2, r3
        // The MOV r3, r2 establishes provenance, but then r2 is modified
        // by ADD. At the RSH, r2 is a different value than what r3 holds.
        // This should NOT match as a rotate.
        let insns = vec![
            BpfInsn::mov64_reg(3, 2),           // MOV r3, r2
            BpfInsn::alu64_imm(BPF_OR, 2, 1),   // modifies r2 (any ALU op)
            BpfInsn::alu64_imm(BPF_RSH, 2, 56), // RSH r2, 56
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),  // LSH r3, 8
            BpfInsn::alu64_reg(BPF_OR, 2, 3),   // OR r2, r3
        ];
        let sites = scan_rotate_sites(&insns);
        assert!(
            sites.is_empty(),
            "should not match when dst is overwritten after MOV"
        );
    }

    #[test]
    fn test_rotate_pass_no_match_dst_overwritten_by_ldx() {
        // mov r3, r2; ldx r2, [r6+0]; rsh r2, 56; lsh r3, 8; or r2, r3
        let insns = vec![
            BpfInsn::mov64_reg(3, 2),
            BpfInsn::ldx_mem(BPF_DW, 2, 6, 0), // overwrites r2
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert!(
            sites.is_empty(),
            "should not match when dst is overwritten by LDX"
        );
    }

    #[test]
    fn test_rotate_pass_match_dst_not_overwritten() {
        // mov r3, r2; mov r5, r6; rsh r2, 56; lsh r3, 8; or r2, r3
        // The MOV r5, r6 doesn't write r2 or r3, so the provenance holds.
        let insns = vec![
            BpfInsn::mov64_reg(3, 2),
            BpfInsn::mov64_reg(5, 6), // doesn't modify r2 or r3
            BpfInsn::alu64_imm(BPF_RSH, 2, 56),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
        ];
        let sites = scan_rotate_sites(&insns);
        assert_eq!(sites.len(), 1, "should match when dst is not overwritten");
    }

    // ── MEDIUM #6: Real bytecode pattern test for rotate ────────────

    /// MEDIUM #6: Test rotate pattern scanning against real compiled BPF bytecode
    /// from rotate_dense.bpf.o. Verifies the scanner finds sites in real clang output.
    ///
    /// The scanner handles both OR operand orderings:
    ///   OR dst, tmp (canonical) and OR tmp, dst (clang's actual output).
    #[test]
    fn test_scan_rotate_real_bytecode() {
        let path = crate::insn::micro_program_path("rotate_dense.bpf.o");
        let insns = match crate::insn::load_bpf_insns_from_elf(&path) {
            Some(i) if !i.is_empty() => i,
            _ => {
                eprintln!("SKIP: rotate_dense.bpf.o not found (run `make micro` first)");
                return;
            }
        };

        let sites = scan_rotate_sites(&insns);

        // Verify the scanner doesn't panic on real bytecode and returns valid sites
        for site in &sites {
            assert!(
                site.start_pc < insns.len(),
                "rotate site start_pc {} out of range (insns.len()={})",
                site.start_pc,
                insns.len()
            );
            assert!(
                site.shift_amount > 0 && site.shift_amount < 64,
                "rotate shift_amount should be 1-63, got {}",
                site.shift_amount
            );
        }

        // Count RSH+LSH pairs that sum to 64 in the bytecode to see how many
        // potential rotate sites exist (regardless of OR direction).
        let mut potential = 0;
        for i in 0..insns.len().saturating_sub(2) {
            let is_rsh = insns[i].code == (BPF_ALU64 | BPF_RSH | BPF_K);
            let is_lsh = insns[i + 1].code == (BPF_ALU64 | BPF_LSH | BPF_K);
            let is_lsh_first = insns[i].code == (BPF_ALU64 | BPF_LSH | BPF_K);
            let is_rsh_second = insns[i + 1].code == (BPF_ALU64 | BPF_RSH | BPF_K);
            if (is_rsh && is_lsh && insns[i].imm + insns[i + 1].imm == 64)
                || (is_lsh_first && is_rsh_second && insns[i].imm + insns[i + 1].imm == 64)
            {
                potential += 1;
            }
        }

        eprintln!(
            "  rotate_dense.bpf.o: {} insns, {} potential rotate pairs, {} matched by scanner",
            insns.len(),
            potential,
            sites.len()
        );
        // There should be many potential rotate pairs in rotate_dense
        assert!(
            potential > 0,
            "rotate_dense.bpf.o should contain RSH+LSH pairs summing to 64"
        );
        // With the OR operand order fix, all potential pairs should be matched.
        assert!(
            !sites.is_empty(),
            "rotate_dense.bpf.o should have matched rotate sites (got 0 from {} potential)",
            potential
        );
        assert_eq!(
            sites.len(),
            potential,
            "all potential rotate pairs should be matched by the scanner"
        );
    }
}
