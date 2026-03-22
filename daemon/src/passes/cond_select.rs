// SPDX-License-Identifier: MIT
//! COND_SELECT optimization pass.

use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::insn::*;
use crate::pass::*;

use super::fixup_branches_inline;

/// COND_SELECT pass: replaces branch+mov diamond patterns with
/// bpf_select64() kfunc calls (lowered to CMOV by the JIT).
///
/// Pattern A (4-insn diamond):
///   Jcc r_cond, X, +2 ; MOV r_dst, val_false ; JA +1 ; MOV r_dst, val_true
///
/// Pattern B (3-insn / JCC +1):
///   Jcc r_cond, X, +1 ; MOV r_dst, val_false ; MOV r_dst, val_true
///
/// Emit (when kfunc available):
///   MOV r1, <true_val>       // arg1 = a (returned when cond != 0)
///   MOV r2, <false_val>      // arg2 = b (returned when cond == 0)
///   MOV r3, <cond_reg>       // arg3 = condition value
///   CALL bpf_select64        // r0 = bpf_select64(a, b, cond)
///   MOV dst, r0              // dst = result
///
/// The kfunc signature is: `u64 bpf_select64(u64 a, u64 b, u64 cond)`
/// Semantics: returns `a` if `cond != 0`, otherwise returns `b`.
///
/// Currently only handles cases where the JCC condition maps cleanly to
/// the kfunc's `cond != 0` test:
///   - JNE reg, 0: cond = reg (direct)
///   - JEQ reg, 0: cond = reg (swap true/false values)
/// Other JCC conditions are skipped (no simple mapping to a single register).
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
    /// The JCC opcode (BPF_JNE, BPF_JEQ, etc.).
    pub jcc_op: u8,
    /// The JCC immediate (for BPF_K source).
    pub jcc_imm: i32,
    /// The JCC source kind (BPF_K or BPF_X).
    pub jcc_src: u8,
    /// The JCC src_reg (for BPF_X source).
    pub jcc_src_reg: u8,
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

/// Check whether a site's JCC condition can be mapped to the kfunc's `cond != 0`.
///
/// Returns `true` if we can use `cond_reg` directly (JNE reg, 0) or with
/// a true/false swap (JEQ reg, 0).
fn is_simple_zero_test(site: &CondSelectSite) -> bool {
    if site.jcc_src != BPF_K || site.jcc_imm != 0 {
        return false;
    }
    matches!(site.jcc_op, BPF_JNE | BPF_JEQ)
}

/// For JEQ reg, 0: the JCC jumps (to true_val) when reg == 0.
/// But bpf_select64 returns `a` when cond != 0.
/// So for JEQ: we need to swap a/b so that a=false_val, b=true_val.
/// Returns (a_val, b_val) in the order for the kfunc call.
fn kfunc_args_for_site(site: &CondSelectSite) -> (CondSelectValue, CondSelectValue) {
    match site.jcc_op {
        BPF_JNE => {
            // JNE jumps when cond != 0 -> true_val selected
            // bpf_select64(a, b, cond) returns a when cond != 0
            // So a = true_val, b = false_val
            (site.true_val, site.false_val)
        }
        BPF_JEQ => {
            // JEQ jumps when cond == 0 -> true_val selected
            // bpf_select64(a, b, cond) returns b when cond == 0
            // So a = false_val, b = true_val
            (site.false_val, site.true_val)
        }
        _ => unreachable!("is_simple_zero_test should have filtered this"),
    }
}

