// SPDX-License-Identifier: MIT
//! Unix socket server implementation.

use std::collections::HashSet;
use std::path::Path;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::{Duration, Instant};

use anyhow::{Context, Result};
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

    let mut failures = Vec::new();
    for prog_id in &invalidated {
        if let Err(err) = reoptimize(*prog_id) {
            failures.push(format!("prog {}: {:#}", prog_id, err));
        }
    }

    if !failures.is_empty() {
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
    F: FnMut(u32) -> Result<()>,
{
    process_invalidation_tick(tracker, reoptimize)
        .with_context(|| format!("{context}: invalidation tick failed"))?;
    Ok(())
}

enum ProfilingState {
    Active(commands::ProfileSession),
    Frozen(commands::FrozenProfile),
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
    fn from_live() -> Self {
        let mut seen = HashSet::new();
        for prog_id in bpf::iter_prog_ids() {
            match prog_id {
                Ok(prog_id) => {
                    seen.insert(prog_id);
                }
                Err(err) => {
                    eprintln!("serve: failed to initialize BPF program watcher: {err:#}");
                    break;
                }
            }
        }
        Self { seen }
    }

    fn tick(&mut self) {
        for prog_id in bpf::iter_prog_ids() {
            match prog_id {
                Ok(prog_id) if self.seen.insert(prog_id) => {
                    eprintln!("serve: observed new BPF program id {prog_id}");
                }
                Ok(_) => {}
                Err(err) => {
                    eprintln!("serve: BPF program watch tick failed: {err:#}");
                    break;
                }
            }
        }
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
    let mut last_invalidation_check = Instant::now();
    let mut last_watch_check = Instant::now();
    let mut watcher = ProgramWatcher::from_live();
    let mut profiling_state: Option<ProfilingState> = None;

    remove_socket_file_if_present(socket_path)?;

    let listener = UnixListener::bind(socket_path)
        .with_context(|| format!("bind unix socket at {socket_path}"))?;
    listener.set_nonblocking(true)?;

    println!("serve: listening on {socket_path}");

    while !SHUTDOWN_FLAG.load(Ordering::Relaxed) {
        if last_watch_check.elapsed() >= Duration::from_secs(1) {
            watcher.tick();
            last_watch_check = Instant::now();
        }

        if last_invalidation_check.elapsed() >= Duration::from_secs(1) {
            let tracker_for_apply = tracker.clone();
            run_invalidation_tick_logged("serve", &tracker, |prog_id| {
                let profile_path = profiling_state
                    .as_ref()
                    .and_then(|state| state.profile_path_for(prog_id));
                let result = commands::try_apply_one(
                    prog_id,
                    &config,
                    None,
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
                Ok(())
            })?;
            last_invalidation_check = Instant::now();
        }

        match listener.accept() {
            Ok((stream, _addr)) => {
                if let Err(err) = handle_client(stream, &config, &mut profiling_state, &tracker) {
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
                process_request(&req, config, profiling_state, tracker)
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
    let mut enabled = parse_request_pass_list(req, "enabled_passes")?;
    let disabled = parse_request_pass_list(req, "disabled_passes")?;
    match (enabled.as_mut(), disabled) {
        (Some(enabled), Some(disabled)) => {
            let disabled: HashSet<_> = disabled.into_iter().collect();
            enabled.retain(|pass| !disabled.contains(pass));
            Ok(Some(enabled.clone()))
        }
        (Some(enabled), None) => Ok(Some(enabled.clone())),
        (None, Some(_)) => Err("disabled_passes requires enabled_passes with CLI backend".into()),
        (None, None) => Ok(None),
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
) -> serde_json::Value {
    let cmd = req.get("cmd").and_then(|v| v.as_str()).unwrap_or("");
    let enabled_passes = match request_enabled_passes(req) {
        Ok(value) => value,
        Err(message) => return error_json(message),
    };

    match cmd {
        "optimize" => {
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
                enabled_passes.as_deref(),
                profile_path.as_deref(),
                Some(tracker),
                mode,
            ) {
                Ok(result) => serialize_or_error(result),
                Err(e) => error_json(
                    format!("{e:#}")
                        .lines()
                        .next()
                        .unwrap_or("<empty error message>")
                        .to_string(),
                ),
            }
        }
        "optimize-all" => {
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
            let mut applied = 0u32;
            let mut errors = 0u32;
            let mut program_errors = Vec::new();
            for entry in &program_order {
                let profile_path = profiling_state
                    .as_ref()
                    .and_then(|state| state.profile_path_for(entry.prog_id));
                match commands::try_apply_one(
                    entry.prog_id,
                    config,
                    enabled_passes.as_deref(),
                    profile_path.as_deref(),
                    Some(tracker),
                    OptimizeMode::Apply,
                ) {
                    Ok(result) if result.status == "ok" && result.summary.applied => {
                        applied += 1;
                    }
                    Ok(result) if result.status == "ok" => {}
                    Ok(result) => {
                        errors += 1;
                        program_errors.push(serde_json::json!({
                            "prog_id": entry.prog_id,
                            "prog_name": result.program.prog_name,
                            "error_message": result.error_message.unwrap_or_else(|| {
                                format!(
                                    "optimize prog {} returned status {}",
                                    entry.prog_id, result.status
                                )
                            }),
                        }));
                    }
                    Err(err) => {
                        errors += 1;
                        program_errors.push(serde_json::json!({
                            "prog_id": entry.prog_id,
                            "prog_name": entry.prog_name,
                            "error_message": format!("{err:#}"),
                        }));
                    }
                }
            }
            serde_json::json!({
                "status": "ok",
                "total": program_order.len() as u32,
                "applied": applied,
                "errors": errors,
                "profiling_source": profiling_state.as_ref().map_or("none", ProfilingState::label),
                "hotness_window_ms": serde_json::Value::Null,
                "program_order": program_order,
                "program_errors": program_errors,
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
                Err(err) => format!("unavailable: {err:#}"),
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

    fn process_test_request(req: &serde_json::Value) -> serde_json::Value {
        let tracker = commands::new_invalidation_tracker();
        let mut profiling_state = None;
        process_request(req, &CliConfig::from_env(), &mut profiling_state, &tracker)
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
    fn process_request_rejects_blank_disabled_pass_name() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "status",
            "disabled_passes": ["   "],
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "disabled_passes entries must not be blank"
        );
    }

    #[test]
    fn process_request_rejects_disabled_passes_without_enabled_passes() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "status",
            "disabled_passes": ["map_inline"],
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "disabled_passes requires enabled_passes with CLI backend"
        );
    }

    #[test]
    fn process_request_rejects_non_boolean_dry_run() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize",
            "prog_id": 1,
            "dry_run": "yes",
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(response["error_message"], "dry_run must be a JSON boolean");
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
        let mut profiling_state = None;
        let load_response = process_request(
            &serde_json::json!({
                "cmd": "profile-load",
                "path": src_path.display().to_string(),
            }),
            &CliConfig::from_env(),
            &mut profiling_state,
            &tracker,
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
