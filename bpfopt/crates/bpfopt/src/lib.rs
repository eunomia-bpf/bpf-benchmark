// SPDX-License-Identifier: MIT
//! bpfopt — BPF bytecode optimizer library.
//!
//! This is the library for BPF program transformations.
//! It is workspace-internal and not published as a public crate.
//! Zero kernel dependency — pure bytecode in, bytecode out.

pub mod analysis;
#[cfg(test)]
pub mod bpf {
    pub use crate::mock_maps::{install_mock_map, use_mock_maps, BpfMapInfo, MockMapState};
}
pub mod insn;
#[cfg(test)]
pub mod mock_maps;
pub mod pass;
pub mod passes;
