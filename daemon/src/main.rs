// SPDX-License-Identifier: MIT
//! bpfrejit-daemon — BpfReJIT userspace daemon.
//!
//! Scans live kernel BPF programs for optimization sites and can apply
//! bytecode rewrites via BPF_PROG_REJIT.

mod analysis;
mod bpf;
mod commands;
mod elf_parser;
mod insn;
mod invalidation;
mod kfunc_discovery;
mod pass;
mod passes;
mod profiler;
mod server;
#[cfg(test)]
mod test_utils;
mod verifier_log;

use std::time::Duration;

use anyhow::Result;
use clap::{Parser, Subcommand};

use commands::PgoConfig;

#[derive(Parser)]
#[command(name = "bpfrejit-daemon", version, about = "BpfReJIT userspace daemon")]
struct Cli {
    /// Enable runtime profiling before each optimize request.
    #[arg(long)]
    pgo: bool,

    /// PGO observation interval in milliseconds.
    #[arg(long, default_value_t = 500)]
    pgo_interval_ms: u64,

    /// Disable automatic verifier-guided transform rollback.
    #[arg(long)]
    no_rollback: bool,

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
    },
}

fn main() -> Result<()> {
    let cli = Cli::parse();

    // Discover available kinsn targets from exported BTF kinsn stubs.
    let discovery = kfunc_discovery::discover_kinsns();
    eprintln!("kinsn discovery:");
    for line in &discovery.log {
        eprintln!("{}", line);
    }
    let platform = pass::PlatformCapabilities::detect();
    eprintln!(
        "platform: arch={:?} bmi1={} bmi2={} cmov={} movbe={} rorx={}",
        platform.arch,
        platform.has_bmi1,
        platform.has_bmi2,
        platform.has_cmov,
        platform.has_movbe,
        platform.has_rorx,
    );
    let ctx = pass::PassContext {
        kinsn_registry: discovery.registry,
        platform,
        policy: pass::PolicyConfig {
            enabled_passes: pass::default_enabled_passes(),
            ..pass::PolicyConfig::default()
        },
        prog_type: 0,
    };
    // Keep descriptor BTF FDs alive for the daemon's lifetime.
    let _btf_fds = discovery.btf_fds;
    let pgo_config = if cli.pgo {
        Some(PgoConfig {
            interval: Duration::from_millis(cli.pgo_interval_ms),
        })
    } else {
        None
    };

    match cli.command {
        Command::Serve { socket } => {
            server::cmd_serve(&socket, &ctx, pgo_config.as_ref(), !cli.no_rollback)
        }
    }
}
