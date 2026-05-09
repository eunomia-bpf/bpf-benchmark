use super::endian::*;
use crate::insn::*;
use crate::pass::*;
use crate::pass::{AnalysisCache, PassContext};
use crate::test_helpers::*;

fn endian_to_be(dst: u8, size: i32) -> BpfInsn {
    BpfInsn::new(
        BPF_ALU | BPF_END | BPF_TO_BE,
        BpfInsn::make_regs(dst, 0),
        0,
        size,
    )
}

fn ctx_with_endian_kfuncs(btf_id16: i32, btf_id32: i32, btf_id64: i32) -> PassContext {
    let mut ctx = PassContext::baseline();
    ctx.kinsn_registry.endian_load16_btf_id = btf_id16;
    ctx.kinsn_registry.endian_load32_btf_id = btf_id32;
    ctx.kinsn_registry.endian_load64_btf_id = btf_id64;
    ctx.platform.has_movbe = true;
    ctx
}

fn ctx_with_endian32_kfunc(btf_id: i32) -> PassContext {
    ctx_with_endian_kfuncs(-1, btf_id, -1)
}

// ── Pattern scanning tests ─────────────────────────────────────

#[test]
fn test_scan_endian_fusion_basic_32bit() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_W, 2, 1, 4), // LDX_MEM(W) r2, [r1+4]
        endian_to_be(2, 32),              // ENDIAN_TO_BE r2, 32
        BpfInsn::exit(),
    ];
    let sites = scan_endian_fusion_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].start_pc, 0);
    assert_eq!(sites[0].old_len, 2);
    assert_eq!(sites[0].dst_reg, 2);
    assert_eq!(sites[0].src_reg, 1);
    assert_eq!(sites[0].offset, 4);
    assert_eq!(sites[0].size, BPF_W);
}

#[test]
fn test_scan_endian_fusion_16bit() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_H, 3, 6, 10),
        endian_to_be(3, 16),
        BpfInsn::exit(),
    ];
    let sites = scan_endian_fusion_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].size, BPF_H);
    assert_eq!(sites[0].dst_reg, 3);
    assert_eq!(sites[0].offset, 10);
}

#[test]
fn test_scan_endian_fusion_64bit() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_DW, 0, 7, 0),
        endian_to_be(0, 64),
        BpfInsn::exit(),
    ];
    let sites = scan_endian_fusion_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].size, BPF_DW);
    assert_eq!(sites[0].dst_reg, 0);
    assert_eq!(sites[0].offset, 0);
}

#[test]
fn test_scan_endian_fusion_no_match_different_regs() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
        endian_to_be(3, 32), // different dst
        BpfInsn::exit(),
    ];
    let sites = scan_endian_fusion_sites(&insns);
    assert!(sites.is_empty());
}

#[test]
fn test_scan_endian_fusion_no_match_size_mismatch() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_H, 2, 1, 0), // 16-bit load
        endian_to_be(2, 32),              // 32-bit swap -- mismatch
        BpfInsn::exit(),
    ];
    let sites = scan_endian_fusion_sites(&insns);
    assert!(sites.is_empty());
}

#[test]
fn test_scan_endian_fusion_no_match_byte_load() {
    // BPF_B (byte) load doesn't need endian swap.
    let insns = vec![
        BpfInsn::ldx_mem(BPF_B, 2, 1, 0),
        endian_to_be(2, 16),
        BpfInsn::exit(),
    ];
    let sites = scan_endian_fusion_sites(&insns);
    assert!(sites.is_empty());
}

#[test]
fn test_scan_endian_fusion_multiple_sites() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
        endian_to_be(2, 32),
        BpfInsn::ldx_mem(BPF_H, 3, 1, 4),
        endian_to_be(3, 16),
        BpfInsn::exit(),
    ];
    let sites = scan_endian_fusion_sites(&insns);
    assert_eq!(sites.len(), 2);
    assert_eq!(sites[0].start_pc, 0);
    assert_eq!(sites[0].size, BPF_W);
    assert_eq!(sites[1].start_pc, 2);
    assert_eq!(sites[1].size, BPF_H);
}

#[test]
fn test_scan_endian_fusion_zero_offset() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
        endian_to_be(2, 32),
        BpfInsn::exit(),
    ];
    let sites = scan_endian_fusion_sites(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].offset, 0);
}

// ── Pass execution tests ───────────────────────────────────────

#[test]
fn test_endian_fusion_pass_skip_when_kfunc_unavailable() {
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0),
        endian_to_be(2, 32),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let mut ctx = PassContext::baseline(); // all btf_ids = -1
    ctx.platform.has_movbe = true; // platform has MOVBE, but kfunc is missing

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 0);
    assert!(result.sites_skipped[0]
        .reason
        .contains("kfuncs not available"));
}

