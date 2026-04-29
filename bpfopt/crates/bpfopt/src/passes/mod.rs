// SPDX-License-Identifier: MIT
//! Concrete pass implementations and pipeline constructors.

use anyhow::Result;

mod bounds_check_merge;
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
mod utils;
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

/// Build a pipeline containing only the named passes, in canonical order.
///
/// Pass names are matched against `PASS_REGISTRY` entries by canonical name.
/// Unknown names are rejected.
#[cfg(test)]
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
#[path = "mod_tests.rs"]
mod tests;
