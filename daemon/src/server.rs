// SPDX-License-Identifier: MIT
//! Unix socket server implementation.

use std::collections::{HashMap, HashSet};
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::{Duration, Instant};

use anyhow::{Context, Result};
use serde::Serialize;

use crate::commands::{self, OptimizeMode};
use crate::invalidation::{MapInvalidationTracker, MapValueReader};
use crate::{bpf, insn, pass, profiler};

const DEFAULT_HOTNESS_WINDOW_MS: u64 = 250;

/// Global shutdown flag set by signal handler.
static SHUTDOWN_FLAG: AtomicBool = AtomicBool::new(false);

extern "C" fn handle_signal(_sig: libc::c_int) {
    SHUTDOWN_FLAG.store(true, Ordering::Relaxed);
}

fn register_signal_handlers() {
    unsafe {
        libc::signal(libc::SIGTERM, handle_signal as libc::sighandler_t);
        libc::signal(libc::SIGINT, handle_signal as libc::sighandler_t);
    }
}

fn process_invalidation_tick<A, F>(
    tracker: &std::sync::Arc<std::sync::Mutex<MapInvalidationTracker<A>>>,
    mut reoptimize: F,
) -> Result<Vec<u32>>
where
    A: MapValueReader,
    F: FnMut(u32) -> Result<()>,
{
    let invalidated = {
        let tracker = tracker
            .lock()
            .map_err(|_| anyhow::anyhow!("invalidation tracker lock poisoned"))?;
        tracker.check_for_invalidations()?
    };

    for prog_id in &invalidated {
        if let Err(err) = reoptimize(*prog_id) {
            eprintln!(
                "  invalidation: prog {} reoptimization failed: {:#}",
                prog_id, err
            );
        }
    }

    Ok(invalidated)
}

fn run_invalidation_tick_logged<A, F>(
    context: &str,
    tracker: &std::sync::Arc<std::sync::Mutex<MapInvalidationTracker<A>>>,
    reoptimize: F,
) where
    A: MapValueReader,
    F: FnMut(u32) -> Result<()>,
{
    if let Err(err) = process_invalidation_tick(tracker, reoptimize) {
        eprintln!("{context}: invalidation tick failed: {:#}", err);
    }
}

enum ProfilingState {
    Active(profiler::ProfilerSession),
    Frozen(profiler::ProfileSnapshot),
}

impl ProfilingState {
    fn snapshot(&self) -> Result<profiler::ProfileSnapshot> {
        match self {
            Self::Active(session) => session.snapshot(),
            Self::Frozen(snapshot) => Ok(snapshot.clone()),
        }
    }

    fn profiling_data_for(&self, prog_id: u32) -> Result<Option<pass::ProfilingData>> {
        Ok(self.snapshot()?.profiling_data_for(prog_id))
    }
}

#[derive(Clone, Debug)]
struct LiveProgramCandidate {
    prog_id: u32,
    prog_name: String,
    orig_insn_count: usize,
}

#[derive(Clone, Debug, Serialize)]
struct OptimizeAllOrderEntry {
    prog_id: u32,
    prog_name: String,
    orig_insn_count: usize,
    #[serde(skip_serializing_if = "Option::is_none")]
    hotness_score: Option<f64>,
    #[serde(skip_serializing_if = "Option::is_none")]
    run_cnt_delta: Option<u64>,
    #[serde(skip_serializing_if = "Option::is_none")]
    run_time_ns_delta: Option<u64>,
    #[serde(skip_serializing_if = "Option::is_none")]
    avg_ns: Option<f64>,
}

fn collect_live_program_candidates() -> Result<Vec<LiveProgramCandidate>> {
    let mut candidates = Vec::new();
    for prog_id in bpf::iter_prog_ids() {
        let prog_id = prog_id.context("enumerate program IDs for optimize-all")?;
        let (info, orig_insns) = bpf::get_orig_insns_by_id(prog_id)
            .with_context(|| format!("collect optimize-all metadata for prog {}", prog_id))?;
        let orig_insn_count = if !orig_insns.is_empty() {
            orig_insns.len()
        } else {
            info.orig_prog_len as usize / std::mem::size_of::<insn::BpfInsn>()
        };
        candidates.push(LiveProgramCandidate {
            prog_id,
            prog_name: info.name_str().to_string(),
            orig_insn_count,
        });
    }
    Ok(candidates)
}

