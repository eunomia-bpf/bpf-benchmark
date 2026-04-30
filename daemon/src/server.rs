// SPDX-License-Identifier: MIT
//! Unix socket server implementation.

use std::collections::{HashMap, HashSet};
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::time::{Duration, Instant};

use anyhow::{Context, Result};
use serde::Serialize;

use crate::bpf;
use crate::commands::{self, CliConfig};
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
    F: Fn(u32) -> Result<()>,
{
    let invalidated = {
        let tracker = tracker
            .lock()
            .map_err(|_| anyhow::anyhow!("invalidation tracker lock poisoned"))?;
        tracker.check_for_invalidations()?
    };

    for prog_id in &invalidated {
        reoptimize(*prog_id)
            .with_context(|| format!("invalidation reoptimization failed for prog {prog_id}"))?;
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
    F: Fn(u32) -> Result<()>,
{
    process_invalidation_tick(tracker, reoptimize)
        .with_context(|| format!("{context}: invalidation tick failed"))?;
    Ok(())
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
    ) {
        if result.status != "ok" || result.inlined_map_entries.is_empty() {
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
) -> Result<()> {
    state
        .lock()
        .map_err(|_| anyhow::anyhow!("reoptimization state lock poisoned"))?
        .remember_result(prog_id, enabled_passes, result);
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
                let enabled_passes =
                    reoptimization_passes_for(&reoptimization_state_for_apply, prog_id)?;
                let result = commands::try_reapply_one(
                    prog_id,
                    &config,
                    Some(&enabled_passes),
                    Some(&tracker_for_apply),
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
                )?;
                Ok(())
            })?;
            last_invalidation_check = Instant::now();
        }

        match listener.accept() {
            Ok((stream, _addr)) => {
                if let Err(err) = handle_client(stream, &config, &tracker, &reoptimization_state) {
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
                process_request(&req, config, tracker, reoptimization_state)
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
            match commands::try_apply_one(prog_id, config, Some(requested_passes), Some(tracker)) {
                Ok(result) => match remember_reoptimization_result(
                    reoptimization_state,
                    prog_id,
                    Some(requested_passes),
                    &result,
                ) {
                    Ok(()) => serialize_or_error(result),
                    Err(err) => error_json(format!("{err:#}")),
                },
                Err(e) => error_json(format!("{e:#}")),
            }
        }
        "status" => {
            serde_json::json!({
                "status": "ok",
                "version": env!("CARGO_PKG_VERSION"),
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

    use crate::commands::{InlinedMapEntry, OptimizeOneResult, OptimizeSummary, ProgramInfo};
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
        process_request(req, config, &tracker, &reoptimization_state)
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
            },
            passes: Vec::new(),
            inlined_map_entries: vec![InlinedMapEntry {
                map_id: 7,
                key_hex: "01000000".to_string(),
                value_hex: "0b000000".to_string(),
            }],
            error_message: None,
        };
        let requested = vec!["const_prop".to_string(), "map_inline".to_string()];

        state.remember_result(101, Some(&requested), &result);

        assert_eq!(state.enabled_passes_for(101), Some(requested));

        result.inlined_map_entries.clear();
        state.remember_result(101, Some(&["map_inline".to_string()]), &result);

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
}
