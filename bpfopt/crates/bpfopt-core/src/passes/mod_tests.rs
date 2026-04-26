#![allow(dead_code)]

use super::*;
use std::collections::HashMap;

use crate::insn::*;
use crate::mock_maps::{apply_mock_maps, install_mock_map, BpfMapInfo, MockMapState};
use crate::pass::{BpfProgram, PassContext, PipelineResult};

const BPF_ADD: u8 = 0x00;
const BPF_MAP_TYPE_HASH: u32 = 1;
const BPF_MAP_TYPE_ARRAY: u32 = 2;
const BPF_PSEUDO_MAP_FD: u8 = 1;
const HELPER_MAP_LOOKUP_ELEM: i32 = 1;

fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}

fn ld_imm64(dst: u8, src: u8, imm_lo: i32) -> [BpfInsn; 2] {
    [
        BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(dst, src),
            off: 0,
            imm: imm_lo,
        },
        BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: 0,
        },
    ]
}

fn exit_insn() -> BpfInsn {
    BpfInsn {
        code: BPF_JMP | BPF_EXIT,
        regs: 0,
        off: 0,
        imm: 0,
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

fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
    BpfInsn {
        code: BPF_ST | size | BPF_MEM,
        regs: BpfInsn::make_regs(dst, 0),
        off,
        imm,
    }
}

fn call_helper(imm: i32) -> BpfInsn {
    BpfInsn {
        code: BPF_JMP | BPF_CALL,
        regs: BpfInsn::make_regs(0, 0),
        off: 0,
        imm,
    }
}

fn install_map(map_id: u32, map_type: u32, value: Vec<u8>) {
    let mut values = HashMap::new();
    values.insert(1u32.to_le_bytes().to_vec(), value.clone());

    let mut info = BpfMapInfo::default();
    info.map_type = map_type;
    info.id = map_id;
    info.key_size = 4;
    info.value_size = value.len() as u32;
    info.max_entries = 8;

    install_mock_map(
        map_id,
        MockMapState {
            info,
            frozen: true,
            values,
        },
    );
}

fn install_array_map(map_id: u32, value: Vec<u8>) {
    install_map(map_id, BPF_MAP_TYPE_ARRAY, value);
}

fn install_hash_map(map_id: u32, value: Vec<u8>) {
    install_map(map_id, BPF_MAP_TYPE_HASH, value);
}

fn run_pipeline_with_passes(program: &mut BpfProgram, pass_names: &[&str]) -> PipelineResult {
    let pass_names = pass_names
        .iter()
        .map(|name| (*name).to_string())
        .collect::<Vec<_>>();
    let pm = build_custom_pipeline(&pass_names).unwrap();
    let mut ctx = PassContext::test_default();
    ctx.policy.enabled_passes = pass_names;
    pm.run(program, &ctx).unwrap()
}

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

#[test]
fn test_cfg_analysis_with_subprogs() {
    use crate::analysis::CFGAnalysis;
    use crate::pass::Analysis;

    let prog = make_program(vec![
        BpfInsn {
            code: BPF_JMP | BPF_CALL,
            regs: BpfInsn::make_regs(0, 1),
            off: 0,
            imm: 2,
        },
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
    ]);

    let cfg = CFGAnalysis;
    let result = cfg.run(&prog);

    assert!(result.subprogs.len() >= 2);
    assert_eq!(result.subprogs[1].start, 3);
}

#[test]
fn test_cfg_analysis_with_callback_subprog_refs() {
    use crate::analysis::CFGAnalysis;
    use crate::pass::Analysis;

    let callback = ld_imm64(2, BPF_PSEUDO_FUNC, 4);
    let prog = make_program(vec![
        callback[0],
        callback[1],
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
        BpfInsn::mov64_reg(0, 1),
        exit_insn(),
    ]);

    let cfg = CFGAnalysis;
    let result = cfg.run(&prog);

    assert!(result.subprogs.len() >= 2);
    assert_eq!(result.subprogs[1].start, 5);
}

#[test]
fn test_liveness_across_branch() {
    use crate::analysis::LivenessAnalysis;
    use crate::pass::Analysis;

    let prog = make_program(vec![
        BpfInsn::mov64_imm(1, 10),
        jeq_imm(1, 0, 1),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::mov64_imm(0, 2),
        exit_insn(),
    ]);

    let liveness = LivenessAnalysis;
    let result = liveness.run(&prog);

    assert!(result.live_out[0].contains(&1));
    assert!(!result.live_out[1].contains(&0));
    assert!(result.live_out[3].contains(&0));
}

#[test]
fn test_branch_targets_backward_jump() {
    use crate::analysis::BranchTargetAnalysis;
    use crate::pass::Analysis;

    let prog = make_program(vec![BpfInsn::mov64_imm(0, 0), BpfInsn::ja(-2)]);

    let bt = BranchTargetAnalysis;
    let result = bt.run(&prog);

    assert!(result.is_target[0]);
    assert!(!result.is_target[1]);
}

#[test]
fn test_default_pipeline_wide_mem() {
    let mut prog = make_program(make_wide_mem_4byte_program());
    let ctx = PassContext::test_default();

    let pm = build_full_pipeline();
    let result = pm.run(&mut prog, &ctx).unwrap();
    assert!(result.program_changed);
    assert!(result.total_sites_applied >= 1);
}

#[test]
fn test_default_pipeline_starts_with_map_inline() {
    let pm = build_full_pipeline();
    assert_eq!(pm.pass_names().first().copied(), Some("map_inline"));
    assert_eq!(pm.pass_names().get(1).copied(), Some("const_prop"));
    assert_eq!(pm.pass_names().get(2).copied(), Some("dce"));
}

#[test]
fn test_default_pipeline_ends_with_branch_flip() {
    let pm = build_full_pipeline();
    assert_eq!(pm.pass_names().last().copied(), Some("branch_flip"));
}

#[test]
fn test_map_inline_only_pipeline_contains_only_map_inline() {
    let pm =
        build_custom_pipeline(&["map_inline".to_string()]).expect("custom pipeline should build");

    assert_eq!(pm.pass_names(), vec!["map_inline"]);
}

#[test]
fn test_build_custom_pipeline_respects_registry_order() {
    let pm = build_custom_pipeline(&[
        "wide_mem".to_string(),
        "const_prop".to_string(),
        "map_inline".to_string(),
    ])
    .expect("custom pipeline should build");

    assert_eq!(
        pm.pass_names(),
        vec!["map_inline", "const_prop", "wide_mem"]
    );
}

#[test]
fn test_build_custom_pipeline_rejects_unknown_pass_name() {
    let err = match build_custom_pipeline(&["wide_mem".to_string(), "nope".to_string()]) {
        Ok(_) => panic!("unknown pass should be rejected"),
        Err(err) => err,
    };

    assert!(err.to_string().contains("unknown pass name(s): nope"));
}

#[test]
fn test_validate_pass_names_reject_aliases() {
    let err = validate_pass_names(&["skb_load_bytes".to_string()])
        .expect_err("legacy alias should be rejected");

    assert!(err
        .to_string()
        .contains("unknown pass name(s): skb_load_bytes"));
}

#[test]
fn cascade_map_inline_emits_non_zero_mov_constant() {
    install_array_map(301, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 0, 0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![301]);
    apply_mock_maps(&mut program);

    let result = run_pipeline_with_passes(&mut program, &["map_inline"]);

    assert!(
        result.program_changed,
        "skip reasons: {:?}",
        result.pass_results[0].sites_skipped
    );
    assert_eq!(result.pass_results[0].pass_name, "map_inline");
    assert_eq!(result.pass_results[0].sites_applied, 1);
    assert_eq!(program.insns, vec![BpfInsn::mov32_imm(0, 42), exit_insn()]);
}

#[test]
fn cascade_const_prop_folds_non_zero_map_inline_output() {
    install_array_map(302, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 0, 0, 0),
        BpfInsn::mov64_imm(1, 10),
        BpfInsn::alu64_reg(BPF_ADD, 1, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![302]);
    apply_mock_maps(&mut program);

    let result = run_pipeline_with_passes(&mut program, &["map_inline", "const_prop"]);

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].pass_name, "map_inline");
    assert_eq!(result.pass_results[1].pass_name, "const_prop");
    assert_eq!(result.pass_results[1].sites_applied, 1);
    assert_eq!(
        program.insns,
        vec![
            BpfInsn::mov32_imm(0, 42),
            BpfInsn::mov64_imm(1, 10),
            BpfInsn::mov64_imm(1, 52),
            exit_insn(),
        ]
    );
}

