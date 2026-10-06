# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-28T19:45:04.133938+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-28T18:48:22.737829+00:00",
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
      "invoked_at": "2026-04-28T18:48:22.737654+00:00",
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
      "newly_loaded_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "snapshot_after": {
        "captured_at": "2026-04-28T18:48:22.737633+00:00",
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
      "captured_at": "2026-04-28T18:48:22.653673+00:00",
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "loaded_bpf_modules": [],
      "missing_expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_rotate",
        "bpf_select"
      ],
      "raw_output": "",
      "resident_expected_modules": [],
      "source": "lsmod"
    }
  },
  "manifest": "/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml",
  "per_program": [
    {
      "app": "bcc/capable",
      "baseline_avg_ns_per_run": 1324.6018846342392,
      "baseline_run_cnt_delta": 18359,
      "baseline_run_time_ns_delta": 24318366,
      "post_rejit_avg_ns_per_run": 1685.0626613213246,
      "post_rejit_run_cnt_delta": 18209,
      "post_rejit_run_time_ns_delta": 30683306,
      "program": "cap_capable",
      "program_id": 79,
      "ratio": 1.2721276338713794,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 495.3333333333333,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 4458,
      "post_rejit_avg_ns_per_run": 515.7777777777778,
      "post_rejit_run_cnt_delta": 9,
      "post_rejit_run_time_ns_delta": 4642,
      "program": "syscall__execve",
      "program_id": 82,
      "ratio": 1.0412741139524453,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 324.44444444444446,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 2920,
      "post_rejit_avg_ns_per_run": 308.44444444444446,
      "post_rejit_run_cnt_delta": 9,
      "post_rejit_run_time_ns_delta": 2776,
      "program": "do_ret_sys_exec",
      "program_id": 83,
      "ratio": 0.9506849315068493,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 850.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1700,
      "post_rejit_avg_ns_per_run": 1102.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 2204,
      "program": "bindsnoop_entry",
      "program_id": 86,
      "ratio": 1.296470588235294,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 12393.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 24786,
      "post_rejit_avg_ns_per_run": 10798.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 21596,
      "program": "bindsnoop_v4_re",
      "program_id": 87,
      "ratio": 0.8712983135641088,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 588.4340689655172,
      "baseline_run_cnt_delta": 21750,
      "baseline_run_time_ns_delta": 12798441,
      "post_rejit_avg_ns_per_run": 627.5281657946869,
      "post_rejit_run_cnt_delta": 19687,
      "post_rejit_run_time_ns_delta": 12354147,
      "program": "trace_pid_start",
      "program_id": 91,
      "ratio": 1.0664375142280564,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 696.556,
      "baseline_run_cnt_delta": 21750,
      "baseline_run_time_ns_delta": 15150093,
      "post_rejit_avg_ns_per_run": 682.2908010362167,
      "post_rejit_run_cnt_delta": 19687,
      "post_rejit_run_time_ns_delta": 13432259,
      "program": "trace_req_start",
      "program_id": 92,
      "ratio": 0.9795203846298313,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 319.97974849755064,
      "baseline_run_cnt_delta": 19801,
      "baseline_run_time_ns_delta": 6335919,
      "post_rejit_avg_ns_per_run": 341.53112500704185,
      "post_rejit_run_cnt_delta": 17751,
      "post_rejit_run_time_ns_delta": 6062519,
      "program": "trace_req_compl",
      "program_id": 93,
      "ratio": 1.067352314047013,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 59.83938164674926,
      "baseline_run_cnt_delta": 18242,
      "baseline_run_time_ns_delta": 1091590,
      "post_rejit_avg_ns_per_run": 60.85224028113332,
      "post_rejit_run_cnt_delta": 18212,
      "post_rejit_run_time_ns_delta": 1108241,
      "program": "vfs_open",
      "program_id": 98,
      "ratio": 1.0169262884493573,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 73.32021492884112,
      "baseline_run_cnt_delta": 41316,
      "baseline_run_time_ns_delta": 3029298,
      "post_rejit_avg_ns_per_run": 67.99748714690081,
      "post_rejit_run_cnt_delta": 34622,
      "post_rejit_run_time_ns_delta": 2354209,
      "program": "vfs_read",
      "program_id": 99,
      "ratio": 0.9274043619879437,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 55.95169287118099,
      "baseline_run_cnt_delta": 89552,
      "baseline_run_time_ns_delta": 5010586,
      "post_rejit_avg_ns_per_run": 67.49880753637014,
      "post_rejit_run_cnt_delta": 83860,
      "post_rejit_run_time_ns_delta": 5660450,
      "program": "vfs_write",
      "program_id": 100,
      "ratio": 1.2063765021690116,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 1860.9611650485438,
      "baseline_run_cnt_delta": 103,
      "baseline_run_time_ns_delta": 191679,
      "post_rejit_avg_ns_per_run": 2175.705263157895,
      "post_rejit_run_cnt_delta": 95,
      "post_rejit_run_time_ns_delta": 206692,
      "program": "__x64_sys_open",
      "program_id": 103,
      "ratio": 1.1691298582800576,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 2327.906302420321,
      "baseline_run_cnt_delta": 16692,
      "baseline_run_time_ns_delta": 38857412,
      "post_rejit_avg_ns_per_run": 2192.065546790761,
      "post_rejit_run_cnt_delta": 17621,
      "post_rejit_run_time_ns_delta": 38626387,
      "program": "__x64_sys_opena",
      "program_id": 104,
      "ratio": 0.9416468113478937,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 2625.285714285714,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 36754,
      "post_rejit_avg_ns_per_run": 2908.5555555555557,
      "post_rejit_run_cnt_delta": 18,
      "post_rejit_run_time_ns_delta": 52354,
      "program": "__x64_sys_opena",
      "program_id": 105,
      "ratio": 1.107900576203346,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 206.79133855641496,
      "baseline_run_cnt_delta": 599646,
      "baseline_run_time_ns_delta": 124001599,
      "post_rejit_avg_ns_per_run": 222.42866225705262,
      "post_rejit_run_cnt_delta": 569362,
      "post_rejit_run_time_ns_delta": 126642428,
      "program": "raw_syscalls__s",
      "program_id": 108,
      "ratio": 1.0756188523649004,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 181.74377378502507,
      "baseline_run_cnt_delta": 599642,
      "baseline_run_time_ns_delta": 108981200,
      "post_rejit_avg_ns_per_run": 156.22626915477497,
      "post_rejit_run_cnt_delta": 569375,
      "post_rejit_run_time_ns_delta": 88951332,
      "program": "raw_syscalls__s",
      "program_id": 109,
      "ratio": 0.8595962651219436,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 1134.625,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 9077,
      "post_rejit_avg_ns_per_run": 1144.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1144,
      "program": "trace_connect_e",
      "program_id": 112,
      "ratio": 1.0082626418420182,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 10029.25,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 80234,
      "post_rejit_avg_ns_per_run": 8505.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 8505,
      "program": "trace_connect_v",
      "program_id": 113,
      "ratio": 0.8480195428372012,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 1458.25,
      "baseline_run_cnt_delta": 36,
      "baseline_run_time_ns_delta": 52497,
      "post_rejit_avg_ns_per_run": 87.99698976520169,
      "post_rejit_run_cnt_delta": 1661,
      "post_rejit_run_time_ns_delta": 146163,
      "program": "sock__inet_sock",
      "program_id": 117,
      "ratio": 0.060344241224208256,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 470.7020073868702,
      "baseline_run_cnt_delta": 102073,
      "baseline_run_time_ns_delta": 48045966,
      "post_rejit_avg_ns_per_run": 494.02495248934366,
      "post_rejit_run_cnt_delta": 93137,
      "post_rejit_run_time_ns_delta": 46012002,
      "program": "sched_switch",
      "program_id": 120,
      "ratio": 1.0495492790267715,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 365.8127562311795,
      "baseline_run_cnt_delta": 55126,
      "baseline_run_time_ns_delta": 20165794,
      "post_rejit_avg_ns_per_run": 375.15634957215286,
      "post_rejit_run_cnt_delta": 49901,
      "post_rejit_run_time_ns_delta": 18720677,
      "program": "sched_wakeup",
      "program_id": 121,
      "ratio": 1.0255420107194637,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 478.0081466395112,
      "baseline_run_cnt_delta": 491,
      "baseline_run_time_ns_delta": 234702,
      "post_rejit_avg_ns_per_run": 563.5282258064516,
      "post_rejit_run_cnt_delta": 496,
      "post_rejit_run_time_ns_delta": 279510,
      "program": "sched_wakeup_ne",
      "program_id": 122,
      "ratio": 1.1789092503300684,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 10537.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 10537,
      "post_rejit_avg_ns_per_run": 12144.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 24288,
      "program": "tracepoint__sch",
      "program_id": 204,
      "ratio": 1.152510202144823,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 28460.796812749006,
      "baseline_run_cnt_delta": 251,
      "baseline_run_time_ns_delta": 7143660,
      "post_rejit_avg_ns_per_run": 28291.882845188284,
      "post_rejit_run_cnt_delta": 239,
      "post_rejit_run_time_ns_delta": 6761760,
      "program": "native_tracer_e",
      "program_id": 205,
      "ratio": 0.9940650302705138,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1503.6451612903227,
      "baseline_run_cnt_delta": 186,
      "baseline_run_time_ns_delta": 279678,
      "post_rejit_avg_ns_per_run": 1597.3013698630136,
      "post_rejit_run_cnt_delta": 146,
      "post_rejit_run_time_ns_delta": 233206,
      "program": "event_exit_acct",
      "program_id": 300,
      "ratio": 1.0622861104360033,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4564.489898989899,
      "baseline_run_cnt_delta": 198,
      "baseline_run_time_ns_delta": 903769,
      "post_rejit_avg_ns_per_run": 4676.697986577181,
      "post_rejit_run_cnt_delta": 149,
      "post_rejit_run_time_ns_delta": 696828,
      "program": "event_wake_up_n",
      "program_id": 302,
      "ratio": 1.0245828318323396,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 9078.253333333334,
      "baseline_run_cnt_delta": 75,
      "baseline_run_time_ns_delta": 680869,
      "post_rejit_avg_ns_per_run": 9877.076923076924,
      "post_rejit_run_cnt_delta": 52,
      "post_rejit_run_time_ns_delta": 513608,
      "program": "event_execve",
      "program_id": 303,
      "ratio": 1.0879930929896489,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 894.04,
      "baseline_run_cnt_delta": 75,
      "baseline_run_time_ns_delta": 67053,
      "post_rejit_avg_ns_per_run": 994.3461538461538,
      "post_rejit_run_cnt_delta": 52,
      "post_rejit_run_time_ns_delta": 51706,
      "program": "tg_kp_bprm_comm",
      "program_id": 306,
      "ratio": 1.1121942573555477,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1692.7201090541314,
      "baseline_run_cnt_delta": 22741,
      "baseline_run_time_ns_delta": 38494148,
      "post_rejit_avg_ns_per_run": 1678.3940268485724,
      "post_rejit_run_cnt_delta": 22869,
      "post_rejit_run_time_ns_delta": 38383193,
      "program": "generic_kprobe_",
      "program_id": 331,
      "ratio": 0.9915366503127536,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 161.85642671826216,
      "baseline_run_cnt_delta": 22741,
      "baseline_run_time_ns_delta": 3680777,
      "post_rejit_avg_ns_per_run": 199.37098255280074,
      "post_rejit_run_cnt_delta": 22869,
      "post_rejit_run_time_ns_delta": 4559415,
      "program": "generic_retkprobe_event",
      "program_id": 340,
      "ratio": 1.2317767455711774,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1952.2279379546053,
      "baseline_run_cnt_delta": 22822,
      "baseline_run_time_ns_delta": 44553746,
      "post_rejit_avg_ns_per_run": 2043.4322372662798,
      "post_rejit_run_cnt_delta": 23265,
      "post_rejit_run_time_ns_delta": 47540451,
      "program": "generic_kprobe_",
      "program_id": 342,
      "ratio": 1.046718058654171,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2724.2309214431766,
      "baseline_run_cnt_delta": 15161,
      "baseline_run_time_ns_delta": 41302065,
      "post_rejit_avg_ns_per_run": 2474.7859544442867,
      "post_rejit_run_cnt_delta": 21117,
      "post_rejit_run_time_ns_delta": 52260055,
      "program": "generic_kprobe_",
      "program_id": 352,
      "ratio": 0.9084347200395387,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1703.5393782155577,
      "baseline_run_cnt_delta": 22741,
      "baseline_run_time_ns_delta": 38740189,
      "post_rejit_avg_ns_per_run": 1669.7856486947396,
      "post_rejit_run_cnt_delta": 22869,
      "post_rejit_run_time_ns_delta": 38186328,
      "program": "generic_kprobe_",
      "program_id": 359,
      "ratio": 0.9801861172377625,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 151.90448968822832,
      "baseline_run_cnt_delta": 22741,
      "baseline_run_time_ns_delta": 3454460,
      "post_rejit_avg_ns_per_run": 185.48126284489922,
      "post_rejit_run_cnt_delta": 22869,
      "post_rejit_run_time_ns_delta": 4241771,
      "program": "generic_retkprobe_event",
      "program_id": 365,
      "ratio": 1.221038714692268,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2264.49557444571,
      "baseline_run_cnt_delta": 22822,
      "baseline_run_time_ns_delta": 51680318,
      "post_rejit_avg_ns_per_run": 2353.6801633354826,
      "post_rejit_run_cnt_delta": 23265,
      "post_rejit_run_time_ns_delta": 54758369,
      "program": "generic_kprobe_",
      "program_id": 373,
      "ratio": 1.039383865394218,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2897.4599186755736,
      "baseline_run_cnt_delta": 6886,
      "baseline_run_time_ns_delta": 19951909,
      "post_rejit_avg_ns_per_run": 2727.0770572542583,
      "post_rejit_run_cnt_delta": 9746,
      "post_rejit_run_time_ns_delta": 26578093,
      "program": "generic_kprobe_",
      "program_id": 380,
      "ratio": 0.9411957831329736,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2966.9431749486157,
      "baseline_run_cnt_delta": 8271,
      "baseline_run_time_ns_delta": 24539587,
      "post_rejit_avg_ns_per_run": 2730.1125670565475,
      "post_rejit_run_cnt_delta": 11371,
      "post_rejit_run_time_ns_delta": 31044110,
      "program": "generic_kprobe_",
      "program_id": 381,
      "ratio": 0.92017689792924,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1069.5141758216448,
      "baseline_run_cnt_delta": 43419,
      "baseline_run_time_ns_delta": 46437236,
      "post_rejit_avg_ns_per_run": 1066.622031014069,
      "post_rejit_run_cnt_delta": 41723,
      "post_rejit_run_time_ns_delta": 44502671,
      "program": "generic_kprobe_",
      "program_id": 404,
      "ratio": 0.9972958331240875,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2460.2121023691293,
      "baseline_run_cnt_delta": 112573,
      "baseline_run_time_ns_delta": 276953457,
      "post_rejit_avg_ns_per_run": 2552.8581168624287,
      "post_rejit_run_cnt_delta": 94162,
      "post_rejit_run_time_ns_delta": 240382226,
      "program": "generic_kprobe_",
      "program_id": 415,
      "ratio": 1.037657734633564,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 130.56214084607117,
      "baseline_run_cnt_delta": 112591,
      "baseline_run_time_ns_delta": 14700122,
      "post_rejit_avg_ns_per_run": 145.69743910984647,
      "post_rejit_run_cnt_delta": 94186,
      "post_rejit_run_time_ns_delta": 13722659,
      "program": "generic_retkprobe_event",
      "program_id": 417,
      "ratio": 1.11592409687598,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7506.705710955711,
      "baseline_run_cnt_delta": 6864,
      "baseline_run_time_ns_delta": 51526028,
      "post_rejit_avg_ns_per_run": 8699.976841306,
      "post_rejit_run_cnt_delta": 5268,
      "post_rejit_run_time_ns_delta": 45831478,
      "program": "generic_kprobe_",
      "program_id": 421,
      "ratio": 1.1589606914533443,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 189.99825174825176,
      "baseline_run_cnt_delta": 6864,
      "baseline_run_time_ns_delta": 1304148,
      "post_rejit_avg_ns_per_run": 183.47456340167045,
      "post_rejit_run_cnt_delta": 5268,
      "post_rejit_run_time_ns_delta": 966544,
      "program": "generic_retkprobe_event",
      "program_id": 429,
      "ratio": 0.9656644822436302,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6768.12,
      "baseline_run_cnt_delta": 75,
      "baseline_run_time_ns_delta": 507609,
      "post_rejit_avg_ns_per_run": 6580.823529411765,
      "post_rejit_run_cnt_delta": 51,
      "post_rejit_run_time_ns_delta": 335622,
      "program": "generic_kprobe_",
      "program_id": 478,
      "ratio": 0.9723266622654098,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1471.2525576000367,
      "baseline_run_cnt_delta": 1723393,
      "baseline_run_time_ns_delta": 2535546359,
      "post_rejit_avg_ns_per_run": 1563.3663323336486,
      "post_rejit_run_cnt_delta": 1558825,
      "post_rejit_run_time_ns_delta": 2437014523,
      "program": "generic_tracepo",
      "program_id": 487,
      "ratio": 1.06260908384341,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6180.08,
      "baseline_run_cnt_delta": 75,
      "baseline_run_time_ns_delta": 463506,
      "post_rejit_avg_ns_per_run": 6213.254901960784,
      "post_rejit_run_cnt_delta": 51,
      "post_rejit_run_time_ns_delta": 316876,
      "program": "generic_rawtp_e",
      "program_id": 497,
      "ratio": 1.0053680376242353,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4106.099706744868,
      "baseline_run_cnt_delta": 1364,
      "baseline_run_time_ns_delta": 5600720,
      "post_rejit_avg_ns_per_run": 4756.87648673376,
      "post_rejit_run_cnt_delta": 1093,
      "post_rejit_run_time_ns_delta": 5199266,
      "program": "generic_kprobe_",
      "program_id": 503,
      "ratio": 1.158490252664809,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 11067.75225121219,
      "baseline_run_cnt_delta": 4331,
      "baseline_run_time_ns_delta": 47934435,
      "post_rejit_avg_ns_per_run": 11317.322091062395,
      "post_rejit_run_cnt_delta": 3558,
      "post_rejit_run_time_ns_delta": 40267032,
      "program": "generic_kprobe_",
      "program_id": 506,
      "ratio": 1.0225492795813955,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1834.7840809146878,
      "baseline_run_cnt_delta": 22740,
      "baseline_run_time_ns_delta": 41722990,
      "post_rejit_avg_ns_per_run": 1755.9608023474796,
      "post_rejit_run_cnt_delta": 22833,
      "post_rejit_run_time_ns_delta": 40093853,
      "program": "generic_kprobe_",
      "program_id": 525,
      "ratio": 0.9570394798019434,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 154.71402814423922,
      "baseline_run_cnt_delta": 22740,
      "baseline_run_time_ns_delta": 3518197,
      "post_rejit_avg_ns_per_run": 193.26558051942365,
      "post_rejit_run_cnt_delta": 22833,
      "post_rejit_run_time_ns_delta": 4412833,
      "program": "generic_retkprobe_event",
      "program_id": 529,
      "ratio": 1.2491794237251905,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2303.780509180141,
      "baseline_run_cnt_delta": 22821,
      "baseline_run_time_ns_delta": 52574575,
      "post_rejit_avg_ns_per_run": 2416.485944293771,
      "post_rejit_run_cnt_delta": 23229,
      "post_rejit_run_time_ns_delta": 56132552,
      "program": "generic_kprobe_",
      "program_id": 531,
      "ratio": 1.0489219501009404,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4698.074074074074,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 253696,
      "post_rejit_avg_ns_per_run": 4830.379310344828,
      "post_rejit_run_cnt_delta": 29,
      "post_rejit_run_time_ns_delta": 140081,
      "program": "generic_kprobe_",
      "program_id": 538,
      "ratio": 1.0281615900866419,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7783.285714285715,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 108966,
      "post_rejit_avg_ns_per_run": 7596.0,
      "post_rejit_run_cnt_delta": 8,
      "post_rejit_run_time_ns_delta": 60768,
      "program": "generic_kprobe_",
      "program_id": 547,
      "ratio": 0.9759374483783932,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5745.75,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 22983,
      "post_rejit_avg_ns_per_run": 5833.666666666667,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 17501,
      "program": "generic_kprobe_",
      "program_id": 554,
      "ratio": 1.0153011646289287,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3479.75,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 13919,
      "post_rejit_avg_ns_per_run": 3029.0,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 9087,
      "program": "generic_retkprobe_event",
      "program_id": 561,
      "ratio": 0.8704648322436956,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 8123.6,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 81236,
      "post_rejit_avg_ns_per_run": 9282.5,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 37130,
      "program": "generic_kprobe_",
      "program_id": 566,
      "ratio": 1.142658427298242,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7266.857142857143,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 101736,
      "post_rejit_avg_ns_per_run": 8155.375,
      "post_rejit_run_cnt_delta": 8,
      "post_rejit_run_time_ns_delta": 65243,
      "program": "generic_kprobe_",
      "program_id": 575,
      "ratio": 1.1222698946292364,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1892.4216202445652,
      "baseline_run_cnt_delta": 23552,
      "baseline_run_time_ns_delta": 44570314,
      "post_rejit_avg_ns_per_run": 1983.0793507664562,
      "post_rejit_run_cnt_delta": 19962,
      "post_rejit_run_time_ns_delta": 39586230,
      "program": "generic_kprobe_",
      "program_id": 582,
      "ratio": 1.0479056725795464,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 88.36848958333333,
      "baseline_run_cnt_delta": 1536,
      "baseline_run_time_ns_delta": 135734,
      "post_rejit_avg_ns_per_run": 79.875,
      "post_rejit_run_cnt_delta": 1536,
      "post_rejit_run_time_ns_delta": 122688,
      "program": "balancer_ingress",
      "program_id": 602,
      "ratio": 0.9038855408372258,
      "runner": "katran",
      "type": "xdp",
      "workload": "test_run"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 709.1299703639855,
      "baseline_run_cnt_delta": 1389863,
      "baseline_run_time_ns_delta": 985593508,
      "post_rejit_avg_ns_per_run": 743.8585039783546,
      "post_rejit_run_cnt_delta": 1197857,
      "post_rejit_run_time_ns_delta": 891036116,
      "program": "tracepoint__raw",
      "program_id": 619,
      "ratio": 1.048973439377472,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1636.2060805268293,
      "baseline_run_cnt_delta": 1389748,
      "baseline_run_time_ns_delta": 2273914128,
      "post_rejit_avg_ns_per_run": 1726.6723031826843,
      "post_rejit_run_cnt_delta": 1199145,
      "post_rejit_run_time_ns_delta": 2070530459,
      "program": "tracepoint__raw",
      "program_id": 622,
      "ratio": 1.0552902374172368,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1285.497967659496,
      "baseline_run_cnt_delta": 1390269,
      "baseline_run_time_ns_delta": 1787187974,
      "post_rejit_avg_ns_per_run": 1316.4598770220382,
      "post_rejit_run_cnt_delta": 1198914,
      "post_rejit_run_time_ns_delta": 1578322177,
      "program": "trace_sys_enter",
      "program_id": 625,
      "ratio": 1.024085537388219,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1287.9213486136125,
      "baseline_run_cnt_delta": 1390376,
      "baseline_run_time_ns_delta": 1790694933,
      "post_rejit_avg_ns_per_run": 1318.857265609684,
      "post_rejit_run_cnt_delta": 1198695,
      "post_rejit_run_time_ns_delta": 1580907610,
      "program": "trace_sys_exit",
      "program_id": 626,
      "ratio": 1.0240200358735978,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 187.94213866819436,
      "baseline_run_cnt_delta": 66331,
      "baseline_run_time_ns_delta": 12466390,
      "post_rejit_avg_ns_per_run": 192.4527535755384,
      "post_rejit_run_cnt_delta": 60830,
      "post_rejit_run_time_ns_delta": 11706901,
      "program": "trace_arch_prct",
      "program_id": 631,
      "ratio": 1.0240000190447305,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 752.6357811581312,
      "baseline_run_cnt_delta": 66331,
      "baseline_run_time_ns_delta": 49923084,
      "post_rejit_avg_ns_per_run": 780.77249712313,
      "post_rejit_run_cnt_delta": 60830,
      "post_rejit_run_time_ns_delta": 47494391,
      "program": "trace_ret_arch_",
      "program_id": 632,
      "ratio": 1.0373842390561117,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1203.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 2407,
      "post_rejit_avg_ns_per_run": 764.8,
      "post_rejit_run_cnt_delta": 20,
      "post_rejit_run_time_ns_delta": 15296,
      "program": "trace_dup",
      "program_id": 633,
      "ratio": 0.6354798504362277,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5562.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 11124,
      "post_rejit_avg_ns_per_run": 4999.35,
      "post_rejit_run_cnt_delta": 20,
      "post_rejit_run_time_ns_delta": 99987,
      "program": "trace_ret_dup",
      "program_id": 634,
      "ratio": 0.8988403451995686,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 872.0898876404494,
      "baseline_run_cnt_delta": 89,
      "baseline_run_time_ns_delta": 77616,
      "post_rejit_avg_ns_per_run": 944.72,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 47236,
      "program": "trace_dup2",
      "program_id": 635,
      "ratio": 1.0832828282828284,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3091.438202247191,
      "baseline_run_cnt_delta": 89,
      "baseline_run_time_ns_delta": 275138,
      "post_rejit_avg_ns_per_run": 4471.62,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 223581,
      "program": "trace_ret_dup2",
      "program_id": 636,
      "ratio": 1.4464529799591477,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 638.9444444444445,
      "baseline_run_cnt_delta": 36,
      "baseline_run_time_ns_delta": 23002,
      "post_rejit_avg_ns_per_run": 1029.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 2058,
      "program": "trace_dup3",
      "program_id": 637,
      "ratio": 1.610468654899574,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3015.8611111111113,
      "baseline_run_cnt_delta": 36,
      "baseline_run_time_ns_delta": 108571,
      "post_rejit_avg_ns_per_run": 4943.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 9887,
      "program": "trace_ret_dup3",
      "program_id": 638,
      "ratio": 1.639166996711829,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 8086.132450331126,
      "baseline_run_cnt_delta": 302,
      "baseline_run_time_ns_delta": 2442012,
      "post_rejit_avg_ns_per_run": 21157.419795221842,
      "post_rejit_run_cnt_delta": 293,
      "post_rejit_run_time_ns_delta": 6199124,
      "program": "tracepoint__sch",
      "program_id": 644,
      "ratio": 2.616506707648036,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 9867.972972972973,
      "baseline_run_cnt_delta": 37,
      "baseline_run_time_ns_delta": 365115,
      "post_rejit_avg_ns_per_run": 10435.714285714286,
      "post_rejit_run_cnt_delta": 42,
      "post_rejit_run_time_ns_delta": 438300,
      "program": "tracepoint__sch",
      "program_id": 652,
      "ratio": 1.0575337320335472,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 6437.602649006622,
      "baseline_run_cnt_delta": 302,
      "baseline_run_time_ns_delta": 1944156,
      "post_rejit_avg_ns_per_run": 47957.20136518771,
      "post_rejit_run_cnt_delta": 293,
      "post_rejit_run_time_ns_delta": 14051460,
      "program": "tracepoint__sch",
      "program_id": 654,
      "ratio": 7.449543561466616,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2292.2615894039736,
      "baseline_run_cnt_delta": 302,
      "baseline_run_time_ns_delta": 692263,
      "post_rejit_avg_ns_per_run": 2600.0819112627987,
      "post_rejit_run_cnt_delta": 293,
      "post_rejit_run_time_ns_delta": 761824,
      "program": "tracepoint__sch",
      "program_id": 655,
      "ratio": 1.1342867338011207,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1746.6175895338718,
      "baseline_run_cnt_delta": 213718,
      "baseline_run_time_ns_delta": 373283618,
      "post_rejit_avg_ns_per_run": 1742.9493912026771,
      "post_rejit_run_cnt_delta": 198424,
      "post_rejit_run_time_ns_delta": 345842990,
      "program": "tracepoint__sch",
      "program_id": 657,
      "ratio": 0.9978998274418079,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 50.87291342087692,
      "baseline_run_cnt_delta": 4493,
      "baseline_run_time_ns_delta": 228572,
      "post_rejit_avg_ns_per_run": 47.74913416654118,
      "post_rejit_run_cnt_delta": 6641,
      "post_rejit_run_time_ns_delta": 317102,
      "program": "trace_filldir64",
      "program_id": 658,
      "ratio": 0.9385964151788913,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2562.655629139073,
      "baseline_run_cnt_delta": 302,
      "baseline_run_time_ns_delta": 773922,
      "post_rejit_avg_ns_per_run": 2452.279863481229,
      "post_rejit_run_cnt_delta": 293,
      "post_rejit_run_time_ns_delta": 718518,
      "program": "trace_do_exit",
      "program_id": 660,
      "ratio": 0.9569291463110379,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 714.8359375,
      "baseline_run_cnt_delta": 1408,
      "baseline_run_time_ns_delta": 1006489,
      "post_rejit_avg_ns_per_run": 2136.946808510638,
      "post_rejit_run_cnt_delta": 282,
      "post_rejit_run_time_ns_delta": 602619,
      "program": "trace_security_",
      "program_id": 664,
      "ratio": 2.989422742208786,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5058.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 5058,
      "post_rejit_avg_ns_per_run": 4395.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 8791,
      "program": "tracepoint__cgr",
      "program_id": 666,
      "ratio": 0.8690193752471332,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3962.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 3962,
      "post_rejit_avg_ns_per_run": 3800.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 3800,
      "program": "tracepoint__cgr",
      "program_id": 667,
      "ratio": 0.9591115598182736,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2905.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2905,
      "post_rejit_avg_ns_per_run": 2312.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2312,
      "program": "tracepoint__cgr",
      "program_id": 668,
      "ratio": 0.7958691910499139,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5949.55,
      "baseline_run_cnt_delta": 40,
      "baseline_run_time_ns_delta": 237982,
      "post_rejit_avg_ns_per_run": 6848.627906976744,
      "post_rejit_run_cnt_delta": 43,
      "post_rejit_run_time_ns_delta": 294491,
      "program": "trace_security_",
      "program_id": 669,
      "ratio": 1.151116959598078,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3381.791415839262,
      "baseline_run_cnt_delta": 12791,
      "baseline_run_time_ns_delta": 43256494,
      "post_rejit_avg_ns_per_run": 3349.202287403719,
      "post_rejit_run_cnt_delta": 12853,
      "post_rejit_run_time_ns_delta": 43047297,
      "program": "trace_security_file_open",
      "program_id": 670,
      "ratio": 0.9903633534927951,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3879.6,
      "baseline_run_cnt_delta": 5,
      "baseline_run_time_ns_delta": 19398,
      "post_rejit_avg_ns_per_run": 4160.0,
      "post_rejit_run_cnt_delta": 11,
      "post_rejit_run_time_ns_delta": 45760,
      "program": "trace_security_",
      "program_id": 672,
      "ratio": 1.0722754923187958,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1454.6022637795274,
      "baseline_run_cnt_delta": 10160,
      "baseline_run_time_ns_delta": 14778759,
      "post_rejit_avg_ns_per_run": 1458.6916321294652,
      "post_rejit_run_cnt_delta": 10134,
      "post_rejit_run_time_ns_delta": 14782381,
      "program": "trace_commit_cr",
      "program_id": 673,
      "ratio": 1.0028113309402615,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1484.0662251655629,
      "baseline_run_cnt_delta": 302,
      "baseline_run_time_ns_delta": 448188,
      "post_rejit_avg_ns_per_run": 1426.938775510204,
      "post_rejit_run_cnt_delta": 294,
      "post_rejit_run_time_ns_delta": 419520,
      "program": "trace_switch_ta",
      "program_id": 674,
      "ratio": 0.9615061318109401,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 979.9697256385998,
      "baseline_run_cnt_delta": 46508,
      "baseline_run_time_ns_delta": 45576432,
      "post_rejit_avg_ns_per_run": 967.9136491557223,
      "post_rejit_run_cnt_delta": 42640,
      "post_rejit_run_time_ns_delta": 41271838,
      "program": "trace_cap_capab",
      "program_id": 675,
      "ratio": 0.9876975010885962,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3227.8342696629215,
      "baseline_run_cnt_delta": 356,
      "baseline_run_time_ns_delta": 1149109,
      "post_rejit_avg_ns_per_run": 3398.776556776557,
      "post_rejit_run_cnt_delta": 273,
      "post_rejit_run_time_ns_delta": 927866,
      "program": "trace_security_",
      "program_id": 676,
      "ratio": 1.052958817842741,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3857.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 3857,
      "post_rejit_avg_ns_per_run": 4537.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 4537,
      "program": "trace_security_",
      "program_id": 677,
      "ratio": 1.1763028260305937,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3511.7638888888887,
      "baseline_run_cnt_delta": 288,
      "baseline_run_time_ns_delta": 1011388,
      "post_rejit_avg_ns_per_run": 3399.5222222222224,
      "post_rejit_run_cnt_delta": 270,
      "post_rejit_run_time_ns_delta": 917871,
      "program": "trace_security_",
      "program_id": 682,
      "ratio": 0.9680383789406243,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5394.830409356725,
      "baseline_run_cnt_delta": 171,
      "baseline_run_time_ns_delta": 922516,
      "post_rejit_avg_ns_per_run": 5709.02027027027,
      "post_rejit_run_cnt_delta": 148,
      "post_rejit_run_time_ns_delta": 844935,
      "program": "trace_security_",
      "program_id": 683,
      "ratio": 1.0582390616707094,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1772.5641025641025,
      "baseline_run_cnt_delta": 39,
      "baseline_run_time_ns_delta": 69130,
      "post_rejit_avg_ns_per_run": 1709.0,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 5127,
      "program": "trace_security_",
      "program_id": 684,
      "ratio": 0.9641400260378996,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3820.3502304147464,
      "baseline_run_cnt_delta": 217,
      "baseline_run_time_ns_delta": 829016,
      "post_rejit_avg_ns_per_run": 3204.984555984556,
      "post_rejit_run_cnt_delta": 259,
      "post_rejit_run_time_ns_delta": 830091,
      "program": "trace_security_",
      "program_id": 685,
      "ratio": 0.83892427727408,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 250.70566746686148,
      "baseline_run_cnt_delta": 76648,
      "baseline_run_time_ns_delta": 19216088,
      "post_rejit_avg_ns_per_run": 242.4379140201183,
      "post_rejit_run_cnt_delta": 73366,
      "post_rejit_run_time_ns_delta": 17786700,
      "program": "trace_vfs_write",
      "program_id": 688,
      "ratio": 0.9670220720166367,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 137.11229269692976,
      "baseline_run_cnt_delta": 76639,
      "baseline_run_time_ns_delta": 10508149,
      "post_rejit_avg_ns_per_run": 159.32001308846986,
      "post_rejit_run_cnt_delta": 73347,
      "post_rejit_run_time_ns_delta": 11685645,
      "program": "vfs_write_magic",
      "program_id": 689,
      "ratio": 1.1619673915060817,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2104.8270974982706,
      "baseline_run_cnt_delta": 76627,
      "baseline_run_time_ns_delta": 161286586,
      "post_rejit_avg_ns_per_run": 214.0644061788485,
      "post_rejit_run_cnt_delta": 73347,
      "post_rejit_run_time_ns_delta": 15700982,
      "program": "trace_ret_vfs_w",
      "program_id": 690,
      "ratio": 0.1017016582660298,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 117.36874779909486,
      "baseline_run_cnt_delta": 76673,
      "baseline_run_time_ns_delta": 8999014,
      "post_rejit_avg_ns_per_run": 121.18335582178244,
      "post_rejit_run_cnt_delta": 73371,
      "post_rejit_run_time_ns_delta": 8891344,
      "program": "vfs_write_magic",
      "program_id": 691,
      "ratio": 1.0325010541069861,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 265.6067175751192,
      "baseline_run_cnt_delta": 34179,
      "baseline_run_time_ns_delta": 9078172,
      "post_rejit_avg_ns_per_run": 264.59189732488016,
      "post_rejit_run_cnt_delta": 32335,
      "post_rejit_run_time_ns_delta": 8555579,
      "program": "trace_vfs_read",
      "program_id": 703,
      "ratio": 0.9961792372591178,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2825.652811072414,
      "baseline_run_cnt_delta": 22109,
      "baseline_run_time_ns_delta": 62472358,
      "post_rejit_avg_ns_per_run": 1350.662632656861,
      "post_rejit_run_cnt_delta": 10742,
      "post_rejit_run_time_ns_delta": 14508818,
      "program": "trace_ret_vfs_r",
      "program_id": 704,
      "ratio": 0.4780002084347535,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 715.5805904309467,
      "baseline_run_cnt_delta": 2947,
      "baseline_run_time_ns_delta": 2108816,
      "post_rejit_avg_ns_per_run": 636.7366283006094,
      "post_rejit_run_cnt_delta": 2954,
      "post_rejit_run_time_ns_delta": 1880920,
      "program": "trace_mmap_aler",
      "program_id": 709,
      "ratio": 0.8898181935275036,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 242.09991039426524,
      "baseline_run_cnt_delta": 2232,
      "baseline_run_time_ns_delta": 540367,
      "post_rejit_avg_ns_per_run": 217.281654676259,
      "post_rejit_run_cnt_delta": 2780,
      "post_rejit_run_time_ns_delta": 604043,
      "program": "trace_do_mmap",
      "program_id": 710,
      "ratio": 0.89748754686613,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2707.0631720430106,
      "baseline_run_cnt_delta": 2232,
      "baseline_run_time_ns_delta": 6042165,
      "post_rejit_avg_ns_per_run": 336.78489208633096,
      "post_rejit_run_cnt_delta": 2780,
      "post_rejit_run_time_ns_delta": 936262,
      "program": "trace_ret_do_mm",
      "program_id": 711,
      "ratio": 0.12440969075433901,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2807.2347670250897,
      "baseline_run_cnt_delta": 2232,
      "baseline_run_time_ns_delta": 6265748,
      "post_rejit_avg_ns_per_run": 2800.4172661870502,
      "post_rejit_run_cnt_delta": 2780,
      "post_rejit_run_time_ns_delta": 7785160,
      "program": "trace_security_mmap_file",
      "program_id": 712,
      "ratio": 0.9975714532613658,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3737.675294117647,
      "baseline_run_cnt_delta": 425,
      "baseline_run_time_ns_delta": 1588512,
      "post_rejit_avg_ns_per_run": 3761.8758029978585,
      "post_rejit_run_cnt_delta": 467,
      "post_rejit_run_time_ns_delta": 1756796,
      "program": "trace_security_file_mprotect",
      "program_id": 713,
      "ratio": 1.0064747488681798,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1694.3406294164283,
      "baseline_run_cnt_delta": 29011,
      "baseline_run_time_ns_delta": 49154516,
      "post_rejit_avg_ns_per_run": 1642.2311915339328,
      "post_rejit_run_cnt_delta": 27687,
      "post_rejit_run_time_ns_delta": 45468455,
      "program": "trace_security_",
      "program_id": 715,
      "ratio": 0.9692450048250077,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1592.9613930034668,
      "baseline_run_cnt_delta": 6346,
      "baseline_run_time_ns_delta": 10108933,
      "post_rejit_avg_ns_per_run": 1531.3547549496916,
      "post_rejit_run_cnt_delta": 6162,
      "post_rejit_run_time_ns_delta": 9436208,
      "program": "trace_security_",
      "program_id": 718,
      "ratio": 0.9613257180466764,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5100.641263940521,
      "baseline_run_cnt_delta": 538,
      "baseline_run_time_ns_delta": 2744145,
      "post_rejit_avg_ns_per_run": 4644.953445065177,
      "post_rejit_run_cnt_delta": 537,
      "post_rejit_run_time_ns_delta": 2494340,
      "program": "trace_security_",
      "program_id": 719,
      "ratio": 0.9106606806291451,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3810.324324324324,
      "baseline_run_cnt_delta": 74,
      "baseline_run_time_ns_delta": 281964,
      "post_rejit_avg_ns_per_run": 3920.8928571428573,
      "post_rejit_run_cnt_delta": 84,
      "post_rejit_run_time_ns_delta": 329355,
      "program": "trace_load_elf_",
      "program_id": 733,
      "ratio": 1.0290181421336464,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 182.93014738802628,
      "baseline_run_cnt_delta": 111678,
      "baseline_run_time_ns_delta": 20429273,
      "post_rejit_avg_ns_per_run": 176.835852665929,
      "post_rejit_run_cnt_delta": 106642,
      "post_rejit_run_time_ns_delta": 18858129,
      "program": "trace_security_",
      "program_id": 734,
      "ratio": 0.966685126486176,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3506.7190332326286,
      "baseline_run_cnt_delta": 331,
      "baseline_run_time_ns_delta": 1160724,
      "post_rejit_avg_ns_per_run": 4928.180379746836,
      "post_rejit_run_cnt_delta": 316,
      "post_rejit_run_time_ns_delta": 1557305,
      "program": "tracepoint__tas",
      "program_id": 735,
      "ratio": 1.4053536462554428,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3595.4444444444443,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 32359,
      "post_rejit_avg_ns_per_run": 4597.25,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 18389,
      "program": "trace_security_",
      "program_id": 736,
      "ratio": 1.2786319107512594,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3264.7679449360867,
      "baseline_run_cnt_delta": 2034,
      "baseline_run_time_ns_delta": 6640538,
      "post_rejit_avg_ns_per_run": 3553.2511230907458,
      "post_rejit_run_cnt_delta": 2226,
      "post_rejit_run_time_ns_delta": 7909537,
      "program": "trace_do_sigact",
      "program_id": 739,
      "ratio": 1.088362536946039,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4319.25,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 51831,
      "post_rejit_avg_ns_per_run": 5566.285714285715,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 38964,
      "program": "trace_do_trunca",
      "program_id": 742,
      "ratio": 1.2887157988738125,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1153.0893051416679,
      "baseline_run_cnt_delta": 21141,
      "baseline_run_time_ns_delta": 24377461,
      "post_rejit_avg_ns_per_run": 1185.435009002871,
      "post_rejit_run_cnt_delta": 20549,
      "post_rejit_run_time_ns_delta": 24359504,
      "program": "trace_fd_instal",
      "program_id": 743,
      "ratio": 1.0280513432194476,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1788.775241779497,
      "baseline_run_cnt_delta": 2585,
      "baseline_run_time_ns_delta": 4623984,
      "post_rejit_avg_ns_per_run": 2486.7567771084337,
      "post_rejit_run_cnt_delta": 1328,
      "post_rejit_run_time_ns_delta": 3302413,
      "program": "trace_filp_clos",
      "program_id": 744,
      "ratio": 1.3902008027764157,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 468.8301886792453,
      "baseline_run_cnt_delta": 530,
      "baseline_run_time_ns_delta": 248480,
      "post_rejit_avg_ns_per_run": 395.53937947494035,
      "post_rejit_run_cnt_delta": 419,
      "post_rejit_run_time_ns_delta": 165731,
      "program": "trace_file_upda",
      "program_id": 745,
      "ratio": 0.8436730164267482,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1717.4962264150943,
      "baseline_run_cnt_delta": 530,
      "baseline_run_time_ns_delta": 910273,
      "post_rejit_avg_ns_per_run": 128.4749403341289,
      "post_rejit_run_cnt_delta": 419,
      "post_rejit_run_time_ns_delta": 53831,
      "program": "trace_ret_file_",
      "program_id": 746,
      "ratio": 0.07480362306372738,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 715.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1430,
      "post_rejit_avg_ns_per_run": 814.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 1628,
      "program": "trace_inotify_f",
      "program_id": 749,
      "ratio": 1.1384615384615384,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4120.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 8240,
      "post_rejit_avg_ns_per_run": 257.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 515,
      "program": "trace_ret_inoti",
      "program_id": 750,
      "ratio": 0.0625,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 216.0810810810811,
      "baseline_run_cnt_delta": 37,
      "baseline_run_time_ns_delta": 7995,
      "post_rejit_avg_ns_per_run": 154.23809523809524,
      "post_rejit_run_cnt_delta": 42,
      "post_rejit_run_time_ns_delta": 6478,
      "program": "trace_exec_binp",
      "program_id": 752,
      "ratio": 0.7137973137973138,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 7395.459459459459,
      "baseline_run_cnt_delta": 37,
      "baseline_run_time_ns_delta": 273632,
      "post_rejit_avg_ns_per_run": 7602.071428571428,
      "post_rejit_run_cnt_delta": 42,
      "post_rejit_run_time_ns_delta": 319287,
      "program": "trace_security_",
      "program_id": 753,
      "ratio": 1.0279376785505454,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 7840.2972972972975,
      "baseline_run_cnt_delta": 37,
      "baseline_run_time_ns_delta": 290091,
      "post_rejit_avg_ns_per_run": 7863.023809523809,
      "post_rejit_run_cnt_delta": 42,
      "post_rejit_run_time_ns_delta": 330247,
      "program": "trace_execute_f",
      "program_id": 754,
      "ratio": 1.0028986799052053,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4378.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 8756,
      "post_rejit_avg_ns_per_run": 4885.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 9771,
      "program": "trace_security_",
      "program_id": 755,
      "ratio": 1.1159205116491548,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5478.8,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 54788,
      "post_rejit_avg_ns_per_run": 4930.625,
      "post_rejit_run_cnt_delta": 16,
      "post_rejit_run_time_ns_delta": 78890,
      "program": "trace_set_fs_pw",
      "program_id": 756,
      "ratio": 0.899946156092575,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1573.7432043975996,
      "baseline_run_cnt_delta": 19829,
      "baseline_run_time_ns_delta": 31205754,
      "post_rejit_avg_ns_per_run": 1575.8200942870178,
      "post_rejit_run_cnt_delta": 19727,
      "post_rejit_run_time_ns_delta": 31086203,
      "program": "trace_security_",
      "program_id": 757,
      "ratio": 1.0013197133329088,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1042.7026355733408,
      "baseline_run_cnt_delta": 21741,
      "baseline_run_time_ns_delta": 22669398,
      "post_rejit_avg_ns_per_run": 1077.1810486481104,
      "post_rejit_run_cnt_delta": 20083,
      "post_rejit_run_time_ns_delta": 21633027,
      "program": "trace_security_task_prctl",
      "program_id": 760,
      "ratio": 1.0330663910289355,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 834.7058823529412,
      "baseline_run_cnt_delta": 527,
      "baseline_run_time_ns_delta": 439890,
      "post_rejit_avg_ns_per_run": 842.6666666666666,
      "post_rejit_run_cnt_delta": 423,
      "post_rejit_run_time_ns_delta": 356448,
      "program": "trace_sock_allo",
      "program_id": 763,
      "ratio": 1.0095372327930467,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2737.0360531309298,
      "baseline_run_cnt_delta": 527,
      "baseline_run_time_ns_delta": 1442418,
      "post_rejit_avg_ns_per_run": 3108.6548463356976,
      "post_rejit_run_cnt_delta": 423,
      "post_rejit_run_time_ns_delta": 1314961,
      "program": "trace_ret_sock_",
      "program_id": 764,
      "ratio": 1.1357741681114022,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 713.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 713,
      "post_rejit_avg_ns_per_run": 401.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 401,
      "program": "trace_security_",
      "program_id": 765,
      "ratio": 0.5624123422159888,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 903.3709543568465,
      "baseline_run_cnt_delta": 1205,
      "baseline_run_time_ns_delta": 1088562,
      "post_rejit_avg_ns_per_run": 2677.8815426997244,
      "post_rejit_run_cnt_delta": 363,
      "post_rejit_run_time_ns_delta": 972071,
      "program": "trace_security_",
      "program_id": 766,
      "ratio": 2.9643210574622003,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1317.7612359550562,
      "baseline_run_cnt_delta": 712,
      "baseline_run_time_ns_delta": 938246,
      "post_rejit_avg_ns_per_run": 3246.089347079038,
      "post_rejit_run_cnt_delta": 291,
      "post_rejit_run_time_ns_delta": 944612,
      "program": "trace_security_",
      "program_id": 767,
      "ratio": 2.4633364971662814,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1781.0280269058296,
      "baseline_run_cnt_delta": 892,
      "baseline_run_time_ns_delta": 1588677,
      "post_rejit_avg_ns_per_run": 2879.769944341373,
      "post_rejit_run_cnt_delta": 539,
      "post_rejit_run_time_ns_delta": 1552196,
      "program": "cgroup_bpf_run_",
      "program_id": 768,
      "ratio": 1.6169144453860065,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2917.3534136546186,
      "baseline_run_cnt_delta": 249,
      "baseline_run_time_ns_delta": 726421,
      "post_rejit_avg_ns_per_run": 2734.879120879121,
      "post_rejit_run_cnt_delta": 273,
      "post_rejit_run_time_ns_delta": 746622,
      "program": "cgroup_skb_ingr",
      "program_id": 770,
      "ratio": 0.9374521126163768,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3914.0238095238096,
      "baseline_run_cnt_delta": 252,
      "baseline_run_time_ns_delta": 986334,
      "post_rejit_avg_ns_per_run": 3670.5072463768115,
      "post_rejit_run_cnt_delta": 276,
      "post_rejit_run_time_ns_delta": 1013060,
      "program": "cgroup_skb_egre",
      "program_id": 771,
      "ratio": 0.9377835764426213,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2808.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2808,
      "post_rejit_avg_ns_per_run": 3826.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 3826,
      "program": "cgroup_mkdir_si",
      "program_id": 772,
      "ratio": 1.3625356125356125,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2083.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2083,
      "post_rejit_avg_ns_per_run": 2226.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2226,
      "program": "cgroup_rmdir_si",
      "program_id": 773,
      "ratio": 1.0686509841574652,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 119.05,
      "baseline_run_cnt_delta": 40,
      "baseline_run_time_ns_delta": 4762,
      "post_rejit_avg_ns_per_run": 156.95348837209303,
      "post_rejit_run_cnt_delta": 43,
      "post_rejit_run_time_ns_delta": 6749,
      "program": "empty_kprobe",
      "program_id": 774,
      "ratio": 1.3183829346668883,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1705.1081081081081,
      "baseline_run_cnt_delta": 37,
      "baseline_run_time_ns_delta": 63089,
      "post_rejit_avg_ns_per_run": 1663.2380952380952,
      "post_rejit_run_cnt_delta": 42,
      "post_rejit_run_time_ns_delta": 69856,
      "program": "tracepoint__exe",
      "program_id": 775,
      "ratio": 0.9754443646881313,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1496.5408426483234,
      "baseline_run_cnt_delta": 12793,
      "baseline_run_time_ns_delta": 19145247,
      "post_rejit_avg_ns_per_run": 1560.3140122928498,
      "post_rejit_run_cnt_delta": 12853,
      "post_rejit_run_time_ns_delta": 20054716,
      "program": "lsm_file_open_t",
      "program_id": 776,
      "ratio": 1.042613718133928,
      "runner": "tracee",
      "type": "lsm",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 833.6768549634609,
      "baseline_run_cnt_delta": 18747,
      "baseline_run_time_ns_delta": 15628940,
      "post_rejit_avg_ns_per_run": 1136.4197900233912,
      "post_rejit_run_cnt_delta": 18383,
      "post_rejit_run_time_ns_delta": 20890805,
      "program": "cap_capable",
      "program_id": 783,
      "ratio": 1.3631418255856451,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 1467.331265961328,
      "baseline_run_cnt_delta": 19187,
      "baseline_run_time_ns_delta": 28153685,
      "post_rejit_avg_ns_per_run": 1401.326437121324,
      "post_rejit_run_cnt_delta": 20301,
      "post_rejit_run_time_ns_delta": 28448328,
      "program": "block_io_start",
      "program_id": 789,
      "ratio": 0.9550170909792748,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 383.1479752596569,
      "baseline_run_cnt_delta": 17138,
      "baseline_run_time_ns_delta": 6566390,
      "post_rejit_avg_ns_per_run": 337.82448466291214,
      "post_rejit_run_cnt_delta": 18289,
      "post_rejit_run_time_ns_delta": 6178472,
      "program": "block_io_done",
      "program_id": 790,
      "ratio": 0.8817076077042314,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1436.25,
      "baseline_run_cnt_delta": 12,
      "baseline_run_time_ns_delta": 17235,
      "post_rejit_avg_ns_per_run": 1288.6153846153845,
      "post_rejit_run_cnt_delta": 13,
      "post_rejit_run_time_ns_delta": 16752,
      "program": "1",
      "program_id": 796,
      "ratio": 0.8972082747539666,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 135.17687164309984,
      "baseline_run_cnt_delta": 136845,
      "baseline_run_time_ns_delta": 18498279,
      "post_rejit_avg_ns_per_run": 145.8284771584227,
      "post_rejit_run_cnt_delta": 143357,
      "post_rejit_run_time_ns_delta": 20905533,
      "program": "vfs_create",
      "program_id": 797,
      "ratio": 1.0787975441793451,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 260.84918564768225,
      "baseline_run_cnt_delta": 48689,
      "baseline_run_time_ns_delta": 12700486,
      "post_rejit_avg_ns_per_run": 264.472572746963,
      "post_rejit_run_cnt_delta": 42476,
      "post_rejit_run_time_ns_delta": 11233737,
      "program": "sched_wakeup",
      "program_id": 803,
      "ratio": 1.0138907357149074,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 423.04581673306774,
      "baseline_run_cnt_delta": 502,
      "baseline_run_time_ns_delta": 212369,
      "post_rejit_avg_ns_per_run": 445.96090534979425,
      "post_rejit_run_cnt_delta": 486,
      "post_rejit_run_time_ns_delta": 216737,
      "program": "sched_wakeup_ne",
      "program_id": 804,
      "ratio": 1.0541669193036494,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 435.1937609613848,
      "baseline_run_cnt_delta": 96361,
      "baseline_run_time_ns_delta": 41935706,
      "post_rejit_avg_ns_per_run": 421.03134990203154,
      "post_rejit_run_cnt_delta": 87273,
      "post_rejit_run_time_ns_delta": 36744669,
      "program": "sched_switch",
      "program_id": 805,
      "ratio": 0.9674572286420947,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 2289.0526315789475,
      "baseline_run_cnt_delta": 19,
      "baseline_run_time_ns_delta": 43492,
      "post_rejit_avg_ns_per_run": 2271.2380952380954,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 47696,
      "program": "tcp_set_state",
      "program_id": 812,
      "ratio": 0.9922175068868714,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_network"
    }
  ],
  "results": [
    {
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "79": {
            "avg_ns_per_run": 1324.6018846342392,
            "bytes_jited": 207,
            "bytes_xlated": 344,
            "id": 79,
            "name": "cap_capable",
            "run_cnt_delta": 18359,
            "run_time_ns_delta": 24318366,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.8993736900000044,
            "ops_per_sec": 744.6553195039246,
            "ops_total": 4393.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [4628]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4628] get                  54      1.00      0.00      0.25        53.95         217.20\nstress-ng: info:  [4628] skipped: 0\nstress-ng: info:  [4628] passed: 1: get (1)\nstress-ng: info:  [4628] failed: 0\nstress-ng: info:  [4628] metrics untrustworthy: 0\nstress-ng: info:  [4628] successful run completed in 1.01 secs\nstress-ng: info:  [4630] setting to a 1 secs run per stressor\nstress-ng: info:  [4630] dispatching hogs: 1 prctl\nstress-ng: info:  [4630] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4630] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4630]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4630] prctl                33      1.03      0.08      0.03        32.18         290.15\nstress-ng: info:  [4630] skipped: 0\nstress-ng: info:  [4630] passed: 1: prctl (1)\nstress-ng: info:  [4630] failed: 0\nstress-ng: info:  [4630] metrics untrustworthy: 0\nstress-ng: info:  [4630] successful run completed in 1.05 secs\nstress-ng: info:  [4665] setting to a 1 secs run per stressor\nstress-ng: info:  [4665] dispatching hogs: 1 set\nstress-ng: info:  [4665] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4665] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4665]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4665] set                 282      1.01      0.01      0.25       280.42        1108.75\nstress-ng: info:  [4665] skipped: 0\nstress-ng: info:  [4665] passed: 1: set (1)\nstress-ng: info:  [4665] failed: 0\nstress-ng: info:  [4665] metrics untrustworthy: 0\nstress-ng: info:  [4665] successful run completed in 1.03 secs\nstress-ng: info:  [4667] setting to a 1 secs run per stressor\nstress-ng: info:  [4667] dispatching hogs: 1 timerfd\nstress-ng: info:  [4667] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4667] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4667]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4667] timerfd            1024      0.24      0.01      0.07      4281.36       12616.74\nstress-ng: info:  [4667] skipped: 0\nstress-ng: info:  [4667] passed: 1: timerfd (1)\nstress-ng: info:  [4667] failed: 0\nstress-ng: info:  [4667] metrics untrustworthy: 0\nstress-ng: info:  [4667] successful run completed in 0.26 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "79": {
            "avg_ns_per_run": 1685.0626613213246,
            "bytes_jited": 210,
            "bytes_xlated": 344,
            "id": 79,
            "name": "cap_capable",
            "run_cnt_delta": 18209,
            "run_time_ns_delta": 30683306,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.094196247999662,
            "ops_per_sec": 890.0324564018055,
            "ops_total": 4534.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [15858]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15858] get                  76      1.00      0.03      0.32        76.02         220.35\nstress-ng: info:  [15858] skipped: 0\nstress-ng: info:  [15858] passed: 1: get (1)\nstress-ng: info:  [15858] failed: 0\nstress-ng: info:  [15858] metrics untrustworthy: 0\nstress-ng: info:  [15858] successful run completed in 1.01 secs\nstress-ng: info:  [15860] setting to a 1 secs run per stressor\nstress-ng: info:  [15860] dispatching hogs: 1 prctl\nstress-ng: info:  [15860] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15860] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15860]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15860] prctl                33      1.00      0.07      0.04        32.98         294.65\nstress-ng: info:  [15860] skipped: 0\nstress-ng: info:  [15860] passed: 1: prctl (1)\nstress-ng: info:  [15860] failed: 0\nstress-ng: info:  [15860] metrics untrustworthy: 0\nstress-ng: info:  [15860] successful run completed in 1.01 secs\nstress-ng: info:  [15897] setting to a 1 secs run per stressor\nstress-ng: info:  [15897] dispatching hogs: 1 set\nstress-ng: info:  [15897] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15897] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15897]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15897] set                 401      1.00      0.01      0.35       401.06        1125.57\nstress-ng: info:  [15897] skipped: 0\nstress-ng: info:  [15897] passed: 1: set (1)\nstress-ng: info:  [15897] failed: 0\nstress-ng: info:  [15897] metrics untrustworthy: 0\nstress-ng: info:  [15897] successful run completed in 1.01 secs\nstress-ng: info:  [15899] setting to a 1 secs run per stressor\nstress-ng: info:  [15899] dispatching hogs: 1 timerfd\nstress-ng: info:  [15899] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15899] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15899]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15899] timerfd            1024      0.14      0.00      0.07      7174.07       15484.89\nstress-ng: info:  [15899] skipped: 0\nstress-ng: info:  [15899] passed: 1: timerfd (1)\nstress-ng: info:  [15899] failed: 0\nstress-ng: info:  [15899] metrics untrustworthy: 0\nstress-ng: info:  [15899] successful run completed in 0.15 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
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
          "82": {
            "avg_ns_per_run": 495.3333333333333,
            "bytes_jited": 2681,
            "bytes_xlated": 4144,
            "id": 82,
            "name": "syscall__execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 4458,
            "type": "kprobe"
          },
          "83": {
            "avg_ns_per_run": 324.44444444444446,
            "bytes_jited": 496,
            "bytes_xlated": 704,
            "id": 83,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 2920,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 6.322210515999984,
            "ops_per_sec": 1180.757898065541,
            "ops_total": 7465.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [5410]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5410] sem-sysv           1001      0.13      0.03      0.00      7849.47       37492.04\nstress-ng: info:  [5410] skipped: 0\nstress-ng: info:  [5410] passed: 1: sem-sysv (1)\nstress-ng: info:  [5410] failed: 0\nstress-ng: info:  [5410] metrics untrustworthy: 0\nstress-ng: info:  [5410] successful run completed in 0.15 secs\nstress-ng: info:  [5414] setting to a 1 secs run per stressor\nstress-ng: info:  [5414] dispatching hogs: 1 switch\nstress-ng: info:  [5414] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5414] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5414]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5414] switch             1000      0.10      0.02      0.02      9816.89       22399.43\nstress-ng: info:  [5414] skipped: 0\nstress-ng: info:  [5414] passed: 1: switch (1)\nstress-ng: info:  [5414] failed: 0\nstress-ng: info:  [5414] metrics untrustworthy: 0\nstress-ng: info:  [5414] successful run completed in 0.11 secs\nstress-ng: info:  [5417] setting to a 1 secs run per stressor\nstress-ng: info:  [5417] dispatching hogs: 1 vfork\nstress-ng: info:  [5417] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5417] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5417]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5417] vfork               200      0.14      0.03      0.00      1462.06        7869.99\nstress-ng: info:  [5417] skipped: 0\nstress-ng: info:  [5417] passed: 1: vfork (1)\nstress-ng: info:  [5417] failed: 0\nstress-ng: info:  [5417] metrics untrustworthy: 0\nstress-ng: info:  [5417] successful run completed in 0.16 secs\nstress-ng: info:  [5619] setting to a 1 secs run per stressor\nstress-ng: info:  [5619] dispatching hogs: 1 yield\nstress-ng: info:  [5619] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5619] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5619]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5619] yield              1021      1.02      0.02      0.01      1002.81       33028.18\nstress-ng: info:  [5619] skipped: 0\nstress-ng: info:  [5619] passed: 1: yield (1)\nstress-ng: info:  [5619] failed: 0\nstress-ng: info:  [5619] metrics untrustworthy: 0\nstress-ng: info:  [5619] successful run completed in 1.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "82": {
            "avg_ns_per_run": 515.7777777777778,
            "bytes_jited": 2681,
            "bytes_xlated": 4144,
            "id": 82,
            "name": "syscall__execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 4642,
            "type": "kprobe"
          },
          "83": {
            "avg_ns_per_run": 308.44444444444446,
            "bytes_jited": 496,
            "bytes_xlated": 704,
            "id": 83,
            "name": "do_ret_sys_exec",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 2776,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.894802431000244,
            "ops_per_sec": 1493.3494553957912,
            "ops_total": 8803.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [16630]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16630] sem-sysv           1001      0.07      0.02      0.01     15387.34       41870.58\nstress-ng: info:  [16630] skipped: 0\nstress-ng: info:  [16630] passed: 1: sem-sysv (1)\nstress-ng: info:  [16630] failed: 0\nstress-ng: info:  [16630] metrics untrustworthy: 0\nstress-ng: info:  [16630] successful run completed in 0.07 secs\nstress-ng: info:  [16634] setting to a 1 secs run per stressor\nstress-ng: info:  [16634] dispatching hogs: 1 switch\nstress-ng: info:  [16634] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16634] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16634]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16634] switch             1000      0.16      0.00      0.05      6145.41       18210.62\nstress-ng: info:  [16634] skipped: 0\nstress-ng: info:  [16634] passed: 1: switch (1)\nstress-ng: info:  [16634] failed: 0\nstress-ng: info:  [16634] metrics untrustworthy: 0\nstress-ng: info:  [16634] successful run completed in 0.17 secs\nstress-ng: info:  [16637] setting to a 1 secs run per stressor\nstress-ng: info:  [16637] dispatching hogs: 1 vfork\nstress-ng: info:  [16637] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16637] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16637]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16637] vfork               200      0.11      0.01      0.01      1816.42        8209.84\nstress-ng: info:  [16637] skipped: 0\nstress-ng: info:  [16637] passed: 1: vfork (1)\nstress-ng: info:  [16637] failed: 0\nstress-ng: info:  [16637] metrics untrustworthy: 0\nstress-ng: info:  [16637] successful run completed in 0.12 secs\nstress-ng: info:  [16839] setting to a 1 secs run per stressor\nstress-ng: info:  [16839] dispatching hogs: 1 yield\nstress-ng: info:  [16839] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16839] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16839]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16839] yield              2364      1.01      0.02      0.03      2335.04       47693.98\nstress-ng: info:  [16839] skipped: 0\nstress-ng: info:  [16839] passed: 1: yield (1)\nstress-ng: info:  [16839] failed: 0\nstress-ng: info:  [16839] metrics untrustworthy: 0\nstress-ng: info:  [16839] successful run completed in 1.02 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 2,
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
          "86": {
            "avg_ns_per_run": 850.0,
            "bytes_jited": 79,
            "bytes_xlated": 120,
            "id": 86,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1700,
            "type": "kprobe"
          },
          "87": {
            "avg_ns_per_run": 12393.0,
            "bytes_jited": 725,
            "bytes_xlated": 1160,
            "id": 87,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 24786,
            "type": "kprobe"
          },
          "88": {
            "avg_ns_per_run": null,
            "bytes_jited": 746,
            "bytes_xlated": 1184,
            "id": 88,
            "name": "bindsnoop_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 7.233017382999947,
            "ops_per_sec": 507.94845435255706,
            "ops_total": 3674.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [5726]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5726] sockdiag           1030      0.00      0.00      0.00    272254.42      431323.28\nstress-ng: info:  [5726] skipped: 0\nstress-ng: info:  [5726] passed: 1: sockdiag (1)\nstress-ng: info:  [5726] failed: 0\nstress-ng: info:  [5726] metrics untrustworthy: 0\nstress-ng: info:  [5726] successful run completed in 0.01 secs\nstress-ng: info:  [5728] setting to a 1 secs run per stressor\nstress-ng: info:  [5728] dispatching hogs: 1 sockfd\nstress-ng: info:  [5728] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5728] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5728]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5728] sockfd              200      0.05      0.02      0.00      3789.47       11889.90\nstress-ng: info:  [5728] skipped: 0\nstress-ng: info:  [5728] passed: 1: sockfd (1)\nstress-ng: info:  [5728] failed: 0\nstress-ng: info:  [5728] metrics untrustworthy: 0\nstress-ng: info:  [5728] successful run completed in 0.06 secs\nstress-ng: info:  [5731] setting to a 1 secs run per stressor\nstress-ng: info:  [5731] dispatching hogs: 1 sockpair\nstress-ng: info:  [5731] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5731] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5731]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5731] sockpair              0      1.87      0.01      0.79         0.00           0.00\nstress-ng: info:  [5731] skipped: 0\nstress-ng: info:  [5731] passed: 1: sockpair (1)\nstress-ng: info:  [5731] failed: 0\nstress-ng: info:  [5731] metrics untrustworthy: 0\nstress-ng: info:  [5731] successful run completed in 1.88 secs\nstress-ng: info:  [5734] setting to a 1 secs run per stressor\nstress-ng: info:  [5734] dispatching hogs: 1 udp-flood\nstress-ng: info:  [5734] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5734] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5734]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5734] udp-flood          1000      0.09      0.00      0.04     10977.53       22238.04\nstress-ng: info:  [5734] skipped: 0\nstress-ng: info:  [5734] passed: 1: udp-flood (1)\nstress-ng: info:  [5734] failed: 0\nstress-ng: info:  [5734] metrics untrustworthy: 0\nstress-ng: info:  [5734] successful run completed in 0.11 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "86": {
            "avg_ns_per_run": 1102.0,
            "bytes_jited": 79,
            "bytes_xlated": 120,
            "id": 86,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2204,
            "type": "kprobe"
          },
          "87": {
            "avg_ns_per_run": 10798.0,
            "bytes_jited": 723,
            "bytes_xlated": 1160,
            "id": 87,
            "name": "bindsnoop_v4_re",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 21596,
            "type": "kprobe"
          },
          "88": {
            "avg_ns_per_run": null,
            "bytes_jited": 744,
            "bytes_xlated": 1184,
            "id": 88,
            "name": "bindsnoop_v6_re",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 7.587693807000051,
            "ops_per_sec": 525.3243082005633,
            "ops_total": 3986.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [16879]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16879] sockdiag           1030      0.00      0.00      0.00    289708.50      385623.36\nstress-ng: info:  [16879] skipped: 0\nstress-ng: info:  [16879] passed: 1: sockdiag (1)\nstress-ng: info:  [16879] failed: 0\nstress-ng: info:  [16879] metrics untrustworthy: 0\nstress-ng: info:  [16879] successful run completed in 0.01 secs\nstress-ng: info:  [16881] setting to a 1 secs run per stressor\nstress-ng: info:  [16881] dispatching hogs: 1 sockfd\nstress-ng: info:  [16881] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16881] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16881]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16881] sockfd              200      0.06      0.00      0.02      3402.71       11608.33\nstress-ng: info:  [16881] skipped: 0\nstress-ng: info:  [16881] passed: 1: sockfd (1)\nstress-ng: info:  [16881] failed: 0\nstress-ng: info:  [16881] metrics untrustworthy: 0\nstress-ng: info:  [16881] successful run completed in 0.08 secs\nstress-ng: info:  [16884] setting to a 1 secs run per stressor\nstress-ng: info:  [16884] dispatching hogs: 1 sockpair\nstress-ng: info:  [16884] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16884] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16884]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16884] sockpair              0      2.50      0.00      0.85         0.00           0.00\nstress-ng: info:  [16884] skipped: 0\nstress-ng: info:  [16884] passed: 1: sockpair (1)\nstress-ng: info:  [16884] failed: 0\nstress-ng: info:  [16884] metrics untrustworthy: 0\nstress-ng: info:  [16884] successful run completed in 2.52 secs\nstress-ng: info:  [16887] setting to a 1 secs run per stressor\nstress-ng: info:  [16887] dispatching hogs: 1 udp-flood\nstress-ng: info:  [16887] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [16887] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16887]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16887] udp-flood          1000      0.13      0.00      0.05      7565.24       21671.29\nstress-ng: info:  [16887] skipped: 0\nstress-ng: info:  [16887] passed: 1: udp-flood (1)\nstress-ng: info:  [16887] failed: 0\nstress-ng: info:  [16887] metrics untrustworthy: 0\nstress-ng: info:  [16887] successful run completed in 0.15 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 2,
          "not_applied": 1,
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
          "91": {
            "avg_ns_per_run": 588.4340689655172,
            "bytes_jited": 271,
            "bytes_xlated": 448,
            "id": 91,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 21750,
            "run_time_ns_delta": 12798441,
            "type": "tracepoint"
          },
          "92": {
            "avg_ns_per_run": 696.556,
            "bytes_jited": 339,
            "bytes_xlated": 616,
            "id": 92,
            "name": "trace_req_start",
            "run_cnt_delta": 21750,
            "run_time_ns_delta": 15150093,
            "type": "kprobe"
          },
          "93": {
            "avg_ns_per_run": 319.97974849755064,
            "bytes_jited": 554,
            "bytes_xlated": 856,
            "id": 93,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 19801,
            "run_time_ns_delta": 6335919,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 8.742616370999997,
            "ops_per_sec": 3849.8772646191424,
            "ops_total": 33658.0,
            "stderr": "",
            "stdout": "        \"500\" : 0.404858,\n        \"750\" : 24.696356,\n        \"1000\" : 4.334365\n      },\n      \"latency_ms\" : {\n        \"2\" : 16.134794,\n        \"4\" : 3.179328,\n        \"10\" : 1.250298,\n        \"20\" : 0.011908,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ],\n  \"disk_util\" : [\n    {\n      \"name\" : \"nvme0n1\",\n      \"read_ios\" : 16428,\n      \"write_ios\" : 1264,\n      \"read_sectors\" : 131424,\n      \"write_sectors\" : 14120,\n      \"read_merges\" : 0,\n      \"write_merges\" : 0,\n      \"read_ticks\" : 15107,\n      \"write_ticks\" : 3527,\n      \"in_queue\" : 18633,\n      \"util\" : 62.886804\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "91": {
            "avg_ns_per_run": 627.5281657946869,
            "bytes_jited": 271,
            "bytes_xlated": 448,
            "id": 91,
            "name": "trace_pid_start",
            "run_cnt_delta": 19687,
            "run_time_ns_delta": 12354147,
            "type": "tracepoint"
          },
          "92": {
            "avg_ns_per_run": 682.2908010362167,
            "bytes_jited": 339,
            "bytes_xlated": 616,
            "id": 92,
            "name": "trace_req_start",
            "run_cnt_delta": 19687,
            "run_time_ns_delta": 13432259,
            "type": "kprobe"
          },
          "93": {
            "avg_ns_per_run": 341.53112500704185,
            "bytes_jited": 552,
            "bytes_xlated": 848,
            "id": 93,
            "name": "trace_req_compl",
            "run_cnt_delta": 17751,
            "run_time_ns_delta": 6062519,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 9.268856469999719,
            "ops_per_sec": 3170.186106032225,
            "ops_total": 29384.0,
            "stderr": "",
            "stdout": "        \"500\" : 0.485235,\n        \"750\" : 27.062249,\n        \"1000\" : 3.881880\n      },\n      \"latency_ms\" : {\n        \"2\" : 8.914460,\n        \"4\" : 8.193539,\n        \"10\" : 1.732982,\n        \"20\" : 0.013864,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ],\n  \"disk_util\" : [\n    {\n      \"name\" : \"nvme0n1\",\n      \"read_ios\" : 14213,\n      \"write_ios\" : 3145,\n      \"read_sectors\" : 113704,\n      \"write_sectors\" : 33384,\n      \"read_merges\" : 0,\n      \"write_merges\" : 0,\n      \"read_ticks\" : 14636,\n      \"write_ticks\" : 8536,\n      \"in_queue\" : 23172,\n      \"util\" : 66.530612\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 2,
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
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 94,
            "bytes_xlated": 144,
            "id": 96,
            "name": "vfs_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "97": {
            "avg_ns_per_run": 96.66666666666667,
            "bytes_jited": 94,
            "bytes_xlated": 144,
            "id": 97,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 580,
            "type": "tracing"
          },
          "98": {
            "avg_ns_per_run": 59.83938164674926,
            "bytes_jited": 94,
            "bytes_xlated": 144,
            "id": 98,
            "name": "vfs_open",
            "run_cnt_delta": 18242,
            "run_time_ns_delta": 1091590,
            "type": "tracing"
          },
          "99": {
            "avg_ns_per_run": 73.32021492884112,
            "bytes_jited": 91,
            "bytes_xlated": 136,
            "id": 99,
            "name": "vfs_read",
            "run_cnt_delta": 41316,
            "run_time_ns_delta": 3029298,
            "type": "tracing"
          },
          "100": {
            "avg_ns_per_run": 55.95169287118099,
            "bytes_jited": 94,
            "bytes_xlated": 144,
            "id": 100,
            "name": "vfs_write",
            "run_cnt_delta": 89552,
            "run_time_ns_delta": 5010586,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 15.089374936000013,
            "ops_per_sec": 437.6589506199009,
            "ops_total": 6604.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [6691]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6691] open                100      0.08      0.01      0.01      1307.72        3813.88\nstress-ng: info:  [6691] skipped: 0\nstress-ng: info:  [6691] passed: 1: open (1)\nstress-ng: info:  [6691] failed: 0\nstress-ng: info:  [6691] metrics untrustworthy: 0\nstress-ng: info:  [6691] successful run completed in 0.09 secs\nstress-ng: info:  [6693] setting to a 1 secs run per stressor\nstress-ng: info:  [6693] dispatching hogs: 1 rename\nstress-ng: info:  [6693] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6693] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6693]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6693] rename              100      0.08      0.00      0.02      1307.91        5097.10\nstress-ng: info:  [6693] skipped: 0\nstress-ng: info:  [6693] passed: 1: rename (1)\nstress-ng: info:  [6693] failed: 0\nstress-ng: info:  [6693] metrics untrustworthy: 0\nstress-ng: info:  [6693] successful run completed in 0.08 secs\nstress-ng: info:  [6695] setting to a 1 secs run per stressor\nstress-ng: info:  [6695] dispatching hogs: 1 touch\nstress-ng: info:  [6695] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6695] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6695]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6695] touch               200      0.04      0.01      0.01      4788.84        7610.93\nstress-ng: info:  [6695] skipped: 0\nstress-ng: info:  [6695] passed: 1: touch (1)\nstress-ng: info:  [6695] failed: 0\nstress-ng: info:  [6695] metrics untrustworthy: 0\nstress-ng: info:  [6695] successful run completed in 0.06 secs\nstress-ng: info:  [6701] setting to a 1 secs run per stressor\nstress-ng: info:  [6701] dispatching hogs: 1 utime\nstress-ng: info:  [6701] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6701] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6701]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6701] utime               200      0.23      0.01      0.07       864.11        2477.58\nstress-ng: info:  [6701] skipped: 0\nstress-ng: info:  [6701] passed: 1: utime (1)\nstress-ng: info:  [6701] failed: 0\nstress-ng: info:  [6701] metrics untrustworthy: 0\nstress-ng: info:  [6701] successful run completed in 0.24 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 94,
            "bytes_xlated": 144,
            "id": 96,
            "name": "vfs_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "97": {
            "avg_ns_per_run": null,
            "bytes_jited": 94,
            "bytes_xlated": 144,
            "id": 97,
            "name": "vfs_fsync_range",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "98": {
            "avg_ns_per_run": 60.85224028113332,
            "bytes_jited": 94,
            "bytes_xlated": 144,
            "id": 98,
            "name": "vfs_open",
            "run_cnt_delta": 18212,
            "run_time_ns_delta": 1108241,
            "type": "tracing"
          },
          "99": {
            "avg_ns_per_run": 67.99748714690081,
            "bytes_jited": 91,
            "bytes_xlated": 136,
            "id": 99,
            "name": "vfs_read",
            "run_cnt_delta": 34622,
            "run_time_ns_delta": 2354209,
            "type": "tracing"
          },
          "100": {
            "avg_ns_per_run": 67.49880753637014,
            "bytes_jited": 94,
            "bytes_xlated": 144,
            "id": 100,
            "name": "vfs_write",
            "run_cnt_delta": 83860,
            "run_time_ns_delta": 5660450,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 15.432164466999893,
            "ops_per_sec": 425.41018883245977,
            "ops_total": 6565.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [17715]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17715] open                100      0.07      0.01      0.01      1419.15        4225.11\nstress-ng: info:  [17715] skipped: 0\nstress-ng: info:  [17715] passed: 1: open (1)\nstress-ng: info:  [17715] failed: 0\nstress-ng: info:  [17715] metrics untrustworthy: 0\nstress-ng: info:  [17715] successful run completed in 0.09 secs\nstress-ng: info:  [17717] setting to a 1 secs run per stressor\nstress-ng: info:  [17717] dispatching hogs: 1 rename\nstress-ng: info:  [17717] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17717] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17717]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17717] rename              100      0.09      0.00      0.02      1114.78        5035.50\nstress-ng: info:  [17717] skipped: 0\nstress-ng: info:  [17717] passed: 1: rename (1)\nstress-ng: info:  [17717] failed: 0\nstress-ng: info:  [17717] metrics untrustworthy: 0\nstress-ng: info:  [17717] successful run completed in 0.10 secs\nstress-ng: info:  [17719] setting to a 1 secs run per stressor\nstress-ng: info:  [17719] dispatching hogs: 1 touch\nstress-ng: info:  [17719] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17719] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17719]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17719] touch               200      0.05      0.02      0.01      3744.38        6743.77\nstress-ng: info:  [17719] skipped: 0\nstress-ng: info:  [17719] passed: 1: touch (1)\nstress-ng: info:  [17719] failed: 0\nstress-ng: info:  [17719] metrics untrustworthy: 0\nstress-ng: info:  [17719] successful run completed in 0.06 secs\nstress-ng: info:  [17725] setting to a 1 secs run per stressor\nstress-ng: info:  [17725] dispatching hogs: 1 utime\nstress-ng: info:  [17725] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17725] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17725]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17725] utime               200      0.33      0.01      0.07       610.52        2308.80\nstress-ng: info:  [17725] skipped: 0\nstress-ng: info:  [17725] passed: 1: utime (1)\nstress-ng: info:  [17725] failed: 0\nstress-ng: info:  [17725] metrics untrustworthy: 0\nstress-ng: info:  [17725] successful run completed in 0.35 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 5,
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
          "103": {
            "avg_ns_per_run": 1860.9611650485438,
            "bytes_jited": 521,
            "bytes_xlated": 600,
            "id": 103,
            "name": "__x64_sys_open",
            "run_cnt_delta": 103,
            "run_time_ns_delta": 191679,
            "type": "tracing"
          },
          "104": {
            "avg_ns_per_run": 2327.906302420321,
            "bytes_jited": 521,
            "bytes_xlated": 600,
            "id": 104,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 16692,
            "run_time_ns_delta": 38857412,
            "type": "tracing"
          },
          "105": {
            "avg_ns_per_run": 2625.285714285714,
            "bytes_jited": 594,
            "bytes_xlated": 640,
            "id": 105,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 36754,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 14.799340028000074,
            "ops_per_sec": 443.39815070028925,
            "ops_total": 6562.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7582]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7582] open                100      0.12      0.00      0.03       804.04        3851.78\nstress-ng: info:  [7582] skipped: 0\nstress-ng: info:  [7582] passed: 1: open (1)\nstress-ng: info:  [7582] failed: 0\nstress-ng: info:  [7582] metrics untrustworthy: 0\nstress-ng: info:  [7582] successful run completed in 0.13 secs\nstress-ng: info:  [7584] setting to a 1 secs run per stressor\nstress-ng: info:  [7584] dispatching hogs: 1 rename\nstress-ng: info:  [7584] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7584] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7584]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7584] rename              100      0.11      0.00      0.02       929.75        4832.79\nstress-ng: info:  [7584] skipped: 0\nstress-ng: info:  [7584] passed: 1: rename (1)\nstress-ng: info:  [7584] failed: 0\nstress-ng: info:  [7584] metrics untrustworthy: 0\nstress-ng: info:  [7584] successful run completed in 0.11 secs\nstress-ng: info:  [7586] setting to a 1 secs run per stressor\nstress-ng: info:  [7586] dispatching hogs: 1 touch\nstress-ng: info:  [7586] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7586] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7586]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7586] touch               200      0.05      0.01      0.02      4029.56        6577.43\nstress-ng: info:  [7586] skipped: 0\nstress-ng: info:  [7586] passed: 1: touch (1)\nstress-ng: info:  [7586] failed: 0\nstress-ng: info:  [7586] metrics untrustworthy: 0\nstress-ng: info:  [7586] successful run completed in 0.06 secs\nstress-ng: info:  [7592] setting to a 1 secs run per stressor\nstress-ng: info:  [7592] dispatching hogs: 1 utime\nstress-ng: info:  [7592] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7592] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7592]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7592] utime               200      0.26      0.02      0.06       762.89        2513.07\nstress-ng: info:  [7592] skipped: 0\nstress-ng: info:  [7592] passed: 1: utime (1)\nstress-ng: info:  [7592] failed: 0\nstress-ng: info:  [7592] metrics untrustworthy: 0\nstress-ng: info:  [7592] successful run completed in 0.27 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "103": {
            "avg_ns_per_run": 2175.705263157895,
            "bytes_jited": 521,
            "bytes_xlated": 600,
            "id": 103,
            "name": "__x64_sys_open",
            "run_cnt_delta": 95,
            "run_time_ns_delta": 206692,
            "type": "tracing"
          },
          "104": {
            "avg_ns_per_run": 2192.065546790761,
            "bytes_jited": 521,
            "bytes_xlated": 600,
            "id": 104,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 17621,
            "run_time_ns_delta": 38626387,
            "type": "tracing"
          },
          "105": {
            "avg_ns_per_run": 2908.5555555555557,
            "bytes_jited": 594,
            "bytes_xlated": 640,
            "id": 105,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 18,
            "run_time_ns_delta": 52354,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 14.920816754000043,
            "ops_per_sec": 435.76702986161354,
            "ops_total": 6502.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [18632]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18632] open                100      0.09      0.03      0.00      1060.03        3805.61\nstress-ng: info:  [18632] skipped: 0\nstress-ng: info:  [18632] passed: 1: open (1)\nstress-ng: info:  [18632] failed: 0\nstress-ng: info:  [18632] metrics untrustworthy: 0\nstress-ng: info:  [18632] successful run completed in 0.11 secs\nstress-ng: info:  [18634] setting to a 1 secs run per stressor\nstress-ng: info:  [18634] dispatching hogs: 1 rename\nstress-ng: info:  [18634] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18634] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18634]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18634] rename              100      0.12      0.00      0.02       809.48        4654.19\nstress-ng: info:  [18634] skipped: 0\nstress-ng: info:  [18634] passed: 1: rename (1)\nstress-ng: info:  [18634] failed: 0\nstress-ng: info:  [18634] metrics untrustworthy: 0\nstress-ng: info:  [18634] successful run completed in 0.13 secs\nstress-ng: info:  [18636] setting to a 1 secs run per stressor\nstress-ng: info:  [18636] dispatching hogs: 1 touch\nstress-ng: info:  [18636] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18636] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18636]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18636] touch               200      0.05      0.02      0.01      3731.57        6888.24\nstress-ng: info:  [18636] skipped: 0\nstress-ng: info:  [18636] passed: 1: touch (1)\nstress-ng: info:  [18636] failed: 0\nstress-ng: info:  [18636] metrics untrustworthy: 0\nstress-ng: info:  [18636] successful run completed in 0.08 secs\nstress-ng: info:  [18642] setting to a 1 secs run per stressor\nstress-ng: info:  [18642] dispatching hogs: 1 utime\nstress-ng: info:  [18642] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18642] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18642]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18642] utime               200      0.28      0.00      0.08       724.51        2467.80\nstress-ng: info:  [18642] skipped: 0\nstress-ng: info:  [18642] passed: 1: utime (1)\nstress-ng: info:  [18642] failed: 0\nstress-ng: info:  [18642] metrics untrustworthy: 0\nstress-ng: info:  [18642] successful run completed in 0.28 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 3,
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
          "108": {
            "avg_ns_per_run": 206.79133855641496,
            "bytes_jited": 76,
            "bytes_xlated": 112,
            "id": 108,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 599646,
            "run_time_ns_delta": 124001599,
            "type": "tracepoint"
          },
          "109": {
            "avg_ns_per_run": 181.74377378502507,
            "bytes_jited": 240,
            "bytes_xlated": 400,
            "id": 109,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 599642,
            "run_time_ns_delta": 108981200,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.245930712000018,
            "ops_per_sec": 859.3327375994487,
            "ops_total": 4508.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7664]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7664] get                  69      1.00      0.01      0.29        68.89         230.39\nstress-ng: info:  [7664] skipped: 0\nstress-ng: info:  [7664] passed: 1: get (1)\nstress-ng: info:  [7664] failed: 0\nstress-ng: info:  [7664] metrics untrustworthy: 0\nstress-ng: info:  [7664] successful run completed in 1.02 secs\nstress-ng: info:  [7666] setting to a 1 secs run per stressor\nstress-ng: info:  [7666] dispatching hogs: 1 prctl\nstress-ng: info:  [7666] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7666] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7666]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7666] prctl                52      1.00      0.10      0.06        51.98         313.63\nstress-ng: info:  [7666] skipped: 0\nstress-ng: info:  [7666] passed: 1: prctl (1)\nstress-ng: info:  [7666] failed: 0\nstress-ng: info:  [7666] metrics untrustworthy: 0\nstress-ng: info:  [7666] successful run completed in 1.01 secs\nstress-ng: info:  [7720] setting to a 1 secs run per stressor\nstress-ng: info:  [7720] dispatching hogs: 1 set\nstress-ng: info:  [7720] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7720] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7720]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7720] set                 363      1.00      0.02      0.29       362.99        1159.44\nstress-ng: info:  [7720] skipped: 0\nstress-ng: info:  [7720] passed: 1: set (1)\nstress-ng: info:  [7720] failed: 0\nstress-ng: info:  [7720] metrics untrustworthy: 0\nstress-ng: info:  [7720] successful run completed in 1.01 secs\nstress-ng: info:  [7722] setting to a 1 secs run per stressor\nstress-ng: info:  [7722] dispatching hogs: 1 timerfd\nstress-ng: info:  [7722] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7722] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7722]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7722] timerfd            1024      0.18      0.00      0.07      5653.73       15642.42\nstress-ng: info:  [7722] skipped: 0\nstress-ng: info:  [7722] passed: 1: timerfd (1)\nstress-ng: info:  [7722] failed: 0\nstress-ng: info:  [7722] metrics untrustworthy: 0\nstress-ng: info:  [7722] successful run completed in 0.19 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "108": {
            "avg_ns_per_run": 222.42866225705262,
            "bytes_jited": 76,
            "bytes_xlated": 112,
            "id": 108,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 569362,
            "run_time_ns_delta": 126642428,
            "type": "tracepoint"
          },
          "109": {
            "avg_ns_per_run": 156.22626915477497,
            "bytes_jited": 240,
            "bytes_xlated": 400,
            "id": 109,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 569375,
            "run_time_ns_delta": 88951332,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.259251537000182,
            "ops_per_sec": 854.4942124147435,
            "ops_total": 4494.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [18707]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18707] get                 100      1.00      0.01      0.45        99.55         215.91\nstress-ng: info:  [18707] skipped: 0\nstress-ng: info:  [18707] passed: 1: get (1)\nstress-ng: info:  [18707] failed: 0\nstress-ng: info:  [18707] metrics untrustworthy: 0\nstress-ng: info:  [18707] successful run completed in 1.01 secs\nstress-ng: info:  [18709] setting to a 1 secs run per stressor\nstress-ng: info:  [18709] dispatching hogs: 1 prctl\nstress-ng: info:  [18709] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18709] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18709]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18709] prctl                52      1.02      0.11      0.06        50.78         314.51\nstress-ng: info:  [18709] skipped: 0\nstress-ng: info:  [18709] passed: 1: prctl (1)\nstress-ng: info:  [18709] failed: 0\nstress-ng: info:  [18709] metrics untrustworthy: 0\nstress-ng: info:  [18709] successful run completed in 1.03 secs\nstress-ng: info:  [18763] setting to a 1 secs run per stressor\nstress-ng: info:  [18763] dispatching hogs: 1 set\nstress-ng: info:  [18763] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18763] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18763]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18763] set                 318      1.00      0.02      0.27       317.22        1123.44\nstress-ng: info:  [18763] skipped: 0\nstress-ng: info:  [18763] passed: 1: set (1)\nstress-ng: info:  [18763] failed: 0\nstress-ng: info:  [18763] metrics untrustworthy: 0\nstress-ng: info:  [18763] successful run completed in 1.01 secs\nstress-ng: info:  [18765] setting to a 1 secs run per stressor\nstress-ng: info:  [18765] dispatching hogs: 1 timerfd\nstress-ng: info:  [18765] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18765] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18765]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18765] timerfd            1024      0.15      0.00      0.07      6985.52       15087.89\nstress-ng: info:  [18765] skipped: 0\nstress-ng: info:  [18765] passed: 1: timerfd (1)\nstress-ng: info:  [18765] failed: 0\nstress-ng: info:  [18765] metrics untrustworthy: 0\nstress-ng: info:  [18765] successful run completed in 0.16 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 2,
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
          "112": {
            "avg_ns_per_run": 1134.625,
            "bytes_jited": 79,
            "bytes_xlated": 120,
            "id": 112,
            "name": "trace_connect_entry",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 9077,
            "type": "kprobe"
          },
          "113": {
            "avg_ns_per_run": 10029.25,
            "bytes_jited": 484,
            "bytes_xlated": 720,
            "id": 113,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 80234,
            "type": "kprobe"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 481,
            "bytes_xlated": 712,
            "id": 114,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 6.6369061139999985,
            "ops_per_sec": 545.2841938453856,
            "ops_total": 3619.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7818]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7818] sockdiag           1030      0.00      0.00      0.00    926272.11      532024.79\nstress-ng: info:  [7818] skipped: 0\nstress-ng: info:  [7818] passed: 1: sockdiag (1)\nstress-ng: info:  [7818] failed: 0\nstress-ng: info:  [7818] metrics untrustworthy: 0\nstress-ng: info:  [7818] successful run completed in 0.01 secs\nstress-ng: info:  [7820] setting to a 1 secs run per stressor\nstress-ng: info:  [7820] dispatching hogs: 1 sockfd\nstress-ng: info:  [7820] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7820] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7820]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7820] sockfd              200      0.04      0.01      0.01      5447.15       11137.72\nstress-ng: info:  [7820] skipped: 0\nstress-ng: info:  [7820] passed: 1: sockfd (1)\nstress-ng: info:  [7820] failed: 0\nstress-ng: info:  [7820] metrics untrustworthy: 0\nstress-ng: info:  [7820] successful run completed in 0.04 secs\nstress-ng: info:  [7823] setting to a 1 secs run per stressor\nstress-ng: info:  [7823] dispatching hogs: 1 sockpair\nstress-ng: info:  [7823] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7823] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7823]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7823] sockpair              0      1.91      0.01      0.78         0.00           0.00\nstress-ng: info:  [7823] skipped: 0\nstress-ng: info:  [7823] passed: 1: sockpair (1)\nstress-ng: info:  [7823] failed: 0\nstress-ng: info:  [7823] metrics untrustworthy: 0\nstress-ng: info:  [7823] successful run completed in 1.92 secs\nstress-ng: info:  [7826] setting to a 1 secs run per stressor\nstress-ng: info:  [7826] dispatching hogs: 1 udp-flood\nstress-ng: info:  [7826] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7826] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7826]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7826] udp-flood          1000      0.08      0.00      0.04     12576.55       23446.11\nstress-ng: info:  [7826] skipped: 0\nstress-ng: info:  [7826] passed: 1: udp-flood (1)\nstress-ng: info:  [7826] failed: 0\nstress-ng: info:  [7826] metrics untrustworthy: 0\nstress-ng: info:  [7826] successful run completed in 0.10 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "112": {
            "avg_ns_per_run": 1144.0,
            "bytes_jited": 79,
            "bytes_xlated": 120,
            "id": 112,
            "name": "trace_connect_e",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1144,
            "type": "kprobe"
          },
          "113": {
            "avg_ns_per_run": 8505.0,
            "bytes_jited": 484,
            "bytes_xlated": 720,
            "id": 113,
            "name": "trace_connect_v",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 8505,
            "type": "kprobe"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 481,
            "bytes_xlated": 712,
            "id": 114,
            "name": "trace_connect_v",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 7.796118116999878,
            "ops_per_sec": 498.70973497977093,
            "ops_total": 3888.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [18801]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18801] sockdiag           1030      0.00      0.00      0.00   1083283.13      532024.79\nstress-ng: info:  [18801] skipped: 0\nstress-ng: info:  [18801] passed: 1: sockdiag (1)\nstress-ng: info:  [18801] failed: 0\nstress-ng: info:  [18801] metrics untrustworthy: 0\nstress-ng: info:  [18801] successful run completed in 0.01 secs\nstress-ng: info:  [18803] setting to a 1 secs run per stressor\nstress-ng: info:  [18803] dispatching hogs: 1 sockfd\nstress-ng: info:  [18803] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18803] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18803]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18803] sockfd              200      0.04      0.01      0.00      5479.13       11961.72\nstress-ng: info:  [18803] skipped: 0\nstress-ng: info:  [18803] passed: 1: sockfd (1)\nstress-ng: info:  [18803] failed: 0\nstress-ng: info:  [18803] metrics untrustworthy: 0\nstress-ng: info:  [18803] successful run completed in 0.04 secs\nstress-ng: info:  [18806] setting to a 1 secs run per stressor\nstress-ng: info:  [18806] dispatching hogs: 1 sockpair\nstress-ng: info:  [18806] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18806] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18806]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18806] sockpair              0      1.81      0.02      0.82         0.00           0.00\nstress-ng: info:  [18806] skipped: 0\nstress-ng: info:  [18806] passed: 1: sockpair (1)\nstress-ng: info:  [18806] failed: 0\nstress-ng: info:  [18806] metrics untrustworthy: 0\nstress-ng: info:  [18806] successful run completed in 1.81 secs\nstress-ng: info:  [18809] setting to a 1 secs run per stressor\nstress-ng: info:  [18809] dispatching hogs: 1 udp-flood\nstress-ng: info:  [18809] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18809] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18809]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18809] udp-flood          1000      0.07      0.00      0.05     13429.12       20587.99\nstress-ng: info:  [18809] skipped: 0\nstress-ng: info:  [18809] passed: 1: udp-flood (1)\nstress-ng: info:  [18809] failed: 0\nstress-ng: info:  [18809] metrics untrustworthy: 0\nstress-ng: info:  [18809] successful run completed in 0.09 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 3,
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
          "117": {
            "avg_ns_per_run": 1458.25,
            "bytes_jited": 1071,
            "bytes_xlated": 1672,
            "id": 117,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 52497,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 8.413444821999974,
            "ops_per_sec": 467.10949951482456,
            "ops_total": 3930.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7862]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7862] sockdiag           1030      0.00      0.00      0.00   1220031.95      531201.65\nstress-ng: info:  [7862] skipped: 0\nstress-ng: info:  [7862] passed: 1: sockdiag (1)\nstress-ng: info:  [7862] failed: 0\nstress-ng: info:  [7862] metrics untrustworthy: 0\nstress-ng: info:  [7862] successful run completed in 0.01 secs\nstress-ng: info:  [7864] setting to a 1 secs run per stressor\nstress-ng: info:  [7864] dispatching hogs: 1 sockfd\nstress-ng: info:  [7864] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7864] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7864]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7864] sockfd              200      0.04      0.00      0.02      4917.03       10768.90\nstress-ng: info:  [7864] skipped: 0\nstress-ng: info:  [7864] passed: 1: sockfd (1)\nstress-ng: info:  [7864] failed: 0\nstress-ng: info:  [7864] metrics untrustworthy: 0\nstress-ng: info:  [7864] successful run completed in 0.05 secs\nstress-ng: info:  [7867] setting to a 1 secs run per stressor\nstress-ng: info:  [7867] dispatching hogs: 1 sockpair\nstress-ng: info:  [7867] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7867] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7867]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7867] sockpair              0      2.50      0.03      1.20         0.00           0.00\nstress-ng: info:  [7867] skipped: 0\nstress-ng: info:  [7867] passed: 1: sockpair (1)\nstress-ng: info:  [7867] failed: 0\nstress-ng: info:  [7867] metrics untrustworthy: 0\nstress-ng: info:  [7867] successful run completed in 2.51 secs\nstress-ng: info:  [7872] setting to a 1 secs run per stressor\nstress-ng: info:  [7872] dispatching hogs: 1 udp-flood\nstress-ng: info:  [7872] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7872] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7872]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7872] udp-flood          1000      0.21      0.00      0.04      4665.75       22607.56\nstress-ng: info:  [7872] skipped: 0\nstress-ng: info:  [7872] passed: 1: udp-flood (1)\nstress-ng: info:  [7872] failed: 0\nstress-ng: info:  [7872] metrics untrustworthy: 0\nstress-ng: info:  [7872] successful run completed in 0.24 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "117": {
            "avg_ns_per_run": 87.99698976520169,
            "bytes_jited": 1071,
            "bytes_xlated": 1672,
            "id": 117,
            "name": "sock__inet_sock",
            "run_cnt_delta": 1661,
            "run_time_ns_delta": 146163,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 7.78130828600024,
            "ops_per_sec": 470.74346181480763,
            "ops_total": 3663.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [18855]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18855] sockdiag           1030      0.00      0.00      0.00   1347515.01      574136.01\nstress-ng: info:  [18855] skipped: 0\nstress-ng: info:  [18855] passed: 1: sockdiag (1)\nstress-ng: info:  [18855] failed: 0\nstress-ng: info:  [18855] metrics untrustworthy: 0\nstress-ng: info:  [18855] successful run completed in 0.01 secs\nstress-ng: info:  [18857] setting to a 1 secs run per stressor\nstress-ng: info:  [18857] dispatching hogs: 1 sockfd\nstress-ng: info:  [18857] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18857] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18857]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18857] sockfd              200      0.08      0.00      0.02      2420.68        8714.98\nstress-ng: info:  [18857] skipped: 0\nstress-ng: info:  [18857] passed: 1: sockfd (1)\nstress-ng: info:  [18857] failed: 0\nstress-ng: info:  [18857] metrics untrustworthy: 0\nstress-ng: info:  [18857] successful run completed in 0.10 secs\nstress-ng: info:  [18860] setting to a 1 secs run per stressor\nstress-ng: info:  [18860] dispatching hogs: 1 sockpair\nstress-ng: info:  [18860] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18860] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18860]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18860] sockpair              0      2.50      0.03      0.81         0.00           0.00\nstress-ng: info:  [18860] skipped: 0\nstress-ng: info:  [18860] passed: 1: sockpair (1)\nstress-ng: info:  [18860] failed: 0\nstress-ng: info:  [18860] metrics untrustworthy: 0\nstress-ng: info:  [18860] successful run completed in 2.53 secs\nstress-ng: info:  [18863] setting to a 1 secs run per stressor\nstress-ng: info:  [18863] dispatching hogs: 1 udp-flood\nstress-ng: info:  [18863] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18863] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18863]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18863] udp-flood          1000      0.13      0.00      0.06      7760.81       17484.05\nstress-ng: info:  [18863] skipped: 0\nstress-ng: info:  [18863] passed: 1: udp-flood (1)\nstress-ng: info:  [18863] failed: 0\nstress-ng: info:  [18863] metrics untrustworthy: 0\nstress-ng: info:  [18863] successful run completed in 0.14 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 1,
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
          "120": {
            "avg_ns_per_run": 470.7020073868702,
            "bytes_jited": 666,
            "bytes_xlated": 1168,
            "id": 120,
            "name": "sched_switch",
            "run_cnt_delta": 102073,
            "run_time_ns_delta": 48045966,
            "type": "raw_tracepoint"
          },
          "121": {
            "avg_ns_per_run": 365.8127562311795,
            "bytes_jited": 153,
            "bytes_xlated": 248,
            "id": 121,
            "name": "sched_wakeup",
            "run_cnt_delta": 55126,
            "run_time_ns_delta": 20165794,
            "type": "raw_tracepoint"
          },
          "122": {
            "avg_ns_per_run": 478.0081466395112,
            "bytes_jited": 153,
            "bytes_xlated": 248,
            "id": 122,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 491,
            "run_time_ns_delta": 234702,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.740667269000028,
            "ops_per_sec": 1878.3530719902358,
            "ops_total": 10783.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [8670]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8670] sem-sysv           1001      0.04      0.00      0.02     26376.62       45564.20\nstress-ng: info:  [8670] skipped: 0\nstress-ng: info:  [8670] passed: 1: sem-sysv (1)\nstress-ng: info:  [8670] failed: 0\nstress-ng: info:  [8670] metrics untrustworthy: 0\nstress-ng: info:  [8670] successful run completed in 0.06 secs\nstress-ng: info:  [8674] setting to a 1 secs run per stressor\nstress-ng: info:  [8674] dispatching hogs: 1 switch\nstress-ng: info:  [8674] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8674] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8674]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8674] switch             1000      0.08      0.00      0.04     13063.36       22985.34\nstress-ng: info:  [8674] skipped: 0\nstress-ng: info:  [8674] passed: 1: switch (1)\nstress-ng: info:  [8674] failed: 0\nstress-ng: info:  [8674] metrics untrustworthy: 0\nstress-ng: info:  [8674] successful run completed in 0.09 secs\nstress-ng: info:  [8677] setting to a 1 secs run per stressor\nstress-ng: info:  [8677] dispatching hogs: 1 vfork\nstress-ng: info:  [8677] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8677] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8677]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8677] vfork               200      0.09      0.02      0.00      2178.11        8879.02\nstress-ng: info:  [8677] skipped: 0\nstress-ng: info:  [8677] passed: 1: vfork (1)\nstress-ng: info:  [8677] failed: 0\nstress-ng: info:  [8677] metrics untrustworthy: 0\nstress-ng: info:  [8677] successful run completed in 0.10 secs\nstress-ng: info:  [8879] setting to a 1 secs run per stressor\nstress-ng: info:  [8879] dispatching hogs: 1 yield\nstress-ng: info:  [8879] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8879] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8879]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8879] yield              5000      1.00      0.00      0.08      4998.76       64300.41\nstress-ng: info:  [8879] skipped: 0\nstress-ng: info:  [8879] passed: 1: yield (1)\nstress-ng: info:  [8879] failed: 0\nstress-ng: info:  [8879] metrics untrustworthy: 0\nstress-ng: info:  [8879] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "120": {
            "avg_ns_per_run": 494.02495248934366,
            "bytes_jited": 649,
            "bytes_xlated": 1136,
            "id": 120,
            "name": "sched_switch",
            "run_cnt_delta": 93137,
            "run_time_ns_delta": 46012002,
            "type": "raw_tracepoint"
          },
          "121": {
            "avg_ns_per_run": 375.15634957215286,
            "bytes_jited": 153,
            "bytes_xlated": 248,
            "id": 121,
            "name": "sched_wakeup",
            "run_cnt_delta": 49901,
            "run_time_ns_delta": 18720677,
            "type": "raw_tracepoint"
          },
          "122": {
            "avg_ns_per_run": 563.5282258064516,
            "bytes_jited": 153,
            "bytes_xlated": 248,
            "id": 122,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 496,
            "run_time_ns_delta": 279510,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.752734802999839,
            "ops_per_sec": 1991.5745106180798,
            "ops_total": 11457.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [19664]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19664] sem-sysv           1001      0.08      0.03      0.00     12398.19       37465.38\nstress-ng: info:  [19664] skipped: 0\nstress-ng: info:  [19664] passed: 1: sem-sysv (1)\nstress-ng: info:  [19664] failed: 0\nstress-ng: info:  [19664] metrics untrustworthy: 0\nstress-ng: info:  [19664] successful run completed in 0.10 secs\nstress-ng: info:  [19668] setting to a 1 secs run per stressor\nstress-ng: info:  [19668] dispatching hogs: 1 switch\nstress-ng: info:  [19668] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19668] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19668]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19668] switch             1000      0.07      0.00      0.04     14634.70       24006.15\nstress-ng: info:  [19668] skipped: 0\nstress-ng: info:  [19668] passed: 1: switch (1)\nstress-ng: info:  [19668] failed: 0\nstress-ng: info:  [19668] metrics untrustworthy: 0\nstress-ng: info:  [19668] successful run completed in 0.08 secs\nstress-ng: info:  [19671] setting to a 1 secs run per stressor\nstress-ng: info:  [19671] dispatching hogs: 1 vfork\nstress-ng: info:  [19671] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19671] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19671]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19671] vfork               200      0.12      0.03      0.00      1697.16        7750.74\nstress-ng: info:  [19671] skipped: 0\nstress-ng: info:  [19671] passed: 1: vfork (1)\nstress-ng: info:  [19671] failed: 0\nstress-ng: info:  [19671] metrics untrustworthy: 0\nstress-ng: info:  [19671] successful run completed in 0.12 secs\nstress-ng: info:  [19873] setting to a 1 secs run per stressor\nstress-ng: info:  [19873] dispatching hogs: 1 yield\nstress-ng: info:  [19873] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19873] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19873]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19873] yield              5000      1.00      0.02      0.06      4997.92       56910.66\nstress-ng: info:  [19873] skipped: 0\nstress-ng: info:  [19873] passed: 1: yield (1)\nstress-ng: info:  [19873] failed: 0\nstress-ng: info:  [19873] metrics untrustworthy: 0\nstress-ng: info:  [19873] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 1,
          "not_applied": 2,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "stress_ng_scheduler",
      "status": "ok"
    },
    {
      "app": "calico/felix",
      "baseline": {
        "bpf": {
          "175": {
            "avg_ns_per_run": 705744.0,
            "bytes_jited": 873,
            "bytes_xlated": 1544,
            "id": 175,
            "name": "conntrack_cleanup",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 705744,
            "type": "sched_cls"
          },
          "178": {
            "avg_ns_per_run": null,
            "bytes_jited": 23,
            "bytes_xlated": 24,
            "id": 178,
            "name": "cali_tcx_test",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 284,
            "bytes_xlated": 344,
            "id": 186,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 284,
            "bytes_xlated": 344,
            "id": 187,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 284,
            "bytes_xlated": 344,
            "id": 189,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 284,
            "bytes_xlated": 344,
            "id": 190,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0562193289999868,
            "ops_per_sec": 329.4770228542223,
            "ops_total": 348.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    15.67ms    7.12ms  47.42ms   70.98%\n    Req/Sec   171.35     25.38   240.00     80.00%\n  348 requests in 1.03s, 52.68KB read\nRequests/sec:    339.16\nTransfer/sec:     51.34KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "175": {
            "avg_ns_per_run": null,
            "bytes_jited": 873,
            "bytes_xlated": 1544,
            "id": 175,
            "name": "conntrack_cleanup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "178": {
            "avg_ns_per_run": null,
            "bytes_jited": 23,
            "bytes_xlated": 24,
            "id": 178,
            "name": "cali_tcx_test",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 284,
            "bytes_xlated": 344,
            "id": 186,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 284,
            "bytes_xlated": 344,
            "id": 187,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 284,
            "bytes_xlated": 344,
            "id": 189,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 284,
            "bytes_xlated": 344,
            "id": 190,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0576340540001183,
            "ops_per_sec": 315.799211208041,
            "ops_total": 334.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    16.28ms    6.73ms  41.00ms   68.26%\n    Req/Sec   165.50     54.53   250.00     55.00%\n  334 requests in 1.03s, 50.56KB read\nRequests/sec:    325.27\nTransfer/sec:     49.23KB"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 6,
          "requested": 6
        }
      },
      "runner": "calico",
      "selected_workload": "network",
      "status": "ok"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline": {
        "bpf": {
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 3727,
            "bytes_xlated": 6232,
            "id": 193,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "194": {
            "avg_ns_per_run": null,
            "bytes_jited": 22581,
            "bytes_xlated": 37232,
            "id": 194,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 18296,
            "bytes_xlated": 28048,
            "id": 195,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 17743,
            "bytes_xlated": 29144,
            "id": 196,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 15184,
            "bytes_xlated": 25032,
            "id": 197,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 19915,
            "bytes_xlated": 33264,
            "id": 198,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 16546,
            "bytes_xlated": 28000,
            "id": 199,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 20056,
            "bytes_xlated": 33712,
            "id": 200,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 22571,
            "bytes_xlated": 34248,
            "id": 201,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 1584,
            "bytes_xlated": 2496,
            "id": 202,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "203": {
            "avg_ns_per_run": null,
            "bytes_jited": 700,
            "bytes_xlated": 1088,
            "id": 203,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "204": {
            "avg_ns_per_run": 10537.0,
            "bytes_jited": 792,
            "bytes_xlated": 1320,
            "id": 204,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 10537,
            "type": "tracepoint"
          },
          "205": {
            "avg_ns_per_run": 28460.796812749006,
            "bytes_jited": 3538,
            "bytes_xlated": 5496,
            "id": 205,
            "name": "native_tracer_entry",
            "run_cnt_delta": 251,
            "run_time_ns_delta": 7143660,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.1402678100000685,
            "ops_per_sec": 390.0574978018457,
            "ops_total": 2005.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [9600] setting to a 5 secs run per stressor\nstress-ng: info:  [9600] dispatching hogs: 1 cpu\nstress-ng: info:  [9600] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9600] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9600]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9600] cpu                2005      4.99      2.02      0.02       401.86         984.02\nstress-ng: info:  [9600] skipped: 0\nstress-ng: info:  [9600] passed: 1: cpu (1)\nstress-ng: info:  [9600] failed: 0\nstress-ng: info:  [9600] metrics untrustworthy: 0\nstress-ng: info:  [9600] successful run completed in 5.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 3727,
            "bytes_xlated": 6232,
            "id": 193,
            "name": "perf_unwind_sto",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "194": {
            "avg_ns_per_run": null,
            "bytes_jited": 22581,
            "bytes_xlated": 37232,
            "id": 194,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 18296,
            "bytes_xlated": 28048,
            "id": 195,
            "name": "perf_unwind_hot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 17743,
            "bytes_xlated": 29144,
            "id": 196,
            "name": "perf_unwind_per",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 15184,
            "bytes_xlated": 25032,
            "id": 197,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 19915,
            "bytes_xlated": 33264,
            "id": 198,
            "name": "perf_unwind_pyt",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 16546,
            "bytes_xlated": 28000,
            "id": 199,
            "name": "perf_unwind_rub",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 20056,
            "bytes_xlated": 33712,
            "id": 200,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 22571,
            "bytes_xlated": 34248,
            "id": 201,
            "name": "perf_unwind_dot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 1584,
            "bytes_xlated": 2496,
            "id": 202,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "203": {
            "avg_ns_per_run": null,
            "bytes_jited": 700,
            "bytes_xlated": 1088,
            "id": 203,
            "name": "perf_unwind_bea",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "204": {
            "avg_ns_per_run": 12144.0,
            "bytes_jited": 792,
            "bytes_xlated": 1320,
            "id": 204,
            "name": "tracepoint__sch",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 24288,
            "type": "tracepoint"
          },
          "205": {
            "avg_ns_per_run": 28291.882845188284,
            "bytes_jited": 3538,
            "bytes_xlated": 5496,
            "id": 205,
            "name": "native_tracer_e",
            "run_cnt_delta": 239,
            "run_time_ns_delta": 6761760,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.162075860000186,
            "ops_per_sec": 388.4096348789279,
            "ops_total": 2005.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [20569] setting to a 5 secs run per stressor\nstress-ng: info:  [20569] dispatching hogs: 1 cpu\nstress-ng: info:  [20569] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20569] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20569]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20569] cpu                2005      4.99      2.06      0.05       402.00         947.78\nstress-ng: info:  [20569] skipped: 0\nstress-ng: info:  [20569] passed: 1: cpu (1)\nstress-ng: info:  [20569] failed: 0\nstress-ng: info:  [20569] metrics untrustworthy: 0\nstress-ng: info:  [20569] successful run completed in 5.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 13,
          "requested": 13
        }
      },
      "runner": "otelcol-ebpf-profiler",
      "selected_workload": "stress_ng_cpu",
      "status": "ok"
    },
    {
      "app": "cilium/agent",
      "baseline": {
        "bpf": {
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 171,
            "bytes_xlated": 280,
            "id": 213,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 744,
            "bytes_xlated": 520,
            "id": 214,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0629101619999801,
            "ops_per_sec": 309.52757040251737,
            "ops_total": 329.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    16.49ms    8.03ms  49.30ms   69.60%\n    Req/Sec   162.75     55.80   270.00     60.00%\n  329 requests in 1.03s, 49.80KB read\nRequests/sec:    318.68\nTransfer/sec:     48.24KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 171,
            "bytes_xlated": 280,
            "id": 213,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 744,
            "bytes_xlated": 520,
            "id": 214,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0688298200002464,
            "ops_per_sec": 310.6200760752759,
            "ops_total": 332.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    16.07ms    7.58ms  40.17ms   69.88%\n    Req/Sec   160.95     60.65   290.00     65.00%\n  332 requests in 1.04s, 50.25KB read\nRequests/sec:    318.88\nTransfer/sec:     48.27KB"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 2,
          "requested": 2
        }
      },
      "runner": "cilium",
      "selected_workload": "network",
      "status": "ok"
    },
    {
      "app": "tetragon/observer",
      "baseline": {
        "bpf": {
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 536,
            "bytes_xlated": 960,
            "id": 274,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 3344,
            "bytes_xlated": 5952,
            "id": 276,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 1189,
            "bytes_xlated": 1976,
            "id": 277,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 20,
            "bytes_xlated": 16,
            "id": 278,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 368,
            "bytes_xlated": 672,
            "id": 279,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 386,
            "bytes_xlated": 592,
            "id": 280,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 536,
            "bytes_xlated": 960,
            "id": 283,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 368,
            "bytes_xlated": 672,
            "id": 284,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 1189,
            "bytes_xlated": 1976,
            "id": 285,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 386,
            "bytes_xlated": 592,
            "id": 286,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "291": {
            "avg_ns_per_run": 1746.0,
            "bytes_jited": 3098,
            "bytes_xlated": 5368,
            "id": 291,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1746,
            "type": "sched_cls"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 1189,
            "bytes_xlated": 1976,
            "id": 292,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 386,
            "bytes_xlated": 592,
            "id": 293,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 368,
            "bytes_xlated": 672,
            "id": 296,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "300": {
            "avg_ns_per_run": 1503.6451612903227,
            "bytes_jited": 1016,
            "bytes_xlated": 1792,
            "id": 300,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 186,
            "run_time_ns_delta": 279678,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": 4564.489898989899,
            "bytes_jited": 7339,
            "bytes_xlated": 11312,
            "id": 302,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 198,
            "run_time_ns_delta": 903769,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": 9078.253333333334,
            "bytes_jited": 11245,
            "bytes_xlated": 20272,
            "id": 303,
            "name": "event_execve",
            "run_cnt_delta": 75,
            "run_time_ns_delta": 680869,
            "type": "tracepoint"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 1385,
            "bytes_xlated": 2352,
            "id": 304,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 5000,
            "bytes_xlated": 8064,
            "id": 305,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "306": {
            "avg_ns_per_run": 894.04,
            "bytes_jited": 1537,
            "bytes_xlated": 2560,
            "id": 306,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 75,
            "run_time_ns_delta": 67053,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 307,
            "bytes_xlated": 504,
            "id": 307,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "310": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 310,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 311,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 312,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 313,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 314,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 315,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 316,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 317,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 318,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 319,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 320,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 321,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 322,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 323,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 324,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 325,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 326,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": 3796.6428571428573,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 327,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 42,
            "run_time_ns_delta": 159459,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 328,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 329,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 330,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": 1692.7201090541314,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 331,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22741,
            "run_time_ns_delta": 38494148,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 332,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 333,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 334,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 335,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 336,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 337,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 338,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 339,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "avg_ns_per_run": 161.85642671826216,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 340,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 22741,
            "run_time_ns_delta": 3680777,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 341,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": 1952.2279379546053,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 342,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22822,
            "run_time_ns_delta": 44553746,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 343,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 344,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 345,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 346,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 347,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 348,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 349,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 350,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 351,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": 2724.2309214431766,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 352,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 15161,
            "run_time_ns_delta": 41302065,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 353,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 354,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "355": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 355,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 356,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 357,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "358": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 358,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": 1703.5393782155577,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 359,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22741,
            "run_time_ns_delta": 38740189,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 360,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 361,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 362,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 363,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 364,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": 151.90448968822832,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 365,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 22741,
            "run_time_ns_delta": 3454460,
            "type": "kprobe"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 366,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 367,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 368,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 369,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 370,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 371,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 372,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "373": {
            "avg_ns_per_run": 2264.49557444571,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 373,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22822,
            "run_time_ns_delta": 51680318,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 374,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 375,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 376,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 377,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 378,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 379,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": 2897.4599186755736,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 380,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6886,
            "run_time_ns_delta": 19951909,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": 2966.9431749486157,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 381,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8271,
            "run_time_ns_delta": 24539587,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 382,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 383,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 384,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 385,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 386,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 387,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 388,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 389,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 390,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 391,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 392,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 393,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 394,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 395,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 396,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": 9199.5,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 397,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 36798,
            "type": "kprobe"
          },
          "398": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 398,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 399,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 400,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 401,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 402,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 403,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": 1069.5141758216448,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 404,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 43419,
            "run_time_ns_delta": 46437236,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 405,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 406,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 407,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 408,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 409,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 410,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 411,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 412,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 413,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 414,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": 2460.2121023691293,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 415,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 112573,
            "run_time_ns_delta": 276953457,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 416,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": 130.56214084607117,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 417,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 112591,
            "run_time_ns_delta": 14700122,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 418,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 419,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "420": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 420,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "avg_ns_per_run": 7506.705710955711,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 421,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6864,
            "run_time_ns_delta": 51526028,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 422,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 423,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 424,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 425,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 426,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 427,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 428,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "avg_ns_per_run": 189.99825174825176,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 429,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 6864,
            "run_time_ns_delta": 1304148,
            "type": "kprobe"
          },
          "430": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 430,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 431,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 432,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 433,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "434": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 434,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": 9432.0,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 435,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 9432,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 436,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 437,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": 445.0,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 438,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 445,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 439,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 440,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 441,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 442,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 443,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 444,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 445,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 446,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 447,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 449,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 450,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 451,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 452,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 453,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 454,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 455,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 456,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 457,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 458,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 459,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 460,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 461,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 462,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 463,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 464,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 465,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 466,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "467": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 467,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 468,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 469,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 470,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "471": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 471,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "472": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 472,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "473": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 473,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "474": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 474,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 475,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 476,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 477,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": 6768.12,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 478,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 75,
            "run_time_ns_delta": 507609,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 479,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "480": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 480,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "481": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 481,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "482": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 482,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "483": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 483,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "484": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 484,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 11097,
            "bytes_xlated": 17992,
            "id": 485,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 486,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "487": {
            "avg_ns_per_run": 1471.2525576000367,
            "bytes_jited": 10903,
            "bytes_xlated": 19392,
            "id": 487,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 1723393,
            "run_time_ns_delta": 2535546359,
            "type": "tracepoint"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 488,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 4762,
            "bytes_xlated": 8504,
            "id": 489,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 14888,
            "bytes_xlated": 25720,
            "id": 490,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 491,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "492": {
            "avg_ns_per_run": null,
            "bytes_jited": 17083,
            "bytes_xlated": 29456,
            "id": 492,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "493": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 493,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 745,
            "bytes_xlated": 1176,
            "id": 494,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 495,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "496": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 496,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "497": {
            "avg_ns_per_run": 6180.08,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 497,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 75,
            "run_time_ns_delta": 463506,
            "type": "raw_tracepoint"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 498,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 499,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "500": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 500,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "501": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 501,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 502,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": 4106.099706744868,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 503,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1364,
            "run_time_ns_delta": 5600720,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 504,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 505,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": 11067.75225121219,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 506,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4331,
            "run_time_ns_delta": 47934435,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 507,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 508,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 509,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 510,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 511,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 512,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 513,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 514,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": 3782.1666666666665,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 515,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 45386,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 516,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 517,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 518,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 519,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 520,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 521,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 522,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 523,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 524,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": 1834.7840809146878,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 525,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22740,
            "run_time_ns_delta": 41722990,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 526,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 527,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 528,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": 154.71402814423922,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 529,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 22740,
            "run_time_ns_delta": 3518197,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 530,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": 2303.780509180141,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 531,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22821,
            "run_time_ns_delta": 52574575,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 532,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 533,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 534,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 535,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 536,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 537,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": 4698.074074074074,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 538,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 253696,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 539,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 540,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 541,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 542,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 543,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 544,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 545,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 546,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "547": {
            "avg_ns_per_run": 7783.285714285715,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 547,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 108966,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 548,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 549,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 550,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 551,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 552,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 553,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": 5745.75,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 554,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 22983,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 555,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 556,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 557,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 558,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 559,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 560,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": 3479.75,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 561,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 13919,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 562,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 563,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 564,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 565,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "566": {
            "avg_ns_per_run": 8123.6,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 566,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 81236,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 567,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 568,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 569,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 570,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 571,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 572,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 573,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 574,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": 7266.857142857143,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 575,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 101736,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 576,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 577,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 578,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 579,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 580,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 581,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 1892.4216202445652,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 582,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 23552,
            "run_time_ns_delta": 44570314,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 583,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 584,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 585,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 586,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 587,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 588,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 589,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 17.95024473000001,
            "ops_per_sec": 543.0566628269027,
            "ops_total": 9748.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [10593]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10593] sockdiag           1030      0.00      0.00      0.00    420983.54      515515.52\nstress-ng: info:  [10593] skipped: 0\nstress-ng: info:  [10593] passed: 1: sockdiag (1)\nstress-ng: info:  [10593] failed: 0\nstress-ng: info:  [10593] metrics untrustworthy: 0\nstress-ng: info:  [10593] successful run completed in 0.01 secs\nstress-ng: info:  [10595] setting to a 1 secs run per stressor\nstress-ng: info:  [10595] dispatching hogs: 1 sockfd\nstress-ng: info:  [10595] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10595] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10595]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10595] sockfd              200      0.05      0.01      0.01      4239.90       10964.91\nstress-ng: info:  [10595] skipped: 0\nstress-ng: info:  [10595] passed: 1: sockfd (1)\nstress-ng: info:  [10595] failed: 0\nstress-ng: info:  [10595] metrics untrustworthy: 0\nstress-ng: info:  [10595] successful run completed in 0.06 secs\nstress-ng: info:  [10598] setting to a 1 secs run per stressor\nstress-ng: info:  [10598] dispatching hogs: 1 sockpair\nstress-ng: info:  [10598] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10598] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10598]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10598] sockpair              0      1.95      0.03      0.75         0.00           0.00\nstress-ng: info:  [10598] skipped: 0\nstress-ng: info:  [10598] passed: 1: sockpair (1)\nstress-ng: info:  [10598] failed: 0\nstress-ng: info:  [10598] metrics untrustworthy: 0\nstress-ng: info:  [10598] successful run completed in 1.96 secs\nstress-ng: info:  [10601] setting to a 1 secs run per stressor\nstress-ng: info:  [10601] dispatching hogs: 1 udp-flood\nstress-ng: info:  [10601] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10601] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10601]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10601] udp-flood          1000      0.14      0.00      0.05      7360.11       18896.09\nstress-ng: info:  [10601] skipped: 0\nstress-ng: info:  [10601] passed: 1: udp-flood (1)\nstress-ng: info:  [10601] failed: 0\nstress-ng: info:  [10601] metrics untrustworthy: 0\nstress-ng: info:  [10601] successful run completed in 0.15 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 536,
            "bytes_xlated": 960,
            "id": 274,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 3344,
            "bytes_xlated": 5952,
            "id": 276,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 1189,
            "bytes_xlated": 1976,
            "id": 277,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 20,
            "bytes_xlated": 16,
            "id": 278,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 368,
            "bytes_xlated": 672,
            "id": 279,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 386,
            "bytes_xlated": 592,
            "id": 280,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 536,
            "bytes_xlated": 960,
            "id": 283,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 368,
            "bytes_xlated": 672,
            "id": 284,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 1189,
            "bytes_xlated": 1976,
            "id": 285,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 386,
            "bytes_xlated": 592,
            "id": 286,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 3098,
            "bytes_xlated": 5368,
            "id": 291,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 1189,
            "bytes_xlated": 1976,
            "id": 292,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 386,
            "bytes_xlated": 592,
            "id": 293,
            "name": "tail_handle_ipv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 368,
            "bytes_xlated": 672,
            "id": 296,
            "name": "tail_drop_notif",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "300": {
            "avg_ns_per_run": 1597.3013698630136,
            "bytes_jited": 1016,
            "bytes_xlated": 1792,
            "id": 300,
            "name": "event_exit_acct",
            "run_cnt_delta": 146,
            "run_time_ns_delta": 233206,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": 4676.697986577181,
            "bytes_jited": 7339,
            "bytes_xlated": 11312,
            "id": 302,
            "name": "event_wake_up_n",
            "run_cnt_delta": 149,
            "run_time_ns_delta": 696828,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": 9877.076923076924,
            "bytes_jited": 11245,
            "bytes_xlated": 20272,
            "id": 303,
            "name": "event_execve",
            "run_cnt_delta": 52,
            "run_time_ns_delta": 513608,
            "type": "tracepoint"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 1385,
            "bytes_xlated": 2352,
            "id": 304,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 5000,
            "bytes_xlated": 8064,
            "id": 305,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "306": {
            "avg_ns_per_run": 994.3461538461538,
            "bytes_jited": 1537,
            "bytes_xlated": 2560,
            "id": 306,
            "name": "tg_kp_bprm_comm",
            "run_cnt_delta": 52,
            "run_time_ns_delta": 51706,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 307,
            "bytes_xlated": 504,
            "id": 307,
            "name": "execve_map_upda",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "310": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 310,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 311,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 312,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 313,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 314,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 315,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 316,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 317,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 318,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 319,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 320,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 321,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 322,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 323,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 324,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 325,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 326,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 327,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 328,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 329,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 330,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": 1678.3940268485724,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 331,
            "name": "generic_kprobe_",
            "run_cnt_delta": 22869,
            "run_time_ns_delta": 38383193,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 332,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 333,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 334,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 335,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 336,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 337,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 338,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 339,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "avg_ns_per_run": 199.37098255280074,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 340,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 22869,
            "run_time_ns_delta": 4559415,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 341,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": 2043.4322372662798,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 342,
            "name": "generic_kprobe_",
            "run_cnt_delta": 23265,
            "run_time_ns_delta": 47540451,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 343,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 344,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 345,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 346,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 347,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 348,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 349,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 350,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 351,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": 2474.7859544442867,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 352,
            "name": "generic_kprobe_",
            "run_cnt_delta": 21117,
            "run_time_ns_delta": 52260055,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 353,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 354,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "355": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 355,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 356,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 357,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "358": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 358,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": 1669.7856486947396,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 359,
            "name": "generic_kprobe_",
            "run_cnt_delta": 22869,
            "run_time_ns_delta": 38186328,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 360,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 361,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 362,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 363,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 364,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": 185.48126284489922,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 365,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 22869,
            "run_time_ns_delta": 4241771,
            "type": "kprobe"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 366,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 367,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 368,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 369,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 370,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 371,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 372,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "373": {
            "avg_ns_per_run": 2353.6801633354826,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 373,
            "name": "generic_kprobe_",
            "run_cnt_delta": 23265,
            "run_time_ns_delta": 54758369,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 374,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 375,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 376,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 377,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 378,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 379,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": 2727.0770572542583,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 380,
            "name": "generic_kprobe_",
            "run_cnt_delta": 9746,
            "run_time_ns_delta": 26578093,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": 2730.1125670565475,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 381,
            "name": "generic_kprobe_",
            "run_cnt_delta": 11371,
            "run_time_ns_delta": 31044110,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 382,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 383,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 384,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 385,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 386,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 387,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 388,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 389,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 390,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 391,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 392,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 393,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 394,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 395,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 396,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 397,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "398": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 398,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 399,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 400,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 401,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 402,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 403,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": 1066.622031014069,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 404,
            "name": "generic_kprobe_",
            "run_cnt_delta": 41723,
            "run_time_ns_delta": 44502671,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 405,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 406,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 407,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 408,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 409,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 410,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 411,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 412,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 413,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 414,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": 2552.8581168624287,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 415,
            "name": "generic_kprobe_",
            "run_cnt_delta": 94162,
            "run_time_ns_delta": 240382226,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 416,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": 145.69743910984647,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 417,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 94186,
            "run_time_ns_delta": 13722659,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 418,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 419,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "420": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 420,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "avg_ns_per_run": 8699.976841306,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 421,
            "name": "generic_kprobe_",
            "run_cnt_delta": 5268,
            "run_time_ns_delta": 45831478,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 422,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 423,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 424,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 425,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 426,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 427,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 428,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "avg_ns_per_run": 183.47456340167045,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 429,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 5268,
            "run_time_ns_delta": 966544,
            "type": "kprobe"
          },
          "430": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 430,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 431,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 432,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 433,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "434": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 434,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 435,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 436,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 437,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 438,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 439,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 440,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 441,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 442,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 443,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 444,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 445,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 446,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 447,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 449,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 450,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 451,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 452,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 453,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 454,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 455,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 456,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 457,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 458,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 459,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 460,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 461,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 462,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 463,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 464,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 465,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 466,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "467": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 467,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 468,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 469,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 470,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "471": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 471,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "472": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 472,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "473": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 473,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "474": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 474,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 475,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 476,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 477,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": 6580.823529411765,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 478,
            "name": "generic_kprobe_",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 335622,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 479,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "480": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 480,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "481": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 481,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "482": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 482,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "483": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 483,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "484": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 484,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 11097,
            "bytes_xlated": 17992,
            "id": 485,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 486,
            "name": "generic_tracepo",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "487": {
            "avg_ns_per_run": 1563.3663323336486,
            "bytes_jited": 10903,
            "bytes_xlated": 19392,
            "id": 487,
            "name": "generic_tracepo",
            "run_cnt_delta": 1558825,
            "run_time_ns_delta": 2437014523,
            "type": "tracepoint"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 488,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 4762,
            "bytes_xlated": 8504,
            "id": 489,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 14888,
            "bytes_xlated": 25720,
            "id": 490,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 491,
            "name": "generic_rawtp_o",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "492": {
            "avg_ns_per_run": null,
            "bytes_jited": 17083,
            "bytes_xlated": 29456,
            "id": 492,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "493": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 493,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 745,
            "bytes_xlated": 1176,
            "id": 494,
            "name": "generic_rawtp_s",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 495,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "496": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 496,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "497": {
            "avg_ns_per_run": 6213.254901960784,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 497,
            "name": "generic_rawtp_e",
            "run_cnt_delta": 51,
            "run_time_ns_delta": 316876,
            "type": "raw_tracepoint"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 498,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 499,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "500": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 500,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "501": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 501,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 502,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": 4756.87648673376,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 503,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1093,
            "run_time_ns_delta": 5199266,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 504,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 505,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": 11317.322091062395,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 506,
            "name": "generic_kprobe_",
            "run_cnt_delta": 3558,
            "run_time_ns_delta": 40267032,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 507,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 508,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 509,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 510,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 511,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 512,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 513,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 514,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 515,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 516,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 517,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 518,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 519,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 520,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 521,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 522,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 523,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 524,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": 1755.9608023474796,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 525,
            "name": "generic_kprobe_",
            "run_cnt_delta": 22833,
            "run_time_ns_delta": 40093853,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 526,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 527,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 528,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": 193.26558051942365,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 529,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 22833,
            "run_time_ns_delta": 4412833,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 530,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": 2416.485944293771,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 531,
            "name": "generic_kprobe_",
            "run_cnt_delta": 23229,
            "run_time_ns_delta": 56132552,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 532,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 533,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 534,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 535,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 536,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 537,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": 4830.379310344828,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 538,
            "name": "generic_kprobe_",
            "run_cnt_delta": 29,
            "run_time_ns_delta": 140081,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 539,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 540,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 541,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 542,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 543,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 544,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 545,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 546,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "547": {
            "avg_ns_per_run": 7596.0,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 547,
            "name": "generic_kprobe_",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 60768,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 548,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 549,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 550,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 551,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 552,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 553,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": 5833.666666666667,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 554,
            "name": "generic_kprobe_",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 17501,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 555,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 556,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 557,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": null,
            "bytes_jited": 803,
            "bytes_xlated": 1360,
            "id": 558,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": null,
            "bytes_jited": 3778,
            "bytes_xlated": 6688,
            "id": 559,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 10641,
            "bytes_xlated": 17344,
            "id": 560,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": 3029.0,
            "bytes_jited": 14051,
            "bytes_xlated": 24744,
            "id": 561,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 9087,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 562,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 563,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 564,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 565,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "566": {
            "avg_ns_per_run": 9282.5,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 566,
            "name": "generic_kprobe_",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 37130,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 567,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 568,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 569,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 570,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 571,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 572,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 573,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 574,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": 8155.375,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 575,
            "name": "generic_kprobe_",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 65243,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 576,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 577,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 578,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 579,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 580,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 581,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 1983.0793507664562,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 582,
            "name": "generic_kprobe_",
            "run_cnt_delta": 19962,
            "run_time_ns_delta": 39586230,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": null,
            "bytes_jited": 1317,
            "bytes_xlated": 2240,
            "id": 583,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": null,
            "bytes_jited": 17173,
            "bytes_xlated": 29456,
            "id": 584,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": null,
            "bytes_jited": 10736,
            "bytes_xlated": 17544,
            "id": 585,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": null,
            "bytes_jited": 1881,
            "bytes_xlated": 3160,
            "id": 586,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": null,
            "bytes_jited": 11094,
            "bytes_xlated": 17992,
            "id": 587,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 4901,
            "bytes_xlated": 8752,
            "id": 588,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": null,
            "bytes_jited": 1726,
            "bytes_xlated": 3056,
            "id": 589,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 17.66253739900003,
            "ops_per_sec": 512.8934645886654,
            "ops_total": 9059.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [21505]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21505] sockdiag           1030      0.00      0.00      0.00   1288822.53      527663.93\nstress-ng: info:  [21505] skipped: 0\nstress-ng: info:  [21505] passed: 1: sockdiag (1)\nstress-ng: info:  [21505] failed: 0\nstress-ng: info:  [21505] metrics untrustworthy: 0\nstress-ng: info:  [21505] successful run completed in 0.00 secs\nstress-ng: info:  [21507] setting to a 1 secs run per stressor\nstress-ng: info:  [21507] dispatching hogs: 1 sockfd\nstress-ng: info:  [21507] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21507] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21507]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21507] sockfd              200      0.06      0.00      0.02      3601.76       10278.55\nstress-ng: info:  [21507] skipped: 0\nstress-ng: info:  [21507] passed: 1: sockfd (1)\nstress-ng: info:  [21507] failed: 0\nstress-ng: info:  [21507] metrics untrustworthy: 0\nstress-ng: info:  [21507] successful run completed in 0.07 secs\nstress-ng: info:  [21510] setting to a 1 secs run per stressor\nstress-ng: info:  [21510] dispatching hogs: 1 sockpair\nstress-ng: info:  [21510] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21510] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21510]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21510] sockpair              0      1.86      0.01      0.80         0.00           0.00\nstress-ng: info:  [21510] skipped: 0\nstress-ng: info:  [21510] passed: 1: sockpair (1)\nstress-ng: info:  [21510] failed: 0\nstress-ng: info:  [21510] metrics untrustworthy: 0\nstress-ng: info:  [21510] successful run completed in 1.88 secs\nstress-ng: info:  [21513] setting to a 1 secs run per stressor\nstress-ng: info:  [21513] dispatching hogs: 1 udp-flood\nstress-ng: info:  [21513] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21513] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21513]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21513] udp-flood          1000      0.10      0.00      0.05      9807.54       21754.26\nstress-ng: info:  [21513] skipped: 0\nstress-ng: info:  [21513] passed: 1: udp-flood (1)\nstress-ng: info:  [21513] failed: 0\nstress-ng: info:  [21513] metrics untrustworthy: 0\nstress-ng: info:  [21513] successful run completed in 0.11 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 301,
          "requested": 301
        }
      },
      "runner": "tetragon",
      "selected_workload": "stress_ng_os_io_network",
      "status": "ok"
    },
    {
      "app": "katran",
      "baseline": {
        "bpf": {
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 180,
            "bytes_xlated": 136,
            "id": 596,
            "name": "xdp_root",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "602": {
            "avg_ns_per_run": 88.36848958333333,
            "bytes_jited": 13641,
            "bytes_xlated": 23840,
            "id": 602,
            "name": "balancer_ingress",
            "run_cnt_delta": 1536,
            "run_time_ns_delta": 135734,
            "type": "xdp"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 545,
            "bytes_xlated": 1000,
            "id": 604,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.084416559000033,
            "ops_per_sec": 1416.4298647526953,
            "ops_total": 1536.0,
            "stderr": "{'retval': 2, 'duration_ns': 125, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 180,
            "bytes_xlated": 136,
            "id": 596,
            "name": "xdp_root",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "602": {
            "avg_ns_per_run": 79.875,
            "bytes_jited": 13641,
            "bytes_xlated": 23840,
            "id": 602,
            "name": "balancer_ingress",
            "run_cnt_delta": 1536,
            "run_time_ns_delta": 122688,
            "type": "xdp"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 545,
            "bytes_xlated": 1000,
            "id": 604,
            "name": "healthcheck_enc",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0291304940001282,
            "ops_per_sec": 1492.522094092966,
            "ops_total": 1536.0,
            "stderr": "{'retval': 2, 'duration_ns': 120, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 3,
          "requested": 3
        }
      },
      "runner": "katran",
      "selected_workload": "test_run",
      "status": "ok"
    },
    {
      "app": "tracee/monitor",
      "baseline": {
        "bpf": {
          "619": {
            "avg_ns_per_run": 709.1299703639855,
            "bytes_jited": 240,
            "bytes_xlated": 264,
            "id": 619,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 1389863,
            "run_time_ns_delta": 985593508,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": null,
            "bytes_jited": 2521,
            "bytes_xlated": 4552,
            "id": 620,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "621": {
            "avg_ns_per_run": null,
            "bytes_jited": 17452,
            "bytes_xlated": 30376,
            "id": 621,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "622": {
            "avg_ns_per_run": 1636.2060805268293,
            "bytes_jited": 269,
            "bytes_xlated": 320,
            "id": 622,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 1389748,
            "run_time_ns_delta": 2273914128,
            "type": "raw_tracepoint"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 2101,
            "bytes_xlated": 3800,
            "id": 623,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 11589,
            "bytes_xlated": 19880,
            "id": 624,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "625": {
            "avg_ns_per_run": 1285.497967659496,
            "bytes_jited": 8160,
            "bytes_xlated": 13688,
            "id": 625,
            "name": "trace_sys_enter",
            "run_cnt_delta": 1390269,
            "run_time_ns_delta": 1787187974,
            "type": "raw_tracepoint"
          },
          "626": {
            "avg_ns_per_run": 1287.9213486136125,
            "bytes_jited": 8193,
            "bytes_xlated": 13744,
            "id": 626,
            "name": "trace_sys_exit",
            "run_cnt_delta": 1390376,
            "run_time_ns_delta": 1790694933,
            "type": "raw_tracepoint"
          },
          "627": {
            "avg_ns_per_run": null,
            "bytes_jited": 2360,
            "bytes_xlated": 4424,
            "id": 627,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": null,
            "bytes_jited": 11323,
            "bytes_xlated": 19504,
            "id": 628,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": null,
            "bytes_jited": 2360,
            "bytes_xlated": 4424,
            "id": 629,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": null,
            "bytes_jited": 11323,
            "bytes_xlated": 19504,
            "id": 630,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": 187.94213866819436,
            "bytes_jited": 2360,
            "bytes_xlated": 4424,
            "id": 631,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 66331,
            "run_time_ns_delta": 12466390,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": 752.6357811581312,
            "bytes_jited": 11323,
            "bytes_xlated": 19504,
            "id": 632,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 66331,
            "run_time_ns_delta": 49923084,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 1203.5,
            "bytes_jited": 2360,
            "bytes_xlated": 4424,
            "id": 633,
            "name": "trace_dup",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2407,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 5562.0,
            "bytes_jited": 11323,
            "bytes_xlated": 19504,
            "id": 634,
            "name": "trace_ret_dup",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11124,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 872.0898876404494,
            "bytes_jited": 2360,
            "bytes_xlated": 4424,
            "id": 635,
            "name": "trace_dup2",
            "run_cnt_delta": 89,
            "run_time_ns_delta": 77616,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 3091.438202247191,
            "bytes_jited": 11323,
            "bytes_xlated": 19504,
            "id": 636,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 89,
            "run_time_ns_delta": 275138,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": 638.9444444444445,
            "bytes_jited": 2360,
            "bytes_xlated": 4424,
            "id": 637,
            "name": "trace_dup3",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 23002,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": 3015.8611111111113,
            "bytes_jited": 11323,
            "bytes_xlated": 19504,
            "id": 638,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 36,
            "run_time_ns_delta": 108571,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": null,
            "bytes_jited": 20738,
            "bytes_xlated": 31992,
            "id": 639,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "640": {
            "avg_ns_per_run": null,
            "bytes_jited": 20709,
            "bytes_xlated": 32008,
            "id": 640,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "641": {
            "avg_ns_per_run": null,
            "bytes_jited": 21001,
            "bytes_xlated": 32400,
            "id": 641,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "642": {
            "avg_ns_per_run": null,
            "bytes_jited": 20969,
            "bytes_xlated": 32408,
            "id": 642,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "643": {
            "avg_ns_per_run": null,
            "bytes_jited": 12300,
            "bytes_xlated": 18744,
            "id": 643,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": 8086.132450331126,
            "bytes_jited": 19726,
            "bytes_xlated": 32248,
            "id": 644,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 302,
            "run_time_ns_delta": 2442012,
            "type": "raw_tracepoint"
          },
          "645": {
            "avg_ns_per_run": null,
            "bytes_jited": 59270,
            "bytes_xlated": 108072,
            "id": 645,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": null,
            "bytes_jited": 6236,
            "bytes_xlated": 10320,
            "id": 646,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": null,
            "bytes_jited": 4345,
            "bytes_xlated": 7784,
            "id": 647,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": null,
            "bytes_jited": 62313,
            "bytes_xlated": 111768,
            "id": 648,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": null,
            "bytes_jited": 656,
            "bytes_xlated": 1048,
            "id": 649,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": null,
            "bytes_jited": 57795,
            "bytes_xlated": 102120,
            "id": 650,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": null,
            "bytes_jited": 3893,
            "bytes_xlated": 6456,
            "id": 651,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "652": {
            "avg_ns_per_run": 9867.972972972973,
            "bytes_jited": 20560,
            "bytes_xlated": 35424,
            "id": 652,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 37,
            "run_time_ns_delta": 365115,
            "type": "raw_tracepoint"
          },
          "653": {
            "avg_ns_per_run": null,
            "bytes_jited": 24438,
            "bytes_xlated": 38432,
            "id": 653,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "654": {
            "avg_ns_per_run": 6437.602649006622,
            "bytes_jited": 8704,
            "bytes_xlated": 14536,
            "id": 654,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 302,
            "run_time_ns_delta": 1944156,
            "type": "raw_tracepoint"
          },
          "655": {
            "avg_ns_per_run": 2292.2615894039736,
            "bytes_jited": 252,
            "bytes_xlated": 440,
            "id": 655,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 302,
            "run_time_ns_delta": 692263,
            "type": "raw_tracepoint"
          },
          "656": {
            "avg_ns_per_run": null,
            "bytes_jited": 9163,
            "bytes_xlated": 13888,
            "id": 656,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "657": {
            "avg_ns_per_run": 1746.6175895338718,
            "bytes_jited": 8949,
            "bytes_xlated": 14912,
            "id": 657,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 213718,
            "run_time_ns_delta": 373283618,
            "type": "raw_tracepoint"
          },
          "658": {
            "avg_ns_per_run": 50.87291342087692,
            "bytes_jited": 8205,
            "bytes_xlated": 13776,
            "id": 658,
            "name": "trace_filldir64",
            "run_cnt_delta": 4493,
            "run_time_ns_delta": 228572,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": null,
            "bytes_jited": 23527,
            "bytes_xlated": 36784,
            "id": 659,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": 2562.655629139073,
            "bytes_jited": 7963,
            "bytes_xlated": 13408,
            "id": 660,
            "name": "trace_do_exit",
            "run_cnt_delta": 302,
            "run_time_ns_delta": 773922,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": null,
            "bytes_jited": 56307,
            "bytes_xlated": 97056,
            "id": 661,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": null,
            "bytes_jited": 6792,
            "bytes_xlated": 11256,
            "id": 662,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": null,
            "bytes_jited": 6557,
            "bytes_xlated": 10976,
            "id": 663,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 714.8359375,
            "bytes_jited": 11480,
            "bytes_xlated": 18328,
            "id": 664,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 1408,
            "run_time_ns_delta": 1006489,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": null,
            "bytes_jited": 9751,
            "bytes_xlated": 15688,
            "id": 665,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": 5058.0,
            "bytes_jited": 8653,
            "bytes_xlated": 14440,
            "id": 666,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 5058,
            "type": "raw_tracepoint"
          },
          "667": {
            "avg_ns_per_run": 3962.0,
            "bytes_jited": 8628,
            "bytes_xlated": 14416,
            "id": 667,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3962,
            "type": "raw_tracepoint"
          },
          "668": {
            "avg_ns_per_run": 2905.0,
            "bytes_jited": 8628,
            "bytes_xlated": 14416,
            "id": 668,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2905,
            "type": "raw_tracepoint"
          },
          "669": {
            "avg_ns_per_run": 5949.55,
            "bytes_jited": 33403,
            "bytes_xlated": 52904,
            "id": 669,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 40,
            "run_time_ns_delta": 237982,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 3381.791415839262,
            "bytes_jited": 22989,
            "bytes_xlated": 37160,
            "id": 670,
            "name": "trace_security_file_open",
            "run_cnt_delta": 12791,
            "run_time_ns_delta": 43256494,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": null,
            "bytes_jited": 18657,
            "bytes_xlated": 30680,
            "id": 671,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "672": {
            "avg_ns_per_run": 3879.6,
            "bytes_jited": 10001,
            "bytes_xlated": 16416,
            "id": 672,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 19398,
            "type": "kprobe"
          },
          "673": {
            "avg_ns_per_run": 1454.6022637795274,
            "bytes_jited": 10749,
            "bytes_xlated": 16960,
            "id": 673,
            "name": "trace_commit_creds",
            "run_cnt_delta": 10160,
            "run_time_ns_delta": 14778759,
            "type": "kprobe"
          },
          "674": {
            "avg_ns_per_run": 1484.0662251655629,
            "bytes_jited": 10038,
            "bytes_xlated": 16552,
            "id": 674,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 302,
            "run_time_ns_delta": 448188,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": 979.9697256385998,
            "bytes_jited": 8203,
            "bytes_xlated": 13760,
            "id": 675,
            "name": "trace_cap_capable",
            "run_cnt_delta": 46508,
            "run_time_ns_delta": 45576432,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": 3227.8342696629215,
            "bytes_jited": 8482,
            "bytes_xlated": 14176,
            "id": 676,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 356,
            "run_time_ns_delta": 1149109,
            "type": "kprobe"
          },
          "677": {
            "avg_ns_per_run": 3857.0,
            "bytes_jited": 9221,
            "bytes_xlated": 15344,
            "id": 677,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3857,
            "type": "kprobe"
          },
          "678": {
            "avg_ns_per_run": null,
            "bytes_jited": 8305,
            "bytes_xlated": 13904,
            "id": 678,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": null,
            "bytes_jited": 9527,
            "bytes_xlated": 15840,
            "id": 679,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "680": {
            "avg_ns_per_run": null,
            "bytes_jited": 9239,
            "bytes_xlated": 15424,
            "id": 680,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "681": {
            "avg_ns_per_run": null,
            "bytes_jited": 10841,
            "bytes_xlated": 16632,
            "id": 681,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "682": {
            "avg_ns_per_run": 3511.7638888888887,
            "bytes_jited": 10097,
            "bytes_xlated": 15472,
            "id": 682,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 288,
            "run_time_ns_delta": 1011388,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": 5394.830409356725,
            "bytes_jited": 11324,
            "bytes_xlated": 17368,
            "id": 683,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 171,
            "run_time_ns_delta": 922516,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 1772.5641025641025,
            "bytes_jited": 10610,
            "bytes_xlated": 16152,
            "id": 684,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 39,
            "run_time_ns_delta": 69130,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 3820.3502304147464,
            "bytes_jited": 11076,
            "bytes_xlated": 17024,
            "id": 685,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 217,
            "run_time_ns_delta": 829016,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": null,
            "bytes_jited": 953,
            "bytes_xlated": 1568,
            "id": 686,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": null,
            "bytes_jited": 953,
            "bytes_xlated": 1568,
            "id": 687,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "688": {
            "avg_ns_per_run": 250.70566746686148,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 688,
            "name": "trace_vfs_write",
            "run_cnt_delta": 76648,
            "run_time_ns_delta": 19216088,
            "type": "kprobe"
          },
          "689": {
            "avg_ns_per_run": 137.11229269692976,
            "bytes_jited": 283,
            "bytes_xlated": 432,
            "id": 689,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 76639,
            "run_time_ns_delta": 10508149,
            "type": "kprobe"
          },
          "690": {
            "avg_ns_per_run": 2104.8270974982706,
            "bytes_jited": 19143,
            "bytes_xlated": 31808,
            "id": 690,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 76627,
            "run_time_ns_delta": 161286586,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": 117.36874779909486,
            "bytes_jited": 23808,
            "bytes_xlated": 36792,
            "id": 691,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 76673,
            "run_time_ns_delta": 8999014,
            "type": "kprobe"
          },
          "692": {
            "avg_ns_per_run": null,
            "bytes_jited": 29925,
            "bytes_xlated": 51704,
            "id": 692,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "693": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 693,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": null,
            "bytes_jited": 283,
            "bytes_xlated": 432,
            "id": 694,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31800,
            "id": 695,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": null,
            "bytes_jited": 24544,
            "bytes_xlated": 37648,
            "id": 696,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": null,
            "bytes_jited": 29849,
            "bytes_xlated": 51680,
            "id": 697,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 698,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": null,
            "bytes_jited": 283,
            "bytes_xlated": 432,
            "id": 699,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": null,
            "bytes_jited": 19146,
            "bytes_xlated": 31808,
            "id": 700,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": null,
            "bytes_jited": 23808,
            "bytes_xlated": 36792,
            "id": 701,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "702": {
            "avg_ns_per_run": null,
            "bytes_jited": 29925,
            "bytes_xlated": 51704,
            "id": 702,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "703": {
            "avg_ns_per_run": 265.6067175751192,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 703,
            "name": "trace_vfs_read",
            "run_cnt_delta": 34179,
            "run_time_ns_delta": 9078172,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 2825.652811072414,
            "bytes_jited": 19146,
            "bytes_xlated": 31808,
            "id": 704,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 22109,
            "run_time_ns_delta": 62472358,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": null,
            "bytes_jited": 17168,
            "bytes_xlated": 29848,
            "id": 705,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 706,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31800,
            "id": 707,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": null,
            "bytes_jited": 17896,
            "bytes_xlated": 30816,
            "id": 708,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 715.5805904309467,
            "bytes_jited": 20746,
            "bytes_xlated": 32864,
            "id": 709,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 2947,
            "run_time_ns_delta": 2108816,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 242.09991039426524,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 710,
            "name": "trace_do_mmap",
            "run_cnt_delta": 2232,
            "run_time_ns_delta": 540367,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 2707.0631720430106,
            "bytes_jited": 19586,
            "bytes_xlated": 31944,
            "id": 711,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 2232,
            "run_time_ns_delta": 6042165,
            "type": "kprobe"
          },
          "712": {
            "avg_ns_per_run": 2807.2347670250897,
            "bytes_jited": 36988,
            "bytes_xlated": 60888,
            "id": 712,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 2232,
            "run_time_ns_delta": 6265748,
            "type": "kprobe"
          },
          "713": {
            "avg_ns_per_run": 3737.675294117647,
            "bytes_jited": 34616,
            "bytes_xlated": 59616,
            "id": 713,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 425,
            "run_time_ns_delta": 1588512,
            "type": "kprobe"
          },
          "714": {
            "avg_ns_per_run": null,
            "bytes_jited": 626,
            "bytes_xlated": 1000,
            "id": 714,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "715": {
            "avg_ns_per_run": 1694.3406294164283,
            "bytes_jited": 15624,
            "bytes_xlated": 26984,
            "id": 715,
            "name": "trace_security_bpf",
            "run_cnt_delta": 29011,
            "run_time_ns_delta": 49154516,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 716,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": null,
            "bytes_jited": 8830,
            "bytes_xlated": 14712,
            "id": 717,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 1592.9613930034668,
            "bytes_jited": 8366,
            "bytes_xlated": 13992,
            "id": 718,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 6346,
            "run_time_ns_delta": 10108933,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 5100.641263940521,
            "bytes_jited": 9605,
            "bytes_xlated": 15520,
            "id": 719,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 538,
            "run_time_ns_delta": 2744145,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": null,
            "bytes_jited": 6380,
            "bytes_xlated": 10616,
            "id": 720,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": null,
            "bytes_jited": 6616,
            "bytes_xlated": 11096,
            "id": 721,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "722": {
            "avg_ns_per_run": null,
            "bytes_jited": 6622,
            "bytes_xlated": 11104,
            "id": 722,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "723": {
            "avg_ns_per_run": null,
            "bytes_jited": 18654,
            "bytes_xlated": 30720,
            "id": 723,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "724": {
            "avg_ns_per_run": null,
            "bytes_jited": 17289,
            "bytes_xlated": 30536,
            "id": 724,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "725": {
            "avg_ns_per_run": 4236.0,
            "bytes_jited": 9255,
            "bytes_xlated": 15432,
            "id": 725,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4236,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": null,
            "bytes_jited": 8689,
            "bytes_xlated": 14440,
            "id": 726,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "727": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 727,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": null,
            "bytes_jited": 8832,
            "bytes_xlated": 14704,
            "id": 728,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": null,
            "bytes_jited": 19888,
            "bytes_xlated": 32720,
            "id": 729,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "730": {
            "avg_ns_per_run": null,
            "bytes_jited": 9008,
            "bytes_xlated": 15024,
            "id": 730,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "731": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 731,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": null,
            "bytes_jited": 14591,
            "bytes_xlated": 24016,
            "id": 732,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "733": {
            "avg_ns_per_run": 3810.324324324324,
            "bytes_jited": 18497,
            "bytes_xlated": 30424,
            "id": 733,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 74,
            "run_time_ns_delta": 281964,
            "type": "kprobe"
          },
          "734": {
            "avg_ns_per_run": 182.93014738802628,
            "bytes_jited": 8723,
            "bytes_xlated": 14592,
            "id": 734,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 111678,
            "run_time_ns_delta": 20429273,
            "type": "kprobe"
          },
          "735": {
            "avg_ns_per_run": 3506.7190332326286,
            "bytes_jited": 8516,
            "bytes_xlated": 14208,
            "id": 735,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 331,
            "run_time_ns_delta": 1160724,
            "type": "raw_tracepoint"
          },
          "736": {
            "avg_ns_per_run": 3595.4444444444443,
            "bytes_jited": 9841,
            "bytes_xlated": 16448,
            "id": 736,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 32359,
            "type": "kprobe"
          },
          "737": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 737,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "738": {
            "avg_ns_per_run": null,
            "bytes_jited": 8435,
            "bytes_xlated": 14104,
            "id": 738,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 3264.7679449360867,
            "bytes_jited": 10074,
            "bytes_xlated": 16296,
            "id": 739,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 2034,
            "run_time_ns_delta": 6640538,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": null,
            "bytes_jited": 18581,
            "bytes_xlated": 30600,
            "id": 740,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": null,
            "bytes_jited": 18581,
            "bytes_xlated": 30600,
            "id": 741,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 4319.25,
            "bytes_jited": 9554,
            "bytes_xlated": 15896,
            "id": 742,
            "name": "trace_do_truncate",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 51831,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 1153.0893051416679,
            "bytes_jited": 17009,
            "bytes_xlated": 27568,
            "id": 743,
            "name": "trace_fd_install",
            "run_cnt_delta": 21141,
            "run_time_ns_delta": 24377461,
            "type": "kprobe"
          },
          "744": {
            "avg_ns_per_run": 1788.775241779497,
            "bytes_jited": 16937,
            "bytes_xlated": 27416,
            "id": 744,
            "name": "trace_filp_close",
            "run_cnt_delta": 2585,
            "run_time_ns_delta": 4623984,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 468.8301886792453,
            "bytes_jited": 473,
            "bytes_xlated": 784,
            "id": 745,
            "name": "trace_file_update_time",
            "run_cnt_delta": 530,
            "run_time_ns_delta": 248480,
            "type": "kprobe"
          },
          "746": {
            "avg_ns_per_run": 1717.4962264150943,
            "bytes_jited": 20049,
            "bytes_xlated": 31224,
            "id": 746,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 530,
            "run_time_ns_delta": 910273,
            "type": "kprobe"
          },
          "747": {
            "avg_ns_per_run": null,
            "bytes_jited": 487,
            "bytes_xlated": 800,
            "id": 747,
            "name": "trace_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "748": {
            "avg_ns_per_run": null,
            "bytes_jited": 20184,
            "bytes_xlated": 31400,
            "id": 748,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "749": {
            "avg_ns_per_run": 715.0,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 749,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1430,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": 4120.0,
            "bytes_jited": 18065,
            "bytes_xlated": 30032,
            "id": 750,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8240,
            "type": "kprobe"
          },
          "751": {
            "avg_ns_per_run": null,
            "bytes_jited": 12891,
            "bytes_xlated": 20216,
            "id": 751,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "752": {
            "avg_ns_per_run": 216.0810810810811,
            "bytes_jited": 16507,
            "bytes_xlated": 28960,
            "id": 752,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 37,
            "run_time_ns_delta": 7995,
            "type": "kprobe"
          },
          "753": {
            "avg_ns_per_run": 7395.459459459459,
            "bytes_jited": 16718,
            "bytes_xlated": 29144,
            "id": 753,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 37,
            "run_time_ns_delta": 273632,
            "type": "kprobe"
          },
          "754": {
            "avg_ns_per_run": 7840.2972972972975,
            "bytes_jited": 24499,
            "bytes_xlated": 38400,
            "id": 754,
            "name": "trace_execute_finished",
            "run_cnt_delta": 37,
            "run_time_ns_delta": 290091,
            "type": "kprobe"
          },
          "755": {
            "avg_ns_per_run": 4378.0,
            "bytes_jited": 18412,
            "bytes_xlated": 30272,
            "id": 755,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8756,
            "type": "kprobe"
          },
          "756": {
            "avg_ns_per_run": 5478.8,
            "bytes_jited": 18271,
            "bytes_xlated": 30048,
            "id": 756,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 54788,
            "type": "kprobe"
          },
          "757": {
            "avg_ns_per_run": 1573.7432043975996,
            "bytes_jited": 8649,
            "bytes_xlated": 14424,
            "id": 757,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 19829,
            "run_time_ns_delta": 31205754,
            "type": "kprobe"
          },
          "758": {
            "avg_ns_per_run": null,
            "bytes_jited": 8674,
            "bytes_xlated": 14480,
            "id": 758,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "759": {
            "avg_ns_per_run": 4468.125,
            "bytes_jited": 17600,
            "bytes_xlated": 29272,
            "id": 759,
            "name": "trace_chmod_common",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 35745,
            "type": "kprobe"
          },
          "760": {
            "avg_ns_per_run": 1042.7026355733408,
            "bytes_jited": 47186,
            "bytes_xlated": 76688,
            "id": 760,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 21741,
            "run_time_ns_delta": 22669398,
            "type": "kprobe"
          },
          "761": {
            "avg_ns_per_run": null,
            "bytes_jited": 14934,
            "bytes_xlated": 24112,
            "id": 761,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "762": {
            "avg_ns_per_run": null,
            "bytes_jited": 9525,
            "bytes_xlated": 15856,
            "id": 762,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "763": {
            "avg_ns_per_run": 834.7058823529412,
            "bytes_jited": 335,
            "bytes_xlated": 528,
            "id": 763,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 527,
            "run_time_ns_delta": 439890,
            "type": "kprobe"
          },
          "764": {
            "avg_ns_per_run": 2737.0360531309298,
            "bytes_jited": 8652,
            "bytes_xlated": 13456,
            "id": 764,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 527,
            "run_time_ns_delta": 1442418,
            "type": "kprobe"
          },
          "765": {
            "avg_ns_per_run": 713.0,
            "bytes_jited": 348,
            "bytes_xlated": 592,
            "id": 765,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 713,
            "type": "kprobe"
          },
          "766": {
            "avg_ns_per_run": 903.3709543568465,
            "bytes_jited": 8899,
            "bytes_xlated": 13696,
            "id": 766,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 1205,
            "run_time_ns_delta": 1088562,
            "type": "kprobe"
          },
          "767": {
            "avg_ns_per_run": 1317.7612359550562,
            "bytes_jited": 8899,
            "bytes_xlated": 13696,
            "id": 767,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 712,
            "run_time_ns_delta": 938246,
            "type": "kprobe"
          },
          "768": {
            "avg_ns_per_run": 1781.0280269058296,
            "bytes_jited": 5672,
            "bytes_xlated": 8808,
            "id": 768,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 892,
            "run_time_ns_delta": 1588677,
            "type": "kprobe"
          },
          "770": {
            "avg_ns_per_run": 2917.3534136546186,
            "bytes_jited": 19664,
            "bytes_xlated": 31088,
            "id": 770,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 249,
            "run_time_ns_delta": 726421,
            "type": "cgroup_skb"
          },
          "771": {
            "avg_ns_per_run": 3914.0238095238096,
            "bytes_jited": 19664,
            "bytes_xlated": 31088,
            "id": 771,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 252,
            "run_time_ns_delta": 986334,
            "type": "cgroup_skb"
          },
          "772": {
            "avg_ns_per_run": 2808.0,
            "bytes_jited": 932,
            "bytes_xlated": 1584,
            "id": 772,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2808,
            "type": "raw_tracepoint"
          },
          "773": {
            "avg_ns_per_run": 2083.0,
            "bytes_jited": 914,
            "bytes_xlated": 1544,
            "id": 773,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2083,
            "type": "raw_tracepoint"
          },
          "774": {
            "avg_ns_per_run": 119.05,
            "bytes_jited": 20,
            "bytes_xlated": 16,
            "id": 774,
            "name": "empty_kprobe",
            "run_cnt_delta": 40,
            "run_time_ns_delta": 4762,
            "type": "kprobe"
          },
          "775": {
            "avg_ns_per_run": 1705.1081081081081,
            "bytes_jited": 58697,
            "bytes_xlated": 96032,
            "id": 775,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 37,
            "run_time_ns_delta": 63089,
            "type": "raw_tracepoint"
          },
          "776": {
            "avg_ns_per_run": 1496.5408426483234,
            "bytes_jited": 7332,
            "bytes_xlated": 13360,
            "id": 776,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 12793,
            "run_time_ns_delta": 19145247,
            "type": "lsm"
          },
          "777": {
            "avg_ns_per_run": null,
            "bytes_jited": 5388,
            "bytes_xlated": 9160,
            "id": 777,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 14.206247503999975,
            "ops_per_sec": 385.46421202771194,
            "ops_total": 5476.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [10881]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10881] get                 200      3.31      0.03      0.85        60.36         226.86\nstress-ng: info:  [10881] skipped: 0\nstress-ng: info:  [10881] passed: 1: get (1)\nstress-ng: info:  [10881] failed: 0\nstress-ng: info:  [10881] metrics untrustworthy: 0\nstress-ng: info:  [10881] successful run completed in 3.32 secs\nstress-ng: info:  [10883] setting to a 5 secs run per stressor\nstress-ng: info:  [10883] dispatching hogs: 1 prctl\nstress-ng: info:  [10883] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10883] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10883]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10883] prctl               252      5.00      0.47      0.32        50.41         318.98\nstress-ng: info:  [10883] skipped: 0\nstress-ng: info:  [10883] passed: 1: prctl (1)\nstress-ng: info:  [10883] failed: 0\nstress-ng: info:  [10883] metrics untrustworthy: 0\nstress-ng: info:  [10883] successful run completed in 5.01 secs\nstress-ng: info:  [11139] setting to a 5 secs run per stressor\nstress-ng: info:  [11139] dispatching hogs: 1 set\nstress-ng: info:  [11139] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11139] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11139]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11139] set                1000      3.84      0.07      0.85       260.22        1088.95\nstress-ng: info:  [11139] skipped: 0\nstress-ng: info:  [11139] passed: 1: set (1)\nstress-ng: info:  [11139] failed: 0\nstress-ng: info:  [11139] metrics untrustworthy: 0\nstress-ng: info:  [11139] successful run completed in 3.85 secs\nstress-ng: info:  [11175] setting to a 5 secs run per stressor\nstress-ng: info:  [11175] dispatching hogs: 1 timerfd\nstress-ng: info:  [11175] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11175] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11175]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11175] timerfd            1024      0.16      0.00      0.06      6400.13       15715.16\nstress-ng: info:  [11175] skipped: 0\nstress-ng: info:  [11175] passed: 1: timerfd (1)\nstress-ng: info:  [11175] failed: 0\nstress-ng: info:  [11175] metrics untrustworthy: 0\nstress-ng: info:  [11175] successful run completed in 0.17 secs"
          }
        ]
      },
      "error": "prog 714: BPF_PROG_REJIT: Invalid argument (os error 22)",
      "post_rejit": {
        "bpf": {
          "619": {
            "avg_ns_per_run": 743.8585039783546,
            "bytes_jited": 240,
            "bytes_xlated": 264,
            "id": 619,
            "name": "tracepoint__raw",
            "run_cnt_delta": 1197857,
            "run_time_ns_delta": 891036116,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": null,
            "bytes_jited": 2521,
            "bytes_xlated": 4552,
            "id": 620,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "621": {
            "avg_ns_per_run": null,
            "bytes_jited": 17421,
            "bytes_xlated": 30288,
            "id": 621,
            "name": "sys_enter_submi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "622": {
            "avg_ns_per_run": 1726.6723031826843,
            "bytes_jited": 269,
            "bytes_xlated": 320,
            "id": 622,
            "name": "tracepoint__raw",
            "run_cnt_delta": 1199145,
            "run_time_ns_delta": 2070530459,
            "type": "raw_tracepoint"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 2101,
            "bytes_xlated": 3800,
            "id": 623,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 11551,
            "bytes_xlated": 19792,
            "id": 624,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "625": {
            "avg_ns_per_run": 1316.4598770220382,
            "bytes_jited": 8135,
            "bytes_xlated": 13608,
            "id": 625,
            "name": "trace_sys_enter",
            "run_cnt_delta": 1198914,
            "run_time_ns_delta": 1578322177,
            "type": "raw_tracepoint"
          },
          "626": {
            "avg_ns_per_run": 1318.857265609684,
            "bytes_jited": 8168,
            "bytes_xlated": 13664,
            "id": 626,
            "name": "trace_sys_exit",
            "run_cnt_delta": 1198695,
            "run_time_ns_delta": 1580907610,
            "type": "raw_tracepoint"
          },
          "627": {
            "avg_ns_per_run": null,
            "bytes_jited": 2362,
            "bytes_xlated": 4424,
            "id": 627,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": null,
            "bytes_jited": 11287,
            "bytes_xlated": 19416,
            "id": 628,
            "name": "trace_ret_ptrac",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": null,
            "bytes_jited": 2362,
            "bytes_xlated": 4424,
            "id": 629,
            "name": "trace_process_v",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": null,
            "bytes_jited": 11287,
            "bytes_xlated": 19416,
            "id": 630,
            "name": "trace_ret_proce",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": 192.4527535755384,
            "bytes_jited": 2362,
            "bytes_xlated": 4424,
            "id": 631,
            "name": "trace_arch_prct",
            "run_cnt_delta": 60830,
            "run_time_ns_delta": 11706901,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": 780.77249712313,
            "bytes_jited": 11287,
            "bytes_xlated": 19416,
            "id": 632,
            "name": "trace_ret_arch_",
            "run_cnt_delta": 60830,
            "run_time_ns_delta": 47494391,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 764.8,
            "bytes_jited": 2362,
            "bytes_xlated": 4424,
            "id": 633,
            "name": "trace_dup",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 15296,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 4999.35,
            "bytes_jited": 11287,
            "bytes_xlated": 19416,
            "id": 634,
            "name": "trace_ret_dup",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 99987,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 944.72,
            "bytes_jited": 2362,
            "bytes_xlated": 4424,
            "id": 635,
            "name": "trace_dup2",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 47236,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 4471.62,
            "bytes_jited": 11287,
            "bytes_xlated": 19416,
            "id": 636,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 223581,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": 1029.0,
            "bytes_jited": 2362,
            "bytes_xlated": 4424,
            "id": 637,
            "name": "trace_dup3",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2058,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": 4943.5,
            "bytes_jited": 11287,
            "bytes_xlated": 19416,
            "id": 638,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9887,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": null,
            "bytes_jited": 20729,
            "bytes_xlated": 31976,
            "id": 639,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "640": {
            "avg_ns_per_run": null,
            "bytes_jited": 20700,
            "bytes_xlated": 31992,
            "id": 640,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "641": {
            "avg_ns_per_run": null,
            "bytes_jited": 21004,
            "bytes_xlated": 32400,
            "id": 641,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "642": {
            "avg_ns_per_run": null,
            "bytes_jited": 20972,
            "bytes_xlated": 32408,
            "id": 642,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "643": {
            "avg_ns_per_run": null,
            "bytes_jited": 12219,
            "bytes_xlated": 18576,
            "id": 643,
            "name": "sys_dup_exit_ta",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": 21157.419795221842,
            "bytes_jited": 19851,
            "bytes_xlated": 32320,
            "id": 644,
            "name": "tracepoint__sch",
            "run_cnt_delta": 293,
            "run_time_ns_delta": 6199124,
            "type": "raw_tracepoint"
          },
          "645": {
            "avg_ns_per_run": null,
            "bytes_jited": 59270,
            "bytes_xlated": 108072,
            "id": 645,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": null,
            "bytes_jited": 6025,
            "bytes_xlated": 9904,
            "id": 646,
            "name": "uprobe_lkm_seek",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": 89889.0,
            "bytes_jited": 4314,
            "bytes_xlated": 7696,
            "id": 647,
            "name": "uprobe_lkm_seek",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 89889,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": null,
            "bytes_jited": 62313,
            "bytes_xlated": 111768,
            "id": 648,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1040,
            "id": 649,
            "name": "lkm_seeker_mod_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": null,
            "bytes_jited": 57795,
            "bytes_xlated": 102120,
            "id": 650,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": null,
            "bytes_jited": 3776,
            "bytes_xlated": 6224,
            "id": 651,
            "name": "lkm_seeker_new_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "652": {
            "avg_ns_per_run": 10435.714285714286,
            "bytes_jited": 20529,
            "bytes_xlated": 35336,
            "id": 652,
            "name": "tracepoint__sch",
            "run_cnt_delta": 42,
            "run_time_ns_delta": 438300,
            "type": "raw_tracepoint"
          },
          "653": {
            "avg_ns_per_run": null,
            "bytes_jited": 23909,
            "bytes_xlated": 37632,
            "id": 653,
            "name": "sched_process_e",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "654": {
            "avg_ns_per_run": 47957.20136518771,
            "bytes_jited": 8684,
            "bytes_xlated": 14464,
            "id": 654,
            "name": "tracepoint__sch",
            "run_cnt_delta": 293,
            "run_time_ns_delta": 14051460,
            "type": "raw_tracepoint"
          },
          "655": {
            "avg_ns_per_run": 2600.0819112627987,
            "bytes_jited": 252,
            "bytes_xlated": 440,
            "id": 655,
            "name": "tracepoint__sch",
            "run_cnt_delta": 293,
            "run_time_ns_delta": 761824,
            "type": "raw_tracepoint"
          },
          "656": {
            "avg_ns_per_run": null,
            "bytes_jited": 9092,
            "bytes_xlated": 13696,
            "id": 656,
            "name": "syscall__accept",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "657": {
            "avg_ns_per_run": 1742.9493912026771,
            "bytes_jited": 8929,
            "bytes_xlated": 14840,
            "id": 657,
            "name": "tracepoint__sch",
            "run_cnt_delta": 198424,
            "run_time_ns_delta": 345842990,
            "type": "raw_tracepoint"
          },
          "658": {
            "avg_ns_per_run": 47.74913416654118,
            "bytes_jited": 8167,
            "bytes_xlated": 13680,
            "id": 658,
            "name": "trace_filldir64",
            "run_cnt_delta": 6641,
            "run_time_ns_delta": 317102,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": null,
            "bytes_jited": 23495,
            "bytes_xlated": 36696,
            "id": 659,
            "name": "trace_call_user",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": 2452.279863481229,
            "bytes_jited": 7925,
            "bytes_xlated": 13312,
            "id": 660,
            "name": "trace_do_exit",
            "run_cnt_delta": 293,
            "run_time_ns_delta": 718518,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": null,
            "bytes_jited": 56307,
            "bytes_xlated": 97056,
            "id": 661,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": null,
            "bytes_jited": 6753,
            "bytes_xlated": 11160,
            "id": 662,
            "name": "uprobe_seq_ops_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": null,
            "bytes_jited": 6537,
            "bytes_xlated": 10904,
            "id": 663,
            "name": "uprobe_mem_dump",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 2136.946808510638,
            "bytes_jited": 11474,
            "bytes_xlated": 18264,
            "id": 664,
            "name": "trace_security_",
            "run_cnt_delta": 282,
            "run_time_ns_delta": 602619,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": null,
            "bytes_jited": 9744,
            "bytes_xlated": 15632,
            "id": 665,
            "name": "trace_tracepoin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": 4395.5,
            "bytes_jited": 8624,
            "bytes_xlated": 14352,
            "id": 666,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8791,
            "type": "raw_tracepoint"
          },
          "667": {
            "avg_ns_per_run": 3800.0,
            "bytes_jited": 8605,
            "bytes_xlated": 14336,
            "id": 667,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3800,
            "type": "raw_tracepoint"
          },
          "668": {
            "avg_ns_per_run": 2312.0,
            "bytes_jited": 8605,
            "bytes_xlated": 14336,
            "id": 668,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2312,
            "type": "raw_tracepoint"
          },
          "669": {
            "avg_ns_per_run": 6848.627906976744,
            "bytes_jited": 33377,
            "bytes_xlated": 52824,
            "id": 669,
            "name": "trace_security_",
            "run_cnt_delta": 43,
            "run_time_ns_delta": 294491,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 3349.202287403719,
            "bytes_jited": 22989,
            "bytes_xlated": 37160,
            "id": 670,
            "name": "trace_security_file_open",
            "run_cnt_delta": 12853,
            "run_time_ns_delta": 43047297,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": 4250.25,
            "bytes_jited": 18611,
            "bytes_xlated": 30576,
            "id": 671,
            "name": "trace_security_",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 51003,
            "type": "kprobe"
          },
          "672": {
            "avg_ns_per_run": 4160.0,
            "bytes_jited": 9988,
            "bytes_xlated": 16352,
            "id": 672,
            "name": "trace_security_",
            "run_cnt_delta": 11,
            "run_time_ns_delta": 45760,
            "type": "kprobe"
          },
          "673": {
            "avg_ns_per_run": 1458.6916321294652,
            "bytes_jited": 10727,
            "bytes_xlated": 16880,
            "id": 673,
            "name": "trace_commit_cr",
            "run_cnt_delta": 10134,
            "run_time_ns_delta": 14782381,
            "type": "kprobe"
          },
          "674": {
            "avg_ns_per_run": 1426.938775510204,
            "bytes_jited": 10049,
            "bytes_xlated": 16520,
            "id": 674,
            "name": "trace_switch_ta",
            "run_cnt_delta": 294,
            "run_time_ns_delta": 419520,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": 967.9136491557223,
            "bytes_jited": 8178,
            "bytes_xlated": 13680,
            "id": 675,
            "name": "trace_cap_capab",
            "run_cnt_delta": 42640,
            "run_time_ns_delta": 41271838,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": 3398.776556776557,
            "bytes_jited": 8475,
            "bytes_xlated": 14120,
            "id": 676,
            "name": "trace_security_",
            "run_cnt_delta": 273,
            "run_time_ns_delta": 927866,
            "type": "kprobe"
          },
          "677": {
            "avg_ns_per_run": 4537.0,
            "bytes_jited": 9148,
            "bytes_xlated": 15208,
            "id": 677,
            "name": "trace_security_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4537,
            "type": "kprobe"
          },
          "678": {
            "avg_ns_per_run": null,
            "bytes_jited": 8280,
            "bytes_xlated": 13824,
            "id": 678,
            "name": "trace_proc_crea",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": null,
            "bytes_jited": 9501,
            "bytes_xlated": 15760,
            "id": 679,
            "name": "trace_debugfs_c",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "680": {
            "avg_ns_per_run": null,
            "bytes_jited": 9201,
            "bytes_xlated": 15328,
            "id": 680,
            "name": "trace_debugfs_c",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "681": {
            "avg_ns_per_run": null,
            "bytes_jited": 10784,
            "bytes_xlated": 16456,
            "id": 681,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "682": {
            "avg_ns_per_run": 3399.5222222222224,
            "bytes_jited": 10079,
            "bytes_xlated": 15400,
            "id": 682,
            "name": "trace_security_",
            "run_cnt_delta": 270,
            "run_time_ns_delta": 917871,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": 5709.02027027027,
            "bytes_jited": 11264,
            "bytes_xlated": 17192,
            "id": 683,
            "name": "trace_security_",
            "run_cnt_delta": 148,
            "run_time_ns_delta": 844935,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 1709.0,
            "bytes_jited": 10593,
            "bytes_xlated": 16080,
            "id": 684,
            "name": "trace_security_",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 5127,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 3204.984555984556,
            "bytes_jited": 11029,
            "bytes_xlated": 16864,
            "id": 685,
            "name": "trace_security_",
            "run_cnt_delta": 259,
            "run_time_ns_delta": 830091,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": null,
            "bytes_jited": 953,
            "bytes_xlated": 1568,
            "id": 686,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": null,
            "bytes_jited": 953,
            "bytes_xlated": 1568,
            "id": 687,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "688": {
            "avg_ns_per_run": 242.4379140201183,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 688,
            "name": "trace_vfs_write",
            "run_cnt_delta": 73366,
            "run_time_ns_delta": 17786700,
            "type": "kprobe"
          },
          "689": {
            "avg_ns_per_run": 159.32001308846986,
            "bytes_jited": 283,
            "bytes_xlated": 432,
            "id": 689,
            "name": "vfs_write_magic",
            "run_cnt_delta": 73347,
            "run_time_ns_delta": 11685645,
            "type": "kprobe"
          },
          "690": {
            "avg_ns_per_run": 214.0644061788485,
            "bytes_jited": 19112,
            "bytes_xlated": 31720,
            "id": 690,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 73347,
            "run_time_ns_delta": 15700982,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": 121.18335582178244,
            "bytes_jited": 23761,
            "bytes_xlated": 36648,
            "id": 691,
            "name": "vfs_write_magic",
            "run_cnt_delta": 73371,
            "run_time_ns_delta": 8891344,
            "type": "kprobe"
          },
          "692": {
            "avg_ns_per_run": null,
            "bytes_jited": 29925,
            "bytes_xlated": 51704,
            "id": 692,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "693": {
            "avg_ns_per_run": 1291.0,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 693,
            "name": "trace_vfs_write",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1291,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 480.0,
            "bytes_jited": 283,
            "bytes_xlated": 432,
            "id": 694,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 480,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 536.0,
            "bytes_jited": 19111,
            "bytes_xlated": 31712,
            "id": 695,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 536,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 591.0,
            "bytes_jited": 23790,
            "bytes_xlated": 36696,
            "id": 696,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 591,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": null,
            "bytes_jited": 29849,
            "bytes_xlated": 51680,
            "id": 697,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 698,
            "name": "trace_kernel_wr",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": null,
            "bytes_jited": 283,
            "bytes_xlated": 432,
            "id": 699,
            "name": "kernel_write_ma",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": null,
            "bytes_jited": 19115,
            "bytes_xlated": 31720,
            "id": 700,
            "name": "trace_ret_kerne",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": null,
            "bytes_jited": 23761,
            "bytes_xlated": 36648,
            "id": 701,
            "name": "kernel_write_ma",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "702": {
            "avg_ns_per_run": null,
            "bytes_jited": 29925,
            "bytes_xlated": 51704,
            "id": 702,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "703": {
            "avg_ns_per_run": 264.59189732488016,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 703,
            "name": "trace_vfs_read",
            "run_cnt_delta": 32335,
            "run_time_ns_delta": 8555579,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 1350.662632656861,
            "bytes_jited": 19115,
            "bytes_xlated": 31720,
            "id": 704,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 10742,
            "run_time_ns_delta": 14508818,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": null,
            "bytes_jited": 17168,
            "bytes_xlated": 29848,
            "id": 705,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 706,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": null,
            "bytes_jited": 19111,
            "bytes_xlated": 31712,
            "id": 707,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": null,
            "bytes_jited": 17896,
            "bytes_xlated": 30816,
            "id": 708,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 636.7366283006094,
            "bytes_jited": 20719,
            "bytes_xlated": 32736,
            "id": 709,
            "name": "trace_mmap_aler",
            "run_cnt_delta": 2954,
            "run_time_ns_delta": 1880920,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 217.281654676259,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 710,
            "name": "trace_do_mmap",
            "run_cnt_delta": 2780,
            "run_time_ns_delta": 604043,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 336.78489208633096,
            "bytes_jited": 19430,
            "bytes_xlated": 31584,
            "id": 711,
            "name": "trace_ret_do_mm",
            "run_cnt_delta": 2780,
            "run_time_ns_delta": 936262,
            "type": "kprobe"
          },
          "712": {
            "avg_ns_per_run": 2800.4172661870502,
            "bytes_jited": 36988,
            "bytes_xlated": 60888,
            "id": 712,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 2780,
            "run_time_ns_delta": 7785160,
            "type": "kprobe"
          },
          "713": {
            "avg_ns_per_run": 3761.8758029978585,
            "bytes_jited": 34616,
            "bytes_xlated": 59616,
            "id": 713,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 467,
            "run_time_ns_delta": 1756796,
            "type": "kprobe"
          },
          "714": {
            "avg_ns_per_run": null,
            "bytes_jited": 626,
            "bytes_xlated": 1000,
            "id": 714,
            "name": "syscall__init_m",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "715": {
            "avg_ns_per_run": 1642.2311915339328,
            "bytes_jited": 15589,
            "bytes_xlated": 26904,
            "id": 715,
            "name": "trace_security_",
            "run_cnt_delta": 27687,
            "run_time_ns_delta": 45468455,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 716,
            "name": "trace_register_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": null,
            "bytes_jited": 8811,
            "bytes_xlated": 14640,
            "id": 717,
            "name": "trace_ret_regis",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 1531.3547549496916,
            "bytes_jited": 8337,
            "bytes_xlated": 13904,
            "id": 718,
            "name": "trace_security_",
            "run_cnt_delta": 6162,
            "run_time_ns_delta": 9436208,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 4644.953445065177,
            "bytes_jited": 9585,
            "bytes_xlated": 15448,
            "id": 719,
            "name": "trace_security_",
            "run_cnt_delta": 537,
            "run_time_ns_delta": 2494340,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": null,
            "bytes_jited": 6349,
            "bytes_xlated": 10528,
            "id": 720,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": null,
            "bytes_jited": 6585,
            "bytes_xlated": 11008,
            "id": 721,
            "name": "trace_check_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "722": {
            "avg_ns_per_run": null,
            "bytes_jited": 6591,
            "bytes_xlated": 11016,
            "id": 722,
            "name": "trace_check_hel",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "723": {
            "avg_ns_per_run": null,
            "bytes_jited": 18645,
            "bytes_xlated": 30648,
            "id": 723,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "724": {
            "avg_ns_per_run": null,
            "bytes_jited": 17251,
            "bytes_xlated": 30448,
            "id": 724,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "725": {
            "avg_ns_per_run": null,
            "bytes_jited": 9229,
            "bytes_xlated": 15352,
            "id": 725,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": null,
            "bytes_jited": 8651,
            "bytes_xlated": 14344,
            "id": 726,
            "name": "trace_device_ad",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "727": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 727,
            "name": "trace___registe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": null,
            "bytes_jited": 8818,
            "bytes_xlated": 14632,
            "id": 728,
            "name": "trace_ret__regi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": null,
            "bytes_jited": 19872,
            "bytes_xlated": 32648,
            "id": 729,
            "name": "tracepoint__mod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "730": {
            "avg_ns_per_run": null,
            "bytes_jited": 8963,
            "bytes_xlated": 14920,
            "id": 730,
            "name": "tracepoint__mod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "731": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 731,
            "name": "trace_do_init_m",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": null,
            "bytes_jited": 14546,
            "bytes_xlated": 23904,
            "id": 732,
            "name": "trace_ret_do_in",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "733": {
            "avg_ns_per_run": 3920.8928571428573,
            "bytes_jited": 18486,
            "bytes_xlated": 30352,
            "id": 733,
            "name": "trace_load_elf_",
            "run_cnt_delta": 84,
            "run_time_ns_delta": 329355,
            "type": "kprobe"
          },
          "734": {
            "avg_ns_per_run": 176.835852665929,
            "bytes_jited": 8685,
            "bytes_xlated": 14496,
            "id": 734,
            "name": "trace_security_",
            "run_cnt_delta": 106642,
            "run_time_ns_delta": 18858129,
            "type": "kprobe"
          },
          "735": {
            "avg_ns_per_run": 4928.180379746836,
            "bytes_jited": 8478,
            "bytes_xlated": 14112,
            "id": 735,
            "name": "tracepoint__tas",
            "run_cnt_delta": 316,
            "run_time_ns_delta": 1557305,
            "type": "raw_tracepoint"
          },
          "736": {
            "avg_ns_per_run": 4597.25,
            "bytes_jited": 9796,
            "bytes_xlated": 16344,
            "id": 736,
            "name": "trace_security_",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 18389,
            "type": "kprobe"
          },
          "737": {
            "avg_ns_per_run": null,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 737,
            "name": "trace_kallsyms_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "738": {
            "avg_ns_per_run": null,
            "bytes_jited": 8410,
            "bytes_xlated": 14024,
            "id": 738,
            "name": "trace_ret_kalls",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 3553.2511230907458,
            "bytes_jited": 10113,
            "bytes_xlated": 16296,
            "id": 739,
            "name": "trace_do_sigact",
            "run_cnt_delta": 2226,
            "run_time_ns_delta": 7909537,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": 5664.0,
            "bytes_jited": 18564,
            "bytes_xlated": 30528,
            "id": 740,
            "name": "trace_vfs_utime",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 5664,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": null,
            "bytes_jited": 18564,
            "bytes_xlated": 30528,
            "id": 741,
            "name": "trace_utimes_co",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 5566.285714285715,
            "bytes_jited": 9534,
            "bytes_xlated": 15824,
            "id": 742,
            "name": "trace_do_trunca",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 38964,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 1185.435009002871,
            "bytes_jited": 16712,
            "bytes_xlated": 27176,
            "id": 743,
            "name": "trace_fd_instal",
            "run_cnt_delta": 20549,
            "run_time_ns_delta": 24359504,
            "type": "kprobe"
          },
          "744": {
            "avg_ns_per_run": 2486.7567771084337,
            "bytes_jited": 16640,
            "bytes_xlated": 27024,
            "id": 744,
            "name": "trace_filp_clos",
            "run_cnt_delta": 1328,
            "run_time_ns_delta": 3302413,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 395.53937947494035,
            "bytes_jited": 463,
            "bytes_xlated": 768,
            "id": 745,
            "name": "trace_file_upda",
            "run_cnt_delta": 419,
            "run_time_ns_delta": 165731,
            "type": "kprobe"
          },
          "746": {
            "avg_ns_per_run": 128.4749403341289,
            "bytes_jited": 20058,
            "bytes_xlated": 31168,
            "id": 746,
            "name": "trace_ret_file_",
            "run_cnt_delta": 419,
            "run_time_ns_delta": 53831,
            "type": "kprobe"
          },
          "747": {
            "avg_ns_per_run": null,
            "bytes_jited": 463,
            "bytes_xlated": 768,
            "id": 747,
            "name": "trace_file_modi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "748": {
            "avg_ns_per_run": null,
            "bytes_jited": 20144,
            "bytes_xlated": 31288,
            "id": 748,
            "name": "trace_ret_file_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "749": {
            "avg_ns_per_run": 814.0,
            "bytes_jited": 156,
            "bytes_xlated": 232,
            "id": 749,
            "name": "trace_inotify_f",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1628,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": 257.5,
            "bytes_jited": 18029,
            "bytes_xlated": 29936,
            "id": 750,
            "name": "trace_ret_inoti",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 515,
            "type": "kprobe"
          },
          "751": {
            "avg_ns_per_run": null,
            "bytes_jited": 12834,
            "bytes_xlated": 20080,
            "id": 751,
            "name": "process_execute",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "752": {
            "avg_ns_per_run": 154.23809523809524,
            "bytes_jited": 16476,
            "bytes_xlated": 28872,
            "id": 752,
            "name": "trace_exec_binp",
            "run_cnt_delta": 42,
            "run_time_ns_delta": 6478,
            "type": "kprobe"
          },
          "753": {
            "avg_ns_per_run": 7602.071428571428,
            "bytes_jited": 16706,
            "bytes_xlated": 29144,
            "id": 753,
            "name": "trace_security_",
            "run_cnt_delta": 42,
            "run_time_ns_delta": 319287,
            "type": "kprobe"
          },
          "754": {
            "avg_ns_per_run": 7863.023809523809,
            "bytes_jited": 24473,
            "bytes_xlated": 38320,
            "id": 754,
            "name": "trace_execute_f",
            "run_cnt_delta": 42,
            "run_time_ns_delta": 330247,
            "type": "kprobe"
          },
          "755": {
            "avg_ns_per_run": 4885.5,
            "bytes_jited": 18395,
            "bytes_xlated": 30200,
            "id": 755,
            "name": "trace_security_",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9771,
            "type": "kprobe"
          },
          "756": {
            "avg_ns_per_run": 4930.625,
            "bytes_jited": 18198,
            "bytes_xlated": 29912,
            "id": 756,
            "name": "trace_set_fs_pw",
            "run_cnt_delta": 16,
            "run_time_ns_delta": 78890,
            "type": "kprobe"
          },
          "757": {
            "avg_ns_per_run": 1575.8200942870178,
            "bytes_jited": 8635,
            "bytes_xlated": 14360,
            "id": 757,
            "name": "trace_security_",
            "run_cnt_delta": 19727,
            "run_time_ns_delta": 31086203,
            "type": "kprobe"
          },
          "758": {
            "avg_ns_per_run": null,
            "bytes_jited": 8660,
            "bytes_xlated": 14416,
            "id": 758,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "759": {
            "avg_ns_per_run": null,
            "bytes_jited": 17565,
            "bytes_xlated": 29176,
            "id": 759,
            "name": "trace_chmod_com",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "760": {
            "avg_ns_per_run": 1077.1810486481104,
            "bytes_jited": 47186,
            "bytes_xlated": 76688,
            "id": 760,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 20083,
            "run_time_ns_delta": 21633027,
            "type": "kprobe"
          },
          "761": {
            "avg_ns_per_run": null,
            "bytes_jited": 14865,
            "bytes_xlated": 23928,
            "id": 761,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "762": {
            "avg_ns_per_run": 2405.3333333333335,
            "bytes_jited": 9486,
            "bytes_xlated": 15760,
            "id": 762,
            "name": "trace_security_",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 7216,
            "type": "kprobe"
          },
          "763": {
            "avg_ns_per_run": 842.6666666666666,
            "bytes_jited": 333,
            "bytes_xlated": 520,
            "id": 763,
            "name": "trace_sock_allo",
            "run_cnt_delta": 423,
            "run_time_ns_delta": 356448,
            "type": "kprobe"
          },
          "764": {
            "avg_ns_per_run": 3108.6548463356976,
            "bytes_jited": 8443,
            "bytes_xlated": 12928,
            "id": 764,
            "name": "trace_ret_sock_",
            "run_cnt_delta": 423,
            "run_time_ns_delta": 1314961,
            "type": "kprobe"
          },
          "765": {
            "avg_ns_per_run": 401.0,
            "bytes_jited": 348,
            "bytes_xlated": 592,
            "id": 765,
            "name": "trace_security_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 401,
            "type": "kprobe"
          },
          "766": {
            "avg_ns_per_run": 2677.8815426997244,
            "bytes_jited": 8687,
            "bytes_xlated": 13152,
            "id": 766,
            "name": "trace_security_",
            "run_cnt_delta": 363,
            "run_time_ns_delta": 972071,
            "type": "kprobe"
          },
          "767": {
            "avg_ns_per_run": 3246.089347079038,
            "bytes_jited": 8687,
            "bytes_xlated": 13152,
            "id": 767,
            "name": "trace_security_",
            "run_cnt_delta": 291,
            "run_time_ns_delta": 944612,
            "type": "kprobe"
          },
          "768": {
            "avg_ns_per_run": 2879.769944341373,
            "bytes_jited": 5286,
            "bytes_xlated": 8136,
            "id": 768,
            "name": "cgroup_bpf_run_",
            "run_cnt_delta": 539,
            "run_time_ns_delta": 1552196,
            "type": "kprobe"
          },
          "770": {
            "avg_ns_per_run": 2734.879120879121,
            "bytes_jited": 16148,
            "bytes_xlated": 25792,
            "id": 770,
            "name": "cgroup_skb_ingr",
            "run_cnt_delta": 273,
            "run_time_ns_delta": 746622,
            "type": "cgroup_skb"
          },
          "771": {
            "avg_ns_per_run": 3670.5072463768115,
            "bytes_jited": 16148,
            "bytes_xlated": 25792,
            "id": 771,
            "name": "cgroup_skb_egre",
            "run_cnt_delta": 276,
            "run_time_ns_delta": 1013060,
            "type": "cgroup_skb"
          },
          "772": {
            "avg_ns_per_run": 3826.0,
            "bytes_jited": 920,
            "bytes_xlated": 1560,
            "id": 772,
            "name": "cgroup_mkdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3826,
            "type": "raw_tracepoint"
          },
          "773": {
            "avg_ns_per_run": 2226.0,
            "bytes_jited": 902,
            "bytes_xlated": 1520,
            "id": 773,
            "name": "cgroup_rmdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2226,
            "type": "raw_tracepoint"
          },
          "774": {
            "avg_ns_per_run": 156.95348837209303,
            "bytes_jited": 20,
            "bytes_xlated": 16,
            "id": 774,
            "name": "empty_kprobe",
            "run_cnt_delta": 43,
            "run_time_ns_delta": 6749,
            "type": "kprobe"
          },
          "775": {
            "avg_ns_per_run": 1663.2380952380952,
            "bytes_jited": 58664,
            "bytes_xlated": 95944,
            "id": 775,
            "name": "tracepoint__exe",
            "run_cnt_delta": 42,
            "run_time_ns_delta": 69856,
            "type": "raw_tracepoint"
          },
          "776": {
            "avg_ns_per_run": 1560.3140122928498,
            "bytes_jited": 7294,
            "bytes_xlated": 13264,
            "id": 776,
            "name": "lsm_file_open_t",
            "run_cnt_delta": 12853,
            "run_time_ns_delta": 20054716,
            "type": "lsm"
          },
          "777": {
            "avg_ns_per_run": null,
            "bytes_jited": 5363,
            "bytes_xlated": 9080,
            "id": 777,
            "name": "uprobe__feature",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 13.08993089500018,
            "ops_per_sec": 416.7325285180526,
            "ops_total": 5455.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [21811]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21811] get                 200      2.70      0.05      0.83        74.10         225.17\nstress-ng: info:  [21811] skipped: 0\nstress-ng: info:  [21811] passed: 1: get (1)\nstress-ng: info:  [21811] failed: 0\nstress-ng: info:  [21811] metrics untrustworthy: 0\nstress-ng: info:  [21811] successful run completed in 2.70 secs\nstress-ng: info:  [21813] setting to a 5 secs run per stressor\nstress-ng: info:  [21813] dispatching hogs: 1 prctl\nstress-ng: info:  [21813] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21813] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21813]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21813] prctl               231      5.00      0.42      0.31        46.18         315.01\nstress-ng: info:  [21813] skipped: 0\nstress-ng: info:  [21813] passed: 1: prctl (1)\nstress-ng: info:  [21813] failed: 0\nstress-ng: info:  [21813] metrics untrustworthy: 0\nstress-ng: info:  [21813] successful run completed in 5.01 secs\nstress-ng: info:  [22094] setting to a 5 secs run per stressor\nstress-ng: info:  [22094] dispatching hogs: 1 set\nstress-ng: info:  [22094] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22094] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22094]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22094] set                1000      3.10      0.05      0.86       322.54        1099.24\nstress-ng: info:  [22094] skipped: 0\nstress-ng: info:  [22094] passed: 1: set (1)\nstress-ng: info:  [22094] failed: 0\nstress-ng: info:  [22094] metrics untrustworthy: 0\nstress-ng: info:  [22094] successful run completed in 3.11 secs\nstress-ng: info:  [22096] setting to a 5 secs run per stressor\nstress-ng: info:  [22096] dispatching hogs: 1 timerfd\nstress-ng: info:  [22096] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22096] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22096]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22096] timerfd            1024      0.18      0.00      0.07      5744.63       13734.83\nstress-ng: info:  [22096] skipped: 0\nstress-ng: info:  [22096] passed: 1: timerfd (1)\nstress-ng: info:  [22096] failed: 0\nstress-ng: info:  [22096] metrics untrustworthy: 0\nstress-ng: info:  [22096] successful run completed in 0.20 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "prog 714: BPF_PROG_REJIT: Invalid argument (os error 22)",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "BPF_PROG_REJIT: Invalid argument (os error 22)",
            "exit_code": 1,
            "prog_id": 714
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 122,
          "not_applied": 36,
          "requested": 158
        }
      },
      "runner": "tracee",
      "selected_workload": "stress_ng_os",
      "status": "error"
    },
    {
      "app": "bpftrace/capable",
      "baseline": {
        "bpf": {
          "783": {
            "avg_ns_per_run": 833.6768549634609,
            "bytes_jited": 773,
            "bytes_xlated": 1360,
            "id": 783,
            "name": "cap_capable",
            "run_cnt_delta": 18747,
            "run_time_ns_delta": 15628940,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.017596910000066,
            "ops_per_sec": 879.50468703552,
            "ops_total": 4413.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [11243]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11243] get                  67      1.00      0.01      0.30        67.01         219.48\nstress-ng: info:  [11243] skipped: 0\nstress-ng: info:  [11243] passed: 1: get (1)\nstress-ng: info:  [11243] failed: 0\nstress-ng: info:  [11243] metrics untrustworthy: 0\nstress-ng: info:  [11243] successful run completed in 1.02 secs\nstress-ng: info:  [11245] setting to a 1 secs run per stressor\nstress-ng: info:  [11245] dispatching hogs: 1 prctl\nstress-ng: info:  [11245] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11245] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11245]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11245] prctl                39      1.00      0.08      0.05        38.84         302.58\nstress-ng: info:  [11245] skipped: 0\nstress-ng: info:  [11245] passed: 1: prctl (1)\nstress-ng: info:  [11245] failed: 0\nstress-ng: info:  [11245] metrics untrustworthy: 0\nstress-ng: info:  [11245] successful run completed in 1.01 secs\nstress-ng: info:  [11286] setting to a 1 secs run per stressor\nstress-ng: info:  [11286] dispatching hogs: 1 set\nstress-ng: info:  [11286] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11286] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11286]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11286] set                 283      1.00      0.01      0.25       282.91        1095.81\nstress-ng: info:  [11286] skipped: 0\nstress-ng: info:  [11286] passed: 1: set (1)\nstress-ng: info:  [11286] failed: 0\nstress-ng: info:  [11286] metrics untrustworthy: 0\nstress-ng: info:  [11286] successful run completed in 1.00 secs\nstress-ng: info:  [11288] setting to a 1 secs run per stressor\nstress-ng: info:  [11288] dispatching hogs: 1 timerfd\nstress-ng: info:  [11288] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11288] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11288]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11288] timerfd            1024      0.16      0.00      0.07      6319.81       14222.22\nstress-ng: info:  [11288] skipped: 0\nstress-ng: info:  [11288] passed: 1: timerfd (1)\nstress-ng: info:  [11288] failed: 0\nstress-ng: info:  [11288] metrics untrustworthy: 0\nstress-ng: info:  [11288] successful run completed in 0.17 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "783": {
            "avg_ns_per_run": 1136.4197900233912,
            "bytes_jited": 773,
            "bytes_xlated": 1360,
            "id": 783,
            "name": "cap_capable",
            "run_cnt_delta": 18383,
            "run_time_ns_delta": 20890805,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 4.908420621999994,
            "ops_per_sec": 910.8836312765384,
            "ops_total": 4471.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [22174]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22174] get                  71      1.00      0.02      0.30        70.97         220.94\nstress-ng: info:  [22174] skipped: 0\nstress-ng: info:  [22174] passed: 1: get (1)\nstress-ng: info:  [22174] failed: 0\nstress-ng: info:  [22174] metrics untrustworthy: 0\nstress-ng: info:  [22174] successful run completed in 1.01 secs\nstress-ng: info:  [22176] setting to a 1 secs run per stressor\nstress-ng: info:  [22176] dispatching hogs: 1 prctl\nstress-ng: info:  [22176] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22176] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22176]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22176] prctl                45      1.02      0.09      0.06        44.03         298.51\nstress-ng: info:  [22176] skipped: 0\nstress-ng: info:  [22176] passed: 1: prctl (1)\nstress-ng: info:  [22176] failed: 0\nstress-ng: info:  [22176] metrics untrustworthy: 0\nstress-ng: info:  [22176] successful run completed in 1.03 secs\nstress-ng: info:  [22223] setting to a 1 secs run per stressor\nstress-ng: info:  [22223] dispatching hogs: 1 set\nstress-ng: info:  [22223] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22223] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22223]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22223] set                 331      1.00      0.04      0.26       330.93        1113.09\nstress-ng: info:  [22223] skipped: 0\nstress-ng: info:  [22223] passed: 1: set (1)\nstress-ng: info:  [22223] failed: 0\nstress-ng: info:  [22223] metrics untrustworthy: 0\nstress-ng: info:  [22223] successful run completed in 1.01 secs\nstress-ng: info:  [22225] setting to a 1 secs run per stressor\nstress-ng: info:  [22225] dispatching hogs: 1 timerfd\nstress-ng: info:  [22225] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22225] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22225]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22225] timerfd            1024      0.18      0.03      0.04      5673.87       14676.58\nstress-ng: info:  [22225] skipped: 0\nstress-ng: info:  [22225] passed: 1: timerfd (1)\nstress-ng: info:  [22225] failed: 0\nstress-ng: info:  [22225] metrics untrustworthy: 0\nstress-ng: info:  [22225] successful run completed in 0.19 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 1,
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
          "789": {
            "avg_ns_per_run": 1467.331265961328,
            "bytes_jited": 226,
            "bytes_xlated": 408,
            "id": 789,
            "name": "block_io_start",
            "run_cnt_delta": 19187,
            "run_time_ns_delta": 28153685,
            "type": "tracepoint"
          },
          "790": {
            "avg_ns_per_run": 383.1479752596569,
            "bytes_jited": 935,
            "bytes_xlated": 1576,
            "id": 790,
            "name": "block_io_done",
            "run_cnt_delta": 17138,
            "run_time_ns_delta": 6566390,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 8.902509269999996,
            "ops_per_sec": 3634.4809107960655,
            "ops_total": 32356.0,
            "stderr": "",
            "stdout": "        \"500\" : 0.562781,\n        \"750\" : 26.825913,\n        \"1000\" : 3.901951\n      },\n      \"latency_ms\" : {\n        \"2\" : 13.181591,\n        \"4\" : 4.077039,\n        \"10\" : 1.400700,\n        \"20\" : 0.087544,\n        \"50\" : 0.025013,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ],\n  \"disk_util\" : [\n    {\n      \"name\" : \"nvme0n1\",\n      \"read_ios\" : 15777,\n      \"write_ios\" : 1726,\n      \"read_sectors\" : 126808,\n      \"write_sectors\" : 19152,\n      \"read_merges\" : 0,\n      \"write_merges\" : 1,\n      \"read_ticks\" : 13768,\n      \"write_ticks\" : 4497,\n      \"in_queue\" : 18265,\n      \"util\" : 61.995153\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "789": {
            "avg_ns_per_run": 1401.326437121324,
            "bytes_jited": 226,
            "bytes_xlated": 408,
            "id": 789,
            "name": "block_io_start",
            "run_cnt_delta": 20301,
            "run_time_ns_delta": 28448328,
            "type": "tracepoint"
          },
          "790": {
            "avg_ns_per_run": 337.82448466291214,
            "bytes_jited": 935,
            "bytes_xlated": 1576,
            "id": 790,
            "name": "block_io_done",
            "run_cnt_delta": 18289,
            "run_time_ns_delta": 6178472,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 9.214255475999835,
            "ops_per_sec": 3356.7552018242473,
            "ops_total": 30930.0,
            "stderr": "",
            "stdout": "        \"500\" : 0.794261,\n        \"750\" : 26.889572,\n        \"1000\" : 3.971304\n      },\n      \"latency_ms\" : {\n        \"2\" : 10.632847,\n        \"4\" : 6.200359,\n        \"10\" : 1.409172,\n        \"20\" : 0.051243,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ],\n  \"disk_util\" : [\n    {\n      \"name\" : \"nvme0n1\",\n      \"read_ios\" : 14966,\n      \"write_ios\" : 2453,\n      \"read_sectors\" : 119728,\n      \"write_sectors\" : 26552,\n      \"read_merges\" : 0,\n      \"write_merges\" : 11,\n      \"read_ticks\" : 14437,\n      \"write_ticks\" : 6296,\n      \"in_queue\" : 20734,\n      \"util\" : 66.558442\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 2,
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
          "796": {
            "avg_ns_per_run": 1436.25,
            "bytes_jited": 366,
            "bytes_xlated": 680,
            "id": 796,
            "name": "1",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 17235,
            "type": "perf_event"
          },
          "797": {
            "avg_ns_per_run": 135.17687164309984,
            "bytes_jited": 144,
            "bytes_xlated": 224,
            "id": 797,
            "name": "vfs_create",
            "run_cnt_delta": 136845,
            "run_time_ns_delta": 18498279,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 15.839677454000025,
            "ops_per_sec": 413.58165398410074,
            "ops_total": 6551.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [12176]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12176] open                100      0.10      0.02      0.00       983.62        4116.24\nstress-ng: info:  [12176] skipped: 0\nstress-ng: info:  [12176] passed: 1: open (1)\nstress-ng: info:  [12176] failed: 0\nstress-ng: info:  [12176] metrics untrustworthy: 0\nstress-ng: info:  [12176] successful run completed in 0.11 secs\nstress-ng: info:  [12178] setting to a 1 secs run per stressor\nstress-ng: info:  [12178] dispatching hogs: 1 rename\nstress-ng: info:  [12178] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12178] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12178]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12178] rename              100      0.12      0.00      0.02       868.72        4680.99\nstress-ng: info:  [12178] skipped: 0\nstress-ng: info:  [12178] passed: 1: rename (1)\nstress-ng: info:  [12178] failed: 0\nstress-ng: info:  [12178] metrics untrustworthy: 0\nstress-ng: info:  [12178] successful run completed in 0.13 secs\nstress-ng: info:  [12180] setting to a 1 secs run per stressor\nstress-ng: info:  [12180] dispatching hogs: 1 touch\nstress-ng: info:  [12180] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12180] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12180]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12180] touch               200      0.04      0.02      0.01      4785.23        7399.73\nstress-ng: info:  [12180] skipped: 0\nstress-ng: info:  [12180] passed: 1: touch (1)\nstress-ng: info:  [12180] failed: 0\nstress-ng: info:  [12180] metrics untrustworthy: 0\nstress-ng: info:  [12180] successful run completed in 0.05 secs\nstress-ng: info:  [12186] setting to a 1 secs run per stressor\nstress-ng: info:  [12186] dispatching hogs: 1 utime\nstress-ng: info:  [12186] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12186] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12186]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12186] utime               200      0.25      0.00      0.08       800.32        2510.86\nstress-ng: info:  [12186] skipped: 0\nstress-ng: info:  [12186] passed: 1: utime (1)\nstress-ng: info:  [12186] failed: 0\nstress-ng: info:  [12186] metrics untrustworthy: 0\nstress-ng: info:  [12186] successful run completed in 0.25 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "796": {
            "avg_ns_per_run": 1288.6153846153845,
            "bytes_jited": 366,
            "bytes_xlated": 680,
            "id": 796,
            "name": "1",
            "run_cnt_delta": 13,
            "run_time_ns_delta": 16752,
            "type": "perf_event"
          },
          "797": {
            "avg_ns_per_run": 145.8284771584227,
            "bytes_jited": 144,
            "bytes_xlated": 224,
            "id": 797,
            "name": "vfs_create",
            "run_cnt_delta": 143357,
            "run_time_ns_delta": 20905533,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 14.880088261999845,
            "ops_per_sec": 444.0161834841184,
            "ops_total": 6607.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [23075]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23075] open                100      0.09      0.01      0.01      1123.96        4001.28\nstress-ng: info:  [23075] skipped: 0\nstress-ng: info:  [23075] passed: 1: open (1)\nstress-ng: info:  [23075] failed: 0\nstress-ng: info:  [23075] metrics untrustworthy: 0\nstress-ng: info:  [23075] successful run completed in 0.10 secs\nstress-ng: info:  [23077] setting to a 1 secs run per stressor\nstress-ng: info:  [23077] dispatching hogs: 1 rename\nstress-ng: info:  [23077] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23077] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23077]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23077] rename              100      0.10      0.00      0.02      1028.86        4873.77\nstress-ng: info:  [23077] skipped: 0\nstress-ng: info:  [23077] passed: 1: rename (1)\nstress-ng: info:  [23077] failed: 0\nstress-ng: info:  [23077] metrics untrustworthy: 0\nstress-ng: info:  [23077] successful run completed in 0.11 secs\nstress-ng: info:  [23079] setting to a 1 secs run per stressor\nstress-ng: info:  [23079] dispatching hogs: 1 touch\nstress-ng: info:  [23079] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23079] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23079]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23079] touch               200      0.06      0.02      0.01      3205.93        5879.59\nstress-ng: info:  [23079] skipped: 0\nstress-ng: info:  [23079] passed: 1: touch (1)\nstress-ng: info:  [23079] failed: 0\nstress-ng: info:  [23079] metrics untrustworthy: 0\nstress-ng: info:  [23079] successful run completed in 0.07 secs\nstress-ng: info:  [23085] setting to a 1 secs run per stressor\nstress-ng: info:  [23085] dispatching hogs: 1 utime\nstress-ng: info:  [23085] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23085] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23085]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23085] utime               200      0.24      0.00      0.08       818.83        2381.15\nstress-ng: info:  [23085] skipped: 0\nstress-ng: info:  [23085] passed: 1: utime (1)\nstress-ng: info:  [23085] failed: 0\nstress-ng: info:  [23085] metrics untrustworthy: 0\nstress-ng: info:  [23085] successful run completed in 0.25 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 2,
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
          "803": {
            "avg_ns_per_run": 260.84918564768225,
            "bytes_jited": 90,
            "bytes_xlated": 136,
            "id": 803,
            "name": "sched_wakeup",
            "run_cnt_delta": 48689,
            "run_time_ns_delta": 12700486,
            "type": "tracepoint"
          },
          "804": {
            "avg_ns_per_run": 423.04581673306774,
            "bytes_jited": 90,
            "bytes_xlated": 136,
            "id": 804,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 502,
            "run_time_ns_delta": 212369,
            "type": "tracepoint"
          },
          "805": {
            "avg_ns_per_run": 435.1937609613848,
            "bytes_jited": 519,
            "bytes_xlated": 896,
            "id": 805,
            "name": "sched_switch",
            "run_cnt_delta": 96361,
            "run_time_ns_delta": 41935706,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.899837096000056,
            "ops_per_sec": 1599.8746823703675,
            "ops_total": 9439.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [12938]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12938] sem-sysv           1001      0.08      0.00      0.02     12857.53       39863.01\nstress-ng: info:  [12938] skipped: 0\nstress-ng: info:  [12938] passed: 1: sem-sysv (1)\nstress-ng: info:  [12938] failed: 0\nstress-ng: info:  [12938] metrics untrustworthy: 0\nstress-ng: info:  [12938] successful run completed in 0.09 secs\nstress-ng: info:  [12942] setting to a 1 secs run per stressor\nstress-ng: info:  [12942] dispatching hogs: 1 switch\nstress-ng: info:  [12942] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12942] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12942]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12942] switch             1000      0.10      0.00      0.05     10154.67       21384.89\nstress-ng: info:  [12942] skipped: 0\nstress-ng: info:  [12942] passed: 1: switch (1)\nstress-ng: info:  [12942] failed: 0\nstress-ng: info:  [12942] metrics untrustworthy: 0\nstress-ng: info:  [12942] successful run completed in 0.11 secs\nstress-ng: info:  [12945] setting to a 1 secs run per stressor\nstress-ng: info:  [12945] dispatching hogs: 1 vfork\nstress-ng: info:  [12945] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12945] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12945]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12945] vfork               200      0.09      0.01      0.01      2152.14        8667.39\nstress-ng: info:  [12945] skipped: 0\nstress-ng: info:  [12945] passed: 1: vfork (1)\nstress-ng: info:  [12945] failed: 0\nstress-ng: info:  [12945] metrics untrustworthy: 0\nstress-ng: info:  [12945] successful run completed in 0.11 secs\nstress-ng: info:  [13147] setting to a 1 secs run per stressor\nstress-ng: info:  [13147] dispatching hogs: 1 yield\nstress-ng: info:  [13147] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13147] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13147]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13147] yield              2998      1.01      0.01      0.03      2966.15       66848.02\nstress-ng: info:  [13147] skipped: 0\nstress-ng: info:  [13147] passed: 1: yield (1)\nstress-ng: info:  [13147] failed: 0\nstress-ng: info:  [13147] metrics untrustworthy: 0\nstress-ng: info:  [13147] successful run completed in 1.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "803": {
            "avg_ns_per_run": 264.472572746963,
            "bytes_jited": 90,
            "bytes_xlated": 136,
            "id": 803,
            "name": "sched_wakeup",
            "run_cnt_delta": 42476,
            "run_time_ns_delta": 11233737,
            "type": "tracepoint"
          },
          "804": {
            "avg_ns_per_run": 445.96090534979425,
            "bytes_jited": 90,
            "bytes_xlated": 136,
            "id": 804,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 486,
            "run_time_ns_delta": 216737,
            "type": "tracepoint"
          },
          "805": {
            "avg_ns_per_run": 421.03134990203154,
            "bytes_jited": 519,
            "bytes_xlated": 896,
            "id": 805,
            "name": "sched_switch",
            "run_cnt_delta": 87273,
            "run_time_ns_delta": 36744669,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.697837063999941,
            "ops_per_sec": 1485.8269734474961,
            "ops_total": 8466.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [23868]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23868] sem-sysv           1001      0.06      0.00      0.02     16257.18       40959.12\nstress-ng: info:  [23868] skipped: 0\nstress-ng: info:  [23868] passed: 1: sem-sysv (1)\nstress-ng: info:  [23868] failed: 0\nstress-ng: info:  [23868] metrics untrustworthy: 0\nstress-ng: info:  [23868] successful run completed in 0.07 secs\nstress-ng: info:  [23872] setting to a 1 secs run per stressor\nstress-ng: info:  [23872] dispatching hogs: 1 switch\nstress-ng: info:  [23872] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23872] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23872]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23872] switch             1000      0.10      0.00      0.05     10209.52       20960.41\nstress-ng: info:  [23872] skipped: 0\nstress-ng: info:  [23872] passed: 1: switch (1)\nstress-ng: info:  [23872] failed: 0\nstress-ng: info:  [23872] metrics untrustworthy: 0\nstress-ng: info:  [23872] successful run completed in 0.11 secs\nstress-ng: info:  [23875] setting to a 1 secs run per stressor\nstress-ng: info:  [23875] dispatching hogs: 1 vfork\nstress-ng: info:  [23875] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23875] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23875]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23875] vfork               200      0.08      0.02      0.00      2664.07        7966.22\nstress-ng: info:  [23875] skipped: 0\nstress-ng: info:  [23875] passed: 1: vfork (1)\nstress-ng: info:  [23875] failed: 0\nstress-ng: info:  [23875] metrics untrustworthy: 0\nstress-ng: info:  [23875] successful run completed in 0.08 secs\nstress-ng: info:  [24077] setting to a 1 secs run per stressor\nstress-ng: info:  [24077] dispatching hogs: 1 yield\nstress-ng: info:  [24077] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24077] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24077]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24077] yield              2007      1.01      0.04      0.00      1988.47       47300.32\nstress-ng: info:  [24077] skipped: 0\nstress-ng: info:  [24077] passed: 1: yield (1)\nstress-ng: info:  [24077] failed: 0\nstress-ng: info:  [24077] metrics untrustworthy: 0\nstress-ng: info:  [24077] successful run completed in 1.05 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 3,
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
          "812": {
            "avg_ns_per_run": 2289.0526315789475,
            "bytes_jited": 2021,
            "bytes_xlated": 3384,
            "id": 812,
            "name": "tcp_set_state",
            "run_cnt_delta": 19,
            "run_time_ns_delta": 43492,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 7.727346999000019,
            "ops_per_sec": 508.45393645560944,
            "ops_total": 3929.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [13208]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13208] sockdiag           1030      0.00      0.00      0.00   1005383.55      504407.44\nstress-ng: info:  [13208] skipped: 0\nstress-ng: info:  [13208] passed: 1: sockdiag (1)\nstress-ng: info:  [13208] failed: 0\nstress-ng: info:  [13208] metrics untrustworthy: 0\nstress-ng: info:  [13208] successful run completed in 0.01 secs\nstress-ng: info:  [13210] setting to a 1 secs run per stressor\nstress-ng: info:  [13210] dispatching hogs: 1 sockfd\nstress-ng: info:  [13210] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13210] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13210]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13210] sockfd              200      0.05      0.00      0.01      4135.33       12290.30\nstress-ng: info:  [13210] skipped: 0\nstress-ng: info:  [13210] passed: 1: sockfd (1)\nstress-ng: info:  [13210] failed: 0\nstress-ng: info:  [13210] metrics untrustworthy: 0\nstress-ng: info:  [13210] successful run completed in 0.06 secs\nstress-ng: info:  [13213] setting to a 1 secs run per stressor\nstress-ng: info:  [13213] dispatching hogs: 1 sockpair\nstress-ng: info:  [13213] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13213] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13213]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13213] sockpair              0      1.90      0.01      0.99         0.00           0.00\nstress-ng: info:  [13213] skipped: 0\nstress-ng: info:  [13213] passed: 1: sockpair (1)\nstress-ng: info:  [13213] failed: 0\nstress-ng: info:  [13213] metrics untrustworthy: 0\nstress-ng: info:  [13213] successful run completed in 1.91 secs\nstress-ng: info:  [13216] setting to a 1 secs run per stressor\nstress-ng: info:  [13216] dispatching hogs: 1 udp-flood\nstress-ng: info:  [13216] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13216] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13216]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13216] udp-flood          1000      0.13      0.00      0.05      7435.07       21070.82\nstress-ng: info:  [13216] skipped: 0\nstress-ng: info:  [13216] passed: 1: udp-flood (1)\nstress-ng: info:  [13216] failed: 0\nstress-ng: info:  [13216] metrics untrustworthy: 0\nstress-ng: info:  [13216] successful run completed in 0.16 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "812": {
            "avg_ns_per_run": 2271.2380952380954,
            "bytes_jited": 2021,
            "bytes_xlated": 3384,
            "id": 812,
            "name": "tcp_set_state",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 47696,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 7.980672383000183,
            "ops_per_sec": 462.2417539477031,
            "ops_total": 3689.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [24117]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24117] sockdiag           1030      0.00      0.00      0.00    725463.16      450371.67\nstress-ng: info:  [24117] skipped: 0\nstress-ng: info:  [24117] passed: 1: sockdiag (1)\nstress-ng: info:  [24117] failed: 0\nstress-ng: info:  [24117] metrics untrustworthy: 0\nstress-ng: info:  [24117] successful run completed in 0.02 secs\nstress-ng: info:  [24119] setting to a 1 secs run per stressor\nstress-ng: info:  [24119] dispatching hogs: 1 sockfd\nstress-ng: info:  [24119] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24119] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24119]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24119] sockfd              200      0.04      0.01      0.00      5224.85       12575.45\nstress-ng: info:  [24119] skipped: 0\nstress-ng: info:  [24119] passed: 1: sockfd (1)\nstress-ng: info:  [24119] failed: 0\nstress-ng: info:  [24119] metrics untrustworthy: 0\nstress-ng: info:  [24119] successful run completed in 0.05 secs\nstress-ng: info:  [24122] setting to a 1 secs run per stressor\nstress-ng: info:  [24122] dispatching hogs: 1 sockpair\nstress-ng: info:  [24122] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24122] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24122]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24122] sockpair              0      2.50      0.02      0.92         0.00           0.00\nstress-ng: info:  [24122] skipped: 0\nstress-ng: info:  [24122] passed: 1: sockpair (1)\nstress-ng: info:  [24122] failed: 0\nstress-ng: info:  [24122] metrics untrustworthy: 0\nstress-ng: info:  [24122] successful run completed in 2.51 secs\nstress-ng: info:  [24125] setting to a 1 secs run per stressor\nstress-ng: info:  [24125] dispatching hogs: 1 udp-flood\nstress-ng: info:  [24125] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24125] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24125]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24125] udp-flood          1000      0.14      0.00      0.06      7314.06       17167.09\nstress-ng: info:  [24125] skipped: 0\nstress-ng: info:  [24125] passed: 1: udp-flood (1)\nstress-ng: info:  [24125] failed: 0\nstress-ng: info:  [24125] metrics untrustworthy: 0\nstress-ng: info:  [24125] successful run completed in 0.15 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 1,
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
          "818": {
            "avg_ns_per_run": null,
            "bytes_jited": 972,
            "bytes_xlated": 1640,
            "id": 818,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 19.219273279999925,
            "ops_per_sec": 283.10123492869246,
            "ops_total": 5441.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [13335]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13335] sockdiag           1030      0.01      0.00      0.00    169903.38      494479.12\nstress-ng: info:  [13335] skipped: 0\nstress-ng: info:  [13335] passed: 1: sockdiag (1)\nstress-ng: info:  [13335] failed: 0\nstress-ng: info:  [13335] metrics untrustworthy: 0\nstress-ng: info:  [13335] successful run completed in 0.02 secs\nstress-ng: info:  [13337] setting to a 5 secs run per stressor\nstress-ng: info:  [13337] dispatching hogs: 1 sockfd\nstress-ng: info:  [13337] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13337] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13337]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13337] sockfd              200      0.05      0.01      0.01      4378.19       11982.51\nstress-ng: info:  [13337] skipped: 0\nstress-ng: info:  [13337] passed: 1: sockfd (1)\nstress-ng: info:  [13337] failed: 0\nstress-ng: info:  [13337] metrics untrustworthy: 0\nstress-ng: info:  [13337] successful run completed in 0.05 secs\nstress-ng: info:  [13340] setting to a 5 secs run per stressor\nstress-ng: info:  [13340] dispatching hogs: 1 sockpair\nstress-ng: info:  [13340] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13340] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13340]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13340] sockpair            500      7.51      0.10      3.38        66.60         143.50\nstress-ng: info:  [13340] skipped: 0\nstress-ng: info:  [13340] passed: 1: sockpair (1)\nstress-ng: info:  [13340] failed: 0\nstress-ng: info:  [13340] metrics untrustworthy: 0\nstress-ng: info:  [13340] successful run completed in 7.51 secs\nstress-ng: info:  [13344] setting to a 5 secs run per stressor\nstress-ng: info:  [13344] dispatching hogs: 1 udp-flood\nstress-ng: info:  [13344] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13344] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13344]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13344] udp-flood          1000      0.11      0.01      0.04      9337.07       22198.54\nstress-ng: info:  [13344] skipped: 0\nstress-ng: info:  [13344] passed: 1: udp-flood (1)\nstress-ng: info:  [13344] failed: 0\nstress-ng: info:  [13344] metrics untrustworthy: 0\nstress-ng: info:  [13344] successful run completed in 0.13 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "818": {
            "avg_ns_per_run": null,
            "bytes_jited": 972,
            "bytes_xlated": 1640,
            "id": 818,
            "name": "tcp_retransmit_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 20.203669062000245,
            "ops_per_sec": 254.80520316394092,
            "ops_total": 5148.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [24210]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24210] sockdiag           1030      0.00      0.00      0.00    296753.20      450568.68\nstress-ng: info:  [24210] skipped: 0\nstress-ng: info:  [24210] passed: 1: sockdiag (1)\nstress-ng: info:  [24210] failed: 0\nstress-ng: info:  [24210] metrics untrustworthy: 0\nstress-ng: info:  [24210] successful run completed in 0.01 secs\nstress-ng: info:  [24212] setting to a 5 secs run per stressor\nstress-ng: info:  [24212] dispatching hogs: 1 sockfd\nstress-ng: info:  [24212] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24212] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24212]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24212] sockfd              200      0.04      0.00      0.02      4727.57        9943.82\nstress-ng: info:  [24212] skipped: 0\nstress-ng: info:  [24212] passed: 1: sockfd (1)\nstress-ng: info:  [24212] failed: 0\nstress-ng: info:  [24212] metrics untrustworthy: 0\nstress-ng: info:  [24212] successful run completed in 0.05 secs\nstress-ng: info:  [24215] setting to a 5 secs run per stressor\nstress-ng: info:  [24215] dispatching hogs: 1 sockpair\nstress-ng: info:  [24215] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24215] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24215]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24215] sockpair            500      6.67      0.14      3.25        74.92         147.54\nstress-ng: info:  [24215] skipped: 0\nstress-ng: info:  [24215] passed: 1: sockpair (1)\nstress-ng: info:  [24215] failed: 0\nstress-ng: info:  [24215] metrics untrustworthy: 0\nstress-ng: info:  [24215] successful run completed in 6.69 secs\nstress-ng: info:  [24231] setting to a 5 secs run per stressor\nstress-ng: info:  [24231] dispatching hogs: 1 udp-flood\nstress-ng: info:  [24231] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [24231] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24231]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24231] udp-flood          1000      0.12      0.00      0.05      8270.49       21934.15\nstress-ng: info:  [24231] skipped: 0\nstress-ng: info:  [24231] passed: 1: udp-flood (1)\nstress-ng: info:  [24231] failed: 0\nstress-ng: info:  [24231] metrics untrustworthy: 0\nstress-ng: info:  [24231] successful run completed in 0.13 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "rotate",
          "cond_select",
          "extract",
          "endian_fusion",
          "map_inline",
          "const_prop",
          "dce",
          "bounds_check_merge",
          "skb_load_bytes_spec",
          "bulk_memory"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 0,
          "not_applied": 1,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "stress_ng_network",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 87,
    "per_program_geomean": 0.9820106488194009,
    "program_count": 148,
    "wins": 61
  },
  "workload_seconds": 1.0
}
```
