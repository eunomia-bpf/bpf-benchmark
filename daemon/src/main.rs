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
use clap::{Parser, Subcommand};

#[derive(Parser)]
#[command(name = "bpfrejit-daemon", version, about = "BpfReJIT userspace daemon")]
struct Cli {
    #[command(subcommand)]
    command: Command,
}

#[derive(Subcommand)]
enum Command {
    /// Run as a Unix socket server (persistent daemon mode).
    Serve {
        /// Unix socket path.
        #[arg(long, default_value = "/var/run/bpfrejit.sock")]
        socket: String,
        /// Directory where failure workdirs are exported on ReJIT failure.
        #[arg(long)]
        failure_root: Option<String>,
        /// Directory containing bpfopt/bpfprof CLI binaries (overrides PATH lookup).
        #[arg(long)]
        cli_dir: Option<String>,
        /// Preserve all per-program workdirs under <failure-root>/workdirs/ (debug).
        #[arg(long)]
        keep_all_workdirs: bool,
    },
}

fn main() -> Result<()> {
    let cli = Cli::parse();

    match cli.command {
        Command::Serve { socket, failure_root, cli_dir, keep_all_workdirs } => {
            server::cmd_serve(&socket, failure_root.as_deref(), cli_dir.as_deref(), keep_all_workdirs)
        }
    }
}
