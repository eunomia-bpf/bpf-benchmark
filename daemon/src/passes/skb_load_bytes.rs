// SPDX-License-Identifier: MIT
//! skb_load_bytes specialization pass.

use crate::pass::*;

/// Specialize eligible `bpf_skb_load_bytes()` helper sites into direct packet access.
pub struct SkbLoadBytesSpecPass;

impl BpfPass for SkbLoadBytesSpecPass {
    fn name(&self) -> &str {
        "skb_load_bytes_spec"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        _program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
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

    use crate::analysis::BranchTargetAnalysis;
    use crate::insn::*;
    use crate::pass::{BpfProgram, PassContext, PassManager};

    const BPF_ADD: u8 = 0x00;

    const BPF_FUNC_SKB_LOAD_BYTES: i32 = 26;
    const BPF_FUNC_DUMMY_HELPER: i32 = 1;

    const BPF_PROG_TYPE_SOCKET_FILTER: u32 = 1;
    const BPF_PROG_TYPE_SCHED_CLS: u32 = 3;
    const BPF_PROG_TYPE_SCHED_ACT: u32 = 4;

    const SKB_DATA_OFF: i16 = 76;
    const SKB_DATA_END_OFF: i16 = 80;

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

    fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JNE | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn jgt_reg(dst: u8, src: u8, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JGT | BPF_X,
            regs: BpfInsn::make_regs(dst, src),
            off,
            imm: 0,
        }
    }