#[test]
fn test_endian_fusion_pass_emit_kfunc_call_32bit() {
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_W, 2, 6, 8),
        endian_to_be(2, 32),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888);

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);

    // Verify a kfunc call exists with the correct btf_id.
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
    assert_eq!(call_insn.imm, 8888);

    // Verify the last instruction is still EXIT.
    assert!(prog.insns.last().unwrap().is_exit());
}

#[test]
fn test_endian_fusion_narrowing_cases() {
    let sites = scan_endian_fusion_sites(&[
        BpfInsn::ldx_mem(BPF_DW, 2, 6, 8),
        endian_to_be(2, 32),
        BpfInsn::ldx_mem(BPF_DW, 3, 6, 16),
        endian_to_be(3, 16),
        BpfInsn::ldx_mem(BPF_W, 4, 6, 24),
        endian_to_be(4, 16),
    ]);
    assert_eq!(sites.len(), 3);
    assert_eq!(sites[0].size, BPF_W);
    assert_eq!(sites[1].size, BPF_H);
    assert_eq!(sites[2].size, BPF_H);

    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_DW, 2, 6, 8),
        BpfInsn::mov64_imm(3, 7),
        endian_to_be(2, 32),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let result = EndianFusionPass
        .run(&mut prog, &mut cache, &ctx_with_endian32_kfunc(8888))
        .unwrap();
    assert_eq!(result.sites_applied, 1);
    assert!(prog.insns[0].is_kinsn_sidecar());
    assert!(prog.insns[1].is_call());
    assert_eq!(prog.insns[2], BpfInsn::mov64_imm(3, 7));

    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_DW, 2, 6, 8),
        BpfInsn::mov64_reg(3, 2),
        endian_to_be(2, 32),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let result = EndianFusionPass
        .run(&mut prog, &mut cache, &ctx_with_endian32_kfunc(8888))
        .unwrap();
    assert!(result
        .sites_skipped
        .iter()
        .any(|skip| skip.reason.contains("upper bits read")));
}

#[test]
fn test_endian_fusion_pass_zero_offset() {
    // Zero-offset packed encoding stores the base register directly in the
    // low payload bits consumed by the endian kinsn decoder.
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
        endian_to_be(2, 32),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888);

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);

    assert!(prog.insns[0].is_kinsn_sidecar());
    assert_eq!(prog.insns[0].dst_reg(), 2);
    assert_eq!(prog.insns[0].off, 6);
    assert_eq!(prog.insns[0].imm, 0);
}

#[test]
fn test_endian_fusion_pass_nonzero_offset() {
    // Non-zero offsets are encoded directly in the packed payload on x86.
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_W, 2, 6, 12),
        endian_to_be(2, 32),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888);

    let pass = EndianFusionPass;
    let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(prog.insns.len(), 3);
    assert!(prog.insns[0].is_kinsn_sidecar());
    assert_eq!(sidecar_payload(&prog.insns[0]), endian_payload(2, 6, 12));
    assert!(prog.insns[1].is_call());
    assert!(prog.insns[2].is_exit());
}

#[test]
fn test_endian_fusion_encodes_stack_offset_directly_on_x86() {
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_DW, 4, BPF_REG_10, -88),
        endian_to_be(4, 64),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian_kfuncs(-1, -1, 3333);

    let pass = EndianFusionPass;
    let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(prog.insns.len(), 3);
    assert!(prog.insns[0].is_kinsn_sidecar());
    assert_eq!(
        sidecar_payload(&prog.insns[0]),
        endian_payload(4, BPF_REG_10, -88)
    );
    assert!(prog.insns[1].is_call());
    assert!(prog.insns[2].is_exit());
}

#[test]
fn test_endian_fusion_pass_packed_keeps_live_regs() {
    let mut prog = make_program(vec![
        BpfInsn::mov64_imm(3, 99), // r3 = 99
        BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
        endian_to_be(2, 32),
        BpfInsn::mov64_reg(0, 3), // uses r3 after site
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888);

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    let has_kfunc_call = prog
        .insns
        .iter()
        .any(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL);
    assert!(has_kfunc_call);
}

#[test]
fn test_endian_fusion_pass_packed_no_callee_saved_dependency() {
    let mut prog = make_program(vec![
        BpfInsn::mov64_imm(3, 99),
        BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
        endian_to_be(2, 32),
        BpfInsn::alu64_reg(BPF_OR, 0, 3),
        BpfInsn::alu64_reg(BPF_OR, 0, 6),
        BpfInsn::alu64_reg(BPF_OR, 0, 7),
        BpfInsn::alu64_reg(BPF_OR, 0, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 9),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888);

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
}

#[test]
fn test_endian_fusion_pass_interior_branch_target() {
    // A branch targets the ENDIAN_TO_BE instruction inside the site.
    let mut prog = make_program(vec![
        jeq_imm(5, 0, 1),                 // if r5 == 0, jump to pc=2
        BpfInsn::ldx_mem(BPF_W, 2, 1, 0), // pc=1
        endian_to_be(2, 32),              // pc=2 -- branch target
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888);

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("interior branch")));
}

#[test]
fn test_endian_fusion_pass_branch_fixup() {
    // Branch over a 2-insn site. After rewrite the site becomes
    // longer (kfunc call sequence), so branch offsets must be adjusted.
    let mut prog = make_program(vec![
        jeq_imm(5, 0, 2),                 // if r5==0, skip 2 insns to exit
        BpfInsn::ldx_mem(BPF_W, 2, 6, 4), // pc=1: site start
        endian_to_be(2, 32),              // pc=2: site end
        BpfInsn::exit(),                  // pc=3: branch target
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888);

    let pass = EndianFusionPass;
    let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    // The branch at pc=0 should still reach the EXIT instruction.
    let last_pc = prog.insns.len() - 1;
    assert!(prog.insns[last_pc].is_exit());
    let branch_target = (1 + prog.insns[0].off as i64) as usize;
    assert_eq!(branch_target, last_pc);
}

#[test]
fn test_endian_fusion_pass_uses_static_call_offset() {
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_W, 2, 6, 0),
        endian_to_be(2, 32),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let mut ctx = ctx_with_endian32_kfunc(8888);
    ctx.kinsn_registry
        .target_call_offsets
        .insert("bpf_endian_load32".to_string(), 42);

    let pass = EndianFusionPass;
    let _result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(prog
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == 8888 && insn.off == 42));
}

