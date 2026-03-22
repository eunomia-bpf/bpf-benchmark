// SPDX-License-Identifier: MIT
//! bpfrejit-daemon — BpfReJIT userspace daemon (Rust POC).
//!
//! Scans live kernel BPF programs for optimization sites and can apply
//! bytecode rewrites via BPF_PROG_REJIT.

mod analysis;
mod bpf;
mod emit;
mod insn;
mod matcher;
mod pass;
mod passes;
mod profiler;
mod rewriter;

use std::collections::HashSet;
use std::os::unix::io::AsRawFd;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::Duration;

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
    match cli.command {
        Command::Enumerate => cmd_enumerate(),
        Command::Rewrite { prog_id } => cmd_rewrite(prog_id),
        Command::Apply { prog_id } => cmd_apply(prog_id),
        Command::ApplyAll => cmd_apply_all(),
        Command::Profile {
            prog_id,
            interval_ms,
            samples,
        } => cmd_profile(prog_id, interval_ms, samples),
        Command::Watch { interval, once } => cmd_watch(interval, once),
    }
}

// ── Subcommand implementations ──────────────────────────────────────

fn cmd_enumerate() -> Result<()> {
    println!(
        "{:>6}  {:>6}  {:>5}  {:<16}  sites",
        "ID", "type", "insns", "name"
    );
    println!("{}", "-".repeat(60));

    for prog_id in bpf::iter_prog_ids() {
        match enumerate_one(prog_id) {
            Ok(()) => {}
            Err(e) => {
                eprintln!("  prog {}: {:#}", prog_id, e);
            }
        }
    }
    Ok(())
}

fn enumerate_one(prog_id: u32) -> Result<()> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    let name = info.name_str();
    let insn_count = if !orig_insns.is_empty() {
        orig_insns.len()
    } else {
        info.orig_prog_len as usize / 8 // orig_prog_len is in bytes
    };

    let sites = if !orig_insns.is_empty() {
        matcher::scan_all(&orig_insns)
    } else {
        Vec::new()
    };

    let site_summary = if sites.is_empty() {
        "-".to_string()
    } else {
        let wide_count = sites
            .iter()
            .filter(|s| s.family == matcher::Family::WideMem)
            .count();
        format!("wide_mem={}", wide_count)
    };

    println!(
        "{:>6}  {:>6}  {:>5}  {:<16}  {}",
        prog_id, info.prog_type, insn_count, name, site_summary,
    );

    Ok(())
}

fn cmd_rewrite(prog_id: u32) -> Result<()> {
    let (info, orig_insns) = bpf::get_orig_insns_by_id(prog_id)?;

    if orig_insns.is_empty() {
        println!(
            "prog {}: no original instructions available (orig_prog_len={})",
            prog_id, info.orig_prog_len
        );
        return Ok(());
    }

    println!(
        "prog {} ({:?}): {} original instructions",
        prog_id,
        info.name_str(),
        orig_insns.len()
    );

    let sites = matcher::scan_all(&orig_insns);
    println!("  found {} rewrite sites", sites.len());
    for site in &sites {
        println!(
            "    pc={} len={} family={} bindings={:?}",
            site.start_pc, site.old_len, site.family, site.bindings
        );
    }

    if sites.is_empty() {
        println!("  nothing to rewrite");
        return Ok(());
    }

    let result = rewriter::rewrite(&orig_insns, &sites).context("rewrite failed")?;

    println!(
        "  rewrite: {} insns -> {} insns ({} sites applied)",
        orig_insns.len(),
        result.new_insns.len(),
        result.sites_applied
    );

    // Print new instructions for inspection.
    for (i, insn) in result.new_insns.iter().enumerate() {
        println!("    [{:>4}] {}", i, insn);
    }

    Ok(())
}

