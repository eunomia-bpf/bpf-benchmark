// SPDX-License-Identifier: MIT
//! kernel-sys — Raw BPF syscall wrappers.
//!
//! Zero libbpf dependency. All interaction with the kernel goes through
//! `libc::syscall(SYS_bpf, ...)`.
//!
//! TODO: Extract from daemon/src/bpf.rs when implementing bpfget/bpfrejit/bpfverify/bpfprof CLIs.

/// Placeholder — will be populated when kernel-facing CLIs are implemented.
pub fn placeholder() {}
