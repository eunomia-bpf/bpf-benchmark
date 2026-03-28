// SPDX-License-Identifier: MIT
//! Concrete pass implementations and pipeline constructors.

use anyhow::Result;

pub mod bounds_check_merge;
mod branch_flip;
mod bulk_memory;
mod cond_select;
mod const_prop;
mod dce;
mod endian;
mod extract;
mod map_inline;
mod rotate;
mod skb_load_bytes;
pub mod utils;
mod wide_mem;

pub use bounds_check_merge::BoundsCheckMergePass;
pub use branch_flip::BranchFlipPass;
pub use bulk_memory::BulkMemoryPass;
pub use cond_select::CondSelectPass;
pub use const_prop::ConstPropPass;
pub use dce::DcePass;
pub use endian::EndianFusionPass;
pub use extract::ExtractPass;
pub use map_inline::MapInlinePass;
pub use rotate::RotatePass;
pub use skb_load_bytes::SkbLoadBytesSpecPass;
pub use wide_mem::WideMemPass;

use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis, MapInfoAnalysis};
use crate::pass::{BpfPass, PassManager};

// ── Pass registry ───────────────────────────────────────────────────

/// Entry in the pass registry. Defines the canonical name, description,
/// and constructor for each pass.
pub struct PassRegistryEntry {
    /// Canonical pass name (matches `BpfPass::name()`).
    pub name: &'static str,
    /// Short description for help text.
    pub description: &'static str,
    /// Constructor: returns a boxed pass instance.
    pub make: fn() -> Box<dyn BpfPass>,
}

/// Canonical pass ordering and metadata. Both `build_full_pipeline()` and
/// `build_custom_pipeline()` iterate this array in order, guaranteeing
/// consistent pass sequencing regardless of which passes are selected.
pub const PASS_REGISTRY: &[PassRegistryEntry] = &[
    PassRegistryEntry {
        name: "map_inline",
        description: "Inline stable map lookups and frozen pseudo-map-value loads",
        make: || Box::new(MapInlinePass),
    },
    PassRegistryEntry {
        name: "const_prop",
        description: "Fold register constants into MOV/LD_IMM64/JA rewrites",
        make: || Box::new(ConstPropPass),
    },
    PassRegistryEntry {
        name: "dce",
        description: "Remove CFG-unreachable blocks and NOPs after simplification",
        make: || Box::new(DcePass),
    },
    PassRegistryEntry {
        name: "skb_load_bytes_spec",
        description: "Specialize eligible skb_load_bytes helper sites into direct packet access",
        make: || Box::new(SkbLoadBytesSpecPass),
    },
    PassRegistryEntry {
        name: "bounds_check_merge",
        description: "Merge direct packet bounds-check ladders into a dominant guard",
        make: || Box::new(BoundsCheckMergePass),
    },
    PassRegistryEntry {
        name: "wide_mem",
        description: "Fuse byte-by-byte loads into wider memory accesses",
        make: || Box::new(WideMemPass),
    },
    PassRegistryEntry {
        name: "bulk_memory",
        description: "Lower large scalarized memcpy/memset runs into bulk-memory kinsn calls",
        make: || Box::new(BulkMemoryPass),
    },
    PassRegistryEntry {
        name: "rotate",
        description: "Replace shift+or patterns with rotate kfunc (ROL/ROR)",
        make: || Box::new(RotatePass),
    },
    PassRegistryEntry {
        name: "cond_select",
        description: "Replace branch-over-mov with conditional select kfunc (CMOV/CSEL)",
        make: || Box::new(CondSelectPass),
    },
    PassRegistryEntry {
        name: "extract",
        description: "Replace shift+mask with bit field extract kfunc (BEXTR)",
        make: || Box::new(ExtractPass),
    },
    PassRegistryEntry {
        name: "endian_fusion",
        description: "Fuse endian swap patterns into endian load kfunc (MOVBE)",
        make: || Box::new(EndianFusionPass),
    },
    PassRegistryEntry {
        name: "branch_flip",
        description: "Flip branch polarity using PGO data to improve branch prediction",
        make: || {
            Box::new(BranchFlipPass {
                min_bias: 0.7,
                max_branch_miss_rate: 0.05,
            })
        },
    },
];

