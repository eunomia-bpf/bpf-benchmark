use std::process::Command;

fn pmu_unavailable(stderr: &[u8]) -> bool {
    let stderr = String::from_utf8_lossy(stderr);
    stderr.contains("perf_event_open")
        || stderr.contains("PMU branch counters")
        || stderr.contains("open branch-instructions PMU counter")
        || stderr.contains("open branch-misses PMU counter")
}

fn kernel_access_unavailable(stderr: &[u8]) -> bool {
    let stderr = String::from_utf8_lossy(stderr);
    stderr.contains("Operation not permitted")
        || stderr.contains("Permission denied")
        || stderr.contains("BPF_ENABLE_STATS")
}

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

#[test]
fn all_mode_pmu_unavailable_exits_with_error() {
    let output = Command::new(env!("CARGO_BIN_EXE_bpfprof"))
        .args(["--all", "--duration", "100ms"])
        .output()
        .expect("run bpfprof --all");
    if output.status.success() {
        eprintln!("skipping PMU failure test: PMU branch counters are available");
        return;
    }
    if kernel_access_unavailable(&output.stderr) && !pmu_unavailable(&output.stderr) {
        eprintln!("skipping PMU failure test: kernel access unavailable before PMU setup");
        return;
    }

    assert!(pmu_unavailable(&output.stderr));
    assert!(output.stdout.is_empty());
}
