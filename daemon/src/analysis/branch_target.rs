// SPDX-License-Identifier: MIT
//! Lightweight branch target analysis.

use crate::pass::{Analysis, BpfProgram};

/// Lightweight analysis: for each instruction, whether it is a branch/call target.
#[derive(Clone, Debug)]
pub struct BranchTargetResult {
    /// `is_target[pc]` is true if some branch/call targets this PC.
    /// Length is `n + 1` to accommodate the past-the-end sentinel.
    pub is_target: Vec<bool>,
}

pub struct BranchTargetAnalysis;

impl Analysis for BranchTargetAnalysis {
    type Result = BranchTargetResult;

    fn name(&self) -> &str {
        "branch_targets"
    }

    fn run(&self, program: &BpfProgram) -> BranchTargetResult {
        let n = program.insns.len();
        let mut is_target = vec![false; n + 1];

        let mut pc = 0;
        while pc < n {
            let insn = &program.insns[pc];
            if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
                let target = (pc as i64 + 1 + insn.off as i64) as usize;
                if target <= n {
                    is_target[target] = true;
                }
            }
            if insn.is_call() && insn.src_reg() == 1 {
                // BPF-to-BPF pseudo call
                let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                if target < n {
                    is_target[target] = true;
                }
            }
            pc = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };
        }

        BranchTargetResult { is_target }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::*;
    use crate::pass::{AnalysisCache, BpfProgram};

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

    #[test]
    fn branch_target_simple_ja() {
        let insns = vec![
            BpfInsn::ja(2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(1, 1),
            exit_insn(),
        ];
        let prog = make_program(insns);
        let result = BranchTargetAnalysis.run(&prog);
        assert!(!result.is_target[0]);
        assert!(!result.is_target[1]);
        assert!(!result.is_target[2]);
        assert!(result.is_target[3]);
    }

    #[test]
    fn branch_target_cond_jmp() {
        let insns = vec![
            BpfInsn {
                code: BPF_JMP | BPF_JEQ | BPF_K,
                regs: BpfInsn::make_regs(1, 0),
                off: 1,
                imm: 0,
            },
            BpfInsn::nop(),
            exit_insn(),
        ];
        let prog = make_program(insns);
        let result = BranchTargetAnalysis.run(&prog);
        assert!(result.is_target[2]);
    }

    #[test]
    fn branch_target_no_branches() {
        let insns = vec![BpfInsn::mov64_imm(0, 42), exit_insn()];
        let prog = make_program(insns);
        let result = BranchTargetAnalysis.run(&prog);
        assert!(!result.is_target[0]);
        assert!(!result.is_target[1]);
    }

    #[test]
    fn cache_branch_target() {
        let prog = make_program(vec![BpfInsn::ja(1), BpfInsn::nop(), exit_insn()]);
        let mut cache = AnalysisCache::new();
        let r1 = cache.get(&BranchTargetAnalysis, &prog);
        let r2 = cache.get(&BranchTargetAnalysis, &prog);
        assert_eq!(r1.is_target, r2.is_target);
    }

    #[test]
    fn cache_invalidation() {
        let prog = make_program(vec![BpfInsn::ja(1), BpfInsn::nop(), exit_insn()]);
        let mut cache = AnalysisCache::new();
        let _ = cache.get(&BranchTargetAnalysis, &prog);
        cache.invalidate_all();
        let r = cache.get(&BranchTargetAnalysis, &prog);
        assert!(r.is_target[2]);
    }
}
