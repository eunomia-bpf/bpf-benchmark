// SPDX-License-Identifier: MIT
//! Dangerous helper firewall security pass.

use std::collections::{BTreeMap, HashSet};

use crate::analysis::{BranchTargetAnalysis, BranchTargetResult, LivenessAnalysis, LivenessResult};
use crate::insn::*;
use crate::pass::*;

use super::utils::fixup_all_branches;

const BPF_ADD: u8 = 0x00;
const BPF_SUB: u8 = 0x10;

const BPF_FUNC_PROBE_READ: i32 = 4;
const BPF_FUNC_KTIME_GET_NS: i32 = 5;
const BPF_FUNC_PROBE_WRITE_USER: i32 = 36;
const BPF_FUNC_PROBE_READ_STR: i32 = 45;
const BPF_FUNC_OVERRIDE_RETURN: i32 = 58;
const BPF_FUNC_SKB_ADJUST_ROOM: i32 = 50;
const BPF_FUNC_SKB_CHANGE_TAIL: i32 = 38;
const BPF_FUNC_SKB_STORE_BYTES: i32 = 9;
const BPF_FUNC_XDP_ADJUST_HEAD: i32 = 44;
const BPF_FUNC_XDP_ADJUST_TAIL: i32 = 65;
const BPF_FUNC_SEND_SIGNAL: i32 = 109;
const BPF_FUNC_PROBE_READ_USER: i32 = 112;
const BPF_FUNC_PROBE_READ_KERNEL: i32 = 113;
const BPF_FUNC_PROBE_READ_USER_STR: i32 = 114;
const BPF_FUNC_PROBE_READ_KERNEL_STR: i32 = 115;
const BPF_FUNC_SEND_SIGNAL_THREAD: i32 = 117;
const BPF_FUNC_JIFFIES64: i32 = 118;
const BPF_FUNC_KTIME_GET_BOOT_NS: i32 = 125;
const BPF_FUNC_D_PATH: i32 = 147;
const BPF_FUNC_COPY_FROM_USER: i32 = 148;
const BPF_FUNC_SNPRINTF_BTF: i32 = 149;
const BPF_FUNC_KTIME_GET_COARSE_NS: i32 = 160;
const BPF_FUNC_FIND_VMA: i32 = 180;
const BPF_FUNC_SET_RETVAL: i32 = 187;
const BPF_FUNC_XDP_STORE_BYTES: i32 = 190;
const BPF_FUNC_COPY_FROM_USER_TASK: i32 = 191;

