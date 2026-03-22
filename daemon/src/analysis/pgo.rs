// SPDX-License-Identifier: MIT
//! PGO (Profile-Guided Optimization) analysis.

use std::collections::HashMap;

use crate::pass::{Analysis, BpfProgram};

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

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::*;
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
}
