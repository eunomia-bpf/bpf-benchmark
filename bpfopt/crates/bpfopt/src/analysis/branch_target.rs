// SPDX-License-Identifier: MIT
// Lightweight branch target analysis.

use crate::insn::relative_branch_target_pc;
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

    fn run(program: &BpfProgram) -> BranchTargetResult {
        let n = program.insns.len();
        let mut is_target = vec![false; n + 1];

        let mut pc = 0;
        while pc < n {
            let insn = &program.insns[pc];
            if insn.is_ldimm64_pseudo_func() {
                if let Some(target) = relative_branch_target_pc(pc, i64::from(insn.imm)) {
                    if target < n {
                        is_target[target] = true;
                    }
                }
            } else if let Some(target) = insn.branch_target_pc(pc) {
                if target <= n {
                    is_target[target] = true;
                }
            }
            if insn.is_call() && insn.src_reg() == 1 {
                // BPF-to-BPF pseudo call
                if let Some(target) = relative_branch_target_pc(pc, i64::from(insn.imm)) {
                    if target < n {
                        is_target[target] = true;
                    }
                }
            }
            pc = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };
        }

        BranchTargetResult { is_target }
    }
}
