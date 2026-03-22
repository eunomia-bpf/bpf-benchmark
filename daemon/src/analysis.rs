// SPDX-License-Identifier: MIT
//! Concrete analysis implementations for the pass framework.
//!
//! - `BranchTargetAnalysis` — lightweight branch target set
//! - `CFGAnalysis` — basic blocks, branch targets, pred/succ edges
//! - `LivenessAnalysis` — per-insn live-in/live-out register sets
//! - `PGOAnalysis` — program-level profiling data

use std::collections::{HashMap, HashSet};

use crate::insn::*;
use crate::pass::{Analysis, BpfProgram};

// ═══════════════════════════════════════════════════════════════════
// BranchTargetAnalysis
// ═══════════════════════════════════════════════════════════════════

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
            if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
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

// ═══════════════════════════════════════════════════════════════════
// CFGAnalysis
// ═══════════════════════════════════════════════════════════════════

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
    pub branch_targets: Vec<bool>,
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
            if insn.is_jmp_class() && !insn.is_exit() {
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

        for i in 0..n {
            if block_starts[i] && i > current_start {
                let bb_idx = blocks.len();
                for j in current_start..i {
                    insn_to_block[j] = bb_idx;
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
            for j in current_start..n {
                insn_to_block[j] = bb_idx;
            }
            blocks.push(BasicBlock {
                start: current_start,
                end: n,
                preds: Vec::new(),
                succs: Vec::new(),
            });
        }

        // Pass 3: build CFG edges
        let num_blocks = blocks.len();
        let mut edges: Vec<(usize, usize)> = Vec::new();

        for bb_idx in 0..num_blocks {
            let block_end = blocks[bb_idx].end;
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
        let mut subprogs = vec![SubprogRange { start: 0, end: n }];
        for &entry in &subprog_entries {
            if entry > 0 {
                subprogs.push(SubprogRange {
                    start: entry,
                    end: n,
                });
            }
        }

        CFGResult {
            blocks,
            insn_to_block,
            branch_targets,
            subprogs,
        }
    }
}

// ═══════════════════════════════════════════════════════════════════
// LivenessAnalysis
// ═══════════════════════════════════════════════════════════════════

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
                for r in 1..=5 {
                    uses.insert(r);
                }
                defs.insert(0);
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

// ═══════════════════════════════════════════════════════════════════
// PGOAnalysis
// ═══════════════════════════════════════════════════════════════════

/// PGO branch profile for a single branch instruction.
#[derive(Clone, Debug)]
pub struct PGOBranchProfile {
    pub taken_count: u64,
    pub not_taken_count: u64,
}

/// PGO analysis result.
#[derive(Clone, Debug)]
pub struct PGOResult {
    pub run_cnt: u64,
    pub run_time_ns: u64,
    pub avg_ns_per_run: f64,
    pub branch_stats: HashMap<usize, PGOBranchProfile>,
    pub hot_blocks: Vec<usize>,
}

/// External profiling data injected into the analysis.
#[derive(Clone, Debug, Default)]
pub struct ProfilingData {
    pub run_cnt: u64,
    pub run_time_ns: u64,
    pub branch_samples: HashMap<usize, PGOBranchProfile>,
}

pub struct PGOAnalysis {
    pub profiling_data: Option<ProfilingData>,
}

impl Analysis for PGOAnalysis {
    type Result = PGOResult;

    fn name(&self) -> &str {
        "pgo"
    }

    fn run(&self, program: &BpfProgram) -> PGOResult {
        let run_cnt = program.meta.run_cnt;
        let run_time_ns = program.meta.run_time_ns;
        let avg = if run_cnt > 0 {
            run_time_ns as f64 / run_cnt as f64
        } else {
            0.0
        };

        let branch_stats = if let Some(ref data) = self.profiling_data {
            data.branch_samples.clone()
        } else {
            HashMap::new()
        };

        PGOResult {
            run_cnt,
            run_time_ns,
            avg_ns_per_run: avg,
            branch_stats,
            hot_blocks: Vec::new(),
        }
    }
}

// ═══════════════════════════════════════════════════════════════════
// Tests
// ═══════════════════════════════════════════════════════════════════

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::*;
    use crate::pass::{AnalysisCache, BpfProgram, ProgMeta};

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

    // ── BranchTargetAnalysis ────────────────────────────────────────

    #[test]
    fn branch_target_simple_ja() {
        let insns = vec![
            BpfInsn::ja(2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(1, 1),
            exit_insn(),
        ];
        let prog = make_program(insns);
        let result = BranchTargetAnalysis.run(&prog);
        assert!(!result.is_target[0]);
        assert!(!result.is_target[1]);
        assert!(!result.is_target[2]);
        assert!(result.is_target[3]);
    }

    #[test]
    fn branch_target_cond_jmp() {
        let insns = vec![
            BpfInsn {
                code: BPF_JMP | BPF_JEQ | BPF_K,
                regs: BpfInsn::make_regs(1, 0),
                off: 1,
                imm: 0,
            },
            BpfInsn::nop(),
            exit_insn(),
        ];
        let prog = make_program(insns);
        let result = BranchTargetAnalysis.run(&prog);
        assert!(result.is_target[2]);
    }

    #[test]
    fn branch_target_no_branches() {
        let insns = vec![BpfInsn::mov64_imm(0, 42), exit_insn()];
        let prog = make_program(insns);
        let result = BranchTargetAnalysis.run(&prog);
        assert!(!result.is_target[0]);
        assert!(!result.is_target[1]);
    }

    // ── CFGAnalysis ─────────────────────────────────────────────────

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
            BpfInsn {
                code: BPF_JMP | BPF_JEQ | BPF_K,
                regs: BpfInsn::make_regs(1, 0),
                off: 1,
                imm: 0,
            },
            BpfInsn::nop(),
            exit_insn(),
        ];
        let prog = make_program(insns);
        let cfg = CFGAnalysis.run(&prog);
        assert!(cfg.blocks.len() >= 2);
    }

    // ── LivenessAnalysis ────────────────────────────────────────────

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

    // ── PGOAnalysis ─────────────────────────────────────────────────

    #[test]
    fn pgo_uses_prog_meta() {
        let mut prog = make_program(vec![BpfInsn::nop(), exit_insn()]);
        prog.meta.run_cnt = 100;
        prog.meta.run_time_ns = 5000;
        let pgo = PGOAnalysis {
            profiling_data: None,
        };
        let result = pgo.run(&prog);
        assert_eq!(result.run_cnt, 100);
        assert!((result.avg_ns_per_run - 50.0).abs() < 0.01);
    }

    // ── AnalysisCache integration ───────────────────────────────────

    #[test]
    fn cache_branch_target() {
        let prog = make_program(vec![BpfInsn::ja(1), BpfInsn::nop(), exit_insn()]);
        let mut cache = AnalysisCache::new();
        let r1 = cache.get(&BranchTargetAnalysis, &prog);
        let r2 = cache.get(&BranchTargetAnalysis, &prog);
        assert_eq!(r1.is_target, r2.is_target);
    }

    #[test]
    fn cache_invalidation() {
        let prog = make_program(vec![BpfInsn::ja(1), BpfInsn::nop(), exit_insn()]);
        let mut cache = AnalysisCache::new();
        let _ = cache.get(&BranchTargetAnalysis, &prog);
        cache.invalidate_all();
        // After invalidation, get() should recompute
        let r = cache.get(&BranchTargetAnalysis, &prog);
        assert!(r.is_target[2]); // ja +1 targets pc=2
    }

    // ── insn_use_def ────────────────────────────────────────────────

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
        assert!(defs.contains(&0));
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
