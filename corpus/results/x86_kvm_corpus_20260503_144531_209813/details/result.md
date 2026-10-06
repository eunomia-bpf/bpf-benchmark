# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-03T14:47:28.022228+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-03T14:45:31.246476+00:00",
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
      "invoked_at": "2026-05-03T14:45:31.246418+00:00",
      "loaded_count": 6,
      "loaded_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "loader": "runner.libs.kinsn.load_kinsn_modules",
      "module_dir": "/artifacts/kinsn",
      "newly_loaded_modules": [],
      "snapshot_after": {
        "captured_at": "2026-05-03T14:45:31.246410+00:00",
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
      "captured_at": "2026-05-03T14:45:31.229141+00:00",
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
      "app": "bcc/capable",
      "baseline_avg_ns_per_run": 143.98653531790416,
      "baseline_run_cnt_delta": 92984,
      "baseline_run_time_ns_delta": 13388444,
      "post_rejit_avg_ns_per_run": 142.86069646390777,
      "post_rejit_run_cnt_delta": 92984,
      "post_rejit_run_time_ns_delta": 13283759,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 0.9921809435062058,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 1282.3333333333333,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 11541,
      "post_rejit_avg_ns_per_run": 1653.3333333333333,
      "post_rejit_run_cnt_delta": 9,
      "post_rejit_run_time_ns_delta": 14880,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 1.2893163504029115,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 320.55555555555554,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 2885,
      "post_rejit_avg_ns_per_run": 445.22222222222223,
      "post_rejit_run_cnt_delta": 9,
      "post_rejit_run_time_ns_delta": 4007,
      "program": "do_ret_sys_execve",
      "program_id": 10,
      "ratio": 1.3889081455805894,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 2503.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 5006,
      "post_rejit_avg_ns_per_run": 2820.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 5640,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 1.1266480223731523,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 6247.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 12495,
      "post_rejit_avg_ns_per_run": 7540.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 15081,
      "program": "bindsnoop_v4_return",
      "program_id": 14,
      "ratio": 1.2069627851140456,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 231.70638292849893,
      "baseline_run_cnt_delta": 1609794,
      "baseline_run_time_ns_delta": 372999545,
      "post_rejit_avg_ns_per_run": 226.93939241792384,
      "post_rejit_run_cnt_delta": 1692940,
      "post_rejit_run_time_ns_delta": 384194775,
      "program": "trace_pid_start_tp",
      "program_id": 18,
      "ratio": 0.9794265895901275,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 200.10387289384298,
      "baseline_run_cnt_delta": 1609804,
      "baseline_run_time_ns_delta": 322128015,
      "post_rejit_avg_ns_per_run": 197.03966921645647,
      "post_rejit_run_cnt_delta": 1692950,
      "post_rejit_run_time_ns_delta": 333578308,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 0.984686934675112,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 96.19301668707281,
      "baseline_run_cnt_delta": 1609809,
      "baseline_run_time_ns_delta": 154852384,
      "post_rejit_avg_ns_per_run": 93.95494800511531,
      "post_rejit_run_cnt_delta": 1692955,
      "post_rejit_run_time_ns_delta": 159061499,
      "program": "trace_req_completion_tp",
      "program_id": 20,
      "ratio": 0.9767335638382337,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 34.983535706935584,
      "baseline_run_cnt_delta": 4859,
      "baseline_run_time_ns_delta": 169985,
      "post_rejit_avg_ns_per_run": 33.31397982293597,
      "post_rejit_run_cnt_delta": 4857,
      "post_rejit_run_time_ns_delta": 161806,
      "program": "vfs_create",
      "program_id": 23,
      "ratio": 0.9522759535232278,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 28.391167192429023,
      "baseline_run_cnt_delta": 317,
      "baseline_run_time_ns_delta": 9000,
      "post_rejit_avg_ns_per_run": 30.2397476340694,
      "post_rejit_run_cnt_delta": 317,
      "post_rejit_run_time_ns_delta": 9586,
      "program": "kfunc__vmlinux__vfs_fsync_range",
      "program_id": 24,
      "ratio": 1.0651111111111111,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 25.33942280825472,
      "baseline_run_cnt_delta": 75157,
      "baseline_run_time_ns_delta": 1904435,
      "post_rejit_avg_ns_per_run": 25.46422992362879,
      "post_rejit_run_cnt_delta": 69136,
      "post_rejit_run_time_ns_delta": 1760495,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 1.0049254127182965,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 23.22852182042806,
      "baseline_run_cnt_delta": 29949,
      "baseline_run_time_ns_delta": 695671,
      "post_rejit_avg_ns_per_run": 23.37051752921536,
      "post_rejit_run_cnt_delta": 29950,
      "post_rejit_run_time_ns_delta": 699947,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.0061129894482748,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 23.807863031071655,
      "baseline_run_cnt_delta": 4731,
      "baseline_run_time_ns_delta": 112635,
      "post_rejit_avg_ns_per_run": 23.752475247524753,
      "post_rejit_run_cnt_delta": 4747,
      "post_rejit_run_time_ns_delta": 112753,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 0.9976735508149297,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 845.4601769911504,
      "baseline_run_cnt_delta": 113,
      "baseline_run_time_ns_delta": 95537,
      "post_rejit_avg_ns_per_run": 531.5591397849462,
      "post_rejit_run_cnt_delta": 93,
      "post_rejit_run_time_ns_delta": 49435,
      "program": "__x64_sys_open",
      "program_id": 30,
      "ratio": 0.6287216763735403,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 756.7857342657343,
      "baseline_run_cnt_delta": 53625,
      "baseline_run_time_ns_delta": 40582635,
      "post_rejit_avg_ns_per_run": 739.3185546975768,
      "post_rejit_run_cnt_delta": 58147,
      "post_rejit_run_time_ns_delta": 42989156,
      "program": "kretfunc__vmlinux____x64_sys_openat",
      "program_id": 31,
      "ratio": 0.9769192536575695,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 1003.8333333333334,
      "baseline_run_cnt_delta": 6,
      "baseline_run_time_ns_delta": 6023,
      "post_rejit_avg_ns_per_run": 586.5,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 2346,
      "program": "kretfunc__vmlinux____x64_sys_openat2",
      "program_id": 32,
      "ratio": 0.5842603353810393,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 68.46213580081356,
      "baseline_run_cnt_delta": 559275,
      "baseline_run_time_ns_delta": 38289161,
      "post_rejit_avg_ns_per_run": 78.89243160403929,
      "post_rejit_run_cnt_delta": 559207,
      "post_rejit_run_time_ns_delta": 44117200,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 35,
      "ratio": 1.1523513060353836,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 60.362988935695434,
      "baseline_run_cnt_delta": 559276,
      "baseline_run_time_ns_delta": 33759571,
      "post_rejit_avg_ns_per_run": 62.561560278107606,
      "post_rejit_run_cnt_delta": 559208,
      "post_rejit_run_time_ns_delta": 34984925,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 36,
      "ratio": 1.0364225062604886,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 3241.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 3241,
      "post_rejit_avg_ns_per_run": 1985.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1985,
      "program": "trace_connect_entry",
      "program_id": 39,
      "ratio": 0.6124652884912064,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 11080.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 11080,
      "post_rejit_avg_ns_per_run": 5735.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 5735,
      "program": "trace_connect_v4_return",
      "program_id": 40,
      "ratio": 0.5175992779783394,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 1069.6315789473683,
      "baseline_run_cnt_delta": 19,
      "baseline_run_time_ns_delta": 20323,
      "post_rejit_avg_ns_per_run": 21.723076923076924,
      "post_rejit_run_cnt_delta": 3510,
      "post_rejit_run_time_ns_delta": 76248,
      "program": "tracepoint__sock__inet_sock_set_state",
      "program_id": 44,
      "ratio": 0.02030893379611581,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 220.17565306910308,
      "baseline_run_cnt_delta": 7771,
      "baseline_run_time_ns_delta": 1710985,
      "post_rejit_avg_ns_per_run": 199.65827338129498,
      "post_rejit_run_cnt_delta": 6950,
      "post_rejit_run_time_ns_delta": 1387625,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 0.9068135854177817,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 297.22504664179104,
      "baseline_run_cnt_delta": 4288,
      "baseline_run_time_ns_delta": 1274501,
      "post_rejit_avg_ns_per_run": 292.2557251908397,
      "post_rejit_run_cnt_delta": 3930,
      "post_rejit_run_time_ns_delta": 1148565,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 0.9832809465181437,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 323.48576512455514,
      "baseline_run_cnt_delta": 562,
      "baseline_run_time_ns_delta": 181799,
      "post_rejit_avg_ns_per_run": 317.68637992831543,
      "post_rejit_run_cnt_delta": 558,
      "post_rejit_run_time_ns_delta": 177269,
      "program": "raw_tracepoint__sched_wakeup_new",
      "program_id": 49,
      "ratio": 0.9820722089764701,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    }
  ],
  "results": [
    {
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 143.98653531790416,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 92984,
            "run_time_ns_delta": 13388444,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.7334071169999845,
            "ops_per_sec": 7090.195717312776,
            "ops_total": 5200.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [2896]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2896] eventfd            1000      0.01      0.00      0.00     90605.37      112917.80\nstress-ng: info:  [2896] skipped: 0\nstress-ng: info:  [2896] passed: 1: eventfd (1)\nstress-ng: info:  [2896] failed: 0\nstress-ng: info:  [2896] metrics untrustworthy: 0\nstress-ng: info:  [2896] successful run completed in 0.01 secs\nstress-ng: info:  [2899] setting to a 1 secs run per stressor\nstress-ng: info:  [2899] dispatching hogs: 1 get\nstress-ng: info:  [2899] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2899] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2899]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2899] get                 200      0.35      0.00      0.03       565.38        7011.39\nstress-ng: info:  [2899] skipped: 0\nstress-ng: info:  [2899] passed: 1: get (1)\nstress-ng: info:  [2899] failed: 0\nstress-ng: info:  [2899] metrics untrustworthy: 0\nstress-ng: info:  [2899] successful run completed in 0.36 secs\nstress-ng: info:  [2901] setting to a 1 secs run per stressor\nstress-ng: info:  [2901] dispatching hogs: 1 prctl\nstress-ng: info:  [2901] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2901] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2901]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2901] prctl              1000      0.28      0.21      0.07      3534.39        3529.07\nstress-ng: info:  [2901] skipped: 0\nstress-ng: info:  [2901] passed: 1: prctl (1)\nstress-ng: info:  [2901] failed: 0\nstress-ng: info:  [2901] metrics untrustworthy: 0\nstress-ng: info:  [2901] successful run completed in 0.28 secs\nstress-ng: info:  [3903] setting to a 1 secs run per stressor\nstress-ng: info:  [3903] dispatching hogs: 1 set\nstress-ng: info:  [3903] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [3903] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3903]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3903] set                1000      0.02      0.00      0.02     50283.58       49795.84\nstress-ng: info:  [3903] skipped: 0\nstress-ng: info:  [3903] passed: 1: set (1)\nstress-ng: info:  [3903] failed: 0\nstress-ng: info:  [3903] metrics untrustworthy: 0\nstress-ng: info:  [3903] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 142.86069646390777,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 92984,
            "run_time_ns_delta": 13283759,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.8831595160000063,
            "ops_per_sec": 5887.9510505098415,
            "ops_total": 5200.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [4938]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4938] eventfd            1000      0.01      0.00      0.00    103353.80      132625.99\nstress-ng: info:  [4938] skipped: 0\nstress-ng: info:  [4938] passed: 1: eventfd (1)\nstress-ng: info:  [4938] failed: 0\nstress-ng: info:  [4938] metrics untrustworthy: 0\nstress-ng: info:  [4938] successful run completed in 0.01 secs\nstress-ng: info:  [4941] setting to a 1 secs run per stressor\nstress-ng: info:  [4941] dispatching hogs: 1 get\nstress-ng: info:  [4941] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4941] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4941]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4941] get                 200      0.51      0.01      0.01       394.42       12288.03\nstress-ng: info:  [4941] skipped: 0\nstress-ng: info:  [4941] passed: 1: get (1)\nstress-ng: info:  [4941] failed: 0\nstress-ng: info:  [4941] metrics untrustworthy: 0\nstress-ng: info:  [4941] successful run completed in 0.51 secs\nstress-ng: info:  [4943] setting to a 1 secs run per stressor\nstress-ng: info:  [4943] dispatching hogs: 1 prctl\nstress-ng: info:  [4943] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4943] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4943]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4943] prctl              1000      0.28      0.19      0.09      3596.81        3588.50\nstress-ng: info:  [4943] skipped: 0\nstress-ng: info:  [4943] passed: 1: prctl (1)\nstress-ng: info:  [4943] failed: 0\nstress-ng: info:  [4943] metrics untrustworthy: 0\nstress-ng: info:  [4943] successful run completed in 0.28 secs\nstress-ng: info:  [5945] setting to a 1 secs run per stressor\nstress-ng: info:  [5945] dispatching hogs: 1 set\nstress-ng: info:  [5945] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5945] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5945]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5945] set                1000      0.02      0.00      0.02     49301.25       48531.91\nstress-ng: info:  [5945] skipped: 0\nstress-ng: info:  [5945] passed: 1: set (1)\nstress-ng: info:  [5945] failed: 0\nstress-ng: info:  [5945] metrics untrustworthy: 0\nstress-ng: info:  [5945] successful run completed in 0.02 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_os",
      "status": "ok"
    },
    {
      "app": "bcc/execsnoop",
      "baseline": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1282.3333333333333,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 11541,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 320.55555555555554,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 2885,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.2790508120000084,
            "ops_per_sec": 5042.888881408563,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [6846]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6846] sem-sysv           1001      0.00      0.00      0.00    205798.65      211583.17\nstress-ng: info:  [6846] skipped: 0\nstress-ng: info:  [6846] passed: 1: sem-sysv (1)\nstress-ng: info:  [6846] failed: 0\nstress-ng: info:  [6846] metrics untrustworthy: 0\nstress-ng: info:  [6846] successful run completed in 0.01 secs\nstress-ng: info:  [6850] setting to a 1 secs run per stressor\nstress-ng: info:  [6850] dispatching hogs: 1 switch\nstress-ng: info:  [6850] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6850] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6850]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6850] switch             1000      0.01      0.01      0.00    115928.80      152835.09\nstress-ng: info:  [6850] skipped: 0\nstress-ng: info:  [6850] passed: 1: switch (1)\nstress-ng: info:  [6850] failed: 0\nstress-ng: info:  [6850] metrics untrustworthy: 0\nstress-ng: info:  [6850] successful run completed in 0.01 secs\nstress-ng: info:  [6853] setting to a 1 secs run per stressor\nstress-ng: info:  [6853] dispatching hogs: 1 vfork\nstress-ng: info:  [6853] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6853] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6853]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6853] vfork               200      0.01      0.01      0.00     19557.97       20267.53\nstress-ng: info:  [6853] skipped: 0\nstress-ng: info:  [6853] passed: 1: vfork (1)\nstress-ng: info:  [6853] failed: 0\nstress-ng: info:  [6853] metrics untrustworthy: 0\nstress-ng: info:  [6853] successful run completed in 0.01 secs\nstress-ng: info:  [7055] setting to a 1 secs run per stressor\nstress-ng: info:  [7055] dispatching hogs: 1 yield\nstress-ng: info:  [7055] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7055] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7055]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7055] yield              4992      1.00      0.01      0.01      4986.17      381855.73\nstress-ng: info:  [7055] skipped: 0\nstress-ng: info:  [7055] passed: 1: yield (1)\nstress-ng: info:  [7055] failed: 0\nstress-ng: info:  [7055] metrics untrustworthy: 0\nstress-ng: info:  [7055] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1653.3333333333333,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 14880,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 445.22222222222223,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 4007,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.2962443750000148,
            "ops_per_sec": 5005.129299445721,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7995]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7995] sem-sysv           1001      0.00      0.00      0.00    280836.01      301506.02\nstress-ng: info:  [7995] skipped: 0\nstress-ng: info:  [7995] passed: 1: sem-sysv (1)\nstress-ng: info:  [7995] failed: 0\nstress-ng: info:  [7995] metrics untrustworthy: 0\nstress-ng: info:  [7995] successful run completed in 0.01 secs\nstress-ng: info:  [7999] setting to a 1 secs run per stressor\nstress-ng: info:  [7999] dispatching hogs: 1 switch\nstress-ng: info:  [7999] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7999] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7999]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7999] switch             1000      0.01      0.01      0.00     91353.30      128982.33\nstress-ng: info:  [7999] skipped: 0\nstress-ng: info:  [7999] passed: 1: switch (1)\nstress-ng: info:  [7999] failed: 0\nstress-ng: info:  [7999] metrics untrustworthy: 0\nstress-ng: info:  [7999] successful run completed in 0.01 secs\nstress-ng: info:  [8002] setting to a 1 secs run per stressor\nstress-ng: info:  [8002] dispatching hogs: 1 vfork\nstress-ng: info:  [8002] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8002] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8002]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8002] vfork               200      0.00      0.00      0.00     41394.56       40120.36\nstress-ng: info:  [8002] skipped: 0\nstress-ng: info:  [8002] passed: 1: vfork (1)\nstress-ng: info:  [8002] failed: 0\nstress-ng: info:  [8002] metrics untrustworthy: 0\nstress-ng: info:  [8002] successful run completed in 0.01 secs\nstress-ng: info:  [8204] setting to a 1 secs run per stressor\nstress-ng: info:  [8204] dispatching hogs: 1 yield\nstress-ng: info:  [8204] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8204] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8204]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8204] yield              4992      1.00      0.01      0.00      4986.74      396442.19\nstress-ng: info:  [8204] skipped: 0\nstress-ng: info:  [8204] passed: 1: yield (1)\nstress-ng: info:  [8204] failed: 0\nstress-ng: info:  [8204] metrics untrustworthy: 0\nstress-ng: info:  [8204] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_process",
      "status": "ok"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 2503.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5006,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 6247.5,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 12495,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": null,
            "bytes_jited": 742,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.28438796999998317,
            "ops_per_sec": 18077.417269093006,
            "ops_total": 5141.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [8307]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8307] sockdiag           1012      0.00      0.00      0.00   3981834.57     2044444.44\nstress-ng: info:  [8307] skipped: 0\nstress-ng: info:  [8307] passed: 1: sockdiag (1)\nstress-ng: info:  [8307] failed: 0\nstress-ng: info:  [8307] metrics untrustworthy: 0\nstress-ng: info:  [8307] successful run completed in 0.00 secs\nstress-ng: info:  [8309] setting to a 1 secs run per stressor\nstress-ng: info:  [8309] dispatching hogs: 1 sockfd\nstress-ng: info:  [8309] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8309] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8309]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8309] sockfd              200      0.00      0.00      0.00    144035.16      102354.15\nstress-ng: info:  [8309] skipped: 0\nstress-ng: info:  [8309] passed: 1: sockfd (1)\nstress-ng: info:  [8309] failed: 0\nstress-ng: info:  [8309] metrics untrustworthy: 0\nstress-ng: info:  [8309] successful run completed in 0.00 secs\nstress-ng: info:  [8312] setting to a 1 secs run per stressor\nstress-ng: info:  [8312] dispatching hogs: 1 sockpair\nstress-ng: info:  [8312] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8312] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8312]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8312] sockpair            500      0.01      0.00      0.01     44227.85       36239.76\nstress-ng: info:  [8312] skipped: 0\nstress-ng: info:  [8312] passed: 1: sockpair (1)\nstress-ng: info:  [8312] failed: 0\nstress-ng: info:  [8312] metrics untrustworthy: 0\nstress-ng: info:  [8312] successful run completed in 0.01 secs\nstress-ng: info:  [8316] setting to a 1 secs run per stressor\nstress-ng: info:  [8316] dispatching hogs: 1 udp-flood\nstress-ng: info:  [8316] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8316] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8316]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8316] udp-flood          1000      0.00      0.00      0.00    421284.05      353481.80\nstress-ng: info:  [8316] skipped: 0\nstress-ng: info:  [8316] passed: 1: udp-flood (1)\nstress-ng: info:  [8316] failed: 0\nstress-ng: info:  [8316] metrics untrustworthy: 0\nstress-ng: info:  [8316] successful run completed in 0.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 2820.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5640,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 7540.5,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 15081,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": null,
            "bytes_jited": 742,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.28953656300001285,
            "ops_per_sec": 17655.801212228154,
            "ops_total": 5112.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [8373]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8373] sockdiag           1012      0.00      0.00      0.00   3756314.73     2003960.40\nstress-ng: info:  [8373] skipped: 0\nstress-ng: info:  [8373] passed: 1: sockdiag (1)\nstress-ng: info:  [8373] failed: 0\nstress-ng: info:  [8373] metrics untrustworthy: 0\nstress-ng: info:  [8373] successful run completed in 0.00 secs\nstress-ng: info:  [8375] setting to a 1 secs run per stressor\nstress-ng: info:  [8375] dispatching hogs: 1 sockfd\nstress-ng: info:  [8375] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8375] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8375]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8375] sockfd              200      0.00      0.00      0.00    133853.65       91324.20\nstress-ng: info:  [8375] skipped: 0\nstress-ng: info:  [8375] passed: 1: sockfd (1)\nstress-ng: info:  [8375] failed: 0\nstress-ng: info:  [8375] metrics untrustworthy: 0\nstress-ng: info:  [8375] successful run completed in 0.00 secs\nstress-ng: info:  [8378] setting to a 1 secs run per stressor\nstress-ng: info:  [8378] dispatching hogs: 1 sockpair\nstress-ng: info:  [8378] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8378] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8378]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8378] sockpair            500      0.01      0.00      0.01     47319.48       38255.55\nstress-ng: info:  [8378] skipped: 0\nstress-ng: info:  [8378] passed: 1: sockpair (1)\nstress-ng: info:  [8378] failed: 0\nstress-ng: info:  [8378] metrics untrustworthy: 0\nstress-ng: info:  [8378] successful run completed in 0.01 secs\nstress-ng: info:  [8382] setting to a 1 secs run per stressor\nstress-ng: info:  [8382] dispatching hogs: 1 udp-flood\nstress-ng: info:  [8382] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8382] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8382]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8382] udp-flood          1000      0.00      0.00      0.00    394795.18      310077.52\nstress-ng: info:  [8382] skipped: 0\nstress-ng: info:  [8382] passed: 1: udp-flood (1)\nstress-ng: info:  [8382] failed: 0\nstress-ng: info:  [8382] metrics untrustworthy: 0\nstress-ng: info:  [8382] successful run completed in 0.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_network",
      "status": "ok"
    },
    {
      "app": "bcc/biosnoop",
      "baseline": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 231.70638292849893,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1609794,
            "run_time_ns_delta": 372999545,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 200.10387289384298,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1609804,
            "run_time_ns_delta": 322128015,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 96.19301668707281,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1609809,
            "run_time_ns_delta": 154852384,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.356441017999998,
            "ops_per_sec": 402239.0973334154,
            "ops_total": 2154570.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.228914,\n        \"1000\" : 17.913339\n      },\n      \"latency_us\" : {\n        \"2\" : 29.682504,\n        \"4\" : 1.562364,\n        \"10\" : 13.873139,\n        \"20\" : 32.250238,\n        \"50\" : 3.515828,\n        \"100\" : 0.636512,\n        \"250\" : 0.324929,\n        \"500\" : 0.012233,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 226.93939241792384,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1692940,
            "run_time_ns_delta": 384194775,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 197.03966921645647,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1692950,
            "run_time_ns_delta": 333578308,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 93.95494800511531,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1692955,
            "run_time_ns_delta": 159061499,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.337686824000002,
            "ops_per_sec": 425468.38637830113,
            "ops_total": 2271017.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.096157,\n        \"1000\" : 16.224487\n      },\n      \"latency_us\" : {\n        \"2\" : 31.534785,\n        \"4\" : 1.550437,\n        \"10\" : 16.794057,\n        \"20\" : 29.634465,\n        \"50\" : 3.540772,\n        \"100\" : 0.428318,\n        \"250\" : 0.185470,\n        \"500\" : 0.011054,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "fio_randrw",
      "status": "ok"
    },
    {
      "app": "bcc/vfsstat",
      "baseline": {
        "bpf": {
          "23": {
            "avg_ns_per_run": 34.983535706935584,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 4859,
            "run_time_ns_delta": 169985,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 28.391167192429023,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 317,
            "run_time_ns_delta": 9000,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 25.33942280825472,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 75157,
            "run_time_ns_delta": 1904435,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 23.22852182042806,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 29949,
            "run_time_ns_delta": 695671,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 23.807863031071655,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 4731,
            "run_time_ns_delta": 112635,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 3.148809065999984,
            "ops_per_sec": 2664.817022601917,
            "ops_total": 8391.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [10179]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10179] open                100      0.01      0.01      0.00     11164.86       15865.46\nstress-ng: info:  [10179] skipped: 0\nstress-ng: info:  [10179] passed: 1: open (1)\nstress-ng: info:  [10179] failed: 0\nstress-ng: info:  [10179] metrics untrustworthy: 0\nstress-ng: info:  [10179] successful run completed in 0.01 secs\nstress-ng: info:  [10181] setting to a 1 secs run per stressor\nstress-ng: info:  [10181] dispatching hogs: 1 rename\nstress-ng: info:  [10181] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10181] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10181]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10181] rename              100      0.00      0.00      0.00     22878.44       56625.14\nstress-ng: info:  [10181] skipped: 0\nstress-ng: info:  [10181] passed: 1: rename (1)\nstress-ng: info:  [10181] failed: 0\nstress-ng: info:  [10181] metrics untrustworthy: 0\nstress-ng: info:  [10181] successful run completed in 0.01 secs\nstress-ng: info:  [10183] setting to a 1 secs run per stressor\nstress-ng: info:  [10183] dispatching hogs: 1 touch\nstress-ng: info:  [10183] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10183] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10183]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10183] touch               200      0.01      0.00      0.03     26202.12        7655.80\nstress-ng: info:  [10183] skipped: 0\nstress-ng: info:  [10183] passed: 1: touch (1)\nstress-ng: info:  [10183] failed: 0\nstress-ng: info:  [10183] metrics untrustworthy: 0\nstress-ng: info:  [10183] successful run completed in 0.01 secs\nstress-ng: info:  [10189] setting to a 1 secs run per stressor\nstress-ng: info:  [10189] dispatching hogs: 1 utime\nstress-ng: info:  [10189] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10189] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10189]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10189] utime               200      0.00      0.00      0.00     55395.95       52246.60\nstress-ng: info:  [10189] skipped: 0\nstress-ng: info:  [10189] passed: 1: utime (1)\nstress-ng: info:  [10189] failed: 0\nstress-ng: info:  [10189] metrics untrustworthy: 0\nstress-ng: info:  [10189] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "23": {
            "avg_ns_per_run": 33.31397982293597,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 4857,
            "run_time_ns_delta": 161806,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 30.2397476340694,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 317,
            "run_time_ns_delta": 9586,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 25.46422992362879,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 69136,
            "run_time_ns_delta": 1760495,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 23.37051752921536,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 29950,
            "run_time_ns_delta": 699947,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 23.752475247524753,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 4747,
            "run_time_ns_delta": 112753,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 4.159802982999992,
            "ops_per_sec": 2017.1628402334882,
            "ops_total": 8391.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [11913]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11913] open                100      0.01      0.01      0.00     11784.40       16350.56\nstress-ng: info:  [11913] skipped: 0\nstress-ng: info:  [11913] passed: 1: open (1)\nstress-ng: info:  [11913] failed: 0\nstress-ng: info:  [11913] metrics untrustworthy: 0\nstress-ng: info:  [11913] successful run completed in 0.01 secs\nstress-ng: info:  [11915] setting to a 1 secs run per stressor\nstress-ng: info:  [11915] dispatching hogs: 1 rename\nstress-ng: info:  [11915] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11915] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11915]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11915] rename              100      0.00      0.00      0.00     23081.14       46794.57\nstress-ng: info:  [11915] skipped: 0\nstress-ng: info:  [11915] passed: 1: rename (1)\nstress-ng: info:  [11915] failed: 0\nstress-ng: info:  [11915] metrics untrustworthy: 0\nstress-ng: info:  [11915] successful run completed in 0.01 secs\nstress-ng: info:  [11917] setting to a 1 secs run per stressor\nstress-ng: info:  [11917] dispatching hogs: 1 touch\nstress-ng: info:  [11917] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11917] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11917]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11917] touch               200      0.01      0.00      0.02     36853.56       10604.45\nstress-ng: info:  [11917] skipped: 0\nstress-ng: info:  [11917] passed: 1: touch (1)\nstress-ng: info:  [11917] failed: 0\nstress-ng: info:  [11917] metrics untrustworthy: 0\nstress-ng: info:  [11917] successful run completed in 0.01 secs\nstress-ng: info:  [11923] setting to a 1 secs run per stressor\nstress-ng: info:  [11923] dispatching hogs: 1 utime\nstress-ng: info:  [11923] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11923] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11923]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11923] utime               200      0.00      0.00      0.00     86010.54       76365.02\nstress-ng: info:  [11923] skipped: 0\nstress-ng: info:  [11923] passed: 1: utime (1)\nstress-ng: info:  [11923] failed: 0\nstress-ng: info:  [11923] metrics untrustworthy: 0\nstress-ng: info:  [11923] successful run completed in 0.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 5,
          "not_applied": 0,
          "requested": 5
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_filesystem",
      "status": "ok"
    },
    {
      "app": "bcc/opensnoop",
      "baseline": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 845.4601769911504,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 113,
            "run_time_ns_delta": 95537,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 756.7857342657343,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 53625,
            "run_time_ns_delta": 40582635,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1003.8333333333334,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 6023,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 4.255348402999999,
            "ops_per_sec": 1971.8714439655253,
            "ops_total": 8391.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [13645]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13645] open                100      0.01      0.01      0.00     12680.81       15158.41\nstress-ng: info:  [13645] skipped: 0\nstress-ng: info:  [13645] passed: 1: open (1)\nstress-ng: info:  [13645] failed: 0\nstress-ng: info:  [13645] metrics untrustworthy: 0\nstress-ng: info:  [13645] successful run completed in 0.01 secs\nstress-ng: info:  [13647] setting to a 1 secs run per stressor\nstress-ng: info:  [13647] dispatching hogs: 1 rename\nstress-ng: info:  [13647] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13647] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13647]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13647] rename              100      0.01      0.00      0.00     14953.49       27693.16\nstress-ng: info:  [13647] skipped: 0\nstress-ng: info:  [13647] passed: 1: rename (1)\nstress-ng: info:  [13647] failed: 0\nstress-ng: info:  [13647] metrics untrustworthy: 0\nstress-ng: info:  [13647] successful run completed in 0.01 secs\nstress-ng: info:  [13649] setting to a 1 secs run per stressor\nstress-ng: info:  [13649] dispatching hogs: 1 touch\nstress-ng: info:  [13649] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13649] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13649]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13649] touch               200      0.00      0.01      0.00     44391.22       13519.91\nstress-ng: info:  [13649] skipped: 0\nstress-ng: info:  [13649] passed: 1: touch (1)\nstress-ng: info:  [13649] failed: 0\nstress-ng: info:  [13649] metrics untrustworthy: 0\nstress-ng: info:  [13649] successful run completed in 0.01 secs\nstress-ng: info:  [13655] setting to a 1 secs run per stressor\nstress-ng: info:  [13655] dispatching hogs: 1 utime\nstress-ng: info:  [13655] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13655] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13655]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13655] utime               200      0.00      0.00      0.00     61563.25       58360.08\nstress-ng: info:  [13655] skipped: 0\nstress-ng: info:  [13655] passed: 1: utime (1)\nstress-ng: info:  [13655] failed: 0\nstress-ng: info:  [13655] metrics untrustworthy: 0\nstress-ng: info:  [13655] successful run completed in 0.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 531.5591397849462,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 93,
            "run_time_ns_delta": 49435,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 739.3185546975768,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 58147,
            "run_time_ns_delta": 42989156,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 586.5,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 2346,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 3.2363897529999974,
            "ops_per_sec": 2592.7037966369458,
            "ops_total": 8391.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [15377]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15377] open                100      0.01      0.00      0.00     18434.88       25075.23\nstress-ng: info:  [15377] skipped: 0\nstress-ng: info:  [15377] passed: 1: open (1)\nstress-ng: info:  [15377] failed: 0\nstress-ng: info:  [15377] metrics untrustworthy: 0\nstress-ng: info:  [15377] successful run completed in 0.01 secs\nstress-ng: info:  [15379] setting to a 1 secs run per stressor\nstress-ng: info:  [15379] dispatching hogs: 1 rename\nstress-ng: info:  [15379] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15379] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15379]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15379] rename              100      0.00      0.00      0.00     22956.07       33829.50\nstress-ng: info:  [15379] skipped: 0\nstress-ng: info:  [15379] passed: 1: rename (1)\nstress-ng: info:  [15379] failed: 0\nstress-ng: info:  [15379] metrics untrustworthy: 0\nstress-ng: info:  [15379] successful run completed in 0.01 secs\nstress-ng: info:  [15381] setting to a 1 secs run per stressor\nstress-ng: info:  [15381] dispatching hogs: 1 touch\nstress-ng: info:  [15381] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15381] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15381]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15381] touch               200      0.01      0.00      0.01     39696.23       15234.61\nstress-ng: info:  [15381] skipped: 0\nstress-ng: info:  [15381] passed: 1: touch (1)\nstress-ng: info:  [15381] failed: 0\nstress-ng: info:  [15381] metrics untrustworthy: 0\nstress-ng: info:  [15381] successful run completed in 0.01 secs\nstress-ng: info:  [15387] setting to a 1 secs run per stressor\nstress-ng: info:  [15387] dispatching hogs: 1 utime\nstress-ng: info:  [15387] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15387] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15387]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15387] utime               200      0.00      0.00      0.00     59258.32       56164.00\nstress-ng: info:  [15387] skipped: 0\nstress-ng: info:  [15387] passed: 1: utime (1)\nstress-ng: info:  [15387] failed: 0\nstress-ng: info:  [15387] metrics untrustworthy: 0\nstress-ng: info:  [15387] successful run completed in 0.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_filesystem",
      "status": "ok"
    },
    {
      "app": "bcc/syscount",
      "baseline": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 68.46213580081356,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 559275,
            "run_time_ns_delta": 38289161,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 60.362988935695434,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 559276,
            "run_time_ns_delta": 33759571,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 0.7925216760000069,
            "ops_per_sec": 6561.334733764373,
            "ops_total": 5200.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [16423]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16423] eventfd            1000      0.01      0.01      0.00    133653.18      157977.88\nstress-ng: info:  [16423] skipped: 0\nstress-ng: info:  [16423] passed: 1: eventfd (1)\nstress-ng: info:  [16423] failed: 0\nstress-ng: info:  [16423] metrics untrustworthy: 0\nstress-ng: info:  [16423] successful run completed in 0.01 secs\nstress-ng: info:  [16426] setting to a 1 secs run per stressor\nstress-ng: info:  [16426] dispatching hogs: 1 get\nstress-ng: info:  [16426] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16426] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16426]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16426] get                 200      0.22      0.01      0.02       892.62        6529.12\nstress-ng: info:  [16426] skipped: 0\nstress-ng: info:  [16426] passed: 1: get (1)\nstress-ng: info:  [16426] failed: 0\nstress-ng: info:  [16426] metrics untrustworthy: 0\nstress-ng: info:  [16426] successful run completed in 0.23 secs\nstress-ng: info:  [16428] setting to a 1 secs run per stressor\nstress-ng: info:  [16428] dispatching hogs: 1 prctl\nstress-ng: info:  [16428] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16428] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16428]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16428] prctl              1000      0.45      0.36      0.08      2197.89        2228.08\nstress-ng: info:  [16428] skipped: 0\nstress-ng: info:  [16428] passed: 1: prctl (1)\nstress-ng: info:  [16428] failed: 0\nstress-ng: info:  [16428] metrics untrustworthy: 0\nstress-ng: info:  [16428] successful run completed in 0.46 secs\nstress-ng: info:  [17430] setting to a 1 secs run per stressor\nstress-ng: info:  [17430] dispatching hogs: 1 set\nstress-ng: info:  [17430] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17430] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17430]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17430] set                1000      0.02      0.00      0.02     44821.95       44618.95\nstress-ng: info:  [17430] skipped: 0\nstress-ng: info:  [17430] passed: 1: set (1)\nstress-ng: info:  [17430] failed: 0\nstress-ng: info:  [17430] metrics untrustworthy: 0\nstress-ng: info:  [17430] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 78.89243160403929,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 559207,
            "run_time_ns_delta": 44117200,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 62.561560278107606,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 559208,
            "run_time_ns_delta": 34984925,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 0.792128933999976,
            "ops_per_sec": 6564.587880588841,
            "ops_total": 5200.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [18466]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18466] eventfd            1000      0.01      0.01      0.00     95566.18       95419.85\nstress-ng: info:  [18466] skipped: 0\nstress-ng: info:  [18466] passed: 1: eventfd (1)\nstress-ng: info:  [18466] failed: 0\nstress-ng: info:  [18466] metrics untrustworthy: 0\nstress-ng: info:  [18466] successful run completed in 0.01 secs\nstress-ng: info:  [18469] setting to a 1 secs run per stressor\nstress-ng: info:  [18469] dispatching hogs: 1 get\nstress-ng: info:  [18469] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18469] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18469]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18469] get                 200      0.28      0.00      0.02       716.96        8312.90\nstress-ng: info:  [18469] skipped: 0\nstress-ng: info:  [18469] passed: 1: get (1)\nstress-ng: info:  [18469] failed: 0\nstress-ng: info:  [18469] metrics untrustworthy: 0\nstress-ng: info:  [18469] successful run completed in 0.28 secs\nstress-ng: info:  [18471] setting to a 1 secs run per stressor\nstress-ng: info:  [18471] dispatching hogs: 1 prctl\nstress-ng: info:  [18471] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18471] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18471]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18471] prctl              1000      0.39      0.29      0.09      2579.86        2600.67\nstress-ng: info:  [18471] skipped: 0\nstress-ng: info:  [18471] passed: 1: prctl (1)\nstress-ng: info:  [18471] failed: 0\nstress-ng: info:  [18471] metrics untrustworthy: 0\nstress-ng: info:  [18471] successful run completed in 0.39 secs\nstress-ng: info:  [19473] setting to a 1 secs run per stressor\nstress-ng: info:  [19473] dispatching hogs: 1 set\nstress-ng: info:  [19473] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19473] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19473]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19473] set                1000      0.03      0.01      0.02     30246.88       30048.08\nstress-ng: info:  [19473] skipped: 0\nstress-ng: info:  [19473] passed: 1: set (1)\nstress-ng: info:  [19473] failed: 0\nstress-ng: info:  [19473] metrics untrustworthy: 0\nstress-ng: info:  [19473] successful run completed in 0.03 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_os",
      "status": "ok"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 3241.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3241,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 11080.0,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 11080,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.4215065000000209,
            "ops_per_sec": 12196.727689845222,
            "ops_total": 5141.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [19532]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19532] sockdiag           1025      0.00      0.00      0.00   3818083.13     2050000.00\nstress-ng: info:  [19532] skipped: 0\nstress-ng: info:  [19532] passed: 1: sockdiag (1)\nstress-ng: info:  [19532] failed: 0\nstress-ng: info:  [19532] metrics untrustworthy: 0\nstress-ng: info:  [19532] successful run completed in 0.00 secs\nstress-ng: info:  [19534] setting to a 1 secs run per stressor\nstress-ng: info:  [19534] dispatching hogs: 1 sockfd\nstress-ng: info:  [19534] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19534] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19534]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19534] sockfd              200      0.00      0.00      0.00     93020.71       83125.52\nstress-ng: info:  [19534] skipped: 0\nstress-ng: info:  [19534] passed: 1: sockfd (1)\nstress-ng: info:  [19534] failed: 0\nstress-ng: info:  [19534] metrics untrustworthy: 0\nstress-ng: info:  [19534] successful run completed in 0.00 secs\nstress-ng: info:  [19537] setting to a 1 secs run per stressor\nstress-ng: info:  [19537] dispatching hogs: 1 sockpair\nstress-ng: info:  [19537] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19537] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19537]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19537] sockpair            500      0.01      0.00      0.01     56367.48       47632.66\nstress-ng: info:  [19537] skipped: 0\nstress-ng: info:  [19537] passed: 1: sockpair (1)\nstress-ng: info:  [19537] failed: 0\nstress-ng: info:  [19537] metrics untrustworthy: 0\nstress-ng: info:  [19537] successful run completed in 0.01 secs\nstress-ng: info:  [19541] setting to a 1 secs run per stressor\nstress-ng: info:  [19541] dispatching hogs: 1 udp-flood\nstress-ng: info:  [19541] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19541] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19541]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19541] udp-flood          1000      0.00      0.00      0.00    934143.43      760456.27\nstress-ng: info:  [19541] skipped: 0\nstress-ng: info:  [19541] passed: 1: udp-flood (1)\nstress-ng: info:  [19541] failed: 0\nstress-ng: info:  [19541] metrics untrustworthy: 0\nstress-ng: info:  [19541] successful run completed in 0.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 1985.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1985,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 5735.0,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 5735,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.420714543999992,
            "ops_per_sec": 12376.562860161306,
            "ops_total": 5207.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [19598]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19598] sockdiag           1025      0.00      0.00      0.00   4214864.31     1764199.66\nstress-ng: info:  [19598] skipped: 0\nstress-ng: info:  [19598] passed: 1: sockdiag (1)\nstress-ng: info:  [19598] failed: 0\nstress-ng: info:  [19598] metrics untrustworthy: 0\nstress-ng: info:  [19598] successful run completed in 0.00 secs\nstress-ng: info:  [19600] setting to a 1 secs run per stressor\nstress-ng: info:  [19600] dispatching hogs: 1 sockfd\nstress-ng: info:  [19600] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19600] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19600]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19600] sockfd              200      0.00      0.00      0.00    127042.37      105988.34\nstress-ng: info:  [19600] skipped: 0\nstress-ng: info:  [19600] passed: 1: sockfd (1)\nstress-ng: info:  [19600] failed: 0\nstress-ng: info:  [19600] metrics untrustworthy: 0\nstress-ng: info:  [19600] successful run completed in 0.00 secs\nstress-ng: info:  [19603] setting to a 1 secs run per stressor\nstress-ng: info:  [19603] dispatching hogs: 1 sockpair\nstress-ng: info:  [19603] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19603] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19603]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19603] sockpair            500      0.01      0.01      0.00     37932.79       30295.69\nstress-ng: info:  [19603] skipped: 0\nstress-ng: info:  [19603] passed: 1: sockpair (1)\nstress-ng: info:  [19603] failed: 0\nstress-ng: info:  [19603] metrics untrustworthy: 0\nstress-ng: info:  [19603] successful run completed in 0.02 secs\nstress-ng: info:  [19607] setting to a 1 secs run per stressor\nstress-ng: info:  [19607] dispatching hogs: 1 udp-flood\nstress-ng: info:  [19607] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19607] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19607]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19607] udp-flood          1000      0.00      0.00      0.00    657826.85      413564.93\nstress-ng: info:  [19607] skipped: 0\nstress-ng: info:  [19607] passed: 1: udp-flood (1)\nstress-ng: info:  [19607] failed: 0\nstress-ng: info:  [19607] metrics untrustworthy: 0\nstress-ng: info:  [19607] successful run completed in 0.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_network",
      "status": "ok"
    },
    {
      "app": "bcc/tcplife",
      "baseline": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 1069.6315789473683,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 19,
            "run_time_ns_delta": 20323,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2618696899999975,
            "ops_per_sec": 4137.511219561831,
            "ops_total": 5221.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [19665]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19665] sockdiag           1025      0.00      0.00      0.00   4110097.13     2324263.04\nstress-ng: info:  [19665] skipped: 0\nstress-ng: info:  [19665] passed: 1: sockdiag (1)\nstress-ng: info:  [19665] failed: 0\nstress-ng: info:  [19665] metrics untrustworthy: 0\nstress-ng: info:  [19665] successful run completed in 0.00 secs\nstress-ng: info:  [19667] setting to a 1 secs run per stressor\nstress-ng: info:  [19667] dispatching hogs: 1 sockfd\nstress-ng: info:  [19667] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19667] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19667]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19667] sockfd              200      0.00      0.00      0.00    200062.20      127959.05\nstress-ng: info:  [19667] skipped: 0\nstress-ng: info:  [19667] passed: 1: sockfd (1)\nstress-ng: info:  [19667] failed: 0\nstress-ng: info:  [19667] metrics untrustworthy: 0\nstress-ng: info:  [19667] successful run completed in 0.00 secs\nstress-ng: info:  [19670] setting to a 1 secs run per stressor\nstress-ng: info:  [19670] dispatching hogs: 1 sockpair\nstress-ng: info:  [19670] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19670] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19670]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19670] sockpair            500      0.01      0.00      0.01     41314.24       33271.23\nstress-ng: info:  [19670] skipped: 0\nstress-ng: info:  [19670] passed: 1: sockpair (1)\nstress-ng: info:  [19670] failed: 0\nstress-ng: info:  [19670] metrics untrustworthy: 0\nstress-ng: info:  [19670] successful run completed in 0.01 secs\nstress-ng: info:  [19674] setting to a 1 secs run per stressor\nstress-ng: info:  [19674] dispatching hogs: 1 udp-flood\nstress-ng: info:  [19674] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19674] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19674]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19674] udp-flood          1000      0.00      0.00      0.00    958698.06      793650.79\nstress-ng: info:  [19674] skipped: 0\nstress-ng: info:  [19674] passed: 1: udp-flood (1)\nstress-ng: info:  [19674] failed: 0\nstress-ng: info:  [19674] metrics untrustworthy: 0\nstress-ng: info:  [19674] successful run completed in 0.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 21.723076923076924,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 3510,
            "run_time_ns_delta": 76248,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 0.28225243200000705,
            "ops_per_sec": 18157.505193790046,
            "ops_total": 5125.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [19729]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19729] sockdiag           1025      0.00      0.00      0.00   3791147.80     2001953.12\nstress-ng: info:  [19729] skipped: 0\nstress-ng: info:  [19729] passed: 1: sockdiag (1)\nstress-ng: info:  [19729] failed: 0\nstress-ng: info:  [19729] metrics untrustworthy: 0\nstress-ng: info:  [19729] successful run completed in 0.00 secs\nstress-ng: info:  [19731] setting to a 1 secs run per stressor\nstress-ng: info:  [19731] dispatching hogs: 1 sockfd\nstress-ng: info:  [19731] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19731] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19731]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19731] sockfd              200      0.00      0.00      0.00    156533.08      123152.71\nstress-ng: info:  [19731] skipped: 0\nstress-ng: info:  [19731] passed: 1: sockfd (1)\nstress-ng: info:  [19731] failed: 0\nstress-ng: info:  [19731] metrics untrustworthy: 0\nstress-ng: info:  [19731] successful run completed in 0.00 secs\nstress-ng: info:  [19734] setting to a 1 secs run per stressor\nstress-ng: info:  [19734] dispatching hogs: 1 sockpair\nstress-ng: info:  [19734] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19734] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19734]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19734] sockpair            500      0.01      0.00      0.01     36469.04       29990.40\nstress-ng: info:  [19734] skipped: 0\nstress-ng: info:  [19734] passed: 1: sockpair (1)\nstress-ng: info:  [19734] failed: 0\nstress-ng: info:  [19734] metrics untrustworthy: 0\nstress-ng: info:  [19734] successful run completed in 0.02 secs\nstress-ng: info:  [19738] setting to a 1 secs run per stressor\nstress-ng: info:  [19738] dispatching hogs: 1 udp-flood\nstress-ng: info:  [19738] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19738] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19738]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19738] udp-flood          1000      0.00      0.00      0.00    592583.22      535905.68\nstress-ng: info:  [19738] skipped: 0\nstress-ng: info:  [19738] passed: 1: udp-flood (1)\nstress-ng: info:  [19738] failed: 0\nstress-ng: info:  [19738] metrics untrustworthy: 0\nstress-ng: info:  [19738] successful run completed in 0.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_network",
      "status": "ok"
    },
    {
      "app": "bcc/runqlat",
      "baseline": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 220.17565306910308,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 7771,
            "run_time_ns_delta": 1710985,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 297.22504664179104,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 4288,
            "run_time_ns_delta": 1274501,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 323.48576512455514,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 562,
            "run_time_ns_delta": 181799,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.3502913780000085,
            "ops_per_sec": 4890.031979685865,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [20640]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20640] sem-sysv           1001      0.00      0.00      0.00    229263.27      203207.47\nstress-ng: info:  [20640] skipped: 0\nstress-ng: info:  [20640] passed: 1: sem-sysv (1)\nstress-ng: info:  [20640] failed: 0\nstress-ng: info:  [20640] metrics untrustworthy: 0\nstress-ng: info:  [20640] successful run completed in 0.01 secs\nstress-ng: info:  [20644] setting to a 1 secs run per stressor\nstress-ng: info:  [20644] dispatching hogs: 1 switch\nstress-ng: info:  [20644] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20644] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20644]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20644] switch             1000      0.01      0.01      0.00    123901.22      173973.56\nstress-ng: info:  [20644] skipped: 0\nstress-ng: info:  [20644] passed: 1: switch (1)\nstress-ng: info:  [20644] failed: 0\nstress-ng: info:  [20644] metrics untrustworthy: 0\nstress-ng: info:  [20644] successful run completed in 0.01 secs\nstress-ng: info:  [20647] setting to a 1 secs run per stressor\nstress-ng: info:  [20647] dispatching hogs: 1 vfork\nstress-ng: info:  [20647] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20647] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20647]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20647] vfork               200      0.01      0.01      0.00     34457.21       31254.88\nstress-ng: info:  [20647] skipped: 0\nstress-ng: info:  [20647] passed: 1: vfork (1)\nstress-ng: info:  [20647] failed: 0\nstress-ng: info:  [20647] metrics untrustworthy: 0\nstress-ng: info:  [20647] successful run completed in 0.01 secs\nstress-ng: info:  [20849] setting to a 1 secs run per stressor\nstress-ng: info:  [20849] dispatching hogs: 1 yield\nstress-ng: info:  [20849] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20849] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20849]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20849] yield              4992      1.00      0.01      0.00      4987.64      417286.63\nstress-ng: info:  [20849] skipped: 0\nstress-ng: info:  [20849] passed: 1: yield (1)\nstress-ng: info:  [20849] failed: 0\nstress-ng: info:  [20849] metrics untrustworthy: 0\nstress-ng: info:  [20849] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 199.65827338129498,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 6950,
            "run_time_ns_delta": 1387625,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 292.2557251908397,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 3930,
            "run_time_ns_delta": 1148565,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 317.68637992831543,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 558,
            "run_time_ns_delta": 177269,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.2855988569999965,
            "ops_per_sec": 5028.441436606834,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [21777]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21777] sem-sysv           1001      0.00      0.00      0.00    698934.29      475986.69\nstress-ng: info:  [21777] skipped: 0\nstress-ng: info:  [21777] passed: 1: sem-sysv (1)\nstress-ng: info:  [21777] failed: 0\nstress-ng: info:  [21777] metrics untrustworthy: 0\nstress-ng: info:  [21777] successful run completed in 0.00 secs\nstress-ng: info:  [21781] setting to a 1 secs run per stressor\nstress-ng: info:  [21781] dispatching hogs: 1 switch\nstress-ng: info:  [21781] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21781] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21781]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21781] switch             1000      0.01      0.01      0.00    118680.97      159438.78\nstress-ng: info:  [21781] skipped: 0\nstress-ng: info:  [21781] passed: 1: switch (1)\nstress-ng: info:  [21781] failed: 0\nstress-ng: info:  [21781] metrics untrustworthy: 0\nstress-ng: info:  [21781] successful run completed in 0.01 secs\nstress-ng: info:  [21784] setting to a 1 secs run per stressor\nstress-ng: info:  [21784] dispatching hogs: 1 vfork\nstress-ng: info:  [21784] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21784] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21784]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21784] vfork               200      0.01      0.01      0.00     29153.43       28113.58\nstress-ng: info:  [21784] skipped: 0\nstress-ng: info:  [21784] passed: 1: vfork (1)\nstress-ng: info:  [21784] failed: 0\nstress-ng: info:  [21784] metrics untrustworthy: 0\nstress-ng: info:  [21784] successful run completed in 0.01 secs\nstress-ng: info:  [21986] setting to a 1 secs run per stressor\nstress-ng: info:  [21986] dispatching hogs: 1 yield\nstress-ng: info:  [21986] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21986] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21986]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21986] yield              4992      1.00      0.01      0.00      4986.61      348579.01\nstress-ng: info:  [21986] skipped: 0\nstress-ng: info:  [21986] passed: 1: yield (1)\nstress-ng: info:  [21986] failed: 0\nstress-ng: info:  [21986] metrics untrustworthy: 0\nstress-ng: info:  [21986] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "rotate"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_scheduler",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 9,
    "per_program_geomean": 0.8058596265764479,
    "program_count": 24,
    "wins": 15
  },
  "workload_seconds": 1.0
}
```
