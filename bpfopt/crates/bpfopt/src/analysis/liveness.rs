// SPDX-License-Identifier: MIT
// Per-instruction liveness analysis.

use std::collections::HashSet;

use crate::insn::*;
use crate::pass::{Analysis, BpfProgram};

/// Per-instruction liveness: which registers are live before/after each insn.
#[derive(Clone, Debug)]

pub struct LivenessResult {
    pub live_out: Vec<HashSet<u8>>,
    pub use_def: Vec<RegUseDefSet>,
}

impl LivenessResult {
    pub fn use_def_at(&self, pc: usize) -> Option<&RegUseDefSet> {
        self.use_def.get(pc)
    }
}

#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct RegUseDefSet {
    pub uses: HashSet<u8>,
    pub defs: HashSet<u8>,
}

pub struct LivenessAnalysis;

impl Analysis for LivenessAnalysis {
    type Result = LivenessResult;

    fn run(program: &BpfProgram) -> LivenessResult {
        let n = program.insns.len();
        let use_def: Vec<_> = program.insns.iter().map(insn_use_def_set).collect();
        let mut live_in = vec![HashSet::new(); n];
        let mut live_out = vec![HashSet::new(); n];

        // Standard backward dataflow to fixed point.
        let mut updated = true;
        while updated {
            updated = false;
            for pc in (0..n).rev() {
                let RegUseDefSet { uses, defs } = &use_def[pc];

                let mut new_out = HashSet::new();
                for s in get_successors(program, pc) {
                    if s < n {
                        new_out.extend(&live_in[s]);
                    }
                }

                let mut new_in: HashSet<u8> = new_out.difference(defs).cloned().collect();
                new_in.extend(uses);

                if new_in != live_in[pc] || new_out != live_out[pc] {
                    live_in[pc] = new_in;
                    live_out[pc] = new_out;
                    updated = true;
                }
            }
        }

        LivenessResult { live_out, use_def }
    }
}

pub fn insn_use_def_set(insn: &BpfInsn) -> RegUseDefSet {
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

    RegUseDefSet { uses, defs }
}

/// Get successor PCs for instruction at `pc`.
fn get_successors(program: &BpfProgram, pc: usize) -> Vec<usize> {
    let insn = &program.insns[pc];
    let mut succs = Vec::new();
    let next = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };

    if insn.is_exit() {
        // No successors
    } else if insn.is_ja() {
        if let Some(target) = insn.branch_target_pc(pc) {
            succs.push(target);
        }
    } else if insn.is_cond_jmp() {
        succs.push(next);
        if let Some(target) = insn.branch_target_pc(pc) {
            succs.push(target);
        }
    } else {
        succs.push(next);
    }

    succs
}