/// Emit a MOV instruction for a CondSelectValue into a target register.
fn emit_mov_value(dst: u8, val: CondSelectValue) -> BpfInsn {
    match val {
        CondSelectValue::Reg(src) => BpfInsn::mov64_reg(dst, src),
        CondSelectValue::Imm(imm) => BpfInsn::mov64_imm(dst, imm),
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
        vec!["branch_targets", "liveness"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // Check if bpf_select64 kfunc is available.
        if ctx.kfunc_registry.select64_btf_id < 0 {
            // Fall back to detection-only mode.
            let sites = self.analyze(&program.insns);
            let diagnostics: Vec<String> = sites
                .iter()
                .map(|s| {
                    format!(
                        "cond_select site: pc={} len={} cond=r{} dst=r{} (kfunc unavailable)",
                        s.start_pc, s.old_len, s.cond_reg, s.dst_reg
                    )
                })
                .collect();
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: if !sites.is_empty() {
                    vec![SkipReason {
                        pc: 0,
                        reason: "bpf_select64 kfunc not available".into(),
                    }]
                } else {
                    vec![]
                },
                diagnostics,
            });
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);
        let liveness_analysis = LivenessAnalysis;
        let liveness = analyses.get(&liveness_analysis, program);

        let sites = self.analyze(&program.insns);
        let btf_id = ctx.kfunc_registry.select64_btf_id;
        let mut safe_sites = Vec::new();
        let mut skipped = Vec::new();

        for site in sites {
            // Safety check 1: only handle simple zero-test conditions.
            if !is_simple_zero_test(&site) {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: format!(
                        "JCC condition not a simple zero test (op={:#x} imm={} src={:#x})",
                        site.jcc_op, site.jcc_imm, site.jcc_src
                    ),
                });
                continue;
            }

            // Safety check 2: interior branch target (excluding the JCC's own target).
            let jcc = &program.insns[site.start_pc];
            let own_target = (site.start_pc as i64 + 1 + jcc.off as i64) as usize;
            let has_interior = (site.start_pc + 1..site.start_pc + site.old_len)
                .any(|pc| pc < bt.is_target.len() && bt.is_target[pc] && pc != own_target);
            if has_interior {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "interior branch target".into(),
                });
                continue;
            }

            // Safety check 3: caller-saved register conflict.
            // A kfunc call clobbers r1-r5. Check if any caller-saved reg
            // (excluding the dst_reg which we're writing anyway) is live after the site.
            let site_end = site.start_pc + site.old_len;
            if site_end > 0 && site_end - 1 < liveness.live_out.len() {
                let live_after = &liveness.live_out[site_end - 1];
                let caller_saved_conflict = (1u8..=5)
                    .any(|r| r != site.dst_reg && live_after.contains(&r));
                if caller_saved_conflict {
                    skipped.push(SkipReason {
                        pc: site.start_pc,
                        reason: "caller-saved register conflict".into(),
                    });
                    continue;
                }
            }

            safe_sites.push(site);
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
            });
        }

        // Build replacement instruction stream.
        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0;
        let mut site_idx = 0;
        let mut applied = 0;

        while pc < orig_len {
            let new_pc = new_insns.len();
            addr_map[pc] = new_pc;

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].start_pc {
                let site = &safe_sites[site_idx];
                let (a_val, b_val) = kfunc_args_for_site(site);

                // Emit: r1 = a (true_val or false_val depending on JCC direction)
                new_insns.push(emit_mov_value(1, a_val));
                // Emit: r2 = b
                new_insns.push(emit_mov_value(2, b_val));
                // Emit: r3 = cond_reg
                if site.cond_reg != 3 {
                    new_insns.push(BpfInsn::mov64_reg(3, site.cond_reg));
                }
                // Emit: call bpf_select64
                new_insns.push(BpfInsn::call_kfunc(btf_id));
                // Emit: dst = r0
                if site.dst_reg != 0 {
                    new_insns.push(BpfInsn::mov64_reg(site.dst_reg, 0));
                }

                // Map old PCs in the site range.
                for j in 1..site.old_len {
                    addr_map[pc + j] = new_pc;
                }

                pc += site.old_len;
                site_idx += 1;
                applied += 1;
            } else {
                new_insns.push(program.insns[pc]);
                if program.insns[pc].is_ldimm64() && pc + 1 < orig_len {
                    pc += 1;
                    addr_map[pc] = new_insns.len();
                    new_insns.push(program.insns[pc]);
                }
                pc += 1;
            }
        }
        addr_map[orig_len] = new_insns.len();

        // Branch fixup.
        fixup_branches_inline(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        program.log_transform(TransformEntry {
            pass_name: self.name().into(),
            sites_applied: applied,
            insns_before: orig_len,
            insns_after: program.insns.len(),
            details: vec![],
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
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
                        jcc_op: bpf_op(jcc.code),
                        jcc_imm: jcc.imm,
                        jcc_src: bpf_src(jcc.code),
                        jcc_src_reg: jcc.src_reg(),
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
                        jcc_op: bpf_op(jcc.code),
                        jcc_imm: jcc.imm,
                        jcc_src: bpf_src(jcc.code),
                        jcc_src_reg: jcc.src_reg(),
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

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
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

    fn ctx_with_select_kfunc(btf_id: i32) -> PassContext {
        let mut ctx = PassContext::test_default();
        ctx.kfunc_registry.select64_btf_id = btf_id;
        ctx
    }

    // ── Detection tests (unchanged) ──────────────────────────────────

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

    // ── Emit tests ───────────────────────────────────────────────────

    #[test]
    fn test_cond_select_skip_when_kfunc_unavailable() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let orig_insns = prog.insns.clone();
        let mut cache = AnalysisCache::new();
        let ctx = PassContext::test_default(); // select64_btf_id = -1

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert_eq!(prog.insns, orig_insns);
        assert!(!result.diagnostics.is_empty());
        assert!(result.diagnostics[0].contains("kfunc unavailable"));
    }

    #[test]
    fn test_cond_select_emit_4insn_diamond_jne() {
        // JNE r1, 0, +2 ; MOV r0, 0 ; JA +1 ; MOV r0, 1 ; EXIT
        // With JNE: if r1 != 0 -> true_val=1, false_val=0
        // kfunc: a=true_val=1, b=false_val=0, cond=r1
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);

        // Verify kfunc call is present
        let has_kfunc_call = prog.insns.iter().any(|i| i.is_call() && i.src_reg() == 2);
        assert!(has_kfunc_call, "expected a kfunc call in the output");
        let call_insn = prog.insns.iter().find(|i| i.is_call() && i.src_reg() == 2).unwrap();
        assert_eq!(call_insn.imm, 5555);

        // Verify r1 = 1 (true_val = a), r2 = 0 (false_val = b)
        assert_eq!(prog.insns[0].code, BPF_ALU64 | BPF_MOV | BPF_K);
        assert_eq!(prog.insns[0].dst_reg(), 1);
        assert_eq!(prog.insns[0].imm, 1); // a = true_val
        assert_eq!(prog.insns[1].dst_reg(), 2);
        assert_eq!(prog.insns[1].imm, 0); // b = false_val
    }

    #[test]
    fn test_cond_select_emit_3insn_jne() {
        // JNE r1, 0, +1 ; MOV r0, 0 ; MOV r0, 1 ; EXIT
        let mut prog = make_program(vec![
            jne_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(7777);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        let has_kfunc_call = prog.insns.iter().any(|i| i.is_call() && i.src_reg() == 2);
        assert!(has_kfunc_call);
    }

    #[test]
    fn test_cond_select_emit_jeq_swaps_args() {
        // JEQ r1, 0, +2 ; MOV r0, 0 ; JA +1 ; MOV r0, 1 ; EXIT
        // With JEQ: if r1 == 0 -> jumps to true_val=1
        // So: true_val=1 is selected when cond==0
        // kfunc: a=false_val=0 (returned when cond!=0), b=true_val=1 (returned when cond==0)
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);

        // For JEQ: a = false_val = 0, b = true_val = 1
        assert_eq!(prog.insns[0].dst_reg(), 1);
        assert_eq!(prog.insns[0].imm, 0); // a = false_val (returned when cond!=0)
        assert_eq!(prog.insns[1].dst_reg(), 2);
        assert_eq!(prog.insns[1].imm, 1); // b = true_val (returned when cond==0)
    }

    #[test]
    fn test_cond_select_skip_non_zero_imm() {
        // JNE r1, 42, +2 — not a simple zero test, should be skipped
        let mut prog = make_program(vec![
            jne_imm(1, 42, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("not a simple zero test")));
    }

    #[test]
    fn test_cond_select_skip_jgt() {
        // JGT r1, 0, +1 — not JNE/JEQ, should be skipped
        let mut prog = make_program(vec![
            jgt_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
    }

    #[test]
    fn test_cond_select_emit_with_reg_values() {
        // JNE r1, 0, +1 ; MOV r0, r3 ; MOV r0, r4 ; EXIT
        // true_val = Reg(4), false_val = Reg(3)
        let mut prog = make_program(vec![
            jne_imm(1, 0, 1),
            BpfInsn::mov64_reg(0, 6),
            BpfInsn::mov64_reg(0, 7),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(8888);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // r1 = r7 (true_val, a), r2 = r6 (false_val, b)
        assert_eq!(prog.insns[0].code, BPF_ALU64 | BPF_MOV | BPF_X);
        assert_eq!(prog.insns[0].dst_reg(), 1);
        assert_eq!(prog.insns[0].src_reg(), 7); // a = true_val
        assert_eq!(prog.insns[1].code, BPF_ALU64 | BPF_MOV | BPF_X);
        assert_eq!(prog.insns[1].dst_reg(), 2);
        assert_eq!(prog.insns[1].src_reg(), 6); // b = false_val
    }

    #[test]
    fn test_cond_select_caller_saved_conflict() {
        // r3 is live after the site -> conflict
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),
            jne_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::mov64_reg(0, 3), // r3 is live-out of the site
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert!(result.sites_skipped.iter().any(|s| s.reason.contains("caller-saved")));
    }

    #[test]
    fn test_cond_select_no_sites_linear() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(0, 42),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
    }

    #[test]
    fn test_cond_select_emit_cond_reg_is_r3() {
        // When cond_reg == 3, we should NOT emit the extra MOV r3, r3
        let mut prog = make_program(vec![
            jne_imm(3, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass { predictability_threshold: 0.8 };
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        // Verify no mov r3, r3 — the emitted sequence should be shorter
        let mov_r3_r3 = prog.insns.iter().any(|i| {
            i.code == (BPF_ALU64 | BPF_MOV | BPF_X)
                && i.dst_reg() == 3
                && i.src_reg() == 3
        });
        assert!(!mov_r3_r3, "should not emit redundant mov r3, r3");
    }
}