fn cmd_apply(prog_id: u32) -> Result<()> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id).context("open program")?;
    let (info, orig_insns) =
        bpf::bpf_prog_get_info(fd.as_raw_fd(), true).context("get program info")?;

    if orig_insns.is_empty() {
        println!("prog {}: no original instructions available", prog_id);
        return Ok(());
    }

    // Build PassManager pipeline and run
    let pm = passes::build_default_pipeline();
    let ctx = pass::PassContext::test_default();

    let meta = pass::ProgMeta {
        prog_id: info.id,
        prog_type: info.prog_type,
        prog_name: info.name_str().to_string(),
        run_cnt: info.run_cnt,
        run_time_ns: info.run_time_ns,
        ..Default::default()
    };
    let mut program = pass::BpfProgram::new(orig_insns.clone(), meta);

    let pipeline_result = pm.run(&mut program, &ctx)?;

    if !pipeline_result.program_changed {
        println!(
            "prog {} ({}): no transforms applied",
            prog_id,
            info.name_str()
        );
        return Ok(());
    }

    println!(
        "prog {} ({}): {} passes, {} sites applied ({} -> {} insns)",
        prog_id,
        info.name_str(),
        pipeline_result.pass_results.len(),
        pipeline_result.total_sites_applied,
        orig_insns.len(),
        program.insns.len(),
    );

    for pr in &pipeline_result.pass_results {
        if pr.sites_applied > 0 {
            println!("  {}: {} sites applied", pr.pass_name, pr.sites_applied);
        }
    }

    bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &[]).context("BPF_PROG_REJIT failed")?;

    println!("  REJIT successful");
    Ok(())
}

fn cmd_apply_all() -> Result<()> {
    let mut total = 0u32;
    let mut applied = 0u32;
    let mut errors = 0u32;

    for prog_id in bpf::iter_prog_ids() {
        total += 1;
        match try_apply_one(prog_id) {
            Ok(true) => applied += 1,
            Ok(false) => {}
            Err(e) => {
                eprintln!("  prog {}: {:#}", prog_id, e);
                errors += 1;
            }
        }
    }

    println!(
        "\napply-all: scanned {} programs, applied {}, errors {}",
        total, applied, errors
    );
    Ok(())
}

fn cmd_profile(prog_id: u32, interval_ms: u64, samples: usize) -> Result<()> {
    if !profiler::bpf_stats_enabled()? {
        anyhow::bail!(
            "kernel.bpf_stats_enabled=0; enable it first, e.g. `sudo sysctl kernel.bpf_stats_enabled=1`"
        );
    }

    let interval = Duration::from_millis(interval_ms);
    let mut poller = profiler::ProgStatsPoller::open(prog_id)?;
    let baseline = poller.snapshot()?;

    println!(
        "prog {} baseline: run_cnt={} run_time_ns={} avg_ns={}",
        prog_id,
        baseline.stats.run_cnt,
        baseline.stats.run_time_ns,
        fmt_avg(baseline.stats.avg_ns),
    );
    println!(
        "{:>6}  {:>10}  {:>14}  {:>14}  {:>12}",
        "sample", "elapsed_ms", "delta_run_cnt", "delta_time_ns", "delta_avg_ns"
    );
    println!("{}", "-".repeat(68));

    poller.poll_delta()?;
    for (index, delta) in poller.collect_deltas(interval, samples)?.iter().enumerate() {
        let pgo = profiler::PgoAnalysis::from_delta(delta);
        println!(
            "{:>6}  {:>10.3}  {:>14}  {:>14}  {:>12}",
            index + 1,
            delta.elapsed.as_secs_f64() * 1000.0,
            pgo.delta_run_cnt,
            pgo.delta_run_time_ns,
            fmt_avg(pgo.delta_avg_ns),
        );
    }

    let final_stats = poller.poll_stats()?;
    println!(
        "final totals: run_cnt={} run_time_ns={} avg_ns={}",
        final_stats.run_cnt,
        final_stats.run_time_ns,
        fmt_avg(final_stats.avg_ns),
    );

    Ok(())
}

