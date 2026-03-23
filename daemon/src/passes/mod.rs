// SPDX-License-Identifier: MIT
//! Concrete pass implementations and pipeline constructors.

pub mod utils;
mod wide_mem;
mod rotate;
mod cond_select;
mod branch_flip;
mod spectre;
mod extract;
mod endian;

pub use wide_mem::WideMemPass;
pub use rotate::RotatePass;
pub use cond_select::CondSelectPass;
pub use branch_flip::BranchFlipPass;
pub use spectre::SpectreMitigationPass;
pub use extract::ExtractPass;
pub use endian::EndianFusionPass;

use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis};
use crate::pass::{BpfPass, PassManager};

// ── Legacy alias ───────────────────────────────────────────────────
// Re-export `fixup_all_branches` under the old name for backward compat
// within this crate. New code should use `utils::fixup_all_branches` directly.
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
        make: || Box::new(BranchFlipPass { min_bias: 0.7, max_branch_miss_rate: 0.05 }),
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
    use crate::pass::{BpfProgram, PassContext, ProgMeta};

    fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
        BpfProgram::new(insns, ProgMeta::default())
    }

    fn exit_insn() -> BpfInsn {
        BpfInsn { code: BPF_JMP | BPF_EXIT, regs: 0, off: 0, imm: 0 }
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
        ctx.kfunc_registry.speculation_barrier_btf_id = 777;

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

        let prog = make_program(vec![
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::ja(-2),
        ]);

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
}
