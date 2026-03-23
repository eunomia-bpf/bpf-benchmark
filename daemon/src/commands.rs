// SPDX-License-Identifier: MIT
//! Subcommand implementations: enumerate, rewrite, apply, apply-all, profile.

use std::collections::{HashMap, HashSet};
use std::os::unix::io::AsRawFd;
use std::time::{Duration, Instant};

use anyhow::{Context, Result};
use serde::Serialize;

use crate::{bpf, pass, passes, profiler, verifier_log};

// ── OptimizeOneResult — structured return from try_apply_one ────────

/// Structured result from a single optimize operation.
/// Serialized as JSON by the serve endpoint.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct OptimizeOneResult {
    pub status: String,
    pub program: ProgramInfo,
    pub summary: OptimizeSummary,
    pub passes: Vec<PassDetail>,
    pub attempts: Vec<AttemptRecord>,
    pub timings_ns: TimingsNs,
}

/// Program identity and size information.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct ProgramInfo {
    pub prog_id: u32,
    pub prog_name: String,
    pub prog_type: u32,
    pub orig_insn_count: usize,
    pub final_insn_count: usize,
    pub insn_delta: i64,
}

/// Top-level summary of the optimization outcome.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct OptimizeSummary {
    pub applied: bool,
    pub program_changed: bool,
    pub total_sites_applied: usize,
    pub passes_executed: usize,
    pub passes_changed: usize,
    pub verifier_retries: usize,
    pub final_disabled_passes: Vec<String>,
}

/// Per-pass detail record.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct PassDetail {
    pub pass_name: String,
    pub changed: bool,
    pub sites_applied: usize,
    pub sites_skipped: usize,
    pub skip_reasons: HashMap<String, usize>,
    pub insns_before: usize,
    pub insns_after: usize,
    pub insn_delta: i64,
    pub diagnostics: Vec<String>,
}

impl From<&pass::PassResult> for PassDetail {
    fn from(pr: &pass::PassResult) -> Self {
        Self {
            pass_name: pr.pass_name.clone(),
            changed: pr.changed,
            sites_applied: pr.sites_applied,
            sites_skipped: pr.sites_skipped.len(),
            skip_reasons: pr.skip_reason_counts(),
            insns_before: pr.insns_before,
            insns_after: pr.insns_after,
            insn_delta: pr.insns_after as i64 - pr.insns_before as i64,
            diagnostics: pr.diagnostics.clone(),
        }
    }
}

/// Record of a single REJIT attempt (for rollback history).
#[derive(Clone, Debug, Serialize)]
pub(crate) struct AttemptRecord {
    pub attempt: usize,
    pub disabled_passes: Vec<String>,
    pub result: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub failure_pc: Option<usize>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub attributed_pass: Option<String>,
}

/// Timing breakdown in nanoseconds.
#[derive(Clone, Debug, Serialize)]
pub(crate) struct TimingsNs {
    pub pipeline_run_ns: u64,
    pub rejit_syscall_ns: u64,
    pub total_ns: u64,
}

// ── PGO helpers ─────────────────────────────────────────────────────

/// PGO configuration passed through CLI flags.
pub(crate) struct PgoConfig {
    /// Observation interval for profiling.
    pub interval: Duration,
}

