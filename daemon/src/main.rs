// SPDX-License-Identifier: MIT
//! bpfrejit-daemon — BpfReJIT userspace daemon.
//!
//! Scans live kernel BPF programs for optimization sites and can apply
//! bytecode rewrites via BPF_PROG_REJIT.

mod analysis;
mod bpf;
mod commands;
mod insn;
mod invalidation;
mod kfunc_discovery;
mod pass;
mod passes;
mod profiler;
mod server;
mod verifier_log;

use std::time::Duration;

use anyhow::Result;
use clap::{Parser, Subcommand};

use commands::PgoConfig;

#[derive(Parser)]
#[command(name = "bpfrejit-daemon", version, about = "BpfReJIT userspace daemon")]
struct Cli {
    /// Comma-separated list of passes to run (default: all optimization passes).
    /// Use --list-passes to see available passes.
    /// Example: --passes speculation_barrier
    #[arg(long, value_delimiter = ',')]
    passes: Option<Vec<String>>,

    /// List all available passes and exit.
    #[arg(long)]
    list_passes: bool,

    /// Disable automatic verifier-guided transform rollback.
    ///
    /// By default, when REJIT fails due to verifier rejection, the daemon
    /// attempts to identify the responsible pass, disables it, and retries.
    /// Use this flag to disable that behavior (fail immediately on rejection).
    #[arg(long)]
    no_rollback: bool,

    /// Enable PGO (Profile-Guided Optimization).
    ///
    /// When set, the daemon polls program runtime stats before optimization
    /// to collect profiling data. This enables PGO-guided passes like
    /// branch_flip to make data-driven decisions.
    #[arg(long)]
    pgo: bool,

    /// PGO profiling observation interval in milliseconds.
    ///
    /// How long to observe program runtime stats before making optimization
    /// decisions. Only used when --pgo is enabled.
    #[arg(long, default_value_t = 500)]
    pgo_interval_ms: u64,

    #[command(subcommand)]
    command: Command,
}

#[derive(Subcommand)]
enum Command {
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
    },

    /// Apply rewrites to all live BPF programs that have optimization sites.
    ApplyAll,

    /// Continuously watch for new BPF programs and apply rewrites (daemon mode).
    Watch {
        /// Polling interval in seconds.
        #[arg(long, default_value_t = 5)]
        interval: u64,

        /// Run only one scan round then exit (useful for testing).
        #[arg(long)]
        once: bool,
    },

    /// Run as a Unix socket server (persistent daemon mode).
    Serve {
        /// Unix socket path.
        #[arg(long, default_value = "/var/run/bpfrejit.sock")]
        socket: String,
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

    if cli.list_passes {
        println!("Available passes (in canonical pipeline order):\n");
        println!("{}", passes::available_passes_help());
        return Ok(());
    }

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
        policy: pass::PolicyConfig::default(),
        prog_type: 0,
    };
    // Keep descriptor BTF FDs alive for the daemon's lifetime.
    let _btf_fds = discovery.btf_fds;

    // Determine which passes to use.
    let pass_names = cli.passes;
    let rollback_enabled = !cli.no_rollback;
    let pgo_config = if cli.pgo {
        Some(PgoConfig {
            interval: Duration::from_millis(cli.pgo_interval_ms),
        })
    } else {
        None
    };

    match cli.command {
        Command::Enumerate => commands::cmd_enumerate(&ctx, &pass_names),
        Command::Rewrite { prog_id } => commands::cmd_rewrite(prog_id, &ctx, &pass_names),
        Command::Apply { prog_id } => {
            commands::cmd_apply(prog_id, &ctx, &pass_names, &pgo_config, rollback_enabled)
        }
        Command::ApplyAll => {
            commands::cmd_apply_all(&ctx, &pass_names, &pgo_config, rollback_enabled)
        }
        Command::Serve { socket } => {
            server::cmd_serve(&socket, &ctx, &pass_names, &pgo_config, rollback_enabled)
        }
        Command::Profile {
            prog_id,
            interval_ms,
            samples,
        } => commands::cmd_profile(prog_id, interval_ms, samples),
        Command::Watch { interval, once } => server::cmd_watch(
            interval,
            once,
            &ctx,
            &pass_names,
            &pgo_config,
            rollback_enabled,
        ),
    }
}
