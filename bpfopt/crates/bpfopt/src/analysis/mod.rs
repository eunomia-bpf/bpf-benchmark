// SPDX-License-Identifier: MIT
//! Concrete analysis implementations for the pass framework.

mod bbprogram;
mod bbprogram_api;
mod bbprogram_btf;
pub mod bbprogram_lift;
pub mod bbprogram_lower;
mod bbprogram_use_def;

pub use bbprogram::{
    BBMapBinding, BBProgram, Block, BlockId, FrameId, InsnSite, KinsnAdmissionWindow, Terminator,
};
pub(crate) use bbprogram::{BtfMetadataMap, VerifierOracle};
pub use bbprogram_api::DiamondPattern;
pub use bbprogram_lift::lift_with_pass_context;
pub use bbprogram_lower::lower;
pub use bbprogram_use_def::{insn_use_def_set, DefSite, RegUseDefSet, UseDefGraph, UseSite};

#[cfg(test)]
mod bbprogram_liveness_tests;
