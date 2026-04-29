// SPDX-License-Identifier: MIT

use std::process::Command;

fn bpfget_bin() -> &'static str {
    env!("CARGO_BIN_EXE_bpfget")
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
