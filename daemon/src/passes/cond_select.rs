// SPDX-License-Identifier: MIT
//! COND_SELECT detection pass.

use crate::insn::*;
use crate::pass::*;

/// COND_SELECT detection pass: identifies branch+mov diamond patterns that
/// could be replaced with a bpf_select64() kfunc call (CMOV).
///
/// Currently detection-only: `analyze()` returns a list of candidate sites.
/// The `BpfPass::run()` implementation performs analysis and reports sites
/// in diagnostics but does not modify the instruction stream.
///
/// Pattern A (4-insn diamond):
///   Jcc r_cond, X, +2 ; MOV r_dst, val_false ; JA +1 ; MOV r_dst, val_true
///
/// Pattern B (3-insn / JCC +1):
///   Jcc r_cond, X, +1 ; MOV r_dst, val_false ; MOV r_dst, val_true
pub struct CondSelectPass {
    /// Predictability threshold: skip if branch is more predictable than this
    /// (e.g., 0.8 means skip if >80% one direction).
    pub predictability_threshold: f64,
}

/// A detected cond-select site.
pub struct CondSelectSite {
    pub start_pc: usize,
    pub old_len: usize,
    pub cond_reg: u8,
    pub dst_reg: u8,
    pub true_val: CondSelectValue,
    pub false_val: CondSelectValue,
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub enum CondSelectValue {
    Reg(u8),
    Imm(i32),
}

impl CondSelectPass {
    /// Analyze the program and return all detected cond-select sites.
    ///
    /// This is the pure detection phase. Each returned `CondSelectSite`
    /// describes a JCC+MOV pattern that could be lowered to a CMOV/kfunc.
    pub fn analyze(&self, insns: &[BpfInsn]) -> Vec<CondSelectSite> {
        scan_cond_select_sites(insns)
    }
}

impl BpfPass for CondSelectPass {
    fn name(&self) -> &str {
        "cond_select"
    }

    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // Detection only — scan for sites and report them.
        let sites = self.analyze(&program.insns);
        let diagnostics: Vec<String> = sites
            .iter()
            .map(|s| {
                format!(
                    "cond_select site: pc={} len={} cond=r{} dst=r{}",
                    s.start_pc, s.old_len, s.cond_reg, s.dst_reg
                )
            })
            .collect();

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: false,
            sites_applied: 0,
            sites_skipped: vec![],
            diagnostics,
        })
    }
}

fn scan_cond_select_sites(insns: &[BpfInsn]) -> Vec<CondSelectSite> {
    let mut sites = Vec::new();
    let n = insns.len();
    let mut pc = 0;
    while pc < n {
        if let Some(site) = try_match_cond_select(insns, pc) {
            let len = site.old_len;
            sites.push(site);
            pc += len;
        } else {
            pc += 1;
        }
    }
    sites
}

fn try_match_cond_select(insns: &[BpfInsn], pc: usize) -> Option<CondSelectSite> {
    let n = insns.len();

    // Pattern A: 4-insn diamond
    //   Jcc +2 ; MOV dst, false_val ; JA +1 ; MOV dst, true_val
    if pc + 3 < n {
        let jcc = &insns[pc];
        if jcc.is_cond_jmp() && jcc.off == 2 {
            let mov_false = &insns[pc + 1];
            let ja = &insns[pc + 2];
            let mov_true = &insns[pc + 3];

            if is_mov64(mov_false) && ja.is_ja() && ja.off == 1 && is_mov64(mov_true) {
                let dst_f = mov_false.dst_reg();
                let dst_t = mov_true.dst_reg();
                if dst_f == dst_t {
                    return Some(CondSelectSite {
                        start_pc: pc,
                        old_len: 4,
                        cond_reg: jcc.dst_reg(),
                        dst_reg: dst_f,
                        true_val: extract_mov_value(mov_true),
                        false_val: extract_mov_value(mov_false),
                    });
                }
            }
        }
    }

    // Pattern B: 3-insn
    //   Jcc +1 ; MOV dst, false_val ; MOV dst, true_val
    if pc + 2 < n {
        let jcc = &insns[pc];
        if jcc.is_cond_jmp() && jcc.off == 1 {
            let mov_false = &insns[pc + 1];
            let mov_true = &insns[pc + 2];

            if is_mov64(mov_false) && is_mov64(mov_true) {
                let dst_f = mov_false.dst_reg();
                let dst_t = mov_true.dst_reg();
                if dst_f == dst_t {
                    return Some(CondSelectSite {
                        start_pc: pc,
                        old_len: 3,
                        cond_reg: jcc.dst_reg(),
                        dst_reg: dst_f,
                        true_val: extract_mov_value(mov_true),
                        false_val: extract_mov_value(mov_false),
                    });
                }
            }
        }
    }

    None
}

fn is_mov64(insn: &BpfInsn) -> bool {
    bpf_class(insn.code) == BPF_ALU64 && bpf_op(insn.code) == BPF_MOV
}

fn extract_mov_value(insn: &BpfInsn) -> CondSelectValue {
    if bpf_src(insn.code) == BPF_X {
        CondSelectValue::Reg(insn.src_reg())
    } else {
        CondSelectValue::Imm(insn.imm)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::pass::{AnalysisCache, PassContext};

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns, ProgMeta::default())
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn { code: BPF_JMP | BPF_EXIT, regs: 0, off: 0, imm: 0 }
    }

    fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JNE | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn jgt_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JGT | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    #[test]
    fn test_cond_select_analyze_4insn_diamond() {
        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let insns = vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].old_len, 4);
        assert_eq!(sites[0].cond_reg, 1);
        assert_eq!(sites[0].dst_reg, 0);
        assert_eq!(sites[0].true_val, CondSelectValue::Imm(1));
        assert_eq!(sites[0].false_val, CondSelectValue::Imm(0));
    }

    #[test]
    fn test_cond_select_analyze_3insn_pattern() {
        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let insns = vec![
            jne_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].old_len, 3);
        assert_eq!(sites[0].cond_reg, 1);
        assert_eq!(sites[0].dst_reg, 0);
    }

    #[test]
    fn test_cond_select_analyze_no_match_different_dst() {
        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let insns = vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(2, 1),
        ];
        let sites = pass.analyze(&insns);
        assert!(sites.is_empty());
    }

    #[test]
    fn test_cond_select_analyze_reg_values() {
        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let insns = vec![
            jne_imm(1, 0, 1),
            BpfInsn::mov64_reg(0, 3),
            BpfInsn::mov64_reg(0, 4),
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].false_val, CondSelectValue::Reg(3));
        assert_eq!(sites[0].true_val, CondSelectValue::Reg(4));
    }

    #[test]
    fn test_cond_select_analyze_multiple_sites() {
        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let insns = vec![
            jne_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            jgt_imm(3, 5, 1),
            BpfInsn::mov64_imm(2, 10),
            BpfInsn::mov64_imm(2, 20),
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 2);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].dst_reg, 0);
        assert_eq!(sites[1].start_pc, 3);
        assert_eq!(sites[1].dst_reg, 2);
    }

    #[test]
    fn test_cond_select_run_is_detection_only() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let orig_insns = prog.insns.clone();
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default();

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert_eq!(prog.insns, orig_insns);
        assert_eq!(result.diagnostics.len(), 1);
        assert!(result.diagnostics[0].contains("cond_select site"));
    }

    #[test]
    fn test_cond_select_analyze_no_sites_in_linear_program() {
        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let insns = vec![
            BpfInsn::mov64_imm(0, 42),
            BpfInsn::mov64_imm(1, 10),
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert!(sites.is_empty());
    }
}
