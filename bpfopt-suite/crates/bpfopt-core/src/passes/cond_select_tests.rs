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
    ctx.kinsn_registry.select64_btf_id = btf_id;
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
