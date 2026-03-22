// SPDX-License-Identifier: MIT
//! Subcommand implementations: enumerate, rewrite, apply, apply-all, profile.

use std::collections::HashSet;
use std::os::unix::io::AsRawFd;
use std::time::Duration;

use anyhow::{Context, Result};

use crate::{bpf, pass, passes, profiler, verifier_log};

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

/// Try to apply rewrites to a single program via PassManager. Returns true if REJIT was called.
pub(crate) fn try_apply_one(prog_id: u32, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>, rollback_enabled: bool) -> Result<bool> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    if orig_insns.is_empty() {
        return Ok(false);
    }

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

    for _attempt in 0..=max_retries {
        let mut program = pass::BpfProgram::new(orig_insns.clone(), meta.clone());
        let pm = build_pipeline(pass_names);
        let mut local_ctx = ctx.clone();
        for disabled in &disabled_passes {
            local_ctx.policy.disabled_passes.push(disabled.clone());
        }

        let pipeline_result = pm.run_with_profiling(&mut program, &local_ctx, profiling.as_ref())?;

        if !pipeline_result.program_changed {
            return Ok(false);
        }

        if disabled_passes.is_empty() {
            println!(
                "  prog {} ({}): {} sites, {} -> {} insns",
                prog_id,
                info.name_str(),
                pipeline_result.total_sites_applied,
                orig_insns.len(),
                program.insns.len(),
            );
        }

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

        match bpf::bpf_prog_rejit(fd.as_raw_fd(), &program.insns, &fd_array) {
            Ok(_) => {
                if disabled_passes.is_empty() {
                    println!("    REJIT ok");
                } else {
                    println!(
                        "    REJIT ok (after disabling: {})",
                        disabled_passes.iter().cloned().collect::<Vec<_>>().join(", ")
                    );
                }
                return Ok(true);
            }
            Err(e) => {
                let err_msg = format!("{:#}", e);
                let log_text = err_msg
                    .find("verifier log:\n")
                    .map(|pos| &err_msg[pos + "verifier log:\n".len()..])
                    .unwrap_or("");

                // Attempt rollback if enabled.
                if rollback_enabled && !log_text.is_empty() {
                    if let Some(failed_pass) =
                        attribute_verifier_failure(log_text, &pipeline_result.attribution)
                    {
                        if !disabled_passes.contains(&failed_pass) {
                            let failed_pc = verifier_log::extract_failure_pc(log_text);
                            eprintln!(
                                "    WARN: pass '{}' caused verifier rejection{} for prog {} ({})",
                                failed_pass,
                                failed_pc
                                    .map_or(String::new(), |pc| format!(" at PC {}", pc)),
                                prog_id,
                                info.name_str(),
                            );
                            eprintln!(
                                "          Disabling '{}', retrying...",
                                failed_pass,
                            );
                            disabled_passes.insert(failed_pass);
                            continue;
                        }
                    }
                }

                // Cannot attribute or rollback disabled — report and fail.
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
