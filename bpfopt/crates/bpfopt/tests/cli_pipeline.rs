// SPDX-License-Identifier: MIT

use std::fs;
use std::io::Write;
use std::path::{Path, PathBuf};
use std::process::{Command, Output, Stdio};
use std::sync::atomic::{AtomicUsize, Ordering};

use bpfopt::insn::{
    BpfInsn, BPF_ADD, BPF_ALU64, BPF_CALL, BPF_DW, BPF_EXIT, BPF_IMM, BPF_JMP, BPF_K, BPF_LD,
    BPF_LDX, BPF_MEM, BPF_MOV, BPF_PSEUDO_MAP_FD, BPF_ST, BPF_W,
};

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

fn map_lookup_program_bytes() -> Vec<u8> {
    let map = [
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(1, BPF_PSEUDO_MAP_FD),
            0,
            42,
        ),
        BpfInsn::new(0, 0, 0, 0),
    ];
    [
        map[0],
        map[1],
        BpfInsn::new(BPF_ST | BPF_W | BPF_MEM, BpfInsn::make_regs(10, 0), -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::new(BPF_ALU64 | BPF_ADD | BPF_K, BpfInsn::make_regs(2, 0), 0, -4),
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 1),
        BpfInsn::new(BPF_LDX | BPF_W | BPF_MEM, BpfInsn::make_regs(6, 0), 0, 0),
        BpfInsn::new(BPF_ALU64 | BPF_MOV | BPF_K, BpfInsn::make_regs(0, 0), 0, 0),
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0),
    ]
    .into_iter()
    .flat_map(|insn| insn.raw_bytes())
    .collect()
}

fn two_hash_lookup_program_bytes() -> Vec<u8> {
    let map = [
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(1, BPF_PSEUDO_MAP_FD),
            0,
            42,
        ),
        BpfInsn::new(0, 0, 0, 0),
    ];
    [
        map[0],
        map[1],
        BpfInsn::new(BPF_ST | BPF_W | BPF_MEM, BpfInsn::make_regs(10, 0), -4, 1),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::new(BPF_ALU64 | BPF_ADD | BPF_K, BpfInsn::make_regs(2, 0), 0, -4),
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 1),
        BpfInsn::new(
            BPF_JMP | bpfopt::insn::BPF_JEQ | BPF_K,
            BpfInsn::make_regs(0, 0),
            3,
            0,
        ),
        BpfInsn::new(BPF_LDX | BPF_W | BPF_MEM, BpfInsn::make_regs(6, 0), 0, 0),
        BpfInsn::new(BPF_ALU64 | BPF_MOV | BPF_K, BpfInsn::make_regs(0, 0), 0, 0),
        BpfInsn::new(BPF_JMP | bpfopt::insn::BPF_JA | BPF_K, 0, 1, 0),
        BpfInsn::new(BPF_ALU64 | BPF_MOV | BPF_K, BpfInsn::make_regs(0, 0), 0, 1),
        map[0],
        map[1],
        BpfInsn::new(BPF_ST | BPF_W | BPF_MEM, BpfInsn::make_regs(10, 0), -8, 2),
        BpfInsn::mov64_reg(2, 10),
        BpfInsn::new(BPF_ALU64 | BPF_ADD | BPF_K, BpfInsn::make_regs(2, 0), 0, -8),
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 1),
        BpfInsn::new(
            BPF_JMP | bpfopt::insn::BPF_JEQ | BPF_K,
            BpfInsn::make_regs(0, 0),
            3,
            0,
        ),
        BpfInsn::new(BPF_LDX | BPF_W | BPF_MEM, BpfInsn::make_regs(7, 0), 0, 0),
        BpfInsn::new(BPF_ALU64 | BPF_MOV | BPF_K, BpfInsn::make_regs(0, 0), 0, 0),
        BpfInsn::new(BPF_JMP | bpfopt::insn::BPF_JA | BPF_K, 0, 1, 0),
        BpfInsn::new(BPF_ALU64 | BPF_MOV | BPF_K, BpfInsn::make_regs(0, 0), 0, 1),
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0),
    ]
    .into_iter()
    .flat_map(|insn| insn.raw_bytes())
    .collect()
}

fn temp_path(name: &str) -> PathBuf {
    let id = NEXT_TEMP_ID.fetch_add(1, Ordering::Relaxed);
    std::env::temp_dir().join(format!("bpfopt-cli-{}-{id}-{name}", std::process::id()))
}

fn remove_file_if_exists(path: impl AsRef<Path>) {
    let path = path.as_ref();
    match fs::remove_file(path) {
        Ok(()) => {}
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => {}
        Err(err) => panic!("remove {}: {err}", path.display()),
    }
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
fn list_passes_outputs_12_cli_names_including_branch_flip() {
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
    assert!(passes.contains(&"branch-flip"));
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
fn optimize_default_pipeline_fails_when_required_side_inputs_are_missing() {
    let report_path = temp_path("optimize-report.json");
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &["optimize", "--report", &report_arg],
        &minimal_program_bytes(),
    );

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("map-inline requires --map-values and --map-ids"),
        "stderr={stderr}"
    );
    assert!(output.stdout.is_empty());
    assert!(!report_path.exists());
    remove_file_if_exists(report_path);
}

