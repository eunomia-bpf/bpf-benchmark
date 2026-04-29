// SPDX-License-Identifier: MIT

use std::fs;
use std::io::Write;
use std::path::PathBuf;
use std::process::{Command, Output, Stdio};
use std::sync::atomic::{AtomicUsize, Ordering};

static NEXT_TEMP_ID: AtomicUsize = AtomicUsize::new(0);

fn bpfopt_bin() -> &'static str {
    env!("CARGO_BIN_EXE_bpfopt")
}

fn minimal_program_bytes() -> Vec<u8> {
    vec![
        0xb7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00,
    ]
}

fn temp_path(name: &str) -> PathBuf {
    let id = NEXT_TEMP_ID.fetch_add(1, Ordering::Relaxed);
    std::env::temp_dir().join(format!("bpfopt-cli-{}-{id}-{name}", std::process::id()))
}

fn write_temp_file(name: &str, contents: &str) -> PathBuf {
    let path = temp_path(name);
    fs::write(&path, contents).expect("write temp file");
    path
}

fn run_bpfopt(args: &[&str], stdin_bytes: &[u8]) -> Output {
    let mut child = Command::new(bpfopt_bin())
        .args(args)
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .expect("spawn bpfopt");
    child
        .stdin
        .as_mut()
        .expect("stdin pipe")
        .write_all(stdin_bytes)
        .expect("write stdin");
    child.wait_with_output().expect("wait bpfopt")
}

#[test]
fn list_passes_outputs_12_v3_cli_names() {
    let output = Command::new(bpfopt_bin())
        .arg("list-passes")
        .output()
        .expect("run list-passes");

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let stdout = String::from_utf8(output.stdout).expect("utf8 stdout");
    let passes = stdout.lines().collect::<Vec<_>>();

    assert_eq!(passes.len(), 12);
    assert!(passes.contains(&"wide-mem"));
    assert!(passes.contains(&"skb-load-bytes"));
}

#[test]
fn wide_mem_accepts_stdin_and_writes_instruction_aligned_stdout() {
    let input = minimal_program_bytes();
    let output = run_bpfopt(&["wide-mem"], &input);

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    assert_eq!(output.stdout.len() % 8, 0);
    assert_eq!(output.stdout, input);
}

#[test]
fn wide_mem_report_is_valid_pass_report_json() {
    let report_path = temp_path("wide-mem-report.json");
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &["wide-mem", "--report", &report_arg],
        &minimal_program_bytes(),
    );

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    fs::remove_file(report_path).ok();

    assert_eq!(report["pass"], "wide_mem");
    assert_eq!(report["changed"], false);
    assert_eq!(report["insn_count_before"], 2);
    assert_eq!(report["insn_count_after"], 2);
}

#[test]
fn optimize_default_pipeline_writes_json_report_array() {
    let report_path = temp_path("optimize-report.json");
    let report_arg = report_path.to_string_lossy().to_string();
    let input = minimal_program_bytes();
    let output = run_bpfopt(&["optimize", "--report", &report_arg], &input);

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    assert_eq!(output.stdout.len() % 8, 0);
    assert_eq!(output.stdout, input);
    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    fs::remove_file(report_path).ok();

    let passes = report["passes"].as_array().expect("passes array");
    let pass_names = passes
        .iter()
        .map(|pass| pass["pass"].as_str().expect("pass name"))
        .collect::<Vec<_>>();
    assert_eq!(
        pass_names,
        vec![
            "dce",
            "skb_load_bytes_spec",
            "bounds_check_merge",
            "wide_mem"
        ]
    );
}

#[test]
fn invalid_bytecode_length_exits_with_error() {
    let output = run_bpfopt(&["wide-mem"], &[0u8; 9]);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("multiple of 8"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
}

#[test]
fn direct_side_input_required_pass_fails_when_missing_input() {
    let output = run_bpfopt(&["const-prop"], &minimal_program_bytes());

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("--verifier-states"), "stderr={stderr}");
}

#[test]
fn rotate_with_empty_target_kinsns_exits_with_error() {
    let target_path = write_temp_file(
        "empty-target.json",
        r#"{"arch":"x86_64","features":["cmov"],"kinsns":{}}"#,
    );
    let target_arg = target_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &["rotate", "--target", &target_arg],
        &minimal_program_bytes(),
    );
    fs::remove_file(target_path).ok();

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("kinsn 'bpf_rotate64' not in target"),
        "stderr={stderr}"
    );
    assert!(output.stdout.is_empty());
}

#[test]
fn cond_select_with_empty_target_kinsns_exits_with_error() {
    let target_path = write_temp_file(
        "empty-target.json",
        r#"{"arch":"x86_64","features":["cmov"],"kinsns":{}}"#,
    );
    let target_arg = target_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &["cond-select", "--target", &target_arg],
        &minimal_program_bytes(),
    );
    fs::remove_file(target_path).ok();

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("kinsn 'bpf_select64' not in target"),
        "stderr={stderr}"
    );
    assert!(output.stdout.is_empty());
}

#[test]
fn optimize_explicit_const_prop_fails_when_verifier_states_missing() {
    let output = run_bpfopt(
        &["optimize", "--passes", "const-prop"],
        &minimal_program_bytes(),
    );

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("--verifier-states"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
}

#[test]
fn optimize_explicit_map_inline_fails_when_map_side_inputs_missing() {
    let output = run_bpfopt(
        &["optimize", "--passes", "map-inline"],
        &minimal_program_bytes(),
    );

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("--map-values and --map-ids"),
        "stderr={stderr}"
    );
    assert!(output.stdout.is_empty());
}

#[test]
fn optimize_explicit_kinsn_pass_fails_when_target_lacks_kinsn() {
    let target_path = write_temp_file(
        "empty-target.json",
        r#"{"arch":"x86_64","features":["cmov"],"kinsns":{}}"#,
    );
    let target_arg = target_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "optimize",
            "--passes",
            "wide-mem,rotate",
            "--target",
            &target_arg,
        ],
        &minimal_program_bytes(),
    );
    fs::remove_file(target_path).ok();

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("kinsn 'bpf_rotate64' not in target"),
        "stderr={stderr}"
    );
    assert!(output.stdout.is_empty());
}
