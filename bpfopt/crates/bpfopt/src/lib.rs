// SPDX-License-Identifier: MIT
//! bpfopt — BPF bytecode optimizer library.
//!
//! This is the library for BPF program transformations.
//! It is workspace-internal and not published as a public crate.
//! Zero kernel dependency — pure bytecode in, bytecode out.

pub mod analysis;
pub mod insn;
pub mod pass;
pub mod passes;
pub mod verifier_log;

#[cfg(test)]
mod pass_tests;
#[cfg(test)]
pub(crate) mod test_helpers;
