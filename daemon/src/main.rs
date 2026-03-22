// SPDX-License-Identifier: MIT
//! bpfrejit-daemon — BpfReJIT userspace daemon.
//!
//! Scans live kernel BPF programs for optimization sites and can apply
//! bytecode rewrites via BPF_PROG_REJIT.

mod analysis;
mod bpf;
mod insn;
mod kfunc_discovery;
mod pass;
mod passes;
mod profiler;
#[allow(dead_code)]
mod verifier_log;

use std::collections::HashSet;
use std::os::unix::io::AsRawFd;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::Duration;

use anyhow::{Context, Result};
use clap::{Parser, Subcommand};

#[derive(Parser)]
#[command(name = "bpfrejit-daemon", version, about = "BpfReJIT userspace daemon")]
struct Cli {
    /// Comma-separated list of passes to run (default: all optimization passes).
    /// Available: wide_mem, rotate, cond_select, extract, branch_flip, speculation_barrier.
    /// Example: --passes speculation_barrier
    #[arg(long, value_delimiter = ',')]
    passes: Option<Vec<String>>,

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

    // Discover available kinsn kfuncs from loaded kernel modules.
    let discovery = kfunc_discovery::discover_kfuncs();
    eprintln!("kfunc discovery:");
    for line in &discovery.log {
        eprintln!("{}", line);
    }
    let ctx = pass::PassContext {
        kfunc_registry: discovery.registry,
        platform: pass::PlatformCapabilities::default(),
        policy: pass::PolicyConfig::default(),
    };
    // Keep module FDs alive for the daemon's lifetime.
    let _module_fds = discovery.module_fds;

    // Determine which passes to use.
    let pass_names = cli.passes;
    let pgo_config = if cli.pgo {
        Some(PgoConfig {
            interval: Duration::from_millis(cli.pgo_interval_ms),
        })
    } else {
        None
    };

    match cli.command {
        Command::Enumerate => cmd_enumerate(&ctx, &pass_names),
        Command::Rewrite { prog_id } => cmd_rewrite(prog_id, &ctx, &pass_names),
        Command::Apply { prog_id } => cmd_apply(prog_id, &ctx, &pass_names, &pgo_config),
        Command::ApplyAll => cmd_apply_all(&ctx, &pass_names, &pgo_config),
        Command::Serve { socket } => cmd_serve(&socket, &ctx, &pass_names, &pgo_config),
        Command::Profile {
            prog_id,
            interval_ms,
            samples,
        } => cmd_profile(prog_id, interval_ms, samples),
        Command::Watch { interval, once } => cmd_watch(interval, once, &ctx, &pass_names, &pgo_config),
    }
}

/// PGO configuration passed through CLI flags.
struct PgoConfig {
    /// Observation interval for profiling.
    interval: Duration,
}

/// Collect profiling data for a program if PGO is enabled.
///
/// When PGO is enabled, polls the program's runtime stats for the configured
/// interval and returns a `ProfilingData` with program-level hotness information.
fn collect_pgo_data(prog_id: u32, pgo_config: &Option<PgoConfig>) -> Option<pass::ProfilingData> {
    let config = pgo_config.as_ref()?;
    match profiler::collect_program_profiling(prog_id, config.interval) {
        Ok((profiling, analysis)) => {
            if analysis.is_hot() {
                eprintln!(
                    "  pgo: prog {} is hot (delta_run_cnt={}, avg_ns={})",
                    prog_id,
                    analysis.delta_run_cnt,
                    analysis
                        .delta_avg_ns
                        .map_or("-".to_string(), |v| format!("{:.2}", v)),
                );
            } else {
                eprintln!("  pgo: prog {} is cold (no activity during observation)", prog_id);
            }
            Some(profiling)
        }
        Err(e) => {
            eprintln!("  pgo: failed to profile prog {}: {:#}", prog_id, e);
            None
        }
    }
}

/// Build the appropriate pipeline based on --passes flag.
fn build_pipeline(pass_names: &Option<Vec<String>>) -> pass::PassManager {
    match pass_names {
        Some(names) if !names.is_empty() => passes::build_pipeline_with_passes(names),
        _ => passes::build_default_pipeline(),
    }
}

// ── Subcommand implementations ──────────────────────────────────────

fn cmd_enumerate(ctx: &pass::PassContext, pass_names: &Option<Vec<String>>) -> Result<()> {
    println!(
        "{:>6}  {:>6}  {:>5}  {:<16}  sites",
        "ID", "type", "insns", "name"
    );
    println!("{}", "-".repeat(60));

    for prog_id in bpf::iter_prog_ids() {
        match enumerate_one(prog_id, ctx, pass_names) {
            Ok(()) => {}
            Err(e) => {
                eprintln!("  prog {}: {:#}", prog_id, e);
            }
        }
    }
    Ok(())
}

