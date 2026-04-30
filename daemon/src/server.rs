// SPDX-License-Identifier: MIT
//! Unix socket server implementation.

use std::collections::{HashMap, HashSet};
use std::path::Path;
use std::sync::atomic::{AtomicBool, AtomicU32, Ordering};
use std::sync::{Arc, Mutex};
use std::time::{Duration, Instant};

use anyhow::{Context, Result};
use rayon::prelude::*;
use serde::Serialize;

use crate::bpf;
use crate::commands::{self, CliConfig, OptimizeMode};
use crate::invalidation::{MapInvalidationTracker, MapValueReader};

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
    reoptimize: F,
) -> Result<Vec<u32>>
where
    A: MapValueReader,
    F: Fn(u32) -> Result<()> + Sync,
{
    let invalidated = {
        let tracker = tracker
            .lock()
            .map_err(|_| anyhow::anyhow!("invalidation tracker lock poisoned"))?;
        tracker.check_for_invalidations()?
    };

    let failures = Mutex::new(Vec::new());
    let result = invalidated.par_iter().try_for_each(|prog_id| {
        reoptimize(*prog_id).map_err(|err| {
            let message = format!("{err:#}");
            match failures.lock() {
                Ok(mut failures) => failures.push((*prog_id, message.clone())),
                Err(_) => {
                    return anyhow::anyhow!(
                        "invalidation reoptimization failure list lock poisoned"
                    );
                }
            }
            anyhow::anyhow!("prog {}: {}", prog_id, message)
        })
    });

    if let Err(err) = result {
        let mut failures = failures
            .into_inner()
            .map_err(|_| anyhow::anyhow!("invalidation failure list lock poisoned"))?;
        if failures.is_empty() {
            failures.push((0, format!("{err:#}")));
        }
        failures.sort_by_key(|(prog_id, _)| *prog_id);
        let failures = failures
            .into_iter()
            .map(|(prog_id, err)| {
                if prog_id == 0 {
                    err
                } else {
                    format!("prog {prog_id}: {err}")
                }
            })
            .collect::<Vec<_>>();
        anyhow::bail!(
            "invalidation reoptimization failed for {}",
            failures.join("; ")
        );
    }

    Ok(invalidated)
}

fn run_invalidation_tick_logged<A, F>(
    context: &str,
    tracker: &std::sync::Arc<std::sync::Mutex<MapInvalidationTracker<A>>>,
    reoptimize: F,
) -> Result<()>
where
    A: MapValueReader,
    F: Fn(u32) -> Result<()> + Sync,
{
    process_invalidation_tick(tracker, reoptimize)
        .with_context(|| format!("{context}: invalidation tick failed"))?;
    Ok(())
}

enum ProfilingState {
    Active(commands::ProfileSession),
    Frozen(commands::FrozenProfile),
}

#[derive(Default)]
struct ReoptimizationState {
    enabled_passes_by_prog: HashMap<u32, Vec<String>>,
}

impl ReoptimizationState {
    fn remember_result(
        &mut self,
        prog_id: u32,
        requested_passes: Option<&[String]>,
        result: &commands::OptimizeOneResult,
        mode: OptimizeMode,
    ) {
        if !matches!(mode, OptimizeMode::Apply)
            || result.status != "ok"
            || result.inlined_map_entries.is_empty()
        {
            self.enabled_passes_by_prog.remove(&prog_id);
            return;
        }

        let enabled_passes = requested_passes
            .map(|passes| passes.to_vec())
            .unwrap_or_else(|| {
                result
                    .passes
                    .iter()
                    .map(|pass| pass.pass_name.clone())
                    .collect()
            });
        self.enabled_passes_by_prog.insert(prog_id, enabled_passes);
    }

    fn enabled_passes_for(&self, prog_id: u32) -> Option<Vec<String>> {
        self.enabled_passes_by_prog.get(&prog_id).cloned()
    }
}

type SharedReoptimizationState = Arc<Mutex<ReoptimizationState>>;

fn new_reoptimization_state() -> SharedReoptimizationState {
    Arc::new(Mutex::new(ReoptimizationState::default()))
}

