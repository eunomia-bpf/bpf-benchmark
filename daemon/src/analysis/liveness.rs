// SPDX-License-Identifier: MIT
//! Per-instruction liveness analysis.

use std::collections::HashSet;

use crate::insn::*;
use crate::pass::{Analysis, BpfProgram};

/// Per-instruction liveness: which registers are live before/after each insn.
#[derive(Clone, Debug)]

pub struct LivenessResult {
    pub live_in: Vec<HashSet<u8>>,
    pub live_out: Vec<HashSet<u8>>,
}

pub struct LivenessAnalysis;

impl Analysis for LivenessAnalysis {
    type Result = LivenessResult;

    fn name(&self) -> &str {
        "liveness"
    }

    fn run(&self, program: &BpfProgram) -> LivenessResult {
        let n = program.insns.len();
        let mut live_in = vec![HashSet::new(); n];
        let mut live_out = vec![HashSet::new(); n];

        // Standard backward dataflow to fixed point.
        let mut changed = true;
        while changed {
            changed = false;
            for pc in (0..n).rev() {
                let insn = &program.insns[pc];
                let (uses, defs) = insn_use_def(insn);

                let mut new_out = HashSet::new();
                for s in get_successors(program, pc) {
                    if s < n {
                        new_out.extend(&live_in[s]);
                    }
                }

                let mut new_in: HashSet<u8> = new_out.difference(&defs).cloned().collect();
                new_in.extend(&uses);

                if new_in != live_in[pc] || new_out != live_out[pc] {
                    live_in[pc] = new_in;
                    live_out[pc] = new_out;
                    changed = true;
                }
            }
        }

        LivenessResult { live_in, live_out }
    }
}

/// Compute use/def register sets for a single instruction.
pub fn insn_use_def(insn: &BpfInsn) -> (HashSet<u8>, HashSet<u8>) {
    let mut uses = HashSet::new();
    let mut defs = HashSet::new();

    let class = insn.class();

    match class {
        BPF_ALU64 | BPF_ALU => {
            let op = bpf_op(insn.code);
            if op == BPF_MOV {
                defs.insert(insn.dst_reg());
                if bpf_src(insn.code) == BPF_X {
                    uses.insert(insn.src_reg());
                }
            } else {
                defs.insert(insn.dst_reg());
                uses.insert(insn.dst_reg());
                if bpf_src(insn.code) == BPF_X {
                    uses.insert(insn.src_reg());
                }
            }
        }
        BPF_LDX => {
            defs.insert(insn.dst_reg());
            uses.insert(insn.src_reg());
        }
        BPF_ST | BPF_STX => {
            uses.insert(insn.dst_reg());
            if class == BPF_STX {
                uses.insert(insn.src_reg());
            }
        }
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                // BPF calling convention: r1-r5 are arguments (used),
                // r0 is return value (defined), r1-r5 are clobbered (defined).
                for r in 1..=5 {
                    uses.insert(r);
                }
                for r in 0..=5 {
                    defs.insert(r);
                }
            } else if insn.is_exit() {
                uses.insert(0);
            } else {
                if bpf_src(insn.code) == BPF_X {
                    uses.insert(insn.src_reg());
                }
                if !insn.is_ja() {
                    uses.insert(insn.dst_reg());
                }
            }
        }
        BPF_LD => {
            defs.insert(insn.dst_reg());
        }
        _ => {}
    }

    (uses, defs)
}

