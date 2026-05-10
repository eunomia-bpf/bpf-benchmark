use super::extract::*;
use crate::insn::*;
use crate::pass::*;
use crate::pass::{AnalysisCache, PassContext};
use crate::test_helpers::*;

fn ctx_with_extract_kfunc(btf_id: i32) -> PassContext {
    let mut ctx = PassContext::baseline();
    ctx.kinsn_registry
        .set_btf_id_for_target_name("bpf_extract64", btf_id)
        .unwrap();
    ctx.platform.has_bmi1 = true;
    ctx
}

// ── contiguous_mask_len tests ──────────────────────────────────

#[test]
fn test_contiguous_mask_len() {
    assert_eq!(contiguous_mask_len(0), None);
    assert_eq!(contiguous_mask_len(0x1), Some(1));
    assert_eq!(contiguous_mask_len(0x3), Some(2));
    assert_eq!(contiguous_mask_len(0x7), Some(3));
    assert_eq!(contiguous_mask_len(0xf), Some(4));
    assert_eq!(contiguous_mask_len(0xff), Some(8));
    assert_eq!(contiguous_mask_len(0xffff), Some(16));
    assert_eq!(contiguous_mask_len(0xffffffff), Some(32));
    // Non-contiguous masks
    assert_eq!(contiguous_mask_len(0x5), None); // 101
    assert_eq!(contiguous_mask_len(0xa), None); // 1010
    assert_eq!(contiguous_mask_len(0x101), None); // 100000001
                                                  // Additional edge cases
    assert_eq!(contiguous_mask_len(0x1f), Some(5)); // 11111
    assert_eq!(contiguous_mask_len(0x3f), Some(6)); // 111111
    assert_eq!(contiguous_mask_len(0x7f), Some(7)); // 1111111
    assert_eq!(contiguous_mask_len(0x1ff), Some(9)); // 9 bits
    assert_eq!(contiguous_mask_len(0xffffff), Some(24));
    // Non-contiguous: gaps in the middle
    assert_eq!(contiguous_mask_len(0x6), None); // 110 — not from bit 0
    assert_eq!(contiguous_mask_len(0xfe), None); // 11111110 — not from bit 0
    assert_eq!(contiguous_mask_len(0x10), None); // single bit not at 0
    assert_eq!(contiguous_mask_len(0x80), None); // single high bit
}

// ── Pattern scanning tests ─────────────────────────────────────

#[test]
fn test_scan_extract_basic() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),    // RSH r2, 8
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff), // AND r2, 0xff
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].start_pc, 0);
    assert_eq!(sites[0].old_len, 2);
    assert_eq!(sites[0].dst_reg, 2);
    assert_eq!(sites[0].shift_amount, 8);
    assert_eq!(sites[0].bit_len, 8);
}

#[test]
fn test_scan_extract_16bit_mask() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 3, 16),     // RSH r3, 16
        BpfInsn::alu64_imm(BPF_AND, 3, 0xffff), // AND r3, 0xffff
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].shift_amount, 16);
    assert_eq!(sites[0].bit_len, 16);
}

#[test]
fn test_scan_extract_sign_extended_all_ones_is_64bit_mask() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 3, 0),
        BpfInsn::alu64_imm(BPF_AND, 3, -1),
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].bit_len, 64);
}

#[test]
fn test_scan_extract_no_match_non_contiguous_mask() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0x5), // 0b101 - not contiguous
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert!(sites.is_empty());
}

#[test]
fn test_scan_extract_no_match_different_regs() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 3, 0xff), // different dst reg
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert!(sites.is_empty());
}

#[test]
fn test_scan_extract_multiple_sites() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
        BpfInsn::alu64_imm(BPF_RSH, 3, 16),
        BpfInsn::alu64_imm(BPF_AND, 3, 0xf),
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert_eq!(sites.len(), 2);
    assert_eq!(sites[0].start_pc, 0);
    assert_eq!(sites[0].bit_len, 8);
    assert_eq!(sites[1].start_pc, 2);
    assert_eq!(sites[1].bit_len, 4);
}

#[test]
fn test_scan_extract_zero_mask() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0), // mask = 0
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert!(sites.is_empty());
}

// ── Pass execution tests ───────────────────────────────────────