/// Try to apply rewrites to a single program via PassManager. Returns true if REJIT was called.
fn try_apply_one(prog_id: u32) -> Result<bool> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    if orig_insns.is_empty() {
        return Ok(false);
    }

    let pm = passes::build_default_pipeline();
    let ctx = pass::PassContext::test_default();

    let meta = pass::ProgMeta {
        prog_id: info.id,
        prog_type: info.prog_type,
        prog_name: info.name_str().to_string(),
        run_cnt: info.run_cnt,
        run_time_ns: info.run_time_ns,
        ..Default::default()
    };
    let mut program = pass::BpfProgram::new(orig_insns.clone(), meta);

    let pipeline_result = pm.run(&mut program, &ctx)?;

    if !pipeline_result.program_changed {
        return Ok(false);
    }

    println!(
        "  prog {} ({}): {} sites, {} -> {} insns",
        prog_id,
        info.name_str(),
        pipeline_result.total_sites_applied,
        orig_insns.len(),
        program.insns.len(),
    );

    bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &[])?;
    println!("    REJIT ok");
    Ok(true)
}

fn cmd_watch(interval_secs: u64, once: bool) -> Result<()> {
    // Register signal handlers for graceful shutdown.
    unsafe {
        libc::signal(libc::SIGTERM, handle_signal as libc::sighandler_t);
        libc::signal(libc::SIGINT, handle_signal as libc::sighandler_t);
    }

    // Set of prog IDs that have already been attempted in this session.
    let mut optimized: HashSet<u32> = HashSet::new();
    let mut round: u32 = 0;

    println!(
        "watch: starting (interval={}s, once={})",
        interval_secs, once
    );

    loop {
        if SHUTDOWN_FLAG.load(Ordering::Relaxed) {
            println!("watch: received shutdown signal, exiting");
            break;
        }

        round += 1;
        let ids: Vec<u32> = bpf::iter_prog_ids().collect();
        let total = ids.len();

        // Find newly seen prog IDs (not yet attempted).
        let new_ids: Vec<u32> = ids
            .iter()
            .copied()
            .filter(|id| !optimized.contains(id))
            .collect();
        let new_count = new_ids.len();

        let mut applied = 0u32;
        let mut errors = 0u32;
        for prog_id in &new_ids {
            // Mark as seen regardless of outcome so we don't retry transient failures
            // infinitely.  The program may have exited by the time we reach it.
            optimized.insert(*prog_id);
            match try_apply_one(*prog_id) {
                Ok(true) => applied += 1,
                Ok(false) => {}
                Err(e) => {
                    eprintln!("  watch: prog {}: {:#}", prog_id, e);
                    errors += 1;
                }
            }
        }

        println!(
            "watch round {}: scanned {} progs, {} new, {} optimized, {} errors",
            round, total, new_count, applied, errors
        );

        if once {
            break;
        }

        // Sleep in small chunks so we can react to SIGINT promptly.
        let steps = interval_secs.max(1) * 10; // 100 ms slices
        for _ in 0..steps {
            if SHUTDOWN_FLAG.load(Ordering::Relaxed) {
                break;
            }
            std::thread::sleep(Duration::from_millis(100));
        }

        if SHUTDOWN_FLAG.load(Ordering::Relaxed) {
            println!("watch: received shutdown signal, exiting");
            break;
        }
    }

    Ok(())
}

/// Global shutdown flag set by signal handler.
static SHUTDOWN_FLAG: AtomicBool = AtomicBool::new(false);

extern "C" fn handle_signal(_sig: libc::c_int) {
    SHUTDOWN_FLAG.store(true, Ordering::Relaxed);
}

fn fmt_avg(value: Option<f64>) -> String {
    match value {
        Some(avg) => format!("{avg:.2}"),
        None => "-".to_string(),
    }
}
