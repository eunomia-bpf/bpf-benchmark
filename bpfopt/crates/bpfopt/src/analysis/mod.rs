// SPDX-License-Identifier: MIT
//! Concrete analysis implementations for the pass framework.

mod bbprogram;
mod bbprogram_api;
mod bbprogram_btf;
pub(crate) mod bbprogram_lift;
pub(crate) mod bbprogram_lower;
mod bbprogram_use_def;

pub(crate) use crate::verifier_log::VerifierStatesBySite;
pub(crate) use bbprogram::BtfMetadataMap;
pub use bbprogram::{
    print_and_reset_timing, BasicBlock, BlockId, FrameId, InsnNode, InsnSite, LiftedRegFact,
    ProgramCFG, SlotDistance, Terminator,
};
pub use bbprogram_api::DiamondPattern;
pub use bbprogram_lift::{
    canonicalize_map_refs_to_idx, canonicalize_map_refs_to_idx_with_mapping,
    lift_with_pass_context, shift_target_module_call_offsets_for_map_prefix,
    validate_map_inline_hint_specs,
};
pub use bbprogram_lower::lower;
pub(crate) use bbprogram_use_def::{insn_use_def_set, UseDefGraph};
pub use bbprogram_use_def::{DefSite, UseSite};

#[cfg(test)]
mod bbprogram_liveness_tests;