/// Collect profiling data for a program if PGO is enabled.
///
/// When PGO is enabled, polls the program's runtime stats for the configured
/// interval and returns a `ProfilingData` with program-level hotness information.
pub(crate) fn collect_pgo_data(prog_id: u32, pgo_config: &Option<PgoConfig>) -> Option<pass::ProfilingData> {
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

// ── Pipeline helpers ────────────────────────────────────────────────

/// Build the appropriate pipeline based on --passes flag.
pub(crate) fn build_pipeline(pass_names: &Option<Vec<String>>) -> pass::PassManager {
    match pass_names {
        Some(names) if !names.is_empty() => passes::build_pipeline_with_passes(names),
        _ => passes::build_default_pipeline(),
    }
}

/// Attribute a verifier failure to a specific pass using the pipeline's
/// transform attribution data and the verifier log.
///
/// Returns the name of the pass that likely caused the failure, or `None`
/// if the failure cannot be attributed.
fn attribute_verifier_failure(
    verifier_log_text: &str,
    attribution: &[pass::TransformAttribution],
) -> Option<String> {
    let failed_pc = verifier_log::extract_failure_pc(verifier_log_text)?;

    // Find the pass whose PC range contains the failure PC.
    // If multiple passes cover the same PC (conservative attribution), pick the
    // last one (most recently applied — most likely the cause).
    let mut candidate: Option<&str> = None;
    for attr in attribution {
        if attr.pc_range.contains(&failed_pc) {
            candidate = Some(&attr.pass_name);
        }
    }

    candidate.map(|s| s.to_string())
}

/// Rank program IDs by hotness using `HotnessRanking`.
///
/// Collects a quick stats snapshot for each program, builds a `HotnessRanking`,
/// and returns IDs sorted hottest-first. Programs whose stats cannot be read
/// are appended at the end (they'll still be processed).
pub(crate) fn rank_programs_by_hotness(prog_ids: &[u32], observation_window: Duration) -> Vec<u32> {
    use profiler::{HotnessRanking, PgoAnalysis, ProgStatsDelta, ProgStatsSnapshot};

    if prog_ids.is_empty() {
        return Vec::new();
    }

    // Collect before-snapshots for all programs.
    let mut snapshots_before: Vec<(u32, ProgStatsSnapshot)> = Vec::new();
    let mut unreadable: Vec<u32> = Vec::new();

    for &pid in prog_ids {
        match profiler::ProgStatsPoller::open(pid) {
            Ok(poller) => match poller.snapshot() {
                Ok(snap) => snapshots_before.push((pid, snap)),
                Err(_) => unreadable.push(pid),
            },
            Err(_) => unreadable.push(pid),
        }
    }

    // Brief sleep to observe activity.
    std::thread::sleep(observation_window);

    // Collect after-snapshots and compute analyses.
    let mut analyses: Vec<PgoAnalysis> = Vec::new();
    for (pid, before) in &snapshots_before {
        match profiler::ProgStatsPoller::open(*pid) {
            Ok(poller) => match poller.snapshot() {
                Ok(after) => {
                    let delta = ProgStatsDelta::from_snapshots(before, &after);
                    analyses.push(PgoAnalysis::from_delta(&delta));
                }
                Err(_) => unreadable.push(*pid),
            },
            Err(_) => unreadable.push(*pid),
        }
    }

    let ranking = HotnessRanking::from_analyses(analyses, observation_window);

    // Return IDs in hotness order, then append unreadable ones.
    let mut result: Vec<u32> = ranking.ranked.iter().map(|a| a.prog_id).collect();
    result.extend(unreadable);
    result
}

// ── Subcommand implementations ──────────────────────────────────────

pub(crate) fn cmd_enumerate(ctx: &pass::PassContext, pass_names: &Option<Vec<String>>) -> Result<()> {
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

pub(crate) fn cmd_rewrite(prog_id: u32, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>) -> Result<()> {
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

pub(crate) fn cmd_apply(prog_id: u32, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>, rollback_enabled: bool) -> Result<()> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id).context("open program")?;
    let (info, orig_insns) =
        bpf::bpf_prog_get_info(fd.as_raw_fd(), true).context("get program info")?;

    if orig_insns.is_empty() {
        println!("prog {}: no original instructions available", prog_id);
        return Ok(());
    }

    // Fetch map IDs for FD relocation before REJIT.
    let map_ids = bpf::bpf_prog_get_map_ids(fd.as_raw_fd()).unwrap_or_default();

    // Collect PGO data once (reused across rollback retries).
    let profiling = collect_pgo_data(prog_id, pgo_config);

    let meta = pass::ProgMeta {
        prog_id: info.id,
        prog_type: info.prog_type,
        prog_name: info.name_str().to_string(),
        run_cnt: info.run_cnt,
        run_time_ns: info.run_time_ns,
        ..Default::default()
    };

    // Rollback loop: on verifier rejection, attribute the failure to a pass,
    // disable it, and retry with the remaining passes.
    let mut disabled_passes: HashSet<String> = HashSet::new();
    let max_retries = 10; // safety bound

    for attempt in 0..=max_retries {
        // Build a fresh program from the original instructions each time.
        let mut program = pass::BpfProgram::new(orig_insns.clone(), meta.clone());

        // Build pipeline with disabled passes applied via policy.
        let pm = build_pipeline(pass_names);
        let mut local_ctx = ctx.clone();
        for disabled in &disabled_passes {
            local_ctx.policy.disabled_passes.push(disabled.clone());
        }

        let pipeline_result = pm.run_with_profiling(&mut program, &local_ctx, profiling.as_ref())?;

        if !pipeline_result.program_changed {
            if attempt == 0 {
                println!(
                    "prog {} ({}): no transforms applied",
                    prog_id,
                    info.name_str()
                );
            } else {
                println!(
                    "prog {} ({}): no transforms remain after disabling {} passes",
                    prog_id,
                    info.name_str(),
                    disabled_passes.len()
                );
            }
            return Ok(());
        }

        if attempt == 0 {
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
        }

        // Relocate stale map FDs in the rewritten bytecode.
        // The original bytecode contains FDs from the loading process which are
        // invalid in the daemon's process context.
        let _map_fds_guard = bpf::relocate_map_fds(&mut program.insns, &map_ids)
            .unwrap_or_else(|e| {
                eprintln!("  warning: map FD relocation failed: {:#}", e);
                Vec::new()
            });

        // Construct fd_array from module FDs required by kfunc passes.
        let fd_array: Vec<std::os::unix::io::RawFd> = program.required_module_fds.clone();
        let all_fds = local_ctx.kfunc_registry.all_module_fds();
        for &fd_needed in &fd_array {
            if !all_fds.contains(&fd_needed) {
                eprintln!(
                    "  warning: required module fd {} not in registry ({:?})",
                    fd_needed, all_fds
                );
            }
        }

        match bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &fd_array) {
            Ok(result) => {
                if disabled_passes.is_empty() {
                    println!("  REJIT successful");
                } else {
                    println!(
                        "  REJIT successful (after disabling: {})",
                        disabled_passes.iter().cloned().collect::<Vec<_>>().join(", ")
                    );
                }
                if !result.verifier_log.is_empty() {
                    eprintln!("  verifier log (success): {} bytes", result.verifier_log.len());
                }
                return Ok(());
            }
            Err(e) => {
                let err_msg = format!("{:#}", e);

                // Extract verifier log for attribution.
                let log_text = err_msg
                    .find("verifier log:\n")
                    .map(|pos| &err_msg[pos + "verifier log:\n".len()..])
                    .unwrap_or("");

                // Attempt rollback if enabled.
                if rollback_enabled && !log_text.is_empty() {
                    if let Some(failed_pass) =
                        attribute_verifier_failure(log_text, &pipeline_result.attribution)
                    {
                        // Don't disable the same pass twice (shouldn't happen, but safety).
                        if !disabled_passes.contains(&failed_pass) {
                            let failed_pc = verifier_log::extract_failure_pc(log_text);
                            eprintln!(
                                "  WARN: pass '{}' caused verifier rejection{} for prog {} ({})",
                                failed_pass,
                                failed_pc.map_or(String::new(), |pc| format!(" at PC {}", pc)),
                                prog_id,
                                info.name_str(),
                            );
                            eprintln!(
                                "        Disabling '{}', retrying with {} remaining passes...",
                                failed_pass,
                                pipeline_result
                                    .pass_results
                                    .iter()
                                    .filter(|pr| pr.sites_applied > 0)
                                    .count()
                                    .saturating_sub(1),
                            );
                            disabled_passes.insert(failed_pass);
                            continue; // retry
                        }
                    }
                }

                // Cannot attribute or rollback disabled — report and fail.
                if !log_text.is_empty() {
                    let parsed = verifier_log::parse_verifier_log(log_text);
                    eprintln!("  REJIT failed for prog {} ({}):", prog_id, info.name_str());
                    eprintln!("  verifier rejected with {} state snapshots", parsed.len());
                    for vi in &parsed {
                        let regs: Vec<String> = vi
                            .regs
                            .iter()
                            .map(|(r, s)| format!("R{}={}", r, s.reg_type))
                            .collect();
                        eprintln!("    pc={}: {}", vi.pc, regs.join(" "));
                    }
                }
                return Err(e).context("BPF_PROG_REJIT failed");
            }
        }
    }

    anyhow::bail!(
        "prog {}: exhausted rollback retries ({} passes disabled: {})",
        prog_id,
        disabled_passes.len(),
        disabled_passes.iter().cloned().collect::<Vec<_>>().join(", ")
    )
}

