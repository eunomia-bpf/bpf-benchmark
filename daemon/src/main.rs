// SPDX-License-Identifier: MIT
//! bpfrejit-daemon — BpfReJIT userspace daemon.
//!
//! Scans live kernel BPF programs for optimization sites and can apply
//! bytecode rewrites via BPF_PROG_REJIT.

mod bpf;
mod commands;
mod invalidation;
mod server;

use anyhow::Result;
use clap::Parser;

/// Hardcoded socket path — runner Python connects here.
const SOCKET_PATH: &str = "/var/tmp/bpfrejit-daemon.sock";
/// Hardcoded failure export root — ReJIT failure workdirs land here.
const FAILURE_ROOT: &str = "/var/tmp/bpfrejit-failures";

#[derive(Parser)]
#[command(name = "bpfrejit-daemon", version, about = "BpfReJIT userspace daemon")]
struct Cli {}

fn main() -> Result<()> {
    let _cli = Cli::parse();
    server::cmd_serve(SOCKET_PATH, FAILURE_ROOT)
}
