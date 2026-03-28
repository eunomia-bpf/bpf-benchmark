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
    /// List all available passes and exit.
    ListPasses,

    /// List all live BPF programs and scan for optimization sites.
    Enumerate,

    /// Fetch bytecode for a program, rewrite it, and print the result (dry-run).
    Rewrite {
        /// BPF program ID.
        #[arg(value_name = "PROG_ID")]
        prog_id: u32,
    },

    /// Fetch bytecode, rewrite, and apply via BPF_PROG_REJIT.
    Apply {
        /// BPF program ID.
        #[arg(value_name = "PROG_ID")]
        prog_id: u32,

        /// Disable automatic verifier-guided transform rollback.
        #[arg(long)]
        no_rollback: bool,
    },

    /// Apply rewrites to all live BPF programs that have optimization sites.
    ApplyAll {
        /// Disable automatic verifier-guided transform rollback.
        #[arg(long)]
        no_rollback: bool,
    },

    /// Continuously watch for new BPF programs and apply rewrites (daemon mode).
    Watch {
        /// Polling interval in seconds.
        #[arg(long, default_value_t = 5)]
        interval: u64,

        /// Run only one scan round then exit (useful for testing).
        #[arg(long)]
        once: bool,

        /// Disable automatic verifier-guided transform rollback.
        #[arg(long)]
        no_rollback: bool,
    },

    /// Run as a Unix socket server (persistent daemon mode).
    Serve {
        /// Unix socket path.
        #[arg(long, default_value = "/var/run/bpfrejit.sock")]
        socket: String,

        /// Disable automatic verifier-guided transform rollback.
        #[arg(long)]
        no_rollback: bool,
    },

    /// Poll runtime BPF stats for one live program.
    Profile {
        /// BPF program ID.
        #[arg(value_name = "PROG_ID")]
        prog_id: u32,

        /// Poll interval in milliseconds.
        #[arg(long, default_value_t = 1000)]
        interval_ms: u64,

        /// Number of delta samples to collect.
        #[arg(long, default_value_t = 5)]
        samples: usize,
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

    match cli.command {
        Command::ListPasses => {
            println!("Available passes (in canonical pipeline order):\n");
            println!("{}", passes::available_passes_help());
            Ok(())
        }
        Command::Enumerate => commands::cmd_enumerate(&ctx),
        Command::Rewrite { prog_id } => commands::cmd_rewrite(prog_id, &ctx),
        Command::Apply {
            prog_id,
            no_rollback,
        } => commands::cmd_apply(prog_id, &ctx, !no_rollback),
        Command::ApplyAll { no_rollback } => commands::cmd_apply_all(&ctx, !no_rollback),
        Command::Serve {
            socket,
            no_rollback,
        } => server::cmd_serve(&socket, &ctx, !no_rollback),
        Command::Profile {
            prog_id,
            interval_ms,
            samples,
        } => commands::cmd_profile(prog_id, interval_ms, samples),
        Command::Watch {
            interval,
            once,
            no_rollback,
        } => server::cmd_watch(interval, once, &ctx, !no_rollback),
    }
}
