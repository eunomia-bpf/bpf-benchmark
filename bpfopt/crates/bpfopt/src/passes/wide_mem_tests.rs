use super::*;
use crate::analysis::{BranchTargetAnalysis, LivenessAnalysis};
use crate::pass::{AnalysisCache, PassContext, PassManager};

fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}

fn exit_insn() -> BpfInsn {
    BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
}

fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
    BpfInsn::new(
        BPF_JMP | BPF_JEQ | BPF_K,
        BpfInsn::make_regs(dst, 0),
        off,
        imm,
    )
}

/// Build a canonical 4-byte low-byte-first byte-ladder (Variant A).
fn make_wide_mem_4byte_program() -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_B, 2, 1, 0),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 1),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 2),
        BpfInsn::alu64_imm(BPF_LSH, 3, 16),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 3),
        BpfInsn::alu64_imm(BPF_LSH, 3, 24),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        exit_insn(),
    ]
}

// ── Pattern matching tests (from matcher.rs) ──────────────────

fn build_wide_mem_4(dst: u8, base: u8, off: i16) -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_B, dst, base, off),
        BpfInsn::ldx_mem(BPF_B, 2, base, off + 1),
        BpfInsn::alu64_imm(BPF_LSH, 2, 8),
        BpfInsn::alu64_reg(BPF_OR, dst, 2),
        BpfInsn::ldx_mem(BPF_B, 3, base, off + 2),
        BpfInsn::alu64_imm(BPF_LSH, 3, 16),
        BpfInsn::alu64_reg(BPF_OR, dst, 3),
        BpfInsn::ldx_mem(BPF_B, 4, base, off + 3),
        BpfInsn::alu64_imm(BPF_LSH, 4, 24),
        BpfInsn::alu64_reg(BPF_OR, dst, 4),
    ]
}

#[test]
fn test_scan_wide_mem_4byte() {
    let insns = build_wide_mem_4(0, 6, 10);
    let sites = scan_wide_mem(&insns);
    assert_eq!(sites.len(), 1);
    let s = &sites[0];
    assert_eq!(s.start_pc, 0);
    assert_eq!(s.old_len, 10);
    assert_eq!(s.get_binding("dst_reg"), Some(0));
    assert_eq!(s.get_binding("base_reg"), Some(6));
    assert_eq!(s.get_binding("base_off"), Some(10));
    assert_eq!(s.get_binding("width"), Some(4));
}

#[test]
fn test_scan_wide_mem_2byte() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_B, 1, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 2, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 2, 8),
        BpfInsn::alu64_reg(BPF_OR, 1, 2),
    ];
    let sites = scan_wide_mem(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].old_len, 4);
    assert_eq!(sites[0].get_binding("width"), Some(2));
}

#[test]
fn test_scan_wide_mem_no_match() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_B, 0, 6, 10),
        BpfInsn::ldx_mem(BPF_B, 2, 6, 20),
        BpfInsn::alu64_imm(BPF_LSH, 2, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 2),
    ];
    let sites = scan_wide_mem(&insns);
    assert!(sites.is_empty());
}

#[test]
fn test_scan_wide_mem_embedded_in_program() {
    let mut insns = vec![BpfInsn::mov64_imm(0, 0)];
    insns.extend(build_wide_mem_4(0, 6, 10));
    insns.push(BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0));
    let sites = scan_wide_mem(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].start_pc, 1);
    assert_eq!(sites[0].old_len, 10);
}

#[test]
fn test_scan_wide_mem_multiple_sites() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        BpfInsn::ldx_mem(BPF_B, 3, 7, 4),
        BpfInsn::ldx_mem(BPF_B, 4, 7, 5),
        BpfInsn::alu64_imm(BPF_LSH, 4, 8),
        BpfInsn::alu64_reg(BPF_OR, 3, 4),
    ];
    let sites = scan_wide_mem(&insns);
    assert_eq!(sites.len(), 2);
    assert_eq!(sites[0].start_pc, 0);
    assert_eq!(sites[0].get_binding("dst_reg"), Some(0));
    assert_eq!(sites[1].start_pc, 4);
    assert_eq!(sites[1].get_binding("dst_reg"), Some(3));
}

