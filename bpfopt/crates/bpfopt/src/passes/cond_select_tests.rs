use super::*;
use crate::pass::{AnalysisCache, Arch, PassContext};
use crate::passes::test_helpers::exit_insn;

fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}

fn jne_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JNE | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn jne32_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP32 | BPF_JNE | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JEQ | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn jgt_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JGT | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn jle_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JLE | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

fn mov32_reg(dst: u8, src: u8) -> BpfInsn {
    BpfInsn::new(
        BPF_ALU | BPF_MOV | BPF_X,
        BpfInsn::make_regs(dst, src),
        0,
        0,
    )
}

fn ctx_with_select_kfunc(btf_id: i32) -> PassContext {
    let mut ctx = PassContext::test_default();
    ctx.kinsn_registry.select64_btf_id = btf_id;
    ctx
}

fn pattern_a(cond_reg: u8, false_mov: BpfInsn, true_mov: BpfInsn) -> Vec<BpfInsn> {
    vec![jne_imm(cond_reg, 0, 2), false_mov, BpfInsn::ja(1), true_mov, exit_insn()]
}

fn pattern_c(true_mov: BpfInsn, false_mov: BpfInsn) -> Vec<BpfInsn> {
    vec![true_mov, jne_imm(1, 0, 1), false_mov, exit_insn()]
}

// ── Detection tests (unchanged) ──────────────────────────────────

#[test]
fn test_cond_select_pattern_a_analyzer_table() {
    let pass = CondSelectPass;
    for (label, false_mov, true_mov, false_val, true_val) in [
        (
            "immediate values",
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            CondSelectValue::Imm(0),
            CondSelectValue::Imm(1),
        ),
        (
            "register values",
            BpfInsn::mov64_reg(0, 3),
            BpfInsn::mov64_reg(0, 4),
            CondSelectValue::Reg(3),
            CondSelectValue::Reg(4),
        ),
    ] {
        let insns = pattern_a(1, false_mov, true_mov);
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 1, "{label}");
        assert_eq!(sites[0].start_pc, 0, "{label}");
        assert_eq!(sites[0].old_len, 4, "{label}");
        assert_eq!(sites[0].cond_reg, 1, "{label}");
        assert_eq!(sites[0].dst_reg, 0, "{label}");
        assert_eq!(sites[0].true_val, true_val, "{label}");
        assert_eq!(sites[0].false_val, false_val, "{label}");
    }
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
fn test_cond_select_pattern_c_analyzer_table() {
    let pass = CondSelectPass;
    for (label, true_mov, false_mov, true_val, false_val) in [
        (
            "immediate values",
            BpfInsn::mov64_imm(0, 42),
            BpfInsn::mov64_imm(0, 0),
            CondSelectValue::Imm(42),
            CondSelectValue::Imm(0),
        ),
        (
            "register values",
            BpfInsn::mov64_reg(0, 6),
            BpfInsn::mov64_reg(0, 7),
            CondSelectValue::Reg(6),
            CondSelectValue::Reg(7),
        ),
    ] {
        let insns = pattern_c(true_mov, false_mov);
        let sites = pass.analyze(&insns);
        assert_eq!(sites.len(), 1, "{label}");
        assert_eq!(sites[0].start_pc, 0, "{label}");
        assert_eq!(sites[0].old_len, 3, "{label}");
        assert_eq!(sites[0].cond_reg, 1, "{label}");
        assert_eq!(sites[0].dst_reg, 0, "{label}");
        assert_eq!(sites[0].true_val, true_val, "{label}");
        assert_eq!(sites[0].false_val, false_val, "{label}");
    }
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
fn test_cond_select_no_match_analyzer_matrix() {
    let pass = CondSelectPass;
    for (label, insns) in [
        (
            "different destination registers",
            vec![jne_imm(1, 0, 2), BpfInsn::mov64_imm(0, 0), BpfInsn::ja(1), BpfInsn::mov64_imm(2, 1)],
        ),
        (
            "linear program",
            vec![
                BpfInsn::mov64_imm(0, 42),
                BpfInsn::mov64_imm(1, 10),
                exit_insn(),
            ],
        ),
    ] {
        assert!(pass.analyze(&insns).is_empty(), "{label}");
    }
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

// ── Emit tests ───────────────────────────────────────────────────

#[test]
fn test_cond_select_capability_matrix() {
    let pass = CondSelectPass;

    let original = pattern_a(1, BpfInsn::mov64_imm(0, 0), BpfInsn::mov64_imm(0, 1));
    let mut no_branchless = make_program(original.clone());
    let result = pass
        .run(
            &mut no_branchless,
            &mut AnalysisCache::new(),
            &PassContext::test_default(),
        )
        .unwrap();
    assert_eq!(result.sites_applied, 0);
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("branchless select")));

    let mut missing_kfunc = make_program(original.clone());
    let mut missing_ctx = PassContext::test_default();
    missing_ctx.platform.has_cmov = true;
    let result = pass
        .run(&mut missing_kfunc, &mut AnalysisCache::new(), &missing_ctx)
        .unwrap();
    assert_eq!(result.sites_applied, 0);
    assert_eq!(missing_kfunc.insns, original);
    assert!(!result.diagnostics.is_empty());
    assert!(result.diagnostics[0].contains("kfunc unavailable"));

    let mut arm64 = make_program(original);
    let mut arm64_ctx = ctx_with_select_kfunc(5555);
    arm64_ctx.platform.arch = Arch::Aarch64;
    assert!(!arm64_ctx.platform.has_cmov);
    let result = pass
        .run(&mut arm64, &mut AnalysisCache::new(), &arm64_ctx)
        .unwrap();
    assert_eq!(result.sites_applied, 1);
    assert!(arm64
        .insns
        .iter()
        .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL));
}

