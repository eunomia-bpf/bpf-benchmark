# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T04:16:54.679873+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T03:59:36.967839+00:00",
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
      "invoked_at": "2026-05-05T03:59:36.967782+00:00",
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
        "captured_at": "2026-05-05T03:59:36.967774+00:00",
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
      "captured_at": "2026-05-05T03:59:36.954579+00:00",
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
      "baseline_avg_ns_per_run": 136.48709900831798,
      "baseline_run_cnt_delta": 2695723,
      "baseline_run_time_ns_delta": 367931412,
      "post_rejit_avg_ns_per_run": 141.84826661109588,
      "post_rejit_run_cnt_delta": 2548101,
      "post_rejit_run_time_ns_delta": 361443710,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 1.0392796655634915,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 890.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1781,
      "post_rejit_avg_ns_per_run": 1199.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 2399,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 1.3469960696238068,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 161.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 323,
      "post_rejit_avg_ns_per_run": 151.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 302,
      "program": "do_ret_sys_execve",
      "program_id": 10,
      "ratio": 0.934984520123839,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 201.86341348788986,
      "baseline_run_cnt_delta": 1817156,
      "baseline_run_time_ns_delta": 366817313,
      "post_rejit_avg_ns_per_run": 202.6130059010164,
      "post_rejit_run_cnt_delta": 1774779,
      "post_rejit_run_time_ns_delta": 359593308,
      "program": "trace_pid_start_tp",
      "program_id": 13,
      "ratio": 1.0037133643990992,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 206.42821734503067,
      "baseline_run_cnt_delta": 1817166,
      "baseline_run_time_ns_delta": 375114338,
      "post_rejit_avg_ns_per_run": 206.72562541237298,
      "post_rejit_run_cnt_delta": 1774789,
      "post_rejit_run_time_ns_delta": 366894366,
      "program": "trace_req_start",
      "program_id": 14,
      "ratio": 1.0014407335933402,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 93.43262411737805,
      "baseline_run_cnt_delta": 1817171,
      "baseline_run_time_ns_delta": 169783055,
      "post_rejit_avg_ns_per_run": 93.60065449849391,
      "post_rejit_run_cnt_delta": 1774794,
      "post_rejit_run_time_ns_delta": 166121880,
      "program": "trace_req_completion_tp",
      "program_id": 15,
      "ratio": 1.001798412307298,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 66.5360681825639,
      "baseline_run_cnt_delta": 121908,
      "baseline_run_time_ns_delta": 8111279,
      "post_rejit_avg_ns_per_run": 214.70323691077675,
      "post_rejit_run_cnt_delta": 90055,
      "post_rejit_run_time_ns_delta": 19335100,
      "program": "vfs_create",
      "program_id": 18,
      "ratio": 3.226869918457863,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 75.3963963963964,
      "baseline_run_cnt_delta": 555,
      "baseline_run_time_ns_delta": 41845,
      "post_rejit_avg_ns_per_run": 74.68161434977578,
      "post_rejit_run_cnt_delta": 446,
      "post_rejit_run_time_ns_delta": 33308,
      "program": "kfunc__vmlinux__vfs_fsync_range",
      "program_id": 19,
      "ratio": 0.9905196789132646,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 47.710287158451195,
      "baseline_run_cnt_delta": 1734269,
      "baseline_run_time_ns_delta": 82742472,
      "post_rejit_avg_ns_per_run": 49.65112853960221,
      "post_rejit_run_cnt_delta": 1983980,
      "post_rejit_run_time_ns_delta": 98506846,
      "program": "vfs_open",
      "program_id": 20,
      "ratio": 1.0406797254165598,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 45.62309034963022,
      "baseline_run_cnt_delta": 55573,
      "baseline_run_time_ns_delta": 2535412,
      "post_rejit_avg_ns_per_run": 44.397566661809705,
      "post_rejit_run_cnt_delta": 41178,
      "post_rejit_run_time_ns_delta": 1828203,
      "program": "vfs_read",
      "program_id": 21,
      "ratio": 0.9731380825273174,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 57.396173703149096,
      "baseline_run_cnt_delta": 44743,
      "baseline_run_time_ns_delta": 2568077,
      "post_rejit_avg_ns_per_run": 58.656090444930705,
      "post_rejit_run_cnt_delta": 43872,
      "post_rejit_run_time_ns_delta": 2573360,
      "program": "vfs_write",
      "program_id": 22,
      "ratio": 1.021951232294645,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 324.30790720272074,
      "baseline_run_cnt_delta": 8233,
      "baseline_run_time_ns_delta": 2670027,
      "post_rejit_avg_ns_per_run": 191.8519313304721,
      "post_rejit_run_cnt_delta": 4660,
      "post_rejit_run_time_ns_delta": 894030,
      "program": "__x64_sys_open",
      "program_id": 25,
      "ratio": 0.5915734000606648,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 264.10241685065586,
      "baseline_run_cnt_delta": 846970,
      "baseline_run_time_ns_delta": 223686824,
      "post_rejit_avg_ns_per_run": 254.04072891081523,
      "post_rejit_run_cnt_delta": 853767,
      "post_rejit_run_time_ns_delta": 216891591,
      "program": "kretfunc__vmlinux____x64_sys_openat",
      "program_id": 26,
      "ratio": 0.9619023253939767,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 346.93026315789473,
      "baseline_run_cnt_delta": 1520,
      "baseline_run_time_ns_delta": 527334,
      "post_rejit_avg_ns_per_run": 1381.7,
      "post_rejit_run_cnt_delta": 760,
      "post_rejit_run_time_ns_delta": 1050092,
      "program": "kretfunc__vmlinux____x64_sys_openat2",
      "program_id": 27,
      "ratio": 3.9826447754174774,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 84.47119641159033,
      "baseline_run_cnt_delta": 28105821,
      "baseline_run_time_ns_delta": 2374132326,
      "post_rejit_avg_ns_per_run": 192.68868656606136,
      "post_rejit_run_cnt_delta": 24144252,
      "post_rejit_run_time_ns_delta": 4652324206,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 30,
      "ratio": 2.2811170523402517,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 99.1134834860745,
      "baseline_run_cnt_delta": 28105825,
      "baseline_run_time_ns_delta": 2785666222,
      "post_rejit_avg_ns_per_run": 25.564187275018952,
      "post_rejit_run_cnt_delta": 24144256,
      "post_rejit_run_time_ns_delta": 617228282,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 31,
      "ratio": 0.2579284510629751,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 242.912926542276,
      "baseline_run_cnt_delta": 5949,
      "baseline_run_time_ns_delta": 1445089,
      "post_rejit_avg_ns_per_run": 258.6649072538079,
      "post_rejit_run_cnt_delta": 6631,
      "post_rejit_run_time_ns_delta": 1715207,
      "program": "trace_connect_entry",
      "program_id": 34,
      "ratio": 1.06484620203524,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 1739.05227769373,
      "baseline_run_cnt_delta": 5949,
      "baseline_run_time_ns_delta": 10345622,
      "post_rejit_avg_ns_per_run": 1792.2094706680741,
      "post_rejit_run_cnt_delta": 6631,
      "post_rejit_run_time_ns_delta": 11884141,
      "program": "trace_connect_v4_return",
      "program_id": 35,
      "ratio": 1.030566759640394,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 403.0613135148235,
      "baseline_run_cnt_delta": 61895,
      "baseline_run_time_ns_delta": 24947480,
      "post_rejit_avg_ns_per_run": 424.28421947203486,
      "post_rejit_run_cnt_delta": 56481,
      "post_rejit_run_time_ns_delta": 23963997,
      "program": "tracepoint__sock__inet_sock_set_state",
      "program_id": 39,
      "ratio": 1.0526542866943513,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 181.55640054974512,
      "baseline_run_cnt_delta": 11881870,
      "baseline_run_time_ns_delta": 2157229549,
      "post_rejit_avg_ns_per_run": 188.8414008071211,
      "post_rejit_run_cnt_delta": 11773698,
      "post_rejit_run_time_ns_delta": 2223361623,
      "program": "sched_switch",
      "program_id": 42,
      "ratio": 1.0401252736632656,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 68.05775946952836,
      "baseline_run_cnt_delta": 3706890,
      "baseline_run_time_ns_delta": 252282628,
      "post_rejit_avg_ns_per_run": 81.30538287515891,
      "post_rejit_run_cnt_delta": 2805118,
      "post_rejit_run_time_ns_delta": 228071193,
      "program": "sched_wakeup",
      "program_id": 43,
      "ratio": 1.1946526525246828,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 315.52564102564105,
      "baseline_run_cnt_delta": 78,
      "baseline_run_time_ns_delta": 24611,
      "post_rejit_avg_ns_per_run": 326.2564102564103,
      "post_rejit_run_cnt_delta": 78,
      "post_rejit_run_time_ns_delta": 25448,
      "program": "raw_tracepoint__sched_wakeup_new",
      "program_id": 44,
      "ratio": 1.0340091828857014,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 1796.6666666666667,
      "baseline_run_cnt_delta": 6,
      "baseline_run_time_ns_delta": 10780,
      "post_rejit_avg_ns_per_run": 1931.6666666666667,
      "post_rejit_run_cnt_delta": 6,
      "post_rejit_run_time_ns_delta": 11590,
      "program": "tracepoint__sched_process_free",
      "program_id": 58,
      "ratio": 1.075139146567718,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 1355.728125,
      "baseline_run_cnt_delta": 1600,
      "baseline_run_time_ns_delta": 2169165,
      "post_rejit_avg_ns_per_run": 1326.25625,
      "post_rejit_run_cnt_delta": 1600,
      "post_rejit_run_time_ns_delta": 2122010,
      "program": "native_tracer_entry",
      "program_id": 59,
      "ratio": 0.9782612203313256,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 1246.7527559055118,
      "baseline_run_cnt_delta": 1270,
      "baseline_run_time_ns_delta": 1583376,
      "post_rejit_avg_ns_per_run": 1218.2864111498259,
      "post_rejit_run_cnt_delta": 1435,
      "post_rejit_run_time_ns_delta": 1748241,
      "program": "cil_from_netdev",
      "program_id": 158,
      "ratio": 0.9771676103214139,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network_lossy_multi"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1376.739534883721,
      "baseline_run_cnt_delta": 1505,
      "baseline_run_time_ns_delta": 2071993,
      "post_rejit_avg_ns_per_run": 1328.232492997199,
      "post_rejit_run_cnt_delta": 1071,
      "post_rejit_run_time_ns_delta": 1422537,
      "program": "event_exit_acct_process",
      "program_id": 178,
      "ratio": 0.9647667255443355,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2142.3220234423197,
      "baseline_run_cnt_delta": 1621,
      "baseline_run_time_ns_delta": 3472704,
      "post_rejit_avg_ns_per_run": 2312.479359730413,
      "post_rejit_run_cnt_delta": 1187,
      "post_rejit_run_time_ns_delta": 2744913,
      "program": "event_wake_up_new_task",
      "program_id": 180,
      "ratio": 1.0794265915329952,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6521.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 13043,
      "post_rejit_avg_ns_per_run": 15230.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 30461,
      "program": "event_execve",
      "program_id": 183,
      "ratio": 2.3354289657287435,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 659.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1319,
      "post_rejit_avg_ns_per_run": 1129.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 2259,
      "program": "tg_kp_bprm_committing_creds",
      "program_id": 184,
      "ratio": 1.712661106899166,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 645.6491277015214,
      "baseline_run_cnt_delta": 53766,
      "baseline_run_time_ns_delta": 34713971,
      "post_rejit_avg_ns_per_run": 637.9912112676056,
      "post_rejit_run_cnt_delta": 62125,
      "post_rejit_run_time_ns_delta": 39635204,
      "program": "generic_kprobe_event",
      "program_id": 210,
      "ratio": 0.9881391980483618,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 386.15096901387494,
      "baseline_run_cnt_delta": 53766,
      "baseline_run_time_ns_delta": 20761793,
      "post_rejit_avg_ns_per_run": 385.17245875251507,
      "post_rejit_run_cnt_delta": 62125,
      "post_rejit_run_time_ns_delta": 23928839,
      "program": "generic_retkprobe_event",
      "program_id": 218,
      "ratio": 0.9974659904030314,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1230.7611543792489,
      "baseline_run_cnt_delta": 60604,
      "baseline_run_time_ns_delta": 74589049,
      "post_rejit_avg_ns_per_run": 969.0520175777616,
      "post_rejit_run_cnt_delta": 69861,
      "post_rejit_run_time_ns_delta": 67698943,
      "program": "generic_kprobe_event",
      "program_id": 223,
      "ratio": 0.7873599309904415,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 649.788063088197,
      "baseline_run_cnt_delta": 53766,
      "baseline_run_time_ns_delta": 34936505,
      "post_rejit_avg_ns_per_run": 641.878921529175,
      "post_rejit_run_cnt_delta": 62125,
      "post_rejit_run_time_ns_delta": 39876728,
      "program": "generic_kprobe_event",
      "program_id": 239,
      "ratio": 0.9878281211854943,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 431.83249637317266,
      "baseline_run_cnt_delta": 53766,
      "baseline_run_time_ns_delta": 23217906,
      "post_rejit_avg_ns_per_run": 552.1960724346077,
      "post_rejit_run_cnt_delta": 62125,
      "post_rejit_run_time_ns_delta": 34305181,
      "program": "generic_retkprobe_event",
      "program_id": 244,
      "ratio": 1.278727462783212,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1210.7851296944095,
      "baseline_run_cnt_delta": 60604,
      "baseline_run_time_ns_delta": 73378422,
      "post_rejit_avg_ns_per_run": 994.3192768497445,
      "post_rejit_run_cnt_delta": 69861,
      "post_rejit_run_time_ns_delta": 69464139,
      "program": "generic_kprobe_event",
      "program_id": 245,
      "ratio": 0.821218606393606,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 514.4126868786815,
      "baseline_run_cnt_delta": 194043,
      "baseline_run_time_ns_delta": 99818181,
      "post_rejit_avg_ns_per_run": 503.3538286839017,
      "post_rejit_run_cnt_delta": 264190,
      "post_rejit_run_time_ns_delta": 132981048,
      "program": "generic_kprobe_event",
      "program_id": 254,
      "ratio": 0.978501972294109,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 850.4870079726969,
      "baseline_run_cnt_delta": 394973,
      "baseline_run_time_ns_delta": 335919405,
      "post_rejit_avg_ns_per_run": 757.2561210963933,
      "post_rejit_run_cnt_delta": 539405,
      "post_rejit_run_time_ns_delta": 408467738,
      "program": "generic_kprobe_event",
      "program_id": 263,
      "ratio": 0.8903794108524505,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 193.80022655680213,
      "baseline_run_cnt_delta": 322215,
      "baseline_run_time_ns_delta": 62445340,
      "post_rejit_avg_ns_per_run": 194.2751662526595,
      "post_rejit_run_cnt_delta": 359092,
      "post_rejit_run_time_ns_delta": 69762658,
      "program": "generic_kprobe_event",
      "program_id": 286,
      "ratio": 1.002450666360383,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 497.22115551946166,
      "baseline_run_cnt_delta": 379258,
      "baseline_run_time_ns_delta": 188575101,
      "post_rejit_avg_ns_per_run": 502.09717516912673,
      "post_rejit_run_cnt_delta": 567326,
      "post_rejit_run_time_ns_delta": 284852782,
      "program": "generic_kprobe_event",
      "program_id": 289,
      "ratio": 1.0098065410040145,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 40.44001444926673,
      "baseline_run_cnt_delta": 379258,
      "baseline_run_time_ns_delta": 15337199,
      "post_rejit_avg_ns_per_run": 41.60171753101391,
      "post_rejit_run_cnt_delta": 567326,
      "post_rejit_run_time_ns_delta": 23601736,
      "program": "generic_retkprobe_event",
      "program_id": 294,
      "ratio": 1.0287265743488934,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6377.99786036036,
      "baseline_run_cnt_delta": 8880,
      "baseline_run_time_ns_delta": 56636621,
      "post_rejit_avg_ns_per_run": 5122.3181359919345,
      "post_rejit_run_cnt_delta": 8927,
      "post_rejit_run_time_ns_delta": 45726934,
      "program": "generic_kprobe_event",
      "program_id": 300,
      "ratio": 0.8031232132935399,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 62.06216216216216,
      "baseline_run_cnt_delta": 8880,
      "baseline_run_time_ns_delta": 551112,
      "post_rejit_avg_ns_per_run": 51.564131287106534,
      "post_rejit_run_cnt_delta": 8927,
      "post_rejit_run_time_ns_delta": 460313,
      "program": "generic_retkprobe_event",
      "program_id": 305,
      "ratio": 0.8308465172768984,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6322.181818181818,
      "baseline_run_cnt_delta": 22,
      "baseline_run_time_ns_delta": 139088,
      "post_rejit_avg_ns_per_run": 6287.75,
      "post_rejit_run_cnt_delta": 20,
      "post_rejit_run_time_ns_delta": 125755,
      "program": "generic_kprobe_event",
      "program_id": 310,
      "ratio": 0.9945538076613367,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 631.0454545454545,
      "baseline_run_cnt_delta": 22,
      "baseline_run_time_ns_delta": 13883,
      "post_rejit_avg_ns_per_run": 616.8,
      "post_rejit_run_cnt_delta": 20,
      "post_rejit_run_time_ns_delta": 12336,
      "program": "generic_retkprobe_event",
      "program_id": 319,
      "ratio": 0.9774256284664697,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4216.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 8432,
      "post_rejit_avg_ns_per_run": 10555.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 21111,
      "program": "generic_kprobe_event",
      "program_id": 356,
      "ratio": 2.5036764705882355,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 931.5019900942085,
      "baseline_run_cnt_delta": 7811188,
      "baseline_run_time_ns_delta": 7276137167,
      "post_rejit_avg_ns_per_run": 871.0861299421252,
      "post_rejit_run_cnt_delta": 6828717,
      "post_rejit_run_time_ns_delta": 5948400664,
      "program": "generic_tracepoint_event",
      "program_id": 368,
      "ratio": 0.9351414588540246,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4121.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 8242,
      "post_rejit_avg_ns_per_run": 8770.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 17540,
      "program": "generic_rawtp_event",
      "program_id": 375,
      "ratio": 2.1281242416889103,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1089.35184352518,
      "baseline_run_cnt_delta": 22240,
      "baseline_run_time_ns_delta": 24227185,
      "post_rejit_avg_ns_per_run": 1189.4735087719298,
      "post_rejit_run_cnt_delta": 17100,
      "post_rejit_run_time_ns_delta": 20339997,
      "program": "generic_kprobe_event",
      "program_id": 380,
      "ratio": 1.0919093916642697,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3746.1638225255974,
      "baseline_run_cnt_delta": 879,
      "baseline_run_time_ns_delta": 3292878,
      "post_rejit_avg_ns_per_run": 4462.496036240091,
      "post_rejit_run_cnt_delta": 883,
      "post_rejit_run_time_ns_delta": 3940384,
      "program": "generic_kprobe_event",
      "program_id": 384,
      "ratio": 1.191217535497835,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 690.7716400699327,
      "baseline_run_cnt_delta": 53766,
      "baseline_run_time_ns_delta": 37140028,
      "post_rejit_avg_ns_per_run": 669.782583501006,
      "post_rejit_run_cnt_delta": 62125,
      "post_rejit_run_time_ns_delta": 41610243,
      "program": "generic_kprobe_event",
      "program_id": 402,
      "ratio": 0.9696150574930931,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 457.36017185581966,
      "baseline_run_cnt_delta": 53766,
      "baseline_run_time_ns_delta": 24590427,
      "post_rejit_avg_ns_per_run": 517.2467283702214,
      "post_rejit_run_cnt_delta": 62125,
      "post_rejit_run_time_ns_delta": 32133953,
      "program": "generic_retkprobe_event",
      "program_id": 404,
      "ratio": 1.1309395968420282,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1226.671259322817,
      "baseline_run_cnt_delta": 60604,
      "baseline_run_time_ns_delta": 74341185,
      "post_rejit_avg_ns_per_run": 1017.7285180572852,
      "post_rejit_run_cnt_delta": 69861,
      "post_rejit_run_time_ns_delta": 71099532,
      "program": "generic_kprobe_event",
      "program_id": 410,
      "ratio": 0.829666881262973,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 583.3634531971456,
      "baseline_run_cnt_delta": 71470,
      "baseline_run_time_ns_delta": 41692986,
      "post_rejit_avg_ns_per_run": 487.8748718600031,
      "post_rejit_run_cnt_delta": 110231,
      "post_rejit_run_time_ns_delta": 53778935,
      "program": "generic_kprobe_event",
      "program_id": 419,
      "ratio": 0.8363137409211809,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1335.6963954338414,
      "baseline_run_cnt_delta": 17783,
      "baseline_run_time_ns_delta": 23752689,
      "post_rejit_avg_ns_per_run": 1041.0319634703196,
      "post_rejit_run_cnt_delta": 28032,
      "post_rejit_run_time_ns_delta": 29182208,
      "program": "generic_kprobe_event",
      "program_id": 425,
      "ratio": 0.7793926576646835,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1414.691121863396,
      "baseline_run_cnt_delta": 8887,
      "baseline_run_time_ns_delta": 12572360,
      "post_rejit_avg_ns_per_run": 1068.9488295746503,
      "post_rejit_run_cnt_delta": 14012,
      "post_rejit_run_time_ns_delta": 14978111,
      "program": "generic_kprobe_event",
      "program_id": 435,
      "ratio": 0.7556058089674427,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1912.5966017778778,
      "baseline_run_cnt_delta": 8887,
      "baseline_run_time_ns_delta": 16997246,
      "post_rejit_avg_ns_per_run": 1693.61704253497,
      "post_rejit_run_cnt_delta": 14012,
      "post_rejit_run_time_ns_delta": 23730962,
      "program": "generic_retkprobe_event",
      "program_id": 439,
      "ratio": 0.8855066671982201,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1747.5451170117012,
      "baseline_run_cnt_delta": 8888,
      "baseline_run_time_ns_delta": 15532181,
      "post_rejit_avg_ns_per_run": 1268.119389138657,
      "post_rejit_run_cnt_delta": 14013,
      "post_rejit_run_time_ns_delta": 17770157,
      "program": "generic_kprobe_event",
      "program_id": 445,
      "ratio": 0.7256575963584497,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1323.2144182646348,
      "baseline_run_cnt_delta": 17783,
      "baseline_run_time_ns_delta": 23530722,
      "post_rejit_avg_ns_per_run": 992.9594392123288,
      "post_rejit_run_cnt_delta": 28032,
      "post_rejit_run_time_ns_delta": 27834639,
      "program": "generic_kprobe_event",
      "program_id": 448,
      "ratio": 0.7504146157314188,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1137.5531295792339,
      "baseline_run_cnt_delta": 334390,
      "baseline_run_time_ns_delta": 380386391,
      "post_rejit_avg_ns_per_run": 1077.5157072841916,
      "post_rejit_run_cnt_delta": 284836,
      "post_rejit_run_time_ns_delta": 306915264,
      "program": "generic_kprobe_event",
      "program_id": 457,
      "ratio": 0.9472223136362437,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 316.4512532552083,
      "baseline_run_cnt_delta": 36864,
      "baseline_run_time_ns_delta": 11665659,
      "post_rejit_avg_ns_per_run": 317.3246570142617,
      "post_rejit_run_cnt_delta": 36882,
      "post_rejit_run_time_ns_delta": 11703568,
      "program": "xdp_root",
      "program_id": 474,
      "ratio": 1.0027599946281425,
      "runner": "katran",
      "type": "xdp",
      "workload": "network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 154.66661957770557,
      "baseline_run_cnt_delta": 29822984,
      "baseline_run_time_ns_delta": 4612620121,
      "post_rejit_avg_ns_per_run": 156.62441874671012,
      "post_rejit_run_cnt_delta": 29974454,
      "post_rejit_run_time_ns_delta": 4694731435,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 497,
      "ratio": 1.0126581881361991,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 304.15366932601137,
      "baseline_run_cnt_delta": 29823011,
      "baseline_run_time_ns_delta": 9070778226,
      "post_rejit_avg_ns_per_run": 304.0246600791513,
      "post_rejit_run_cnt_delta": 29974478,
      "post_rejit_run_time_ns_delta": 9112980485,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 500,
      "ratio": 0.99957584188563,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 265.3590630558107,
      "baseline_run_cnt_delta": 29822993,
      "baseline_run_time_ns_delta": 7913801480,
      "post_rejit_avg_ns_per_run": 261.0933840529672,
      "post_rejit_run_cnt_delta": 29974454,
      "post_rejit_run_time_ns_delta": 7826131630,
      "program": "trace_sys_enter",
      "program_id": 503,
      "ratio": 0.9839248791666623,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 260.82820792410104,
      "baseline_run_cnt_delta": 29823017,
      "baseline_run_time_ns_delta": 7778684079,
      "post_rejit_avg_ns_per_run": 259.42529671409125,
      "post_rejit_run_cnt_delta": 29974478,
      "post_rejit_run_time_ns_delta": 7776137849,
      "program": "trace_sys_exit",
      "program_id": 504,
      "ratio": 0.9946213209791404,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 68.3029665704395,
      "baseline_run_cnt_delta": 1509622,
      "baseline_run_time_ns_delta": 103111661,
      "post_rejit_avg_ns_per_run": 72.78695006889836,
      "post_rejit_run_cnt_delta": 1224267,
      "post_rejit_run_time_ns_delta": 89110661,
      "program": "trace_arch_prctl",
      "program_id": 509,
      "ratio": 1.065648444329788,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 274.7958257100122,
      "baseline_run_cnt_delta": 1509622,
      "baseline_run_time_ns_delta": 414837824,
      "post_rejit_avg_ns_per_run": 266.3988263997968,
      "post_rejit_run_cnt_delta": 1224267,
      "post_rejit_run_time_ns_delta": 326143292,
      "program": "trace_ret_arch_prctl",
      "program_id": 510,
      "ratio": 0.9694427697781821,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 321.3978853644964,
      "baseline_run_cnt_delta": 1797,
      "baseline_run_time_ns_delta": 577552,
      "post_rejit_avg_ns_per_run": 322.3808368708308,
      "post_rejit_run_cnt_delta": 1649,
      "post_rejit_run_time_ns_delta": 531606,
      "program": "trace_dup",
      "program_id": 511,
      "ratio": 1.003058363328121,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1309.0222593210908,
      "baseline_run_cnt_delta": 1797,
      "baseline_run_time_ns_delta": 2352313,
      "post_rejit_avg_ns_per_run": 1593.5603395997575,
      "post_rejit_run_cnt_delta": 1649,
      "post_rejit_run_time_ns_delta": 2627781,
      "program": "trace_ret_dup",
      "program_id": 512,
      "ratio": 1.2173668768827806,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1131.5,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 4526,
      "post_rejit_avg_ns_per_run": 741.5,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 2966,
      "program": "trace_dup2",
      "program_id": 513,
      "ratio": 0.655324790101635,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3888.5,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 15554,
      "post_rejit_avg_ns_per_run": 2725.25,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 10901,
      "program": "trace_ret_dup2",
      "program_id": 514,
      "ratio": 0.7008486562942009,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2506.626461038961,
      "baseline_run_cnt_delta": 6160,
      "baseline_run_time_ns_delta": 15440819,
      "post_rejit_avg_ns_per_run": 2960.4956835976714,
      "post_rejit_run_cnt_delta": 4981,
      "post_rejit_run_time_ns_delta": 14746229,
      "program": "tracepoint__sched__sched_process_fork",
      "program_id": 522,
      "ratio": 1.1810677536574747,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3754.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 7508,
      "post_rejit_avg_ns_per_run": 7461.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 14923,
      "program": "tracepoint__sched__sched_process_exec",
      "program_id": 530,
      "ratio": 1.9876132125732553,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1259.3258408258407,
      "baseline_run_cnt_delta": 6006,
      "baseline_run_time_ns_delta": 7563511,
      "post_rejit_avg_ns_per_run": 1376.2097134728713,
      "post_rejit_run_cnt_delta": 4921,
      "post_rejit_run_time_ns_delta": 6772328,
      "program": "tracepoint__sched__sched_process_exit",
      "program_id": 532,
      "ratio": 1.0928146384817932,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 866.0098612736085,
      "baseline_run_cnt_delta": 5983,
      "baseline_run_time_ns_delta": 5181337,
      "post_rejit_avg_ns_per_run": 978.0952477660438,
      "post_rejit_run_cnt_delta": 4924,
      "post_rejit_run_time_ns_delta": 4816141,
      "program": "tracepoint__sched__sched_process_free",
      "program_id": 533,
      "ratio": 1.1294273789533937,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 378.7381171483004,
      "baseline_run_cnt_delta": 1407259,
      "baseline_run_time_ns_delta": 532982624,
      "post_rejit_avg_ns_per_run": 408.3298501049583,
      "post_rejit_run_cnt_delta": 975149,
      "post_rejit_run_time_ns_delta": 398182445,
      "program": "tracepoint__sched__sched_switch",
      "program_id": 535,
      "ratio": 1.078132439321049,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 18.03117807776686,
      "baseline_run_cnt_delta": 445794,
      "baseline_run_time_ns_delta": 8038191,
      "post_rejit_avg_ns_per_run": 17.346020029150406,
      "post_rejit_run_cnt_delta": 680608,
      "post_rejit_run_time_ns_delta": 11805840,
      "program": "trace_filldir64",
      "program_id": 536,
      "ratio": 0.9620014817855257,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 899.0391275391275,
      "baseline_run_cnt_delta": 6006,
      "baseline_run_time_ns_delta": 5399629,
      "post_rejit_avg_ns_per_run": 932.45925624873,
      "post_rejit_run_cnt_delta": 4921,
      "post_rejit_run_time_ns_delta": 4588632,
      "program": "trace_do_exit",
      "program_id": 538,
      "ratio": 1.037173163754375,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 92.90275813353568,
      "baseline_run_cnt_delta": 6101590,
      "baseline_run_time_ns_delta": 566854540,
      "post_rejit_avg_ns_per_run": 100.53838199411375,
      "post_rejit_run_cnt_delta": 4770440,
      "post_rejit_run_time_ns_delta": 479612319,
      "program": "trace_security_file_ioctl",
      "program_id": 542,
      "ratio": 1.0821894205724532,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 10979.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 21958,
      "post_rejit_avg_ns_per_run": 4797.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 9594,
      "program": "trace_security_bprm_check",
      "program_id": 547,
      "ratio": 0.43692503871026506,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 548.5469832937455,
      "baseline_run_cnt_delta": 882005,
      "baseline_run_time_ns_delta": 483821182,
      "post_rejit_avg_ns_per_run": 551.959995047185,
      "post_rejit_run_cnt_delta": 638021,
      "post_rejit_run_time_ns_delta": 352162068,
      "program": "trace_security_file_open",
      "program_id": 548,
      "ratio": 1.0062219132679322,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1715.7936893203882,
      "baseline_run_cnt_delta": 412,
      "baseline_run_time_ns_delta": 706907,
      "post_rejit_avg_ns_per_run": 1777.7958115183246,
      "post_rejit_run_cnt_delta": 382,
      "post_rejit_run_time_ns_delta": 679118,
      "program": "trace_security_inode_unlink",
      "program_id": 550,
      "ratio": 1.0361361174037742,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 257.9464476155299,
      "baseline_run_cnt_delta": 384446,
      "baseline_run_time_ns_delta": 99166480,
      "post_rejit_avg_ns_per_run": 244.58289610128307,
      "post_rejit_run_cnt_delta": 516888,
      "post_rejit_run_time_ns_delta": 126421964,
      "program": "trace_commit_creds",
      "program_id": 551,
      "ratio": 0.948192535164643,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 526.2364302364302,
      "baseline_run_cnt_delta": 6006,
      "baseline_run_time_ns_delta": 3160576,
      "post_rejit_avg_ns_per_run": 443.616744564113,
      "post_rejit_run_cnt_delta": 4921,
      "post_rejit_run_time_ns_delta": 2183038,
      "program": "trace_switch_task_namespaces",
      "program_id": 552,
      "ratio": 0.8429989241999125,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 134.3471848267331,
      "baseline_run_cnt_delta": 2339483,
      "baseline_run_time_ns_delta": 314302955,
      "post_rejit_avg_ns_per_run": 140.7474461859275,
      "post_rejit_run_cnt_delta": 2344043,
      "post_rejit_run_time_ns_delta": 329918066,
      "program": "trace_cap_capable",
      "program_id": 553,
      "ratio": 1.047639713235888,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 342.5153170431471,
      "baseline_run_cnt_delta": 363941,
      "baseline_run_time_ns_delta": 124655367,
      "post_rejit_avg_ns_per_run": 334.18461226604205,
      "post_rejit_run_cnt_delta": 443990,
      "post_rejit_run_time_ns_delta": 148374626,
      "program": "trace_security_socket_create",
      "program_id": 554,
      "ratio": 0.9756778620908927,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1217.85,
      "baseline_run_cnt_delta": 20,
      "baseline_run_time_ns_delta": 24357,
      "post_rejit_avg_ns_per_run": 1375.3,
      "post_rejit_run_cnt_delta": 20,
      "post_rejit_run_time_ns_delta": 27506,
      "program": "trace_security_socket_listen",
      "program_id": 559,
      "ratio": 1.129285215749066,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 386.1986335050079,
      "baseline_run_cnt_delta": 154556,
      "baseline_run_time_ns_delta": 59689316,
      "post_rejit_avg_ns_per_run": 448.5697340743678,
      "post_rejit_run_cnt_delta": 148801,
      "post_rejit_run_time_ns_delta": 66747625,
      "program": "trace_security_socket_connect",
      "program_id": 560,
      "ratio": 1.1615000550449932,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 512.9116447204406,
      "baseline_run_cnt_delta": 176492,
      "baseline_run_time_ns_delta": 90524802,
      "post_rejit_avg_ns_per_run": 531.7254082004476,
      "post_rejit_run_cnt_delta": 172893,
      "post_rejit_run_time_ns_delta": 91931601,
      "program": "trace_security_socket_accept",
      "program_id": 561,
      "ratio": 1.036680320428797,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1159.15,
      "baseline_run_cnt_delta": 20,
      "baseline_run_time_ns_delta": 23183,
      "post_rejit_avg_ns_per_run": 1058.1,
      "post_rejit_run_cnt_delta": 20,
      "post_rejit_run_time_ns_delta": 21162,
      "program": "trace_security_socket_bind",
      "program_id": 562,
      "ratio": 0.9128240521071473,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 357.0358695596773,
      "baseline_run_cnt_delta": 392394,
      "baseline_run_time_ns_delta": 140098733,
      "post_rejit_avg_ns_per_run": 353.95609985029273,
      "post_rejit_run_cnt_delta": 381411,
      "post_rejit_run_time_ns_delta": 135002750,
      "program": "trace_security_socket_setsockopt",
      "program_id": 563,
      "ratio": 0.9913740607822324,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 58.560397473003285,
      "baseline_run_cnt_delta": 826119,
      "baseline_run_time_ns_delta": 48377857,
      "post_rejit_avg_ns_per_run": 70.69864348318758,
      "post_rejit_run_cnt_delta": 522441,
      "post_rejit_run_time_ns_delta": 36935870,
      "program": "trace_vfs_write",
      "program_id": 566,
      "ratio": 1.2072773842728801,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 53.26108829357514,
      "baseline_run_cnt_delta": 826119,
      "baseline_run_time_ns_delta": 43999997,
      "post_rejit_avg_ns_per_run": 76.35999088892335,
      "post_rejit_run_cnt_delta": 522441,
      "post_rejit_run_time_ns_delta": 39893590,
      "program": "vfs_write_magic_enter",
      "program_id": 567,
      "ratio": 1.4336919003236857,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 560.8627461661092,
      "baseline_run_cnt_delta": 826119,
      "baseline_run_time_ns_delta": 463339371,
      "post_rejit_avg_ns_per_run": 627.0019849131289,
      "post_rejit_run_cnt_delta": 522441,
      "post_rejit_run_time_ns_delta": 327571544,
      "program": "trace_ret_vfs_write",
      "program_id": 568,
      "ratio": 1.1179241074561073,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 42.660665109990205,
      "baseline_run_cnt_delta": 826119,
      "baseline_run_time_ns_delta": 35242786,
      "post_rejit_avg_ns_per_run": 50.248910403279986,
      "post_rejit_run_cnt_delta": 522441,
      "post_rejit_run_time_ns_delta": 26252091,
      "program": "vfs_write_magic_return",
      "program_id": 569,
      "ratio": 1.177874519155417,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 527.4213483146067,
      "baseline_run_cnt_delta": 178,
      "baseline_run_time_ns_delta": 93881,
      "post_rejit_avg_ns_per_run": 408.85276073619633,
      "post_rejit_run_cnt_delta": 163,
      "post_rejit_run_time_ns_delta": 66643,
      "program": "trace_vfs_writev",
      "program_id": 571,
      "ratio": 0.775191906893226,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 326.10674157303373,
      "baseline_run_cnt_delta": 178,
      "baseline_run_time_ns_delta": 58047,
      "post_rejit_avg_ns_per_run": 463.8834355828221,
      "post_rejit_run_cnt_delta": 163,
      "post_rejit_run_time_ns_delta": 75613,
      "program": "vfs_writev_magic_enter",
      "program_id": 572,
      "ratio": 1.4224895607652819,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2297.376404494382,
      "baseline_run_cnt_delta": 178,
      "baseline_run_time_ns_delta": 408933,
      "post_rejit_avg_ns_per_run": 2302.564417177914,
      "post_rejit_run_cnt_delta": 163,
      "post_rejit_run_time_ns_delta": 375318,
      "program": "trace_ret_vfs_writev",
      "program_id": 573,
      "ratio": 1.002258233641376,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4904.224719101124,
      "baseline_run_cnt_delta": 178,
      "baseline_run_time_ns_delta": 872952,
      "post_rejit_avg_ns_per_run": 5304.60736196319,
      "post_rejit_run_cnt_delta": 163,
      "post_rejit_run_time_ns_delta": 864651,
      "program": "vfs_writev_magic_return",
      "program_id": 574,
      "ratio": 1.0816403541425506,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 51.36088454468403,
      "baseline_run_cnt_delta": 1271886,
      "baseline_run_time_ns_delta": 65325190,
      "post_rejit_avg_ns_per_run": 71.9985237009714,
      "post_rejit_run_cnt_delta": 698368,
      "post_rejit_run_time_ns_delta": 50281465,
      "program": "trace_vfs_read",
      "program_id": 581,
      "ratio": 1.4018162720373828,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 534.5490672906219,
      "baseline_run_cnt_delta": 1271886,
      "baseline_run_time_ns_delta": 679885475,
      "post_rejit_avg_ns_per_run": 674.0630741958395,
      "post_rejit_run_cnt_delta": 698368,
      "post_rejit_run_time_ns_delta": 470744081,
      "program": "trace_ret_vfs_read",
      "program_id": 582,
      "ratio": 1.2609938272128105,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 399.9269662921348,
      "baseline_run_cnt_delta": 178,
      "baseline_run_time_ns_delta": 71187,
      "post_rejit_avg_ns_per_run": 386.70552147239266,
      "post_rejit_run_cnt_delta": 163,
      "post_rejit_run_time_ns_delta": 63033,
      "program": "trace_vfs_readv",
      "program_id": 584,
      "ratio": 0.9669403517789189,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2052.775280898876,
      "baseline_run_cnt_delta": 178,
      "baseline_run_time_ns_delta": 365394,
      "post_rejit_avg_ns_per_run": 2612.711656441718,
      "post_rejit_run_cnt_delta": 163,
      "post_rejit_run_time_ns_delta": 425872,
      "program": "trace_ret_vfs_readv",
      "program_id": 585,
      "ratio": 1.2727704200031358,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 137.34856822403702,
      "baseline_run_cnt_delta": 28531,
      "baseline_run_time_ns_delta": 3918692,
      "post_rejit_avg_ns_per_run": 135.2674552496598,
      "post_rejit_run_cnt_delta": 28659,
      "post_rejit_run_time_ns_delta": 3876630,
      "program": "trace_mmap_alert",
      "program_id": 587,
      "ratio": 0.9848479456226832,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 69.6737034049865,
      "baseline_run_cnt_delta": 28517,
      "baseline_run_time_ns_delta": 1986885,
      "post_rejit_avg_ns_per_run": 66.8346657357305,
      "post_rejit_run_cnt_delta": 28645,
      "post_rejit_run_time_ns_delta": 1914479,
      "program": "trace_do_mmap",
      "program_id": 588,
      "ratio": 0.9592523788673358,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 377.0950661009223,
      "baseline_run_cnt_delta": 28517,
      "baseline_run_time_ns_delta": 10753620,
      "post_rejit_avg_ns_per_run": 378.00977482981324,
      "post_rejit_run_cnt_delta": 28645,
      "post_rejit_run_time_ns_delta": 10828090,
      "program": "trace_ret_do_mmap",
      "program_id": 589,
      "ratio": 1.0024256714317397,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 122.6734822712447,
      "baseline_run_cnt_delta": 28513,
      "baseline_run_time_ns_delta": 3497789,
      "post_rejit_avg_ns_per_run": 123.78942774344472,
      "post_rejit_run_cnt_delta": 28641,
      "post_rejit_run_time_ns_delta": 3545453,
      "program": "trace_security_mmap_file",
      "program_id": 590,
      "ratio": 1.0090968761262726,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1085.547619047619,
      "baseline_run_cnt_delta": 42,
      "baseline_run_time_ns_delta": 45593,
      "post_rejit_avg_ns_per_run": 1305.404761904762,
      "post_rejit_run_cnt_delta": 42,
      "post_rejit_run_time_ns_delta": 54827,
      "program": "trace_security_file_mprotect",
      "program_id": 591,
      "ratio": 1.2025310902989494,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 304.24902391410444,
      "baseline_run_cnt_delta": 8196,
      "baseline_run_time_ns_delta": 2493625,
      "post_rejit_avg_ns_per_run": 281.2938018545632,
      "post_rejit_run_cnt_delta": 8196,
      "post_rejit_run_time_ns_delta": 2305484,
      "program": "trace_security_bpf",
      "program_id": 593,
      "ratio": 0.9245512055742142,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 311.6019938650307,
      "baseline_run_cnt_delta": 2608,
      "baseline_run_time_ns_delta": 812658,
      "post_rejit_avg_ns_per_run": 280.0621165644172,
      "post_rejit_run_cnt_delta": 2608,
      "post_rejit_run_time_ns_delta": 730402,
      "program": "trace_security_bpf_map",
      "program_id": 596,
      "ratio": 0.8987815292533883,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 895.8571428571429,
      "baseline_run_cnt_delta": 161,
      "baseline_run_time_ns_delta": 144233,
      "post_rejit_avg_ns_per_run": 929.7888198757764,
      "post_rejit_run_cnt_delta": 161,
      "post_rejit_run_time_ns_delta": 149696,
      "program": "trace_security_bpf_prog",
      "program_id": 597,
      "ratio": 1.0378762141812206,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1166.875,
      "baseline_run_cnt_delta": 16,
      "baseline_run_time_ns_delta": 18670,
      "post_rejit_avg_ns_per_run": 1740.9375,
      "post_rejit_run_cnt_delta": 16,
      "post_rejit_run_time_ns_delta": 27855,
      "program": "trace_security_inode_mknod",
      "program_id": 603,
      "ratio": 1.4919657204070702,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3756.25,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 15025,
      "post_rejit_avg_ns_per_run": 2069.25,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 8277,
      "program": "trace_load_elf_phdrs",
      "program_id": 611,
      "ratio": 0.5508818635607321,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 45.849202417206904,
      "baseline_run_cnt_delta": 2555346,
      "baseline_run_time_ns_delta": 117160576,
      "post_rejit_avg_ns_per_run": 54.85318614529561,
      "post_rejit_run_cnt_delta": 1657834,
      "post_rejit_run_time_ns_delta": 90937477,
      "program": "trace_security_file_permission",
      "program_id": 612,
      "ratio": 1.1963825596388034,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1000.7777603019817,
      "baseline_run_cnt_delta": 6358,
      "baseline_run_time_ns_delta": 6362945,
      "post_rejit_avg_ns_per_run": 974.3694291674568,
      "post_rejit_run_cnt_delta": 5273,
      "post_rejit_run_time_ns_delta": 5137850,
      "program": "tracepoint__task__task_rename",
      "program_id": 613,
      "ratio": 0.9736121922547957,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 970.8146011038635,
      "baseline_run_cnt_delta": 11958,
      "baseline_run_time_ns_delta": 11609001,
      "post_rejit_avg_ns_per_run": 892.3730385164051,
      "post_rejit_run_cnt_delta": 9814,
      "post_rejit_run_time_ns_delta": 8757749,
      "program": "trace_do_sigaction",
      "program_id": 617,
      "ratio": 0.9192002649133352,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1931.9983079526228,
      "baseline_run_cnt_delta": 591,
      "baseline_run_time_ns_delta": 1141811,
      "post_rejit_avg_ns_per_run": 2181.6666666666665,
      "post_rejit_run_cnt_delta": 501,
      "post_rejit_run_time_ns_delta": 1093015,
      "program": "trace_do_truncate",
      "program_id": 620,
      "ratio": 1.1292280421190546,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 173.81351467321343,
      "baseline_run_cnt_delta": 1841110,
      "baseline_run_time_ns_delta": 320009800,
      "post_rejit_avg_ns_per_run": 163.18652641441943,
      "post_rejit_run_cnt_delta": 1579535,
      "post_rejit_run_time_ns_delta": 257758830,
      "program": "trace_fd_install",
      "program_id": 621,
      "ratio": 0.9388598275641926,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 322.0476360194918,
      "baseline_run_cnt_delta": 496620,
      "baseline_run_time_ns_delta": 159935297,
      "post_rejit_avg_ns_per_run": 312.9415874839682,
      "post_rejit_run_cnt_delta": 396867,
      "post_rejit_run_time_ns_delta": 124196189,
      "program": "trace_filp_close",
      "program_id": 622,
      "ratio": 0.971724529178123,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 193.97326565143825,
      "baseline_run_cnt_delta": 14775,
      "baseline_run_time_ns_delta": 2865955,
      "post_rejit_avg_ns_per_run": 190.8776443682104,
      "post_rejit_run_cnt_delta": 13992,
      "post_rejit_run_time_ns_delta": 2670760,
      "program": "trace_file_update_time",
      "program_id": 623,
      "ratio": 0.9840409900156523,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 693.951269035533,
      "baseline_run_cnt_delta": 14775,
      "baseline_run_time_ns_delta": 10253130,
      "post_rejit_avg_ns_per_run": 824.6516580903374,
      "post_rejit_run_cnt_delta": 13992,
      "post_rejit_run_time_ns_delta": 11538526,
      "program": "trace_ret_file_update_time",
      "program_id": 624,
      "ratio": 1.1883423157889088,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 109.3367885986746,
      "baseline_run_cnt_delta": 190434,
      "baseline_run_time_ns_delta": 20821442,
      "post_rejit_avg_ns_per_run": 104.0250650271932,
      "post_rejit_run_cnt_delta": 177618,
      "post_rejit_run_time_ns_delta": 18476724,
      "program": "trace_file_modified",
      "program_id": 625,
      "ratio": 0.9514186977726379,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 470.41178045937176,
      "baseline_run_cnt_delta": 190434,
      "baseline_run_time_ns_delta": 89582397,
      "post_rejit_avg_ns_per_run": 489.10771993829457,
      "post_rejit_run_cnt_delta": 177618,
      "post_rejit_run_time_ns_delta": 86874335,
      "program": "trace_ret_file_modified",
      "program_id": 626,
      "ratio": 1.0397437739774833,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 219.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 439,
      "post_rejit_avg_ns_per_run": 229.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 459,
      "program": "trace_exec_binprm",
      "program_id": 630,
      "ratio": 1.0455580865603644,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 8122.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 16244,
      "post_rejit_avg_ns_per_run": 3954.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 7908,
      "program": "trace_security_bprm_creds_for_exec",
      "program_id": 631,
      "ratio": 0.4868259049495198,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4052.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 8104,
      "post_rejit_avg_ns_per_run": 7279.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 14558,
      "program": "trace_execute_finished",
      "program_id": 632,
      "ratio": 1.7963968410661402,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 7990.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 15981,
      "post_rejit_avg_ns_per_run": 4993.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 9987,
      "program": "trace_set_fs_pwd",
      "program_id": 634,
      "ratio": 0.6249296039046368,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 286.69381285169453,
      "baseline_run_cnt_delta": 672814,
      "baseline_run_time_ns_delta": 192891611,
      "post_rejit_avg_ns_per_run": 281.6192294381499,
      "post_rejit_run_cnt_delta": 884186,
      "post_rejit_run_time_ns_delta": 249003780,
      "program": "trace_security_task_setrlimit",
      "program_id": 635,
      "ratio": 0.9822996409895678,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 356.30003252856653,
      "baseline_run_cnt_delta": 528766,
      "baseline_run_time_ns_delta": 188399343,
      "post_rejit_avg_ns_per_run": 328.5365057606319,
      "post_rejit_run_cnt_delta": 428946,
      "post_rejit_run_time_ns_delta": 140924420,
      "program": "trace_security_task_prctl",
      "program_id": 638,
      "ratio": 0.9220782367857104,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 55.52940044411547,
      "baseline_run_cnt_delta": 540400,
      "baseline_run_time_ns_delta": 30008088,
      "post_rejit_avg_ns_per_run": 50.99164137680596,
      "post_rejit_run_cnt_delta": 616848,
      "post_rejit_run_time_ns_delta": 31454092,
      "program": "trace_sock_alloc_file",
      "program_id": 641,
      "ratio": 0.9182818645435171,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 318.52416358253146,
      "baseline_run_cnt_delta": 540400,
      "baseline_run_time_ns_delta": 172130458,
      "post_rejit_avg_ns_per_run": 290.15168080305034,
      "post_rejit_run_cnt_delta": 616848,
      "post_rejit_run_time_ns_delta": 178979484,
      "program": "trace_ret_sock_alloc_file",
      "program_id": 642,
      "ratio": 0.9109251792379963,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 992.7848594075344,
      "baseline_run_cnt_delta": 114302,
      "baseline_run_time_ns_delta": 113477295,
      "post_rejit_avg_ns_per_run": 767.8977431906615,
      "post_rejit_run_cnt_delta": 115650,
      "post_rejit_run_time_ns_delta": 88807374,
      "program": "trace_security_sk_clone",
      "program_id": 643,
      "ratio": 0.7734784993084209,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 227.04661281919246,
      "baseline_run_cnt_delta": 1648731,
      "baseline_run_time_ns_delta": 374338789,
      "post_rejit_avg_ns_per_run": 203.46361885294235,
      "post_rejit_run_cnt_delta": 1526340,
      "post_rejit_run_time_ns_delta": 310554660,
      "program": "trace_security_socket_recvmsg",
      "program_id": 644,
      "ratio": 0.8961314873918409,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 241.1360789488755,
      "baseline_run_cnt_delta": 3265303,
      "baseline_run_time_ns_delta": 787382362,
      "post_rejit_avg_ns_per_run": 235.47762068617436,
      "post_rejit_run_cnt_delta": 3605964,
      "post_rejit_run_time_ns_delta": 849123823,
      "program": "trace_security_socket_sendmsg",
      "program_id": 645,
      "ratio": 0.9765341698871166,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 261.55131878727116,
      "baseline_run_cnt_delta": 3542952,
      "baseline_run_time_ns_delta": 926663768,
      "post_rejit_avg_ns_per_run": 232.17478525340164,
      "post_rejit_run_cnt_delta": 4659678,
      "post_rejit_run_time_ns_delta": 1081859739,
      "program": "cgroup_bpf_run_filter_skb",
      "program_id": 646,
      "ratio": 0.8876834815053543,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 281.8141550602362,
      "baseline_run_cnt_delta": 1114612,
      "baseline_run_time_ns_delta": 314113439,
      "post_rejit_avg_ns_per_run": 258.3194562273025,
      "post_rejit_run_cnt_delta": 1075008,
      "post_rejit_run_time_ns_delta": 277695482,
      "program": "cgroup_skb_ingress",
      "program_id": 648,
      "ratio": 0.9166305225941833,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 255.21425979890324,
      "baseline_run_cnt_delta": 2163635,
      "baseline_run_time_ns_delta": 552190505,
      "post_rejit_avg_ns_per_run": 246.8842282021183,
      "post_rejit_run_cnt_delta": 3308716,
      "post_rejit_run_time_ns_delta": 816869796,
      "program": "cgroup_skb_egress",
      "program_id": 649,
      "ratio": 0.9673606341458012,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 106.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 212,
      "post_rejit_avg_ns_per_run": 121.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 243,
      "program": "empty_kprobe",
      "program_id": 652,
      "ratio": 1.1462264150943395,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 720.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1440,
      "post_rejit_avg_ns_per_run": 1072.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 2144,
      "program": "tracepoint__exec_test",
      "program_id": 653,
      "ratio": 1.488888888888889,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 262.6831242453274,
      "baseline_run_cnt_delta": 882005,
      "baseline_run_time_ns_delta": 231687829,
      "post_rejit_avg_ns_per_run": 262.34329434297615,
      "post_rejit_run_cnt_delta": 638021,
      "post_rejit_run_time_ns_delta": 167380531,
      "program": "lsm_file_open_test",
      "program_id": 654,
      "ratio": 0.9987063123932016,
      "runner": "tracee",
      "type": "lsm",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 331.67867981673163,
      "baseline_run_cnt_delta": 2261383,
      "baseline_run_time_ns_delta": 750052528,
      "post_rejit_avg_ns_per_run": 321.59251140268464,
      "post_rejit_run_cnt_delta": 2347035,
      "post_rejit_run_time_ns_delta": 754788880,
      "program": "cap_capable",
      "program_id": 661,
      "ratio": 0.9695905434150303,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 387.69849119730316,
      "baseline_run_cnt_delta": 1422121,
      "baseline_run_time_ns_delta": 551354166,
      "post_rejit_avg_ns_per_run": 396.39755719637725,
      "post_rejit_run_cnt_delta": 1374650,
      "post_rejit_run_time_ns_delta": 544907902,
      "program": "block_io_start",
      "program_id": 668,
      "ratio": 1.0224377091904828,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 776.5563497443283,
      "baseline_run_cnt_delta": 1422136,
      "baseline_run_time_ns_delta": 1104368741,
      "post_rejit_avg_ns_per_run": 791.1940523691227,
      "post_rejit_run_cnt_delta": 1374665,
      "post_rejit_run_time_ns_delta": 1087626772,
      "program": "block_io_done",
      "program_id": 669,
      "ratio": 1.0188495047778745,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1827.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1827,
      "post_rejit_avg_ns_per_run": 1796.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1796,
      "program": "1",
      "program_id": 676,
      "ratio": 0.983032293377121,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 34.06883758890778,
      "baseline_run_cnt_delta": 1933464,
      "baseline_run_time_ns_delta": 65870871,
      "post_rejit_avg_ns_per_run": 33.294011769227964,
      "post_rejit_run_cnt_delta": 2000641,
      "post_rejit_run_time_ns_delta": 66609365,
      "program": "vfs_create",
      "program_id": 677,
      "ratio": 0.9772570514723963,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 74.04267460031846,
      "baseline_run_cnt_delta": 2028490,
      "baseline_run_time_ns_delta": 150194825,
      "post_rejit_avg_ns_per_run": 69.18058619464318,
      "post_rejit_run_cnt_delta": 3638689,
      "post_rejit_run_time_ns_delta": 251726638,
      "program": "sched_wakeup",
      "program_id": 684,
      "ratio": 0.9343339711602697,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 316.4871794871795,
      "baseline_run_cnt_delta": 78,
      "baseline_run_time_ns_delta": 24686,
      "post_rejit_avg_ns_per_run": 267.64102564102564,
      "post_rejit_run_cnt_delta": 78,
      "post_rejit_run_time_ns_delta": 20876,
      "program": "tracepoint_sched_sched_wakeup_new",
      "program_id": 685,
      "ratio": 0.8456615085473547,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 141.43596811090694,
      "baseline_run_cnt_delta": 12918649,
      "baseline_run_time_ns_delta": 1827161628,
      "post_rejit_avg_ns_per_run": 118.34100255966224,
      "post_rejit_run_cnt_delta": 10416218,
      "post_rejit_run_time_ns_delta": 1232665681,
      "program": "sched_switch",
      "program_id": 686,
      "ratio": 0.8367108037671521,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 439.60515954533,
      "baseline_run_cnt_delta": 58416,
      "baseline_run_time_ns_delta": 25679975,
      "post_rejit_avg_ns_per_run": 442.2191174505612,
      "post_rejit_run_cnt_delta": 59872,
      "post_rejit_run_time_ns_delta": 26476543,
      "program": "tcp_set_state",
      "program_id": 694,
      "ratio": 1.0059461492852693,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline_avg_ns_per_run": 3434.0862068965516,
      "baseline_run_cnt_delta": 116,
      "baseline_run_time_ns_delta": 398354,
      "post_rejit_avg_ns_per_run": 4293.089430894309,
      "post_rejit_run_cnt_delta": 123,
      "post_rejit_run_time_ns_delta": 528050,
      "program": "kprobe_tcp_retransmit_skb",
      "program_id": 701,
      "ratio": 1.2501402621380477,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "network_lossy_multi"
    }
  ],
  "results": [
    {
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 136.48709900831798,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 2695723,
            "run_time_ns_delta": 367931412,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.019226059999994,
            "ops_per_sec": 5638244.767799632,
            "ops_total": 5746646.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [11630] setting to a 1 secs run per stressor\nstress-ng: info:  [11630] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set\nstress-ng: info:  [11630] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11630] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11630]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11630] cap             4300021      1.00      0.80      3.09   4300013.05     1104865.91\nstress-ng: metrc: [11630] eventfd         1257316      1.00      0.68      3.14   1257132.94      329545.43\nstress-ng: metrc: [11630] get                4388      1.00      0.06      0.41      4384.17        9312.43\nstress-ng: metrc: [11630] prctl              9070      1.00      1.52      1.15      9056.87        3396.68\nstress-ng: metrc: [11630] set              175851      1.00      0.71      2.81    175850.53       49978.85\nstress-ng: info:  [11630] skipped: 0\nstress-ng: info:  [11630] passed: 20: cap (4) eventfd (4) get (4) prctl (4) set (4)\nstress-ng: info:  [11630] failed: 0\nstress-ng: info:  [11630] metrics untrustworthy: 0\nstress-ng: info:  [11630] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 141.84826661109588,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 2548101,
            "run_time_ns_delta": 361443710,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.01250134,
            "ops_per_sec": 5815132.057010413,
            "ops_total": 5887829.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [29926] setting to a 1 secs run per stressor\nstress-ng: info:  [29926] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set\nstress-ng: info:  [29926] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29926] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29926]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29926] cap             4426532      1.00      0.82      3.06   4426496.38     1140243.97\nstress-ng: metrc: [29926] eventfd         1284354      1.00      0.51      3.21   1284196.70      345738.81\nstress-ng: metrc: [29926] get                4074      1.00      0.05      0.45      4072.31        8223.39\nstress-ng: metrc: [29926] prctl              8864      1.00      1.55      1.03      8862.36        3444.89\nstress-ng: metrc: [29926] set              164005      1.00      0.66      2.79    164002.44       47513.69\nstress-ng: info:  [29926] skipped: 0\nstress-ng: info:  [29926] passed: 20: cap (4) eventfd (4) get (4) prctl (4) set (4)\nstress-ng: info:  [29926] failed: 0\nstress-ng: info:  [29926] metrics untrustworthy: 0\nstress-ng: info:  [29926] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
            "avg_ns_per_run": 890.5,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1781,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 161.5,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 323,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.033858594999998,
            "ops_per_sec": 104181.90938476296,
            "ops_total": 524437.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [14110] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [14110] setting to a 5 secs run per stressor\nstress-ng: info:  [14110] dispatching hogs: 4 clone, 4 fork, 4 vfork\nstress-ng: info:  [14110] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [14110] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [14110]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [14110] clone             12745      5.02      4.45     19.73      2539.56         527.05\nstress-ng: metrc: [14110] fork              73193      5.00      7.47      9.72     14638.34        4259.18\nstress-ng: metrc: [14110] vfork            438499      5.00      4.51      5.58     87694.28       43471.30\nstress-ng: info:  [14110] skipped: 4: exec (4)\nstress-ng: info:  [14110] passed: 12: clone (4) fork (4) vfork (4)\nstress-ng: info:  [14110] failed: 0\nstress-ng: info:  [14110] metrics untrustworthy: 0\nstress-ng: info:  [14110] successful run completed in 5.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1199.5,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2399,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 151.0,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 302,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.054136774,
            "ops_per_sec": 105081.24804459438,
            "ops_total": 531095.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [28590] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [28590] setting to a 5 secs run per stressor\nstress-ng: info:  [28590] dispatching hogs: 4 clone, 4 fork, 4 vfork\nstress-ng: info:  [28590] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [28590] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [28590]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [28590] clone             11522      5.02      4.46     19.60      2293.76         478.81\nstress-ng: metrc: [28590] fork              72646      5.00      7.50      9.82     14528.97        4192.53\nstress-ng: metrc: [28590] vfork            446927      5.00      4.60      5.65     89382.88       43621.09\nstress-ng: info:  [28590] skipped: 4: exec (4)\nstress-ng: info:  [28590] passed: 12: clone (4) fork (4) vfork (4)\nstress-ng: info:  [28590] failed: 0\nstress-ng: info:  [28590] metrics untrustworthy: 0\nstress-ng: info:  [28590] successful run completed in 5.04 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
      "app": "bcc/biosnoop",
      "baseline": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 201.86341348788986,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 13,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1817156,
            "run_time_ns_delta": 366817313,
            "type": "tracepoint"
          },
          "14": {
            "avg_ns_per_run": 206.42821734503067,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 14,
            "name": "trace_req_start",
            "run_cnt_delta": 1817166,
            "run_time_ns_delta": 375114338,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 93.43262411737805,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 15,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1817171,
            "run_time_ns_delta": 169783055,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.350119345999985,
            "ops_per_sec": 453950.43417411024,
            "ops_total": 2428689.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.156213,\n        \"1000\" : 18.230189\n      },\n      \"latency_us\" : {\n        \"2\" : 29.569144,\n        \"4\" : 1.458533,\n        \"10\" : 22.682009,\n        \"20\" : 24.829649,\n        \"50\" : 2.701679,\n        \"100\" : 0.287838,\n        \"250\" : 0.078680,\n        \"500\" : 0.010000,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 202.6130059010164,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 13,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1774779,
            "run_time_ns_delta": 359593308,
            "type": "tracepoint"
          },
          "14": {
            "avg_ns_per_run": 206.72562541237298,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 14,
            "name": "trace_req_start",
            "run_cnt_delta": 1774789,
            "run_time_ns_delta": 366894366,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 93.60065449849391,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 15,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1774794,
            "run_time_ns_delta": 166121880,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.341159853000022,
            "ops_per_sec": 443498.8027309263,
            "ops_total": 2368798.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.179457,\n        \"1000\" : 17.238122\n      },\n      \"latency_us\" : {\n        \"2\" : 30.352959,\n        \"4\" : 1.567547,\n        \"10\" : 20.641220,\n        \"20\" : 26.727734,\n        \"50\" : 2.737894,\n        \"100\" : 0.441726,\n        \"250\" : 0.105751,\n        \"500\" : 0.010000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
          "18": {
            "avg_ns_per_run": 66.5360681825639,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 18,
            "name": "vfs_create",
            "run_cnt_delta": 121908,
            "run_time_ns_delta": 8111279,
            "type": "tracing"
          },
          "19": {
            "avg_ns_per_run": 75.3963963963964,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 19,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 555,
            "run_time_ns_delta": 41845,
            "type": "tracing"
          },
          "20": {
            "avg_ns_per_run": 47.710287158451195,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 20,
            "name": "vfs_open",
            "run_cnt_delta": 1734269,
            "run_time_ns_delta": 82742472,
            "type": "tracing"
          },
          "21": {
            "avg_ns_per_run": 45.62309034963022,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 21,
            "name": "vfs_read",
            "run_cnt_delta": 55573,
            "run_time_ns_delta": 2535412,
            "type": "tracing"
          },
          "22": {
            "avg_ns_per_run": 57.396173703149096,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 22,
            "name": "vfs_write",
            "run_cnt_delta": 44743,
            "run_time_ns_delta": 2568077,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.186187698999987,
            "ops_per_sec": 1415071.1573008972,
            "ops_total": 1678540.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [9613] setting to a 1 secs run per stressor\nstress-ng: info:  [9613] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime\nstress-ng: info:  [9613] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [9686] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [9630] dentry: 149908 dentries allocated\nstress-ng: metrc: [9613] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9613]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9613] access            17072      1.03      0.21      1.67     16655.44        9051.57\nstress-ng: metrc: [9613] chdir                30      1.13      0.08      1.36        26.56          20.88\nstress-ng: metrc: [9613] chmod               145      1.03      0.01      0.06       140.71        2060.07\nstress-ng: metrc: [9613] chown               176      1.02      0.00      0.01       171.90       15913.20\nstress-ng: metrc: [9613] dentry             8192      1.13      0.01      0.16      7230.88       48364.91\nstress-ng: metrc: [9613] dir               11700      1.11      0.06      1.19     10520.61        9330.81\nstress-ng: metrc: [9613] dirmany           12866      1.02      0.01      0.28     12665.84       42910.70\nstress-ng: metrc: [9613] fallocate             0      1.03      0.01      0.00         0.00           0.00\nstress-ng: metrc: [9613] file-ioctl        79256      1.01      0.14      0.87     78857.38       79227.95\nstress-ng: metrc: [9613] filename           4830      1.02      0.12      0.91      4750.71        4658.61\nstress-ng: metrc: [9613] flock           1023673      1.02      0.17      0.27   1002141.42     2337708.04\nstress-ng: metrc: [9613] fpunch              112      1.05      0.00      0.31       107.09         362.17\nstress-ng: metrc: [9613] fstat              3775      1.00      0.26      0.88      3771.59        3308.22\nstress-ng: metrc: [9613] getdent          325245      1.00      0.09      2.23    325234.53      140035.48\nstress-ng: metrc: [9613] hdd               24383      1.02      0.39      0.28     23869.33       36099.70\nstress-ng: metrc: [9613] inotify               4      1.08      0.01      0.00         3.70         563.54\nstress-ng: metrc: [9613] open               5120      1.11      0.04      0.05      4632.23       54312.08\nstress-ng: metrc: [9613] rename            44948      1.02      0.01      0.27     44101.45      156067.82\nstress-ng: metrc: [9613] touch             48098      1.09      0.04      1.33     43974.08       35123.90\nstress-ng: metrc: [9613] utime             68915      1.01      0.05      1.26     67951.34       52676.76\nstress-ng: info:  [9613] skipped: 0\nstress-ng: info:  [9613] passed: 80: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4)\nstress-ng: info:  [9613] failed: 0\nstress-ng: info:  [9613] metrics untrustworthy: 0\nstress-ng: info:  [9613] successful run completed in 1.17 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 214.70323691077675,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 18,
            "name": "vfs_create",
            "run_cnt_delta": 90055,
            "run_time_ns_delta": 19335100,
            "type": "tracing"
          },
          "19": {
            "avg_ns_per_run": 74.68161434977578,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 19,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 446,
            "run_time_ns_delta": 33308,
            "type": "tracing"
          },
          "20": {
            "avg_ns_per_run": 49.65112853960221,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 20,
            "name": "vfs_open",
            "run_cnt_delta": 1983980,
            "run_time_ns_delta": 98506846,
            "type": "tracing"
          },
          "21": {
            "avg_ns_per_run": 44.397566661809705,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 21,
            "name": "vfs_read",
            "run_cnt_delta": 41178,
            "run_time_ns_delta": 1828203,
            "type": "tracing"
          },
          "22": {
            "avg_ns_per_run": 58.656090444930705,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 22,
            "name": "vfs_write",
            "run_cnt_delta": 43872,
            "run_time_ns_delta": 2573360,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2066467880000005,
            "ops_per_sec": 1719080.5301343903,
            "ops_total": 2074323.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5780] setting to a 1 secs run per stressor\nstress-ng: info:  [5780] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime\nstress-ng: info:  [5780] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [5853] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [5799] dentry: 149621 dentries allocated\nstress-ng: metrc: [5780] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5780]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5780] access            17713      1.02      0.21      1.78     17399.45        8894.10\nstress-ng: metrc: [5780] chdir                 5      1.12      0.03      0.91         4.45           5.33\nstress-ng: metrc: [5780] chmod               121      1.02      0.02      0.01       118.57        3898.82\nstress-ng: metrc: [5780] chown               130      1.01      0.01      0.01       128.35        9235.58\nstress-ng: metrc: [5780] dentry            10240      1.12      0.02      0.26      9131.25       36556.68\nstress-ng: metrc: [5780] dir               11784      1.11      0.07      1.28     10581.27        8705.12\nstress-ng: metrc: [5780] dirmany           11194      1.02      0.05      0.21     11024.67       43693.62\nstress-ng: metrc: [5780] fallocate             0      1.02      0.01      0.00         0.00           0.00\nstress-ng: metrc: [5780] file-ioctl        85470      1.01      0.13      0.85     84581.75       87674.40\nstress-ng: metrc: [5780] filename           3470      1.01      0.05      0.70      3432.40        4660.91\nstress-ng: metrc: [5780] flock           1363838      1.02      0.23      0.40   1343629.20     2179682.12\nstress-ng: metrc: [5780] fpunch              202      1.02      0.02      0.44       197.11         438.21\nstress-ng: metrc: [5780] fstat              5824      1.00      0.36      1.48      5802.99        3179.61\nstress-ng: metrc: [5780] getdent          443021      1.00      0.22      2.42    442622.26      167992.79\nstress-ng: metrc: [5780] hdd               20480      1.02      0.28      0.25     20174.51       38310.52\nstress-ng: metrc: [5780] inotify               4      1.04      0.01      0.00         3.83         782.01\nstress-ng: metrc: [5780] open               4096      1.10      0.02      0.06      3740.47       54139.79\nstress-ng: metrc: [5780] rename            27161      1.02      0.02      0.19     26744.47      125205.71\nstress-ng: metrc: [5780] touch             30331      1.09      0.02      1.02     27731.67       29213.61\nstress-ng: metrc: [5780] utime             39239      1.00      0.05      0.66     39209.32       54991.32\nstress-ng: info:  [5780] skipped: 0\nstress-ng: info:  [5780] passed: 80: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4)\nstress-ng: info:  [5780] failed: 0\nstress-ng: info:  [5780] metrics untrustworthy: 0\nstress-ng: info:  [5780] successful run completed in 1.19 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
          "25": {
            "avg_ns_per_run": 324.30790720272074,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 25,
            "name": "__x64_sys_open",
            "run_cnt_delta": 8233,
            "run_time_ns_delta": 2670027,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 264.10241685065586,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 26,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 846970,
            "run_time_ns_delta": 223686824,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 346.93026315789473,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 27,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 1520,
            "run_time_ns_delta": 527334,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.191233202999996,
            "ops_per_sec": 2561689.006245749,
            "ops_total": 3051569.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8141] setting to a 1 secs run per stressor\nstress-ng: info:  [8141] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime\nstress-ng: info:  [8141] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [8218] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [8158] dentry: 206898 dentries allocated\nstress-ng: metrc: [8141] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8141]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8141] access            17306      1.02      0.30      1.31     16897.12       10797.77\nstress-ng: metrc: [8141] chdir                70      1.12      0.20      1.89        62.70          33.52\nstress-ng: metrc: [8141] chmod               109      1.02      0.02      0.01       106.66        4216.80\nstress-ng: metrc: [8141] chown                91      1.03      0.00      0.00        88.72       21833.01\nstress-ng: metrc: [8141] dentry            10240      1.04      0.02      0.37      9824.38       25929.83\nstress-ng: metrc: [8141] dir               15192      1.11      0.04      1.26     13682.84       11732.09\nstress-ng: metrc: [8141] dirmany            9759      1.02      0.00      0.23      9572.59       41746.16\nstress-ng: metrc: [8141] fallocate             0      1.02      0.01      0.00         0.00           0.00\nstress-ng: metrc: [8141] file-ioctl        60419      1.02      0.12      0.58     59322.99       86162.69\nstress-ng: metrc: [8141] filename           2799      1.02      0.02      0.57      2748.55        4778.67\nstress-ng: metrc: [8141] flock           2455154      1.02      0.40      0.49   2414095.76     2749957.72\nstress-ng: metrc: [8141] fpunch              309      1.03      0.00      0.84       300.83         369.65\nstress-ng: metrc: [8141] fstat              3771      1.00      0.17      0.67      3764.72        4475.81\nstress-ng: metrc: [8141] getdent          368690      1.00      0.20      2.59    368116.21      132233.64\nstress-ng: metrc: [8141] hdd               14368      1.02      0.21      0.19     14104.89       36454.98\nstress-ng: metrc: [8141] inotify               4      1.09      0.01      0.00         3.67         339.04\nstress-ng: metrc: [8141] open               9081      1.02      0.02      0.12      8887.06       66546.00\nstress-ng: metrc: [8141] rename             7904      1.02      0.00      0.05      7752.15      170095.55\nstress-ng: metrc: [8141] touch             31792      1.03      0.05      0.84     30749.27       35521.47\nstress-ng: metrc: [8141] utime             44511      1.01      0.03      0.72     43972.14       59725.79\nstress-ng: info:  [8141] skipped: 0\nstress-ng: info:  [8141] passed: 80: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4)\nstress-ng: info:  [8141] failed: 0\nstress-ng: info:  [8141] metrics untrustworthy: 0\nstress-ng: info:  [8141] successful run completed in 1.18 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "25": {
            "avg_ns_per_run": 191.8519313304721,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 25,
            "name": "__x64_sys_open",
            "run_cnt_delta": 4660,
            "run_time_ns_delta": 894030,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 254.04072891081523,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 26,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 853767,
            "run_time_ns_delta": 216891591,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 1381.7,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 27,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 760,
            "run_time_ns_delta": 1050092,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1977910700000223,
            "ops_per_sec": 1282401.4458548028,
            "ops_total": 1536049.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [10125] setting to a 1 secs run per stressor\nstress-ng: info:  [10125] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime\nstress-ng: info:  [10125] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [10199] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [10142] dentry: 273407 dentries allocated\nstress-ng: metrc: [10125] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10125]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10125] access            16309      1.03      0.24      1.53     15808.87        9205.19\nstress-ng: metrc: [10125] chdir                24      1.13      0.13      1.25        21.29          17.46\nstress-ng: metrc: [10125] chmod                92      1.02      0.01      0.01        90.17        4031.90\nstress-ng: metrc: [10125] chown                81      1.03      0.00      0.01        78.64        5066.30\nstress-ng: metrc: [10125] dentry            15197      1.05      0.06      0.40     14444.65       33140.70\nstress-ng: metrc: [10125] dir               16887      1.10      0.09      1.23     15344.92       12800.37\nstress-ng: metrc: [10125] dirmany            9654      1.03      0.00      0.21      9380.17       45441.49\nstress-ng: metrc: [10125] fallocate             0      1.03      0.01      0.00         0.00           0.00\nstress-ng: metrc: [10125] file-ioctl        84281      1.02      0.12      0.81     82941.45       91078.95\nstress-ng: metrc: [10125] filename           3174      1.03      0.03      0.61      3093.54        5010.13\nstress-ng: metrc: [10125] flock            886883      1.01      0.20      0.16    877159.91     2449560.57\nstress-ng: metrc: [10125] fpunch              197      1.03      0.02      0.87       190.42         222.38\nstress-ng: metrc: [10125] fstat              2857      1.00      0.20      0.82      2856.66        2809.95\nstress-ng: metrc: [10125] getdent          357575      1.00      0.15      2.42    357396.80      139064.60\nstress-ng: metrc: [10125] hdd               18427      1.02      0.22      0.31     18011.69       34402.35\nstress-ng: metrc: [10125] inotify               4      1.08      0.01      0.00         3.69         740.74\nstress-ng: metrc: [10125] open               5120      1.02      0.00      0.08      4996.48       64891.45\nstress-ng: metrc: [10125] rename            39062      1.02      0.03      0.24     38238.63      143283.69\nstress-ng: metrc: [10125] touch             47196      1.03      0.04      1.24     45795.11       36721.69\nstress-ng: metrc: [10125] utime             33029      1.01      0.03      0.59     32603.85       52602.33\nstress-ng: info:  [10125] skipped: 0\nstress-ng: info:  [10125] passed: 80: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4)\nstress-ng: info:  [10125] failed: 0\nstress-ng: info:  [10125] metrics untrustworthy: 0\nstress-ng: info:  [10125] successful run completed in 1.19 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
          "30": {
            "avg_ns_per_run": 84.47119641159033,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 30,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 28105821,
            "run_time_ns_delta": 2374132326,
            "type": "tracepoint"
          },
          "31": {
            "avg_ns_per_run": 99.1134834860745,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 31,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 28105825,
            "run_time_ns_delta": 2785666222,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0159777320000103,
            "ops_per_sec": 1926379.8195135838,
            "ops_total": 1957159.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [30236] setting to a 1 secs run per stressor\nstress-ng: info:  [30236] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set\nstress-ng: info:  [30236] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [30236] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [30236]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [30236] cap             1154387      1.00      0.31      3.47   1154377.50      304987.87\nstress-ng: metrc: [30236] eventfd          683330      1.00      0.40      3.32    683225.67      183401.66\nstress-ng: metrc: [30236] get                3740      1.00      0.05      0.61      3738.10        5712.25\nstress-ng: metrc: [30236] prctl              7106      1.00      2.04      0.89      7104.65        2433.10\nstress-ng: metrc: [30236] set              108596      1.00      0.31      3.56    108593.85       28126.15\nstress-ng: info:  [30236] skipped: 0\nstress-ng: info:  [30236] passed: 20: cap (4) eventfd (4) get (4) prctl (4) set (4)\nstress-ng: info:  [30236] failed: 0\nstress-ng: info:  [30236] metrics untrustworthy: 0\nstress-ng: info:  [30236] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 192.68868656606136,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 30,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 24144252,
            "run_time_ns_delta": 4652324206,
            "type": "tracepoint"
          },
          "31": {
            "avg_ns_per_run": 25.564187275018952,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 31,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 24144256,
            "run_time_ns_delta": 617228282,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0231552479999948,
            "ops_per_sec": 1750489.970609044,
            "ops_total": 1791023.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [12237] setting to a 1 secs run per stressor\nstress-ng: info:  [12237] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set\nstress-ng: info:  [12237] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12237] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12237]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12237] cap             1117362      1.00      0.21      3.79   1117357.07      279398.96\nstress-ng: metrc: [12237] eventfd          586471      1.00      0.26      3.36    586379.95      161862.17\nstress-ng: metrc: [12237] get                3400      1.00      0.06      0.67      3392.50        4635.99\nstress-ng: metrc: [12237] prctl              7357      1.00      2.18      0.87      7353.28        2412.90\nstress-ng: metrc: [12237] set               76433      1.00      0.31      3.44     76339.17       20396.39\nstress-ng: info:  [12237] skipped: 0\nstress-ng: info:  [12237] passed: 20: cap (4) eventfd (4) get (4) prctl (4) set (4)\nstress-ng: info:  [12237] failed: 0\nstress-ng: info:  [12237] metrics untrustworthy: 0\nstress-ng: info:  [12237] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
          "34": {
            "avg_ns_per_run": 242.912926542276,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 34,
            "name": "trace_connect_entry",
            "run_cnt_delta": 5949,
            "run_time_ns_delta": 1445089,
            "type": "kprobe"
          },
          "35": {
            "avg_ns_per_run": 1739.05227769373,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 35,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 5949,
            "run_time_ns_delta": 10345622,
            "type": "kprobe"
          },
          "36": {
            "avg_ns_per_run": null,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 36,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.005498915000004,
            "ops_per_sec": 5906.520545574111,
            "ops_total": 5939.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:35607/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.92ms  327.72us   5.82ms   80.25%\n    Req/Sec     2.98k     1.05k    4.29k    55.00%\n  5939 requests in 1.00s, 0.88MB read\n  Socket errors: connect 0, read 5938, write 0, timeout 0\nRequests/sec:   5932.72\nTransfer/sec:      0.88MB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "34": {
            "avg_ns_per_run": 258.6649072538079,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 34,
            "name": "trace_connect_entry",
            "run_cnt_delta": 6631,
            "run_time_ns_delta": 1715207,
            "type": "kprobe"
          },
          "35": {
            "avg_ns_per_run": 1792.2094706680741,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 35,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 6631,
            "run_time_ns_delta": 11884141,
            "type": "kprobe"
          },
          "36": {
            "avg_ns_per_run": null,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 36,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.101527266000005,
            "ops_per_sec": 6010.74544803866,
            "ops_total": 6621.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:36745/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.90ms  275.62us   2.46ms   73.37%\n    Req/Sec     3.03k   135.98     3.29k    68.18%\n  6621 requests in 1.10s, 0.98MB read\n  Socket errors: connect 0, read 6620, write 0, timeout 0\nRequests/sec:   6021.99\nTransfer/sec:      0.89MB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
      "selected_workload": "tcp_connect",
      "status": "ok"
    },
    {
      "app": "bcc/tcplife",
      "baseline": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 403.0613135148235,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 39,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 61895,
            "run_time_ns_delta": 24947480,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1022161600000118,
            "ops_per_sec": 5758.398606676146,
            "ops_total": 6347.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:46855/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.89ms  311.49us   2.61ms   74.48%\n    Req/Sec     3.04k     2.07k    6.06k    52.38%\n  6347 requests in 1.10s, 0.94MB read\n  Socket errors: connect 0, read 6345, write 0, timeout 0\nRequests/sec:   5769.64\nTransfer/sec:      0.85MB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 424.28421947203486,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 39,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 56481,
            "run_time_ns_delta": 23963997,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0032213270000057,
            "ops_per_sec": 5780.379507422461,
            "ops_total": 5799.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:43935/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.94ms  345.33us   5.41ms   84.05%\n    Req/Sec     2.91k     1.03k    4.20k    65.00%\n  5799 requests in 1.00s, 0.86MB read\n  Socket errors: connect 0, read 5798, write 0, timeout 0\nRequests/sec:   5792.72\nTransfer/sec:      0.86MB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
      "selected_workload": "tcp_connect",
      "status": "ok"
    },
    {
      "app": "bcc/runqlat",
      "baseline": {
        "bpf": {
          "42": {
            "avg_ns_per_run": 181.55640054974512,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 42,
            "name": "sched_switch",
            "run_cnt_delta": 11881870,
            "run_time_ns_delta": 2157229549,
            "type": "raw_tracepoint"
          },
          "43": {
            "avg_ns_per_run": 68.05775946952836,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 43,
            "name": "sched_wakeup",
            "run_cnt_delta": 3706890,
            "run_time_ns_delta": 252282628,
            "type": "raw_tracepoint"
          },
          "44": {
            "avg_ns_per_run": 315.52564102564105,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 44,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 24611,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0150567759999944,
            "ops_per_sec": 11552355.766944867,
            "ops_total": 11726297.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5459] setting to a 1 secs run per stressor\nstress-ng: info:  [5459] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [5459] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5459] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5459]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5459] futex           1673538      2.00      0.40      6.26    836646.62      251176.08\nstress-ng: metrc: [5459] sem             2095700      1.00      0.40      1.30   2094742.60     1231469.49\nstress-ng: metrc: [5459] sem-sysv         430799      1.00      0.15      0.82    430450.14      443992.69\nstress-ng: metrc: [5459] switch          1416619      1.00      0.19      2.68   1416414.35      494452.92\nstress-ng: metrc: [5459] yield           6109641      1.00      1.44      4.45   6103752.34     1038381.76\nstress-ng: info:  [5459] skipped: 0\nstress-ng: info:  [5459] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [5459] failed: 0\nstress-ng: info:  [5459] metrics untrustworthy: 0\nstress-ng: info:  [5459] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "42": {
            "avg_ns_per_run": 188.8414008071211,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 42,
            "name": "sched_switch",
            "run_cnt_delta": 11773698,
            "run_time_ns_delta": 2223361623,
            "type": "raw_tracepoint"
          },
          "43": {
            "avg_ns_per_run": 81.30538287515891,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 43,
            "name": "sched_wakeup",
            "run_cnt_delta": 2805118,
            "run_time_ns_delta": 228071193,
            "type": "raw_tracepoint"
          },
          "44": {
            "avg_ns_per_run": 326.2564102564103,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 44,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 25448,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0143092190000118,
            "ops_per_sec": 16054534.154835293,
            "ops_total": 16284262.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5639] setting to a 1 secs run per stressor\nstress-ng: info:  [5639] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [5639] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5639] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5639]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5639] futex           1468916      2.00      0.40      5.27    734354.66      258988.87\nstress-ng: metrc: [5639] sem             7548061      1.00      0.94      2.29   7546668.37     2338301.62\nstress-ng: metrc: [5639] sem-sysv         223753      1.00      0.05      0.52    223571.78      393672.12\nstress-ng: metrc: [5639] switch          1235617      1.00      0.48      2.91   1235390.94      363865.60\nstress-ng: metrc: [5639] yield           5807915      1.00      1.47      3.33   5798591.82     1210250.31\nstress-ng: info:  [5639] skipped: 0\nstress-ng: info:  [5639] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [5639] failed: 0\nstress-ng: info:  [5639] metrics untrustworthy: 0\nstress-ng: info:  [5639] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline": {
        "bpf": {
          "47": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 47,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "48": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 48,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 49,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "50": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 50,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "51": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 51,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 19909,
            "bytes_xlated": 33264,
            "id": 52,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 53,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "54": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 54,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 55,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 56,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "57": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 57,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "58": {
            "avg_ns_per_run": 1796.6666666666667,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 58,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 10780,
            "type": "tracepoint"
          },
          "59": {
            "avg_ns_per_run": 1355.728125,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 59,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1600,
            "run_time_ns_delta": 2169165,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.014007674999988,
            "ops_per_sec": 11565.000247032956,
            "ops_total": 57987.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5769] setting to a 5 secs run per stressor\nstress-ng: info:  [5769] dispatching hogs: 4 cpu\nstress-ng: info:  [5769] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5769] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5769]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5769] cpu               57987      5.00     20.00      0.00     11595.88        2898.81\nstress-ng: info:  [5769] skipped: 0\nstress-ng: info:  [5769] passed: 4: cpu (4)\nstress-ng: info:  [5769] failed: 0\nstress-ng: info:  [5769] metrics untrustworthy: 0\nstress-ng: info:  [5769] successful run completed in 5.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 47,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "48": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 48,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 49,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "50": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 50,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "51": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 51,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 18325,
            "bytes_xlated": 30096,
            "id": 52,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 53,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "54": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 54,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 55,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 56,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "57": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 57,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "58": {
            "avg_ns_per_run": 1931.6666666666667,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 58,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 11590,
            "type": "tracepoint"
          },
          "59": {
            "avg_ns_per_run": 1326.25625,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 59,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1600,
            "run_time_ns_delta": 2122010,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.014713297000014,
            "ops_per_sec": 11564.569411115395,
            "ops_total": 57993.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5828] setting to a 5 secs run per stressor\nstress-ng: info:  [5828] dispatching hogs: 4 cpu\nstress-ng: info:  [5828] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5828] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5828]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5828] cpu               57993      5.00     20.00      0.00     11597.19        2899.20\nstress-ng: info:  [5828] skipped: 0\nstress-ng: info:  [5828] passed: 4: cpu (4)\nstress-ng: info:  [5828] failed: 0\nstress-ng: info:  [5828] metrics untrustworthy: 0\nstress-ng: info:  [5828] successful run completed in 5.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
        ],
        "error": "prog 47: prog 47 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-23/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-23/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-23/map-values.json\" \"--map-ids\" \"69,81,76,39,56,78,79,59,47,38,40\": error: map_values snapshot missing map 76 key 00000000; prog 48: prog 48 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-28/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-28/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-28/map-values.json\" \"--map-ids\" \"69,76,39,54,61,42,51,37,31,35,29,44,53,27,83,67,63,65,49,33,45,72,75,40\": error: map_values snapshot missing map 76 key 00000000; prog 49: prog 49 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-34/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-34/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-34/map-values.json\" \"--map-ids\" \"69,76,73,39,72,75,40\": error: map_values snapshot missing map 76 key 00000000; prog 50: prog 50 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-27/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-27/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-27/map-values.json\" \"--map-ids\" \"69,76,80,39,40\": error: map_values snapshot missing map 76 key 00000000; prog 51: prog 51 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-30/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-30/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-30/map-values.json\" \"--map-ids\" \"69,58,76,39,72,40\": error: map_values snapshot missing map 76 key 00000000; prog 52: prog 52 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-31/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-31/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-31/map-values.json\" \"--map-ids\" \"69,76,74,39,40\": error: map_values snapshot missing map 76 key 00000000; prog 53: prog 53 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-24/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-24/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-24/map-values.json\" \"--map-ids\" \"69,77,76,39,40\": error: map_values snapshot missing map 76 key 00000000; prog 54: prog 54 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-26/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-26/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-26/map-values.json\" \"--map-ids\" \"69,76,57,39,72,75,40\": error: map_values snapshot missing map 76 key 00000000; prog 55: prog 55 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-29/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-29/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-29/map-values.json\" \"--map-ids\" \"69,76,71,39,72,75,40\": error: map_values snapshot missing map 76 key 00000000; prog 56: prog 56 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-25/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-25/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-25/map-values.json\" \"--map-ids\" \"69,59,76,39,47\": error: map_values snapshot missing map 76 key 00000000; prog 57: prog 57 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-35/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-35/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-35/map-values.json\" \"--map-ids\" \"69,76,70,39,40\": error: map_values snapshot missing map 76 key 00000000; prog 58: prog 58 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-32/pass-01-map_inline.report.json\" \"--prog-type\" \"tracepoint\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-32/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-32/map-values.json\" \"--map-ids\" \"56,72,78,76,39,79,38\": error: map_values snapshot missing map 76 key 00000000; prog 59: prog 59 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-33/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-33/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-33/map-values.json\" \"--map-ids\" \"76,69,39,55,40,72,56,78,75,79,38\": error: map_values snapshot missing map 76 key 00000000",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 47 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-23/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-23/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-23/map-values.json\" \"--map-ids\" \"69,81,76,39,56,78,79,59,47,38,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 47
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 48 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-28/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-28/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-28/map-values.json\" \"--map-ids\" \"69,76,39,54,61,42,51,37,31,35,29,44,53,27,83,67,63,65,49,33,45,72,75,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 48
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 49 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-34/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-34/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-34/map-values.json\" \"--map-ids\" \"69,76,73,39,72,75,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 49
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 50 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-27/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-27/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-27/map-values.json\" \"--map-ids\" \"69,76,80,39,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 50
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 51 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-30/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-30/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-30/map-values.json\" \"--map-ids\" \"69,58,76,39,72,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 51
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 52 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-31/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-31/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-31/map-values.json\" \"--map-ids\" \"69,76,74,39,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 52
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 53 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-24/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-24/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-24/map-values.json\" \"--map-ids\" \"69,77,76,39,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 53
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 54 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-26/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-26/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-26/map-values.json\" \"--map-ids\" \"69,76,57,39,72,75,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 54
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 55 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-29/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-29/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-29/map-values.json\" \"--map-ids\" \"69,76,71,39,72,75,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 55
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 56 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-25/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-25/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-25/map-values.json\" \"--map-ids\" \"69,59,76,39,47\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 56
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 57 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-35/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-35/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-35/map-values.json\" \"--map-ids\" \"69,76,70,39,40\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 57
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 58 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-32/pass-01-map_inline.report.json\" \"--prog-type\" \"tracepoint\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-32/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-32/map-values.json\" \"--map-ids\" \"56,72,78,76,39,79,38\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 58
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 59 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-33/pass-01-map_inline.report.json\" \"--prog-type\" \"perf_event\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-33/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-33/map-values.json\" \"--map-ids\" \"76,69,39,55,40,72,56,78,75,79,38\": error: map_values snapshot missing map 76 key 00000000",
            "exit_code": 1,
            "prog_id": 59
          }
        ],
        "exit_code": 1,
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
          "67": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 67,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "68": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 68,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 117,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 118,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 120,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 122,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 123,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 124,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 125,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 126,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 127,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 128,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 129,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "131": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 131,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "132": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 132,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "133": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 133,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 134,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "137": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 137,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 138,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 139,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 140,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "141": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 141,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "142": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 142,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "143": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 143,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 144,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "145": {
            "avg_ns_per_run": 1174.0,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 145,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1174,
            "type": "sched_cls"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 146,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 147,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 148,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 149,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 150,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 151,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 152,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "153": {
            "avg_ns_per_run": 607.0,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 153,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 607,
            "type": "sched_cls"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 154,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 155,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "157": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 157,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "158": {
            "avg_ns_per_run": 1246.7527559055118,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 158,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1270,
            "run_time_ns_delta": 1583376,
            "type": "sched_cls"
          },
          "159": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 159,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 160,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 161,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "162": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 162,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 163,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.065144940999971,
            "ops_per_sec": 101.87270177072766,
            "ops_total": 516.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   336.18ms  299.64ms   1.99s    85.42%\n    Req/Sec    28.17     14.96    70.00     63.37%\n  516 requests in 5.01s, 82.01KB read\n  Socket errors: connect 0, read 0, write 0, timeout 13\nRequests/sec:    103.07\nTransfer/sec:     16.38KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "67": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 67,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "68": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 68,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 117,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 118,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 120,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 122,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 123,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 124,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 125,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 126,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 127,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 128,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 129,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "131": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 131,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "132": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 132,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "133": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 133,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 134,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "137": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 137,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 138,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 139,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 140,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "141": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 141,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "142": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 142,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "143": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 143,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 144,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "145": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 145,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 146,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 147,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 148,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 149,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 150,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 151,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 152,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "153": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 153,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 154,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 155,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "157": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 157,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "158": {
            "avg_ns_per_run": 1218.2864111498259,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 158,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1435,
            "run_time_ns_delta": 1748241,
            "type": "sched_cls"
          },
          "159": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 159,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 160,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 161,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "162": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 162,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 163,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 5.079569247999984,
            "ops_per_sec": 115.7578470323084,
            "ops_total": 588.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   337.65ms  292.21ms   1.66s    83.52%\n    Req/Sec    31.63     16.60    80.00     65.92%\n  588 requests in 5.01s, 93.72KB read\n  Socket errors: connect 0, read 0, write 0, timeout 9\nRequests/sec:    117.38\nTransfer/sec:     18.71KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
        ],
        "error": "prog 68: prog 68 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8c0b471cd77a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8c0b471cd79a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 117: prog 117 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-47/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-47/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-47/map-values.json\" \"--map-ids\" \"203,190,165,166,204,169\": error: map_values snapshot missing map 203 key 00000000; prog 118: prog 118 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-49/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-49/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-49/map-values.json\" \"--map-ids\" \"203,165,166,204,164\": error: map_values snapshot missing map 203 key 00000000; prog 120: prog 120 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-57/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-57/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-57/map-values.json\" \"--map-ids\" \"203,166,164,204\": error: map_values snapshot missing map 203 key 00000000; prog 122: prog 122 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-40/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-40/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-40/map-values.json\" \"--map-ids\" \"203,166,204\": error: map_values snapshot missing map 203 key 00000000; prog 123: prog 123 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-50/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-50/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-50/map-values.json\" \"--map-ids\" \"203,164\": error: map_values snapshot missing map 203 key 00000000; prog 124: prog 124 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-44/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-44/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-44/map-values.json\" \"--map-ids\" \"205,164\": error: map_values snapshot missing map 205 key 00000000; prog 125: prog 125 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-48/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-48/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-48/map-values.json\" \"--map-ids\" \"205,166,164,206\": error: map_values snapshot missing map 205 key 00000000; prog 126: prog 126 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-55/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-55/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-55/map-values.json\" \"--map-ids\" \"205,166,165,164,206\": error: map_values snapshot missing map 205 key 00000000; prog 127: prog 127 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-36/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-36/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-36/map-values.json\" \"--map-ids\" \"205,190,165,166,206,169\": error: map_values snapshot missing map 205 key 00000000; prog 128: prog 128 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-46/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-46/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-46/map-values.json\" \"--map-ids\" \"205,165,166,206,164\": error: map_values snapshot missing map 205 key 00000000; prog 131: prog 131 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-43/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-43/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-43/map-values.json\" \"--map-ids\" \"205,166,206\": error: map_values snapshot missing map 205 key 00000000; prog 132: prog 132 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-45/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-45/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-45/map-values.json\" \"--map-ids\" \"208,166,165,164,207\": error: map_values snapshot missing map 208 key 00000000; prog 133: prog 133 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-37/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-37/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-37/map-values.json\" \"--map-ids\" \"208,190,165,166,207,169\": error: map_values snapshot missing map 208 key 00000000; prog 134: prog 134 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-53/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-53/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-53/map-values.json\" \"--map-ids\" \"208,164\": error: map_values snapshot missing map 208 key 00000000; prog 138: prog 138 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-52/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-52/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-52/map-values.json\" \"--map-ids\" \"208,166,207\": error: map_values snapshot missing map 208 key 00000000; prog 139: prog 139 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-59/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-59/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-59/map-values.json\" \"--map-ids\" \"208,166,164\": error: map_values snapshot missing map 208 key 00000000; prog 140: prog 140 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-61/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-61/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-61/map-values.json\" \"--map-ids\" \"210,190,165,166,209,169\": error: map_values snapshot missing map 210 key 00000000; prog 142: prog 142 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-54/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-54/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-54/map-values.json\" \"--map-ids\" \"210,164\": error: map_values snapshot missing map 210 key 00000000; prog 143: prog 143 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-71/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-71/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-71/map-values.json\" \"--map-ids\" \"210,165,166,209,164\": error: map_values snapshot missing map 210 key 00000000; prog 144: prog 144 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-73/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-73/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-73/map-values.json\" \"--map-ids\" \"210,166,164\": error: map_values snapshot missing map 210 key 00000000; prog 145: prog 145 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-76/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-76/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-76/map-values.json\" \"--map-ids\" \"210,166,165,164,209\": error: map_values snapshot missing map 210 key 00000000; prog 146: prog 146 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-64/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-64/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-64/map-values.json\" \"--map-ids\" \"210,166,164,209\": error: map_values snapshot missing map 210 key 00000000; prog 147: prog 147 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-66/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-66/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-66/map-values.json\" \"--map-ids\" \"210,166,209\": error: map_values snapshot missing map 210 key 00000000; prog 149: prog 149 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-65/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-65/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-65/map-values.json\" \"--map-ids\" \"211,166,165,164,212\": error: map_values snapshot missing map 211 key 00000000; prog 150: prog 150 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-75/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-75/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-75/map-values.json\" \"--map-ids\" \"211,166,164,212\": error: map_values snapshot missing map 211 key 00000000; prog 151: prog 151 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-77/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-77/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-77/map-values.json\" \"--map-ids\" \"211,166,212\": error: map_values snapshot missing map 211 key 00000000; prog 152: prog 152 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-42/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-42/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-42/map-values.json\" \"--map-ids\" \"211,165,166,212,164\": error: map_values snapshot missing map 211 key 00000000; prog 153: prog 153 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-58/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-58/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-58/map-values.json\" \"--map-ids\" \"211,166,164\": error: map_values snapshot missing map 211 key 00000000; prog 154: prog 154 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-62/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-62/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-62/map-values.json\" \"--map-ids\" \"211,164\": error: map_values snapshot missing map 211 key 00000000; prog 155: prog 155 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-63/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-63/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-63/map-values.json\" \"--map-ids\" \"211,190,165,166,212,169\": error: map_values snapshot missing map 211 key 00000000; prog 157: prog 157 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-67/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-67/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-67/map-values.json\" \"--map-ids\" \"214,164\": error: map_values snapshot missing map 214 key 00000000; prog 158: prog 158 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-60/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-60/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-60/map-values.json\" \"--map-ids\" \"214,165,166,213,164\": error: map_values snapshot missing map 214 key 00000000; prog 159: prog 159 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-72/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-72/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-72/map-values.json\" \"--map-ids\" \"214,166,164\": error: map_values snapshot missing map 214 key 00000000; prog 161: prog 161 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-68/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-68/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-68/map-values.json\" \"--map-ids\" \"214,166,213\": error: map_values snapshot missing map 214 key 00000000; prog 162: prog 162 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-69/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-69/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-69/map-values.json\" \"--map-ids\" \"214,190,165,166,213,169\": error: map_values snapshot missing map 214 key 00000000; prog 163: prog 163 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-70/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-70/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-70/map-values.json\" \"--map-ids\" \"214,166,165,164,213\": error: map_values snapshot missing map 214 key 00000000",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 68 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8c0b471cd77a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8c0b471cd79a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
            "exit_code": 1,
            "prog_id": 68
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 117 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-47/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-47/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-47/map-values.json\" \"--map-ids\" \"203,190,165,166,204,169\": error: map_values snapshot missing map 203 key 00000000",
            "exit_code": 1,
            "prog_id": 117
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 118 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-49/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-49/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-49/map-values.json\" \"--map-ids\" \"203,165,166,204,164\": error: map_values snapshot missing map 203 key 00000000",
            "exit_code": 1,
            "prog_id": 118
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 120 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-57/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-57/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-57/map-values.json\" \"--map-ids\" \"203,166,164,204\": error: map_values snapshot missing map 203 key 00000000",
            "exit_code": 1,
            "prog_id": 120
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 122 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-40/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-40/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-40/map-values.json\" \"--map-ids\" \"203,166,204\": error: map_values snapshot missing map 203 key 00000000",
            "exit_code": 1,
            "prog_id": 122
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 123 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-50/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-50/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-50/map-values.json\" \"--map-ids\" \"203,164\": error: map_values snapshot missing map 203 key 00000000",
            "exit_code": 1,
            "prog_id": 123
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 124 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-44/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-44/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-44/map-values.json\" \"--map-ids\" \"205,164\": error: map_values snapshot missing map 205 key 00000000",
            "exit_code": 1,
            "prog_id": 124
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 125 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-48/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-48/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-48/map-values.json\" \"--map-ids\" \"205,166,164,206\": error: map_values snapshot missing map 205 key 00000000",
            "exit_code": 1,
            "prog_id": 125
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 126 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-55/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-55/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-55/map-values.json\" \"--map-ids\" \"205,166,165,164,206\": error: map_values snapshot missing map 205 key 00000000",
            "exit_code": 1,
            "prog_id": 126
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 127 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-36/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-36/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-36/map-values.json\" \"--map-ids\" \"205,190,165,166,206,169\": error: map_values snapshot missing map 205 key 00000000",
            "exit_code": 1,
            "prog_id": 127
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 128 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-46/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-46/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-46/map-values.json\" \"--map-ids\" \"205,165,166,206,164\": error: map_values snapshot missing map 205 key 00000000",
            "exit_code": 1,
            "prog_id": 128
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 131 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-43/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-43/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-43/map-values.json\" \"--map-ids\" \"205,166,206\": error: map_values snapshot missing map 205 key 00000000",
            "exit_code": 1,
            "prog_id": 131
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 132 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-45/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-45/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-45/map-values.json\" \"--map-ids\" \"208,166,165,164,207\": error: map_values snapshot missing map 208 key 00000000",
            "exit_code": 1,
            "prog_id": 132
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 133 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-37/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-37/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-37/map-values.json\" \"--map-ids\" \"208,190,165,166,207,169\": error: map_values snapshot missing map 208 key 00000000",
            "exit_code": 1,
            "prog_id": 133
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 134 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-53/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-53/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-53/map-values.json\" \"--map-ids\" \"208,164\": error: map_values snapshot missing map 208 key 00000000",
            "exit_code": 1,
            "prog_id": 134
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 138 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-52/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-52/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-52/map-values.json\" \"--map-ids\" \"208,166,207\": error: map_values snapshot missing map 208 key 00000000",
            "exit_code": 1,
            "prog_id": 138
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 139 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-59/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-59/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-59/map-values.json\" \"--map-ids\" \"208,166,164\": error: map_values snapshot missing map 208 key 00000000",
            "exit_code": 1,
            "prog_id": 139
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 140 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-61/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-61/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-61/map-values.json\" \"--map-ids\" \"210,190,165,166,209,169\": error: map_values snapshot missing map 210 key 00000000",
            "exit_code": 1,
            "prog_id": 140
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 142 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-54/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-54/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-54/map-values.json\" \"--map-ids\" \"210,164\": error: map_values snapshot missing map 210 key 00000000",
            "exit_code": 1,
            "prog_id": 142
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 143 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-71/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-71/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-71/map-values.json\" \"--map-ids\" \"210,165,166,209,164\": error: map_values snapshot missing map 210 key 00000000",
            "exit_code": 1,
            "prog_id": 143
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 144 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-73/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-73/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-73/map-values.json\" \"--map-ids\" \"210,166,164\": error: map_values snapshot missing map 210 key 00000000",
            "exit_code": 1,
            "prog_id": 144
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 145 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-76/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-76/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-76/map-values.json\" \"--map-ids\" \"210,166,165,164,209\": error: map_values snapshot missing map 210 key 00000000",
            "exit_code": 1,
            "prog_id": 145
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 146 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-64/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-64/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-64/map-values.json\" \"--map-ids\" \"210,166,164,209\": error: map_values snapshot missing map 210 key 00000000",
            "exit_code": 1,
            "prog_id": 146
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 147 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-66/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-66/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-66/map-values.json\" \"--map-ids\" \"210,166,209\": error: map_values snapshot missing map 210 key 00000000",
            "exit_code": 1,
            "prog_id": 147
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 149 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-65/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-65/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-65/map-values.json\" \"--map-ids\" \"211,166,165,164,212\": error: map_values snapshot missing map 211 key 00000000",
            "exit_code": 1,
            "prog_id": 149
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 150 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-75/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-75/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-75/map-values.json\" \"--map-ids\" \"211,166,164,212\": error: map_values snapshot missing map 211 key 00000000",
            "exit_code": 1,
            "prog_id": 150
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 151 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-77/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-77/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-77/map-values.json\" \"--map-ids\" \"211,166,212\": error: map_values snapshot missing map 211 key 00000000",
            "exit_code": 1,
            "prog_id": 151
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 152 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-42/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-42/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-42/map-values.json\" \"--map-ids\" \"211,165,166,212,164\": error: map_values snapshot missing map 211 key 00000000",
            "exit_code": 1,
            "prog_id": 152
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 153 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-58/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-58/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-58/map-values.json\" \"--map-ids\" \"211,166,164\": error: map_values snapshot missing map 211 key 00000000",
            "exit_code": 1,
            "prog_id": 153
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 154 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-62/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-62/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-62/map-values.json\" \"--map-ids\" \"211,164\": error: map_values snapshot missing map 211 key 00000000",
            "exit_code": 1,
            "prog_id": 154
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 155 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-63/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-63/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-63/map-values.json\" \"--map-ids\" \"211,190,165,166,212,169\": error: map_values snapshot missing map 211 key 00000000",
            "exit_code": 1,
            "prog_id": 155
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 157 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-67/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-67/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-67/map-values.json\" \"--map-ids\" \"214,164\": error: map_values snapshot missing map 214 key 00000000",
            "exit_code": 1,
            "prog_id": 157
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 158 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-60/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-60/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-60/map-values.json\" \"--map-ids\" \"214,165,166,213,164\": error: map_values snapshot missing map 214 key 00000000",
            "exit_code": 1,
            "prog_id": 158
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 159 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-72/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-72/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-72/map-values.json\" \"--map-ids\" \"214,166,164\": error: map_values snapshot missing map 214 key 00000000",
            "exit_code": 1,
            "prog_id": 159
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 161 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-68/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-68/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-68/map-values.json\" \"--map-ids\" \"214,166,213\": error: map_values snapshot missing map 214 key 00000000",
            "exit_code": 1,
            "prog_id": 161
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 162 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-69/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-69/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-69/map-values.json\" \"--map-ids\" \"214,190,165,166,213,169\": error: map_values snapshot missing map 214 key 00000000",
            "exit_code": 1,
            "prog_id": 162
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 163 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-70/pass-01-map_inline.report.json\" \"--prog-type\" \"sched_cls\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-70/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-70/map-values.json\" \"--map-ids\" \"214,166,165,164,213\": error: map_values snapshot missing map 214 key 00000000",
            "exit_code": 1,
            "prog_id": 163
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 6,
          "not_applied": 37,
          "requested": 43
        }
      },
      "runner": "cilium",
      "selected_workload": "network_lossy_multi",
      "status": "ok"
    },
    {
      "app": "tetragon/observer",
      "baseline": {
        "bpf": {
          "178": {
            "avg_ns_per_run": 1376.739534883721,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 178,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1505,
            "run_time_ns_delta": 2071993,
            "type": "kprobe"
          },
          "180": {
            "avg_ns_per_run": 2142.3220234423197,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 180,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1621,
            "run_time_ns_delta": 3472704,
            "type": "kprobe"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 181,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 182,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "183": {
            "avg_ns_per_run": 6521.5,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 183,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 13043,
            "type": "tracepoint"
          },
          "184": {
            "avg_ns_per_run": 659.5,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 184,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1319,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 185,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 188,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 189,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 190,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "191": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 191,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 192,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 193,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "194": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 194,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 195,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 196,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 197,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 198,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 199,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 200,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 201,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 202,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 203,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "204": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 204,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 205,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "206": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 206,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 207,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "208": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 208,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 209,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "210": {
            "avg_ns_per_run": 645.6491277015214,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 210,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 53766,
            "run_time_ns_delta": 34713971,
            "type": "kprobe"
          },
          "211": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 211,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "212": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 212,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 213,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 214,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 215,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 216,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 217,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": 386.15096901387494,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 218,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 53766,
            "run_time_ns_delta": 20761793,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 219,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 220,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 221,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 222,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": 1230.7611543792489,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 223,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 60604,
            "run_time_ns_delta": 74589049,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 224,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 225,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 226,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 227,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 228,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 229,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 230,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 231,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 232,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 233,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 234,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 235,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 236,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "237": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 237,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 238,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": 649.788063088197,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 239,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 53766,
            "run_time_ns_delta": 34936505,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 240,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 241,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 242,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 243,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": 431.83249637317266,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 244,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 53766,
            "run_time_ns_delta": 23217906,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": 1210.7851296944095,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 245,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 60604,
            "run_time_ns_delta": 73378422,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 246,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 247,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "248": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 248,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 249,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 250,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 251,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 252,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 253,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": 514.4126868786815,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 254,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 194043,
            "run_time_ns_delta": 99818181,
            "type": "kprobe"
          },
          "255": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 255,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "256": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 256,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "257": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 257,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 258,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 259,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 260,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 261,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 262,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": 850.4870079726969,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 263,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 394973,
            "run_time_ns_delta": 335919405,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 264,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 265,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 266,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 267,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 268,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 269,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 270,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 271,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 272,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 273,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 274,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 275,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 276,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 277,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 278,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 279,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 280,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 281,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 282,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 283,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 284,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 285,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": 193.80022655680213,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 286,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 322215,
            "run_time_ns_delta": 62445340,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 287,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 288,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": 497.22115551946166,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 289,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 379258,
            "run_time_ns_delta": 188575101,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 290,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 291,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 292,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 293,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": 40.44001444926673,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 294,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 379258,
            "run_time_ns_delta": 15337199,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 295,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 296,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 297,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 298,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 299,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": 6377.99786036036,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 300,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8880,
            "run_time_ns_delta": 56636621,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 301,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 302,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 303,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 304,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": 62.06216216216216,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 305,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8880,
            "run_time_ns_delta": 551112,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 306,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 307,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 308,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "309": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 309,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "310": {
            "avg_ns_per_run": 6322.181818181818,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 310,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 139088,
            "type": "kprobe"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 311,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 312,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 313,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 314,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 315,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 316,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 317,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 318,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": 631.0454545454545,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 319,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 13883,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 320,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 321,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 322,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 323,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 324,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 325,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 326,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 327,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 328,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 329,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 330,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 331,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 332,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 333,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 334,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 335,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 336,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 337,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 338,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 339,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 340,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 341,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 342,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 343,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 344,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 345,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 346,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 347,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 348,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 349,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 350,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 351,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 352,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 353,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 354,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "355": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 355,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "avg_ns_per_run": 4216.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 356,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8432,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 357,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "358": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 358,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 359,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 360,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 361,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 362,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 363,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 364,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 365,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 366,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 367,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "368": {
            "avg_ns_per_run": 931.5019900942085,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 368,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 7811188,
            "run_time_ns_delta": 7276137167,
            "type": "tracepoint"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 369,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 370,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 371,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 372,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "373": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 373,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 374,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "375": {
            "avg_ns_per_run": 4121.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 375,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8242,
            "type": "raw_tracepoint"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 376,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 377,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 378,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 379,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": 1089.35184352518,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 380,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22240,
            "run_time_ns_delta": 24227185,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 381,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 382,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 383,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": 3746.1638225255974,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 384,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 879,
            "run_time_ns_delta": 3292878,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 385,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 386,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 387,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 388,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 389,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 390,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 391,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 392,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 393,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 394,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 395,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 396,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 397,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "398": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 398,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 399,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 400,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 401,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": 690.7716400699327,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 402,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 53766,
            "run_time_ns_delta": 37140028,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 403,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": 457.36017185581966,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 404,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 53766,
            "run_time_ns_delta": 24590427,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 405,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 406,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 407,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 408,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 409,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": 1226.671259322817,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 410,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 60604,
            "run_time_ns_delta": 74341185,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 411,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 412,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 413,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 414,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 415,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 416,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 417,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 418,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": 583.3634531971456,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 419,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 71470,
            "run_time_ns_delta": 41692986,
            "type": "kprobe"
          },
          "420": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 420,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 421,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 422,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 423,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 424,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": 1335.6963954338414,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 425,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 17783,
            "run_time_ns_delta": 23752689,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 426,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 427,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 428,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 429,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "430": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 430,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 431,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 432,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 433,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "434": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 434,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": 1414.691121863396,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 435,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8887,
            "run_time_ns_delta": 12572360,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 436,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 437,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 438,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": 1912.5966017778778,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 439,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8887,
            "run_time_ns_delta": 16997246,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 440,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 441,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 442,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 443,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 444,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": 1747.5451170117012,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 445,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8888,
            "run_time_ns_delta": 15532181,
            "type": "kprobe"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 446,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 447,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "avg_ns_per_run": 1323.2144182646348,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 17783,
            "run_time_ns_delta": 23530722,
            "type": "kprobe"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 449,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 450,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 451,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 452,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 453,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 454,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 455,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 456,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": 1137.5531295792339,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 457,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 334390,
            "run_time_ns_delta": 380386391,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 458,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 459,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 460,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 461,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 462,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 463,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 464,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 465,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 466,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "467": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 467,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.0485739360000252,
            "ops_per_sec": 10952614.697329491,
            "ops_total": 22437241.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8602] setting to a 1 secs run per stressor\nstress-ng: info:  [8602] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 aio, 4 aiol, 4 hdd, 4 io, 4 iomix, 4 io-uring, 4 sync-file, 4 epoll, 4 netdev, 4 sctp, 4 sock, 4 sockdiag, 4 sockfd, 4 sockpair, 4 sockmany, 4 udp-flood\nstress-ng: info:  [8602] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [8644] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [8602] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8602]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8602] cap              105409      1.00      0.04      1.09    105208.60       93527.04\nstress-ng: metrc: [8602] eventfd           44901      1.00      0.05      0.74     44840.31       56606.06\nstress-ng: metrc: [8602] get                 733      1.01      0.07      0.33       728.32        1847.12\nstress-ng: metrc: [8602] prctl              1306      1.00      0.70      0.14      1300.70        1558.94\nstress-ng: metrc: [8602] set                8638      1.01      0.03      0.90      8568.97        9248.00\nstress-ng: metrc: [8602] aio                8096      1.05      0.03      0.04      7720.18      106910.35\nstress-ng: metrc: [8602] aiol                485      1.19      0.00      0.08       409.01        5970.63\nstress-ng: metrc: [8602] hdd               18193      1.04      0.28      0.29     17431.74       32097.63\nstress-ng: metrc: [8602] io                   84      1.03      0.01      0.00        81.21        6012.02\nstress-ng: metrc: [8602] iomix               882      1.28      0.12      1.26       689.14         639.73\nstress-ng: metrc: [8602] io-uring           8308      1.05      0.00      0.40      7937.51       20778.21\nstress-ng: metrc: [8602] sync-file            27      1.04      0.01      0.32        25.93          80.91\nstress-ng: metrc: [8602] epoll             10494      1.10      0.03      0.80      9581.93       12677.47\nstress-ng: metrc: [8602] netdev            64733      1.00      0.02      1.54     64731.46       41520.29\nstress-ng: metrc: [8602] sctp              26417      1.00      0.03      0.47     26346.42       52824.81\nstress-ng: metrc: [8602] sock                637      1.01      0.01      1.32       632.84         475.73\nstress-ng: metrc: [8602] sockdiag       21903817      1.00      0.04      1.29  21898449.81    16473581.06\nstress-ng: metrc: [8602] sockfd            92604      1.02      0.03      0.84     90633.28      106566.81\nstress-ng: metrc: [8602] sockpair           2779      1.04      0.00      0.25      2675.72       11121.52\nstress-ng: metrc: [8602] sockmany           8883      1.05      0.06      0.75      8488.29       10948.34\nstress-ng: metrc: [8602] udp-flood        129815      1.01      0.05      1.14    128772.48      109324.62\nstress-ng: info:  [8602] skipped: 0\nstress-ng: info:  [8602] passed: 84: cap (4) eventfd (4) get (4) prctl (4) set (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp-flood (4)\nstress-ng: info:  [8602] failed: 0\nstress-ng: info:  [8602] metrics untrustworthy: 0\nstress-ng: info:  [8602] successful run completed in 2.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "178": {
            "avg_ns_per_run": 1328.232492997199,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 178,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1071,
            "run_time_ns_delta": 1422537,
            "type": "kprobe"
          },
          "180": {
            "avg_ns_per_run": 2312.479359730413,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 180,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1187,
            "run_time_ns_delta": 2744913,
            "type": "kprobe"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 181,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 182,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "183": {
            "avg_ns_per_run": 15230.5,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 183,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 30461,
            "type": "tracepoint"
          },
          "184": {
            "avg_ns_per_run": 1129.5,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 184,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2259,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 185,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 188,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 189,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 190,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "191": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 191,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 192,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 193,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "194": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 194,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 195,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 196,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 197,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 198,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 199,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 200,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 201,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 202,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 203,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "204": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 204,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 205,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "206": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 206,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 207,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "208": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 208,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 209,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "210": {
            "avg_ns_per_run": 637.9912112676056,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 210,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 62125,
            "run_time_ns_delta": 39635204,
            "type": "kprobe"
          },
          "211": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 211,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "212": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 212,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 213,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 214,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 215,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 216,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 217,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": 385.17245875251507,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 218,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 62125,
            "run_time_ns_delta": 23928839,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 219,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 220,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 221,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 222,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": 969.0520175777616,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 223,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 69861,
            "run_time_ns_delta": 67698943,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 224,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 225,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 226,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 227,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 228,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 229,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 230,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 231,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 232,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 233,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 234,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 235,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 236,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "237": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 237,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 238,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": 641.878921529175,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 239,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 62125,
            "run_time_ns_delta": 39876728,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 240,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 241,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 242,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 243,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": 552.1960724346077,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 244,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 62125,
            "run_time_ns_delta": 34305181,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": 994.3192768497445,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 245,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 69861,
            "run_time_ns_delta": 69464139,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 246,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 247,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "248": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 248,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 249,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 250,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 251,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 252,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 253,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": 503.3538286839017,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 254,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 264190,
            "run_time_ns_delta": 132981048,
            "type": "kprobe"
          },
          "255": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 255,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "256": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 256,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "257": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 257,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 258,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 259,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 260,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 261,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 262,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": 757.2561210963933,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 263,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 539405,
            "run_time_ns_delta": 408467738,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 264,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 265,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 266,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 267,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 268,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 269,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 270,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 271,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 272,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 273,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 274,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 275,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 276,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 277,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 278,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 279,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 280,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 281,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 282,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 283,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 284,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 285,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": 194.2751662526595,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 286,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 359092,
            "run_time_ns_delta": 69762658,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 287,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 288,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": 502.09717516912673,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 289,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 567326,
            "run_time_ns_delta": 284852782,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 290,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 291,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 292,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 293,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": 41.60171753101391,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 294,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 567326,
            "run_time_ns_delta": 23601736,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 295,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 296,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 297,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 298,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 299,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": 5122.3181359919345,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 300,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8927,
            "run_time_ns_delta": 45726934,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 301,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 302,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 303,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 304,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": 51.564131287106534,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 305,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8927,
            "run_time_ns_delta": 460313,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 306,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 307,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 308,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "309": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 309,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "310": {
            "avg_ns_per_run": 6287.75,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 310,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 125755,
            "type": "kprobe"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 311,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 312,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 313,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 314,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 315,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 316,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 317,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 318,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": 616.8,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 319,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 12336,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 320,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 321,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 322,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 323,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 324,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 325,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 326,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 327,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 328,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 329,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 330,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 331,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 332,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 333,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 334,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 335,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 336,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 337,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 338,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 339,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 340,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 341,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 342,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 343,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 344,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 345,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 346,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 347,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 348,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 349,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 350,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 351,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 352,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 353,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 354,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "355": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 355,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "avg_ns_per_run": 10555.5,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 356,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 21111,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 357,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "358": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 358,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 359,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 360,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 361,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 362,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 4646,
            "bytes_xlated": 8312,
            "id": 363,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 14824,
            "bytes_xlated": 25624,
            "id": 364,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 11015,
            "bytes_xlated": 17848,
            "id": 365,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 366,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 367,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "368": {
            "avg_ns_per_run": 871.0861299421252,
            "bytes_jited": 10815,
            "bytes_xlated": 19224,
            "id": 368,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 6828717,
            "run_time_ns_delta": 5948400664,
            "type": "tracepoint"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 369,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 370,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 16995,
            "bytes_xlated": 29336,
            "id": 371,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 372,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "373": {
            "avg_ns_per_run": null,
            "bytes_jited": 729,
            "bytes_xlated": 1152,
            "id": 373,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 374,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "375": {
            "avg_ns_per_run": 8770.0,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 375,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 17540,
            "type": "raw_tracepoint"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 376,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 377,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 378,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 379,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": 1189.4735087719298,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 380,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 17100,
            "run_time_ns_delta": 20339997,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 381,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 382,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 383,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": 4462.496036240091,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 384,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 883,
            "run_time_ns_delta": 3940384,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 385,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 386,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 387,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 388,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 389,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 390,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 391,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 392,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 393,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 394,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 395,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 396,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 397,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "398": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 398,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 399,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 400,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 401,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": 669.782583501006,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 402,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 62125,
            "run_time_ns_delta": 41610243,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 403,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": 517.2467283702214,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 404,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 62125,
            "run_time_ns_delta": 32133953,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 405,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 406,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 407,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 408,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 409,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": 1017.7285180572852,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 410,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 69861,
            "run_time_ns_delta": 71099532,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 411,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 412,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 413,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 414,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 415,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 416,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 417,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 418,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": 487.8748718600031,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 419,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 110231,
            "run_time_ns_delta": 53778935,
            "type": "kprobe"
          },
          "420": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 420,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 421,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 422,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 423,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 424,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": 1041.0319634703196,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 425,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 28032,
            "run_time_ns_delta": 29182208,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 426,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 427,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 428,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 429,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "430": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 430,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 431,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 432,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 433,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "434": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 434,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": 1068.9488295746503,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 435,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 14012,
            "run_time_ns_delta": 14978111,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 436,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 437,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 438,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": 1693.61704253497,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 439,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 14012,
            "run_time_ns_delta": 23730962,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 440,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 441,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 442,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 443,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 444,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": 1268.119389138657,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 445,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 14013,
            "run_time_ns_delta": 17770157,
            "type": "kprobe"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 446,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 447,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "avg_ns_per_run": 992.9594392123288,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 448,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 28032,
            "run_time_ns_delta": 27834639,
            "type": "kprobe"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 449,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 450,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 451,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 452,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 453,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 454,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 455,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 456,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": 1077.5157072841916,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 457,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 284836,
            "run_time_ns_delta": 306915264,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 458,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 459,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 460,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 461,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 462,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 463,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 464,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 465,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 466,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "467": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 467,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2514172859999917,
            "ops_per_sec": 19449485.213519868,
            "ops_total": 24339422.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [12591] setting to a 1 secs run per stressor\nstress-ng: info:  [12591] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 aio, 4 aiol, 4 hdd, 4 io, 4 iomix, 4 io-uring, 4 sync-file, 4 epoll, 4 netdev, 4 sctp, 4 sock, 4 sockdiag, 4 sockfd, 4 sockpair, 4 sockmany, 4 udp-flood\nstress-ng: info:  [12591] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [12633] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [12591] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12591]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12591] cap              187339      1.01      0.03      1.62    185079.80      113377.86\nstress-ng: metrc: [12591] eventfd           70018      1.01      0.05      1.11     69579.23       60175.31\nstress-ng: metrc: [12591] get                1011      1.01      0.05      0.43      1002.73        2130.81\nstress-ng: metrc: [12591] prctl               873      1.00      0.50      0.13       870.78        1383.29\nstress-ng: metrc: [12591] set                9684      1.01      0.02      0.92      9614.18       10229.24\nstress-ng: metrc: [12591] aio                6036      1.03      0.01      0.04      5857.38      108222.47\nstress-ng: metrc: [12591] aiol                583      1.19      0.03      0.07       488.62        5893.83\nstress-ng: metrc: [12591] hdd               20734      1.04      0.26      0.27     19974.33       38580.70\nstress-ng: metrc: [12591] io                   28      1.04      0.01      0.00        26.93        1933.84\nstress-ng: metrc: [12591] iomix              1302      1.05      0.08      1.13      1237.04        1079.29\nstress-ng: metrc: [12591] io-uring           8948      1.06      0.00      0.47      8444.23       18902.04\nstress-ng: metrc: [12591] sync-file            29      1.04      0.05      0.26        27.98          94.79\nstress-ng: metrc: [12591] epoll               293      1.14      0.03      0.00       256.91        7765.29\nstress-ng: metrc: [12591] netdev            41094      1.00      0.04      0.89     40940.57       43883.17\nstress-ng: metrc: [12591] sctp              21897      1.01      0.03      0.42     21659.84       48230.96\nstress-ng: metrc: [12591] sock                530      1.01      0.01      1.27       526.87         415.65\nstress-ng: metrc: [12591] sockdiag       23682533      1.00      0.09      1.50  23654096.85    14938786.54\nstress-ng: metrc: [12591] sockfd            88025      1.02      0.04      0.76     85924.57      110903.65\nstress-ng: metrc: [12591] sockpair          18323      1.04      0.01      0.61     17669.31       29470.09\nstress-ng: metrc: [12591] sockmany          14007      1.04      0.00      1.01     13469.88       13818.97\nstress-ng: metrc: [12591] udp-flood        166135      1.00      0.02      1.31    166134.25      124625.96\nstress-ng: info:  [12591] skipped: 0\nstress-ng: info:  [12591] passed: 84: cap (4) eventfd (4) get (4) prctl (4) set (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp-flood (4)\nstress-ng: info:  [12591] failed: 0\nstress-ng: info:  [12591] metrics untrustworthy: 0\nstress-ng: info:  [12591] successful run completed in 1.22 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
        ],
        "error": "prog 189: prog 189 pass map_inline failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 11: Resource temporarily unavailable (os error 11)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2040\nLive regs before insn:\n      0: .1........ (bf) r9 = r1\n      1: .........9 (b7) r1 = 0\n      2: .1.......9 (63) *(u32 *)(r10 -308) = r1\n      3: .........9 (bf) r2 = r10\n      4: ..2......9 (07) r2 += -308\n      5: ..2......9 (18) r1 = 0xffff8c080e950000\n      7: .12......9 (85) call bpf_map_lookup_elem#1\n      8: 0........9 (bf) r7 = r0\n      9: .......7.9 (15) if r7 == 0x0 goto pc+2020\n     10: .......7.9 (85) call bpf_get_current_task#35\n     11: 0......7.9 (7b) *(u64 *)(r10 -264) = r0\n     12: 0......7.9 (b7) r1 = 2804\n     13: 01.....7.9 (0f) r0 += r1\n     14: 0......7.9 (bf) r1 = r10\n     15: 01.....7.9 (07) r1 += -280\n     16: 01.....7.9 (b7) r2 = 4\n     17: 012....7.9 (bf) r3 = r0\n     18: .123...7.9 (85) call bpf_probe_read_kernel#113\n     19: .......7.9 (61) r1 = *(u32 *)(r10 -280)\n     20: .1.....7.9 (63) *(u32 *)(r10 -304) = r1\n     21: .......7.9 (bf) r2 = r10\n     22: ..2....7.9 (07) r2 += -304\n     23: ..2....7.9 (18) r1 = 0xffff8c0a25fcb800\n     25: .12....7.9 (85) call bpf_map_lookup_elem#1\n     26: 0......7.9 (bf) r6 = r0\n     27: ......67.9 (15) if r6 == 0x0 goto pc+2\n     28: ......67.9 (79) r1 = *(u64 *)(r6 +8)\n     29: .1....67.9 (55) if r1 != 0x0 goto pc+661\n     30: .......7.9 (b7) r1 = 2816\n     31: .1.....7.9 (79) r3 = *(u64 *)(r10 -264)\n     32: .1.3...7.9 (0f) r3 += r1\n     33: ...3...7.9 (bf) r1 = r10\n     34: .1.3...7.9 (07) r1 += -264\n     35: .1.3...7.9 (b7) r2 = 8\n     36: .123...7.9 (85) call bpf_probe_read_kernel#113\n     37: .......7.9 (79) r3 = *(u64 *)(r10 -264)\n     38: ...3...7.9 (15) if r3 == 0x0 goto pc+76\n     39: ...3...7.9 (b7) r1 = 2804\n     40: .1.3...7.9 (0f) r3 += r1\n     41: ...3...7.9 (bf) r1 = r10\n     42: .1.3...7.9 (07) r1 += -280\n     43: .1.3...7.9 (b7) r2 = 4\n     44: .123...7.9 (85) call bpf_probe_read_kernel#113\n     45: .......7.9 (61) r1 = *(u32 *)(r10 -280)\n     46: .1.....7.9 (63) *(u32 *)(r10 -304) = r1\n     47: .......7.9 (bf) r2 = r10\n     48: ..2....7.9 (07) r2 += -304\n     49: ..2....7.9 (18) r1 = 0xffff8c0a25fcb800\n     51: .12....7.9 (85) call bpf_map_lookup_elem#1\n     52: 0......7.9 (bf) r6 = r0\n     53: ......67.9 (15) if r6 == 0x0 goto pc+2\n     54: ......67.9 (79) r1 = *(u64 *)(r6 +8)\n     55: .1....67.9 (55) if r1 != 0x0 goto pc+635\n     56: .......7.9 (b7) r1 = 2816\n     57: .1.....7.9 (79) r3 = *(u64 *)(r10 -264)\n     58: .1.3...7.9 (0f) r3 += r1\n     59: ...3...7.9 (bf) r1 = r10\n     60: .1.3...7.9 (07) r1 += -264\n     61: .1.3...7.9 (b7) r2 = 8\n     62: .123...7.9 (85) call bpf_probe_read_kernel#113\n     63: .......7.9 (79) r3 = *(u64 *)(r10 -264)\n     64: ...3...7.9 (15) if r3 == 0x0 goto pc+50\n     65: ...3...7.9 (b7) r1 = 2804\n     66: .1.3...7.9 (0f) r3 += r1\n     67: ...3...7.9 (bf) r1 = r10\n     68: .1.3...7.9 (07) r1 += -280\n     69: .1.3...7.9 (b7) r2 = 4\n     70: .123...7.9 (85) call bpf_probe_read_kernel#113\n     71: .......7.9 (61) r1 = *(u32 *)(r10 -280)\n     72: .1.....7.9 (63) *(u32 *)(r10 -304) = r1\n     73: .......7.9 (bf) r2 = r10\n     74: ..2....7.9 (07) r2 += -304\n     75: ..2....7.9 (18) r1 = 0xffff8c0a25fcb800\n     77: .12....7.9 (85) call bpf_map_lookup_elem#1\n     78: 0......7.9 (bf) r6 = r0\n     79: ......67.9 (15) if r6 == 0x0 goto pc+2\n     80: ......67.9 (79) r1 = *(u64 *)(r6 +8)\n     81: .1....67.9 (55) if r1 != 0x0 goto pc+609\n     82: .......7.9 (b7) r1 = 2816\n     83: .1.....7.9 (79) r3 = *(u64 *)(r10 -264)\n     84: .1.3...7.9 (0f) r3 += r1\n     85: ...3...7.9 (bf) r1 = r10\n     86: .1.3...7.9 (07) r1 += -264\n     87: .1.3...7.9 (b7) r2 = 8\n     88: .123...7.9 (85) call bpf_probe_read_kernel#113\n     89: .......7.9 (79) r3 = *(u64 *)(r10 -264)\n     90: ...3...7.9 (15) if r3 == 0x0 goto pc+24\n     91: ...3...7.9 (b7) r1 = 2804\n     92: .1.3...7.9 (0f) r3 += r1\n     93: ...3...7.9 (bf) r1 = r10\n     94: .1.3...7.9 (07) r1 += -280\n     95: .1.3...7.9 (b7) r2 = 4\n     96: .123...7.9 (85) call bpf_probe_read_kernel#113\n     97: .......7.9 (61) r1 = *(u32 *)(r10 -280)\n     98: .1.....7.9 (63) *(u32 *)(r10 -304) = r1\n     99: .......7.9 (bf) r2 = r10\n    100: ..2....7.9 (07) r2 += -304\n    101: \n... verifier log truncated ...; prog 194: prog 194 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 201: prog 201 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 204: prog 204 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 212: prog 212 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 216: prog 216 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 222: prog 222 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 229: prog 229 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 235: prog 235 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 242: prog 242 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 250: prog 250 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 253: prog 253 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 259: prog 259 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 270: prog 270 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 273: prog 273 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 280: prog 280 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 290: prog 290 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 295: prog 295 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 304: prog 304 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 308: prog 308 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 309: prog 309 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 316: prog 316 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 320: prog 320 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 328: prog 328 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 335: prog 335 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 341: prog 341 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 11: Resource temporarily unavailable (os error 11)\nverifier log summary:\nfunc#0 @0\nfunc#1 @273\nfunc#2 @302\nfunc#3 @331\nfunc#4 @392\nfunc#5 @449\nfunc#6 @682\nfunc#7 @727\nfunc#8 @909\nfunc#9 @1189\nfunc#10 @1225\nfunc#11 @1380\nfunc#12 @1628\nfunc#13 @1834\nfunc#14 @1891\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -20) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -20\n      5: ..2...6... (18) r1 = 0xffff8c09bca16000\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (15) if r7 == 0x0 goto pc+261\n     10: ......67.. (61) r9 = *(u32 *)(r7 +24296)\n     11: ......67.9 (bf) r2 = r7\n     12: ..2...67.9 (07) r2 += 24288\n     13: ..2...67.9 (18) r1 = 0xffff8c08501b2000\n     15: .12...67.9 (85) call bpf_map_lookup_elem#1\n     16: 0.....67.9 (bf) r8 = r0\n     17: ......6789 (15) if r8 == 0x0 goto pc+248\n     18: ......6789 (71) r1 = *(u8 *)(r7 +24264)\n     19: .1....6789 (15) if r1 == 0x0 goto pc+246\n     20: ......6789 (7b) *(u64 *)(r10 -48) = r6\n     21: .......789 (7b) *(u64 *)(r10 -56) = r9\n     22: .......789 (57) r9 &= 7\n     23: .......789 (bf) r1 = r7\n     24: .1.....789 (0f) r1 += r9\n     25: .1.....789 (71) r1 = *(u8 *)(r1 +24233)\n     26: .1.....789 (15) if r1 == 0x0 goto pc+174\n     27: .......789 (67) r9 <<= 2\n     28: .......789 (07) r9 += 4\n     29: .......789 (bf) r1 = r9\n     30: .1.....789 (0f) r1 += r8\n     31: .1.....789 (61) r1 = *(u32 *)(r1 +0)\n     32: .1.....789 (0f) r9 += r1\n     33: .......789 (07) r9 += 4\n     34: .......789 (bf) r1 = r9\n     35: .1.....789 (57) r1 &= 1023\n     36: .1.....789 (bf) r3 = r8\n     37: .1.3...789 (7b) *(u64 *)(r10 -64) = r1\n     38: .1.3...789 (0f) r3 += r1\n     39: ...3...789 (69) r1 = *(u16 *)(r3 +0)\n     40: .1.3...789 (71) r2 = *(u8 *)(r3 +2)\n     41: .123...789 (67) r2 <<= 16\n     42: .123...789 (7b) *(u64 *)(r10 -40) = r3\n     43: .123...789 (71) r3 = *(u8 *)(r3 +3)\n     44: .123...789 (67) r3 <<= 24\n     45: .123...789 (4f) r3 |= r2\n     46: .1.3...789 (4f) r3 |= r1\n     47: ...3...789 (a5) if r3 < 0x19 goto pc+149\n     48: .......789 (b7) r1 = 1\n     49: .1.....789 (7b) *(u64 *)(r10 -32) = r1\n     50: .......789 (b7) r6 = 4\n  1  51: ......6789 (79) r1 = *(u64 *)(r10 -40)\n  1  52: .1....6789 (0f) r1 += r6\n  1  53: .1....6789 (69) r3 = *(u16 *)(r1 +0)\n  1  54: .1.3..6789 (71) r4 = *(u8 *)(r1 +2)\n  1  55: .1.34.6789 (67) r4 <<= 16\n  1  56: .1.34.6789 (71) r2 = *(u8 *)(r1 +3)\n  1  57: ..234.6789 (67) r2 <<= 24\n  1  58: ..234.6789 (4f) r2 |= r4\n  1  59: ..23..6789 (4f) r2 |= r3\n  1  60: ..2...6789 (57) r2 &= 1023\n  1  61: ..2...6789 (65) if r2 s> 0x0 goto pc+3\n     62: .......7.. (79) r1 = *(u64 *)(r10 -32)\n     63: .1.....7.. (15) if r1 == 0x0 goto pc+137\n     64: .......7.. (05) goto pc+132\n  1  65: ..2...6789 (0f) r2 += r9\n  1  66: ..2...6789 (57) r2 &= 1023\n  1  67: ..2...6789 (bf) r1 = r8\n  1  68: .12...6789 (0f) r1 += r2\n  1  69: .1....6789 (69) r3 = *(u16 *)(r1 +0)\n  1  70: .1.3..6789 (71) r4 = *(u8 *)(r1 +2)\n  1  71: .1.34.6789 (67) r4 <<= 16\n  1  72: .1.34.6789 (71) r2 = *(u8 *)(r1 +3)\n  1  73: .1234.6789 (67) r2 <<= 24\n  1  74: .1234.6789 (4f) r2 |= r4\n  1  75: .123..6789 (4f) r2 |= r3\n  1  76: .12...6789 (25) if r2 > 0x5 goto pc+124\n  1  77: .12...6789 (57) r2 &= 7\n  1  78: .12...6789 (67) r2 <<= 32\n  1  79: .12...6789 (77) r2 >>= 32\n  1  80: .12...6789 (67) r2 <<= 3\n  1  81: .12...6789 (bf) r3 = r7\n  1  82: .123..6789 (0f) r3 += r2\n  1  83: .1.3..6789 (79) r4 = *(u64 *)(r3 +24184)\n  1  84: .1..4.6789 (57) r4 &= 2047\n  1  85: .1..4.6789 (69) r2 = *(u16 *)(r1 +12)\n  1  86: .12.4.6789 (71) r5 = *(u8 *)(r1 +14)\n  1  87: .12.456789 (67) r5 <<= 16\n  1  88: .12.456789 (71) r3 = *(u8 *)(r1 +15)\n  1  89: .123456789 (67) r3 <<= 24\n  1  90: .123456789 (4f) r3 |= r5\n  1  91: .123456789 (4f) r3 |= r2\n  1  92: .1.3456789 (bf) r2 = r7\n  1  93: .123456789 (0f) r2 += r4\n  1  94: .123456789 (07) r2 += 144\n  1  95: .123456789 (65) if r3 s> 0x10 goto pc+8\n  1  96: .123456789 (65) if r3 s> 0x9 goto pc+16\n  1  97: .123456789 (65) if r3 s> 0x4 goto pc+78\n  1  98: .123456789 (15) if r3 == 0x1 goto pc+3\n  1  9\n... verifier log truncated ...; prog 343: prog 343 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 354: prog 354 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 357: prog 357 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 367: prog 367 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 370: prog 370 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 382: prog 382 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 386: prog 386 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 390: prog 390 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 397: prog 397 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 405: prog 405 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 411: prog 411 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 417: prog 417 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 422: prog 422 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 434: prog 434 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 436: prog 436 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 444: prog 444 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 450: prog 450 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 454: prog 454 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 461: prog 461 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 189 pass map_inline failed after 1 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 11: Resource temporarily unavailable (os error 11)\nverifier log summary:\nfunc#0 @0\nfunc#1 @2040\nLive regs before insn:\n      0: .1........ (bf) r9 = r1\n      1: .........9 (b7) r1 = 0\n      2: .1.......9 (63) *(u32 *)(r10 -308) = r1\n      3: .........9 (bf) r2 = r10\n      4: ..2......9 (07) r2 += -308\n      5: ..2......9 (18) r1 = 0xffff8c080e950000\n      7: .12......9 (85) call bpf_map_lookup_elem#1\n      8: 0........9 (bf) r7 = r0\n      9: .......7.9 (15) if r7 == 0x0 goto pc+2020\n     10: .......7.9 (85) call bpf_get_current_task#35\n     11: 0......7.9 (7b) *(u64 *)(r10 -264) = r0\n     12: 0......7.9 (b7) r1 = 2804\n     13: 01.....7.9 (0f) r0 += r1\n     14: 0......7.9 (bf) r1 = r10\n     15: 01.....7.9 (07) r1 += -280\n     16: 01.....7.9 (b7) r2 = 4\n     17: 012....7.9 (bf) r3 = r0\n     18: .123...7.9 (85) call bpf_probe_read_kernel#113\n     19: .......7.9 (61) r1 = *(u32 *)(r10 -280)\n     20: .1.....7.9 (63) *(u32 *)(r10 -304) = r1\n     21: .......7.9 (bf) r2 = r10\n     22: ..2....7.9 (07) r2 += -304\n     23: ..2....7.9 (18) r1 = 0xffff8c0a25fcb800\n     25: .12....7.9 (85) call bpf_map_lookup_elem#1\n     26: 0......7.9 (bf) r6 = r0\n     27: ......67.9 (15) if r6 == 0x0 goto pc+2\n     28: ......67.9 (79) r1 = *(u64 *)(r6 +8)\n     29: .1....67.9 (55) if r1 != 0x0 goto pc+661\n     30: .......7.9 (b7) r1 = 2816\n     31: .1.....7.9 (79) r3 = *(u64 *)(r10 -264)\n     32: .1.3...7.9 (0f) r3 += r1\n     33: ...3...7.9 (bf) r1 = r10\n     34: .1.3...7.9 (07) r1 += -264\n     35: .1.3...7.9 (b7) r2 = 8\n     36: .123...7.9 (85) call bpf_probe_read_kernel#113\n     37: .......7.9 (79) r3 = *(u64 *)(r10 -264)\n     38: ...3...7.9 (15) if r3 == 0x0 goto pc+76\n     39: ...3...7.9 (b7) r1 = 2804\n     40: .1.3...7.9 (0f) r3 += r1\n     41: ...3...7.9 (bf) r1 = r10\n     42: .1.3...7.9 (07) r1 += -280\n     43: .1.3...7.9 (b7) r2 = 4\n     44: .123...7.9 (85) call bpf_probe_read_kernel#113\n     45: .......7.9 (61) r1 = *(u32 *)(r10 -280)\n     46: .1.....7.9 (63) *(u32 *)(r10 -304) = r1\n     47: .......7.9 (bf) r2 = r10\n     48: ..2....7.9 (07) r2 += -304\n     49: ..2....7.9 (18) r1 = 0xffff8c0a25fcb800\n     51: .12....7.9 (85) call bpf_map_lookup_elem#1\n     52: 0......7.9 (bf) r6 = r0\n     53: ......67.9 (15) if r6 == 0x0 goto pc+2\n     54: ......67.9 (79) r1 = *(u64 *)(r6 +8)\n     55: .1....67.9 (55) if r1 != 0x0 goto pc+635\n     56: .......7.9 (b7) r1 = 2816\n     57: .1.....7.9 (79) r3 = *(u64 *)(r10 -264)\n     58: .1.3...7.9 (0f) r3 += r1\n     59: ...3...7.9 (bf) r1 = r10\n     60: .1.3...7.9 (07) r1 += -264\n     61: .1.3...7.9 (b7) r2 = 8\n     62: .123...7.9 (85) call bpf_probe_read_kernel#113\n     63: .......7.9 (79) r3 = *(u64 *)(r10 -264)\n     64: ...3...7.9 (15) if r3 == 0x0 goto pc+50\n     65: ...3...7.9 (b7) r1 = 2804\n     66: .1.3...7.9 (0f) r3 += r1\n     67: ...3...7.9 (bf) r1 = r10\n     68: .1.3...7.9 (07) r1 += -280\n     69: .1.3...7.9 (b7) r2 = 4\n     70: .123...7.9 (85) call bpf_probe_read_kernel#113\n     71: .......7.9 (61) r1 = *(u32 *)(r10 -280)\n     72: .1.....7.9 (63) *(u32 *)(r10 -304) = r1\n     73: .......7.9 (bf) r2 = r10\n     74: ..2....7.9 (07) r2 += -304\n     75: ..2....7.9 (18) r1 = 0xffff8c0a25fcb800\n     77: .12....7.9 (85) call bpf_map_lookup_elem#1\n     78: 0......7.9 (bf) r6 = r0\n     79: ......67.9 (15) if r6 == 0x0 goto pc+2\n     80: ......67.9 (79) r1 = *(u64 *)(r6 +8)\n     81: .1....67.9 (55) if r1 != 0x0 goto pc+609\n     82: .......7.9 (b7) r1 = 2816\n     83: .1.....7.9 (79) r3 = *(u64 *)(r10 -264)\n     84: .1.3...7.9 (0f) r3 += r1\n     85: ...3...7.9 (bf) r1 = r10\n     86: .1.3...7.9 (07) r1 += -264\n     87: .1.3...7.9 (b7) r2 = 8\n     88: .123...7.9 (85) call bpf_probe_read_kernel#113\n     89: .......7.9 (79) r3 = *(u64 *)(r10 -264)\n     90: ...3...7.9 (15) if r3 == 0x0 goto pc+24\n     91: ...3...7.9 (b7) r1 = 2804\n     92: .1.3...7.9 (0f) r3 += r1\n     93: ...3...7.9 (bf) r1 = r10\n     94: .1.3...7.9 (07) r1 += -280\n     95: .1.3...7.9 (b7) r2 = 4\n     96: .123...7.9 (85) call bpf_probe_read_kernel#113\n     97: .......7.9 (61) r1 = *(u32 *)(r10 -280)\n     98: .1.....7.9 (63) *(u32 *)(r10 -304) = r1\n     99: .......7.9 (bf) r2 = r10\n    100: ..2....7.9 (07) r2 += -304\n    101: \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 189
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 194 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 194
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 201 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 201
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 204 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 204
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 212 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 212
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 216 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 216
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 222 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 222
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 229 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 229
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 235 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 235
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 242 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 242
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 250 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 250
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 253 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 253
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 259 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 259
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 270 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 270
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 273 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 273
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 280 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 280
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 290 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 290
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 295 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 295
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 304 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 304
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 308 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 308
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 309 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 309
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 316 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 316
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 320 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 320
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 328 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 328
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 335 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 335
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 341 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 11: Resource temporarily unavailable (os error 11)\nverifier log summary:\nfunc#0 @0\nfunc#1 @273\nfunc#2 @302\nfunc#3 @331\nfunc#4 @392\nfunc#5 @449\nfunc#6 @682\nfunc#7 @727\nfunc#8 @909\nfunc#9 @1189\nfunc#10 @1225\nfunc#11 @1380\nfunc#12 @1628\nfunc#13 @1834\nfunc#14 @1891\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r1 = 0\n      2: .1....6... (63) *(u32 *)(r10 -20) = r1\n      3: ......6... (bf) r2 = r10\n      4: ..2...6... (07) r2 += -20\n      5: ..2...6... (18) r1 = 0xffff8c09bca16000\n      7: .12...6... (85) call bpf_map_lookup_elem#1\n      8: 0.....6... (bf) r7 = r0\n      9: ......67.. (15) if r7 == 0x0 goto pc+261\n     10: ......67.. (61) r9 = *(u32 *)(r7 +24296)\n     11: ......67.9 (bf) r2 = r7\n     12: ..2...67.9 (07) r2 += 24288\n     13: ..2...67.9 (18) r1 = 0xffff8c08501b2000\n     15: .12...67.9 (85) call bpf_map_lookup_elem#1\n     16: 0.....67.9 (bf) r8 = r0\n     17: ......6789 (15) if r8 == 0x0 goto pc+248\n     18: ......6789 (71) r1 = *(u8 *)(r7 +24264)\n     19: .1....6789 (15) if r1 == 0x0 goto pc+246\n     20: ......6789 (7b) *(u64 *)(r10 -48) = r6\n     21: .......789 (7b) *(u64 *)(r10 -56) = r9\n     22: .......789 (57) r9 &= 7\n     23: .......789 (bf) r1 = r7\n     24: .1.....789 (0f) r1 += r9\n     25: .1.....789 (71) r1 = *(u8 *)(r1 +24233)\n     26: .1.....789 (15) if r1 == 0x0 goto pc+174\n     27: .......789 (67) r9 <<= 2\n     28: .......789 (07) r9 += 4\n     29: .......789 (bf) r1 = r9\n     30: .1.....789 (0f) r1 += r8\n     31: .1.....789 (61) r1 = *(u32 *)(r1 +0)\n     32: .1.....789 (0f) r9 += r1\n     33: .......789 (07) r9 += 4\n     34: .......789 (bf) r1 = r9\n     35: .1.....789 (57) r1 &= 1023\n     36: .1.....789 (bf) r3 = r8\n     37: .1.3...789 (7b) *(u64 *)(r10 -64) = r1\n     38: .1.3...789 (0f) r3 += r1\n     39: ...3...789 (69) r1 = *(u16 *)(r3 +0)\n     40: .1.3...789 (71) r2 = *(u8 *)(r3 +2)\n     41: .123...789 (67) r2 <<= 16\n     42: .123...789 (7b) *(u64 *)(r10 -40) = r3\n     43: .123...789 (71) r3 = *(u8 *)(r3 +3)\n     44: .123...789 (67) r3 <<= 24\n     45: .123...789 (4f) r3 |= r2\n     46: .1.3...789 (4f) r3 |= r1\n     47: ...3...789 (a5) if r3 < 0x19 goto pc+149\n     48: .......789 (b7) r1 = 1\n     49: .1.....789 (7b) *(u64 *)(r10 -32) = r1\n     50: .......789 (b7) r6 = 4\n  1  51: ......6789 (79) r1 = *(u64 *)(r10 -40)\n  1  52: .1....6789 (0f) r1 += r6\n  1  53: .1....6789 (69) r3 = *(u16 *)(r1 +0)\n  1  54: .1.3..6789 (71) r4 = *(u8 *)(r1 +2)\n  1  55: .1.34.6789 (67) r4 <<= 16\n  1  56: .1.34.6789 (71) r2 = *(u8 *)(r1 +3)\n  1  57: ..234.6789 (67) r2 <<= 24\n  1  58: ..234.6789 (4f) r2 |= r4\n  1  59: ..23..6789 (4f) r2 |= r3\n  1  60: ..2...6789 (57) r2 &= 1023\n  1  61: ..2...6789 (65) if r2 s> 0x0 goto pc+3\n     62: .......7.. (79) r1 = *(u64 *)(r10 -32)\n     63: .1.....7.. (15) if r1 == 0x0 goto pc+137\n     64: .......7.. (05) goto pc+132\n  1  65: ..2...6789 (0f) r2 += r9\n  1  66: ..2...6789 (57) r2 &= 1023\n  1  67: ..2...6789 (bf) r1 = r8\n  1  68: .12...6789 (0f) r1 += r2\n  1  69: .1....6789 (69) r3 = *(u16 *)(r1 +0)\n  1  70: .1.3..6789 (71) r4 = *(u8 *)(r1 +2)\n  1  71: .1.34.6789 (67) r4 <<= 16\n  1  72: .1.34.6789 (71) r2 = *(u8 *)(r1 +3)\n  1  73: .1234.6789 (67) r2 <<= 24\n  1  74: .1234.6789 (4f) r2 |= r4\n  1  75: .123..6789 (4f) r2 |= r3\n  1  76: .12...6789 (25) if r2 > 0x5 goto pc+124\n  1  77: .12...6789 (57) r2 &= 7\n  1  78: .12...6789 (67) r2 <<= 32\n  1  79: .12...6789 (77) r2 >>= 32\n  1  80: .12...6789 (67) r2 <<= 3\n  1  81: .12...6789 (bf) r3 = r7\n  1  82: .123..6789 (0f) r3 += r2\n  1  83: .1.3..6789 (79) r4 = *(u64 *)(r3 +24184)\n  1  84: .1..4.6789 (57) r4 &= 2047\n  1  85: .1..4.6789 (69) r2 = *(u16 *)(r1 +12)\n  1  86: .12.4.6789 (71) r5 = *(u8 *)(r1 +14)\n  1  87: .12.456789 (67) r5 <<= 16\n  1  88: .12.456789 (71) r3 = *(u8 *)(r1 +15)\n  1  89: .123456789 (67) r3 <<= 24\n  1  90: .123456789 (4f) r3 |= r5\n  1  91: .123456789 (4f) r3 |= r2\n  1  92: .1.3456789 (bf) r2 = r7\n  1  93: .123456789 (0f) r2 += r4\n  1  94: .123456789 (07) r2 += 144\n  1  95: .123456789 (65) if r3 s> 0x10 goto pc+8\n  1  96: .123456789 (65) if r3 s> 0x9 goto pc+16\n  1  97: .123456789 (65) if r3 s> 0x4 goto pc+78\n  1  98: .123456789 (15) if r3 == 0x1 goto pc+3\n  1  9\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 341
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 343 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 343
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 354 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 354
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 357 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 357
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 367 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 367
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 370 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 370
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 382 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 382
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 386 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 386
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 390 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 390
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 397 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 397
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 405 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 405
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 411 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 411
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 417 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 417
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 422 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 422
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 434 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 434
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 436 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 436
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 444 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 444
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 450 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 450
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 454 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 454
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 461 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 461
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 242,
          "not_applied": 45,
          "requested": 287
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
          "474": {
            "avg_ns_per_run": 316.4512532552083,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 474,
            "name": "xdp_root",
            "run_cnt_delta": 36864,
            "run_time_ns_delta": 11665659,
            "type": "xdp"
          },
          "480": {
            "avg_ns_per_run": null,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 480,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "482": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 482,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0006714410000086,
            "ops_per_sec": 6139.877434555412,
            "ops_total": 6144.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "474": {
            "avg_ns_per_run": 317.3246570142617,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 474,
            "name": "xdp_root",
            "run_cnt_delta": 36882,
            "run_time_ns_delta": 11703568,
            "type": "xdp"
          },
          "480": {
            "avg_ns_per_run": null,
            "bytes_jited": 13581,
            "bytes_xlated": 23744,
            "id": 480,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "482": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 482,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0004054779999478,
            "ops_per_sec": 6144.508536967768,
            "ops_total": 6147.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "katran",
      "selected_workload": "network",
      "status": "ok"
    },
    {
      "app": "tracee/monitor",
      "baseline": {
        "bpf": {
          "497": {
            "avg_ns_per_run": 154.66661957770557,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 497,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 29822984,
            "run_time_ns_delta": 4612620121,
            "type": "raw_tracepoint"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 498,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 499,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "500": {
            "avg_ns_per_run": 304.15366932601137,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 500,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 29823011,
            "run_time_ns_delta": 9070778226,
            "type": "raw_tracepoint"
          },
          "501": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 501,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 502,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "503": {
            "avg_ns_per_run": 265.3590630558107,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 503,
            "name": "trace_sys_enter",
            "run_cnt_delta": 29822993,
            "run_time_ns_delta": 7913801480,
            "type": "raw_tracepoint"
          },
          "504": {
            "avg_ns_per_run": 260.82820792410104,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 504,
            "name": "trace_sys_exit",
            "run_cnt_delta": 29823017,
            "run_time_ns_delta": 7778684079,
            "type": "raw_tracepoint"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 505,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 506,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 507,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 508,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": 68.3029665704395,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 509,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 1509622,
            "run_time_ns_delta": 103111661,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": 274.7958257100122,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 510,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1509622,
            "run_time_ns_delta": 414837824,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": 321.3978853644964,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 511,
            "name": "trace_dup",
            "run_cnt_delta": 1797,
            "run_time_ns_delta": 577552,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": 1309.0222593210908,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 512,
            "name": "trace_ret_dup",
            "run_cnt_delta": 1797,
            "run_time_ns_delta": 2352313,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": 1131.5,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 513,
            "name": "trace_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 4526,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": 3888.5,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 514,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 15554,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 515,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 516,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 517,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 518,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 519,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 520,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 521,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": 2506.626461038961,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 522,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 6160,
            "run_time_ns_delta": 15440819,
            "type": "raw_tracepoint"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 523,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 524,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 525,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 526,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 527,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 528,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 529,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": 3754.0,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 530,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7508,
            "type": "raw_tracepoint"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 531,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "532": {
            "avg_ns_per_run": 1259.3258408258407,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 532,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 6006,
            "run_time_ns_delta": 7563511,
            "type": "raw_tracepoint"
          },
          "533": {
            "avg_ns_per_run": 866.0098612736085,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 533,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 5983,
            "run_time_ns_delta": 5181337,
            "type": "raw_tracepoint"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 534,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "535": {
            "avg_ns_per_run": 378.7381171483004,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 535,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 1407259,
            "run_time_ns_delta": 532982624,
            "type": "raw_tracepoint"
          },
          "536": {
            "avg_ns_per_run": 18.03117807776686,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 536,
            "name": "trace_filldir64",
            "run_cnt_delta": 445794,
            "run_time_ns_delta": 8038191,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 537,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": 899.0391275391275,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 538,
            "name": "trace_do_exit",
            "run_cnt_delta": 6006,
            "run_time_ns_delta": 5399629,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 539,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 540,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 541,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": 92.90275813353568,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 542,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 6101590,
            "run_time_ns_delta": 566854540,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 543,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 544,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 545,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "546": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 546,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "547": {
            "avg_ns_per_run": 10979.0,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 547,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 21958,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": 548.5469832937455,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 548,
            "name": "trace_security_file_open",
            "run_cnt_delta": 882005,
            "run_time_ns_delta": 483821182,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 549,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": 1715.7936893203882,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 550,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 412,
            "run_time_ns_delta": 706907,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": 257.9464476155299,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 551,
            "name": "trace_commit_creds",
            "run_cnt_delta": 384446,
            "run_time_ns_delta": 99166480,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": 526.2364302364302,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 552,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 6006,
            "run_time_ns_delta": 3160576,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": 134.3471848267331,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 553,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2339483,
            "run_time_ns_delta": 314302955,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": 342.5153170431471,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 554,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 363941,
            "run_time_ns_delta": 124655367,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 555,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 556,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 557,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 558,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": 1217.85,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 559,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 24357,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": 386.1986335050079,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 560,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 154556,
            "run_time_ns_delta": 59689316,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": 512.9116447204406,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 561,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 176492,
            "run_time_ns_delta": 90524802,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": 1159.15,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 562,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 23183,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": 357.0358695596773,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 563,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 392394,
            "run_time_ns_delta": 140098733,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 564,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 565,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "566": {
            "avg_ns_per_run": 58.560397473003285,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 566,
            "name": "trace_vfs_write",
            "run_cnt_delta": 826119,
            "run_time_ns_delta": 48377857,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": 53.26108829357514,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 567,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 826119,
            "run_time_ns_delta": 43999997,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": 560.8627461661092,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 568,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 826119,
            "run_time_ns_delta": 463339371,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": 42.660665109990205,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 569,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 826119,
            "run_time_ns_delta": 35242786,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 570,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "571": {
            "avg_ns_per_run": 527.4213483146067,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 571,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 178,
            "run_time_ns_delta": 93881,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": 326.10674157303373,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 572,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 178,
            "run_time_ns_delta": 58047,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": 2297.376404494382,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 573,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 178,
            "run_time_ns_delta": 408933,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": 4904.224719101124,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 574,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 178,
            "run_time_ns_delta": 872952,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 575,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 576,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 577,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 578,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 579,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 580,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": 51.36088454468403,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 581,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1271886,
            "run_time_ns_delta": 65325190,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 534.5490672906219,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 582,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1271886,
            "run_time_ns_delta": 679885475,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 583,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": 399.9269662921348,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 584,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 178,
            "run_time_ns_delta": 71187,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": 2052.775280898876,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 585,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 178,
            "run_time_ns_delta": 365394,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 586,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 137.34856822403702,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 587,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 28531,
            "run_time_ns_delta": 3918692,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": 69.6737034049865,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 588,
            "name": "trace_do_mmap",
            "run_cnt_delta": 28517,
            "run_time_ns_delta": 1986885,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": 377.0950661009223,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 589,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 28517,
            "run_time_ns_delta": 10753620,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": 122.6734822712447,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 590,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 28513,
            "run_time_ns_delta": 3497789,
            "type": "kprobe"
          },
          "591": {
            "avg_ns_per_run": 1085.547619047619,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 591,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 42,
            "run_time_ns_delta": 45593,
            "type": "kprobe"
          },
          "592": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 592,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "593": {
            "avg_ns_per_run": 304.24902391410444,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 593,
            "name": "trace_security_bpf",
            "run_cnt_delta": 8196,
            "run_time_ns_delta": 2493625,
            "type": "kprobe"
          },
          "594": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 594,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 595,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "596": {
            "avg_ns_per_run": 311.6019938650307,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 596,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 812658,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": 895.8571428571429,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 597,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 144233,
            "type": "kprobe"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 598,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 599,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 600,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 601,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 602,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": 1166.875,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 603,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 16,
            "run_time_ns_delta": 18670,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 604,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 605,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 606,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 607,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "608": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 608,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 609,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 610,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 3756.25,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 611,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 15025,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": 45.849202417206904,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 612,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 2555346,
            "run_time_ns_delta": 117160576,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": 1000.7777603019817,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 613,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 6358,
            "run_time_ns_delta": 6362945,
            "type": "raw_tracepoint"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 614,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 615,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 616,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": 970.8146011038635,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 617,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 11958,
            "run_time_ns_delta": 11609001,
            "type": "kprobe"
          },
          "618": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 618,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "619": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 619,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "620": {
            "avg_ns_per_run": 1931.9983079526228,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 620,
            "name": "trace_do_truncate",
            "run_cnt_delta": 591,
            "run_time_ns_delta": 1141811,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 173.81351467321343,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 621,
            "name": "trace_fd_install",
            "run_cnt_delta": 1841110,
            "run_time_ns_delta": 320009800,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": 322.0476360194918,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 622,
            "name": "trace_filp_close",
            "run_cnt_delta": 496620,
            "run_time_ns_delta": 159935297,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": 193.97326565143825,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 623,
            "name": "trace_file_update_time",
            "run_cnt_delta": 14775,
            "run_time_ns_delta": 2865955,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 693.951269035533,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 624,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 14775,
            "run_time_ns_delta": 10253130,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 109.3367885986746,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 625,
            "name": "trace_file_modified",
            "run_cnt_delta": 190434,
            "run_time_ns_delta": 20821442,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 470.41178045937176,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 626,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 190434,
            "run_time_ns_delta": 89582397,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 627,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 628,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 629,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": 219.5,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 630,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 439,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": 8122.0,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 631,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 16244,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": 4052.0,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 632,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8104,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 633,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 7990.5,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 634,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 15981,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 286.69381285169453,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 635,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 672814,
            "run_time_ns_delta": 192891611,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 636,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 637,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": 356.30003252856653,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 638,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 528766,
            "run_time_ns_delta": 188399343,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 639,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 640,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 55.52940044411547,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 641,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 540400,
            "run_time_ns_delta": 30008088,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 318.52416358253146,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 642,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 540400,
            "run_time_ns_delta": 172130458,
            "type": "kprobe"
          },
          "643": {
            "avg_ns_per_run": 992.7848594075344,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 643,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 114302,
            "run_time_ns_delta": 113477295,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": 227.04661281919246,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 644,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 1648731,
            "run_time_ns_delta": 374338789,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 241.1360789488755,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 645,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 3265303,
            "run_time_ns_delta": 787382362,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": 261.55131878727116,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 646,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 3542952,
            "run_time_ns_delta": 926663768,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 281.8141550602362,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 648,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 1114612,
            "run_time_ns_delta": 314113439,
            "type": "cgroup_skb"
          },
          "649": {
            "avg_ns_per_run": 255.21425979890324,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 649,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 2163635,
            "run_time_ns_delta": 552190505,
            "type": "cgroup_skb"
          },
          "650": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 650,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "651": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 651,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "652": {
            "avg_ns_per_run": 106.0,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 652,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 212,
            "type": "kprobe"
          },
          "653": {
            "avg_ns_per_run": 720.0,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 653,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1440,
            "type": "raw_tracepoint"
          },
          "654": {
            "avg_ns_per_run": 262.6831242453274,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 654,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 882005,
            "run_time_ns_delta": 231687829,
            "type": "lsm"
          },
          "655": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 655,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.18782839000005,
            "ops_per_sec": 21844881.418677557,
            "ops_total": 113327496.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [12483] setting to a 5 secs run per stressor\nstress-ng: info:  [12483] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 aio, 4 aiol, 4 hdd, 4 io, 4 iomix, 4 io-uring, 4 sync-file, 4 epoll, 4 netdev, 4 sctp, 4 sock, 4 sockdiag, 4 sockfd, 4 sockpair, 4 sockmany, 4 udp-flood\nstress-ng: info:  [12483] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [12523] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [12483] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12483]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12483] cap              422691      5.00      0.14      4.72     84459.37       87089.86\nstress-ng: metrc: [12483] eventfd          288544      5.00      0.15      5.53     57661.00       50854.25\nstress-ng: metrc: [12483] get                3916      5.00      0.10      2.39       782.97        1571.61\nstress-ng: metrc: [12483] prctl              5740      5.00      3.93      1.11      1147.82        1138.40\nstress-ng: metrc: [12483] set               40124      5.01      0.14      4.87      8004.62        8002.75\nstress-ng: metrc: [12483] aio               26094      5.03      0.01      0.28      5189.61       88170.00\nstress-ng: metrc: [12483] aiol               3825      5.15      0.05      0.36       743.04        9241.59\nstress-ng: metrc: [12483] hdd               90833      5.03      1.27      1.48     18040.71       32994.02\nstress-ng: metrc: [12483] io                  119      5.04      0.01      0.05        23.60        1943.84\nstress-ng: metrc: [12483] iomix              4155      5.04      0.12      3.31       824.12        1210.22\nstress-ng: metrc: [12483] io-uring          35948      5.05      0.01      1.55      7113.85       23019.57\nstress-ng: metrc: [12483] sync-file           137      5.00      0.08      1.55        27.39          84.42\nstress-ng: metrc: [12483] epoll             38617      5.06      0.20      2.76      7635.44       13061.40\nstress-ng: metrc: [12483] netdev           267449      5.00      0.21      7.12     53474.45       36490.64\nstress-ng: metrc: [12483] sctp              53861      5.00      0.05      2.18     10767.50       24103.81\nstress-ng: metrc: [12483] sock               2487      5.00      0.10      5.04       496.99         484.62\nstress-ng: metrc: [12483] sockdiag      110806285      5.01      0.15      7.52  22127232.91    14446863.20\nstress-ng: metrc: [12483] sockfd           458976      5.01      0.13      5.29     91666.26       84766.42\nstress-ng: metrc: [12483] sockpair         136068      5.03      0.05      2.58     27052.88       51840.43\nstress-ng: metrc: [12483] sockmany         100931      5.02      0.17      6.71     20091.44       14687.09\nstress-ng: metrc: [12483] udp-flood        540696      5.00      0.07      3.99    108087.66      133040.43\nstress-ng: info:  [12483] skipped: 0\nstress-ng: info:  [12483] passed: 84: cap (4) eventfd (4) get (4) prctl (4) set (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp-flood (4)\nstress-ng: info:  [12483] failed: 0\nstress-ng: info:  [12483] metrics untrustworthy: 0\nstress-ng: info:  [12483] successful run completed in 5.16 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "497": {
            "avg_ns_per_run": 156.62441874671012,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 497,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 29974454,
            "run_time_ns_delta": 4694731435,
            "type": "raw_tracepoint"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 498,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 499,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "500": {
            "avg_ns_per_run": 304.0246600791513,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 500,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 29974478,
            "run_time_ns_delta": 9112980485,
            "type": "raw_tracepoint"
          },
          "501": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 501,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 502,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "503": {
            "avg_ns_per_run": 261.0933840529672,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 503,
            "name": "trace_sys_enter",
            "run_cnt_delta": 29974454,
            "run_time_ns_delta": 7826131630,
            "type": "raw_tracepoint"
          },
          "504": {
            "avg_ns_per_run": 259.42529671409125,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 504,
            "name": "trace_sys_exit",
            "run_cnt_delta": 29974478,
            "run_time_ns_delta": 7776137849,
            "type": "raw_tracepoint"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 505,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 506,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 507,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 508,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": 72.78695006889836,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 509,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 1224267,
            "run_time_ns_delta": 89110661,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": 266.3988263997968,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 510,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1224267,
            "run_time_ns_delta": 326143292,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": 322.3808368708308,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 511,
            "name": "trace_dup",
            "run_cnt_delta": 1649,
            "run_time_ns_delta": 531606,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": 1593.5603395997575,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 512,
            "name": "trace_ret_dup",
            "run_cnt_delta": 1649,
            "run_time_ns_delta": 2627781,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": 741.5,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 513,
            "name": "trace_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 2966,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": 2725.25,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 514,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 10901,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 515,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 516,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 517,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 518,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 519,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 520,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 521,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": 2960.4956835976714,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 522,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 4981,
            "run_time_ns_delta": 14746229,
            "type": "raw_tracepoint"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 523,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 524,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 525,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 526,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 527,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 528,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 529,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": 7461.5,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 530,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 14923,
            "type": "raw_tracepoint"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 531,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "532": {
            "avg_ns_per_run": 1376.2097134728713,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 532,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 4921,
            "run_time_ns_delta": 6772328,
            "type": "raw_tracepoint"
          },
          "533": {
            "avg_ns_per_run": 978.0952477660438,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 533,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 4924,
            "run_time_ns_delta": 4816141,
            "type": "raw_tracepoint"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 534,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "535": {
            "avg_ns_per_run": 408.3298501049583,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 535,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 975149,
            "run_time_ns_delta": 398182445,
            "type": "raw_tracepoint"
          },
          "536": {
            "avg_ns_per_run": 17.346020029150406,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 536,
            "name": "trace_filldir64",
            "run_cnt_delta": 680608,
            "run_time_ns_delta": 11805840,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 537,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": 932.45925624873,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 538,
            "name": "trace_do_exit",
            "run_cnt_delta": 4921,
            "run_time_ns_delta": 4588632,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 539,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 540,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 541,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": 100.53838199411375,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 542,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 4770440,
            "run_time_ns_delta": 479612319,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 543,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 544,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 545,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "546": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 546,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "547": {
            "avg_ns_per_run": 4797.0,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 547,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9594,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": 551.959995047185,
            "bytes_jited": 22949,
            "bytes_xlated": 37088,
            "id": 548,
            "name": "trace_security_file_open",
            "run_cnt_delta": 638021,
            "run_time_ns_delta": 352162068,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 549,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": 1777.7958115183246,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 550,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 382,
            "run_time_ns_delta": 679118,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": 244.58289610128307,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 551,
            "name": "trace_commit_creds",
            "run_cnt_delta": 516888,
            "run_time_ns_delta": 126421964,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": 443.616744564113,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 552,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 4921,
            "run_time_ns_delta": 2183038,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": 140.7474461859275,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 553,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2344043,
            "run_time_ns_delta": 329918066,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": 334.18461226604205,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 554,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 443990,
            "run_time_ns_delta": 148374626,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 555,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 556,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 557,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 558,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": 1375.3,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 559,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 27506,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": 448.5697340743678,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 560,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 148801,
            "run_time_ns_delta": 66747625,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": 531.7254082004476,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 561,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 172893,
            "run_time_ns_delta": 91931601,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": 1058.1,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 562,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 21162,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": 353.95609985029273,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 563,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 381411,
            "run_time_ns_delta": 135002750,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 564,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 565,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "566": {
            "avg_ns_per_run": 70.69864348318758,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 566,
            "name": "trace_vfs_write",
            "run_cnt_delta": 522441,
            "run_time_ns_delta": 36935870,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": 76.35999088892335,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 567,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 522441,
            "run_time_ns_delta": 39893590,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": 627.0019849131289,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 568,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 522441,
            "run_time_ns_delta": 327571544,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": 50.248910403279986,
            "bytes_jited": 23768,
            "bytes_xlated": 36720,
            "id": 569,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 522441,
            "run_time_ns_delta": 26252091,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 570,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "571": {
            "avg_ns_per_run": 408.85276073619633,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 571,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 66643,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": 463.8834355828221,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 572,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 75613,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": 2302.564417177914,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 573,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 375318,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": 5304.60736196319,
            "bytes_jited": 24504,
            "bytes_xlated": 37576,
            "id": 574,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 864651,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 575,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 576,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 577,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 578,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 23768,
            "bytes_xlated": 36720,
            "id": 579,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 580,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": 71.9985237009714,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 581,
            "name": "trace_vfs_read",
            "run_cnt_delta": 698368,
            "run_time_ns_delta": 50281465,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 674.0630741958395,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 582,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 698368,
            "run_time_ns_delta": 470744081,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 583,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": 386.70552147239266,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 584,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 63033,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": 2612.711656441718,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 585,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 163,
            "run_time_ns_delta": 425872,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 586,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 135.2674552496598,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 587,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 28659,
            "run_time_ns_delta": 3876630,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": 66.8346657357305,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 588,
            "name": "trace_do_mmap",
            "run_cnt_delta": 28645,
            "run_time_ns_delta": 1914479,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": 378.00977482981324,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 589,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 28645,
            "run_time_ns_delta": 10828090,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": 123.78942774344472,
            "bytes_jited": 36948,
            "bytes_xlated": 60816,
            "id": 590,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 28641,
            "run_time_ns_delta": 3545453,
            "type": "kprobe"
          },
          "591": {
            "avg_ns_per_run": 1305.404761904762,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 591,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 42,
            "run_time_ns_delta": 54827,
            "type": "kprobe"
          },
          "592": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 592,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "593": {
            "avg_ns_per_run": 281.2938018545632,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 593,
            "name": "trace_security_bpf",
            "run_cnt_delta": 8196,
            "run_time_ns_delta": 2305484,
            "type": "kprobe"
          },
          "594": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 594,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 595,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "596": {
            "avg_ns_per_run": 280.0621165644172,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 596,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 730402,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": 929.7888198757764,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 597,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 149696,
            "type": "kprobe"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 598,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 599,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 600,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 601,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 602,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": 1740.9375,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 603,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 16,
            "run_time_ns_delta": 27855,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 604,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 605,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 606,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 607,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "608": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 608,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 609,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 610,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 2069.25,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 611,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 8277,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": 54.85318614529561,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 612,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 1657834,
            "run_time_ns_delta": 90937477,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": 974.3694291674568,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 613,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 5273,
            "run_time_ns_delta": 5137850,
            "type": "raw_tracepoint"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 614,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 615,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 616,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": 892.3730385164051,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 617,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 9814,
            "run_time_ns_delta": 8757749,
            "type": "kprobe"
          },
          "618": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 618,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "619": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 619,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "620": {
            "avg_ns_per_run": 2181.6666666666665,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 620,
            "name": "trace_do_truncate",
            "run_cnt_delta": 501,
            "run_time_ns_delta": 1093015,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 163.18652641441943,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 621,
            "name": "trace_fd_install",
            "run_cnt_delta": 1579535,
            "run_time_ns_delta": 257758830,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": 312.9415874839682,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 622,
            "name": "trace_filp_close",
            "run_cnt_delta": 396867,
            "run_time_ns_delta": 124196189,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": 190.8776443682104,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 623,
            "name": "trace_file_update_time",
            "run_cnt_delta": 13992,
            "run_time_ns_delta": 2670760,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 824.6516580903374,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 624,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 13992,
            "run_time_ns_delta": 11538526,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 104.0250650271932,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 625,
            "name": "trace_file_modified",
            "run_cnt_delta": 177618,
            "run_time_ns_delta": 18476724,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 489.10771993829457,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 626,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 177618,
            "run_time_ns_delta": 86874335,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 627,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 628,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 629,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": 229.5,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 630,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 459,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": 3954.0,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 631,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7908,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": 7279.0,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 632,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 14558,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 633,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 4993.5,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 634,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9987,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 281.6192294381499,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 635,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 884186,
            "run_time_ns_delta": 249003780,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 636,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 637,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": 328.5365057606319,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 638,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 428946,
            "run_time_ns_delta": 140924420,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 639,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 640,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 50.99164137680596,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 641,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 616848,
            "run_time_ns_delta": 31454092,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 290.15168080305034,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 642,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 616848,
            "run_time_ns_delta": 178979484,
            "type": "kprobe"
          },
          "643": {
            "avg_ns_per_run": 767.8977431906615,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 643,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 115650,
            "run_time_ns_delta": 88807374,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": 203.46361885294235,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 644,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 1526340,
            "run_time_ns_delta": 310554660,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 235.47762068617436,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 645,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 3605964,
            "run_time_ns_delta": 849123823,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": 232.17478525340164,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 646,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 4659678,
            "run_time_ns_delta": 1081859739,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 258.3194562273025,
            "bytes_jited": 18427,
            "bytes_xlated": 29120,
            "id": 648,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 1075008,
            "run_time_ns_delta": 277695482,
            "type": "cgroup_skb"
          },
          "649": {
            "avg_ns_per_run": 246.8842282021183,
            "bytes_jited": 18427,
            "bytes_xlated": 29120,
            "id": 649,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 3308716,
            "run_time_ns_delta": 816869796,
            "type": "cgroup_skb"
          },
          "650": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 650,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "651": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 651,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "652": {
            "avg_ns_per_run": 121.5,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 652,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 243,
            "type": "kprobe"
          },
          "653": {
            "avg_ns_per_run": 1072.0,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 653,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2144,
            "type": "raw_tracepoint"
          },
          "654": {
            "avg_ns_per_run": 262.34329434297615,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 654,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 638021,
            "run_time_ns_delta": 167380531,
            "type": "lsm"
          },
          "655": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 655,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.1814727650000805,
            "ops_per_sec": 22770589.820903588,
            "ops_total": 117985191.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23884] setting to a 5 secs run per stressor\nstress-ng: info:  [23884] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 4 aio, 4 aiol, 4 hdd, 4 io, 4 iomix, 4 io-uring, 4 sync-file, 4 epoll, 4 netdev, 4 sctp, 4 sock, 4 sockdiag, 4 sockfd, 4 sockpair, 4 sockmany, 4 udp-flood\nstress-ng: info:  [23884] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [23927] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [23884] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23884]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23884] cap              637124      5.00      0.21      6.85    127338.56       90277.55\nstress-ng: metrc: [23884] eventfd          134585      5.00      0.15      3.14     26890.88       40968.97\nstress-ng: metrc: [23884] get                3911      5.00      0.11      2.34       781.97        1593.31\nstress-ng: metrc: [23884] prctl              4655      5.00      3.17      0.89       930.40        1147.04\nstress-ng: metrc: [23884] set               55232      5.00      0.20      6.52     11035.77        8219.82\nstress-ng: metrc: [23884] aio               21439      5.02      0.01      0.25      4267.02       79995.97\nstress-ng: metrc: [23884] aiol               3742      5.12      0.04      0.38       730.35        8951.10\nstress-ng: metrc: [23884] hdd               82708      5.02      1.13      1.50     16468.46       31367.28\nstress-ng: metrc: [23884] io                  120      5.02      0.01      0.05        23.91        1946.63\nstress-ng: metrc: [23884] iomix              4042      5.03      0.13      3.16       803.57        1225.09\nstress-ng: metrc: [23884] io-uring          32988      5.03      0.01      1.52      6554.22       21604.66\nstress-ng: metrc: [23884] sync-file           111      5.02      0.04      1.32        22.13          81.52\nstress-ng: metrc: [23884] epoll             31559      5.06      0.10      2.75      6237.82       11087.07\nstress-ng: metrc: [23884] netdev           207924      5.01      0.20      6.14     41505.42       32811.79\nstress-ng: metrc: [23884] sctp              49065      5.01      0.06      2.16      9799.15       22035.47\nstress-ng: metrc: [23884] sock               2164      5.01      0.08      3.81       431.91         557.13\nstress-ng: metrc: [23884] sockdiag      114953917      5.00      0.33      7.59  22968845.47    14510609.24\nstress-ng: metrc: [23884] sockfd           367870      5.03      0.06      4.12     73186.98       88007.26\nstress-ng: metrc: [23884] sockpair         155446      5.03      0.12      3.23     30924.07       46343.09\nstress-ng: metrc: [23884] sockmany         102642      5.01      0.09      6.22     20468.74       16276.28\nstress-ng: metrc: [23884] udp-flood       1133947      5.00      0.15      6.98    226789.11      159046.28\nstress-ng: info:  [23884] skipped: 0\nstress-ng: info:  [23884] passed: 84: cap (4) eventfd (4) get (4) prctl (4) set (4) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp-flood (4)\nstress-ng: info:  [23884] failed: 0\nstress-ng: info:  [23884] metrics untrustworthy: 0\nstress-ng: info:  [23884] successful run completed in 5.16 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
        ],
        "error": "prog 522: prog 522 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-480/pass-01-map_inline.report.json\" \"--prog-type\" \"raw_tracepoint\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-480/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-480/map-values.json\" \"--map-ids\" \"3696,3657,3654,3666,3699,3656,3673,3741,3698,3742,3711,3708,3714,3757,3717,3720,3732,3735,3669,3738,3692,3743,3755,3756\": error: map_values snapshot missing map 3757 key 00000000; prog 523: prog 523 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-490/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-490/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-490/map-values.json\" \"--map-ids\" \"3696,3657,3656,3666,3670,3671,3752,3676,3757,3692,3743,3699,3698,3742,3672,3755,3756\": error: map_values snapshot missing map 3757 key 00000000; prog 525: prog 525 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-513/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-513/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-513/map-values.json\" \"--map-ids\" \"3699,3696,3657,3654,3666,3698,3742,3656,3673,3741,3757,3682,3752,3672,3755,3756\": error: map_values snapshot missing map 3757 key 00000000; prog 526: prog 526 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-501/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-501/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-501/map-values.json\" \"--map-ids\" \"3699,3696,3657,3656,3666,3682,3752,3676,3757,3692,3743,3672,3698,3742,3755,3756\": error: map_values snapshot missing map 3757 key 00000000; prog 528: prog 528 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-505/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-505/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-505/map-values.json\" \"--map-ids\" \"3699,3696,3657,3656,3666,3682,3752,3757,3692,3743,3672,3698,3742,3755,3756\": error: map_values snapshot missing map 3757 key 00000000; prog 630: prog 630 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-474/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-474/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-474/map-values.json\" \"--map-ids\" \"3757,3696,3657,3654,3666,3699,3656,3673,3741,3711,3708,3714,3717,3720,3732,3735,3669,3738,3688,3756,3672,3755\": error: map_values snapshot missing map 3757 key 00000000; prog 639: prog 639 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-494/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-494/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-494/map-values.json\" \"--map-ids\" \"3680,3654,3753,3696,3657,3666,3699,3656,3673,3741,3711,3708,3714,3717,3720,3732,3735,3669,3738,3757,3698,3742,3754,3691,3756,3692,3743,3755\": error: map_values snapshot missing map 3757 key 00000000",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 522 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-480/pass-01-map_inline.report.json\" \"--prog-type\" \"raw_tracepoint\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-480/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-480/map-values.json\" \"--map-ids\" \"3696,3657,3654,3666,3699,3656,3673,3741,3698,3742,3711,3708,3714,3757,3717,3720,3732,3735,3669,3738,3692,3743,3755,3756\": error: map_values snapshot missing map 3757 key 00000000",
            "exit_code": 1,
            "prog_id": 522
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 523 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-490/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-490/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-490/map-values.json\" \"--map-ids\" \"3696,3657,3656,3666,3670,3671,3752,3676,3757,3692,3743,3699,3698,3742,3672,3755,3756\": error: map_values snapshot missing map 3757 key 00000000",
            "exit_code": 1,
            "prog_id": 523
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 525 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-513/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-513/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-513/map-values.json\" \"--map-ids\" \"3699,3696,3657,3654,3666,3698,3742,3656,3673,3741,3757,3682,3752,3672,3755,3756\": error: map_values snapshot missing map 3757 key 00000000",
            "exit_code": 1,
            "prog_id": 525
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 526 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-501/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-501/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-501/map-values.json\" \"--map-ids\" \"3699,3696,3657,3656,3666,3682,3752,3676,3757,3692,3743,3672,3698,3742,3755,3756\": error: map_values snapshot missing map 3757 key 00000000",
            "exit_code": 1,
            "prog_id": 526
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 528 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-505/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-505/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-505/map-values.json\" \"--map-ids\" \"3699,3696,3657,3656,3666,3682,3752,3757,3692,3743,3672,3698,3742,3755,3756\": error: map_values snapshot missing map 3757 key 00000000",
            "exit_code": 1,
            "prog_id": 528
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 630 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-474/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-474/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-474/map-values.json\" \"--map-ids\" \"3757,3696,3657,3654,3666,3699,3656,3673,3741,3711,3708,3714,3717,3720,3732,3735,3669,3738,3688,3756,3672,3755\": error: map_values snapshot missing map 3757 key 00000000",
            "exit_code": 1,
            "prog_id": 630
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 639 pass map_inline failed after 1 committed passes: bpfopt pass map_inline failed: bpfopt pass failed (returncode 1, status exit status: 1): subprocess \"bpfopt\" \"--pass\" \"map_inline\" \"--report\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-494/pass-01-map_inline.report.json\" \"--prog-type\" \"kprobe\" \"--verifier-states\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-494/verifier-states.json\" \"--map-values\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.corpus.54cc8c67/bpfrejit-daemon-optimize-1858-494/map-values.json\" \"--map-ids\" \"3680,3654,3753,3696,3657,3666,3699,3656,3673,3741,3711,3708,3714,3717,3720,3732,3735,3669,3738,3757,3698,3742,3754,3691,3756,3692,3743,3755\": error: map_values snapshot missing map 3757 key 00000000",
            "exit_code": 1,
            "prog_id": 639
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 151,
          "not_applied": 7,
          "requested": 158
        }
      },
      "runner": "tracee",
      "selected_workload": "stress_ng_os_io_network",
      "status": "ok"
    },
    {
      "app": "bpftrace/capable",
      "baseline": {
        "bpf": {
          "661": {
            "avg_ns_per_run": 331.67867981673163,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 661,
            "name": "cap_capable",
            "run_cnt_delta": 2261383,
            "run_time_ns_delta": 750052528,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0409460199998648,
            "ops_per_sec": 5430093.291485695,
            "ops_total": 5652434.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [4239] setting to a 1 secs run per stressor\nstress-ng: info:  [4239] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set\nstress-ng: info:  [4239] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4239] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4239]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4239] cap             4429850      1.00      0.77      3.23   4429825.44     1107604.55\nstress-ng: metrc: [4239] eventfd         1067841      1.00      0.48      2.85   1067707.04      321199.33\nstress-ng: metrc: [4239] get                3685      1.00      0.08      0.54      3682.62        5948.50\nstress-ng: metrc: [4239] prctl              8442      1.02      1.53      1.26      8313.78        3026.26\nstress-ng: metrc: [4239] set              142616      1.00      0.69      2.54    142274.87       44195.07\nstress-ng: info:  [4239] skipped: 0\nstress-ng: info:  [4239] passed: 20: cap (4) eventfd (4) get (4) prctl (4) set (4)\nstress-ng: info:  [4239] failed: 0\nstress-ng: info:  [4239] metrics untrustworthy: 0\nstress-ng: info:  [4239] successful run completed in 1.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "661": {
            "avg_ns_per_run": 321.59251140268464,
            "bytes_jited": 697,
            "bytes_xlated": 1216,
            "id": 661,
            "name": "cap_capable",
            "run_cnt_delta": 2347035,
            "run_time_ns_delta": 754788880,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0146274979999816,
            "ops_per_sec": 5636647.943480143,
            "ops_total": 5719098.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [21744] setting to a 1 secs run per stressor\nstress-ng: info:  [21744] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set\nstress-ng: info:  [21744] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21744] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21744]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21744] cap             4340161      1.00      1.02      2.89   4340154.79     1111177.08\nstress-ng: metrc: [21744] eventfd         1213546      1.00      0.46      3.08   1213243.07      342565.84\nstress-ng: metrc: [21744] get                2738      1.00      0.05      0.57      2736.44        4426.99\nstress-ng: metrc: [21744] prctl              7858      1.00      1.42      1.12      7856.59        3096.76\nstress-ng: metrc: [21744] set              154795      1.00      0.61      2.83    154793.27       45054.93\nstress-ng: info:  [21744] skipped: 0\nstress-ng: info:  [21744] passed: 20: cap (4) eventfd (4) get (4) prctl (4) set (4)\nstress-ng: info:  [21744] failed: 0\nstress-ng: info:  [21744] metrics untrustworthy: 0\nstress-ng: info:  [21744] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
          "668": {
            "avg_ns_per_run": 387.69849119730316,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 668,
            "name": "block_io_start",
            "run_cnt_delta": 1422121,
            "run_time_ns_delta": 551354166,
            "type": "tracepoint"
          },
          "669": {
            "avg_ns_per_run": 776.5563497443283,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 669,
            "name": "block_io_done",
            "run_cnt_delta": 1422136,
            "run_time_ns_delta": 1104368741,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.365274143000079,
            "ops_per_sec": 354406.8670714282,
            "ops_total": 1901490.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.128297,\n        \"1000\" : 12.892243\n      },\n      \"latency_us\" : {\n        \"2\" : 34.695572,\n        \"4\" : 1.725433,\n        \"10\" : 9.766187,\n        \"20\" : 35.697954,\n        \"50\" : 2.796866,\n        \"100\" : 1.930707,\n        \"250\" : 0.349843,\n        \"500\" : 0.016689,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "668": {
            "avg_ns_per_run": 396.39755719637725,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 668,
            "name": "block_io_start",
            "run_cnt_delta": 1374650,
            "run_time_ns_delta": 544907902,
            "type": "tracepoint"
          },
          "669": {
            "avg_ns_per_run": 791.1940523691227,
            "bytes_jited": 883,
            "bytes_xlated": 1480,
            "id": 669,
            "name": "block_io_done",
            "run_cnt_delta": 1374665,
            "run_time_ns_delta": 1087626772,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.352367979000064,
            "ops_per_sec": 343588.11038690316,
            "ops_total": 1839010.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.094913,\n        \"1000\" : 11.149231\n      },\n      \"latency_us\" : {\n        \"2\" : 36.131381,\n        \"4\" : 2.013636,\n        \"10\" : 9.184575,\n        \"20\" : 36.269396,\n        \"50\" : 2.644938,\n        \"100\" : 2.035841,\n        \"250\" : 0.451925,\n        \"500\" : 0.021769,\n        \"750\" : 0.010000,\n        \"1000\" : 0.010000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.010000,\n        \"4\" : 0.010000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
          "676": {
            "avg_ns_per_run": 1827.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 676,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1827,
            "type": "perf_event"
          },
          "677": {
            "avg_ns_per_run": 34.06883758890778,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 677,
            "name": "vfs_create",
            "run_cnt_delta": 1933464,
            "run_time_ns_delta": 65870871,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.242339129000129,
            "ops_per_sec": 2421040.221457669,
            "ops_total": 3007753.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15123] setting to a 1 secs run per stressor\nstress-ng: info:  [15123] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime\nstress-ng: info:  [15123] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [15213] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [15140] dentry: 155058 dentries allocated\nstress-ng: metrc: [15123] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15123]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15123] access            14354      1.03      0.24      1.59     13875.34        7838.43\nstress-ng: metrc: [15123] chdir                23      1.17      0.10      1.32        19.65          16.20\nstress-ng: metrc: [15123] chmod               106      1.02      0.01      0.05       103.43        1968.50\nstress-ng: metrc: [15123] chown               127      1.02      0.01      0.01       124.40        9356.81\nstress-ng: metrc: [15123] dentry             8192      1.16      0.04      0.19      7039.01       36205.65\nstress-ng: metrc: [15123] dir               22338      1.18      0.11      1.74     18996.10       12084.43\nstress-ng: metrc: [15123] dirmany           14399      1.02      0.00      0.33     14132.44       44134.60\nstress-ng: metrc: [15123] fallocate             1      1.02      0.01      0.00         0.98         112.78\nstress-ng: metrc: [15123] file-ioctl        76751      1.02      0.11      0.85     75604.74       79925.06\nstress-ng: metrc: [15123] filename           3610      1.02      0.02      0.72      3544.48        4887.72\nstress-ng: metrc: [15123] flock           2337266      1.02      0.36      0.56   2301204.21     2541000.91\nstress-ng: metrc: [15123] fpunch              103      1.03      0.05      0.29        99.96         310.76\nstress-ng: metrc: [15123] fstat              3633      1.00      0.31      1.12      3630.60        2547.55\nstress-ng: metrc: [15123] getdent          360822      1.00      0.18      2.08    360386.93      159491.39\nstress-ng: metrc: [15123] hdd               22761      1.05      0.26      0.35     21752.81       37029.93\nstress-ng: metrc: [15123] inotify               4      1.04      0.01      0.00         3.86         729.00\nstress-ng: metrc: [15123] open               4096      1.13      0.03      0.03      3622.80       65978.32\nstress-ng: metrc: [15123] rename            36739      1.01      0.00      0.28     36198.51      129758.35\nstress-ng: metrc: [15123] touch             45580      1.13      0.05      1.16     40511.60       37716.11\nstress-ng: metrc: [15123] utime             56848      1.01      0.08      0.96     56340.48       54758.00\nstress-ng: info:  [15123] skipped: 0\nstress-ng: info:  [15123] passed: 80: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4)\nstress-ng: info:  [15123] failed: 0\nstress-ng: info:  [15123] metrics untrustworthy: 0\nstress-ng: info:  [15123] successful run completed in 1.23 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "676": {
            "avg_ns_per_run": 1796.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 676,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1796,
            "type": "perf_event"
          },
          "677": {
            "avg_ns_per_run": 33.294011769227964,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 677,
            "name": "vfs_create",
            "run_cnt_delta": 2000641,
            "run_time_ns_delta": 66609365,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2287985089999438,
            "ops_per_sec": 2006784.6615527696,
            "ops_total": 2465934.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [17486] setting to a 1 secs run per stressor\nstress-ng: info:  [17486] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime\nstress-ng: info:  [17486] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [17574] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [17504] dentry: 167724 dentries allocated\nstress-ng: metrc: [17486] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17486]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17486] access            15521      1.02      0.28      1.78     15147.10        7509.15\nstress-ng: metrc: [17486] chdir                53      1.15      0.12      1.72        46.28          28.78\nstress-ng: metrc: [17486] chmod               106      1.02      0.02      0.03       104.23        2153.16\nstress-ng: metrc: [17486] chown               101      1.03      0.00      0.02        98.25        5027.88\nstress-ng: metrc: [17486] dentry            12288      1.12      0.01      0.37     11008.19       32541.34\nstress-ng: metrc: [17486] dir               23710      1.18      0.08      1.63     20171.39       13864.75\nstress-ng: metrc: [17486] dirmany           15274      1.02      0.01      0.34     14983.67       43029.84\nstress-ng: metrc: [17486] fallocate             0      1.03      0.01      0.00         0.00           0.00\nstress-ng: metrc: [17486] file-ioctl        88080      1.02      0.09      0.95     86469.35       84666.42\nstress-ng: metrc: [17486] filename           4745      1.01      0.06      1.00      4676.76        4480.01\nstress-ng: metrc: [17486] flock           1818272      1.01      0.21      0.46   1806696.99     2731023.88\nstress-ng: metrc: [17486] fpunch              155      1.03      0.02      0.39       150.29         376.02\nstress-ng: metrc: [17486] fstat              4204      1.00      0.17      0.90      4202.67        3923.44\nstress-ng: metrc: [17486] getdent          355477      1.00      0.14      2.14    355468.33      156512.78\nstress-ng: metrc: [17486] hdd               14184      1.02      0.22      0.23     13949.03       31938.90\nstress-ng: metrc: [17486] inotify               4      1.04      0.00      0.00         3.85         610.87\nstress-ng: metrc: [17486] open               4096      1.12      0.03      0.04      3656.29       56088.08\nstress-ng: metrc: [17486] rename            31571      1.01      0.01      0.21     31364.52      144242.15\nstress-ng: metrc: [17486] touch             51419      1.11      0.01      1.23     46328.78       41463.66\nstress-ng: metrc: [17486] utime             26674      1.01      0.03      0.48     26403.63       53136.62\nstress-ng: info:  [17486] skipped: 0\nstress-ng: info:  [17486] passed: 80: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4)\nstress-ng: info:  [17486] failed: 0\nstress-ng: info:  [17486] metrics untrustworthy: 0\nstress-ng: info:  [17486] successful run completed in 1.22 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
          "684": {
            "avg_ns_per_run": 74.04267460031846,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 684,
            "name": "sched_wakeup",
            "run_cnt_delta": 2028490,
            "run_time_ns_delta": 150194825,
            "type": "tracepoint"
          },
          "685": {
            "avg_ns_per_run": 316.4871794871795,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 685,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 24686,
            "type": "tracepoint"
          },
          "686": {
            "avg_ns_per_run": 141.43596811090694,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 686,
            "name": "sched_switch",
            "run_cnt_delta": 12918649,
            "run_time_ns_delta": 1827161628,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0202998160000334,
            "ops_per_sec": 12524373.521987954,
            "ops_total": 12778616.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [2419] setting to a 1 secs run per stressor\nstress-ng: info:  [2419] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [2419] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2419] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2419]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2419] futex           1354836      2.00      0.26      5.42    677335.42      238395.76\nstress-ng: metrc: [2419] sem             2159532      1.00      0.54      1.21   2159079.78     1234450.70\nstress-ng: metrc: [2419] sem-sysv         179232      1.00      0.08      0.37    179086.71      393289.81\nstress-ng: metrc: [2419] switch           844094      1.00      0.28      1.89    843826.32      387729.45\nstress-ng: metrc: [2419] yield           8240922      1.00      2.33      5.17   8231098.97     1098897.73\nstress-ng: info:  [2419] skipped: 0\nstress-ng: info:  [2419] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [2419] failed: 0\nstress-ng: info:  [2419] metrics untrustworthy: 0\nstress-ng: info:  [2419] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "684": {
            "avg_ns_per_run": 69.18058619464318,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 684,
            "name": "sched_wakeup",
            "run_cnt_delta": 3638689,
            "run_time_ns_delta": 251726638,
            "type": "tracepoint"
          },
          "685": {
            "avg_ns_per_run": 267.64102564102564,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 685,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 20876,
            "type": "tracepoint"
          },
          "686": {
            "avg_ns_per_run": 118.34100255966224,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 686,
            "name": "sched_switch",
            "run_cnt_delta": 10416218,
            "run_time_ns_delta": 1232665681,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0179338850000477,
            "ops_per_sec": 17968163.030548044,
            "ops_total": 18290402.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [2598] setting to a 1 secs run per stressor\nstress-ng: info:  [2598] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [2598] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2598] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2598]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2598] futex           1227366      2.00      0.34      5.33    613613.40      216302.82\nstress-ng: metrc: [2598] sem             6516198      1.00      0.66      1.81   6514783.77     2635565.30\nstress-ng: metrc: [2598] sem-sysv         419727      1.00      0.20      0.75    419416.01      443657.44\nstress-ng: metrc: [2598] switch          1479967      1.00      0.21      3.15   1479744.30      440345.67\nstress-ng: metrc: [2598] yield           8647144      1.00      1.57      3.44   8637213.16     1724923.99\nstress-ng: info:  [2598] skipped: 0\nstress-ng: info:  [2598] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [2598] failed: 0\nstress-ng: info:  [2598] metrics untrustworthy: 0\nstress-ng: info:  [2598] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
          "694": {
            "avg_ns_per_run": 439.60515954533,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 694,
            "name": "tcp_set_state",
            "run_cnt_delta": 58416,
            "run_time_ns_delta": 25679975,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1029197569998814,
            "ops_per_sec": 6046.677428411246,
            "ops_total": 6669.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.86ms  289.34us   3.54ms   76.54%\n    Req/Sec     3.20k     1.23k    6.10k    80.95%\n  6669 requests in 1.10s, 0.99MB read\n  Socket errors: connect 0, read 6667, write 0, timeout 0\nRequests/sec:   6063.40\nTransfer/sec:      0.90MB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "694": {
            "avg_ns_per_run": 442.2191174505612,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 694,
            "name": "tcp_set_state",
            "run_cnt_delta": 59872,
            "run_time_ns_delta": 26476543,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1022115630000826,
            "ops_per_sec": 6202.076107234131,
            "ops_total": 6836.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.86ms  273.74us   2.87ms   76.61%\n    Req/Sec     3.12k     2.09k    5.57k    54.55%\n  6836 requests in 1.10s, 1.01MB read\n  Socket errors: connect 0, read 6835, write 0, timeout 0\nRequests/sec:   6217.34\nTransfer/sec:      0.92MB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
      "selected_workload": "tcp_connect",
      "status": "ok"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline": {
        "bpf": {
          "701": {
            "avg_ns_per_run": 3434.0862068965516,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 701,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 116,
            "run_time_ns_delta": 398354,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.071609674000001,
            "ops_per_sec": 107.26377520511052,
            "ops_total": 544.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   351.71ms  331.72ms   1.98s    87.87%\n    Req/Sec    30.69     16.19    80.00     63.69%\n  544 requests in 5.01s, 86.25KB read\n  Socket errors: connect 0, read 0, write 0, timeout 11\nRequests/sec:    108.56\nTransfer/sec:     17.21KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "701": {
            "avg_ns_per_run": 4293.089430894309,
            "bytes_jited": 928,
            "bytes_xlated": 1568,
            "id": 701,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 123,
            "run_time_ns_delta": 528050,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 6.0961365489999935,
            "ops_per_sec": 94.65011083038334,
            "ops_total": 577.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   328.61ms  295.56ms   1.84s    84.64%\n    Req/Sec    32.52     16.94    80.00     57.65%\n  577 requests in 5.01s, 91.25KB read\n  Socket errors: connect 0, read 0, write 0, timeout 14\nRequests/sec:    115.08\nTransfer/sec:     18.20KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem",
          "map_inline"
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
      "selected_workload": "network_lossy_multi",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 74,
    "per_program_geomean": 1.0251215766901183,
    "program_count": 149,
    "wins": 75
  },
  "workload_seconds": 1.0
}
```