/// Generate the pass-list help string dynamically from the registry.
pub fn available_passes_help() -> String {
    PASS_REGISTRY
        .iter()
        .map(|e| format!("  {:<24} {}", e.name, e.description))
        .collect::<Vec<_>>()
        .join("\n")
}

// ── Pipeline constructors ───────────────────────────────────────────

fn resolve_requested_passes(names: &[String]) -> Result<Vec<&'static PassRegistryEntry>> {
    let requested: std::collections::HashSet<&str> = names.iter().map(|s| s.as_str()).collect();
    let mut unknown = Vec::new();

    for name in &requested {
        let known = PASS_REGISTRY.iter().any(|entry| entry.name == *name);
        if !known {
            unknown.push((*name).to_string());
        }
    }

    if !unknown.is_empty() {
        unknown.sort();
        anyhow::bail!("unknown pass name(s): {}", unknown.join(", "));
    }

    Ok(PASS_REGISTRY
        .iter()
        .filter(|entry| requested.contains(entry.name))
        .collect())
}

pub fn validate_pass_names(names: &[String]) -> Result<()> {
    resolve_requested_passes(names).map(|_| ())
}

pub fn selected_pass_names(names: Option<&[String]>) -> Result<Vec<String>> {
    match names {
        Some(names) => Ok(resolve_requested_passes(names)?
            .into_iter()
            .map(|entry| entry.name.to_string())
            .collect()),
        None => Ok(PASS_REGISTRY
            .iter()
            .map(|entry| entry.name.to_string())
            .collect()),
    }
}

/// Register standard analyses into a PassManager.
fn register_standard_analyses(pm: &mut PassManager) {
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.register_analysis(MapInfoAnalysis);
}

/// Build the default optimization pipeline from `PASS_REGISTRY` in canonical order.
pub fn build_full_pipeline() -> PassManager {
    let mut pm = PassManager::new();
    register_standard_analyses(&mut pm);

    for entry in PASS_REGISTRY {
        pm.add_pass_boxed((entry.make)());
    }

    pm
}

pub fn build_pipeline_for_profile(profile: crate::pass::PipelineProfile) -> PassManager {
    match profile {
        crate::pass::PipelineProfile::Default => build_full_pipeline(),
        crate::pass::PipelineProfile::MapInlineOnly => {
            build_custom_pipeline(&["map_inline".to_string()])
                .expect("map_inline-only pipeline should always be valid")
        }
    }
}

/// Build a pipeline containing only the named passes, in canonical order.
///
/// Pass names are matched against `PASS_REGISTRY` entries by canonical name
/// and legacy aliases. Unknown names are rejected.
pub fn build_custom_pipeline(names: &[String]) -> Result<PassManager> {
    let mut pm = PassManager::new();
    register_standard_analyses(&mut pm);

    for entry in resolve_requested_passes(names)? {
        pm.add_pass_boxed((entry.make)());
    }

    Ok(pm)
}

// ── Cross-pass integration tests ────────────────────────────────────

#[cfg(test)]
mod tests {
    #![allow(dead_code)]

    use super::*;
    use std::collections::HashMap;

