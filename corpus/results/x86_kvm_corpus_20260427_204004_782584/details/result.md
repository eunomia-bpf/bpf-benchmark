# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-27T20:51:48.443324+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-27T20:40:04.812577+00:00",
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
      "invoked_at": "2026-04-27T20:40:04.812519+00:00",
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
        "captured_at": "2026-04-27T20:40:04.812513+00:00",
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
      "captured_at": "2026-04-27T20:40:04.805769+00:00",
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
  "per_program": [
    {
      "app": "bcc/capable",
      "baseline_avg_ns_per_run": 89.15524728752875,
      "baseline_run_cnt_delta": 146914,
      "baseline_run_time_ns_delta": 13098154,
      "post_rejit_avg_ns_per_run": 77.82634697071317,
      "post_rejit_run_cnt_delta": 143136,
      "post_rejit_run_time_ns_delta": 11139752,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 0.8729306388408135,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 1853.1267723102585,
      "baseline_run_cnt_delta": 1199,
      "baseline_run_time_ns_delta": 2221899,
      "post_rejit_avg_ns_per_run": 1935.9398359161348,
      "post_rejit_run_cnt_delta": 1097,
      "post_rejit_run_time_ns_delta": 2123726,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 1.0446882883800954,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 1291.312252964427,
      "baseline_run_cnt_delta": 1012,
      "baseline_run_time_ns_delta": 1306808,
      "post_rejit_avg_ns_per_run": 1655.3639661426844,
      "post_rejit_run_cnt_delta": 827,
      "post_rejit_run_time_ns_delta": 1368986,
      "program": "do_ret_sys_exec",
      "program_id": 10,
      "ratio": 1.281923843239708,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 57.62550754499727,
      "baseline_run_cnt_delta": 33002,
      "baseline_run_time_ns_delta": 1901757,
      "post_rejit_avg_ns_per_run": 65.04307624568871,
      "post_rejit_run_cnt_delta": 27254,
      "post_rejit_run_time_ns_delta": 1772684,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 1.1287202320066227,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 644.9567904975456,
      "baseline_run_cnt_delta": 16501,
      "baseline_run_time_ns_delta": 10642432,
      "post_rejit_avg_ns_per_run": 724.9509062889852,
      "post_rejit_run_cnt_delta": 13627,
      "post_rejit_run_time_ns_delta": 9878906,
      "program": "bindsnoop_v4_re",
      "program_id": 14,
      "ratio": 1.1240301939138106,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 642.1478698260712,
      "baseline_run_cnt_delta": 16501,
      "baseline_run_time_ns_delta": 10596082,
      "post_rejit_avg_ns_per_run": 713.7269391648932,
      "post_rejit_run_cnt_delta": 13627,
      "post_rejit_run_time_ns_delta": 9725957,
      "program": "bindsnoop_v6_re",
      "program_id": 15,
      "ratio": 1.1114682033566654,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 139.20854529752296,
      "baseline_run_cnt_delta": 327689,
      "baseline_run_time_ns_delta": 45617109,
      "post_rejit_avg_ns_per_run": 183.98109618397228,
      "post_rejit_run_cnt_delta": 294914,
      "post_rejit_run_time_ns_delta": 54258601,
      "program": "trace_pid_start",
      "program_id": 18,
      "ratio": 1.3216221446087189,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 160.07522681566974,
      "baseline_run_cnt_delta": 327689,
      "baseline_run_time_ns_delta": 52454891,
      "post_rejit_avg_ns_per_run": 206.4856501512295,
      "post_rejit_run_cnt_delta": 294916,
      "post_rejit_run_time_ns_delta": 60895922,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 1.2899288307053434,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "block_io"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 374.09161318673273,
      "baseline_run_cnt_delta": 327693,
      "baseline_run_time_ns_delta": 122587203,
      "post_rejit_avg_ns_per_run": 418.87909140537846,
      "post_rejit_run_cnt_delta": 294917,
      "post_rejit_run_time_ns_delta": 123534565,
      "program": "trace_req_compl",
      "program_id": 20,
      "ratio": 1.119723288734328,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 38.025782688766114,
      "baseline_run_cnt_delta": 543,
      "baseline_run_time_ns_delta": 20648,
      "post_rejit_avg_ns_per_run": 41.43560606060606,
      "post_rejit_run_cnt_delta": 528,
      "post_rejit_run_time_ns_delta": 21878,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 1.0896713527174104,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 27.337440281619312,
      "baseline_run_cnt_delta": 7954,
      "baseline_run_time_ns_delta": 217442,
      "post_rejit_avg_ns_per_run": 34.32895082829345,
      "post_rejit_run_cnt_delta": 3803,
      "post_rejit_run_time_ns_delta": 130553,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.2557485439254887,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 26.61536670547148,
      "baseline_run_cnt_delta": 12885,
      "baseline_run_time_ns_delta": 342939,
      "post_rejit_avg_ns_per_run": 25.83262599469496,
      "post_rejit_run_cnt_delta": 11310,
      "post_rejit_run_time_ns_delta": 292167,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 0.9705906471461239,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 1144.0676037483267,
      "baseline_run_cnt_delta": 1494,
      "baseline_run_time_ns_delta": 1709237,
      "post_rejit_avg_ns_per_run": 1291.8303867403315,
      "post_rejit_run_cnt_delta": 1810,
      "post_rejit_run_time_ns_delta": 2338213,
      "program": "__x64_sys_opena",
      "program_id": 31,
      "ratio": 1.1291556394988262,
      "runner": "bcc",
      "type": "tracing",
      "workload": "open_family_storm"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 1187.7358490566037,
      "baseline_run_cnt_delta": 477,
      "baseline_run_time_ns_delta": 566550,
      "post_rejit_avg_ns_per_run": 1384.2170542635658,
      "post_rejit_run_cnt_delta": 645,
      "post_rejit_run_time_ns_delta": 892820,
      "program": "__x64_sys_opena",
      "program_id": 32,
      "ratio": 1.165425002001096,
      "runner": "bcc",
      "type": "tracing",
      "workload": "open_family_storm"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 61.4675109817412,
      "baseline_run_cnt_delta": 944750,
      "baseline_run_time_ns_delta": 58071431,
      "post_rejit_avg_ns_per_run": 70.49441029925617,
      "post_rejit_run_cnt_delta": 886899,
      "post_rejit_run_time_ns_delta": 62521422,
      "program": "raw_syscalls__s",
      "program_id": 35,
      "ratio": 1.1468564315252068,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "file_open_storm"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 61.55168234498366,
      "baseline_run_cnt_delta": 944723,
      "baseline_run_time_ns_delta": 58149290,
      "post_rejit_avg_ns_per_run": 60.9642990437123,
      "post_rejit_run_cnt_delta": 886867,
      "post_rejit_run_time_ns_delta": 54067225,
      "program": "raw_syscalls__s",
      "program_id": 36,
      "ratio": 0.9904570715390165,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "file_open_storm"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 685.36,
      "baseline_run_cnt_delta": 75,
      "baseline_run_time_ns_delta": 51402,
      "post_rejit_avg_ns_per_run": 740.2142857142857,
      "post_rejit_run_cnt_delta": 70,
      "post_rejit_run_time_ns_delta": 51815,
      "program": "trace_connect_e",
      "program_id": 39,
      "ratio": 1.080037185879371,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4101.184210526316,
      "baseline_run_cnt_delta": 38,
      "baseline_run_time_ns_delta": 155845,
      "post_rejit_avg_ns_per_run": 4994.657142857143,
      "post_rejit_run_cnt_delta": 35,
      "post_rejit_run_time_ns_delta": 174813,
      "program": "trace_connect_v",
      "program_id": 40,
      "ratio": 1.2178573032729407,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 3731.945945945946,
      "baseline_run_cnt_delta": 37,
      "baseline_run_time_ns_delta": 138082,
      "post_rejit_avg_ns_per_run": 4656.914285714286,
      "post_rejit_run_cnt_delta": 35,
      "post_rejit_run_time_ns_delta": 162992,
      "program": "trace_connect_v",
      "program_id": 41,
      "ratio": 1.2478514836939543,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 640.0189573459716,
      "baseline_run_cnt_delta": 844,
      "baseline_run_time_ns_delta": 540176,
      "post_rejit_avg_ns_per_run": 769.4987341772152,
      "post_rejit_run_cnt_delta": 790,
      "post_rejit_run_time_ns_delta": 607904,
      "program": "sock__inet_sock",
      "program_id": 44,
      "ratio": 1.2023061588178106,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "network"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 166.17432443861802,
      "baseline_run_cnt_delta": 94588,
      "baseline_run_time_ns_delta": 15718097,
      "post_rejit_avg_ns_per_run": 173.8952323798093,
      "post_rejit_run_cnt_delta": 74985,
      "post_rejit_run_time_ns_delta": 13039534,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 1.0464627009453753,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 106.93092506330697,
      "baseline_run_cnt_delta": 63974,
      "baseline_run_time_ns_delta": 6840799,
      "post_rejit_avg_ns_per_run": 116.6100971651808,
      "post_rejit_run_cnt_delta": 49915,
      "post_rejit_run_time_ns_delta": 5820593,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 1.0905179871598736,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 245.8143153526971,
      "baseline_run_cnt_delta": 3856,
      "baseline_run_time_ns_delta": 947860,
      "post_rejit_avg_ns_per_run": 252.47652125590443,
      "post_rejit_run_cnt_delta": 3599,
      "post_rejit_run_time_ns_delta": 908663,
      "program": "sched_wakeup_ne",
      "program_id": 49,
      "ratio": 1.0271025952807034,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 417.7929634641407,
      "baseline_run_cnt_delta": 1478,
      "baseline_run_time_ns_delta": 617498,
      "post_rejit_avg_ns_per_run": 445.25144927536235,
      "post_rejit_run_cnt_delta": 1380,
      "post_rejit_run_time_ns_delta": 614447,
      "program": "tracepoint__sch",
      "program_id": 131,
      "ratio": 1.0657227100800093,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "exec_storm"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 11914.837837837838,
      "baseline_run_cnt_delta": 74,
      "baseline_run_time_ns_delta": 881698,
      "post_rejit_avg_ns_per_run": 12226.591549295774,
      "post_rejit_run_cnt_delta": 71,
      "post_rejit_run_time_ns_delta": 868088,
      "program": "native_tracer_e",
      "program_id": 132,
      "ratio": 1.026165166131586,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "exec_storm"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 521.5529315960912,
      "baseline_run_cnt_delta": 1228,
      "baseline_run_time_ns_delta": 640467,
      "post_rejit_avg_ns_per_run": 524.3860232945092,
      "post_rejit_run_cnt_delta": 1202,
      "post_rejit_run_time_ns_delta": 630312,
      "program": "event_exit_acct",
      "program_id": 275,
      "ratio": 1.005432031011211,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 724.7833954230974,
      "baseline_run_cnt_delta": 1879,
      "baseline_run_time_ns_delta": 1361868,
      "post_rejit_avg_ns_per_run": 762.9391929242676,
      "post_rejit_run_cnt_delta": 1809,
      "post_rejit_run_time_ns_delta": 1380157,
      "program": "event_wake_up_n",
      "program_id": 277,
      "ratio": 1.05264441451352,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2849.0556722689075,
      "baseline_run_cnt_delta": 952,
      "baseline_run_time_ns_delta": 2712301,
      "post_rejit_avg_ns_per_run": 2876.2953586497893,
      "post_rejit_run_cnt_delta": 948,
      "post_rejit_run_time_ns_delta": 2726728,
      "program": "event_execve",
      "program_id": 279,
      "ratio": 1.0095609526503877,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 270.2279411764706,
      "baseline_run_cnt_delta": 952,
      "baseline_run_time_ns_delta": 257257,
      "post_rejit_avg_ns_per_run": 307.55696202531647,
      "post_rejit_run_cnt_delta": 948,
      "post_rejit_run_time_ns_delta": 291564,
      "program": "tg_kp_bprm_comm",
      "program_id": 281,
      "ratio": 1.1381390121477792,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 608.7472474868358,
      "baseline_run_cnt_delta": 2089,
      "baseline_run_time_ns_delta": 1271673,
      "post_rejit_avg_ns_per_run": 878.501269035533,
      "post_rejit_run_cnt_delta": 1576,
      "post_rejit_run_time_ns_delta": 1384518,
      "program": "generic_kprobe_",
      "program_id": 312,
      "ratio": 1.4431297597851245,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 540.2637625658209,
      "baseline_run_cnt_delta": 2089,
      "baseline_run_time_ns_delta": 1128611,
      "post_rejit_avg_ns_per_run": 703.0374365482234,
      "post_rejit_run_cnt_delta": 1576,
      "post_rejit_run_time_ns_delta": 1107987,
      "program": "generic_retkprobe_event",
      "program_id": 316,
      "ratio": 1.3012855669041314,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 538.4140504374678,
      "baseline_run_cnt_delta": 3886,
      "baseline_run_time_ns_delta": 2092277,
      "post_rejit_avg_ns_per_run": 722.0069352708058,
      "post_rejit_run_cnt_delta": 3028,
      "post_rejit_run_time_ns_delta": 2186237,
      "program": "generic_kprobe_",
      "program_id": 323,
      "ratio": 1.3409882871447478,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 492.4947346770876,
      "baseline_run_cnt_delta": 24310,
      "baseline_run_time_ns_delta": 11972547,
      "post_rejit_avg_ns_per_run": 494.4085870329314,
      "post_rejit_run_cnt_delta": 18493,
      "post_rejit_run_time_ns_delta": 9143098,
      "program": "generic_kprobe_",
      "program_id": 325,
      "ratio": 1.0038860361768105,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 624.7510770703686,
      "baseline_run_cnt_delta": 2089,
      "baseline_run_time_ns_delta": 1305105,
      "post_rejit_avg_ns_per_run": 902.1643401015228,
      "post_rejit_run_cnt_delta": 1576,
      "post_rejit_run_time_ns_delta": 1421811,
      "program": "generic_kprobe_",
      "program_id": 332,
      "ratio": 1.4440380708617935,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 589.6807084729536,
      "baseline_run_cnt_delta": 2089,
      "baseline_run_time_ns_delta": 1231843,
      "post_rejit_avg_ns_per_run": 736.8565989847716,
      "post_rejit_run_cnt_delta": 1576,
      "post_rejit_run_time_ns_delta": 1161286,
      "program": "generic_retkprobe_event",
      "program_id": 341,
      "ratio": 1.2495857307134008,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 532.4691199176531,
      "baseline_run_cnt_delta": 3886,
      "baseline_run_time_ns_delta": 2069175,
      "post_rejit_avg_ns_per_run": 799.5934610303831,
      "post_rejit_run_cnt_delta": 3028,
      "post_rejit_run_time_ns_delta": 2421169,
      "program": "generic_kprobe_",
      "program_id": 343,
      "ratio": 1.501671047429081,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 535.5973993909967,
      "baseline_run_cnt_delta": 12151,
      "baseline_run_time_ns_delta": 6508044,
      "post_rejit_avg_ns_per_run": 561.9164504971898,
      "post_rejit_run_cnt_delta": 9252,
      "post_rejit_run_time_ns_delta": 5198851,
      "program": "generic_kprobe_",
      "program_id": 349,
      "ratio": 1.0491396170633378,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 563.5273264401773,
      "baseline_run_cnt_delta": 12863,
      "baseline_run_time_ns_delta": 7248652,
      "post_rejit_avg_ns_per_run": 596.2379606365159,
      "post_rejit_run_cnt_delta": 9552,
      "post_rejit_run_time_ns_delta": 5695265,
      "program": "generic_kprobe_",
      "program_id": 361,
      "ratio": 1.0580462253764569,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 254.4952346373786,
      "baseline_run_cnt_delta": 44068,
      "baseline_run_time_ns_delta": 11215096,
      "post_rejit_avg_ns_per_run": 271.02074179069217,
      "post_rejit_run_cnt_delta": 42330,
      "post_rejit_run_time_ns_delta": 11472308,
      "program": "generic_kprobe_",
      "program_id": 382,
      "ratio": 1.064934446324153,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 475.63436318184733,
      "baseline_run_cnt_delta": 156010,
      "baseline_run_time_ns_delta": 74203717,
      "post_rejit_avg_ns_per_run": 498.19432620273807,
      "post_rejit_run_cnt_delta": 147767,
      "post_rejit_run_time_ns_delta": 73616681,
      "program": "generic_kprobe_",
      "program_id": 385,
      "ratio": 1.0474313144028777,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 39.073648380107436,
      "baseline_run_cnt_delta": 155998,
      "baseline_run_time_ns_delta": 6095411,
      "post_rejit_avg_ns_per_run": 40.30818307905687,
      "post_rejit_run_cnt_delta": 147805,
      "post_rejit_run_time_ns_delta": 5957751,
      "program": "generic_retkprobe_event",
      "program_id": 392,
      "ratio": 1.0315950711062327,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 982.157948531043,
      "baseline_run_cnt_delta": 126212,
      "baseline_run_time_ns_delta": 123960119,
      "post_rejit_avg_ns_per_run": 987.8090735434575,
      "post_rejit_run_cnt_delta": 125640,
      "post_rejit_run_time_ns_delta": 124108332,
      "program": "generic_kprobe_",
      "program_id": 397,
      "ratio": 1.0057537843285458,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 50.62639844071879,
      "baseline_run_cnt_delta": 126212,
      "baseline_run_time_ns_delta": 6389659,
      "post_rejit_avg_ns_per_run": 51.31848137535817,
      "post_rejit_run_cnt_delta": 125640,
      "post_rejit_run_time_ns_delta": 6447654,
      "program": "generic_retkprobe_event",
      "program_id": 403,
      "ratio": 1.0136703963930949,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1531.5126050420167,
      "baseline_run_cnt_delta": 952,
      "baseline_run_time_ns_delta": 1458000,
      "post_rejit_avg_ns_per_run": 1656.159282700422,
      "post_rejit_run_cnt_delta": 948,
      "post_rejit_run_time_ns_delta": 1570039,
      "program": "generic_kprobe_",
      "program_id": 455,
      "ratio": 1.0813879541363525,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 380.01965553074353,
      "baseline_run_cnt_delta": 814122,
      "baseline_run_time_ns_delta": 309382362,
      "post_rejit_avg_ns_per_run": 466.92832247825845,
      "post_rejit_run_cnt_delta": 1381228,
      "post_rejit_run_time_ns_delta": 644934473,
      "program": "generic_tracepo",
      "program_id": 465,
      "ratio": 1.2286951890057802,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1357.7531512605042,
      "baseline_run_cnt_delta": 952,
      "baseline_run_time_ns_delta": 1292581,
      "post_rejit_avg_ns_per_run": 1512.5105485232068,
      "post_rejit_run_cnt_delta": 948,
      "post_rejit_run_time_ns_delta": 1433860,
      "program": "generic_rawtp_e",
      "program_id": 472,
      "ratio": 1.1139805104624723,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 749.0086496876502,
      "baseline_run_cnt_delta": 2081,
      "baseline_run_time_ns_delta": 1558687,
      "post_rejit_avg_ns_per_run": 1149.3052899936265,
      "post_rejit_run_cnt_delta": 1569,
      "post_rejit_run_time_ns_delta": 1803260,
      "program": "generic_kprobe_",
      "program_id": 474,
      "ratio": 1.5344352705044288,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2640.4324816090157,
      "baseline_run_cnt_delta": 51112,
      "baseline_run_time_ns_delta": 134957785,
      "post_rejit_avg_ns_per_run": 2684.2724318575706,
      "post_rejit_run_cnt_delta": 50776,
      "post_rejit_run_time_ns_delta": 136296617,
      "program": "generic_kprobe_",
      "program_id": 482,
      "ratio": 1.0166033218247035,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 678.4061302681993,
      "baseline_run_cnt_delta": 2088,
      "baseline_run_time_ns_delta": 1416512,
      "post_rejit_avg_ns_per_run": 979.746192893401,
      "post_rejit_run_cnt_delta": 1576,
      "post_rejit_run_time_ns_delta": 1544080,
      "program": "generic_kprobe_",
      "program_id": 496,
      "ratio": 1.4441882954478473,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 537.9133141762452,
      "baseline_run_cnt_delta": 2088,
      "baseline_run_time_ns_delta": 1123163,
      "post_rejit_avg_ns_per_run": 664.7696700507614,
      "post_rejit_run_cnt_delta": 1576,
      "post_rejit_run_time_ns_delta": 1047677,
      "program": "generic_retkprobe_event",
      "program_id": 501,
      "ratio": 1.2358304814759655,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 574.6419562419562,
      "baseline_run_cnt_delta": 3885,
      "baseline_run_time_ns_delta": 2232484,
      "post_rejit_avg_ns_per_run": 798.4306472919419,
      "post_rejit_run_cnt_delta": 3028,
      "post_rejit_run_time_ns_delta": 2417648,
      "program": "generic_kprobe_",
      "program_id": 509,
      "ratio": 1.3894402220706596,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 401.42515932391245,
      "baseline_run_cnt_delta": 18045,
      "baseline_run_time_ns_delta": 7243717,
      "post_rejit_avg_ns_per_run": 439.11025103089054,
      "post_rejit_run_cnt_delta": 13823,
      "post_rejit_run_time_ns_delta": 6069821,
      "program": "generic_kprobe_",
      "program_id": 512,
      "ratio": 1.0938782506070321,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 631.908936376882,
      "baseline_run_cnt_delta": 4118,
      "baseline_run_time_ns_delta": 2602201,
      "post_rejit_avg_ns_per_run": 812.7113104774111,
      "post_rejit_run_cnt_delta": 3121,
      "post_rejit_run_time_ns_delta": 2536472,
      "program": "generic_kprobe_",
      "program_id": 521,
      "ratio": 1.286120932451405,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 611.4594594594595,
      "baseline_run_cnt_delta": 2072,
      "baseline_run_time_ns_delta": 1266944,
      "post_rejit_avg_ns_per_run": 875.1417575368827,
      "post_rejit_run_cnt_delta": 1559,
      "post_rejit_run_time_ns_delta": 1364346,
      "program": "generic_kprobe_",
      "program_id": 532,
      "ratio": 1.4312343099745695,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 541.934362934363,
      "baseline_run_cnt_delta": 2072,
      "baseline_run_time_ns_delta": 1122888,
      "post_rejit_avg_ns_per_run": 683.9967928159076,
      "post_rejit_run_cnt_delta": 1559,
      "post_rejit_run_time_ns_delta": 1066351,
      "program": "generic_retkprobe_event",
      "program_id": 534,
      "ratio": 1.2621395497276313,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 769.0448841698842,
      "baseline_run_cnt_delta": 2072,
      "baseline_run_time_ns_delta": 1593461,
      "post_rejit_avg_ns_per_run": 1173.6833333333334,
      "post_rejit_run_cnt_delta": 1560,
      "post_rejit_run_time_ns_delta": 1830946,
      "program": "generic_kprobe_",
      "program_id": 542,
      "ratio": 1.526157130087694,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 691.7940747935892,
      "baseline_run_cnt_delta": 4118,
      "baseline_run_time_ns_delta": 2848808,
      "post_rejit_avg_ns_per_run": 966.808074335149,
      "post_rejit_run_cnt_delta": 3121,
      "post_rejit_run_time_ns_delta": 3017408,
      "program": "generic_kprobe_",
      "program_id": 550,
      "ratio": 1.397537373565415,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "tetragon_exec_connect_mix"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 50.021701388888886,
      "baseline_run_cnt_delta": 1152,
      "baseline_run_time_ns_delta": 57625,
      "post_rejit_avg_ns_per_run": 57.5765625,
      "post_rejit_run_cnt_delta": 1280,
      "post_rejit_run_time_ns_delta": 73698,
      "program": "balancer_ingress",
      "program_id": 577,
      "ratio": 1.1510316702819958,
      "runner": "katran",
      "type": "xdp",
      "workload": "test_run"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 146.58150124023777,
      "baseline_run_cnt_delta": 2877674,
      "baseline_run_time_ns_delta": 421813775,
      "post_rejit_avg_ns_per_run": 162.47460781285542,
      "post_rejit_run_cnt_delta": 2334281,
      "post_rejit_run_time_ns_delta": 379261390,
      "program": "tracepoint__raw",
      "program_id": 594,
      "ratio": 1.1084250498060453,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 356.5541686667086,
      "baseline_run_cnt_delta": 2877023,
      "baseline_run_time_ns_delta": 1025814544,
      "post_rejit_avg_ns_per_run": 396.3064785536898,
      "post_rejit_run_cnt_delta": 2334271,
      "post_rejit_run_time_ns_delta": 925086720,
      "program": "tracepoint__raw",
      "program_id": 597,
      "ratio": 1.1114902401383502,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 333.83215185888054,
      "baseline_run_cnt_delta": 2877619,
      "baseline_run_time_ns_delta": 960641743,
      "post_rejit_avg_ns_per_run": 370.2226282359079,
      "post_rejit_run_cnt_delta": 2334623,
      "post_rejit_run_time_ns_delta": 864330263,
      "program": "trace_sys_enter",
      "program_id": 600,
      "ratio": 1.1090083030480855,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 310.60001800063037,
      "baseline_run_cnt_delta": 2877677,
      "baseline_run_time_ns_delta": 893806528,
      "post_rejit_avg_ns_per_run": 334.2468217031688,
      "post_rejit_run_cnt_delta": 2334977,
      "post_rejit_run_time_ns_delta": 780458641,
      "program": "trace_sys_exit",
      "program_id": 601,
      "ratio": 1.0761326539990428,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1197.9135135135134,
      "baseline_run_cnt_delta": 185,
      "baseline_run_time_ns_delta": 221614,
      "post_rejit_avg_ns_per_run": 1467.7951807228915,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 243654,
      "program": "trace_arch_prct",
      "program_id": 606,
      "ratio": 1.2252931152081319,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1675.1513513513514,
      "baseline_run_cnt_delta": 185,
      "baseline_run_time_ns_delta": 309903,
      "post_rejit_avg_ns_per_run": 2200.8493975903616,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 365341,
      "program": "trace_ret_arch_",
      "program_id": 607,
      "ratio": 1.313821223267335,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1224.52688172043,
      "baseline_run_cnt_delta": 186,
      "baseline_run_time_ns_delta": 227762,
      "post_rejit_avg_ns_per_run": 1680.5748502994013,
      "post_rejit_run_cnt_delta": 167,
      "post_rejit_run_time_ns_delta": 280656,
      "program": "trace_dup2",
      "program_id": 610,
      "ratio": 1.3724278947132913,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2577.8279569892475,
      "baseline_run_cnt_delta": 186,
      "baseline_run_time_ns_delta": 479476,
      "post_rejit_avg_ns_per_run": 3277.8263473053894,
      "post_rejit_run_cnt_delta": 167,
      "post_rejit_run_time_ns_delta": 547397,
      "program": "trace_ret_dup2",
      "program_id": 611,
      "ratio": 1.2715458137608606,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4421.650994575045,
      "baseline_run_cnt_delta": 553,
      "baseline_run_time_ns_delta": 2445173,
      "post_rejit_avg_ns_per_run": 8338.179435483871,
      "post_rejit_run_cnt_delta": 496,
      "post_rejit_run_time_ns_delta": 4135737,
      "program": "tracepoint__sch",
      "program_id": 619,
      "ratio": 1.8857615505416512,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4760.627027027027,
      "baseline_run_cnt_delta": 185,
      "baseline_run_time_ns_delta": 880716,
      "post_rejit_avg_ns_per_run": 5723.987951807229,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 950182,
      "program": "tracepoint__sch",
      "program_id": 627,
      "ratio": 1.2023600923388895,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1466.0235081374321,
      "baseline_run_cnt_delta": 553,
      "baseline_run_time_ns_delta": 810711,
      "post_rejit_avg_ns_per_run": 2270.122983870968,
      "post_rejit_run_cnt_delta": 496,
      "post_rejit_run_time_ns_delta": 1125981,
      "program": "tracepoint__sch",
      "program_id": 629,
      "ratio": 1.548490164905429,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1184.6962025316457,
      "baseline_run_cnt_delta": 553,
      "baseline_run_time_ns_delta": 655137,
      "post_rejit_avg_ns_per_run": 1454.9556451612902,
      "post_rejit_run_cnt_delta": 496,
      "post_rejit_run_time_ns_delta": 721658,
      "program": "tracepoint__sch",
      "program_id": 630,
      "ratio": 1.2281255245455431,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 246.35829449663768,
      "baseline_run_cnt_delta": 283881,
      "baseline_run_time_ns_delta": 69936439,
      "post_rejit_avg_ns_per_run": 340.08917611239855,
      "post_rejit_run_cnt_delta": 206266,
      "post_rejit_run_time_ns_delta": 70148834,
      "program": "tracepoint__sch",
      "program_id": 632,
      "ratio": 1.3804657026355576,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 17.217978672417924,
      "baseline_run_cnt_delta": 33384,
      "baseline_run_time_ns_delta": 574805,
      "post_rejit_avg_ns_per_run": 23.907692307692308,
      "post_rejit_run_cnt_delta": 195,
      "post_rejit_run_time_ns_delta": 4662,
      "program": "trace_filldir64",
      "program_id": 633,
      "ratio": 1.3885307191134386,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1319.7793851717902,
      "baseline_run_cnt_delta": 553,
      "baseline_run_time_ns_delta": 729838,
      "post_rejit_avg_ns_per_run": 1767.6149193548388,
      "post_rejit_run_cnt_delta": 496,
      "post_rejit_run_time_ns_delta": 876737,
      "program": "trace_do_exit",
      "program_id": 635,
      "ratio": 1.3393260564717455,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 830.7459459459459,
      "baseline_run_cnt_delta": 370,
      "baseline_run_time_ns_delta": 307376,
      "post_rejit_avg_ns_per_run": 880.9548192771084,
      "post_rejit_run_cnt_delta": 332,
      "post_rejit_run_time_ns_delta": 292477,
      "program": "trace_security_",
      "program_id": 639,
      "ratio": 1.060438300753898,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1713.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1713,
      "post_rejit_avg_ns_per_run": 1876.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1876,
      "program": "tracepoint__cgr",
      "program_id": 642,
      "ratio": 1.0951546993578518,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1262.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1262,
      "post_rejit_avg_ns_per_run": 1169.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1169,
      "program": "tracepoint__cgr",
      "program_id": 643,
      "ratio": 0.9263074484944532,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3235.2864864864864,
      "baseline_run_cnt_delta": 185,
      "baseline_run_time_ns_delta": 598528,
      "post_rejit_avg_ns_per_run": 3951.475903614458,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 655945,
      "program": "trace_security_",
      "program_id": 644,
      "ratio": 1.2213681601674018,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 925.3762010347376,
      "baseline_run_cnt_delta": 4059,
      "baseline_run_time_ns_delta": 3756102,
      "post_rejit_avg_ns_per_run": 1759.832712215321,
      "post_rejit_run_cnt_delta": 2415,
      "post_rejit_run_time_ns_delta": 4249996,
      "program": "trace_security_file_open",
      "program_id": 645,
      "ratio": 1.9017484027009883,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3331.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 3331,
      "post_rejit_avg_ns_per_run": 4255.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 4255,
      "program": "trace_security_",
      "program_id": 647,
      "ratio": 1.2773941759231462,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 470.16963064295487,
      "baseline_run_cnt_delta": 731,
      "baseline_run_time_ns_delta": 343694,
      "post_rejit_avg_ns_per_run": 1732.9397590361446,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 287668,
      "program": "trace_commit_cr",
      "program_id": 648,
      "ratio": 3.6857756139339695,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1007.0144665461121,
      "baseline_run_cnt_delta": 553,
      "baseline_run_time_ns_delta": 556879,
      "post_rejit_avg_ns_per_run": 1614.725806451613,
      "post_rejit_run_cnt_delta": 496,
      "post_rejit_run_time_ns_delta": 800904,
      "program": "trace_switch_ta",
      "program_id": 649,
      "ratio": 1.6034782618266121,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 154.53290279647302,
      "baseline_run_cnt_delta": 66119,
      "baseline_run_time_ns_delta": 10217561,
      "post_rejit_avg_ns_per_run": 162.85408667981045,
      "post_rejit_run_cnt_delta": 57822,
      "post_rejit_run_time_ns_delta": 9416549,
      "program": "trace_cap_capab",
      "program_id": 650,
      "ratio": 1.053847327868401,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 922.8383152173913,
      "baseline_run_cnt_delta": 736,
      "baseline_run_time_ns_delta": 679209,
      "post_rejit_avg_ns_per_run": 1124.4878787878788,
      "post_rejit_run_cnt_delta": 660,
      "post_rejit_run_time_ns_delta": 742162,
      "program": "trace_security_",
      "program_id": 651,
      "ratio": 1.2185101769674413,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1661.8260869565217,
      "baseline_run_cnt_delta": 184,
      "baseline_run_time_ns_delta": 305776,
      "post_rejit_avg_ns_per_run": 2157.5030303030303,
      "post_rejit_run_cnt_delta": 165,
      "post_rejit_run_time_ns_delta": 355988,
      "program": "trace_security_",
      "program_id": 656,
      "ratio": 1.298272452958236,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1624.7934782608695,
      "baseline_run_cnt_delta": 184,
      "baseline_run_time_ns_delta": 298962,
      "post_rejit_avg_ns_per_run": 2061.2848484848487,
      "post_rejit_run_cnt_delta": 165,
      "post_rejit_run_time_ns_delta": 340112,
      "program": "trace_security_",
      "program_id": 657,
      "ratio": 1.268644216058269,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2115.2275280898875,
      "baseline_run_cnt_delta": 356,
      "baseline_run_time_ns_delta": 753021,
      "post_rejit_avg_ns_per_run": 2935.508038585209,
      "post_rejit_run_cnt_delta": 311,
      "post_rejit_run_time_ns_delta": 912943,
      "program": "trace_security_",
      "program_id": 658,
      "ratio": 1.387797766246007,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1635.3152173913043,
      "baseline_run_cnt_delta": 184,
      "baseline_run_time_ns_delta": 300898,
      "post_rejit_avg_ns_per_run": 2068.7939393939396,
      "post_rejit_run_cnt_delta": 165,
      "post_rejit_run_time_ns_delta": 341351,
      "program": "trace_security_",
      "program_id": 659,
      "ratio": 1.2650734961631014,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1738.6141304347825,
      "baseline_run_cnt_delta": 184,
      "baseline_run_time_ns_delta": 319905,
      "post_rejit_avg_ns_per_run": 2291.151515151515,
      "post_rejit_run_cnt_delta": 165,
      "post_rejit_run_time_ns_delta": 378040,
      "program": "trace_security_",
      "program_id": 660,
      "ratio": 1.3178033440798949,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 65.29183800454496,
      "baseline_run_cnt_delta": 73928,
      "baseline_run_time_ns_delta": 4826895,
      "post_rejit_avg_ns_per_run": 82.36015947783869,
      "post_rejit_run_cnt_delta": 62203,
      "post_rejit_run_time_ns_delta": 5123049,
      "program": "trace_vfs_write",
      "program_id": 663,
      "ratio": 1.2614158521943526,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 36.54969708443771,
      "baseline_run_cnt_delta": 73948,
      "baseline_run_time_ns_delta": 2702777,
      "post_rejit_avg_ns_per_run": 42.782261954529375,
      "post_rejit_run_cnt_delta": 62194,
      "post_rejit_run_time_ns_delta": 2660800,
      "program": "vfs_write_magic",
      "program_id": 664,
      "ratio": 1.1705230239170819,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 35.089142779881016,
      "baseline_run_cnt_delta": 73960,
      "baseline_run_time_ns_delta": 2595193,
      "post_rejit_avg_ns_per_run": 39.23190712781181,
      "post_rejit_run_cnt_delta": 62193,
      "post_rejit_run_time_ns_delta": 2439950,
      "program": "trace_ret_vfs_w",
      "program_id": 665,
      "ratio": 1.1180639941510946,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 41.57468638477344,
      "baseline_run_cnt_delta": 73976,
      "baseline_run_time_ns_delta": 3075529,
      "post_rejit_avg_ns_per_run": 54.68237165071002,
      "post_rejit_run_cnt_delta": 62252,
      "post_rejit_run_time_ns_delta": 3404087,
      "program": "vfs_write_magic",
      "program_id": 666,
      "ratio": 1.315280436384415,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 101.72103992979378,
      "baseline_run_cnt_delta": 18232,
      "baseline_run_time_ns_delta": 1854578,
      "post_rejit_avg_ns_per_run": 160.90828605810555,
      "post_rejit_run_cnt_delta": 11634,
      "post_rejit_run_time_ns_delta": 1872007,
      "program": "trace_vfs_read",
      "program_id": 678,
      "ratio": 1.581858445107933,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 129.505757507338,
      "baseline_run_cnt_delta": 4429,
      "baseline_run_time_ns_delta": 573581,
      "post_rejit_avg_ns_per_run": 245.3351886209029,
      "post_rejit_run_cnt_delta": 3234,
      "post_rejit_run_time_ns_delta": 793414,
      "program": "trace_ret_vfs_r",
      "program_id": 679,
      "ratio": 1.8943959970814568,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 196.75771370763783,
      "baseline_run_cnt_delta": 3954,
      "baseline_run_time_ns_delta": 777980,
      "post_rejit_avg_ns_per_run": 294.840311587147,
      "post_rejit_run_cnt_delta": 3081,
      "post_rejit_run_time_ns_delta": 908403,
      "program": "trace_mmap_aler",
      "program_id": 684,
      "ratio": 1.4984942955031997,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 134.50725552050474,
      "baseline_run_cnt_delta": 3170,
      "baseline_run_time_ns_delta": 426388,
      "post_rejit_avg_ns_per_run": 181.6421052631579,
      "post_rejit_run_cnt_delta": 2850,
      "post_rejit_run_time_ns_delta": 517680,
      "program": "trace_do_mmap",
      "program_id": 685,
      "ratio": 1.3504260759782416,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 56.099053627760256,
      "baseline_run_cnt_delta": 3170,
      "baseline_run_time_ns_delta": 177834,
      "post_rejit_avg_ns_per_run": 86.3698245614035,
      "post_rejit_run_cnt_delta": 2850,
      "post_rejit_run_time_ns_delta": 246154,
      "program": "trace_ret_do_mm",
      "program_id": 686,
      "ratio": 1.5395950372799863,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 895.9422712933754,
      "baseline_run_cnt_delta": 3170,
      "baseline_run_time_ns_delta": 2840137,
      "post_rejit_avg_ns_per_run": 1071.7666666666667,
      "post_rejit_run_cnt_delta": 2850,
      "post_rejit_run_time_ns_delta": 3054535,
      "program": "trace_security_mmap_file",
      "program_id": 687,
      "ratio": 1.196245228076439,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1594.8520499108733,
      "baseline_run_cnt_delta": 561,
      "baseline_run_time_ns_delta": 894712,
      "post_rejit_avg_ns_per_run": 1923.7017892644135,
      "post_rejit_run_cnt_delta": 503,
      "post_rejit_run_time_ns_delta": 967622,
      "program": "trace_security_file_mprotect",
      "program_id": 688,
      "ratio": 1.2061945115046362,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 426.26507189657445,
      "baseline_run_cnt_delta": 22741,
      "baseline_run_time_ns_delta": 9693694,
      "post_rejit_avg_ns_per_run": 407.108557186375,
      "post_rejit_run_cnt_delta": 21666,
      "post_rejit_run_time_ns_delta": 8820414,
      "program": "trace_security_",
      "program_id": 690,
      "ratio": 0.9550596190652763,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 388.7079885423297,
      "baseline_run_cnt_delta": 6284,
      "baseline_run_time_ns_delta": 2442641,
      "post_rejit_avg_ns_per_run": 302.94763376158727,
      "post_rejit_run_cnt_delta": 6149,
      "post_rejit_run_time_ns_delta": 1862825,
      "program": "trace_security_",
      "program_id": 693,
      "ratio": 0.7793707427975762,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1224.994071146245,
      "baseline_run_cnt_delta": 506,
      "baseline_run_time_ns_delta": 619847,
      "post_rejit_avg_ns_per_run": 1238.2747035573123,
      "post_rejit_run_cnt_delta": 506,
      "post_rejit_run_time_ns_delta": 626567,
      "program": "trace_security_",
      "program_id": 694,
      "ratio": 1.0108413850514724,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1676.9945945945947,
      "baseline_run_cnt_delta": 370,
      "baseline_run_time_ns_delta": 620488,
      "post_rejit_avg_ns_per_run": 2014.948795180723,
      "post_rejit_run_cnt_delta": 332,
      "post_rejit_run_time_ns_delta": 668963,
      "program": "trace_load_elf_",
      "program_id": 708,
      "ratio": 1.2015237268357606,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 39.38897761109451,
      "baseline_run_cnt_delta": 97057,
      "baseline_run_time_ns_delta": 3822976,
      "post_rejit_avg_ns_per_run": 48.45037066194319,
      "post_rejit_run_cnt_delta": 76215,
      "post_rejit_run_time_ns_delta": 3692645,
      "program": "trace_security_",
      "program_id": 709,
      "ratio": 1.2300489527886704,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1905.6378378378379,
      "baseline_run_cnt_delta": 185,
      "baseline_run_time_ns_delta": 352543,
      "post_rejit_avg_ns_per_run": 3043.144578313253,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 505162,
      "program": "tracepoint__tas",
      "program_id": 710,
      "ratio": 1.596916537806599,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 391.24719101123594,
      "baseline_run_cnt_delta": 89,
      "baseline_run_time_ns_delta": 34821,
      "post_rejit_avg_ns_per_run": 445.95238095238096,
      "post_rejit_run_cnt_delta": 63,
      "post_rejit_run_time_ns_delta": 28095,
      "program": "trace_do_sigact",
      "program_id": 714,
      "ratio": 1.139822575594093,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2732.7650273224044,
      "baseline_run_cnt_delta": 183,
      "baseline_run_time_ns_delta": 500096,
      "post_rejit_avg_ns_per_run": 3372.737804878049,
      "post_rejit_run_cnt_delta": 164,
      "post_rejit_run_time_ns_delta": 553129,
      "program": "trace_do_trunca",
      "program_id": 717,
      "ratio": 1.23418507305134,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 303.8625055334219,
      "baseline_run_cnt_delta": 11295,
      "baseline_run_time_ns_delta": 3432127,
      "post_rejit_avg_ns_per_run": 438.05823645536304,
      "post_rejit_run_cnt_delta": 9118,
      "post_rejit_run_time_ns_delta": 3994215,
      "program": "trace_fd_instal",
      "program_id": 718,
      "ratio": 1.441633069161871,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 813.5658865575283,
      "baseline_run_cnt_delta": 17348,
      "baseline_run_time_ns_delta": 14113741,
      "post_rejit_avg_ns_per_run": 1086.1125176712505,
      "post_rejit_run_cnt_delta": 15562,
      "post_rejit_run_time_ns_delta": 16902083,
      "program": "trace_filp_clos",
      "program_id": 719,
      "ratio": 1.3350025309774958,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 549.5652173913044,
      "baseline_run_cnt_delta": 184,
      "baseline_run_time_ns_delta": 101120,
      "post_rejit_avg_ns_per_run": 1079.9101796407185,
      "post_rejit_run_cnt_delta": 167,
      "post_rejit_run_time_ns_delta": 180345,
      "program": "trace_file_upda",
      "program_id": 720,
      "ratio": 1.9650264344728263,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 218.6358695652174,
      "baseline_run_cnt_delta": 184,
      "baseline_run_time_ns_delta": 40229,
      "post_rejit_avg_ns_per_run": 417.622754491018,
      "post_rejit_run_cnt_delta": 167,
      "post_rejit_run_time_ns_delta": 69743,
      "program": "trace_ret_file_",
      "program_id": 721,
      "ratio": 1.9101291810969028,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 167.46486486486486,
      "baseline_run_cnt_delta": 185,
      "baseline_run_time_ns_delta": 30981,
      "post_rejit_avg_ns_per_run": 338.68674698795184,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 56222,
      "program": "trace_exec_binp",
      "program_id": 727,
      "ratio": 2.022434659719541,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4444.27027027027,
      "baseline_run_cnt_delta": 185,
      "baseline_run_time_ns_delta": 822190,
      "post_rejit_avg_ns_per_run": 5823.3975903614455,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 966684,
      "program": "trace_security_",
      "program_id": 728,
      "ratio": 1.3103158080454245,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3225.5663956639564,
      "baseline_run_cnt_delta": 369,
      "baseline_run_time_ns_delta": 1190234,
      "post_rejit_avg_ns_per_run": 4549.969788519637,
      "post_rejit_run_cnt_delta": 331,
      "post_rejit_run_time_ns_delta": 1506040,
      "program": "trace_execute_f",
      "program_id": 729,
      "ratio": 1.4105956072198798,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2704.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2704,
      "post_rejit_avg_ns_per_run": 2648.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2648,
      "program": "trace_set_fs_pw",
      "program_id": 731,
      "ratio": 0.9792899408284024,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1284.0,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 5136,
      "post_rejit_avg_ns_per_run": 1159.8,
      "post_rejit_run_cnt_delta": 10,
      "post_rejit_run_time_ns_delta": 11598,
      "program": "trace_security_",
      "program_id": 732,
      "ratio": 0.9032710280373831,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 521.6666666666666,
      "baseline_run_cnt_delta": 6,
      "baseline_run_time_ns_delta": 3130,
      "post_rejit_avg_ns_per_run": 558.8333333333334,
      "post_rejit_run_cnt_delta": 6,
      "post_rejit_run_time_ns_delta": 3353,
      "program": "trace_security_task_prctl",
      "program_id": 735,
      "ratio": 1.0712460063897764,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 387.224153705398,
      "baseline_run_cnt_delta": 1093,
      "baseline_run_time_ns_delta": 423236,
      "post_rejit_avg_ns_per_run": 512.058762886598,
      "post_rejit_run_cnt_delta": 970,
      "post_rejit_run_time_ns_delta": 496697,
      "program": "trace_sock_allo",
      "program_id": 738,
      "ratio": 1.3223833223899941,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1217.7804208600182,
      "baseline_run_cnt_delta": 1093,
      "baseline_run_time_ns_delta": 1331034,
      "post_rejit_avg_ns_per_run": 1541.7855670103093,
      "post_rejit_run_cnt_delta": 970,
      "post_rejit_run_time_ns_delta": 1495532,
      "program": "trace_ret_sock_",
      "program_id": 739,
      "ratio": 1.266062042549077,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1516.5652173913043,
      "baseline_run_cnt_delta": 184,
      "baseline_run_time_ns_delta": 279048,
      "post_rejit_avg_ns_per_run": 1959.290909090909,
      "post_rejit_run_cnt_delta": 165,
      "post_rejit_run_time_ns_delta": 323283,
      "program": "trace_security_",
      "program_id": 740,
      "ratio": 1.2919265763335601,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 204.2554347826087,
      "baseline_run_cnt_delta": 184,
      "baseline_run_time_ns_delta": 37583,
      "post_rejit_avg_ns_per_run": 453.4969696969697,
      "post_rejit_run_cnt_delta": 165,
      "post_rejit_run_time_ns_delta": 74827,
      "program": "trace_security_",
      "program_id": 741,
      "ratio": 2.220244323876285,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 357.0652173913044,
      "baseline_run_cnt_delta": 184,
      "baseline_run_time_ns_delta": 65700,
      "post_rejit_avg_ns_per_run": 554.3515151515152,
      "post_rejit_run_cnt_delta": 165,
      "post_rejit_run_time_ns_delta": 91468,
      "program": "trace_security_",
      "program_id": 742,
      "ratio": 1.5525217471518842,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1283.0146788990826,
      "baseline_run_cnt_delta": 2180,
      "baseline_run_time_ns_delta": 2796972,
      "post_rejit_avg_ns_per_run": 1629.3454081632653,
      "post_rejit_run_cnt_delta": 1960,
      "post_rejit_run_time_ns_delta": 3193517,
      "program": "cgroup_bpf_run_",
      "program_id": 743,
      "ratio": 1.2699351261993035,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1246.133152173913,
      "baseline_run_cnt_delta": 1104,
      "baseline_run_time_ns_delta": 1375731,
      "post_rejit_avg_ns_per_run": 1474.4185110663984,
      "post_rejit_run_cnt_delta": 994,
      "post_rejit_run_time_ns_delta": 1465572,
      "program": "cgroup_skb_ingr",
      "program_id": 745,
      "ratio": 1.183194996854257,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1703.7590579710145,
      "baseline_run_cnt_delta": 1104,
      "baseline_run_time_ns_delta": 1880950,
      "post_rejit_avg_ns_per_run": 2412.9024144869213,
      "post_rejit_run_cnt_delta": 994,
      "post_rejit_run_time_ns_delta": 2398425,
      "program": "cgroup_skb_egre",
      "program_id": 746,
      "ratio": 1.4162227946482155,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2622.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2622,
      "post_rejit_avg_ns_per_run": 2347.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2347,
      "program": "cgroup_mkdir_si",
      "program_id": 747,
      "ratio": 0.8951182303585049,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 762.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 762,
      "post_rejit_avg_ns_per_run": 679.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 679,
      "program": "cgroup_rmdir_si",
      "program_id": 748,
      "ratio": 0.8910761154855643,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 171.7891891891892,
      "baseline_run_cnt_delta": 185,
      "baseline_run_time_ns_delta": 31781,
      "post_rejit_avg_ns_per_run": 119.34939759036145,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 19812,
      "program": "empty_kprobe",
      "program_id": 749,
      "ratio": 0.6947433546526814,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 938.0756756756757,
      "baseline_run_cnt_delta": 185,
      "baseline_run_time_ns_delta": 173544,
      "post_rejit_avg_ns_per_run": 1166.198795180723,
      "post_rejit_run_cnt_delta": 166,
      "post_rejit_run_time_ns_delta": 193589,
      "program": "tracepoint__exe",
      "program_id": 750,
      "ratio": 1.243182000578722,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 432.8460211874846,
      "baseline_run_cnt_delta": 4059,
      "baseline_run_time_ns_delta": 1756922,
      "post_rejit_avg_ns_per_run": 784.9859213250518,
      "post_rejit_run_cnt_delta": 2415,
      "post_rejit_run_time_ns_delta": 1895741,
      "program": "lsm_file_open_t",
      "program_id": 751,
      "ratio": 1.8135454247020557,
      "runner": "tracee",
      "type": "lsm",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 109.38633420121504,
      "baseline_run_cnt_delta": 149790,
      "baseline_run_time_ns_delta": 16384979,
      "post_rejit_avg_ns_per_run": 129.41389344074,
      "post_rejit_run_cnt_delta": 130594,
      "post_rejit_run_time_ns_delta": 16900678,
      "program": "cap_capable",
      "program_id": 758,
      "ratio": 1.183090139968348,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 179.326171875,
      "baseline_run_cnt_delta": 368640,
      "baseline_run_time_ns_delta": 66106800,
      "post_rejit_avg_ns_per_run": 257.17417454075166,
      "post_rejit_run_cnt_delta": 303104,
      "post_rejit_run_time_ns_delta": 77950521,
      "program": "block_io_start",
      "program_id": 764,
      "ratio": 1.4341140049541454,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 284.0650119357639,
      "baseline_run_cnt_delta": 368640,
      "baseline_run_time_ns_delta": 104717726,
      "post_rejit_avg_ns_per_run": 351.9539695945946,
      "post_rejit_run_cnt_delta": 303104,
      "post_rejit_run_time_ns_delta": 106678656,
      "program": "block_io_done",
      "program_id": 765,
      "ratio": 1.2389909168897666,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1377.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1377,
      "post_rejit_avg_ns_per_run": 1629.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1629,
      "program": "1",
      "program_id": 771,
      "ratio": 1.1830065359477124,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "vfs_create_write_fsync"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 45.96949650863653,
      "baseline_run_cnt_delta": 19047,
      "baseline_run_time_ns_delta": 875581,
      "post_rejit_avg_ns_per_run": 62.34661551109893,
      "post_rejit_run_cnt_delta": 18245,
      "post_rejit_run_time_ns_delta": 1137514,
      "program": "vfs_create",
      "program_id": 772,
      "ratio": 1.3562605694275016,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "vfs_create_write_fsync"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 99.86229844314707,
      "baseline_run_cnt_delta": 57552,
      "baseline_run_time_ns_delta": 5747275,
      "post_rejit_avg_ns_per_run": 121.34776636078905,
      "post_rejit_run_cnt_delta": 54597,
      "post_rejit_run_time_ns_delta": 6625224,
      "program": "sched_wakeup",
      "program_id": 778,
      "ratio": 1.215150945377789,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 207.55601659751036,
      "baseline_run_cnt_delta": 3856,
      "baseline_run_time_ns_delta": 800336,
      "post_rejit_avg_ns_per_run": 256.21037277147485,
      "post_rejit_run_cnt_delta": 3085,
      "post_rejit_run_time_ns_delta": 790409,
      "program": "sched_wakeup_ne",
      "program_id": 779,
      "ratio": 1.2344155422307719,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 157.61468502114928,
      "baseline_run_cnt_delta": 92911,
      "baseline_run_time_ns_delta": 14644138,
      "post_rejit_avg_ns_per_run": 188.2003861183476,
      "post_rejit_run_cnt_delta": 85984,
      "post_rejit_run_time_ns_delta": 16182222,
      "program": "sched_switch",
      "program_id": 780,
      "ratio": 1.1940536257335046,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 953.2543046357616,
      "baseline_run_cnt_delta": 755,
      "baseline_run_time_ns_delta": 719707,
      "post_rejit_avg_ns_per_run": 1088.1556291390727,
      "post_rejit_run_cnt_delta": 604,
      "post_rejit_run_time_ns_delta": 657246,
      "program": "tcp_set_state",
      "program_id": 787,
      "ratio": 1.1415166171789353,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline_avg_ns_per_run": 5407.882352941177,
      "baseline_run_cnt_delta": 17,
      "baseline_run_time_ns_delta": 91934,
      "post_rejit_avg_ns_per_run": 8451.368421052632,
      "post_rejit_run_cnt_delta": 19,
      "post_rejit_run_time_ns_delta": 160576,
      "program": "tcp_retransmit_",
      "program_id": 793,
      "ratio": 1.5627870337186975,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "tcp_retransmit"
    }
  ],
  "results": [
    {
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 89.15524728752875,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 146914,
            "run_time_ns_delta": 13098154,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0932513409999842,
            "ops_per_sec": 1072.9463171086263,
            "ops_total": 1173.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5377] setting to a 1 secs run per stressor\nstress-ng: info:  [5377] dispatching hogs: 2 exec\nstress-ng: info:  [5377] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5377] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5377]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5377] exec               1173      1.03      2.49      0.84      1135.05         352.27\nstress-ng: info:  [5377] skipped: 0\nstress-ng: info:  [5377] passed: 2: exec (2)\nstress-ng: info:  [5377] failed: 0\nstress-ng: info:  [5377] metrics untrustworthy: 0\nstress-ng: info:  [5377] successful run completed in 1.06 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 77.82634697071317,
            "bytes_jited": 206,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 143136,
            "run_time_ns_delta": 11139752,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.083891719999997,
            "ops_per_sec": 1072.9854085424727,
            "ops_total": 1163.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [10421] setting to a 1 secs run per stressor\nstress-ng: info:  [10421] dispatching hogs: 2 exec\nstress-ng: info:  [10421] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10421] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10421]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10421] exec               1163      1.03      2.59      0.93      1125.44         329.66\nstress-ng: info:  [10421] skipped: 0\nstress-ng: info:  [10421] passed: 2: exec (2)\nstress-ng: info:  [10421] failed: 0\nstress-ng: info:  [10421] metrics untrustworthy: 0\nstress-ng: info:  [10421] successful run completed in 1.06 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "applied_site_totals": {
          "bitfield_sites": 1,
          "bounds_check_merge_sites": 0,
          "branch_flip_sites": 0,
          "bulk_memory_sites": 0,
          "cmov_sites": 0,
          "const_prop_sites": 0,
          "dce_sites": 0,
          "endian_sites": 0,
          "extract_sites": 1,
          "lea_sites": 0,
          "map_inline_sites": 0,
          "other_sites": 0,
          "rotate_sites": 0,
          "skb_load_bytes_spec_sites": 0,
          "total_sites": 1,
          "wide_sites": 0
        },
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
        "output_chars": 3701,
        "output_stripped": true,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bcc",
      "selected_workload": "exec_storm",
      "status": "ok"
    },
    {
      "app": "bcc/execsnoop",
      "baseline": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1853.1267723102585,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1199,
            "run_time_ns_delta": 2221899,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1291.312252964427,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 1012,
            "run_time_ns_delta": 1306808,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1096698069999889,
            "ops_per_sec": 1077.7980913380047,
            "ops_total": 1196.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8999] setting to a 1 secs run per stressor\nstress-ng: info:  [8999] dispatching hogs: 2 exec\nstress-ng: info:  [8999] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8999] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8999]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8999] exec               1196      1.07      2.52      0.91      1113.29         348.66\nstress-ng: info:  [8999] skipped: 0\nstress-ng: info:  [8999] passed: 2: exec (2)\nstress-ng: info:  [8999] failed: 0\nstress-ng: info:  [8999] metrics untrustworthy: 0\nstress-ng: info:  [8999] successful run completed in 1.08 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1935.9398359161348,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1097,
            "run_time_ns_delta": 2123726,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1655.3639661426844,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_exec",
            "run_cnt_delta": 827,
            "run_time_ns_delta": 1368986,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.106156282000029,
            "ops_per_sec": 989.0103394991805,
            "ops_total": 1094.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [12160] setting to a 1 secs run per stressor\nstress-ng: info:  [12160] dispatching hogs: 2 exec\nstress-ng: info:  [12160] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12160] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12160]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12160] exec               1094      1.04      2.43      0.91      1053.72         327.81\nstress-ng: info:  [12160] skipped: 0\nstress-ng: info:  [12160] passed: 2: exec (2)\nstress-ng: info:  [12160] failed: 0\nstress-ng: info:  [12160] metrics untrustworthy: 0\nstress-ng: info:  [12160] successful run completed in 1.07 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 7422,
        "output_stripped": true,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bcc",
      "selected_workload": "exec_storm",
      "status": "ok"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 57.62550754499727,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 33002,
            "run_time_ns_delta": 1901757,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 644.9567904975456,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 16501,
            "run_time_ns_delta": 10642432,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 642.1478698260712,
            "bytes_jited": 742,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_return",
            "run_cnt_delta": 16501,
            "run_time_ns_delta": 10596082,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0001199029999839,
            "ops_per_sec": 32998.043435598476,
            "ops_total": 33002.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 65.04307624568871,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 27254,
            "run_time_ns_delta": 1772684,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 724.9509062889852,
            "bytes_jited": 719,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_re",
            "run_cnt_delta": 13627,
            "run_time_ns_delta": 9878906,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 713.7269391648932,
            "bytes_jited": 740,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_re",
            "run_cnt_delta": 13627,
            "run_time_ns_delta": 9725957,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000009076000083,
            "ops_per_sec": 27253.75264493873,
            "ops_total": 27254.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "applied_site_totals": {
          "bitfield_sites": 2,
          "bounds_check_merge_sites": 0,
          "branch_flip_sites": 0,
          "bulk_memory_sites": 0,
          "cmov_sites": 0,
          "const_prop_sites": 0,
          "dce_sites": 0,
          "endian_sites": 2,
          "extract_sites": 2,
          "lea_sites": 0,
          "map_inline_sites": 0,
          "other_sites": 0,
          "rotate_sites": 0,
          "skb_load_bytes_spec_sites": 0,
          "total_sites": 4,
          "wide_sites": 0
        },
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
        "output_chars": 12431,
        "output_stripped": true,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "bind_storm",
      "status": "ok"
    },
    {
      "app": "bcc/biosnoop",
      "baseline": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 139.20854529752296,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 327689,
            "run_time_ns_delta": 45617109,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 160.07522681566974,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 327689,
            "run_time_ns_delta": 52454891,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 374.09161318673273,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 327693,
            "run_time_ns_delta": 122587203,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.003202895000015,
            "ops_per_sec": 65494.0458895779,
            "ops_total": 327680.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 183.98109618397228,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start",
            "run_cnt_delta": 294914,
            "run_time_ns_delta": 54258601,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 206.4856501512295,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 294916,
            "run_time_ns_delta": 60895922,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 418.87909140537846,
            "bytes_jited": 548,
            "bytes_xlated": 848,
            "id": 20,
            "name": "trace_req_compl",
            "run_cnt_delta": 294917,
            "run_time_ns_delta": 123534565,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.02175991799993,
            "ops_per_sec": 58726.82183449697,
            "ops_total": 294912.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "applied_site_totals": {
          "bitfield_sites": 0,
          "bounds_check_merge_sites": 0,
          "branch_flip_sites": 0,
          "bulk_memory_sites": 0,
          "cmov_sites": 0,
          "const_prop_sites": 2,
          "dce_sites": 1,
          "endian_sites": 0,
          "extract_sites": 0,
          "lea_sites": 0,
          "map_inline_sites": 0,
          "other_sites": 0,
          "rotate_sites": 0,
          "skb_load_bytes_spec_sites": 0,
          "total_sites": 3,
          "wide_sites": 0
        },
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
        "output_chars": 13071,
        "output_stripped": true,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "block_io",
      "status": "ok"
    },
    {
      "app": "bcc/vfsstat",
      "baseline": {
        "bpf": {
          "23": {
            "avg_ns_per_run": null,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": null,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 38.025782688766114,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 543,
            "run_time_ns_delta": 20648,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 27.337440281619312,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 7954,
            "run_time_ns_delta": 217442,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 26.61536670547148,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 12885,
            "run_time_ns_delta": 342939,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.001475666000033,
            "ops_per_sec": 81.87917368727888,
            "ops_total": 82.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "23": {
            "avg_ns_per_run": null,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": null,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "vfs_fsync_range",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 41.43560606060606,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 528,
            "run_time_ns_delta": 21878,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 34.32895082829345,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 3803,
            "run_time_ns_delta": 130553,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 25.83262599469496,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 11310,
            "run_time_ns_delta": 292167,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0037750899999764,
            "ops_per_sec": 105.60134541693247,
            "ops_total": 106.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 19731,
        "output_stripped": true,
        "program_counts": {
          "applied": 5,
          "not_applied": 0,
          "requested": 5
        }
      },
      "runner": "bcc",
      "selected_workload": "vfs_create_fsync_exact",
      "status": "ok"
    },
    {
      "app": "bcc/opensnoop",
      "baseline": {
        "bpf": {
          "30": {
            "avg_ns_per_run": null,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 1144.0676037483267,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 1494,
            "run_time_ns_delta": 1709237,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1187.7358490566037,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 477,
            "run_time_ns_delta": 566550,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0033595240000182,
            "ops_per_sec": 475.4028726396894,
            "ops_total": 477.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": null,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 1291.8303867403315,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 1810,
            "run_time_ns_delta": 2338213,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1384.2170542635658,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 645,
            "run_time_ns_delta": 892820,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0001468169999725,
            "ops_per_sec": 644.9053169361011,
            "ops_total": 645.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 11098,
        "output_stripped": true,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "open_family_storm",
      "status": "ok"
    },
    {
      "app": "bcc/syscount",
      "baseline": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 61.4675109817412,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 944750,
            "run_time_ns_delta": 58071431,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 61.55168234498366,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 944723,
            "run_time_ns_delta": 58149290,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000602108999999,
            "ops_per_sec": 935.4367651048004,
            "ops_total": 936.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 70.49441029925617,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 886899,
            "run_time_ns_delta": 62521422,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 60.9642990437123,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 886867,
            "run_time_ns_delta": 54067225,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0031643470000517,
            "ops_per_sec": 1009.8046277555235,
            "ops_total": 1013.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 9093,
        "output_stripped": true,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bcc",
      "selected_workload": "file_open_storm",
      "status": "ok"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 685.36,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 75,
            "run_time_ns_delta": 51402,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4101.184210526316,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 38,
            "run_time_ns_delta": 155845,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 3731.945945945946,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 37,
            "run_time_ns_delta": 138082,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000312025000028,
            "ops_per_sec": 74.97660542469026,
            "ops_total": 75.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 740.2142857142857,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_e",
            "run_cnt_delta": 70,
            "run_time_ns_delta": 51815,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4994.657142857143,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v",
            "run_cnt_delta": 35,
            "run_time_ns_delta": 174813,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4656.914285714286,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v",
            "run_cnt_delta": 35,
            "run_time_ns_delta": 162992,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.00550432,
            "ops_per_sec": 69.61680681789612,
            "ops_total": 70.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 12342,
        "output_stripped": true,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "network",
      "status": "ok"
    },
    {
      "app": "bcc/tcplife",
      "baseline": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 640.0189573459716,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 844,
            "run_time_ns_delta": 540176,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0114408279999907,
            "ops_per_sec": 76.129020965328,
            "ops_total": 77.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 769.4987341772152,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "sock__inet_sock",
            "run_cnt_delta": 790,
            "run_time_ns_delta": 607904,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0111832999999706,
            "ops_per_sec": 71.20370757705561,
            "ops_total": 72.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 4883,
        "output_stripped": true,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bcc",
      "selected_workload": "network",
      "status": "ok"
    },
    {
      "app": "bcc/runqlat",
      "baseline": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 166.17432443861802,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 94588,
            "run_time_ns_delta": 15718097,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 106.93092506330697,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 63974,
            "run_time_ns_delta": 6840799,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 245.8143153526971,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 3856,
            "run_time_ns_delta": 947860,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0561650129999975,
            "ops_per_sec": 14.20232616624277,
            "ops_total": 15.0,
            "stderr": "",
            "stdout": "Time: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.050\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.034\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.048\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 173.8952323798093,
            "bytes_jited": 645,
            "bytes_xlated": 1136,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 74985,
            "run_time_ns_delta": 13039534,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 116.6100971651808,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 49915,
            "run_time_ns_delta": 5820593,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 252.47652125590443,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 3599,
            "run_time_ns_delta": 908663,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0202607630000102,
            "ops_per_sec": 13.721982171336192,
            "ops_total": 14.0,
            "stderr": "",
            "stdout": "Time: 0.046\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.046\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.052\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.051\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.057\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.053\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "applied_site_totals": {
          "bitfield_sites": 0,
          "bounds_check_merge_sites": 0,
          "branch_flip_sites": 0,
          "bulk_memory_sites": 0,
          "cmov_sites": 0,
          "const_prop_sites": 2,
          "dce_sites": 4,
          "endian_sites": 0,
          "extract_sites": 0,
          "lea_sites": 0,
          "map_inline_sites": 0,
          "other_sites": 0,
          "rotate_sites": 0,
          "skb_load_bytes_spec_sites": 0,
          "total_sites": 6,
          "wide_sites": 0
        },
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
        "output_chars": 12830,
        "output_stripped": true,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bcc",
      "selected_workload": "hackbench",
      "status": "ok"
    },
    {
      "app": "calico/felix",
      "baseline": {
        "bpf": {
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 865,
            "bytes_xlated": 1544,
            "id": 102,
            "name": "conntrack_cleanup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "105": {
            "avg_ns_per_run": null,
            "bytes_jited": 19,
            "bytes_xlated": 24,
            "id": 105,
            "name": "cali_tcx_test",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 113,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 114,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 116,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 117,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.009223469999995,
            "ops_per_sec": 802.5972681749108,
            "ops_total": 810.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     7.24ms    4.98ms  30.36ms   81.07%\n    Req/Sec   405.55    106.86   530.00     75.00%\n  810 requests in 1.00s, 122.74KB read\nRequests/sec:    806.75\nTransfer/sec:    122.25KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 865,
            "bytes_xlated": 1544,
            "id": 102,
            "name": "conntrack_cleanup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "105": {
            "avg_ns_per_run": null,
            "bytes_jited": 19,
            "bytes_xlated": 24,
            "id": 105,
            "name": "cali_tcx_test",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 113,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 114,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 116,
            "name": "calico_tc_allow",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 278,
            "bytes_xlated": 344,
            "id": 117,
            "name": "calico_tc_deny",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0201881570000069,
            "ops_per_sec": 786.1294943458107,
            "ops_total": 802.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     7.40ms    5.64ms  38.47ms   82.25%\n    Req/Sec   401.35    114.39   592.00     60.00%\n  802 requests in 1.01s, 121.53KB read\nRequests/sec:    794.15\nTransfer/sec:    120.34KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 25749,
        "output_stripped": true,
        "program_counts": {
          "applied": 6,
          "not_applied": 0,
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
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 120,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 121,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 122,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 123,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 124,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 19909,
            "bytes_xlated": 33264,
            "id": 125,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 126,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 127,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 128,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 129,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 130,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "131": {
            "avg_ns_per_run": 417.7929634641407,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 1478,
            "run_time_ns_delta": 617498,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 11914.837837837838,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_entry",
            "run_cnt_delta": 74,
            "run_time_ns_delta": 881698,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1039389209999513,
            "ops_per_sec": 1108.7569943555366,
            "ops_total": 1224.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [22807] setting to a 1 secs run per stressor\nstress-ng: info:  [22807] dispatching hogs: 2 exec\nstress-ng: info:  [22807] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22807] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22807]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22807] exec               1224      1.05      2.43      0.87      1163.99         371.20\nstress-ng: info:  [22807] skipped: 0\nstress-ng: info:  [22807] passed: 2: exec (2)\nstress-ng: info:  [22807] failed: 0\nstress-ng: info:  [22807] metrics untrustworthy: 0\nstress-ng: info:  [22807] successful run completed in 1.06 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 120,
            "name": "perf_unwind_sto",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 121,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 122,
            "name": "perf_unwind_hot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 123,
            "name": "perf_unwind_per",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 124,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 19909,
            "bytes_xlated": 33264,
            "id": 125,
            "name": "perf_unwind_pyt",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 126,
            "name": "perf_unwind_rub",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 127,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 128,
            "name": "perf_unwind_dot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 129,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 130,
            "name": "perf_unwind_bea",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "131": {
            "avg_ns_per_run": 445.25144927536235,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sch",
            "run_cnt_delta": 1380,
            "run_time_ns_delta": 614447,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 12226.591549295774,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_e",
            "run_cnt_delta": 71,
            "run_time_ns_delta": 868088,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0686968889999662,
            "ops_per_sec": 1053.6196105648396,
            "ops_total": 1126.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [18587] setting to a 1 secs run per stressor\nstress-ng: info:  [18587] dispatching hogs: 2 exec\nstress-ng: info:  [18587] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [18587] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [18587]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [18587] exec               1126      1.04      2.53      0.84      1085.73         334.46\nstress-ng: info:  [18587] skipped: 0\nstress-ng: info:  [18587] passed: 2: exec (2)\nstress-ng: info:  [18587] failed: 0\nstress-ng: info:  [18587] metrics untrustworthy: 0\nstress-ng: info:  [18587] successful run completed in 1.05 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 348005,
        "output_stripped": true,
        "program_counts": {
          "applied": 13,
          "not_applied": 0,
          "requested": 13
        }
      },
      "runner": "otelcol-ebpf-profiler",
      "selected_workload": "exec_storm",
      "status": "ok"
    },
    {
      "app": "cilium/agent",
      "baseline": null,
      "error": "failed to read BPF stats for requested program ids: 213, 214, 215, 217, 219, 221, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 235, 240, 244, 247, 248, 250, 252, 254, 259, 260",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "cilium",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "tetragon/observer",
      "baseline": {
        "bpf": {
          "275": {
            "avg_ns_per_run": 521.5529315960912,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 275,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1228,
            "run_time_ns_delta": 640467,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": 724.7833954230974,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 277,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1879,
            "run_time_ns_delta": 1361868,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 278,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "279": {
            "avg_ns_per_run": 2849.0556722689075,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 279,
            "name": "event_execve",
            "run_cnt_delta": 952,
            "run_time_ns_delta": 2712301,
            "type": "tracepoint"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 280,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "281": {
            "avg_ns_per_run": 270.2279411764706,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 281,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 952,
            "run_time_ns_delta": 257257,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 282,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 285,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 286,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 287,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 288,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 289,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 290,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 291,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 292,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 293,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 294,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 295,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 296,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 297,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 298,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 299,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 300,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 301,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 302,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 303,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 304,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 305,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 306,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 307,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 308,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 310,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 311,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": 608.7472474868358,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 312,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2089,
            "run_time_ns_delta": 1271673,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 313,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 314,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 315,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": 540.2637625658209,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 316,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2089,
            "run_time_ns_delta": 1128611,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 317,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 318,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 319,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 320,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 321,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 322,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": 538.4140504374678,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 323,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3886,
            "run_time_ns_delta": 2092277,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 324,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": 492.4947346770876,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 325,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 24310,
            "run_time_ns_delta": 11972547,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 327,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 328,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 329,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 330,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 331,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": 624.7510770703686,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 332,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2089,
            "run_time_ns_delta": 1305105,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 333,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 334,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 335,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 336,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 337,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 338,
            "name": "generic_retkprobe_filter_arg",
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
            "avg_ns_per_run": 589.6807084729536,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 341,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2089,
            "run_time_ns_delta": 1231843,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 342,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": 532.4691199176531,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 343,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3886,
            "run_time_ns_delta": 2069175,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 344,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 346,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 347,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 348,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": 535.5973993909967,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 349,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 12151,
            "run_time_ns_delta": 6508044,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 350,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 351,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 353,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 354,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "355": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 355,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 356,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 357,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "358": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 358,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 359,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 360,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": 563.5273264401773,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 361,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 12863,
            "run_time_ns_delta": 7248652,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 362,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 363,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 364,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 365,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 366,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 367,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 368,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 369,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 370,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 371,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 372,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "373": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 373,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 374,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 375,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 376,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 377,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 378,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 380,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 254.4952346373786,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 382,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 44068,
            "run_time_ns_delta": 11215096,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 383,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 384,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": 475.63436318184733,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 385,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 156010,
            "run_time_ns_delta": 74203717,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 386,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 387,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 388,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 389,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 390,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 391,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": 39.073648380107436,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 392,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 155998,
            "run_time_ns_delta": 6095411,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 393,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 394,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 395,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 396,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": 982.157948531043,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 397,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 126212,
            "run_time_ns_delta": 123960119,
            "type": "kprobe"
          },
          "398": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 398,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 399,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 400,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 401,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 402,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": 50.62639844071879,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 403,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 126212,
            "run_time_ns_delta": 6389659,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 404,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 405,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 406,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 407,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 408,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 409,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 410,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 411,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 412,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 413,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 414,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 415,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 416,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 417,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 419,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "420": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 420,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 421,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 423,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 424,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 425,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 426,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 427,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 428,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 429,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "430": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 430,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 431,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 432,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 433,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "434": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 434,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 435,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 436,
            "name": "generic_retkprobe_output",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 438,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 439,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 440,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 441,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 443,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 444,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 445,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 446,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 447,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 448,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 449,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 450,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 451,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 452,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 453,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 1531.5126050420167,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 455,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 952,
            "run_time_ns_delta": 1458000,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 456,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 457,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 458,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 459,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 460,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 461,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 462,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 463,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 464,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "465": {
            "avg_ns_per_run": 380.01965553074353,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 465,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 814122,
            "run_time_ns_delta": 309382362,
            "type": "tracepoint"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 466,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "467": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 467,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 468,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 469,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 470,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "471": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 471,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "472": {
            "avg_ns_per_run": 1357.7531512605042,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 472,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 952,
            "run_time_ns_delta": 1292581,
            "type": "raw_tracepoint"
          },
          "473": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 473,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "474": {
            "avg_ns_per_run": 749.0086496876502,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 474,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2081,
            "run_time_ns_delta": 1558687,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 475,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 476,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 477,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 478,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 479,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "480": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 480,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "481": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 481,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "482": {
            "avg_ns_per_run": 2640.4324816090157,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 482,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 51112,
            "run_time_ns_delta": 134957785,
            "type": "kprobe"
          },
          "483": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 483,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "484": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 484,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 485,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 486,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 487,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 488,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 489,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 490,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 491,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "492": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 492,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "493": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 493,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 494,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 495,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": 678.4061302681993,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 496,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2088,
            "run_time_ns_delta": 1416512,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 497,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 498,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 499,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "500": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 500,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "501": {
            "avg_ns_per_run": 537.9133141762452,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 501,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2088,
            "run_time_ns_delta": 1123163,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 502,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 503,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 504,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 505,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 506,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 507,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 508,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": 574.6419562419562,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 509,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3885,
            "run_time_ns_delta": 2232484,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 510,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 511,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": 401.42515932391245,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 512,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 18045,
            "run_time_ns_delta": 7243717,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 513,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 514,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 515,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 516,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 517,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 518,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 519,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 520,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": 631.908936376882,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 521,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4118,
            "run_time_ns_delta": 2602201,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 522,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 523,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 524,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 525,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 526,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 527,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 528,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 529,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 530,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 531,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": 611.4594594594595,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 532,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2072,
            "run_time_ns_delta": 1266944,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 533,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": 541.934362934363,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 534,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2072,
            "run_time_ns_delta": 1122888,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 535,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 536,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 537,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 538,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 539,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 540,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 541,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": 769.0448841698842,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 542,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2072,
            "run_time_ns_delta": 1593461,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 543,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 544,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 545,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 546,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "547": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 547,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 548,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 549,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": 691.7940747935892,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 550,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4118,
            "run_time_ns_delta": 2848808,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 551,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 552,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 553,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 554,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 555,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 556,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 557,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 558,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 559,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 560,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 561,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 562,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 563,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 564,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.4600357680000116,
            "ops_per_sec": 2257.4789414336965,
            "ops_total": 3296.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [27481] setting to a 1 secs run per stressor\nstress-ng: info:  [27481] dispatching hogs: 2 exec\nstress-ng: info:  [27481] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [27481] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [27481]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [27481] exec               1224      1.02      2.48      0.88      1200.02         365.29\nstress-ng: info:  [27481] skipped: 0\nstress-ng: info:  [27481] passed: 2: exec (2)\nstress-ng: info:  [27481] failed: 0\nstress-ng: info:  [27481] metrics untrustworthy: 0\nstress-ng: info:  [27481] successful run completed in 1.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "275": {
            "avg_ns_per_run": 524.3860232945092,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 275,
            "name": "event_exit_acct",
            "run_cnt_delta": 1202,
            "run_time_ns_delta": 630312,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": 762.9391929242676,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 277,
            "name": "event_wake_up_n",
            "run_cnt_delta": 1809,
            "run_time_ns_delta": 1380157,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 278,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "279": {
            "avg_ns_per_run": 2876.2953586497893,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 279,
            "name": "event_execve",
            "run_cnt_delta": 948,
            "run_time_ns_delta": 2726728,
            "type": "tracepoint"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 280,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "281": {
            "avg_ns_per_run": 307.55696202531647,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 281,
            "name": "tg_kp_bprm_comm",
            "run_cnt_delta": 948,
            "run_time_ns_delta": 291564,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 282,
            "name": "execve_map_upda",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 285,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 286,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 287,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 288,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 289,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 290,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 291,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 292,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 293,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 294,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 295,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 296,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 297,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 298,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 299,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 300,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 301,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 302,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 303,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": 1480.9333333333334,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 304,
            "name": "generic_kprobe_",
            "run_cnt_delta": 15,
            "run_time_ns_delta": 22214,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 305,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 306,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 307,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 308,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 310,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 311,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": 878.501269035533,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 312,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1576,
            "run_time_ns_delta": 1384518,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 313,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 314,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 315,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": 703.0374365482234,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 316,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1576,
            "run_time_ns_delta": 1107987,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 317,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 318,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 319,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 320,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 321,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 322,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": 722.0069352708058,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 323,
            "name": "generic_kprobe_",
            "run_cnt_delta": 3028,
            "run_time_ns_delta": 2186237,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 324,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": 494.4085870329314,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 325,
            "name": "generic_kprobe_",
            "run_cnt_delta": 18493,
            "run_time_ns_delta": 9143098,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 327,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 328,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 329,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 330,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 331,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": 902.1643401015228,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 332,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1576,
            "run_time_ns_delta": 1421811,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 333,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 334,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 335,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 336,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 337,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 338,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 339,
            "name": "generic_retkpro",
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
            "avg_ns_per_run": 736.8565989847716,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 341,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1576,
            "run_time_ns_delta": 1161286,
            "type": "kprobe"
          },
          "342": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 342,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": 799.5934610303831,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 343,
            "name": "generic_kprobe_",
            "run_cnt_delta": 3028,
            "run_time_ns_delta": 2421169,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 344,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 346,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 347,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 348,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": 561.9164504971898,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 349,
            "name": "generic_kprobe_",
            "run_cnt_delta": 9252,
            "run_time_ns_delta": 5198851,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 350,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 351,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 352,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 353,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 354,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "355": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 355,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 356,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "357": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 357,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "358": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 358,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 359,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 360,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": 596.2379606365159,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 361,
            "name": "generic_kprobe_",
            "run_cnt_delta": 9552,
            "run_time_ns_delta": 5695265,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 362,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 363,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 364,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 365,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 366,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 367,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 368,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 369,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 370,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 371,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 372,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "373": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 373,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 374,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 375,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 376,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 377,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 378,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 379,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 380,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 271.02074179069217,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 382,
            "name": "generic_kprobe_",
            "run_cnt_delta": 42330,
            "run_time_ns_delta": 11472308,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 383,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 384,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": 498.19432620273807,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 385,
            "name": "generic_kprobe_",
            "run_cnt_delta": 147767,
            "run_time_ns_delta": 73616681,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 386,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 387,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "388": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 388,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 389,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 390,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 391,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": 40.30818307905687,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 392,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 147805,
            "run_time_ns_delta": 5957751,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 393,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 394,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 395,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 396,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": 987.8090735434575,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 397,
            "name": "generic_kprobe_",
            "run_cnt_delta": 125640,
            "run_time_ns_delta": 124108332,
            "type": "kprobe"
          },
          "398": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 398,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 399,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 400,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 401,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 402,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": 51.31848137535817,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 403,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 125640,
            "run_time_ns_delta": 6447654,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 404,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 405,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 406,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 407,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 408,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 409,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 410,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 411,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 412,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 413,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 414,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 415,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 416,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 417,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 418,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 419,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "420": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 420,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 421,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 423,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 424,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 425,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 426,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 427,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 428,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 429,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "430": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 430,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 431,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 432,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 433,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "434": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 434,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 435,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 436,
            "name": "generic_retkpro",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 438,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 439,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 440,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 441,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 443,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 444,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 445,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 446,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 447,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "448": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 448,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 449,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 450,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 451,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 452,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 453,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 1656.159282700422,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 455,
            "name": "generic_kprobe_",
            "run_cnt_delta": 948,
            "run_time_ns_delta": 1570039,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 456,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 457,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 458,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 459,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 460,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 461,
            "name": "generic_tracepo",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 462,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 463,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 464,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "465": {
            "avg_ns_per_run": 466.92832247825845,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 465,
            "name": "generic_tracepo",
            "run_cnt_delta": 1381228,
            "run_time_ns_delta": 644934473,
            "type": "tracepoint"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 466,
            "name": "generic_rawtp_s",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "467": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 467,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 468,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 469,
            "name": "generic_rawtp_o",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 470,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "471": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 471,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "472": {
            "avg_ns_per_run": 1512.5105485232068,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 472,
            "name": "generic_rawtp_e",
            "run_cnt_delta": 948,
            "run_time_ns_delta": 1433860,
            "type": "raw_tracepoint"
          },
          "473": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 473,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "474": {
            "avg_ns_per_run": 1149.3052899936265,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 474,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1569,
            "run_time_ns_delta": 1803260,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 475,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 476,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 477,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 478,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 479,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "480": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 480,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "481": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 481,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "482": {
            "avg_ns_per_run": 2684.2724318575706,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 482,
            "name": "generic_kprobe_",
            "run_cnt_delta": 50776,
            "run_time_ns_delta": 136296617,
            "type": "kprobe"
          },
          "483": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 483,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "484": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 484,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 485,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 486,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 487,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 488,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 489,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 490,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 491,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "492": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 492,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "493": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 493,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 494,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 495,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": 979.746192893401,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 496,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1576,
            "run_time_ns_delta": 1544080,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 497,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 498,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 499,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "500": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 500,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "501": {
            "avg_ns_per_run": 664.7696700507614,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 501,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1576,
            "run_time_ns_delta": 1047677,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 502,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 503,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 504,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 505,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 506,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 507,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 508,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": 798.4306472919419,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 509,
            "name": "generic_kprobe_",
            "run_cnt_delta": 3028,
            "run_time_ns_delta": 2417648,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 510,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 511,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": 439.11025103089054,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 512,
            "name": "generic_kprobe_",
            "run_cnt_delta": 13823,
            "run_time_ns_delta": 6069821,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 513,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 514,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 515,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 516,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 517,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 518,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 519,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 520,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": 812.7113104774111,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 521,
            "name": "generic_kprobe_",
            "run_cnt_delta": 3121,
            "run_time_ns_delta": 2536472,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 522,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 523,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 524,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 525,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 526,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 527,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 528,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 529,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 530,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 531,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": 875.1417575368827,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 532,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1559,
            "run_time_ns_delta": 1364346,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 533,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": 683.9967928159076,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 534,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1559,
            "run_time_ns_delta": 1066351,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 535,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 536,
            "name": "generic_retkpro",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 537,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 538,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 539,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 540,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 541,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": 1173.6833333333334,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 542,
            "name": "generic_kprobe_",
            "run_cnt_delta": 1560,
            "run_time_ns_delta": 1830946,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 543,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 544,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 545,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 546,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "547": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 547,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 548,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 549,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": 966.808074335149,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 550,
            "name": "generic_kprobe_",
            "run_cnt_delta": 3121,
            "run_time_ns_delta": 3017408,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 551,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 552,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 553,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 554,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 555,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 556,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 557,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 558,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 559,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 560,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 561,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 562,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 563,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 564,
            "name": "generic_kprobe_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.65307028899997,
            "ops_per_sec": 1039.5502944023324,
            "ops_total": 2758.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [20268] setting to a 1 secs run per stressor\nstress-ng: info:  [20268] dispatching hogs: 2 exec\nstress-ng: info:  [20268] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20268] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20268]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20268] exec               1198      1.04      2.48      0.91      1155.36         352.83\nstress-ng: info:  [20268] skipped: 0\nstress-ng: info:  [20268] passed: 2: exec (2)\nstress-ng: info:  [20268] failed: 0\nstress-ng: info:  [20268] metrics untrustworthy: 0\nstress-ng: info:  [20268] successful run completed in 1.05 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 3620878,
        "output_stripped": true,
        "program_counts": {
          "applied": 287,
          "not_applied": 0,
          "requested": 287
        }
      },
      "runner": "tetragon",
      "selected_workload": "tetragon_exec_connect_mix",
      "status": "ok"
    },
    {
      "app": "katran",
      "baseline": {
        "bpf": {
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 571,
            "name": "xdp_root",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "577": {
            "avg_ns_per_run": 50.021701388888886,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 577,
            "name": "balancer_ingress",
            "run_cnt_delta": 1152,
            "run_time_ns_delta": 57625,
            "type": "xdp"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 579,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0746318989999963,
            "ops_per_sec": 1071.9949789988543,
            "ops_total": 1152.0,
            "stderr": "{'retval': 2, 'duration_ns': 73, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 571,
            "name": "xdp_root",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "577": {
            "avg_ns_per_run": 57.5765625,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 577,
            "name": "balancer_ingress",
            "run_cnt_delta": 1280,
            "run_time_ns_delta": 73698,
            "type": "xdp"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 579,
            "name": "healthcheck_enc",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1123382270000093,
            "ops_per_sec": 1150.729129800903,
            "ops_total": 1280.0,
            "stderr": "{'retval': 2, 'duration_ns': 78, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 89603,
        "output_stripped": true,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
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
          "594": {
            "avg_ns_per_run": 146.58150124023777,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 594,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 2877674,
            "run_time_ns_delta": 421813775,
            "type": "raw_tracepoint"
          },
          "595": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 595,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 596,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "597": {
            "avg_ns_per_run": 356.5541686667086,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 597,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 2877023,
            "run_time_ns_delta": 1025814544,
            "type": "raw_tracepoint"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 598,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 599,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "600": {
            "avg_ns_per_run": 333.83215185888054,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 600,
            "name": "trace_sys_enter",
            "run_cnt_delta": 2877619,
            "run_time_ns_delta": 960641743,
            "type": "raw_tracepoint"
          },
          "601": {
            "avg_ns_per_run": 310.60001800063037,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 601,
            "name": "trace_sys_exit",
            "run_cnt_delta": 2877677,
            "run_time_ns_delta": 893806528,
            "type": "raw_tracepoint"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 602,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 603,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 604,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 605,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": 1197.9135135135134,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 606,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 221614,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": 1675.1513513513514,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 607,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 309903,
            "type": "kprobe"
          },
          "608": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 608,
            "name": "trace_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "609": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 609,
            "name": "trace_ret_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": 1224.52688172043,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 610,
            "name": "trace_dup2",
            "run_cnt_delta": 186,
            "run_time_ns_delta": 227762,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 2577.8279569892475,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 611,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 186,
            "run_time_ns_delta": 479476,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 612,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 613,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 614,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 615,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "616": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 616,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "617": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 617,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "618": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 618,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "619": {
            "avg_ns_per_run": 4421.650994575045,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 619,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 553,
            "run_time_ns_delta": 2445173,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 620,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 621,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 622,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 623,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 624,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 625,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 626,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 4760.627027027027,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 627,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 880716,
            "type": "raw_tracepoint"
          },
          "628": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 628,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "629": {
            "avg_ns_per_run": 1466.0235081374321,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 629,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 553,
            "run_time_ns_delta": 810711,
            "type": "raw_tracepoint"
          },
          "630": {
            "avg_ns_per_run": 1184.6962025316457,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 630,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 553,
            "run_time_ns_delta": 655137,
            "type": "raw_tracepoint"
          },
          "631": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 631,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "632": {
            "avg_ns_per_run": 246.35829449663768,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 632,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 283881,
            "run_time_ns_delta": 69936439,
            "type": "raw_tracepoint"
          },
          "633": {
            "avg_ns_per_run": 17.217978672417924,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 633,
            "name": "trace_filldir64",
            "run_cnt_delta": 33384,
            "run_time_ns_delta": 574805,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 634,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1319.7793851717902,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 635,
            "name": "trace_do_exit",
            "run_cnt_delta": 553,
            "run_time_ns_delta": 729838,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 636,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 637,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 638,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": 830.7459459459459,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 639,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 370,
            "run_time_ns_delta": 307376,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 640,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 641,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "642": {
            "avg_ns_per_run": 1713.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 642,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1713,
            "type": "raw_tracepoint"
          },
          "643": {
            "avg_ns_per_run": 1262.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 643,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1262,
            "type": "raw_tracepoint"
          },
          "644": {
            "avg_ns_per_run": 3235.2864864864864,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 644,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 598528,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 925.3762010347376,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 645,
            "name": "trace_security_file_open",
            "run_cnt_delta": 4059,
            "run_time_ns_delta": 3756102,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 646,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": 3331.0,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 647,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3331,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 470.16963064295487,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 648,
            "name": "trace_commit_creds",
            "run_cnt_delta": 731,
            "run_time_ns_delta": 343694,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 1007.0144665461121,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 649,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 553,
            "run_time_ns_delta": 556879,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": 154.53290279647302,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 650,
            "name": "trace_cap_capable",
            "run_cnt_delta": 66119,
            "run_time_ns_delta": 10217561,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": 922.8383152173913,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 651,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 736,
            "run_time_ns_delta": 679209,
            "type": "kprobe"
          },
          "652": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 652,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "653": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 653,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "654": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 654,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 655,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "656": {
            "avg_ns_per_run": 1661.8260869565217,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 656,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 305776,
            "type": "kprobe"
          },
          "657": {
            "avg_ns_per_run": 1624.7934782608695,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 657,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 298962,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 2115.2275280898875,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 658,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 356,
            "run_time_ns_delta": 753021,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": 1635.3152173913043,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 659,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 300898,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": 1738.6141304347825,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 660,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 319905,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 661,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 662,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "663": {
            "avg_ns_per_run": 65.29183800454496,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 663,
            "name": "trace_vfs_write",
            "run_cnt_delta": 73928,
            "run_time_ns_delta": 4826895,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 36.54969708443771,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 664,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 73948,
            "run_time_ns_delta": 2702777,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": 35.089142779881016,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 665,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 73960,
            "run_time_ns_delta": 2595193,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": 41.57468638477344,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 666,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 73976,
            "run_time_ns_delta": 3075529,
            "type": "kprobe"
          },
          "667": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 667,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "668": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 668,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "669": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 669,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": null,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 670,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": null,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 671,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "672": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 672,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "673": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 673,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "674": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 674,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 675,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": null,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 676,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "677": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 677,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "678": {
            "avg_ns_per_run": 101.72103992979378,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 678,
            "name": "trace_vfs_read",
            "run_cnt_delta": 18232,
            "run_time_ns_delta": 1854578,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": 129.505757507338,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 679,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 4429,
            "run_time_ns_delta": 573581,
            "type": "kprobe"
          },
          "680": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 680,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "681": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 681,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "682": {
            "avg_ns_per_run": null,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 682,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 683,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 196.75771370763783,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 684,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 3954,
            "run_time_ns_delta": 777980,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 134.50725552050474,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 685,
            "name": "trace_do_mmap",
            "run_cnt_delta": 3170,
            "run_time_ns_delta": 426388,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 56.099053627760256,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 686,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 3170,
            "run_time_ns_delta": 177834,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": 895.9422712933754,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 687,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 3170,
            "run_time_ns_delta": 2840137,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": 1594.8520499108733,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 688,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 561,
            "run_time_ns_delta": 894712,
            "type": "kprobe"
          },
          "689": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 689,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "690": {
            "avg_ns_per_run": 426.26507189657445,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 690,
            "name": "trace_security_bpf",
            "run_cnt_delta": 22741,
            "run_time_ns_delta": 9693694,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 691,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "692": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 692,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "693": {
            "avg_ns_per_run": 388.7079885423297,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 693,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 6284,
            "run_time_ns_delta": 2442641,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 1224.994071146245,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 694,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 506,
            "run_time_ns_delta": 619847,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 695,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 696,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 697,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 698,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 699,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": null,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 700,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 701,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "702": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 702,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "703": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 703,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 704,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "705": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 705,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "706": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 706,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 707,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 1676.9945945945947,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 708,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 370,
            "run_time_ns_delta": 620488,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 39.38897761109451,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 709,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 97057,
            "run_time_ns_delta": 3822976,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 1905.6378378378379,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 710,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 352543,
            "type": "raw_tracepoint"
          },
          "711": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 711,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "712": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 712,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "713": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 713,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "714": {
            "avg_ns_per_run": 391.24719101123594,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 714,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 89,
            "run_time_ns_delta": 34821,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 715,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 716,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 2732.7650273224044,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 717,
            "name": "trace_do_truncate",
            "run_cnt_delta": 183,
            "run_time_ns_delta": 500096,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 303.8625055334219,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 718,
            "name": "trace_fd_install",
            "run_cnt_delta": 11295,
            "run_time_ns_delta": 3432127,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 813.5658865575283,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 719,
            "name": "trace_filp_close",
            "run_cnt_delta": 17348,
            "run_time_ns_delta": 14113741,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": 549.5652173913044,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 720,
            "name": "trace_file_update_time",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 101120,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 218.6358695652174,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 721,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 40229,
            "type": "kprobe"
          },
          "722": {
            "avg_ns_per_run": null,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 722,
            "name": "trace_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "723": {
            "avg_ns_per_run": null,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 723,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "724": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 724,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "725": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 725,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 726,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "727": {
            "avg_ns_per_run": 167.46486486486486,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 727,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 30981,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": 4444.27027027027,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 728,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 822190,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": 3225.5663956639564,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 729,
            "name": "trace_execute_finished",
            "run_cnt_delta": 369,
            "run_time_ns_delta": 1190234,
            "type": "kprobe"
          },
          "730": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 730,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "731": {
            "avg_ns_per_run": 2704.0,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 731,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2704,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": 1284.0,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 732,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5136,
            "type": "kprobe"
          },
          "733": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 733,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "734": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 734,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "735": {
            "avg_ns_per_run": 521.6666666666666,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 735,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 3130,
            "type": "kprobe"
          },
          "736": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 736,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "737": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 737,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "738": {
            "avg_ns_per_run": 387.224153705398,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 738,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 1093,
            "run_time_ns_delta": 423236,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 1217.7804208600182,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 739,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 1093,
            "run_time_ns_delta": 1331034,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": 1516.5652173913043,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 740,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 279048,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": 204.2554347826087,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 741,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 37583,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 357.0652173913044,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 742,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 65700,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 1283.0146788990826,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 743,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 2180,
            "run_time_ns_delta": 2796972,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 1246.133152173913,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 745,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 1104,
            "run_time_ns_delta": 1375731,
            "type": "cgroup_skb"
          },
          "746": {
            "avg_ns_per_run": 1703.7590579710145,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 746,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 1104,
            "run_time_ns_delta": 1880950,
            "type": "cgroup_skb"
          },
          "747": {
            "avg_ns_per_run": 2622.0,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 747,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2622,
            "type": "raw_tracepoint"
          },
          "748": {
            "avg_ns_per_run": 762.0,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 748,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 762,
            "type": "raw_tracepoint"
          },
          "749": {
            "avg_ns_per_run": 171.7891891891892,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 749,
            "name": "empty_kprobe",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 31781,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": 938.0756756756757,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 750,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 185,
            "run_time_ns_delta": 173544,
            "type": "raw_tracepoint"
          },
          "751": {
            "avg_ns_per_run": 432.8460211874846,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 751,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 4059,
            "run_time_ns_delta": 1756922,
            "type": "lsm"
          },
          "752": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 752,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.015541482999993,
            "ops_per_sec": 36.68596912689522,
            "ops_total": 184.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "prog 689: BPF_PROG_REJIT: Invalid argument (os error 22)",
      "post_rejit": {
        "bpf": {
          "594": {
            "avg_ns_per_run": 162.47460781285542,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 594,
            "name": "tracepoint__raw",
            "run_cnt_delta": 2334281,
            "run_time_ns_delta": 379261390,
            "type": "raw_tracepoint"
          },
          "595": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 595,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 17415,
            "bytes_xlated": 30288,
            "id": 596,
            "name": "sys_enter_submi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "597": {
            "avg_ns_per_run": 396.3064785536898,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 597,
            "name": "tracepoint__raw",
            "run_cnt_delta": 2334271,
            "run_time_ns_delta": 925086720,
            "type": "raw_tracepoint"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 598,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 11545,
            "bytes_xlated": 19792,
            "id": 599,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "600": {
            "avg_ns_per_run": 370.2226282359079,
            "bytes_jited": 8131,
            "bytes_xlated": 13608,
            "id": 600,
            "name": "trace_sys_enter",
            "run_cnt_delta": 2334623,
            "run_time_ns_delta": 864330263,
            "type": "raw_tracepoint"
          },
          "601": {
            "avg_ns_per_run": 334.2468217031688,
            "bytes_jited": 8164,
            "bytes_xlated": 13664,
            "id": 601,
            "name": "trace_sys_exit",
            "run_cnt_delta": 2334977,
            "run_time_ns_delta": 780458641,
            "type": "raw_tracepoint"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 602,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 603,
            "name": "trace_ret_ptrac",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 604,
            "name": "trace_process_v",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 605,
            "name": "trace_ret_proce",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": 1467.7951807228915,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 606,
            "name": "trace_arch_prct",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 243654,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": 2200.8493975903616,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 607,
            "name": "trace_ret_arch_",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 365341,
            "type": "kprobe"
          },
          "608": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 608,
            "name": "trace_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "609": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 609,
            "name": "trace_ret_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": 1680.5748502994013,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 610,
            "name": "trace_dup2",
            "run_cnt_delta": 167,
            "run_time_ns_delta": 280656,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 3277.8263473053894,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 611,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 167,
            "run_time_ns_delta": 547397,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 612,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": null,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 613,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 20725,
            "bytes_xlated": 31976,
            "id": 614,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 20696,
            "bytes_xlated": 31992,
            "id": 615,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "616": {
            "avg_ns_per_run": null,
            "bytes_jited": 21000,
            "bytes_xlated": 32400,
            "id": 616,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "617": {
            "avg_ns_per_run": null,
            "bytes_jited": 20968,
            "bytes_xlated": 32408,
            "id": 617,
            "name": "syscall__execve",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "618": {
            "avg_ns_per_run": null,
            "bytes_jited": 12211,
            "bytes_xlated": 18576,
            "id": 618,
            "name": "sys_dup_exit_ta",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "619": {
            "avg_ns_per_run": 8338.179435483871,
            "bytes_jited": 19847,
            "bytes_xlated": 32320,
            "id": 619,
            "name": "tracepoint__sch",
            "run_cnt_delta": 496,
            "run_time_ns_delta": 4135737,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 620,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": null,
            "bytes_jited": 6021,
            "bytes_xlated": 9904,
            "id": 621,
            "name": "uprobe_lkm_seek",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": null,
            "bytes_jited": 4308,
            "bytes_xlated": 7696,
            "id": 622,
            "name": "uprobe_lkm_seek",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 623,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 648,
            "bytes_xlated": 1040,
            "id": 624,
            "name": "lkm_seeker_mod_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 625,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": null,
            "bytes_jited": 3772,
            "bytes_xlated": 6224,
            "id": 626,
            "name": "lkm_seeker_new_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 5723.987951807229,
            "bytes_jited": 20525,
            "bytes_xlated": 35336,
            "id": 627,
            "name": "tracepoint__sch",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 950182,
            "type": "raw_tracepoint"
          },
          "628": {
            "avg_ns_per_run": null,
            "bytes_jited": 23905,
            "bytes_xlated": 37632,
            "id": 628,
            "name": "sched_process_e",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "629": {
            "avg_ns_per_run": 2270.122983870968,
            "bytes_jited": 8680,
            "bytes_xlated": 14464,
            "id": 629,
            "name": "tracepoint__sch",
            "run_cnt_delta": 496,
            "run_time_ns_delta": 1125981,
            "type": "raw_tracepoint"
          },
          "630": {
            "avg_ns_per_run": 1454.9556451612902,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 630,
            "name": "tracepoint__sch",
            "run_cnt_delta": 496,
            "run_time_ns_delta": 721658,
            "type": "raw_tracepoint"
          },
          "631": {
            "avg_ns_per_run": null,
            "bytes_jited": 9084,
            "bytes_xlated": 13696,
            "id": 631,
            "name": "syscall__accept",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "632": {
            "avg_ns_per_run": 340.08917611239855,
            "bytes_jited": 8925,
            "bytes_xlated": 14840,
            "id": 632,
            "name": "tracepoint__sch",
            "run_cnt_delta": 206266,
            "run_time_ns_delta": 70148834,
            "type": "raw_tracepoint"
          },
          "633": {
            "avg_ns_per_run": 23.907692307692308,
            "bytes_jited": 8163,
            "bytes_xlated": 13680,
            "id": 633,
            "name": "trace_filldir64",
            "run_cnt_delta": 195,
            "run_time_ns_delta": 4662,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": null,
            "bytes_jited": 23491,
            "bytes_xlated": 36696,
            "id": 634,
            "name": "trace_call_user",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1767.6149193548388,
            "bytes_jited": 7921,
            "bytes_xlated": 13312,
            "id": 635,
            "name": "trace_do_exit",
            "run_cnt_delta": 496,
            "run_time_ns_delta": 876737,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 636,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": null,
            "bytes_jited": 6749,
            "bytes_xlated": 11160,
            "id": 637,
            "name": "uprobe_seq_ops_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": null,
            "bytes_jited": 6533,
            "bytes_xlated": 10904,
            "id": 638,
            "name": "uprobe_mem_dump",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": 880.9548192771084,
            "bytes_jited": 11470,
            "bytes_xlated": 18264,
            "id": 639,
            "name": "trace_security_",
            "run_cnt_delta": 332,
            "run_time_ns_delta": 292477,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": null,
            "bytes_jited": 9740,
            "bytes_xlated": 15632,
            "id": 640,
            "name": "trace_tracepoin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": null,
            "bytes_jited": 8620,
            "bytes_xlated": 14352,
            "id": 641,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "642": {
            "avg_ns_per_run": 1876.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 642,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1876,
            "type": "raw_tracepoint"
          },
          "643": {
            "avg_ns_per_run": 1169.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 643,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1169,
            "type": "raw_tracepoint"
          },
          "644": {
            "avg_ns_per_run": 3951.475903614458,
            "bytes_jited": 33373,
            "bytes_xlated": 52824,
            "id": 644,
            "name": "trace_security_",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 655945,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 1759.832712215321,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 645,
            "name": "trace_security_file_open",
            "run_cnt_delta": 2415,
            "run_time_ns_delta": 4249996,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": null,
            "bytes_jited": 18607,
            "bytes_xlated": 30576,
            "id": 646,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": 4255.0,
            "bytes_jited": 9984,
            "bytes_xlated": 16352,
            "id": 647,
            "name": "trace_security_",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4255,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 1732.9397590361446,
            "bytes_jited": 10723,
            "bytes_xlated": 16880,
            "id": 648,
            "name": "trace_commit_cr",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 287668,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 1614.725806451613,
            "bytes_jited": 10045,
            "bytes_xlated": 16520,
            "id": 649,
            "name": "trace_switch_ta",
            "run_cnt_delta": 496,
            "run_time_ns_delta": 800904,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": 162.85408667981045,
            "bytes_jited": 8174,
            "bytes_xlated": 13680,
            "id": 650,
            "name": "trace_cap_capab",
            "run_cnt_delta": 57822,
            "run_time_ns_delta": 9416549,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": 1124.4878787878788,
            "bytes_jited": 8471,
            "bytes_xlated": 14120,
            "id": 651,
            "name": "trace_security_",
            "run_cnt_delta": 660,
            "run_time_ns_delta": 742162,
            "type": "kprobe"
          },
          "652": {
            "avg_ns_per_run": null,
            "bytes_jited": 9144,
            "bytes_xlated": 15208,
            "id": 652,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "653": {
            "avg_ns_per_run": null,
            "bytes_jited": 8276,
            "bytes_xlated": 13824,
            "id": 653,
            "name": "trace_proc_crea",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "654": {
            "avg_ns_per_run": null,
            "bytes_jited": 9497,
            "bytes_xlated": 15760,
            "id": 654,
            "name": "trace_debugfs_c",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": null,
            "bytes_jited": 9197,
            "bytes_xlated": 15328,
            "id": 655,
            "name": "trace_debugfs_c",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "656": {
            "avg_ns_per_run": 2157.5030303030303,
            "bytes_jited": 10780,
            "bytes_xlated": 16456,
            "id": 656,
            "name": "trace_security_",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 355988,
            "type": "kprobe"
          },
          "657": {
            "avg_ns_per_run": 2061.2848484848487,
            "bytes_jited": 10075,
            "bytes_xlated": 15400,
            "id": 657,
            "name": "trace_security_",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 340112,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 2935.508038585209,
            "bytes_jited": 11260,
            "bytes_xlated": 17192,
            "id": 658,
            "name": "trace_security_",
            "run_cnt_delta": 311,
            "run_time_ns_delta": 912943,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": 2068.7939393939396,
            "bytes_jited": 10589,
            "bytes_xlated": 16080,
            "id": 659,
            "name": "trace_security_",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 341351,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": 2291.151515151515,
            "bytes_jited": 11025,
            "bytes_xlated": 16864,
            "id": 660,
            "name": "trace_security_",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 378040,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 661,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 662,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "663": {
            "avg_ns_per_run": 82.36015947783869,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 663,
            "name": "trace_vfs_write",
            "run_cnt_delta": 62203,
            "run_time_ns_delta": 5123049,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 42.782261954529375,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 664,
            "name": "vfs_write_magic",
            "run_cnt_delta": 62194,
            "run_time_ns_delta": 2660800,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": 39.23190712781181,
            "bytes_jited": 19108,
            "bytes_xlated": 31720,
            "id": 665,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 62193,
            "run_time_ns_delta": 2439950,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": 54.68237165071002,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 666,
            "name": "vfs_write_magic",
            "run_cnt_delta": 62252,
            "run_time_ns_delta": 3404087,
            "type": "kprobe"
          },
          "667": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 667,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "668": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 668,
            "name": "trace_vfs_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "669": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 669,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": null,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 670,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": null,
            "bytes_jited": 23786,
            "bytes_xlated": 36696,
            "id": 671,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "672": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 672,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "673": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 673,
            "name": "trace_kernel_wr",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "674": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 674,
            "name": "kernel_write_ma",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": null,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 675,
            "name": "trace_ret_kerne",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": null,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 676,
            "name": "kernel_write_ma",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "677": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 677,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "678": {
            "avg_ns_per_run": 160.90828605810555,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 678,
            "name": "trace_vfs_read",
            "run_cnt_delta": 11634,
            "run_time_ns_delta": 1872007,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": 245.3351886209029,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 679,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 3234,
            "run_time_ns_delta": 793414,
            "type": "kprobe"
          },
          "680": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 680,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "681": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 681,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "682": {
            "avg_ns_per_run": null,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 682,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 683,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 294.840311587147,
            "bytes_jited": 20715,
            "bytes_xlated": 32736,
            "id": 684,
            "name": "trace_mmap_aler",
            "run_cnt_delta": 3081,
            "run_time_ns_delta": 908403,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 181.6421052631579,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 685,
            "name": "trace_do_mmap",
            "run_cnt_delta": 2850,
            "run_time_ns_delta": 517680,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 86.3698245614035,
            "bytes_jited": 19426,
            "bytes_xlated": 31584,
            "id": 686,
            "name": "trace_ret_do_mm",
            "run_cnt_delta": 2850,
            "run_time_ns_delta": 246154,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": 1071.7666666666667,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 687,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 2850,
            "run_time_ns_delta": 3054535,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": 1923.7017892644135,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 688,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 503,
            "run_time_ns_delta": 967622,
            "type": "kprobe"
          },
          "689": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 689,
            "name": "syscall__init_m",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "690": {
            "avg_ns_per_run": 407.108557186375,
            "bytes_jited": 15585,
            "bytes_xlated": 26904,
            "id": 690,
            "name": "trace_security_",
            "run_cnt_delta": 21666,
            "run_time_ns_delta": 8820414,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 691,
            "name": "trace_register_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "692": {
            "avg_ns_per_run": null,
            "bytes_jited": 8807,
            "bytes_xlated": 14640,
            "id": 692,
            "name": "trace_ret_regis",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "693": {
            "avg_ns_per_run": 302.94763376158727,
            "bytes_jited": 8333,
            "bytes_xlated": 13904,
            "id": 693,
            "name": "trace_security_",
            "run_cnt_delta": 6149,
            "run_time_ns_delta": 1862825,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 1238.2747035573123,
            "bytes_jited": 9581,
            "bytes_xlated": 15448,
            "id": 694,
            "name": "trace_security_",
            "run_cnt_delta": 506,
            "run_time_ns_delta": 626567,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": null,
            "bytes_jited": 6345,
            "bytes_xlated": 10528,
            "id": 695,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": null,
            "bytes_jited": 6581,
            "bytes_xlated": 11008,
            "id": 696,
            "name": "trace_check_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": null,
            "bytes_jited": 6587,
            "bytes_xlated": 11016,
            "id": 697,
            "name": "trace_check_hel",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": null,
            "bytes_jited": 18641,
            "bytes_xlated": 30648,
            "id": 698,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": null,
            "bytes_jited": 17247,
            "bytes_xlated": 30448,
            "id": 699,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": null,
            "bytes_jited": 9225,
            "bytes_xlated": 15352,
            "id": 700,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": null,
            "bytes_jited": 8647,
            "bytes_xlated": 14344,
            "id": 701,
            "name": "trace_device_ad",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "702": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 702,
            "name": "trace___registe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "703": {
            "avg_ns_per_run": null,
            "bytes_jited": 8814,
            "bytes_xlated": 14632,
            "id": 703,
            "name": "trace_ret__regi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": null,
            "bytes_jited": 19868,
            "bytes_xlated": 32648,
            "id": 704,
            "name": "tracepoint__mod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "705": {
            "avg_ns_per_run": null,
            "bytes_jited": 8959,
            "bytes_xlated": 14920,
            "id": 705,
            "name": "tracepoint__mod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "706": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 706,
            "name": "trace_do_init_m",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": null,
            "bytes_jited": 14542,
            "bytes_xlated": 23904,
            "id": 707,
            "name": "trace_ret_do_in",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 2014.948795180723,
            "bytes_jited": 18482,
            "bytes_xlated": 30352,
            "id": 708,
            "name": "trace_load_elf_",
            "run_cnt_delta": 332,
            "run_time_ns_delta": 668963,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 48.45037066194319,
            "bytes_jited": 8681,
            "bytes_xlated": 14496,
            "id": 709,
            "name": "trace_security_",
            "run_cnt_delta": 76215,
            "run_time_ns_delta": 3692645,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 3043.144578313253,
            "bytes_jited": 8474,
            "bytes_xlated": 14112,
            "id": 710,
            "name": "tracepoint__tas",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 505162,
            "type": "raw_tracepoint"
          },
          "711": {
            "avg_ns_per_run": null,
            "bytes_jited": 9792,
            "bytes_xlated": 16344,
            "id": 711,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "712": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 712,
            "name": "trace_kallsyms_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "713": {
            "avg_ns_per_run": null,
            "bytes_jited": 8406,
            "bytes_xlated": 14024,
            "id": 713,
            "name": "trace_ret_kalls",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "714": {
            "avg_ns_per_run": 445.95238095238096,
            "bytes_jited": 10109,
            "bytes_xlated": 16296,
            "id": 714,
            "name": "trace_do_sigact",
            "run_cnt_delta": 63,
            "run_time_ns_delta": 28095,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": null,
            "bytes_jited": 18560,
            "bytes_xlated": 30528,
            "id": 715,
            "name": "trace_vfs_utime",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": null,
            "bytes_jited": 18560,
            "bytes_xlated": 30528,
            "id": 716,
            "name": "trace_utimes_co",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 3372.737804878049,
            "bytes_jited": 9530,
            "bytes_xlated": 15824,
            "id": 717,
            "name": "trace_do_trunca",
            "run_cnt_delta": 164,
            "run_time_ns_delta": 553129,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 438.05823645536304,
            "bytes_jited": 16708,
            "bytes_xlated": 27176,
            "id": 718,
            "name": "trace_fd_instal",
            "run_cnt_delta": 9118,
            "run_time_ns_delta": 3994215,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 1086.1125176712505,
            "bytes_jited": 16636,
            "bytes_xlated": 27024,
            "id": 719,
            "name": "trace_filp_clos",
            "run_cnt_delta": 15562,
            "run_time_ns_delta": 16902083,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": 1079.9101796407185,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 720,
            "name": "trace_file_upda",
            "run_cnt_delta": 167,
            "run_time_ns_delta": 180345,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 417.622754491018,
            "bytes_jited": 20054,
            "bytes_xlated": 31168,
            "id": 721,
            "name": "trace_ret_file_",
            "run_cnt_delta": 167,
            "run_time_ns_delta": 69743,
            "type": "kprobe"
          },
          "722": {
            "avg_ns_per_run": null,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 722,
            "name": "trace_file_modi",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "723": {
            "avg_ns_per_run": null,
            "bytes_jited": 20140,
            "bytes_xlated": 31288,
            "id": 723,
            "name": "trace_ret_file_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "724": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 724,
            "name": "trace_inotify_f",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "725": {
            "avg_ns_per_run": null,
            "bytes_jited": 18025,
            "bytes_xlated": 29936,
            "id": 725,
            "name": "trace_ret_inoti",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": null,
            "bytes_jited": 12830,
            "bytes_xlated": 20080,
            "id": 726,
            "name": "process_execute",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "727": {
            "avg_ns_per_run": 338.68674698795184,
            "bytes_jited": 16472,
            "bytes_xlated": 28872,
            "id": 727,
            "name": "trace_exec_binp",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 56222,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": 5823.3975903614455,
            "bytes_jited": 16702,
            "bytes_xlated": 29144,
            "id": 728,
            "name": "trace_security_",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 966684,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": 4549.969788519637,
            "bytes_jited": 24469,
            "bytes_xlated": 38320,
            "id": 729,
            "name": "trace_execute_f",
            "run_cnt_delta": 331,
            "run_time_ns_delta": 1506040,
            "type": "kprobe"
          },
          "730": {
            "avg_ns_per_run": null,
            "bytes_jited": 18391,
            "bytes_xlated": 30200,
            "id": 730,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "731": {
            "avg_ns_per_run": 2648.0,
            "bytes_jited": 18194,
            "bytes_xlated": 29912,
            "id": 731,
            "name": "trace_set_fs_pw",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2648,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": 1159.8,
            "bytes_jited": 8631,
            "bytes_xlated": 14360,
            "id": 732,
            "name": "trace_security_",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 11598,
            "type": "kprobe"
          },
          "733": {
            "avg_ns_per_run": null,
            "bytes_jited": 8656,
            "bytes_xlated": 14416,
            "id": 733,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "734": {
            "avg_ns_per_run": null,
            "bytes_jited": 17561,
            "bytes_xlated": 29176,
            "id": 734,
            "name": "trace_chmod_com",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "735": {
            "avg_ns_per_run": 558.8333333333334,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 735,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 3353,
            "type": "kprobe"
          },
          "736": {
            "avg_ns_per_run": null,
            "bytes_jited": 14861,
            "bytes_xlated": 23928,
            "id": 736,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "737": {
            "avg_ns_per_run": null,
            "bytes_jited": 9482,
            "bytes_xlated": 15760,
            "id": 737,
            "name": "trace_security_",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "738": {
            "avg_ns_per_run": 512.058762886598,
            "bytes_jited": 329,
            "bytes_xlated": 520,
            "id": 738,
            "name": "trace_sock_allo",
            "run_cnt_delta": 970,
            "run_time_ns_delta": 496697,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 1541.7855670103093,
            "bytes_jited": 8439,
            "bytes_xlated": 12928,
            "id": 739,
            "name": "trace_ret_sock_",
            "run_cnt_delta": 970,
            "run_time_ns_delta": 1495532,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": 1959.290909090909,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 740,
            "name": "trace_security_",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 323283,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": 453.4969696969697,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 741,
            "name": "trace_security_",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 74827,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 554.3515151515152,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 742,
            "name": "trace_security_",
            "run_cnt_delta": 165,
            "run_time_ns_delta": 91468,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 1629.3454081632653,
            "bytes_jited": 5282,
            "bytes_xlated": 8136,
            "id": 743,
            "name": "cgroup_bpf_run_",
            "run_cnt_delta": 1960,
            "run_time_ns_delta": 3193517,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 1474.4185110663984,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 745,
            "name": "cgroup_skb_ingr",
            "run_cnt_delta": 994,
            "run_time_ns_delta": 1465572,
            "type": "cgroup_skb"
          },
          "746": {
            "avg_ns_per_run": 2412.9024144869213,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 746,
            "name": "cgroup_skb_egre",
            "run_cnt_delta": 994,
            "run_time_ns_delta": 2398425,
            "type": "cgroup_skb"
          },
          "747": {
            "avg_ns_per_run": 2347.0,
            "bytes_jited": 916,
            "bytes_xlated": 1560,
            "id": 747,
            "name": "cgroup_mkdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2347,
            "type": "raw_tracepoint"
          },
          "748": {
            "avg_ns_per_run": 679.0,
            "bytes_jited": 898,
            "bytes_xlated": 1520,
            "id": 748,
            "name": "cgroup_rmdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 679,
            "type": "raw_tracepoint"
          },
          "749": {
            "avg_ns_per_run": 119.34939759036145,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 749,
            "name": "empty_kprobe",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 19812,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": 1166.198795180723,
            "bytes_jited": 58660,
            "bytes_xlated": 95944,
            "id": 750,
            "name": "tracepoint__exe",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 193589,
            "type": "raw_tracepoint"
          },
          "751": {
            "avg_ns_per_run": 784.9859213250518,
            "bytes_jited": 7290,
            "bytes_xlated": 13264,
            "id": 751,
            "name": "lsm_file_open_t",
            "run_cnt_delta": 2415,
            "run_time_ns_delta": 1895741,
            "type": "lsm"
          },
          "752": {
            "avg_ns_per_run": null,
            "bytes_jited": 5359,
            "bytes_xlated": 9080,
            "id": 752,
            "name": "uprobe__feature",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.004649644999972,
            "ops_per_sec": 32.96934085382932,
            "ops_total": 165.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "applied_site_totals": {
          "bitfield_sites": 37,
          "bounds_check_merge_sites": 0,
          "branch_flip_sites": 0,
          "bulk_memory_sites": 109,
          "cmov_sites": 1,
          "const_prop_sites": 299,
          "dce_sites": 1301,
          "endian_sites": 4,
          "extract_sites": 37,
          "lea_sites": 0,
          "map_inline_sites": 141,
          "other_sites": 0,
          "rotate_sites": 0,
          "skb_load_bytes_spec_sites": 0,
          "total_sites": 2073,
          "wide_sites": 181
        },
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
        "error": "prog 689: BPF_PROG_REJIT: Invalid argument (os error 22)",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "BPF_PROG_REJIT: Invalid argument (os error 22)",
            "exit_code": 1,
            "prog_id": 689
          }
        ],
        "exit_code": 1,
        "output_chars": 2254125,
        "output_stripped": true,
        "program_counts": {
          "applied": 157,
          "not_applied": 1,
          "requested": 158
        }
      },
      "runner": "tracee",
      "selected_workload": "tracee_system_edge_mix",
      "status": "error"
    },
    {
      "app": "bpftrace/capable",
      "baseline": {
        "bpf": {
          "758": {
            "avg_ns_per_run": 109.38633420121504,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 758,
            "name": "cap_capable",
            "run_cnt_delta": 149790,
            "run_time_ns_delta": 16384979,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.079162354999994,
            "ops_per_sec": 1113.826843969188,
            "ops_total": 1202.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [32342] setting to a 1 secs run per stressor\nstress-ng: info:  [32342] dispatching hogs: 2 exec\nstress-ng: info:  [32342] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [32342] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [32342]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32342] exec               1202      1.04      2.45      0.91      1156.80         357.17\nstress-ng: info:  [32342] skipped: 0\nstress-ng: info:  [32342] passed: 2: exec (2)\nstress-ng: info:  [32342] failed: 0\nstress-ng: info:  [32342] metrics untrustworthy: 0\nstress-ng: info:  [32342] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "758": {
            "avg_ns_per_run": 129.41389344074,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 758,
            "name": "cap_capable",
            "run_cnt_delta": 130594,
            "run_time_ns_delta": 16900678,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0750506760000462,
            "ops_per_sec": 972.0472004986257,
            "ops_total": 1045.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [22587] setting to a 1 secs run per stressor\nstress-ng: info:  [22587] dispatching hogs: 2 exec\nstress-ng: info:  [22587] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [22587] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22587]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22587] exec               1045      1.03      2.38      0.93      1011.73         315.75\nstress-ng: info:  [22587] skipped: 0\nstress-ng: info:  [22587] passed: 2: exec (2)\nstress-ng: info:  [22587] failed: 0\nstress-ng: info:  [22587] metrics untrustworthy: 0\nstress-ng: info:  [22587] successful run completed in 1.05 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 5258,
        "output_stripped": true,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "exec_storm",
      "status": "ok"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline": {
        "bpf": {
          "764": {
            "avg_ns_per_run": 179.326171875,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 764,
            "name": "block_io_start",
            "run_cnt_delta": 368640,
            "run_time_ns_delta": 66106800,
            "type": "tracepoint"
          },
          "765": {
            "avg_ns_per_run": 284.0650119357639,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 765,
            "name": "block_io_done",
            "run_cnt_delta": 368640,
            "run_time_ns_delta": 104717726,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.061148192000019,
            "ops_per_sec": 72837.227051106,
            "ops_total": 368640.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "764": {
            "avg_ns_per_run": 257.17417454075166,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 764,
            "name": "block_io_start",
            "run_cnt_delta": 303104,
            "run_time_ns_delta": 77950521,
            "type": "tracepoint"
          },
          "765": {
            "avg_ns_per_run": 351.9539695945946,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 765,
            "name": "block_io_done",
            "run_cnt_delta": 303104,
            "run_time_ns_delta": 106678656,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.09713122200003,
            "ops_per_sec": 59465.606592931115,
            "ops_total": 303104.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 12592,
        "output_stripped": true,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bpftrace",
      "selected_workload": "block_io",
      "status": "ok"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline": {
        "bpf": {
          "771": {
            "avg_ns_per_run": 1377.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 771,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1377,
            "type": "perf_event"
          },
          "772": {
            "avg_ns_per_run": 45.96949650863653,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 772,
            "name": "vfs_create",
            "run_cnt_delta": 19047,
            "run_time_ns_delta": 875581,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0112380900000062,
            "ops_per_sec": 79.11094409032744,
            "ops_total": 80.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "771": {
            "avg_ns_per_run": 1629.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 771,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1629,
            "type": "perf_event"
          },
          "772": {
            "avg_ns_per_run": 62.34661551109893,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 772,
            "name": "vfs_create",
            "run_cnt_delta": 18245,
            "run_time_ns_delta": 1137514,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0047304370000347,
            "ops_per_sec": 80.61863860903141,
            "ops_total": 81.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 8218,
        "output_stripped": true,
        "program_counts": {
          "applied": 2,
          "not_applied": 0,
          "requested": 2
        }
      },
      "runner": "bpftrace",
      "selected_workload": "vfs_create_write_fsync",
      "status": "ok"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline": {
        "bpf": {
          "778": {
            "avg_ns_per_run": 99.86229844314707,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 778,
            "name": "sched_wakeup",
            "run_cnt_delta": 57552,
            "run_time_ns_delta": 5747275,
            "type": "tracepoint"
          },
          "779": {
            "avg_ns_per_run": 207.55601659751036,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 779,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 3856,
            "run_time_ns_delta": 800336,
            "type": "tracepoint"
          },
          "780": {
            "avg_ns_per_run": 157.61468502114928,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 780,
            "name": "sched_switch",
            "run_cnt_delta": 92911,
            "run_time_ns_delta": 14644138,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0685427629999822,
            "ops_per_sec": 14.037809734340271,
            "ops_total": 15.0,
            "stderr": "",
            "stdout": "Time: 0.051\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.053\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.063\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.042\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.044\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.058\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.045"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "778": {
            "avg_ns_per_run": 121.34776636078905,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 778,
            "name": "sched_wakeup",
            "run_cnt_delta": 54597,
            "run_time_ns_delta": 6625224,
            "type": "tracepoint"
          },
          "779": {
            "avg_ns_per_run": 256.21037277147485,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 779,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 3085,
            "run_time_ns_delta": 790409,
            "type": "tracepoint"
          },
          "780": {
            "avg_ns_per_run": 188.2003861183476,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 780,
            "name": "sched_switch",
            "run_cnt_delta": 85984,
            "run_time_ns_delta": 16182222,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0434688500000675,
            "ops_per_sec": 11.50010371655965,
            "ops_total": 12.0,
            "stderr": "",
            "stdout": "Running in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.048\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.053\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.064\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.051\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.056\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.064\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.040\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.055\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.065\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 13107,
        "output_stripped": true,
        "program_counts": {
          "applied": 3,
          "not_applied": 0,
          "requested": 3
        }
      },
      "runner": "bpftrace",
      "selected_workload": "hackbench",
      "status": "ok"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline": {
        "bpf": {
          "787": {
            "avg_ns_per_run": 953.2543046357616,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 787,
            "name": "tcp_set_state",
            "run_cnt_delta": 755,
            "run_time_ns_delta": 719707,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.016578012000025,
            "ops_per_sec": 74.76061758455398,
            "ops_total": 76.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "787": {
            "avg_ns_per_run": 1088.1556291390727,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 787,
            "name": "tcp_set_state",
            "run_cnt_delta": 604,
            "run_time_ns_delta": 657246,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.010674033999976,
            "ops_per_sec": 60.35576055969144,
            "ops_total": 61.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 7022,
        "output_stripped": true,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "network",
      "status": "ok"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline": {
        "bpf": {
          "793": {
            "avg_ns_per_run": 5407.882352941177,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 793,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 17,
            "run_time_ns_delta": 91934,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.270864811999957,
            "ops_per_sec": 0.4836253633594055,
            "ops_total": 4.0,
            "stderr": "failed_cycles=3",
            "stdout": "successful_cycles=1"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "793": {
            "avg_ns_per_run": 8451.368421052632,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 793,
            "name": "tcp_retransmit_",
            "run_cnt_delta": 19,
            "run_time_ns_delta": 160576,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.250335684999982,
            "ops_per_sec": 0.4848287576070923,
            "ops_total": 4.0,
            "stderr": "failed_cycles=3",
            "stdout": "successful_cycles=1"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
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
        "output_chars": 5739,
        "output_stripped": true,
        "program_counts": {
          "applied": 1,
          "not_applied": 0,
          "requested": 1
        }
      },
      "runner": "bpftrace",
      "selected_workload": "tcp_retransmit",
      "status": "ok"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 129,
    "per_program_geomean": 1.2386711586504822,
    "program_count": 140,
    "wins": 11
  },
  "workload_seconds": 1.0
}
```