fn remember_reoptimization_result(
    state: &SharedReoptimizationState,
    prog_id: u32,
    enabled_passes: Option<&[String]>,
    result: &commands::OptimizeOneResult,
    mode: OptimizeMode,
) -> Result<()> {
    state
        .lock()
        .map_err(|_| anyhow::anyhow!("reoptimization state lock poisoned"))?
        .remember_result(prog_id, enabled_passes, result, mode);
    Ok(())
}

fn reoptimization_passes_for(
    state: &SharedReoptimizationState,
    prog_id: u32,
) -> Result<Vec<String>> {
    state
        .lock()
        .map_err(|_| anyhow::anyhow!("reoptimization state lock poisoned"))?
        .enabled_passes_for(prog_id)
        .ok_or_else(|| anyhow::anyhow!("missing original enabled_passes for prog {prog_id}"))
}

impl ProfilingState {
    fn label(&self) -> &'static str {
        match self {
            Self::Active(_) => "active",
            Self::Frozen(_) => "loaded",
        }
    }

    fn profile_path_for(&self, prog_id: u32) -> Option<std::path::PathBuf> {
        match self {
            Self::Frozen(profile) => profile.profile_path_for(prog_id),
            Self::Active(_) => None,
        }
    }

    fn duration_ms(&self) -> u64 {
        match self {
            Self::Active(session) => session.duration_ms(),
            Self::Frozen(profile) => profile.duration_ms(),
        }
    }

    fn programs_profiled(&self) -> usize {
        match self {
            Self::Active(_) => 0,
            Self::Frozen(profile) => profile.programs_profiled(),
        }
    }
}

#[derive(Clone, Debug, Serialize)]
struct OptimizeAllOrderEntry {
    prog_id: u32,
    prog_name: String,
    #[serde(skip_serializing_if = "Option::is_none")]
    prog_type: Option<String>,
    #[serde(skip_serializing_if = "Option::is_none")]
    hotness_score: Option<f64>,
    #[serde(skip_serializing_if = "Option::is_none")]
    run_cnt_delta: Option<u64>,
    #[serde(skip_serializing_if = "Option::is_none")]
    run_time_ns_delta: Option<u64>,
    #[serde(skip_serializing_if = "Option::is_none")]
    avg_ns: Option<f64>,
}

struct ProgramWatcher {
    seen: HashSet<u32>,
}

impl ProgramWatcher {
    fn from_live() -> Result<Self> {
        let mut seen = HashSet::new();
        for prog_id in bpf::iter_prog_ids() {
            let prog_id = prog_id.context("initialize BPF program watcher")?;
            seen.insert(prog_id);
        }
        Ok(Self { seen })
    }

    fn tick(&mut self) -> Result<()> {
        for prog_id in bpf::iter_prog_ids() {
            let prog_id = prog_id.context("watch live BPF programs")?;
            if self.seen.insert(prog_id) {
                eprintln!("serve: observed new BPF program id {prog_id}");
            }
        }
        Ok(())
    }
}

fn remove_socket_file_if_present(socket_path: &str) -> Result<()> {
    match std::fs::remove_file(socket_path) {
        Ok(()) => Ok(()),
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => Ok(()),
        Err(err) => Err(err).with_context(|| format!("remove stale socket file {socket_path}")),
    }
}

