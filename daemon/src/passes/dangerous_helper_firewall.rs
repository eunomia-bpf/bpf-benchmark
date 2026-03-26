// SPDX-License-Identifier: MIT
//! Dangerous helper firewall security pass.

use crate::pass::*;

/// Phase-1 helper firewall pass.
pub struct DangerousHelperFirewallPass;

impl BpfPass for DangerousHelperFirewallPass {
    fn name(&self) -> &str {
        "dangerous_helper_firewall"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Security
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "liveness"]
    }

    fn run(
        &self,
        _program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // Intentionally left as a no-op for TDD. The tests in this module
        // encode the desired phase-1 behavior and should fail until the
        // rewrite logic is implemented.
        Ok(PassResult {
            pass_name: self.name().into(),
            changed: false,
            sites_applied: 0,
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
    use crate::insn::*;
    use crate::pass::{BpfProgram, PassContext, PassManager, PipelineResult};

    const BPF_ADD: u8 = 0x00;

    const BPF_PROG_TYPE_TRACEPOINT: u32 = 5;

    const BPF_FUNC_MAP_LOOKUP_ELEM: i32 = 1;
    const BPF_FUNC_KTIME_GET_NS: i32 = 5;
    const BPF_FUNC_OVERRIDE_RETURN: i32 = 58;
    const BPF_FUNC_SEND_SIGNAL: i32 = 109;
    const BPF_FUNC_PROBE_READ_KERNEL: i32 = 113;
    const BPF_FUNC_KTIME_GET_COARSE_NS: i32 = 160;

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }
    }

    fn helper_call(helper_id: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_CALL,
            regs: BpfInsn::make_regs(0, 0),
            off: 0,
            imm: helper_id,
        }
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn run_dangerous_helper_pass(program: &mut BpfProgram, prog_type: u32) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(DangerousHelperFirewallPass);

        let mut ctx = PassContext::test_default();
        ctx.prog_type = prog_type;
        pm.run(program, &ctx).unwrap()
    }

    fn audit_reason(helper_name: &str, helper_id: i32) -> String {
        format!("audit-only dangerous helper {helper_name} (#{helper_id})")
    }

    fn make_no_helpers_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(1, 42),
            BpfInsn::mov64_reg(0, 1),
            exit_insn(),
        ]
    }

    fn make_safe_helper_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(1, 0),
            BpfInsn::mov64_imm(2, 0),
            helper_call(BPF_FUNC_MAP_LOOKUP_ELEM),
            exit_insn(),
        ]
    }

    fn make_single_helper_program(helper_id: i32) -> Vec<BpfInsn> {
        vec![helper_call(helper_id), exit_insn()]
    }

    fn make_multiple_dangerous_calls_program() -> Vec<BpfInsn> {
        vec![
            helper_call(BPF_FUNC_SEND_SIGNAL),
            helper_call(BPF_FUNC_OVERRIDE_RETURN),
            helper_call(BPF_FUNC_KTIME_GET_NS),
            exit_insn(),
        ]
    }

    fn make_branch_fixup_program() -> Vec<BpfInsn> {
        vec![
            jeq_imm(0, 0, 4),
            BpfInsn::mov64_imm(1, 7),
            BpfInsn::alu64_imm(BPF_ADD, 1, 2),
            helper_call(BPF_FUNC_SEND_SIGNAL),
            exit_insn(),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]
    }

    #[test]
    fn test_empty_program() {
        let mut program = BpfProgram::new(vec![]);

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(!result.program_changed);
        assert!(program.insns.is_empty());
        assert_eq!(result.pass_results.len(), 1);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_no_helpers_unchanged() {
        let original = make_no_helpers_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert!(result.pass_results[0].sites_skipped.is_empty());
    }

    #[test]
    fn test_safe_helper_unchanged() {
        let original = make_safe_helper_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert!(result.pass_results[0].sites_skipped.is_empty());
    }

    #[test]
    fn test_send_signal_replaced() {
        let mut program = BpfProgram::new(make_single_helper_program(BPF_FUNC_SEND_SIGNAL));

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, -1), exit_insn()]);
    }

    #[test]
    fn test_override_return_replaced() {
        let mut program = BpfProgram::new(make_single_helper_program(BPF_FUNC_OVERRIDE_RETURN));

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, -1), exit_insn()]);
    }

    #[test]
    fn test_ktime_get_ns_coarseified() {
        let mut program = BpfProgram::new(make_single_helper_program(BPF_FUNC_KTIME_GET_NS));

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![helper_call(BPF_FUNC_KTIME_GET_COARSE_NS), exit_insn()],
        );
    }

    #[test]
    fn test_probe_read_kernel_audit_only() {
        let original = make_single_helper_program(BPF_FUNC_PROBE_READ_KERNEL);
        let mut program = BpfProgram::new(original.clone());

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason == audit_reason("probe_read_kernel", 113)));
    }

    #[test]
    fn test_multiple_dangerous_calls() {
        let mut program = BpfProgram::new(make_multiple_dangerous_calls_program());

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 3);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(0, -1),
                BpfInsn::mov64_imm(0, -1),
                helper_call(BPF_FUNC_KTIME_GET_COARSE_NS),
                exit_insn(),
            ],
        );
    }

    #[test]
    fn test_branch_fixup_after_replacement() {
        let mut program = BpfProgram::new(make_branch_fixup_program());

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                jeq_imm(0, 0, 2),
                BpfInsn::mov64_imm(0, -1),
                exit_insn(),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ],
        );
    }
}
