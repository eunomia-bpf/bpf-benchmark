// SPDX-License-Identifier: MIT
//! COND_SELECT optimization pass.

use crate::analysis::BranchTargetAnalysis;
use crate::insn::*;
use crate::pass::*;

use super::utils::{emit_packed_kinsn_call_with_off, ensure_module_fd_slot, fixup_all_branches};

/// COND_SELECT pass: replaces branch+mov diamond patterns with
/// bpf_select64() kfunc calls (lowered to CMOV by the JIT).
///
/// Pattern A (4-insn diamond):
///   Jcc r_cond, X, +2 ; MOV r_dst, val_false ; JA +1 ; MOV r_dst, val_true
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
///
/// Other JCC conditions are skipped (no simple mapping to a single register).
pub struct CondSelectPass;

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
}

/// A cond_select site that has passed safety checks, ready for transformation.
struct SafeCondSelectSite {
    site: CondSelectSite,
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

fn packed_supported_for_site(ctx: &PassContext, site: &CondSelectSite) -> bool {
    if !ctx.kfunc_registry.packed_supported_for_pass("cond_select") {
        return false;
    }

    let (a_val, b_val) = kfunc_args_for_site(site);
    matches!(a_val, CondSelectValue::Reg(_)) && matches!(b_val, CondSelectValue::Reg(_))
}

impl BpfPass for CondSelectPass {
    fn name(&self) -> &str {
        "cond_select"
    }


    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        // Check if platform has CMOV support.
        if !ctx.platform.has_cmov {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "platform lacks CMOV support".into(),
                }],
                diagnostics: vec![],
                ..Default::default()
            });
        }

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
                ..Default::default()
            });
        }

        if !ctx.kfunc_registry.packed_supported_for_pass(self.name()) {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: vec![SkipReason {
                    pc: 0,
                    reason: "bpf_select64 packed ABI not available".into(),
                }],
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let bt_analysis = BranchTargetAnalysis;
        let bt = analyses.get(&bt_analysis, program);

        let sites = self.analyze(&program.insns);
        let btf_id = ctx.kfunc_registry.select64_btf_id;
        let mut safe_sites: Vec<SafeCondSelectSite> = Vec::new();
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
            // For Pattern C (3-insn), the JCC is at start_pc+1, not start_pc.
            let jcc_pc = if site.old_len == 3 {
                site.start_pc + 1
            } else {
                site.start_pc
            };
            let jcc = &program.insns[jcc_pc];
            let own_target = (jcc_pc as i64 + 1 + jcc.off as i64) as usize;
            let has_interior = (site.start_pc + 1..site.start_pc + site.old_len)
                .any(|pc| pc < bt.is_target.len() && bt.is_target[pc] && pc != own_target);
            if has_interior {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "interior branch target".into(),
                });
                continue;
            }

            if !packed_supported_for_site(ctx, &site) {
                skipped.push(SkipReason {
                    pc: site.start_pc,
                    reason: "packed ABI requires register true/false operands".into(),
                });
                continue;
            }

            safe_sites.push(SafeCondSelectSite { site });
        }

        if safe_sites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let kfunc_off = ctx
            .kfunc_registry
            .module_fd_for_pass(self.name())
            .map(|fd| ensure_module_fd_slot(program, fd))
            .unwrap_or(0);

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

            if site_idx < safe_sites.len() && pc == safe_sites[site_idx].site.start_pc {
                let safe_site = &safe_sites[site_idx];
                let site = &safe_site.site;
                let (a_val, b_val) = kfunc_args_for_site(site);

                let a_reg = match a_val {
                    CondSelectValue::Reg(r) => r,
                    CondSelectValue::Imm(_) => unreachable!("packed path requires register inputs"),
                };
                let b_reg = match b_val {
                    CondSelectValue::Reg(r) => r,
                    CondSelectValue::Imm(_) => unreachable!("packed path requires register inputs"),
                };
                let payload = (site.dst_reg as u64)
                    | ((a_reg as u64) << 4)
                    | ((b_reg as u64) << 8)
                    | ((site.cond_reg as u64) << 12);
                let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
                new_insns.extend_from_slice(&replacement);

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
        fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry { sites_applied: applied });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: applied > 0,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
            ..Default::default()
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
                    });
                }
            }
        }
    }

    // Pattern C: 3-insn short conditional MOV (clang's common pattern)
    //   MOV dst, true_val ; Jcc +1 ; MOV dst, false_val
    //
    // Semantics:
    //   - dst is set to true_val unconditionally
    //   - If Jcc taken (condition true): skip false MOV, dst = true_val
    //   - If Jcc not taken (condition false): execute false MOV, dst = false_val
    //
    // The site starts at the MOV before the Jcc (pc-1 relative to the Jcc).
    // We check pc as potential Jcc position.
    if pc >= 1 && pc + 1 < n {
        let mov_true = &insns[pc - 1];
        let jcc = &insns[pc];
        let mov_false = &insns[pc + 1];

        if jcc.is_cond_jmp() && jcc.off == 1 && is_mov64(mov_true) && is_mov64(mov_false) {
            let dst_t = mov_true.dst_reg();
            let dst_f = mov_false.dst_reg();
            if dst_t == dst_f {
                // Ensure the MOV true_val doesn't also write a register
                // used by the JCC condition (would change semantics).
                // For BPF_X: jcc uses dst_reg and src_reg.
                // For BPF_K: jcc uses dst_reg.
                let jcc_cond_reg = jcc.dst_reg();
                let jcc_src_used = if bpf_src(jcc.code) == BPF_X {
                    Some(jcc.src_reg())
                } else {
                    None
                };
                let mov_true_dst = mov_true.dst_reg();
                let cond_clobbered = mov_true_dst == jcc_cond_reg
                    || jcc_src_used.is_some_and(|s| mov_true_dst == s);

                if !cond_clobbered {
                    return Some(CondSelectSite {
                        start_pc: pc - 1,
                        old_len: 3,
                        cond_reg: jcc_cond_reg,
                        dst_reg: dst_t,
                        true_val: extract_mov_value(mov_true),
                        false_val: extract_mov_value(mov_false),
                        jcc_op: bpf_op(jcc.code),
                        jcc_imm: jcc.imm,
                        jcc_src: bpf_src(jcc.code),
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
        BpfProgram::new(insns)
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
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
        ctx.platform.has_cmov = true;
        ctx
    }

    // ── Detection tests (unchanged) ──────────────────────────────────

    #[test]
    fn test_cond_select_analyze_4insn_diamond() {
        let pass = CondSelectPass;
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
    fn test_cond_select_pattern_b_removed() {
        // Pattern B (Jcc +1 ; MOV false ; MOV true) is semantically wrong:
        // both paths always reach MOV true. It should NOT be detected.
        let pass = CondSelectPass;
        let insns = vec![
            jne_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert!(sites.is_empty(), "Pattern B should not be matched");
    }

    #[test]
    fn test_cond_select_analyze_short_pattern_c() {
        // Pattern C: MOV dst, true_val ; JNE cond, 0, +1 ; MOV dst, false_val
        let pass = CondSelectPass;
        let insns = vec![
            BpfInsn::mov64_imm(0, 42), // true_val
            jne_imm(1, 0, 1),          // if r1 != 0, skip next
            BpfInsn::mov64_imm(0, 0),  // false_val
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 1, "should detect Pattern C (short cond MOV)");
        assert_eq!(sites[0].start_pc, 0); // starts at the MOV true
        assert_eq!(sites[0].old_len, 3);
        assert_eq!(sites[0].cond_reg, 1);
        assert_eq!(sites[0].dst_reg, 0);
        assert_eq!(sites[0].true_val, CondSelectValue::Imm(42));
        assert_eq!(sites[0].false_val, CondSelectValue::Imm(0));
    }

    #[test]
    fn test_cond_select_short_pattern_c_with_reg_values() {
        let pass = CondSelectPass;
        let insns = vec![
            BpfInsn::mov64_reg(0, 6), // true_val = r6
            jne_imm(1, 0, 1),
            BpfInsn::mov64_reg(0, 7), // false_val = r7
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].true_val, CondSelectValue::Reg(6));
        assert_eq!(sites[0].false_val, CondSelectValue::Reg(7));
    }

    #[test]
    fn test_cond_select_short_pattern_c_no_match_cond_clobbered() {
        // MOV r1, 42 ; JNE r1, 0, +1 ; MOV r1, 0
        // The MOV true_val writes r1, which is also the JCC condition register.
        // This changes semantics -- the JCC tests the new r1, not the old one.
        let pass = CondSelectPass;
        let insns = vec![
            BpfInsn::mov64_imm(1, 42), // clobbers cond_reg r1
            jne_imm(1, 0, 1),
            BpfInsn::mov64_imm(1, 0),
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert!(
            sites.is_empty(),
            "should not match when MOV true clobbers cond_reg"
        );
    }

    #[test]
    fn test_cond_select_short_pattern_c_emit_jne() {
        // Pattern C with register values should lower to a packed select call.
        let mut prog = make_program(vec![
            BpfInsn::mov64_reg(0, 7), // true_val
            jne_imm(1, 0, 1),
            BpfInsn::mov64_reg(0, 6), // false_val
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        let has_kfunc_call = prog
            .insns
            .iter()
            .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL);
        assert!(has_kfunc_call);
    }

    #[test]
    fn test_cond_select_analyze_no_match_different_dst() {
        let pass = CondSelectPass;
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
    fn test_cond_select_analyze_reg_values_4insn() {
        // Pattern A with register values.
        let pass = CondSelectPass;
        let insns = vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_reg(0, 3), // false_val
            BpfInsn::ja(1),
            BpfInsn::mov64_reg(0, 4), // true_val
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].false_val, CondSelectValue::Reg(3));
        assert_eq!(sites[0].true_val, CondSelectValue::Reg(4));
    }

    #[test]
    fn test_cond_select_analyze_multiple_sites() {
        // Two Pattern A sites (4-insn diamond).
        let pass = CondSelectPass;
        let insns = vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            jne_imm(3, 0, 2),
            BpfInsn::mov64_imm(2, 10),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(2, 20),
            exit_insn(),
        ];
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 2);
        assert_eq!(sites[0].start_pc, 0);
        assert_eq!(sites[0].dst_reg, 0);
        assert_eq!(sites[1].start_pc, 4);
        assert_eq!(sites[1].dst_reg, 2);
    }

    #[test]
    fn test_cond_select_analyze_no_sites_in_linear_program() {
        let pass = CondSelectPass;
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
        let mut ctx = PassContext::test_default(); // select64_btf_id = -1
        ctx.platform.has_cmov = true; // platform has CMOV, but kfunc is missing

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert_eq!(prog.insns, orig_insns);
        assert!(!result.diagnostics.is_empty());
        assert!(result.diagnostics[0].contains("kfunc unavailable"));
    }

    #[test]
    fn test_cond_select_skip_immediate_values_without_legacy() {
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("register true/false operands")));
    }

    #[test]
    fn test_cond_select_no_emit_3insn_pattern_b() {
        // Pattern B (Jcc +1) is no longer matched; should not emit.
        let mut prog = make_program(vec![
            jne_imm(1, 0, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(7777);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed, "Pattern B should not be transformed");
        assert_eq!(result.sites_applied, 0);
    }

    #[test]
    fn test_cond_select_emit_jeq_swaps_args() {
        // JEQ with register values swaps a/b so cond==0 selects the original true path.
        let mut prog = make_program(vec![
            jeq_imm(1, 0, 2),
            BpfInsn::mov64_reg(0, 6),
            BpfInsn::ja(1),
            BpfInsn::mov64_reg(0, 7),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);

        let mut initial = [0u64; 11];
        initial[1] = 999;
        initial[6] = 600;
        initial[7] = 700;
        let after = simulate_param_setup(&prog.insns, &initial);
        assert_eq!(after[1], 600, "logical a should be false_val for JEQ");
        assert_eq!(after[2], 700, "logical b should be true_val for JEQ");
        assert_eq!(after[3], 999, "r3 should be original cond");
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

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
        assert!(result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("not a simple zero test")));
    }

    #[test]
    fn test_cond_select_skip_jgt() {
        // JGT r1, 0, +2 — not JNE/JEQ, should be skipped
        let mut prog = make_program(vec![
            jgt_imm(1, 0, 2),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(1),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
    }

    #[test]
    fn test_cond_select_emit_with_reg_values() {
        // Pattern A with register values.
        // JNE r1, 0, +2 ; MOV r0, r6 ; JA +1 ; MOV r0, r7 ; EXIT
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_reg(0, 6), // false_val
            BpfInsn::ja(1),
            BpfInsn::mov64_reg(0, 7), // true_val
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(8888);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert_eq!(result.sites_applied, 1);
        // Verify semantics: r1 = r7 (true_val, a), r2 = r6 (false_val, b), r3 = cond(r1)
        let mut initial = [0u64; 11];
        initial[1] = 100; // cond
        initial[6] = 600; // false_val
        initial[7] = 700; // true_val
        let after = simulate_param_setup(&prog.insns, &initial);
        assert_eq!(after[1], 700, "r1 should be true_val (r7)");
        assert_eq!(after[2], 600, "r2 should be false_val (r6)");
        assert_eq!(after[3], 100, "r3 should be original cond (r1)");
    }

    #[test]
    fn test_cond_select_packed_keeps_live_regs() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),
            jne_imm(1, 0, 2),
            BpfInsn::mov64_reg(0, 6),
            BpfInsn::ja(1),
            BpfInsn::mov64_reg(0, 7),
            BpfInsn::mov64_reg(0, 3), // r3 is live-out of the site
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(
            result.changed,
            "packed ABI should apply without save/restore"
        );
        assert_eq!(result.sites_applied, 1);
    }

    #[test]
    fn test_cond_select_packed_no_callee_saved_dependency() {
        let mut prog = make_program(vec![
            BpfInsn::mov64_imm(3, 99),
            jne_imm(1, 0, 2),
            BpfInsn::mov64_reg(0, 6),
            BpfInsn::ja(1),
            BpfInsn::mov64_reg(0, 7),
            BpfInsn::alu64_reg(BPF_OR, 0, 3),
            BpfInsn::alu64_reg(BPF_OR, 0, 6),
            BpfInsn::alu64_reg(BPF_OR, 0, 7),
            BpfInsn::alu64_reg(BPF_OR, 0, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 9),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(
            result.changed,
            "packed ABI should not depend on free callee-saved regs"
        );
        assert_eq!(result.sites_applied, 1);
    }

    #[test]
    fn test_cond_select_no_sites_linear() {
        let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(!result.changed);
        assert_eq!(result.sites_applied, 0);
    }

    #[test]
    fn test_cond_select_emit_cond_reg_is_r3() {
        // Packed lowering should preserve cond_reg == r3 without emitting any register setup MOVs.
        let mut prog = make_program(vec![
            jne_imm(3, 0, 2),
            BpfInsn::mov64_reg(0, 6),
            BpfInsn::ja(1),
            BpfInsn::mov64_reg(0, 7),
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        assert!(prog.insns[0].is_kinsn_sidecar());
    }

    #[test]
    fn test_cond_select_register_alias_safety() {
        // Packed lowering keeps cond as an operand reference instead of materializing it into r3.
        let mut prog = make_program(vec![
            jne_imm(1, 0, 2),
            BpfInsn::mov64_reg(0, 6), // false_val
            BpfInsn::ja(1),
            BpfInsn::mov64_reg(0, 7), // true_val
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

        assert!(result.changed);
        let mut initial = [0u64; 11];
        initial[1] = 100;
        initial[6] = 600;
        initial[7] = 700;
        let after = simulate_param_setup(&prog.insns, &initial);
        assert_eq!(after[1], 700);
        assert_eq!(after[2], 600);
        assert_eq!(after[3], 100);
    }

    // ── Issue 1: Parallel-copy alias safety tests ─────────────────

    /// Decode the packed sidecar payload and map its logical (a, b, cond)
    /// operands back to the provided initial register values.
    fn simulate_param_setup(insns: &[BpfInsn], initial_regs: &[u64; 11]) -> [u64; 11] {
        let sidecar = insns.iter().find(|insn| insn.is_kinsn_sidecar()).unwrap();
        let payload = (sidecar.dst_reg() as u64)
            | ((sidecar.off as u16 as u64) << 4)
            | ((sidecar.imm as u32 as u64) << 20);
        let a_reg = ((payload >> 4) & 0xf) as usize;
        let b_reg = ((payload >> 8) & 0xf) as usize;
        let cond_reg = ((payload >> 12) & 0xf) as usize;

        let mut regs = [0u64; 11];
        regs[1] = initial_regs[a_reg];
        regs[2] = initial_regs[b_reg];
        regs[3] = initial_regs[cond_reg];
        regs
    }

    #[test]
    fn test_cond_select_alias_cond_reg_is_r2() {
        // The bug from the review: cond_reg == r2 means we need r3 = old r2,
        // but writing r2 = b_val first would clobber it.
        // JNE r2, 0, +2 ; MOV r0, r6 (false) ; JA +1 ; MOV r0, r7 (true)
        let mut prog = make_program(vec![
            jne_imm(2, 0, 2),
            BpfInsn::mov64_reg(0, 6), // false_val = r6
            BpfInsn::ja(1),
            BpfInsn::mov64_reg(0, 7), // true_val = r7
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);

        // Simulate with known register values.
        // r2=COND_VAL(200), r6=FALSE_VAL(600), r7=TRUE_VAL(700)
        let mut initial = [0u64; 11];
        initial[2] = 200; // cond
        initial[6] = 600; // false_val
        initial[7] = 700; // true_val
        let after = simulate_param_setup(&prog.insns, &initial);

        // For JNE: a=true_val=r7=700, b=false_val=r6=600, cond=r2=200
        assert_eq!(after[1], 700, "r1 should be true_val (a)");
        assert_eq!(after[2], 600, "r2 should be false_val (b)");
        assert_eq!(after[3], 200, "r3 should be original cond (r2=200)");
    }

    #[test]
    fn test_cond_select_alias_cycle_r1_r2() {
        // Circular alias: true_val = Reg(2), false_val = Reg(1), cond = r3
        // We need r1=r2, r2=r1 which is a swap cycle.
        // JNE r3, 0, +2 ; MOV r0, r1 (false) ; JA +1 ; MOV r0, r2 (true)
        let mut prog = make_program(vec![
            jne_imm(3, 0, 2),
            BpfInsn::mov64_reg(0, 1), // false_val = r1
            BpfInsn::ja(1),
            BpfInsn::mov64_reg(0, 2), // true_val = r2
            exit_insn(),
        ]);
        let mut cache = AnalysisCache::new();
        let ctx = ctx_with_select_kfunc(5555);

        let pass = CondSelectPass;
        let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert!(result.changed);

        let mut initial = [0u64; 11];
        initial[1] = 100; // false_val source
        initial[2] = 200; // true_val source
        initial[3] = 300; // cond
        let after = simulate_param_setup(&prog.insns, &initial);

        // For JNE: a=true_val=r2=200, b=false_val=r1=100, cond=r3=300
        assert_eq!(after[1], 200, "r1 should be true_val (from r2)");
        assert_eq!(after[2], 100, "r2 should be false_val (from r1)");
        assert_eq!(after[3], 300, "r3 should be cond (r3 already there)");
    }

    #[test]
    fn test_cond_select_alias_all_overlap_combinations() {
        // Exhaustive test: for all (cond_reg, true_src, false_src) combinations
        // among r1/r2/r3, verify the output semantics are correct.
        let regs = [1u8, 2, 3];
        for &cond_reg in &regs {
            for &true_src in &regs {
                for &false_src in &regs {
                    // Build: JNE cond_reg, 0, +2 ; MOV r0, false_src ; JA +1 ; MOV r0, true_src
                    let mut prog = make_program(vec![
                        jne_imm(cond_reg, 0, 2),
                        BpfInsn::mov64_reg(0, false_src),
                        BpfInsn::ja(1),
                        BpfInsn::mov64_reg(0, true_src),
                        exit_insn(),
                    ]);
                    let mut cache = AnalysisCache::new();
                    let ctx = ctx_with_select_kfunc(5555);

                    let pass = CondSelectPass;
                    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
                    assert!(
                        result.changed,
                        "should transform: cond=r{} true=r{} false=r{}",
                        cond_reg, true_src, false_src
                    );

                    // Simulate with distinct values.
                    let mut initial = [0u64; 11];
                    initial[1] = 100;
                    initial[2] = 200;
                    initial[3] = 300;
                    let after = simulate_param_setup(&prog.insns, &initial);

                    // Expected: r1=a=true_val (from true_src), r2=b=false_val (from false_src), r3=cond
                    let expected_a = initial[true_src as usize];
                    let expected_b = initial[false_src as usize];
                    let expected_cond = initial[cond_reg as usize];

                    assert_eq!(
                        after[1], expected_a,
                        "r1 wrong: cond=r{} true=r{} false=r{}",
                        cond_reg, true_src, false_src
                    );
                    assert_eq!(
                        after[2], expected_b,
                        "r2 wrong: cond=r{} true=r{} false=r{}",
                        cond_reg, true_src, false_src
                    );
                    assert_eq!(
                        after[3], expected_cond,
                        "r3 wrong: cond=r{} true=r{} false=r{}",
                        cond_reg, true_src, false_src
                    );
                }
            }
        }
    }

    /// Test cond_select pattern scanning against real compiled BPF bytecode
    /// from cond_select_dense.bpf.o.
    #[test]
    fn test_scan_cond_select_real_bytecode() {
        let path = crate::insn::micro_program_path("cond_select_dense.bpf.o");
        let insns = match crate::insn::load_bpf_insns_from_elf(&path) {
            Some(i) if !i.is_empty() => i,
            _ => {
                eprintln!("SKIP: cond_select_dense.bpf.o not found");
                return;
            }
        };

        let pass = CondSelectPass;
        let sites = pass.analyze(&insns);

        for site in &sites {
            assert!(site.start_pc < insns.len());
            assert!(site.old_len >= 2);
        }

        eprintln!(
            "  cond_select_dense.bpf.o: {} insns, {} sites found",
            insns.len(),
            sites.len()
        );
        assert!(
            !sites.is_empty(),
            "cond_select_dense.bpf.o should contain cond_select patterns"
        );
    }
}