#[test]
fn cascade_dce_eliminates_dead_branch_after_const_prop() {
    install_array_map(303, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        jeq_imm(6, 0, 2),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::ja(1),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![303]);
    apply_mock_maps(&mut program);

    let result = run_pipeline_with_passes(&mut program, &["map_inline", "const_prop", "dce"]);

    assert!(result.program_changed);
    assert_eq!(result.pass_results[1].pass_name, "const_prop");
    assert_eq!(result.pass_results[1].sites_applied, 1);
    assert_eq!(result.pass_results[2].pass_name, "dce");
    assert!(result.pass_results[2].changed);
    assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
}

#[test]
fn cascade_full_pipeline_shortens_program_and_preserves_folded_semantics() {
    install_array_map(304, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        jeq_imm(6, 0, 4),
        BpfInsn::mov64_imm(1, 10),
        BpfInsn::alu64_reg(BPF_ADD, 1, 6),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![304]);
    apply_mock_maps(&mut program);
    let original_len = program.insns.len();

    let pm = build_full_pipeline();
    let result = pm.run(&mut program, &PassContext::test_default()).unwrap();

    assert!(result.program_changed);
    assert!(program.insns.len() < original_len);
    assert_eq!(
        result
            .pass_results
            .iter()
            .find(|pr| pr.pass_name == "map_inline")
            .map(|pr| pr.sites_applied),
        Some(1)
    );
    assert_eq!(
        result
            .pass_results
            .iter()
            .find(|pr| pr.pass_name == "const_prop")
            .map(|pr| pr.sites_applied),
        Some(2)
    );
    assert!(result
        .pass_results
        .iter()
        .find(|pr| pr.pass_name == "dce")
        .map(|pr| pr.changed)
        .unwrap_or(false));
    assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
}

