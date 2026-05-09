use super::rotate::*;
use crate::insn::*;
use crate::pass::*;
use crate::pass::{AnalysisCache, PassContext};
use crate::passes::test_helpers::{exit_insn, pseudo_call_to};

fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}

fn mov32_reg(dst: u8, src: u8) -> BpfInsn {
    BpfInsn::new(
        BPF_ALU | BPF_MOV | BPF_X,
        BpfInsn::make_regs(dst, src),
        0,
        0,
    )
}

fn alu32_imm(op: u8, dst: u8, imm: i32) -> BpfInsn {
    BpfInsn::new(BPF_ALU | op | BPF_K, BpfInsn::make_regs(dst, 0), 0, imm)
}

fn alu32_reg(op: u8, dst: u8, src: u8) -> BpfInsn {
    BpfInsn::new(BPF_ALU | op | BPF_X, BpfInsn::make_regs(dst, src), 0, 0)
}

fn ctx_with_rotate_kfunc(btf_id: i32) -> PassContext {
    let mut ctx = PassContext::test_default();
    ctx.kinsn_registry.rotate64_btf_id = btf_id;
    ctx.platform.has_rorx = true;
    ctx
}

fn ctx_with_rotate32_kfunc(btf_id: i32) -> PassContext {
    let mut ctx = PassContext::test_default();
    ctx.kinsn_registry.rotate32_btf_id = btf_id;
    ctx.platform.has_rorx = true;
    ctx
}

#[test]
fn test_rotate_pass_pattern_match() {
    // Now requires MOV tmp, dst before the shift pattern.
    let insns = vec![
        BpfInsn::mov64_reg(3, 2), // MOV r3, r2 (provenance)
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];
    let sites = scan_rotate_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].start_pc, 0); // includes the MOV
    assert_eq!(sites[0].old_len, 4);
    assert_eq!(sites[0].shift_amount, 8);
    assert_eq!(sites[0].dst_reg, 2);
    assert_eq!(sites[0].tmp_reg, 3);
    assert_eq!(sites[0].width, RotateWidth::W64);
}

#[test]
fn test_rotate_pass_pattern_b_match() {
    let insns = vec![
        BpfInsn::mov64_reg(3, 2), // provenance
        BpfInsn::alu64_imm(BPF_LSH, 2, 16),
        BpfInsn::alu64_imm(BPF_RSH, 3, 48),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];
    let sites = scan_rotate_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].shift_amount, 16);
    assert_eq!(sites[0].width, RotateWidth::W64);
}

#[test]
fn test_rotate32_pass_pattern_a_match() {
    let insns = vec![
        mov32_reg(3, 2),
        alu32_imm(BPF_RSH, 2, 24),
        alu32_imm(BPF_LSH, 3, 8),
        alu32_reg(BPF_OR, 2, 3),
    ];

    let sites = scan_rotate_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].shift_amount, 8);
    assert_eq!(sites[0].dst_reg, 2);
    assert_eq!(sites[0].val_reg, 2);
    assert_eq!(sites[0].tmp_reg, 3);
    assert_eq!(sites[0].width, RotateWidth::W32);
}

#[test]
fn test_rotate32_pass_pattern_b_match() {
    let insns = vec![
        mov32_reg(3, 2),
        alu32_imm(BPF_LSH, 2, 7),
        alu32_imm(BPF_RSH, 3, 25),
        alu32_reg(BPF_OR, 2, 3),
    ];

    let sites = scan_rotate_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].shift_amount, 7);
    assert_eq!(sites[0].width, RotateWidth::W32);
}

#[test]
fn test_rotate32_pass_cilium_split_copy_shape() {
    // From Cilium bpf_xdp.bpf.o LBB6_177:
    // w1 = w6; w1 >>= 0x1c; w2 = w6; w2 <<= 0x4; w2 |= w1
    let insns = vec![
        mov32_reg(1, 6),
        alu32_imm(BPF_RSH, 1, 28),
        mov32_reg(2, 6),
        alu32_imm(BPF_LSH, 2, 4),
        alu32_reg(BPF_OR, 2, 1),
    ];

    let sites = scan_rotate_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].start_pc, 0);
    assert_eq!(sites[0].old_len, 5);
    assert_eq!(sites[0].shift_amount, 4);
    assert_eq!(sites[0].dst_reg, 2);
    assert_eq!(sites[0].val_reg, 6);
    assert_eq!(sites[0].tmp_reg, 1);
    assert_eq!(sites[0].width, RotateWidth::W32);
}

#[test]
fn test_rotate32_pass_no_match_wrong_sum() {
    let insns = vec![
        mov32_reg(3, 2),
        alu32_imm(BPF_RSH, 2, 20),
        alu32_imm(BPF_LSH, 3, 8),
        alu32_reg(BPF_OR, 2, 3),
    ];

    assert!(scan_rotate_sites(&insns).is_empty());
}