#[test]
fn test_endian_fusion_pass_uses_per_size_call_offsets() {
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_H, 2, 6, 0),
        endian_to_be(2, 16),
        BpfInsn::ldx_mem(BPF_W, 3, 6, 4),
        endian_to_be(3, 32),
        BpfInsn::ldx_mem(BPF_DW, 4, 6, 8),
        endian_to_be(4, 64),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let mut ctx = ctx_with_endian_kfuncs(111, 222, 333);
    ctx.kinsn_registry.target_call_offsets.extend([
        ("bpf_endian_load16".to_string(), 11),
        ("bpf_endian_load32".to_string(), 22),
        ("bpf_endian_load64".to_string(), 33),
    ]);

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 3);
    assert!(prog
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == 111 && insn.off == 11));
    assert!(prog
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == 222 && insn.off == 22));
    assert!(prog
        .insns
        .iter()
        .any(|insn| insn.is_call() && insn.imm == 333 && insn.off == 33));
}

#[test]
fn test_endian_fusion_pass_specific_size_unavailable() {
    // Only 32-bit kfunc available, but pattern is 16-bit.
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_H, 2, 1, 0),
        endian_to_be(2, 16),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888); // only 32-bit available

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 0);
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("load16")));
}

#[test]
fn test_endian_fusion_pass_dst_is_r0() {
    // When dst_reg is r0, no trailing MOV should be emitted.
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_W, 0, 6, 0),
        endian_to_be(0, 32),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888);

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 1);
    // No redundant MOV r0, r0.
    let mov_r0_r0_count = prog
        .insns
        .iter()
        .filter(|i| i.code == (BPF_ALU64 | BPF_MOV | BPF_X) && i.dst_reg() == 0 && i.src_reg() == 0)
        .count();
    assert_eq!(mov_r0_r0_count, 0, "should not emit redundant MOV r0, r0");
}

#[test]
fn test_endian_fusion_pass_two_consecutive_sites() {
    // Use different offsets to verify back-to-back packed endian sites.
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_W, 7, 6, 0),
        endian_to_be(7, 32),
        BpfInsn::ldx_mem(BPF_W, 8, 6, 4),
        endian_to_be(8, 32),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian32_kfunc(8888);

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 2);
    // Verify two kfunc calls exist.
    let call_count = prog
        .insns
        .iter()
        .filter(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL && i.imm == 8888)
        .count();
    assert_eq!(call_count, 2);
    assert!(prog.insns.last().unwrap().is_exit());
}

#[test]
fn test_endian_fusion_pass_all_three_sizes() {
    // Verify all size variants use packed endian payloads.
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_H, 7, 6, 0),
        endian_to_be(7, 16),
        BpfInsn::ldx_mem(BPF_W, 8, 6, 2),
        endian_to_be(8, 32),
        BpfInsn::ldx_mem(BPF_DW, 9, 6, 6),
        endian_to_be(9, 64),
        BpfInsn::exit(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = ctx_with_endian_kfuncs(1111, 2222, 3333);

    let pass = EndianFusionPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 3);

    // Check we got the right BTF IDs for each size.
    let calls: Vec<i32> = prog
        .insns
        .iter()
        .filter(|i| i.is_call() && i.src_reg() == BPF_PSEUDO_KINSN_CALL)
        .map(|i| i.imm)
        .collect();
    assert!(calls.contains(&1111), "should contain 16-bit kfunc btf_id");
    assert!(calls.contains(&2222), "should contain 32-bit kfunc btf_id");
    assert!(calls.contains(&3333), "should contain 64-bit kfunc btf_id");
}
