// SPDX-License-Identifier: MIT
// CFG (Control Flow Graph) analysis.

use std::ops::Range;

use crate::insn::{insn_width, relative_branch_target_pc, BpfInsn, BPF_PSEUDO_FUNC};
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
    pub end: usize,
}

/// Result of CFG analysis.
#[derive(Clone, Debug)]

pub struct CFGResult {
    pub blocks: Vec<BasicBlock>,
    pub insn_to_block: Vec<usize>,
    pub subprogs: Vec<SubprogRange>,
}

impl CFGResult {
    pub fn subprog_bounds(&self, pc: usize) -> Option<Range<usize>> {
        self.subprogs
            .iter()
            .find(|subprog| pc >= subprog.start && pc < subprog.end)
            .map(|subprog| subprog.start..subprog.end)
    }
}

pub struct CFGAnalysis;

pub fn subprog_bounds(insns: &[BpfInsn], pc: usize) -> (usize, usize) {
    subprog_ranges(insns)
        .into_iter()
        .find(|subprog| pc >= subprog.start && pc < subprog.end)
        .map(|subprog| (subprog.start, subprog.end))
        .unwrap_or((0, insns.len()))
}

pub fn subprog_ranges(insns: &[BpfInsn]) -> Vec<SubprogRange> {
    let n = insns.len();
    let mut starts = vec![0usize];
    starts.extend(
        collect_subprog_entries(insns)
            .into_iter()
            .filter(|&entry| entry > 0),
    );
    starts.sort_unstable();
    starts.dedup();
    starts
        .iter()
        .enumerate()
        .map(|(idx, &start)| SubprogRange {
            start,
            end: starts.get(idx + 1).copied().unwrap_or(n),
        })
        .collect()
}

fn collect_subprog_entries(insns: &[BpfInsn]) -> Vec<usize> {
    let mut entries = Vec::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = &insns[pc];
        if insn.is_ldimm64() && insn.src_reg() == BPF_PSEUDO_FUNC {
            if let Some(target) = relative_branch_target_pc(pc, i64::from(insn.imm)) {
                if target < insns.len() {
                    entries.push(target);
                }
            }
        } else if insn.is_call() && insn.src_reg() == 1 {
            if let Some(target) = relative_branch_target_pc(pc, i64::from(insn.imm)) {
                if target < insns.len() {
                    entries.push(target);
                }
            }
        }
        pc += insn_width(insn);
    }
    entries.sort_unstable();
    entries.dedup();
    entries
}

impl Analysis for CFGAnalysis {
    type Result = CFGResult;

    fn run(program: &BpfProgram) -> CFGResult {
        let n = program.insns.len();
        let mut branch_targets = vec![false; n + 1];
        let subprog_entries = collect_subprog_entries(&program.insns);
        for &target in &subprog_entries {
            branch_targets[target] = true;
        }

        // Pass 1: collect branch targets and subprog entries
        let mut pc = 0;
        while pc < n {
            let insn = &program.insns[pc];
            if insn.is_jmp_class() && !insn.is_exit() {
                if insn.is_call() {
                    // Subprogram call targets were collected above.
                } else if let Some(target) = insn.branch_target_pc(pc) {
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
                if let Some(target) = last_insn.branch_target_pc(last_pc) {
                    if target < n {
                        edges.push((bb_idx, insn_to_block[target]));
                    }
                }
            } else if last_insn.is_cond_jmp() {
                let next_pc = last_pc + 1;
                if next_pc < n {
                    edges.push((bb_idx, insn_to_block[next_pc]));
                }
                if let Some(target) = last_insn.branch_target_pc(last_pc) {
                    if target < n {
                        edges.push((bb_idx, insn_to_block[target]));
                    }
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

        CFGResult {
            blocks,
            insn_to_block,
            subprogs: subprog_ranges(&program.insns),
        }
    }
}