#[test]
fn test_rotate_pass_requires_adjacent_provenance_mov() {
    let insns = vec![
        BpfInsn::mov64_reg(3, 2),
        BpfInsn::mov64_reg(8, 8),
        BpfInsn::alu64_imm(BPF_RSH, 3, 56),
        BpfInsn::alu64_imm(BPF_LSH, 2, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];

    assert!(scan_rotate_sites(&insns).is_empty());
}

#[test]
fn test_rotate_pass_pattern_or_reversed() {
    // OR source/destination order may differ, but the result must not land
    // in the scratch copy register.
    let insns = vec![
        BpfInsn::mov64_reg(3, 2),           // MOV r3, r2 (provenance: r3 is copy)
        BpfInsn::alu64_imm(BPF_RSH, 3, 56), // RSH r3 (copy), 56
        BpfInsn::alu64_imm(BPF_LSH, 2, 8),  // LSH r2 (orig), 8
        BpfInsn::alu64_reg(BPF_OR, 2, 3),   // OR r2, r3 — result in r2
    ];
    let sites = scan_rotate_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].shift_amount, 8);
    assert_eq!(sites[0].dst_reg, 2); // result register
    assert_eq!(sites[0].val_reg, 2); // original value register
    assert_eq!(sites[0].tmp_reg, 3); // copy register
}

#[test]
fn test_rotate_pass_no_match_when_or_writes_tmp_reg() {
    let insns = vec![
        BpfInsn::mov64_reg(3, 2),
        BpfInsn::alu64_imm(BPF_RSH, 3, 56),
        BpfInsn::alu64_imm(BPF_LSH, 2, 8),
        BpfInsn::alu64_reg(BPF_OR, 3, 2),
    ];

    assert!(scan_rotate_sites(&insns).is_empty());
}

#[test]
fn test_rotate_pass_pattern_clang_style() {
    // Exact pattern from clang: MOV r2,r3 ; RSH r2,51 ; LSH r3,13 ; OR r3,r2
    // Here r3 is the original, r2 is the copy.
    let insns = vec![
        BpfInsn::mov64_reg(2, 3), // MOV r2, r3 (provenance: r2 = copy of r3)
        BpfInsn::alu64_imm(BPF_RSH, 2, 51), // RSH r2 (copy), 51
        BpfInsn::alu64_imm(BPF_LSH, 3, 13), // LSH r3 (orig), 13
        BpfInsn::alu64_reg(BPF_OR, 3, 2), // OR r3, r2 — result in r3
    ];
    let sites = scan_rotate_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].shift_amount, 13);
    assert_eq!(sites[0].dst_reg, 3); // result register (r3, OR destination)
    assert_eq!(sites[0].val_reg, 3); // original value
    assert_eq!(sites[0].tmp_reg, 2); // copy register
}

#[test]
fn test_rotate_pass_no_match_wrong_sum() {
    let insns = vec![
        BpfInsn::mov64_reg(3, 2),
        BpfInsn::alu64_imm(BPF_RSH, 2, 20),
        BpfInsn::alu64_imm(BPF_LSH, 3, 20),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];
    let sites = scan_rotate_sites(&insns);
    assert!(sites.is_empty());
}

#[test]
fn test_rotate_pass_no_match_without_provenance() {
    // Without the MOV tmp, dst, no match should occur.
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];
    let sites = scan_rotate_sites(&insns);
    assert!(sites.is_empty(), "should not match without provenance MOV");
}

#[test]
fn test_rotate_pass_no_match_wrong_provenance() {
    // MOV r3, r4 instead of MOV r3, r2 -- wrong source
    let insns = vec![
        BpfInsn::mov64_reg(3, 4), // wrong: copies from r4, not r2
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];
    let sites = scan_rotate_sites(&insns);
    assert!(sites.is_empty(), "should not match with wrong provenance");
}

