// SPDX-License-Identifier: MIT

use std::fs;
use std::io::Write;
use std::path::{Path, PathBuf};
use std::process::{Command, Output, Stdio};
use std::sync::atomic::{AtomicUsize, Ordering};

static NEXT_TEMP_ID: AtomicUsize = AtomicUsize::new(0);

fn bpfrejit_bin() -> &'static str {
    env!("CARGO_BIN_EXE_bpfrejit")
}

fn minimal_program_bytes() -> Vec<u8> {
    vec![
        0xb7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00,
    ]
}

fn temp_path(name: &str) -> PathBuf {
    let id = NEXT_TEMP_ID.fetch_add(1, Ordering::Relaxed);
    std::env::temp_dir().join(format!("bpfrejit-cli-{}-{id}-{name}", std::process::id()))
}

fn remove_file_if_exists(path: impl AsRef<Path>) {
    let path = path.as_ref();
    match fs::remove_file(path) {
        Ok(()) => {}
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => {}
        Err(err) => panic!("remove {}: {err}", path.display()),
    }
}

fn write_temp_file(name: &str, bytes: impl AsRef<[u8]>) -> PathBuf {
    let path = temp_path(name);
    fs::write(&path, bytes).expect("write temp file");
    path
}

fn run_bpfrejit(args: &[&str], stdin_bytes: &[u8]) -> Output {
    let mut child = Command::new(bpfrejit_bin())
        .args(args)
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .expect("spawn bpfrejit");
    child
        .stdin
        .as_mut()
        .expect("stdin pipe")
        .write_all(stdin_bytes)
        .expect("write stdin");
    child.wait_with_output().expect("wait bpfrejit")
}

#[test]
fn rejects_input_length_that_is_not_instruction_aligned() {
    let path = temp_path("bad.bin");
    fs::write(&path, [0u8; 9]).expect("write bad bytecode");
    let path_arg = path.to_string_lossy().to_string();

    let output = Command::new(bpfrejit_bin())
        .args(["0", &path_arg])
        .output()
        .expect("run bpfrejit");
    remove_file_if_exists(path);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("multiple of 8"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
}

#[test]
fn dry_run_reads_valid_stdin_before_opening_target_program() {
    let output = run_bpfrejit(&["--dry-run", "0"], &minimal_program_bytes());

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("open BPF program id 0"), "stderr={stderr}");
    assert!(!stderr.contains("multiple of 8"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
}

#[test]
fn fd_array_malformed_json_exits_with_parse_error() {
    let bytecode_path = write_temp_file("prog.bin", minimal_program_bytes());
    let fd_array_path = write_temp_file("malformed.json", b"{ not json");
    let bytecode_arg = bytecode_path.to_string_lossy().to_string();
    let fd_array_arg = fd_array_path.to_string_lossy().to_string();

    let output = Command::new(bpfrejit_bin())
        .args(["--fd-array", &fd_array_arg, "0", &bytecode_arg])
        .output()
        .expect("run bpfrejit with malformed fd_array JSON");
    remove_file_if_exists(bytecode_path);
    remove_file_if_exists(fd_array_path);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("failed to parse fd_array JSON"),
        "stderr={stderr}"
    );
    assert!(!stderr.contains("open BPF program id 0"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
}

#[test]
fn fd_array_missing_btf_fd_exits_with_friendly_error() {
    let bytecode_path = write_temp_file("prog.bin", minimal_program_bytes());
    let fd_array_path = write_temp_file("missing-btf-fd.json", br#"[{"name":"bpf_rotate64"}]"#);
    let bytecode_arg = bytecode_path.to_string_lossy().to_string();
    let fd_array_arg = fd_array_path.to_string_lossy().to_string();

    let output = Command::new(bpfrejit_bin())
        .args(["--fd-array", &fd_array_arg, "0", &bytecode_arg])
        .output()
        .expect("run bpfrejit with fd_array missing btf_fd");
    remove_file_if_exists(bytecode_path);
    remove_file_if_exists(fd_array_path);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("missing btf_fd"), "stderr={stderr}");
    assert!(!stderr.contains("open BPF program id 0"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
}

#[test]
fn map_fds_malformed_json_exits_before_opening_target_program() {
    let bytecode_path = write_temp_file("prog.bin", minimal_program_bytes());
    let map_fds_path = write_temp_file("malformed-map-fds.json", b"{ not json");
    let bytecode_arg = bytecode_path.to_string_lossy().to_string();
    let map_fds_arg = map_fds_path.to_string_lossy().to_string();

    let output = Command::new(bpfrejit_bin())
        .args(["--map-fds", &map_fds_arg, "0", &bytecode_arg])
        .output()
        .expect("run bpfrejit with malformed map_fds JSON");
    remove_file_if_exists(bytecode_path);
    remove_file_if_exists(map_fds_path);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("failed to parse map_fds JSON"),
        "stderr={stderr}"
    );
    assert!(!stderr.contains("open BPF program id 0"), "stderr={stderr}");
    assert!(output.stdout.is_empty());
}

#[test]
fn dry_run_accepts_fd_array_before_opening_target_program() {
    let fd_array_path =
        write_temp_file("fd-array.json", br#"[{"name":"bpf_rotate64","btf_fd":0}]"#);
    let fd_array_arg = fd_array_path.to_string_lossy().to_string();

    let output = run_bpfrejit(
        &["--dry-run", "--fd-array", &fd_array_arg, "0"],
        &minimal_program_bytes(),
    );
    remove_file_if_exists(fd_array_path);

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("open BPF program id 0"), "stderr={stderr}");
    assert!(
        !stderr.contains("--dry-run with --fd-array is not supported"),
        "stderr={stderr}"
    );
    assert!(output.stdout.is_empty());
}