// ── High-byte-first (Variant B) tests ──────────────────────────

fn build_wide_mem_high_first_2(dst: u8, tmp: u8, base: u8, off: i16) -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_B, dst, base, off + 1),
        BpfInsn::alu64_imm(BPF_LSH, dst, 8),
        BpfInsn::ldx_mem(BPF_B, tmp, base, off),
        BpfInsn::alu64_reg(BPF_OR, dst, tmp),
    ]
}

#[test]
fn test_scan_high_first_2byte() {
    let insns = build_wide_mem_high_first_2(1, 2, 6, 10);
    let sites = scan_wide_mem(&insns);
    assert_eq!(sites.len(), 1);
    let s = &sites[0];
    assert_eq!(s.start_pc, 0);
    assert_eq!(s.old_len, 4);
    assert_eq!(s.get_binding("dst_reg"), Some(1));
    assert_eq!(s.get_binding("base_reg"), Some(6));
    assert_eq!(s.get_binding("base_off"), Some(10));
    assert_eq!(s.get_binding("width"), Some(2));
}

#[test]
fn test_scan_high_first_matches_clang_output() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_B, 2, 1, 9),
        BpfInsn::alu64_imm(BPF_LSH, 2, 8),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 10),
        BpfInsn::alu64_imm(BPF_LSH, 3, 16),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 11),
        BpfInsn::alu64_imm(BPF_LSH, 3, 24),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];
    let sites = scan_wide_mem(&insns);
    assert_eq!(sites.len(), 1);
    let s = &sites[0];
    assert_eq!(s.start_pc, 0);
    assert_eq!(s.old_len, 10);
    assert_eq!(s.get_binding("dst_reg"), Some(2));
    assert_eq!(s.get_binding("base_reg"), Some(1));
    assert_eq!(s.get_binding("base_off"), Some(8));
    assert_eq!(s.get_binding("width"), Some(4));
}

#[test]
fn test_scan_high_first_no_false_positive() {
    let insns = vec![
        BpfInsn::ldx_mem(BPF_B, 2, 1, 9),
        BpfInsn::alu64_imm(BPF_LSH, 2, 8),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        BpfInsn::ldx_mem(BPF_B, 3, 1, 10),
        BpfInsn::alu64_imm(BPF_LSH, 3, 24),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
    ];
    let sites = scan_wide_mem(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].old_len, 4);
    assert_eq!(sites[0].get_binding("width"), Some(2));
}

// ── Emission tests (from emit.rs) ──────────────────────────────

#[test]
fn test_emit_wide_mem_supported_widths() {
    for (width, size, dst, base, off) in [
        (2, BPF_H, 1, 7, 0),
        (4, BPF_W, 0, 6, 10),
        (8, BPF_DW, 3, 10, -8),
    ] {
        let site = RewriteSite {
            start_pc: 0,
            old_len: 1 + 3 * (width as usize - 1),
            bindings: vec![
                Binding {
                    name: "dst_reg",
                    value: dst as i64,
                },
                Binding {
                    name: "base_reg",
                    value: base as i64,
                },
                Binding {
                    name: "base_off",
                    value: off as i64,
                },
                Binding {
                    name: "width",
                    value: width as i64,
                },
            ],
        };
        let result = emit_wide_mem(&site).unwrap();
        assert_eq!(result.len(), 1);
        assert_eq!(result[0].code, BPF_LDX | size | BPF_MEM);
        assert_eq!(result[0].dst_reg(), dst as u8);
        assert_eq!(result[0].src_reg(), base as u8);
        assert_eq!(result[0].off, off as i16);
    }
}

