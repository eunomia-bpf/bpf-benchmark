// SPDX-License-Identifier: MIT
//! Concrete pass implementations and pipeline constructors.

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
pub mod map_inline;
mod noop;
mod prefetch;
mod rotate;
mod skb_load_bytes;
mod wide_mem;

pub use bounds_check_merge::BoundsCheckMergePass;
pub use branch_flip::BranchFlipPass;
pub use bulk_memory::BulkMemoryPass;
pub use ccmp::CcmpPass;
pub use cond_select::CondSelectPass;
pub use const_prop::ConstPropPass;
pub use dce::DcePass;
pub use endian::EndianFusionPass;
pub use extract::ExtractPass;
pub use map_inline::MapInlinePass;
pub use noop::NoopPass;
pub use prefetch::PrefetchPass;
pub use rotate::RotatePass;
pub use skb_load_bytes::SkbLoadBytesSpecPass;
pub use wide_mem::WideMemPass;

use crate::pass::{BpfPass, KinsnDescriptor};

// ── Pass registry ───────────────────────────────────────────────────

/// Entry in the pass registry. Defines the canonical name and constructor for
/// each pass.
pub struct PassRegistryEntry {
    /// Canonical pass name (matches `BpfPass::name()`).
    pub name: &'static str,
    /// Constructor: parses pass-local CLI args and returns a boxed pass instance.
    pub make: fn(&[String]) -> Result<Box<dyn BpfPass>>,
    /// Side-input and kinsn requirements consumed by the CLI entrypoint.
    pub requirements: PassRequirements,
}

#[derive(Clone, Copy, Debug)]
pub struct PassRequirements {
    flags: u8,
    pub kinsn_targets: &'static [KinsnDescriptor],
    pub required_kinsns: &'static [&'static str],
}

impl PassRequirements {
    const fn new(
        flags: u8,
        kinsn_targets: &'static [KinsnDescriptor],
        required_kinsns: &'static [&'static str],
    ) -> Self {
        Self {
            flags,
            kinsn_targets,
            required_kinsns,
        }
    }

    pub fn needs_kinsns(self) -> bool {
        self.flags & NEEDS_KINSNS != 0
    }

    pub fn needs_verifier_states(self) -> bool {
        self.flags & NEEDS_VERIFIER_STATES != 0
    }
}

const NEEDS_KINSNS: u8 = 1 << 0;
const NEEDS_VERIFIER_STATES: u8 = 1 << 1;

const REQ_ROTATE: &[&str] = &["bpf_rotate64", "bpf_rotate32"];
const REQ_SELECT: &[&str] = &["bpf_select64"];
const REQ_CCMP: &[&str] = &["bpf_ccmp64"];
const REQ_EXTRACT: &[&str] = &["bpf_extract64"];
const REQ_ENDIAN: &[&str] = &[
    "bpf_endian_load16",
    "bpf_endian_load32",
    "bpf_endian_load64",
];
const REQ_BULK_MEMORY: &[&str] = &["bpf_bulk_memcpy", "bpf_bulk_memset"];
const REQ_PREFETCH: &[&str] = &["bpf_prefetch"];

const PASS_REQ_NONE: PassRequirements = PassRequirements::new(0, &[], &[]);
const PASS_REQ_NEEDS_STATES: PassRequirements =
    PassRequirements::new(NEEDS_VERIFIER_STATES, &[], &[]);
const PASS_REQ_ROTATE: PassRequirements =
    PassRequirements::new(NEEDS_KINSNS, rotate::KINSN_TARGETS, REQ_ROTATE);
const PASS_REQ_SELECT: PassRequirements =
    PassRequirements::new(NEEDS_KINSNS, cond_select::KINSN_TARGETS, REQ_SELECT);
const PASS_REQ_CCMP: PassRequirements =
    PassRequirements::new(NEEDS_KINSNS, ccmp::KINSN_TARGETS, REQ_CCMP);
const PASS_REQ_EXTRACT: PassRequirements =
    PassRequirements::new(NEEDS_KINSNS, extract::KINSN_TARGETS, REQ_EXTRACT);
const PASS_REQ_ENDIAN: PassRequirements =
    PassRequirements::new(NEEDS_KINSNS, endian::KINSN_TARGETS, REQ_ENDIAN);
const PASS_REQ_BULK_MEMORY: PassRequirements =
    PassRequirements::new(NEEDS_KINSNS, bulk_memory::KINSN_TARGETS, REQ_BULK_MEMORY);
const PASS_REQ_PREFETCH: PassRequirements =
    PassRequirements::new(NEEDS_KINSNS, prefetch::KINSN_TARGETS, REQ_PREFETCH);

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
    ($name:literal, $make:expr, $requirements:expr) => {
        PassRegistryEntry {
            name: $name,
            make: |args| -> Result<Box<dyn BpfPass>> {
                reject_pass_args($name, args)?;
                Ok(Box::new($make))
            },
            requirements: $requirements,
        }
    };
}

/// Canonical pass ordering and requirements. Pipeline builders iterate this array in
/// order, guaranteeing consistent pass sequencing regardless of selected names.
#[rustfmt::skip] pub const PASS_REGISTRY: &[PassRegistryEntry] = &[
    pass_entry!("noop", NoopPass, PASS_REQ_NONE),
    PassRegistryEntry { name: "map_inline", make: MapInlinePass::from_cli_args, requirements: PASS_REQ_NEEDS_STATES },
    pass_entry!("const_prop", ConstPropPass, PASS_REQ_NEEDS_STATES),
    pass_entry!("dce", DcePass, PASS_REQ_NONE),
    pass_entry!("skb_load_bytes_spec", SkbLoadBytesSpecPass, PASS_REQ_NONE),
    pass_entry!("bounds_check_merge", BoundsCheckMergePass, PASS_REQ_NONE),
    pass_entry!("wide_mem", WideMemPass, PASS_REQ_NONE),
    pass_entry!("bulk_memory", BulkMemoryPass, PASS_REQ_BULK_MEMORY),
    pass_entry!("rotate", RotatePass, PASS_REQ_ROTATE),
    pass_entry!("cond_select", CondSelectPass, PASS_REQ_SELECT),
    pass_entry!("ccmp", CcmpPass, PASS_REQ_CCMP),
    pass_entry!("extract", ExtractPass, PASS_REQ_EXTRACT),
    pass_entry!("endian_fusion", EndianFusionPass, PASS_REQ_ENDIAN),
    pass_entry!("branch_flip", BranchFlipPass { min_bias: 0.7, max_branch_miss_rate: 0.05 }, PASS_REQ_NONE),
    pass_entry!("prefetch", PrefetchPass, PASS_REQ_PREFETCH),
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
mod map_inline_tests;
#[cfg(test)]
mod mod_tests;
#[cfg(test)]
mod prefetch_tests;
#[cfg(test)]
mod rotate_tests;
#[cfg(test)]
mod skb_load_bytes_tests;
#[cfg(test)]
mod wide_mem_tests;
