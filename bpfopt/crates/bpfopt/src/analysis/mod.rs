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
    BBMapBinding, BBProgram, Block, BlockBodyLinearView, BlockId, BtfMetadataMap, FrameId,
    InsnSite, ProgramLinearView, Terminator, VerifierOracle,
};
pub use bbprogram_api::DiamondPattern;
pub use bbprogram_btf::BtfRecordsView;
pub(crate) use bbprogram_helpers::{
    advance_reg_state, annotations_from_profile, block_slot_offset, packet_ctx_layout,
    read_json_file, site_current_pc, PacketCtxLayout, PacketCtxLayoutScope, SimpleRegValue,
};
pub use bbprogram_lift::{lift, lift_with_kinsn_registry};
pub use bbprogram_lower::lower;
pub use bbprogram_use_def::{insn_use_def_set, DefSite, RegUseDefSet, UseDefGraph, UseSite};

#[cfg(test)]
mod bbprogram_branch_target_tests;
#[cfg(test)]
mod bbprogram_cfg_tests;
#[cfg(test)]
mod bbprogram_liveness_tests;
#[cfg(test)]
mod bbprogram_map_refs_tests;
#[cfg(test)]
mod bbprogram_site_scan_tests;
#[cfg(test)]
mod lower_tests;