fn enumerate_one(prog_id: u32, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>) -> Result<()> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    let name = info.name_str();
    let insn_count = if !orig_insns.is_empty() {
        orig_insns.len()
    } else {
        info.orig_prog_len as usize / 8
    };

    // Run the pipeline in dry-run mode to count sites.
    let site_summary = if !orig_insns.is_empty() {
        let meta = pass::ProgMeta {
            prog_id: info.id,
            prog_type: info.prog_type,
            prog_name: info.name_str().to_string(),
            run_cnt: info.run_cnt,
            run_time_ns: info.run_time_ns,
            ..Default::default()
        };
        let mut program = pass::BpfProgram::new(orig_insns, meta);
        let pm = build_pipeline(pass_names);

        match pm.run(&mut program, ctx) {
            Ok(result) if result.total_sites_applied > 0 => {
                let parts: Vec<String> = result
                    .pass_results
                    .iter()
                    .filter(|pr| pr.sites_applied > 0)
                    .map(|pr| format!("{}={}", pr.pass_name, pr.sites_applied))
                    .collect();
                parts.join(" ")
            }
            _ => "-".to_string(),
        }
    } else {
        "-".to_string()
    };

    println!(
        "{:>6}  {:>6}  {:>5}  {:<16}  {}",
        prog_id, info.prog_type, insn_count, name, site_summary,
    );

    Ok(())
}

fn cmd_rewrite(prog_id: u32, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>) -> Result<()> {
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

    let meta = pass::ProgMeta {
        prog_id: info.id,
        prog_type: info.prog_type,
        prog_name: info.name_str().to_string(),
        run_cnt: info.run_cnt,
        run_time_ns: info.run_time_ns,
        ..Default::default()
    };
    let mut program = pass::BpfProgram::new(orig_insns.clone(), meta);
    let pm = build_pipeline(pass_names);

    let pipeline_result = pm.run(&mut program, ctx)?;

    for pr in &pipeline_result.pass_results {
        if pr.sites_applied > 0 {
            println!("  {}: {} sites applied", pr.pass_name, pr.sites_applied);
        }
        for skip in &pr.sites_skipped {
            println!("    skip pc={}: {}", skip.pc, skip.reason);
        }
    }

    if !pipeline_result.program_changed {
        println!("  nothing to rewrite");
        return Ok(());
    }

    println!(
        "  rewrite: {} insns -> {} insns ({} sites applied)",
        orig_insns.len(),
        program.insns.len(),
        pipeline_result.total_sites_applied
    );

    // Print new instructions for inspection.
    for (i, insn) in program.insns.iter().enumerate() {
        println!("    [{:>4}] {}", i, insn);
    }

    Ok(())
}

fn cmd_apply(prog_id: u32, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>) -> Result<()> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id).context("open program")?;
    let (info, orig_insns) =
        bpf::bpf_prog_get_info(fd.as_raw_fd(), true).context("get program info")?;

    if orig_insns.is_empty() {
        println!("prog {}: no original instructions available", prog_id);
        return Ok(());
    }

    let pm = build_pipeline(pass_names);

    let meta = pass::ProgMeta {
        prog_id: info.id,
        prog_type: info.prog_type,
        prog_name: info.name_str().to_string(),
        run_cnt: info.run_cnt,
        run_time_ns: info.run_time_ns,
        ..Default::default()
    };
    let mut program = pass::BpfProgram::new(orig_insns.clone(), meta);

    // Collect PGO data if enabled, then run pipeline with profiling.
    let profiling = collect_pgo_data(prog_id, pgo_config);
    let pipeline_result = pm.run_with_profiling(&mut program, ctx, profiling.as_ref())?;

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

    // Construct fd_array from module FDs required by kfunc passes.
    let fd_array: Vec<std::os::unix::io::RawFd> = program.required_module_fds.clone();
    bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &fd_array).context("BPF_PROG_REJIT failed")?;

    println!("  REJIT successful");
    Ok(())
}