#[test]
fn test_extract_pass_skip_when_kfunc_unavailable() {
    let mut prog = make_program(vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let mut ctx = PassContext::baseline(); // bpf_extract64 unavailable
    ctx.platform.has_bmi1 = true; // platform has BMI1, but kfunc is missing

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 0);
    assert!(result.sites_skipped[0]
        .reason
        .contains("kfunc not available"));
}

#[test]
fn test_extract_pass_emit_kfunc_call() {
    let mut prog = make_program(vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);

    // Verify a kfunc call exists.
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
    assert_eq!(call_insn.imm, 7777);

    // Verify the last instruction is still EXIT.
    assert!(prog.insns.last().unwrap().is_exit());
}

#[test]
fn test_extract_pass_applies_site_inside_multi_subprog_program() {
    let mut prog = make_program(vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
        BpfInsn::pseudo_call_to(2, 4),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    assert!(prog
        .insns
        .iter()
        .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL && i.imm == 7777));
}

#[test]
fn test_extract_pass_caller_saved_with_save_restore() {
    // r3 is live after the site, but can be saved to a free callee-saved reg.
    let mut prog = make_program(vec![
        BpfInsn::mov64_imm(3, 99), // r3 = 99
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
        BpfInsn::mov64_reg(0, 3), // uses r3 after site
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    let has_kfunc_call = prog
        .insns
        .iter()
        .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL);
    assert!(has_kfunc_call);
}

#[test]
fn test_extract_pass_packed_no_callee_saved_dependency() {
    let mut prog = make_program(vec![
        BpfInsn::mov64_imm(3, 99),
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
        BpfInsn::alu64_reg(BPF_OR, 0, 3),
        BpfInsn::alu64_reg(BPF_OR, 0, 6),
        BpfInsn::alu64_reg(BPF_OR, 0, 7),
        BpfInsn::alu64_reg(BPF_OR, 0, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 9),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
}

#[test]
fn test_extract_pass_interior_branch_target() {
    // A branch targets the AND instruction inside the site.
    let mut prog = make_program(vec![
        BpfInsn::jeq_imm(5, 0, 1),            // if r5 == 0, jump to pc=2 (the AND)
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),    // pc=1
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff), // pc=2 -- branch target
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("interior branch")));
}

#[test]
fn test_extract_pass_branch_fixup() {
    // Branch over a 2-insn extract site. After rewrite the site becomes
    // longer (kfunc call sequence), so branch offsets must be adjusted.
    let mut prog = make_program(vec![
        BpfInsn::jeq_imm(5, 0, 2),            // if r5==0, skip 2 insns to exit
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),    // pc=1: site start
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff), // pc=2: site end
        BpfInsn::exit(),                      // pc=3: branch target
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    // The branch at pc=0 should still reach the EXIT instruction.
    let last_pc = prog.insns.len() - 1;
    assert!(prog.insns[last_pc].is_exit());
    // The branch offset should be adjusted to skip the expanded kfunc sequence.
    let branch_target = (1 + prog.insns[0].off as i64) as usize;
    assert_eq!(branch_target, last_pc);
}

#[test]
fn test_extract_pass_uses_static_call_offset() {
    let mut prog = make_program(vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let mut ctx = ctx_with_extract_kfunc(7777);
    ctx.kinsn_registry
        .set_call_off_for_target_name("bpf_extract64", 42)
        .unwrap();

    let pass = ExtractPass;
    let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(prog
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == 7777 && insn.off == 42));
}

// ── Edge case: width=1 (mask=1) ───────────────────────────────────

#[test]
fn test_scan_extract_width_1() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 4, 3),   // RSH r4, 3
        BpfInsn::alu64_imm(BPF_AND, 4, 0x1), // AND r4, 1 (width=1)
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].shift_amount, 3);
    assert_eq!(sites[0].bit_len, 1);
}

#[test]
fn test_extract_pass_width_1() {
    let mut prog = make_program(vec![
        BpfInsn::alu64_imm(BPF_RSH, 4, 3),
        BpfInsn::alu64_imm(BPF_AND, 4, 0x1),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    // Verify kfunc call with correct btf_id.
    let call = prog
        .insns
        .iter()
        .find(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL)
        .unwrap();
    assert_eq!(call.imm, 7777);
    assert!(prog.insns.last().unwrap().is_exit());
}

// ── Edge case: sign-extended all-ones mask ────────────────────────

#[test]
fn test_scan_extract_sign_extended_all_ones_shifted_is_not_width_32() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 16),
        BpfInsn::alu64_imm(BPF_AND, 2, -1),
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert!(sites.is_empty());
}