pub(crate) fn cmd_serve(socket_path: &str) -> Result<()> {
    use std::os::unix::net::UnixListener;

    register_signal_handlers();
    let config = CliConfig::from_env();
    let tracker = commands::new_invalidation_tracker();
    let reoptimization_state = new_reoptimization_state();
    let mut last_invalidation_check = Instant::now();
    let mut last_watch_check = Instant::now();
    let mut watcher = ProgramWatcher::from_live()?;
    let mut profiling_state: Option<ProfilingState> = None;

    commands::validate_failure_export_root_from_env()?;
    remove_socket_file_if_present(socket_path)?;

    let listener = UnixListener::bind(socket_path)
        .with_context(|| format!("bind unix socket at {socket_path}"))?;
    listener.set_nonblocking(true)?;

    println!("serve: listening on {socket_path}");

    while !SHUTDOWN_FLAG.load(Ordering::Relaxed) {
        if last_watch_check.elapsed() >= Duration::from_secs(1) {
            watcher.tick()?;
            last_watch_check = Instant::now();
        }

        if last_invalidation_check.elapsed() >= Duration::from_secs(1) {
            let tracker_for_apply = tracker.clone();
            let reoptimization_state_for_apply = reoptimization_state.clone();
            run_invalidation_tick_logged("serve", &tracker, |prog_id| {
                let profile_path = profiling_state
                    .as_ref()
                    .and_then(|state| state.profile_path_for(prog_id));
                let enabled_passes =
                    reoptimization_passes_for(&reoptimization_state_for_apply, prog_id)?;
                let result = commands::try_reapply_one(
                    prog_id,
                    &config,
                    Some(&enabled_passes),
                    profile_path.as_deref(),
                    Some(&tracker_for_apply),
                    OptimizeMode::Apply,
                )?;
                if result.status != "ok" {
                    anyhow::bail!(
                        "{}",
                        result.error_message.unwrap_or_else(|| {
                            format!(
                                "optimize prog {} returned status {}",
                                prog_id, result.status
                            )
                        })
                    );
                }
                remember_reoptimization_result(
                    &reoptimization_state_for_apply,
                    prog_id,
                    Some(&enabled_passes),
                    &result,
                    OptimizeMode::Apply,
                )?;
                Ok(())
            })?;
            last_invalidation_check = Instant::now();
        }

        match listener.accept() {
            Ok((stream, _addr)) => {
                if let Err(err) = handle_client(
                    stream,
                    &config,
                    &mut profiling_state,
                    &tracker,
                    &reoptimization_state,
                ) {
                    eprintln!("serve: client error: {err:#}");
                }
            }
            Err(ref e) if e.kind() == std::io::ErrorKind::WouldBlock => {
                std::thread::sleep(Duration::from_millis(100));
            }
            Err(e) => {
                eprintln!("serve: accept error: {e}");
            }
        }
    }

    println!("serve: shutting down");
    if let Some(ProfilingState::Active(session)) = profiling_state.take() {
        if let Err(err) = commands::stop_profile(session) {
            eprintln!("serve: failed to stop profiling session during shutdown: {err:#}");
        }
    }
    remove_socket_file_if_present(socket_path)?;
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
    eprintln!("serve: request panicked: {message}");
    serde_json::json!({
        "status": "error",
        "error_message": format!("request handler panicked: {message}"),
    })
}

fn handle_client(
    stream: std::os::unix::net::UnixStream,
    config: &CliConfig,
    profiling_state: &mut Option<ProfilingState>,
    tracker: &commands::SharedInvalidationTracker,
    reoptimization_state: &SharedReoptimizationState,
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
                process_request(&req, config, profiling_state, tracker, reoptimization_state)
            })) {
                Ok(response) => response,
                Err(payload) => panic_response(payload),
            },
            Err(e) => {
                serde_json::json!({"status": "error", "error_message": format!("invalid JSON: {e}")})
            }
        };

        let mut resp_str = serde_json::to_string(&response)?;
        resp_str.push('\n');
        writer.write_all(resp_str.as_bytes())?;
        writer.flush()?;
    }

    Ok(())
}

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

fn request_enabled_passes(
    req: &serde_json::Value,
) -> std::result::Result<Option<Vec<String>>, String> {
    parse_request_pass_list(req, "enabled_passes")
}

fn required_enabled_passes<'a>(
    cmd: &str,
    enabled_passes: &'a Option<Vec<String>>,
) -> std::result::Result<&'a [String], String> {
    match enabled_passes.as_deref() {
        Some([]) => Err(format!("{cmd} requires at least one enabled_passes entry")),
        Some(passes) => Ok(passes),
        None => Err(format!("{cmd} requires enabled_passes")),
    }
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

    Ok(OptimizeMode::Apply)
}

