// SPDX-License-Identifier: MIT
//! Concrete analysis implementations for the pass framework.

mod bbprogram;
mod bbprogram_api;
mod bbprogram_btf;
mod bbprogram_helpers;
pub mod bbprogram_lift;
pub mod bbprogram_lower;
mod bbprogram_use_def;

pub use bbprogram::{
    BBMapBinding, BBProgram, Block, BlockId, BtfMetadataMap, FrameId, InsnSite, Terminator,
    VerifierOracle,
};
pub use bbprogram_api::DiamondPattern;
pub(crate) use bbprogram_helpers::{
    advance_reg_state, control_flow_target_sites, packet_ctx_layout, program_sites, read_json_file,
    PacketCtxLayout, PacketCtxLayoutScope, SimpleRegValue,
};
pub use bbprogram_lift::{lift, lift_with_kinsn_registry};
pub use bbprogram_lower::lower;
pub use bbprogram_use_def::{insn_use_def_set, DefSite, RegUseDefSet, UseDefGraph, UseSite};

#[cfg(test)]
mod bbprogram_liveness_tests;