fn cmd_apply_all(ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>) -> Result<()> {
    let mut total = 0u32;
    let mut applied = 0u32;
    let mut errors = 0u32;

    for prog_id in bpf::iter_prog_ids() {
        total += 1;
        match try_apply_one(prog_id, ctx, pass_names, pgo_config) {
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
fn try_apply_one(prog_id: u32, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>) -> Result<bool> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    if orig_insns.is_empty() {
        return Ok(false);
    }

    let pm = build_pipeline(pass_names);

    let meta = pass::ProgMeta {
        prog_id: info.id,
        prog_type: info.prog_type,
        prog_name: info.name_str().to_string(),
        run_cnt: info.run_cnt,
        run_time_ns: info.run_time_ns,
        ..Default::default()
    };
    let mut program = pass::BpfProgram::new(orig_insns.clone(), meta);

    // Collect PGO data if enabled, then run pipeline with profiling.
    let profiling = collect_pgo_data(prog_id, pgo_config);
    let pipeline_result = pm.run_with_profiling(&mut program, ctx, profiling.as_ref())?;

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

    let fd_array: Vec<std::os::unix::io::RawFd> = program.required_module_fds.clone();
    bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &fd_array)?;
    println!("    REJIT ok");
    Ok(true)
}

// ── Serve (Unix socket server) ──────────────────────────────────────

fn cmd_serve(socket_path: &str, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>) -> Result<()> {
    use std::os::unix::net::UnixListener;

    // Register signal handlers for graceful shutdown.
    unsafe {
        libc::signal(libc::SIGTERM, handle_signal as libc::sighandler_t);
        libc::signal(libc::SIGINT, handle_signal as libc::sighandler_t);
    }

    // Remove stale socket file if it exists.
    let _ = std::fs::remove_file(socket_path);

    let listener = UnixListener::bind(socket_path)
        .with_context(|| format!("bind unix socket at {}", socket_path))?;
    listener.set_nonblocking(true)?;

    println!("serve: listening on {}", socket_path);

    while !SHUTDOWN_FLAG.load(Ordering::Relaxed) {
        match listener.accept() {
            Ok((stream, _addr)) => {
                let _ = handle_client(stream, ctx, pass_names, pgo_config);
            }
            Err(ref e) if e.kind() == std::io::ErrorKind::WouldBlock => {
                std::thread::sleep(Duration::from_millis(100));
                continue;
            }
            Err(e) => {
                eprintln!("serve: accept error: {}", e);
            }
        }
    }

    println!("serve: shutting down");
    let _ = std::fs::remove_file(socket_path);
    Ok(())
}

fn handle_client(
    stream: std::os::unix::net::UnixStream,
    ctx: &pass::PassContext,
    pass_names: &Option<Vec<String>>,
    pgo_config: &Option<PgoConfig>,
) -> Result<()> {
    use std::io::{BufRead, BufReader, Write};

    let reader = BufReader::new(&stream);
    let mut writer = &stream;

    for line in reader.lines() {
        let line = line?;
        if line.is_empty() {
            continue;
        }

        let response = match serde_json::from_str::<serde_json::Value>(&line) {
            Ok(req) => process_request(&req, ctx, pass_names, pgo_config),
            Err(e) => serde_json::json!({"status": "error", "message": format!("invalid JSON: {}", e)}),
        };

        let mut resp_str = serde_json::to_string(&response)?;
        resp_str.push('\n');
        writer.write_all(resp_str.as_bytes())?;
        writer.flush()?;
    }

    Ok(())
}

fn process_request(
    req: &serde_json::Value,
    ctx: &pass::PassContext,
    pass_names: &Option<Vec<String>>,
    pgo_config: &Option<PgoConfig>,
) -> serde_json::Value {
    let cmd = req.get("cmd").and_then(|v| v.as_str()).unwrap_or("");
    match cmd {
        "optimize" => {
            let prog_id = match req.get("prog_id").and_then(|v| v.as_u64()) {
                Some(id) => id as u32,
                None => return serde_json::json!({"status": "error", "message": "missing prog_id"}),
            };
            match try_apply_one(prog_id, ctx, pass_names, pgo_config) {
                Ok(true) => serde_json::json!({"status": "ok", "applied": true}),
                Ok(false) => serde_json::json!({"status": "ok", "applied": false}),
                Err(e) => serde_json::json!({"status": "error", "message": format!("{:#}", e)}),
            }
        }
        "optimize-all" => {
            let mut applied = 0u32;
            let mut errors = 0u32;
            let mut total = 0u32;
            for prog_id in bpf::iter_prog_ids() {
                total += 1;
                match try_apply_one(prog_id, ctx, pass_names, pgo_config) {
                    Ok(true) => applied += 1,
                    Ok(false) => {}
                    Err(_) => errors += 1,
                }
            }
            serde_json::json!({"status": "ok", "total": total, "applied": applied, "errors": errors})
        }
        "status" => {
            serde_json::json!({"status": "ok", "version": env!("CARGO_PKG_VERSION")})
        }
        _ => {
            serde_json::json!({"status": "error", "message": format!("unknown command: {}", cmd)})
        }
    }
}

fn cmd_watch(interval_secs: u64, once: bool, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>) -> Result<()> {
    // Register signal handlers for graceful shutdown.
    unsafe {
        libc::signal(libc::SIGTERM, handle_signal as libc::sighandler_t);
        libc::signal(libc::SIGINT, handle_signal as libc::sighandler_t);
    }

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

        let new_ids: Vec<u32> = ids
            .iter()
            .copied()
            .filter(|id| !optimized.contains(id))
            .collect();
        let new_count = new_ids.len();

        let mut applied = 0u32;
        let mut errors = 0u32;
        for prog_id in &new_ids {
            optimized.insert(*prog_id);
            match try_apply_one(*prog_id, ctx, pass_names, pgo_config) {
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

        let steps = interval_secs.max(1) * 10;
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
