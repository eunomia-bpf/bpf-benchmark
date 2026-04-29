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
            "map_inline",
            "const_prop",
            "dce",
            "skb_load_bytes_spec",
            "bounds_check_merge",
            "wide_mem",
            "bulk_memory",
            "rotate",
            "cond_select",
            "extract",
            "endian_fusion",
            "branch_flip"
        ]
    );
    assert_eq!(passes.len(), 12);
    assert_eq!(passes[0]["skipped"], true);
    assert_eq!(passes[1]["skipped"], true);
    assert_eq!(passes[2]["skipped"], false);
    assert_eq!(passes[6]["reason"], "missing --target kinsns");
    assert_eq!(passes[11]["reason"], "missing --profile");
}

#[test]
fn optimize_without_target_skips_kinsn_passes_with_warning() {
    let report_path = temp_path("optimize-kinsn-skip-report.json");
    let report_arg = report_path.to_string_lossy().to_string();
    let input = minimal_program_bytes();
    let output = run_bpfopt(
        &[
            "optimize",
            "--passes",
            "rotate,cond-select",
            "--report",
            &report_arg,
        ],
        &input,
    );

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    assert_eq!(output.stdout, input);
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("warning: skipping rotate: missing --target kinsns"),
        "stderr={stderr}"
    );
    assert!(
        stderr.contains("warning: skipping cond-select: missing --target kinsns"),
        "stderr={stderr}"
    );

    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    fs::remove_file(report_path).ok();
    let passes = report["passes"].as_array().expect("passes array");
    assert_eq!(passes.len(), 2);
    assert_eq!(passes[0]["pass"], "rotate");
    assert_eq!(passes[0]["skipped"], true);
    assert_eq!(passes[0]["reason"], "missing --target kinsns");
    assert_eq!(passes[1]["pass"], "cond_select");
    assert_eq!(passes[1]["skipped"], true);
    assert_eq!(passes[1]["reason"], "missing --target kinsns");
}

#[test]
fn optimize_default_pipeline_with_all_side_inputs_reports_12_entries() {
    let report_path = temp_path("optimize-full-report.json");
    let target_path = write_temp_file(
        "target.json",
        r#"{
            "arch":"x86_64",
            "features":["cmov","movbe","bmi1","bmi2","rorx"],
            "kinsns":{
                "bpf_rotate64":{"btf_func_id":1001},
                "bpf_select64":{"btf_func_id":1002},
                "bpf_extract64":{"btf_func_id":1003},
                "bpf_endian_load64":{"btf_func_id":1004},
                "bpf_bulk_memcpy":{"btf_func_id":1005},
                "bpf_bulk_memset":{"btf_func_id":1006}
            }
        }"#,
    );
    let verifier_path = write_temp_file("verifier-states.json", r#"{"insns":[]}"#);
    let profile_path = write_temp_file("profile.json", r#"{"per_insn":{}}"#);
    let map_values_path = write_temp_file("map-values.json", r#"{"maps":[]}"#);
    let report_arg = report_path.to_string_lossy().to_string();
    let target_arg = target_path.to_string_lossy().to_string();
    let verifier_arg = verifier_path.to_string_lossy().to_string();
    let profile_arg = profile_path.to_string_lossy().to_string();
    let map_values_arg = map_values_path.to_string_lossy().to_string();

    let output = run_bpfopt(
        &[
            "optimize",
            "--target",
            &target_arg,
            "--verifier-states",
            &verifier_arg,
            "--profile",
            &profile_arg,
            "--map-values",
            &map_values_arg,
            "--map-ids",
            "1",
            "--report",
            &report_arg,
        ],
        &minimal_program_bytes(),
    );
    fs::remove_file(target_path).ok();
    fs::remove_file(verifier_path).ok();
    fs::remove_file(profile_path).ok();
    fs::remove_file(map_values_path).ok();

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    fs::remove_file(report_path).ok();

    let passes = report["passes"].as_array().expect("passes array");
    assert_eq!(passes.len(), 12);
    assert!(
        passes.iter().all(|pass| pass["skipped"] == false),
        "report={report}"
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
fn optimize_explicit_const_prop_skips_when_verifier_states_missing() {
    let report_path = temp_path("const-prop-skip-report.json");
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "optimize",
            "--passes",
            "const-prop",
            "--report",
            &report_arg,
        ],
        &minimal_program_bytes(),
    );

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("warning: skipping const-prop: missing --verifier-states"),
        "stderr={stderr}"
    );
    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    fs::remove_file(report_path).ok();
    assert_eq!(report["passes"][0]["pass"], "const_prop");
    assert_eq!(report["passes"][0]["skipped"], true);
}

#[test]
fn optimize_explicit_map_inline_skips_when_map_side_inputs_missing() {
    let report_path = temp_path("map-inline-skip-report.json");
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "optimize",
            "--passes",
            "map-inline",
            "--report",
            &report_arg,
        ],
        &minimal_program_bytes(),
    );

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("warning: skipping map-inline: missing --map-values and --map-ids"),
        "stderr={stderr}"
    );
    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    fs::remove_file(report_path).ok();
    assert_eq!(report["passes"][0]["pass"], "map_inline");
    assert_eq!(report["passes"][0]["skipped"], true);
}

#[test]
fn optimize_explicit_kinsn_pass_skips_when_target_lacks_kinsn() {
    let target_path = write_temp_file(
        "empty-target.json",
        r#"{"arch":"x86_64","features":["cmov"],"kinsns":{}}"#,
    );
    let report_path = temp_path("target-lacks-kinsn-report.json");
    let target_arg = target_path.to_string_lossy().to_string();
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "optimize",
            "--passes",
            "wide-mem,rotate",
            "--target",
            &target_arg,
            "--report",
            &report_arg,
        ],
        &minimal_program_bytes(),
    );
    fs::remove_file(target_path).ok();

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("warning: skipping rotate: missing --target kinsns: bpf_rotate64"),
        "stderr={stderr}"
    );
    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    fs::remove_file(report_path).ok();
    assert_eq!(report["passes"][0]["pass"], "wide_mem");
    assert_eq!(report["passes"][0]["skipped"], false);
    assert_eq!(report["passes"][1]["pass"], "rotate");
    assert_eq!(report["passes"][1]["skipped"], true);
    assert_eq!(
        report["passes"][1]["reason"],
        "missing --target kinsns: bpf_rotate64"
    );
}