#[test]
fn cascade_hash_map_removes_lookup_and_null_path_then_folds_non_null_path() {
    install_hash_map(305, 42u32.to_le_bytes().to_vec());

    let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
    let mut program = make_program(vec![
        map[0],
        map[1],
        st_mem(BPF_W, 10, -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::alu64_imm(BPF_ADD, 2, -4),
        call_helper(HELPER_MAP_LOOKUP_ELEM),
        jeq_imm(0, 0, 5),
        BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
        BpfInsn::mov64_imm(1, 10),
        BpfInsn::alu64_reg(BPF_ADD, 1, 6),
        BpfInsn::mov64_imm(0, 1),
        exit_insn(),
        BpfInsn::mov64_imm(0, 0),
        exit_insn(),
    ]);
    program.set_map_ids(vec![305]);
    apply_mock_maps(&mut program);

    let result = run_pipeline_with_passes(&mut program, &["map_inline", "const_prop", "dce"]);

    assert!(result.program_changed);
    assert_eq!(result.pass_results[0].pass_name, "map_inline");
    assert_eq!(result.pass_results[1].pass_name, "const_prop");
    assert_eq!(result.pass_results[1].sites_applied, 1);
    assert_eq!(result.pass_results[2].pass_name, "dce");
    assert!(result.pass_results[2].changed);
    assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 1), exit_insn(),]);
}

// ── HIGH #6: Real BPF bytecode pipeline tests ────────────────────