#[test]
fn test_rotate_pass_emit_kfunc_call() {
    let mut prog = make_program(vec![
        BpfInsn::mov64_reg(3, 2), // provenance
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_rotate_kfunc(9999);

    let pass = RotatePass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    let has_kfunc_call = prog
        .insns
        .iter()
        .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL);
    assert!(has_kfunc_call, "expected a kfunc call in the output");
    let call_insn = prog
        .insns
        .iter()
        .find(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL)
        .unwrap();
    assert_eq!(call_insn.imm, 9999);
}

#[test]
fn test_rotate32_pass_emit_kfunc_call() {
    let mut prog = make_program(vec![
        mov32_reg(3, 2),
        alu32_imm(BPF_RSH, 2, 24),
        alu32_imm(BPF_LSH, 3, 8),
        alu32_reg(BPF_OR, 2, 3),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_rotate32_kfunc(8888);

    let pass = RotatePass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    let call_insn = prog
        .insns
        .iter()
        .find(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL)
        .unwrap();
    assert_eq!(call_insn.imm, 8888);
}

#[test]
fn test_rotate_pass_skip_when_kfunc_unavailable() {
    let mut prog = make_program(vec![
        BpfInsn::mov64_reg(3, 2),
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = RotatePass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 0);
    assert!(!result.sites_skipped.is_empty());
    assert!(result.sites_skipped[0].reason.contains("kfunc"));
}

#[test]
fn test_rotate_pass_packed_keeps_live_regs() {
    let mut prog = make_program(vec![
        BpfInsn::mov64_imm(3, 99),
        BpfInsn::mov64_reg(4, 2), // provenance for tmp=r4
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 4, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 4),
        BpfInsn::mov64_reg(0, 3), // r3 is live after site
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_rotate_kfunc(9999);

    let pass = RotatePass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    let has_kfunc_call = prog
        .insns
        .iter()
        .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL);
    assert!(has_kfunc_call, "expected a kfunc call in the output");
}

#[test]
fn test_rotate_pass_packed_no_callee_saved_dependency() {
    let mut prog = make_program(vec![
        BpfInsn::mov64_imm(3, 99),
        BpfInsn::mov64_reg(4, 2), // provenance for tmp=r4
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 4, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 4),
        // Use r3, r6, r7, r8, r9 after site to make them all live
        BpfInsn::alu64_reg(BPF_OR, 0, 3),
        BpfInsn::alu64_reg(BPF_OR, 0, 6),
        BpfInsn::alu64_reg(BPF_OR, 0, 7),
        BpfInsn::alu64_reg(BPF_OR, 0, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 9),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_rotate_kfunc(9999);

    let pass = RotatePass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
}

#[test]
fn test_rotate_pass_tmp_live_out_conflict() {
    // tmp_reg (r6, callee-saved) is live after the site -- should skip.
    let mut prog = make_program(vec![
        BpfInsn::mov64_reg(6, 2), // provenance
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 6, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 6),
        BpfInsn::mov64_reg(0, 6), // r6 is used after site
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_rotate_kfunc(9999);

    let pass = RotatePass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("tmp_reg")));
}

#[test]
fn test_rotate_pass_applies_site_inside_multi_subprog_program() {
    let mut prog = make_program(vec![
        pseudo_call_to(0, 2),
        exit_insn(),
        BpfInsn::mov64_reg(3, 2),
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_rotate_kfunc(1234);

    let pass = RotatePass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    assert!(prog
        .insns
        .iter()
        .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL && i.imm == 1234));
}

// ── Issue 2: dst overwrite between MOV and shift ─────────────

#[test]
fn test_rotate_pass_no_match_dst_overwritten_after_mov() {
    // mov r3, r2; add r2, 1; rsh r2, 56; lsh r3, 8; or r2, r3
    // The MOV r3, r2 establishes provenance, but then r2 is modified
    // by ADD. At the RSH, r2 is a different value than what r3 holds.
    // This should NOT match as a rotate.
    let insns = vec![
        BpfInsn::mov64_reg(3, 2),           // MOV r3, r2
        BpfInsn::alu64_imm(BPF_OR, 2, 1),   // modifies r2 (any ALU op)
        BpfInsn::alu64_imm(BPF_RSH, 2, 56), // RSH r2, 56
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),  // LSH r3, 8
        BpfInsn::alu64_reg(BPF_OR, 2, 3),   // OR r2, r3
    ];
    let sites = scan_rotate_sites(&insns);
    assert!(
        sites.is_empty(),
        "should not match when dst is overwritten after MOV"
    );
}

#[test]
fn test_rotate_pass_no_match_dst_overwritten_by_ldx() {
    // mov r3, r2; ldx r2, [r6+0]; rsh r2, 56; lsh r3, 8; or r2, r3
    let insns = vec![
        BpfInsn::mov64_reg(3, 2),
        BpfInsn::ldx_mem(BPF_DW, 2, 6, 0), // overwrites r2
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];
    let sites = scan_rotate_sites(&insns);
    assert!(
        sites.is_empty(),
        "should not match when dst is overwritten by LDX"
    );
}

#[test]
fn test_rotate_pass_no_match_with_intervening_harmless_insn() {
    // Even a harmless intervening instruction changes the window shape.
    // The pass now requires the provenance MOV to be immediately adjacent
    // to the rotate idiom so it never drops side effects in between.
    let insns = vec![
        BpfInsn::mov64_reg(3, 2),
        BpfInsn::mov64_reg(5, 6),
        BpfInsn::alu64_imm(BPF_RSH, 2, 56),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];
    let sites = scan_rotate_sites(&insns);
    assert!(sites.is_empty());
}
