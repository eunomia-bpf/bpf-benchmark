use super::wide_mem::*;
use crate::insn::*;
use crate::pass::*;
use crate::pass::{AnalysisCache, PassContext};
use crate::test_helpers::*;

fn pseudo_func_ref(dst: u8, pc: usize, target_pc: usize) -> [BpfInsn; 2] {
    let imm = target_pc as i64 - (pc as i64 + 1);
    ld_imm64(dst, BPF_PSEUDO_FUNC, imm)
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

fn build_wide_mem_2(dst: u8, tmp: u8, base: u8, off: i16) -> Vec<BpfInsn> {
    vec![
        BpfInsn::ldx_mem(BPF_B, dst, base, off),
        BpfInsn::ldx_mem(BPF_B, tmp, base, off + 1),
        BpfInsn::alu64_imm(BPF_LSH, tmp, 8),
        BpfInsn::alu64_reg(BPF_OR, dst, tmp),
    ]
}

fn build_wide_mem_3(dst: u8, tmp: u8, base: u8, off: i16) -> Vec<BpfInsn> {
    let mut insns = build_wide_mem_2(dst, tmp, base, off);
    insns.push(BpfInsn::ldx_mem(BPF_B, tmp, base, off + 2));
    insns.push(BpfInsn::alu64_imm(BPF_LSH, tmp, 16));
    insns.push(BpfInsn::alu64_reg(BPF_OR, dst, tmp));
    insns
}

fn with_exit(mut insns: Vec<BpfInsn>) -> Vec<BpfInsn> {
    insns.push(exit_insn());
    insns
}

#[test]
fn test_scan_wide_mem_low_first_table() {
    for (label, insns, dst, base, off, width, old_len) in [
        ("4-byte", build_wide_mem_4(0, 6, 10), 0, 6, 10, 4, 10),
        ("2-byte", build_wide_mem_2(1, 2, 6, 0), 1, 6, 0, 2, 4),
    ] {
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), 1, "{label}");
        let s = &sites[0];
        assert_eq!(s.start_pc, 0, "{label}");
        assert_eq!(s.old_len, old_len, "{label}");
        assert_eq!(s.get_binding("dst_reg"), Some(dst), "{label}");
        assert_eq!(s.get_binding("base_reg"), Some(base), "{label}");
        assert_eq!(s.get_binding("base_off"), Some(off), "{label}");
        assert_eq!(s.get_binding("width"), Some(width), "{label}");
    }
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
fn test_scan_wide_mem_position_table() {
    let mut embedded = vec![BpfInsn::mov64_imm(0, 0)];
    embedded.extend(build_wide_mem_4(0, 6, 10));
    embedded.push(BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0));
    let mut multiple = build_wide_mem_2(0, 1, 6, 0);
    multiple.extend(build_wide_mem_2(3, 4, 7, 4));
    for (label, insns, expected) in [
        ("embedded", embedded, vec![(1, 0, 10)]),
        ("multiple sites", multiple, vec![(0, 0, 4), (4, 3, 4)]),
    ] {
        let sites = scan_wide_mem(&insns);
        assert_eq!(sites.len(), expected.len(), "{label}");
        for (site, (start_pc, dst_reg, old_len)) in sites.iter().zip(expected) {
            assert_eq!(site.start_pc, start_pc, "{label}");
            assert_eq!(site.old_len, old_len, "{label}");
            assert_eq!(site.get_binding("dst_reg"), Some(dst_reg), "{label}");
        }
    }
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
fn test_wide_mem_pass_transform_matrix() {
    for (
        label,
        mut prog,
        expected_applied,
        expected_len,
        first_size,
        first_dst,
        first_src,
        first_off,
    ) in [
        (
            "single halfword",
            make_program(with_exit(build_wide_mem_2(0, 1, 6, 10))),
            1,
            2,
            BPF_H,
            0,
            6,
            10,
        ),
        (
            "multiple sites",
            make_program({
                let mut insns = build_wide_mem_2(0, 1, 6, 0);
                insns.extend(build_wide_mem_2(3, 4, 7, 4));
                with_exit(insns)
            }),
            2,
            3,
            BPF_H,
            0,
            6,
            0,
        ),
    ] {
        let mut cache = AnalysisCache::new();
        let result = WideMemPass
            .run(&mut prog, &mut cache, &PassContext::test_default())
            .unwrap();
        assert_eq!(result.sites_applied, expected_applied, "{label}");
        assert_eq!(prog.insns.len(), expected_len, "{label}");
        assert_eq!(bpf_size(prog.insns[0].code), first_size, "{label}");
        assert_eq!(prog.insns[0].dst_reg(), first_dst, "{label}");
        assert_eq!(prog.insns[0].src_reg(), first_src, "{label}");
        assert_eq!(prog.insns[0].off, first_off, "{label}");
    }
}

