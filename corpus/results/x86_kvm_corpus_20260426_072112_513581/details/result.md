# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "fatal_error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
  "generated_at": "2026-04-26T07:27:30.461130+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-26T07:21:12.542767+00:00",
    "daemon_binary": "daemon/target/release/bpfrejit-daemon",
    "expected_modules": [
      "bpf_bulk_memory",
      "bpf_endian",
      "bpf_extract",
      "bpf_rotate",
      "bpf_select"
    ],
    "module_load": {
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "failed_modules": [],
      "invoked_at": "2026-04-26T07:21:12.542661+00:00",
      "loaded_count": 5,
      "loaded_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "loader": "runner.libs.kinsn.load_kinsn_modules",
      "module_dir": "/artifacts/kinsn",
      "newly_loaded_modules": [],
      "snapshot_after": {
        "captured_at": "2026-04-26T07:21:12.542639+00:00",
        "expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_rotate",
          "bpf_select"
        ],
        "loaded_bpf_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_rotate",
          "bpf_select"
        ],
        "missing_expected_modules": [],
        "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
        "resident_expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_rotate",
          "bpf_select"
        ],
        "source": "lsmod"
      },
      "status": "ok",
      "total_count": 5
    },
    "module_snapshot_before_daemon": {
      "captured_at": "2026-04-26T07:21:12.532103+00:00",
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "loaded_bpf_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "missing_expected_modules": [],
      "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
      "resident_expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "source": "lsmod"
    }
  },
  "manifest": "/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml",
  "results": [
    {
      "app": "bcc/capable",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "exec_storm",
      "status": "error"
    },
    {
      "app": "bcc/execsnoop",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "exec_storm",
      "status": "error"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "bind_storm",
      "status": "error"
    },
    {
      "app": "bcc/biosnoop",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "block_io",
      "status": "error"
    },
    {
      "app": "bcc/vfsstat",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "vfs_create_fsync_exact",
      "status": "error"
    },
    {
      "app": "bcc/opensnoop",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "open_family_storm",
      "status": "error"
    },
    {
      "app": "bcc/syscount",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "file_open_storm",
      "status": "error"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "bcc/tcplife",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "bcc/runqlat",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "hackbench",
      "status": "error"
    },
    {
      "app": "calico/felix",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "calico",
      "selected_workload": "exec_storm",
      "status": "error"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "otelcol-ebpf-profiler",
      "selected_workload": "exec_storm",
      "status": "error"
    },
    {
      "app": "cilium/agent",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "cilium",
      "selected_workload": "exec_storm",
      "status": "error"
    },
    {
      "app": "tetragon/observer",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "tetragon",
      "selected_workload": "tetragon_exec_connect_mix",
      "status": "error"
    },
    {
      "app": "katran",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "katran",
      "selected_workload": "test_run",
      "status": "error"
    },
    {
      "app": "tracee/monitor",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "tracee",
      "selected_workload": "tracee_system_edge_mix",
      "status": "error"
    },
    {
      "app": "bpftrace/capable",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bpftrace",
      "selected_workload": "exec_storm",
      "status": "error"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bpftrace",
      "selected_workload": "block_io",
      "status": "error"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bpftrace",
      "selected_workload": "vfs_create_write_fsync",
      "status": "error"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bpftrace",
      "selected_workload": "hackbench",
      "status": "error"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bpftrace",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline": null,
      "error": "cilium/agent: tracked BPF program ids disappeared before baseline: missing_ids=[166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 219, 220, 222, 224, 227, 228, 229, 232, 233], tracked_ids=[140, 141, 166, 167, 169, 171, 172, 173, 175, 176, 177, 178, 179, 180, 181, 182, 184, 185, 186, 187, 191, 192, 193, 194, 196, 197, 198, 199, 200, 202, 203, 204, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235]",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bpftrace",
      "selected_workload": "tcp_retransmit",
      "status": "error"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "workload_seconds": 1.0
}
```
