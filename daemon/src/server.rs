// SPDX-License-Identifier: MIT
//! Server and watch daemon implementations.

use std::collections::HashSet;
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::Duration;

use anyhow::{Context, Result};

use crate::commands::{self, PgoConfig};
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

// ── Serve (Unix socket server) ──────────────────────────────────────

pub(crate) fn cmd_serve(socket_path: &str, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>, rollback_enabled: bool) -> Result<()> {
    use std::os::unix::net::UnixListener;

    register_signal_handlers();

    // Remove stale socket file if it exists.
    let _ = std::fs::remove_file(socket_path);

    let listener = UnixListener::bind(socket_path)
        .with_context(|| format!("bind unix socket at {}", socket_path))?;
    listener.set_nonblocking(true)?;

    println!("serve: listening on {}", socket_path);

    while !SHUTDOWN_FLAG.load(Ordering::Relaxed) {
        match listener.accept() {
            Ok((stream, _addr)) => {
                let _ = handle_client(stream, ctx, pass_names, pgo_config, rollback_enabled);
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
    rollback_enabled: bool,
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
            Ok(req) => process_request(&req, ctx, pass_names, pgo_config, rollback_enabled),
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
    rollback_enabled: bool,
) -> serde_json::Value {
    let cmd = req.get("cmd").and_then(|v| v.as_str()).unwrap_or("");
    match cmd {
        "optimize" => {
            let prog_id = match req.get("prog_id").and_then(|v| v.as_u64()) {
                Some(id) => id as u32,
                None => return serde_json::json!({"status": "error", "message": "missing prog_id"}),
            };
            match commands::try_apply_one(prog_id, ctx, pass_names, pgo_config, rollback_enabled) {
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
                match commands::try_apply_one(prog_id, ctx, pass_names, pgo_config, rollback_enabled) {
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

// ── Watch (polling daemon) ──────────────────────────────────────────

pub(crate) fn cmd_watch(interval_secs: u64, once: bool, ctx: &pass::PassContext, pass_names: &Option<Vec<String>>, pgo_config: &Option<PgoConfig>, rollback_enabled: bool) -> Result<()> {
    register_signal_handlers();

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
            match commands::try_apply_one(*prog_id, ctx, pass_names, pgo_config, rollback_enabled) {
                Ok(true) => {
                    optimized.insert(*prog_id);
                    applied += 1;
                }
                Ok(false) => {
                    no_op.insert(*prog_id);
                }
                Err(e) => {
                    let count = fail_count.entry(*prog_id).or_insert(0);
                    *count += 1;
                    if *count >= MAX_RETRIES {
                        eprintln!("  watch: prog {}: giving up after {} attempts: {:#}", prog_id, count, e);
                    } else {
                        eprintln!("  watch: prog {}: attempt {}/{} failed: {:#}", prog_id, count, MAX_RETRIES, e);
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
            std::thread::sleep(Duration::from_millis(100));
        }

        if SHUTDOWN_FLAG.load(Ordering::Relaxed) {
            println!("watch: received shutdown signal, exiting");
            break;
        }
    }

    Ok(())
}
