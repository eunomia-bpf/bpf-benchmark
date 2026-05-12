// SPDX-License-Identifier: MIT

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
