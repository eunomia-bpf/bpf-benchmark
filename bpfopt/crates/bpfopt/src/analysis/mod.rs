// SPDX-License-Identifier: MIT
//! Concrete analysis implementations for the pass framework.

mod bbprogram;
mod bbprogram_api;
mod bbprogram_btf;
pub mod bbprogram_lift;
pub mod bbprogram_lower;
mod bbprogram_use_def;

pub use bbprogram::{BBMapBinding, BBProgram, Block, BlockId, FrameId, InsnSite, Terminator};
pub(crate) use bbprogram::{BtfMetadataMap, VerifierOracle};
pub use bbprogram_api::DiamondPattern;
pub use bbprogram_lift::{
    lift, lift_with_kinsn_registry, lift_with_kinsn_registry_and_side_inputs,
};
pub use bbprogram_lower::lower;
pub use bbprogram_use_def::{insn_use_def_set, DefSite, RegUseDefSet, UseDefGraph, UseSite};

#[cfg(test)]
mod bbprogram_liveness_tests;
