// SPDX-License-Identifier: MIT
//! Spectre mitigation pass.

use crate::insn::*;
use crate::pass::*;

use super::fixup_branches_inline;

/// Spectre mitigation pass: inserts NOP (`JA +0`) barriers after conditional
/// branches as speculation barrier placeholders. Avoids double-insertion if
/// a NOP already follows. Performs branch fixup after insertion.
pub struct SpectreMitigationPass;

impl BpfPass for SpectreMitigationPass {
    fn name(&self) -> &str {
        "spectre_mitigation"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Security
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
            program.log_transform(TransformEntry {
                pass_name: self.name().into(),
                sites_applied: insertions,
                insns_before: orig_len,
                insns_after: program.insns.len(),
                details: vec![format!("inserted {} NOP barriers", insertions)],
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
}