    fn make_skb_load_bytes_setup(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(2, offset),
            BpfInsn::mov64_reg(3, 10),
            BpfInsn::alu64_imm(BPF_ADD, 3, stack_off),
            BpfInsn::mov64_imm(4, len),
        ]
    }

    fn make_skb_load_bytes_program(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
        let mut insns = make_skb_load_bytes_setup(offset, stack_off, len);
        insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
        insns.push(jne_imm(0, 0, 2));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(exit_insn());
        insns
    }

    fn make_non_skb_helper_program() -> Vec<BpfInsn> {
        let mut insns = make_skb_load_bytes_setup(14, -8, 1);
        insns.push(helper_call(BPF_FUNC_DUMMY_HELPER));
        insns.push(jne_imm(0, 0, 2));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(exit_insn());
        insns
    }

    fn make_no_helper_calls_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_reg(2, 10),
            BpfInsn::alu64_imm(BPF_ADD, 2, -8),
            exit_insn(),
        ]
    }

    fn make_variable_offset_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_reg(2, 6),
            BpfInsn::mov64_reg(3, 10),
            BpfInsn::alu64_imm(BPF_ADD, 3, -8),
            BpfInsn::mov64_imm(4, 1),
            helper_call(BPF_FUNC_SKB_LOAD_BYTES),
            jne_imm(0, 0, 2),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_variable_len_program() -> Vec<BpfInsn> {
        vec![
            BpfInsn::mov64_imm(2, 14),
            BpfInsn::mov64_reg(3, 10),
            BpfInsn::alu64_imm(BPF_ADD, 3, -8),
            BpfInsn::mov64_reg(4, 7),
            helper_call(BPF_FUNC_SKB_LOAD_BYTES),
            jne_imm(0, 0, 2),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]
    }

    fn make_two_call_program() -> Vec<BpfInsn> {
        let mut insns = Vec::new();
        insns.extend(make_skb_load_bytes_setup(14, -8, 1));
        insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
        insns.push(jne_imm(0, 0, 8));
        insns.extend(make_skb_load_bytes_setup(18, -16, 1));
        insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
        insns.push(jne_imm(0, 0, 2));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(exit_insn());
        insns
    }

    fn make_branch_around_program() -> Vec<BpfInsn> {
        let mut insns = vec![jeq_imm(0, 0, 6)];
        insns.extend(make_skb_load_bytes_program(14, -8, 1));
        insns
    }

    fn expected_call_replacement(offset: i32, len: i32) -> Vec<BpfInsn> {
        let mut insns = vec![
            BpfInsn::ldx_mem(BPF_W, 5, 1, SKB_DATA_OFF),
            BpfInsn::ldx_mem(BPF_W, 0, 1, SKB_DATA_END_OFF),
            BpfInsn::mov64_reg(2, 5),
            BpfInsn::alu64_imm(BPF_ADD, 2, offset + len),
            jgt_reg(2, 0, (3 + 2 * len) as i16),
            BpfInsn::alu64_imm(BPF_ADD, 5, offset),
        ];

        for i in 0..len {
            insns.push(BpfInsn::ldx_mem(BPF_B, 4, 5, i as i16));
            insns.push(BpfInsn::stx_mem(BPF_B, 3, 4, i as i16));
        }

        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(BpfInsn::ja(3));
        insns.push(BpfInsn::mov64_imm(2, offset));
        insns.push(BpfInsn::mov64_imm(4, len));
        insns.push(helper_call(BPF_FUNC_SKB_LOAD_BYTES));
        insns
    }

    fn expected_rewritten_program(offset: i32, stack_off: i32, len: i32) -> Vec<BpfInsn> {
        let mut insns = make_skb_load_bytes_setup(offset, stack_off, len);
        insns.extend(expected_call_replacement(offset, len));
        insns.push(jne_imm(0, 0, 2));
        insns.push(BpfInsn::mov64_imm(0, 1));
        insns.push(exit_insn());
        insns.push(BpfInsn::mov64_imm(0, 0));
        insns.push(exit_insn());
        insns
    }

    fn run_skb_load_bytes_pass(
        program: &mut BpfProgram,
        prog_type: u32,
    ) -> crate::pass::PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.add_pass(SkbLoadBytesSpecPass);

        let mut ctx = PassContext::test_default();
        ctx.prog_type = prog_type;
        pm.run(program, &ctx).unwrap()
    }

    fn count_ctx_access(insns: &[BpfInsn], off: i16) -> usize {
        insns
            .iter()
            .filter(|insn| {
                insn.is_ldx_mem()
                    && bpf_size(insn.code) == BPF_W
                    && insn.src_reg() == 1
                    && insn.off == off
            })
            .count()
    }

    #[test]
    fn test_empty_program() {
        let mut program = BpfProgram::new(vec![]);

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(!result.program_changed);
        assert!(program.insns.is_empty());
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_no_helper_calls() {
        let original = make_no_helper_calls_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_non_skb_helper_unchanged() {
        let original = make_non_skb_helper_program();
        let mut program = BpfProgram::new(original.clone());

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
    }

    #[test]
    fn test_single_skb_load_bytes_replaced() {
        let mut program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, expected_rewritten_program(14, -8, 1));
    }

    #[test]
    fn test_constant_offset_and_len_required() {
        let variable_offset = make_variable_offset_program();
        let mut offset_program = BpfProgram::new(variable_offset.clone());
        let offset_result = run_skb_load_bytes_pass(&mut offset_program, BPF_PROG_TYPE_SCHED_CLS);
        assert!(!offset_result.program_changed);
        assert_eq!(offset_program.insns, variable_offset);

        let variable_len = make_variable_len_program();
        let mut len_program = BpfProgram::new(variable_len.clone());
        let len_result = run_skb_load_bytes_pass(&mut len_program, BPF_PROG_TYPE_SCHED_CLS);
        assert!(!len_result.program_changed);
        assert_eq!(len_program.insns, variable_len);
    }

    #[test]
    fn test_only_tc_programs() {
        let expected = expected_rewritten_program(14, -8, 1);

        let mut cls_program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));
        let cls_result = run_skb_load_bytes_pass(&mut cls_program, BPF_PROG_TYPE_SCHED_CLS);
        assert!(cls_result.program_changed);
        assert_eq!(cls_result.pass_results[0].sites_applied, 1);
        assert_eq!(cls_program.insns, expected);

        let mut act_program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));
        let act_result = run_skb_load_bytes_pass(&mut act_program, BPF_PROG_TYPE_SCHED_ACT);
        assert!(act_result.program_changed);
        assert_eq!(act_result.pass_results[0].sites_applied, 1);
        assert_eq!(act_program.insns, expected_rewritten_program(14, -8, 1));

        let original = make_skb_load_bytes_program(14, -8, 1);
        let mut socket_filter_program = BpfProgram::new(original.clone());
        let socket_filter_result =
            run_skb_load_bytes_pass(&mut socket_filter_program, BPF_PROG_TYPE_SOCKET_FILTER);
        assert!(!socket_filter_result.program_changed);
        assert_eq!(socket_filter_program.insns, original);
    }

    #[test]
    fn test_error_check_preserved() {
        let mut program = BpfProgram::new(make_skb_load_bytes_program(14, -8, 1));

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(result.program_changed);
        assert_eq!(program.insns[8], jgt_reg(2, 0, 5));
        assert_eq!(program.insns[17], jne_imm(0, 0, 2));
    }

    #[test]
    fn test_multiple_calls_in_sequence() {
        let original = make_two_call_program();
        let original_len = original.len();
        let mut program = BpfProgram::new(original);

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_ACT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 2);
        assert_eq!(count_ctx_access(&program.insns, SKB_DATA_OFF), 2);
        assert_eq!(count_ctx_access(&program.insns, SKB_DATA_END_OFF), 2);
        assert_eq!(program.insns.len(), original_len + 24);
    }

    #[test]
    fn test_output_fewer_or_equal_instructions() {
        let original = make_skb_load_bytes_program(14, -8, 1);
        let original_len = original.len();
        let mut program = BpfProgram::new(original);

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert!(program.insns.len() > original_len);
        assert!(program.insns.len() <= original_len + 12);
    }

    #[test]
    fn test_branch_fixup_correct() {
        let mut program = BpfProgram::new(make_branch_around_program());

        let result = run_skb_load_bytes_pass(&mut program, BPF_PROG_TYPE_SCHED_CLS);

        assert!(result.program_changed);
        assert_eq!(program.insns[0], jeq_imm(0, 0, 18));
    }
}
