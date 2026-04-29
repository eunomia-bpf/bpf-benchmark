// SPDX-License-Identifier: MIT
//! bpfrejit-daemon — BpfReJIT userspace daemon.
//!
//! Scans live kernel BPF programs for optimization sites and can apply
//! bytecode rewrites via BPF_PROG_REJIT.

mod bpf;
mod commands;
mod invalidation;
mod server;

use anyhow::{Context, Result};
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
        /// Cross-program worker threads for optimize-all and invalidation reapply.
        #[arg(long, env = "BPFREJIT_DAEMON_JOBS", value_parser = parse_jobs)]
        jobs: Option<usize>,
    },
}

fn parse_jobs(value: &str) -> std::result::Result<usize, String> {
    let jobs = value
        .parse::<usize>()
        .map_err(|err| format!("jobs must be a positive integer: {err}"))?;
    if jobs == 0 {
        return Err("jobs must be greater than zero".to_string());
    }
    Ok(jobs)
}

fn default_jobs() -> Result<usize> {
    std::thread::available_parallelism()
        .context("detect default daemon job count from available parallelism")
        .map(std::num::NonZeroUsize::get)
}

fn initialize_worker_pool(jobs: usize) -> Result<()> {
    rayon::ThreadPoolBuilder::new()
        .num_threads(jobs)
        .build_global()
        .context("initialize daemon rayon thread pool")
}

fn main() -> Result<()> {
    let cli = Cli::parse();

    match cli.command {
        Command::Serve { socket, jobs } => {
            let jobs = match jobs {
                Some(jobs) => jobs,
                None => default_jobs()?,
            };
            initialize_worker_pool(jobs)?;
            eprintln!("serve: using {jobs} cross-program worker threads");
            server::cmd_serve(&socket)
        }
    }
}
