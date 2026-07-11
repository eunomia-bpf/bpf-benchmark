# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-04T05:25:59.047551+00:00",
  "kop_modules": {
    "captured_at": "2026-05-04T05:24:43.065694+00:00",
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
      "invoked_at": "2026-05-04T05:24:43.065638+00:00",
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
        "captured_at": "2026-05-04T05:24:43.065631+00:00",
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
      "captured_at": "2026-05-04T05:24:43.049822+00:00",
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
  "per_program": [
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 387.2589398062011,
      "baseline_run_cnt_delta": 92983,
      "baseline_run_time_ns_delta": 36008498,
      "post_rejit_avg_ns_per_run": 224.14515940053045,
      "post_rejit_run_cnt_delta": 93883,
      "post_rejit_run_time_ns_delta": 21043420,
      "program": "cap_capable",
      "program_id": 9,
      "ratio": 0.5787991866958606,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 418.46129700970545,
      "baseline_run_cnt_delta": 1464538,
      "baseline_run_time_ns_delta": 612852471,
      "post_rejit_avg_ns_per_run": 397.3630812532302,
      "post_rejit_run_cnt_delta": 1431820,
      "post_rejit_run_time_ns_delta": 568952407,
      "program": "block_io_start",
      "program_id": 16,
      "ratio": 0.949581440608148,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 777.9962732656312,
      "baseline_run_cnt_delta": 1464553,
      "baseline_run_time_ns_delta": 1139416776,
      "post_rejit_avg_ns_per_run": 793.8605384000251,
      "post_rejit_run_cnt_delta": 1431835,
      "post_rejit_run_time_ns_delta": 1136677304,
      "program": "block_io_done",
      "program_id": 17,
      "ratio": 1.0203911839677635,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 3094.0,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 9282,
      "post_rejit_avg_ns_per_run": 5003.666666666667,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 15011,
      "program": "1",
      "program_id": 24,
      "ratio": 1.6172161172161172,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 37.13940995233623,
      "baseline_run_cnt_delta": 113923,
      "baseline_run_time_ns_delta": 4231033,
      "post_rejit_avg_ns_per_run": 35.77965058308406,
      "post_rejit_run_cnt_delta": 115335,
      "post_rejit_run_time_ns_delta": 4126646,
      "program": "vfs_create",
      "program_id": 25,
      "ratio": 0.9633876959543178,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 261.38871115173674,
      "baseline_run_cnt_delta": 4376,
      "baseline_run_time_ns_delta": 1143837,
      "post_rejit_avg_ns_per_run": 243.62474767864353,
      "post_rejit_run_cnt_delta": 4954,
      "post_rejit_run_time_ns_delta": 1206917,
      "program": "sched_wakeup",
      "program_id": 32,
      "ratio": 0.9320400510227804,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 277.9697508896797,
      "baseline_run_cnt_delta": 562,
      "baseline_run_time_ns_delta": 156219,
      "post_rejit_avg_ns_per_run": 276.708041958042,
      "post_rejit_run_cnt_delta": 572,
      "post_rejit_run_time_ns_delta": 158277,
      "program": "tracepoint_sched_sched_wakeup_new",
      "program_id": 33,
      "ratio": 0.9954609847740646,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 288.9494089233507,
      "baseline_run_cnt_delta": 7867,
      "baseline_run_time_ns_delta": 2273165,
      "post_rejit_avg_ns_per_run": 260.5599339570721,
      "post_rejit_run_cnt_delta": 9085,
      "post_rejit_run_time_ns_delta": 2367187,
      "program": "sched_switch",
      "program_id": 34,
      "ratio": 0.9017493232740633,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 1737.5555555555557,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 15638,
      "post_rejit_avg_ns_per_run": 1320.75,
      "post_rejit_run_cnt_delta": 8,
      "post_rejit_run_time_ns_delta": 10566,
      "program": "tcp_set_state",
      "program_id": 42,
      "ratio": 0.7601195805090164,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_network"
    }
  ],
  "results": [
    {
      "app": "bpftrace/capable",
      "baseline": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 387.2589398062011,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 9,
            "name": "cap_capable",
            "run_cnt_delta": 92983,
            "run_time_ns_delta": 36008498,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.721208431000008,
            "ops_per_sec": 7210.12092549975,
            "ops_total": 5200.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [2899]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2899] eventfd            1000      0.01      0.00      0.00    124626.47      162311.31\nstress-ng: info:  [2899] skipped: 0\nstress-ng: info:  [2899] passed: 1: eventfd (1)\nstress-ng: info:  [2899] failed: 0\nstress-ng: info:  [2899] metrics untrustworthy: 0\nstress-ng: info:  [2899] successful run completed in 0.01 secs\nstress-ng: info:  [2902] setting to a 1 secs run per stressor\nstress-ng: info:  [2902] dispatching hogs: 1 get\nstress-ng: info:  [2902] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2902] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2902]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2902] get                 200      0.30      0.02      0.00       660.16        8666.26\nstress-ng: info:  [2902] skipped: 0\nstress-ng: info:  [2902] passed: 1: get (1)\nstress-ng: info:  [2902] failed: 0\nstress-ng: info:  [2902] metrics untrustworthy: 0\nstress-ng: info:  [2902] successful run completed in 0.30 secs\nstress-ng: info:  [2904] setting to a 1 secs run per stressor\nstress-ng: info:  [2904] dispatching hogs: 1 prctl\nstress-ng: info:  [2904] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2904] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2904]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2904] prctl              1000      0.33      0.19      0.13      3070.22        3084.37\nstress-ng: info:  [2904] skipped: 0\nstress-ng: info:  [2904] passed: 1: prctl (1)\nstress-ng: info:  [2904] failed: 0\nstress-ng: info:  [2904] metrics untrustworthy: 0\nstress-ng: info:  [2904] successful run completed in 0.33 secs\nstress-ng: info:  [3906] setting to a 1 secs run per stressor\nstress-ng: info:  [3906] dispatching hogs: 1 set\nstress-ng: info:  [3906] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [3906] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3906]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3906] set                1000      0.02      0.02      0.00     52977.78       52490.68\nstress-ng: info:  [3906] skipped: 0\nstress-ng: info:  [3906] passed: 1: set (1)\nstress-ng: info:  [3906] failed: 0\nstress-ng: info:  [3906] metrics untrustworthy: 0\nstress-ng: info:  [3906] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 224.14515940053045,
            "bytes_jited": 772,
            "bytes_xlated": 1376,
            "id": 9,
            "name": "cap_capable",
            "run_cnt_delta": 93883,
            "run_time_ns_delta": 21043420,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.6746217659999729,
            "ops_per_sec": 7708.0228686250375,
            "ops_total": 5200.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [4946]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4946] eventfd            1000      0.01      0.00      0.00    123762.29      158982.51\nstress-ng: info:  [4946] skipped: 0\nstress-ng: info:  [4946] passed: 1: eventfd (1)\nstress-ng: info:  [4946] failed: 0\nstress-ng: info:  [4946] metrics untrustworthy: 0\nstress-ng: info:  [4946] successful run completed in 0.01 secs\nstress-ng: info:  [4949] setting to a 1 secs run per stressor\nstress-ng: info:  [4949] dispatching hogs: 1 get\nstress-ng: info:  [4949] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4949] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4949]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4949] get                 200      0.29      0.01      0.01       686.89        9581.30\nstress-ng: info:  [4949] skipped: 0\nstress-ng: info:  [4949] passed: 1: get (1)\nstress-ng: info:  [4949] failed: 0\nstress-ng: info:  [4949] metrics untrustworthy: 0\nstress-ng: info:  [4949] successful run completed in 0.29 secs\nstress-ng: info:  [4951] setting to a 1 secs run per stressor\nstress-ng: info:  [4951] dispatching hogs: 1 prctl\nstress-ng: info:  [4951] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4951] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4951]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4951] prctl              1000      0.29      0.20      0.09      3420.09        3431.73\nstress-ng: info:  [4951] skipped: 0\nstress-ng: info:  [4951] passed: 1: prctl (1)\nstress-ng: info:  [4951] failed: 0\nstress-ng: info:  [4951] metrics untrustworthy: 0\nstress-ng: info:  [4951] successful run completed in 0.29 secs\nstress-ng: info:  [5953] setting to a 1 secs run per stressor\nstress-ng: info:  [5953] dispatching hogs: 1 set\nstress-ng: info:  [5953] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5953] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5953]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5953] set                1000      0.02      0.02      0.00     53307.03       52540.32\nstress-ng: info:  [5953] skipped: 0\nstress-ng: info:  [5953] passed: 1: set (1)\nstress-ng: info:  [5953] failed: 0\nstress-ng: info:  [5953] metrics untrustworthy: 0\nstress-ng: info:  [5953] successful run completed in 0.02 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "stress_ng_os",
      "status": "ok"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline": {
        "bpf": {
          "16": {
            "avg_ns_per_run": 418.46129700970545,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 16,
            "name": "block_io_start",
            "run_cnt_delta": 1464538,
            "run_time_ns_delta": 612852471,
            "type": "tracepoint"
          },
          "17": {
            "avg_ns_per_run": 777.9962732656312,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 17,
            "name": "block_io_done",
            "run_cnt_delta": 1464553,
            "run_time_ns_delta": 1139416776,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.3575657260000185,
            "ops_per_sec": 366170.02951164416,
            "ops_total": 1961780.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.231390,\n        \"1000\" : 17.974077\n      },\n      \"latency_us\" : {\n        \"2\" : 29.571898,\n        \"4\" : 1.567784,\n        \"10\" : 11.057227,\n        \"20\" : 34.910904,\n        \"50\" : 2.767233,\n        \"100\" : 1.586057,\n        \"250\" : 0.310231,\n        \"500\" : 0.022995,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "16": {
            "avg_ns_per_run": 397.3630812532302,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 16,
            "name": "block_io_start",
            "run_cnt_delta": 1431820,
            "run_time_ns_delta": 568952407,
            "type": "tracepoint"
          },
          "17": {
            "avg_ns_per_run": 793.8605384000251,
            "bytes_jited": 943,
            "bytes_xlated": 1640,
            "id": 17,
            "name": "block_io_done",
            "run_cnt_delta": 1431835,
            "run_time_ns_delta": 1136677304,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.355707631000001,
            "ops_per_sec": 357125.7304878074,
            "ops_total": 1912661.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.169130,\n        \"1000\" : 17.019896\n      },\n      \"latency_us\" : {\n        \"2\" : 30.713641,\n        \"4\" : 1.563781,\n        \"10\" : 10.463799,\n        \"20\" : 34.957130,\n        \"50\" : 2.895807,\n        \"100\" : 1.833441,\n        \"250\" : 0.359684,\n        \"500\" : 0.022661,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.010000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bpftrace",
      "selected_workload": "fio_randrw",
      "status": "ok"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline": {
        "bpf": {
          "24": {
            "avg_ns_per_run": 3094.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 24,
            "name": "1",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 9282,
            "type": "perf_event"
          },
          "25": {
            "avg_ns_per_run": 37.13940995233623,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 25,
            "name": "vfs_create",
            "run_cnt_delta": 113923,
            "run_time_ns_delta": 4231033,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.2332170690000055,
            "ops_per_sec": 2594.938669736432,
            "ops_total": 8390.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7757]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7757] open                100      0.01      0.00      0.00     15658.57       24795.44\nstress-ng: info:  [7757] skipped: 0\nstress-ng: info:  [7757] passed: 1: open (1)\nstress-ng: info:  [7757] failed: 0\nstress-ng: info:  [7757] metrics untrustworthy: 0\nstress-ng: info:  [7757] successful run completed in 0.01 secs\nstress-ng: info:  [7759] setting to a 1 secs run per stressor\nstress-ng: info:  [7759] dispatching hogs: 1 rename\nstress-ng: info:  [7759] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7759] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7759]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7759] rename              100      0.00      0.00      0.00     21937.88       34518.47\nstress-ng: info:  [7759] skipped: 0\nstress-ng: info:  [7759] passed: 1: rename (1)\nstress-ng: info:  [7759] failed: 0\nstress-ng: info:  [7759] metrics untrustworthy: 0\nstress-ng: info:  [7759] successful run completed in 0.01 secs\nstress-ng: info:  [7761] setting to a 1 secs run per stressor\nstress-ng: info:  [7761] dispatching hogs: 1 touch\nstress-ng: info:  [7761] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7761] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7761]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7761] touch               200      0.00      0.02      0.00     50907.93       11928.19\nstress-ng: info:  [7761] skipped: 0\nstress-ng: info:  [7761] passed: 1: touch (1)\nstress-ng: info:  [7761] failed: 0\nstress-ng: info:  [7761] metrics untrustworthy: 0\nstress-ng: info:  [7761] successful run completed in 0.01 secs\nstress-ng: info:  [7767] setting to a 1 secs run per stressor\nstress-ng: info:  [7767] dispatching hogs: 1 utime\nstress-ng: info:  [7767] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7767] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7767]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7767] utime               200      0.00      0.00      0.00     62243.88       51719.68\nstress-ng: info:  [7767] skipped: 0\nstress-ng: info:  [7767] passed: 1: utime (1)\nstress-ng: info:  [7767] failed: 0\nstress-ng: info:  [7767] metrics untrustworthy: 0\nstress-ng: info:  [7767] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "24": {
            "avg_ns_per_run": 5003.666666666667,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 24,
            "name": "1",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 15011,
            "type": "perf_event"
          },
          "25": {
            "avg_ns_per_run": 35.77965058308406,
            "bytes_jited": 143,
            "bytes_xlated": 240,
            "id": 25,
            "name": "vfs_create",
            "run_cnt_delta": 115335,
            "run_time_ns_delta": 4126646,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.164074129999989,
            "ops_per_sec": 2652.2766709008897,
            "ops_total": 8392.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [9498]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9498] open                100      0.01      0.00      0.01     14199.69       17295.05\nstress-ng: info:  [9498] skipped: 0\nstress-ng: info:  [9498] passed: 1: open (1)\nstress-ng: info:  [9498] failed: 0\nstress-ng: info:  [9498] metrics untrustworthy: 0\nstress-ng: info:  [9498] successful run completed in 0.01 secs\nstress-ng: info:  [9500] setting to a 1 secs run per stressor\nstress-ng: info:  [9500] dispatching hogs: 1 rename\nstress-ng: info:  [9500] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9500] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9500]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9500] rename              100      0.00      0.00      0.00     27422.71       63938.62\nstress-ng: info:  [9500] skipped: 0\nstress-ng: info:  [9500] passed: 1: rename (1)\nstress-ng: info:  [9500] failed: 0\nstress-ng: info:  [9500] metrics untrustworthy: 0\nstress-ng: info:  [9500] successful run completed in 0.01 secs\nstress-ng: info:  [9502] setting to a 1 secs run per stressor\nstress-ng: info:  [9502] dispatching hogs: 1 touch\nstress-ng: info:  [9502] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9502] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9502]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9502] touch               200      0.00      0.02      0.00     56485.14       13134.56\nstress-ng: info:  [9502] skipped: 0\nstress-ng: info:  [9502] passed: 1: touch (1)\nstress-ng: info:  [9502] failed: 0\nstress-ng: info:  [9502] metrics untrustworthy: 0\nstress-ng: info:  [9502] successful run completed in 0.01 secs\nstress-ng: info:  [9508] setting to a 1 secs run per stressor\nstress-ng: info:  [9508] dispatching hogs: 1 utime\nstress-ng: info:  [9508] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9508] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9508]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9508] utime               200      0.00      0.00      0.00     87435.98       77790.74\nstress-ng: info:  [9508] skipped: 0\nstress-ng: info:  [9508] passed: 1: utime (1)\nstress-ng: info:  [9508] failed: 0\nstress-ng: info:  [9508] metrics untrustworthy: 0\nstress-ng: info:  [9508] successful run completed in 0.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bpftrace",
      "selected_workload": "stress_ng_filesystem",
      "status": "ok"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline": {
        "bpf": {
          "32": {
            "avg_ns_per_run": 261.38871115173674,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 32,
            "name": "sched_wakeup",
            "run_cnt_delta": 4376,
            "run_time_ns_delta": 1143837,
            "type": "tracepoint"
          },
          "33": {
            "avg_ns_per_run": 277.9697508896797,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 33,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 562,
            "run_time_ns_delta": 156219,
            "type": "tracepoint"
          },
          "34": {
            "avg_ns_per_run": 288.9494089233507,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 34,
            "name": "sched_switch",
            "run_cnt_delta": 7867,
            "run_time_ns_delta": 2273165,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.3275952669999924,
            "ops_per_sec": 4937.7141133360265,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [10417]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10417] sem-sysv           1001      0.00      0.00      0.00    406516.10      291836.73\nstress-ng: info:  [10417] skipped: 0\nstress-ng: info:  [10417] passed: 1: sem-sysv (1)\nstress-ng: info:  [10417] failed: 0\nstress-ng: info:  [10417] metrics untrustworthy: 0\nstress-ng: info:  [10417] successful run completed in 0.00 secs\nstress-ng: info:  [10421] setting to a 1 secs run per stressor\nstress-ng: info:  [10421] dispatching hogs: 1 switch\nstress-ng: info:  [10421] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10421] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10421]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10421] switch             1000      0.01      0.01      0.00    103435.36      116157.51\nstress-ng: info:  [10421] skipped: 0\nstress-ng: info:  [10421] passed: 1: switch (1)\nstress-ng: info:  [10421] failed: 0\nstress-ng: info:  [10421] metrics untrustworthy: 0\nstress-ng: info:  [10421] successful run completed in 0.01 secs\nstress-ng: info:  [10424] setting to a 1 secs run per stressor\nstress-ng: info:  [10424] dispatching hogs: 1 vfork\nstress-ng: info:  [10424] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10424] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10424]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10424] vfork               200      0.01      0.01      0.00     24707.26       24360.54\nstress-ng: info:  [10424] skipped: 0\nstress-ng: info:  [10424] passed: 1: vfork (1)\nstress-ng: info:  [10424] failed: 0\nstress-ng: info:  [10424] metrics untrustworthy: 0\nstress-ng: info:  [10424] successful run completed in 0.01 secs\nstress-ng: info:  [10626] setting to a 1 secs run per stressor\nstress-ng: info:  [10626] dispatching hogs: 1 yield\nstress-ng: info:  [10626] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10626] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10626]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10626] yield              4992      1.00      0.01      0.00      4989.58      432544.84\nstress-ng: info:  [10626] skipped: 0\nstress-ng: info:  [10626] passed: 1: yield (1)\nstress-ng: info:  [10626] failed: 0\nstress-ng: info:  [10626] metrics untrustworthy: 0\nstress-ng: info:  [10626] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "32": {
            "avg_ns_per_run": 243.62474767864353,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 32,
            "name": "sched_wakeup",
            "run_cnt_delta": 4954,
            "run_time_ns_delta": 1206917,
            "type": "tracepoint"
          },
          "33": {
            "avg_ns_per_run": 276.708041958042,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 33,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 572,
            "run_time_ns_delta": 158277,
            "type": "tracepoint"
          },
          "34": {
            "avg_ns_per_run": 260.5599339570721,
            "bytes_jited": 518,
            "bytes_xlated": 912,
            "id": 34,
            "name": "sched_switch",
            "run_cnt_delta": 9085,
            "run_time_ns_delta": 2367187,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.302339589000013,
            "ops_per_sec": 4991.878719764278,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [11585]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11585] sem-sysv           1001      0.01      0.01      0.00    146754.46      172586.21\nstress-ng: info:  [11585] skipped: 0\nstress-ng: info:  [11585] passed: 1: sem-sysv (1)\nstress-ng: info:  [11585] failed: 0\nstress-ng: info:  [11585] metrics untrustworthy: 0\nstress-ng: info:  [11585] successful run completed in 0.01 secs\nstress-ng: info:  [11589] setting to a 1 secs run per stressor\nstress-ng: info:  [11589] dispatching hogs: 1 switch\nstress-ng: info:  [11589] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11589] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11589]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11589] switch             1000      0.01      0.01      0.00    110350.29      137551.58\nstress-ng: info:  [11589] skipped: 0\nstress-ng: info:  [11589] passed: 1: switch (1)\nstress-ng: info:  [11589] failed: 0\nstress-ng: info:  [11589] metrics untrustworthy: 0\nstress-ng: info:  [11589] successful run completed in 0.01 secs\nstress-ng: info:  [11592] setting to a 1 secs run per stressor\nstress-ng: info:  [11592] dispatching hogs: 1 vfork\nstress-ng: info:  [11592] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11592] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11592]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11592] vfork               200      0.01      0.00      0.00     27793.41       26641.80\nstress-ng: info:  [11592] skipped: 0\nstress-ng: info:  [11592] passed: 1: vfork (1)\nstress-ng: info:  [11592] failed: 0\nstress-ng: info:  [11592] metrics untrustworthy: 0\nstress-ng: info:  [11592] successful run completed in 0.01 secs\nstress-ng: info:  [11794] setting to a 1 secs run per stressor\nstress-ng: info:  [11794] dispatching hogs: 1 yield\nstress-ng: info:  [11794] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11794] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11794]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11794] yield              4992      1.00      0.01      0.00      4986.34      470810.15\nstress-ng: info:  [11794] skipped: 0\nstress-ng: info:  [11794] passed: 1: yield (1)\nstress-ng: info:  [11794] failed: 0\nstress-ng: info:  [11794] metrics untrustworthy: 0\nstress-ng: info:  [11794] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bpftrace",
      "selected_workload": "stress_ng_scheduler",
      "status": "ok"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline": {
        "bpf": {
          "42": {
            "avg_ns_per_run": 1737.5555555555557,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 42,
            "name": "tcp_set_state",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 15638,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.3197019659999967,
            "ops_per_sec": 16030.555157737295,
            "ops_total": 5125.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [11900]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11900] sockdiag           1025      0.00      0.00      0.00   2469363.35     1472701.15\nstress-ng: info:  [11900] skipped: 0\nstress-ng: info:  [11900] passed: 1: sockdiag (1)\nstress-ng: info:  [11900] failed: 0\nstress-ng: info:  [11900] metrics untrustworthy: 0\nstress-ng: info:  [11900] successful run completed in 0.00 secs\nstress-ng: info:  [11902] setting to a 1 secs run per stressor\nstress-ng: info:  [11902] dispatching hogs: 1 sockfd\nstress-ng: info:  [11902] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11902] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11902]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11902] sockfd              200      0.00      0.00      0.00    188762.56      136612.02\nstress-ng: info:  [11902] skipped: 0\nstress-ng: info:  [11902] passed: 1: sockfd (1)\nstress-ng: info:  [11902] failed: 0\nstress-ng: info:  [11902] metrics untrustworthy: 0\nstress-ng: info:  [11902] successful run completed in 0.00 secs\nstress-ng: info:  [11905] setting to a 1 secs run per stressor\nstress-ng: info:  [11905] dispatching hogs: 1 sockpair\nstress-ng: info:  [11905] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11905] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11905]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11905] sockpair            500      0.01      0.00      0.01     49727.36       40290.09\nstress-ng: info:  [11905] skipped: 0\nstress-ng: info:  [11905] passed: 1: sockpair (1)\nstress-ng: info:  [11905] failed: 0\nstress-ng: info:  [11905] metrics untrustworthy: 0\nstress-ng: info:  [11905] successful run completed in 0.01 secs\nstress-ng: info:  [11909] setting to a 1 secs run per stressor\nstress-ng: info:  [11909] dispatching hogs: 1 udp-flood\nstress-ng: info:  [11909] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11909] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11909]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11909] udp-flood          1000      0.00      0.00      0.00    595190.01      523834.47\nstress-ng: info:  [11909] skipped: 0\nstress-ng: info:  [11909] passed: 1: udp-flood (1)\nstress-ng: info:  [11909] failed: 0\nstress-ng: info:  [11909] metrics untrustworthy: 0\nstress-ng: info:  [11909] successful run completed in 0.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "42": {
            "avg_ns_per_run": 1320.75,
            "bytes_jited": 2023,
            "bytes_xlated": 3416,
            "id": 42,
            "name": "tcp_set_state",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 10566,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.5983021700000108,
            "ops_per_sec": 8624.404621497371,
            "ops_total": 5160.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [11969]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11969] sockdiag           1025      0.00      0.00      0.00   2079904.02     1091586.79\nstress-ng: info:  [11969] skipped: 0\nstress-ng: info:  [11969] passed: 1: sockdiag (1)\nstress-ng: info:  [11969] failed: 0\nstress-ng: info:  [11969] metrics untrustworthy: 0\nstress-ng: info:  [11969] successful run completed in 0.00 secs\nstress-ng: info:  [11971] setting to a 1 secs run per stressor\nstress-ng: info:  [11971] dispatching hogs: 1 sockfd\nstress-ng: info:  [11971] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11971] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11971]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11971] sockfd              200      0.00      0.00      0.00    195220.11      101163.38\nstress-ng: info:  [11971] skipped: 0\nstress-ng: info:  [11971] passed: 1: sockfd (1)\nstress-ng: info:  [11971] failed: 0\nstress-ng: info:  [11971] metrics untrustworthy: 0\nstress-ng: info:  [11971] successful run completed in 0.00 secs\nstress-ng: info:  [11974] setting to a 1 secs run per stressor\nstress-ng: info:  [11974] dispatching hogs: 1 sockpair\nstress-ng: info:  [11974] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11974] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11974]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11974] sockpair            500      0.01      0.00      0.01     41428.50       33909.80\nstress-ng: info:  [11974] skipped: 0\nstress-ng: info:  [11974] passed: 1: sockpair (1)\nstress-ng: info:  [11974] failed: 0\nstress-ng: info:  [11974] metrics untrustworthy: 0\nstress-ng: info:  [11974] successful run completed in 0.01 secs\nstress-ng: info:  [11978] setting to a 1 secs run per stressor\nstress-ng: info:  [11978] dispatching hogs: 1 udp-flood\nstress-ng: info:  [11978] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11978] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11978]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11978] udp-flood          1000      0.00      0.00      0.00    578205.68      506585.61\nstress-ng: info:  [11978] skipped: 0\nstress-ng: info:  [11978] passed: 1: udp-flood (1)\nstress-ng: info:  [11978] failed: 0\nstress-ng: info:  [11978] metrics untrustworthy: 0\nstress-ng: info:  [11978] successful run completed in 0.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "stress_ng_network",
      "status": "ok"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline": {
        "bpf": {
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 49,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.9253965890000018,
            "ops_per_sec": 5874.2382072903765,
            "ops_total": 5436.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [12040]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12040] sockdiag           1025      0.00      0.00      0.00   3646447.50     1836917.56\nstress-ng: info:  [12040] skipped: 0\nstress-ng: info:  [12040] passed: 1: sockdiag (1)\nstress-ng: info:  [12040] failed: 0\nstress-ng: info:  [12040] metrics untrustworthy: 0\nstress-ng: info:  [12040] successful run completed in 0.00 secs\nstress-ng: info:  [12042] setting to a 5 secs run per stressor\nstress-ng: info:  [12042] dispatching hogs: 1 sockfd\nstress-ng: info:  [12042] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12042] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12042]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12042] sockfd              200      0.00      0.00      0.00    243996.74      164880.46\nstress-ng: info:  [12042] skipped: 0\nstress-ng: info:  [12042] passed: 1: sockfd (1)\nstress-ng: info:  [12042] failed: 0\nstress-ng: info:  [12042] metrics untrustworthy: 0\nstress-ng: info:  [12042] successful run completed in 0.00 secs\nstress-ng: info:  [12045] setting to a 5 secs run per stressor\nstress-ng: info:  [12045] dispatching hogs: 1 sockpair\nstress-ng: info:  [12045] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12045] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12045]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12045] sockpair            500      0.01      0.01      0.00     47119.60       38708.68\nstress-ng: info:  [12045] skipped: 0\nstress-ng: info:  [12045] passed: 1: sockpair (1)\nstress-ng: info:  [12045] failed: 0\nstress-ng: info:  [12045] metrics untrustworthy: 0\nstress-ng: info:  [12045] successful run completed in 0.01 secs\nstress-ng: info:  [12049] setting to a 5 secs run per stressor\nstress-ng: info:  [12049] dispatching hogs: 1 udp-flood\nstress-ng: info:  [12049] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12049] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12049]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12049] udp-flood          1000      0.00      0.00      0.00    977921.19      772797.53\nstress-ng: info:  [12049] skipped: 0\nstress-ng: info:  [12049] passed: 1: udp-flood (1)\nstress-ng: info:  [12049] failed: 0\nstress-ng: info:  [12049] metrics untrustworthy: 0\nstress-ng: info:  [12049] successful run completed in 0.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 971,
            "bytes_xlated": 1656,
            "id": 49,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.826250627999997,
            "ops_per_sec": 1923.396299728308,
            "ops_total": 5436.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [12109]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12109] sockdiag           1025      0.00      0.00      0.00    784375.41      568496.95\nstress-ng: info:  [12109] skipped: 0\nstress-ng: info:  [12109] passed: 1: sockdiag (1)\nstress-ng: info:  [12109] failed: 0\nstress-ng: info:  [12109] metrics untrustworthy: 0\nstress-ng: info:  [12109] successful run completed in 0.00 secs\nstress-ng: info:  [12111] setting to a 5 secs run per stressor\nstress-ng: info:  [12111] dispatching hogs: 1 sockfd\nstress-ng: info:  [12111] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12111] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12111]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12111] sockfd              200      0.00      0.00      0.00    114348.53       89445.44\nstress-ng: info:  [12111] skipped: 0\nstress-ng: info:  [12111] passed: 1: sockfd (1)\nstress-ng: info:  [12111] failed: 0\nstress-ng: info:  [12111] metrics untrustworthy: 0\nstress-ng: info:  [12111] successful run completed in 0.00 secs\nstress-ng: info:  [12114] setting to a 5 secs run per stressor\nstress-ng: info:  [12114] dispatching hogs: 1 sockpair\nstress-ng: info:  [12114] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12114] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12114]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12114] sockpair            500      0.01      0.00      0.01     41090.82       32419.11\nstress-ng: info:  [12114] skipped: 0\nstress-ng: info:  [12114] passed: 1: sockpair (1)\nstress-ng: info:  [12114] failed: 0\nstress-ng: info:  [12114] metrics untrustworthy: 0\nstress-ng: info:  [12114] successful run completed in 0.01 secs\nstress-ng: info:  [12118] setting to a 5 secs run per stressor\nstress-ng: info:  [12118] dispatching hogs: 1 udp-flood\nstress-ng: info:  [12118] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12118] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12118]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12118] udp-flood          1000      0.00      0.00      0.00    694651.21      537634.41\nstress-ng: info:  [12118] skipped: 0\nstress-ng: info:  [12118] passed: 1: udp-flood (1)\nstress-ng: info:  [12118] failed: 0\nstress-ng: info:  [12118] metrics untrustworthy: 0\nstress-ng: info:  [12118] successful run completed in 0.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "bulk_memory",
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "stress_ng_network",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 2,
    "per_program_geomean": 0.9368001459076336,
    "program_count": 9,
    "wins": 7
  },
  "workload_seconds": 1.0
}
```