#[test]
fn test_emit_wide_mem_unsupported_width() {
    let site = RewriteSite {
        start_pc: 0,
        old_len: 7,
        bindings: vec![
            Binding {
                name: "dst_reg",
                value: 0,
            },
            Binding {
                name: "base_reg",
                value: 6,
            },
            Binding {
                name: "base_off",
                value: 0,
            },
            Binding {
                name: "width",
                value: 3,
            },
        ],
    };
    assert!(emit_wide_mem(&site).is_err());
}

// ── Pass tests ─────────────────────────────────────────────────

#[test]
fn test_wide_mem_pass_no_sites() {
    let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(!result.changed);
    assert_eq!(result.sites_applied, 0);
    assert_eq!(prog.insns.len(), 2);
}

#[test]
fn test_wide_mem_pass_transforms_correctly() {
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_B, 0, 6, 10),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 11),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(result.changed);
    assert_eq!(result.sites_applied, 1);
    assert_eq!(prog.insns.len(), 2);
    assert_eq!(bpf_size(prog.insns[0].code), BPF_H);
    assert_eq!(prog.insns[0].dst_reg(), 0);
    assert_eq!(prog.insns[0].src_reg(), 6);
    assert_eq!(prog.insns[0].off, 10);
}

#[test]
fn test_wide_mem_pass_skips_site_with_interior_branch_target() {
    let mut prog = make_program(vec![
        jeq_imm(5, 0, 2),
        BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(!result.changed);
    assert_eq!(result.sites_applied, 0);
    assert!(!result.sites_skipped.is_empty());
    assert!(result.sites_skipped[0]
        .reason
        .contains("interior branch target"));
}

#[test]
fn test_wide_mem_pass_multiple_sites() {
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        BpfInsn::ldx_mem(BPF_B, 3, 7, 4),
        BpfInsn::ldx_mem(BPF_B, 4, 7, 5),
        BpfInsn::alu64_imm(BPF_LSH, 4, 8),
        BpfInsn::alu64_reg(BPF_OR, 3, 4),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(result.changed);
    assert_eq!(result.sites_applied, 2);
    assert_eq!(prog.insns.len(), 3);
}

#[test]
fn test_wide_mem_pass_skips_site_with_live_scratch_reg() {
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        BpfInsn::mov64_reg(2, 1),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(!result.changed);
    assert_eq!(result.sites_applied, 0);
    assert!(!result.sites_skipped.is_empty());
    assert!(result.sites_skipped[0]
        .reason
        .contains("scratch register live"),);
    assert_eq!(prog.insns.len(), 6);
}

#[test]
fn test_wide_mem_pass_integration_with_pass_manager() {
    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.add_pass(WideMemPass);

    let mut prog = make_program(make_wide_mem_4byte_program());
    let ctx = PassContext::test_default();

    let result = pm.run(&mut prog, &ctx).unwrap();

    assert!(result.program_changed);
    assert_eq!(result.total_sites_applied, 1);
    assert_eq!(prog.insns.len(), 2);
}

// ── Branch fixup tests (from rewriter.rs) ──────────────────────

fn wide_mem_4_insns(dst: u8, base: u8, off: i16) -> Vec<BpfInsn> {
    build_wide_mem_4(dst, base, off)
}

#[test]
fn test_branch_fixup_forward_across_site() {
    let mut insns = Vec::new();
    insns.push(BpfInsn::ja(10));
    insns.extend(wide_mem_4_insns(0, 6, 0));
    insns.push(exit_insn());

    let mut prog = make_program(insns);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(result.changed);
    assert_eq!(prog.insns.len(), 3);
    let ja = &prog.insns[0];
    assert!(ja.is_ja());
    assert_eq!(ja.off, 1, "ja should jump to exit at pc 2");
}

#[test]
fn test_branch_fixup_backward_across_site() {
    let mut insns = Vec::new();
    insns.push(BpfInsn::mov64_imm(0, 0));
    insns.extend(wide_mem_4_insns(0, 6, 0));
    insns.push(BpfInsn::ja(-12));
    insns.push(exit_insn());

    let mut prog = make_program(insns);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(result.changed);
    assert_eq!(prog.insns.len(), 4);
    let ja = &prog.insns[2];
    assert!(ja.is_ja());
    assert_eq!(ja.off, -3, "ja should jump back to pc 0");
}

#[test]
fn test_conditional_branch_fixup() {
    let mut insns = Vec::new();
    insns.push(BpfInsn::new(
        BPF_JMP | BPF_JEQ | BPF_K,
        BpfInsn::make_regs(1, 0),
        10,
        0,
    ));
    insns.extend(wide_mem_4_insns(0, 6, 0));
    insns.push(exit_insn());

    let mut prog = make_program(insns);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(result.changed);
    assert_eq!(prog.insns.len(), 3);
    let jeq = &prog.insns[0];
    assert!(jeq.is_cond_jmp());
    assert_eq!(jeq.off, 1, "jeq should jump to exit at pc=2");
}

#[test]
fn test_wide_mem_pass_skips_unsupported_width_3() {
    // Build a 3-byte low-first byte-ladder: LDX(B, dst, base, 0) + 2 more bytes.
    // Width 3 is detected by the daemon but cannot be emitted as a single load.
    let insns = vec![
        BpfInsn::ldx_mem(BPF_B, 0, 6, 0), // byte 0
        BpfInsn::ldx_mem(BPF_B, 1, 6, 1), // byte 1
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 2), // byte 2
        BpfInsn::alu64_imm(BPF_LSH, 1, 16),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        exit_insn(),
    ];

    // Verify the daemon finds a width=3 site.
    let sites = scan_wide_mem(&insns);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].get_binding("width"), Some(3));

    // The pass should skip this site (unsupported width) without error.
    let mut prog = make_program(insns);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(!result.changed, "width=3 should be skipped, not applied");
    assert_eq!(result.sites_applied, 0);
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("unsupported width")));
}

