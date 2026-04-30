use std::process::Command;

#[test]
fn nonexistent_prog_id_exits_with_error() {
    let output_path =
        std::env::temp_dir().join(format!("bpfprof-cli-{}-missing.json", std::process::id()));
    let output_arg = output_path.to_string_lossy().to_string();
    let output = Command::new(env!("CARGO_BIN_EXE_bpfprof"))
        .args([
            "--prog-id",
            "0",
            "--duration",
            "100ms",
            "--output",
            &output_arg,
        ])
        .output()
        .expect("run bpfprof");

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("open BPF program id 0"), "stderr={stderr}");
}

#[test]
fn profile_json_requires_side_output_file() {
    let output = Command::new(env!("CARGO_BIN_EXE_bpfprof"))
        .args(["--prog-id", "0", "--duration", "100ms"])
        .output()
        .expect("run bpfprof");

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(
        stderr.contains("profile JSON side-output requires --output FILE or --output-dir DIR"),
        "stderr={stderr}"
    );
    assert!(output.stdout.is_empty());
}
