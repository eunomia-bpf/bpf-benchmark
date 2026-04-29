// SPDX-License-Identifier: MIT

use std::fs;
use std::path::PathBuf;
use std::process::Command;
use std::sync::atomic::{AtomicUsize, Ordering};

static NEXT_TEMP_ID: AtomicUsize = AtomicUsize::new(0);

fn bpfget_bin() -> &'static str {
    env!("CARGO_BIN_EXE_bpfget")
}

fn temp_path(name: &str) -> PathBuf {
    let id = NEXT_TEMP_ID.fetch_add(1, Ordering::Relaxed);
    std::env::temp_dir().join(format!("bpfget-cli-{}-{id}-{name}", std::process::id()))
}

fn unsupported_environment(stderr: &[u8]) -> bool {
    let stderr = String::from_utf8_lossy(stderr);
    [
        "Operation not permitted",
        "Permission denied",
        "Function not implemented",
        "Invalid argument",
    ]
    .iter()
    .any(|needle| stderr.contains(needle))
}

#[test]
fn list_exits_zero_and_emits_line_or_empty_output() {
    let output = Command::new(bpfget_bin())
        .arg("--list")
        .output()
        .expect("run bpfget --list");

    if !output.status.success() && unsupported_environment(&output.stderr) {
        eprintln!(
            "skipping bpfget --list test: {}",
            String::from_utf8_lossy(&output.stderr)
        );
        return;
    }

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let stdout = String::from_utf8(output.stdout).expect("utf8 stdout");
    for line in stdout.lines() {
        assert!(
            line.split_whitespace().count() >= 3,
            "expected 'prog_id name type' line, got {line:?}"
        );
    }
}

#[test]
fn list_json_emits_array_when_supported() {
    let output = Command::new(bpfget_bin())
        .args(["--list", "--json"])
        .output()
        .expect("run bpfget --list --json");

    if !output.status.success() && unsupported_environment(&output.stderr) {
        eprintln!(
            "skipping bpfget --list --json test: {}",
            String::from_utf8_lossy(&output.stderr)
        );
        return;
    }

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let value: serde_json::Value =
        serde_json::from_slice(&output.stdout).expect("json stdout from bpfget --list --json");
    assert!(value.is_array(), "expected JSON array, got {value}");
}

#[test]
fn info_missing_program_exits_failure() {
    let output = Command::new(bpfget_bin())
        .args(["--info", "0"])
        .output()
        .expect("run bpfget --info 0");

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("open BPF program id 0"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
}

#[test]
fn full_missing_outdir_exits_failure_without_creating_it() {
    let outdir = temp_path("missing-outdir");
    fs::remove_dir_all(&outdir).ok();
    fs::remove_file(&outdir).ok();
    let outdir_arg = outdir.to_string_lossy().to_string();

    let output = Command::new(bpfget_bin())
        .args(["0", "--full", "--outdir", &outdir_arg])
        .output()
        .expect("run bpfget --full with missing outdir");

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("failed to stat"), "stderr={stderr}");
    assert!(
        !outdir.exists(),
        "bpfget --full must not create missing outdir {}",
        outdir.display()
    );
    assert!(output.stdout.is_empty());
}

#[test]
fn target_stdout_contains_arch_and_features() {
    let output = Command::new(bpfget_bin())
        .arg("--target")
        .output()
        .expect("run bpfget --target");

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let value: serde_json::Value =
        serde_json::from_slice(&output.stdout).expect("json stdout from bpfget --target");
    assert!(
        value["arch"].as_str().is_some_and(|arch| !arch.is_empty()),
        "target JSON missing arch: {value}"
    );
    assert!(
        value["features"].is_array(),
        "target JSON missing features: {value}"
    );
    assert!(
        value["kinsns"].is_object(),
        "target JSON missing kinsns: {value}"
    );
    for (name, entry) in value["kinsns"].as_object().expect("kinsns object") {
        assert!(
            entry["btf_func_id"].is_i64() || entry["btf_func_id"].is_u64(),
            "kinsn {name} missing numeric btf_func_id: {entry}"
        );
    }
}

#[test]
fn target_output_writes_json_file() {
    let output_path = temp_path("target.json");
    fs::remove_file(&output_path).ok();
    let output_arg = output_path.to_string_lossy().to_string();

    let output = Command::new(bpfget_bin())
        .args(["--target", "--output", &output_arg])
        .output()
        .expect("run bpfget --target --output");

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    assert!(output.stdout.is_empty());
    let bytes = fs::read(&output_path).expect("read target output file");
    fs::remove_file(output_path).ok();

    let value: serde_json::Value =
        serde_json::from_slice(&bytes).expect("json file from bpfget --target --output");
    assert!(
        value["arch"].as_str().is_some_and(|arch| !arch.is_empty()),
        "target JSON missing arch: {value}"
    );
    assert!(
        value["features"].is_array(),
        "target JSON missing features: {value}"
    );
}

#[test]
fn target_manual_kinsn_spec_writes_numeric_btf_func_id() {
    let output = Command::new(bpfget_bin())
        .args(["--target", "--kinsns", "bpf_rotate64:77"])
        .output()
        .expect("run bpfget --target --kinsns");

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let value: serde_json::Value =
        serde_json::from_slice(&output.stdout).expect("json stdout from bpfget --target");
    assert_eq!(value["kinsns"]["bpf_rotate64"]["btf_func_id"], 77);
}
