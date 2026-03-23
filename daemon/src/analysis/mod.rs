// SPDX-License-Identifier: MIT
//! Concrete analysis implementations for the pass framework.

mod branch_target;
mod cfg;
mod liveness;

pub use branch_target::BranchTargetAnalysis;
pub use cfg::CFGAnalysis;
pub use liveness::LivenessAnalysis;

// Result types are used by tests and analysis cache consumers.
#[allow(unused_imports)]
pub use branch_target::BranchTargetResult;
#[allow(unused_imports)]
pub use cfg::CFGResult;
#[allow(unused_imports)]
pub use liveness::LivenessResult;