/// Get successor PCs for instruction at `pc`.
fn get_successors(program: &BpfProgram, pc: usize) -> Vec<usize> {
    let insn = &program.insns[pc];
    let mut succs = Vec::new();
    let next = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };

    if insn.is_exit() {
        // No successors
    } else if insn.is_ja() {
        succs.push((pc as i64 + 1 + insn.off as i64) as usize);
    } else if insn.is_cond_jmp() {
        succs.push(next);
        succs.push((pc as i64 + 1 + insn.off as i64) as usize);
    } else {
        succs.push(next);
    }

    succs
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::pass::{BpfProgram, ProgMeta};

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns, ProgMeta::default())
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
    fn liveness_simple_def_use() {
        let insns = vec![BpfInsn::mov64_imm(0, 42), exit_insn()];
        let prog = make_program(insns);
        let liveness = LivenessAnalysis.run(&prog);
        assert!(liveness.live_out[0].contains(&0));
        assert!(liveness.live_in[1].contains(&0));
    }

    #[test]
    fn liveness_register_killed() {
        let insns = vec![
            BpfInsn::mov64_imm(1, 10),
            BpfInsn::mov64_reg(0, 1),
            exit_insn(),
        ];
        let prog = make_program(insns);
        let liveness = LivenessAnalysis.run(&prog);
        assert!(liveness.live_out[0].contains(&1));
        assert!(!liveness.live_out[1].contains(&1));
        assert!(liveness.live_out[1].contains(&0));
    }

    #[test]
    fn liveness_branch_merges() {
        let insns = vec![
            BpfInsn {
                code: BPF_JMP | BPF_JEQ | BPF_K,
                regs: BpfInsn::make_regs(1, 0),
                off: 1,
                imm: 0,
            },
            BpfInsn::mov64_imm(2, 5),
            BpfInsn::mov64_reg(0, 2),
            exit_insn(),
        ];
        let prog = make_program(insns);
        let liveness = LivenessAnalysis.run(&prog);
        assert!(liveness.live_in[2].contains(&2));
    }

    #[test]
    fn use_def_alu_imm() {
        let insn = BpfInsn::alu64_imm(BPF_LSH, 1, 8);
        let (uses, defs) = insn_use_def(&insn);
        assert!(uses.contains(&1));
        assert!(defs.contains(&1));
    }

    #[test]
    fn use_def_mov_reg() {
        let insn = BpfInsn::mov64_reg(0, 1);
        let (uses, defs) = insn_use_def(&insn);
        assert!(uses.contains(&1));
        assert!(!uses.contains(&0));
        assert!(defs.contains(&0));
    }

    #[test]
    fn use_def_call() {
        let insn = BpfInsn::call_kfunc(42);
        let (uses, defs) = insn_use_def(&insn);
        for r in 1..=5 {
            assert!(uses.contains(&r));
        }
        // BPF calling convention: r0 = return value, r1-r5 = clobbered
        for r in 0..=5 {
            assert!(defs.contains(&r), "r{} should be in defs for call", r);
        }
    }

    #[test]
    fn liveness_call_clobbers_caller_saved() {
        // After a call, r1-r5 are dead (clobbered).
        // r6 is callee-saved, so it should remain live across the call.
        let insns = vec![
            BpfInsn::mov64_imm(6, 42), // r6 = 42
            BpfInsn::mov64_imm(1, 1),  // r1 = 1 (arg)
            BpfInsn::call_kfunc(99),   // call; clobbers r0-r5
            BpfInsn::mov64_reg(0, 6),  // r0 = r6 (use callee-saved)
            exit_insn(),
        ];
        let prog = make_program(insns);
        let liveness = LivenessAnalysis.run(&prog);
        // r6 should be live across the call (live_out[2] should contain r6)
        assert!(liveness.live_out[2].contains(&6));
        // r1 should NOT be live after the call (it's clobbered)
        assert!(!liveness.live_out[2].contains(&1));
    }

    #[test]
    fn use_def_exit() {
        let (uses, defs) = insn_use_def(&exit_insn());
        assert!(uses.contains(&0));
        assert!(defs.is_empty());
    }

    #[test]
    fn use_def_ldx() {
        let insn = BpfInsn::ldx_mem(BPF_W, 0, 6, 4);
        let (uses, defs) = insn_use_def(&insn);
        assert!(uses.contains(&6));
        assert!(defs.contains(&0));
    }

    #[test]
    fn use_def_stx() {
        let insn = BpfInsn::stx_mem(BPF_DW, 10, 1, -8);
        let (uses, _defs) = insn_use_def(&insn);
        assert!(uses.contains(&10));
        assert!(uses.contains(&1));
    }
}