#[test]
fn test_cond_select_value_materialization_matrix() {
    for (label, mut prog, expected_prefix, sidecar_index, expected_regs) in [
        (
            "imm true reg false",
            make_program(pattern_c(BpfInsn::mov32_imm(0, 1), BpfInsn::mov64_reg(0, 6))),
            vec![BpfInsn::mov32_imm(0, 1)],
            1,
            (0u8, 0, 6, 1),
        ),
        (
            "reg true imm false",
            make_program(pattern_a(1, BpfInsn::mov64_imm(0, 0), BpfInsn::mov64_reg(0, 7))),
            vec![BpfInsn::mov64_imm(0, 0)],
            1,
            (0u8, 7, 0, 1),
        ),
        (
            "reg32 true imm false",
            make_program(pattern_a(1, BpfInsn::mov32_imm(0, 0), mov32_reg(0, 6))),
            vec![mov32_reg(0, 6), BpfInsn::mov32_imm(2, 0)],
            2,
            (0u8, 0, 2, 1),
        ),
        (
            "both immediate values",
            make_program(pattern_c(BpfInsn::mov32_imm(0, 1), BpfInsn::mov32_imm(0, 0))),
            vec![BpfInsn::mov32_imm(0, 1), BpfInsn::mov32_imm(2, 0)],
            2,
            (0u8, 0, 2, 1),
        ),
    ] {
        let result = CondSelectPass
            .run(
                &mut prog,
                &mut AnalysisCache::new(),
                &ctx_with_select_kfunc(5555),
            )
            .unwrap();
        assert_eq!(result.sites_applied, 1, "{label}");
        assert_eq!(&prog.insns[..expected_prefix.len()], expected_prefix.as_slice(), "{label}");
        assert!(prog.insns[sidecar_index].is_kinsn_sidecar(), "{label}");
        assert_eq!(
            payload_regs(sidecar_payload(&prog.insns[sidecar_index])),
            expected_regs,
            "{label}"
        );
    }
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
fn test_cond_select_emit_non_zero_compare_imm() {
    let mut prog = make_program(vec![
        jeq_imm(1, 5, 2),
        BpfInsn::mov64_reg(0, 6),
        BpfInsn::ja(1),
        BpfInsn::mov64_reg(0, 7),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_select_kfunc(5555);

    let pass = CondSelectPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    assert_eq!(prog.insns[0], BpfInsn::mov64_reg(0, 1));
    assert_eq!(prog.insns[1], BpfInsn::alu64_imm(BPF_XOR, 0, 5));
    assert!(prog.insns[2].is_kinsn_sidecar());
    assert_eq!(payload_regs(sidecar_payload(&prog.insns[2])), (0, 6, 7, 0));
}

#[test]
fn test_cond_select_emit_jmp32_zero_compare_predicate() {
    let mut prog = make_program(vec![
        jne32_imm(1, 0, 2),
        BpfInsn::mov64_reg(0, 6),
        BpfInsn::ja(1),
        BpfInsn::mov64_reg(0, 7),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_select_kfunc(5555);

    let pass = CondSelectPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    assert_eq!(prog.insns[0], mov32_reg(0, 1));
    assert!(prog.insns[1].is_kinsn_sidecar());
    assert_eq!(payload_regs(sidecar_payload(&prog.insns[1])), (0, 7, 6, 0));
}

#[test]
fn test_cond_select_emit_jgt_predicate_prefix() {
    let mut prog = make_program(vec![
        jgt_imm(1, 0, 2),
        BpfInsn::mov64_reg(0, 6),
        BpfInsn::ja(1),
        BpfInsn::mov64_reg(0, 7),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_select_kfunc(5555);

    let pass = CondSelectPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    assert_eq!(prog.insns[0], BpfInsn::mov64_imm(0, 0));
    assert_eq!(prog.insns[1], jle_imm(1, 0, 1));
    assert_eq!(prog.insns[2], BpfInsn::mov64_imm(0, 1));
    assert!(prog.insns[3].is_kinsn_sidecar());
    assert_eq!(payload_regs(sidecar_payload(&prog.insns[3])), (0, 7, 6, 0));
}

// ── Issue 1: Parallel-copy alias safety tests ─────────────────

/// Decode the packed sidecar payload and map its logical (a, b, cond)
/// operands back to the provided initial register values.
fn sidecar_payload(sidecar: &BpfInsn) -> u64 {
    (sidecar.dst_reg() as u64)
        | ((sidecar.off as u16 as u64) << 4)
        | ((sidecar.imm as u32 as u64) << 20)
}

fn payload_regs(payload: u64) -> (u8, u8, u8, u8) {
    (
        (payload & 0xf) as u8,
        ((payload >> 4) & 0xf) as u8,
        ((payload >> 8) & 0xf) as u8,
        ((payload >> 12) & 0xf) as u8,
    )
}

fn simulate_param_setup(insns: &[BpfInsn], initial_regs: &[u64; 11]) -> [u64; 11] {
    let sidecar = insns.iter().find(|insn| insn.is_kinsn_sidecar()).unwrap();
    let payload = sidecar_payload(sidecar);
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
                let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

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
