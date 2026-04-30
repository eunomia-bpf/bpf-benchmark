use std::process::Command;

#[test]
fn nonexistent_prog_id_exits_with_error() {
    let output = Command::new(env!("CARGO_BIN_EXE_bpfprof"))
        .args(["--prog-id", "0", "--duration", "100ms"])
        .output()
        .expect("run bpfprof");

    assert!(!output.status.success());
    let stderr = String::from_utf8_lossy(&output.stderr);
    assert!(stderr.contains("open BPF program id 0"), "stderr={stderr}");
}
