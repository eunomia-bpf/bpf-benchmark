// SPDX-License-Identifier: MIT
//! Concrete pass implementations and pipeline constructors.

mod wide_mem;
mod rotate;
mod cond_select;
mod branch_flip;
mod spectre;

pub use wide_mem::WideMemPass;
pub use rotate::RotatePass;
pub use cond_select::CondSelectPass;
pub use branch_flip::BranchFlipPass;
pub use spectre::SpectreMitigationPass;

use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis};
use crate::insn::BpfInsn;
use crate::pass::PassManager;

// ── Shared utility ──────────────────────────────────────────────────

/// Fix up branch and pseudo-call offsets after rewriting using an address map.
///
/// For each instruction in the *original* stream that is a branch/jump,
/// compute where it ended up in the new stream and adjust its offset
/// so it still points to the correct target.
pub(crate) fn fixup_branches_inline(
    new_insns: &mut [BpfInsn],
    old_insns: &[BpfInsn],
    addr_map: &[usize],
) {
    let old_n = old_insns.len();
    let mut old_pc = 0;
    while old_pc < old_n {
        let insn = &old_insns[old_pc];
        if insn.is_call() && insn.src_reg() == 1 {
            // BPF pseudo-call: fix up imm (pc-relative offset to target subprog).
            let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
            if old_target < old_n {
                let new_pc = addr_map[old_pc];
                let new_target = addr_map[old_target];
                if new_pc < new_insns.len() && new_insns[new_pc].is_call() {
                    let new_imm = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].imm = new_imm as i32;
                }
            }
        } else if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
            let new_pc = addr_map[old_pc];
            let old_target = (old_pc as i64 + 1 + insn.off as i64) as usize;
            if old_target <= old_n {
                let new_target = addr_map[old_target];
                if new_pc < new_insns.len() && new_insns[new_pc].is_jmp_class() {
                    let new_off = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].off = new_off as i16;
                }
            }
        }
        old_pc = if insn.is_ldimm64() {
            old_pc + 2
        } else {
            old_pc + 1
        };
    }
}

// ── Pipeline constructors ───────────────────────────────────────────

/// Build the default optimization pipeline.
pub fn build_default_pipeline() -> PassManager {
    let mut pm = PassManager::new();

    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);


    pm.add_pass(WideMemPass);
    pm.add_pass(RotatePass);
    pm.add_pass(CondSelectPass);
    pm.add_pass(BranchFlipPass { min_bias: 0.7 });

    pm
}

/// Build a pipeline containing only the named passes.
///
/// Pass names: `wide_mem`, `rotate`, `cond_select`, `branch_flip`, `spectre_mitigation`.
/// Unknown names are silently ignored.
pub fn build_pipeline_with_passes(names: &[String]) -> PassManager {
    let mut pm = PassManager::new();

    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);


    let name_set: std::collections::HashSet<&str> = names.iter().map(|s| s.as_str()).collect();

    if name_set.contains("wide_mem") {
        pm.add_pass(WideMemPass);
    }
    if name_set.contains("rotate") {
        pm.add_pass(RotatePass);
    }
    if name_set.contains("cond_select") {
        pm.add_pass(CondSelectPass);
    }
    if name_set.contains("branch_flip") {
        pm.add_pass(BranchFlipPass { min_bias: 0.7 });
    }
    if name_set.contains("spectre_mitigation") {
        pm.add_pass(SpectreMitigationPass);
    }

    pm
}

// ── Cross-pass integration tests ────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::*;
    use crate::pass::{BpfProgram, PassContext, ProgMeta};

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

    fn make_wide_mem_4byte_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::ldx_mem(BPF_B, 2, 1, 0),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 1),
            BpfInsn::alu64_imm(BPF_LSH, 3, 8),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 2),
            BpfInsn::alu64_imm(BPF_LSH, 3, 16),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            BpfInsn::ldx_mem(BPF_B, 3, 1, 3),
            BpfInsn::alu64_imm(BPF_LSH, 3, 24),
            BpfInsn::alu64_reg(BPF_OR, 2, 3),
            exit_insn(),
        ]
    }

    #[test]
    fn test_pipeline_wide_mem_then_spectre() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(WideMemPass);
        pm.add_pass(SpectreMitigationPass);

        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            jeq_imm(0, 42, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ];

        let mut prog = make_program(insns);
        let ctx = PassContext::test_default();

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert!(result.total_sites_applied >= 2);
    }

    #[test]
    fn test_cfg_analysis_with_subprogs() {
        use crate::analysis::CFGAnalysis;
        use crate::pass::Analysis;

        let prog = make_program(vec![
            BpfInsn {
                code: BPF_JMP | BPF_CALL,
                regs: BpfInsn::make_regs(0, 1),
                off: 0,
                imm: 2,
            },
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);

        let cfg = CFGAnalysis;
        let result = cfg.run(&prog);

        assert!(result.branch_targets[3]);
        assert!(result.subprogs.len() >= 2);
    }

    #[test]
    fn test_liveness_across_branch() {
        use crate::analysis::LivenessAnalysis;
        use crate::pass::Analysis;

        let prog = make_program(vec![
            BpfInsn::mov64_imm(1, 10),
            jeq_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_imm(0, 2),
            exit_insn(),
        ]);

        let liveness = LivenessAnalysis;
        let result = liveness.run(&prog);

        assert!(result.live_out[0].contains(&1));
        assert!(result.live_in[1].contains(&1));
        assert!(result.live_in[4].contains(&0));
    }

    #[test]
    fn test_branch_targets_backward_jump() {
        use crate::analysis::BranchTargetAnalysis;
        use crate::pass::Analysis;

        let prog = make_program(vec![
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(-2),
        ]);

        let bt = BranchTargetAnalysis;
        let result = bt.run(&prog);

        assert!(result.is_target[0]);
        assert!(!result.is_target[1]);
    }

    #[test]
    fn test_default_pipeline_wide_mem() {
        let mut prog = make_program(make_wide_mem_4byte_program());
        let ctx = PassContext::test_default();

        let pm = build_default_pipeline();
        let result = pm.run(&mut prog, &ctx).unwrap();
        assert!(result.program_changed);
        assert!(result.total_sites_applied >= 1);
    }
}
