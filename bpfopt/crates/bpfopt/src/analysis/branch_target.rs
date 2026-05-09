// SPDX-License-Identifier: MIT
// Lightweight branch target analysis.

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
            if insn.is_ldimm64_pseudo_func() {
                let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                if target < n {
                    is_target[target] = true;
                }
            } else if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
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
