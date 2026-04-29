// SPDX-License-Identifier: MIT
// CFG (Control Flow Graph) analysis.

use crate::insn::BPF_PSEUDO_FUNC;
use crate::pass::{Analysis, BpfProgram};

/// A single basic block in the CFG.
#[derive(Clone, Debug)]

pub struct BasicBlock {
    pub start: usize,
    pub end: usize,
    pub preds: Vec<usize>,
    pub succs: Vec<usize>,
}

/// Subprogram address range.
#[derive(Clone, Debug)]

pub struct SubprogRange {
    pub start: usize,
}

/// Result of CFG analysis.
#[derive(Clone, Debug)]

pub struct CFGResult {
    pub blocks: Vec<BasicBlock>,
    pub insn_to_block: Vec<usize>,
    pub subprogs: Vec<SubprogRange>,
}

pub struct CFGAnalysis;

impl Analysis for CFGAnalysis {
    type Result = CFGResult;

    fn name(&self) -> &str {
        "cfg"
    }

    fn run(&self, program: &BpfProgram) -> CFGResult {
        let n = program.insns.len();
        let mut branch_targets = vec![false; n + 1];
        let mut subprog_entries = Vec::new();

        // Pass 1: collect branch targets and subprog entries
        let mut pc = 0;
        while pc < n {
            let insn = &program.insns[pc];
            if insn.is_ldimm64() && insn.src_reg() == BPF_PSEUDO_FUNC {
                let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                if target < n {
                    branch_targets[target] = true;
                    subprog_entries.push(target);
                }
            } else if insn.is_jmp_class() && !insn.is_exit() {
                if insn.is_call() {
                    if insn.src_reg() == 1 {
                        let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                        if target < n {
                            branch_targets[target] = true;
                            subprog_entries.push(target);
                        }
                    }
                } else {
                    let target = (pc as i64 + 1 + insn.off as i64) as usize;
                    if target <= n {
                        branch_targets[target] = true;
                    }
                }
            }
            pc = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };
        }

        // Pass 2: determine basic block start positions
        let mut block_starts = vec![false; n];
        if n > 0 {
            block_starts[0] = true;
        }
        for i in 0..n {
            if branch_targets[i] {
                block_starts[i] = true;
            }
        }

        pc = 0;
        while pc < n {
            let insn = &program.insns[pc];
            let next_pc = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };
            if insn.is_jmp_class() && next_pc < n {
                block_starts[next_pc] = true;
            }
            pc = next_pc;
        }

        // Build basic block list
        let mut blocks: Vec<BasicBlock> = Vec::new();
        let mut insn_to_block = vec![0usize; n];
        let mut current_start = 0;

        for (i, &is_start) in block_starts.iter().enumerate() {
            if is_start && i > current_start {
                let bb_idx = blocks.len();
                for slot in &mut insn_to_block[current_start..i] {
                    *slot = bb_idx;
                }
                blocks.push(BasicBlock {
                    start: current_start,
                    end: i,
                    preds: Vec::new(),
                    succs: Vec::new(),
                });
                current_start = i;
            }
        }
        // Last BB
        if n > 0 {
            let bb_idx = blocks.len();
            for slot in &mut insn_to_block[current_start..n] {
                *slot = bb_idx;
            }
            blocks.push(BasicBlock {
                start: current_start,
                end: n,
                preds: Vec::new(),
                succs: Vec::new(),
            });
        }

        // Pass 3: build CFG edges
        let mut edges: Vec<(usize, usize)> = Vec::new();

        for (bb_idx, block) in blocks.iter().enumerate() {
            let block_end = block.end;
            if block_end == 0 {
                continue;
            }
            let last_pc = block_end - 1;
            let last_insn = &program.insns[last_pc];

            if last_insn.is_exit() {
                // No successors
            } else if last_insn.is_ja() {
                let target = (last_pc as i64 + 1 + last_insn.off as i64) as usize;
                if target < n {
                    edges.push((bb_idx, insn_to_block[target]));
                }
            } else if last_insn.is_cond_jmp() {
                let next_pc = last_pc + 1;
                if next_pc < n {
                    edges.push((bb_idx, insn_to_block[next_pc]));
                }
                let target = (last_pc as i64 + 1 + last_insn.off as i64) as usize;
                if target < n {
                    edges.push((bb_idx, insn_to_block[target]));
                }
            } else if last_insn.is_call() {
                let next_pc = last_pc + 1;
                if next_pc < n {
                    edges.push((bb_idx, insn_to_block[next_pc]));
                }
            } else if block_end < n {
                edges.push((bb_idx, insn_to_block[block_end]));
            }
        }

        for (from, to) in edges {
            blocks[from].succs.push(to);
            blocks[to].preds.push(from);
        }
        for block in &mut blocks {
            block.succs.sort();
            block.succs.dedup();
            block.preds.sort();
            block.preds.dedup();
        }

        // Subprog boundaries
        subprog_entries.sort();
        subprog_entries.dedup();
        let mut subprogs = vec![SubprogRange { start: 0 }];
        for &entry in &subprog_entries {
            if entry > 0 {
                subprogs.push(SubprogRange { start: entry });
            }
        }

        CFGResult {
            blocks,
            insn_to_block,
            subprogs,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::*;
    use crate::pass::BpfProgram;

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns)
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
    }

    #[test]
    fn cfg_linear_program() {
        let insns = vec![
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(1, 1),
            exit_insn(),
        ];
        let prog = make_program(insns);
        let cfg = CFGAnalysis.run(&prog);
        assert!(!cfg.blocks.is_empty());
        assert_eq!(cfg.blocks[0].start, 0);
    }

    #[test]
    fn cfg_branch_creates_blocks() {
        let insns = vec![
            BpfInsn::new(BPF_JMP | BPF_JEQ | BPF_K, BpfInsn::make_regs(1, 0), 1, 0),
            BpfInsn::nop(),
            exit_insn(),
        ];
        let prog = make_program(insns);
        let cfg = CFGAnalysis.run(&prog);
        assert!(cfg.blocks.len() >= 2);
    }
}
