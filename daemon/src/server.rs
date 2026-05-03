// SPDX-License-Identifier: MIT
//! Unix socket server implementation.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::time::{Duration, Instant};

use crate::bpf;
use crate::commands::{self, CliConfig};
use crate::invalidation::{MapInvalidationTracker, MapValueReader};
use anyhow::{Context, Result};

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
        requested_passes: &[String],
        result: &commands::OptimizeOneResult,
    ) {
        if result.status != "ok"
            || result.error_message.is_some()
            || result.inlined_map_entries.is_empty()
        {
            self.enabled_passes_by_prog.remove(&prog_id);
            return;
        }

        let enabled_passes = requested_passes.to_vec();
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
    enabled_passes: &[String],
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

    commands::init_cli_dir()?;
    let config = CliConfig::from_global();
    let tracker = commands::new_invalidation_tracker();
    let reoptimization_state = new_reoptimization_state();
    let mut last_invalidation_check = Instant::now();
    let mut last_watch_check = Instant::now();
    let mut watcher = ProgramWatcher::from_live()?;

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
                    &enabled_passes,
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
                    &enabled_passes,
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

        let mut resp_str = serde_json::to_string(&response).context("serialize daemon response")?;
        resp_str.push('\n');
        writer
            .write_all(resp_str.as_bytes())
            .context("write daemon response")?;
        writer.flush().context("flush daemon response")?;
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

fn require_runner_enabled_passes(
    enabled_passes: Option<&[String]>,
) -> std::result::Result<&[String], String> {
    match enabled_passes {
        Some(passes) if !passes.is_empty() => Ok(passes),
        _ => Err("no enabled_passes provided by runner".to_string()),
    }
}

fn request_prog_ids(req: &serde_json::Value) -> std::result::Result<Vec<u32>, String> {
    if req.get("prog_id").is_some() {
        return Err("prog_id is not supported; use prog_ids".to_string());
    }
    let value = req
        .get("prog_ids")
        .ok_or_else(|| "missing prog_ids".to_string())?;
    let array = value
        .as_array()
        .ok_or_else(|| "prog_ids must be a JSON integer array".to_string())?;
    let mut prog_ids = Vec::with_capacity(array.len());
    for entry in array {
        let id = entry
            .as_u64()
            .ok_or_else(|| "prog_ids entries must be integers".to_string())?;
        if id == 0 || id > u32::MAX as u64 {
            return Err(format!("invalid prog_id {id}"));
        }
        prog_ids.push(id as u32);
    }
    if prog_ids.is_empty() {
        return Err("prog_ids must not be empty".to_string());
    }
    let mut seen = HashSet::new();
    for prog_id in &prog_ids {
        if !seen.insert(*prog_id) {
            return Err(format!("duplicate prog_id {prog_id}"));
        }
    }
    Ok(prog_ids)
}

fn error_json(message: impl Into<String>) -> serde_json::Value {
    serde_json::json!({
        "status": "error",
        "error_message": message.into(),
    })
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
            let enabled_passes = match require_runner_enabled_passes(enabled_passes.as_deref()) {
                Ok(value) => value,
                Err(message) => return error_json(message),
            };
            let prog_ids = match request_prog_ids(req) {
                Ok(value) => value,
                Err(message) => return error_json(message),
            };
            match commands::try_apply_programs(&prog_ids, config, enabled_passes, Some(tracker)) {
                Ok(outcomes) => match optimize_response_from_outcomes(
                    &prog_ids,
                    enabled_passes,
                    reoptimization_state,
                    outcomes,
                ) {
                    Ok(response) => response,
                    Err(err) => error_json(format!("{err:#}")),
                },
                Err(err) => error_json(format!("{err:#}")),
            }
        }
        _ => error_json(format!("unknown command: {cmd}")),
    }
}