/// Run the full default pipeline on real compiled BPF bytecode from
/// load_byte_recompose.bpf.o (contains wide_mem patterns).
/// Verifies: pipeline completes without panic, output is structurally valid.
#[test]
fn test_full_pipeline_real_bytecode_load_byte_recompose() {
    let path = crate::insn::micro_program_path("load_byte_recompose.bpf.o");
    let insns = match crate::insn::load_bpf_insns_from_elf(&path) {
        Some(i) if !i.is_empty() => i,
        _ => {
            eprintln!("SKIP: {} not found or empty (run `make micro` first)", path);
            return;
        }
    };
    let orig_len = insns.len();
    let mut prog = make_program(insns);
    let ctx = PassContext::test_default();
    let pm = build_full_pipeline();
    let result = pm.run(&mut prog, &ctx).unwrap();

    // Structural validity checks:
    // 1. The program should still end with EXIT
    assert!(
        prog.insns.last().map_or(false, |i| i.is_exit()),
        "real bytecode pipeline output should end with EXIT"
    );
    // 2. The program should have been modified (wide_mem patterns exist)
    assert!(
        result.program_changed,
        "load_byte_recompose.bpf.o should contain wide_mem patterns (no changes detected)"
    );
    // 3. Instruction count should be reasonable (not wildly different)
    assert!(
        prog.insns.len() > 0 && prog.insns.len() <= orig_len + 20,
        "instruction count changed unreasonably: {} -> {}",
        orig_len,
        prog.insns.len()
    );
    eprintln!(
        "  load_byte_recompose.bpf.o: {} -> {} insns, {} sites",
        orig_len,
        prog.insns.len(),
        result.total_sites_applied
    );
}

/// Run the full pipeline on rotate_dense.bpf.o (contains rotate patterns).
/// Note: clang may emit OR with reversed operands, so the rotate scanner may
/// not match all patterns. This test verifies the pipeline completes without
/// error on real bytecode.
#[test]
fn test_full_pipeline_real_bytecode_rotate_dense() {
    let path = crate::insn::micro_program_path("rotate_dense.bpf.o");
    let insns = match crate::insn::load_bpf_insns_from_elf(&path) {
        Some(i) if !i.is_empty() => i,
        _ => {
            eprintln!("SKIP: {} not found or empty (run `make micro` first)", path);
            return;
        }
    };
    let orig_len = insns.len();
    let mut prog = make_program(insns);
    // Provide a fake rotate kfunc btf_id and enable RORX so the pass can fire
    let mut ctx = PassContext::test_default();
    ctx.kinsn_registry.rotate64_btf_id = 9999;
    ctx.platform.has_rorx = true;
    let pm = build_full_pipeline();
    let result = pm.run(&mut prog, &ctx).unwrap();

    assert!(
        prog.insns.last().map_or(false, |i| i.is_exit()),
        "rotate_dense pipeline output should end with EXIT"
    );

    // After fixing the OR operand order and caller-saved save/restore,
    // the rotate pass should find and apply sites on real bytecode.
    let rotate_result = result
        .pass_results
        .iter()
        .find(|pr| pr.pass_name == "rotate");
    let applied = rotate_result.map_or(0, |r| r.sites_applied);
    let skipped_count = rotate_result.map_or(0, |r| r.sites_skipped.len());
    eprintln!(
        "  rotate_dense.bpf.o: {} -> {} insns, {} sites applied, {} skipped",
        orig_len,
        prog.insns.len(),
        applied,
        skipped_count,
    );
    assert!(
        applied + skipped_count > 0,
        "rotate_dense.bpf.o should have rotate sites (found+skipped=0)"
    );
}

/// Run the full pipeline on bitfield_extract.bpf.o (contains extract patterns).
#[test]
fn test_full_pipeline_real_bytecode_bitfield_extract() {
    let path = crate::insn::micro_program_path("bitfield_extract.bpf.o");
    let insns = match crate::insn::load_bpf_insns_from_elf(&path) {
        Some(i) if !i.is_empty() => i,
        _ => {
            eprintln!("SKIP: {} not found or empty (run `make micro` first)", path);
            return;
        }
    };
    let orig_len = insns.len();
    let mut prog = make_program(insns);
    let mut ctx = PassContext::test_default();
    ctx.kinsn_registry.extract64_btf_id = 9999;
    ctx.platform.has_bmi1 = true;
    ctx.platform.has_bmi2 = true;
    let pm = build_full_pipeline();
    let result = pm.run(&mut prog, &ctx).unwrap();

    assert!(
        prog.insns.last().map_or(false, |i| i.is_exit()),
        "bitfield_extract pipeline output should end with EXIT"
    );
    let extract_result = result
        .pass_results
        .iter()
        .find(|pr| pr.pass_name == "extract");
    // The extract scanner should find sites, but safety checks (e.g., caller-saved
    // register conflict) may prevent some or all from being applied.
    let found_sites = extract_result.map_or(0, |r| r.sites_applied + r.sites_skipped.len());
    assert!(
        found_sites > 0,
        "bitfield_extract.bpf.o should contain extract patterns (found+skipped={})",
        found_sites
    );
    eprintln!(
        "  bitfield_extract.bpf.o: {} -> {} insns, {} sites applied, {} skipped",
        orig_len,
        prog.insns.len(),
        extract_result.map_or(0, |r| r.sites_applied),
        extract_result.map_or(0, |r| r.sites_skipped.len()),
    );
}