fn default_optimize_all_order(candidates: &[LiveProgramCandidate]) -> Vec<OptimizeAllOrderEntry> {
    candidates
        .iter()
        .map(|candidate| OptimizeAllOrderEntry {
            prog_id: candidate.prog_id,
            prog_name: candidate.prog_name.clone(),
            orig_insn_count: candidate.orig_insn_count,
            hotness_score: None,
            run_cnt_delta: None,
            run_time_ns_delta: None,
            avg_ns: None,
        })
        .collect()
}

fn optimize_all_order_from_ranking(
    candidates: &[LiveProgramCandidate],
    ranking: &profiler::HotnessRanking,
    observation_window: Duration,
) -> Vec<OptimizeAllOrderEntry> {
    let candidates_by_id: HashMap<u32, &LiveProgramCandidate> = candidates
        .iter()
        .map(|candidate| (candidate.prog_id, candidate))
        .collect();
    let mut ranked_ids = HashSet::new();
    let mut ordered = Vec::with_capacity(candidates.len());

    for analysis in &ranking.ranked {
        let Some(candidate) = candidates_by_id.get(&analysis.prog_id) else {
            continue;
        };
        ranked_ids.insert(analysis.prog_id);
        ordered.push(OptimizeAllOrderEntry {
            prog_id: candidate.prog_id,
            prog_name: candidate.prog_name.clone(),
            orig_insn_count: candidate.orig_insn_count,
            hotness_score: Some(analysis.hotness_score(observation_window)),
            run_cnt_delta: Some(analysis.delta_run_cnt),
            run_time_ns_delta: Some(analysis.delta_run_time_ns),
            avg_ns: analysis.delta_avg_ns,
        });
    }

    for candidate in candidates {
        if ranked_ids.contains(&candidate.prog_id) {
            continue;
        }
        ordered.push(OptimizeAllOrderEntry {
            prog_id: candidate.prog_id,
            prog_name: candidate.prog_name.clone(),
            orig_insn_count: candidate.orig_insn_count,
            hotness_score: None,
            run_cnt_delta: None,
            run_time_ns_delta: None,
            avg_ns: None,
        });
    }

    ordered
}

// ── Serve (Unix socket server) ──────────────────────────────────────