#[test]
fn test_wide_mem_pass_applies_width4_skips_width3_mixed() {
    // Program with both a width=4 site (supported) and a width=3 site (unsupported).
    // The pass should apply the width=4 site and skip the width=3 site.
    let insns = vec![
        // Width=4 low-first: dst=0, base=6, off=0
        BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 2),
        BpfInsn::alu64_imm(BPF_LSH, 1, 16),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 3),
        BpfInsn::alu64_imm(BPF_LSH, 1, 24),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        // Width=3 low-first: dst=2, base=7, off=0
        BpfInsn::ldx_mem(BPF_B, 2, 7, 0),
        BpfInsn::ldx_mem(BPF_B, 3, 7, 1),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        BpfInsn::ldx_mem(BPF_B, 3, 7, 2),
        BpfInsn::alu64_imm(BPF_LSH, 3, 16),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        exit_insn(),
    ];

    let mut prog = make_program(insns);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert!(result.changed, "width=4 site should be applied");
    assert_eq!(result.sites_applied, 1);
    // The width=3 site should be in sites_skipped.
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("unsupported width 3")));
}

// ── Packet pointer safety tests ─────────────────────────────────

#[test]
fn test_is_packet_unsafe_prog_type() {
    // XDP and TC are packet-unsafe.
    assert!(is_packet_unsafe_prog_type(6)); // XDP
    assert!(is_packet_unsafe_prog_type(3)); // SCHED_CLS
    assert!(is_packet_unsafe_prog_type(4)); // SCHED_ACT
                                            // Tracing, kprobe, etc. are not packet-unsafe.
    assert!(!is_packet_unsafe_prog_type(0)); // unspecified
    assert!(!is_packet_unsafe_prog_type(1)); // SOCKET_FILTER
    assert!(!is_packet_unsafe_prog_type(2)); // KPROBE
    assert!(!is_packet_unsafe_prog_type(5)); // CGROUP_SKB
    assert!(!is_packet_unsafe_prog_type(7)); // PERF_EVENT
    assert!(!is_packet_unsafe_prog_type(26)); // TRACING
}

