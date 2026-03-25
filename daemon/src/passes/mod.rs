// SPDX-License-Identifier: MIT
//! Concrete pass implementations and pipeline constructors.

mod branch_flip;
mod cond_select;
mod const_prop;
mod endian;
mod extract;
mod map_inline;
mod rotate;
mod spectre;
pub mod utils;
mod wide_mem;

pub use branch_flip::BranchFlipPass;
pub use cond_select::CondSelectPass;
pub use const_prop::ConstPropPass;
pub use endian::EndianFusionPass;
pub use extract::ExtractPass;
pub use map_inline::MapInlinePass;
pub use rotate::RotatePass;
pub use spectre::SpectreMitigationPass;
pub use wide_mem::WideMemPass;

use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis, MapInfoAnalysis};
use crate::pass::{BpfPass, PassManager};

// ── Legacy alias ───────────────────────────────────────────────────
// Re-export `fixup_all_branches` under the old name for backward compat
// within this crate. New code should use `utils::fixup_all_branches` directly.
#[allow(unused_imports)]
pub(crate) use utils::fixup_all_branches as fixup_branches_inline;

// ── Pass registry ───────────────────────────────────────────────────

/// Entry in the pass registry. Defines the canonical name, description,
/// legacy aliases, and a constructor for each pass.
pub struct PassRegistryEntry {
    /// Canonical pass name (matches `BpfPass::name()`).
    pub name: &'static str,
    /// Short description for help text.
    pub description: &'static str,
    /// Legacy aliases accepted on the CLI (e.g. "spectre_mitigation" for "speculation_barrier").
    pub aliases: &'static [&'static str],
    /// Constructor: returns a boxed pass instance.
    pub make: fn() -> Box<dyn BpfPass>,
}

/// Canonical pass ordering and metadata. Both `build_default_pipeline()` and
/// `build_pipeline_with_passes()` iterate this array in order, guaranteeing
/// consistent pass sequencing regardless of which passes are selected.
///
/// `speculation_barrier` is excluded from the default pipeline but is available
/// when explicitly requested via `--passes`.
pub const PASS_REGISTRY: &[PassRegistryEntry] = &[
    PassRegistryEntry {
        name: "map_inline",
        description: "Inline stable map value loads with constant keys",
        aliases: &[],
        make: || Box::new(MapInlinePass),
    },
    PassRegistryEntry {
        name: "const_prop",
        description: "Fold register constants into MOV/LD_IMM64/JA rewrites",
        aliases: &[],
        make: || Box::new(ConstPropPass),
    },
    PassRegistryEntry {
        name: "wide_mem",
        description: "Fuse byte-by-byte loads into wider memory accesses",
        aliases: &[],
        make: || Box::new(WideMemPass),
    },
    PassRegistryEntry {
        name: "rotate",
        description: "Replace shift+or patterns with rotate kfunc (ROL/ROR)",
        aliases: &[],
        make: || Box::new(RotatePass),
    },
    PassRegistryEntry {
        name: "cond_select",
        description: "Replace branch-over-mov with conditional select kfunc (CMOV/CSEL)",
        aliases: &[],
        make: || Box::new(CondSelectPass),
    },
    PassRegistryEntry {
        name: "extract",
        description: "Replace shift+mask with bit field extract kfunc (BEXTR)",
        aliases: &[],
        make: || Box::new(ExtractPass),
    },
    PassRegistryEntry {
        name: "endian_fusion",
        description: "Fuse endian swap patterns into endian load kfunc (MOVBE)",
        aliases: &[],
        make: || Box::new(EndianFusionPass),
    },
    PassRegistryEntry {
        name: "branch_flip",
        description: "Flip branch polarity using PGO data to improve branch prediction",
        aliases: &[],
        make: || {
            Box::new(BranchFlipPass {
                min_bias: 0.7,
                max_branch_miss_rate: 0.05,
            })
        },
    },
    PassRegistryEntry {
        name: "speculation_barrier",
        description: "Insert speculation barrier kfunc after conditional branches",
        aliases: &["spectre_mitigation", "barrier_placeholder"],
        make: || Box::new(SpectreMitigationPass),
    },
];