#[test]
fn test_extract_pass_sign_extended_all_ones_shifted_no_match() {
    let mut prog = make_program(vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 16),
        BpfInsn::alu64_imm(BPF_AND, 2, -1),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 0);
}

#[test]
fn test_scan_extract_sign_extended_all_ones_shift_too_large() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 33),
        BpfInsn::alu64_imm(BPF_AND, 2, -1),
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert!(sites.is_empty());
}

// ── Edge case: shift=0 ────────────────────────────────────────────

#[test]
fn test_scan_extract_shift_0() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 5, 0),    // RSH r5, 0 (no-op shift)
        BpfInsn::alu64_imm(BPF_AND, 5, 0xff), // AND r5, 0xff
        BpfInsn::exit(),
    ];
    let sites = scan_extract_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].shift_amount, 0);
    assert_eq!(sites[0].bit_len, 8);
}

#[test]
fn test_extract_pass_shift_0() {
    let mut prog = make_program(vec![
        BpfInsn::alu64_imm(BPF_RSH, 5, 0),
        BpfInsn::alu64_imm(BPF_AND, 5, 0xff),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
}

// ── Edge case: two consecutive extract patterns (full pass) ───────

#[test]
fn test_extract_pass_two_consecutive_sites() {
    let mut prog = make_program(vec![
        BpfInsn::alu64_imm(BPF_RSH, 6, 8),
        BpfInsn::alu64_imm(BPF_AND, 6, 0xff),
        BpfInsn::alu64_imm(BPF_RSH, 7, 16),
        BpfInsn::alu64_imm(BPF_AND, 7, 0xf),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 2);
    // Verify two kfunc calls exist.
    let call_count = prog
        .insns
        .iter()
        .filter(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL && i.imm == 7777)
        .count();
    assert_eq!(call_count, 2);
    assert!(prog.insns.last().unwrap().is_exit());
}

// ── Edge case: rsh+and but mask is NOT (1<<n)-1 ───────────────────

#[test]
fn test_scan_extract_non_power_of_two_minus_one_masks() {
    // Mask = 0x6 = 0b110 — not contiguous from bit 0.
    let insns_a = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 4),
        BpfInsn::alu64_imm(BPF_AND, 2, 0x6),
        BpfInsn::exit(),
    ];
    assert!(scan_extract_sites(&insns_a).is_empty());

    // Mask = 0x10 = 0b10000 — single bit, not at position 0.
    let insns_b = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 4),
        BpfInsn::alu64_imm(BPF_AND, 2, 0x10),
        BpfInsn::exit(),
    ];
    assert!(scan_extract_sites(&insns_b).is_empty());

    // Mask = 0xfe = 0b11111110 — contiguous but not from bit 0.
    let insns_c = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 4),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xfe_u32 as i32),
        BpfInsn::exit(),
    ];
    assert!(scan_extract_sites(&insns_c).is_empty());

    // Mask = 0x80 = 0b10000000 — single high bit.
    let insns_d = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 4),
        BpfInsn::alu64_imm(BPF_AND, 2, 0x80),
        BpfInsn::exit(),
    ];
    assert!(scan_extract_sites(&insns_d).is_empty());
}

#[test]
fn test_extract_pass_dst_is_r0() {
    // When dst_reg is r0, no trailing MOV should be emitted (result is
    // already in r0 after the call).
    let mut prog = make_program(vec![
        BpfInsn::alu64_imm(BPF_RSH, 0, 4),
        BpfInsn::alu64_imm(BPF_AND, 0, 0xf),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_extract_kfunc(7777);

    let pass = ExtractPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    // Count: should not have a trailing MOV r0, r0.
    let mov_r0_r0_count = prog
        .insns
        .iter()
        .filter(|i| i.code == (BPF_ALU64 | BPF_MOV | BPF_X) && i.dst_reg() == 0 && i.src_reg() == 0)
        .count();
    assert_eq!(mov_r0_r0_count, 0, "should not emit redundant MOV r0, r0");
}