fn request_interval_ms(req: &serde_json::Value) -> std::result::Result<u64, String> {
    let value = req
        .get("interval_ms")
        .ok_or_else(|| "missing interval_ms".to_string())?;
    let interval_ms = value
        .as_u64()
        .ok_or_else(|| "interval_ms must be a JSON integer".to_string())?;
    if interval_ms == 0 {
        return Err("interval_ms must be greater than zero".to_string());
    }
    Ok(interval_ms)
}

fn request_path<'a>(req: &'a serde_json::Value, key: &str) -> std::result::Result<&'a str, String> {
    let value = req.get(key).ok_or_else(|| format!("missing {key}"))?;
    value
        .as_str()
        .ok_or_else(|| format!("{key} must be a JSON string"))
}

fn error_json(message: impl Into<String>) -> serde_json::Value {
    serde_json::json!({
        "status": "error",
        "error_message": message.into(),
    })
}

fn serialize_or_error<T: Serialize>(value: T) -> serde_json::Value {
    match serde_json::to_value(value) {
        Ok(v) => v,
        Err(e) => error_json(format!("failed to serialize result: {e}")),
    }
}

fn process_request(
    req: &serde_json::Value,
    config: &CliConfig,
    profiling_state: &mut Option<ProfilingState>,
    tracker: &commands::SharedInvalidationTracker,
    reoptimization_state: &SharedReoptimizationState,
) -> serde_json::Value {
    let cmd = req.get("cmd").and_then(|v| v.as_str()).unwrap_or("");
    let enabled_passes = match request_enabled_passes(req) {
        Ok(value) => value,
        Err(message) => return error_json(message),
    };

    match cmd {
        "optimize" => {
            let requested_passes = match required_enabled_passes(cmd, &enabled_passes) {
                Ok(passes) => passes,
                Err(message) => return error_json(message),
            };
            let prog_id = match req.get("prog_id").and_then(|v| v.as_u64()) {
                Some(id) => id as u32,
                None => return error_json("missing prog_id"),
            };
            let mode = match request_mode(req) {
                Ok(mode) => mode,
                Err(message) => return error_json(message),
            };
            let profile_path = profiling_state
                .as_ref()
                .and_then(|state| state.profile_path_for(prog_id));
            match commands::try_apply_one(
                prog_id,
                config,
                Some(requested_passes),
                profile_path.as_deref(),
                Some(tracker),
                mode,
            ) {
                Ok(result) => match remember_reoptimization_result(
                    reoptimization_state,
                    prog_id,
                    Some(requested_passes),
                    &result,
                    mode,
                ) {
                    Ok(()) => serialize_or_error(result),
                    Err(err) => error_json(format!("{err:#}")),
                },
                Err(e) => error_json(format!("{e:#}")),
            }
        }
        "optimize-all" => {
            let requested_passes = match required_enabled_passes(cmd, &enabled_passes) {
                Ok(passes) => passes,
                Err(message) => return error_json(message),
            };
            let programs = match commands::list_programs(config) {
                Ok(programs) => programs,
                Err(err) => {
                    return error_json(format!("failed to list live BPF programs: {err:#}"));
                }
            };
            let program_order = programs
                .iter()
                .map(|program| OptimizeAllOrderEntry {
                    prog_id: program.id,
                    prog_name: program.name.clone(),
                    prog_type: Some(program.prog_type_name().to_string()),
                    hotness_score: None,
                    run_cnt_delta: None,
                    run_time_ns_delta: None,
                    avg_ns: None,
                })
                .collect::<Vec<_>>();
            let applied = AtomicU32::new(0);
            let failures = Mutex::new(Vec::<(u32, String)>::new());
            let optimize_result = program_order.par_iter().try_for_each(|entry| {
                let profile_path = profiling_state
                    .as_ref()
                    .and_then(|state| state.profile_path_for(entry.prog_id));
                let result = (|| -> Result<()> {
                    let result = commands::try_apply_one(
                        entry.prog_id,
                        config,
                        Some(requested_passes),
                        profile_path.as_deref(),
                        Some(tracker),
                        OptimizeMode::Apply,
                    )
                    .with_context(|| {
                        format!(
                            "optimize-all failed for prog {} ({})",
                            entry.prog_id, entry.prog_name
                        )
                    })?;
                    if result.status != "ok" {
                        anyhow::bail!(
                            "{}",
                            result.error_message.unwrap_or_else(|| {
                                format!(
                                    "optimize prog {} returned status {}",
                                    entry.prog_id, result.status
                                )
                            })
                        );
                    }
                    if result.summary.applied {
                        applied.fetch_add(1, Ordering::Relaxed);
                    }
                    remember_reoptimization_result(
                        reoptimization_state,
                        entry.prog_id,
                        Some(requested_passes),
                        &result,
                        OptimizeMode::Apply,
                    )
                })();
                if let Err(err) = result {
                    let message = format!("{err:#}");
                    match failures.lock() {
                        Ok(mut failures) => failures.push((entry.prog_id, message.clone())),
                        Err(_) => {
                            return Err(anyhow::anyhow!("optimize-all failure list lock poisoned"))
                        }
                    }
                    return Err(anyhow::anyhow!(message));
                }
                Ok(())
            });
            if let Err(err) = optimize_result {
                let mut failures = match failures.into_inner() {
                    Ok(failures) => failures,
                    Err(_) => return error_json("optimize-all failure list lock poisoned"),
                };
                if failures.is_empty() {
                    failures.push((0, format!("{err:#}")));
                }
                failures.sort_by_key(|(prog_id, _)| *prog_id);
                let failures = failures
                    .into_iter()
                    .map(|(prog_id, err)| {
                        if prog_id == 0 {
                            err
                        } else {
                            format!("prog {prog_id}: {err}")
                        }
                    })
                    .collect::<Vec<_>>();
                return error_json(format!("optimize-all failed for {}", failures.join("; ")));
            }
            serde_json::json!({
                "status": "ok",
                "total": program_order.len() as u32,
                "applied": applied.load(Ordering::Relaxed),
                "errors": 0u32,
                "profiling_source": profiling_state.as_ref().map_or("none", ProfilingState::label),
                "hotness_window_ms": serde_json::Value::Null,
                "program_order": program_order,
                "program_errors": [],
            })
        }
        "profile-start" => {
            let interval_ms = match request_interval_ms(req) {
                Ok(interval_ms) => interval_ms,
                Err(message) => return error_json(message),
            };
            if matches!(profiling_state.as_ref(), Some(ProfilingState::Active(_))) {
                return error_json("profiling is already active");
            }
            match commands::start_profile(config, interval_ms) {
                Ok(session) => {
                    *profiling_state = Some(ProfilingState::Active(session));
                    serde_json::json!({"status": "ok"})
                }
                Err(err) => error_json(format!("{err:#}")),
            }
        }
        "profile-stop" => {
            let current_state = match profiling_state.take() {
                Some(state) => state,
                None => return error_json("no profiling session is active"),
            };
            match current_state {
                ProfilingState::Active(session) => match commands::stop_profile(session) {
                    Ok(profile) => {
                        let programs_profiled = profile.programs_profiled();
                        let duration_ms = profile.duration_ms();
                        *profiling_state = Some(ProfilingState::Frozen(profile));
                        serde_json::json!({
                            "status": "ok",
                            "programs_profiled": programs_profiled,
                            "duration_ms": duration_ms,
                        })
                    }
                    Err(err) => error_json(format!("{err:#}")),
                },
                ProfilingState::Frozen(profile) => {
                    *profiling_state = Some(ProfilingState::Frozen(profile));
                    error_json("profiling is not active")
                }
            }
        }
        "profile-save" => {
            let path = match request_path(req, "path") {
                Ok(path) => path,
                Err(message) => return error_json(message),
            };
            let Some(ProfilingState::Frozen(profile)) = profiling_state.as_ref() else {
                return error_json("no profile data available");
            };
            match commands::save_profile(profile, Path::new(path)) {
                Ok(()) => serde_json::json!({
                    "status": "ok",
                    "path": path,
                    "programs": profile.programs_profiled(),
                }),
                Err(err) => error_json(format!("{err:#}")),
            }
        }
        "profile-load" => {
            let path = match request_path(req, "path") {
                Ok(path) => path,
                Err(message) => return error_json(message),
            };
            if matches!(profiling_state.as_ref(), Some(ProfilingState::Active(_))) {
                return error_json("profiling is active; stop it before loading a snapshot");
            }
            match commands::load_profile(Path::new(path)) {
                Ok(profile) => {
                    let programs_loaded = profile.programs_profiled();
                    *profiling_state = Some(ProfilingState::Frozen(profile));
                    serde_json::json!({
                        "status": "ok",
                        "programs_loaded": programs_loaded,
                    })
                }
                Err(err) => error_json(format!("{err:#}")),
            }
        }
        "status" => {
            let profiling = profiling_state
                .as_ref()
                .map_or("none", ProfilingState::label);
            let available_passes_help = match commands::available_passes_help(config) {
                Ok(help) => help,
                Err(err) => return error_json(format!("bpfopt list-passes failed: {err:#}")),
            };
            serde_json::json!({
                "status": "ok",
                "version": env!("CARGO_PKG_VERSION"),
                "profiling": profiling,
                "profile_duration_ms": profiling_state.as_ref().map(ProfilingState::duration_ms),
                "programs_profiled": profiling_state.as_ref().map(ProfilingState::programs_profiled),
                "available_passes_help": available_passes_help,
            })
        }
        _ => error_json(format!("unknown command: {cmd}")),
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashMap;
    use std::sync::{Arc, Mutex};
    use std::time::{SystemTime, UNIX_EPOCH};

    use crate::commands::{
        InlinedMapEntry, OptimizeOneResult, OptimizeSummary, ProgramInfo, TimingsNs,
    };
    use crate::invalidation::{BatchLookupValue, MapInvalidationTracker};

    type MockMapValues = HashMap<u32, HashMap<Vec<u8>, Vec<u8>>>;
    type SharedMockMapValues = Arc<Mutex<MockMapValues>>;

    #[derive(Clone, Debug, Default)]
    struct MockMapValueReader {
        values: SharedMockMapValues,
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

    fn process_test_request(req: &serde_json::Value) -> serde_json::Value {
        process_test_request_with_config(req, &CliConfig::from_env())
    }

    fn process_test_request_with_config(
        req: &serde_json::Value,
        config: &CliConfig,
    ) -> serde_json::Value {
        let tracker = commands::new_invalidation_tracker();
        let reoptimization_state = new_reoptimization_state();
        let mut profiling_state = None;
        process_request(
            req,
            config,
            &mut profiling_state,
            &tracker,
            &reoptimization_state,
        )
    }

    fn temp_test_dir(prefix: &str) -> std::path::PathBuf {
        let timestamp = SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .expect("clock should be after epoch")
            .as_nanos();
        let path = std::env::temp_dir().join(format!("{prefix}-{timestamp}"));
        std::fs::create_dir(&path).expect("create temp test dir");
        path
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
    fn process_invalidation_tick_propagates_reoptimization_failures() {
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

        let err =
            process_invalidation_tick(&tracker, |_prog_id| anyhow::bail!("reoptimization failed"))
                .expect_err("process_invalidation_tick should fail when reoptimization fails");

        let message = format!("{err:#}");
        assert!(message.contains("invalidation reoptimization failed"));
        assert!(message.contains("prog 101"));
        assert!(message.contains("reoptimization failed"));
    }

    #[test]
    fn reoptimization_state_persists_pass_list_for_map_inline_results() {
        let mut state = ReoptimizationState::default();
        let mut result = OptimizeOneResult {
            status: "ok".to_string(),
            prog_id: 101,
            changed: true,
            passes_applied: vec!["map_inline".to_string()],
            program: ProgramInfo {
                prog_id: 101,
                prog_name: "demo".to_string(),
                prog_type: 6,
                orig_insn_count: 2,
                final_insn_count: 2,
                insn_delta: 0,
            },
            summary: OptimizeSummary {
                applied: true,
                total_sites_applied: 1,
                passes_executed: 1,
                passes_changed: 1,
                verifier_rejections: 0,
            },
            passes: Vec::new(),
            attempts: Vec::new(),
            timings_ns: TimingsNs {
                pipeline_run_ns: 1,
                rejit_syscall_ns: 1,
                total_ns: 2,
            },
            inlined_map_entries: vec![InlinedMapEntry {
                map_id: 7,
                key_hex: "01000000".to_string(),
                value_hex: "0b000000".to_string(),
            }],
            error_message: None,
        };
        let requested = vec!["const_prop".to_string(), "map_inline".to_string()];

        state.remember_result(101, Some(&requested), &result, OptimizeMode::Apply);

        assert_eq!(state.enabled_passes_for(101), Some(requested));

        result.inlined_map_entries.clear();
        state.remember_result(
            101,
            Some(&["map_inline".to_string()]),
            &result,
            OptimizeMode::Apply,
        );

        assert!(state.enabled_passes_for(101).is_none());
    }

    #[test]
    fn process_request_rejects_blank_enabled_pass_name() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "status",
            "enabled_passes": ["   "],
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "enabled_passes entries must not be blank"
        );
    }

    #[test]
    fn process_request_rejects_non_boolean_dry_run() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize",
            "prog_id": 1,
            "enabled_passes": ["wide_mem"],
            "dry_run": "yes",
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(response["error_message"], "dry_run must be a JSON boolean");
    }

    #[test]
    fn process_request_rejects_optimize_without_enabled_passes() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize",
            "prog_id": 1,
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "optimize requires enabled_passes"
        );
    }

    #[test]
    fn process_request_rejects_optimize_all_without_enabled_passes() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize-all",
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "optimize-all requires enabled_passes"
        );
    }

    #[test]
    fn process_request_rejects_empty_enabled_passes_for_optimize() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize",
            "prog_id": 1,
            "enabled_passes": [],
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "optimize requires at least one enabled_passes entry"
        );
    }

    #[test]
    fn process_request_status_reports_list_passes_failure_as_error() {
        let cli_dir = temp_test_dir("bpfrejit-daemon-empty-cli");
        let config = CliConfig::with_dir(cli_dir.clone());
        let response = process_test_request_with_config(
            &serde_json::json!({
                "cmd": "status",
            }),
            &config,
        );

        std::fs::remove_dir_all(cli_dir).expect("remove temp cli dir");
        assert_eq!(response["status"], "error");
        assert!(response["error_message"]
            .as_str()
            .expect("error message should be a string")
            .contains("bpfopt list-passes failed"));
    }

    #[test]
    fn process_request_rejects_zero_profile_interval() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "profile-start",
            "interval_ms": 0,
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "interval_ms must be greater than zero"
        );
    }

    #[test]
    fn process_request_profile_save_and_load_round_trip() {
        let timestamp = SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .expect("clock should be after epoch")
            .as_nanos();
        let src_path = std::env::temp_dir().join(format!("bpfrejit-profile-src-{timestamp}.json"));
        let dst_path = std::env::temp_dir().join(format!("bpfrejit-profile-dst-{timestamp}.json"));
        std::fs::write(
            &src_path,
            r#"[{"prog_id":123,"duration_ms":5,"run_cnt_delta":1,"run_time_ns_delta":2}]"#,
        )
        .expect("write source profile");

        let tracker = commands::new_invalidation_tracker();
        let reoptimization_state = new_reoptimization_state();
        let mut profiling_state = None;
        let load_response = process_request(
            &serde_json::json!({
                "cmd": "profile-load",
                "path": src_path.display().to_string(),
            }),
            &CliConfig::from_env(),
            &mut profiling_state,
            &tracker,
            &reoptimization_state,
        );
        assert_eq!(load_response["status"], "ok");
        assert_eq!(load_response["programs_loaded"], 1);

        let save_response = process_request(
            &serde_json::json!({
                "cmd": "profile-save",
                "path": dst_path.display().to_string(),
            }),
            &CliConfig::from_env(),
            &mut profiling_state,
            &tracker,
            &reoptimization_state,
        );
        assert_eq!(save_response["status"], "ok");
        assert_eq!(save_response["programs"], 1);
        assert!(
            dst_path.exists(),
            "profile-save should write the destination file"
        );

        std::fs::remove_file(&src_path).expect("source profile cleanup should succeed");
        std::fs::remove_file(&dst_path).expect("destination profile cleanup should succeed");
    }
}