#[test]
fn test_wide_mem_pass_skips_misaligned_halfword_site() {
    let mut prog = make_program(vec![
        BpfInsn::ldx_mem(BPF_B, 1, 10, -94),
        BpfInsn::alu64_imm(BPF_LSH, 1, 8),
        BpfInsn::ldx_mem(BPF_B, 2, 10, -95),
        BpfInsn::alu64_reg(BPF_OR, 1, 2),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 0);
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.reason.contains("not naturally aligned")));
    assert_eq!(prog.insns[0].code, BPF_LDX | BPF_B | BPF_MEM);
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
    assert_eq!(result.sites_applied, 0);
    assert!(!result.sites_skipped.is_empty());
    assert!(result.sites_skipped[0]
        .reason
        .contains("interior branch target"));
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
    assert_eq!(result.sites_applied, 0);
    assert!(!result.sites_skipped.is_empty());
    assert!(result.sites_skipped[0]
        .reason
        .contains("scratch register live"),);
    assert_eq!(prog.insns.len(), 6);
}

// ── Branch fixup tests (from rewriter.rs) ──────────────────────

fn wide_mem_4_insns(dst: u8, base: u8, off: i16) -> Vec<BpfInsn> {
    build_wide_mem_4(dst, base, off)
}

#[test]
fn test_wide_mem_branch_fixup_table() {
    for (label, insns, branch_pc, expected_len, expected_off, is_conditional) in {
        let mut forward = vec![BpfInsn::ja(10)];
        forward.extend(wide_mem_4_insns(0, 6, 0));
        forward.push(exit_insn());

        let mut backward = vec![BpfInsn::mov64_imm(0, 0)];
        backward.extend(wide_mem_4_insns(0, 6, 0));
        backward.push(BpfInsn::ja(-12));
        backward.push(exit_insn());

        let mut conditional = vec![BpfInsn::new(
            BPF_JMP | BPF_JEQ | BPF_K,
            BpfInsn::make_regs(1, 0),
            10,
            0,
        )];
        conditional.extend(wide_mem_4_insns(0, 6, 0));
        conditional.push(exit_insn());

        [
            ("forward ja", forward, 0, 3, 1, false),
            ("backward ja", backward, 2, 4, -3, false),
            ("conditional jeq", conditional, 0, 3, 1, true),
        ]
    } {
        let mut prog = make_program(insns);
        let mut cache = AnalysisCache::new();
        let _result = WideMemPass
            .run(&mut prog, &mut cache, &PassContext::test_default())
            .unwrap();
        assert_eq!(prog.insns.len(), expected_len, "{label}");
        let branch = &prog.insns[branch_pc];
        if is_conditional {
            assert!(branch.is_cond_jmp(), "{label}");
        } else {
            assert!(branch.is_ja(), "{label}");
        }
        assert_eq!(branch.off, expected_off, "{label}");
    }
}

#[test]
fn test_wide_mem_skips_byte_ladder_with_pseudo_func_boundary_inside() {
    let map_ref = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let callback = pseudo_func_ref(2, 2, 5);
    let mut prog = make_program(vec![
        map_ref[0],
        map_ref[1],
        callback[0],
        callback[1],
        BpfInsn::ldx_mem(BPF_B, 6, 10, -8),
        BpfInsn::ldx_mem(BPF_B, 8, 10, -7),
        BpfInsn::alu64_imm(BPF_LSH, 8, 8),
        BpfInsn::alu64_reg(BPF_OR, 6, 8),
        exit_insn(),
    ]);
    let mut cache = AnalysisCache::new();
    let ctx = PassContext::test_default();

    let pass = WideMemPass;
    let result = pass.run(&mut prog, &mut cache, &ctx).unwrap();
    assert_eq!(result.sites_applied, 0);
    assert!(result
        .sites_skipped
        .iter()
        .any(|s| s.pc == 4 && s.reason.contains("interior branch target")));
    assert_eq!(prog.insns[0].src_reg(), BPF_PSEUDO_MAP_FD);
    assert_eq!(prog.insns[0].imm, 42);
    assert!(prog.insns[2].is_ldimm64_pseudo_func());
    assert_eq!(prog.insns[2].imm, 2);
}

