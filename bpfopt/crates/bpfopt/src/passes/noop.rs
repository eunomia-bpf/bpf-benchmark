// SPDX-License-Identifier: MIT
//! No-op pass.
//!
//! Paper baseline: measures the framework cost (daemon dispatch + bpfopt CLI
//! invocation + kernel BPF_PROG_REJIT round-trip) independent of any actual
//! bytecode transform. Useful for isolating ReJIT pipeline overhead from the
//! per-pass optimization effect in performance regressions.

use crate::analysis::BBProgram;
use crate::pass::*;

pub struct NoopPass;

impl BpfPass for NoopPass {
    fn name(&self) -> &str {
        "noop"
    }

    fn run(&self, _program: &mut BBProgram, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        Ok(PassResult::unchanged())
    }
}