#[derive(Clone, Copy)]
enum HelperAction {
    Deny { cleanup_args: &'static [u8] },
    Coarseify { replacement_id: i32 },
    Audit,
}

#[derive(Clone, Copy)]
struct HelperRule {
    helper_name: &'static str,
    action: HelperAction,
}

fn helper_rule(helper_id: i32) -> Option<HelperRule> {
    let rule = match helper_id {
        BPF_FUNC_OVERRIDE_RETURN => HelperRule {
            helper_name: "override_return",
            action: HelperAction::Deny { cleanup_args: &[] },
        },
        BPF_FUNC_SEND_SIGNAL => HelperRule {
            helper_name: "send_signal",
            action: HelperAction::Deny { cleanup_args: &[1] },
        },
        BPF_FUNC_SEND_SIGNAL_THREAD => HelperRule {
            helper_name: "send_signal_thread",
            action: HelperAction::Deny { cleanup_args: &[1] },
        },
        BPF_FUNC_SET_RETVAL => HelperRule {
            helper_name: "set_retval",
            action: HelperAction::Deny { cleanup_args: &[] },
        },
        BPF_FUNC_KTIME_GET_NS => HelperRule {
            helper_name: "ktime_get_ns",
            action: HelperAction::Coarseify {
                replacement_id: BPF_FUNC_KTIME_GET_COARSE_NS,
            },
        },
        BPF_FUNC_PROBE_READ => HelperRule {
            helper_name: "probe_read",
            action: HelperAction::Audit,
        },
        BPF_FUNC_PROBE_READ_STR => HelperRule {
            helper_name: "probe_read_str",
            action: HelperAction::Audit,
        },
        BPF_FUNC_PROBE_READ_USER => HelperRule {
            helper_name: "probe_read_user",
            action: HelperAction::Audit,
        },
        BPF_FUNC_PROBE_READ_KERNEL => HelperRule {
            helper_name: "probe_read_kernel",
            action: HelperAction::Audit,
        },
        BPF_FUNC_PROBE_READ_USER_STR => HelperRule {
            helper_name: "probe_read_user_str",
            action: HelperAction::Audit,
        },
        BPF_FUNC_PROBE_READ_KERNEL_STR => HelperRule {
            helper_name: "probe_read_kernel_str",
            action: HelperAction::Audit,
        },
        BPF_FUNC_PROBE_WRITE_USER => HelperRule {
            helper_name: "probe_write_user",
            action: HelperAction::Audit,
        },
        BPF_FUNC_SKB_STORE_BYTES => HelperRule {
            helper_name: "skb_store_bytes",
            action: HelperAction::Audit,
        },
        BPF_FUNC_SKB_CHANGE_TAIL => HelperRule {
            helper_name: "skb_change_tail",
            action: HelperAction::Audit,
        },
        BPF_FUNC_SKB_ADJUST_ROOM => HelperRule {
            helper_name: "skb_adjust_room",
            action: HelperAction::Audit,
        },
        BPF_FUNC_XDP_ADJUST_HEAD => HelperRule {
            helper_name: "xdp_adjust_head",
            action: HelperAction::Audit,
        },
        BPF_FUNC_XDP_ADJUST_TAIL => HelperRule {
            helper_name: "xdp_adjust_tail",
            action: HelperAction::Audit,
        },
        BPF_FUNC_JIFFIES64 => HelperRule {
            helper_name: "jiffies64",
            action: HelperAction::Audit,
        },
        BPF_FUNC_KTIME_GET_BOOT_NS => HelperRule {
            helper_name: "ktime_get_boot_ns",
            action: HelperAction::Audit,
        },
        BPF_FUNC_D_PATH => HelperRule {
            helper_name: "d_path",
            action: HelperAction::Audit,
        },
        BPF_FUNC_COPY_FROM_USER => HelperRule {
            helper_name: "copy_from_user",
            action: HelperAction::Audit,
        },
        BPF_FUNC_SNPRINTF_BTF => HelperRule {
            helper_name: "snprintf_btf",
            action: HelperAction::Audit,
        },
        BPF_FUNC_FIND_VMA => HelperRule {
            helper_name: "find_vma",
            action: HelperAction::Audit,
        },
        BPF_FUNC_XDP_STORE_BYTES => HelperRule {
            helper_name: "xdp_store_bytes",
            action: HelperAction::Audit,
        },
        BPF_FUNC_COPY_FROM_USER_TASK => HelperRule {
            helper_name: "copy_from_user_task",
            action: HelperAction::Audit,
        },
        _ => return None,
    };

    Some(rule)
}

fn audit_reason(helper_name: &str, helper_id: i32) -> String {
    format!("audit-only dangerous helper {helper_name} (#{helper_id})")
}

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
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        if program.insns.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![],
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let bt = analyses.get(&BranchTargetAnalysis, program);
        let liveness = analyses.get(&LivenessAnalysis, program);
        let old_insns = program.insns.clone();

        let mut replacements: BTreeMap<usize, BpfInsn> = BTreeMap::new();
        let mut deleted_pcs = HashSet::new();
        let mut sites_skipped = Vec::new();
        let mut diagnostics = Vec::new();
        let mut sites_applied = 0usize;
        let mut pc = 0usize;

