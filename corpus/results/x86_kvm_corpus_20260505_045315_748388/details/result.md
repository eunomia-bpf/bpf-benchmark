# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T05:04:27.016025+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-05T04:53:15.782880+00:00",
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
      "invoked_at": "2026-05-05T04:53:15.782815+00:00",
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
        "captured_at": "2026-05-05T04:53:15.782807+00:00",
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
      "captured_at": "2026-05-05T04:53:15.764795+00:00",
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
      "baseline_avg_ns_per_run": 159.511327337757,
      "baseline_run_cnt_delta": 1255370,
      "baseline_run_time_ns_delta": 200245735,
      "post_rejit_avg_ns_per_run": 161.05035884545376,
      "post_rejit_run_cnt_delta": 1153700,
      "post_rejit_run_time_ns_delta": 185803799,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 1.0096484151525988,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 195.6264868063976,
      "baseline_run_cnt_delta": 1801176,
      "baseline_run_time_ns_delta": 352357733,
      "post_rejit_avg_ns_per_run": 210.09272065601965,
      "post_rejit_run_cnt_delta": 1760557,
      "post_rejit_run_time_ns_delta": 369880210,
      "program": "trace_pid_start_tp",
      "program_id": 9,
      "ratio": 1.0739482372033733,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 193.72337115656018,
      "baseline_run_cnt_delta": 1801186,
      "baseline_run_time_ns_delta": 348931824,
      "post_rejit_avg_ns_per_run": 198.99417289998053,
      "post_rejit_run_cnt_delta": 1760567,
      "post_rejit_run_time_ns_delta": 350342574,
      "program": "trace_req_start",
      "program_id": 10,
      "ratio": 1.0272078774592492,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 91.77781423513665,
      "baseline_run_cnt_delta": 1801191,
      "baseline_run_time_ns_delta": 165309373,
      "post_rejit_avg_ns_per_run": 93.05852643345459,
      "post_rejit_run_cnt_delta": 1760572,
      "post_rejit_run_time_ns_delta": 163836236,
      "program": "trace_req_completion_tp",
      "program_id": 11,
      "ratio": 1.0139544857217533,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 61.109886174702645,
      "baseline_run_cnt_delta": 117285,
      "baseline_run_time_ns_delta": 7167273,
      "post_rejit_avg_ns_per_run": 62.11342846313806,
      "post_rejit_run_cnt_delta": 97621,
      "post_rejit_run_time_ns_delta": 6063575,
      "program": "vfs_create",
      "program_id": 14,
      "ratio": 1.0164219302514566,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 70.06949806949807,
      "baseline_run_cnt_delta": 518,
      "baseline_run_time_ns_delta": 36296,
      "post_rejit_avg_ns_per_run": 71.55532786885246,
      "post_rejit_run_cnt_delta": 488,
      "post_rejit_run_time_ns_delta": 34919,
      "program": "kfunc__vmlinux__vfs_fsync_range",
      "program_id": 15,
      "ratio": 1.021205086953537,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 49.14765810206582,
      "baseline_run_cnt_delta": 1888938,
      "baseline_run_time_ns_delta": 92836879,
      "post_rejit_avg_ns_per_run": 48.37473849690534,
      "post_rejit_run_cnt_delta": 1890513,
      "post_rejit_run_time_ns_delta": 91453072,
      "program": "vfs_open",
      "program_id": 16,
      "ratio": 0.9842735211603502,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 47.319182746878546,
      "baseline_run_cnt_delta": 44050,
      "baseline_run_time_ns_delta": 2084410,
      "post_rejit_avg_ns_per_run": 76.74403326771218,
      "post_rejit_run_cnt_delta": 45209,
      "post_rejit_run_time_ns_delta": 3469521,
      "program": "vfs_read",
      "program_id": 17,
      "ratio": 1.621837673702737,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 55.231237216132584,
      "baseline_run_cnt_delta": 38134,
      "baseline_run_time_ns_delta": 2106188,
      "post_rejit_avg_ns_per_run": 54.12892148303359,
      "post_rejit_run_cnt_delta": 34362,
      "post_rejit_run_time_ns_delta": 1859978,
      "program": "vfs_write",
      "program_id": 18,
      "ratio": 0.9800418062556633,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 231.51762472885034,
      "baseline_run_cnt_delta": 3688,
      "baseline_run_time_ns_delta": 853837,
      "post_rejit_avg_ns_per_run": 186.63573147900507,
      "post_rejit_run_cnt_delta": 3739,
      "post_rejit_run_time_ns_delta": 697831,
      "program": "__x64_sys_open",
      "program_id": 21,
      "ratio": 0.8061404901574547,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 239.51319690978957,
      "baseline_run_cnt_delta": 916313,
      "baseline_run_time_ns_delta": 219469056,
      "post_rejit_avg_ns_per_run": 247.56208129455396,
      "post_rejit_run_cnt_delta": 945623,
      "post_rejit_run_time_ns_delta": 234100398,
      "program": "kretfunc__vmlinux____x64_sys_openat",
      "program_id": 22,
      "ratio": 1.0336051812117724,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 237.58840579710144,
      "baseline_run_cnt_delta": 690,
      "baseline_run_time_ns_delta": 163936,
      "post_rejit_avg_ns_per_run": 203.88292011019283,
      "post_rejit_run_cnt_delta": 726,
      "post_rejit_run_time_ns_delta": 148019,
      "program": "kretfunc__vmlinux____x64_sys_openat2",
      "program_id": 23,
      "ratio": 0.8581349726480642,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 63.51321063813738,
      "baseline_run_cnt_delta": 30080341,
      "baseline_run_time_ns_delta": 1910499034,
      "post_rejit_avg_ns_per_run": 110.28480843047936,
      "post_rejit_run_cnt_delta": 26512751,
      "post_rejit_run_time_ns_delta": 2923953665,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 26,
      "ratio": 1.7364073918231009,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 110.4600920453369,
      "baseline_run_cnt_delta": 30080394,
      "baseline_run_time_ns_delta": 3322683090,
      "post_rejit_avg_ns_per_run": 25.54331891600467,
      "post_rejit_run_cnt_delta": 26512771,
      "post_rejit_run_time_ns_delta": 677224165,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 27,
      "ratio": 0.23124477304908225,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 253.55552025416998,
      "baseline_run_cnt_delta": 6295,
      "baseline_run_time_ns_delta": 1596132,
      "post_rejit_avg_ns_per_run": 249.47005124919923,
      "post_rejit_run_cnt_delta": 6244,
      "post_rejit_run_time_ns_delta": 1557691,
      "program": "trace_connect_entry",
      "program_id": 30,
      "ratio": 0.9838872803838963,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 1782.6795869737887,
      "baseline_run_cnt_delta": 6295,
      "baseline_run_time_ns_delta": 11221968,
      "post_rejit_avg_ns_per_run": 1761.525944907111,
      "post_rejit_run_cnt_delta": 6244,
      "post_rejit_run_time_ns_delta": 10998968,
      "program": "trace_connect_v4_return",
      "program_id": 31,
      "ratio": 0.9881337946419259,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 427.34246152345975,
      "baseline_run_cnt_delta": 61531,
      "baseline_run_time_ns_delta": 26294809,
      "post_rejit_avg_ns_per_run": 432.495575379765,
      "post_rejit_run_cnt_delta": 55824,
      "post_rejit_run_time_ns_delta": 24143633,
      "program": "tracepoint__sock__inet_sock_set_state",
      "program_id": 35,
      "ratio": 1.0120585111948264,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 184.60393772855113,
      "baseline_run_cnt_delta": 11843630,
      "baseline_run_time_ns_delta": 2186380735,
      "post_rejit_avg_ns_per_run": 185.14829321902144,
      "post_rejit_run_cnt_delta": 11301245,
      "post_rejit_run_time_ns_delta": 2092406223,
      "program": "sched_switch",
      "program_id": 38,
      "ratio": 1.00294877507581,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 75.54223755081482,
      "baseline_run_cnt_delta": 3660842,
      "baseline_run_time_ns_delta": 276548196,
      "post_rejit_avg_ns_per_run": 70.936554006908,
      "post_rejit_run_cnt_delta": 3160105,
      "post_rejit_run_time_ns_delta": 224166959,
      "program": "sched_wakeup",
      "program_id": 39,
      "ratio": 0.9390316769369093,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 366.6794871794872,
      "baseline_run_cnt_delta": 78,
      "baseline_run_time_ns_delta": 28601,
      "post_rejit_avg_ns_per_run": 299.5,
      "post_rejit_run_cnt_delta": 78,
      "post_rejit_run_time_ns_delta": 23361,
      "program": "raw_tracepoint__sched_wakeup_new",
      "program_id": 40,
      "ratio": 0.8167896227404636,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 1894.125,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 15153,
      "post_rejit_avg_ns_per_run": 2612.375,
      "post_rejit_run_cnt_delta": 8,
      "post_rejit_run_time_ns_delta": 20899,
      "program": "tracepoint__sched_process_free",
      "program_id": 54,
      "ratio": 1.3791988385138256,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "multi_runtime_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 1475.0471171729696,
      "baseline_run_cnt_delta": 1613,
      "baseline_run_time_ns_delta": 2379251,
      "post_rejit_avg_ns_per_run": 1488.3552220137585,
      "post_rejit_run_cnt_delta": 1599,
      "post_rejit_run_time_ns_delta": 2379880,
      "program": "native_tracer_entry",
      "program_id": 55,
      "ratio": 1.009022155757502,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "multi_runtime_cpu"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 1224.9522653721683,
      "baseline_run_cnt_delta": 1236,
      "baseline_run_time_ns_delta": 1514041,
      "post_rejit_avg_ns_per_run": 1215.1887863733143,
      "post_rejit_run_cnt_delta": 1409,
      "post_rejit_run_time_ns_delta": 1712201,
      "program": "cil_from_netdev",
      "program_id": 158,
      "ratio": 0.9920295024754392,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network_lossy_multi"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1418.767754318618,
      "baseline_run_cnt_delta": 1042,
      "baseline_run_time_ns_delta": 1478356,
      "post_rejit_avg_ns_per_run": 1347.9895600298285,
      "post_rejit_run_cnt_delta": 1341,
      "post_rejit_run_time_ns_delta": 1807654,
      "program": "event_exit_acct_process",
      "program_id": 174,
      "ratio": 0.9501129102537422,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2233.6635822868475,
      "baseline_run_cnt_delta": 1513,
      "baseline_run_time_ns_delta": 3379533,
      "post_rejit_avg_ns_per_run": 2108.2438692098094,
      "post_rejit_run_cnt_delta": 1468,
      "post_rejit_run_time_ns_delta": 3094902,
      "program": "event_wake_up_new_task",
      "program_id": 176,
      "ratio": 0.9438502225350193,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 12080.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 24161,
      "post_rejit_avg_ns_per_run": 5548.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 11096,
      "program": "event_execve",
      "program_id": 178,
      "ratio": 0.45925251438268283,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 605.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1211,
      "post_rejit_avg_ns_per_run": 657.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 1315,
      "program": "tg_kp_bprm_committing_creds",
      "program_id": 180,
      "ratio": 1.0858794384805945,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 895.841257367387,
      "baseline_run_cnt_delta": 30540,
      "baseline_run_time_ns_delta": 27358992,
      "post_rejit_avg_ns_per_run": 750.4529711831036,
      "post_rejit_run_cnt_delta": 44696,
      "post_rejit_run_time_ns_delta": 33542246,
      "program": "generic_kprobe_event",
      "program_id": 205,
      "ratio": 0.8377075346903126,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 699.0666339227243,
      "baseline_run_cnt_delta": 30540,
      "baseline_run_time_ns_delta": 21349495,
      "post_rejit_avg_ns_per_run": 536.5101351351351,
      "post_rejit_run_cnt_delta": 44696,
      "post_rejit_run_time_ns_delta": 23979857,
      "program": "generic_retkprobe_event",
      "program_id": 212,
      "ratio": 0.7674663745923276,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 961.585371583701,
      "baseline_run_cnt_delta": 38309,
      "baseline_run_time_ns_delta": 36837374,
      "post_rejit_avg_ns_per_run": 1064.4475298676139,
      "post_rejit_run_cnt_delta": 52649,
      "post_rejit_run_time_ns_delta": 56042098,
      "program": "generic_kprobe_event",
      "program_id": 220,
      "ratio": 1.106971425859466,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 859.7304518664047,
      "baseline_run_cnt_delta": 30540,
      "baseline_run_time_ns_delta": 26256168,
      "post_rejit_avg_ns_per_run": 721.9423885806336,
      "post_rejit_run_cnt_delta": 44696,
      "post_rejit_run_time_ns_delta": 32267937,
      "program": "generic_kprobe_event",
      "program_id": 231,
      "ratio": 0.8397310889865022,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 712.5205631958088,
      "baseline_run_cnt_delta": 30540,
      "baseline_run_time_ns_delta": 21760378,
      "post_rejit_avg_ns_per_run": 608.148178807947,
      "post_rejit_run_cnt_delta": 44696,
      "post_rejit_run_time_ns_delta": 27181791,
      "program": "generic_retkprobe_event",
      "program_id": 240,
      "ratio": 0.8535166705649462,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 877.2765146571302,
      "baseline_run_cnt_delta": 38309,
      "baseline_run_time_ns_delta": 33607586,
      "post_rejit_avg_ns_per_run": 1030.6398602062718,
      "post_rejit_run_cnt_delta": 52649,
      "post_rejit_run_time_ns_delta": 54262158,
      "program": "generic_kprobe_event",
      "program_id": 243,
      "ratio": 1.174817566624454,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 680.3164314406688,
      "baseline_run_cnt_delta": 184220,
      "baseline_run_time_ns_delta": 125327893,
      "post_rejit_avg_ns_per_run": 620.6182126611923,
      "post_rejit_run_cnt_delta": 199839,
      "post_rejit_run_time_ns_delta": 124023723,
      "program": "generic_kprobe_event",
      "program_id": 250,
      "ratio": 0.9122493357200606,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 846.0789371218868,
      "baseline_run_cnt_delta": 410922,
      "baseline_run_time_ns_delta": 347672449,
      "post_rejit_avg_ns_per_run": 780.5659497123993,
      "post_rejit_run_cnt_delta": 317454,
      "post_rejit_run_time_ns_delta": 247793783,
      "program": "generic_kprobe_event",
      "program_id": 258,
      "ratio": 0.9225687054303189,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 182.89160153716736,
      "baseline_run_cnt_delta": 269847,
      "baseline_run_time_ns_delta": 49352750,
      "post_rejit_avg_ns_per_run": 190.5245109908882,
      "post_rejit_run_cnt_delta": 301477,
      "post_rejit_run_time_ns_delta": 57438758,
      "program": "generic_kprobe_event",
      "program_id": 278,
      "ratio": 1.0417346088588417,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 512.9197817003395,
      "baseline_run_cnt_delta": 336968,
      "baseline_run_time_ns_delta": 172837553,
      "post_rejit_avg_ns_per_run": 472.5996675651884,
      "post_rejit_run_cnt_delta": 548679,
      "post_rejit_run_time_ns_delta": 259305513,
      "program": "generic_kprobe_event",
      "program_id": 283,
      "ratio": 0.9213909941209733,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 44.760081075947866,
      "baseline_run_cnt_delta": 336968,
      "baseline_run_time_ns_delta": 15082715,
      "post_rejit_avg_ns_per_run": 39.4776171087596,
      "post_rejit_run_cnt_delta": 548678,
      "post_rejit_run_time_ns_delta": 21660500,
      "program": "generic_retkprobe_event",
      "program_id": 292,
      "ratio": 0.8819826988645284,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4372.79947063689,
      "baseline_run_cnt_delta": 30225,
      "baseline_run_time_ns_delta": 132167864,
      "post_rejit_avg_ns_per_run": 4724.575635470427,
      "post_rejit_run_cnt_delta": 36233,
      "post_rejit_run_time_ns_delta": 171185549,
      "program": "generic_kprobe_event",
      "program_id": 295,
      "ratio": 1.0804464433358298,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 41.95248966087676,
      "baseline_run_cnt_delta": 30225,
      "baseline_run_time_ns_delta": 1268014,
      "post_rejit_avg_ns_per_run": 43.29475892142522,
      "post_rejit_run_cnt_delta": 36233,
      "post_rejit_run_time_ns_delta": 1568699,
      "program": "generic_retkprobe_event",
      "program_id": 302,
      "ratio": 1.0319949845980227,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5413.705882352941,
      "baseline_run_cnt_delta": 17,
      "baseline_run_time_ns_delta": 92033,
      "post_rejit_avg_ns_per_run": 5384.285714285715,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 113070,
      "program": "generic_kprobe_event",
      "program_id": 309,
      "ratio": 0.9945656138869443,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 429.70588235294116,
      "baseline_run_cnt_delta": 17,
      "baseline_run_time_ns_delta": 7305,
      "post_rejit_avg_ns_per_run": 508.3809523809524,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 10676,
      "program": "generic_retkprobe_event",
      "program_id": 315,
      "ratio": 1.1830905120432842,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4712.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 9425,
      "post_rejit_avg_ns_per_run": 5353.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 10706,
      "program": "generic_kprobe_event",
      "program_id": 353,
      "ratio": 1.1359151193633952,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1060.452524184484,
      "baseline_run_cnt_delta": 8029425,
      "baseline_run_time_ns_delta": 8514824009,
      "post_rejit_avg_ns_per_run": 988.0068499928943,
      "post_rejit_run_cnt_delta": 7740300,
      "post_rejit_run_time_ns_delta": 7647469421,
      "program": "generic_tracepoint_event",
      "program_id": 361,
      "ratio": 0.9316841890236413,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7108.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 14216,
      "post_rejit_avg_ns_per_run": 3669.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 7338,
      "program": "generic_rawtp_event",
      "program_id": 367,
      "ratio": 0.5161789532920653,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1491.4579086750662,
      "baseline_run_cnt_delta": 12461,
      "baseline_run_time_ns_delta": 18585057,
      "post_rejit_avg_ns_per_run": 1210.809284505921,
      "post_rejit_run_cnt_delta": 20098,
      "post_rejit_run_time_ns_delta": 24334845,
      "program": "generic_kprobe_event",
      "program_id": 372,
      "ratio": 0.811829336559381,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3173.775311176697,
      "baseline_run_cnt_delta": 7793,
      "baseline_run_time_ns_delta": 24733231,
      "post_rejit_avg_ns_per_run": 3198.4733279798097,
      "post_rejit_run_cnt_delta": 8717,
      "post_rejit_run_time_ns_delta": 27881092,
      "program": "generic_kprobe_event",
      "program_id": 384,
      "ratio": 1.0077819046345646,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 886.7278978388998,
      "baseline_run_cnt_delta": 30540,
      "baseline_run_time_ns_delta": 27080670,
      "post_rejit_avg_ns_per_run": 760.6314882763559,
      "post_rejit_run_cnt_delta": 44696,
      "post_rejit_run_time_ns_delta": 33997185,
      "program": "generic_kprobe_event",
      "program_id": 394,
      "ratio": 0.8577958245479121,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 784.8669941060904,
      "baseline_run_cnt_delta": 30540,
      "baseline_run_time_ns_delta": 23969838,
      "post_rejit_avg_ns_per_run": 660.3386209056739,
      "post_rejit_run_cnt_delta": 44696,
      "post_rejit_run_time_ns_delta": 29514495,
      "program": "generic_retkprobe_event",
      "program_id": 401,
      "ratio": 0.8413382469443174,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 905.6465843535461,
      "baseline_run_cnt_delta": 38309,
      "baseline_run_time_ns_delta": 34694415,
      "post_rejit_avg_ns_per_run": 1057.011301259283,
      "post_rejit_run_cnt_delta": 52649,
      "post_rejit_run_time_ns_delta": 55650588,
      "program": "generic_kprobe_event",
      "program_id": 406,
      "ratio": 1.1671344203365837,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 541.6129707929487,
      "baseline_run_cnt_delta": 76865,
      "baseline_run_time_ns_delta": 41631081,
      "post_rejit_avg_ns_per_run": 499.17912889584,
      "post_rejit_run_cnt_delta": 97187,
      "post_rejit_run_time_ns_delta": 48513722,
      "program": "generic_kprobe_event",
      "program_id": 417,
      "ratio": 0.921652832953791,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1146.2027392896957,
      "baseline_run_cnt_delta": 18837,
      "baseline_run_time_ns_delta": 21591021,
      "post_rejit_avg_ns_per_run": 1114.869107363225,
      "post_rejit_run_cnt_delta": 24310,
      "post_rejit_run_time_ns_delta": 27102468,
      "program": "generic_kprobe_event",
      "program_id": 419,
      "ratio": 0.9726630980258447,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1397.7979819437069,
      "baseline_run_cnt_delta": 9415,
      "baseline_run_time_ns_delta": 13160268,
      "post_rejit_avg_ns_per_run": 1269.2146502057612,
      "post_rejit_run_cnt_delta": 12150,
      "post_rejit_run_time_ns_delta": 15420958,
      "program": "generic_kprobe_event",
      "program_id": 426,
      "ratio": 0.9080100748470503,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1683.2033988316516,
      "baseline_run_cnt_delta": 9415,
      "baseline_run_time_ns_delta": 15847360,
      "post_rejit_avg_ns_per_run": 1650.2285596707818,
      "post_rejit_run_cnt_delta": 12150,
      "post_rejit_run_time_ns_delta": 20050277,
      "program": "generic_retkprobe_event",
      "program_id": 433,
      "ratio": 0.9804094744676976,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1627.060223048327,
      "baseline_run_cnt_delta": 9415,
      "baseline_run_time_ns_delta": 15318772,
      "post_rejit_avg_ns_per_run": 1481.5497860434496,
      "post_rejit_run_cnt_delta": 12152,
      "post_rejit_run_time_ns_delta": 18003793,
      "program": "generic_kprobe_event",
      "program_id": 438,
      "ratio": 0.9105684995898548,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1131.6979349153262,
      "baseline_run_cnt_delta": 18837,
      "baseline_run_time_ns_delta": 21317794,
      "post_rejit_avg_ns_per_run": 1109.118058412176,
      "post_rejit_run_cnt_delta": 24310,
      "post_rejit_run_time_ns_delta": 26962660,
      "program": "generic_kprobe_event",
      "program_id": 445,
      "ratio": 0.980047788542762,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1319.950370098621,
      "baseline_run_cnt_delta": 231695,
      "baseline_run_time_ns_delta": 305825901,
      "post_rejit_avg_ns_per_run": 1279.1819927104075,
      "post_rejit_run_cnt_delta": 210437,
      "post_rejit_run_time_ns_delta": 269187221,
      "program": "generic_kprobe_event",
      "program_id": 453,
      "ratio": 0.9691137043393779,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 312.50268684542414,
      "baseline_run_cnt_delta": 36474,
      "baseline_run_time_ns_delta": 11398223,
      "post_rejit_avg_ns_per_run": 318.6253033895941,
      "post_rejit_run_cnt_delta": 35845,
      "post_rejit_run_time_ns_delta": 11421124,
      "program": "xdp_root",
      "program_id": 470,
      "ratio": 1.019592204489424,
      "runner": "katran",
      "type": "xdp",
      "workload": "xdp_traffic"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 150.0143829489421,
      "baseline_run_cnt_delta": 31137634,
      "baseline_run_time_ns_delta": 4671092951,
      "post_rejit_avg_ns_per_run": 150.7652279519838,
      "post_rejit_run_cnt_delta": 31548530,
      "post_rejit_run_time_ns_delta": 4756421317,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 493,
      "ratio": 1.0050051534278366,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 286.2993750842023,
      "baseline_run_cnt_delta": 31137795,
      "baseline_run_time_ns_delta": 8914731250,
      "post_rejit_avg_ns_per_run": 292.0466121584827,
      "post_rejit_run_cnt_delta": 31548657,
      "post_rejit_run_time_ns_delta": 9213678395,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 496,
      "ratio": 1.0200742215123244,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 263.3247027696452,
      "baseline_run_cnt_delta": 31137634,
      "baseline_run_time_ns_delta": 8199308218,
      "post_rejit_avg_ns_per_run": 261.4723338298171,
      "post_rejit_run_cnt_delta": 31548530,
      "post_rejit_run_time_ns_delta": 8249067768,
      "program": "trace_sys_enter",
      "program_id": 499,
      "ratio": 0.9929654570181038,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 268.9238591557302,
      "baseline_run_cnt_delta": 31137795,
      "baseline_run_time_ns_delta": 8373695997,
      "post_rejit_avg_ns_per_run": 275.90395955682044,
      "post_rejit_run_cnt_delta": 31548657,
      "post_rejit_run_time_ns_delta": 8704399385,
      "program": "trace_sys_exit",
      "program_id": 500,
      "ratio": 1.025955675420559,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 71.35697401722504,
      "baseline_run_cnt_delta": 1184554,
      "baseline_run_time_ns_delta": 84526189,
      "post_rejit_avg_ns_per_run": 67.02926461024637,
      "post_rejit_run_cnt_delta": 1224004,
      "post_rejit_run_time_ns_delta": 82044088,
      "program": "trace_arch_prctl",
      "program_id": 505,
      "ratio": 0.9393512762195606,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 266.7018439007424,
      "baseline_run_cnt_delta": 1184554,
      "baseline_run_time_ns_delta": 315922736,
      "post_rejit_avg_ns_per_run": 262.16116368900754,
      "post_rejit_run_cnt_delta": 1224004,
      "post_rejit_run_time_ns_delta": 320886313,
      "program": "trace_ret_arch_prctl",
      "program_id": 506,
      "ratio": 0.982974695092754,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 336.2861574253587,
      "baseline_run_cnt_delta": 2579,
      "baseline_run_time_ns_delta": 867282,
      "post_rejit_avg_ns_per_run": 328.0425196850394,
      "post_rejit_run_cnt_delta": 2540,
      "post_rejit_run_time_ns_delta": 833228,
      "program": "trace_dup",
      "program_id": 507,
      "ratio": 0.9754862412314755,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1281.1124466847616,
      "baseline_run_cnt_delta": 2579,
      "baseline_run_time_ns_delta": 3303989,
      "post_rejit_avg_ns_per_run": 1205.1913385826772,
      "post_rejit_run_cnt_delta": 2540,
      "post_rejit_run_time_ns_delta": 3061186,
      "program": "trace_ret_dup",
      "program_id": 508,
      "ratio": 0.9407381387179934,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 158.51036144578313,
      "baseline_run_cnt_delta": 2075,
      "baseline_run_time_ns_delta": 328909,
      "post_rejit_avg_ns_per_run": 165.1149877149877,
      "post_rejit_run_cnt_delta": 2035,
      "post_rejit_run_time_ns_delta": 336009,
      "program": "trace_dup2",
      "program_id": 509,
      "ratio": 1.0416668425266546,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 813.3595180722891,
      "baseline_run_cnt_delta": 2075,
      "baseline_run_time_ns_delta": 1687721,
      "post_rejit_avg_ns_per_run": 887.4265356265356,
      "post_rejit_run_cnt_delta": 2035,
      "post_rejit_run_time_ns_delta": 1805913,
      "program": "trace_ret_dup2",
      "program_id": 510,
      "ratio": 1.0910630734730808,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 141.39655172413794,
      "baseline_run_cnt_delta": 2204,
      "baseline_run_time_ns_delta": 311638,
      "post_rejit_avg_ns_per_run": 158.87063750581666,
      "post_rejit_run_cnt_delta": 2149,
      "post_rejit_run_time_ns_delta": 341413,
      "program": "trace_dup3",
      "program_id": 511,
      "ratio": 1.1235821211239319,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 656.3979128856624,
      "baseline_run_cnt_delta": 2204,
      "baseline_run_time_ns_delta": 1446701,
      "post_rejit_avg_ns_per_run": 807.5518845974872,
      "post_rejit_run_cnt_delta": 2149,
      "post_rejit_run_time_ns_delta": 1735429,
      "program": "trace_ret_dup3",
      "program_id": 512,
      "ratio": 1.230277959061936,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2766.73104013104,
      "baseline_run_cnt_delta": 6105,
      "baseline_run_time_ns_delta": 16890893,
      "post_rejit_avg_ns_per_run": 2798.7329704766616,
      "post_rejit_run_cnt_delta": 6063,
      "post_rejit_run_time_ns_delta": 16968718,
      "program": "tracepoint__sched__sched_process_fork",
      "program_id": 518,
      "ratio": 1.011566693647282,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 6665.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 13331,
      "post_rejit_avg_ns_per_run": 12402.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 24805,
      "program": "tracepoint__sched__sched_process_exec",
      "program_id": 526,
      "ratio": 1.8607006226089566,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1353.106877950101,
      "baseline_run_cnt_delta": 5932,
      "baseline_run_time_ns_delta": 8026630,
      "post_rejit_avg_ns_per_run": 1190.1067174056916,
      "post_rejit_run_cnt_delta": 6044,
      "post_rejit_run_time_ns_delta": 7193005,
      "program": "tracepoint__sched__sched_process_exit",
      "program_id": 528,
      "ratio": 0.8795363742505339,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 906.9124936772888,
      "baseline_run_cnt_delta": 5931,
      "baseline_run_time_ns_delta": 5378898,
      "post_rejit_avg_ns_per_run": 888.2159748635687,
      "post_rejit_run_cnt_delta": 6047,
      "post_rejit_run_time_ns_delta": 5371042,
      "program": "tracepoint__sched__sched_process_free",
      "program_id": 529,
      "ratio": 0.9793844290997572,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 401.1973691068984,
      "baseline_run_cnt_delta": 940061,
      "baseline_run_time_ns_delta": 377150000,
      "post_rejit_avg_ns_per_run": 387.7230903868325,
      "post_rejit_run_cnt_delta": 1170093,
      "post_rejit_run_time_ns_delta": 453672074,
      "program": "tracepoint__sched__sched_switch",
      "program_id": 531,
      "ratio": 0.9664148377890391,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 17.042709906725054,
      "baseline_run_cnt_delta": 525007,
      "baseline_run_time_ns_delta": 8947542,
      "post_rejit_avg_ns_per_run": 17.48358642800735,
      "post_rejit_run_cnt_delta": 507781,
      "post_rejit_run_time_ns_delta": 8877833,
      "program": "trace_filldir64",
      "program_id": 532,
      "ratio": 1.025868921298034,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 812.73971679029,
      "baseline_run_cnt_delta": 5932,
      "baseline_run_time_ns_delta": 4821172,
      "post_rejit_avg_ns_per_run": 722.8735936465916,
      "post_rejit_run_cnt_delta": 6044,
      "post_rejit_run_time_ns_delta": 4369048,
      "program": "trace_do_exit",
      "program_id": 534,
      "ratio": 0.8894281634240764,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 92.6413794216971,
      "baseline_run_cnt_delta": 3220596,
      "baseline_run_time_ns_delta": 298360456,
      "post_rejit_avg_ns_per_run": 95.83648102947234,
      "post_rejit_run_cnt_delta": 5352645,
      "post_rejit_run_time_ns_delta": 512978661,
      "program": "trace_security_file_ioctl",
      "program_id": 538,
      "ratio": 1.0344889252267215,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 7380.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 14760,
      "post_rejit_avg_ns_per_run": 11407.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 22814,
      "program": "trace_security_bprm_check",
      "program_id": 543,
      "ratio": 1.5456639566395665,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 571.9280736453136,
      "baseline_run_cnt_delta": 633523,
      "baseline_run_time_ns_delta": 362329589,
      "post_rejit_avg_ns_per_run": 579.7044471854167,
      "post_rejit_run_cnt_delta": 660755,
      "post_rejit_run_time_ns_delta": 383042612,
      "program": "trace_security_file_open",
      "program_id": 544,
      "ratio": 1.0135967683672855,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1534.2746376811594,
      "baseline_run_cnt_delta": 1380,
      "baseline_run_time_ns_delta": 2117299,
      "post_rejit_avg_ns_per_run": 1601.3084464555052,
      "post_rejit_run_cnt_delta": 1326,
      "post_rejit_run_time_ns_delta": 2123335,
      "program": "trace_security_inode_unlink",
      "program_id": 546,
      "ratio": 1.043690879799498,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 251.73264248479205,
      "baseline_run_cnt_delta": 459628,
      "baseline_run_time_ns_delta": 115703371,
      "post_rejit_avg_ns_per_run": 268.2843369800448,
      "post_rejit_run_cnt_delta": 384913,
      "post_rejit_run_time_ns_delta": 103266129,
      "program": "trace_commit_creds",
      "program_id": 547,
      "ratio": 1.0657510854844847,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 520.831591368847,
      "baseline_run_cnt_delta": 5932,
      "baseline_run_time_ns_delta": 3089573,
      "post_rejit_avg_ns_per_run": 502.95565850430177,
      "post_rejit_run_cnt_delta": 6044,
      "post_rejit_run_time_ns_delta": 3039864,
      "program": "trace_switch_task_namespaces",
      "program_id": 548,
      "ratio": 0.9656780941079942,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 129.9026494899896,
      "baseline_run_cnt_delta": 3026507,
      "baseline_run_time_ns_delta": 393151278,
      "post_rejit_avg_ns_per_run": 138.15964035558522,
      "post_rejit_run_cnt_delta": 2217190,
      "post_rejit_run_time_ns_delta": 306326173,
      "program": "trace_cap_capable",
      "program_id": 549,
      "ratio": 1.063562913443362,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 398.654807662741,
      "baseline_run_cnt_delta": 97563,
      "baseline_run_time_ns_delta": 38893959,
      "post_rejit_avg_ns_per_run": 310.4762076867474,
      "post_rejit_run_cnt_delta": 260084,
      "post_rejit_run_time_ns_delta": 80749894,
      "program": "trace_security_socket_create",
      "program_id": 550,
      "ratio": 0.778809641120415,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1345.6,
      "baseline_run_cnt_delta": 20,
      "baseline_run_time_ns_delta": 26912,
      "post_rejit_avg_ns_per_run": 1813.6,
      "post_rejit_run_cnt_delta": 20,
      "post_rejit_run_time_ns_delta": 36272,
      "program": "trace_security_socket_listen",
      "program_id": 555,
      "ratio": 1.3478002378121285,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 457.872879567896,
      "baseline_run_cnt_delta": 47396,
      "baseline_run_time_ns_delta": 21701343,
      "post_rejit_avg_ns_per_run": 369.3429145442465,
      "post_rejit_run_cnt_delta": 63214,
      "post_rejit_run_time_ns_delta": 23347643,
      "program": "trace_security_socket_connect",
      "program_id": 556,
      "ratio": 0.8066494676269164,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 606.65834767642,
      "baseline_run_cnt_delta": 52290,
      "baseline_run_time_ns_delta": 31722165,
      "post_rejit_avg_ns_per_run": 507.9714446125294,
      "post_rejit_run_cnt_delta": 64121,
      "post_rejit_run_time_ns_delta": 32571637,
      "program": "trace_security_socket_accept",
      "program_id": 557,
      "ratio": 0.8373270499913597,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1459.4285714285713,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 30648,
      "post_rejit_avg_ns_per_run": 1204.904761904762,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 25303,
      "program": "trace_security_socket_bind",
      "program_id": 558,
      "ratio": 0.8256003654398331,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 343.29359193318203,
      "baseline_run_cnt_delta": 256458,
      "baseline_run_time_ns_delta": 88040388,
      "post_rejit_avg_ns_per_run": 434.29803720662164,
      "post_rejit_run_cnt_delta": 62462,
      "post_rejit_run_time_ns_delta": 27127124,
      "program": "trace_security_socket_setsockopt",
      "program_id": 559,
      "ratio": 1.2650921759447014,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 84.0056576673551,
      "baseline_run_cnt_delta": 308431,
      "baseline_run_time_ns_delta": 25909949,
      "post_rejit_avg_ns_per_run": 75.61181736505135,
      "post_rejit_run_cnt_delta": 617735,
      "post_rejit_run_time_ns_delta": 46708066,
      "program": "trace_vfs_write",
      "program_id": 562,
      "ratio": 0.9000800596604862,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 39.188820189929025,
      "baseline_run_cnt_delta": 308431,
      "baseline_run_time_ns_delta": 12087047,
      "post_rejit_avg_ns_per_run": 54.271639133285305,
      "post_rejit_run_cnt_delta": 617735,
      "post_rejit_run_time_ns_delta": 33525491,
      "program": "vfs_write_magic_enter",
      "program_id": 563,
      "ratio": 1.384875555585936,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 627.7450645363144,
      "baseline_run_cnt_delta": 308431,
      "baseline_run_time_ns_delta": 193616038,
      "post_rejit_avg_ns_per_run": 599.2983172395931,
      "post_rejit_run_cnt_delta": 617735,
      "post_rejit_run_time_ns_delta": 370207546,
      "program": "trace_ret_vfs_write",
      "program_id": 564,
      "ratio": 0.9546842358406535,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 49.764294120889275,
      "baseline_run_cnt_delta": 308431,
      "baseline_run_time_ns_delta": 15348851,
      "post_rejit_avg_ns_per_run": 44.52529320825273,
      "post_rejit_run_cnt_delta": 617735,
      "post_rejit_run_time_ns_delta": 27504832,
      "program": "vfs_write_magic_return",
      "program_id": 565,
      "ratio": 0.8947236968757203,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 664.1626506024096,
      "baseline_run_cnt_delta": 166,
      "baseline_run_time_ns_delta": 110251,
      "post_rejit_avg_ns_per_run": 431.6774193548387,
      "post_rejit_run_cnt_delta": 155,
      "post_rejit_run_time_ns_delta": 66910,
      "program": "trace_vfs_writev",
      "program_id": 567,
      "ratio": 0.6499573846305542,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 308.2590361445783,
      "baseline_run_cnt_delta": 166,
      "baseline_run_time_ns_delta": 51171,
      "post_rejit_avg_ns_per_run": 500.1290322580645,
      "post_rejit_run_cnt_delta": 155,
      "post_rejit_run_time_ns_delta": 77520,
      "program": "vfs_writev_magic_enter",
      "program_id": 568,
      "ratio": 1.6224310518621623,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2054.1867469879517,
      "baseline_run_cnt_delta": 166,
      "baseline_run_time_ns_delta": 340995,
      "post_rejit_avg_ns_per_run": 2100.8322580645163,
      "post_rejit_run_cnt_delta": 155,
      "post_rejit_run_time_ns_delta": 325629,
      "program": "trace_ret_vfs_writev",
      "program_id": 569,
      "ratio": 1.0227075318955108,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5276.379518072289,
      "baseline_run_cnt_delta": 166,
      "baseline_run_time_ns_delta": 875879,
      "post_rejit_avg_ns_per_run": 5407.664516129033,
      "post_rejit_run_cnt_delta": 155,
      "post_rejit_run_time_ns_delta": 838188,
      "program": "vfs_writev_magic_return",
      "program_id": 570,
      "ratio": 1.0248816442424347,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 78.77573150357729,
      "baseline_run_cnt_delta": 894254,
      "baseline_run_time_ns_delta": 70445513,
      "post_rejit_avg_ns_per_run": 63.7033243792805,
      "post_rejit_run_cnt_delta": 1335708,
      "post_rejit_run_time_ns_delta": 85089040,
      "program": "trace_vfs_read",
      "program_id": 577,
      "ratio": 0.8086668719336191,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 596.6753595734546,
      "baseline_run_cnt_delta": 894254,
      "baseline_run_time_ns_delta": 533579327,
      "post_rejit_avg_ns_per_run": 753.6418551060561,
      "post_rejit_run_cnt_delta": 1335708,
      "post_rejit_run_time_ns_delta": 1006645455,
      "program": "trace_ret_vfs_read",
      "program_id": 578,
      "ratio": 1.263068506205472,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 438.9578313253012,
      "baseline_run_cnt_delta": 166,
      "baseline_run_time_ns_delta": 72867,
      "post_rejit_avg_ns_per_run": 280.35483870967744,
      "post_rejit_run_cnt_delta": 155,
      "post_rejit_run_time_ns_delta": 43455,
      "program": "trace_vfs_readv",
      "program_id": 580,
      "ratio": 0.6386828499294119,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2134.144578313253,
      "baseline_run_cnt_delta": 166,
      "baseline_run_time_ns_delta": 354268,
      "post_rejit_avg_ns_per_run": 2695.122580645161,
      "post_rejit_run_cnt_delta": 155,
      "post_rejit_run_time_ns_delta": 417744,
      "program": "trace_ret_vfs_readv",
      "program_id": 581,
      "ratio": 1.2628584811134416,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 105.4828959752402,
      "baseline_run_cnt_delta": 851057,
      "baseline_run_time_ns_delta": 89771957,
      "post_rejit_avg_ns_per_run": 116.78617102873959,
      "post_rejit_run_cnt_delta": 255536,
      "post_rejit_run_time_ns_delta": 29843071,
      "program": "trace_mmap_alert",
      "program_id": 583,
      "ratio": 1.1071574206319912,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 42.22399777851089,
      "baseline_run_cnt_delta": 842678,
      "baseline_run_time_ns_delta": 35581234,
      "post_rejit_avg_ns_per_run": 52.568873201281214,
      "post_rejit_run_cnt_delta": 251012,
      "post_rejit_run_time_ns_delta": 13195418,
      "program": "trace_do_mmap",
      "program_id": 584,
      "ratio": 1.2449999044864282,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 299.02329122155794,
      "baseline_run_cnt_delta": 842678,
      "baseline_run_time_ns_delta": 251980349,
      "post_rejit_avg_ns_per_run": 334.3961284719456,
      "post_rejit_run_cnt_delta": 251012,
      "post_rejit_run_time_ns_delta": 83937441,
      "program": "trace_ret_do_mmap",
      "program_id": 585,
      "ratio": 1.1182945887120832,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 94.79683958446564,
      "baseline_run_cnt_delta": 842674,
      "baseline_run_time_ns_delta": 79882832,
      "post_rejit_avg_ns_per_run": 102.7262477689954,
      "post_rejit_run_cnt_delta": 251008,
      "post_rejit_run_time_ns_delta": 25785110,
      "program": "trace_security_mmap_file",
      "program_id": 586,
      "ratio": 1.0836463348281198,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 436.71508524649425,
      "baseline_run_cnt_delta": 1250374,
      "baseline_run_time_ns_delta": 546057188,
      "post_rejit_avg_ns_per_run": 405.06122608661633,
      "post_rejit_run_cnt_delta": 1048001,
      "post_rejit_run_time_ns_delta": 424504570,
      "program": "trace_security_file_mprotect",
      "program_id": 587,
      "ratio": 0.9275182831341592,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 248.834065397755,
      "baseline_run_cnt_delta": 8196,
      "baseline_run_time_ns_delta": 2039444,
      "post_rejit_avg_ns_per_run": 286.8645680819912,
      "post_rejit_run_cnt_delta": 8196,
      "post_rejit_run_time_ns_delta": 2351142,
      "program": "trace_security_bpf",
      "program_id": 589,
      "ratio": 1.1528347922276854,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 232.92331288343559,
      "baseline_run_cnt_delta": 2608,
      "baseline_run_time_ns_delta": 607464,
      "post_rejit_avg_ns_per_run": 297.46434049079755,
      "post_rejit_run_cnt_delta": 2608,
      "post_rejit_run_time_ns_delta": 775787,
      "program": "trace_security_bpf_map",
      "program_id": 592,
      "ratio": 1.2770913173455547,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 619.1242236024844,
      "baseline_run_cnt_delta": 161,
      "baseline_run_time_ns_delta": 99679,
      "post_rejit_avg_ns_per_run": 852.6211180124224,
      "post_rejit_run_cnt_delta": 161,
      "post_rejit_run_time_ns_delta": 137272,
      "program": "trace_security_bpf_prog",
      "program_id": 593,
      "ratio": 1.3771406213946769,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1390.1646706586826,
      "baseline_run_cnt_delta": 1002,
      "baseline_run_time_ns_delta": 1392945,
      "post_rejit_avg_ns_per_run": 1428.5648148148148,
      "post_rejit_run_cnt_delta": 972,
      "post_rejit_run_time_ns_delta": 1388565,
      "program": "trace_security_inode_mknod",
      "program_id": 599,
      "ratio": 1.027622730577621,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2458.0,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 9832,
      "post_rejit_avg_ns_per_run": 3785.0,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 15140,
      "program": "trace_load_elf_phdrs",
      "program_id": 607,
      "ratio": 1.5398698128559805,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 46.563558167302155,
      "baseline_run_cnt_delta": 1732004,
      "baseline_run_time_ns_delta": 80648269,
      "post_rejit_avg_ns_per_run": 46.129413666365195,
      "post_rejit_run_cnt_delta": 2598350,
      "post_rejit_run_time_ns_delta": 119860362,
      "program": "trace_security_file_permission",
      "program_id": 608,
      "ratio": 0.9906763031429625,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 942.2585975024016,
      "baseline_run_cnt_delta": 5205,
      "baseline_run_time_ns_delta": 4904456,
      "post_rejit_avg_ns_per_run": 857.9732959850606,
      "post_rejit_run_cnt_delta": 5355,
      "post_rejit_run_time_ns_delta": 4594447,
      "program": "tracepoint__task__task_rename",
      "program_id": 609,
      "ratio": 0.9105497134854998,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 978.5960963951404,
      "baseline_run_cnt_delta": 10042,
      "baseline_run_time_ns_delta": 9827062,
      "post_rejit_avg_ns_per_run": 806.0980923792001,
      "post_rejit_run_cnt_delta": 10327,
      "post_rejit_run_time_ns_delta": 8324575,
      "program": "trace_do_sigaction",
      "program_id": 613,
      "ratio": 0.823729110864664,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2193.5036764705883,
      "baseline_run_cnt_delta": 544,
      "baseline_run_time_ns_delta": 1193266,
      "post_rejit_avg_ns_per_run": 2150.2958801498125,
      "post_rejit_run_cnt_delta": 534,
      "post_rejit_run_time_ns_delta": 1148258,
      "program": "trace_do_truncate",
      "program_id": 616,
      "ratio": 0.9803019266462784,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 177.03923027434234,
      "baseline_run_cnt_delta": 1112916,
      "baseline_run_time_ns_delta": 197029792,
      "post_rejit_avg_ns_per_run": 198.63814990019105,
      "post_rejit_run_cnt_delta": 1236863,
      "post_rejit_run_time_ns_delta": 245688178,
      "program": "trace_fd_install",
      "program_id": 617,
      "ratio": 1.1220007542530475,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 306.36073074663585,
      "baseline_run_cnt_delta": 507262,
      "baseline_run_time_ns_delta": 155405157,
      "post_rejit_avg_ns_per_run": 315.3567345066512,
      "post_rejit_run_cnt_delta": 414210,
      "post_rejit_run_time_ns_delta": 130623913,
      "program": "trace_filp_close",
      "program_id": 618,
      "ratio": 1.0293640889878122,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 205.65760595358225,
      "baseline_run_cnt_delta": 15856,
      "baseline_run_time_ns_delta": 3260907,
      "post_rejit_avg_ns_per_run": 193.1636872187766,
      "post_rejit_run_cnt_delta": 16446,
      "post_rejit_run_time_ns_delta": 3176770,
      "program": "trace_file_update_time",
      "program_id": 619,
      "ratio": 0.9392489342814504,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 759.6849772956609,
      "baseline_run_cnt_delta": 15856,
      "baseline_run_time_ns_delta": 12045565,
      "post_rejit_avg_ns_per_run": 741.4116502493007,
      "post_rejit_run_cnt_delta": 16446,
      "post_rejit_run_time_ns_delta": 12193256,
      "program": "trace_ret_file_update_time",
      "program_id": 620,
      "ratio": 0.9759461782284943,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 100.81519450484967,
      "baseline_run_cnt_delta": 202797,
      "baseline_run_time_ns_delta": 20445019,
      "post_rejit_avg_ns_per_run": 101.90381307027286,
      "post_rejit_run_cnt_delta": 229605,
      "post_rejit_run_time_ns_delta": 23397625,
      "program": "trace_file_modified",
      "program_id": 621,
      "ratio": 1.010798159650139,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 445.6928406238751,
      "baseline_run_cnt_delta": 202797,
      "baseline_run_time_ns_delta": 90385171,
      "post_rejit_avg_ns_per_run": 457.6725419742601,
      "post_rejit_run_cnt_delta": 229605,
      "post_rejit_run_time_ns_delta": 105083904,
      "program": "trace_ret_file_modified",
      "program_id": 622,
      "ratio": 1.0268788283285322,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 193.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 386,
      "post_rejit_avg_ns_per_run": 469.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 938,
      "program": "trace_exec_binprm",
      "program_id": 626,
      "ratio": 2.430051813471503,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5250.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 10501,
      "post_rejit_avg_ns_per_run": 8008.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 16016,
      "program": "trace_security_bprm_creds_for_exec",
      "program_id": 627,
      "ratio": 1.525188077325969,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 6147.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 12295,
      "post_rejit_avg_ns_per_run": 12162.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 24324,
      "program": "trace_execute_finished",
      "program_id": 628,
      "ratio": 1.9783651891012606,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3741.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 7482,
      "post_rejit_avg_ns_per_run": 5245.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 10491,
      "program": "trace_set_fs_pwd",
      "program_id": 630,
      "ratio": 1.4021651964715316,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 282.5351418330877,
      "baseline_run_cnt_delta": 788462,
      "baseline_run_time_ns_delta": 222768223,
      "post_rejit_avg_ns_per_run": 298.0386882906453,
      "post_rejit_run_cnt_delta": 672710,
      "post_rejit_run_time_ns_delta": 200493606,
      "program": "trace_security_task_setrlimit",
      "program_id": 631,
      "ratio": 1.054872984496621,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 332.09104360902256,
      "baseline_run_cnt_delta": 415625,
      "baseline_run_time_ns_delta": 138025340,
      "post_rejit_avg_ns_per_run": 321.4835847609903,
      "post_rejit_run_cnt_delta": 429083,
      "post_rejit_run_time_ns_delta": 137943141,
      "program": "trace_security_task_prctl",
      "program_id": 634,
      "ratio": 0.9680585819697064,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 65.40731051328426,
      "baseline_run_cnt_delta": 149839,
      "baseline_run_time_ns_delta": 9800566,
      "post_rejit_avg_ns_per_run": 45.97302457863436,
      "post_rejit_run_cnt_delta": 324184,
      "post_rejit_run_time_ns_delta": 14903719,
      "program": "trace_sock_alloc_file",
      "program_id": 637,
      "ratio": 0.7028728779376613,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 426.6561242400176,
      "baseline_run_cnt_delta": 149839,
      "baseline_run_time_ns_delta": 63929727,
      "post_rejit_avg_ns_per_run": 347.3998685931446,
      "post_rejit_run_cnt_delta": 324184,
      "post_rejit_run_time_ns_delta": 112621479,
      "program": "trace_ret_sock_alloc_file",
      "program_id": 638,
      "ratio": 0.8142385608830802,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 842.4967303367882,
      "baseline_run_cnt_delta": 38689,
      "baseline_run_time_ns_delta": 32595356,
      "post_rejit_avg_ns_per_run": 1202.2834578061463,
      "post_rejit_run_cnt_delta": 61727,
      "post_rejit_run_time_ns_delta": 74213351,
      "program": "trace_security_sk_clone",
      "program_id": 639,
      "ratio": 1.427048218128435,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 203.72270116317267,
      "baseline_run_cnt_delta": 1254156,
      "baseline_run_time_ns_delta": 255500048,
      "post_rejit_avg_ns_per_run": 238.38787618167092,
      "post_rejit_run_cnt_delta": 1395270,
      "post_rejit_run_time_ns_delta": 332615452,
      "program": "trace_security_socket_recvmsg",
      "program_id": 640,
      "ratio": 1.1701586265083586,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 248.2668454838304,
      "baseline_run_cnt_delta": 2734264,
      "baseline_run_time_ns_delta": 678827098,
      "post_rejit_avg_ns_per_run": 253.2758702571099,
      "post_rejit_run_cnt_delta": 3027927,
      "post_rejit_run_time_ns_delta": 766900846,
      "program": "trace_security_socket_sendmsg",
      "program_id": 641,
      "ratio": 1.0201759713968965,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 211.62412433800344,
      "baseline_run_cnt_delta": 3208287,
      "baseline_run_time_ns_delta": 678950927,
      "post_rejit_avg_ns_per_run": 232.4720421843405,
      "post_rejit_run_cnt_delta": 3208584,
      "post_rejit_run_time_ns_delta": 745906075,
      "program": "cgroup_bpf_run_filter_skb",
      "program_id": 642,
      "ratio": 1.0985139001120638,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 258.46748245906053,
      "baseline_run_cnt_delta": 784023,
      "baseline_run_time_ns_delta": 202644451,
      "post_rejit_avg_ns_per_run": 267.5780488412783,
      "post_rejit_run_cnt_delta": 1003045,
      "post_rejit_run_time_ns_delta": 268392824,
      "program": "cgroup_skb_ingress",
      "program_id": 644,
      "ratio": 1.0352484045402532,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 218.67584013416658,
      "baseline_run_cnt_delta": 2165666,
      "baseline_run_time_ns_delta": 473578832,
      "post_rejit_avg_ns_per_run": 236.6225713477314,
      "post_rejit_run_cnt_delta": 2007492,
      "post_rejit_run_time_ns_delta": 475017919,
      "program": "cgroup_skb_egress",
      "program_id": 645,
      "ratio": 1.0820700229277902,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 74.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 149,
      "post_rejit_avg_ns_per_run": 239.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 479,
      "program": "empty_kprobe",
      "program_id": 648,
      "ratio": 3.214765100671141,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1086.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 2172,
      "post_rejit_avg_ns_per_run": 1681.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 3362,
      "program": "tracepoint__exec_test",
      "program_id": 649,
      "ratio": 1.5478821362799264,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 268.89352714897484,
      "baseline_run_cnt_delta": 633523,
      "baseline_run_time_ns_delta": 170350234,
      "post_rejit_avg_ns_per_run": 275.44090623604814,
      "post_rejit_run_cnt_delta": 660755,
      "post_rejit_run_time_ns_delta": 181998956,
      "program": "lsm_file_open_test",
      "program_id": 650,
      "ratio": 1.0243493369159677,
      "runner": "tracee",
      "type": "lsm",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 206.53755271581207,
      "baseline_run_cnt_delta": 975988,
      "baseline_run_time_ns_delta": 201578173,
      "post_rejit_avg_ns_per_run": 194.59746887888662,
      "post_rejit_run_cnt_delta": 690287,
      "post_rejit_run_time_ns_delta": 134328103,
      "program": "cap_capable",
      "program_id": 657,
      "ratio": 0.9421892838376246,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 420.66326585621334,
      "baseline_run_cnt_delta": 1465435,
      "baseline_run_time_ns_delta": 616454673,
      "post_rejit_avg_ns_per_run": 394.44579212060523,
      "post_rejit_run_cnt_delta": 1440999,
      "post_rejit_run_time_ns_delta": 568395992,
      "program": "block_io_start",
      "program_id": 664,
      "ratio": 0.9376758660344507,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 757.4656610597427,
      "baseline_run_cnt_delta": 1465450,
      "baseline_run_time_ns_delta": 1110028053,
      "post_rejit_avg_ns_per_run": 758.7494333851024,
      "post_rejit_run_cnt_delta": 1441014,
      "post_rejit_run_time_ns_delta": 1093368556,
      "program": "block_io_done",
      "program_id": 665,
      "ratio": 1.0016948257740999,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1736.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1736,
      "post_rejit_avg_ns_per_run": 2104.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 4209,
      "program": "1",
      "program_id": 672,
      "ratio": 1.2122695852534562,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 36.31464539874612,
      "baseline_run_cnt_delta": 2190968,
      "baseline_run_time_ns_delta": 79564226,
      "post_rejit_avg_ns_per_run": 37.51909591542329,
      "post_rejit_run_cnt_delta": 2084451,
      "post_rejit_run_time_ns_delta": 78206717,
      "program": "vfs_create",
      "program_id": 673,
      "ratio": 1.0331670735994232,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 69.6376894235002,
      "baseline_run_cnt_delta": 2569177,
      "baseline_run_time_ns_delta": 178911550,
      "post_rejit_avg_ns_per_run": 68.82500156243908,
      "post_rejit_run_cnt_delta": 3232126,
      "post_rejit_run_time_ns_delta": 222451077,
      "program": "sched_wakeup",
      "program_id": 680,
      "ratio": 0.9883297698733401,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 276.0769230769231,
      "baseline_run_cnt_delta": 78,
      "baseline_run_time_ns_delta": 21534,
      "post_rejit_avg_ns_per_run": 288.6025641025641,
      "post_rejit_run_cnt_delta": 78,
      "post_rejit_run_time_ns_delta": 22511,
      "program": "tracepoint_sched_sched_wakeup_new",
      "program_id": 681,
      "ratio": 1.0453701123804215,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 132.8917525942951,
      "baseline_run_cnt_delta": 13057015,
      "baseline_run_time_ns_delta": 1735169607,
      "post_rejit_avg_ns_per_run": 132.18894854750914,
      "post_rejit_run_cnt_delta": 12001246,
      "post_rejit_run_time_ns_delta": 1586432090,
      "program": "sched_switch",
      "program_id": 682,
      "ratio": 0.9947114547512098,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 425.7177143260509,
      "baseline_run_cnt_delta": 56666,
      "baseline_run_time_ns_delta": 24123720,
      "post_rejit_avg_ns_per_run": 427.5742082312677,
      "post_rejit_run_cnt_delta": 57561,
      "post_rejit_run_time_ns_delta": 24611599,
      "program": "tcp_set_state",
      "program_id": 690,
      "ratio": 1.0043608566022577,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "tcp_connect"
    }
  ],
  "results": [
    {
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 159.511327337757,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 1255370,
            "run_time_ns_delta": 200245735,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0214987210000004,
            "ops_per_sec": 5707420.753588978,
            "ops_total": 5830123.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [7682] setting to a 1 secs run per stressor\nstress-ng: info:  [7682] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 1 dup, 1 kill, 1 sigfd, 1 signal, 1 pty, 1 itimer, 1 timerfd\nstress-ng: info:  [7682] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7682] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7682]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7682] cap             2925696      1.00      0.61      2.44   2922634.22      960044.10\nstress-ng: metrc: [7682] eventfd         1043997      1.00      0.47      2.85   1043782.24      314324.38\nstress-ng: metrc: [7682] get                2664      1.00      0.03      0.25      2662.44        9352.26\nstress-ng: metrc: [7682] prctl              6030      1.00      1.02      0.66      6028.72        3586.05\nstress-ng: metrc: [7682] set               64668      1.00      0.15      1.10     64576.82       51648.13\nstress-ng: metrc: [7682] dup                 506      1.00      0.09      0.08       505.97        3027.15\nstress-ng: metrc: [7682] kill              68852      1.00      0.09      0.82     68842.76       75581.55\nstress-ng: metrc: [7682] sigfd           1370466      1.00      0.17      0.83   1370312.45     1379355.95\nstress-ng: metrc: [7682] signal                0      1.00      0.06      0.35         0.00           0.00\nstress-ng: metrc: [7682] pty                  21      1.00      0.03      0.81        20.98          24.87\nstress-ng: metrc: [7682] itimer               87      1.00      0.17      0.66        87.00         104.85\nstress-ng: metrc: [7682] timerfd          347136      1.00      0.12      0.79    347033.82      381630.01\nstress-ng: info:  [7682] skipped: 0\nstress-ng: info:  [7682] passed: 27: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1)\nstress-ng: info:  [7682] failed: 0\nstress-ng: info:  [7682] metrics untrustworthy: 0\nstress-ng: info:  [7682] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 161.05035884545376,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 1153700,
            "run_time_ns_delta": 185803799,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0193703639999967,
            "ops_per_sec": 6900570.4387929635,
            "ops_total": 7034237.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [21432] setting to a 1 secs run per stressor\nstress-ng: info:  [21432] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 1 dup, 1 kill, 1 sigfd, 1 signal, 1 pty, 1 itimer, 1 timerfd\nstress-ng: info:  [21432] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21432] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21432]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21432] cap             3824025      1.00      0.77      2.85   3824023.18     1057147.52\nstress-ng: metrc: [21432] eventfd          731270      1.00      0.51      2.11    730959.05      278714.42\nstress-ng: metrc: [21432] get                3614      1.00      0.05      0.31      3609.97        9988.59\nstress-ng: metrc: [21432] prctl              2499      1.00      0.37      0.37      2498.47        3345.95\nstress-ng: metrc: [21432] set               82641      1.00      0.30      1.36     82621.96       49871.85\nstress-ng: metrc: [21432] dup                 270      1.00      0.04      0.05       269.98        3215.47\nstress-ng: metrc: [21432] kill              84977      1.00      0.03      0.72     84951.44      113651.05\nstress-ng: metrc: [21432] sigfd           1949507      1.00      0.26      1.30   1949385.70     1250969.43\nstress-ng: metrc: [21432] signal                0      1.01      0.16      0.67         0.00           0.00\nstress-ng: metrc: [21432] pty                  14      1.00      0.05      0.85        13.98          15.54\nstress-ng: metrc: [21432] itimer               92      1.00      0.26      0.67        92.01          98.70\nstress-ng: metrc: [21432] timerfd          355328      1.00      0.15      0.79    354838.59      376626.61\nstress-ng: info:  [21432] skipped: 0\nstress-ng: info:  [21432] passed: 27: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1)\nstress-ng: info:  [21432] failed: 0\nstress-ng: info:  [21432] metrics untrustworthy: 0\nstress-ng: info:  [21432] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
      "app": "bcc/biosnoop",
      "baseline": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 195.6264868063976,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 9,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1801176,
            "run_time_ns_delta": 352357733,
            "type": "tracepoint"
          },
          "10": {
            "avg_ns_per_run": 193.72337115656018,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 10,
            "name": "trace_req_start",
            "run_cnt_delta": 1801186,
            "run_time_ns_delta": 348931824,
            "type": "kprobe"
          },
          "11": {
            "avg_ns_per_run": 91.77781423513665,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 11,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1801191,
            "run_time_ns_delta": 165309373,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.347500568999976,
            "ops_per_sec": 451277.3713367343,
            "ops_total": 2413206.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.264100,\n        \"1000\" : 18.109266\n      },\n      \"latency_us\" : {\n        \"2\" : 29.537503,\n        \"4\" : 1.539568,\n        \"10\" : 22.380070,\n        \"20\" : 24.975875,\n        \"50\" : 2.865678,\n        \"100\" : 0.222036,\n        \"250\" : 0.098481,\n        \"500\" : 0.010000,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 210.09272065601965,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 9,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1760557,
            "run_time_ns_delta": 369880210,
            "type": "tracepoint"
          },
          "10": {
            "avg_ns_per_run": 198.99417289998053,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 10,
            "name": "trace_req_start",
            "run_cnt_delta": 1760567,
            "run_time_ns_delta": 350342574,
            "type": "kprobe"
          },
          "11": {
            "avg_ns_per_run": 93.05852643345459,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 11,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1760572,
            "run_time_ns_delta": 163836236,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.329311735999994,
            "ops_per_sec": 443707.5774769432,
            "ops_total": 2364656.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.081180,\n        \"1000\" : 14.468187\n      },\n      \"latency_us\" : {\n        \"2\" : 33.177088,\n        \"4\" : 1.651280,\n        \"10\" : 20.647876,\n        \"20\" : 26.618842,\n        \"50\" : 2.803932,\n        \"100\" : 0.425260,\n        \"250\" : 0.112259,\n        \"500\" : 0.011039,\n        \"750\" : 0.010000,\n        \"1000\" : 0.010000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.010000,\n        \"4\" : 0.010000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
          "14": {
            "avg_ns_per_run": 61.109886174702645,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 14,
            "name": "vfs_create",
            "run_cnt_delta": 117285,
            "run_time_ns_delta": 7167273,
            "type": "tracing"
          },
          "15": {
            "avg_ns_per_run": 70.06949806949807,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 15,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 518,
            "run_time_ns_delta": 36296,
            "type": "tracing"
          },
          "16": {
            "avg_ns_per_run": 49.14765810206582,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 16,
            "name": "vfs_open",
            "run_cnt_delta": 1888938,
            "run_time_ns_delta": 92836879,
            "type": "tracing"
          },
          "17": {
            "avg_ns_per_run": 47.319182746878546,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 17,
            "name": "vfs_read",
            "run_cnt_delta": 44050,
            "run_time_ns_delta": 2084410,
            "type": "tracing"
          },
          "18": {
            "avg_ns_per_run": 55.231237216132584,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 18,
            "name": "vfs_write",
            "run_cnt_delta": 38134,
            "run_time_ns_delta": 2106188,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2104166409999948,
            "ops_per_sec": 1700848.228837271,
            "ops_total": 2058735.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16338] setting to a 1 secs run per stressor\nstress-ng: info:  [16338] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 1 link, 1 symlink, 1 mknod, 1 fcntl\nstress-ng: info:  [16338] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [16418] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [16357] dentry: 192147 dentries allocated\nstress-ng: metrc: [16338] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16338]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16338] access            17792      1.01      0.26      1.83     17586.81        8500.64\nstress-ng: metrc: [16338] chdir                 4      1.13      0.01      0.93         3.54           4.23\nstress-ng: metrc: [16338] chmod               139      1.03      0.00      0.08       135.30        1729.65\nstress-ng: metrc: [16338] chown               154      1.03      0.00      0.00       149.20       24444.44\nstress-ng: metrc: [16338] dentry            16384      1.11      0.04      0.46     14798.68       32833.14\nstress-ng: metrc: [16338] dir               16628      1.13      0.11      1.53     14758.56       10195.30\nstress-ng: metrc: [16338] dirmany           14833      1.01      0.01      0.32     14698.00       45136.42\nstress-ng: metrc: [16338] fallocate             0      1.03      0.01      0.00         0.00           0.00\nstress-ng: metrc: [16338] file-ioctl        90172      1.00      0.11      0.95     89969.72       85149.94\nstress-ng: metrc: [16338] filename           3546      1.01      0.08      0.68      3511.86        4678.71\nstress-ng: metrc: [16338] flock           1444409      1.01      0.32      0.30   1434528.86     2349343.05\nstress-ng: metrc: [16338] fpunch              163      1.02      0.01      0.55       159.29         291.35\nstress-ng: metrc: [16338] fstat              4112      1.00      0.24      1.27      4102.95        2731.53\nstress-ng: metrc: [16338] getdent          301507      1.00      0.15      2.07    301014.48      135740.16\nstress-ng: metrc: [16338] hdd               15872      1.02      0.22      0.21     15553.93       36926.66\nstress-ng: metrc: [16338] inotify               4      1.03      0.00      0.00         3.87         800.48\nstress-ng: metrc: [16338] open               6144      1.07      0.04      0.04      5719.87       72194.87\nstress-ng: metrc: [16338] rename            49733      1.01      0.02      0.29     49474.65      161354.48\nstress-ng: metrc: [16338] touch             45797      1.07      0.03      1.24     42943.61       36031.38\nstress-ng: metrc: [16338] utime             27660      1.01      0.02      0.49     27519.88       54258.91\nstress-ng: metrc: [16338] link                  2      1.05      0.00      0.22         1.90           8.93\nstress-ng: metrc: [16338] symlink               1      1.12      0.00      0.23         0.89           4.33\nstress-ng: metrc: [16338] mknod                16      1.07      0.00      0.01        14.99        1228.22\nstress-ng: metrc: [16338] fcntl              3663      1.01      0.01      0.05      3622.59       57576.23\nstress-ng: info:  [16338] skipped: 0\nstress-ng: info:  [16338] passed: 84: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (1) symlink (1) mknod (1) fcntl (1)\nstress-ng: info:  [16338] failed: 0\nstress-ng: info:  [16338] metrics untrustworthy: 0\nstress-ng: info:  [16338] successful run completed in 1.20 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "14": {
            "avg_ns_per_run": 62.11342846313806,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 14,
            "name": "vfs_create",
            "run_cnt_delta": 97621,
            "run_time_ns_delta": 6063575,
            "type": "tracing"
          },
          "15": {
            "avg_ns_per_run": 71.55532786885246,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 15,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 488,
            "run_time_ns_delta": 34919,
            "type": "tracing"
          },
          "16": {
            "avg_ns_per_run": 48.37473849690534,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 16,
            "name": "vfs_open",
            "run_cnt_delta": 1890513,
            "run_time_ns_delta": 91453072,
            "type": "tracing"
          },
          "17": {
            "avg_ns_per_run": 76.74403326771218,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 17,
            "name": "vfs_read",
            "run_cnt_delta": 45209,
            "run_time_ns_delta": 3469521,
            "type": "tracing"
          },
          "18": {
            "avg_ns_per_run": 54.12892148303359,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 18,
            "name": "vfs_write",
            "run_cnt_delta": 34362,
            "run_time_ns_delta": 1859978,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2091614520000178,
            "ops_per_sec": 1946497.7122012696,
            "ops_total": 2353630.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15689] setting to a 1 secs run per stressor\nstress-ng: info:  [15689] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 1 link, 1 symlink, 1 mknod, 1 fcntl\nstress-ng: info:  [15689] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [15764] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [15708] dentry: 141095 dentries allocated\nstress-ng: metrc: [15689] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15689]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15689] access            17585      1.02      0.19      1.77     17307.12        8986.40\nstress-ng: metrc: [15689] chdir                13      1.13      0.03      1.09        11.49          11.64\nstress-ng: metrc: [15689] chmod               132      1.02      0.03      0.04       128.87        2085.54\nstress-ng: metrc: [15689] chown               138      1.02      0.00      0.01       134.88        8978.53\nstress-ng: metrc: [15689] dentry            10240      1.15      0.02      0.26      8916.03       36711.98\nstress-ng: metrc: [15689] dir               14052      1.12      0.16      1.20     12536.63       10348.46\nstress-ng: metrc: [15689] dirmany            9929      1.01      0.01      0.21      9817.78       43885.66\nstress-ng: metrc: [15689] fallocate             0      1.02      0.01      0.00         0.00           0.00\nstress-ng: metrc: [15689] file-ioctl        85601      1.00      0.09      0.96     85414.20       82023.31\nstress-ng: metrc: [15689] filename           3851      1.01      0.10      0.66      3796.42        5036.94\nstress-ng: metrc: [15689] flock           1674141      1.01      0.28      0.43   1658866.32     2350598.62\nstress-ng: metrc: [15689] fpunch                2      1.04      0.00      0.16         1.92          12.12\nstress-ng: metrc: [15689] fstat              5359      1.00      0.29      1.26      5345.24        3448.63\nstress-ng: metrc: [15689] getdent          398138      1.00      0.18      2.52    398097.04      147449.02\nstress-ng: metrc: [15689] hdd               17444      1.02      0.25      0.28     17099.98       32986.03\nstress-ng: metrc: [15689] inotify               4      1.04      0.01      0.00         3.84         487.63\nstress-ng: metrc: [15689] open               4096      1.12      0.00      0.08      3641.84       49660.52\nstress-ng: metrc: [15689] rename            41694      1.01      0.02      0.30     41386.49      132664.30\nstress-ng: metrc: [15689] touch             34961      1.12      0.01      1.08     31278.90       32242.33\nstress-ng: metrc: [15689] utime             30028      1.01      0.00      0.57     29798.08       52501.09\nstress-ng: metrc: [15689] link                  1      1.04      0.01      0.11         0.96           8.51\nstress-ng: metrc: [15689] symlink               1      1.08      0.01      0.17         0.92           5.59\nstress-ng: metrc: [15689] mknod                 9      1.12      0.00      0.00         8.06        5184.33\nstress-ng: metrc: [15689] fcntl              6211      1.01      0.01      0.07      6132.44       75998.78\nstress-ng: info:  [15689] skipped: 0\nstress-ng: info:  [15689] passed: 84: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (1) symlink (1) mknod (1) fcntl (1)\nstress-ng: info:  [15689] failed: 0\nstress-ng: info:  [15689] metrics untrustworthy: 0\nstress-ng: info:  [15689] successful run completed in 1.20 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
          "21": {
            "avg_ns_per_run": 231.51762472885034,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 21,
            "name": "__x64_sys_open",
            "run_cnt_delta": 3688,
            "run_time_ns_delta": 853837,
            "type": "tracing"
          },
          "22": {
            "avg_ns_per_run": 239.51319690978957,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 22,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 916313,
            "run_time_ns_delta": 219469056,
            "type": "tracing"
          },
          "23": {
            "avg_ns_per_run": 237.58840579710144,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 23,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 690,
            "run_time_ns_delta": 163936,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2195640639999965,
            "ops_per_sec": 1492633.3546017024,
            "ops_total": 1820362.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16313] setting to a 1 secs run per stressor\nstress-ng: info:  [16313] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 1 link, 1 symlink, 1 mknod, 1 fcntl\nstress-ng: info:  [16313] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [16386] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [16333] dentry: 77914 dentries allocated\nstress-ng: metrc: [16313] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16313]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16313] access            15428      1.02      0.24      1.59     15176.16        8454.81\nstress-ng: metrc: [16313] chdir                73      1.15      0.16      2.13        63.75          31.89\nstress-ng: metrc: [16313] chmod               166      1.03      0.02      0.02       160.46        4130.38\nstress-ng: metrc: [16313] chown               163      1.03      0.01      0.00       157.68       30865.37\nstress-ng: metrc: [16313] dentry            12288      1.16      0.02      0.32     10586.25       36075.71\nstress-ng: metrc: [16313] dir               18042      1.16      0.15      1.57     15603.93       10531.51\nstress-ng: metrc: [16313] dirmany           12796      1.04      0.00      0.28     12353.17       45857.22\nstress-ng: metrc: [16313] fallocate             0      1.04      0.01      0.00         0.00           0.00\nstress-ng: metrc: [16313] file-ioctl        86553      1.01      0.10      0.83     85641.20       92707.18\nstress-ng: metrc: [16313] filename           4142      1.01      0.02      0.84      4091.70        4810.48\nstress-ng: metrc: [16313] flock           1287431      1.02      0.15      0.32   1262671.46     2739313.98\nstress-ng: metrc: [16313] fpunch               75      1.04      0.01      0.24        71.97         294.51\nstress-ng: metrc: [16313] fstat              4352      1.00      0.13      1.14      4336.70        3430.56\nstress-ng: metrc: [16313] getdent          249412      1.00      0.14      1.76    248511.74      131249.16\nstress-ng: metrc: [16313] hdd               14631      1.02      0.25      0.20     14328.54       32775.24\nstress-ng: metrc: [16313] inotify               4      1.06      0.01      0.00         3.76         696.14\nstress-ng: metrc: [16313] open               4096      1.14      0.02      0.04      3584.48       63464.52\nstress-ng: metrc: [16313] rename            37963      1.02      0.02      0.25     37346.44      142619.93\nstress-ng: metrc: [16313] touch             33197      1.13      0.03      0.90     29264.22       35348.60\nstress-ng: metrc: [16313] utime             38212      1.01      0.08      0.64     37702.14       53282.24\nstress-ng: metrc: [16313] link                  1      1.06      0.00      0.13         0.94           7.72\nstress-ng: metrc: [16313] symlink               1      1.12      0.02      0.13         0.89           6.57\nstress-ng: metrc: [16313] mknod                 2      1.13      0.00      0.00         1.76        4000.00\nstress-ng: metrc: [16313] fcntl              1334      1.01      0.00      0.02      1319.92       86343.04\nstress-ng: info:  [16313] skipped: 0\nstress-ng: info:  [16313] passed: 84: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (1) symlink (1) mknod (1) fcntl (1)\nstress-ng: info:  [16313] failed: 0\nstress-ng: info:  [16313] metrics untrustworthy: 0\nstress-ng: info:  [16313] successful run completed in 1.21 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "21": {
            "avg_ns_per_run": 186.63573147900507,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 21,
            "name": "__x64_sys_open",
            "run_cnt_delta": 3739,
            "run_time_ns_delta": 697831,
            "type": "tracing"
          },
          "22": {
            "avg_ns_per_run": 247.56208129455396,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 22,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 945623,
            "run_time_ns_delta": 234100398,
            "type": "tracing"
          },
          "23": {
            "avg_ns_per_run": 203.88292011019283,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 23,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 726,
            "run_time_ns_delta": 148019,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2297837079999852,
            "ops_per_sec": 1368621.9690918366,
            "ops_total": 1683109.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [14470] setting to a 1 secs run per stressor\nstress-ng: info:  [14470] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 1 link, 1 symlink, 1 mknod, 1 fcntl\nstress-ng: info:  [14470] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [14543] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [14487] dentry: 311502 dentries allocated\nstress-ng: metrc: [14470] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [14470]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [14470] access            16817      1.01      0.25      1.45     16619.84        9897.05\nstress-ng: metrc: [14470] chdir                47      1.13      0.11      1.56        41.43          28.22\nstress-ng: metrc: [14470] chmod               134      1.02      0.01      0.05       131.51        2137.33\nstress-ng: metrc: [14470] chown               138      1.01      0.00      0.04       136.10        3055.80\nstress-ng: metrc: [14470] dentry            16053      1.12      0.04      0.43     14303.93       34071.73\nstress-ng: metrc: [14470] dir               22003      1.18      0.10      1.63     18657.01       12708.93\nstress-ng: metrc: [14470] dirmany           16794      1.02      0.01      0.39     16540.32       41939.50\nstress-ng: metrc: [14470] fallocate             0      1.02      0.01      0.00         0.00           0.00\nstress-ng: metrc: [14470] file-ioctl        75378      1.00      0.13      0.72     75034.71       88899.84\nstress-ng: metrc: [14470] filename           4219      1.02      0.07      0.81      4139.52        4778.01\nstress-ng: metrc: [14470] flock           1048170      1.01      0.12      0.35   1038082.16     2224998.30\nstress-ng: metrc: [14470] fpunch                0      1.04      0.02      0.10         0.00           0.00\nstress-ng: metrc: [14470] fstat              3822      1.00      0.21      0.83      3819.38        3694.93\nstress-ng: metrc: [14470] getdent          368835      1.00      0.12      2.44    368796.40      144205.68\nstress-ng: metrc: [14470] hdd               13609      1.02      0.17      0.19     13349.00       37824.32\nstress-ng: metrc: [14470] inotify               4      1.04      0.00      0.00         3.83         931.32\nstress-ng: metrc: [14470] open               4096      1.13      0.01      0.05      3626.28       66295.48\nstress-ng: metrc: [14470] rename            28651      1.02      0.01      0.21     28010.18      131879.72\nstress-ng: metrc: [14470] touch             32238      1.13      0.05      1.07     28627.32       28640.04\nstress-ng: metrc: [14470] utime             28825      1.01      0.07      0.48     28630.59       52545.71\nstress-ng: metrc: [14470] link                  1      1.06      0.00      0.13         0.95           7.86\nstress-ng: metrc: [14470] symlink               1      1.06      0.01      0.08         0.94          11.04\nstress-ng: metrc: [14470] mknod                 1      1.13      0.00      0.00         0.89        1926.78\nstress-ng: metrc: [14470] fcntl              3273      1.00      0.01      0.02      3260.53       91442.46\nstress-ng: info:  [14470] skipped: 0\nstress-ng: info:  [14470] passed: 84: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (1) symlink (1) mknod (1) fcntl (1)\nstress-ng: info:  [14470] failed: 0\nstress-ng: info:  [14470] metrics untrustworthy: 0\nstress-ng: info:  [14470] successful run completed in 1.22 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
          "26": {
            "avg_ns_per_run": 63.51321063813738,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 26,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 30080341,
            "run_time_ns_delta": 1910499034,
            "type": "tracepoint"
          },
          "27": {
            "avg_ns_per_run": 110.4600920453369,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 27,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 30080394,
            "run_time_ns_delta": 3322683090,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0256631579999862,
            "ops_per_sec": 2440520.535885363,
            "ops_total": 2503152.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1083] setting to a 1 secs run per stressor\nstress-ng: info:  [1083] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 1 dup, 1 kill, 1 sigfd, 1 signal, 1 pty, 1 itimer, 1 timerfd\nstress-ng: info:  [1083] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1083] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1083]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1083] cap             1185875      1.00      0.32      3.47   1185870.19      313129.59\nstress-ng: metrc: [1083] eventfd          429716      1.00      0.19      2.30    429607.53      172599.10\nstress-ng: metrc: [1083] get                3241      1.00      0.07      0.56      3238.92        5118.49\nstress-ng: metrc: [1083] prctl              3462      1.00      0.93      0.38      3459.90        2654.41\nstress-ng: metrc: [1083] set               46430      1.00      0.29      1.71     46429.39       23152.40\nstress-ng: metrc: [1083] dup                 380      1.00      0.06      0.05       379.85        3378.95\nstress-ng: metrc: [1083] kill              39303      1.00      0.06      0.69     39293.66       52604.39\nstress-ng: metrc: [1083] sigfd            605206      1.00      0.05      0.92    605132.13      626869.35\nstress-ng: metrc: [1083] signal                0      1.00      0.10      0.76         0.00           0.00\nstress-ng: metrc: [1083] pty                  12      1.01      0.08      0.87        11.90          12.71\nstress-ng: metrc: [1083] itimer               87      1.00      0.07      0.81        87.00          99.13\nstress-ng: metrc: [1083] timerfd          189440      1.00      0.06      0.93    188643.70      192179.52\nstress-ng: info:  [1083] skipped: 0\nstress-ng: info:  [1083] passed: 27: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1)\nstress-ng: info:  [1083] failed: 0\nstress-ng: info:  [1083] metrics untrustworthy: 0\nstress-ng: info:  [1083] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "26": {
            "avg_ns_per_run": 110.28480843047936,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 26,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 26512751,
            "run_time_ns_delta": 2923953665,
            "type": "tracepoint"
          },
          "27": {
            "avg_ns_per_run": 25.54331891600467,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 27,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 26512771,
            "run_time_ns_delta": 677224165,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0258188189999942,
            "ops_per_sec": 2262313.7312516132,
            "ops_total": 2320724.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8661] setting to a 1 secs run per stressor\nstress-ng: info:  [8661] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 1 dup, 1 kill, 1 sigfd, 1 signal, 1 pty, 1 itimer, 1 timerfd\nstress-ng: info:  [8661] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8661] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8661]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8661] cap              856005      1.00      0.22      2.39    855688.17      328012.74\nstress-ng: metrc: [8661] eventfd          684899      1.00      0.25      3.45    684798.92      185018.68\nstress-ng: metrc: [8661] get                2601      1.00      0.05      0.46      2600.09        5067.58\nstress-ng: metrc: [8661] prctl              5811      1.00      1.33      0.53      5809.99        3115.93\nstress-ng: metrc: [8661] set               39182      1.00      0.23      1.47     39180.38       23024.09\nstress-ng: metrc: [8661] dup                 524      1.00      0.08      0.07       523.91        3472.94\nstress-ng: metrc: [8661] kill              42074      1.00      0.10      0.71     42069.27       51986.53\nstress-ng: metrc: [8661] sigfd            566657      1.00      0.14      1.21    566563.12      421141.31\nstress-ng: metrc: [8661] signal                0      1.00      0.04      0.68         0.00           0.00\nstress-ng: metrc: [8661] pty                  15      1.00      0.02      0.92        14.93          16.01\nstress-ng: metrc: [8661] itimer               76      1.00      0.06      0.61        76.00         112.70\nstress-ng: metrc: [8661] timerfd          122880      1.00      0.02      0.77    122378.76      155046.58\nstress-ng: info:  [8661] skipped: 0\nstress-ng: info:  [8661] passed: 27: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1)\nstress-ng: info:  [8661] failed: 0\nstress-ng: info:  [8661] metrics untrustworthy: 0\nstress-ng: info:  [8661] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
          "30": {
            "avg_ns_per_run": 253.55552025416998,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 30,
            "name": "trace_connect_entry",
            "run_cnt_delta": 6295,
            "run_time_ns_delta": 1596132,
            "type": "kprobe"
          },
          "31": {
            "avg_ns_per_run": 1782.6795869737887,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 31,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 6295,
            "run_time_ns_delta": 11221968,
            "type": "kprobe"
          },
          "32": {
            "avg_ns_per_run": null,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 32,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1018530940000062,
            "ops_per_sec": 5704.027183137324,
            "ops_total": 6285.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:41485/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.95ms  286.98us   2.80ms   73.67%\n    Req/Sec     2.87k     1.00k    4.10k    54.55%\n  6285 requests in 1.10s, 0.93MB read\n  Socket errors: connect 0, read 6284, write 0, timeout 0\nRequests/sec:   5714.53\nTransfer/sec:    865.11KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 249.47005124919923,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 30,
            "name": "trace_connect_entry",
            "run_cnt_delta": 6244,
            "run_time_ns_delta": 1557691,
            "type": "kprobe"
          },
          "31": {
            "avg_ns_per_run": 1761.525944907111,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 31,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 6244,
            "run_time_ns_delta": 10998968,
            "type": "kprobe"
          },
          "32": {
            "avg_ns_per_run": null,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 32,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1014349779999861,
            "ops_per_sec": 5658.981351144342,
            "ops_total": 6233.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:44311/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.97ms  306.44us   3.10ms   73.67%\n    Req/Sec     2.85k     1.00k    4.06k    59.09%\n  6233 requests in 1.10s, 0.92MB read\n  Socket errors: connect 0, read 6233, write 0, timeout 0\nRequests/sec:   5668.45\nTransfer/sec:    858.14KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
          "35": {
            "avg_ns_per_run": 427.34246152345975,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 35,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 61531,
            "run_time_ns_delta": 26294809,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.101640056000008,
            "ops_per_sec": 5730.546892895436,
            "ops_total": 6313.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:41913/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.94ms  289.03us   2.64ms   73.10%\n    Req/Sec     2.89k   238.92     3.70k    81.82%\n  6313 requests in 1.10s, 0.93MB read\n  Socket errors: connect 0, read 6311, write 0, timeout 0\nRequests/sec:   5742.23\nTransfer/sec:    869.18KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 432.495575379765,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 35,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 55824,
            "run_time_ns_delta": 24143633,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0049309700000038,
            "ops_per_sec": 5722.781137892465,
            "ops_total": 5751.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://127.0.0.1:39545/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.95ms  336.06us   4.92ms   77.66%\n    Req/Sec     2.89k     2.00k    5.24k    75.00%\n  5751 requests in 1.00s, 0.85MB read\n  Socket errors: connect 0, read 5751, write 0, timeout 0\nRequests/sec:   5741.95\nTransfer/sec:    869.28KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
          "38": {
            "avg_ns_per_run": 184.60393772855113,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 38,
            "name": "sched_switch",
            "run_cnt_delta": 11843630,
            "run_time_ns_delta": 2186380735,
            "type": "raw_tracepoint"
          },
          "39": {
            "avg_ns_per_run": 75.54223755081482,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 39,
            "name": "sched_wakeup",
            "run_cnt_delta": 3660842,
            "run_time_ns_delta": 276548196,
            "type": "raw_tracepoint"
          },
          "40": {
            "avg_ns_per_run": 366.6794871794872,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 40,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 28601,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0153439169999956,
            "ops_per_sec": 11105653.77031756,
            "ops_total": 11276058.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1139] setting to a 1 secs run per stressor\nstress-ng: info:  [1139] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [1139] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1139] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1139]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1139] futex           1011080      2.00      0.27      4.77    505494.73      200594.16\nstress-ng: metrc: [1139] sem             1310381      1.00      0.24      0.96   1309384.52     1089901.55\nstress-ng: metrc: [1139] sem-sysv         675383      1.00      0.14      0.80    675018.96      715114.02\nstress-ng: metrc: [1139] switch          1454763      1.00      0.46      3.54   1454531.78      364130.62\nstress-ng: metrc: [1139] yield           6824451      1.00      1.62      4.30   6817157.71     1152914.43\nstress-ng: info:  [1139] skipped: 0\nstress-ng: info:  [1139] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [1139] failed: 0\nstress-ng: info:  [1139] metrics untrustworthy: 0\nstress-ng: info:  [1139] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "38": {
            "avg_ns_per_run": 185.14829321902144,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 38,
            "name": "sched_switch",
            "run_cnt_delta": 11301245,
            "run_time_ns_delta": 2092406223,
            "type": "raw_tracepoint"
          },
          "39": {
            "avg_ns_per_run": 70.936554006908,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 39,
            "name": "sched_wakeup",
            "run_cnt_delta": 3160105,
            "run_time_ns_delta": 224166959,
            "type": "raw_tracepoint"
          },
          "40": {
            "avg_ns_per_run": 299.5,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 40,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 23361,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0138844960000029,
            "ops_per_sec": 17157121.021801237,
            "ops_total": 17395339.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1315] setting to a 1 secs run per stressor\nstress-ng: info:  [1315] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [1315] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1315] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1315]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1315] futex           1619532      2.00      0.25      5.41    809667.02      285823.81\nstress-ng: metrc: [1315] sem             5813926      1.00      0.79      1.95   5812280.76     2122781.89\nstress-ng: metrc: [1315] sem-sysv         221585      1.00      0.10      0.48    221448.76      382615.71\nstress-ng: metrc: [1315] switch          1510624      1.00      0.37      3.05   1510148.38      441548.38\nstress-ng: metrc: [1315] yield           8229672      1.00      1.19      4.09   8222095.93     1559596.69\nstress-ng: info:  [1315] skipped: 0\nstress-ng: info:  [1315] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [1315] failed: 0\nstress-ng: info:  [1315] metrics untrustworthy: 0\nstress-ng: info:  [1315] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
          "43": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 43,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "44": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 44,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "45": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 45,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "46": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 46,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "47": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 47,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "48": {
            "avg_ns_per_run": null,
            "bytes_jited": 19909,
            "bytes_xlated": 33264,
            "id": 48,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 49,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "50": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 50,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "51": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 51,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 52,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 53,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "54": {
            "avg_ns_per_run": 1894.125,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 54,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 15153,
            "type": "tracepoint"
          },
          "55": {
            "avg_ns_per_run": 1475.0471171729696,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 55,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1613,
            "run_time_ns_delta": 2379251,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.021422010000009,
            "ops_per_sec": 11446.956636094383,
            "ops_total": 57480.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1462] setting to a 5 secs run per stressor\nstress-ng: info:  [1462] dispatching hogs: 4 cpu\nstress-ng: info:  [1462] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1462] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1462]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1462] cpu               57480      5.00     20.00      0.00     11494.34        2873.38\nstress-ng: info:  [1462] skipped: 0\nstress-ng: info:  [1462] passed: 4: cpu (4)\nstress-ng: info:  [1462] failed: 0\nstress-ng: info:  [1462] metrics untrustworthy: 0\nstress-ng: info:  [1462] successful run completed in 5.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "43": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 43,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "44": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 44,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "45": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 45,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "46": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 46,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "47": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 47,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "48": {
            "avg_ns_per_run": null,
            "bytes_jited": 18325,
            "bytes_xlated": 30096,
            "id": 48,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 49,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "50": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 50,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "51": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 51,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 52,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 53,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "54": {
            "avg_ns_per_run": 2612.375,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 54,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 20899,
            "type": "tracepoint"
          },
          "55": {
            "avg_ns_per_run": 1488.3552220137585,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 55,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1599,
            "run_time_ns_delta": 2379880,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.013338656999991,
            "ops_per_sec": 11550.386670796195,
            "ops_total": 57906.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1534] setting to a 5 secs run per stressor\nstress-ng: info:  [1534] dispatching hogs: 4 cpu\nstress-ng: info:  [1534] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1534] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1534]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1534] cpu               57906      5.00     19.99      0.01     11579.60        2894.83\nstress-ng: info:  [1534] skipped: 0\nstress-ng: info:  [1534] passed: 4: cpu (4)\nstress-ng: info:  [1534] failed: 0\nstress-ng: info:  [1534] metrics untrustworthy: 0\nstress-ng: info:  [1534] successful run completed in 5.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 13,
          "not_applied": 0,
          "requested": 13
        }
      },
      "runner": "otelcol-ebpf-profiler",
      "selected_workload": "multi_runtime_cpu",
      "status": "ok"
    },
    {
      "app": "cilium/agent",
      "baseline": {
        "bpf": {
          "63": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 63,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "64": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 64,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 113,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 114,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 116,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 117,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 119,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 120,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 121,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 122,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 124,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 125,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 126,
            "name": "tail_drop_notify",
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
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 128,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 129,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 130,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "131": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 131,
            "name": "tail_handle_ipv4_from_host",
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
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 135,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 136,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "137": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 137,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 138,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 139,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 140,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "141": {
            "avg_ns_per_run": 1398.0,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 141,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1398,
            "type": "sched_cls"
          },
          "142": {
            "avg_ns_per_run": 1350.0,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 142,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1350,
            "type": "sched_cls"
          },
          "143": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 143,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 144,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "145": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 145,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "146": {
            "avg_ns_per_run": 581.0,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 146,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 581,
            "type": "sched_cls"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 147,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 148,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 149,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 150,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 151,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 152,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "153": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 153,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 154,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 156,
            "name": "cil_host_policy",
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
            "avg_ns_per_run": 1224.9522653721683,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 158,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1236,
            "run_time_ns_delta": 1514041,
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
          }
        },
        "workloads": [
          {
            "duration_s": 5.082364589999997,
            "ops_per_sec": 97.78912771781299,
            "ops_total": 497.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   350.77ms  308.41ms   1.86s    82.61%\n    Req/Sec    28.35     16.13    70.00     59.39%\n  497 requests in 5.01s, 79.68KB read\n  Socket errors: connect 0, read 0, write 0, timeout 12\nRequests/sec:     99.23\nTransfer/sec:     15.91KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "63": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 63,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "64": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 64,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 113,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 114,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 116,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 117,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 119,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 120,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 121,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 122,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 124,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 125,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 126,
            "name": "tail_drop_notify",
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
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 128,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 129,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 130,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "131": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 131,
            "name": "tail_handle_ipv4_from_host",
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
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 135,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 136,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "137": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 137,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 138,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 139,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 140,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "141": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 141,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "142": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 142,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "143": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 143,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 144,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "145": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 145,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 146,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 147,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 148,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 149,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 150,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 151,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 152,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "153": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 153,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 154,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 156,
            "name": "cil_host_policy",
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
            "avg_ns_per_run": 1215.1887863733143,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 158,
            "name": "cil_from_netdev",
            "run_cnt_delta": 1409,
            "run_time_ns_delta": 1712201,
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
          }
        },
        "workloads": [
          {
            "duration_s": 5.067195380999976,
            "ops_per_sec": 114.46173995476389,
            "ops_total": 580.0,
            "stderr": "",
            "stdout": "Running 5s test @ http://198.18.0.2:18080/\n  4 threads and 50 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   296.11ms  258.55ms   1.70s    88.36%\n    Req/Sec    31.60     16.22    70.00     59.55%\n  580 requests in 5.01s, 92.11KB read\n  Socket errors: connect 0, read 0, write 0, timeout 11\nRequests/sec:    115.79\nTransfer/sec:     18.39KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
        ],
        "error": "prog 64: prog 64 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8b3b0763a37a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8b3b0763a39a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 126: prog 126 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffcf290055a049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffcf290055a004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffcf290055a03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffcf290055a05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b3b06278200\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 64 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8b3b0763a37a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8b3b0763a39a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
            "exit_code": 1,
            "prog_id": 64
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 126 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffcf290055a049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffcf290055a004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffcf290055a03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffcf290055a05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8b3b06278200\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 126
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 41,
          "not_applied": 2,
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
          "174": {
            "avg_ns_per_run": 1418.767754318618,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 174,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1042,
            "run_time_ns_delta": 1478356,
            "type": "kprobe"
          },
          "176": {
            "avg_ns_per_run": 2233.6635822868475,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 176,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1513,
            "run_time_ns_delta": 3379533,
            "type": "kprobe"
          },
          "177": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 177,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "178": {
            "avg_ns_per_run": 12080.5,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 178,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 24161,
            "type": "tracepoint"
          },
          "179": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 179,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "180": {
            "avg_ns_per_run": 605.5,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 180,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1211,
            "type": "kprobe"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 181,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 184,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 185,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 186,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 187,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 188,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 189,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 190,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 194,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 195,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 197,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 198,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 199,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 200,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 201,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 202,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 204,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "205": {
            "avg_ns_per_run": 895.841257367387,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 205,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 30540,
            "run_time_ns_delta": 27358992,
            "type": "kprobe"
          },
          "206": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 206,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 207,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "208": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 208,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 209,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 210,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 699.0666339227243,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 212,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 30540,
            "run_time_ns_delta": 21349495,
            "type": "kprobe"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 213,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 214,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 215,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 216,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 217,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 218,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 219,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": 961.585371583701,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 220,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 38309,
            "run_time_ns_delta": 36837374,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 221,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 222,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 223,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 224,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 226,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 227,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 228,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 229,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 230,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "avg_ns_per_run": 859.7304518664047,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 231,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 30540,
            "run_time_ns_delta": 26256168,
            "type": "kprobe"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 232,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 233,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 234,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 235,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 237,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 238,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 239,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": 712.5205631958088,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 240,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 30540,
            "run_time_ns_delta": 21760378,
            "type": "kprobe"
          },
          "241": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 241,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 242,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": 877.2765146571302,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 243,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 38309,
            "run_time_ns_delta": 33607586,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 244,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 245,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 246,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 248,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 249,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": 680.3164314406688,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 250,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 184220,
            "run_time_ns_delta": 125327893,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 251,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 253,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 254,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 256,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 846.0789371218868,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 258,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 410922,
            "run_time_ns_delta": 347672449,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 259,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 260,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 262,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 263,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 265,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 266,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 268,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 269,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 270,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 271,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 272,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 273,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 274,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 275,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 276,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 277,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": 182.89160153716736,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 278,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 269847,
            "run_time_ns_delta": 49352750,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 279,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 280,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 281,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 282,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": 512.9197817003395,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 283,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 336968,
            "run_time_ns_delta": 172837553,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 284,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 285,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 286,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 287,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 288,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 290,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 291,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": 44.760081075947866,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 292,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 336968,
            "run_time_ns_delta": 15082715,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 293,
            "name": "generic_retkprobe_actions",
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
            "avg_ns_per_run": 4372.79947063689,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 295,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 30225,
            "run_time_ns_delta": 132167864,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 296,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 297,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 298,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 299,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 300,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 301,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": 41.95248966087676,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 302,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 30225,
            "run_time_ns_delta": 1268014,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 303,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 304,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 305,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 306,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 307,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 308,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "309": {
            "avg_ns_per_run": 5413.705882352941,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 309,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 17,
            "run_time_ns_delta": 92033,
            "type": "kprobe"
          },
          "310": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 310,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 312,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 313,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 314,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": 429.70588235294116,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 315,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 17,
            "run_time_ns_delta": 7305,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 316,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 317,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 318,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 319,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 320,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 321,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 322,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 323,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 324,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 325,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 326,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 327,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 329,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 330,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 332,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 333,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 334,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 335,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 336,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 337,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 338,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 339,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 340,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 341,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 343,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 344,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 345,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 346,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 348,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 349,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 350,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 352,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": 4712.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 353,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9425,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 354,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 358,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 359,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 360,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "361": {
            "avg_ns_per_run": 1060.452524184484,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 361,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 8029425,
            "run_time_ns_delta": 8514824009,
            "type": "tracepoint"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 362,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 363,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 364,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 365,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 366,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "367": {
            "avg_ns_per_run": 7108.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 367,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 14216,
            "type": "raw_tracepoint"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 368,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 369,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 370,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 371,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "372": {
            "avg_ns_per_run": 1491.4579086750662,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 372,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 12461,
            "run_time_ns_delta": 18585057,
            "type": "kprobe"
          },
          "373": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 373,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 374,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 375,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 376,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 377,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 379,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 380,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 381,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 382,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 383,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": 3173.775311176697,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 384,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7793,
            "run_time_ns_delta": 24733231,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 385,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 386,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 387,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 389,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 390,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 391,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 393,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": 886.7278978388998,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 394,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 30540,
            "run_time_ns_delta": 27080670,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 395,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 398,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 399,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 400,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": 784.8669941060904,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 401,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 30540,
            "run_time_ns_delta": 23969838,
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
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 403,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 404,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 405,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": 905.6465843535461,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 406,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 38309,
            "run_time_ns_delta": 34694415,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 407,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 408,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 409,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 410,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 412,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 413,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 414,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 415,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 416,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": 541.6129707929487,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 417,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 76865,
            "run_time_ns_delta": 41631081,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 418,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": 1146.2027392896957,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 419,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 18837,
            "run_time_ns_delta": 21591021,
            "type": "kprobe"
          },
          "420": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 420,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 421,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 422,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 423,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 424,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 425,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": 1397.7979819437069,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 426,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 9415,
            "run_time_ns_delta": 13160268,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 428,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 429,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "430": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 430,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 431,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 432,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": 1683.2033988316516,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 433,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 9415,
            "run_time_ns_delta": 15847360,
            "type": "kprobe"
          },
          "434": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 434,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 435,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 436,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 437,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": 1627.060223048327,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 438,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 9415,
            "run_time_ns_delta": 15318772,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 439,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 440,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 441,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 442,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 444,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": 1131.6979349153262,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 445,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 18837,
            "run_time_ns_delta": 21317794,
            "type": "kprobe"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 446,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 448,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 449,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 451,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 452,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": 1319.950370098621,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 453,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 231695,
            "run_time_ns_delta": 305825901,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 454,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 455,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 456,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 458,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 459,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 460,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 461,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 462,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 463,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.0707256259999554,
            "ops_per_sec": 2924656.904786926,
            "ops_total": 6056162.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [4334] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4334]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4334] cap               76460      1.01      0.03      0.89     75527.86       82775.17\nstress-ng: metrc: [4334] eventfd           27174      1.01      0.00      0.55     27005.29       49721.33\nstress-ng: metrc: [4334] get                 847      1.01      0.04      0.43       838.34        1779.76\nstress-ng: metrc: [4334] prctl               717      1.00      0.46      0.10       714.39        1280.99\nstress-ng: metrc: [4334] set                8134      1.00      0.03      1.00      8114.30        7890.91\nstress-ng: metrc: [4334] dup                  51      1.00      0.03      0.00        50.90        2017.88\nstress-ng: metrc: [4334] kill               6004      1.00      0.00      0.29      6003.02       20740.35\nstress-ng: metrc: [4334] sigfd             40907      1.02      0.08      0.18     40285.91      159318.13\nstress-ng: metrc: [4334] signal                0      1.02      0.00      0.00         0.00           0.00\nstress-ng: metrc: [4334] pty                   4      1.00      0.00      0.46         3.98           8.63\nstress-ng: metrc: [4334] itimer               23      1.01      0.00      0.20        22.69         113.80\nstress-ng: metrc: [4334] timerfd           30720      1.05      0.00      0.31     29232.09      100153.23\nstress-ng: metrc: [4334] aio                4142      1.05      0.01      0.04      3930.79       95218.39\nstress-ng: metrc: [4334] aiol                429      1.22      0.02      0.05       350.36        6122.89\nstress-ng: metrc: [4334] hdd               19119      1.05      0.23      0.27     18215.37       38372.30\nstress-ng: metrc: [4334] io                   17      1.04      0.01      0.01        16.29        1042.37\nstress-ng: metrc: [4334] iomix              1327      1.76      0.06      1.13       752.44        1112.68\nstress-ng: metrc: [4334] io-uring           5968      1.06      0.01      0.29      5633.57       19695.65\nstress-ng: metrc: [4334] sync-file            25      1.04      0.00      0.33        23.95          75.44\nstress-ng: metrc: [4334] epoll               268      1.11      0.03      0.00       241.45        7258.74\nstress-ng: metrc: [4334] netdev            54574      1.00      0.07      1.42     54305.59       36733.89\nstress-ng: metrc: [4334] sctp               8008      1.01      0.02      0.42      7963.39       18461.78\nstress-ng: metrc: [4334] sock                435      1.01      0.02      0.98       428.68         433.43\nstress-ng: metrc: [4334] sockdiag        5342253      1.01      0.02      0.69   5291638.19     7502352.98\nstress-ng: metrc: [4334] sockfd            77236      1.04      0.01      0.70     74537.92      109170.27\nstress-ng: metrc: [4334] sockpair            285      1.04      0.02      0.18       274.43        1394.13\nstress-ng: metrc: [4334] sockmany           9412      1.04      0.01      0.78      9067.00       11914.65\nstress-ng: metrc: [4334] udp                8300      1.00      0.03      0.20      8273.52       36192.70\nstress-ng: metrc: [4334] udp-flood        119486      1.00      0.01      0.80    118901.50      146335.67\nstress-ng: metrc: [4334] mmap                  5      1.03      0.02      0.15         4.85          28.65\nstress-ng: metrc: [4334] mprotect         213775      1.02      0.06      1.45    209393.78      141382.40\nstress-ng: metrc: [4334] mremap               54      1.00      0.00      0.17        53.93         323.24\nstress-ng: metrc: [4334] madvise               3      1.04      0.02      0.17         2.89          15.34\nstress-ng: info:  [4334] skipped: 0\nstress-ng: info:  [4334] passed: 96: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (1) udp-flood (4) mmap (1) mprotect (1) mremap (1) madvise (1)\nstress-ng: info:  [4334] failed: 0\nstress-ng: info:  [4334] metrics untrustworthy: 0\nstress-ng: info:  [4334] successful run completed in 2.05 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "174": {
            "avg_ns_per_run": 1347.9895600298285,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 174,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1341,
            "run_time_ns_delta": 1807654,
            "type": "kprobe"
          },
          "176": {
            "avg_ns_per_run": 2108.2438692098094,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 176,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1468,
            "run_time_ns_delta": 3094902,
            "type": "kprobe"
          },
          "177": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 177,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "178": {
            "avg_ns_per_run": 5548.0,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 178,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11096,
            "type": "tracepoint"
          },
          "179": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 179,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "180": {
            "avg_ns_per_run": 657.5,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 180,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1315,
            "type": "kprobe"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 181,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 184,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 185,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 186,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 187,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 188,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 189,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 190,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 194,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 195,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 197,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 198,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 199,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 200,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 201,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 202,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 204,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "205": {
            "avg_ns_per_run": 750.4529711831036,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 205,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 44696,
            "run_time_ns_delta": 33542246,
            "type": "kprobe"
          },
          "206": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 206,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 207,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "208": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 208,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 209,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 210,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "avg_ns_per_run": 536.5101351351351,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 212,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 44696,
            "run_time_ns_delta": 23979857,
            "type": "kprobe"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 213,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 214,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 215,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 216,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 217,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 218,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 219,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": 1064.4475298676139,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 220,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52649,
            "run_time_ns_delta": 56042098,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 221,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 222,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 223,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 224,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 226,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 227,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 228,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 229,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 230,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "avg_ns_per_run": 721.9423885806336,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 231,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 44696,
            "run_time_ns_delta": 32267937,
            "type": "kprobe"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 232,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 233,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 234,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 235,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 237,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 238,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 239,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": 608.148178807947,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 240,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 44696,
            "run_time_ns_delta": 27181791,
            "type": "kprobe"
          },
          "241": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 241,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 242,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": 1030.6398602062718,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 243,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52649,
            "run_time_ns_delta": 54262158,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 244,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 245,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 246,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 248,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 249,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": 620.6182126611923,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 250,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 199839,
            "run_time_ns_delta": 124023723,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 251,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 253,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 254,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 256,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 780.5659497123993,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 258,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 317454,
            "run_time_ns_delta": 247793783,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 259,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 260,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 262,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 263,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 265,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 266,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 268,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 269,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 270,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 271,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 272,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 273,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 274,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 275,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 276,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 277,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": 190.5245109908882,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 278,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 301477,
            "run_time_ns_delta": 57438758,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 279,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 280,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 281,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 282,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": 472.5996675651884,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 283,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 548679,
            "run_time_ns_delta": 259305513,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 284,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 285,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 286,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 287,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 288,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 289,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 290,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 291,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": 39.4776171087596,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 292,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 548678,
            "run_time_ns_delta": 21660500,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 293,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 294,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": 4724.575635470427,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 295,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 36233,
            "run_time_ns_delta": 171185549,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 296,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 297,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 298,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 299,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 300,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 301,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": 43.29475892142522,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 302,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 36233,
            "run_time_ns_delta": 1568699,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 303,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 304,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 305,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 306,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 307,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 308,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "309": {
            "avg_ns_per_run": 5384.285714285715,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 309,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 113070,
            "type": "kprobe"
          },
          "310": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 310,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 312,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 313,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "314": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 314,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "315": {
            "avg_ns_per_run": 508.3809523809524,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 315,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 10676,
            "type": "kprobe"
          },
          "316": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 316,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 317,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 318,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 319,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "320": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 320,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "321": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 321,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 322,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 323,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 324,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 325,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 326,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 327,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 329,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 330,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 332,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 333,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 334,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 335,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 336,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 337,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 338,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 339,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "340": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 340,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "341": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 341,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 343,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 344,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 345,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 346,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 347,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "348": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 348,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "349": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 349,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 350,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 352,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": 5353.0,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 353,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10706,
            "type": "kprobe"
          },
          "354": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 354,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "355": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
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
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 357,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "358": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 358,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": null,
            "bytes_jited": 4646,
            "bytes_xlated": 8312,
            "id": 359,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 14824,
            "bytes_xlated": 25624,
            "id": 360,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "361": {
            "avg_ns_per_run": 988.0068499928943,
            "bytes_jited": 10815,
            "bytes_xlated": 19224,
            "id": 361,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 7740300,
            "run_time_ns_delta": 7647469421,
            "type": "tracepoint"
          },
          "362": {
            "avg_ns_per_run": null,
            "bytes_jited": 11015,
            "bytes_xlated": 17848,
            "id": 362,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 363,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 364,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 16995,
            "bytes_xlated": 29336,
            "id": 365,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 366,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "367": {
            "avg_ns_per_run": 3669.0,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 367,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7338,
            "type": "raw_tracepoint"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 368,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 369,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 370,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 729,
            "bytes_xlated": 1152,
            "id": 371,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "372": {
            "avg_ns_per_run": 1210.809284505921,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 372,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 20098,
            "run_time_ns_delta": 24334845,
            "type": "kprobe"
          },
          "373": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 373,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 374,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 375,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 376,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 377,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 379,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 380,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 381,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 382,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "383": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 383,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "384": {
            "avg_ns_per_run": 3198.4733279798097,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 384,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8717,
            "run_time_ns_delta": 27881092,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 385,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "386": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 386,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "387": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 387,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 389,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 390,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 391,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 393,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": 760.6314882763559,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 394,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 44696,
            "run_time_ns_delta": 33997185,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 395,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 398,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "399": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 399,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 400,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": 660.3386209056739,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 401,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 44696,
            "run_time_ns_delta": 29514495,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 402,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 403,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 404,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 405,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": 1057.011301259283,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 406,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 52649,
            "run_time_ns_delta": 55650588,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 407,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 408,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 409,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 410,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 412,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 413,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 414,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 415,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 416,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": 499.17912889584,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 417,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 97187,
            "run_time_ns_delta": 48513722,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 418,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": 1114.869107363225,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 419,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 24310,
            "run_time_ns_delta": 27102468,
            "type": "kprobe"
          },
          "420": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 420,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "421": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 421,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 422,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 423,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 424,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 425,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": 1269.2146502057612,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 426,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 12150,
            "run_time_ns_delta": 15420958,
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
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 428,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 429,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "430": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 430,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 431,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 432,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": 1650.2285596707818,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 433,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 12150,
            "run_time_ns_delta": 20050277,
            "type": "kprobe"
          },
          "434": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 434,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "435": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 435,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 436,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 437,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": 1481.5497860434496,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 438,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 12152,
            "run_time_ns_delta": 18003793,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 439,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 440,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 441,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 442,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 444,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": 1109.118058412176,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 445,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 24310,
            "run_time_ns_delta": 26962660,
            "type": "kprobe"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 446,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 448,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "449": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 449,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 451,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 452,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": 1279.1819927104075,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 453,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 210437,
            "run_time_ns_delta": 269187221,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 454,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "455": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 455,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 456,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 457,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "458": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 458,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "459": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 459,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "460": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 460,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "461": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 461,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 462,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 463,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.052227251999966,
            "ops_per_sec": 4345181.066721429,
            "ops_total": 8917299.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7765] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7765]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7765] cap               96711      1.00      0.06      1.01     96373.20       90037.93\nstress-ng: metrc: [7765] eventfd           45923      1.01      0.03      0.87     45509.05       51231.96\nstress-ng: metrc: [7765] get                 877      1.00      0.09      0.35       876.81        2023.08\nstress-ng: metrc: [7765] prctl               943      1.00      0.57      0.08       941.42        1446.71\nstress-ng: metrc: [7765] set                2885      1.02      0.01      0.36      2834.92        7891.68\nstress-ng: metrc: [7765] dup                  88      1.01      0.02      0.01        87.25        2318.47\nstress-ng: metrc: [7765] kill               1177      1.00      0.00      0.08      1176.62       14550.44\nstress-ng: metrc: [7765] sigfd            122315      1.02      0.01      0.64    120185.99      189572.17\nstress-ng: metrc: [7765] signal                0      1.00      0.00      0.00         0.00           0.00\nstress-ng: metrc: [7765] pty                   4      1.02      0.00      0.48         3.92           8.26\nstress-ng: metrc: [7765] itimer               68      1.01      0.01      0.59        67.60         112.88\nstress-ng: metrc: [7765] timerfd           22528      1.05      0.01      0.18     21468.92      118540.97\nstress-ng: metrc: [7765] aio                6404      1.02      0.01      0.05      6265.37      101038.15\nstress-ng: metrc: [7765] aiol                673      1.19      0.00      0.11       567.50        6325.49\nstress-ng: metrc: [7765] hdd               19375      1.02      0.36      0.25     19045.12       31747.46\nstress-ng: metrc: [7765] io                   27      1.03      0.01      0.00        26.26        2006.99\nstress-ng: metrc: [7765] iomix               968      1.28      0.06      1.25       759.14         737.39\nstress-ng: metrc: [7765] io-uring           6428      1.04      0.00      0.45      6164.89       14196.87\nstress-ng: metrc: [7765] sync-file            26      1.02      0.00      0.34        25.37          76.55\nstress-ng: metrc: [7765] epoll              5087      1.11      0.03      0.40      4587.54       11691.35\nstress-ng: metrc: [7765] netdev            30982      1.03      0.03      0.75     30144.16       40058.70\nstress-ng: metrc: [7765] sctp              13923      1.01      0.06      0.40     13726.70       30223.24\nstress-ng: metrc: [7765] sock                389      1.02      0.00      0.86       381.80         451.79\nstress-ng: metrc: [7765] sockdiag        8284689      1.01      0.05      0.73   8239473.40    10666139.24\nstress-ng: metrc: [7765] sockfd            73464      1.03      0.01      0.69     71380.24      104443.81\nstress-ng: metrc: [7765] sockpair            459      1.04      0.01      0.19       443.19        2303.06\nstress-ng: metrc: [7765] sockmany          12147      1.04      0.00      0.91     11651.69       13340.87\nstress-ng: metrc: [7765] udp                7545      1.00      0.01      0.20      7540.27       36548.15\nstress-ng: metrc: [7765] udp-flood         67932      1.01      0.00      0.50     67205.96      136291.68\nstress-ng: metrc: [7765] mmap                  7      1.01      0.00      0.19         6.94          37.54\nstress-ng: metrc: [7765] mprotect          93197      1.03      0.05      0.61     90758.28      141126.96\nstress-ng: metrc: [7765] mremap               53      1.00      0.00      0.25        52.76         213.97\nstress-ng: metrc: [7765] madvise               5      1.03      0.00      0.29         4.86          17.28\nstress-ng: info:  [7765] skipped: 0\nstress-ng: info:  [7765] passed: 96: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (1) udp-flood (4) mmap (1) mprotect (1) mremap (1) madvise (1)\nstress-ng: info:  [7765] failed: 0\nstress-ng: info:  [7765] metrics untrustworthy: 0\nstress-ng: info:  [7765] successful run completed in 2.03 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem"
        ],
        "error": "prog 188: prog 188 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 195: prog 195 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 200: prog 200 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 209: prog 209 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 213: prog 213 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 219: prog 219 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 226: prog 226 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 232: prog 232 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 237: prog 237 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 246: prog 246 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 251: prog 251 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 256: prog 256 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 262: prog 262 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 271: prog 271 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 279: prog 279 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 288: prog 288 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 291: prog 291 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 300: prog 300 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 303: prog 303 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 307: prog 307 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 312: prog 312 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 319: prog 319 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 324: prog 324 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 328: prog 328 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 337: prog 337 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 339: prog 339 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 346: prog 346 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 356: prog 356 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 364: prog 364 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 369: prog 369 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 373: prog 373 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 380: prog 380 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 389: prog 389 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 397: prog 397 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 400: prog 400 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 405: prog 405 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 411: prog 411 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 418: prog 418 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 429: prog 429 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 432: prog 432 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 442: prog 442 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 446: prog 446 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 450: prog 450 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 459: prog 459 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 188 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 188
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 195 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 195
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 200 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 200
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 209 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 209
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 213 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 213
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 219 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 219
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 226 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 226
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 232 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 232
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 237 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 237
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 246 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 246
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 251 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 251
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 256 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 256
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 262 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 262
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 271 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 271
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 279 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 279
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 288 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 288
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 291 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 291
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 300 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 300
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 303 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 303
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 307 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 307
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 312 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 312
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 319 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 319
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 324 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 324
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 328 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 328
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 337 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 337
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 339 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 339
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 346 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 346
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 356 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 356
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 364 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 364
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 369 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 369
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 373 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 373
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 380 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 380
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 389 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 389
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
            "error": "prog 400 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 400
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 405 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
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
            "error": "prog 418 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 418
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 429 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 429
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 432 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 432
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 442 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 442
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 446 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 446
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
            "error": "prog 459 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 459
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 243,
          "not_applied": 44,
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
          "470": {
            "avg_ns_per_run": 312.50268684542414,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 470,
            "name": "xdp_root",
            "run_cnt_delta": 36474,
            "run_time_ns_delta": 11398223,
            "type": "xdp"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 476,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "478": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 478,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0010603609999862,
            "ops_per_sec": 6072.5608932587475,
            "ops_total": 6079.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "470": {
            "avg_ns_per_run": 318.6253033895941,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 470,
            "name": "xdp_root",
            "run_cnt_delta": 35845,
            "run_time_ns_delta": 11421124,
            "type": "xdp"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 13581,
            "bytes_xlated": 23744,
            "id": 476,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "478": {
            "avg_ns_per_run": 526.0,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 478,
            "name": "healthcheck_encap",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 526,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000583421999977,
            "ops_per_sec": 5970.516669223945,
            "ops_total": 5974.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem"
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
      "selected_workload": "xdp_traffic",
      "status": "ok"
    },
    {
      "app": "tracee/monitor",
      "baseline": {
        "bpf": {
          "493": {
            "avg_ns_per_run": 150.0143829489421,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 493,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 31137634,
            "run_time_ns_delta": 4671092951,
            "type": "raw_tracepoint"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 494,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 495,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "496": {
            "avg_ns_per_run": 286.2993750842023,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 496,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 31137795,
            "run_time_ns_delta": 8914731250,
            "type": "raw_tracepoint"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 497,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 498,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "499": {
            "avg_ns_per_run": 263.3247027696452,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 499,
            "name": "trace_sys_enter",
            "run_cnt_delta": 31137634,
            "run_time_ns_delta": 8199308218,
            "type": "raw_tracepoint"
          },
          "500": {
            "avg_ns_per_run": 268.9238591557302,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 500,
            "name": "trace_sys_exit",
            "run_cnt_delta": 31137795,
            "run_time_ns_delta": 8373695997,
            "type": "raw_tracepoint"
          },
          "501": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 501,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 502,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 503,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 504,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": 71.35697401722504,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 505,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 1184554,
            "run_time_ns_delta": 84526189,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": 266.7018439007424,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 506,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1184554,
            "run_time_ns_delta": 315922736,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": 336.2861574253587,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 507,
            "name": "trace_dup",
            "run_cnt_delta": 2579,
            "run_time_ns_delta": 867282,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": 1281.1124466847616,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 508,
            "name": "trace_ret_dup",
            "run_cnt_delta": 2579,
            "run_time_ns_delta": 3303989,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": 158.51036144578313,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 509,
            "name": "trace_dup2",
            "run_cnt_delta": 2075,
            "run_time_ns_delta": 328909,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": 813.3595180722891,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 510,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 2075,
            "run_time_ns_delta": 1687721,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": 141.39655172413794,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 511,
            "name": "trace_dup3",
            "run_cnt_delta": 2204,
            "run_time_ns_delta": 311638,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": 656.3979128856624,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 512,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 2204,
            "run_time_ns_delta": 1446701,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 513,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 514,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 515,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 516,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 517,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": 2766.73104013104,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 518,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 6105,
            "run_time_ns_delta": 16890893,
            "type": "raw_tracepoint"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 519,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 520,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 521,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 522,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 523,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 524,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 525,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": 6665.5,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 526,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 13331,
            "type": "raw_tracepoint"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 527,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "528": {
            "avg_ns_per_run": 1353.106877950101,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 528,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 5932,
            "run_time_ns_delta": 8026630,
            "type": "raw_tracepoint"
          },
          "529": {
            "avg_ns_per_run": 906.9124936772888,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 529,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 5931,
            "run_time_ns_delta": 5378898,
            "type": "raw_tracepoint"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 530,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "531": {
            "avg_ns_per_run": 401.1973691068984,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 531,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 940061,
            "run_time_ns_delta": 377150000,
            "type": "raw_tracepoint"
          },
          "532": {
            "avg_ns_per_run": 17.042709906725054,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 532,
            "name": "trace_filldir64",
            "run_cnt_delta": 525007,
            "run_time_ns_delta": 8947542,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 533,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": 812.73971679029,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 534,
            "name": "trace_do_exit",
            "run_cnt_delta": 5932,
            "run_time_ns_delta": 4821172,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 535,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 536,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 537,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": 92.6413794216971,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 538,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 3220596,
            "run_time_ns_delta": 298360456,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 539,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 540,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 541,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "542": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 542,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "543": {
            "avg_ns_per_run": 7380.0,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 543,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 14760,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": 571.9280736453136,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 544,
            "name": "trace_security_file_open",
            "run_cnt_delta": 633523,
            "run_time_ns_delta": 362329589,
            "type": "kprobe"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 545,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "avg_ns_per_run": 1534.2746376811594,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 546,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 1380,
            "run_time_ns_delta": 2117299,
            "type": "kprobe"
          },
          "547": {
            "avg_ns_per_run": 251.73264248479205,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 547,
            "name": "trace_commit_creds",
            "run_cnt_delta": 459628,
            "run_time_ns_delta": 115703371,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": 520.831591368847,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 548,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 5932,
            "run_time_ns_delta": 3089573,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": 129.9026494899896,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 549,
            "name": "trace_cap_capable",
            "run_cnt_delta": 3026507,
            "run_time_ns_delta": 393151278,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": 398.654807662741,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 550,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 97563,
            "run_time_ns_delta": 38893959,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 551,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 552,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 553,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 554,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": 1345.6,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 555,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 26912,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": 457.872879567896,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 556,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 47396,
            "run_time_ns_delta": 21701343,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": 606.65834767642,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 557,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 52290,
            "run_time_ns_delta": 31722165,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": 1459.4285714285713,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 558,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 30648,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": 343.29359193318203,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 559,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 256458,
            "run_time_ns_delta": 88040388,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 560,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 561,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "562": {
            "avg_ns_per_run": 84.0056576673551,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 562,
            "name": "trace_vfs_write",
            "run_cnt_delta": 308431,
            "run_time_ns_delta": 25909949,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": 39.188820189929025,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 563,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 308431,
            "run_time_ns_delta": 12087047,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": 627.7450645363144,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 564,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 308431,
            "run_time_ns_delta": 193616038,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": 49.764294120889275,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 565,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 308431,
            "run_time_ns_delta": 15348851,
            "type": "kprobe"
          },
          "566": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 566,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": 664.1626506024096,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 567,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 110251,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": 308.2590361445783,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 568,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 51171,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": 2054.1867469879517,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 569,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 340995,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": 5276.379518072289,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 570,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 875879,
            "type": "kprobe"
          },
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 571,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 572,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 573,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 574,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 575,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 576,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": 78.77573150357729,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 577,
            "name": "trace_vfs_read",
            "run_cnt_delta": 894254,
            "run_time_ns_delta": 70445513,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": 596.6753595734546,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 578,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 894254,
            "run_time_ns_delta": 533579327,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 579,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": 438.9578313253012,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 580,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 72867,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": 2134.144578313253,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 581,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 166,
            "run_time_ns_delta": 354268,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 582,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 105.4828959752402,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 583,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 851057,
            "run_time_ns_delta": 89771957,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": 42.22399777851089,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 584,
            "name": "trace_do_mmap",
            "run_cnt_delta": 842678,
            "run_time_ns_delta": 35581234,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": 299.02329122155794,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 585,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 842678,
            "run_time_ns_delta": 251980349,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": 94.79683958446564,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 586,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 842674,
            "run_time_ns_delta": 79882832,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 436.71508524649425,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 587,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 1250374,
            "run_time_ns_delta": 546057188,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 588,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "589": {
            "avg_ns_per_run": 248.834065397755,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 589,
            "name": "trace_security_bpf",
            "run_cnt_delta": 8196,
            "run_time_ns_delta": 2039444,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 590,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "591": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 591,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "592": {
            "avg_ns_per_run": 232.92331288343559,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 592,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 607464,
            "type": "kprobe"
          },
          "593": {
            "avg_ns_per_run": 619.1242236024844,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 593,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 99679,
            "type": "kprobe"
          },
          "594": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 594,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 595,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 596,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 597,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 598,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": 1390.1646706586826,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 599,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 1002,
            "run_time_ns_delta": 1392945,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 600,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 601,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 602,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 603,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 604,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 605,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 606,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": 2458.0,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 607,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 9832,
            "type": "kprobe"
          },
          "608": {
            "avg_ns_per_run": 46.563558167302155,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 608,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 1732004,
            "run_time_ns_delta": 80648269,
            "type": "kprobe"
          },
          "609": {
            "avg_ns_per_run": 942.2585975024016,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 609,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 5205,
            "run_time_ns_delta": 4904456,
            "type": "raw_tracepoint"
          },
          "610": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 610,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 611,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 612,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": 978.5960963951404,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 613,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 10042,
            "run_time_ns_delta": 9827062,
            "type": "kprobe"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 614,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 615,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": 2193.5036764705883,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 616,
            "name": "trace_do_truncate",
            "run_cnt_delta": 544,
            "run_time_ns_delta": 1193266,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": 177.03923027434234,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 617,
            "name": "trace_fd_install",
            "run_cnt_delta": 1112916,
            "run_time_ns_delta": 197029792,
            "type": "kprobe"
          },
          "618": {
            "avg_ns_per_run": 306.36073074663585,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 618,
            "name": "trace_filp_close",
            "run_cnt_delta": 507262,
            "run_time_ns_delta": 155405157,
            "type": "kprobe"
          },
          "619": {
            "avg_ns_per_run": 205.65760595358225,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 619,
            "name": "trace_file_update_time",
            "run_cnt_delta": 15856,
            "run_time_ns_delta": 3260907,
            "type": "kprobe"
          },
          "620": {
            "avg_ns_per_run": 759.6849772956609,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 620,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 15856,
            "run_time_ns_delta": 12045565,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 100.81519450484967,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 621,
            "name": "trace_file_modified",
            "run_cnt_delta": 202797,
            "run_time_ns_delta": 20445019,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": 445.6928406238751,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 622,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 202797,
            "run_time_ns_delta": 90385171,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 623,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 624,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 625,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 193.0,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 626,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 386,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 5250.5,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 627,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10501,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": 6147.5,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 628,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 12295,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 629,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": 3741.0,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 630,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7482,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": 282.5351418330877,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 631,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 788462,
            "run_time_ns_delta": 222768223,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 632,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 633,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 332.09104360902256,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 634,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 415625,
            "run_time_ns_delta": 138025340,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 635,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 636,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": 65.40731051328426,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 637,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 149839,
            "run_time_ns_delta": 9800566,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": 426.6561242400176,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 638,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 149839,
            "run_time_ns_delta": 63929727,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": 842.4967303367882,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 639,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 38689,
            "run_time_ns_delta": 32595356,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 203.72270116317267,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 640,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 1254156,
            "run_time_ns_delta": 255500048,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 248.2668454838304,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 641,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 2734264,
            "run_time_ns_delta": 678827098,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 211.62412433800344,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 642,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 3208287,
            "run_time_ns_delta": 678950927,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": 258.46748245906053,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 644,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 784023,
            "run_time_ns_delta": 202644451,
            "type": "cgroup_skb"
          },
          "645": {
            "avg_ns_per_run": 218.67584013416658,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 645,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 2165666,
            "run_time_ns_delta": 473578832,
            "type": "cgroup_skb"
          },
          "646": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 646,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "647": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 647,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "648": {
            "avg_ns_per_run": 74.5,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 648,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 149,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 1086.0,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 649,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2172,
            "type": "raw_tracepoint"
          },
          "650": {
            "avg_ns_per_run": 268.89352714897484,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 650,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 633523,
            "run_time_ns_delta": 170350234,
            "type": "lsm"
          },
          "651": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 651,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.21125720200007,
            "ops_per_sec": 20351198.547501393,
            "ops_total": 106055330.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [9480] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9480]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9480] cap              502655      5.04      0.12      5.15     99759.63       95280.02\nstress-ng: metrc: [9480] eventfd           97635      5.01      0.15      2.47     19479.15       37213.58\nstress-ng: metrc: [9480] get                3587      5.03      0.11      1.97       713.22        1730.01\nstress-ng: metrc: [9480] prctl              4504      5.01      2.99      0.92       899.85        1151.96\nstress-ng: metrc: [9480] set               49028      5.01      0.17      6.10      9791.17        7821.00\nstress-ng: metrc: [9480] dup                 493      5.02      0.17      0.13        98.15        1627.44\nstress-ng: metrc: [9480] kill               5362      5.08      0.01      0.51      1056.20       10373.32\nstress-ng: metrc: [9480] sigfd            140710      5.07      0.01      0.77     27757.18      181782.95\nstress-ng: metrc: [9480] signal                0      5.01      0.00      0.00         0.00           0.00\nstress-ng: metrc: [9480] pty                  14      5.02      0.05      2.00         2.79           6.85\nstress-ng: metrc: [9480] itimer              143      5.05      0.02      1.26        28.31         111.55\nstress-ng: metrc: [9480] timerfd          319488      5.07      0.05      3.06     63054.12      102503.16\nstress-ng: metrc: [9480] aio               22064      5.06      0.01      0.26      4356.93       80097.58\nstress-ng: metrc: [9480] aiol               4803      5.15      0.09      0.39       933.17       10077.91\nstress-ng: metrc: [9480] hdd               84096      5.07      1.17      1.36     16592.85       33179.70\nstress-ng: metrc: [9480] io                  150      5.07      0.01      0.05        29.61        2359.94\nstress-ng: metrc: [9480] iomix              4340      5.07      0.13      3.21       855.80        1300.78\nstress-ng: metrc: [9480] io-uring          31828      5.07      0.01      1.82      6276.16       17353.92\nstress-ng: metrc: [9480] sync-file           124      5.06      0.05      1.48        24.49          81.16\nstress-ng: metrc: [9480] epoll              7292      5.09      0.09      0.71      1431.48        9029.79\nstress-ng: metrc: [9480] netdev            85795      5.02      0.03      2.31     17095.18       36627.07\nstress-ng: metrc: [9480] sctp              33069      5.00      0.05      1.71      6612.17       18794.38\nstress-ng: metrc: [9480] sock               1635      5.02      0.01      3.18       325.83         511.28\nstress-ng: metrc: [9480] sockdiag      102480475      5.01      0.18      6.85  20474726.24    14563582.00\nstress-ng: metrc: [9480] sockfd           348979      5.05      0.12      4.02     69169.27       84316.15\nstress-ng: metrc: [9480] sockpair          13339      5.05      0.05      0.49      2642.63       24819.75\nstress-ng: metrc: [9480] sockmany          27986      5.03      0.03      2.01      5563.77       13713.73\nstress-ng: metrc: [9480] udp              155934      5.00      0.03      2.11     31183.94       72849.10\nstress-ng: metrc: [9480] udp-flood        703954      5.00      0.05      4.39    140734.93      158586.92\nstress-ng: metrc: [9480] mmap                198      5.00      0.04      2.22        39.59          87.52\nstress-ng: metrc: [9480] mprotect         925390      5.03      0.26      6.66    183892.32      133707.19\nstress-ng: metrc: [9480] mremap              241      5.00      0.00      0.89        48.16         271.10\nstress-ng: metrc: [9480] madvise              19      5.03      0.04      1.11         3.78          16.56\nstress-ng: info:  [9480] skipped: 0\nstress-ng: info:  [9480] passed: 96: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (1) udp-flood (4) mmap (1) mprotect (1) mremap (1) madvise (1)\nstress-ng: info:  [9480] failed: 0\nstress-ng: info:  [9480] metrics untrustworthy: 0\nstress-ng: info:  [9480] successful run completed in 5.18 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "493": {
            "avg_ns_per_run": 150.7652279519838,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 493,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 31548530,
            "run_time_ns_delta": 4756421317,
            "type": "raw_tracepoint"
          },
          "494": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 494,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 495,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "496": {
            "avg_ns_per_run": 292.0466121584827,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 496,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 31548657,
            "run_time_ns_delta": 9213678395,
            "type": "raw_tracepoint"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 497,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 498,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "499": {
            "avg_ns_per_run": 261.4723338298171,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 499,
            "name": "trace_sys_enter",
            "run_cnt_delta": 31548530,
            "run_time_ns_delta": 8249067768,
            "type": "raw_tracepoint"
          },
          "500": {
            "avg_ns_per_run": 275.90395955682044,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 500,
            "name": "trace_sys_exit",
            "run_cnt_delta": 31548657,
            "run_time_ns_delta": 8704399385,
            "type": "raw_tracepoint"
          },
          "501": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 501,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 502,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 503,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 504,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "505": {
            "avg_ns_per_run": 67.02926461024637,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 505,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 1224004,
            "run_time_ns_delta": 82044088,
            "type": "kprobe"
          },
          "506": {
            "avg_ns_per_run": 262.16116368900754,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 506,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1224004,
            "run_time_ns_delta": 320886313,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": 328.0425196850394,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 507,
            "name": "trace_dup",
            "run_cnt_delta": 2540,
            "run_time_ns_delta": 833228,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": 1205.1913385826772,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 508,
            "name": "trace_ret_dup",
            "run_cnt_delta": 2540,
            "run_time_ns_delta": 3061186,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": 165.1149877149877,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 509,
            "name": "trace_dup2",
            "run_cnt_delta": 2035,
            "run_time_ns_delta": 336009,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": 887.4265356265356,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 510,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 2035,
            "run_time_ns_delta": 1805913,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": 158.87063750581666,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 511,
            "name": "trace_dup3",
            "run_cnt_delta": 2149,
            "run_time_ns_delta": 341413,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": 807.5518845974872,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 512,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 2149,
            "run_time_ns_delta": 1735429,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 513,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "514": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 514,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 515,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 516,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 517,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": 2798.7329704766616,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 518,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 6063,
            "run_time_ns_delta": 16968718,
            "type": "raw_tracepoint"
          },
          "519": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 519,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 520,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 521,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 522,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 523,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 524,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 525,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "526": {
            "avg_ns_per_run": 12402.5,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 526,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 24805,
            "type": "raw_tracepoint"
          },
          "527": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 527,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "528": {
            "avg_ns_per_run": 1190.1067174056916,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 528,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 6044,
            "run_time_ns_delta": 7193005,
            "type": "raw_tracepoint"
          },
          "529": {
            "avg_ns_per_run": 888.2159748635687,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 529,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 6047,
            "run_time_ns_delta": 5371042,
            "type": "raw_tracepoint"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 530,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "531": {
            "avg_ns_per_run": 387.7230903868325,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 531,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 1170093,
            "run_time_ns_delta": 453672074,
            "type": "raw_tracepoint"
          },
          "532": {
            "avg_ns_per_run": 17.48358642800735,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 532,
            "name": "trace_filldir64",
            "run_cnt_delta": 507781,
            "run_time_ns_delta": 8877833,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 533,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": 722.8735936465916,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 534,
            "name": "trace_do_exit",
            "run_cnt_delta": 6044,
            "run_time_ns_delta": 4369048,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 535,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 536,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 537,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": 95.83648102947234,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 538,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 5352645,
            "run_time_ns_delta": 512978661,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 539,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "540": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 540,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "541": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 541,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "542": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 542,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "543": {
            "avg_ns_per_run": 11407.0,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 543,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 22814,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": 579.7044471854167,
            "bytes_jited": 22949,
            "bytes_xlated": 37088,
            "id": 544,
            "name": "trace_security_file_open",
            "run_cnt_delta": 660755,
            "run_time_ns_delta": 383042612,
            "type": "kprobe"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 545,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "avg_ns_per_run": 1601.3084464555052,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 546,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 1326,
            "run_time_ns_delta": 2123335,
            "type": "kprobe"
          },
          "547": {
            "avg_ns_per_run": 268.2843369800448,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 547,
            "name": "trace_commit_creds",
            "run_cnt_delta": 384913,
            "run_time_ns_delta": 103266129,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": 502.95565850430177,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 548,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 6044,
            "run_time_ns_delta": 3039864,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": 138.15964035558522,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 549,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2217190,
            "run_time_ns_delta": 306326173,
            "type": "kprobe"
          },
          "550": {
            "avg_ns_per_run": 310.4762076867474,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 550,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 260084,
            "run_time_ns_delta": 80749894,
            "type": "kprobe"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 551,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "552": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 552,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 553,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 554,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": 1813.6,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 555,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 20,
            "run_time_ns_delta": 36272,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": 369.3429145442465,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 556,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 63214,
            "run_time_ns_delta": 23347643,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": 507.9714446125294,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 557,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 64121,
            "run_time_ns_delta": 32571637,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": 1204.904761904762,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 558,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 25303,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": 434.29803720662164,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 559,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 62462,
            "run_time_ns_delta": 27127124,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 560,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 561,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "562": {
            "avg_ns_per_run": 75.61181736505135,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 562,
            "name": "trace_vfs_write",
            "run_cnt_delta": 617735,
            "run_time_ns_delta": 46708066,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": 54.271639133285305,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 563,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 617735,
            "run_time_ns_delta": 33525491,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": 599.2983172395931,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 564,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 617735,
            "run_time_ns_delta": 370207546,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": 44.52529320825273,
            "bytes_jited": 23768,
            "bytes_xlated": 36720,
            "id": 565,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 617735,
            "run_time_ns_delta": 27504832,
            "type": "kprobe"
          },
          "566": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 566,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": 431.6774193548387,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 567,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 155,
            "run_time_ns_delta": 66910,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": 500.1290322580645,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 568,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 155,
            "run_time_ns_delta": 77520,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": 2100.8322580645163,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 569,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 155,
            "run_time_ns_delta": 325629,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": 5407.664516129033,
            "bytes_jited": 24504,
            "bytes_xlated": 37576,
            "id": 570,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 155,
            "run_time_ns_delta": 838188,
            "type": "kprobe"
          },
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 571,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 572,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 573,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 574,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 23768,
            "bytes_xlated": 36720,
            "id": 575,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 576,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": 63.7033243792805,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 577,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1335708,
            "run_time_ns_delta": 85089040,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": 753.6418551060561,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 578,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1335708,
            "run_time_ns_delta": 1006645455,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 579,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": 280.35483870967744,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 580,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 155,
            "run_time_ns_delta": 43455,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": 2695.122580645161,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 581,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 155,
            "run_time_ns_delta": 417744,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 582,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 116.78617102873959,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 583,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 255536,
            "run_time_ns_delta": 29843071,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": 52.568873201281214,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 584,
            "name": "trace_do_mmap",
            "run_cnt_delta": 251012,
            "run_time_ns_delta": 13195418,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": 334.3961284719456,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 585,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 251012,
            "run_time_ns_delta": 83937441,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": 102.7262477689954,
            "bytes_jited": 36948,
            "bytes_xlated": 60816,
            "id": 586,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 251008,
            "run_time_ns_delta": 25785110,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 405.06122608661633,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 587,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 1048001,
            "run_time_ns_delta": 424504570,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 588,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "589": {
            "avg_ns_per_run": 286.8645680819912,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 589,
            "name": "trace_security_bpf",
            "run_cnt_delta": 8196,
            "run_time_ns_delta": 2351142,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 590,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "591": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 591,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "592": {
            "avg_ns_per_run": 297.46434049079755,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 592,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 775787,
            "type": "kprobe"
          },
          "593": {
            "avg_ns_per_run": 852.6211180124224,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 593,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 137272,
            "type": "kprobe"
          },
          "594": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 594,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 595,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 596,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 597,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 598,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": 1428.5648148148148,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 599,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 972,
            "run_time_ns_delta": 1388565,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 600,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 601,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 602,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 603,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 604,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 605,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 606,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": 3785.0,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 607,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 15140,
            "type": "kprobe"
          },
          "608": {
            "avg_ns_per_run": 46.129413666365195,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 608,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 2598350,
            "run_time_ns_delta": 119860362,
            "type": "kprobe"
          },
          "609": {
            "avg_ns_per_run": 857.9732959850606,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 609,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 5355,
            "run_time_ns_delta": 4594447,
            "type": "raw_tracepoint"
          },
          "610": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 610,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 611,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 612,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": 806.0980923792001,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 613,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 10327,
            "run_time_ns_delta": 8324575,
            "type": "kprobe"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 614,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 615,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": 2150.2958801498125,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 616,
            "name": "trace_do_truncate",
            "run_cnt_delta": 534,
            "run_time_ns_delta": 1148258,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": 198.63814990019105,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 617,
            "name": "trace_fd_install",
            "run_cnt_delta": 1236863,
            "run_time_ns_delta": 245688178,
            "type": "kprobe"
          },
          "618": {
            "avg_ns_per_run": 315.3567345066512,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 618,
            "name": "trace_filp_close",
            "run_cnt_delta": 414210,
            "run_time_ns_delta": 130623913,
            "type": "kprobe"
          },
          "619": {
            "avg_ns_per_run": 193.1636872187766,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 619,
            "name": "trace_file_update_time",
            "run_cnt_delta": 16446,
            "run_time_ns_delta": 3176770,
            "type": "kprobe"
          },
          "620": {
            "avg_ns_per_run": 741.4116502493007,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 620,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 16446,
            "run_time_ns_delta": 12193256,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 101.90381307027286,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 621,
            "name": "trace_file_modified",
            "run_cnt_delta": 229605,
            "run_time_ns_delta": 23397625,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": 457.6725419742601,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 622,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 229605,
            "run_time_ns_delta": 105083904,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 623,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 624,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 625,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 469.0,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 626,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 938,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 8008.0,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 627,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 16016,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": 12162.0,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 628,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 24324,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 629,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": 5245.5,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 630,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10491,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": 298.0386882906453,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 631,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 672710,
            "run_time_ns_delta": 200493606,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 632,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 633,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 321.4835847609903,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 634,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 429083,
            "run_time_ns_delta": 137943141,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 635,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 636,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": 45.97302457863436,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 637,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 324184,
            "run_time_ns_delta": 14903719,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": 347.3998685931446,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 638,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 324184,
            "run_time_ns_delta": 112621479,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": 1202.2834578061463,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 639,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 61727,
            "run_time_ns_delta": 74213351,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 238.38787618167092,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 640,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 1395270,
            "run_time_ns_delta": 332615452,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 253.2758702571099,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 641,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 3027927,
            "run_time_ns_delta": 766900846,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 232.4720421843405,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 642,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 3208584,
            "run_time_ns_delta": 745906075,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": 267.5780488412783,
            "bytes_jited": 18427,
            "bytes_xlated": 29120,
            "id": 644,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 1003045,
            "run_time_ns_delta": 268392824,
            "type": "cgroup_skb"
          },
          "645": {
            "avg_ns_per_run": 236.6225713477314,
            "bytes_jited": 18427,
            "bytes_xlated": 29120,
            "id": 645,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 2007492,
            "run_time_ns_delta": 475017919,
            "type": "cgroup_skb"
          },
          "646": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 646,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "647": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 647,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "648": {
            "avg_ns_per_run": 239.5,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 648,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 479,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 1681.0,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 649,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3362,
            "type": "raw_tracepoint"
          },
          "650": {
            "avg_ns_per_run": 275.44090623604814,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 650,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 660755,
            "run_time_ns_delta": 181998956,
            "type": "lsm"
          },
          "651": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 651,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.20652734500004,
            "ops_per_sec": 16624396.121365098,
            "ops_total": 86555373.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [21171] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21171]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21171] cap              488670      5.00      0.31      4.93     97677.99       93210.64\nstress-ng: metrc: [21171] eventfd          213518      5.00      0.13      4.91     42695.94       42308.91\nstress-ng: metrc: [21171] get                3634      5.00      0.10      2.34       726.61        1491.54\nstress-ng: metrc: [21171] prctl              4654      5.01      3.06      0.93       929.50        1167.03\nstress-ng: metrc: [21171] set               40666      5.02      0.23      5.36      8102.51        7269.76\nstress-ng: metrc: [21171] dup                 478      5.00      0.18      0.12        95.54        1591.42\nstress-ng: metrc: [21171] kill               7875      5.00      0.01      0.77      1573.96       10001.23\nstress-ng: metrc: [21171] sigfd            153360      5.04      0.01      0.99     30423.31      153325.81\nstress-ng: metrc: [21171] signal                0      5.00      0.00      0.00         0.00           0.00\nstress-ng: metrc: [21171] pty                  12      5.05      0.05      1.82         2.38           6.43\nstress-ng: metrc: [21171] itimer              123      5.04      0.03      0.82        24.41         144.29\nstress-ng: metrc: [21171] timerfd          207872      5.04      0.00      1.69     41262.38      123036.86\nstress-ng: metrc: [21171] aio               26795      5.04      0.00      0.31      5320.19       85129.43\nstress-ng: metrc: [21171] aiol               6166      5.15      0.11      0.47      1196.61       10650.17\nstress-ng: metrc: [21171] hdd               79056      5.02      1.05      1.49     15754.57       31095.80\nstress-ng: metrc: [21171] io                  111      5.03      0.04      0.01        22.09        2176.60\nstress-ng: metrc: [21171] iomix              3882      5.05      0.24      3.11       768.65        1160.79\nstress-ng: metrc: [21171] io-uring          31648      5.03      0.02      2.16      6286.67       14505.41\nstress-ng: metrc: [21171] sync-file           125      5.03      0.04      1.51        24.87          80.92\nstress-ng: metrc: [21171] epoll              1111      5.10      0.05      0.07       217.88        8823.62\nstress-ng: metrc: [21171] netdev           201411      5.01      0.13      5.77     40232.31       34180.30\nstress-ng: metrc: [21171] sctp               5417      5.00      0.04      0.01      1083.13      111946.93\nstress-ng: metrc: [21171] sock               2600      5.02      0.12      4.60       518.39         551.62\nstress-ng: metrc: [21171] sockdiag       83280267      5.00      0.17      5.97  16650225.85    13563422.23\nstress-ng: metrc: [21171] sockfd           267346      5.02      0.10      3.07     53298.89       84323.59\nstress-ng: metrc: [21171] sockpair          90206      5.02      0.09      2.06     17968.05       41971.23\nstress-ng: metrc: [21171] sockmany          61712      5.02      0.07      3.60     12296.82       16795.18\nstress-ng: metrc: [21171] udp               80147      5.01      0.03      1.48     16012.46       52921.07\nstress-ng: metrc: [21171] udp-flood        520733      5.00      0.09      3.64    104105.37      139685.38\nstress-ng: metrc: [21171] mmap                 54      5.00      0.01      0.68        10.80          78.63\nstress-ng: metrc: [21171] mprotect         775581      5.01      0.24      5.11    154675.43      145098.70\nstress-ng: metrc: [21171] mremap              125      5.00      0.01      0.48        24.98         254.65\nstress-ng: metrc: [21171] madvise              18      5.00      0.03      1.06         3.60          16.52\nstress-ng: info:  [21171] skipped: 0\nstress-ng: info:  [21171] passed: 96: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1) aio (4) aiol (4) hdd (4) io (4) iomix (4) io-uring (4) sync-file (4) epoll (4) netdev (4) sctp (4) sock (4) sockdiag (4) sockfd (4) sockpair (4) sockmany (4) udp (1) udp-flood (4) mmap (1) mprotect (1) mremap (1) madvise (1)\nstress-ng: info:  [21171] failed: 0\nstress-ng: info:  [21171] metrics untrustworthy: 0\nstress-ng: info:  [21171] successful run completed in 5.17 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem"
        ],
        "error": "",
        "exit_code": 0,
        "program_counts": {
          "applied": 158,
          "not_applied": 0,
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
          "657": {
            "avg_ns_per_run": 206.53755271581207,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 657,
            "name": "cap_capable",
            "run_cnt_delta": 975988,
            "run_time_ns_delta": 201578173,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0229945510000107,
            "ops_per_sec": 5307288.288772071,
            "ops_total": 5429327.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [31020] setting to a 1 secs run per stressor\nstress-ng: info:  [31020] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 1 dup, 1 kill, 1 sigfd, 1 signal, 1 pty, 1 itimer, 1 timerfd\nstress-ng: info:  [31020] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31020] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31020]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31020] cap             3223719      1.00      0.66      2.59   3223603.71      992722.68\nstress-ng: metrc: [31020] eventfd         1136802      1.00      0.61      2.74   1136478.41      339047.14\nstress-ng: metrc: [31020] get                2629      1.00      0.06      0.50      2622.75        4734.98\nstress-ng: metrc: [31020] prctl              3383      1.00      0.68      0.53      3382.07        2776.86\nstress-ng: metrc: [31020] set               61116      1.00      0.27      1.43     61112.32       35933.30\nstress-ng: metrc: [31020] dup                 308      1.00      0.07      0.06       307.79        2345.40\nstress-ng: metrc: [31020] kill               6042      1.00      0.00      0.49      6040.62       12339.78\nstress-ng: metrc: [31020] sigfd            725916      1.00      0.26      0.66    725667.90      788500.04\nstress-ng: metrc: [31020] signal                0      1.00      0.15      0.70         0.00           0.00\nstress-ng: metrc: [31020] pty                  17      1.01      0.07      0.86        16.91          18.42\nstress-ng: metrc: [31020] itimer               83      1.00      0.12      0.39        83.00         163.16\nstress-ng: metrc: [31020] timerfd          269312      1.00      0.08      0.82    268666.20      300095.16\nstress-ng: info:  [31020] skipped: 0\nstress-ng: info:  [31020] passed: 27: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1)\nstress-ng: info:  [31020] failed: 0\nstress-ng: info:  [31020] metrics untrustworthy: 0\nstress-ng: info:  [31020] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "657": {
            "avg_ns_per_run": 194.59746887888662,
            "bytes_jited": 697,
            "bytes_xlated": 1216,
            "id": 657,
            "name": "cap_capable",
            "run_cnt_delta": 690287,
            "run_time_ns_delta": 134328103,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0267022680000082,
            "ops_per_sec": 5790089.478988034,
            "ops_total": 5944698.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [6632] setting to a 1 secs run per stressor\nstress-ng: info:  [6632] dispatching hogs: 4 cap, 4 eventfd, 4 get, 4 prctl, 4 set, 1 dup, 1 kill, 1 sigfd, 1 signal, 1 pty, 1 itimer, 1 timerfd\nstress-ng: info:  [6632] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6632] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6632]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6632] cap             3134306      1.00      0.93      2.74   3134309.55      853333.76\nstress-ng: metrc: [6632] eventfd          857759      1.00      0.43      2.51    857325.82      291744.34\nstress-ng: metrc: [6632] get                2232      1.00      0.09      0.35      2230.05        5152.69\nstress-ng: metrc: [6632] prctl              2503      1.00      0.52      0.40      2502.24        2711.82\nstress-ng: metrc: [6632] set               41721      1.00      0.12      1.32     41720.14       28871.41\nstress-ng: metrc: [6632] dup                 300      1.00      0.07      0.06       299.95        2303.74\nstress-ng: metrc: [6632] kill               9581      1.00      0.02      0.68      9579.63       13689.31\nstress-ng: metrc: [6632] sigfd           1665790      1.00      0.19      0.91   1664738.20     1515277.49\nstress-ng: metrc: [6632] signal                0      1.00      0.09      0.77         0.00           0.00\nstress-ng: metrc: [6632] pty                  12      1.01      0.01      0.91        11.91          13.04\nstress-ng: metrc: [6632] itimer               94      1.00      0.19      0.68        94.03         107.17\nstress-ng: metrc: [6632] timerfd          230400      1.00      0.05      0.88    230225.94      249457.02\nstress-ng: info:  [6632] skipped: 0\nstress-ng: info:  [6632] passed: 27: cap (4) eventfd (4) get (4) prctl (4) set (4) dup (1) kill (1) sigfd (1) signal (1) pty (1) itimer (1) timerfd (1)\nstress-ng: info:  [6632] failed: 0\nstress-ng: info:  [6632] metrics untrustworthy: 0\nstress-ng: info:  [6632] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem"
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
          "664": {
            "avg_ns_per_run": 420.66326585621334,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 664,
            "name": "block_io_start",
            "run_cnt_delta": 1465435,
            "run_time_ns_delta": 616454673,
            "type": "tracepoint"
          },
          "665": {
            "avg_ns_per_run": 757.4656610597427,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 665,
            "name": "block_io_done",
            "run_cnt_delta": 1465450,
            "run_time_ns_delta": 1110028053,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.332985520999955,
            "ops_per_sec": 368217.5757401642,
            "ops_total": 1963699.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.067096,\n        \"1000\" : 12.192014\n      },\n      \"latency_us\" : {\n        \"2\" : 35.410374,\n        \"4\" : 1.742449,\n        \"10\" : 10.771709,\n        \"20\" : 35.212984,\n        \"50\" : 2.597669,\n        \"100\" : 1.698129,\n        \"250\" : 0.288903,\n        \"500\" : 0.018467,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "664": {
            "avg_ns_per_run": 394.44579212060523,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 664,
            "name": "block_io_start",
            "run_cnt_delta": 1440999,
            "run_time_ns_delta": 568395992,
            "type": "tracepoint"
          },
          "665": {
            "avg_ns_per_run": 758.7494333851024,
            "bytes_jited": 883,
            "bytes_xlated": 1480,
            "id": 665,
            "name": "block_io_done",
            "run_cnt_delta": 1441014,
            "run_time_ns_delta": 1093368556,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.358781454999985,
            "ops_per_sec": 360319.9750193966,
            "ops_total": 1930876.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.145736,\n        \"1000\" : 14.533148\n      },\n      \"latency_us\" : {\n        \"2\" : 33.084705,\n        \"4\" : 1.625275,\n        \"10\" : 10.796468,\n        \"20\" : 36.762304,\n        \"50\" : 1.711099,\n        \"100\" : 1.007712,\n        \"250\" : 0.310544,\n        \"500\" : 0.020316,\n        \"750\" : 0.000000,\n        \"1000\" : 0.010000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.010000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem"
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
          "672": {
            "avg_ns_per_run": 1736.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 672,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1736,
            "type": "perf_event"
          },
          "673": {
            "avg_ns_per_run": 36.31464539874612,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 673,
            "name": "vfs_create",
            "run_cnt_delta": 2190968,
            "run_time_ns_delta": 79564226,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.212661584999978,
            "ops_per_sec": 1996945.4215044207,
            "ops_total": 2421619.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [32174] setting to a 1 secs run per stressor\nstress-ng: info:  [32174] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 1 link, 1 symlink, 1 mknod, 1 fcntl\nstress-ng: info:  [32174] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [32317] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [32191] dentry: 304626 dentries allocated\nstress-ng: metrc: [32174] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [32174]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32174] access            16951      1.02      0.27      1.66     16637.27        8783.39\nstress-ng: metrc: [32174] chdir                11      1.13      0.05      1.06         9.70           9.94\nstress-ng: metrc: [32174] chmod               124      1.02      0.02      0.02       121.95        3302.53\nstress-ng: metrc: [32174] chown               152      1.02      0.00      0.03       149.41        5072.58\nstress-ng: metrc: [32174] dentry             8192      1.12      0.02      0.22      7329.07       34125.94\nstress-ng: metrc: [32174] dir               21558      1.15      0.11      1.70     18757.84       11894.29\nstress-ng: metrc: [32174] dirmany           17222      1.02      0.01      0.40     16850.02       42075.17\nstress-ng: metrc: [32174] fallocate             0      1.03      0.02      0.00         0.00           0.00\nstress-ng: metrc: [32174] file-ioctl        82173      1.00      0.05      0.91     81873.44       84878.15\nstress-ng: metrc: [32174] filename           4930      1.02      0.01      1.00      4814.85        4882.00\nstress-ng: metrc: [32174] flock           1685350      1.02      0.24      0.43   1645428.11     2499825.72\nstress-ng: metrc: [32174] fpunch              228      1.04      0.02      0.55       220.23         403.10\nstress-ng: metrc: [32174] fstat              4428      1.00      0.21      0.89      4422.05        4013.83\nstress-ng: metrc: [32174] getdent          411891      1.00      0.15      2.48    411873.01      156695.72\nstress-ng: metrc: [32174] hdd               18152      1.01      0.25      0.25     17908.72       35798.24\nstress-ng: metrc: [32174] inotify               4      1.05      0.00      0.00         3.80         784.93\nstress-ng: metrc: [32174] open               4096      1.11      0.02      0.04      3699.15       67148.64\nstress-ng: metrc: [32174] rename            59970      1.01      0.01      0.37     59127.72      156668.40\nstress-ng: metrc: [32174] touch             52425      1.11      0.04      1.15     47248.99       43797.18\nstress-ng: metrc: [32174] utime             30589      1.01      0.02      0.56     30288.22       52799.74\nstress-ng: metrc: [32174] link                  1      1.04      0.00      0.14         0.96           7.27\nstress-ng: metrc: [32174] symlink               1      1.11      0.00      0.16         0.90           6.09\nstress-ng: metrc: [32174] mknod                 1      1.12      0.00      0.00         0.89        2444.99\nstress-ng: metrc: [32174] fcntl              3170      1.01      0.02      0.02      3154.03       74138.17\nstress-ng: info:  [32174] skipped: 0\nstress-ng: info:  [32174] passed: 84: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (1) symlink (1) mknod (1) fcntl (1)\nstress-ng: info:  [32174] failed: 0\nstress-ng: info:  [32174] metrics untrustworthy: 0\nstress-ng: info:  [32174] successful run completed in 1.20 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "672": {
            "avg_ns_per_run": 2104.5,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 672,
            "name": "1",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 4209,
            "type": "perf_event"
          },
          "673": {
            "avg_ns_per_run": 37.51909591542329,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 673,
            "name": "vfs_create",
            "run_cnt_delta": 2084451,
            "run_time_ns_delta": 78206717,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.220311742999911,
            "ops_per_sec": 2039977.9107920798,
            "ops_total": 2489409.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1425] setting to a 1 secs run per stressor\nstress-ng: info:  [1425] dispatching hogs: 4 access, 4 chdir, 4 chmod, 4 chown, 4 dentry, 4 dir, 4 dirmany, 4 fallocate, 4 file-ioctl, 4 filename, 4 flock, 4 fpunch, 4 fstat, 4 getdent, 4 hdd, 4 inotify, 4 open, 4 rename, 4 touch, 4 utime, 1 link, 1 symlink, 1 mknod, 1 fcntl\nstress-ng: info:  [1425] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [1531] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [1448] dentry: 82987 dentries allocated\nstress-ng: metrc: [1425] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1425]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1425] access            15937      1.02      0.17      1.52     15662.84        9430.78\nstress-ng: metrc: [1425] chdir                51      1.12      0.13      1.53        45.49          30.75\nstress-ng: metrc: [1425] chmod               128      1.00      0.01      0.04       127.74        2531.40\nstress-ng: metrc: [1425] chown               126      1.01      0.01      0.00       124.18       24124.07\nstress-ng: metrc: [1425] dentry             8192      1.12      0.00      0.23      7337.35       35204.58\nstress-ng: metrc: [1425] dir               15762      1.13      0.08      1.27     13992.14       11699.47\nstress-ng: metrc: [1425] dirmany           11472      1.01      0.00      0.28     11335.83       40967.33\nstress-ng: metrc: [1425] fallocate             0      1.02      0.01      0.00         0.00           0.00\nstress-ng: metrc: [1425] file-ioctl        73058      1.01      0.10      0.82     72357.20       79601.83\nstress-ng: metrc: [1425] filename           4774      1.02      0.10      0.93      4699.16        4610.05\nstress-ng: metrc: [1425] flock           1751605      1.02      0.28      0.37   1712309.95     2683761.12\nstress-ng: metrc: [1425] fpunch              217      1.03      0.02      0.45       209.77         463.05\nstress-ng: metrc: [1425] fstat              3134      1.00      0.16      0.72      3122.37        3570.89\nstress-ng: metrc: [1425] getdent          446860      1.00      0.20      2.63    444960.01      158074.89\nstress-ng: metrc: [1425] hdd               16384      1.02      0.34      0.16     16113.37       33323.30\nstress-ng: metrc: [1425] inotify               4      1.11      0.01      0.00         3.62         302.48\nstress-ng: metrc: [1425] open               4096      1.13      0.04      0.04      3632.89       57475.62\nstress-ng: metrc: [1425] rename            33055      1.01      0.02      0.23     32737.08      129751.10\nstress-ng: metrc: [1425] touch             79695      1.12      0.03      1.47     71027.14       53060.99\nstress-ng: metrc: [1425] utime             22346      1.01      0.01      0.41     22161.25       53186.40\nstress-ng: metrc: [1425] link                  1      1.05      0.01      0.08         0.95          11.00\nstress-ng: metrc: [1425] symlink               1      1.11      0.01      0.16         0.90           5.84\nstress-ng: metrc: [1425] mknod                 0      1.12      0.00      0.00         0.00           0.00\nstress-ng: metrc: [1425] fcntl              2511      1.01      0.00      0.04      2474.38       58892.51\nstress-ng: info:  [1425] skipped: 0\nstress-ng: info:  [1425] passed: 84: access (4) chdir (4) chmod (4) chown (4) dentry (4) dir (4) dirmany (4) fallocate (4) file-ioctl (4) filename (4) flock (4) fpunch (4) fstat (4) getdent (4) hdd (4) inotify (4) open (4) rename (4) touch (4) utime (4) link (1) symlink (1) mknod (1) fcntl (1)\nstress-ng: info:  [1425] failed: 0\nstress-ng: info:  [1425] metrics untrustworthy: 0\nstress-ng: info:  [1425] successful run completed in 1.21 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
          "680": {
            "avg_ns_per_run": 69.6376894235002,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 680,
            "name": "sched_wakeup",
            "run_cnt_delta": 2569177,
            "run_time_ns_delta": 178911550,
            "type": "tracepoint"
          },
          "681": {
            "avg_ns_per_run": 276.0769230769231,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 681,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 21534,
            "type": "tracepoint"
          },
          "682": {
            "avg_ns_per_run": 132.8917525942951,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 682,
            "name": "sched_switch",
            "run_cnt_delta": 13057015,
            "run_time_ns_delta": 1735169607,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.015344824000067,
            "ops_per_sec": 11390766.689917391,
            "ops_total": 11565556.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15504] setting to a 1 secs run per stressor\nstress-ng: info:  [15504] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [15504] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15504] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15504]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15504] futex            945328      2.00      0.17      4.51    472620.97      202019.54\nstress-ng: metrc: [15504] sem             1783594      1.00      0.55      1.24   1782708.02      991648.57\nstress-ng: metrc: [15504] sem-sysv         428700      1.00      0.15      0.85    428546.31      428793.48\nstress-ng: metrc: [15504] switch          1558267      1.00      0.47      2.82   1557997.23      474483.96\nstress-ng: metrc: [15504] yield           6849667      1.00      2.03      4.20   6842837.71     1099788.41\nstress-ng: info:  [15504] skipped: 0\nstress-ng: info:  [15504] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [15504] failed: 0\nstress-ng: info:  [15504] metrics untrustworthy: 0\nstress-ng: info:  [15504] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "680": {
            "avg_ns_per_run": 68.82500156243908,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 680,
            "name": "sched_wakeup",
            "run_cnt_delta": 3232126,
            "run_time_ns_delta": 222451077,
            "type": "tracepoint"
          },
          "681": {
            "avg_ns_per_run": 288.6025641025641,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 681,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 78,
            "run_time_ns_delta": 22511,
            "type": "tracepoint"
          },
          "682": {
            "avg_ns_per_run": 132.18894854750914,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 682,
            "name": "sched_switch",
            "run_cnt_delta": 12001246,
            "run_time_ns_delta": 1586432090,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.016111464000005,
            "ops_per_sec": 12853319.210263269,
            "ops_total": 13060405.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15738] setting to a 1 secs run per stressor\nstress-ng: info:  [15738] dispatching hogs: 4 futex, 4 sem, 4 sem-sysv, 4 switch, 4 yield\nstress-ng: info:  [15738] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15738] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15738]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15738] futex           1097420      2.00      0.19      5.27    548551.33      201219.06\nstress-ng: metrc: [15738] sem             2961322      1.00      0.63      2.01   2960560.39     1121306.41\nstress-ng: metrc: [15738] sem-sysv         724946      1.00      0.08      0.91    724554.08      727674.05\nstress-ng: metrc: [15738] switch          1127704      1.00      0.25      2.49   1127525.17      410135.63\nstress-ng: metrc: [15738] yield           7149013      1.00      1.38      4.02   7141364.77     1324624.99\nstress-ng: info:  [15738] skipped: 0\nstress-ng: info:  [15738] passed: 20: futex (4) sem (4) sem-sysv (4) switch (4) yield (4)\nstress-ng: info:  [15738] failed: 0\nstress-ng: info:  [15738] metrics untrustworthy: 0\nstress-ng: info:  [15738] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
          "690": {
            "avg_ns_per_run": 425.7177143260509,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 690,
            "name": "tcp_set_state",
            "run_cnt_delta": 56666,
            "run_time_ns_delta": 24123720,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.103183594999905,
            "ops_per_sec": 5892.038305736916,
            "ops_total": 6500.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.86ms  331.96us   3.56ms   79.38%\n    Req/Sec     3.11k     2.11k    6.02k    42.86%\n  6500 requests in 1.10s, 0.96MB read\n  Socket errors: connect 0, read 6500, write 0, timeout 0\nRequests/sec:   5908.51\nTransfer/sec:      0.87MB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "690": {
            "avg_ns_per_run": 427.5742082312677,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 690,
            "name": "tcp_set_state",
            "run_cnt_delta": 57561,
            "run_time_ns_delta": 24611599,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.102771649000033,
            "ops_per_sec": 5954.995311998453,
            "ops_total": 6567.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     0.89ms  276.13us   2.48ms   74.77%\n    Req/Sec     3.00k     1.02k    4.34k    59.09%\n  6567 requests in 1.10s, 0.97MB read\n  Socket errors: connect 0, read 6567, write 0, timeout 0\nRequests/sec:   5970.98\nTransfer/sec:      0.88MB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
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
    }
  ],
  "samples": 1,
  "status": "ok",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 80,
    "per_program_geomean": 1.0228188862872964,
    "program_count": 148,
    "wins": 68
  },
  "workload_seconds": 1.0
}
```
