// SPDX-License-Identifier: MIT
//! Server and watch daemon implementations.

use std::collections::HashSet;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::{Duration, Instant};

use anyhow::{Context, Result};

use crate::commands;
use crate::invalidation::{MapInvalidationTracker, MapValueReader};
use crate::{bpf, pass};

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

// ── Serve (Unix socket server) ──────────────────────────────────────

pub(crate) fn cmd_serve(
    socket_path: &str,
    ctx: &pass::PassContext,
    rollback_enabled: bool,
) -> Result<()> {
    use std::os::unix::net::UnixListener;

    register_signal_handlers();
    let tracker = commands::new_invalidation_tracker();
    let mut last_invalidation_check = Instant::now();

    // Remove stale socket file if it exists.
    let _ = std::fs::remove_file(socket_path);

    let listener = UnixListener::bind(socket_path)
        .with_context(|| format!("bind unix socket at {}", socket_path))?;
    listener.set_nonblocking(true)?;

    println!("serve: listening on {}", socket_path);

    while !SHUTDOWN_FLAG.load(Ordering::Relaxed) {
        if last_invalidation_check.elapsed() >= Duration::from_secs(1) {
            let tracker_for_apply = tracker.clone();
            let _ = process_invalidation_tick(&tracker, |prog_id| {
                commands::try_apply_one(prog_id, ctx, rollback_enabled, Some(&tracker_for_apply))?;
                Ok(())
            });
            last_invalidation_check = Instant::now();
        }

        match listener.accept() {
            Ok((stream, _addr)) => {
                if let Err(err) = handle_client(stream, ctx, rollback_enabled, &tracker) {
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
    rollback_enabled: bool,
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
                process_request(&req, ctx, rollback_enabled, tracker)
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
    rollback_enabled: bool,
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
            let name = entry
                .as_str()
                .ok_or_else(|| format!("{key} entries must be strings"))?
                .trim();
            if !name.is_empty() {
                passes.push(name.to_string());
            }
        }
        Ok(Some(passes))
    }

    fn request_context(
        req: &serde_json::Value,
        base_ctx: &pass::PassContext,
    ) -> std::result::Result<pass::PassContext, String> {
        let mut local_ctx = base_ctx.clone();
        if let Some(enabled_passes) = parse_request_pass_list(req, "enabled_passes")? {
            local_ctx.policy.enabled_passes = enabled_passes;
        }
        if let Some(disabled_passes) = parse_request_pass_list(req, "disabled_passes")? {
            local_ctx.policy.disabled_passes = disabled_passes;
        }
        Ok(local_ctx)
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
            match commands::try_apply_one(prog_id, &local_ctx, rollback_enabled, Some(tracker)) {
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
            let mut applied = 0u32;
            let mut errors = 0u32;
            let mut total = 0u32;
            for prog_id in bpf::iter_prog_ids() {
                total += 1;
                match commands::try_apply_one(prog_id, &local_ctx, rollback_enabled, Some(tracker))
                {
                    Ok(result) => {
                        if result.summary.applied {
                            applied += 1;
                        }
                    }
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

// ── Watch (polling daemon) ──────────────────────────────────────────

pub(crate) fn cmd_watch(
    interval_secs: u64,
    once: bool,
    ctx: &pass::PassContext,
    rollback_enabled: bool,
) -> Result<()> {
    register_signal_handlers();
    let tracker = commands::new_invalidation_tracker();
    let mut last_invalidation_check = Instant::now();

    // Programs that were successfully optimized — never revisited.
    let mut optimized: HashSet<u32> = HashSet::new();
    // Programs that returned Ok(false) (no transforms) — no point retrying.
    let mut no_op: HashSet<u32> = HashSet::new();
    // Programs that failed — retry up to MAX_RETRIES times.
    let mut fail_count: std::collections::HashMap<u32, u32> = std::collections::HashMap::new();
    const MAX_RETRIES: u32 = 3;

    let mut round: u32 = 0;
    let observation_window = Duration::from_millis(200);

    println!(
        "watch: starting (interval={}s, once={})",
        interval_secs, once
    );

    loop {
        if SHUTDOWN_FLAG.load(Ordering::Relaxed) {
            println!("watch: received shutdown signal, exiting");
            break;
        }

        if last_invalidation_check.elapsed() >= Duration::from_secs(1) {
            let tracker_for_apply = tracker.clone();
            let _ = process_invalidation_tick(&tracker, |prog_id| {
                commands::try_apply_one(prog_id, ctx, rollback_enabled, Some(&tracker_for_apply))?;
                Ok(())
            });
            last_invalidation_check = Instant::now();
        }

        round += 1;
        let ids: Vec<u32> = bpf::iter_prog_ids().collect();
        let total = ids.len();

        // Candidates: not yet optimized, not permanently no-op, and not exhausted retries.
        let candidate_ids: Vec<u32> = ids
            .iter()
            .copied()
            .filter(|id| {
                !optimized.contains(id)
                    && !no_op.contains(id)
                    && fail_count.get(id).copied().unwrap_or(0) < MAX_RETRIES
            })
            .collect();
        let candidate_count = candidate_ids.len();

        // Collect stats for candidate programs and rank by hotness.
        let ranked_ids = commands::rank_programs_by_hotness(&candidate_ids, observation_window);

        let mut applied = 0u32;
        let mut errors = 0u32;
        for prog_id in &ranked_ids {
            match commands::try_apply_one(*prog_id, ctx, rollback_enabled, Some(&tracker)) {
                Ok(result) => {
                    if result.summary.applied {
                        optimized.insert(*prog_id);
                        applied += 1;
                    } else {
                        no_op.insert(*prog_id);
                    }
                }
                Err(e) => {
                    let count = fail_count.entry(*prog_id).or_insert(0);
                    *count += 1;
                    if *count >= MAX_RETRIES {
                        eprintln!(
                            "  watch: prog {}: giving up after {} attempts: {:#}",
                            prog_id, count, e
                        );
                    } else {
                        eprintln!(
                            "  watch: prog {}: attempt {}/{} failed: {:#}",
                            prog_id, count, MAX_RETRIES, e
                        );
                    }
                    errors += 1;
                }
            }
        }

        println!(
            "watch round {}: scanned {} progs, {} candidates, {} optimized, {} errors",
            round, total, candidate_count, applied, errors
        );

        if once {
            break;
        }

        let steps = interval_secs.max(1) * 10;
        for _ in 0..steps {
            if SHUTDOWN_FLAG.load(Ordering::Relaxed) {
                break;
            }
            if last_invalidation_check.elapsed() >= Duration::from_secs(1) {
                let tracker_for_apply = tracker.clone();
                let _ = process_invalidation_tick(&tracker, |prog_id| {
                    commands::try_apply_one(
                        prog_id,
                        ctx,
                        rollback_enabled,
                        Some(&tracker_for_apply),
                    )?;
                    Ok(())
                });
                last_invalidation_check = Instant::now();
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

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashMap;
    use std::sync::{Arc, Mutex};

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
        assert_eq!(panic_payload_message(payload.as_ref()), "non-string panic payload");
    }
}
