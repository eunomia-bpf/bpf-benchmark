// SPDX-License-Identifier: MIT

use std::fs;
use std::io::Write;
use std::path::PathBuf;
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
    fs::remove_file(path).ok();

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
