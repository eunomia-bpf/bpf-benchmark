// SPDX-License-Identifier: MIT
// Instruction-boundary site scanning helpers.

use crate::insn::{insn_width, BpfInsn};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Site {
    pub pc: usize,
    pub len: usize,
}

pub fn iter_sites<F>(insns: &[BpfInsn], mut pattern_fn: F) -> Vec<Site>
where
    F: FnMut(&[BpfInsn], usize) -> Option<usize>,
{
    let mut sites = Vec::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        if let Some(len) = pattern_fn(insns, pc) {
            sites.push(Site { pc, len });
            pc += len.max(insn_width(&insns[pc]));
            continue;
        }
        pc += insn_width(&insns[pc]);
    }
    sites
}