pub(crate) fn cmd_apply_all(ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>, rollback_enabled: bool) -> Result<()> {
    let mut total = 0u32;
    let mut applied = 0u32;
    let mut errors = 0u32;

    for prog_id in bpf::iter_prog_ids() {
        total += 1;
        match try_apply_one(prog_id, ctx, pass_names, pgo_config, rollback_enabled) {
            Ok(result) if result.summary.applied => applied += 1,
            Ok(_) => {}
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

pub(crate) fn cmd_profile(prog_id: u32, interval_ms: u64, samples: usize) -> Result<()> {
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

/// Try to apply rewrites to a single program via PassManager.
///
/// Returns a structured `OptimizeOneResult` describing everything that happened:
/// program info, per-pass details, rollback attempts, and timings.
pub(crate) fn try_apply_one(prog_id: u32, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>, rollback_enabled: bool) -> Result<OptimizeOneResult> {
    let total_start = Instant::now();
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    let prog_name = info.name_str().to_string();
    let orig_insn_count = if !orig_insns.is_empty() {
        orig_insns.len()
    } else {
        info.orig_prog_len as usize / 8
    };

    // Helper to build result for early-return (no orig insns or no changes).
    let make_noop_result = |status: &str, applied: bool, final_count: usize, passes: Vec<PassDetail>, pipeline_ns: u64| -> OptimizeOneResult {
        let total_ns = total_start.elapsed().as_nanos() as u64;
        OptimizeOneResult {
            status: status.to_string(),
            program: ProgramInfo {
                prog_id,
                prog_name: prog_name.clone(),
                prog_type: info.prog_type,
                orig_insn_count,
                final_insn_count: final_count,
                insn_delta: final_count as i64 - orig_insn_count as i64,
            },
            summary: OptimizeSummary {
                applied,
                program_changed: false,
                total_sites_applied: 0,
                passes_executed: passes.len(),
                passes_changed: 0,
                verifier_retries: 0,
                final_disabled_passes: vec![],
            },
            passes,
            attempts: vec![],
            timings_ns: TimingsNs {
                pipeline_run_ns: pipeline_ns,
                rejit_syscall_ns: 0,
                total_ns,
            },
        }
    };

    if orig_insns.is_empty() {
        return Ok(make_noop_result("ok", false, orig_insn_count, vec![], 0));
    }

    // Fetch map IDs for FD relocation before REJIT.
    let map_ids = bpf::bpf_prog_get_map_ids(fd.as_raw_fd()).unwrap_or_default();

    // Collect PGO data once (reused across rollback retries).
    let profiling = collect_pgo_data(prog_id, pgo_config);

    let meta = pass::ProgMeta {
        prog_id: info.id,
        prog_type: info.prog_type,
        prog_name: info.name_str().to_string(),
        run_cnt: info.run_cnt,
        run_time_ns: info.run_time_ns,
        ..Default::default()
    };

    let mut disabled_passes: HashSet<String> = HashSet::new();
    let max_retries = 10;
    let mut attempts: Vec<AttemptRecord> = Vec::new();
    #[allow(unused_assignments)]
    let mut last_pass_details: Vec<PassDetail> = Vec::new();
    #[allow(unused_assignments)]
    let mut total_pipeline_ns: u64 = 0;
    let mut total_rejit_ns: u64 = 0;

    for attempt in 0..=max_retries {
        let mut program = pass::BpfProgram::new(orig_insns.clone(), meta.clone());
        let pm = build_pipeline(pass_names);
        let mut local_ctx = ctx.clone();
        for disabled in &disabled_passes {
            local_ctx.policy.disabled_passes.push(disabled.clone());
        }

        let pipeline_start = Instant::now();
        let pipeline_result = pm.run_with_profiling(&mut program, &local_ctx, profiling.as_ref())?;
        let pipeline_elapsed = pipeline_start.elapsed().as_nanos() as u64;
        total_pipeline_ns = pipeline_elapsed;

        // Build per-pass details from the latest pipeline run.
        last_pass_details = pipeline_result.pass_results.iter().map(PassDetail::from).collect();

        if !pipeline_result.program_changed {
            return Ok(make_noop_result("ok", false, orig_insn_count, last_pass_details, pipeline_elapsed));
        }

        let final_insn_count = program.insns.len();

        if disabled_passes.is_empty() {
            println!(
                "  prog {} ({}): {} sites, {} -> {} insns",
                prog_id,
                info.name_str(),
                pipeline_result.total_sites_applied,
                orig_insns.len(),
                final_insn_count,
            );
        }

        // Relocate stale map FDs in the rewritten bytecode.
        let _map_fds_guard = bpf::relocate_map_fds(&mut program.insns, &map_ids)
            .unwrap_or_else(|e| {
                eprintln!("    warning: map FD relocation failed: {:#}", e);
                Vec::new()
            });

        let fd_array: Vec<std::os::unix::io::RawFd> = program.required_module_fds.clone();
        let all_fds = local_ctx.kfunc_registry.all_module_fds();
        for &fd_needed in &fd_array {
            if !all_fds.contains(&fd_needed) {
                eprintln!(
                    "    warning: required module fd {} not in registry ({:?})",
                    fd_needed, all_fds
                );
            }
        }

        let rejit_start = Instant::now();
        match bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &fd_array) {
            Ok(_) => {
                let rejit_elapsed = rejit_start.elapsed().as_nanos() as u64;
                total_rejit_ns = rejit_elapsed;

                if disabled_passes.is_empty() {
                    println!("    REJIT ok");
                } else {
                    println!(
                        "    REJIT ok (after disabling: {})",
                        disabled_passes.iter().cloned().collect::<Vec<_>>().join(", ")
                    );
                }

                attempts.push(AttemptRecord {
                    attempt,
                    disabled_passes: disabled_passes.iter().cloned().collect(),
                    result: "applied".to_string(),
                    failure_pc: None,
                    attributed_pass: None,
                });

                let total_ns = total_start.elapsed().as_nanos() as u64;
                let passes_changed = last_pass_details.iter().filter(|p| p.changed).count();

                return Ok(OptimizeOneResult {
                    status: "ok".to_string(),
                    program: ProgramInfo {
                        prog_id,
                        prog_name: prog_name.clone(),
                        prog_type: info.prog_type,
                        orig_insn_count,
                        final_insn_count,
                        insn_delta: final_insn_count as i64 - orig_insn_count as i64,
                    },
                    summary: OptimizeSummary {
                        applied: true,
                        program_changed: true,
                        total_sites_applied: pipeline_result.total_sites_applied,
                        passes_executed: last_pass_details.len(),
                        passes_changed,
                        verifier_retries: attempt,
                        final_disabled_passes: disabled_passes.iter().cloned().collect(),
                    },
                    passes: last_pass_details,
                    attempts,
                    timings_ns: TimingsNs {
                        pipeline_run_ns: total_pipeline_ns,
                        rejit_syscall_ns: total_rejit_ns,
                        total_ns,
                    },
                });
            }
            Err(e) => {
                let rejit_elapsed = rejit_start.elapsed().as_nanos() as u64;
                total_rejit_ns += rejit_elapsed;

                let err_msg = format!("{:#}", e);
                let log_text = err_msg
                    .find("verifier log:\n")
                    .map(|pos| &err_msg[pos + "verifier log:\n".len()..])
                    .unwrap_or("");

                let failed_pc = verifier_log::extract_failure_pc(log_text);

                // Attempt rollback if enabled.
                if rollback_enabled && !log_text.is_empty() {
                    if let Some(ref failed_pass_name) =
                        attribute_verifier_failure(log_text, &pipeline_result.attribution)
                    {
                        if !disabled_passes.contains(failed_pass_name) {
                            eprintln!(
                                "    WARN: pass '{}' caused verifier rejection{} for prog {} ({})",
                                failed_pass_name,
                                failed_pc
                                    .map_or(String::new(), |pc| format!(" at PC {}", pc)),
                                prog_id,
                                info.name_str(),
                            );
                            eprintln!(
                                "          Disabling '{}', retrying...",
                                failed_pass_name,
                            );

                            attempts.push(AttemptRecord {
                                attempt,
                                disabled_passes: disabled_passes.iter().cloned().collect(),
                                result: "verifier_rejected".to_string(),
                                failure_pc: failed_pc,
                                attributed_pass: Some(failed_pass_name.clone()),
                            });

                            disabled_passes.insert(failed_pass_name.clone());
                            continue;
                        }
                    }
                }

                // Cannot attribute or rollback disabled — record final attempt and fail.
                attempts.push(AttemptRecord {
                    attempt,
                    disabled_passes: disabled_passes.iter().cloned().collect(),
                    result: "verifier_rejected".to_string(),
                    failure_pc: failed_pc,
                    attributed_pass: None,
                });

                if !log_text.is_empty() {
                    let parsed = verifier_log::parse_verifier_log(log_text);
                    eprintln!(
                        "    REJIT failed: verifier rejected with {} state snapshots",
                        parsed.len()
                    );
                    for vi in &parsed {
                        let regs: Vec<String> = vi
                            .regs
                            .iter()
                            .map(|(r, s)| format!("R{}={}", r, s.reg_type))
                            .collect();
                        eprintln!("      pc={}: {}", vi.pc, regs.join(" "));
                    }
                }
                return Err(e);
            }
        }
    }

    anyhow::bail!(
        "prog {}: exhausted rollback retries ({} passes disabled)",
        prog_id,
        disabled_passes.len()
    )
}

fn fmt_avg(value: Option<f64>) -> String {
    match value {
        Some(avg) => format!("{avg:.2}"),
        None => "-".to_string(),
    }
}

// ── Tests ───────────────────────────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_optimize_one_result_serialization() {
        let result = OptimizeOneResult {
            status: "ok".to_string(),
            program: ProgramInfo {
                prog_id: 42,
                prog_name: "test_prog".to_string(),
                prog_type: 6,
                orig_insn_count: 100,
                final_insn_count: 90,
                insn_delta: -10,
            },
            summary: OptimizeSummary {
                applied: true,
                program_changed: true,
                total_sites_applied: 3,
                passes_executed: 2,
                passes_changed: 1,
                verifier_retries: 0,
                final_disabled_passes: vec![],
            },
            passes: vec![
                PassDetail {
                    pass_name: "wide_mem".to_string(),
                    changed: true,
                    sites_applied: 3,
                    sites_skipped: 1,
                    skip_reasons: HashMap::from([("subprog_unsupported".to_string(), 1)]),
                    insns_before: 100,
                    insns_after: 90,
                    insn_delta: -10,
                    diagnostics: vec![],
                },
                PassDetail {
                    pass_name: "rotate".to_string(),
                    changed: false,
                    sites_applied: 0,
                    sites_skipped: 0,
                    skip_reasons: HashMap::new(),
                    insns_before: 90,
                    insns_after: 90,
                    insn_delta: 0,
                    diagnostics: vec![],
                },
            ],
            attempts: vec![
                AttemptRecord {
                    attempt: 0,
                    disabled_passes: vec![],
                    result: "applied".to_string(),
                    failure_pc: None,
                    attributed_pass: None,
                },
            ],
            timings_ns: TimingsNs {
                pipeline_run_ns: 100_000,
                rejit_syscall_ns: 50_000,
                total_ns: 200_000,
            },
        };

        let json = serde_json::to_string(&result).expect("serialization should succeed");
        let parsed: serde_json::Value =
            serde_json::from_str(&json).expect("JSON should parse back");

        assert_eq!(parsed["status"], "ok");
        assert_eq!(parsed["program"]["prog_id"], 42);
        assert_eq!(parsed["program"]["insn_delta"], -10);
        assert_eq!(parsed["summary"]["applied"], true);
        assert_eq!(parsed["summary"]["total_sites_applied"], 3);
        assert_eq!(parsed["summary"]["verifier_retries"], 0);
        assert_eq!(parsed["passes"].as_array().unwrap().len(), 2);
        assert_eq!(parsed["passes"][0]["pass_name"], "wide_mem");
        assert_eq!(parsed["passes"][0]["changed"], true);
        assert_eq!(parsed["passes"][0]["skip_reasons"]["subprog_unsupported"], 1);
        assert_eq!(parsed["passes"][1]["changed"], false);
        assert_eq!(parsed["attempts"].as_array().unwrap().len(), 1);
        assert_eq!(parsed["attempts"][0]["result"], "applied");
        // failure_pc and attributed_pass should be absent when None
        assert!(parsed["attempts"][0].get("failure_pc").is_none());
        assert!(parsed["attempts"][0].get("attributed_pass").is_none());
        assert_eq!(parsed["timings_ns"]["pipeline_run_ns"], 100_000);
        assert_eq!(parsed["timings_ns"]["rejit_syscall_ns"], 50_000);
        assert_eq!(parsed["timings_ns"]["total_ns"], 200_000);
    }

    #[test]
    fn test_optimize_one_result_with_rollback() {
        let result = OptimizeOneResult {
            status: "ok".to_string(),
            program: ProgramInfo {
                prog_id: 99,
                prog_name: "xdp_main".to_string(),
                prog_type: 6,
                orig_insn_count: 110,
                final_insn_count: 100,
                insn_delta: -10,
            },
            summary: OptimizeSummary {
                applied: true,
                program_changed: true,
                total_sites_applied: 2,
                passes_executed: 3,
                passes_changed: 1,
                verifier_retries: 1,
                final_disabled_passes: vec!["branch_flip".to_string()],
            },
            passes: vec![],
            attempts: vec![
                AttemptRecord {
                    attempt: 0,
                    disabled_passes: vec![],
                    result: "verifier_rejected".to_string(),
                    failure_pc: Some(76),
                    attributed_pass: Some("branch_flip".to_string()),
                },
                AttemptRecord {
                    attempt: 1,
                    disabled_passes: vec!["branch_flip".to_string()],
                    result: "applied".to_string(),
                    failure_pc: None,
                    attributed_pass: None,
                },
            ],
            timings_ns: TimingsNs {
                pipeline_run_ns: 200_000,
                rejit_syscall_ns: 100_000,
                total_ns: 400_000,
            },
        };

        let json = serde_json::to_string(&result).expect("serialization should succeed");
        let parsed: serde_json::Value =
            serde_json::from_str(&json).expect("JSON should parse back");

        assert_eq!(parsed["summary"]["verifier_retries"], 1);
        assert_eq!(parsed["summary"]["final_disabled_passes"][0], "branch_flip");
        assert_eq!(parsed["attempts"].as_array().unwrap().len(), 2);
        assert_eq!(parsed["attempts"][0]["failure_pc"], 76);
        assert_eq!(parsed["attempts"][0]["attributed_pass"], "branch_flip");
        assert_eq!(parsed["attempts"][1]["result"], "applied");
    }

    #[test]
    fn test_pass_detail_from_pass_result() {
        let pr = pass::PassResult {
            pass_name: "wide_mem".to_string(),
            changed: true,
            sites_applied: 5,
            sites_skipped: vec![
                pass::SkipReason { pc: 10, reason: "subprog_unsupported".to_string() },
                pass::SkipReason { pc: 20, reason: "subprog_unsupported".to_string() },
                pass::SkipReason { pc: 30, reason: "kfunc_unavailable".to_string() },
            ],
            diagnostics: vec!["test".to_string()],
            insns_before: 100,
            insns_after: 95,
        };

        let detail = PassDetail::from(&pr);

        assert_eq!(detail.pass_name, "wide_mem");
        assert_eq!(detail.changed, true);
        assert_eq!(detail.sites_applied, 5);
        assert_eq!(detail.sites_skipped, 3);
        assert_eq!(detail.skip_reasons["subprog_unsupported"], 2);
        assert_eq!(detail.skip_reasons["kfunc_unavailable"], 1);
        assert_eq!(detail.insns_before, 100);
        assert_eq!(detail.insns_after, 95);
        assert_eq!(detail.insn_delta, -5);
    }
}