pub(crate) fn cmd_serve(socket_path: &str, ctx: &pass::PassContext) -> Result<()> {
    use std::os::unix::net::UnixListener;

    register_signal_handlers();
    let tracker = commands::new_invalidation_tracker();
    let mut last_invalidation_check = Instant::now();
    let mut profiling_state: Option<ProfilingState> = None;

    // Remove stale socket file if it exists.
    let _ = std::fs::remove_file(socket_path);

    let listener = UnixListener::bind(socket_path)
        .with_context(|| format!("bind unix socket at {}", socket_path))?;
    listener.set_nonblocking(true)?;

    println!("serve: listening on {}", socket_path);

    while !SHUTDOWN_FLAG.load(Ordering::Relaxed) {
        if last_invalidation_check.elapsed() >= Duration::from_secs(1) {
            let tracker_for_apply = tracker.clone();
            run_invalidation_tick_logged("serve", &tracker, |prog_id| {
                let profiling = match profiling_state.as_ref() {
                    Some(state) => state.profiling_data_for(prog_id)?,
                    None => None,
                };
                commands::try_apply_one(
                    prog_id,
                    ctx,
                    profiling.as_ref(),
                    Some(&tracker_for_apply),
                    OptimizeMode::Apply,
                )?;
                Ok(())
            });
            last_invalidation_check = Instant::now();
        }

        match listener.accept() {
            Ok((stream, _addr)) => {
                if let Err(err) = handle_client(stream, ctx, &mut profiling_state, &tracker) {
                    eprintln!("serve: client error: {:#}", err);
                }
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
    if let Some(ProfilingState::Active(session)) = profiling_state.take() {
        if let Err(err) = session.stop() {
            eprintln!(
                "serve: failed to stop profiling session during shutdown: {:#}",
                err
            );
        }
    }
    let _ = std::fs::remove_file(socket_path);
    Ok(())
}

fn panic_payload_message(payload: &(dyn std::any::Any + Send)) -> String {
    if let Some(message) = payload.downcast_ref::<String>() {
        return message.clone();
    }
    if let Some(message) = payload.downcast_ref::<&'static str>() {
        return (*message).to_string();
    }
    "non-string panic payload".to_string()
}

fn panic_response(payload: Box<dyn std::any::Any + Send>) -> serde_json::Value {
    let message = panic_payload_message(payload.as_ref());
    eprintln!("serve: request panicked: {}", message);
    serde_json::json!({
        "status": "error",
        "message": format!("request handler panicked: {}", message),
    })
}

fn handle_client(
    stream: std::os::unix::net::UnixStream,
    ctx: &pass::PassContext,
    profiling_state: &mut Option<ProfilingState>,
    tracker: &commands::SharedInvalidationTracker,
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
            Ok(req) => match std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| {
                process_request(&req, ctx, profiling_state, tracker)
            })) {
                Ok(response) => response,
                Err(payload) => panic_response(payload),
            },
            Err(e) => {
                serde_json::json!({"status": "error", "message": format!("invalid JSON: {}", e)})
            }
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
    profiling_state: &mut Option<ProfilingState>,
    tracker: &commands::SharedInvalidationTracker,
) -> serde_json::Value {
    fn parse_request_pass_list(
        req: &serde_json::Value,
        key: &str,
    ) -> std::result::Result<Option<Vec<String>>, String> {
        let Some(value) = req.get(key) else {
            return Ok(None);
        };
        let array = value
            .as_array()
            .ok_or_else(|| format!("{key} must be a JSON string array"))?;
        let mut passes = Vec::with_capacity(array.len());
        for entry in array {
            let raw_name = entry
                .as_str()
                .ok_or_else(|| format!("{key} entries must be strings"))?;
            let name = raw_name.trim();
            if name.is_empty() {
                return Err(format!("{key} entries must not be blank"));
            }
            passes.push(name.to_string());
        }
        Ok(Some(passes))
    }

    fn request_context(
        req: &serde_json::Value,
        base_ctx: &pass::PassContext,
    ) -> std::result::Result<pass::PassContext, String> {
        let mut local_ctx = base_ctx.clone();
        if let Some(enabled_passes) = parse_request_pass_list(req, "enabled_passes")? {
            crate::passes::validate_pass_names(&enabled_passes)
                .map_err(|err| format!("invalid enabled_passes: {err}"))?;
            local_ctx.policy.enabled_passes = enabled_passes;
        }
        if let Some(disabled_passes) = parse_request_pass_list(req, "disabled_passes")? {
            crate::passes::validate_pass_names(&disabled_passes)
                .map_err(|err| format!("invalid disabled_passes: {err}"))?;
            local_ctx.policy.disabled_passes = disabled_passes;
        }
        Ok(local_ctx)
    }

    fn request_mode(req: &serde_json::Value) -> std::result::Result<OptimizeMode, String> {
        if let Some(value) = req.get("dry_run") {
            let dry_run = value
                .as_bool()
                .ok_or_else(|| "dry_run must be a JSON boolean".to_string())?;
            return Ok(if dry_run {
                OptimizeMode::DryRun
            } else {
                OptimizeMode::Apply
            });
        }

        if let Some(value) = req.get("apply") {
            let apply = value
                .as_bool()
                .ok_or_else(|| "apply must be a JSON boolean".to_string())?;
            return Ok(if apply {
                OptimizeMode::Apply
            } else {
                OptimizeMode::DryRun
            });
        }

        Ok(OptimizeMode::Apply)
    }

    fn request_interval(req: &serde_json::Value) -> std::result::Result<Duration, String> {
        let value = req
            .get("interval_ms")
            .ok_or_else(|| "missing interval_ms".to_string())?;
        let interval_ms = value
            .as_u64()
            .ok_or_else(|| "interval_ms must be a JSON integer".to_string())?;
        if interval_ms == 0 {
            return Err("interval_ms must be greater than zero".to_string());
        }
        Ok(Duration::from_millis(interval_ms))
    }

    fn request_optional_interval(
        req: &serde_json::Value,
        key: &str,
        default_ms: u64,
    ) -> std::result::Result<Duration, String> {
        let Some(value) = req.get(key) else {
            return Ok(Duration::from_millis(default_ms));
        };
        let interval_ms = value
            .as_u64()
            .ok_or_else(|| format!("{key} must be a JSON integer"))?;
        if interval_ms == 0 {
            return Err(format!("{key} must be greater than zero"));
        }
        Ok(Duration::from_millis(interval_ms))
    }

    fn request_path<'a>(
        req: &'a serde_json::Value,
        key: &str,
    ) -> std::result::Result<&'a str, String> {
        let value = req.get(key).ok_or_else(|| format!("missing {key}"))?;
        value
            .as_str()
            .ok_or_else(|| format!("{key} must be a JSON string"))
    }

    fn request_profile_snapshot(
        profiling_state: &Option<ProfilingState>,
    ) -> std::result::Result<Option<profiler::ProfileSnapshot>, String> {
        match profiling_state.as_ref() {
            Some(state) => state.snapshot().map(Some).map_err(|err| format!("{err:#}")),
            None => Ok(None),
        }
    }

    let cmd = req.get("cmd").and_then(|v| v.as_str()).unwrap_or("");
    let local_ctx = match request_context(req, ctx) {
        Ok(value) => value,
        Err(message) => return serde_json::json!({"status": "error", "message": message}),
    };
    match cmd {
        "optimize" => {
            let prog_id = match req.get("prog_id").and_then(|v| v.as_u64()) {
                Some(id) => id as u32,
                None => return serde_json::json!({"status": "error", "message": "missing prog_id"}),
            };
            let mode = match request_mode(req) {
                Ok(mode) => mode,
                Err(message) => {
                    return serde_json::json!({"status": "error", "message": message});
                }
            };
            let profile_snapshot = match request_profile_snapshot(profiling_state) {
                Ok(snapshot) => snapshot,
                Err(message) => {
                    return serde_json::json!({"status": "error", "message": message});
                }
            };
            let profiling = profile_snapshot
                .as_ref()
                .and_then(|snapshot| snapshot.profiling_data_for(prog_id));
            match commands::try_apply_one(
                prog_id,
                &local_ctx,
                profiling.as_ref(),
                Some(tracker),
                mode,
            ) {
                Ok(result) => {
                    // The optimize response already embeds the full structured
                    // result, including any deduplicated `inlined_map_entries`,
                    // so serve mode does not need a second debug channel.
                    match serde_json::to_value(&result) {
                        Ok(v) => v,
                        Err(e) => serde_json::json!({
                            "status": "error",
                            "message": format!("failed to serialize result: {}", e)
                        }),
                    }
                }
                Err(e) => serde_json::json!({"status": "error", "message": format!("{:#}", e)}),
            }
        }
        "optimize-all" => {
            let hotness_window = match request_optional_interval(
                req,
                "hotness_window_ms",
                DEFAULT_HOTNESS_WINDOW_MS,
            ) {
                Ok(interval) => interval,
                Err(message) => {
                    return serde_json::json!({"status": "error", "message": message});
                }
            };
            let profile_snapshot = match request_profile_snapshot(profiling_state) {
                Ok(snapshot) => snapshot,
                Err(message) => {
                    return serde_json::json!({"status": "error", "message": message});
                }
            };
            let candidates = match collect_live_program_candidates() {
                Ok(candidates) => candidates,
                Err(err) => {
                    return serde_json::json!({
                        "status": "error",
                        "message": format!("failed to collect optimize-all candidates: {err:#}"),
                    });
                }
            };
            let mut program_order = default_optimize_all_order(&candidates);
            let mut profiling_source = "none";
            let mut observation_window_ms: Option<u64> = None;
            let mut on_demand_profiles: HashMap<u32, pass::ProfilingData> = HashMap::new();

            if let Some(snapshot) = profile_snapshot.as_ref() {
                let observation_window = Duration::from_millis(snapshot.duration_ms.max(1));
                let ranking = match snapshot.hotness_ranking() {
                    Ok(ranking) => ranking,
                    Err(err) => {
                        return serde_json::json!({
                            "status": "error",
                            "message": format!(
                                "failed to rank loaded profile snapshot by hotness: {err:#}"
                            ),
                        });
                    }
                };
                program_order =
                    optimize_all_order_from_ranking(&candidates, &ranking, observation_window);
                profiling_source = "snapshot";
                observation_window_ms = Some(observation_window.as_millis() as u64);
            } else if candidates.len() > 1 {
                let prog_ids = candidates
                    .iter()
                    .map(|candidate| candidate.prog_id)
                    .collect::<Vec<_>>();
                match profiler::collect_hotness_ranking(&prog_ids, hotness_window) {
                    Ok((ranking, observation_window)) => {
                        program_order = optimize_all_order_from_ranking(
                            &candidates,
                            &ranking,
                            observation_window,
                        );
                        profiling_source = "stats_window";
                        observation_window_ms = Some(observation_window.as_millis() as u64);
                    }
                    Err(err) => {
                        return serde_json::json!({
                            "status": "error",
                            "message": format!(
                                "failed to rank optimize-all programs by hotness: {err:#}"
                            ),
                        });
                    }
                }
            } else if let Some(candidate) = candidates.first() {
                match profiler::bpf_stats_enabled() {
                    Ok(true) => {
                        match profiler::collect_program_profiling(candidate.prog_id, hotness_window)
                        {
                            Ok((profiling, analysis)) => {
                                on_demand_profiles.insert(candidate.prog_id, profiling);
                                let ranking = profiler::HotnessRanking::from_analyses(
                                    vec![analysis],
                                    hotness_window,
                                );
                                program_order = optimize_all_order_from_ranking(
                                    &candidates,
                                    &ranking,
                                    hotness_window,
                                );
                                profiling_source = "stats_window_single";
                                observation_window_ms = Some(hotness_window.as_millis() as u64);
                            }
                            Err(err) => {
                                return serde_json::json!({
                                    "status": "error",
                                    "message": format!(
                                        "failed to collect one-shot profiling for prog {}: {err:#}",
                                        candidate.prog_id
                                    ),
                                });
                            }
                        }
                    }
                    Ok(false) => {}
                    Err(err) => {
                        return serde_json::json!({
                            "status": "error",
                            "message": format!("failed to query bpf stats state: {err:#}"),
                        });
                    }
                }
            }
            let mut applied = 0u32;
            let mut errors = 0u32;
            let total = program_order.len() as u32;
            for entry in &program_order {
                let prog_id = entry.prog_id;
                let snapshot_profiling = profile_snapshot
                    .as_ref()
                    .and_then(|snapshot| snapshot.profiling_data_for(prog_id));
                let profiling = on_demand_profiles
                    .get(&prog_id)
                    .or(snapshot_profiling.as_ref());
                match commands::try_apply_one(
                    prog_id,
                    &local_ctx,
                    profiling,
                    Some(tracker),
                    OptimizeMode::Apply,
                ) {
                    Ok(result) => {
                        if result.summary.applied {
                            applied += 1;
                        }
                    }
                    Err(_) => errors += 1,
                }
            }
            serde_json::json!({
                "status": "ok",
                "total": total,
                "applied": applied,
                "errors": errors,
                "profiling_source": profiling_source,
                "hotness_window_ms": observation_window_ms,
                "program_order": program_order,
            })
        }
        "profile-start" => {
            let interval = match request_interval(req) {
                Ok(interval) => interval,
                Err(message) => {
                    return serde_json::json!({"status": "error", "message": message});
                }
            };
            if matches!(profiling_state.as_ref(), Some(ProfilingState::Active(_))) {
                return serde_json::json!({
                    "status": "error",
                    "message": "profiling is already active",
                });
            }
            match profiler::ProfilerSession::start(interval) {
                Ok(session) => {
                    *profiling_state = Some(ProfilingState::Active(session));
                    serde_json::json!({"status": "ok"})
                }
                Err(err) => {
                    serde_json::json!({"status": "error", "message": format!("{err:#}")})
                }
            }
        }
        "profile-stop" => {
            let current_state = match profiling_state.take() {
                Some(state) => state,
                None => {
                    return serde_json::json!({
                        "status": "error",
                        "message": "no profiling session is active",
                    });
                }
            };

            match current_state {
                ProfilingState::Active(session) => match session.stop() {
                    Ok(snapshot) => {
                        let summary = snapshot.summary();
                        *profiling_state = Some(ProfilingState::Frozen(snapshot));
                        serde_json::json!({
                            "status": "ok",
                            "programs_profiled": summary.programs_profiled,
                            "duration_ms": summary.duration_ms,
                        })
                    }
                    Err(err) => {
                        serde_json::json!({"status": "error", "message": format!("{err:#}")})
                    }
                },
                ProfilingState::Frozen(snapshot) => {
                    *profiling_state = Some(ProfilingState::Frozen(snapshot));
                    serde_json::json!({
                        "status": "error",
                        "message": "profiling is not active",
                    })
                }
            }
        }
        "profile-save" => {
            let path = match request_path(req, "path") {
                Ok(path) => path,
                Err(message) => {
                    return serde_json::json!({"status": "error", "message": message});
                }
            };
            let snapshot = match request_profile_snapshot(profiling_state) {
                Ok(Some(snapshot)) => snapshot,
                Ok(None) => {
                    return serde_json::json!({
                        "status": "error",
                        "message": "no profile data available",
                    });
                }
                Err(message) => {
                    return serde_json::json!({"status": "error", "message": message});
                }
            };
            match snapshot.save_to_path(std::path::Path::new(path)) {
                Ok(()) => serde_json::json!({
                    "status": "ok",
                    "path": path,
                    "programs": snapshot.programs_profiled(),
                }),
                Err(err) => {
                    serde_json::json!({"status": "error", "message": format!("{err:#}")})
                }
            }
        }
        "profile-load" => {
            let path = match request_path(req, "path") {
                Ok(path) => path,
                Err(message) => {
                    return serde_json::json!({"status": "error", "message": message});
                }
            };
            if matches!(profiling_state.as_ref(), Some(ProfilingState::Active(_))) {
                return serde_json::json!({
                    "status": "error",
                    "message": "profiling is active; stop it before loading a snapshot",
                });
            }
            match profiler::ProfileSnapshot::load_from_path(std::path::Path::new(path)) {
                Ok(snapshot) => {
                    let programs_loaded = snapshot.programs_profiled();
                    *profiling_state = Some(ProfilingState::Frozen(snapshot));
                    serde_json::json!({
                        "status": "ok",
                        "programs_loaded": programs_loaded,
                    })
                }
                Err(err) => {
                    serde_json::json!({"status": "error", "message": format!("{err:#}")})
                }
            }
        }
        "status" => {
            let profiling = match profiling_state.as_ref() {
                Some(ProfilingState::Active(_)) => "active",
                Some(ProfilingState::Frozen(_)) => "loaded",
                None => "none",
            };
            serde_json::json!({
                "status": "ok",
                "version": env!("CARGO_PKG_VERSION"),
                "profiling": profiling,
                "available_passes_help": crate::passes::available_passes_help(),
            })
        }
        _ => {
            serde_json::json!({"status": "error", "message": format!("unknown command: {}", cmd)})
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::BTreeMap;
    use std::collections::HashMap;
    use std::sync::{Arc, Mutex};
    use std::time::{SystemTime, UNIX_EPOCH};

    use crate::invalidation::{BatchLookupValue, MapInvalidationTracker};

    #[derive(Clone, Debug, Default)]
    struct MockMapValueReader {
        values: Arc<Mutex<HashMap<u32, HashMap<Vec<u8>, Vec<u8>>>>>,
    }

    impl MockMapValueReader {
        fn set_value(&self, map_fd: u32, key: Vec<u8>, value: Vec<u8>) {
            self.values
                .lock()
                .expect("values lock should not be poisoned")
                .entry(map_fd)
                .or_default()
                .insert(key, value);
        }
    }

    impl MapValueReader for MockMapValueReader {
        fn lookup_values_batch(
            &self,
            map_fd: u32,
            keys: &[Vec<u8>],
        ) -> Result<Vec<BatchLookupValue>> {
            let values = self
                .values
                .lock()
                .expect("values lock should not be poisoned");
            let map_values = values.get(&map_fd).cloned().unwrap_or_default();

            Ok(keys
                .iter()
                .cloned()
                .map(|key| BatchLookupValue {
                    value: map_values.get(&key).cloned(),
                    key,
                })
                .collect())
        }
    }

    #[test]
    fn process_invalidation_tick_reoptimizes_invalidated_programs() {
        let reader = MockMapValueReader::default();
        reader.set_value(7, 1u32.to_le_bytes().to_vec(), 99u32.to_le_bytes().to_vec());

        let mut tracker = MapInvalidationTracker::new(reader);
        tracker.record_inline_site(
            101,
            7,
            1u32.to_le_bytes().to_vec(),
            11u32.to_le_bytes().to_vec(),
        );
        let tracker = Arc::new(Mutex::new(tracker));
        let seen = Arc::new(Mutex::new(Vec::new()));
        let seen_for_closure = seen.clone();

        let invalidated = process_invalidation_tick(&tracker, move |prog_id| {
            seen_for_closure
                .lock()
                .expect("seen lock should not be poisoned")
                .push(prog_id);
            Ok(())
        })
        .expect("process_invalidation_tick should succeed");

        assert_eq!(invalidated, vec![101]);
        assert_eq!(
            *seen.lock().expect("seen lock should not be poisoned"),
            vec![101]
        );
    }

    #[test]
    fn panic_payload_message_formats_strings() {
        let payload: Box<dyn std::any::Any + Send> = Box::new(String::from("boom"));
        assert_eq!(panic_payload_message(payload.as_ref()), "boom");
    }

    #[test]
    fn panic_payload_message_formats_static_str() {
        let payload: Box<dyn std::any::Any + Send> = Box::new("boom");
        assert_eq!(panic_payload_message(payload.as_ref()), "boom");
    }

    #[test]
    fn panic_payload_message_handles_unknown_payloads() {
        let payload: Box<dyn std::any::Any + Send> = Box::new(42usize);
        assert_eq!(
            panic_payload_message(payload.as_ref()),
            "non-string panic payload"
        );
    }

    #[test]
    fn process_request_accepts_valid_disabled_passes() {
        let req = serde_json::json!({
            "cmd": "status",
            "disabled_passes": ["map_inline"],
        });
        let tracker = commands::new_invalidation_tracker();
        let mut profiling_state = None;
        let response = process_request(
            &req,
            &pass::PassContext::test_default(),
            &mut profiling_state,
            &tracker,
        );

        assert_eq!(response["status"], "ok");
    }

    #[test]
    fn process_request_rejects_unknown_enabled_passes() {
        let req = serde_json::json!({
            "cmd": "status",
            "enabled_passes": ["skb_load_bytes"],
        });
        let tracker = commands::new_invalidation_tracker();
        let mut profiling_state = None;
        let response = process_request(
            &req,
            &pass::PassContext::test_default(),
            &mut profiling_state,
            &tracker,
        );

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["message"],
            "invalid enabled_passes: unknown pass name(s): skb_load_bytes"
        );
    }

    #[test]
    fn process_request_rejects_unknown_disabled_passes() {
        let req = serde_json::json!({
            "cmd": "status",
            "disabled_passes": ["bulk_mem"],
        });
        let tracker = commands::new_invalidation_tracker();
        let mut profiling_state = None;
        let response = process_request(
            &req,
            &pass::PassContext::test_default(),
            &mut profiling_state,
            &tracker,
        );

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["message"],
            "invalid disabled_passes: unknown pass name(s): bulk_mem"
        );
    }

    #[test]
    fn process_request_rejects_blank_enabled_pass_name() {
        let req = serde_json::json!({
            "cmd": "status",
            "enabled_passes": ["   "],
        });
        let tracker = commands::new_invalidation_tracker();
        let mut profiling_state = None;
        let response = process_request(
            &req,
            &pass::PassContext::test_default(),
            &mut profiling_state,
            &tracker,
        );

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["message"],
            "enabled_passes entries must not be blank"
        );
    }

    #[test]
    fn process_request_rejects_blank_disabled_pass_name() {
        let req = serde_json::json!({
            "cmd": "status",
            "disabled_passes": ["   "],
        });
        let tracker = commands::new_invalidation_tracker();
        let mut profiling_state = None;
        let response = process_request(
            &req,
            &pass::PassContext::test_default(),
            &mut profiling_state,
            &tracker,
        );

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["message"],
            "disabled_passes entries must not be blank"
        );
    }

    #[test]
    fn process_request_rejects_non_boolean_dry_run() {
        let req = serde_json::json!({
            "cmd": "optimize",
            "prog_id": 1,
            "dry_run": "yes",
        });
        let tracker = commands::new_invalidation_tracker();
        let mut profiling_state = None;
        let response = process_request(
            &req,
            &pass::PassContext::test_default(),
            &mut profiling_state,
            &tracker,
        );

        assert_eq!(response["status"], "error");
        assert_eq!(response["message"], "dry_run must be a JSON boolean");
    }

    #[test]
    fn process_request_rejects_zero_profile_interval() {
        let req = serde_json::json!({
            "cmd": "profile-start",
            "interval_ms": 0,
        });
        let tracker = commands::new_invalidation_tracker();
        let mut profiling_state = None;
        let response = process_request(
            &req,
            &pass::PassContext::test_default(),
            &mut profiling_state,
            &tracker,
        );

        assert_eq!(response["status"], "error");
        assert_eq!(response["message"], "interval_ms must be greater than zero");
    }

    #[test]
    fn process_request_profile_save_and_load_round_trip() {
        let timestamp = SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .expect("clock should be after epoch")
            .as_nanos();
        let path = std::env::temp_dir().join(format!("bpfrejit-profile-{timestamp}.json"));
        let tracker = commands::new_invalidation_tracker();
        let snapshot = profiler::ProfileSnapshot {
            version: profiler::ProfileSnapshot::VERSION,
            collected_at: "2026-03-28T00:00:00Z".to_string(),
            duration_ms: 5_000,
            programs: BTreeMap::from([(
                "123".to_string(),
                profiler::ProgramProfile {
                    run_cnt: 10_000,
                    run_time_ns: 500_000,
                    avg_ns: Some(50.0),
                    branch_miss_rate: Some(0.05),
                },
            )]),
        };
        let mut profiling_state = Some(ProfilingState::Frozen(snapshot.clone()));

        let save_response = process_request(
            &serde_json::json!({
                "cmd": "profile-save",
                "path": path.display().to_string(),
            }),
            &pass::PassContext::test_default(),
            &mut profiling_state,
            &tracker,
        );

        assert_eq!(save_response["status"], "ok");
        assert_eq!(save_response["programs"], 1);

        let mut loaded_state = None;
        let load_response = process_request(
            &serde_json::json!({
                "cmd": "profile-load",
                "path": path.display().to_string(),
            }),
            &pass::PassContext::test_default(),
            &mut loaded_state,
            &tracker,
        );

        assert_eq!(load_response["status"], "ok");
        assert_eq!(load_response["programs_loaded"], 1);
        match loaded_state {
            Some(ProfilingState::Frozen(loaded)) => assert_eq!(loaded, snapshot),
            _ => panic!("expected frozen profile state after load"),
        }

        std::fs::remove_file(&path).expect("profile snapshot cleanup should succeed");
    }
}
