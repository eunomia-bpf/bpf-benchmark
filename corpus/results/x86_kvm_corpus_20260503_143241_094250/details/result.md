# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "fatal_error": "name 'daemon_session' is not defined",
  "generated_at": "2026-05-03T14:32:45.970445+00:00",
  "kop_modules": {
    "captured_at": "2026-05-03T14:32:41.125820+00:00",
    "daemon_binary": "daemon/target/release/bpfrejit-daemon",
    "expected_modules": [
      "bpf_bulk_memory",
      "bpf_endian",
      "bpf_extract",
      "bpf_prefetch",
      "bpf_rotate",
      "bpf_select"
    ],
    "module_load": {
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "failed_modules": [],
      "invoked_at": "2026-05-03T14:32:41.125760+00:00",
      "loaded_count": 6,
      "loaded_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "loader": "runner.libs.kop.load_kop_modules",
      "module_dir": "/artifacts/kop",
      "newly_loaded_modules": [],
      "snapshot_after": {
        "captured_at": "2026-05-03T14:32:41.125752+00:00",
        "expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_prefetch",
          "bpf_rotate",
          "bpf_select"
        ],
        "loaded_bpf_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_prefetch",
          "bpf_rotate",
          "bpf_select"
        ],
        "missing_expected_modules": [],
        "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_prefetch           12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
        "resident_expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_prefetch",
          "bpf_rotate",
          "bpf_select"
        ],
        "source": "lsmod"
      },
      "status": "ok",
      "total_count": 6
    },
    "module_snapshot_before_daemon": {
      "captured_at": "2026-05-03T14:32:41.110009+00:00",
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "loaded_bpf_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "missing_expected_modules": [],
      "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_prefetch           12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
      "resident_expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "source": "lsmod"
    }
  },
  "manifest": "/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml",
  "per_program": [],
  "results": [
    {
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 136.80128839370215,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 92984,
            "run_time_ns_delta": 12720331,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.6145335559999978,
            "ops_per_sec": 8461.70229311289,
            "ops_total": 5200.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [2894]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2894] eventfd            1000      0.01      0.01      0.00    144491.66      184979.65\nstress-ng: info:  [2894] skipped: 0\nstress-ng: info:  [2894] passed: 1: eventfd (1)\nstress-ng: info:  [2894] failed: 0\nstress-ng: info:  [2894] metrics untrustworthy: 0\nstress-ng: info:  [2894] successful run completed in 0.01 secs\nstress-ng: info:  [2897] setting to a 1 secs run per stressor\nstress-ng: info:  [2897] dispatching hogs: 1 get\nstress-ng: info:  [2897] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2897] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2897]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2897] get                 200      0.21      0.02      0.00       949.94        9639.48\nstress-ng: info:  [2897] skipped: 0\nstress-ng: info:  [2897] passed: 1: get (1)\nstress-ng: info:  [2897] failed: 0\nstress-ng: info:  [2897] metrics untrustworthy: 0\nstress-ng: info:  [2897] successful run completed in 0.21 secs\nstress-ng: info:  [2899] setting to a 1 secs run per stressor\nstress-ng: info:  [2899] dispatching hogs: 1 prctl\nstress-ng: info:  [2899] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2899] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2899]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2899] prctl              1000      0.32      0.22      0.09      3160.61        3175.28\nstress-ng: info:  [2899] skipped: 0\nstress-ng: info:  [2899] passed: 1: prctl (1)\nstress-ng: info:  [2899] failed: 0\nstress-ng: info:  [2899] metrics untrustworthy: 0\nstress-ng: info:  [2899] successful run completed in 0.32 secs\nstress-ng: info:  [3901] setting to a 1 secs run per stressor\nstress-ng: info:  [3901] dispatching hogs: 1 set\nstress-ng: info:  [3901] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [3901] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3901]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3901] set                1000      0.02      0.00      0.02     51864.77       49925.11\nstress-ng: info:  [3901] skipped: 0\nstress-ng: info:  [3901] passed: 1: set (1)\nstress-ng: info:  [3901] failed: 0\nstress-ng: info:  [3901] metrics untrustworthy: 0\nstress-ng: info:  [3901] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "stress_ng_os",
      "status": "error"
    },
    {
      "app": "bcc/execsnoop",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bcc",
      "selected_workload": "stress_ng_process",
      "status": "error"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bcc",
      "selected_workload": "stress_ng_network",
      "status": "error"
    },
    {
      "app": "bcc/biosnoop",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bcc",
      "selected_workload": "fio_randrw",
      "status": "error"
    },
    {
      "app": "bcc/vfsstat",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bcc",
      "selected_workload": "stress_ng_filesystem",
      "status": "error"
    },
    {
      "app": "bcc/opensnoop",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bcc",
      "selected_workload": "stress_ng_filesystem",
      "status": "error"
    },
    {
      "app": "bcc/syscount",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bcc",
      "selected_workload": "stress_ng_os",
      "status": "error"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bcc",
      "selected_workload": "stress_ng_network",
      "status": "error"
    },
    {
      "app": "bcc/tcplife",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bcc",
      "selected_workload": "stress_ng_network",
      "status": "error"
    },
    {
      "app": "bcc/runqlat",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bcc",
      "selected_workload": "stress_ng_scheduler",
      "status": "error"
    },
    {
      "app": "calico/felix",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "calico",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "otelcol-ebpf-profiler",
      "selected_workload": "stress_ng_cpu",
      "status": "error"
    },
    {
      "app": "cilium/agent",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "cilium",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "tetragon/observer",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "tetragon",
      "selected_workload": "stress_ng_os_io_network",
      "status": "error"
    },
    {
      "app": "katran",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "katran",
      "selected_workload": "test_run",
      "status": "error"
    },
    {
      "app": "tracee/monitor",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "tracee",
      "selected_workload": "stress_ng_os",
      "status": "error"
    },
    {
      "app": "bpftrace/capable",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "stress_ng_os",
      "status": "error"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "fio_randrw",
      "status": "error"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "stress_ng_filesystem",
      "status": "error"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "stress_ng_scheduler",
      "status": "error"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "stress_ng_network",
      "status": "error"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline": null,
      "error": "name 'daemon_session' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "stress_ng_network",
      "status": "error"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 0,
    "per_program_geomean": null,
    "program_count": 0,
    "wins": 0
  },
  "workload_seconds": 1.0
}
```
