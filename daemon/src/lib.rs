// SPDX-License-Identifier: MIT
//! Re-exports for external callers (bpfopt/kinsnprober) that want to reuse the
//! BTF probe code without duplicating it. The daemon binary still uses these
//! same modules via its `mod` declarations in `main.rs`; this library entry
//! point just makes the public-marked items reachable from a separate crate.

pub mod bpf;
pub mod commands;
pub mod server;
pub mod syscall;
