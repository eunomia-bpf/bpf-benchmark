// SPDX-License-Identifier: MIT
//! Concrete analysis implementations for the pass framework.

mod branch_target;
mod cfg;
mod liveness;
mod map_info;

pub use branch_target::BranchTargetAnalysis;
pub use cfg::CFGAnalysis;
pub use liveness::LivenessAnalysis;
pub use map_info::MapInfoAnalysis;

// Result types are used by tests and analysis cache consumers.
#[allow(unused_imports)]
pub use branch_target::BranchTargetResult;
#[allow(unused_imports)]
pub use cfg::CFGResult;
#[allow(unused_imports)]
pub use liveness::LivenessResult;
#[allow(unused_imports)]
pub use map_info::{collect_map_references, MapInfo, MapInfoResult, MapReference};