/// Returns whether a pass is included in the default pipeline.
/// `speculation_barrier` is opt-in only.
fn is_default_pass(name: &str) -> bool {
    name != "speculation_barrier"
}

/// Generate the `--passes` help string dynamically from the registry.
pub fn available_passes_help() -> String {
    PASS_REGISTRY
        .iter()
        .map(|e| format!("  {:<24} {}", e.name, e.description))
        .collect::<Vec<_>>()
        .join("\n")
}

// ── Pipeline constructors ───────────────────────────────────────────

/// Register standard analyses into a PassManager.
fn register_standard_analyses(pm: &mut PassManager) {
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.register_analysis(MapInfoAnalysis);
}

/// Build the default optimization pipeline.
///
/// Includes all passes from `PASS_REGISTRY` except opt-in passes
/// (currently `speculation_barrier`), in canonical order.
pub fn build_default_pipeline() -> PassManager {
    let mut pm = PassManager::new();
    register_standard_analyses(&mut pm);

    for entry in PASS_REGISTRY {
        if is_default_pass(entry.name) {
            pm.add_pass_boxed((entry.make)());
        }
    }

    pm
}

/// Build a pipeline containing only the named passes, in canonical order.
///
/// Pass names are matched against `PASS_REGISTRY` entries by canonical name
/// and legacy aliases. Unknown names are silently ignored.
pub fn build_pipeline_with_passes(names: &[String]) -> PassManager {
    let mut pm = PassManager::new();
    register_standard_analyses(&mut pm);

    let name_set: std::collections::HashSet<&str> = names.iter().map(|s| s.as_str()).collect();

    for entry in PASS_REGISTRY {
        let matched = name_set.contains(entry.name)
            || entry.aliases.iter().any(|alias| name_set.contains(alias));
        if matched {
            pm.add_pass_boxed((entry.make)());
        }
    }

    pm
}

// ── Cross-pass integration tests ────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::*;
    use crate::pass::{BpfProgram, PassContext};

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

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
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
    fn test_pipeline_wide_mem_then_spectre() {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(LivenessAnalysis);
        pm.add_pass(WideMemPass);
        pm.add_pass(SpectreMitigationPass);

        let insns = vec![
            BpfInsn::ldx_mem(BPF_B, 0, 6, 0),
            BpfInsn::ldx_mem(BPF_B, 1, 6, 1),
            BpfInsn::alu64_imm(BPF_LSH, 1, 8),
            BpfInsn::alu64_reg(BPF_OR, 0, 1),
            jeq_imm(0, 42, 1),
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ];

        let mut prog = make_program(insns);
        // Provide a barrier btf_id so the spectre pass can fire.
        let mut ctx = PassContext::test_default();
        ctx.kinsn_registry.speculation_barrier_btf_id = 777;

        let result = pm.run(&mut prog, &ctx).unwrap();

        assert!(result.program_changed);
        assert!(result.total_sites_applied >= 2);
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

        let pm = build_default_pipeline();
        let result = pm.run(&mut prog, &ctx).unwrap();
        assert!(result.program_changed);
        assert!(result.total_sites_applied >= 1);
    }

    #[test]
    fn test_default_pipeline_starts_with_map_inline() {
        let pm = build_default_pipeline();
        assert_eq!(pm.pass_names().first().copied(), Some("map_inline"));
        assert_eq!(pm.pass_names().get(1).copied(), Some("const_prop"));
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
        let pm = build_default_pipeline();
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
        let pm = build_default_pipeline();
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
        let pm = build_default_pipeline();
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
        let pm = build_default_pipeline();
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
        let pm = build_default_pipeline();
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
