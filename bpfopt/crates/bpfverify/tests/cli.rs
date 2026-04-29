use std::fs;
use std::io::Write;
use std::path::Path;
use std::process::{Command, Stdio};

fn run_bpfverify(args: &[&str], stdin_bytes: &[u8]) -> std::process::Output {
    let mut child = Command::new(env!("CARGO_BIN_EXE_bpfverify"))
        .args(args)
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .expect("spawn bpfverify");
    child
        .stdin
        .as_mut()
        .unwrap()
        .write_all(stdin_bytes)
        .expect("write stdin");
    child.wait_with_output().expect("wait for bpfverify")
}

fn good_xdp_prog() -> Vec<u8> {
    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0xb7, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00]);
    bytes.extend_from_slice(&[0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
    bytes
}

fn bad_xdp_prog() -> Vec<u8> {
    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0x05, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00]);
    bytes.extend_from_slice(&[0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
    bytes
}

fn temp_path(name: &str) -> std::path::PathBuf {
    let unique = format!(
        "{}-{}-{}",
        name,
        std::process::id(),
        std::time::SystemTime::now()
            .duration_since(std::time::UNIX_EPOCH)
            .unwrap()
            .as_nanos()
    );
    std::env::temp_dir().join(unique)
}

fn remove_file_if_exists(path: impl AsRef<Path>) {
    let path = path.as_ref();
    match fs::remove_file(path) {
        Ok(()) => {}
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => {}
        Err(err) => panic!("remove {}: {err}", path.display()),
    }
}

fn permission_denied(stderr: &[u8]) -> bool {
    let stderr = String::from_utf8_lossy(stderr);
    stderr.contains("Operation not permitted")
        || stderr.contains("Permission denied")
        || stderr.contains("EPERM")
}

#[test]
fn pipe_mode_passes_good_program_through() {
    let input = good_xdp_prog();
    let output = run_bpfverify(&["--prog-type", "xdp"], &input);
    if !output.status.success() && permission_denied(&output.stderr) {
        eprintln!("skipping kernel-dependent bpfverify pass test: permission denied");
        return;
    }

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    assert_eq!(output.stdout, input);
}

#[test]
fn pipe_mode_rejects_bad_program_with_verifier_log() {
    let output = run_bpfverify(&["--prog-type", "xdp"], &bad_xdp_prog());
    if !output.status.success() && permission_denied(&output.stderr) {
        eprintln!("skipping kernel-dependent bpfverify reject test: permission denied");
        return;
    }

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("jump") || stderr.contains("invalid") || stderr.contains("processed"),
        "stderr={stderr}"
    );
}

#[test]
fn report_mode_writes_json_for_bad_program() {
    let report = temp_path("bpfverify-report.json");
    let report_arg = report.to_string_lossy().to_string();
    let output = run_bpfverify(
        &["--prog-type", "xdp", "--report", &report_arg],
        &bad_xdp_prog(),
    );

    let json: serde_json::Value =
        serde_json::from_slice(&fs::read(&report).expect("read report")).unwrap();
    remove_file_if_exists(report);
    assert_eq!(json["log_level"], 2);
    assert!(json["verifier_states"]["insns"].is_array(), "json={json}");
    let verifier_log_empty = match json["verifier_log"].as_str() {
        Some(log) => log.is_empty(),
        None => true,
    };
    if verifier_log_empty && matches!(json["errno"].as_i64(), Some(1 | 13)) {
        eprintln!("skipping kernel-dependent bpfverify report assertions: permission denied");
        return;
    }

    assert!(!output.status.success());
    assert_eq!(json["status"], "fail");
    assert_eq!(json["insn_count"], 2);
    assert!(!json["verifier_log"].as_str().unwrap().is_empty());
}

#[test]
fn verifier_states_out_writes_v3_schema() {
    let states = temp_path("verifier-states.json");
    let states_arg = states.to_string_lossy().to_string();
    let output = run_bpfverify(
        &["--prog-type", "xdp", "--verifier-states-out", &states_arg],
        &good_xdp_prog(),
    );
    if !output.status.success() && permission_denied(&output.stderr) {
        eprintln!("skipping kernel-dependent verifier-states test: permission denied");
        remove_file_if_exists(states);
        return;
    }

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let json: serde_json::Value =
        serde_json::from_slice(&fs::read(&states).expect("read states")).unwrap();
    remove_file_if_exists(states);
    assert!(json["insns"].is_array(), "json={json}");
}

#[test]
fn missing_prog_type_exits_with_friendly_error() {
    let output = run_bpfverify(&[], &good_xdp_prog());
    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("prog-type"), "stderr={stderr}");
}
