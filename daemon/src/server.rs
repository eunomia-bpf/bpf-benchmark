// SPDX-License-Identifier: MIT
//! Unix socket server implementation.

use std::collections::{BTreeMap, HashSet};
use std::sync::atomic::{AtomicBool, Ordering};
use std::time::Duration;

use crate::bpf;
use crate::commands;
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
    remove_socket_file_if_present(socket_path)?;

    let listener = UnixListener::bind(socket_path)
        .with_context(|| format!("bind unix socket at {socket_path}"))?;
    listener.set_nonblocking(true)?;

    println!("serve: listening on {socket_path}");

    while !SHUTDOWN_FLAG.load(Ordering::Relaxed) {
        match listener.accept() {
            Ok((stream, _addr)) => {
                if let Err(err) = handle_client(stream) {
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

fn handle_client(stream: std::os::unix::net::UnixStream) -> Result<()> {
    use std::io::{BufRead, BufReader, Write};

    let reader = BufReader::new(&stream);
    let mut writer = &stream;

    for line in reader.lines() {
        let line = line?;
        if line.is_empty() {
            continue;
        }

        let response = match serde_json::from_str::<serde_json::Value>(&line) {
            Ok(req) => process_request(&req),
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

#[derive(Debug)]
struct ParsedPlan {
    plans: Vec<commands::ProgramPlan>,
    kinsn_probes: Vec<bpf::KinsnProbeTarget>,
}

fn parse_execute_plan(req: &serde_json::Value) -> std::result::Result<ParsedPlan, String> {
    let programs_value = req
        .get("programs")
        .ok_or_else(|| "missing programs".to_string())?;
    let programs_array = programs_value
        .as_array()
        .ok_or_else(|| "programs must be a JSON array".to_string())?;
    let mut plans = Vec::with_capacity(programs_array.len());
    let mut seen_ids = HashSet::new();
    for (idx, entry) in programs_array.iter().enumerate() {
        let obj = entry
            .as_object()
            .ok_or_else(|| format!("programs[{idx}] must be a JSON object"))?;
        let id = obj
            .get("prog_id")
            .and_then(|v| v.as_u64())
            .ok_or_else(|| format!("programs[{idx}].prog_id must be a positive integer"))?;
        if id == 0 || id > u32::MAX as u64 {
            return Err(format!("programs[{idx}].prog_id {id} is invalid"));
        }
        let prog_id = id as u32;
        if !seen_ids.insert(prog_id) {
            return Err(format!("duplicate prog_id {prog_id}"));
        }

        let steps = match obj.get("steps") {
            None => Vec::new(),
            Some(value) => {
                let array = value
                    .as_array()
                    .ok_or_else(|| format!("programs[{idx}].steps must be a JSON array"))?;
                let mut steps = Vec::with_capacity(array.len());
                for (j, entry) in array.iter().enumerate() {
                    let step = parse_step_spec(idx, j, entry)?;
                    steps.push(step);
                }
                steps
            }
        };

        plans.push(commands::ProgramPlan { prog_id, steps });
    }

    let kinsn_probes = parse_kinsn_probes(req)?;
    Ok(ParsedPlan {
        plans,
        kinsn_probes,
    })
}

fn parse_step_spec(
    program_idx: usize,
    step_idx: usize,
    entry: &serde_json::Value,
) -> std::result::Result<commands::StepSpec, String> {
    let obj = entry.as_object().ok_or_else(|| {
        format!("programs[{program_idx}].steps[{step_idx}] must be a JSON object")
    })?;
    let name = obj
        .get("name")
        .and_then(|v| v.as_str())
        .ok_or_else(|| format!("programs[{program_idx}].steps[{step_idx}].name must be a string"))?
        .trim()
        .to_string();
    if name.is_empty() {
        return Err(format!(
            "programs[{program_idx}].steps[{step_idx}].name must not be blank"
        ));
    }
    let command = obj
        .get("command")
        .and_then(|v| v.as_str())
        .ok_or_else(|| {
            format!("programs[{program_idx}].steps[{step_idx}].command must be a string")
        })?
        .trim()
        .to_string();
    if command.is_empty() {
        return Err(format!(
            "programs[{program_idx}].steps[{step_idx}].command must not be blank"
        ));
    }
    let log_level_value = obj
        .get("log_level")
        .ok_or_else(|| {
            format!("programs[{program_idx}].steps[{step_idx}].log_level must be 1 or 2")
        })?
        .as_u64()
        .ok_or_else(|| {
            format!(
                "programs[{program_idx}].steps[{step_idx}].log_level must be a positive integer"
            )
        })?;
    if log_level_value != 1 && log_level_value != 2 {
        return Err(format!(
            "programs[{program_idx}].steps[{step_idx}].log_level must be 1 or 2 (got {log_level_value})"
        ));
    }
    Ok(commands::StepSpec {
        name,
        command,
        log_level: log_level_value as u32,
    })
}

fn parse_kinsn_probes(
    req: &serde_json::Value,
) -> std::result::Result<Vec<bpf::KinsnProbeTarget>, String> {
    let Some(value) = req.get("kinsn_probes") else {
        return Ok(Vec::new());
    };
    let array = value
        .as_array()
        .ok_or_else(|| "kinsn_probes must be a JSON array".to_string())?;
    let mut probes = Vec::with_capacity(array.len());
    let mut seen_names = HashSet::new();
    for (idx, entry) in array.iter().enumerate() {
        let obj = entry
            .as_object()
            .ok_or_else(|| format!("kinsn_probes[{idx}] must be a JSON object"))?;
        let name = obj
            .get("name")
            .and_then(|v| v.as_str())
            .ok_or_else(|| format!("kinsn_probes[{idx}].name must be a string"))?
            .trim()
            .to_string();
        if name.is_empty() {
            return Err(format!("kinsn_probes[{idx}].name must not be blank"));
        }
        if !seen_names.insert(name.clone()) {
            return Err(format!("duplicate kinsn_probe name {name}"));
        }
        if obj.contains_key("aliases") {
            return Err(format!(
                "kinsn_probes[{idx}].aliases is not supported; use exact kinsn names"
            ));
        }
        probes.push(bpf::KinsnProbeTarget { name });
    }
    Ok(probes)
}

fn error_json(message: impl Into<String>) -> serde_json::Value {
    serde_json::json!({
        "status": "error",
        "error_message": message.into(),
    })
}

fn process_request(req: &serde_json::Value) -> serde_json::Value {
    let cmd = req.get("cmd").and_then(|v| v.as_str()).unwrap_or("");

    match cmd {
        "execute_plan" => {
            let parsed = match parse_execute_plan(req) {
                Ok(parsed) => parsed,
                Err(message) => return error_json(message),
            };
            match commands::try_execute_plan(&parsed.plans, &parsed.kinsn_probes) {
                Ok(outcomes) => match optimize_response_from_outcomes(outcomes) {
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
    outcomes: Vec<commands::ApplyProgramOutcome>,
) -> Result<serde_json::Value> {
    // Single source of truth: per_program[id]. No top-level error_message —
    // readers inspect per_program[id].status and passes[*].error directly.
    let mut per_program = BTreeMap::new();
    for outcome in outcomes {
        per_program.insert(
            outcome.prog_id,
            serde_json::to_value(outcome.result).with_context(|| {
                format!("serialize optimize result for prog {}", outcome.prog_id)
            })?,
        );
    }
    Ok(serde_json::json!({
        "status": "ok",
        "per_program": per_program,
    }))
}

#[cfg(test)]
mod tests {
    use super::*;

    use crate::commands::{ApplyProgramOutcome, OptimizeOneResult, ProgramInfo};

    fn process_test_request(req: &serde_json::Value) -> serde_json::Value {
        process_request(req)
    }

    #[test]
    fn optimize_response_keeps_per_program_errors_under_top_level_ok() {
        let prog_ids = vec![10, 11, 12];
        let outcomes = vec![
            ApplyProgramOutcome {
                prog_id: 10,
                result: optimize_success_result(10),
            },
            ApplyProgramOutcome {
                prog_id: 11,
                result: OptimizeOneResult::error(11, "missing program 11"),
            },
            ApplyProgramOutcome {
                prog_id: 12,
                result: OptimizeOneResult::error(12, "pass failed while optimizing prog 12"),
            },
        ];

        let response = optimize_response_from_outcomes(outcomes)
            .expect("optimize response should be built from per-program outcomes");

        assert_eq!(response["status"], "ok");
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
        assert_eq!(per_program["12"]["status"], "error");
        assert!(per_program["12"]["error_message"]
            .as_str()
            .unwrap_or("")
            .contains("pass failed"));
    }

    fn optimize_success_result(prog_id: u32) -> OptimizeOneResult {
        OptimizeOneResult {
            status: "ok".to_string(),
            prog_id,
            program: ProgramInfo {
                prog_id,
                prog_name: "demo".to_string(),
                prog_type: 6,
                orig_insn_count: 2,
                final_insn_count: 2,
            },
            passes: Vec::new(),
            error_message: None,
            workdir_tar_b64: None,
        }
    }

    #[test]
    fn process_request_rejects_old_optimize_command() {
        let response = process_test_request(&serde_json::json!({
            "cmd": "optimize",
            "prog_ids": [42],
            "enabled_passes": ["dce"],
        }));

        assert_eq!(response["status"], "error");
        assert_eq!(response["error_message"], "unknown command: optimize");
    }

    #[test]
    fn parse_execute_plan_rejects_missing_programs() {
        let err = parse_execute_plan(&serde_json::json!({"cmd": "execute_plan"})).unwrap_err();
        assert_eq!(err, "missing programs");
    }

    #[test]
    fn parse_execute_plan_rejects_non_array_programs() {
        let err = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": 123,
        }))
        .unwrap_err();
        assert_eq!(err, "programs must be a JSON array");
    }

    #[test]
    fn parse_execute_plan_accepts_empty_programs() {
        let parsed = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [],
        }))
        .unwrap();
        assert!(parsed.plans.is_empty());
        assert!(parsed.kinsn_probes.is_empty());
    }

    #[test]
    fn parse_execute_plan_rejects_zero_prog_id() {
        let err = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [{"prog_id": 0, "steps": []}],
        }))
        .unwrap_err();
        assert!(err.contains("prog_id 0 is invalid"), "err={err}");
    }

    #[test]
    fn parse_execute_plan_rejects_duplicate_prog_id() {
        let err = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [
                {"prog_id": 42, "steps": []},
                {"prog_id": 42, "steps": []},
            ],
        }))
        .unwrap_err();
        assert_eq!(err, "duplicate prog_id 42");
    }

    #[test]
    fn parse_execute_plan_rejects_blank_step_command() {
        let err = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [{
                "prog_id": 42,
                "steps": [
                    {"name": "noop", "command": "bpfopt --pass noop", "log_level": 2},
                    {"name": "blank", "command": "   ", "log_level": 1},
                ],
            }],
        }))
        .unwrap_err();
        assert_eq!(err, "programs[0].steps[1].command must not be blank");
    }

    #[test]
    fn parse_execute_plan_rejects_invalid_log_level() {
        let err = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [{
                "prog_id": 42,
                "steps": [{"name": "noop", "command": "bpfopt --pass noop", "log_level": 3}],
            }],
        }))
        .unwrap_err();
        assert!(
            err.contains("log_level must be 1 or 2 (got 3)"),
            "err={err}"
        );
    }

    #[test]
    fn parse_execute_plan_rejects_missing_log_level() {
        let err = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [{
                "prog_id": 42,
                "steps": [{"name": "noop", "command": "bpfopt --pass noop"}],
            }],
        }))
        .unwrap_err();
        assert_eq!(err, "programs[0].steps[0].log_level must be 1 or 2");
    }

    #[test]
    fn parse_execute_plan_accepts_empty_steps_as_skip() {
        let parsed = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [{"prog_id": 470, "steps": []}],
        }))
        .unwrap();
        assert_eq!(parsed.plans.len(), 1);
        assert_eq!(parsed.plans[0].prog_id, 470);
        assert!(parsed.plans[0].steps.is_empty());
    }

    #[test]
    fn parse_execute_plan_treats_missing_steps_as_skip() {
        let parsed = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [{"prog_id": 470}],
        }))
        .unwrap();
        assert_eq!(parsed.plans.len(), 1);
        assert!(parsed.plans[0].steps.is_empty());
    }

    #[test]
    fn parse_execute_plan_parses_kinsn_probes() {
        let parsed = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [{
                "prog_id": 470,
                "steps": [
                    {"name": "noop", "command": "bpfopt --pass noop", "log_level": 2},
                ],
            }],
            "kinsn_probes": [
                {"name": "bpf_x86_rolq"},
                {"name": "bpf_x86_testq"},
            ],
        }))
        .unwrap();
        assert_eq!(parsed.kinsn_probes.len(), 2);
        assert_eq!(parsed.kinsn_probes[0].name, "bpf_x86_rolq");
        assert_eq!(parsed.kinsn_probes[1].name, "bpf_x86_testq");
        assert_eq!(parsed.plans[0].steps[0].name, "noop");
        assert_eq!(parsed.plans[0].steps[0].log_level, 2);
    }

    #[test]
    fn parse_execute_plan_rejects_kinsn_probe_aliases() {
        let err = parse_execute_plan(&serde_json::json!({
            "cmd": "execute_plan",
            "programs": [],
            "kinsn_probes": [{"name": "bpf_x86_rolq", "aliases": []}],
        }))
        .unwrap_err();
        assert_eq!(
            err,
            "kinsn_probes[0].aliases is not supported; use exact kinsn names"
        );
    }
}