        while pc < old_insns.len() {
            let insn = &old_insns[pc];
            if insn.is_call() && insn.src_reg() == 0 {
                if let Some(rule) = helper_rule(insn.imm) {
                    match rule.action {
                        HelperAction::Deny { cleanup_args } => {
                            replacements.insert(pc, BpfInsn::mov64_imm(0, -1));
                            if !cleanup_args.is_empty() {
                                for cleanup_pc in collect_cleanup_pcs(
                                    &old_insns,
                                    pc,
                                    &bt,
                                    &liveness,
                                    cleanup_args,
                                ) {
                                    deleted_pcs.insert(cleanup_pc);
                                }
                            }
                            sites_applied += 1;
                        }
                        HelperAction::Coarseify { replacement_id } => {
                            let mut coarse_call = *insn;
                            coarse_call.imm = replacement_id;
                            replacements.insert(pc, coarse_call);
                            sites_applied += 1;
                        }
                        HelperAction::Audit => {
                            let reason = audit_reason(rule.helper_name, insn.imm);
                            sites_skipped.push(SkipReason {
                                pc,
                                reason: reason.clone(),
                            });
                            diagnostics.push(format!("pc {pc}: {reason}"));
                        }
                    }
                }
            }

            pc += insn_width(insn);
        }

        if sites_applied == 0 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped,
                diagnostics,
                ..Default::default()
            });
        }

        if deleted_pcs.is_empty() {
            for (pc, replacement) in replacements {
                program.insns[pc] = replacement;
            }
        } else {
            let (mut new_insns, addr_map) =
                rebuild_program(&old_insns, &replacements, &deleted_pcs);
            fixup_all_branches(&mut new_insns, &old_insns, &addr_map);
            program.insns = new_insns;
            program.remap_annotations(&addr_map);
        }

        program.log_transform(TransformEntry { sites_applied });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied,
            sites_skipped,
            diagnostics,
            ..Default::default()
        })
    }
}

fn rebuild_program(
    old_insns: &[BpfInsn],
    replacements: &BTreeMap<usize, BpfInsn>,
    deleted_pcs: &HashSet<usize>,
) -> (Vec<BpfInsn>, Vec<usize>) {
    let orig_len = old_insns.len();
    let mut new_insns = Vec::with_capacity(orig_len);
    let mut addr_map = vec![0usize; orig_len + 1];
    let mut pc = 0usize;

    while pc < orig_len {
        let width = insn_width(&old_insns[pc]);
        let new_pc = new_insns.len();

        if deleted_pcs.contains(&pc) {
            for slot in 0..width {
                addr_map[pc + slot] = new_pc;
            }
            pc += width;
            continue;
        }

        addr_map[pc] = new_pc;
        if let Some(replacement) = replacements.get(&pc) {
            new_insns.push(*replacement);
            pc += width;
            continue;
        }

        new_insns.push(old_insns[pc]);
        if width == 2 && pc + 1 < orig_len {
            addr_map[pc + 1] = new_insns.len();
            new_insns.push(old_insns[pc + 1]);
        }
        pc += width;
    }

    addr_map[orig_len] = new_insns.len();
    (new_insns, addr_map)
}

fn collect_cleanup_pcs(
    insns: &[BpfInsn],
    call_pc: usize,
    bt: &BranchTargetResult,
    liveness: &LivenessResult,
    arg_regs: &[u8],
) -> Vec<usize> {
    let mut cleanup = Vec::new();
    for &arg_reg in arg_regs {
        cleanup.extend(collect_arg_cleanup_pcs(
            insns, call_pc, bt, liveness, arg_reg,
        ));
    }
    cleanup.sort_unstable();
    cleanup.dedup();
    cleanup
}

fn collect_arg_cleanup_pcs(
    insns: &[BpfInsn],
    call_pc: usize,
    bt: &BranchTargetResult,
    liveness: &LivenessResult,
    arg_reg: u8,
) -> Vec<usize> {
    if liveness
        .live_out
        .get(call_pc)
        .is_some_and(|live_out| live_out.contains(&arg_reg))
    {
        return Vec::new();
    }

    let mut cleanup = Vec::new();
    let mut cursor = call_pc;

    while let Some(pc) = prev_insn_pc(insns, cursor) {
        if bt.is_target.get(pc).copied().unwrap_or(false) {
            return Vec::new();
        }

        let insn = &insns[pc];
        if insn.is_jmp_class() {
            return Vec::new();
        }
        if insn_uses_reg(insn, arg_reg) && !insn_defines_reg(insn, arg_reg) {
            return Vec::new();
        }

        if !insn_defines_reg(insn, arg_reg) {
            cursor = pc;
            continue;
        }

        if is_terminal_arg_setup(insn, arg_reg) {
            cleanup.push(pc);
            if insn.is_ldimm64() {
                cleanup.push(pc + 1);
            }
            return cleanup;
        }

        if is_chained_arg_update(insn, arg_reg) {
            cleanup.push(pc);
            cursor = pc;
            continue;
        }

        return Vec::new();
    }

    Vec::new()
}

