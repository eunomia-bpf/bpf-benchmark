// SPDX-License-Identifier: MIT
//! Subcommand implementations: enumerate, rewrite, apply, apply-all, profile.

use std::collections::{HashMap, HashSet};
use std::os::unix::io::{AsRawFd, RawFd};
use std::time::{Duration, Instant};

use anyhow::Result;
use serde::Serialize;

use crate::{bpf, insn, pass, passes, profiler, verifier_log};

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
    #[serde(skip_serializing_if = "Option::is_none")]
    pub error_message: Option<String>,
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
    #[serde(skip_serializing_if = "Option::is_none")]
    pub debug: Option<AttemptDebug>,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct AttemptDebug {
    pub pass_traces: Vec<pass::PassDebugTrace>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub pre_rejit_bytecode: Option<insn::BpfBytecodeDump>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub verifier_log: Option<VerifierLogRecord>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub final_xlated_bytecode: Option<insn::BpfBytecodeDump>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub final_jited_machine_code: Option<bpf::MachineCodeDump>,
    #[serde(skip_serializing_if = "Vec::is_empty", default)]
    pub warnings: Vec<String>,
}

#[derive(Clone, Debug, Serialize)]
pub(crate) struct VerifierLogRecord {
    pub source: String,
    pub log_level: u32,
    pub log: String,
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
pub(crate) fn collect_pgo_data(
    prog_id: u32,
    pgo_config: &Option<PgoConfig>,
) -> Option<pass::ProfilingData> {
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
                eprintln!(
                    "  pgo: prog {} is cold (no activity during observation)",
                    prog_id
                );
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

fn build_rejit_fd_array(required_btf_fds: &[RawFd]) -> Vec<RawFd> {
    if required_btf_fds.is_empty() {
        return Vec::new();
    }

    // CALL.off uses 0 for vmlinux and 1-based slots for descriptor BTFs.
    // The REJIT fd_array pre-scan requires every populated slot to be a valid
    // map or BTF fd, so reserve slot 0 with a duplicate valid BTF fd.
    let mut fd_array = Vec::with_capacity(required_btf_fds.len() + 1);
    fd_array.push(required_btf_fds[0]);
    fd_array.extend(required_btf_fds.iter().copied());
    fd_array
}

fn sorted_strings(values: impl IntoIterator<Item = String>) -> Vec<String> {
    let mut values: Vec<String> = values.into_iter().collect();
    values.sort();
    values
}

fn new_attempt_debug(pass_traces: Vec<pass::PassDebugTrace>) -> Option<AttemptDebug> {
    Some(AttemptDebug {
        pass_traces,
        pre_rejit_bytecode: None,
        verifier_log: None,
        final_xlated_bytecode: None,
        final_jited_machine_code: None,
        warnings: Vec::new(),
    })
}

fn push_debug_warning(debug: &mut Option<AttemptDebug>, warning: impl Into<String>) {
    if let Some(debug) = debug.as_mut() {
        debug.warnings.push(warning.into());
    }
}

pub(crate) fn emit_debug_result(result: &OptimizeOneResult) {
    match serde_json::to_string(result) {
        Ok(json) => eprintln!("{}", json),
        Err(err) => eprintln!("debug-log: failed to serialize optimize result: {err}"),
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

fn verifier_log_looks_complete(verifier_log_text: &str) -> bool {
    verifier_log_text.contains("\nprocessed ")
        || verifier_log_text.contains("\nSCC exit")
        || verifier_log_text.lines().any(|line| line.trim() == "safe")
}

fn should_treat_as_verifier_rejection(err_msg: &str, verifier_log_text: &str) -> bool {
    if verifier_log_text.is_empty() {
        return false;
    }

    let first_line = err_msg.lines().next().unwrap_or_default().to_ascii_lowercase();
    if first_line.contains("no space left on device")
        || first_line.contains("out of memory")
        || first_line.contains("operation not supported")
    {
        return false;
    }

    !verifier_log_looks_complete(verifier_log_text)
}

fn should_retry_post_verify_rejit_failure(err_msg: &str, verifier_log_text: &str) -> bool {
    if !verifier_log_looks_complete(verifier_log_text) {
        return false;
    }

    let first_line = err_msg.lines().next().unwrap_or_default().to_ascii_lowercase();
    first_line.contains("no space left on device")
        || first_line.contains("argument list too long")
        || first_line.contains("out of memory")
}

fn attribute_post_verify_rejit_failure(passes: &[PassDetail]) -> Option<String> {
    passes
        .iter()
        .rev()
        .find(|pass| pass.changed)
        .map(|pass| pass.pass_name.clone())
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

pub(crate) fn cmd_enumerate(
    ctx: &pass::PassContext,
    pass_names: &Option<Vec<String>>,
) -> Result<()> {
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

fn enumerate_one(
    prog_id: u32,
    ctx: &pass::PassContext,
    pass_names: &Option<Vec<String>>,
) -> Result<()> {
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
        let mut program = pass::BpfProgram::new(orig_insns);
        program.set_map_ids(bpf::bpf_prog_get_map_ids(fd.as_raw_fd()).unwrap_or_default());
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

pub(crate) fn cmd_rewrite(
    prog_id: u32,
    ctx: &pass::PassContext,
    pass_names: &Option<Vec<String>>,
) -> Result<()> {
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

    let mut program = pass::BpfProgram::new(orig_insns.clone());
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    program.set_map_ids(bpf::bpf_prog_get_map_ids(fd.as_raw_fd()).unwrap_or_default());
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

pub(crate) fn cmd_apply(
    prog_id: u32,
    ctx: &pass::PassContext,
    pass_names: &Option<Vec<String>>,
    pgo_config: &Option<PgoConfig>,
    rollback_enabled: bool,
) -> Result<()> {
    let result = try_apply_one(prog_id, ctx, pass_names, pgo_config, rollback_enabled)?;
    emit_debug_result(&result);

    if result.program.orig_insn_count == 0 {
        println!("prog {}: no original instructions available", prog_id);
    } else if !result.summary.applied {
        println!(
            "prog {} ({}): no transforms applied",
            result.program.prog_id, result.program.prog_name
        );
    }

    Ok(())
}

pub(crate) fn cmd_apply_all(
    ctx: &pass::PassContext,
    pass_names: &Option<Vec<String>>,
    pgo_config: &Option<PgoConfig>,
    rollback_enabled: bool,
) -> Result<()> {
    let mut total = 0u32;
    let mut applied = 0u32;
    let mut errors = 0u32;

    for prog_id in bpf::iter_prog_ids() {
        total += 1;
        match try_apply_one(prog_id, ctx, pass_names, pgo_config, rollback_enabled) {
            Ok(result) => {
                emit_debug_result(&result);
                if result.summary.applied {
                    applied += 1;
                }
            }
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
pub(crate) fn try_apply_one(
    prog_id: u32,
    ctx: &pass::PassContext,
    pass_names: &Option<Vec<String>>,
    pgo_config: &Option<PgoConfig>,
    rollback_enabled: bool,
) -> Result<OptimizeOneResult> {
    let total_start = Instant::now();
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    let prog_name = info.name_str().to_string();
    let orig_insn_count = if !orig_insns.is_empty() {
        orig_insns.len()
    } else {
        info.orig_prog_len as usize / 8
    };

    let make_result = |status: &str,
                       applied: bool,
                       program_changed: bool,
                       total_sites_applied: usize,
                       final_count: usize,
                       passes: Vec<PassDetail>,
                       attempts: Vec<AttemptRecord>,
                       pipeline_ns: u64,
                       rejit_ns: u64,
                       final_disabled_passes: Vec<String>,
                       error_message: Option<String>|
     -> OptimizeOneResult {
        let total_ns = total_start.elapsed().as_nanos() as u64;
        let verifier_retries = attempts
            .iter()
            .filter(|attempt| attempt.result == "verifier_rejected")
            .count();
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
                program_changed,
                total_sites_applied,
                passes_executed: passes.len(),
                passes_changed: passes.iter().filter(|pass| pass.changed).count(),
                verifier_retries,
                final_disabled_passes,
            },
            passes,
            attempts,
            timings_ns: TimingsNs {
                pipeline_run_ns: pipeline_ns,
                rejit_syscall_ns: rejit_ns,
                total_ns,
            },
            error_message,
        }
    };

    if orig_insns.is_empty() {
        return Ok(make_result(
            "ok",
            false,
            false,
            0,
            orig_insn_count,
            vec![],
            vec![],
            0,
            0,
            vec![],
            None,
        ));
    }

    // Fetch map IDs for FD relocation before REJIT.
    let map_ids = bpf::bpf_prog_get_map_ids(fd.as_raw_fd()).unwrap_or_default();

    // Collect PGO data once (reused across rollback retries).
    let profiling = collect_pgo_data(prog_id, pgo_config);

    let mut disabled_passes: HashSet<String> = HashSet::new();
    let max_retries = 10;
    let mut attempts: Vec<AttemptRecord> = Vec::new();
    let mut last_pass_details: Vec<PassDetail> = Vec::new();
    let mut total_pipeline_ns: u64 = 0;
    let mut total_rejit_ns: u64 = 0;

    for attempt in 0..=max_retries {
        let mut program = pass::BpfProgram::new(orig_insns.clone());
        program.set_map_ids(map_ids.clone());
        let pm = build_pipeline(pass_names);
        let mut local_ctx = ctx.clone();
        for disabled in sorted_strings(disabled_passes.iter().cloned()) {
            local_ctx.policy.disabled_passes.push(disabled.clone());
        }

        let pipeline_start = Instant::now();
        let pipeline_result =
            pm.run_with_profiling(&mut program, &local_ctx, profiling.as_ref())?;
        let pipeline_elapsed = pipeline_start.elapsed().as_nanos() as u64;
        total_pipeline_ns += pipeline_elapsed;

        // Build per-pass details from the latest pipeline run.
        last_pass_details = pipeline_result
            .pass_results
            .iter()
            .map(PassDetail::from)
            .collect();
        let mut attempt_debug = new_attempt_debug(pipeline_result.debug_traces.clone());
        let disabled_passes_sorted = sorted_strings(disabled_passes.iter().cloned());

        if !pipeline_result.program_changed {
            attempts.push(AttemptRecord {
                attempt,
                disabled_passes: disabled_passes_sorted.clone(),
                result: "no_change".to_string(),
                failure_pc: None,
                attributed_pass: None,
                debug: attempt_debug,
            });

            return Ok(make_result(
                "ok",
                false,
                false,
                0,
                orig_insn_count,
                last_pass_details,
                attempts,
                total_pipeline_ns,
                total_rejit_ns,
                disabled_passes_sorted,
                None,
            ));
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
        let _map_fds_guard =
            bpf::relocate_map_fds(&mut program.insns, &map_ids).unwrap_or_else(|e| {
                eprintln!("    warning: map FD relocation failed: {:#}", e);
                push_debug_warning(
                    &mut attempt_debug,
                    format!("map FD relocation failed before REJIT: {e:#}"),
                );
                Vec::new()
            });

        if let Some(debug) = attempt_debug.as_mut() {
            debug.pre_rejit_bytecode = Some(insn::dump_bytecode_compact(&program.insns));
        }

        let fd_array = build_rejit_fd_array(&program.required_btf_fds);
        let all_fds = local_ctx.kinsn_registry.all_btf_fds();
        for &fd_needed in &program.required_btf_fds {
            if !all_fds.contains(&fd_needed) {
                eprintln!(
                    "    warning: required descriptor BTF fd {} not in registry ({:?})",
                    fd_needed, all_fds
                );
                push_debug_warning(
                    &mut attempt_debug,
                    format!(
                        "required descriptor BTF fd {fd_needed} missing from registry {:?}",
                        all_fds
                    ),
                );
            }
        }

        let rejit_start = Instant::now();
        match bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &fd_array) {
            Ok(rejit_result) => {
                let rejit_elapsed = rejit_start.elapsed().as_nanos() as u64;
                total_rejit_ns += rejit_elapsed;

                if disabled_passes.is_empty() {
                    println!("    REJIT ok");
                } else {
                    println!(
                        "    REJIT ok (after disabling: {})",
                        disabled_passes
                            .iter()
                            .cloned()
                            .collect::<Vec<_>>()
                            .join(", ")
                    );
                }

                if let Some(debug) = attempt_debug.as_mut() {
                    if rejit_result.verifier_log.is_empty() {
                        debug.warnings.push(
                            "REJIT succeeded but the verifier log buffer was empty".to_string(),
                        );
                    } else {
                        debug.verifier_log = Some(VerifierLogRecord {
                            source: "BPF_PROG_REJIT".to_string(),
                            log_level: 2,
                            log: rejit_result.verifier_log.clone(),
                        });
                        debug.warnings.push(
                            "verifier log captured from BPF_PROG_REJIT(log_level=2); daemon-only debug mode cannot reconstruct the full original BPF_PROG_LOAD attr for arbitrary live programs".to_string(),
                        );
                    }

                    match bpf::bpf_prog_get_runtime_images(fd.as_raw_fd()) {
                        Ok(images) => {
                            debug.final_xlated_bytecode =
                                Some(insn::dump_bytecode_compact(&images.xlated_insns));
                            debug.final_jited_machine_code =
                                Some(bpf::dump_machine_code(&images.jited_prog_insns));
                        }
                        Err(err) => debug.warnings.push(format!(
                            "failed to fetch final xlated/jited images: {err:#}"
                        )),
                    }
                }

                attempts.push(AttemptRecord {
                    attempt,
                    disabled_passes: disabled_passes_sorted.clone(),
                    result: "applied".to_string(),
                    failure_pc: None,
                    attributed_pass: None,
                    debug: attempt_debug,
                });

                return Ok(make_result(
                    "ok",
                    true,
                    true,
                    pipeline_result.total_sites_applied,
                    final_insn_count,
                    last_pass_details,
                    attempts,
                    total_pipeline_ns,
                    total_rejit_ns,
                    disabled_passes_sorted,
                    None,
                ));
            }
            Err(e) => {
                let rejit_elapsed = rejit_start.elapsed().as_nanos() as u64;
                total_rejit_ns += rejit_elapsed;

                let err_msg = format!("{:#}", e);
                let log_text = err_msg
                    .find("verifier log:\n")
                    .map(|pos| &err_msg[pos + "verifier log:\n".len()..])
                    .unwrap_or("");

                if let Some(debug) = attempt_debug.as_mut() {
                    if !log_text.is_empty() {
                        debug.verifier_log = Some(VerifierLogRecord {
                            source: "BPF_PROG_REJIT".to_string(),
                            log_level: 2,
                            log: log_text.to_string(),
                        });
                        debug.warnings.push(
                            "verifier log captured from BPF_PROG_REJIT(log_level=2) failure path"
                                .to_string(),
                        );
                    } else {
                        debug
                            .warnings
                            .push("REJIT failed without returning a verifier log".to_string());
                    }
                }

                let failed_pc = verifier_log::extract_failure_pc(log_text);
                let verifier_rejected = should_treat_as_verifier_rejection(&err_msg, log_text);
                let post_verify_retryable =
                    should_retry_post_verify_rejit_failure(&err_msg, log_text);

                // Attempt rollback if enabled.
                if rollback_enabled && verifier_rejected {
                    if let Some(ref failed_pass_name) =
                        attribute_verifier_failure(log_text, &pipeline_result.attribution)
                    {
                        if !disabled_passes.contains(failed_pass_name) {
                            eprintln!(
                                "    WARN: pass '{}' caused verifier rejection{} for prog {} ({})",
                                failed_pass_name,
                                failed_pc.map_or(String::new(), |pc| format!(" at PC {}", pc)),
                                prog_id,
                                info.name_str(),
                            );
                            eprintln!("          Disabling '{}', retrying...", failed_pass_name,);

                            attempts.push(AttemptRecord {
                                attempt,
                                disabled_passes: disabled_passes_sorted.clone(),
                                result: "verifier_rejected".to_string(),
                                failure_pc: failed_pc,
                                attributed_pass: Some(failed_pass_name.clone()),
                                debug: attempt_debug,
                            });

                            disabled_passes.insert(failed_pass_name.clone());
                            continue;
                        }
                    }
                }

                if rollback_enabled && post_verify_retryable {
                    if let Some(failed_pass_name) =
                        attribute_post_verify_rejit_failure(&last_pass_details)
                    {
                        if !disabled_passes.contains(&failed_pass_name) {
                            let first_line = err_msg.lines().next().unwrap_or_default();
                            eprintln!(
                                "    WARN: pass '{}' caused post-verifier REJIT failure ({}) for prog {} ({})",
                                failed_pass_name,
                                first_line,
                                prog_id,
                                info.name_str(),
                            );
                            eprintln!("          Disabling '{}', retrying...", failed_pass_name);

                            attempts.push(AttemptRecord {
                                attempt,
                                disabled_passes: disabled_passes_sorted.clone(),
                                result: "rejit_failed".to_string(),
                                failure_pc: None,
                                attributed_pass: Some(failed_pass_name.clone()),
                                debug: attempt_debug,
                            });

                            disabled_passes.insert(failed_pass_name);
                            continue;
                        }
                    }
                }

                // Cannot attribute or rollback disabled — record final attempt and fail.
                attempts.push(AttemptRecord {
                    attempt,
                    disabled_passes: disabled_passes_sorted.clone(),
                    result: if verifier_rejected {
                        "verifier_rejected".to_string()
                    } else {
                        "rejit_failed".to_string()
                    },
                    failure_pc: if verifier_rejected { failed_pc } else { None },
                    attributed_pass: None,
                    debug: attempt_debug,
                });

                if verifier_rejected && !log_text.is_empty() {
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

                {
                    let failure_result = make_result(
                        "error",
                        false,
                        true,
                        pipeline_result.total_sites_applied,
                        final_insn_count,
                        last_pass_details.clone(),
                        attempts.clone(),
                        total_pipeline_ns,
                        total_rejit_ns,
                        disabled_passes_sorted,
                        Some(err_msg),
                    );
                    emit_debug_result(&failure_result);
                }
                return Err(e);
            }
        }
    }

    let exhausted_msg = format!(
        "prog {}: exhausted rollback retries ({} passes disabled)",
        prog_id,
        disabled_passes.len()
    );

    {
        let failure_result = make_result(
            "error",
            false,
            true,
            0,
            orig_insn_count,
            last_pass_details,
            attempts,
            total_pipeline_ns,
            total_rejit_ns,
            sorted_strings(disabled_passes.iter().cloned()),
            Some(exhausted_msg.clone()),
        );
        emit_debug_result(&failure_result);
    }

    anyhow::bail!(exhausted_msg)
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
    use std::collections::HashMap;

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
            attempts: vec![AttemptRecord {
                attempt: 0,
                disabled_passes: vec![],
                result: "applied".to_string(),
                failure_pc: None,
                attributed_pass: None,
                debug: None,
            }],
            timings_ns: TimingsNs {
                pipeline_run_ns: 100_000,
                rejit_syscall_ns: 50_000,
                total_ns: 200_000,
            },
            error_message: None,
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
        assert_eq!(
            parsed["passes"][0]["skip_reasons"]["subprog_unsupported"],
            1
        );
        assert_eq!(parsed["passes"][1]["changed"], false);
        assert_eq!(parsed["attempts"].as_array().unwrap().len(), 1);
        assert_eq!(parsed["attempts"][0]["result"], "applied");
        // failure_pc and attributed_pass should be absent when None
        assert!(parsed["attempts"][0].get("failure_pc").is_none());
        assert!(parsed["attempts"][0].get("attributed_pass").is_none());
        assert!(parsed["attempts"][0].get("debug").is_none());
        assert_eq!(parsed["timings_ns"]["pipeline_run_ns"], 100_000);
        assert_eq!(parsed["timings_ns"]["rejit_syscall_ns"], 50_000);
        assert_eq!(parsed["timings_ns"]["total_ns"], 200_000);
        assert!(parsed.get("error_message").is_none());
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
                    debug: None,
                },
                AttemptRecord {
                    attempt: 1,
                    disabled_passes: vec!["branch_flip".to_string()],
                    result: "applied".to_string(),
                    failure_pc: None,
                    attributed_pass: None,
                    debug: None,
                },
            ],
            timings_ns: TimingsNs {
                pipeline_run_ns: 200_000,
                rejit_syscall_ns: 100_000,
                total_ns: 400_000,
            },
            error_message: None,
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
                pass::SkipReason {
                    pc: 10,
                    reason: "subprog_unsupported".to_string(),
                },
                pass::SkipReason {
                    pc: 20,
                    reason: "subprog_unsupported".to_string(),
                },
                pass::SkipReason {
                    pc: 30,
                    reason: "kfunc_unavailable".to_string(),
                },
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

    // ── HIGH #3: Orchestration unit tests ───────────────────────────

    /// Test attribute_verifier_failure — the core attribution logic used by
    /// the rollback loop in cmd_apply / try_apply_one.
    ///
    /// The verifier log format requires state lines (e.g., "15: R0=scalar R1=ctx()")
    /// followed by error lines. extract_failure_pc extracts the PC from the last
    /// state line before an error keyword.
    #[test]
    fn test_attribute_verifier_failure_basic() {
        let attribution = vec![
            pass::TransformAttribution {
                pass_name: "wide_mem".to_string(),
                pc_range: 10..20,
            },
            pass::TransformAttribution {
                pass_name: "rotate".to_string(),
                pc_range: 30..40,
            },
        ];

        // Failure at PC 15 -> attributed to wide_mem
        // Use realistic verifier log format: state line, then error line
        let log_wide_mem = "\
0: R1=ctx() R10=fp0
15: R0=scalar R2=pkt(r=8)
R2 type=scalar expected=pkt_ptr
";
        let result = attribute_verifier_failure(log_wide_mem, &attribution);
        assert_eq!(result, Some("wide_mem".to_string()));

        // Failure at PC 35 -> attributed to rotate
        let log_rotate = "\
0: R1=ctx() R10=fp0
35: R0=scalar R1=ctx()
invalid func bpf_rotate64#12345
";
        let result = attribute_verifier_failure(log_rotate, &attribution);
        assert_eq!(result, Some("rotate".to_string()));

        // Failure at PC 5 (before any pass range) -> None
        let log_before = "\
0: R1=ctx() R10=fp0
5: R0=scalar R2=pkt(r=8)
R2 invalid mem access
";
        let result = attribute_verifier_failure(log_before, &attribution);
        assert_eq!(result, None);

        // Failure at PC 25 (between pass ranges) -> None
        let log_gap = "\
0: R1=ctx() R10=fp0
25: R0=scalar R1=ctx()
R1 type=scalar expected=fp
";
        let result = attribute_verifier_failure(log_gap, &attribution);
        assert_eq!(result, None);
    }

    /// Test attribute_verifier_failure with overlapping ranges —
    /// should pick the last (most recently applied) pass.
    #[test]
    fn test_attribute_verifier_failure_overlapping_ranges() {
        let attribution = vec![
            pass::TransformAttribution {
                pass_name: "wide_mem".to_string(),
                pc_range: 10..30,
            },
            pass::TransformAttribution {
                pass_name: "rotate".to_string(),
                pc_range: 20..40,
            },
        ];

        // PC 25 is in both ranges — should pick "rotate" (last)
        let log = "\
0: R1=ctx() R10=fp0
25: R0=scalar R2=pkt(r=8)
R2 invalid mem access 'scalar'
";
        let result = attribute_verifier_failure(log, &attribution);
        assert_eq!(result, Some("rotate".to_string()));
    }

    #[test]
    fn test_verifier_log_completion_marker_detection() {
        let log = "\
10: R0=scalar
55: safe
processed 49965 insns (limit 1000000) max_states_per_insn 32 total_states 1318 peak_states 232 mark_read 0
";
        assert!(verifier_log_looks_complete(log));
        assert!(!should_treat_as_verifier_rejection(
            "BPF_PROG_REJIT: No space left on device (os error 28)",
            log,
        ));
    }

    #[test]
    fn test_incomplete_verifier_log_still_treated_as_rejection() {
        let log = "\
35: R0=scalar R1=ctx()
invalid func bpf_rotate64#12345
";
        assert!(!verifier_log_looks_complete(log));
        assert!(should_treat_as_verifier_rejection(
            "BPF_PROG_REJIT: Permission denied (os error 13)",
            log,
        ));
    }

    #[test]
    fn test_complete_verifier_log_e2big_is_retryable_post_verify_failure() {
        let log = "\
10: R0=scalar
55: safe
processed 49965 insns (limit 1000000) max_states_per_insn 32 total_states 1318 peak_states 232 mark_read 0
";
        assert!(!should_treat_as_verifier_rejection(
            "BPF_PROG_REJIT: Argument list too long (os error 7)",
            log,
        ));
        assert!(should_retry_post_verify_rejit_failure(
            "BPF_PROG_REJIT: Argument list too long (os error 7)",
            log,
        ));
    }

    #[test]
    fn test_attribute_post_verify_rejit_failure_uses_last_changed_pass() {
        let passes = vec![
            PassDetail {
                pass_name: "wide_mem".to_string(),
                changed: false,
                sites_applied: 0,
                sites_skipped: 0,
                skip_reasons: HashMap::new(),
                insns_before: 100,
                insns_after: 100,
                insn_delta: 0,
                diagnostics: vec![],
            },
            PassDetail {
                pass_name: "extract".to_string(),
                changed: true,
                sites_applied: 2,
                sites_skipped: 0,
                skip_reasons: HashMap::new(),
                insns_before: 100,
                insns_after: 104,
                insn_delta: 4,
                diagnostics: vec![],
            },
            PassDetail {
                pass_name: "endian_fusion".to_string(),
                changed: true,
                sites_applied: 3,
                sites_skipped: 0,
                skip_reasons: HashMap::new(),
                insns_before: 104,
                insns_after: 110,
                insn_delta: 6,
                diagnostics: vec![],
            },
        ];

        assert_eq!(
            attribute_post_verify_rejit_failure(&passes),
            Some("endian_fusion".to_string())
        );
    }

    /// Test build_pipeline: verify that pass selection works correctly.
    #[test]
    fn test_build_pipeline_default_and_custom() {
        // Default pipeline should include the standard passes.
        let pm_default = build_pipeline(&None);
        // Just verify it was built without panic.
        // We can test it by running on a trivial program.
        let exit_insn = crate::insn::BpfInsn {
            code: crate::insn::BPF_JMP | crate::insn::BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        };
        let mut prog = pass::BpfProgram::new(vec![exit_insn]);
        let ctx = pass::PassContext::test_default();
        let result = pm_default.run(&mut prog, &ctx).unwrap();
        // A single EXIT instruction should not trigger any transforms.
        assert!(!result.program_changed);

        // Custom pipeline with specific passes.
        let pm_custom = build_pipeline(&Some(vec!["wide_mem".to_string()]));
        let mut prog2 = pass::BpfProgram::new(vec![exit_insn]);
        let result2 = pm_custom.run(&mut prog2, &ctx).unwrap();
        assert!(!result2.program_changed);
    }

    /// Test collect_pgo_data returns None when PGO is disabled.
    #[test]
    fn test_collect_pgo_data_none_when_disabled() {
        let result = collect_pgo_data(1, &None);
        assert!(result.is_none());
    }

    /// HIGH #3 continued: Integration test for try_apply_one with a real BPF program.
    /// Requires root/BPF access.
    #[test]
    #[ignore]
    fn test_try_apply_one_integration() {
        use crate::kfunc_discovery;

        // Discover kfuncs (may find none if modules not loaded, that's OK).
        let discovery = kfunc_discovery::discover_kinsns();
        let ctx = pass::PassContext {
            kinsn_registry: discovery.registry,
            platform: pass::PlatformCapabilities::default(),
            policy: pass::PolicyConfig::default(),
        };

        // Find a program to try applying to.
        for prog_id in bpf::iter_prog_ids().take(50) {
            let result = try_apply_one(prog_id, &ctx, &None, &None, true);
            match result {
                Ok(opt_result) => {
                    // Verify the result structure is well-formed.
                    assert!(
                        opt_result.status == "ok" || opt_result.status == "error",
                        "unexpected status: {}",
                        opt_result.status
                    );
                    assert_eq!(opt_result.program.prog_id, prog_id);
                    assert!(
                        opt_result.program.orig_insn_count > 0
                            || opt_result.program.orig_insn_count == 0
                    );
                    // Verify JSON serialization works.
                    let json = serde_json::to_string(&opt_result);
                    assert!(
                        json.is_ok(),
                        "JSON serialization failed: {:#}",
                        json.unwrap_err()
                    );
                    eprintln!(
                        "  try_apply_one(prog_id={}): status={} applied={}",
                        prog_id, opt_result.status, opt_result.summary.applied
                    );
                    return; // One successful test is enough
                }
                Err(e) => {
                    eprintln!("  try_apply_one(prog_id={}): error: {:#}", prog_id, e);
                    continue;
                }
            }
        }
        eprintln!("  SKIP: no BPF programs found to test try_apply_one");
    }
}
