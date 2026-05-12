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
pub use map_inline::{MapInfo, MapInfoResult, MapInlinePass, MapReference};
pub use noop::NoopPass;
pub use prefetch::PrefetchPass;
pub use rotate::RotatePass;
pub use skb_load_bytes::SkbLoadBytesSpecPass;
pub use wide_mem::WideMemPass;

use crate::pass::{BpfPass, KinsnDescriptor};

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
#[rustfmt::skip] pub struct PassMetadata { flags: u8, pub kinsn_targets: &'static [KinsnDescriptor], pub required_kinsns: &'static [&'static str] }

#[rustfmt::skip] impl PassMetadata {
    const fn new(flags: u8, kinsn_targets: &'static [KinsnDescriptor], required_kinsns: &'static [&'static str]) -> Self { Self { flags, kinsn_targets, required_kinsns } }
    pub fn needs_target(self) -> bool { self.flags & NEEDS_TARGET != 0 }
    pub fn needs_verifier_states(self) -> bool { self.flags & NEEDS_VERIFIER_STATES != 0 }
    pub fn produces_verifier_states(self) -> bool { self.flags & PRODUCES_VERIFIER_STATES != 0 }
    pub fn needs_map_values(self) -> bool { self.flags & NEEDS_MAP_VALUES != 0 }
}

const NEEDS_TARGET: u8 = 1 << 0;
const NEEDS_VERIFIER_STATES: u8 = 1 << 1;
const PRODUCES_VERIFIER_STATES: u8 = 1 << 2;
const NEEDS_MAP_VALUES: u8 = 1 << 3;

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

const META_NONE: PassMetadata = PassMetadata::new(0, &[], &[]);
const META_PRODUCES_STATES: PassMetadata = PassMetadata::new(PRODUCES_VERIFIER_STATES, &[], &[]);
#[rustfmt::skip] const META_NEEDS_AND_PRODUCES_STATES: PassMetadata = PassMetadata::new(NEEDS_VERIFIER_STATES | PRODUCES_VERIFIER_STATES, &[], &[]);
#[rustfmt::skip] const META_MAP_INLINE: PassMetadata = PassMetadata::new(NEEDS_VERIFIER_STATES | PRODUCES_VERIFIER_STATES | NEEDS_MAP_VALUES, &[], &[]);
#[rustfmt::skip] const META_ROTATE: PassMetadata = PassMetadata::new(NEEDS_TARGET, rotate::KINSN_TARGETS, REQ_ROTATE);
#[rustfmt::skip] const META_SELECT: PassMetadata = PassMetadata::new(NEEDS_TARGET, cond_select::KINSN_TARGETS, REQ_SELECT);
#[rustfmt::skip] const META_CCMP: PassMetadata = PassMetadata::new(NEEDS_TARGET, ccmp::KINSN_TARGETS, REQ_CCMP);
#[rustfmt::skip] const META_EXTRACT: PassMetadata = PassMetadata::new(NEEDS_TARGET, extract::KINSN_TARGETS, REQ_EXTRACT);
#[rustfmt::skip] const META_ENDIAN: PassMetadata = PassMetadata::new(NEEDS_TARGET, endian::KINSN_TARGETS, REQ_ENDIAN);
#[rustfmt::skip] const META_BULK_MEMORY: PassMetadata = PassMetadata::new(NEEDS_TARGET, bulk_memory::KINSN_TARGETS, REQ_BULK_MEMORY);
#[rustfmt::skip] const META_PREFETCH: PassMetadata = PassMetadata::new(NEEDS_TARGET, prefetch::KINSN_TARGETS, REQ_PREFETCH);

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

/// Canonical pass ordering and metadata. Pipeline builders iterate this array in
/// order, guaranteeing consistent pass sequencing regardless of selected names.
#[rustfmt::skip] pub const PASS_REGISTRY: &[PassRegistryEntry] = &[
    pass_entry!("noop", "Identity pass — measures ReJIT pipeline overhead with no transform", NoopPass, META_PRODUCES_STATES),
    PassRegistryEntry { name: "map_inline", description: "Inline stable map lookups and pseudo-map-value loads", make: MapInlinePass::from_cli_args, metadata: META_MAP_INLINE },
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
    pass_entry!("branch_flip", "Flip branch polarity using PGO data to improve branch prediction", BranchFlipPass { min_bias: 0.7, max_branch_miss_rate: 0.05 }, META_NONE),
    pass_entry!("prefetch", "Insert packet and map-value prefetch kinsn calls", PrefetchPass, META_PREFETCH),
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