fn is_terminal_arg_setup(insn: &BpfInsn, arg_reg: u8) -> bool {
    if insn.is_ldimm64() {
        return insn.dst_reg() == arg_reg;
    }

    insn.class() == BPF_ALU64 && bpf_op(insn.code) == BPF_MOV && insn.dst_reg() == arg_reg
}

fn is_chained_arg_update(insn: &BpfInsn, arg_reg: u8) -> bool {
    insn.class() == BPF_ALU64
        && bpf_src(insn.code) == BPF_K
        && insn.dst_reg() == arg_reg
        && matches!(bpf_op(insn.code), BPF_ADD | BPF_SUB)
}

fn prev_insn_pc(insns: &[BpfInsn], pc: usize) -> Option<usize> {
    if pc == 0 {
        return None;
    }

    if pc >= 2 && insns[pc - 2].is_ldimm64() {
        Some(pc - 2)
    } else {
        Some(pc - 1)
    }
}

fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}

fn insn_uses_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU => {
            if bpf_op(insn.code) == BPF_MOV {
                bpf_src(insn.code) == BPF_X && insn.src_reg() == reg
            } else {
                insn.dst_reg() == reg || (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
            }
        }
        BPF_LDX => insn.src_reg() == reg,
        BPF_ST => insn.dst_reg() == reg,
        BPF_STX => insn.dst_reg() == reg || insn.src_reg() == reg,
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                (1..=5).contains(&reg)
            } else if insn.is_exit() {
                reg == 0
            } else if insn.is_ja() {
                false
            } else {
                insn.dst_reg() == reg || (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
            }
        }
        _ => false,
    }
}

fn insn_defines_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD => insn.dst_reg() == reg,
        BPF_JMP | BPF_JMP32 => insn.is_call() && reg <= 5,
        _ => false,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
    use crate::pass::{BpfProgram, PassContext, PassManager, PipelineResult};

    const BPF_ADD: u8 = 0x00;

    const BPF_PROG_TYPE_TRACEPOINT: u32 = 5;

    const BPF_FUNC_MAP_LOOKUP_ELEM: i32 = 1;
    const BPF_FUNC_KTIME_GET_NS: i32 = 5;
    const BPF_FUNC_OVERRIDE_RETURN: i32 = 58;
    const BPF_FUNC_SEND_SIGNAL: i32 = 109;
    const BPF_FUNC_SEND_SIGNAL_THREAD: i32 = 117;
    const BPF_FUNC_PROBE_READ_KERNEL: i32 = 113;
    const BPF_FUNC_KTIME_GET_COARSE_NS: i32 = 160;
    const BPF_FUNC_COPY_FROM_USER_TASK: i32 = 191;

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
        ctx.policy.enabled_passes = vec!["dangerous_helper_firewall".to_string()];
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
    fn test_send_signal_thread_replaced() {
        let mut program = BpfProgram::new(make_single_helper_program(BPF_FUNC_SEND_SIGNAL_THREAD));

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
    fn test_copy_from_user_task_audit_only() {
        let original = make_single_helper_program(BPF_FUNC_COPY_FROM_USER_TASK);
        let mut program = BpfProgram::new(original.clone());

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason == audit_reason("copy_from_user_task", 191)));
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

    #[test]
    fn test_cleanup_does_not_remove_live_arg_setup() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(1, 7),
            helper_call(BPF_FUNC_SEND_SIGNAL),
            BpfInsn::mov64_reg(6, 1),
            BpfInsn::mov64_reg(0, 6),
            exit_insn(),
        ]);

        let result = run_dangerous_helper_pass(&mut program, BPF_PROG_TYPE_TRACEPOINT);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(1, 7),
                BpfInsn::mov64_imm(0, -1),
                BpfInsn::mov64_reg(6, 1),
                BpfInsn::mov64_reg(0, 6),
                exit_insn(),
            ],
        );
    }
}
