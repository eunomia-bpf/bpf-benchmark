// SPDX-License-Identifier: MIT

use std::fs;
use std::path::PathBuf;
use std::process::Command;
use std::sync::atomic::{AtomicUsize, Ordering};

static NEXT_TEMP_ID: AtomicUsize = AtomicUsize::new(0);
const KINSN_MODULE_TEST_ENV: &str = "BPFGET_TEST_KINSN_MODULE_LOADED";
const EXPECTED_V3_KINSN_NAMES: &[&str] = &[
    "bpf_rotate64",
    "bpf_select64",
    "bpf_extract64",
    "bpf_endian_load64",
    "bpf_bulk_memcpy",
    "bpf_bulk_memset",
];

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

fn target_btf_permission_blocked(stderr: &str) -> bool {
    stderr.contains("kinsn BTF probing unavailable")
        && (stderr.contains("Operation not permitted") || stderr.contains("Permission denied"))
}

fn target_stdout_json(output: &std::process::Output) -> serde_json::Value {
    serde_json::from_slice(&output.stdout).expect("json stdout from bpfget --target")
}

fn expected_kinsn_names() -> Vec<String> {
    match std::env::var("BPFGET_TEST_EXPECT_KINSNS") {
        Ok(value) => value
            .split(',')
            .map(str::trim)
            .filter(|name| !name.is_empty())
            .map(str::to_string)
            .collect(),
        Err(_) => EXPECTED_V3_KINSN_NAMES
            .iter()
            .map(|name| (*name).to_string())
            .collect(),
    }
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
fn test_target_empty_kinsns_in_unprivileged_env() {
    let output = Command::new(bpfget_bin())
        .arg("--target")
        .output()
        .expect("run bpfget --target");

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let stderr = String::from_utf8_lossy(&output.stderr);
    if !target_btf_permission_blocked(&stderr) {
        eprintln!("skipping unprivileged target test: BTF probing is accessible");
        return;
    }

    let value = target_stdout_json(&output);
    assert!(
        value["kinsns"]
            .as_object()
            .is_some_and(serde_json::Map::is_empty),
        "expected empty kinsns after permission fallback: {value}"
    );
    assert!(
        stderr.contains("no kinsn BTF functions found; target.json uses empty kinsns"),
        "stderr={stderr}"
    );
}

#[test]
fn test_target_finds_kinsn_when_loaded() {
    if std::env::var_os(KINSN_MODULE_TEST_ENV).is_none() {
        eprintln!("skipping loaded-kinsn target test: set {KINSN_MODULE_TEST_ENV}=1 after loading kinsn modules");
        return;
    }

    let output = Command::new(bpfget_bin())
        .arg("--target")
        .output()
        .expect("run bpfget --target");

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let value = target_stdout_json(&output);
    let kinsns = value["kinsns"].as_object().expect("kinsns object");
    let expected_names = expected_kinsn_names();
    assert!(
        !expected_names.is_empty(),
        "BPFGET_TEST_EXPECT_KINSNS must name at least one kinsn"
    );
    for name in expected_names {
        let entry = kinsns
            .get(&name)
            .unwrap_or_else(|| panic!("target JSON missing loaded kinsn {name}: {value}"));
        let btf_func_id = entry["btf_func_id"]
            .as_i64()
            .or_else(|| {
                entry["btf_func_id"]
                    .as_u64()
                    .and_then(|id| i64::try_from(id).ok())
            })
            .unwrap_or_else(|| panic!("kinsn {name} missing numeric btf_func_id: {entry}"));
        assert!(btf_func_id >= 0, "kinsn {name} has negative id: {entry}");
    }
    assert!(
        !kinsns.contains_key("bpf_memcpy_bulk") && !kinsns.contains_key("bpf_memset_bulk"),
        "target JSON must use v3 bulk-memory names: {value}"
    );
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