#[test]
fn optimize_without_target_fails_before_running_kinsn_passes() {
    let report_path = temp_path("optimize-kinsn-skip-report.json");
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "optimize",
            "--passes",
            "rotate,cond-select",
            "--report",
            &report_arg,
        ],
        &minimal_program_bytes(),
    );

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("rotate requires --target or --kinsns"),
        "stderr={stderr}"
    );
    assert!(output.stdout.is_empty());
    assert!(!report_path.exists());
    remove_file_if_exists(report_path);
}

#[test]
fn optimize_default_pipeline_with_all_side_inputs_reports_11_entries() {
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
    let map_values_path = write_temp_file("map-values.json", r#"{"maps":[]}"#);
    let report_arg = report_path.to_string_lossy().to_string();
    let target_arg = target_path.to_string_lossy().to_string();
    let verifier_arg = verifier_path.to_string_lossy().to_string();
    let map_values_arg = map_values_path.to_string_lossy().to_string();

    let output = run_bpfopt(
        &[
            "optimize",
            "--target",
            &target_arg,
            "--verifier-states",
            &verifier_arg,
            "--map-values",
            &map_values_arg,
            "--map-ids",
            "1",
            "--report",
            &report_arg,
        ],
        &minimal_program_bytes(),
    );
    remove_file_if_exists(target_path);
    remove_file_if_exists(verifier_path);
    remove_file_if_exists(map_values_path);

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    remove_file_if_exists(report_path);

    let passes = report["passes"].as_array().expect("passes array");
    assert_eq!(passes.len(), 11);
    assert!(passes.iter().all(|pass| pass["pass"] != "branch_flip"));
    assert!(
        passes
            .iter()
            .all(|pass| pass.get("skipped").is_none() && pass.get("reason").is_none()),
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
fn optimize_map_inline_errors_when_snapshot_key_is_absent() {
    let map_values_path = write_temp_file(
        "map-values-absent-key.json",
        r#"{"maps":[{"map_id":111,"map_type":2,"key_size":4,"value_size":4,"max_entries":8,"frozen":true,"entries":[]}]}"#,
    );
    let map_values_arg = map_values_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "optimize",
            "--passes",
            "map-inline",
            "--map-values",
            &map_values_arg,
            "--map-ids",
            "111",
        ],
        &map_lookup_program_bytes(),
    );
    remove_file_if_exists(map_values_path);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("map_inline requires a concrete snapshot value"),
        "stderr={stderr}"
    );
    assert!(
        stderr.contains("map_values snapshot missing map 111 key 01000000"),
        "stderr={stderr}"
    );
}

#[test]
fn optimize_map_inline_skips_hash_lookup_when_snapshot_value_is_null() {
    let report_path = temp_path("map-inline-hash-null-report.json");
    let map_values_path = write_temp_file(
        "map-values-hash-null.json",
        r#"{"maps":[{"map_id":111,"map_type":"hash","key_size":4,"value_size":4,"max_entries":8,"frozen":true,"entries":[{"key":"01000000","value":null},{"key":"02000000","value":"09000000"}]}]}"#,
    );
    let report_arg = report_path.to_string_lossy().to_string();
    let map_values_arg = map_values_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "optimize",
            "--passes",
            "map-inline",
            "--report",
            &report_arg,
            "--map-values",
            &map_values_arg,
            "--map-ids",
            "111",
        ],
        &two_hash_lookup_program_bytes(),
    );
    remove_file_if_exists(map_values_path);

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    remove_file_if_exists(report_path);

    let pass = &report["passes"][0];
    assert_eq!(pass["pass"], "map_inline");
    assert_eq!(pass["changed"], true);
    assert_eq!(pass["sites_applied"], 1);
    assert_eq!(pass["map_inline_records"].as_array().unwrap().len(), 1);
    assert_eq!(pass["map_inline_records"][0]["key_hex"], "02000000");
}

#[test]
fn optimize_explicit_kinsn_pass_fails_when_target_lacks_kinsn() {
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
    remove_file_if_exists(target_path);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("kinsn 'bpf_rotate64' not in target"),
        "stderr={stderr}"
    );
    assert!(output.stdout.is_empty());
    assert!(!report_path.exists());
    remove_file_if_exists(report_path);
}

#[test]
fn optimize_bulk_memory_missing_kinsns_fails_with_v3_names() {
    let target_path = write_temp_file(
        "empty-target.json",
        r#"{"arch":"x86_64","features":["cmov"],"kinsns":{}}"#,
    );
    let report_path = temp_path("bulk-memory-target-lacks-kinsn-report.json");
    let target_arg = target_path.to_string_lossy().to_string();
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "optimize",
            "--passes",
            "bulk-memory",
            "--target",
            &target_arg,
            "--report",
            &report_arg,
        ],
        &minimal_program_bytes(),
    );
    remove_file_if_exists(target_path);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("bulk-memory requires target kinsns: bpf_bulk_memcpy, bpf_bulk_memset"),
        "stderr={stderr}"
    );
    assert!(!stderr.contains("bpf_memcpy_bulk"), "stderr={stderr}");
    assert!(!stderr.contains("bpf_memset_bulk"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
    assert!(!report_path.exists());
    remove_file_if_exists(report_path);
}
