// SPDX-License-Identifier: MIT
//! Spectre mitigation pass.

use crate::insn::*;
use crate::pass::*;

use super::utils::fixup_all_branches as fixup_branches_inline;

/// Barrier placeholder pass: inserts NOP (`JA +0`) after conditional branches.
///
/// **WARNING**: This is a PLACEHOLDER, NOT a real speculation barrier. The
/// inserted `JA +0` is a semantic NOP and does NOT prevent speculative
/// execution on any real CPU. A real Spectre mitigation would require
/// architecture-specific barrier instructions (e.g., LFENCE on x86).
///
/// This pass exists to mark branch sites for future barrier insertion and
/// to measure the code-size overhead of barrier placement strategies.
///
/// **Note on site count**: this pass only fires when the program contains
/// conditional branches (`is_cond_jmp()`). Pure-compute micro benchmarks
/// (e.g., bitcount, rotate) that are straight-line code will correctly show
/// 0 sites. Programs with if/else logic (Cilium, Calico, Tracee) will have
/// many conditional branches and thus many insertion sites.
///
/// This pass is NOT in the default optimization pipeline by design. Enable
/// it explicitly via policy or by adding it to a custom pipeline.
pub struct SpectreMitigationPass;

impl BpfPass for SpectreMitigationPass {
    fn name(&self) -> &str {
        "barrier_placeholder"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Placeholder
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let orig_len = program.insns.len();
        let mut new_insns: Vec<BpfInsn> = Vec::with_capacity(orig_len + orig_len / 4);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut insertions = 0usize;

        let mut pc = 0;
        while pc < orig_len {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            let insn = program.insns[pc];
            new_insns.push(insn);

            // After a conditional jump, insert a NOP if one isn't already there
            if insn.is_cond_jmp() {
                let next_pc = pc + 1;
                let already_has_nop = next_pc < orig_len
                    && program.insns[next_pc].is_ja()
                    && program.insns[next_pc].off == 0;

                if !already_has_nop {
                    new_insns.push(BpfInsn::nop());
                    insertions += 1;
                }
            }

            // Handle LDIMM64 second slot
            if insn.is_ldimm64() && pc + 1 < orig_len {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(program.insns[pc]);
            }

            pc += 1;
        }
        addr_map[orig_len] = new_insns.len();

        if insertions > 0 {
            // Fix up branches using the address map
            fixup_branches_inline(&mut new_insns, &program.insns, &addr_map);

            program.insns = new_insns;
            program.remap_annotations(&addr_map);
            program.log_transform(TransformEntry {
                pass_name: self.name().into(),
                sites_applied: insertions,
                insns_before: orig_len,
                insns_after: program.insns.len(),
                details: vec![format!("inserted {} placeholder NOP barriers", insertions)],
            });
        }

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: insertions > 0,
            sites_applied: insertions,
            sites_skipped: vec![],
            diagnostics: if insertions > 0 {
                vec![format!(
                    "{} speculation barriers inserted (NOP placeholder)",
                    insertions
                )]
            } else {
                vec![]
            },
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::analysis::BranchTargetAnalysis;
    use crate::pass::{AnalysisCache, PassContext, PassManager};

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns, ProgMeta::default())
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn { code: BPF_JMP | BPF_EXIT, regs: 0, off: 0, imm: 0 }
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    #[test]
    fn test_spectre_pass_inserts_fence_after_branch() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_imm(0, 2),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = SpectreMitigationPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert_eq!(prog.insns.len(), 5);
        assert!(prog.insns[0].is_cond_jmp());
        assert!(prog.insns[1].is_ja() && prog.insns[1].off == 0);
    }

    #[test]
    fn test_spectre_pass_no_change_when_no_vulnerable_sites() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = SpectreMitigationPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert_eq!(prog.insns.len(), 2);
    }

    #[test]
    fn test_spectre_pass_multiple_branches() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 1),
            jeq_imm(2, 0, 1),
            BpfInsn::mov64_imm(0, 2),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = SpectreMitigationPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 2);
        assert_eq!(prog.insns.len(), 7);
    }

    #[test]
    fn test_spectre_pass_does_not_insert_after_unconditional_jump() {
        let mut prog = make_program(vec![
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = SpectreMitigationPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert_eq!(prog.insns.len(), 3);
    }

    #[test]
    fn test_spectre_pass_integration_with_pass_manager() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.add_pass(SpectreMitigationPass);

        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert_eq!(result.total_sites_applied, 1);
    }

    #[test]
    fn test_spectre_inserts_nop() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert_eq!(prog.insns.len(), 4);
        assert!(prog.insns[1].is_ja() && prog.insns[1].off == 0);
    }

    #[test]
    fn test_spectre_no_double_insert() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::nop(),
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
        assert_eq!(prog.insns.len(), 4);
    }

    #[test]
    fn test_spectre_no_jcc() {
        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 0), exit_insn()]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
    }

    // ── Branch fixup tests ──────────────────────────────────────────

    #[test]
    fn test_spectre_forward_branch_fixup() {
        // jeq r1, 0, +2  -> should skip mov r0,1 and mov r0,2 to reach exit
        // After NOP insertion: jeq r1, 0, +3 (skip NOP + mov + mov)
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 2),       // pc=0: if r1==0, skip 2 insns to exit
            BpfInsn::mov64_imm(0, 1), // pc=1
            BpfInsn::mov64_imm(0, 2), // pc=2
            exit_insn(),             // pc=3: target of branch
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // New layout: [0] jeq  [1] nop  [2] mov  [3] mov  [4] exit
        assert_eq!(prog.insns.len(), 5);
        // The branch at [0] should now have off=3 to reach exit at [4]
        assert_eq!(prog.insns[0].off, 3);
    }

    #[test]
    fn test_spectre_chained_branches_fixup() {
        // Two chained conditional branches, each jumping forward.
        // jeq r1, 0, +1  -> jumps over mov r0,1 to reach jeq r2
        // mov r0, 1
        // jeq r2, 0, +1  -> jumps over mov r0,2 to reach exit
        // mov r0, 2
        // exit
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),         // pc=0
            BpfInsn::mov64_imm(0, 1), // pc=1
            jeq_imm(2, 0, 1),         // pc=2
            BpfInsn::mov64_imm(0, 2), // pc=3
            exit_insn(),               // pc=4
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 2);
        // New layout: [0] jeq [1] nop [2] mov [3] jeq [4] nop [5] mov [6] exit
        assert_eq!(prog.insns.len(), 7);

        // First branch: originally jumped +1 (to pc=2, which is now at new_pc=3)
        // From new_pc=0, offset should be 3-1=2
        assert_eq!(prog.insns[0].off, 2);

        // Second branch: originally jumped +1 (to pc=4, which is now at new_pc=6)
        // From new_pc=3, offset should be 6-4=2
        assert_eq!(prog.insns[3].off, 2);
    }

    #[test]
    fn test_spectre_jmp32_variant() {
        // JMP32 conditional branch should also get a NOP
        let jne32_imm = BpfInsn {
            code: BPF_JMP32 | BPF_JNE | BPF_K,
            regs: BpfInsn::make_regs(1, 0),
            off: 1,
            imm: 42,
        };
        let mut prog = make_program(vec![
            jne32_imm,
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_imm(0, 2),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        assert_eq!(prog.insns.len(), 5);
        // NOP at position 1
        assert!(prog.insns[1].is_ja() && prog.insns[1].off == 0);
    }

    #[test]
    fn test_spectre_ldimm64_not_affected() {
        // LDIMM64 is a 2-slot instruction; the pass should handle it without
        // inserting a NOP after it (it's not a conditional branch).
        let ldimm64_lo = BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(0, 0),
            off: 0,
            imm: 42,
        };
        let ldimm64_hi = BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: 0,
        };
        let mut prog = make_program(vec![
            ldimm64_lo,
            ldimm64_hi,
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!result.changed);
        assert_eq!(prog.insns.len(), 3);
    }

    #[test]
    fn test_spectre_branch_around_ldimm64() {
        // jeq r1, 0, +3 -> skip LDIMM64 (2 slots) + mov to reach exit
        // LDIMM64 (2 slots)
        // mov r0, 1
        // exit
        let ldimm64_lo = BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(2, 0),
            off: 0,
            imm: 99,
        };
        let ldimm64_hi = BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: 0,
        };
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 3),         // pc=0: jump to pc=4 (exit)
            ldimm64_lo,                // pc=1
            ldimm64_hi,                // pc=2
            BpfInsn::mov64_imm(0, 1), // pc=3
            exit_insn(),               // pc=4
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // New layout: [0] jeq [1] nop [2] ldimm64_lo [3] ldimm64_hi [4] mov [5] exit
        assert_eq!(prog.insns.len(), 6);
        // Branch at [0] should target exit at [5]: off = 5 - 1 = 4
        assert_eq!(prog.insns[0].off, 4);
    }

    #[test]
    fn test_spectre_realistic_spectre_v1_pattern() {
        // Classic Spectre v1 pattern:
        //   if (idx < ARRAY_SIZE) {    // JGE r1, imm, +N  (bounds check)
        //     val = array[idx];         // LDX [r2 + r1*8]
        //   }
        //
        // Simplified as BPF:
        //   jge r1, 256, +2  -> skip load+use if out of bounds
        //   ldx r0, [r6 + 0]  (simulated array access)
        //   mov r0, r0
        //   exit
        let jge_imm = BpfInsn {
            code: BPF_JMP | BPF_JGE | BPF_K,
            regs: BpfInsn::make_regs(1, 0),
            off: 2,
            imm: 256,
        };
        let mut prog = make_program(vec![
            jge_imm,                            // pc=0: bounds check
            BpfInsn::ldx_mem(BPF_DW, 0, 6, 0), // pc=1: speculative load
            BpfInsn::mov64_reg(0, 0),           // pc=2: use loaded value
            exit_insn(),                         // pc=3
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // NOP barrier inserted right after the conditional branch
        assert_eq!(prog.insns.len(), 5);
        assert!(prog.insns[0].is_cond_jmp());
        assert!(prog.insns[1].is_ja() && prog.insns[1].off == 0);
        // Branch offset adjusted: originally +2 (to exit at pc=3), now +3 (exit at new_pc=4)
        assert_eq!(prog.insns[0].off, 3);
    }

    #[test]
    fn test_spectre_idempotent() {
        // Running the pass twice should not insert more NOPs (second run finds
        // NOPs already present).
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_imm(0, 2),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        // First run
        let r1 = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(r1.changed);
        let len_after_first = prog.insns.len();

        // Second run on the already-mitigated program
        cache.invalidate_all();
        let r2 = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(!r2.changed);
        assert_eq!(prog.insns.len(), len_after_first);
    }

    #[test]
    fn test_spectre_all_cond_jmp_opcodes() {
        // Verify that all conditional jump opcodes trigger NOP insertion.
        let cond_opcodes: Vec<u8> = vec![
            BPF_JEQ, BPF_JGT, BPF_JGE, BPF_JSET, BPF_JNE,
            BPF_JLT, BPF_JLE, BPF_JSGT, BPF_JSGE, BPF_JSLT, BPF_JSLE,
        ];

        for opcode in &cond_opcodes {
            let insn = BpfInsn {
                code: BPF_JMP | opcode | BPF_K,
                regs: BpfInsn::make_regs(1, 0),
                off: 1,
                imm: 0,
            };
            let mut prog = make_program(vec![
                insn,
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]);
            let mut cache = AnalysisCache::new();
            let ctx = PassContext::test_default();

            let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
            assert!(
                result.changed,
                "expected NOP insertion for JMP opcode {:#x}",
                opcode
            );
            assert_eq!(
                result.sites_applied, 1,
                "expected 1 site for JMP opcode {:#x}",
                opcode
            );
        }
    }

    #[test]
    fn test_spectre_diagnostics_content() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 1),
            jeq_imm(2, 0, 0),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert_eq!(result.diagnostics.len(), 1);
        assert!(result.diagnostics[0].contains("speculation barriers inserted"));
    }

    // ── Issue 4: Naming and category tests ──────────────────────

    #[test]
    fn test_spectre_pass_name_is_barrier_placeholder() {
        let pass = SpectreMitigationPass;
        assert_eq!(pass.name(), "barrier_placeholder",
            "pass name should be 'barrier_placeholder', not 'spectre_mitigation'");
    }

    #[test]
    fn test_spectre_pass_category_is_placeholder() {
        let pass = SpectreMitigationPass;
        assert_eq!(pass.category(), PassCategory::Placeholder,
            "category should be Placeholder, not Security");
    }

    #[test]
    fn test_spectre_diagnostics_contain_placeholder() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);
        assert!(!result.diagnostics.is_empty());
        // Diagnostics should clearly indicate this is a placeholder.
        let diag = &result.diagnostics[0];
        assert!(diag.contains("placeholder") || diag.contains("NOP placeholder"),
            "diagnostics should contain 'placeholder', got: {}", diag);
    }

    #[test]
    fn test_spectre_pass_result_name() {
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let result = SpectreMitigationPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(result.pass_name, "barrier_placeholder",
            "PassResult should use the new name");
    }
}
