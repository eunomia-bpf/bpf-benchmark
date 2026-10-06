# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-27T23:51:24.583235+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-27T23:42:54.534150+00:00",
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
      "invoked_at": "2026-04-27T23:42:54.534082+00:00",
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
        "captured_at": "2026-04-27T23:42:54.534075+00:00",
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
      "captured_at": "2026-04-27T23:42:54.527669+00:00",
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
      "baseline_avg_ns_per_run": 95.45226672741649,
      "baseline_run_cnt_delta": 149246,
      "baseline_run_time_ns_delta": 14245869,
      "post_rejit_avg_ns_per_run": 53.9468967062514,
      "post_rejit_run_cnt_delta": 169594,
      "post_rejit_run_time_ns_delta": 9149070,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 0.5651714574815475,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 2076.930276981853,
      "baseline_run_cnt_delta": 1047,
      "baseline_run_time_ns_delta": 2174546,
      "post_rejit_avg_ns_per_run": 1847.0423666910153,
      "post_rejit_run_cnt_delta": 1369,
      "post_rejit_run_time_ns_delta": 2528601,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 0.8893136120944295,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 1478.9153225806451,
      "baseline_run_cnt_delta": 992,
      "baseline_run_time_ns_delta": 1467084,
      "post_rejit_avg_ns_per_run": 1623.752911813644,
      "post_rejit_run_cnt_delta": 1202,
      "post_rejit_run_time_ns_delta": 1951751,
      "program": "do_ret_sys_exec",
      "program_id": 10,
      "ratio": 1.0979350115733897,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 59.56498904254515,
      "baseline_run_cnt_delta": 26466,
      "baseline_run_time_ns_delta": 1576447,
      "post_rejit_avg_ns_per_run": 51.62315071020107,
      "post_rejit_run_cnt_delta": 54210,
      "post_rejit_run_time_ns_delta": 2798491,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 0.8666693562778713,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 778.3137610519157,
      "baseline_run_cnt_delta": 13233,
      "baseline_run_time_ns_delta": 10299426,
      "post_rejit_avg_ns_per_run": 801.9406751521859,
      "post_rejit_run_cnt_delta": 27105,
      "post_rejit_run_time_ns_delta": 21736602,
      "program": "bindsnoop_v4_re",
      "program_id": 14,
      "ratio": 1.0303565416450273,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 768.6967429910073,
      "baseline_run_cnt_delta": 13233,
      "baseline_run_time_ns_delta": 10172164,
      "post_rejit_avg_ns_per_run": 804.9411547684929,
      "post_rejit_run_cnt_delta": 27105,
      "post_rejit_run_time_ns_delta": 21817930,
      "program": "bindsnoop_v6_re",
      "program_id": 15,
      "ratio": 1.0471504687745368,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "bind_storm"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 157.1659420766156,
      "baseline_run_cnt_delta": 319491,
      "baseline_run_time_ns_delta": 50213104,
      "post_rejit_avg_ns_per_run": 111.79552472654981,
      "post_rejit_run_cnt_delta": 745474,
      "post_rejit_run_time_ns_delta": 83340657,
      "program": "trace_pid_start",
      "program_id": 18,
      "ratio": 0.7113215703695619,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 180.61814260808598,
      "baseline_run_cnt_delta": 319491,
      "baseline_run_time_ns_delta": 57705871,
      "post_rejit_avg_ns_per_run": 132.33642129324082,
      "post_rejit_run_cnt_delta": 745476,
      "post_rejit_run_time_ns_delta": 98653626,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 0.7326862040674995,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "block_io"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 381.6263149822687,
      "baseline_run_cnt_delta": 319491,
      "baseline_run_time_ns_delta": 121926173,
      "post_rejit_avg_ns_per_run": 343.21848561390897,
      "post_rejit_run_cnt_delta": 745477,
      "post_rejit_run_time_ns_delta": 255861487,
      "program": "trace_req_compl",
      "program_id": 20,
      "ratio": 0.8993574922364977,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 32.28648648648649,
      "baseline_run_cnt_delta": 555,
      "baseline_run_time_ns_delta": 17919,
      "post_rejit_avg_ns_per_run": 53.39923954372624,
      "post_rejit_run_cnt_delta": 263,
      "post_rejit_run_time_ns_delta": 14044,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 1.6539191889484939,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 32.15847979570377,
      "baseline_run_cnt_delta": 6657,
      "baseline_run_time_ns_delta": 214079,
      "post_rejit_avg_ns_per_run": 35.55666063893912,
      "post_rejit_run_cnt_delta": 3318,
      "post_rejit_run_time_ns_delta": 117977,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.1056698222311283,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 27.04390913248971,
      "baseline_run_cnt_delta": 13118,
      "baseline_run_time_ns_delta": 354762,
      "post_rejit_avg_ns_per_run": 29.036638716733503,
      "post_rejit_run_cnt_delta": 5486,
      "post_rejit_run_time_ns_delta": 159295,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 1.0736849681930705,
      "runner": "bcc",
      "type": "tracing",
      "workload": "vfs_create_fsync_exact"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 1320.3156668608037,
      "baseline_run_cnt_delta": 1717,
      "baseline_run_time_ns_delta": 2266982,
      "post_rejit_avg_ns_per_run": 1505.2947067238913,
      "post_rejit_run_cnt_delta": 2097,
      "post_rejit_run_time_ns_delta": 3156603,
      "program": "__x64_sys_opena",
      "program_id": 31,
      "ratio": 1.1401021320173346,
      "runner": "bcc",
      "type": "tracing",
      "workload": "open_family_storm"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 1315.0923076923077,
      "baseline_run_cnt_delta": 585,
      "baseline_run_time_ns_delta": 769329,
      "post_rejit_avg_ns_per_run": 1616.0989130434782,
      "post_rejit_run_cnt_delta": 920,
      "post_rejit_run_time_ns_delta": 1486811,
      "program": "__x64_sys_opena",
      "program_id": 32,
      "ratio": 1.228886294589746,
      "runner": "bcc",
      "type": "tracing",
      "workload": "open_family_storm"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 62.039679538625045,
      "baseline_run_cnt_delta": 1145099,
      "baseline_run_time_ns_delta": 71041575,
      "post_rejit_avg_ns_per_run": 67.12050371373614,
      "post_rejit_run_cnt_delta": 277618,
      "post_rejit_run_time_ns_delta": 18633860,
      "program": "raw_syscalls__s",
      "program_id": 35,
      "ratio": 1.0818963639544246,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "file_open_storm"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 61.89863249147163,
      "baseline_run_cnt_delta": 1145002,
      "baseline_run_time_ns_delta": 70874058,
      "post_rejit_avg_ns_per_run": 100.32609705758404,
      "post_rejit_run_cnt_delta": 277629,
      "post_rejit_run_time_ns_delta": 27853434,
      "program": "raw_syscalls__s",
      "program_id": 36,
      "ratio": 1.6208128195951166,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "file_open_storm"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 782.8840579710145,
      "baseline_run_cnt_delta": 69,
      "baseline_run_time_ns_delta": 54019,
      "post_rejit_avg_ns_per_run": 590.8369565217391,
      "post_rejit_run_cnt_delta": 184,
      "post_rejit_run_time_ns_delta": 108714,
      "program": "trace_connect_e",
      "program_id": 39,
      "ratio": 0.7546927932764398,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4622.342857142857,
      "baseline_run_cnt_delta": 35,
      "baseline_run_time_ns_delta": 161782,
      "post_rejit_avg_ns_per_run": 2887.0108695652175,
      "post_rejit_run_cnt_delta": 92,
      "post_rejit_run_time_ns_delta": 265605,
      "program": "trace_connect_v",
      "program_id": 40,
      "ratio": 0.6245773969587631,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 5019.14705882353,
      "baseline_run_cnt_delta": 34,
      "baseline_run_time_ns_delta": 170651,
      "post_rejit_avg_ns_per_run": 3067.5434782608695,
      "post_rejit_run_cnt_delta": 92,
      "post_rejit_run_time_ns_delta": 282214,
      "program": "trace_connect_v",
      "program_id": 41,
      "ratio": 0.6111682806480452,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 774.5054545454545,
      "baseline_run_cnt_delta": 825,
      "baseline_run_time_ns_delta": 638967,
      "post_rejit_avg_ns_per_run": 637.573568753344,
      "post_rejit_run_cnt_delta": 1869,
      "post_rejit_run_time_ns_delta": 1191625,
      "program": "sock__inet_sock",
      "program_id": 44,
      "ratio": 0.8232008761352446,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "network"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 174.2585643569766,
      "baseline_run_cnt_delta": 91513,
      "baseline_run_time_ns_delta": 15946924,
      "post_rejit_avg_ns_per_run": 169.43880899241765,
      "post_rejit_run_cnt_delta": 135314,
      "post_rejit_run_time_ns_delta": 22927443,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 0.9723413573252822,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 108.02756523131103,
      "baseline_run_cnt_delta": 62470,
      "baseline_run_time_ns_delta": 6748482,
      "post_rejit_avg_ns_per_run": 119.12259908669432,
      "post_rejit_run_cnt_delta": 86061,
      "post_rejit_run_time_ns_delta": 10251810,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 1.102705581039676,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 271.7118644067797,
      "baseline_run_cnt_delta": 3599,
      "baseline_run_time_ns_delta": 977891,
      "post_rejit_avg_ns_per_run": 259.1159307527718,
      "post_rejit_run_cnt_delta": 5141,
      "post_rejit_run_time_ns_delta": 1332115,
      "program": "sched_wakeup_ne",
      "program_id": 49,
      "ratio": 0.9536423126700477,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 6145.0,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 24580,
      "post_rejit_avg_ns_per_run": 953.6111111111111,
      "post_rejit_run_cnt_delta": 18,
      "post_rejit_run_time_ns_delta": 17165,
      "program": "tracepoint__sch",
      "program_id": 131,
      "ratio": 0.1551848838260555,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "exec_storm"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 17217.662921348314,
      "baseline_run_cnt_delta": 89,
      "baseline_run_time_ns_delta": 1532372,
      "post_rejit_avg_ns_per_run": 13129.383720930233,
      "post_rejit_run_cnt_delta": 86,
      "post_rejit_run_time_ns_delta": 1129127,
      "program": "native_tracer_e",
      "program_id": 132,
      "ratio": 0.7625531862777385,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "exec_storm"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 49.97743055555556,
      "baseline_run_cnt_delta": 1152,
      "baseline_run_time_ns_delta": 57574,
      "post_rejit_avg_ns_per_run": 52.361979166666664,
      "post_rejit_run_cnt_delta": 1152,
      "post_rejit_run_time_ns_delta": 60321,
      "program": "balancer_ingress",
      "program_id": 577,
      "ratio": 1.0477125091186994,
      "runner": "katran",
      "type": "xdp",
      "workload": "test_run"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 172.81058226391355,
      "baseline_run_cnt_delta": 931502,
      "baseline_run_time_ns_delta": 160973403,
      "post_rejit_avg_ns_per_run": 175.5284035416632,
      "post_rejit_run_cnt_delta": 904095,
      "post_rejit_run_time_ns_delta": 158694352,
      "program": "tracepoint__raw",
      "program_id": 594,
      "ratio": 1.015727169263275,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 256.642886289299,
      "baseline_run_cnt_delta": 931258,
      "baseline_run_time_ns_delta": 239000741,
      "post_rejit_avg_ns_per_run": 262.77466200074326,
      "post_rejit_run_cnt_delta": 904144,
      "post_rejit_run_time_ns_delta": 237586134,
      "program": "tracepoint__raw",
      "program_id": 597,
      "ratio": 1.023892248875865,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 211.74037372198185,
      "baseline_run_cnt_delta": 931227,
      "baseline_run_time_ns_delta": 197178353,
      "post_rejit_avg_ns_per_run": 217.09998672859987,
      "post_rejit_run_cnt_delta": 904200,
      "post_rejit_run_time_ns_delta": 196301808,
      "program": "trace_sys_enter",
      "program_id": 600,
      "ratio": 1.0253121920605244,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 191.66737585301047,
      "baseline_run_cnt_delta": 931114,
      "baseline_run_time_ns_delta": 178464177,
      "post_rejit_avg_ns_per_run": 195.8385538837555,
      "post_rejit_run_cnt_delta": 904215,
      "post_rejit_run_time_ns_delta": 177080158,
      "program": "trace_sys_exit",
      "program_id": 601,
      "ratio": 1.021762587462688,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 636.01,
      "baseline_run_cnt_delta": 100,
      "baseline_run_time_ns_delta": 63601,
      "post_rejit_avg_ns_per_run": 591.38,
      "post_rejit_run_cnt_delta": 100,
      "post_rejit_run_time_ns_delta": 59138,
      "program": "trace_ptrace",
      "program_id": 602,
      "ratio": 0.9298281473561737,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2103.14,
      "baseline_run_cnt_delta": 100,
      "baseline_run_time_ns_delta": 210314,
      "post_rejit_avg_ns_per_run": 2003.44,
      "post_rejit_run_cnt_delta": 100,
      "post_rejit_run_time_ns_delta": 200344,
      "program": "trace_ret_ptrac",
      "program_id": 603,
      "ratio": 0.9525946917466266,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 390.7,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 19535,
      "post_rejit_avg_ns_per_run": 370.3,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 18515,
      "program": "trace_process_v",
      "program_id": 604,
      "ratio": 0.9477860250831841,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2511.66,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 125583,
      "post_rejit_avg_ns_per_run": 2602.14,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 130107,
      "program": "trace_ret_proce",
      "program_id": 605,
      "ratio": 1.0360239841379804,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1254.3225806451612,
      "baseline_run_cnt_delta": 62,
      "baseline_run_time_ns_delta": 77768,
      "post_rejit_avg_ns_per_run": 1159.71875,
      "post_rejit_run_cnt_delta": 64,
      "post_rejit_run_time_ns_delta": 74222,
      "program": "trace_arch_prct",
      "program_id": 606,
      "ratio": 0.9245777504886329,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2138.2258064516127,
      "baseline_run_cnt_delta": 62,
      "baseline_run_time_ns_delta": 132570,
      "post_rejit_avg_ns_per_run": 2341.265625,
      "post_rejit_run_cnt_delta": 64,
      "post_rejit_run_time_ns_delta": 149841,
      "program": "trace_ret_arch_",
      "program_id": 607,
      "ratio": 1.0949571452817382,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 996.0945945945946,
      "baseline_run_cnt_delta": 74,
      "baseline_run_time_ns_delta": 73711,
      "post_rejit_avg_ns_per_run": 994.525641025641,
      "post_rejit_run_cnt_delta": 78,
      "post_rejit_run_time_ns_delta": 77573,
      "program": "trace_dup2",
      "program_id": 610,
      "ratio": 0.9984248950074947,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2685.5945945945946,
      "baseline_run_cnt_delta": 74,
      "baseline_run_time_ns_delta": 198734,
      "post_rejit_avg_ns_per_run": 2844.269230769231,
      "post_rejit_run_cnt_delta": 78,
      "post_rejit_run_time_ns_delta": 221853,
      "program": "trace_ret_dup2",
      "program_id": 611,
      "ratio": 1.0590836146654476,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5437.089743589743,
      "baseline_run_cnt_delta": 234,
      "baseline_run_time_ns_delta": 1272279,
      "post_rejit_avg_ns_per_run": 5547.745833333333,
      "post_rejit_run_cnt_delta": 240,
      "post_rejit_run_time_ns_delta": 1331459,
      "program": "tracepoint__sch",
      "program_id": 619,
      "ratio": 1.0203520807935995,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5763.096774193548,
      "baseline_run_cnt_delta": 62,
      "baseline_run_time_ns_delta": 357312,
      "post_rejit_avg_ns_per_run": 5771.0625,
      "post_rejit_run_cnt_delta": 64,
      "post_rejit_run_time_ns_delta": 369348,
      "program": "tracepoint__sch",
      "program_id": 627,
      "ratio": 1.0013821953922621,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2109.923076923077,
      "baseline_run_cnt_delta": 234,
      "baseline_run_time_ns_delta": 493722,
      "post_rejit_avg_ns_per_run": 2166.873949579832,
      "post_rejit_run_cnt_delta": 238,
      "post_rejit_run_time_ns_delta": 515716,
      "program": "tracepoint__sch",
      "program_id": 629,
      "ratio": 1.026991918937541,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1327.3148936170212,
      "baseline_run_cnt_delta": 235,
      "baseline_run_time_ns_delta": 311919,
      "post_rejit_avg_ns_per_run": 1360.3865546218487,
      "post_rejit_run_cnt_delta": 238,
      "post_rejit_run_time_ns_delta": 323772,
      "program": "tracepoint__sch",
      "program_id": 630,
      "ratio": 1.0249162132993965,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 324.3259368211581,
      "baseline_run_cnt_delta": 970863,
      "baseline_run_time_ns_delta": 314876052,
      "post_rejit_avg_ns_per_run": 325.48750338562826,
      "post_rejit_run_cnt_delta": 959940,
      "post_rejit_run_time_ns_delta": 312448474,
      "program": "tracepoint__sch",
      "program_id": 632,
      "ratio": 1.003581479100485,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 18.15120258350605,
      "baseline_run_cnt_delta": 20747,
      "baseline_run_time_ns_delta": 376583,
      "post_rejit_avg_ns_per_run": 18.721434028156718,
      "post_rejit_run_cnt_delta": 18326,
      "post_rejit_run_time_ns_delta": 343089,
      "program": "trace_filldir64",
      "program_id": 633,
      "ratio": 1.031415628910937,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1532.482905982906,
      "baseline_run_cnt_delta": 234,
      "baseline_run_time_ns_delta": 358601,
      "post_rejit_avg_ns_per_run": 1558.0084033613446,
      "post_rejit_run_cnt_delta": 238,
      "post_rejit_run_time_ns_delta": 370806,
      "program": "trace_do_exit",
      "program_id": 635,
      "ratio": 1.016656301534448,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 712.4965277777778,
      "baseline_run_cnt_delta": 288,
      "baseline_run_time_ns_delta": 205199,
      "post_rejit_avg_ns_per_run": 669.2184300341297,
      "post_rejit_run_cnt_delta": 293,
      "post_rejit_run_time_ns_delta": 196081,
      "program": "trace_security_",
      "program_id": 639,
      "ratio": 0.939258514173214,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3371.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 3371,
      "post_rejit_avg_ns_per_run": 2343.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2343,
      "program": "tracepoint__cgr",
      "program_id": 641,
      "ratio": 0.69504598042124,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1970.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1970,
      "post_rejit_avg_ns_per_run": 2427.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2427,
      "program": "tracepoint__cgr",
      "program_id": 642,
      "ratio": 1.2319796954314721,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2346.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2346,
      "post_rejit_avg_ns_per_run": 1588.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1588,
      "program": "tracepoint__cgr",
      "program_id": 643,
      "ratio": 0.6768968456947997,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3729.0806451612902,
      "baseline_run_cnt_delta": 62,
      "baseline_run_time_ns_delta": 231203,
      "post_rejit_avg_ns_per_run": 3810.53125,
      "post_rejit_run_cnt_delta": 64,
      "post_rejit_run_time_ns_delta": 243874,
      "program": "trace_security_",
      "program_id": 644,
      "ratio": 1.0218420068078702,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1217.9276830953477,
      "baseline_run_cnt_delta": 6513,
      "baseline_run_time_ns_delta": 7932363,
      "post_rejit_avg_ns_per_run": 1260.7776027495345,
      "post_rejit_run_cnt_delta": 6983,
      "post_rejit_run_time_ns_delta": 8804010,
      "program": "trace_security_file_open",
      "program_id": 645,
      "ratio": 1.0351826469247207,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2246.3502304147464,
      "baseline_run_cnt_delta": 217,
      "baseline_run_time_ns_delta": 487458,
      "post_rejit_avg_ns_per_run": 2231.518181818182,
      "post_rejit_run_cnt_delta": 220,
      "post_rejit_run_time_ns_delta": 490934,
      "program": "trace_security_",
      "program_id": 647,
      "ratio": 0.9933972679790781,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 475.1950354609929,
      "baseline_run_cnt_delta": 282,
      "baseline_run_time_ns_delta": 134005,
      "post_rejit_avg_ns_per_run": 923.2578125,
      "post_rejit_run_cnt_delta": 128,
      "post_rejit_run_time_ns_delta": 118177,
      "program": "trace_commit_cr",
      "program_id": 648,
      "ratio": 1.9429029000783553,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1273.611111111111,
      "baseline_run_cnt_delta": 234,
      "baseline_run_time_ns_delta": 298025,
      "post_rejit_avg_ns_per_run": 1225.735294117647,
      "post_rejit_run_cnt_delta": 238,
      "post_rejit_run_time_ns_delta": 291725,
      "program": "trace_switch_ta",
      "program_id": 649,
      "ratio": 0.962409391237411,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 182.59029794557384,
      "baseline_run_cnt_delta": 27891,
      "baseline_run_time_ns_delta": 5092626,
      "post_rejit_avg_ns_per_run": 172.80270431794412,
      "post_rejit_run_cnt_delta": 26772,
      "post_rejit_run_time_ns_delta": 4626274,
      "program": "trace_cap_capab",
      "program_id": 650,
      "ratio": 0.9463958724107718,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1313.4827586206898,
      "baseline_run_cnt_delta": 203,
      "baseline_run_time_ns_delta": 266637,
      "post_rejit_avg_ns_per_run": 1568.3564356435643,
      "post_rejit_run_cnt_delta": 202,
      "post_rejit_run_time_ns_delta": 316808,
      "program": "trace_security_",
      "program_id": 651,
      "ratio": 1.194044174048026,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2866.44,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 143322,
      "post_rejit_avg_ns_per_run": 3333.18,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 166659,
      "program": "trace_security_",
      "program_id": 652,
      "ratio": 1.1628291539331017,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2176.28,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 108814,
      "post_rejit_avg_ns_per_run": 2229.82,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 111491,
      "program": "trace_security_",
      "program_id": 656,
      "ratio": 1.0246016137629348,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1986.88,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 99344,
      "post_rejit_avg_ns_per_run": 2298.2,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 114910,
      "program": "trace_security_",
      "program_id": 657,
      "ratio": 1.1566878724432275,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3108.2585034013605,
      "baseline_run_cnt_delta": 147,
      "baseline_run_time_ns_delta": 456914,
      "post_rejit_avg_ns_per_run": 3157.2027027027025,
      "post_rejit_run_cnt_delta": 148,
      "post_rejit_run_time_ns_delta": 467266,
      "program": "trace_security_",
      "program_id": 658,
      "ratio": 1.015746502180492,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2059.4716981132074,
      "baseline_run_cnt_delta": 53,
      "baseline_run_time_ns_delta": 109152,
      "post_rejit_avg_ns_per_run": 1993.7307692307693,
      "post_rejit_run_cnt_delta": 52,
      "post_rejit_run_time_ns_delta": 103674,
      "program": "trace_security_",
      "program_id": 659,
      "ratio": 0.9680787412894933,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2221.9821428571427,
      "baseline_run_cnt_delta": 56,
      "baseline_run_time_ns_delta": 124431,
      "post_rejit_avg_ns_per_run": 2412.625,
      "post_rejit_run_cnt_delta": 56,
      "post_rejit_run_time_ns_delta": 135107,
      "program": "trace_security_",
      "program_id": 660,
      "ratio": 1.0857985550224623,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 66.92582133755768,
      "baseline_run_cnt_delta": 43557,
      "baseline_run_time_ns_delta": 2915088,
      "post_rejit_avg_ns_per_run": 68.85187923028946,
      "post_rejit_run_cnt_delta": 43289,
      "post_rejit_run_time_ns_delta": 2980529,
      "program": "trace_vfs_write",
      "program_id": 663,
      "ratio": 1.0287789952254334,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 40.616906970337034,
      "baseline_run_cnt_delta": 43556,
      "baseline_run_time_ns_delta": 1769110,
      "post_rejit_avg_ns_per_run": 41.02384473197782,
      "post_rejit_run_cnt_delta": 43280,
      "post_rejit_run_time_ns_delta": 1775512,
      "program": "vfs_write_magic",
      "program_id": 664,
      "ratio": 1.0100189254178802,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 33.056156300939,
      "baseline_run_cnt_delta": 43557,
      "baseline_run_time_ns_delta": 1439827,
      "post_rejit_avg_ns_per_run": 30.762467070296253,
      "post_rejit_run_cnt_delta": 43274,
      "post_rejit_run_time_ns_delta": 1331215,
      "program": "trace_ret_vfs_w",
      "program_id": 665,
      "ratio": 0.9306123431362892,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 53.54402277475492,
      "baseline_run_cnt_delta": 43557,
      "baseline_run_time_ns_delta": 2332217,
      "post_rejit_avg_ns_per_run": 52.84396687332285,
      "post_rejit_run_cnt_delta": 43228,
      "post_rejit_run_time_ns_delta": 2284339,
      "program": "vfs_write_magic",
      "program_id": 666,
      "ratio": 0.9869256013061063,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 94.28442252363338,
      "baseline_run_cnt_delta": 4866,
      "baseline_run_time_ns_delta": 458788,
      "post_rejit_avg_ns_per_run": 85.1532472464869,
      "post_rejit_run_cnt_delta": 5266,
      "post_rejit_run_time_ns_delta": 448417,
      "program": "trace_vfs_write",
      "program_id": 668,
      "ratio": 0.9031528747513127,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 52.160501438553226,
      "baseline_run_cnt_delta": 4866,
      "baseline_run_time_ns_delta": 253813,
      "post_rejit_avg_ns_per_run": 50.22559817698443,
      "post_rejit_run_cnt_delta": 5266,
      "post_rejit_run_time_ns_delta": 264488,
      "program": "vfs_writev_magi",
      "program_id": 669,
      "ratio": 0.9629048186231841,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 66.49136868064119,
      "baseline_run_cnt_delta": 4866,
      "baseline_run_time_ns_delta": 323547,
      "post_rejit_avg_ns_per_run": 51.58127611090011,
      "post_rejit_run_cnt_delta": 5266,
      "post_rejit_run_time_ns_delta": 271627,
      "program": "trace_ret_vfs_w",
      "program_id": 670,
      "ratio": 0.7757589764567124,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 74.71557747636662,
      "baseline_run_cnt_delta": 4866,
      "baseline_run_time_ns_delta": 363566,
      "post_rejit_avg_ns_per_run": 69.41834409418914,
      "post_rejit_run_cnt_delta": 5266,
      "post_rejit_run_time_ns_delta": 365557,
      "program": "vfs_writev_magi",
      "program_id": 671,
      "ratio": 0.9291013526081217,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 105.29880453911038,
      "baseline_run_cnt_delta": 16479,
      "baseline_run_time_ns_delta": 1735219,
      "post_rejit_avg_ns_per_run": 98.54986604968339,
      "post_rejit_run_cnt_delta": 16424,
      "post_rejit_run_time_ns_delta": 1618583,
      "program": "trace_vfs_read",
      "program_id": 678,
      "ratio": 0.9359067890754611,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 173.84078481826953,
      "baseline_run_cnt_delta": 3109,
      "baseline_run_time_ns_delta": 540471,
      "post_rejit_avg_ns_per_run": 118.03906068356196,
      "post_rejit_run_cnt_delta": 4301,
      "post_rejit_run_time_ns_delta": 507686,
      "program": "trace_ret_vfs_r",
      "program_id": 679,
      "ratio": 0.6790067175948278,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 105.0517879161529,
      "baseline_run_cnt_delta": 4866,
      "baseline_run_time_ns_delta": 511182,
      "post_rejit_avg_ns_per_run": 92.93619445499431,
      "post_rejit_run_cnt_delta": 5266,
      "post_rejit_run_time_ns_delta": 489402,
      "program": "trace_vfs_readv",
      "program_id": 681,
      "ratio": 0.8846702783314011,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 102.80579531442663,
      "baseline_run_cnt_delta": 4866,
      "baseline_run_time_ns_delta": 500253,
      "post_rejit_avg_ns_per_run": 89.47645271553361,
      "post_rejit_run_cnt_delta": 5266,
      "post_rejit_run_time_ns_delta": 471183,
      "program": "trace_ret_vfs_r",
      "program_id": 682,
      "ratio": 0.8703444435391423,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 176.26258992805757,
      "baseline_run_cnt_delta": 1946,
      "baseline_run_time_ns_delta": 343007,
      "post_rejit_avg_ns_per_run": 200.86185983827494,
      "post_rejit_run_cnt_delta": 1484,
      "post_rejit_run_time_ns_delta": 298079,
      "program": "trace_mmap_aler",
      "program_id": 684,
      "ratio": 1.1395603566262,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 106.67454688731284,
      "baseline_run_cnt_delta": 1269,
      "baseline_run_time_ns_delta": 135370,
      "post_rejit_avg_ns_per_run": 91.11742707554225,
      "post_rejit_run_cnt_delta": 1337,
      "post_rejit_run_time_ns_delta": 121824,
      "program": "trace_do_mmap",
      "program_id": 685,
      "ratio": 0.8541627757912619,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 92.50197005516155,
      "baseline_run_cnt_delta": 1269,
      "baseline_run_time_ns_delta": 117385,
      "post_rejit_avg_ns_per_run": 67.06357516828722,
      "post_rejit_run_cnt_delta": 1337,
      "post_rejit_run_time_ns_delta": 89664,
      "program": "trace_ret_do_mm",
      "program_id": 686,
      "ratio": 0.7249961825493587,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1115.7935382190701,
      "baseline_run_cnt_delta": 1269,
      "baseline_run_time_ns_delta": 1415942,
      "post_rejit_avg_ns_per_run": 1136.8399401645474,
      "post_rejit_run_cnt_delta": 1337,
      "post_rejit_run_time_ns_delta": 1519955,
      "program": "trace_security_mmap_file",
      "program_id": 687,
      "ratio": 1.0188622726558085,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1629.0848214285713,
      "baseline_run_cnt_delta": 224,
      "baseline_run_time_ns_delta": 364915,
      "post_rejit_avg_ns_per_run": 1660.457627118644,
      "post_rejit_run_cnt_delta": 236,
      "post_rejit_run_time_ns_delta": 391868,
      "program": "trace_security_file_mprotect",
      "program_id": 688,
      "ratio": 1.0192579325995814,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 551.7734883317429,
      "baseline_run_cnt_delta": 11527,
      "baseline_run_time_ns_delta": 6360293,
      "post_rejit_avg_ns_per_run": 627.3857995894756,
      "post_rejit_run_cnt_delta": 10718,
      "post_rejit_run_time_ns_delta": 6724321,
      "program": "trace_security_",
      "program_id": 690,
      "ratio": 1.1370350566975271,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 442.4652406417112,
      "baseline_run_cnt_delta": 2992,
      "baseline_run_time_ns_delta": 1323856,
      "post_rejit_avg_ns_per_run": 470.8377715487036,
      "post_rejit_run_cnt_delta": 2854,
      "post_rejit_run_time_ns_delta": 1343771,
      "program": "trace_security_",
      "program_id": 693,
      "ratio": 1.0641237509772372,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1170.3333333333333,
      "baseline_run_cnt_delta": 240,
      "baseline_run_time_ns_delta": 280880,
      "post_rejit_avg_ns_per_run": 1111.6958333333334,
      "post_rejit_run_cnt_delta": 240,
      "post_rejit_run_time_ns_delta": 266807,
      "program": "trace_security_",
      "program_id": 694,
      "ratio": 0.9498967530618059,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2739.2,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 27392,
      "post_rejit_avg_ns_per_run": 2796.0,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 33552,
      "program": "trace_security_",
      "program_id": 698,
      "ratio": 1.0207359813084114,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3618.5,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 36185,
      "post_rejit_avg_ns_per_run": 3901.4166666666665,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 46817,
      "program": "trace_security_",
      "program_id": 699,
      "ratio": 1.0781861729077427,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2836.12,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 141806,
      "post_rejit_avg_ns_per_run": 2705.82,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 135291,
      "program": "trace_security_",
      "program_id": 700,
      "ratio": 0.954056951045795,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 6848.6,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 68486,
      "post_rejit_avg_ns_per_run": 7195.166666666667,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 86342,
      "program": "tracepoint__mod",
      "program_id": 704,
      "ratio": 1.0506040163926447,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 7330.5,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 73305,
      "post_rejit_avg_ns_per_run": 7362.75,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 88353,
      "program": "tracepoint__mod",
      "program_id": 705,
      "ratio": 1.0043994270513608,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 522.1,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 5221,
      "post_rejit_avg_ns_per_run": 562.0833333333334,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 6745,
      "program": "trace_do_init_m",
      "program_id": 706,
      "ratio": 1.0765817531762754,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 217.4,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 2174,
      "post_rejit_avg_ns_per_run": 201.83333333333334,
      "post_rejit_run_cnt_delta": 12,
      "post_rejit_run_time_ns_delta": 2422,
      "program": "trace_ret_do_in",
      "program_id": 707,
      "ratio": 0.9283961974854339,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2080.4274193548385,
      "baseline_run_cnt_delta": 124,
      "baseline_run_time_ns_delta": 257973,
      "post_rejit_avg_ns_per_run": 2165.0390625,
      "post_rejit_run_cnt_delta": 128,
      "post_rejit_run_time_ns_delta": 277125,
      "program": "trace_load_elf_",
      "program_id": 708,
      "ratio": 1.0406703172425023,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 38.68342116452565,
      "baseline_run_cnt_delta": 77611,
      "baseline_run_time_ns_delta": 3002259,
      "post_rejit_avg_ns_per_run": 38.41319092933792,
      "post_rejit_run_cnt_delta": 79024,
      "post_rejit_run_time_ns_delta": 3035564,
      "program": "trace_security_",
      "program_id": 709,
      "ratio": 0.9930143139605362,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2675.609375,
      "baseline_run_cnt_delta": 64,
      "baseline_run_time_ns_delta": 171239,
      "post_rejit_avg_ns_per_run": 2866.121212121212,
      "post_rejit_run_cnt_delta": 66,
      "post_rejit_run_time_ns_delta": 189164,
      "program": "tracepoint__tas",
      "program_id": 710,
      "ratio": 1.0712031580174934,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2988.88,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 149444,
      "post_rejit_avg_ns_per_run": 3251.2,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 162560,
      "program": "trace_security_",
      "program_id": 711,
      "ratio": 1.087765316774176,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 734.676293622142,
      "baseline_run_cnt_delta": 831,
      "baseline_run_time_ns_delta": 610516,
      "post_rejit_avg_ns_per_run": 754.0463645943098,
      "post_rejit_run_cnt_delta": 949,
      "post_rejit_run_time_ns_delta": 715590,
      "program": "trace_do_sigact",
      "program_id": 714,
      "ratio": 1.0263654498454937,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3027.507692307692,
      "baseline_run_cnt_delta": 65,
      "baseline_run_time_ns_delta": 196788,
      "post_rejit_avg_ns_per_run": 2956.573529411765,
      "post_rejit_run_cnt_delta": 68,
      "post_rejit_run_time_ns_delta": 201047,
      "program": "trace_vfs_utime",
      "program_id": 715,
      "ratio": 0.976570113074805,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1476.3809907370116,
      "baseline_run_cnt_delta": 2483,
      "baseline_run_time_ns_delta": 3665854,
      "post_rejit_avg_ns_per_run": 1433.1617592247485,
      "post_rejit_run_cnt_delta": 2683,
      "post_rejit_run_time_ns_delta": 3845173,
      "program": "trace_do_trunca",
      "program_id": 717,
      "ratio": 0.9707262340930791,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 376.9588191250401,
      "baseline_run_cnt_delta": 9349,
      "baseline_run_time_ns_delta": 3524188,
      "post_rejit_avg_ns_per_run": 407.94519804666305,
      "post_rejit_run_cnt_delta": 9215,
      "post_rejit_run_time_ns_delta": 3759215,
      "program": "trace_fd_instal",
      "program_id": 718,
      "ratio": 1.0822009655949831,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 768.5501202886928,
      "baseline_run_cnt_delta": 7482,
      "baseline_run_time_ns_delta": 5750292,
      "post_rejit_avg_ns_per_run": 833.1122002914293,
      "post_rejit_run_cnt_delta": 7549,
      "post_rejit_run_time_ns_delta": 6289164,
      "program": "trace_filp_clos",
      "program_id": 719,
      "ratio": 1.084005035323506,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 119.70452409719425,
      "baseline_run_cnt_delta": 7449,
      "baseline_run_time_ns_delta": 891679,
      "post_rejit_avg_ns_per_run": 105.56913902348118,
      "post_rejit_run_cnt_delta": 8049,
      "post_rejit_run_time_ns_delta": 849726,
      "program": "trace_file_upda",
      "program_id": 720,
      "ratio": 0.8819143622154513,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 38.98644113303799,
      "baseline_run_cnt_delta": 7449,
      "baseline_run_time_ns_delta": 290410,
      "post_rejit_avg_ns_per_run": 48.195179525406886,
      "post_rejit_run_cnt_delta": 8049,
      "post_rejit_run_time_ns_delta": 387923,
      "program": "trace_ret_file_",
      "program_id": 721,
      "ratio": 1.2362036165585066,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 478.56,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 23928,
      "post_rejit_avg_ns_per_run": 417.36,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 20868,
      "program": "trace_inotify_f",
      "program_id": 724,
      "ratio": 0.8721163490471414,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 299.78,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 14989,
      "post_rejit_avg_ns_per_run": 341.92,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 17096,
      "program": "trace_ret_inoti",
      "program_id": 725,
      "ratio": 1.1405697511508441,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 171.20967741935485,
      "baseline_run_cnt_delta": 62,
      "baseline_run_time_ns_delta": 10615,
      "post_rejit_avg_ns_per_run": 367.0625,
      "post_rejit_run_cnt_delta": 64,
      "post_rejit_run_time_ns_delta": 23492,
      "program": "trace_exec_binp",
      "program_id": 727,
      "ratio": 2.143935468676401,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4925.6612903225805,
      "baseline_run_cnt_delta": 62,
      "baseline_run_time_ns_delta": 305391,
      "post_rejit_avg_ns_per_run": 4893.328125,
      "post_rejit_run_cnt_delta": 64,
      "post_rejit_run_time_ns_delta": 313173,
      "program": "trace_security_",
      "program_id": 728,
      "ratio": 0.993435771682859,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3957.2053571428573,
      "baseline_run_cnt_delta": 112,
      "baseline_run_time_ns_delta": 443207,
      "post_rejit_avg_ns_per_run": 4105.377192982456,
      "post_rejit_run_cnt_delta": 114,
      "post_rejit_run_time_ns_delta": 468013,
      "program": "trace_execute_f",
      "program_id": 729,
      "ratio": 1.0374435548491676,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3563.1,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 178155,
      "post_rejit_avg_ns_per_run": 3543.92,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 177196,
      "program": "trace_security_",
      "program_id": 730,
      "ratio": 0.9946170469534956,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2822.090909090909,
      "baseline_run_cnt_delta": 11,
      "baseline_run_time_ns_delta": 31043,
      "post_rejit_avg_ns_per_run": 2892.230769230769,
      "post_rejit_run_cnt_delta": 13,
      "post_rejit_run_time_ns_delta": 37599,
      "program": "trace_set_fs_pw",
      "program_id": 731,
      "ratio": 1.0248538627561272,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1421.25,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 5685,
      "post_rejit_avg_ns_per_run": 1362.75,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 5451,
      "program": "trace_security_",
      "program_id": 732,
      "ratio": 0.9588390501319262,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3246.88,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 162344,
      "post_rejit_avg_ns_per_run": 3510.86,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 175543,
      "program": "trace_chmod_com",
      "program_id": 734,
      "ratio": 1.0813026659439215,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1197.2142857142858,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 16761,
      "post_rejit_avg_ns_per_run": 1548.5,
      "post_rejit_run_cnt_delta": 14,
      "post_rejit_run_time_ns_delta": 21679,
      "program": "trace_security_task_prctl",
      "program_id": 735,
      "ratio": 1.293419247061631,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 371.69714285714286,
      "baseline_run_cnt_delta": 350,
      "baseline_run_time_ns_delta": 130094,
      "post_rejit_avg_ns_per_run": 263.66381766381767,
      "post_rejit_run_cnt_delta": 351,
      "post_rejit_run_time_ns_delta": 92546,
      "program": "trace_sock_allo",
      "program_id": 738,
      "ratio": 0.7093512089899318,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1127.28,
      "baseline_run_cnt_delta": 350,
      "baseline_run_time_ns_delta": 394548,
      "post_rejit_avg_ns_per_run": 1305.5242165242166,
      "post_rejit_run_cnt_delta": 351,
      "post_rejit_run_time_ns_delta": 458239,
      "program": "trace_ret_sock_",
      "program_id": 739,
      "ratio": 1.15811884937568,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1630.82,
      "baseline_run_cnt_delta": 50,
      "baseline_run_time_ns_delta": 81541,
      "post_rejit_avg_ns_per_run": 1704.0,
      "post_rejit_run_cnt_delta": 50,
      "post_rejit_run_time_ns_delta": 85200,
      "program": "trace_security_",
      "program_id": 740,
      "ratio": 1.0448731313081763,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 149.47761194029852,
      "baseline_run_cnt_delta": 268,
      "baseline_run_time_ns_delta": 40060,
      "post_rejit_avg_ns_per_run": 171.04615384615386,
      "post_rejit_run_cnt_delta": 260,
      "post_rejit_run_time_ns_delta": 44472,
      "program": "trace_security_",
      "program_id": 741,
      "ratio": 1.144292791581858,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 364.93283582089555,
      "baseline_run_cnt_delta": 134,
      "baseline_run_time_ns_delta": 48901,
      "post_rejit_avg_ns_per_run": 335.1,
      "post_rejit_run_cnt_delta": 120,
      "post_rejit_run_time_ns_delta": 40212,
      "program": "trace_security_",
      "program_id": 742,
      "ratio": 0.9182511605079651,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1124.1436388508891,
      "baseline_run_cnt_delta": 731,
      "baseline_run_time_ns_delta": 821749,
      "post_rejit_avg_ns_per_run": 1158.4957020057307,
      "post_rejit_run_cnt_delta": 698,
      "post_rejit_run_time_ns_delta": 808630,
      "program": "cgroup_bpf_run_",
      "program_id": 743,
      "ratio": 1.0305584286274632,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2049.4104234527686,
      "baseline_run_cnt_delta": 307,
      "baseline_run_time_ns_delta": 629169,
      "post_rejit_avg_ns_per_run": 2151.562913907285,
      "post_rejit_run_cnt_delta": 302,
      "post_rejit_run_time_ns_delta": 649772,
      "program": "cgroup_skb_ingr",
      "program_id": 745,
      "ratio": 1.0498448184343738,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2708.0781758957655,
      "baseline_run_cnt_delta": 307,
      "baseline_run_time_ns_delta": 831380,
      "post_rejit_avg_ns_per_run": 2864.135761589404,
      "post_rejit_run_cnt_delta": 302,
      "post_rejit_run_time_ns_delta": 864969,
      "program": "cgroup_skb_egre",
      "program_id": 746,
      "ratio": 1.0576266915344932,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2556.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2556,
      "post_rejit_avg_ns_per_run": 3546.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 3546,
      "program": "cgroup_mkdir_si",
      "program_id": 747,
      "ratio": 1.3873239436619718,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2810.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2810,
      "post_rejit_avg_ns_per_run": 2786.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 2786,
      "program": "cgroup_rmdir_si",
      "program_id": 748,
      "ratio": 0.9914590747330961,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 76.35483870967742,
      "baseline_run_cnt_delta": 62,
      "baseline_run_time_ns_delta": 4734,
      "post_rejit_avg_ns_per_run": 152.375,
      "post_rejit_run_cnt_delta": 64,
      "post_rejit_run_time_ns_delta": 9752,
      "program": "empty_kprobe",
      "program_id": 749,
      "ratio": 1.9956168145331643,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1015.6935483870968,
      "baseline_run_cnt_delta": 62,
      "baseline_run_time_ns_delta": 62973,
      "post_rejit_avg_ns_per_run": 1123.734375,
      "post_rejit_run_cnt_delta": 64,
      "post_rejit_run_time_ns_delta": 71919,
      "program": "tracepoint__exe",
      "program_id": 750,
      "ratio": 1.1063714806345577,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 700.2885885424666,
      "baseline_run_cnt_delta": 6511,
      "baseline_run_time_ns_delta": 4559579,
      "post_rejit_avg_ns_per_run": 740.1065888714957,
      "post_rejit_run_cnt_delta": 7027,
      "post_rejit_run_time_ns_delta": 5200729,
      "program": "lsm_file_open_t",
      "program_id": 751,
      "ratio": 1.0568594162185385,
      "runner": "tracee",
      "type": "lsm",
      "workload": "tracee_system_edge_mix"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 125.6786661102656,
      "baseline_run_cnt_delta": 162952,
      "baseline_run_time_ns_delta": 20479590,
      "post_rejit_avg_ns_per_run": 118.31930999812944,
      "post_rejit_run_cnt_delta": 171072,
      "post_rejit_run_time_ns_delta": 20241121,
      "program": "cap_capable",
      "program_id": 758,
      "ratio": 0.9414430759021636,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "exec_storm"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 153.3770497081044,
      "baseline_run_cnt_delta": 745472,
      "baseline_run_time_ns_delta": 114338296,
      "post_rejit_avg_ns_per_run": 147.530583937983,
      "post_rejit_run_cnt_delta": 745473,
      "post_rejit_run_time_ns_delta": 109980067,
      "program": "block_io_start",
      "program_id": 764,
      "ratio": 0.961881743186168,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 281.2024636740213,
      "baseline_run_cnt_delta": 745472,
      "baseline_run_time_ns_delta": 209628563,
      "post_rejit_avg_ns_per_run": 306.15733500743823,
      "post_rejit_run_cnt_delta": 745473,
      "post_rejit_run_time_ns_delta": 228232027,
      "program": "block_io_done",
      "program_id": 765,
      "ratio": 1.088743430649119,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "block_io"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1290.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1290,
      "post_rejit_avg_ns_per_run": 1405.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1405,
      "program": "1",
      "program_id": 771,
      "ratio": 1.0891472868217054,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "vfs_create_write_fsync"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 67.06503762891387,
      "baseline_run_cnt_delta": 10763,
      "baseline_run_time_ns_delta": 721821,
      "post_rejit_avg_ns_per_run": 60.23352405170587,
      "post_rejit_run_cnt_delta": 9438,
      "post_rejit_run_time_ns_delta": 568484,
      "program": "vfs_create",
      "program_id": 772,
      "ratio": 0.8981359912894059,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "vfs_create_write_fsync"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 107.38117865647257,
      "baseline_run_cnt_delta": 93649,
      "baseline_run_time_ns_delta": 10056140,
      "post_rejit_avg_ns_per_run": 99.44864559819413,
      "post_rejit_run_cnt_delta": 85056,
      "post_rejit_run_time_ns_delta": 8458704,
      "program": "sched_wakeup",
      "program_id": 778,
      "ratio": 0.9261273422630634,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 230.06944174285158,
      "baseline_run_cnt_delta": 5141,
      "baseline_run_time_ns_delta": 1182787,
      "post_rejit_avg_ns_per_run": 223.97549114958179,
      "post_rejit_run_cnt_delta": 5141,
      "post_rejit_run_time_ns_delta": 1151458,
      "program": "sched_wakeup_ne",
      "program_id": 779,
      "ratio": 0.9735125597423712,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 162.22613176094563,
      "baseline_run_cnt_delta": 145172,
      "baseline_run_time_ns_delta": 23550692,
      "post_rejit_avg_ns_per_run": 153.58388753142816,
      "post_rejit_run_cnt_delta": 141195,
      "post_rejit_run_time_ns_delta": 21685277,
      "program": "sched_switch",
      "program_id": 780,
      "ratio": 0.9467271756053915,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "hackbench"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 775.2368728121354,
      "baseline_run_cnt_delta": 1714,
      "baseline_run_time_ns_delta": 1328756,
      "post_rejit_avg_ns_per_run": 712.767955801105,
      "post_rejit_run_cnt_delta": 1810,
      "post_rejit_run_time_ns_delta": 1290110,
      "program": "tcp_set_state",
      "program_id": 787,
      "ratio": 0.91941957458186,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "network"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline_avg_ns_per_run": 5098.166666666667,
      "baseline_run_cnt_delta": 24,
      "baseline_run_time_ns_delta": 122356,
      "post_rejit_avg_ns_per_run": 4199.875,
      "post_rejit_run_cnt_delta": 16,
      "post_rejit_run_time_ns_delta": 67198,
      "program": "tcp_retransmit_",
      "program_id": 793,
      "ratio": 0.8238010395893949,
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
            "avg_ns_per_run": 95.45226672741649,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 149246,
            "run_time_ns_delta": 14245869,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.108192540999994,
            "ops_per_sec": 1072.9182484183555,
            "ops_total": 1189.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5203] setting to a 1 secs run per stressor\nstress-ng: info:  [5203] dispatching hogs: 2 exec\nstress-ng: info:  [5203] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5203] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5203]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5203] exec               1189      1.04      2.52      1.00      1141.43         337.27\nstress-ng: info:  [5203] skipped: 0\nstress-ng: info:  [5203] passed: 2: exec (2)\nstress-ng: info:  [5203] failed: 0\nstress-ng: info:  [5203] metrics untrustworthy: 0\nstress-ng: info:  [5203] successful run completed in 1.07 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 53.9468967062514,
            "bytes_jited": 206,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 169594,
            "run_time_ns_delta": 9149070,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.04879791999997,
            "ops_per_sec": 1373.953907155004,
            "ops_total": 1441.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [6742] setting to a 1 secs run per stressor\nstress-ng: info:  [6742] dispatching hogs: 2 exec\nstress-ng: info:  [6742] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6742] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6742]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6742] exec               1441      1.03      2.72      0.84      1404.69         404.99\nstress-ng: info:  [6742] skipped: 0\nstress-ng: info:  [6742] passed: 2: exec (2)\nstress-ng: info:  [6742] failed: 0\nstress-ng: info:  [6742] metrics untrustworthy: 0\nstress-ng: info:  [6742] successful run completed in 1.03 secs"
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
        "output_chars": 3700,
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
            "avg_ns_per_run": 2076.930276981853,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1047,
            "run_time_ns_delta": 2174546,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1478.9153225806451,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 992,
            "run_time_ns_delta": 1467084,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0895527210000182,
            "ops_per_sec": 958.1913567631599,
            "ops_total": 1044.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8575] setting to a 1 secs run per stressor\nstress-ng: info:  [8575] dispatching hogs: 2 exec\nstress-ng: info:  [8575] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8575] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8575]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8575] exec               1044      1.04      2.21      0.86      1007.80         340.22\nstress-ng: info:  [8575] skipped: 0\nstress-ng: info:  [8575] passed: 2: exec (2)\nstress-ng: info:  [8575] failed: 0\nstress-ng: info:  [8575] metrics untrustworthy: 0\nstress-ng: info:  [8575] successful run completed in 1.04 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1847.0423666910153,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 1369,
            "run_time_ns_delta": 2528601,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 1623.752911813644,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_exec",
            "run_cnt_delta": 1202,
            "run_time_ns_delta": 1951751,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.043745156,
            "ops_per_sec": 1308.7485888174028,
            "ops_total": 1366.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8910] setting to a 1 secs run per stressor\nstress-ng: info:  [8910] dispatching hogs: 2 exec\nstress-ng: info:  [8910] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8910] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8910]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8910] exec               1366      1.02      2.61      0.81      1333.39         398.78\nstress-ng: info:  [8910] skipped: 0\nstress-ng: info:  [8910] passed: 2: exec (2)\nstress-ng: info:  [8910] failed: 0\nstress-ng: info:  [8910] metrics untrustworthy: 0\nstress-ng: info:  [8910] successful run completed in 1.03 secs"
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
        "output_chars": 7420,
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
            "avg_ns_per_run": 59.56498904254515,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 26466,
            "run_time_ns_delta": 1576447,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 778.3137610519157,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 13233,
            "run_time_ns_delta": 10299426,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 768.6967429910073,
            "bytes_jited": 742,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_return",
            "run_cnt_delta": 13233,
            "run_time_ns_delta": 10172164,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0000213100000224,
            "ops_per_sec": 26465.436021557787,
            "ops_total": 26466.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 51.62315071020107,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 54210,
            "run_time_ns_delta": 2798491,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 801.9406751521859,
            "bytes_jited": 719,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_re",
            "run_cnt_delta": 27105,
            "run_time_ns_delta": 21736602,
            "type": "kprobe"
          },
          "15": {
            "avg_ns_per_run": 804.9411547684929,
            "bytes_jited": 740,
            "bytes_xlated": 1184,
            "id": 15,
            "name": "bindsnoop_v6_re",
            "run_cnt_delta": 27105,
            "run_time_ns_delta": 21817930,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0000154890000204,
            "ops_per_sec": 54209.16035431417,
            "ops_total": 54210.0,
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
        "output_chars": 12428,
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
            "avg_ns_per_run": 157.1659420766156,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 319491,
            "run_time_ns_delta": 50213104,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 180.61814260808598,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 319491,
            "run_time_ns_delta": 57705871,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 381.6263149822687,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 319491,
            "run_time_ns_delta": 121926173,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.129788528000006,
            "ops_per_sec": 62280.92995571525,
            "ops_total": 319488.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 111.79552472654981,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start",
            "run_cnt_delta": 745474,
            "run_time_ns_delta": 83340657,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 132.33642129324082,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 745476,
            "run_time_ns_delta": 98653626,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 343.21848561390897,
            "bytes_jited": 548,
            "bytes_xlated": 848,
            "id": 20,
            "name": "trace_req_compl",
            "run_cnt_delta": 745477,
            "run_time_ns_delta": 255861487,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.039467484999932,
            "ops_per_sec": 147926.74071594095,
            "ops_total": 745472.0,
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
        "output_chars": 13066,
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
            "avg_ns_per_run": 32.28648648648649,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 555,
            "run_time_ns_delta": 17919,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 32.15847979570377,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 6657,
            "run_time_ns_delta": 214079,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 27.04390913248971,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 13118,
            "run_time_ns_delta": 354762,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0141422270000362,
            "ops_per_sec": 75.92623396402293,
            "ops_total": 77.0,
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
            "avg_ns_per_run": 53.39923954372624,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 263,
            "run_time_ns_delta": 14044,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 35.55666063893912,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 3318,
            "run_time_ns_delta": 117977,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 29.036638716733503,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 5486,
            "run_time_ns_delta": 159295,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0004657709999947,
            "ops_per_sec": 95.95530680079659,
            "ops_total": 96.0,
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
        "output_chars": 19730,
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
            "avg_ns_per_run": 1320.3156668608037,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 1717,
            "run_time_ns_delta": 2266982,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1315.0923076923077,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 585,
            "run_time_ns_delta": 769329,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0003686850000122,
            "ops_per_sec": 584.7843987639346,
            "ops_total": 585.0,
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
            "avg_ns_per_run": 1505.2947067238913,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 2097,
            "run_time_ns_delta": 3156603,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1616.0989130434782,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "__x64_sys_opena",
            "run_cnt_delta": 920,
            "run_time_ns_delta": 1486811,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.00023871399992,
            "ops_per_sec": 919.7804355331857,
            "ops_total": 920.0,
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
        "output_chars": 11095,
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
            "avg_ns_per_run": 62.039679538625045,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 1145099,
            "run_time_ns_delta": 71041575,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 61.89863249147163,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 1145002,
            "run_time_ns_delta": 70874058,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0007955570000036,
            "ops_per_sec": 820.3473669098204,
            "ops_total": 821.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 67.12050371373614,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 277618,
            "run_time_ns_delta": 18633860,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 100.32609705758404,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "raw_syscalls__s",
            "run_cnt_delta": 277629,
            "run_time_ns_delta": 27853434,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000313449000032,
            "ops_per_sec": 1235.6126984352486,
            "ops_total": 1236.0,
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
            "avg_ns_per_run": 782.8840579710145,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 69,
            "run_time_ns_delta": 54019,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4622.342857142857,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 35,
            "run_time_ns_delta": 161782,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 5019.14705882353,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 34,
            "run_time_ns_delta": 170651,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0073355989999868,
            "ops_per_sec": 68.49752959043484,
            "ops_total": 69.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 590.8369565217391,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_e",
            "run_cnt_delta": 184,
            "run_time_ns_delta": 108714,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 2887.0108695652175,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v",
            "run_cnt_delta": 92,
            "run_time_ns_delta": 265605,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 3067.5434782608695,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v",
            "run_cnt_delta": 92,
            "run_time_ns_delta": 282214,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0037127650000457,
            "ops_per_sec": 183.3193782286824,
            "ops_total": 184.0,
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
        "output_chars": 12340,
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
            "avg_ns_per_run": 774.5054545454545,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 825,
            "run_time_ns_delta": 638967,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0142831900000147,
            "ops_per_sec": 74.92976394491848,
            "ops_total": 76.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 637.573568753344,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "sock__inet_sock",
            "run_cnt_delta": 1869,
            "run_time_ns_delta": 1191625,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0006818429999385,
            "ops_per_sec": 170.88348429243013,
            "ops_total": 171.0,
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
        "output_chars": 4882,
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
            "avg_ns_per_run": 174.2585643569766,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 91513,
            "run_time_ns_delta": 15946924,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 108.02756523131103,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 62470,
            "run_time_ns_delta": 6748482,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 271.7118644067797,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 3599,
            "run_time_ns_delta": 977891,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0049438839999993,
            "ops_per_sec": 13.931126128431673,
            "ops_total": 14.0,
            "stderr": "",
            "stdout": "Time: 0.049\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.046\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.054\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.052\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.047\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.034\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 169.43880899241765,
            "bytes_jited": 645,
            "bytes_xlated": 1136,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 135314,
            "run_time_ns_delta": 22927443,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 119.12259908669432,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 86061,
            "run_time_ns_delta": 10251810,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 259.1159307527718,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 5141,
            "run_time_ns_delta": 1332115,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0102489539999624,
            "ops_per_sec": 19.79710042837693,
            "ops_total": 20.0,
            "stderr": "",
            "stdout": "Time: 0.028\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.029\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.032\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.031\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.031\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.034\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.029\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.027\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.028\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.034\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.039\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.033\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035"
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
        "output_chars": 12831,
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
            "duration_s": 1.019830538000008,
            "ops_per_sec": 796.2107131959542,
            "ops_total": 812.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     7.25ms    5.09ms  33.67ms   78.63%\n    Req/Sec   406.40     96.69   560.00     80.00%\n  812 requests in 1.01s, 123.04KB read\nRequests/sec:    805.19\nTransfer/sec:    122.01KB"
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
            "duration_s": 1.0027663050000228,
            "ops_per_sec": 2327.5612556606065,
            "ops_total": 2334.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     2.52ms    1.80ms  14.65ms   89.68%\n    Req/Sec     1.17k   426.25     1.81k    60.00%\n  2334 requests in 1.00s, 353.43KB read\nRequests/sec:   2333.42\nTransfer/sec:    353.34KB"
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
        "output_chars": 25746,
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
            "avg_ns_per_run": 6145.0,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 24580,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 17217.662921348314,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_entry",
            "run_cnt_delta": 89,
            "run_time_ns_delta": 1532372,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0339870189999942,
            "ops_per_sec": 1.9342602597992684,
            "ops_total": 2.0,
            "stderr": "shell_burner=bash\nnode_burner_unavailable\njava_burner_unavailable",
            "stdout": "started_burners=shell python"
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
            "avg_ns_per_run": 953.6111111111111,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sch",
            "run_cnt_delta": 18,
            "run_time_ns_delta": 17165,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 13129.383720930233,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_e",
            "run_cnt_delta": 86,
            "run_time_ns_delta": 1129127,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0152595609999935,
            "ops_per_sec": 1.9699395867102922,
            "ops_total": 2.0,
            "stderr": "shell_burner=bash\nnode_burner_unavailable\njava_burner_unavailable",
            "stdout": "started_burners=shell python"
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
        "output_chars": 348002,
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
      "error": "failed to read BPF stats for requested program ids: 241, 243, 247, 248, 250, 252, 255, 257, 260",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "cilium",
      "selected_workload": "network",
      "status": "error"
    },
    {
      "app": "tetragon/observer",
      "baseline": null,
      "error": "[Errno 22] Invalid argument",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "tetragon",
      "selected_workload": "tetragon_exec_connect_mix",
      "status": "error"
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
            "avg_ns_per_run": 49.97743055555556,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 577,
            "name": "balancer_ingress",
            "run_cnt_delta": 1152,
            "run_time_ns_delta": 57574,
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
            "duration_s": 1.0342630499999927,
            "ops_per_sec": 1113.8365621782661,
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
            "avg_ns_per_run": 52.361979166666664,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 577,
            "name": "balancer_ingress",
            "run_cnt_delta": 1152,
            "run_time_ns_delta": 60321,
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
            "duration_s": 1.0883142820000558,
            "ops_per_sec": 1058.5177637133509,
            "ops_total": 1152.0,
            "stderr": "{'retval': 2, 'duration_ns': 74, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
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
        "output_chars": 89601,
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
            "avg_ns_per_run": 172.81058226391355,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 594,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 931502,
            "run_time_ns_delta": 160973403,
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
            "avg_ns_per_run": 256.642886289299,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 597,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 931258,
            "run_time_ns_delta": 239000741,
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
            "avg_ns_per_run": 211.74037372198185,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 600,
            "name": "trace_sys_enter",
            "run_cnt_delta": 931227,
            "run_time_ns_delta": 197178353,
            "type": "raw_tracepoint"
          },
          "601": {
            "avg_ns_per_run": 191.66737585301047,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 601,
            "name": "trace_sys_exit",
            "run_cnt_delta": 931114,
            "run_time_ns_delta": 178464177,
            "type": "raw_tracepoint"
          },
          "602": {
            "avg_ns_per_run": 636.01,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 602,
            "name": "trace_ptrace",
            "run_cnt_delta": 100,
            "run_time_ns_delta": 63601,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": 2103.14,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 603,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 100,
            "run_time_ns_delta": 210314,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": 390.7,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 604,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 19535,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": 2511.66,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 605,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 125583,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": 1254.3225806451612,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 606,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 77768,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": 2138.2258064516127,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 607,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 132570,
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
            "avg_ns_per_run": 996.0945945945946,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 610,
            "name": "trace_dup2",
            "run_cnt_delta": 74,
            "run_time_ns_delta": 73711,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 2685.5945945945946,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 611,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 74,
            "run_time_ns_delta": 198734,
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
            "avg_ns_per_run": 5437.089743589743,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 619,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 234,
            "run_time_ns_delta": 1272279,
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
            "avg_ns_per_run": 18358.0,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 622,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 18358,
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
            "avg_ns_per_run": 5763.096774193548,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 627,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 357312,
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
            "avg_ns_per_run": 2109.923076923077,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 629,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 234,
            "run_time_ns_delta": 493722,
            "type": "raw_tracepoint"
          },
          "630": {
            "avg_ns_per_run": 1327.3148936170212,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 630,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 235,
            "run_time_ns_delta": 311919,
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
            "avg_ns_per_run": 324.3259368211581,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 632,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 970863,
            "run_time_ns_delta": 314876052,
            "type": "raw_tracepoint"
          },
          "633": {
            "avg_ns_per_run": 18.15120258350605,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 633,
            "name": "trace_filldir64",
            "run_cnt_delta": 20747,
            "run_time_ns_delta": 376583,
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
            "avg_ns_per_run": 1532.482905982906,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 635,
            "name": "trace_do_exit",
            "run_cnt_delta": 234,
            "run_time_ns_delta": 358601,
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
            "avg_ns_per_run": 712.4965277777778,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 639,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 288,
            "run_time_ns_delta": 205199,
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
            "avg_ns_per_run": 3371.0,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 641,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3371,
            "type": "raw_tracepoint"
          },
          "642": {
            "avg_ns_per_run": 1970.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 642,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1970,
            "type": "raw_tracepoint"
          },
          "643": {
            "avg_ns_per_run": 2346.0,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 643,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2346,
            "type": "raw_tracepoint"
          },
          "644": {
            "avg_ns_per_run": 3729.0806451612902,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 644,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 231203,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 1217.9276830953477,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 645,
            "name": "trace_security_file_open",
            "run_cnt_delta": 6513,
            "run_time_ns_delta": 7932363,
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
            "avg_ns_per_run": 2246.3502304147464,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 647,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 217,
            "run_time_ns_delta": 487458,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 475.1950354609929,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 648,
            "name": "trace_commit_creds",
            "run_cnt_delta": 282,
            "run_time_ns_delta": 134005,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 1273.611111111111,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 649,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 234,
            "run_time_ns_delta": 298025,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": 182.59029794557384,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 650,
            "name": "trace_cap_capable",
            "run_cnt_delta": 27891,
            "run_time_ns_delta": 5092626,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": 1313.4827586206898,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 651,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 203,
            "run_time_ns_delta": 266637,
            "type": "kprobe"
          },
          "652": {
            "avg_ns_per_run": 2866.44,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 652,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 143322,
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
            "avg_ns_per_run": 2176.28,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 656,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 108814,
            "type": "kprobe"
          },
          "657": {
            "avg_ns_per_run": 1986.88,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 657,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 99344,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 3108.2585034013605,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 658,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 147,
            "run_time_ns_delta": 456914,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": 2059.4716981132074,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 659,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 53,
            "run_time_ns_delta": 109152,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": 2221.9821428571427,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 660,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 56,
            "run_time_ns_delta": 124431,
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
            "avg_ns_per_run": 66.92582133755768,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 663,
            "name": "trace_vfs_write",
            "run_cnt_delta": 43557,
            "run_time_ns_delta": 2915088,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 40.616906970337034,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 664,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 43556,
            "run_time_ns_delta": 1769110,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": 33.056156300939,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 665,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 43557,
            "run_time_ns_delta": 1439827,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": 53.54402277475492,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 666,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 43557,
            "run_time_ns_delta": 2332217,
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
            "avg_ns_per_run": 94.28442252363338,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 668,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 4866,
            "run_time_ns_delta": 458788,
            "type": "kprobe"
          },
          "669": {
            "avg_ns_per_run": 52.160501438553226,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 669,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 4866,
            "run_time_ns_delta": 253813,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 66.49136868064119,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 670,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 4866,
            "run_time_ns_delta": 323547,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": 74.71557747636662,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 671,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 4866,
            "run_time_ns_delta": 363566,
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
            "avg_ns_per_run": 105.29880453911038,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 678,
            "name": "trace_vfs_read",
            "run_cnt_delta": 16479,
            "run_time_ns_delta": 1735219,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": 173.84078481826953,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 679,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 3109,
            "run_time_ns_delta": 540471,
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
            "avg_ns_per_run": 105.0517879161529,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 681,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 4866,
            "run_time_ns_delta": 511182,
            "type": "kprobe"
          },
          "682": {
            "avg_ns_per_run": 102.80579531442663,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 682,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 4866,
            "run_time_ns_delta": 500253,
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
            "avg_ns_per_run": 176.26258992805757,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 684,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 1946,
            "run_time_ns_delta": 343007,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 106.67454688731284,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 685,
            "name": "trace_do_mmap",
            "run_cnt_delta": 1269,
            "run_time_ns_delta": 135370,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 92.50197005516155,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 686,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 1269,
            "run_time_ns_delta": 117385,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": 1115.7935382190701,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 687,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 1269,
            "run_time_ns_delta": 1415942,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": 1629.0848214285713,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 688,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 224,
            "run_time_ns_delta": 364915,
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
            "avg_ns_per_run": 551.7734883317429,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 690,
            "name": "trace_security_bpf",
            "run_cnt_delta": 11527,
            "run_time_ns_delta": 6360293,
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
            "avg_ns_per_run": 442.4652406417112,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 693,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2992,
            "run_time_ns_delta": 1323856,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 1170.3333333333333,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 694,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 240,
            "run_time_ns_delta": 280880,
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
            "avg_ns_per_run": 2739.2,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 698,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 27392,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": 3618.5,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 699,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 36185,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": 2836.12,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 700,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 141806,
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
            "avg_ns_per_run": 6848.6,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 704,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 68486,
            "type": "raw_tracepoint"
          },
          "705": {
            "avg_ns_per_run": 7330.5,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 705,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 73305,
            "type": "raw_tracepoint"
          },
          "706": {
            "avg_ns_per_run": 522.1,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 706,
            "name": "trace_do_init_module",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 5221,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": 217.4,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 707,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 2174,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 2080.4274193548385,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 708,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 124,
            "run_time_ns_delta": 257973,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 38.68342116452565,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 709,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 77611,
            "run_time_ns_delta": 3002259,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 2675.609375,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 710,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 64,
            "run_time_ns_delta": 171239,
            "type": "raw_tracepoint"
          },
          "711": {
            "avg_ns_per_run": 2988.88,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 711,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 149444,
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
            "avg_ns_per_run": 734.676293622142,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 714,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 831,
            "run_time_ns_delta": 610516,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 3027.507692307692,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 715,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 65,
            "run_time_ns_delta": 196788,
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
            "avg_ns_per_run": 1476.3809907370116,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 717,
            "name": "trace_do_truncate",
            "run_cnt_delta": 2483,
            "run_time_ns_delta": 3665854,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 376.9588191250401,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 718,
            "name": "trace_fd_install",
            "run_cnt_delta": 9349,
            "run_time_ns_delta": 3524188,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 768.5501202886928,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 719,
            "name": "trace_filp_close",
            "run_cnt_delta": 7482,
            "run_time_ns_delta": 5750292,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": 119.70452409719425,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 720,
            "name": "trace_file_update_time",
            "run_cnt_delta": 7449,
            "run_time_ns_delta": 891679,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 38.98644113303799,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 721,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 7449,
            "run_time_ns_delta": 290410,
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
            "avg_ns_per_run": 478.56,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 724,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 23928,
            "type": "kprobe"
          },
          "725": {
            "avg_ns_per_run": 299.78,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 725,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 14989,
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
            "avg_ns_per_run": 171.20967741935485,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 727,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 10615,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": 4925.6612903225805,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 728,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 305391,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": 3957.2053571428573,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 729,
            "name": "trace_execute_finished",
            "run_cnt_delta": 112,
            "run_time_ns_delta": 443207,
            "type": "kprobe"
          },
          "730": {
            "avg_ns_per_run": 3563.1,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 730,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 178155,
            "type": "kprobe"
          },
          "731": {
            "avg_ns_per_run": 2822.090909090909,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 731,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 11,
            "run_time_ns_delta": 31043,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": 1421.25,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 732,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5685,
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
            "avg_ns_per_run": 3246.88,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 734,
            "name": "trace_chmod_common",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 162344,
            "type": "kprobe"
          },
          "735": {
            "avg_ns_per_run": 1197.2142857142858,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 735,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 16761,
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
            "avg_ns_per_run": 371.69714285714286,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 738,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 130094,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 1127.28,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 739,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 394548,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": 1630.82,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 740,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 81541,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": 149.47761194029852,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 741,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 268,
            "run_time_ns_delta": 40060,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 364.93283582089555,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 742,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 134,
            "run_time_ns_delta": 48901,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 1124.1436388508891,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 743,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 731,
            "run_time_ns_delta": 821749,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 2049.4104234527686,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 745,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 307,
            "run_time_ns_delta": 629169,
            "type": "cgroup_skb"
          },
          "746": {
            "avg_ns_per_run": 2708.0781758957655,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 746,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 307,
            "run_time_ns_delta": 831380,
            "type": "cgroup_skb"
          },
          "747": {
            "avg_ns_per_run": 2556.0,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 747,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2556,
            "type": "raw_tracepoint"
          },
          "748": {
            "avg_ns_per_run": 2810.0,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 748,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2810,
            "type": "raw_tracepoint"
          },
          "749": {
            "avg_ns_per_run": 76.35483870967742,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 749,
            "name": "empty_kprobe",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 4734,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": 1015.6935483870968,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 750,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 62,
            "run_time_ns_delta": 62973,
            "type": "raw_tracepoint"
          },
          "751": {
            "avg_ns_per_run": 700.2885885424666,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 751,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 6511,
            "run_time_ns_delta": 4559579,
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
            "duration_s": 5.073399460999951,
            "ops_per_sec": 490.40096667444806,
            "ops_total": 2488.0,
            "stderr": "module_load_candidate=vcan",
            "stdout": ""
          }
        ]
      },
      "error": "prog 689: BPF_PROG_REJIT: Invalid argument (os error 22)",
      "post_rejit": {
        "bpf": {
          "594": {
            "avg_ns_per_run": 175.5284035416632,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 594,
            "name": "tracepoint__raw",
            "run_cnt_delta": 904095,
            "run_time_ns_delta": 158694352,
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
            "avg_ns_per_run": 262.77466200074326,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 597,
            "name": "tracepoint__raw",
            "run_cnt_delta": 904144,
            "run_time_ns_delta": 237586134,
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
            "avg_ns_per_run": 217.09998672859987,
            "bytes_jited": 8131,
            "bytes_xlated": 13608,
            "id": 600,
            "name": "trace_sys_enter",
            "run_cnt_delta": 904200,
            "run_time_ns_delta": 196301808,
            "type": "raw_tracepoint"
          },
          "601": {
            "avg_ns_per_run": 195.8385538837555,
            "bytes_jited": 8164,
            "bytes_xlated": 13664,
            "id": 601,
            "name": "trace_sys_exit",
            "run_cnt_delta": 904215,
            "run_time_ns_delta": 177080158,
            "type": "raw_tracepoint"
          },
          "602": {
            "avg_ns_per_run": 591.38,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 602,
            "name": "trace_ptrace",
            "run_cnt_delta": 100,
            "run_time_ns_delta": 59138,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": 2003.44,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 603,
            "name": "trace_ret_ptrac",
            "run_cnt_delta": 100,
            "run_time_ns_delta": 200344,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": 370.3,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 604,
            "name": "trace_process_v",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 18515,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": 2602.14,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 605,
            "name": "trace_ret_proce",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 130107,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": 1159.71875,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 606,
            "name": "trace_arch_prct",
            "run_cnt_delta": 64,
            "run_time_ns_delta": 74222,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": 2341.265625,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 607,
            "name": "trace_ret_arch_",
            "run_cnt_delta": 64,
            "run_time_ns_delta": 149841,
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
            "avg_ns_per_run": 994.525641025641,
            "bytes_jited": 2358,
            "bytes_xlated": 4424,
            "id": 610,
            "name": "trace_dup2",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 77573,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 2844.269230769231,
            "bytes_jited": 11283,
            "bytes_xlated": 19416,
            "id": 611,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 221853,
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
            "avg_ns_per_run": 5547.745833333333,
            "bytes_jited": 19847,
            "bytes_xlated": 32320,
            "id": 619,
            "name": "tracepoint__sch",
            "run_cnt_delta": 240,
            "run_time_ns_delta": 1331459,
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
            "avg_ns_per_run": 5771.0625,
            "bytes_jited": 20525,
            "bytes_xlated": 35336,
            "id": 627,
            "name": "tracepoint__sch",
            "run_cnt_delta": 64,
            "run_time_ns_delta": 369348,
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
            "avg_ns_per_run": 2166.873949579832,
            "bytes_jited": 8680,
            "bytes_xlated": 14464,
            "id": 629,
            "name": "tracepoint__sch",
            "run_cnt_delta": 238,
            "run_time_ns_delta": 515716,
            "type": "raw_tracepoint"
          },
          "630": {
            "avg_ns_per_run": 1360.3865546218487,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 630,
            "name": "tracepoint__sch",
            "run_cnt_delta": 238,
            "run_time_ns_delta": 323772,
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
            "avg_ns_per_run": 325.48750338562826,
            "bytes_jited": 8925,
            "bytes_xlated": 14840,
            "id": 632,
            "name": "tracepoint__sch",
            "run_cnt_delta": 959940,
            "run_time_ns_delta": 312448474,
            "type": "raw_tracepoint"
          },
          "633": {
            "avg_ns_per_run": 18.721434028156718,
            "bytes_jited": 8163,
            "bytes_xlated": 13680,
            "id": 633,
            "name": "trace_filldir64",
            "run_cnt_delta": 18326,
            "run_time_ns_delta": 343089,
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
            "avg_ns_per_run": 1558.0084033613446,
            "bytes_jited": 7921,
            "bytes_xlated": 13312,
            "id": 635,
            "name": "trace_do_exit",
            "run_cnt_delta": 238,
            "run_time_ns_delta": 370806,
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
            "avg_ns_per_run": 669.2184300341297,
            "bytes_jited": 11470,
            "bytes_xlated": 18264,
            "id": 639,
            "name": "trace_security_",
            "run_cnt_delta": 293,
            "run_time_ns_delta": 196081,
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
            "avg_ns_per_run": 2343.0,
            "bytes_jited": 8620,
            "bytes_xlated": 14352,
            "id": 641,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2343,
            "type": "raw_tracepoint"
          },
          "642": {
            "avg_ns_per_run": 2427.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 642,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2427,
            "type": "raw_tracepoint"
          },
          "643": {
            "avg_ns_per_run": 1588.0,
            "bytes_jited": 8601,
            "bytes_xlated": 14336,
            "id": 643,
            "name": "tracepoint__cgr",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1588,
            "type": "raw_tracepoint"
          },
          "644": {
            "avg_ns_per_run": 3810.53125,
            "bytes_jited": 33373,
            "bytes_xlated": 52824,
            "id": 644,
            "name": "trace_security_",
            "run_cnt_delta": 64,
            "run_time_ns_delta": 243874,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": 1260.7776027495345,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 645,
            "name": "trace_security_file_open",
            "run_cnt_delta": 6983,
            "run_time_ns_delta": 8804010,
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
            "avg_ns_per_run": 2231.518181818182,
            "bytes_jited": 9984,
            "bytes_xlated": 16352,
            "id": 647,
            "name": "trace_security_",
            "run_cnt_delta": 220,
            "run_time_ns_delta": 490934,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 923.2578125,
            "bytes_jited": 10723,
            "bytes_xlated": 16880,
            "id": 648,
            "name": "trace_commit_cr",
            "run_cnt_delta": 128,
            "run_time_ns_delta": 118177,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 1225.735294117647,
            "bytes_jited": 10045,
            "bytes_xlated": 16520,
            "id": 649,
            "name": "trace_switch_ta",
            "run_cnt_delta": 238,
            "run_time_ns_delta": 291725,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": 172.80270431794412,
            "bytes_jited": 8174,
            "bytes_xlated": 13680,
            "id": 650,
            "name": "trace_cap_capab",
            "run_cnt_delta": 26772,
            "run_time_ns_delta": 4626274,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": 1568.3564356435643,
            "bytes_jited": 8471,
            "bytes_xlated": 14120,
            "id": 651,
            "name": "trace_security_",
            "run_cnt_delta": 202,
            "run_time_ns_delta": 316808,
            "type": "kprobe"
          },
          "652": {
            "avg_ns_per_run": 3333.18,
            "bytes_jited": 9144,
            "bytes_xlated": 15208,
            "id": 652,
            "name": "trace_security_",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 166659,
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
            "avg_ns_per_run": 2229.82,
            "bytes_jited": 10780,
            "bytes_xlated": 16456,
            "id": 656,
            "name": "trace_security_",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 111491,
            "type": "kprobe"
          },
          "657": {
            "avg_ns_per_run": 2298.2,
            "bytes_jited": 10075,
            "bytes_xlated": 15400,
            "id": 657,
            "name": "trace_security_",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 114910,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 3157.2027027027025,
            "bytes_jited": 11260,
            "bytes_xlated": 17192,
            "id": 658,
            "name": "trace_security_",
            "run_cnt_delta": 148,
            "run_time_ns_delta": 467266,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": 1993.7307692307693,
            "bytes_jited": 10589,
            "bytes_xlated": 16080,
            "id": 659,
            "name": "trace_security_",
            "run_cnt_delta": 52,
            "run_time_ns_delta": 103674,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": 2412.625,
            "bytes_jited": 11025,
            "bytes_xlated": 16864,
            "id": 660,
            "name": "trace_security_",
            "run_cnt_delta": 56,
            "run_time_ns_delta": 135107,
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
            "avg_ns_per_run": 68.85187923028946,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 663,
            "name": "trace_vfs_write",
            "run_cnt_delta": 43289,
            "run_time_ns_delta": 2980529,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 41.02384473197782,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 664,
            "name": "vfs_write_magic",
            "run_cnt_delta": 43280,
            "run_time_ns_delta": 1775512,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": 30.762467070296253,
            "bytes_jited": 19108,
            "bytes_xlated": 31720,
            "id": 665,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 43274,
            "run_time_ns_delta": 1331215,
            "type": "kprobe"
          },
          "666": {
            "avg_ns_per_run": 52.84396687332285,
            "bytes_jited": 23757,
            "bytes_xlated": 36648,
            "id": 666,
            "name": "vfs_write_magic",
            "run_cnt_delta": 43228,
            "run_time_ns_delta": 2284339,
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
            "avg_ns_per_run": 85.1532472464869,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 668,
            "name": "trace_vfs_write",
            "run_cnt_delta": 5266,
            "run_time_ns_delta": 448417,
            "type": "kprobe"
          },
          "669": {
            "avg_ns_per_run": 50.22559817698443,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 669,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 5266,
            "run_time_ns_delta": 264488,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 51.58127611090011,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 670,
            "name": "trace_ret_vfs_w",
            "run_cnt_delta": 5266,
            "run_time_ns_delta": 271627,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": 69.41834409418914,
            "bytes_jited": 23786,
            "bytes_xlated": 36696,
            "id": 671,
            "name": "vfs_writev_magi",
            "run_cnt_delta": 5266,
            "run_time_ns_delta": 365557,
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
            "avg_ns_per_run": 98.54986604968339,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 678,
            "name": "trace_vfs_read",
            "run_cnt_delta": 16424,
            "run_time_ns_delta": 1618583,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": 118.03906068356196,
            "bytes_jited": 19111,
            "bytes_xlated": 31720,
            "id": 679,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 4301,
            "run_time_ns_delta": 507686,
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
            "avg_ns_per_run": 92.93619445499431,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 681,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 5266,
            "run_time_ns_delta": 489402,
            "type": "kprobe"
          },
          "682": {
            "avg_ns_per_run": 89.47645271553361,
            "bytes_jited": 19107,
            "bytes_xlated": 31712,
            "id": 682,
            "name": "trace_ret_vfs_r",
            "run_cnt_delta": 5266,
            "run_time_ns_delta": 471183,
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
            "avg_ns_per_run": 200.86185983827494,
            "bytes_jited": 20715,
            "bytes_xlated": 32736,
            "id": 684,
            "name": "trace_mmap_aler",
            "run_cnt_delta": 1484,
            "run_time_ns_delta": 298079,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 91.11742707554225,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 685,
            "name": "trace_do_mmap",
            "run_cnt_delta": 1337,
            "run_time_ns_delta": 121824,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 67.06357516828722,
            "bytes_jited": 19426,
            "bytes_xlated": 31584,
            "id": 686,
            "name": "trace_ret_do_mm",
            "run_cnt_delta": 1337,
            "run_time_ns_delta": 89664,
            "type": "kprobe"
          },
          "687": {
            "avg_ns_per_run": 1136.8399401645474,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 687,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 1337,
            "run_time_ns_delta": 1519955,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": 1660.457627118644,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 688,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 236,
            "run_time_ns_delta": 391868,
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
            "avg_ns_per_run": 627.3857995894756,
            "bytes_jited": 15585,
            "bytes_xlated": 26904,
            "id": 690,
            "name": "trace_security_",
            "run_cnt_delta": 10718,
            "run_time_ns_delta": 6724321,
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
            "avg_ns_per_run": 470.8377715487036,
            "bytes_jited": 8333,
            "bytes_xlated": 13904,
            "id": 693,
            "name": "trace_security_",
            "run_cnt_delta": 2854,
            "run_time_ns_delta": 1343771,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 1111.6958333333334,
            "bytes_jited": 9581,
            "bytes_xlated": 15448,
            "id": 694,
            "name": "trace_security_",
            "run_cnt_delta": 240,
            "run_time_ns_delta": 266807,
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
            "avg_ns_per_run": 2796.0,
            "bytes_jited": 18641,
            "bytes_xlated": 30648,
            "id": 698,
            "name": "trace_security_",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 33552,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": 3901.4166666666665,
            "bytes_jited": 17247,
            "bytes_xlated": 30448,
            "id": 699,
            "name": "trace_security_",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 46817,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": 2705.82,
            "bytes_jited": 9225,
            "bytes_xlated": 15352,
            "id": 700,
            "name": "trace_security_",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 135291,
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
            "avg_ns_per_run": 7195.166666666667,
            "bytes_jited": 19868,
            "bytes_xlated": 32648,
            "id": 704,
            "name": "tracepoint__mod",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 86342,
            "type": "raw_tracepoint"
          },
          "705": {
            "avg_ns_per_run": 7362.75,
            "bytes_jited": 8959,
            "bytes_xlated": 14920,
            "id": 705,
            "name": "tracepoint__mod",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 88353,
            "type": "raw_tracepoint"
          },
          "706": {
            "avg_ns_per_run": 562.0833333333334,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 706,
            "name": "trace_do_init_m",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 6745,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": 201.83333333333334,
            "bytes_jited": 14542,
            "bytes_xlated": 23904,
            "id": 707,
            "name": "trace_ret_do_in",
            "run_cnt_delta": 12,
            "run_time_ns_delta": 2422,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 2165.0390625,
            "bytes_jited": 18482,
            "bytes_xlated": 30352,
            "id": 708,
            "name": "trace_load_elf_",
            "run_cnt_delta": 128,
            "run_time_ns_delta": 277125,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": 38.41319092933792,
            "bytes_jited": 8681,
            "bytes_xlated": 14496,
            "id": 709,
            "name": "trace_security_",
            "run_cnt_delta": 79024,
            "run_time_ns_delta": 3035564,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": 2866.121212121212,
            "bytes_jited": 8474,
            "bytes_xlated": 14112,
            "id": 710,
            "name": "tracepoint__tas",
            "run_cnt_delta": 66,
            "run_time_ns_delta": 189164,
            "type": "raw_tracepoint"
          },
          "711": {
            "avg_ns_per_run": 3251.2,
            "bytes_jited": 9792,
            "bytes_xlated": 16344,
            "id": 711,
            "name": "trace_security_",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 162560,
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
            "avg_ns_per_run": 754.0463645943098,
            "bytes_jited": 10109,
            "bytes_xlated": 16296,
            "id": 714,
            "name": "trace_do_sigact",
            "run_cnt_delta": 949,
            "run_time_ns_delta": 715590,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 2956.573529411765,
            "bytes_jited": 18560,
            "bytes_xlated": 30528,
            "id": 715,
            "name": "trace_vfs_utime",
            "run_cnt_delta": 68,
            "run_time_ns_delta": 201047,
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
            "avg_ns_per_run": 1433.1617592247485,
            "bytes_jited": 9530,
            "bytes_xlated": 15824,
            "id": 717,
            "name": "trace_do_trunca",
            "run_cnt_delta": 2683,
            "run_time_ns_delta": 3845173,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 407.94519804666305,
            "bytes_jited": 16708,
            "bytes_xlated": 27176,
            "id": 718,
            "name": "trace_fd_instal",
            "run_cnt_delta": 9215,
            "run_time_ns_delta": 3759215,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 833.1122002914293,
            "bytes_jited": 16636,
            "bytes_xlated": 27024,
            "id": 719,
            "name": "trace_filp_clos",
            "run_cnt_delta": 7549,
            "run_time_ns_delta": 6289164,
            "type": "kprobe"
          },
          "720": {
            "avg_ns_per_run": 105.56913902348118,
            "bytes_jited": 459,
            "bytes_xlated": 768,
            "id": 720,
            "name": "trace_file_upda",
            "run_cnt_delta": 8049,
            "run_time_ns_delta": 849726,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 48.195179525406886,
            "bytes_jited": 20054,
            "bytes_xlated": 31168,
            "id": 721,
            "name": "trace_ret_file_",
            "run_cnt_delta": 8049,
            "run_time_ns_delta": 387923,
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
            "avg_ns_per_run": 417.36,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 724,
            "name": "trace_inotify_f",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 20868,
            "type": "kprobe"
          },
          "725": {
            "avg_ns_per_run": 341.92,
            "bytes_jited": 18025,
            "bytes_xlated": 29936,
            "id": 725,
            "name": "trace_ret_inoti",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 17096,
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
            "avg_ns_per_run": 367.0625,
            "bytes_jited": 16472,
            "bytes_xlated": 28872,
            "id": 727,
            "name": "trace_exec_binp",
            "run_cnt_delta": 64,
            "run_time_ns_delta": 23492,
            "type": "kprobe"
          },
          "728": {
            "avg_ns_per_run": 4893.328125,
            "bytes_jited": 16702,
            "bytes_xlated": 29144,
            "id": 728,
            "name": "trace_security_",
            "run_cnt_delta": 64,
            "run_time_ns_delta": 313173,
            "type": "kprobe"
          },
          "729": {
            "avg_ns_per_run": 4105.377192982456,
            "bytes_jited": 24469,
            "bytes_xlated": 38320,
            "id": 729,
            "name": "trace_execute_f",
            "run_cnt_delta": 114,
            "run_time_ns_delta": 468013,
            "type": "kprobe"
          },
          "730": {
            "avg_ns_per_run": 3543.92,
            "bytes_jited": 18391,
            "bytes_xlated": 30200,
            "id": 730,
            "name": "trace_security_",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 177196,
            "type": "kprobe"
          },
          "731": {
            "avg_ns_per_run": 2892.230769230769,
            "bytes_jited": 18194,
            "bytes_xlated": 29912,
            "id": 731,
            "name": "trace_set_fs_pw",
            "run_cnt_delta": 13,
            "run_time_ns_delta": 37599,
            "type": "kprobe"
          },
          "732": {
            "avg_ns_per_run": 1362.75,
            "bytes_jited": 8631,
            "bytes_xlated": 14360,
            "id": 732,
            "name": "trace_security_",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5451,
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
            "avg_ns_per_run": 3510.86,
            "bytes_jited": 17561,
            "bytes_xlated": 29176,
            "id": 734,
            "name": "trace_chmod_com",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 175543,
            "type": "kprobe"
          },
          "735": {
            "avg_ns_per_run": 1548.5,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 735,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 21679,
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
            "avg_ns_per_run": 263.66381766381767,
            "bytes_jited": 329,
            "bytes_xlated": 520,
            "id": 738,
            "name": "trace_sock_allo",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 92546,
            "type": "kprobe"
          },
          "739": {
            "avg_ns_per_run": 1305.5242165242166,
            "bytes_jited": 8439,
            "bytes_xlated": 12928,
            "id": 739,
            "name": "trace_ret_sock_",
            "run_cnt_delta": 351,
            "run_time_ns_delta": 458239,
            "type": "kprobe"
          },
          "740": {
            "avg_ns_per_run": 1704.0,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 740,
            "name": "trace_security_",
            "run_cnt_delta": 50,
            "run_time_ns_delta": 85200,
            "type": "kprobe"
          },
          "741": {
            "avg_ns_per_run": 171.04615384615386,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 741,
            "name": "trace_security_",
            "run_cnt_delta": 260,
            "run_time_ns_delta": 44472,
            "type": "kprobe"
          },
          "742": {
            "avg_ns_per_run": 335.1,
            "bytes_jited": 8683,
            "bytes_xlated": 13152,
            "id": 742,
            "name": "trace_security_",
            "run_cnt_delta": 120,
            "run_time_ns_delta": 40212,
            "type": "kprobe"
          },
          "743": {
            "avg_ns_per_run": 1158.4957020057307,
            "bytes_jited": 5282,
            "bytes_xlated": 8136,
            "id": 743,
            "name": "cgroup_bpf_run_",
            "run_cnt_delta": 698,
            "run_time_ns_delta": 808630,
            "type": "kprobe"
          },
          "745": {
            "avg_ns_per_run": 2151.562913907285,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 745,
            "name": "cgroup_skb_ingr",
            "run_cnt_delta": 302,
            "run_time_ns_delta": 649772,
            "type": "cgroup_skb"
          },
          "746": {
            "avg_ns_per_run": 2864.135761589404,
            "bytes_jited": 16144,
            "bytes_xlated": 25792,
            "id": 746,
            "name": "cgroup_skb_egre",
            "run_cnt_delta": 302,
            "run_time_ns_delta": 864969,
            "type": "cgroup_skb"
          },
          "747": {
            "avg_ns_per_run": 3546.0,
            "bytes_jited": 916,
            "bytes_xlated": 1560,
            "id": 747,
            "name": "cgroup_mkdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3546,
            "type": "raw_tracepoint"
          },
          "748": {
            "avg_ns_per_run": 2786.0,
            "bytes_jited": 898,
            "bytes_xlated": 1520,
            "id": 748,
            "name": "cgroup_rmdir_si",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2786,
            "type": "raw_tracepoint"
          },
          "749": {
            "avg_ns_per_run": 152.375,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 749,
            "name": "empty_kprobe",
            "run_cnt_delta": 64,
            "run_time_ns_delta": 9752,
            "type": "kprobe"
          },
          "750": {
            "avg_ns_per_run": 1123.734375,
            "bytes_jited": 58660,
            "bytes_xlated": 95944,
            "id": 750,
            "name": "tracepoint__exe",
            "run_cnt_delta": 64,
            "run_time_ns_delta": 71919,
            "type": "raw_tracepoint"
          },
          "751": {
            "avg_ns_per_run": 740.1065888714957,
            "bytes_jited": 7290,
            "bytes_xlated": 13264,
            "id": 751,
            "name": "lsm_file_open_t",
            "run_cnt_delta": 7027,
            "run_time_ns_delta": 5200729,
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
            "duration_s": 5.3019936500000995,
            "ops_per_sec": 507.167714167283,
            "ops_total": 2689.0,
            "stderr": "module_load_candidate=vcan",
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
        "output_chars": 2254064,
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
            "avg_ns_per_run": 125.6786661102656,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 758,
            "name": "cap_capable",
            "run_cnt_delta": 162952,
            "run_time_ns_delta": 20479590,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0472209010000029,
            "ops_per_sec": 1296.765561786659,
            "ops_total": 1358.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [25473] setting to a 1 secs run per stressor\nstress-ng: info:  [25473] dispatching hogs: 2 exec\nstress-ng: info:  [25473] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25473] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25473]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25473] exec               1358      1.02      2.57      0.83      1330.81         398.62\nstress-ng: info:  [25473] skipped: 0\nstress-ng: info:  [25473] passed: 2: exec (2)\nstress-ng: info:  [25473] failed: 0\nstress-ng: info:  [25473] metrics untrustworthy: 0\nstress-ng: info:  [25473] successful run completed in 1.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "758": {
            "avg_ns_per_run": 118.31930999812944,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 758,
            "name": "cap_capable",
            "run_cnt_delta": 171072,
            "run_time_ns_delta": 20241121,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0647027219999927,
            "ops_per_sec": 1371.2747885695835,
            "ops_total": 1460.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [19605] setting to a 1 secs run per stressor\nstress-ng: info:  [19605] dispatching hogs: 2 exec\nstress-ng: info:  [19605] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [19605] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19605]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19605] exec               1460      1.03      2.71      0.87      1418.26         407.71\nstress-ng: info:  [19605] skipped: 0\nstress-ng: info:  [19605] passed: 2: exec (2)\nstress-ng: info:  [19605] failed: 0\nstress-ng: info:  [19605] metrics untrustworthy: 0\nstress-ng: info:  [19605] successful run completed in 1.05 secs"
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
        "output_chars": 5256,
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
            "avg_ns_per_run": 153.3770497081044,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 764,
            "name": "block_io_start",
            "run_cnt_delta": 745472,
            "run_time_ns_delta": 114338296,
            "type": "tracepoint"
          },
          "765": {
            "avg_ns_per_run": 281.2024636740213,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 765,
            "name": "block_io_done",
            "run_cnt_delta": 745472,
            "run_time_ns_delta": 209628563,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.000875887999996,
            "ops_per_sec": 149068.28657532175,
            "ops_total": 745472.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "764": {
            "avg_ns_per_run": 147.530583937983,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 764,
            "name": "block_io_start",
            "run_cnt_delta": 745473,
            "run_time_ns_delta": 109980067,
            "type": "tracepoint"
          },
          "765": {
            "avg_ns_per_run": 306.15733500743823,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 765,
            "name": "block_io_done",
            "run_cnt_delta": 745473,
            "run_time_ns_delta": 228232027,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.037943176999988,
            "ops_per_sec": 147971.49825018793,
            "ops_total": 745472.0,
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
        "output_chars": 12591,
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
            "avg_ns_per_run": 1290.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 771,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1290,
            "type": "perf_event"
          },
          "772": {
            "avg_ns_per_run": 67.06503762891387,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 772,
            "name": "vfs_create",
            "run_cnt_delta": 10763,
            "run_time_ns_delta": 721821,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0015853450000236,
            "ops_per_sec": 97.84488210537634,
            "ops_total": 98.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "771": {
            "avg_ns_per_run": 1405.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 771,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1405,
            "type": "perf_event"
          },
          "772": {
            "avg_ns_per_run": 60.23352405170587,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 772,
            "name": "vfs_create",
            "run_cnt_delta": 9438,
            "run_time_ns_delta": 568484,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0066480919999776,
            "ops_per_sec": 99.339581324118,
            "ops_total": 100.0,
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
            "avg_ns_per_run": 107.38117865647257,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 778,
            "name": "sched_wakeup",
            "run_cnt_delta": 93649,
            "run_time_ns_delta": 10056140,
            "type": "tracepoint"
          },
          "779": {
            "avg_ns_per_run": 230.06944174285158,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 779,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 5141,
            "run_time_ns_delta": 1182787,
            "type": "tracepoint"
          },
          "780": {
            "avg_ns_per_run": 162.22613176094563,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 780,
            "name": "sched_switch",
            "run_cnt_delta": 145172,
            "run_time_ns_delta": 23550692,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0199814540000034,
            "ops_per_sec": 19.608199660461604,
            "ops_total": 20.0,
            "stderr": "",
            "stdout": "Time: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.033\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.041\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.029\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.026\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.033\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.043\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.030\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.029\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.030\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "778": {
            "avg_ns_per_run": 99.44864559819413,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 778,
            "name": "sched_wakeup",
            "run_cnt_delta": 85056,
            "run_time_ns_delta": 8458704,
            "type": "tracepoint"
          },
          "779": {
            "avg_ns_per_run": 223.97549114958179,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 779,
            "name": "sched_wakeup_ne",
            "run_cnt_delta": 5141,
            "run_time_ns_delta": 1151458,
            "type": "tracepoint"
          },
          "780": {
            "avg_ns_per_run": 153.58388753142816,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 780,
            "name": "sched_switch",
            "run_cnt_delta": 141195,
            "run_time_ns_delta": 21685277,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0111909720000085,
            "ops_per_sec": 19.778657596638265,
            "ops_total": 20.0,
            "stderr": "",
            "stdout": "Time: 0.035\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.038\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.028\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.030\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.036\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.035\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.037\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.028\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.032\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.033\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.029\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.033\nRunning in process mode with 8 groups using 32 file descriptors each (== 256 tasks)\nEach sender will pass 10 messages of 100 bytes\nTime: 0.032"
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
        "output_chars": 13108,
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
            "avg_ns_per_run": 775.2368728121354,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 787,
            "name": "tcp_set_state",
            "run_cnt_delta": 1714,
            "run_time_ns_delta": 1328756,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0026895299999978,
            "ops_per_sec": 171.5386416770507,
            "ops_total": 172.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "787": {
            "avg_ns_per_run": 712.767955801105,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 787,
            "name": "tcp_set_state",
            "run_cnt_delta": 1810,
            "run_time_ns_delta": 1290110,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0023384689999375,
            "ops_per_sec": 181.57539157564884,
            "ops_total": 182.0,
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
        "output_chars": 7021,
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
            "avg_ns_per_run": 5098.166666666667,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 793,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 24,
            "run_time_ns_delta": 122356,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.17726999499996,
            "ops_per_sec": 0.4891608082460067,
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
            "avg_ns_per_run": 4199.875,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 793,
            "name": "tcp_retransmit_",
            "run_cnt_delta": 16,
            "run_time_ns_delta": 67198,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 8.169044320000012,
            "ops_per_sec": 0.4896533600885145,
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
    "losses": 73,
    "per_program_geomean": 0.9872645037667326,
    "program_count": 133,
    "wins": 60
  },
  "workload_seconds": 1.0
}
```
