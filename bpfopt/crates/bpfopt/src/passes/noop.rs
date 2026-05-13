// SPDX-License-Identifier: MIT

use crate::analysis::ProgramCFG;
use crate::pass::*;

pub struct NoopPass;

impl BpfPass for NoopPass {
    fn name(&self) -> &str {
        "noop"
    }

    fn run(&self, _program: &mut ProgramCFG, _ctx: &PassContext) -> anyhow::Result<PassResult> {
        Ok(PassResult::unchanged())
    }
}
