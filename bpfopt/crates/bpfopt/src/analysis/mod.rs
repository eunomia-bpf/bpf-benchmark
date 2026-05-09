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

pub use branch_target::BranchTargetAnalysis;
pub use cfg::CFGAnalysis;
pub use liveness::LivenessAnalysis;

// Result types are used by tests and analysis cache consumers.
pub use branch_target::BranchTargetResult;
pub use cfg::CFGResult;
pub use liveness::LivenessResult;