    use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};
    use crate::insn::*;
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

        assert!(result.branch_targets[3]);
        assert!(result.subprogs.len() >= 2);
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
        assert!(result.live_in[1].contains(&1));
        assert!(result.live_in[4].contains(&0));
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
        let pm = build_pipeline_for_profile(crate::pass::PipelineProfile::MapInlineOnly);

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
    fn test_selected_pass_names_reject_aliases() {
        let err = selected_pass_names(Some(&["skb_load_bytes".to_string()]))
            .expect_err("legacy alias should be rejected");

        assert!(err.to_string().contains("unknown pass name(s): skb_load_bytes"));
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

        let result = run_pipeline_with_passes(&mut program, &["map_inline"]);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.pass_results[0].pass_name, "map_inline");
        assert_eq!(result.pass_results[0].sites_applied, 1);
        assert_eq!(program.insns, vec![BpfInsn::mov64_imm(0, 42), exit_insn()]);
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

        let result = run_pipeline_with_passes(&mut program, &["map_inline", "const_prop"]);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].pass_name, "map_inline");
        assert_eq!(result.pass_results[1].pass_name, "const_prop");
        assert_eq!(result.pass_results[1].sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(0, 42),
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

        let result = run_pipeline_with_passes(&mut program, &["map_inline", "const_prop", "dce"]);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[1].pass_name, "const_prop");
        assert_eq!(result.pass_results[1].sites_applied, 1);
        assert_eq!(result.pass_results[2].pass_name, "dce");
        assert!(result.pass_results[2].changed);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 42),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]
        );
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
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 42),
                BpfInsn::mov64_imm(1, 10),
                BpfInsn::mov64_imm(1, 52),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn cascade_hash_map_keeps_null_path_but_folds_non_null_path() {
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

        let result = run_pipeline_with_passes(&mut program, &["map_inline", "const_prop", "dce"]);

        assert!(result.program_changed);
        assert_eq!(result.pass_results[0].pass_name, "map_inline");
        assert_eq!(result.pass_results[1].pass_name, "const_prop");
        assert_eq!(result.pass_results[1].sites_applied, 1);
        assert_eq!(result.pass_results[2].pass_name, "dce");
        assert!(!result.pass_results[2].changed);
        assert_eq!(
            program.insns,
            vec![
                map[0],
                map[1],
                st_mem(BPF_W, 10, -4, 1),
                BpfInsn::mov64_reg(2, 10),
                BpfInsn::alu64_imm(BPF_ADD, 2, -4),
                call_helper(HELPER_MAP_LOOKUP_ELEM),
                jeq_imm(0, 0, 5),
                BpfInsn::mov64_imm(6, 42),
                BpfInsn::mov64_imm(1, 10),
                BpfInsn::mov64_imm(1, 52),
                BpfInsn::mov64_imm(0, 1),
                exit_insn(),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
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
}

#[cfg(test)]
mod real_bpfo_tests {
    use crate::pass::{BpfProgram, PipelineResult};
    use crate::test_utils::{
        assert_valid_bpf, hot_branch_profiling, load_fixture_program, load_program_from_path,
        pass_result, permissive_pass_ctx, repo_path, run_named_pipeline,
        run_named_pipeline_with_profiling, LoadedFixtureProgram,
    };

    #[derive(Clone, Copy)]
    struct CapturedRealCase {
        object_path: &'static str,
        program_name: &'static str,
        capture_path: &'static str,
    }

    fn run_real_case(
        pass_names: &[&str],
        fixture: &str,
        program_name: &str,
        with_maps: bool,
        with_profiling: bool,
    ) -> (LoadedFixtureProgram, BpfProgram, PipelineResult) {
        let loaded = load_fixture_program(fixture, program_name).unwrap();
        let mut program = if with_maps {
            loaded.into_program_with_synthetic_maps()
        } else {
            loaded.into_program()
        };
        let ctx = permissive_pass_ctx(loaded.prog_type);
        let result = if with_profiling {
            let profiling = hot_branch_profiling(&program.insns);
            run_named_pipeline_with_profiling(&mut program, &ctx, pass_names, Some(&profiling))
                .unwrap()
        } else {
            run_named_pipeline(&mut program, &ctx, pass_names).unwrap()
        };
        assert_valid_bpf(&program);
        (loaded, program, result)
    }

    fn run_captured_real_case(
        pass_names: &[&str],
        case: CapturedRealCase,
    ) -> (LoadedFixtureProgram, BpfProgram, PipelineResult) {
        try_run_captured_real_case(pass_names, case).unwrap()
    }

    fn try_run_captured_real_case(
        pass_names: &[&str],
        case: CapturedRealCase,
    ) -> anyhow::Result<(LoadedFixtureProgram, BpfProgram, PipelineResult)> {
        let object_path = repo_path(case.object_path);
        let capture_path = repo_path(case.capture_path);
        let loaded = load_program_from_path(&object_path, case.program_name)?;
        let mut program = loaded.into_program_with_captured_maps(&capture_path)?;
        let ctx = permissive_pass_ctx(loaded.prog_type);
        let result = run_named_pipeline(&mut program, &ctx, pass_names)?;
        assert_valid_bpf(&program);
        Ok((loaded, program, result))
    }

    fn assert_pass_changed(
        result: &PipelineResult,
        pass_name: &str,
        fixture: &LoadedFixtureProgram,
    ) {
        let pass = pass_result(result, pass_name).unwrap();
        assert!(
            pass.changed,
            "{} on {}:{} did not change; skipped={:?}",
            pass_name,
            fixture.object_path.display(),
            fixture.section_name,
            pass.sites_skipped
        );
        assert!(
            pass.insns_after != pass.insns_before || pass.sites_applied > 0,
            "{} on {}:{} reported changed without any visible delta",
            pass_name,
            fixture.object_path.display(),
            fixture.section_name
        );
    }

    fn all_captured_real_cases() -> &'static [CapturedRealCase] {
        &[
            CapturedRealCase {
                object_path: "corpus/build/tetragon/bpf_execve_bprm_commit_creds.bpf.o",
                program_name: "tg_kp_bprm_committing_creds",
                capture_path:
                    "corpus/fixtures/tetragon/bpf_execve_bprm_commit_creds.bpf.o/tg_kp_bprm_committing_creds.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tetragon/bpf_execve_event.bpf.o",
                program_name: "event_execve",
                capture_path:
                    "corpus/fixtures/tetragon/bpf_execve_event.bpf.o/event_execve.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tetragon/bpf_execve_event.bpf.o",
                program_name: "execve_rate",
                capture_path:
                    "corpus/fixtures/tetragon/bpf_execve_event.bpf.o/execve_rate.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tetragon/bpf_execve_event.bpf.o",
                program_name: "execve_send",
                capture_path:
                    "corpus/fixtures/tetragon/bpf_execve_event.bpf.o/execve_send.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tetragon/bpf_execve_map_update.bpf.o",
                program_name: "execve_map_update",
                capture_path:
                    "corpus/fixtures/tetragon/bpf_execve_map_update.bpf.o/execve_map_update.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tetragon/bpf_exit.bpf.o",
                program_name: "event_exit_acct_process",
                capture_path:
                    "corpus/fixtures/tetragon/bpf_exit.bpf.o/event_exit_acct_process.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tetragon/bpf_fork.bpf.o",
                program_name: "event_wake_up_new_task",
                capture_path:
                    "corpus/fixtures/tetragon/bpf_fork.bpf.o/event_wake_up_new_task.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "lkm_seeker_modtree_loop",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/lkm_seeker_modtree_loop.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "sys_dup_exit_tail",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/sys_dup_exit_tail.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "sys_enter_init",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/sys_enter_init.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "sys_enter_submit",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/sys_enter_submit.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "sys_exit_init",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/sys_exit_init.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "sys_exit_submit",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/sys_exit_submit.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "syscall__execve_enter",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/syscall__execve_enter.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "syscall__execve_exit",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/syscall__execve_exit.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "syscall__execveat_enter",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/syscall__execveat_enter.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "syscall__execveat_exit",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/syscall__execveat_exit.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "tracepoint__raw_syscalls__sys_enter",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/tracepoint__raw_syscalls__sys_enter.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "tracepoint__raw_syscalls__sys_exit",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/tracepoint__raw_syscalls__sys_exit.json",
            },
            CapturedRealCase {
                object_path: "corpus/build/tracee/tracee.bpf.o",
                program_name: "tracepoint__sched__sched_process_fork",
                capture_path:
                    "corpus/fixtures/tracee/tracee.bpf.o/tracepoint__sched__sched_process_fork.json",
            },
        ]
    }

    macro_rules! real_single_pass_test {
        ($name:ident, $pass:literal, $fixture:literal, $program:literal, $with_maps:expr, $with_profile:expr, $expect_change:expr) => {
            #[test]
            fn $name() {
                let (fixture, _program, result) =
                    run_real_case(&[$pass], $fixture, $program, $with_maps, $with_profile);
                if $expect_change {
                    assert_pass_changed(&result, $pass, &fixture);
                } else {
                    let _ = pass_result(&result, $pass).unwrap();
                }
            }
        };
    }

    macro_rules! real_pipeline_test {
        ($name:ident, [$($pass:literal),+ $(,)?], assert_pass=$assert_pass:literal, fixture=$fixture:literal, program=$program:literal, maps=$with_maps:expr, profile=$with_profile:expr, change=$expect_change:expr) => {
            #[test]
            fn $name() {
                let (fixture, _program, result) = run_real_case(
                    &[$($pass),+],
                    $fixture,
                    $program,
                    $with_maps,
                    $with_profile,
                );
                if $expect_change {
                    assert_pass_changed(&result, $assert_pass, &fixture);
                } else {
                    let _ = pass_result(&result, $assert_pass).unwrap();
                }
            }
        };
    }

    real_single_pass_test!(
        test_map_inline_real_katran_xdp,
        "map_inline",
        "katran/xdp_pktcntr.bpf.o",
        "xdp",
        true,
        false,
        true
    );

    #[test]
    fn test_map_inline_real_katran_balancer_ingress() {
        let object_path = repo_path("corpus/build/katran/balancer.bpf.o");
        let loaded = load_program_from_path(&object_path, "balancer_ingress").unwrap();
        let mut program = loaded.into_program_with_synthetic_maps();
        let ctx = permissive_pass_ctx(loaded.prog_type);
        let result = run_named_pipeline(&mut program, &ctx, &["map_inline"]).unwrap();
        assert_valid_bpf(&program);
        let pass = pass_result(&result, "map_inline").unwrap();
        assert!(
            pass.changed && pass.sites_applied > 0,
            "expected map_inline to apply on {}:{}; applied={} skipped={:?} diagnostics={:?}",
            loaded.object_path.display(),
            loaded.section_name,
            pass.sites_applied,
            pass.sites_skipped,
            pass.diagnostics
        );
        assert!(
            !pass.map_inline_records.is_empty(),
            "expected balancer_ingress to record inlined map entries on {}:{}",
            loaded.object_path.display(),
            loaded.section_name
        );
    }

    #[test]
    fn test_map_inline_real_tracee_cgroup_skb_ingress() {
        let (fixture, _program, result) = run_real_case(
            &["map_inline"],
            "tracee/tracee.bpf.o",
            "cgroup_skb_ingress",
            true,
            false,
        );
        assert_pass_changed(&result, "map_inline", &fixture);
        let pass = pass_result(&result, "map_inline").unwrap();
        assert!(
            !pass.sites_skipped.iter().any(|skip| skip
                .reason
                .contains("speculative map inline requires an immediate null check")),
            "unexpected null-check skips on {}:{}: {:?}",
            fixture.object_path.display(),
            fixture.section_name,
            pass.sites_skipped
        );
    }

    #[test]
    fn test_map_inline_real_tracee_cgroup_skb_egress() {
        let (fixture, _program, result) = run_real_case(
            &["map_inline"],
            "tracee/tracee.bpf.o",
            "cgroup_skb_egress",
            true,
            false,
        );
        assert_pass_changed(&result, "map_inline", &fixture);
        let pass = pass_result(&result, "map_inline").unwrap();
        assert!(
            !pass.sites_skipped.iter().any(|skip| skip
                .reason
                .contains("speculative map inline requires an immediate null check")),
            "unexpected null-check skips on {}:{}: {:?}",
            fixture.object_path.display(),
            fixture.section_name,
            pass.sites_skipped
        );
    }

    #[test]
    fn test_map_inline_real_tetragon_event_exit_acct_partially_applies_but_still_rejects_dynamic_sites(
    ) {
        let object_path = repo_path("corpus/build/tetragon/bpf_exit.bpf.o");
        let capture_path =
            repo_path("corpus/fixtures/tetragon/bpf_exit.bpf.o/event_exit_acct_process.json");
        let loaded = load_program_from_path(&object_path, "event_exit_acct_process").unwrap();
        let mut program = loaded
            .into_program_with_captured_maps(&capture_path)
            .unwrap();
        let ctx = permissive_pass_ctx(loaded.prog_type);
        let result = run_named_pipeline(&mut program, &ctx, &["map_inline"]).unwrap();
        assert_valid_bpf(&program);
        let pass = pass_result(&result, "map_inline").unwrap();
        assert!(
            pass.changed && pass.sites_applied >= 1,
            "map_inline should partially apply on {}:{}; skipped={:?}",
            loaded.object_path.display(),
            loaded.section_name,
            pass.sites_skipped
        );
        assert!(
            pass.sites_skipped
                .iter()
                .any(|skip| {
                    skip.reason
                        == "lookup key is not a constant stack or pseudo-map-value materialization"
                }),
            "expected dynamic-key skip on {}:{}; skipped={:?}",
            loaded.object_path.display(),
            loaded.section_name,
            pass.sites_skipped
        );
    }

    #[test]
    fn test_map_inline_real_tetragon_execve_rate() {
        let object_path = repo_path("corpus/build/tetragon/bpf_execve_event.bpf.o");
        let capture_path =
            repo_path("corpus/fixtures/tetragon/bpf_execve_event.bpf.o/execve_rate.json");
        let loaded = load_program_from_path(&object_path, "execve_rate").unwrap();
        let mut program = loaded
            .into_program_with_captured_maps(&capture_path)
            .unwrap();
        let ctx = permissive_pass_ctx(loaded.prog_type);
        let result = run_named_pipeline(&mut program, &ctx, &["map_inline"]).unwrap();
        assert_valid_bpf(&program);
        assert_pass_changed(&result, "map_inline", &loaded);
        let pass = pass_result(&result, "map_inline").unwrap();
        assert!(
            pass.sites_applied > 0,
            "expected map_inline to apply on {}:{}; skipped={:?}",
            loaded.object_path.display(),
            loaded.section_name,
            pass.sites_skipped
        );
    }

    #[test]
    fn test_map_inline_real_tetragon_event_execve() {
        let case = CapturedRealCase {
            object_path: "corpus/build/tetragon/bpf_execve_event.bpf.o",
            program_name: "event_execve",
            capture_path: "corpus/fixtures/tetragon/bpf_execve_event.bpf.o/event_execve.json",
        };
        let (loaded, _program, result) = run_captured_real_case(&["map_inline"], case);
        assert_pass_changed(&result, "map_inline", &loaded);
        let pass = pass_result(&result, "map_inline").unwrap();
        assert!(
            pass.sites_applied > 0,
            "expected map_inline to apply on {}:{}; skipped={:?}",
            loaded.object_path.display(),
            loaded.section_name,
            pass.sites_skipped
        );
    }

    #[test]
    fn test_map_inline_real_tetragon_event_wake_up_new_task() {
        let case = CapturedRealCase {
            object_path: "corpus/build/tetragon/bpf_fork.bpf.o",
            program_name: "event_wake_up_new_task",
            capture_path: "corpus/fixtures/tetragon/bpf_fork.bpf.o/event_wake_up_new_task.json",
        };
        let (loaded, _program, result) = run_captured_real_case(&["map_inline"], case);
        assert_pass_changed(&result, "map_inline", &loaded);
        let pass = pass_result(&result, "map_inline").unwrap();
        assert!(
            pass.sites_applied > 0,
            "expected map_inline to apply on {}:{}; skipped={:?}",
            loaded.object_path.display(),
            loaded.section_name,
            pass.sites_skipped
        );
    }

    #[test]
    fn test_map_inline_real_all_captured_fixtures_smoke() {
        let mut changed_cases = 0usize;
        let mut attempted_cases = 0usize;

        for case in all_captured_real_cases() {
            let (loaded, _program, result) =
                match try_run_captured_real_case(&["map_inline"], *case) {
                    Ok(result) => result,
                    Err(err) => {
                        eprintln!(
                            "captured fixture {}:{} skipped during smoke scan: {:#}",
                            case.object_path, case.program_name, err
                        );
                        continue;
                    }
                };
            attempted_cases += 1;
            let pass = pass_result(&result, "map_inline").unwrap();
            eprintln!(
                "captured fixture {}:{} changed={} applied={} skipped={}",
                loaded.object_path.display(),
                loaded.section_name,
                pass.changed,
                pass.sites_applied,
                pass.sites_skipped.len()
            );
            if pass.changed {
                changed_cases += 1;
            }
        }

        assert!(
            changed_cases >= 2,
            "expected at least two captured real fixtures to hit map_inline, got {}",
            changed_cases
        );
        assert!(
            attempted_cases >= 10,
            "expected to scan at least ten captured real fixtures, got {}",
            attempted_cases
        );
    }

    real_single_pass_test!(
        test_map_inline_real_bindsnoop,
        "map_inline",
        "bcc/libbpf-tools/bindsnoop.bpf.o",
        "kprobe/inet_bind",
        true,
        false,
        false
    );
    real_single_pass_test!(
        test_map_inline_real_cilium_xdp_entry,
        "map_inline",
        "cilium/bpf_xdp.bpf.o",
        "xdp/entry",
        true,
        false,
        false
    );

    real_pipeline_test!(
        test_const_prop_real_katran_xdp,
        ["map_inline", "const_prop"],
        assert_pass = "const_prop",
        fixture = "katran/xdp_pktcntr.bpf.o",
        program = "xdp",
        maps = true,
        profile = false,
        change = true
    );
    real_pipeline_test!(
        test_const_prop_real_bindsnoop,
        ["map_inline", "const_prop"],
        assert_pass = "const_prop",
        fixture = "bcc/libbpf-tools/bindsnoop.bpf.o",
        program = "kprobe/inet_bind",
        maps = true,
        profile = false,
        change = false
    );
    real_pipeline_test!(
        test_const_prop_real_cilium_xdp_entry,
        ["map_inline", "const_prop"],
        assert_pass = "const_prop",
        fixture = "cilium/bpf_xdp.bpf.o",
        program = "xdp/entry",
        maps = true,
        profile = false,
        change = false
    );

    real_pipeline_test!(
        test_dce_real_katran_xdp,
        ["map_inline", "const_prop", "dce"],
        assert_pass = "dce",
        fixture = "katran/xdp_pktcntr.bpf.o",
        program = "xdp",
        maps = true,
        profile = false,
        change = true
    );
    real_pipeline_test!(
        test_dce_real_bindsnoop,
        ["map_inline", "const_prop", "dce"],
        assert_pass = "dce",
        fixture = "bcc/libbpf-tools/bindsnoop.bpf.o",
        program = "kprobe/inet_bind",
        maps = true,
        profile = false,
        change = false
    );
    real_pipeline_test!(
        test_dce_real_cilium_xdp_entry,
        ["map_inline", "const_prop", "dce"],
        assert_pass = "dce",
        fixture = "cilium/bpf_xdp.bpf.o",
        program = "xdp/entry",
        maps = true,
        profile = false,
        change = false
    );

    real_single_pass_test!(
        test_skb_load_bytes_real_cilium_lxc_tail,
        "skb_load_bytes_spec",
        "cilium/bpf_lxc.bpf.o",
        "tc/tail",
        false,
        false,
        true
    );
    real_single_pass_test!(
        test_skb_load_bytes_real_cilium_overlay_tail,
        "skb_load_bytes_spec",
        "cilium/bpf_overlay.bpf.o",
        "tc/tail",
        false,
        false,
        true
    );
    real_single_pass_test!(
        test_skb_load_bytes_real_decap_sanity,
        "skb_load_bytes_spec",
        "linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o",
        "tc",
        false,
        false,
        true
    );

    real_single_pass_test!(
        test_bounds_check_merge_real_cilium_xdp_entry,
        "bounds_check_merge",
        "cilium/bpf_xdp.bpf.o",
        "xdp/entry",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_bounds_check_merge_real_xdp_flowtable,
        "bounds_check_merge",
        "xdp-tools/xdp_flowtable.bpf.o",
        "xdp",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_bounds_check_merge_real_calico_from_hep,
        "bounds_check_merge",
        "calico/from_hep_debug.bpf.o",
        "tc",
        false,
        false,
        false
    );

    real_single_pass_test!(
        test_wide_mem_real_cilium_xdp_entry,
        "wide_mem",
        "cilium/bpf_xdp.bpf.o",
        "xdp/entry",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_wide_mem_real_cilium_lxc_entry,
        "wide_mem",
        "cilium/bpf_lxc.bpf.o",
        "tc/entry",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_wide_mem_real_calico_to_hep,
        "wide_mem",
        "calico/to_hep_debug.bpf.o",
        "tc",
        false,
        false,
        false
    );

    real_single_pass_test!(
        test_bulk_memory_real_calico_to_hep,
        "bulk_memory",
        "calico/to_hep_debug.bpf.o",
        "tc",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_bulk_memory_real_calico_from_hep,
        "bulk_memory",
        "calico/from_hep_debug.bpf.o",
        "tc",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_bulk_memory_real_xdp_flowtable,
        "bulk_memory",
        "xdp-tools/xdp_flowtable.bpf.o",
        "xdp",
        false,
        false,
        false
    );

    real_single_pass_test!(
        test_rotate_real_cilium_xdp_entry,
        "rotate",
        "cilium/bpf_xdp.bpf.o",
        "xdp/entry",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_rotate_real_cilium_lxc_entry,
        "rotate",
        "cilium/bpf_lxc.bpf.o",
        "tc/entry",
        false,
        false,
        false
    );

    real_single_pass_test!(
        test_cond_select_real_cilium_xdp_tail,
        "cond_select",
        "cilium/bpf_xdp.bpf.o",
        "xdp/tail",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_cond_select_real_cilium_lxc_tail,
        "cond_select",
        "cilium/bpf_lxc.bpf.o",
        "tc/tail",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_cond_select_real_calico_to_hep,
        "cond_select",
        "calico/to_hep_debug.bpf.o",
        "tc",
        false,
        false,
        false
    );

    real_single_pass_test!(
        test_extract_real_cilium_xdp_entry,
        "extract",
        "cilium/bpf_xdp.bpf.o",
        "xdp/entry",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_extract_real_calico_to_hep,
        "extract",
        "calico/to_hep_debug.bpf.o",
        "tc",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_extract_real_tracee_sys_enter,
        "extract",
        "tracee/tracee.bpf.o",
        "tracepoint__raw_syscalls__sys_enter",
        false,
        false,
        false
    );

    real_single_pass_test!(
        test_endian_real_selftest,
        "endian_fusion",
        "linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o",
        "raw_tp/sys_enter",
        false,
        false,
        true
    );
    real_single_pass_test!(
        test_endian_real_calico_to_hep,
        "endian_fusion",
        "calico/to_hep_debug.bpf.o",
        "tc",
        false,
        false,
        false
    );
    real_single_pass_test!(
        test_endian_real_cilium_lxc_entry,
        "endian_fusion",
        "cilium/bpf_lxc.bpf.o",
        "tc/entry",
        false,
        false,
        false
    );

    real_single_pass_test!(
        test_branch_flip_real_cilium_xdp_entry,
        "branch_flip",
        "cilium/bpf_xdp.bpf.o",
        "xdp/entry",
        false,
        true,
        true
    );
    real_single_pass_test!(
        test_branch_flip_real_cilium_lxc_entry,
        "branch_flip",
        "cilium/bpf_lxc.bpf.o",
        "tc/entry",
        false,
        true,
        true
    );
    real_single_pass_test!(
        test_branch_flip_real_tracee_sys_enter,
        "branch_flip",
        "tracee/tracee.bpf.o",
        "tracepoint__raw_syscalls__sys_enter",
        false,
        true,
        false
    );

}
