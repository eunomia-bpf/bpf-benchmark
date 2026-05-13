// SPDX-License-Identifier: MIT
//! Concrete pass implementations and registry.

use anyhow::Result;

mod bounds_check_merge;
mod branch_flip;
mod bulk_memory;
mod ccmp;
mod cond_select;
mod const_prop;
mod dce;
mod endian;
mod extract;
mod lea;
pub mod map_inline;
mod noop;
mod prefetch;
mod rotate;
mod skb_load_bytes;
mod wide_mem;

// Only NoopPass is referenced outside this module (by the bbprogram_roundtrip
// integration test). The other pass structs are reached through PASS_REGISTRY.
pub use noop::NoopPass;

use crate::pass::{BpfPass, KinsnDescriptor};

// ── Pass registry ───────────────────────────────────────────────────

/// Entry in the pass registry. `kinsn_targets` declares which kinsn descriptors
/// the pass might emit (used by `KinsnRegistry` to know which targets exist and
/// to compute register liveness for in-bytecode kinsn calls). `needs_verifier_states`
/// flags passes that consume the daemon's verifier log at lift time.
///
/// There is intentionally no kinsn pre-flight or arch gate here — bpfopt emits
/// candidate bytecode and lets the kernel verifier (via the daemon's REJIT)
/// reject what the running kernel cannot accept.
pub struct PassRegistryEntry {
    pub name: &'static str,
    pub make: fn(&[String]) -> Result<Box<dyn BpfPass>>,
    pub kinsn_targets: &'static [KinsnDescriptor],
    pub needs_verifier_states: bool,
}

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
    ($name:literal, $make:expr, $kinsn_targets:expr, $needs_verifier_states:expr) => {
        PassRegistryEntry {
            name: $name,
            make: |args| -> Result<Box<dyn BpfPass>> {
                reject_pass_args($name, args)?;
                Ok(Box::new($make))
            },
            kinsn_targets: $kinsn_targets,
            needs_verifier_states: $needs_verifier_states,
        }
    };
}

/// Canonical pass ordering and requirements. The CLI looks up entries by name to
/// build a single-pass invocation; the daemon iterates this array in order when
/// orchestrating multiple per-pass `bpfopt` invocations.
#[rustfmt::skip] pub const PASS_REGISTRY: &[PassRegistryEntry] = &[
    pass_entry!("noop", noop::NoopPass, &[], false),
    PassRegistryEntry { name: "map_inline", make: map_inline::MapInlinePass::from_cli_args, kinsn_targets: &[], needs_verifier_states: true },
    pass_entry!("const_prop", const_prop::ConstPropPass, &[], true),
    pass_entry!("dce", dce::DcePass, &[], false),
    pass_entry!("skb_load_bytes_spec", skb_load_bytes::SkbLoadBytesSpecPass, &[], false),
    pass_entry!("bounds_check_merge", bounds_check_merge::BoundsCheckMergePass, &[], false),
    pass_entry!("wide_mem", wide_mem::WideMemPass, &[], false),
    pass_entry!("bulk_memory", bulk_memory::BulkMemoryPass, bulk_memory::KINSN_TARGETS, false),
    pass_entry!("rotate", rotate::RotatePass, rotate::KINSN_TARGETS, false),
    pass_entry!("cond_select", cond_select::CondSelectPass, cond_select::KINSN_TARGETS, false),
    pass_entry!("ccmp", ccmp::CcmpPass, ccmp::KINSN_TARGETS, false),
    pass_entry!("extract", extract::ExtractPass, extract::KINSN_TARGETS, false),
    pass_entry!("endian_fusion", endian::EndianFusionPass, endian::KINSN_TARGETS, false),
    pass_entry!("lea", lea::LeaPass, lea::KINSN_TARGETS, false),
    pass_entry!("branch_flip", branch_flip::BranchFlipPass { min_bias: 0.7, max_branch_miss_rate: 0.05 }, &[], false),
    pass_entry!("prefetch", prefetch::PrefetchPass, prefetch::KINSN_TARGETS, false),
];

#[cfg(test)]
mod bounds_check_merge_tests;
#[cfg(test)]
mod branch_flip_tests;
#[cfg(test)]
mod bulk_memory_tests;
#[cfg(test)]
mod ccmp_tests;
#[cfg(test)]
mod cond_select_tests;
#[cfg(test)]
mod const_prop_tests;
#[cfg(test)]
mod dce_tests;
#[cfg(test)]
mod endian_tests;
#[cfg(test)]
mod extract_tests;
#[cfg(test)]
mod lea_tests;
#[cfg(test)]
mod map_inline_tests;
#[cfg(test)]
mod prefetch_tests;
#[cfg(test)]
mod rotate_tests;
#[cfg(test)]
mod skb_load_bytes_tests;
#[cfg(test)]
mod wide_mem_tests;