/// Run the full pipeline on endian_swap_dense.bpf.o (contains endian patterns).
#[test]
fn test_full_pipeline_real_bytecode_endian_swap_dense() {
    let path = crate::insn::micro_program_path("endian_swap_dense.bpf.o");
    let insns = match crate::insn::load_bpf_insns_from_elf(&path) {
        Some(i) if !i.is_empty() => i,
        _ => {
            eprintln!("SKIP: {} not found or empty (run `make micro` first)", path);
            return;
        }
    };
    let orig_len = insns.len();
    let mut prog = make_program(insns);
    let mut ctx = PassContext::test_default();
    ctx.kinsn_registry.endian_load16_btf_id = 9999;
    ctx.kinsn_registry.endian_load32_btf_id = 9998;
    ctx.kinsn_registry.endian_load64_btf_id = 9997;
    ctx.platform.has_movbe = true;
    let pm = build_full_pipeline();
    let result = pm.run(&mut prog, &ctx).unwrap();

    assert!(
        prog.insns.last().map_or(false, |i| i.is_exit()),
        "endian_swap_dense pipeline output should end with EXIT"
    );
    let endian_result = result
        .pass_results
        .iter()
        .find(|pr| pr.pass_name == "endian_fusion");
    // The endian scanner should find sites; safety checks may skip some.
    let found_sites = endian_result.map_or(0, |r| r.sites_applied + r.sites_skipped.len());
    assert!(
        found_sites > 0,
        "endian_swap_dense.bpf.o should contain endian patterns (found+skipped={})",
        found_sites
    );
    eprintln!(
        "  endian_swap_dense.bpf.o: {} -> {} insns, {} sites applied, {} skipped",
        orig_len,
        prog.insns.len(),
        endian_result.map_or(0, |r| r.sites_applied),
        endian_result.map_or(0, |r| r.sites_skipped.len()),
    );
}

/// Run the full pipeline on cond_select_dense.bpf.o.
/// Note: clang may emit `Jcc +1; MOV` instead of the 4-insn diamond
/// (`Jcc +2; MOV; JA +1; MOV`) that the cond_select scanner matches.
/// This test verifies the pipeline completes without error on real bytecode.
#[test]
fn test_full_pipeline_real_bytecode_cmov_select() {
    let path = crate::insn::micro_program_path("cond_select_dense.bpf.o");
    let insns = match crate::insn::load_bpf_insns_from_elf(&path) {
        Some(i) if !i.is_empty() => i,
        _ => {
            eprintln!("SKIP: {} not found or empty (run `make micro` first)", path);
            return;
        }
    };
    let orig_len = insns.len();
    let mut prog = make_program(insns);
    let mut ctx = PassContext::test_default();
    ctx.kinsn_registry.select64_btf_id = 9999;
    ctx.platform.has_cmov = true;
    let pm = build_full_pipeline();
    let result = pm.run(&mut prog, &ctx).unwrap();

    assert!(
        prog.insns.last().map_or(false, |i| i.is_exit()),
        "cond_select_dense pipeline output should end with EXIT"
    );
    // The program has conditional branches but clang may not emit the exact
    // 4-insn diamond pattern. Verify the pipeline ran without error.
    eprintln!(
        "  cond_select_dense.bpf.o: {} -> {} insns, {} total sites",
        orig_len,
        prog.insns.len(),
        result.total_sites_applied
    );
}
