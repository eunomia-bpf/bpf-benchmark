// SPDX-License-Identifier: MIT
//! Concrete pass implementations and pipeline constructors.

use anyhow::Result;

mod bounds_check_merge;
#[cfg(test)]
mod bounds_check_merge_tests;
mod branch_flip;
#[cfg(test)]
mod branch_flip_tests;
mod bulk_memory;
#[cfg(test)]
mod bulk_memory_tests;
mod ccmp;
#[cfg(test)]
mod ccmp_tests;
mod cond_select;
#[cfg(test)]
mod cond_select_tests;
mod const_prop;
#[cfg(test)]
mod const_prop_tests;
mod dce;
#[cfg(test)]
mod dce_tests;
mod endian;
#[cfg(test)]
mod endian_tests;
mod extract;
#[cfg(test)]
mod extract_tests;
pub mod map_inline;
mod noop;
mod prefetch;
#[cfg(test)]
mod prefetch_tests;
mod rotate;
#[cfg(test)]
mod rotate_tests;
mod skb_load_bytes;
#[cfg(test)]
mod skb_load_bytes_tests;
mod utils;
mod wide_mem;
#[cfg(test)]
mod wide_mem_tests;

pub use bounds_check_merge::BoundsCheckMergePass;
pub use branch_flip::BranchFlipPass;
pub use bulk_memory::BulkMemoryPass;
pub use ccmp::CcmpPass;
pub use cond_select::CondSelectPass;
pub use const_prop::ConstPropPass;
pub use dce::DcePass;
pub use endian::EndianFusionPass;
pub use extract::ExtractPass;
pub use map_inline::{MapInfo, MapInfoAnalysis, MapInfoResult, MapInlinePass, MapReference};
pub use noop::NoopPass;
pub use prefetch::PrefetchPass;
pub use rotate::RotatePass;
pub use skb_load_bytes::SkbLoadBytesSpecPass;
pub use wide_mem::WideMemPass;

#[cfg(test)]
use crate::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis};
use crate::pass::BpfPass;
#[cfg(test)]
use crate::pass::PassManager;
use serde::Serialize;

// ── Pass registry ───────────────────────────────────────────────────

/// Entry in the pass registry. Defines the canonical name, description,
/// and constructor for each pass.
pub struct PassRegistryEntry {
    /// Canonical pass name (matches `BpfPass::name()`).
    pub name: &'static str,
    /// Short description for help text.
    pub description: &'static str,
    /// Constructor: parses pass-local CLI args and returns a boxed pass instance.
    pub make: fn(&[String]) -> Result<Box<dyn BpfPass>>,
    /// Side-input and kinsn requirements consumed by `bpfopt list-passes --json`.
    pub metadata: PassMetadata,
}

#[derive(Clone, Copy, Debug)]
#[rustfmt::skip] pub struct PassMetadata { flags: u8, pub kinsns_used: &'static [KinsnRef] }

#[derive(Clone, Copy, Debug, Serialize)]
#[rustfmt::skip] pub struct KinsnRef { pub json_name: &'static str, pub probe_aliases: &'static [&'static str] }

#[rustfmt::skip] impl KinsnRef { const fn new(json_name: &'static str, probe_aliases: &'static [&'static str]) -> Self { Self { json_name, probe_aliases } } }

#[rustfmt::skip] impl PassMetadata {
    const fn new(flags: u8, kinsns_used: &'static [KinsnRef]) -> Self { Self { flags, kinsns_used } }
    pub fn needs_target(self) -> bool { self.flags & NEEDS_TARGET != 0 }
    pub fn needs_verifier_states(self) -> bool { self.flags & NEEDS_VERIFIER_STATES != 0 }
    pub fn produces_verifier_states(self) -> bool { self.flags & PRODUCES_VERIFIER_STATES != 0 }
    pub fn needs_map_values(self) -> bool { self.flags & NEEDS_MAP_VALUES != 0 }
}

const NEEDS_TARGET: u8 = 1 << 0;
const NEEDS_VERIFIER_STATES: u8 = 1 << 1;
const PRODUCES_VERIFIER_STATES: u8 = 1 << 2;
const NEEDS_MAP_VALUES: u8 = 1 << 3;

const META_NONE: PassMetadata = PassMetadata::new(0, &[]);
const META_PRODUCES_STATES: PassMetadata = PassMetadata::new(PRODUCES_VERIFIER_STATES, &[]);
#[rustfmt::skip] const META_NEEDS_AND_PRODUCES_STATES: PassMetadata = PassMetadata::new(NEEDS_VERIFIER_STATES | PRODUCES_VERIFIER_STATES, &[]);
#[rustfmt::skip] const META_MAP_INLINE: PassMetadata = PassMetadata::new(NEEDS_VERIFIER_STATES | PRODUCES_VERIFIER_STATES | NEEDS_MAP_VALUES, &[]);
#[rustfmt::skip] const META_ROTATE: PassMetadata = PassMetadata::new(NEEDS_TARGET, &[KinsnRef::new("bpf_rotate64", &["bpf_rotate64"]), KinsnRef::new("bpf_rotate32", &["bpf_rotate32"])]);
#[rustfmt::skip] const META_SELECT: PassMetadata = PassMetadata::new(NEEDS_TARGET, &[KinsnRef::new("bpf_select64", &["bpf_select64"])]);
#[rustfmt::skip] const META_CCMP: PassMetadata = PassMetadata::new(NEEDS_TARGET, &[KinsnRef::new("bpf_ccmp64", &["bpf_ccmp64"])]);
#[rustfmt::skip] const META_EXTRACT: PassMetadata = PassMetadata::new(NEEDS_TARGET, &[KinsnRef::new("bpf_extract64", &["bpf_extract64"])]);
#[rustfmt::skip] const META_ENDIAN: PassMetadata = PassMetadata::new(NEEDS_TARGET, &[KinsnRef::new("bpf_endian_load16", &["bpf_endian_load16"]), KinsnRef::new("bpf_endian_load32", &["bpf_endian_load32"]), KinsnRef::new("bpf_endian_load64", &["bpf_endian_load64"])]);
#[rustfmt::skip] const META_BULK_MEMORY: PassMetadata = PassMetadata::new(NEEDS_TARGET, &[KinsnRef::new("bpf_bulk_memcpy", &["bpf_memcpy_bulk"]), KinsnRef::new("bpf_bulk_memset", &["bpf_memset_bulk"])]);
#[rustfmt::skip] const META_PREFETCH: PassMetadata = PassMetadata::new(NEEDS_TARGET, &[KinsnRef::new("bpf_prefetch", &["bpf_prefetch"])]);

