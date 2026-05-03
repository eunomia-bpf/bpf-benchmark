// SPDX-License-Identifier: MIT

use std::fs;
use std::io::{ErrorKind, Write};
use std::path::{Path, PathBuf};
use std::process::{Command, Output, Stdio};
use std::sync::atomic::{AtomicUsize, Ordering};

use bpfopt::insn::{
    BpfInsn, BPF_ADD, BPF_ALU64, BPF_CALL, BPF_DW, BPF_EXIT, BPF_IMM, BPF_JA, BPF_JMP, BPF_K,
    BPF_LD, BPF_LDX, BPF_MEM, BPF_MOV, BPF_PSEUDO_MAP_FD, BPF_PSEUDO_MAP_IDX, BPF_ST, BPF_W,
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

fn decode_insns(bytes: &[u8]) -> Vec<BpfInsn> {
    assert_eq!(bytes.len() % 8, 0);
    bytes
        .chunks_exact(8)
        .map(|chunk| {
            BpfInsn::from_raw_bytes([
                chunk[0], chunk[1], chunk[2], chunk[3], chunk[4], chunk[5], chunk[6], chunk[7],
            ])
        })
        .collect()
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

fn unreachable_idx_then_live_idx_program_bytes() -> Vec<u8> {
    let dead_map = [
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(1, BPF_PSEUDO_MAP_IDX),
            0,
            0,
        ),
        BpfInsn::new(0, 0, 0, 0),
    ];
    let live_map = [
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(1, BPF_PSEUDO_MAP_IDX),
            0,
            1,
        ),
        BpfInsn::new(0, 0, 0, 0),
    ];
    [
        BpfInsn::new(BPF_JMP | BPF_JA | BPF_K, 0, 2, 0),
        dead_map[0],
        dead_map[1],
        live_map[0],
        live_map[1],
        BpfInsn::new(BPF_JMP | BPF_CALL, BpfInsn::make_regs(0, 0), 0, 1),
        BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0),
    ]
    .into_iter()
    .flat_map(|insn| insn.raw_bytes())
    .collect()
}

fn map_lookup_verifier_states_json() -> &'static str {
    r#"{"insns":[
        {"pc":2,"regs":{}},
        {"pc":4,"regs":{"r2":{"type":"fp","offset":-4}}},
        {"pc":5,"regs":{}}
    ]}"#
}

fn two_hash_lookup_verifier_states_json() -> &'static str {
    r#"{"insns":[
        {"pc":2,"regs":{}},
        {"pc":4,"regs":{"r2":{"type":"fp","offset":-4}}},
        {"pc":5,"regs":{}},
        {"pc":13,"regs":{}},
        {"pc":15,"regs":{"r2":{"type":"fp","offset":-8}}},
        {"pc":16,"regs":{}}
    ]}"#
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
    if let Err(err) = child
        .stdin
        .as_mut()
        .expect("stdin pipe")
        .write_all(stdin_bytes)
    {
        if err.kind() != ErrorKind::BrokenPipe {
            panic!("write stdin: {err}");
        }
    }
    child.wait_with_output().expect("wait bpfopt")
}

#[test]
fn list_passes_outputs_cli_names_including_experimental_passes() {
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

    assert_eq!(passes.len(), 14);
    assert!(passes.contains(&"wide-mem"));
    assert!(passes.contains(&"skb-load-bytes"));
    assert!(passes.contains(&"ccmp"));
    assert!(passes.contains(&"branch-flip"));
    assert!(passes.contains(&"prefetch"));
}

#[test]
fn wide_mem_accepts_stdin_and_writes_instruction_aligned_stdout() {
    let input = minimal_program_bytes();
    let output = run_bpfopt(&["--pass", "wide-mem"], &input);

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    assert_eq!(output.stdout.len() % 8, 0);
    assert_eq!(output.stdout, input);
}

#[test]
fn dce_deletes_unreachable_pseudo_map_idx_without_rebinding_live_idx() {
    let output = run_bpfopt(
        &["--pass", "dce"],
        &unreachable_idx_then_live_idx_program_bytes(),
    );

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let insns = decode_insns(&output.stdout);
    let map_loads = insns
        .iter()
        .filter(|insn| insn.is_ldimm64() && insn.src_reg() == BPF_PSEUDO_MAP_IDX)
        .map(|insn| insn.imm)
        .collect::<Vec<_>>();
    assert_eq!(map_loads, vec![1]);
}