#[test]
fn test_wide_mem_unsupported_and_mixed_width_table() {
    let width3 = with_exit(build_wide_mem_3(0, 1, 6, 0));
    let mixed = {
        let mut insns = build_wide_mem_4(0, 6, 0);
        insns.extend(build_wide_mem_3(2, 3, 7, 0));
        with_exit(insns)
    };

    let sites = scan_wide_mem(&width3);
    assert_eq!(sites.len(), 1);
    assert_eq!(sites[0].get_binding("width"), Some(3));

    for (label, insns, expected_applied) in
        [("width3 only", width3, 0), ("width4 plus width3", mixed, 1)]
    {
        let mut prog = make_program(insns);
        let mut cache = AnalysisCache::new();
        let result = WideMemPass
            .run(&mut prog, &mut cache, &PassContext::test_default())
            .unwrap();
        assert_eq!(result.sites_applied, expected_applied, "{label}");
        assert!(result
            .sites_skipped
            .iter()
            .any(|s| s.reason.contains("unsupported width")));
    }
}

// ── Packet pointer safety tests ─────────────────────────────────

#[test]
fn test_wide_mem_packet_pointer_gate_matrix() {
    for (label, mut prog, prog_type, expected_applied, expect_packet_skip) in [
        (
            "xdp non-stack",
            make_program(with_exit(build_wide_mem_2(0, 1, 6, 0))),
            6,
            0,
            true,
        ),
        (
            "xdp stack",
            make_program(with_exit(build_wide_mem_4(0, 10, -4))),
            6,
            1,
            false,
        ),
        (
            "xdp map value",
            make_program({
                let mut insns = vec![BpfInsn::ldx_mem(BPF_DW, 6, 0, 0)];
                insns.extend(build_wide_mem_2(2, 3, 6, 0));
                with_exit(insns)
            }),
            6,
            1,
            false,
        ),
        (
            "tracing non-stack",
            make_program(with_exit(build_wide_mem_2(0, 1, 6, 0))),
            26,
            1,
            false,
        ),
    ] {
        let mut cache = AnalysisCache::new();
        let mut ctx = PassContext::test_default();
        ctx.prog_type = prog_type;
        let result = WideMemPass.run(&mut prog, &mut cache, &ctx).unwrap();
        assert_eq!(result.sites_applied, expected_applied, "{label}");
        if expect_packet_skip {
            assert!(result.sites_skipped.iter().any(|s| {
                s.reason.contains("packet pointer") || s.reason.contains("non-stack base")
            }));
        }
    }
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

// ── BTF struct pointer field boundary tests ─────────────────────────

/// Build a minimal verifier state with the given reg_type for a register at a
/// specific PC.  Used to simulate the verifier log output for a BTF pointer.
fn make_verifier_state_with_reg_type(
    pc: usize,
    reg: u8,
    reg_type: &str,
) -> crate::pass::VerifierInsn {
    let mut regs = std::collections::HashMap::new();
    regs.insert(
        reg,
        crate::pass::RegState::new(reg_type, crate::pass::VerifierValueWidth::Unknown),
    );
    crate::pass::VerifierInsn {
        pc,
        frame: 0,
        from_pc: None,
        kind: crate::pass::VerifierInsnKind::PcFullState,
        speculative: false,
        regs,
        stack: std::collections::HashMap::new(),
    }
}

#[test]
fn test_wide_mem_verifier_state_pointer_type_gate_matrix() {
    for (label, reg_type, expected_applied, expect_btf_skip) in [
        ("no verifier states", None, 1, false),
        ("scalar base", Some("scalar"), 1, false),
        ("btf struct ptr", Some("trusted_ptr_bpf_prog"), 0, true),
    ] {
        let mut prog = make_program(with_exit(build_wide_mem_2(0, 1, 6, 0)));
        if let Some(reg_type) = reg_type {
            prog.set_verifier_states(vec![make_verifier_state_with_reg_type(0, 6, reg_type)]);
        }

        let mut cache = AnalysisCache::new();
        let result = WideMemPass
            .run(&mut prog, &mut cache, &PassContext::test_default())
            .unwrap();
        assert_eq!(result.sites_applied, expected_applied, "{label}");
        if expect_btf_skip {
            assert!(
                result
                    .sites_skipped
                    .iter()
                    .any(|s| s.reason.contains("BTF struct pointer")),
                "skip reason must mention BTF struct pointer; got: {:?}",
                result.sites_skipped
            );
            assert_eq!(prog.insns.len(), 5, "{label}");
            assert_eq!(prog.insns[0].code, BPF_LDX | BPF_B | BPF_MEM, "{label}");
        }
    }
}
