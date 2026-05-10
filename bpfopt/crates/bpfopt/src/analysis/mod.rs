// SPDX-License-Identifier: MIT
//! Concrete analysis implementations for the pass framework.

mod branch_target;
#[cfg(test)]
mod branch_target_tests;
mod cfg;
#[cfg(test)]
mod cfg_tests;
mod liveness;
#[cfg(test)]
mod liveness_tests;
mod map_refs;
#[cfg(test)]
mod map_refs_tests;
mod site_scan;
#[cfg(test)]
mod site_scan_tests;

pub use branch_target::BranchTargetAnalysis;
pub use cfg::{subprog_bounds, subprog_ranges, CFGAnalysis};
pub use liveness::{insn_use_def_set, LivenessAnalysis, RegUseDefSet};
pub use map_refs::{MapBinding, MapRefsAnalysis, MapRefsResult};
pub use site_scan::{iter_sites, Site};

// Result types are used by tests and analysis cache consumers.
pub use branch_target::BranchTargetResult;
pub use cfg::CFGResult;
pub use liveness::LivenessResult;