#[test]
fn command_requires_single_pass_name() {
    let report_path = temp_path("optimize-report.json");
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(&["--report", &report_arg], &minimal_program_bytes());

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("requires --pass <name>"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
    assert!(!report_path.exists());
    remove_file_if_exists(report_path);
}

#[test]
fn single_kinsn_pass_without_target_fails_before_running() {
    let report_path = temp_path("optimize-kinsn-skip-report.json");
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &["--pass", "rotate", "--report", &report_arg],
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
fn invalid_bytecode_length_exits_with_error() {
    let output = run_bpfopt(&["--pass", "wide-mem"], &[0u8; 9]);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("multiple of 8"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
}

#[test]
fn map_inline_errors_when_snapshot_key_is_absent() {
    let map_values_path = write_temp_file(
        "map-values-absent-key.json",
        r#"{"maps":[{"map_id":111,"map_type":2,"key_size":4,"value_size":4,"max_entries":8,"frozen":true,"entries":[]}]}"#,
    );
    let verifier_path = write_temp_file(
        "map-lookup-verifier-states.json",
        map_lookup_verifier_states_json(),
    );
    let map_values_arg = map_values_path.to_string_lossy().to_string();
    let verifier_arg = verifier_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "--pass",
            "map-inline",
            "--verifier-states",
            &verifier_arg,
            "--map-values",
            &map_values_arg,
            "--map-ids",
            "111",
        ],
        &map_lookup_program_bytes(),
    );
    remove_file_if_exists(map_values_path);
    remove_file_if_exists(verifier_path);

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
fn map_inline_skips_hash_lookup_when_snapshot_value_is_null() {
    let report_path = temp_path("map-inline-hash-null-report.json");
    let map_values_path = write_temp_file(
        "map-values-hash-null.json",
        r#"{"maps":[{"map_id":111,"map_type":"hash","key_size":4,"value_size":4,"max_entries":8,"frozen":true,"entries":[{"key":"01000000","value":null},{"key":"02000000","value":"09000000"}]}]}"#,
    );
    let report_arg = report_path.to_string_lossy().to_string();
    let map_values_arg = map_values_path.to_string_lossy().to_string();
    let verifier_path = write_temp_file(
        "two-hash-lookup-verifier-states.json",
        two_hash_lookup_verifier_states_json(),
    );
    let verifier_arg = verifier_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "--pass",
            "map-inline",
            "--report",
            &report_arg,
            "--verifier-states",
            &verifier_arg,
            "--map-values",
            &map_values_arg,
            "--map-ids",
            "111",
        ],
        &two_hash_lookup_program_bytes(),
    );
    remove_file_if_exists(map_values_path);
    remove_file_if_exists(verifier_path);

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let report_text = fs::read_to_string(&report_path).expect("read report");
    let report: serde_json::Value = serde_json::from_str(&report_text).expect("report json");
    remove_file_if_exists(report_path);

    assert_eq!(report["pass"], "map_inline");
    assert_eq!(report["changed"], true);
    assert_eq!(report["sites_applied"], 1);
    assert_eq!(report["map_inline_records"].as_array().unwrap().len(), 1);
    assert_eq!(report["map_inline_records"][0]["key_hex"], "02000000");
}

#[test]
fn explicit_kinsn_pass_fails_when_target_lacks_kinsn() {
    let target_path = write_temp_file(
        "empty-target.json",
        r#"{"arch":"x86_64","features":["cmov"],"kinsns":{}}"#,
    );
    let report_path = temp_path("target-lacks-kinsn-report.json");
    let target_arg = target_path.to_string_lossy().to_string();
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "--pass",
            "rotate",
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
fn bulk_memory_missing_kinsns_fails_with_v3_names() {
    let target_path = write_temp_file(
        "empty-target.json",
        r#"{"arch":"x86_64","features":["cmov"],"kinsns":{}}"#,
    );
    let report_path = temp_path("bulk-memory-target-lacks-kinsn-report.json");
    let target_arg = target_path.to_string_lossy().to_string();
    let report_arg = report_path.to_string_lossy().to_string();
    let output = run_bpfopt(
        &[
            "--pass",
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
