use std::process::Command;

fn permission_or_kernel_unavailable(stderr: &[u8]) -> bool {
    let stderr = String::from_utf8_lossy(stderr);
    if stderr.contains("perf_event_open") || stderr.contains("PMU branch counters") {
        return false;
    }

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
fn all_mode_writes_json_array_or_skips_without_kernel_access() {
    let output = Command::new(env!("CARGO_BIN_EXE_bpfprof"))
        .args(["--all", "--duration", "100ms"])
        .output()
        .expect("run bpfprof --all");
    if !output.status.success() && permission_or_kernel_unavailable(&output.stderr) {
        eprintln!("skipping kernel-dependent bpfprof --all test");
        return;
    }

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let json: serde_json::Value = serde_json::from_slice(&output.stdout).unwrap();
    let profiles = json.as_array().expect("json array");
    for profile in profiles {
        assert!(profile["pmu_available"].is_boolean(), "profile={profile}");
        assert!(profile["branch_miss_rate"].is_null(), "profile={profile}");
        assert!(profile["branch_misses"].is_null(), "profile={profile}");
        assert!(
            profile["branch_instructions"].is_null(),
            "profile={profile}"
        );
    }
    if String::from_utf8_lossy(&output.stderr).contains("PMU branch counters unavailable") {
        for profile in profiles {
            assert_eq!(profile["pmu_available"], false, "profile={profile}");
        }
    }
}

#[test]
fn show_mode_prints_table_or_skips_without_kernel_access() {
    let output = Command::new(env!("CARGO_BIN_EXE_bpfprof"))
        .args(["--all", "--duration", "100ms", "--show"])
        .output()
        .expect("run bpfprof --show");
    if !output.status.success() && permission_or_kernel_unavailable(&output.stderr) {
        eprintln!("skipping kernel-dependent bpfprof --show test");
        return;
    }

    assert!(
        output.status.success(),
        "stderr={}",
        String::from_utf8_lossy(&output.stderr)
    );
    let stdout = String::from_utf8_lossy(&output.stdout);
    assert!(stdout.contains("RANK"), "stdout={stdout}");
    assert!(stdout.contains("PROG_ID"), "stdout={stdout}");
}