fn optimize_response_from_outcomes(
    prog_ids: &[u32],
    enabled_passes: &[String],
    reoptimization_state: &SharedReoptimizationState,
    outcomes: Vec<commands::ApplyProgramOutcome>,
) -> Result<serde_json::Value> {
    let mut per_program = BTreeMap::new();
    let mut applied = 0usize;
    let mut errors = Vec::new();
    for outcome in outcomes {
        let result = outcome.result;
        if result.status == "ok" && result.summary.applied {
            applied += 1;
        }
        if let Some(message) = result.error_message.as_deref() {
            errors.push(format!("prog {}: {message}", outcome.prog_id));
        }
        remember_reoptimization_result(
            reoptimization_state,
            outcome.prog_id,
            enabled_passes,
            &result,
        )
        .with_context(|| {
            format!(
                "remember reoptimization result for prog {}",
                outcome.prog_id
            )
        })?;
        per_program.insert(
            outcome.prog_id,
            serde_json::to_value(result).with_context(|| {
                format!("serialize optimize result for prog {}", outcome.prog_id)
            })?,
        );
    }
    Ok(serde_json::json!({
        "status": "ok",
        "per_program": per_program,
        "program_counts": {
            "requested": prog_ids.len(),
            "applied": applied,
            "not_applied": prog_ids.len() - applied,
        },
        "error_message": errors.join("; "),
    }))
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashMap;
    use std::sync::{Arc, Mutex};

    use crate::commands::{
        ApplyProgramOutcome, FailureArtifacts, InlinedMapEntry, OptimizeOneResult, OptimizeSummary,
        ProgramInfo,
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
        // CLI_DIR global is unset in tests; from_global() returns CliConfig { cli_dir: None }.
        process_test_request_with_config(req, &CliConfig::from_global())
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
                failed_pass: None,
                committed_passes_before_failure: None,
            },
            passes: Vec::new(),
            inlined_map_entries: vec![InlinedMapEntry {
                map_id: 7,
                key_hex: "01000000".to_string(),
                value_hex: "0b000000".to_string(),
            }],
            error_message: None,
            failure_artifacts: None,
        };
        let requested = vec!["const_prop".to_string(), "map_inline".to_string()];

        state.remember_result(101, &requested, &result);

        assert_eq!(state.enabled_passes_for(101), Some(requested));

        result.inlined_map_entries.clear();
        state.remember_result(101, &["map_inline".to_string()], &result);

        assert!(state.enabled_passes_for(101).is_none());
    }

    #[test]
    fn optimize_response_keeps_per_program_errors_under_top_level_ok() {
        let prog_ids = vec![10, 11, 12];
        let enabled_passes = vec!["rotate".to_string()];
        let reoptimization_state = new_reoptimization_state();
        let mut artifact_error = OptimizeOneResult::error(11, "missing program 11");
        artifact_error.failure_artifacts = Some(FailureArtifacts {
            failed_pass_index: 2,
            failed_pass: "rotate".to_string(),
            committed_passes: 1,
            verifier_log: "full verifier log".to_string(),
            pass_error: "EINVAL".to_string(),
            partial_failure_json: serde_json::json!({"failed_pass": "rotate"}),
        });
        let outcomes = vec![
            ApplyProgramOutcome {
                prog_id: 10,
                result: optimize_success_result(10),
            },
            ApplyProgramOutcome {
                prog_id: 11,
                result: artifact_error,
            },
            ApplyProgramOutcome {
                prog_id: 12,
                result: OptimizeOneResult::error(12, "worker panicked while optimizing prog 12"),
            },
        ];

        let response = optimize_response_from_outcomes(
            &prog_ids,
            &enabled_passes,
            &reoptimization_state,
            outcomes,
        )
        .expect("optimize response should be built from per-program outcomes");

        assert_eq!(response["status"], "ok");
        assert_eq!(response["program_counts"]["requested"], 3);
        assert_eq!(response["program_counts"]["applied"], 1);
        assert_eq!(response["program_counts"]["not_applied"], 2);
        let per_program = response["per_program"]
            .as_object()
            .expect("per_program should be an object");
        assert_eq!(per_program.len(), prog_ids.len());
        for prog_id in &prog_ids {
            assert!(
                per_program.contains_key(&prog_id.to_string()),
                "missing prog {prog_id}"
            );
        }
        assert_eq!(per_program["10"]["status"], "ok");
        assert_eq!(per_program["11"]["status"], "error");
        assert!(per_program["11"]["error_message"]
            .as_str()
            .unwrap_or("")
            .contains("missing program 11"));
        assert_eq!(
            per_program["11"]["failure_artifacts"]["verifier_log"],
            "full verifier log"
        );
        assert!(per_program["10"].get("failure_artifacts").is_none());
        assert_eq!(per_program["12"]["status"], "error");
        assert!(per_program["12"]["error_message"]
            .as_str()
            .unwrap_or("")
            .contains("worker panicked"));
    }

    fn optimize_success_result(prog_id: u32) -> OptimizeOneResult {
        OptimizeOneResult {
            status: "ok".to_string(),
            prog_id,
            changed: true,
            passes_applied: vec!["rotate".to_string()],
            program: ProgramInfo {
                prog_id,
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
                failed_pass: None,
                committed_passes_before_failure: None,
            },
            passes: Vec::new(),
            inlined_map_entries: Vec::new(),
            error_message: None,
            failure_artifacts: None,
        }
    }

    #[test]
    fn process_request_rejects_blank_enabled_pass_name() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize",
            "prog_ids": [42],
            "enabled_passes": ["   "],
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "enabled_passes entries must not be blank"
        );
    }

    #[test]
    fn process_request_rejects_missing_enabled_passes_for_optimize() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize",
            "prog_ids": [42],
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "no enabled_passes provided by runner"
        );
    }

    #[test]
    fn process_request_rejects_empty_enabled_passes_for_optimize() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize",
            "prog_ids": [42],
            "enabled_passes": [],
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "no enabled_passes provided by runner"
        );
    }

    #[test]
    fn process_request_rejects_singular_prog_id_for_optimize() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize",
            "prog_id": 42,
            "enabled_passes": ["dce"],
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(
            response["error_message"],
            "prog_id is not supported; use prog_ids"
        );
    }

    #[test]
    fn request_prog_ids_rejects_empty_list() {
        let err = request_prog_ids(&serde_json::json!({
            "cmd": "optimize",
            "prog_ids": [],
        }))
        .unwrap_err();

        assert_eq!(err, "prog_ids must not be empty");
    }

    #[test]
    fn request_prog_ids_rejects_duplicate_ids() {
        let err = request_prog_ids(&serde_json::json!({
            "cmd": "optimize",
            "prog_ids": [42, 42],
        }))
        .unwrap_err();

        assert_eq!(err, "duplicate prog_id 42");
    }
}