fn reject_pass_args(pass_name: &str, args: &[String]) -> Result<()> {
    if !args.is_empty() {
        anyhow::bail!(
            "{pass_name} does not accept pass-local args: {}",
            args.join(" ")
        );
    }
    Ok(())
}

#[rustfmt::skip] macro_rules! pass_entry {
    ($name:literal, $description:literal, $make:expr, $metadata:expr) => {
        PassRegistryEntry {
            name: $name,
            description: $description,
            make: |args| -> Result<Box<dyn BpfPass>> {
                reject_pass_args($name, args)?;
                Ok(Box::new($make))
            },
            metadata: $metadata,
        }
    };
}

#[rustfmt::skip] macro_rules! pass_entry_with_args {
    ($name:literal, $description:literal, $make:expr, $metadata:expr) => {
        PassRegistryEntry { name: $name, description: $description, make: $make, metadata: $metadata }
    };
}

/// Canonical pass ordering and metadata. Pipeline builders iterate this array in
/// order, guaranteeing consistent pass sequencing regardless of selected names.
#[rustfmt::skip] pub const PASS_REGISTRY: &[PassRegistryEntry] = &[
    pass_entry!("noop", "Identity pass — measures ReJIT pipeline overhead with no transform", NoopPass, META_PRODUCES_STATES),
    pass_entry_with_args!("map_inline", "Inline stable map lookups and pseudo-map-value loads", MapInlinePass::from_cli_args, META_MAP_INLINE),
    pass_entry!("const_prop", "Fold register constants into MOV/LD_IMM64/JA rewrites", ConstPropPass, META_NEEDS_AND_PRODUCES_STATES),
    pass_entry!("dce", "Remove CFG-unreachable blocks and NOPs after simplification", DcePass, META_NONE),
    pass_entry!("skb_load_bytes_spec", "Specialize eligible skb_load_bytes helper sites into direct packet access", SkbLoadBytesSpecPass, META_NONE),
    pass_entry!("bounds_check_merge", "Merge direct packet bounds-check ladders into a dominant guard", BoundsCheckMergePass, META_NONE),
    pass_entry!("wide_mem", "Fuse byte-by-byte loads into wider memory accesses", WideMemPass, META_NONE),
    pass_entry!("bulk_memory", "Lower large scalarized memcpy/memset runs into bulk-memory kinsn calls", BulkMemoryPass, META_BULK_MEMORY),
    pass_entry!("rotate", "Replace shift+or patterns with rotate kfunc (ROL/ROR)", RotatePass, META_ROTATE),
    pass_entry!("cond_select", "Replace branch-over-mov with conditional select kfunc (CMOV/CSEL)", CondSelectPass, META_SELECT),
    pass_entry!("ccmp", "Fold ARM64 zero-test compare chains into CCMP kfunc calls", CcmpPass, META_CCMP),
    pass_entry!("extract", "Replace shift+mask with bit field extract kfunc (BEXTR)", ExtractPass, META_EXTRACT),
    pass_entry!("endian_fusion", "Fuse endian swap patterns into endian load kfunc (MOVBE)", EndianFusionPass, META_ENDIAN),
    pass_entry_with_args!("branch_flip", "Flip branch polarity using PGO data to improve branch prediction", BranchFlipPass::from_cli_args, META_NONE),
    pass_entry_with_args!("prefetch", "Insert packet and map-value prefetch kinsn calls", PrefetchPass::from_cli_args, META_PREFETCH),
];

// ── Pipeline constructors ───────────────────────────────────────────

#[cfg(test)]
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

/// Register standard analyses into a PassManager.
#[cfg(test)]
fn register_standard_analyses(pm: &mut PassManager) {
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.register_analysis(MapInfoAnalysis);
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
        pm.add_pass_boxed(make_test_pass(entry));
    }

    Ok(pm)
}

#[cfg(test)]
fn make_test_pass(entry: &PassRegistryEntry) -> Box<dyn BpfPass> {
    match entry.name {
        "map_inline" => Box::new(MapInlinePass),
        "branch_flip" => Box::new(BranchFlipPass {
            min_bias: 0.7,
            max_branch_miss_rate: 0.05,
        }),
        "prefetch" => Box::new(PrefetchPass),
        _ => (entry.make)(&[]).expect("no-arg test pass construction should succeed"),
    }
}

// ── Cross-pass integration tests ────────────────────────────────────

#[cfg(test)]
#[path = "mod_tests.rs"]
mod tests;