#[test]
fn test_wide_mem_skips_non_stack_in_xdp() {
    // 2-byte wide_mem site with base_reg=6 (not stack pointer R10).
    // In XDP prog (type 6), this should be skipped.
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let mut ctx = PassContext::test_default();
    ctx.prog_type = 6; // XDP

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(!result.changed, "should skip non-stack base in XDP");
    assert_eq!(result.sites_applied, 0);
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("packet pointer") || s.reason.contains("non-stack base")));
}

#[test]
fn test_wide_mem_allows_stack_base_in_xdp() {
    // Byte-ladder from R10 (stack pointer) should still work in XDP.
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_B, 0, 10, -4),
        BpfInsn::ldx_mem(BPF_B, 1, 10, -3),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        BpfInsn::ldx_mem(BPF_B, 1, 10, -2),
        BpfInsn::alu64_imm(BPF_LSH, 1, 16),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        BpfInsn::ldx_mem(BPF_B, 1, 10, -1),
        BpfInsn::alu64_imm(BPF_LSH, 1, 24),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let mut ctx = PassContext::test_default();
    ctx.prog_type = 6; // XDP

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(result.changed, "R10-based wide_mem should apply in XDP");
    assert_eq!(result.sites_applied, 1);
    assert_eq!(prog.insns.len(), 2);
    assert_eq!(bpf_size(prog.insns[0].code), BPF_W);
    assert_eq!(prog.insns[0].src_reg(), 10);
    assert_eq!(prog.insns[0].off, -4);
}

#[test]
fn test_wide_mem_allows_map_value_base_in_xdp() {
    // In XDP, a base register derived from a map value (via LDX_MEM from
    // R0, not R1/ctx) should be allowed — it's not a packet pointer.
    let mut prog = make_program(vec![
        // r6 = *(u64 *)(r0 + 0)  -- map value pointer, not ctx
        BpfInsn::ldx_mem(BPF_DW, 6, 0, 0),
        // byte-ladder from r6
        BpfInsn::ldx_mem(BPF_B, 2, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 3, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let mut ctx = PassContext::test_default();
    ctx.prog_type = 6; // XDP

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(result.changed, "map-value base in XDP should be allowed");
    assert_eq!(result.sites_applied, 1);
}

#[test]
fn test_wide_mem_allows_non_stack_in_tracing() {
    // In non-packet prog types (e.g., tracing/kprobe), non-stack base is OK.
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let mut ctx = PassContext::test_default();
    ctx.prog_type = 26; // TRACING

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(
        result.changed,
        "non-stack base should work in tracing progs"
    );
    assert_eq!(result.sites_applied, 1);
}

#[test]
fn test_wide_mem_mixed_sites_xdp_some_skipped() {
    // Two sites: one from stack (R10, should apply), one from R6 (should skip in XDP).
    let insns = vec![
        // Site 1: R10-based (stack), 2-byte
        BpfInsn::ldx_mem(BPF_B, 0, 10, -4),
        BpfInsn::ldx_mem(BPF_B, 1, 10, -3),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::alu64_reg(BPF_OR, 0, 1),
        // Site 2: R6-based (potential packet ptr), 2-byte
        BpfInsn::ldx_mem(BPF_B, 2, 6, 0),
        BpfInsn::ldx_mem(BPF_B, 3, 6, 1),
        BpfInsn::alu64_imm(BPF_LSH, 3, 8),
        BpfInsn::alu64_reg(BPF_OR, 2, 3),
        exit_insn(),
    ];

    let mut prog = make_program(insns);
    let mut cache = AnalysisCache::new();
    let mut ctx = PassContext::test_default();
    ctx.prog_type = 6; // XDP

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();

    assert!(result.changed, "stack-based site should still apply");
    assert_eq!(result.sites_applied, 1);
    assert_eq!(
        result
            .sites_skipped
            .iter()
            .filter(|s| s.reason.contains("packet pointer") || s.reason.contains("non-stack base"))
            .count(),
        1,
        "one site should be skipped for likely packet pointer in XDP"
    );
}
