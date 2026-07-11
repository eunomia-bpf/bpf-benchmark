# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T02:46:56.405190+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T02:36:39.044285+00:00",
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
      "invoked_at": "2026-05-05T02:36:39.044228+00:00",
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
        "captured_at": "2026-05-05T02:36:39.044220+00:00",
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
      "captured_at": "2026-05-05T02:36:39.030211+00:00",
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
      "baseline_avg_ns_per_run": 328.60978852348626,
      "baseline_run_cnt_delta": 1098940,
      "baseline_run_time_ns_delta": 361122441,
      "post_rejit_avg_ns_per_run": 318.6086652551018,
      "post_rejit_run_cnt_delta": 1102795,
      "post_rejit_run_time_ns_delta": 351360043,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 0.9695653519229551,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 834.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1668,
      "post_rejit_avg_ns_per_run": 809.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 1619,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 0.9706235011990407,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 110.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 220,
      "post_rejit_avg_ns_per_run": 204.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 408,
      "program": "do_ret_sys_execve",
      "program_id": 10,
      "ratio": 1.8545454545454545,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 1807.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 3614,
      "post_rejit_avg_ns_per_run": 2731.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 5462,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 1.5113447703375762,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 4745.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 9490,
      "post_rejit_avg_ns_per_run": 11309.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 22618,
      "program": "bindsnoop_v4_return",
      "program_id": 14,
      "ratio": 2.383350895679663,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 214.32101549644932,
      "baseline_run_cnt_delta": 1751498,
      "baseline_run_time_ns_delta": 375382830,
      "post_rejit_avg_ns_per_run": 212.04397881729713,
      "post_rejit_run_cnt_delta": 1703843,
      "post_rejit_run_time_ns_delta": 361289649,
      "program": "trace_pid_start_tp",
      "program_id": 18,
      "ratio": 0.9893755790869239,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 194.2467216821162,
      "baseline_run_cnt_delta": 1751508,
      "baseline_run_time_ns_delta": 340224687,
      "post_rejit_avg_ns_per_run": 193.42022345824435,
      "post_rejit_run_cnt_delta": 1703853,
      "post_rejit_run_time_ns_delta": 329559628,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 0.9957451110797926,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 94.76248820305645,
      "baseline_run_cnt_delta": 1751513,
      "baseline_run_time_ns_delta": 165977730,
      "post_rejit_avg_ns_per_run": 94.27904672807242,
      "post_rejit_run_cnt_delta": 1703858,
      "post_rejit_run_time_ns_delta": 160638108,
      "program": "trace_req_completion_tp",
      "program_id": 20,
      "ratio": 0.9948983877043401,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 62.77591283259897,
      "baseline_run_cnt_delta": 146385,
      "baseline_run_time_ns_delta": 9189452,
      "post_rejit_avg_ns_per_run": 69.88205654370788,
      "post_rejit_run_cnt_delta": 142297,
      "post_rejit_run_time_ns_delta": 9944007,
      "program": "vfs_create",
      "program_id": 23,
      "ratio": 1.113198572357816,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 70.12316715542522,
      "baseline_run_cnt_delta": 682,
      "baseline_run_time_ns_delta": 47824,
      "post_rejit_avg_ns_per_run": 84.02051282051282,
      "post_rejit_run_cnt_delta": 585,
      "post_rejit_run_time_ns_delta": 49152,
      "program": "kfunc__vmlinux__vfs_fsync_range",
      "program_id": 24,
      "ratio": 1.198184797248029,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 46.94345574816848,
      "baseline_run_cnt_delta": 1361164,
      "baseline_run_time_ns_delta": 63897742,
      "post_rejit_avg_ns_per_run": 44.61829639077238,
      "post_rejit_run_cnt_delta": 1427757,
      "post_rejit_run_time_ns_delta": 63704085,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 0.9504689350125908,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 44.02140917079406,
      "baseline_run_cnt_delta": 62590,
      "baseline_run_time_ns_delta": 2755300,
      "post_rejit_avg_ns_per_run": 85.93267040898155,
      "post_rejit_run_cnt_delta": 62350,
      "post_rejit_run_time_ns_delta": 5357902,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.9520654160701756,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 52.18107911815008,
      "baseline_run_cnt_delta": 85366,
      "baseline_run_time_ns_delta": 4454490,
      "post_rejit_avg_ns_per_run": 53.16791644751672,
      "post_rejit_run_cnt_delta": 66545,
      "post_rejit_run_time_ns_delta": 3538059,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 1.0189117846170297,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 385.3668746226605,
      "baseline_run_cnt_delta": 14907,
      "baseline_run_time_ns_delta": 5744664,
      "post_rejit_avg_ns_per_run": 367.2263266454153,
      "post_rejit_run_cnt_delta": 15999,
      "post_rejit_run_time_ns_delta": 5875254,
      "program": "__x64_sys_open",
      "program_id": 30,
      "ratio": 0.9529265508484407,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 388.6312563824044,
      "baseline_run_cnt_delta": 614972,
      "baseline_run_time_ns_delta": 238997341,
      "post_rejit_avg_ns_per_run": 375.9022230020059,
      "post_rejit_run_cnt_delta": 592757,
      "post_rejit_run_time_ns_delta": 222818674,
      "program": "kretfunc__vmlinux____x64_sys_openat",
      "program_id": 31,
      "ratio": 0.9672465012235829,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 406.1200139958013,
      "baseline_run_cnt_delta": 2858,
      "baseline_run_time_ns_delta": 1160691,
      "post_rejit_avg_ns_per_run": 373.2580095432856,
      "post_rejit_run_cnt_delta": 2934,
      "post_rejit_run_time_ns_delta": 1095139,
      "program": "kretfunc__vmlinux____x64_sys_openat2",
      "program_id": 32,
      "ratio": 0.9190830214714426,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 55.65912021919594,
      "baseline_run_cnt_delta": 9622806,
      "baseline_run_time_ns_delta": 535596916,
      "post_rejit_avg_ns_per_run": 57.76994409991454,
      "post_rejit_run_cnt_delta": 9566175,
      "post_rejit_run_time_ns_delta": 552637395,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 35,
      "ratio": 1.0379241330514348,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 57.05617425352083,
      "baseline_run_cnt_delta": 9622807,
      "baseline_run_time_ns_delta": 549040553,
      "post_rejit_avg_ns_per_run": 55.711621655298835,
      "post_rejit_run_cnt_delta": 9566176,
      "post_rejit_run_time_ns_delta": 532947178,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 36,
      "ratio": 0.9764345819569382,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 721.3225806451613,
      "baseline_run_cnt_delta": 310,
      "baseline_run_time_ns_delta": 223610,
      "post_rejit_avg_ns_per_run": 736.9019607843137,
      "post_rejit_run_cnt_delta": 306,
      "post_rejit_run_time_ns_delta": 225492,
      "program": "trace_connect_entry",
      "program_id": 39,
      "ratio": 1.0215983535760351,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4084.4774193548387,
      "baseline_run_cnt_delta": 155,
      "baseline_run_time_ns_delta": 633094,
      "post_rejit_avg_ns_per_run": 4734.522875816993,
      "post_rejit_run_cnt_delta": 153,
      "post_rejit_run_time_ns_delta": 724382,
      "program": "trace_connect_v4_return",
      "program_id": 40,
      "ratio": 1.1591502142677612,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 4321.238709677419,
      "baseline_run_cnt_delta": 155,
      "baseline_run_time_ns_delta": 669792,
      "post_rejit_avg_ns_per_run": 4778.392156862745,
      "post_rejit_run_cnt_delta": 153,
      "post_rejit_run_time_ns_delta": 731094,
      "program": "trace_connect_v6_return",
      "program_id": 41,
      "ratio": 1.1057922225313612,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 841.6738991703893,
      "baseline_run_cnt_delta": 3134,
      "baseline_run_time_ns_delta": 2637806,
      "post_rejit_avg_ns_per_run": 851.9226263871764,
      "post_rejit_run_cnt_delta": 3244,
      "post_rejit_run_time_ns_delta": 2763637,
      "program": "tracepoint__sock__inet_sock_set_state",
      "program_id": 44,
      "ratio": 1.0121766009696735,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 187.23885051602977,
      "baseline_run_cnt_delta": 11478020,
      "baseline_run_time_ns_delta": 2149131271,
      "post_rejit_avg_ns_per_run": 190.66186655737602,
      "post_rejit_run_cnt_delta": 12712280,
      "post_rejit_run_time_ns_delta": 2423747033,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 1.018281548043648,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 86.56025811144379,
      "baseline_run_cnt_delta": 555419,
      "baseline_run_time_ns_delta": 48077212,
      "post_rejit_avg_ns_per_run": 82.42585176764223,
      "post_rejit_run_cnt_delta": 467968,
      "post_rejit_run_time_ns_delta": 38572661,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 0.9522366680275072,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 183.05585640401583,
      "baseline_run_cnt_delta": 32870,
      "baseline_run_time_ns_delta": 6017046,
      "post_rejit_avg_ns_per_run": 206.76208868378814,
      "post_rejit_run_cnt_delta": 19936,
      "post_rejit_run_time_ns_delta": 4122009,
      "program": "raw_tracepoint__sched_wakeup_new",
      "program_id": 49,
      "ratio": 1.1295027252635454,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 1322.0,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 3966,
      "post_rejit_avg_ns_per_run": 4544.333333333333,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 13633,
      "program": "tracepoint__sched_process_free",
      "program_id": 63,
      "ratio": 3.4374684820978314,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 1010.8890954151177,
      "baseline_run_cnt_delta": 1614,
      "baseline_run_time_ns_delta": 1631575,
      "post_rejit_avg_ns_per_run": 935.1635687732341,
      "post_rejit_run_cnt_delta": 1614,
      "post_rejit_run_time_ns_delta": 1509354,
      "program": "native_tracer_entry",
      "program_id": 64,
      "ratio": 0.9250901736052587,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 1697.8195488721803,
      "baseline_run_cnt_delta": 266,
      "baseline_run_time_ns_delta": 451620,
      "post_rejit_avg_ns_per_run": 1647.6571428571428,
      "post_rejit_run_cnt_delta": 350,
      "post_rejit_run_time_ns_delta": 576680,
      "program": "cil_from_netdev",
      "program_id": 166,
      "ratio": 0.970454807138745,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1674.489247311828,
      "baseline_run_cnt_delta": 930,
      "baseline_run_time_ns_delta": 1557275,
      "post_rejit_avg_ns_per_run": 1531.9455388180766,
      "post_rejit_run_cnt_delta": 863,
      "post_rejit_run_time_ns_delta": 1322069,
      "program": "event_exit_acct_process",
      "program_id": 183,
      "ratio": 0.914873321090245,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2188.5888125613346,
      "baseline_run_cnt_delta": 1019,
      "baseline_run_time_ns_delta": 2230172,
      "post_rejit_avg_ns_per_run": 2144.818880351262,
      "post_rejit_run_cnt_delta": 911,
      "post_rejit_run_time_ns_delta": 1953930,
      "program": "event_wake_up_new_task",
      "program_id": 185,
      "ratio": 0.9800008425708583,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5182.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 10364,
      "post_rejit_avg_ns_per_run": 7107.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 14215,
      "program": "event_execve",
      "program_id": 188,
      "ratio": 1.3715746815901197,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 539.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1078,
      "post_rejit_avg_ns_per_run": 852.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 1704,
      "program": "tg_kp_bprm_committing_creds",
      "program_id": 189,
      "ratio": 1.5807050092764379,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 405.35254134557107,
      "baseline_run_cnt_delta": 115490,
      "baseline_run_time_ns_delta": 46814165,
      "post_rejit_avg_ns_per_run": 446.2741940988754,
      "post_rejit_run_cnt_delta": 117198,
      "post_rejit_run_time_ns_delta": 52302443,
      "program": "generic_kprobe_event",
      "program_id": 217,
      "ratio": 1.1009532408936296,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 49.1028227552169,
      "baseline_run_cnt_delta": 115490,
      "baseline_run_time_ns_delta": 5670885,
      "post_rejit_avg_ns_per_run": 74.08026587484429,
      "post_rejit_run_cnt_delta": 117198,
      "post_rejit_run_time_ns_delta": 8682059,
      "program": "generic_retkprobe_event",
      "program_id": 224,
      "ratio": 1.508676318755497,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1316.728100261567,
      "baseline_run_cnt_delta": 115458,
      "baseline_run_time_ns_delta": 152026793,
      "post_rejit_avg_ns_per_run": 1371.6946787745057,
      "post_rejit_run_cnt_delta": 117830,
      "post_rejit_run_time_ns_delta": 161626784,
      "program": "generic_kprobe_event",
      "program_id": 226,
      "ratio": 1.0417448207431887,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 409.0532253874794,
      "baseline_run_cnt_delta": 115490,
      "baseline_run_time_ns_delta": 47241557,
      "post_rejit_avg_ns_per_run": 429.9455366132528,
      "post_rejit_run_cnt_delta": 117198,
      "post_rejit_run_time_ns_delta": 50388757,
      "program": "generic_kprobe_event",
      "program_id": 245,
      "ratio": 1.0510747988992948,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 49.34443674777037,
      "baseline_run_cnt_delta": 115490,
      "baseline_run_time_ns_delta": 5698789,
      "post_rejit_avg_ns_per_run": 80.79230874247001,
      "post_rejit_run_cnt_delta": 117198,
      "post_rejit_run_time_ns_delta": 9468697,
      "program": "generic_retkprobe_event",
      "program_id": 249,
      "ratio": 1.6373134251273143,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1378.7790538550814,
      "baseline_run_cnt_delta": 115458,
      "baseline_run_time_ns_delta": 159191072,
      "post_rejit_avg_ns_per_run": 1406.0109988967156,
      "post_rejit_run_cnt_delta": 117830,
      "post_rejit_run_time_ns_delta": 165670276,
      "program": "generic_kprobe_event",
      "program_id": 256,
      "ratio": 1.0197507678735713,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 558.2925075981148,
      "baseline_run_cnt_delta": 113515,
      "baseline_run_time_ns_delta": 63374574,
      "post_rejit_avg_ns_per_run": 454.4143473233951,
      "post_rejit_run_cnt_delta": 227471,
      "post_rejit_run_time_ns_delta": 103366086,
      "program": "generic_kprobe_event",
      "program_id": 263,
      "ratio": 0.8139359585504305,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 839.8856810275269,
      "baseline_run_cnt_delta": 377995,
      "baseline_run_time_ns_delta": 317472588,
      "post_rejit_avg_ns_per_run": 747.3661606306157,
      "post_rejit_run_cnt_delta": 453525,
      "post_rejit_run_time_ns_delta": 338949238,
      "program": "generic_kprobe_event",
      "program_id": 268,
      "ratio": 0.8898427220669822,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 186.5028209977591,
      "baseline_run_cnt_delta": 377526,
      "baseline_run_time_ns_delta": 70409664,
      "post_rejit_avg_ns_per_run": 187.82205188679245,
      "post_rejit_run_cnt_delta": 347680,
      "post_rejit_run_time_ns_delta": 65301971,
      "program": "generic_kprobe_event",
      "program_id": 286,
      "ratio": 1.0070735170759118,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 486.748130184388,
      "baseline_run_cnt_delta": 676671,
      "baseline_run_time_ns_delta": 329368344,
      "post_rejit_avg_ns_per_run": 540.0739291360487,
      "post_rejit_run_cnt_delta": 589524,
      "post_rejit_run_time_ns_delta": 318386543,
      "program": "generic_kprobe_event",
      "program_id": 296,
      "ratio": 1.1095552209547472,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 38.19771765345692,
      "baseline_run_cnt_delta": 676672,
      "baseline_run_time_ns_delta": 25847326,
      "post_rejit_avg_ns_per_run": 39.31123128359708,
      "post_rejit_run_cnt_delta": 589523,
      "post_rejit_run_time_ns_delta": 23174875,
      "program": "generic_retkprobe_event",
      "program_id": 301,
      "ratio": 1.0291513131816499,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7636.313989239047,
      "baseline_run_cnt_delta": 2602,
      "baseline_run_time_ns_delta": 19869689,
      "post_rejit_avg_ns_per_run": 6957.263221153846,
      "post_rejit_run_cnt_delta": 2496,
      "post_rejit_run_time_ns_delta": 17365329,
      "program": "generic_kprobe_event",
      "program_id": 307,
      "ratio": 0.9110761070010862,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 66.20983858570331,
      "baseline_run_cnt_delta": 2602,
      "baseline_run_time_ns_delta": 172278,
      "post_rejit_avg_ns_per_run": 62.47355769230769,
      "post_rejit_run_cnt_delta": 2496,
      "post_rejit_run_time_ns_delta": 155934,
      "program": "generic_retkprobe_event",
      "program_id": 310,
      "ratio": 0.9435690982910447,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7276.125,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 58209,
      "post_rejit_avg_ns_per_run": 6607.666666666667,
      "post_rejit_run_cnt_delta": 6,
      "post_rejit_run_time_ns_delta": 39646,
      "program": "generic_kprobe_event",
      "program_id": 319,
      "ratio": 0.908129899729137,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 477.25,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 3818,
      "post_rejit_avg_ns_per_run": 362.0,
      "post_rejit_run_cnt_delta": 6,
      "post_rejit_run_time_ns_delta": 2172,
      "program": "generic_retkprobe_event",
      "program_id": 322,
      "ratio": 0.7585123101100052,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3778.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 7557,
      "post_rejit_avg_ns_per_run": 6048.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 12096,
      "program": "generic_kprobe_event",
      "program_id": 363,
      "ratio": 1.6006351726875745,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1109.3458298898413,
      "baseline_run_cnt_delta": 5760867,
      "baseline_run_time_ns_delta": 6390793783,
      "post_rejit_avg_ns_per_run": 1043.8606558436343,
      "post_rejit_run_cnt_delta": 6112951,
      "post_rejit_run_time_ns_delta": 6381069040,
      "program": "generic_tracepoint_event",
      "program_id": 371,
      "ratio": 0.9409695585616347,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5695.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 11390,
      "post_rejit_avg_ns_per_run": 5240.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 10481,
      "program": "generic_rawtp_event",
      "program_id": 380,
      "ratio": 0.9201931518876207,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 458.2957420625154,
      "baseline_run_cnt_delta": 20315,
      "baseline_run_time_ns_delta": 9310278,
      "post_rejit_avg_ns_per_run": 498.2035438625612,
      "post_rejit_run_cnt_delta": 24098,
      "post_rejit_run_time_ns_delta": 12005709,
      "program": "generic_kprobe_event",
      "program_id": 387,
      "ratio": 1.0870787095259595,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2792.7630465444286,
      "baseline_run_cnt_delta": 709,
      "baseline_run_time_ns_delta": 1980069,
      "post_rejit_avg_ns_per_run": 3455.5909732016926,
      "post_rejit_run_cnt_delta": 709,
      "post_rejit_run_time_ns_delta": 2450014,
      "program": "generic_kprobe_event",
      "program_id": 394,
      "ratio": 1.2373376887371097,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 428.3977920166248,
      "baseline_run_cnt_delta": 115490,
      "baseline_run_time_ns_delta": 49475661,
      "post_rejit_avg_ns_per_run": 437.2789126094302,
      "post_rejit_run_cnt_delta": 117198,
      "post_rejit_run_time_ns_delta": 51248214,
      "program": "generic_kprobe_event",
      "program_id": 402,
      "ratio": 1.0207310139274965,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 47.15235951164603,
      "baseline_run_cnt_delta": 115490,
      "baseline_run_time_ns_delta": 5445626,
      "post_rejit_avg_ns_per_run": 77.93896653526511,
      "post_rejit_run_cnt_delta": 117198,
      "post_rejit_run_time_ns_delta": 9134291,
      "program": "generic_retkprobe_event",
      "program_id": 410,
      "ratio": 1.6529176342917724,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1376.4772991044363,
      "baseline_run_cnt_delta": 115458,
      "baseline_run_time_ns_delta": 158925316,
      "post_rejit_avg_ns_per_run": 1425.5577781549691,
      "post_rejit_run_cnt_delta": 117830,
      "post_rejit_run_time_ns_delta": 167973473,
      "program": "generic_kprobe_event",
      "program_id": 414,
      "ratio": 1.0356565844438304,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2511.0,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 25110,
      "post_rejit_avg_ns_per_run": 2826.7,
      "post_rejit_run_cnt_delta": 10,
      "post_rejit_run_time_ns_delta": 28267,
      "program": "generic_kprobe_event",
      "program_id": 423,
      "ratio": 1.125726802070888,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3103.3333333333335,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 9310,
      "post_rejit_avg_ns_per_run": 3442.6666666666665,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 10328,
      "program": "generic_kprobe_event",
      "program_id": 431,
      "ratio": 1.109344790547798,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6636.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 6636,
      "post_rejit_avg_ns_per_run": 5157.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 5157,
      "program": "generic_kprobe_event",
      "program_id": 440,
      "ratio": 0.777124773960217,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4111.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 4111,
      "post_rejit_avg_ns_per_run": 4480.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 4480,
      "program": "generic_retkprobe_event",
      "program_id": 442,
      "ratio": 1.089759182680613,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 9509.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 9509,
      "post_rejit_avg_ns_per_run": 8977.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 8977,
      "program": "generic_kprobe_event",
      "program_id": 447,
      "ratio": 0.9440530024187612,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3764.0,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 11292,
      "post_rejit_avg_ns_per_run": 4244.0,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 12732,
      "program": "generic_kprobe_event",
      "program_id": 452,
      "ratio": 1.1275239107332624,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1358.3585773989187,
      "baseline_run_cnt_delta": 120596,
      "baseline_run_time_ns_delta": 163812611,
      "post_rejit_avg_ns_per_run": 1243.7832915476138,
      "post_rejit_run_cnt_delta": 159943,
      "post_rejit_run_time_ns_delta": 198934431,
      "program": "generic_kprobe_event",
      "program_id": 462,
      "ratio": 0.9156516638848766,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 320.1599293130108,
      "baseline_run_cnt_delta": 36216,
      "baseline_run_time_ns_delta": 11594912,
      "post_rejit_avg_ns_per_run": 314.38949490486317,
      "post_rejit_run_cnt_delta": 36211,
      "post_rejit_run_time_ns_delta": 11384358,
      "program": "xdp_root",
      "program_id": 479,
      "ratio": 0.9819764002930358,
      "runner": "katran",
      "type": "xdp",
      "workload": "network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 149.76698042476414,
      "baseline_run_cnt_delta": 29729910,
      "baseline_run_time_ns_delta": 4452558849,
      "post_rejit_avg_ns_per_run": 152.80916095140142,
      "post_rejit_run_cnt_delta": 28688374,
      "post_rejit_run_time_ns_delta": 4383846360,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 502,
      "ratio": 1.0203127586468603,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 294.5453219425619,
      "baseline_run_cnt_delta": 29729915,
      "baseline_run_time_ns_delta": 8756807385,
      "post_rejit_avg_ns_per_run": 291.77108344113833,
      "post_rejit_run_cnt_delta": 28688379,
      "post_rejit_run_time_ns_delta": 8370439423,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 505,
      "ratio": 0.9905812847981182,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 254.19696379841042,
      "baseline_run_cnt_delta": 29729910,
      "baseline_run_time_ns_delta": 7557252856,
      "post_rejit_avg_ns_per_run": 250.97843492280182,
      "post_rejit_run_cnt_delta": 28688374,
      "post_rejit_run_time_ns_delta": 7200163207,
      "program": "trace_sys_enter",
      "program_id": 508,
      "ratio": 0.9873384448519179,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 252.45125157606404,
      "baseline_run_cnt_delta": 29729915,
      "baseline_run_time_ns_delta": 7505354251,
      "post_rejit_avg_ns_per_run": 251.65376227775016,
      "post_rejit_run_cnt_delta": 28688379,
      "post_rejit_run_time_ns_delta": 7219538509,
      "program": "trace_sys_exit",
      "program_id": 509,
      "ratio": 0.9968410166583247,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 73.51225879617924,
      "baseline_run_cnt_delta": 1059892,
      "baseline_run_time_ns_delta": 77915055,
      "post_rejit_avg_ns_per_run": 67.62128948515412,
      "post_rejit_run_cnt_delta": 1046216,
      "post_rejit_run_time_ns_delta": 70746475,
      "program": "trace_arch_prctl",
      "program_id": 514,
      "ratio": 0.919864123242921,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 278.42146369630115,
      "baseline_run_cnt_delta": 1059892,
      "baseline_run_time_ns_delta": 295096682,
      "post_rejit_avg_ns_per_run": 276.755750246603,
      "post_rejit_run_cnt_delta": 1046216,
      "post_rejit_run_time_ns_delta": 289546294,
      "program": "trace_ret_arch_prctl",
      "program_id": 515,
      "ratio": 0.9940172951194772,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 221.90639269406392,
      "baseline_run_cnt_delta": 3942,
      "baseline_run_time_ns_delta": 874755,
      "post_rejit_avg_ns_per_run": 215.6111811685582,
      "post_rejit_run_cnt_delta": 4758,
      "post_rejit_run_time_ns_delta": 1025878,
      "program": "trace_dup",
      "program_id": 516,
      "ratio": 0.9716312295059262,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 879.1050228310502,
      "baseline_run_cnt_delta": 3942,
      "baseline_run_time_ns_delta": 3465432,
      "post_rejit_avg_ns_per_run": 893.0926860025221,
      "post_rejit_run_cnt_delta": 4758,
      "post_rejit_run_time_ns_delta": 4249335,
      "program": "trace_ret_dup",
      "program_id": 517,
      "ratio": 1.0159112538413515,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 765.75,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 3063,
      "post_rejit_avg_ns_per_run": 594.25,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 2377,
      "program": "trace_dup2",
      "program_id": 518,
      "ratio": 0.7760365654587006,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2545.25,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 10181,
      "post_rejit_avg_ns_per_run": 1767.25,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 7069,
      "program": "trace_ret_dup2",
      "program_id": 519,
      "ratio": 0.694332580296631,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2321.7528116774347,
      "baseline_run_cnt_delta": 4179,
      "baseline_run_time_ns_delta": 9702605,
      "post_rejit_avg_ns_per_run": 3474.744379276637,
      "post_rejit_run_cnt_delta": 4092,
      "post_rejit_run_time_ns_delta": 14218654,
      "program": "tracepoint__sched__sched_process_fork",
      "program_id": 527,
      "ratio": 1.4966039286353578,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 10808.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 21616,
      "post_rejit_avg_ns_per_run": 11522.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 23044,
      "program": "tracepoint__sched__sched_process_exec",
      "program_id": 535,
      "ratio": 1.0660621761658031,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1363.449462890625,
      "baseline_run_cnt_delta": 4096,
      "baseline_run_time_ns_delta": 5584689,
      "post_rejit_avg_ns_per_run": 1383.5395647873393,
      "post_rejit_run_cnt_delta": 4044,
      "post_rejit_run_time_ns_delta": 5595034,
      "program": "tracepoint__sched__sched_process_exit",
      "program_id": 537,
      "ratio": 1.014734760945317,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 907.1206728425159,
      "baseline_run_cnt_delta": 4102,
      "baseline_run_time_ns_delta": 3721009,
      "post_rejit_avg_ns_per_run": 933.1275964391691,
      "post_rejit_run_cnt_delta": 4044,
      "post_rejit_run_time_ns_delta": 3773568,
      "program": "tracepoint__sched__sched_process_free",
      "program_id": 538,
      "ratio": 1.028669750756709,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 375.7010164546622,
      "baseline_run_cnt_delta": 1713800,
      "baseline_run_time_ns_delta": 643876402,
      "post_rejit_avg_ns_per_run": 382.1614920641386,
      "post_rejit_run_cnt_delta": 1767672,
      "post_rejit_run_time_ns_delta": 675536169,
      "program": "tracepoint__sched__sched_switch",
      "program_id": 540,
      "ratio": 1.0171957895414852,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 16.767294857475928,
      "baseline_run_cnt_delta": 552433,
      "baseline_run_time_ns_delta": 9262807,
      "post_rejit_avg_ns_per_run": 16.720179516018487,
      "post_rejit_run_cnt_delta": 455224,
      "post_rejit_run_time_ns_delta": 7611427,
      "program": "trace_filldir64",
      "program_id": 541,
      "ratio": 0.9971900451529047,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 949.248291015625,
      "baseline_run_cnt_delta": 4096,
      "baseline_run_time_ns_delta": 3888121,
      "post_rejit_avg_ns_per_run": 826.0724530168151,
      "post_rejit_run_cnt_delta": 4044,
      "post_rejit_run_time_ns_delta": 3340637,
      "program": "trace_do_exit",
      "program_id": 543,
      "ratio": 0.8702385464744731,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 94.49657033434912,
      "baseline_run_cnt_delta": 4388766,
      "baseline_run_time_ns_delta": 414723335,
      "post_rejit_avg_ns_per_run": 97.61409499944438,
      "post_rejit_run_cnt_delta": 4418489,
      "post_rejit_run_time_ns_delta": 431306805,
      "program": "trace_security_file_ioctl",
      "program_id": 547,
      "ratio": 1.0329908763256146,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 10134.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 20269,
      "post_rejit_avg_ns_per_run": 10655.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 21311,
      "program": "trace_security_bprm_check",
      "program_id": 552,
      "ratio": 1.0514085549361094,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 534.2702850706995,
      "baseline_run_cnt_delta": 805309,
      "baseline_run_time_ns_delta": 430252669,
      "post_rejit_avg_ns_per_run": 536.8758367288905,
      "post_rejit_run_cnt_delta": 801783,
      "post_rejit_run_time_ns_delta": 430457919,
      "program": "trace_security_file_open",
      "program_id": 553,
      "ratio": 1.0048768417989897,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2026.8032786885246,
      "baseline_run_cnt_delta": 122,
      "baseline_run_time_ns_delta": 247270,
      "post_rejit_avg_ns_per_run": 2116.0725806451615,
      "post_rejit_run_cnt_delta": 124,
      "post_rejit_run_time_ns_delta": 262393,
      "program": "trace_security_inode_unlink",
      "program_id": 555,
      "ratio": 1.0440443840284293,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 230.3472916765261,
      "baseline_run_cnt_delta": 380346,
      "baseline_run_time_ns_delta": 87611671,
      "post_rejit_avg_ns_per_run": 232.3749274462851,
      "post_rejit_run_cnt_delta": 397981,
      "post_rejit_run_time_ns_delta": 92480806,
      "program": "trace_commit_creds",
      "program_id": 556,
      "ratio": 1.008802516213676,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 538.762451171875,
      "baseline_run_cnt_delta": 4096,
      "baseline_run_time_ns_delta": 2206771,
      "post_rejit_avg_ns_per_run": 534.3677052423343,
      "post_rejit_run_cnt_delta": 4044,
      "post_rejit_run_time_ns_delta": 2160983,
      "program": "trace_switch_task_namespaces",
      "program_id": 557,
      "ratio": 0.9918428874915437,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 130.1778706425276,
      "baseline_run_cnt_delta": 2610487,
      "baseline_run_time_ns_delta": 339827639,
      "post_rejit_avg_ns_per_run": 130.9248586615252,
      "post_rejit_run_cnt_delta": 2649314,
      "post_rejit_run_time_ns_delta": 346861061,
      "program": "trace_cap_capable",
      "program_id": 558,
      "ratio": 1.0057382104601238,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 280.62648174803934,
      "baseline_run_cnt_delta": 755864,
      "baseline_run_time_ns_delta": 212115455,
      "post_rejit_avg_ns_per_run": 274.3507876756751,
      "post_rejit_run_cnt_delta": 755514,
      "post_rejit_run_time_ns_delta": 207275861,
      "program": "trace_security_socket_create",
      "program_id": 559,
      "ratio": 0.9776368429904672,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 992.5,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 3970,
      "post_rejit_avg_ns_per_run": 1345.75,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 5383,
      "program": "trace_security_socket_listen",
      "program_id": 564,
      "ratio": 1.355919395465995,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 358.22576026395245,
      "baseline_run_cnt_delta": 64254,
      "baseline_run_time_ns_delta": 23017438,
      "post_rejit_avg_ns_per_run": 324.1104643382845,
      "post_rejit_run_cnt_delta": 14946,
      "post_rejit_run_time_ns_delta": 4844155,
      "program": "trace_security_socket_connect",
      "program_id": 565,
      "ratio": 0.9047659333585315,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 481.9448227393409,
      "baseline_run_cnt_delta": 64030,
      "baseline_run_time_ns_delta": 30858927,
      "post_rejit_avg_ns_per_run": 589.2031466536235,
      "post_rejit_run_cnt_delta": 12267,
      "post_rejit_run_time_ns_delta": 7227755,
      "program": "trace_security_socket_accept",
      "program_id": 566,
      "ratio": 1.2225531198875295,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1025.5,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 4102,
      "post_rejit_avg_ns_per_run": 1580.5,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 6322,
      "program": "trace_security_socket_bind",
      "program_id": 567,
      "ratio": 1.5411994149195514,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1305.7109004739336,
      "baseline_run_cnt_delta": 211,
      "baseline_run_time_ns_delta": 275505,
      "post_rejit_avg_ns_per_run": 1071.2396694214876,
      "post_rejit_run_cnt_delta": 242,
      "post_rejit_run_time_ns_delta": 259240,
      "program": "trace_security_socket_setsockopt",
      "program_id": 568,
      "ratio": 0.8204263815463745,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 59.86693938453219,
      "baseline_run_cnt_delta": 998590,
      "baseline_run_time_ns_delta": 59782527,
      "post_rejit_avg_ns_per_run": 63.19148597297094,
      "post_rejit_run_cnt_delta": 1023417,
      "post_rejit_run_time_ns_delta": 64671241,
      "program": "trace_vfs_write",
      "program_id": 571,
      "ratio": 1.055532262424254,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 73.95357454010154,
      "baseline_run_cnt_delta": 998590,
      "baseline_run_time_ns_delta": 73849300,
      "post_rejit_avg_ns_per_run": 81.80284087522486,
      "post_rejit_run_cnt_delta": 1023417,
      "post_rejit_run_time_ns_delta": 83718418,
      "program": "vfs_write_magic_enter",
      "program_id": 572,
      "ratio": 1.1061377544484619,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 610.9193643036682,
      "baseline_run_cnt_delta": 998590,
      "baseline_run_time_ns_delta": 610057968,
      "post_rejit_avg_ns_per_run": 668.178880163218,
      "post_rejit_run_cnt_delta": 1023417,
      "post_rejit_run_time_ns_delta": 683825625,
      "program": "trace_ret_vfs_write",
      "program_id": 573,
      "ratio": 1.0937267980117387,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 33.56837941497511,
      "baseline_run_cnt_delta": 998590,
      "baseline_run_time_ns_delta": 33521048,
      "post_rejit_avg_ns_per_run": 38.46015065217795,
      "post_rejit_run_cnt_delta": 1023417,
      "post_rejit_run_time_ns_delta": 39360772,
      "program": "vfs_write_magic_return",
      "program_id": 574,
      "ratio": 1.1457255703866533,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 413.2037037037037,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 22313,
      "post_rejit_avg_ns_per_run": 435.3272727272727,
      "post_rejit_run_cnt_delta": 55,
      "post_rejit_run_time_ns_delta": 23943,
      "program": "trace_vfs_writev",
      "program_id": 576,
      "ratio": 1.0535415554731649,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 666.7407407407408,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 36004,
      "post_rejit_avg_ns_per_run": 647.6363636363636,
      "post_rejit_run_cnt_delta": 55,
      "post_rejit_run_time_ns_delta": 35620,
      "program": "vfs_writev_magic_enter",
      "program_id": 577,
      "ratio": 0.9713466180525395,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4784.2962962962965,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 258352,
      "post_rejit_avg_ns_per_run": 5025.945454545455,
      "post_rejit_run_cnt_delta": 55,
      "post_rejit_run_time_ns_delta": 276427,
      "program": "trace_ret_vfs_writev",
      "program_id": 578,
      "ratio": 1.0505088195386703,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3406.240740740741,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 183937,
      "post_rejit_avg_ns_per_run": 4030.3454545454547,
      "post_rejit_run_cnt_delta": 55,
      "post_rejit_run_time_ns_delta": 221669,
      "program": "vfs_writev_magic_return",
      "program_id": 579,
      "ratio": 1.183223900278109,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 52.27014659667113,
      "baseline_run_cnt_delta": 1340276,
      "baseline_run_time_ns_delta": 70056423,
      "post_rejit_avg_ns_per_run": 59.34982602602085,
      "post_rejit_run_cnt_delta": 1315714,
      "post_rejit_run_time_ns_delta": 78087397,
      "program": "trace_vfs_read",
      "program_id": 586,
      "ratio": 1.1354440324030122,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 553.8892519152771,
      "baseline_run_cnt_delta": 1340276,
      "baseline_run_time_ns_delta": 742364471,
      "post_rejit_avg_ns_per_run": 585.7562152565071,
      "post_rejit_run_cnt_delta": 1315714,
      "post_rejit_run_time_ns_delta": 770687653,
      "program": "trace_ret_vfs_read",
      "program_id": 587,
      "ratio": 1.057533095706476,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 450.01851851851853,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 24301,
      "post_rejit_avg_ns_per_run": 463.92727272727274,
      "post_rejit_run_cnt_delta": 55,
      "post_rejit_run_time_ns_delta": 25516,
      "program": "trace_vfs_readv",
      "program_id": 589,
      "ratio": 1.030907070790203,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2634.296296296296,
      "baseline_run_cnt_delta": 54,
      "baseline_run_time_ns_delta": 142252,
      "post_rejit_avg_ns_per_run": 2928.5454545454545,
      "post_rejit_run_cnt_delta": 55,
      "post_rejit_run_time_ns_delta": 161070,
      "program": "trace_ret_vfs_readv",
      "program_id": 590,
      "ratio": 1.1116993402233681,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 158.87128580946035,
      "baseline_run_cnt_delta": 7505,
      "baseline_run_time_ns_delta": 1192329,
      "post_rejit_avg_ns_per_run": 160.6126582278481,
      "post_rejit_run_cnt_delta": 7505,
      "post_rejit_run_time_ns_delta": 1205398,
      "program": "trace_mmap_alert",
      "program_id": 592,
      "ratio": 1.0109609008922873,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 90.50607395541316,
      "baseline_run_cnt_delta": 7491,
      "baseline_run_time_ns_delta": 677981,
      "post_rejit_avg_ns_per_run": 89.83073020958483,
      "post_rejit_run_cnt_delta": 7491,
      "post_rejit_run_time_ns_delta": 672922,
      "program": "trace_do_mmap",
      "program_id": 593,
      "ratio": 0.992538138974396,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 430.31731411026567,
      "baseline_run_cnt_delta": 7491,
      "baseline_run_time_ns_delta": 3223507,
      "post_rejit_avg_ns_per_run": 432.7364837805366,
      "post_rejit_run_cnt_delta": 7491,
      "post_rejit_run_time_ns_delta": 3241629,
      "program": "trace_ret_do_mmap",
      "program_id": 594,
      "ratio": 1.0056218274072306,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 154.10560747663553,
      "baseline_run_cnt_delta": 7490,
      "baseline_run_time_ns_delta": 1154251,
      "post_rejit_avg_ns_per_run": 161.24032042723633,
      "post_rejit_run_cnt_delta": 7490,
      "post_rejit_run_time_ns_delta": 1207690,
      "program": "trace_security_mmap_file",
      "program_id": 595,
      "ratio": 1.046297555730946,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 923.0512820512821,
      "baseline_run_cnt_delta": 39,
      "baseline_run_time_ns_delta": 35999,
      "post_rejit_avg_ns_per_run": 846.6153846153846,
      "post_rejit_run_cnt_delta": 39,
      "post_rejit_run_time_ns_delta": 33018,
      "program": "trace_security_file_mprotect",
      "program_id": 596,
      "ratio": 0.9171921442262285,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 248.50988286969255,
      "baseline_run_cnt_delta": 8196,
      "baseline_run_time_ns_delta": 2036787,
      "post_rejit_avg_ns_per_run": 242.38299170326988,
      "post_rejit_run_cnt_delta": 8196,
      "post_rejit_run_time_ns_delta": 1986571,
      "program": "trace_security_bpf",
      "program_id": 598,
      "ratio": 0.9753454828609962,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 236.59125766871165,
      "baseline_run_cnt_delta": 2608,
      "baseline_run_time_ns_delta": 617030,
      "post_rejit_avg_ns_per_run": 234.85237730061348,
      "post_rejit_run_cnt_delta": 2608,
      "post_rejit_run_time_ns_delta": 612495,
      "program": "trace_security_bpf_map",
      "program_id": 601,
      "ratio": 0.9926502763236795,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 645.4285714285714,
      "baseline_run_cnt_delta": 161,
      "baseline_run_time_ns_delta": 103914,
      "post_rejit_avg_ns_per_run": 654.3664596273292,
      "post_rejit_run_cnt_delta": 161,
      "post_rejit_run_time_ns_delta": 105353,
      "program": "trace_security_bpf_prog",
      "program_id": 602,
      "ratio": 1.0138479896837769,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1458.5,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 5834,
      "post_rejit_avg_ns_per_run": 1342.0,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 5368,
      "program": "trace_security_inode_mknod",
      "program_id": 608,
      "ratio": 0.920123414466918,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3145.5,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 12582,
      "post_rejit_avg_ns_per_run": 3679.5,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 14718,
      "program": "trace_load_elf_phdrs",
      "program_id": 616,
      "ratio": 1.1697663328564616,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 49.94760221422938,
      "baseline_run_cnt_delta": 3497018,
      "baseline_run_time_ns_delta": 174667664,
      "post_rejit_avg_ns_per_run": 49.881890551594594,
      "post_rejit_run_cnt_delta": 3538142,
      "post_rejit_run_time_ns_delta": 176489212,
      "program": "trace_security_file_permission",
      "program_id": 617,
      "ratio": 0.998684388044236,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1012.5691387559808,
      "baseline_run_cnt_delta": 4180,
      "baseline_run_time_ns_delta": 4232539,
      "post_rejit_avg_ns_per_run": 930.0796996124031,
      "post_rejit_run_cnt_delta": 4128,
      "post_rejit_run_time_ns_delta": 3839369,
      "program": "tracepoint__task__task_rename",
      "program_id": 618,
      "ratio": 0.918534511880421,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 950.8021964759836,
      "baseline_run_cnt_delta": 8286,
      "baseline_run_time_ns_delta": 7878347,
      "post_rejit_avg_ns_per_run": 950.3660474211684,
      "post_rejit_run_cnt_delta": 8182,
      "post_rejit_run_time_ns_delta": 7775895,
      "program": "trace_do_sigaction",
      "program_id": 622,
      "ratio": 0.9995412830802961,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2759.31541218638,
      "baseline_run_cnt_delta": 279,
      "baseline_run_time_ns_delta": 769849,
      "post_rejit_avg_ns_per_run": 2768.6408450704225,
      "post_rejit_run_cnt_delta": 284,
      "post_rejit_run_time_ns_delta": 786294,
      "program": "trace_do_truncate",
      "program_id": 625,
      "ratio": 1.0033796183078083,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 147.67961658774632,
      "baseline_run_cnt_delta": 1976254,
      "baseline_run_time_ns_delta": 291852433,
      "post_rejit_avg_ns_per_run": 145.58296100165305,
      "post_rejit_run_cnt_delta": 1938236,
      "post_rejit_run_time_ns_delta": 282174136,
      "program": "trace_fd_install",
      "program_id": 626,
      "ratio": 0.9858026745021544,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 287.31919511816585,
      "baseline_run_cnt_delta": 444587,
      "baseline_run_time_ns_delta": 127738379,
      "post_rejit_avg_ns_per_run": 279.9061140759478,
      "post_rejit_run_cnt_delta": 453838,
      "post_rejit_run_time_ns_delta": 127032031,
      "program": "trace_filp_close",
      "program_id": 627,
      "ratio": 0.9741991444770363,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 185.53683259244787,
      "baseline_run_cnt_delta": 40942,
      "baseline_run_time_ns_delta": 7596249,
      "post_rejit_avg_ns_per_run": 186.66049808958246,
      "post_rejit_run_cnt_delta": 43446,
      "post_rejit_run_time_ns_delta": 8109652,
      "program": "trace_file_update_time",
      "program_id": 628,
      "ratio": 1.0060562934131945,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 611.354257241952,
      "baseline_run_cnt_delta": 40942,
      "baseline_run_time_ns_delta": 25030066,
      "post_rejit_avg_ns_per_run": 643.0117387101229,
      "post_rejit_run_cnt_delta": 43446,
      "post_rejit_run_time_ns_delta": 27936288,
      "program": "trace_ret_file_update_time",
      "program_id": 629,
      "ratio": 1.051782548486682,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 117.79657943137799,
      "baseline_run_cnt_delta": 389292,
      "baseline_run_time_ns_delta": 45857266,
      "post_rejit_avg_ns_per_run": 121.76515478976316,
      "post_rejit_run_cnt_delta": 402546,
      "post_rejit_run_time_ns_delta": 49016076,
      "program": "trace_file_modified",
      "program_id": 630,
      "ratio": 1.0336900729846494,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 491.11117104898125,
      "baseline_run_cnt_delta": 389292,
      "baseline_run_time_ns_delta": 191185650,
      "post_rejit_avg_ns_per_run": 491.6928077784899,
      "post_rejit_run_cnt_delta": 402546,
      "post_rejit_run_time_ns_delta": 197928973,
      "program": "trace_ret_file_modified",
      "program_id": 631,
      "ratio": 1.0011843280377155,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 167.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 334,
      "post_rejit_avg_ns_per_run": 426.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 853,
      "program": "trace_exec_binprm",
      "program_id": 635,
      "ratio": 2.553892215568862,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 6882.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 13765,
      "post_rejit_avg_ns_per_run": 8286.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 16572,
      "program": "trace_security_bprm_creds_for_exec",
      "program_id": 636,
      "ratio": 1.203922993098438,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 9414.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 18829,
      "post_rejit_avg_ns_per_run": 9956.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 19913,
      "program": "trace_execute_finished",
      "program_id": 637,
      "ratio": 1.057570768495406,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3973.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 7946,
      "post_rejit_avg_ns_per_run": 2963.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 5926,
      "program": "trace_set_fs_pwd",
      "program_id": 639,
      "ratio": 0.7457840422854266,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 270.83887954244983,
      "baseline_run_cnt_delta": 621746,
      "baseline_run_time_ns_delta": 168392990,
      "post_rejit_avg_ns_per_run": 261.524738925255,
      "post_rejit_run_cnt_delta": 656900,
      "post_rejit_run_time_ns_delta": 171795601,
      "program": "trace_security_task_setrlimit",
      "program_id": 640,
      "ratio": 0.965610031200358,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 348.49135681318205,
      "baseline_run_cnt_delta": 370928,
      "baseline_run_time_ns_delta": 129265202,
      "post_rejit_avg_ns_per_run": 350.8770538367418,
      "post_rejit_run_cnt_delta": 366144,
      "post_rejit_run_time_ns_delta": 128471528,
      "program": "trace_security_task_prctl",
      "program_id": 643,
      "ratio": 1.006845785345657,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 26.248126582525504,
      "baseline_run_cnt_delta": 819892,
      "baseline_run_time_ns_delta": 21520629,
      "post_rejit_avg_ns_per_run": 24.304609790056773,
      "post_rejit_run_cnt_delta": 767779,
      "post_rejit_run_time_ns_delta": 18660569,
      "program": "trace_sock_alloc_file",
      "program_id": 646,
      "ratio": 0.9259559806541541,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 98.45175340166753,
      "baseline_run_cnt_delta": 819892,
      "baseline_run_time_ns_delta": 80719805,
      "post_rejit_avg_ns_per_run": 97.19739143685878,
      "post_rejit_run_cnt_delta": 767779,
      "post_rejit_run_time_ns_delta": 74626116,
      "program": "trace_ret_sock_alloc_file",
      "program_id": 647,
      "ratio": 0.987259120112456,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 949.5,
      "baseline_run_cnt_delta": 4,
      "baseline_run_time_ns_delta": 3798,
      "post_rejit_avg_ns_per_run": 597.6,
      "post_rejit_run_cnt_delta": 5,
      "post_rejit_run_time_ns_delta": 2988,
      "program": "trace_security_sk_clone",
      "program_id": 648,
      "ratio": 0.6293838862559242,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 201.2607247761112,
      "baseline_run_cnt_delta": 1893909,
      "baseline_run_time_ns_delta": 381169498,
      "post_rejit_avg_ns_per_run": 203.54440543835787,
      "post_rejit_run_cnt_delta": 1888879,
      "post_rejit_run_time_ns_delta": 384470753,
      "program": "trace_security_socket_recvmsg",
      "program_id": 649,
      "ratio": 1.0113468768672433,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 194.9141634827794,
      "baseline_run_cnt_delta": 4492412,
      "baseline_run_time_ns_delta": 875634727,
      "post_rejit_avg_ns_per_run": 191.86343087978273,
      "post_rejit_run_cnt_delta": 4644249,
      "post_rejit_run_time_ns_delta": 891061547,
      "program": "trace_security_socket_sendmsg",
      "program_id": 650,
      "ratio": 0.9843483277536873,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 189.13536614608464,
      "baseline_run_cnt_delta": 3081871,
      "baseline_run_time_ns_delta": 582890800,
      "post_rejit_avg_ns_per_run": 186.56751961800168,
      "post_rejit_run_cnt_delta": 3306402,
      "post_rejit_run_time_ns_delta": 616867220,
      "program": "cgroup_bpf_run_filter_skb",
      "program_id": 651,
      "ratio": 0.9864232344251281,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 300.32897267627203,
      "baseline_run_cnt_delta": 487159,
      "baseline_run_time_ns_delta": 146307962,
      "post_rejit_avg_ns_per_run": 299.7602896731521,
      "post_rejit_run_cnt_delta": 517825,
      "post_rejit_run_time_ns_delta": 155223372,
      "program": "cgroup_skb_ingress",
      "program_id": 653,
      "ratio": 0.9981064663923287,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 191.59181272044447,
      "baseline_run_cnt_delta": 2346396,
      "baseline_run_time_ns_delta": 449550263,
      "post_rejit_avg_ns_per_run": 183.80737686514007,
      "post_rejit_run_cnt_delta": 2583184,
      "post_rejit_run_time_ns_delta": 474808275,
      "program": "cgroup_skb_egress",
      "program_id": 654,
      "ratio": 0.9593696842011572,
      "runner": "tracee",
      "type": "cgroup_skb",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 100.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 200,
      "post_rejit_avg_ns_per_run": 192.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 385,
      "program": "empty_kprobe",
      "program_id": 657,
      "ratio": 1.925,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1497.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 2994,
      "post_rejit_avg_ns_per_run": 1943.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 3887,
      "program": "tracepoint__exec_test",
      "program_id": 658,
      "ratio": 1.2982631930527722,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 255.83823476454378,
      "baseline_run_cnt_delta": 805309,
      "baseline_run_time_ns_delta": 206028833,
      "post_rejit_avg_ns_per_run": 254.81604997861018,
      "post_rejit_run_cnt_delta": 801783,
      "post_rejit_run_time_ns_delta": 204307177,
      "program": "lsm_file_open_test",
      "program_id": 659,
      "ratio": 0.996004565983367,
      "runner": "tracee",
      "type": "lsm",
      "workload": "stress_ng_os_io_network"
    }
  ],
  "results": [
    {
      "app": "bcc/capable",
      "baseline": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 328.60978852348626,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 1098940,
            "run_time_ns_delta": 361122441,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0136478259999961,
            "ops_per_sec": 1504461.3729581519,
            "ops_total": 1524994.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5986] setting to a 1 secs run per stressor\nstress-ng: info:  [5986] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [5986] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5986] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5986]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5986] cap             1295882      1.00      0.26      0.74   1295889.11     1297240.21\nstress-ng: metrc: [5986] eventfd          154406      1.00      0.08      0.63    154367.94      217533.90\nstress-ng: metrc: [5986] get                1025      1.00      0.01      0.11      1024.69        8450.19\nstress-ng: metrc: [5986] prctl              4007      1.00      0.62      0.37      4006.29        4053.83\nstress-ng: metrc: [5986] set               69674      1.00      0.10      0.87     69674.93       72085.25\nstress-ng: info:  [5986] skipped: 0\nstress-ng: info:  [5986] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [5986] failed: 0\nstress-ng: info:  [5986] metrics untrustworthy: 0\nstress-ng: info:  [5986] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 318.6086652551018,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 1102795,
            "run_time_ns_delta": 351360043,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0119467449999888,
            "ops_per_sec": 1388793.4389274758,
            "ops_total": 1405385.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [14014] setting to a 1 secs run per stressor\nstress-ng: info:  [14014] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [14014] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [14014] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [14014]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [14014] cap             1172483      1.00      0.24      0.76   1172489.43     1174318.46\nstress-ng: metrc: [14014] eventfd          157146      1.00      0.07      0.64    157086.30      222952.09\nstress-ng: metrc: [14014] get                 970      1.00      0.00      0.12       969.82        7765.53\nstress-ng: metrc: [14014] prctl              3898      1.00      0.63      0.36      3897.76        3948.55\nstress-ng: metrc: [14014] set               70888      1.00      0.08      0.90     70887.86       72300.39\nstress-ng: info:  [14014] skipped: 0\nstress-ng: info:  [14014] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [14014] failed: 0\nstress-ng: info:  [14014] metrics untrustworthy: 0\nstress-ng: info:  [14014] successful run completed in 1.00 secs"
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
      "app": "bcc/execsnoop",
      "baseline": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 834.0,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1668,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 110.0,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 220,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0174277699999976,
            "ops_per_sec": 23274020.719918087,
            "ops_total": 23679635.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [7690] setting to a 1 secs run per stressor\nstress-ng: info:  [7690] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [7690] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7690] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7690]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7690] clone               903      1.01      0.20      0.84       897.04         869.37\nstress-ng: metrc: [7690] fork               2508      1.00      0.21      0.30      2507.80        4901.95\nstress-ng: metrc: [7690] futex            274118      2.00      0.16      1.08    137048.85      221304.73\nstress-ng: metrc: [7690] sem              755493      1.00      0.14      0.32    755459.86     1635924.85\nstress-ng: metrc: [7690] sem-sysv        2524149      1.00      0.22      0.72   2523328.41     2707294.78\nstress-ng: metrc: [7690] switch           454946      1.00      0.13      0.75    454854.25      517037.56\nstress-ng: metrc: [7690] vfork             15809      1.00      0.14      0.15     15804.95       55877.99\nstress-ng: metrc: [7690] yield          19651709      1.00      4.12      6.25  19576977.42     1894720.09\nstress-ng: info:  [7690] skipped: 0\nstress-ng: info:  [7690] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [7690] failed: 0\nstress-ng: info:  [7690] metrics untrustworthy: 0\nstress-ng: info:  [7690] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 809.5,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1619,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 204.0,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 408,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.017748056000002,
            "ops_per_sec": 23231519.68761899,
            "ops_total": 23643834.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23646] setting to a 1 secs run per stressor\nstress-ng: info:  [23646] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [23646] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23646] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23646]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23646] clone               636      1.01      0.14      0.63       632.26         826.98\nstress-ng: metrc: [23646] fork               3621      1.00      0.28      0.44      3620.82        5048.08\nstress-ng: metrc: [23646] futex            426744      2.00      0.06      1.21    213347.97      336920.62\nstress-ng: metrc: [23646] sem             1357115      1.00      0.16      0.46   1357084.59     2192523.43\nstress-ng: metrc: [23646] sem-sysv        2360261      1.00      0.25      0.65   2355847.34     2599163.07\nstress-ng: metrc: [23646] switch           819333      1.00      0.18      0.77    817638.97      862882.69\nstress-ng: metrc: [23646] vfork             27806      1.00      0.25      0.32     27805.65       48642.16\nstress-ng: metrc: [23646] yield          18648318      1.01      3.65      6.51  18553513.50     1835770.45\nstress-ng: info:  [23646] skipped: 0\nstress-ng: info:  [23646] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [23646] failed: 0\nstress-ng: info:  [23646] metrics untrustworthy: 0\nstress-ng: info:  [23646] successful run completed in 1.01 secs"
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
      "selected_workload": "stress_ng_process",
      "status": "ok"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 1807.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3614,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 4745.0,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 9490,
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
            "duration_s": 1.0592407959999974,
            "ops_per_sec": 36767777.588506036,
            "ops_total": 38945930.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23511] setting to a 1 secs run per stressor\nstress-ng: info:  [23511] dispatching hogs: 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [23511] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23511] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23511]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23511] epoll            202645      1.01      0.11      1.66    200782.75      114882.03\nstress-ng: metrc: [23511] netdev          2159466      1.00      0.26      0.74   2159446.95     2159014.77\nstress-ng: metrc: [23511] sctp              16162      1.00      0.03      0.45     16153.89       33745.28\nstress-ng: metrc: [23511] sock               5070      1.00      0.08      1.88      5066.57        2591.44\nstress-ng: metrc: [23511] sockdiag       34596352      1.00      0.05      0.95  34589482.44    34673431.04\nstress-ng: metrc: [23511] sockfd           544946      1.00      0.18      1.42    544677.32      339477.97\nstress-ng: metrc: [23511] sockpair         335970      1.05      0.06      1.38    321387.62      233248.36\nstress-ng: metrc: [23511] udp-flood       1085319      1.00      0.05      0.91   1085312.79     1127519.81\nstress-ng: info:  [23511] skipped: 0\nstress-ng: info:  [23511] passed: 8: epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [23511] failed: 0\nstress-ng: info:  [23511] metrics untrustworthy: 0\nstress-ng: info:  [23511] successful run completed in 1.05 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 2731.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5462,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 11309.0,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 22618,
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
            "duration_s": 1.0569232500000112,
            "ops_per_sec": 34753819.63638288,
            "ops_total": 36732120.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [23563] setting to a 1 secs run per stressor\nstress-ng: info:  [23563] dispatching hogs: 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [23563] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [23563] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [23563]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [23563] epoll            208365      1.01      0.11      1.65    206059.11      118583.45\nstress-ng: metrc: [23563] netdev          2166338      1.00      0.21      0.79   2166429.42     2164855.07\nstress-ng: metrc: [23563] sctp                286      1.00      0.00      0.00       285.40       62719.30\nstress-ng: metrc: [23563] sock               4860      1.00      0.04      1.89      4852.74        2524.16\nstress-ng: metrc: [23563] sockdiag       32363876      1.00      0.05      0.95  32362548.88    32443817.57\nstress-ng: metrc: [23563] sockfd           573087      1.00      0.12      1.51    572876.66      350636.95\nstress-ng: metrc: [23563] sockpair         355384      1.04      0.11      1.36    340257.43      242493.55\nstress-ng: metrc: [23563] udp-flood       1059924      1.00      0.06      0.91   1059792.86     1097722.99\nstress-ng: info:  [23563] skipped: 0\nstress-ng: info:  [23563] passed: 8: epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [23563] failed: 0\nstress-ng: info:  [23563] metrics untrustworthy: 0\nstress-ng: info:  [23563] successful run completed in 1.05 secs"
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
      "selected_workload": "stress_ng_network",
      "status": "ok"
    },
    {
      "app": "bcc/biosnoop",
      "baseline": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 214.32101549644932,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1751498,
            "run_time_ns_delta": 375382830,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 194.2467216821162,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1751508,
            "run_time_ns_delta": 340224687,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 94.76248820305645,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1751513,
            "run_time_ns_delta": 165977730,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.329452997999994,
            "ops_per_sec": 440383.2815264098,
            "ops_total": 2347002.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.259334,\n        \"1000\" : 17.699642\n      },\n      \"latency_us\" : {\n        \"2\" : 29.857888,\n        \"4\" : 1.582841,\n        \"10\" : 19.520276,\n        \"20\" : 27.769715,\n        \"50\" : 2.814034,\n        \"100\" : 0.350964,\n        \"250\" : 0.138984,\n        \"500\" : 0.010000,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 212.04397881729713,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1703843,
            "run_time_ns_delta": 361289649,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 193.42022345824435,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1703853,
            "run_time_ns_delta": 329559628,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 94.27904672807242,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1703858,
            "run_time_ns_delta": 160638108,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.344795330000011,
            "ops_per_sec": 427436.0118481834,
            "ops_total": 2284558.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.236945,\n        \"1000\" : 17.611092\n      },\n      \"latency_us\" : {\n        \"2\" : 29.991723,\n        \"4\" : 1.540491,\n        \"10\" : 16.943131,\n        \"20\" : 29.750753,\n        \"50\" : 3.135057,\n        \"100\" : 0.608812,\n        \"250\" : 0.172721,\n        \"500\" : 0.010000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
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
          "23": {
            "avg_ns_per_run": 62.77591283259897,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 146385,
            "run_time_ns_delta": 9189452,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 70.12316715542522,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 682,
            "run_time_ns_delta": 47824,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 46.94345574816848,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 1361164,
            "run_time_ns_delta": 63897742,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 44.02140917079406,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 62590,
            "run_time_ns_delta": 2755300,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 52.18107911815008,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 85366,
            "run_time_ns_delta": 4454490,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1128918029999966,
            "ops_per_sec": 2747016.369209442,
            "ops_total": 3057132.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [4067] setting to a 1 secs run per stressor\nstress-ng: info:  [4067] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [4067] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [4084] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [4072] dentry: 75688 dentries allocated\nstress-ng: metrc: [4067] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4067]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4067] access            11118      1.01      0.28      1.51     10998.29        6231.71\nstress-ng: metrc: [4067] chdir                51      1.09      0.11      0.81        46.94          55.38\nstress-ng: metrc: [4067] chmod               149      1.01      0.00      0.04       147.39        4235.48\nstress-ng: metrc: [4067] chown               160      1.01      0.00      0.00       158.12       32733.22\nstress-ng: metrc: [4067] dentry            16384      1.03      0.02      0.53     15903.09       29774.10\nstress-ng: metrc: [4067] dir                8193      1.08      0.08      0.93      7594.73        8095.51\nstress-ng: metrc: [4067] dirmany           11263      1.01      0.00      0.27     11147.01       42086.11\nstress-ng: metrc: [4067] fallocate             2      1.01      0.00      0.00         1.98         434.78\nstress-ng: metrc: [4067] file-ioctl        70171      1.00      0.10      0.65     70167.30       93505.11\nstress-ng: metrc: [4067] filename           4007      1.01      0.05      0.72      3969.38        5150.33\nstress-ng: metrc: [4067] flock           2550971      1.01      0.46      0.60   2526063.32     2409852.45\nstress-ng: metrc: [4067] fpunch             1610      1.01      0.02      0.24      1593.48        6371.77\nstress-ng: metrc: [4067] fstat              2286      1.00      0.19      0.45      2284.48        3541.92\nstress-ng: metrc: [4067] getdent          215403      1.00      0.07      0.91    215393.81      220209.51\nstress-ng: metrc: [4067] hdd               29597      1.01      0.41      0.26     29177.02       43764.48\nstress-ng: metrc: [4067] inotify               2      1.05      0.01      0.00         1.90         283.13\nstress-ng: metrc: [4067] open              19383      1.02      0.02      0.26     19037.33       69153.38\nstress-ng: metrc: [4067] rename              489      1.01      0.00      0.01       484.95       32604.35\nstress-ng: metrc: [4067] touch             69703      1.02      0.07      1.69     68651.81       39451.15\nstress-ng: metrc: [4067] utime             46190      1.01      0.04      0.75     45791.18       58883.22\nstress-ng: info:  [4067] skipped: 0\nstress-ng: info:  [4067] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [4067] failed: 0\nstress-ng: info:  [4067] metrics untrustworthy: 0\nstress-ng: info:  [4067] successful run completed in 1.10 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "23": {
            "avg_ns_per_run": 69.88205654370788,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 142297,
            "run_time_ns_delta": 9944007,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 84.02051282051282,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 585,
            "run_time_ns_delta": 49152,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 44.61829639077238,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 1427757,
            "run_time_ns_delta": 63704085,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 85.93267040898155,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 62350,
            "run_time_ns_delta": 5357902,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 53.16791644751672,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 66545,
            "run_time_ns_delta": 3538059,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.127229935999992,
            "ops_per_sec": 2425139.638945873,
            "ops_total": 2733690.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [22219] setting to a 1 secs run per stressor\nstress-ng: info:  [22219] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [22219] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [22236] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [22224] dentry: 102620 dentries allocated\nstress-ng: metrc: [22219] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [22219]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [22219] access            10496      1.01      0.15      1.64     10413.30        5865.66\nstress-ng: metrc: [22219] chdir                45      1.08      0.09      0.78        41.64          51.57\nstress-ng: metrc: [22219] chmod               124      1.02      0.00      0.03       121.91        3665.93\nstress-ng: metrc: [22219] chown               141      1.01      0.00      0.00       139.92       28565.64\nstress-ng: metrc: [22219] dentry            12288      1.02      0.04      0.37     12000.55       29911.20\nstress-ng: metrc: [22219] dir                8192      1.10      0.05      0.86      7441.80        8998.27\nstress-ng: metrc: [22219] dirmany           11775      1.02      0.02      0.24     11566.26       44180.22\nstress-ng: metrc: [22219] fallocate             1      1.02      0.01      0.00         0.98         128.72\nstress-ng: metrc: [22219] file-ioctl        75265      1.01      0.07      0.73     74730.15       94300.03\nstress-ng: metrc: [22219] filename           4201      1.02      0.02      0.75      4132.28        5477.54\nstress-ng: metrc: [22219] flock           2238194      1.02      0.40      0.59   2200801.45     2254743.82\nstress-ng: metrc: [22219] fpunch             1074      1.02      0.00      0.30      1056.46        3620.16\nstress-ng: metrc: [22219] fstat              2338      1.00      0.10      0.59      2337.73        3383.13\nstress-ng: metrc: [22219] getdent          206743      1.00      0.03      0.92    206739.30      216786.96\nstress-ng: metrc: [22219] hdd               27905      1.02      0.26      0.40     27451.24       42277.48\nstress-ng: metrc: [22219] inotify               2      1.02      0.00      0.00         1.96         475.74\nstress-ng: metrc: [22219] open              17408      1.02      0.00      0.23     17096.84       76071.95\nstress-ng: metrc: [22219] rename              393      1.01      0.02      0.00       390.27       24766.83\nstress-ng: metrc: [22219] touch             68179      1.02      0.04      1.78     67097.50       37512.72\nstress-ng: metrc: [22219] utime             48926      1.01      0.11      0.68     48603.09       62077.80\nstress-ng: info:  [22219] skipped: 0\nstress-ng: info:  [22219] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [22219] failed: 0\nstress-ng: info:  [22219] metrics untrustworthy: 0\nstress-ng: info:  [22219] successful run completed in 1.11 secs"
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
          "30": {
            "avg_ns_per_run": 385.3668746226605,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 14907,
            "run_time_ns_delta": 5744664,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 388.6312563824044,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 614972,
            "run_time_ns_delta": 238997341,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 406.1200139958013,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 2858,
            "run_time_ns_delta": 1160691,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1124775579999948,
            "ops_per_sec": 2776230.385763894,
            "ops_total": 3088494.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [5395] setting to a 1 secs run per stressor\nstress-ng: info:  [5395] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [5395] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [5413] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [5400] dentry: 99951 dentries allocated\nstress-ng: metrc: [5395] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5395]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5395] access             9312      1.01      0.19      1.36      9199.16        5990.10\nstress-ng: metrc: [5395] chdir                49      1.07      0.10      0.79        45.64          54.79\nstress-ng: metrc: [5395] chmod               124      1.00      0.00      0.02       123.95        5050.30\nstress-ng: metrc: [5395] chown               151      1.00      0.00      0.00       150.95       30873.03\nstress-ng: metrc: [5395] dentry            14336      1.02      0.02      0.47     13992.91       29637.84\nstress-ng: metrc: [5395] dir                8192      1.09      0.03      0.92      7525.31        8628.93\nstress-ng: metrc: [5395] dirmany           10003      1.01      0.01      0.21      9896.73       44970.44\nstress-ng: metrc: [5395] fallocate             1      1.01      0.01      0.00         0.99         117.86\nstress-ng: metrc: [5395] file-ioctl        70727      1.00      0.10      0.60     70718.37      100292.11\nstress-ng: metrc: [5395] filename           3546      1.01      0.00      0.66      3511.67        5354.91\nstress-ng: metrc: [5395] flock           2618846      1.01      0.41      0.65   2594238.40     2479972.50\nstress-ng: metrc: [5395] fpunch             1547      1.01      0.01      0.24      1532.16        6314.11\nstress-ng: metrc: [5395] fstat              1986      1.00      0.12      0.55      1985.97        2962.21\nstress-ng: metrc: [5395] getdent          204873      1.00      0.03      0.96    204635.89      206265.08\nstress-ng: metrc: [5395] hdd               28919      1.01      0.31      0.30     28657.45       47764.08\nstress-ng: metrc: [5395] inotify               2      1.01      0.00      0.00         1.98         445.83\nstress-ng: metrc: [5395] open              16384      1.01      0.01      0.24     16224.21       65683.66\nstress-ng: metrc: [5395] rename              420      1.01      0.00      0.02       415.58       23923.44\nstress-ng: metrc: [5395] touch             51202      1.01      0.04      1.13     50553.27       43789.30\nstress-ng: metrc: [5395] utime             47874      1.00      0.03      0.75     47845.88       61639.13\nstress-ng: info:  [5395] skipped: 0\nstress-ng: info:  [5395] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [5395] failed: 0\nstress-ng: info:  [5395] metrics untrustworthy: 0\nstress-ng: info:  [5395] successful run completed in 1.10 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 367.2263266454153,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 15999,
            "run_time_ns_delta": 5875254,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 375.9022230020059,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 592757,
            "run_time_ns_delta": 222818674,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 373.2580095432856,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 2934,
            "run_time_ns_delta": 1095139,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1128634189999786,
            "ops_per_sec": 2666214.87357925,
            "ops_total": 2967133.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [19409] setting to a 1 secs run per stressor\nstress-ng: info:  [19409] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [19409] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [19428] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [19414] dentry: 83480 dentries allocated\nstress-ng: metrc: [19409] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19409]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19409] access             9973      1.01      0.23      1.48      9879.35        5813.32\nstress-ng: metrc: [19409] chdir                46      1.07      0.08      0.76        42.84          54.97\nstress-ng: metrc: [19409] chmod               152      1.01      0.00      0.03       150.67        5222.29\nstress-ng: metrc: [19409] chown               174      1.01      0.00      0.01       172.36       33010.81\nstress-ng: metrc: [19409] dentry            14336      1.03      0.06      0.40     13933.16       31476.70\nstress-ng: metrc: [19409] dir                8192      1.09      0.07      0.84      7506.28        8976.15\nstress-ng: metrc: [19409] dirmany            9983      1.01      0.01      0.21      9878.16       44268.35\nstress-ng: metrc: [19409] fallocate             2      1.01      0.01      0.00         1.98         312.55\nstress-ng: metrc: [19409] file-ioctl        74658      1.01      0.05      0.65     74034.35      105954.38\nstress-ng: metrc: [19409] filename           3239      1.01      0.08      0.54      3211.99        5238.51\nstress-ng: metrc: [19409] flock           2488131      1.01      0.42      0.55   2467498.23     2545858.34\nstress-ng: metrc: [19409] fpunch             1501      1.01      0.00      0.27      1480.03        5460.70\nstress-ng: metrc: [19409] fstat              1838      1.00      0.14      0.41      1829.73        3398.88\nstress-ng: metrc: [19409] getdent          205845      1.00      0.10      0.89    205842.60      208028.47\nstress-ng: metrc: [19409] hdd               27995      1.01      0.31      0.29     27781.43       46602.10\nstress-ng: metrc: [19409] inotify               2      1.03      0.00      0.00         1.94         542.15\nstress-ng: metrc: [19409] open              17408      1.01      0.02      0.23     17216.54       69537.15\nstress-ng: metrc: [19409] rename              525      1.01      0.00      0.02       520.73       28317.15\nstress-ng: metrc: [19409] touch             60121      1.01      0.05      1.38     59594.45       42136.86\nstress-ng: metrc: [19409] utime             43012      1.00      0.05      0.67     42850.05       59256.12\nstress-ng: info:  [19409] skipped: 0\nstress-ng: info:  [19409] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [19409] failed: 0\nstress-ng: info:  [19409] metrics untrustworthy: 0\nstress-ng: info:  [19409] successful run completed in 1.10 secs"
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
          "35": {
            "avg_ns_per_run": 55.65912021919594,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 9622806,
            "run_time_ns_delta": 535596916,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 57.05617425352083,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 9622807,
            "run_time_ns_delta": 549040553,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0148557670000002,
            "ops_per_sec": 620068.4082036653,
            "ops_total": 629280.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [29606] setting to a 1 secs run per stressor\nstress-ng: info:  [29606] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [29606] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29606] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29606]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29606] cap              451420      1.00      0.11      0.89    451348.22      451609.68\nstress-ng: metrc: [29606] eventfd          133550      1.00      0.04      0.77    133523.20      164321.70\nstress-ng: metrc: [29606] get                 964      1.00      0.02      0.14       963.34        6113.14\nstress-ng: metrc: [29606] prctl              2761      1.00      0.65      0.32      2760.89        2845.91\nstress-ng: metrc: [29606] set               40585      1.00      0.05      0.93     40584.78       41649.26\nstress-ng: info:  [29606] skipped: 0\nstress-ng: info:  [29606] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [29606] failed: 0\nstress-ng: info:  [29606] metrics untrustworthy: 0\nstress-ng: info:  [29606] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 57.76994409991454,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 9566175,
            "run_time_ns_delta": 552637395,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 55.711621655298835,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 9566176,
            "run_time_ns_delta": 532947178,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.015545603999982,
            "ops_per_sec": 616893.0253180547,
            "ops_total": 626483.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [2699] setting to a 1 secs run per stressor\nstress-ng: info:  [2699] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [2699] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2699] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2699]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2699] cap              454154      1.00      0.08      0.92    454151.08      454152.18\nstress-ng: metrc: [2699] eventfd          128471      1.00      0.09      0.74    128445.58      153947.09\nstress-ng: metrc: [2699] get                 937      1.00      0.02      0.14       936.69        6058.57\nstress-ng: metrc: [2699] prctl              2786      1.00      0.65      0.32      2784.81        2857.51\nstress-ng: metrc: [2699] set               40135      1.00      0.06      0.91     40133.31       41260.21\nstress-ng: info:  [2699] skipped: 0\nstress-ng: info:  [2699] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [2699] failed: 0\nstress-ng: info:  [2699] metrics untrustworthy: 0\nstress-ng: info:  [2699] successful run completed in 1.00 secs"
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
          "39": {
            "avg_ns_per_run": 721.3225806451613,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 310,
            "run_time_ns_delta": 223610,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4084.4774193548387,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 155,
            "run_time_ns_delta": 633094,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4321.238709677419,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 155,
            "run_time_ns_delta": 669792,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.002147076,
            "ops_per_sec": 309.33583245818903,
            "ops_total": 310.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 736.9019607843137,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 306,
            "run_time_ns_delta": 225492,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4734.522875816993,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 153,
            "run_time_ns_delta": 724382,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 4778.392156862745,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 153,
            "run_time_ns_delta": 731094,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000973211999991,
            "ops_per_sec": 305.70248667154414,
            "ops_total": 306.0,
            "stderr": "",
            "stdout": ""
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
          "44": {
            "avg_ns_per_run": 841.6738991703893,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 3134,
            "run_time_ns_delta": 2637806,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0015660969999942,
            "ops_per_sec": 312.51057812113805,
            "ops_total": 313.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 851.9226263871764,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 3244,
            "run_time_ns_delta": 2763637,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0029227240000012,
            "ops_per_sec": 323.0557970685682,
            "ops_total": 324.0,
            "stderr": "",
            "stdout": ""
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
          "47": {
            "avg_ns_per_run": 187.23885051602977,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 11478020,
            "run_time_ns_delta": 2149131271,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 86.56025811144379,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 555419,
            "run_time_ns_delta": 48077212,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 183.05585640401583,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 32870,
            "run_time_ns_delta": 6017046,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0251313759999903,
            "ops_per_sec": 22110119.278994944,
            "ops_total": 22665777.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [27871] setting to a 1 secs run per stressor\nstress-ng: info:  [27871] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [27871] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [27871] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [27871]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [27871] clone               674      1.01      0.19      0.77       669.50         707.03\nstress-ng: metrc: [27871] fork               3117      1.00      0.26      0.37      3114.44        4909.59\nstress-ng: metrc: [27871] futex            282274      2.00      0.21      1.07    141123.56      221622.56\nstress-ng: metrc: [27871] sem             1076687      1.00      0.09      0.59   1076009.99     1574380.01\nstress-ng: metrc: [27871] sem-sysv        2567065      1.00      0.22      0.78   2566209.66     2569691.22\nstress-ng: metrc: [27871] switch           279382      1.00      0.12      0.66    279340.38      355952.33\nstress-ng: metrc: [27871] vfork             28970      1.00      0.21      0.29     28960.38       58284.23\nstress-ng: metrc: [27871] yield          18427608      1.01      2.84      7.16  18189736.11     1842450.53\nstress-ng: info:  [27871] skipped: 0\nstress-ng: info:  [27871] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [27871] failed: 0\nstress-ng: info:  [27871] metrics untrustworthy: 0\nstress-ng: info:  [27871] successful run completed in 1.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 190.66186655737602,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 12712280,
            "run_time_ns_delta": 2423747033,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 82.42585176764223,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 467968,
            "run_time_ns_delta": 38572661,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 206.76208868378814,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 19936,
            "run_time_ns_delta": 4122009,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0239851849999866,
            "ops_per_sec": 22672078.01448837,
            "ops_total": 23215872.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [27222] setting to a 1 secs run per stressor\nstress-ng: info:  [27222] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [27222] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [27222] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [27222]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [27222] clone               448      1.01      0.12      0.51       442.44         712.50\nstress-ng: metrc: [27222] fork               3241      1.00      0.27      0.35      3240.81        5236.28\nstress-ng: metrc: [27222] futex            303426      2.00      0.15      1.28    151698.17      212101.32\nstress-ng: metrc: [27222] sem             1220464      1.00      0.11      0.56   1220348.20     1820563.65\nstress-ng: metrc: [27222] sem-sysv        2524600      1.00      0.26      0.68   2523740.16     2697556.53\nstress-ng: metrc: [27222] switch           199462      1.00      0.07      0.50    199422.96      346392.83\nstress-ng: metrc: [27222] vfork             16159      1.00      0.14      0.20     16158.82       47900.52\nstress-ng: metrc: [27222] yield          18948072      1.00      2.85      7.89  18885184.48     1764576.68\nstress-ng: info:  [27222] skipped: 0\nstress-ng: info:  [27222] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [27222] failed: 0\nstress-ng: info:  [27222] metrics untrustworthy: 0\nstress-ng: info:  [27222] successful run completed in 1.01 secs"
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
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 52,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 53,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "54": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 54,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 55,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 56,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "57": {
            "avg_ns_per_run": null,
            "bytes_jited": 19909,
            "bytes_xlated": 33264,
            "id": 57,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "58": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 58,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "59": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 59,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "60": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 60,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "61": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 61,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "62": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 62,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "63": {
            "avg_ns_per_run": 1322.0,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 63,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 3966,
            "type": "tracepoint"
          },
          "64": {
            "avg_ns_per_run": 1010.8890954151177,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 64,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1614,
            "run_time_ns_delta": 1631575,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.018998345999989,
            "ops_per_sec": 3052.60112552347,
            "ops_total": 15321.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [14856] setting to a 5 secs run per stressor\nstress-ng: info:  [14856] dispatching hogs: 1 cpu\nstress-ng: info:  [14856] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [14856] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [14856]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [14856] cpu               15321      5.00      5.00      0.00      3063.60        3064.11\nstress-ng: info:  [14856] skipped: 0\nstress-ng: info:  [14856] passed: 1: cpu (1)\nstress-ng: info:  [14856] failed: 0\nstress-ng: info:  [14856] metrics untrustworthy: 0\nstress-ng: info:  [14856] successful run completed in 5.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 3721,
            "bytes_xlated": 6232,
            "id": 52,
            "name": "perf_unwind_stop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 22575,
            "bytes_xlated": 37232,
            "id": 53,
            "name": "perf_unwind_native",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "54": {
            "avg_ns_per_run": null,
            "bytes_jited": 18290,
            "bytes_xlated": 28048,
            "id": 54,
            "name": "perf_unwind_hotspot",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 17737,
            "bytes_xlated": 29144,
            "id": 55,
            "name": "perf_unwind_perl",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 15178,
            "bytes_xlated": 25032,
            "id": 56,
            "name": "perf_unwind_php",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "57": {
            "avg_ns_per_run": null,
            "bytes_jited": 18325,
            "bytes_xlated": 30096,
            "id": 57,
            "name": "perf_unwind_python",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "58": {
            "avg_ns_per_run": null,
            "bytes_jited": 16540,
            "bytes_xlated": 28000,
            "id": 58,
            "name": "perf_unwind_ruby",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "59": {
            "avg_ns_per_run": null,
            "bytes_jited": 20050,
            "bytes_xlated": 33712,
            "id": 59,
            "name": "perf_unwind_v8",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "60": {
            "avg_ns_per_run": null,
            "bytes_jited": 22565,
            "bytes_xlated": 34248,
            "id": 60,
            "name": "perf_unwind_dotnet",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "61": {
            "avg_ns_per_run": null,
            "bytes_jited": 1580,
            "bytes_xlated": 2496,
            "id": 61,
            "name": "perf_go_labels",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "62": {
            "avg_ns_per_run": null,
            "bytes_jited": 696,
            "bytes_xlated": 1088,
            "id": 62,
            "name": "perf_unwind_beam",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "perf_event"
          },
          "63": {
            "avg_ns_per_run": 4544.333333333333,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 63,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 13633,
            "type": "tracepoint"
          },
          "64": {
            "avg_ns_per_run": 935.1635687732341,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 64,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1614,
            "run_time_ns_delta": 1509354,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.018404107999999,
            "ops_per_sec": 3044.9919279398146,
            "ops_total": 15281.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [14896] setting to a 5 secs run per stressor\nstress-ng: info:  [14896] dispatching hogs: 1 cpu\nstress-ng: info:  [14896] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [14896] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [14896]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [14896] cpu               15281      5.00      5.00      0.00      3056.03        3056.05\nstress-ng: info:  [14896] skipped: 0\nstress-ng: info:  [14896] passed: 1: cpu (1)\nstress-ng: info:  [14896] failed: 0\nstress-ng: info:  [14896] metrics untrustworthy: 0\nstress-ng: info:  [14896] successful run completed in 5.00 secs"
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
      "selected_workload": "stress_ng_cpu",
      "status": "ok"
    },
    {
      "app": "cilium/agent",
      "baseline": {
        "bpf": {
          "72": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 72,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "73": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 73,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 129,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 130,
            "name": "cil_from_host",
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
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 132,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 134,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 135,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 136,
            "name": "tail_handle_ipv4_from_host",
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
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 138,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 139,
            "name": "cil_from_host",
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
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 141,
            "name": "tail_handle_ipv4_from_netdev",
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
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 145,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 146,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 147,
            "name": "cil_host_policy",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 149,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 150,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 151,
            "name": "cil_from_host",
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
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 153,
            "name": "tail_handle_ipv4_from_netdev",
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
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 155,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 156,
            "name": "cil_to_netdev",
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
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 158,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 160,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 161,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "162": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 162,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 163,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "164": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 164,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "165": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 165,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "166": {
            "avg_ns_per_run": 1697.8195488721803,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 166,
            "name": "cil_from_netdev",
            "run_cnt_delta": 266,
            "run_time_ns_delta": 451620,
            "type": "sched_cls"
          },
          "168": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 168,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0070491710000056,
            "ops_per_sec": 119.16002063815743,
            "ops_total": 120.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    48.83ms   10.97ms  60.23ms   85.83%\n    Req/Sec    60.20     41.25   101.00    100.00%\n  120 requests in 1.00s, 18.97KB read\nRequests/sec:    119.41\nTransfer/sec:     18.88KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "72": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 72,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "73": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 73,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 129,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 130,
            "name": "cil_from_host",
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
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 132,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 134,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 135,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 136,
            "name": "tail_handle_ipv4_from_host",
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
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 138,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 139,
            "name": "cil_from_host",
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
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 141,
            "name": "tail_handle_ipv4_from_netdev",
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
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 145,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 146,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 147,
            "name": "cil_host_policy",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 149,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 150,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 151,
            "name": "cil_from_host",
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
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 153,
            "name": "tail_handle_ipv4_from_netdev",
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
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 155,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 156,
            "name": "cil_to_netdev",
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
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 158,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 160,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 161,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "162": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 162,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 163,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "164": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 164,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "165": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 165,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "166": {
            "avg_ns_per_run": 1647.6571428571428,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 166,
            "name": "cil_from_netdev",
            "run_cnt_delta": 350,
            "run_time_ns_delta": 576680,
            "type": "sched_cls"
          },
          "168": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 168,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.008753812000009,
            "ops_per_sec": 156.62890005514902,
            "ops_total": 158.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency    49.68ms   11.63ms  60.21ms   94.94%\n    Req/Sec    79.20     21.21   110.00     70.00%\n  158 requests in 1.00s, 24.99KB read\nRequests/sec:    157.74\nTransfer/sec:     24.95KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
        ],
        "error": "prog 73: prog 73 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8aadda58817a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8aadda58819a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 73 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8aadda58817a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8aadda58819a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
            "exit_code": 1,
            "prog_id": 73
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 37,
          "not_applied": 1,
          "requested": 38
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
          "183": {
            "avg_ns_per_run": 1674.489247311828,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 183,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 930,
            "run_time_ns_delta": 1557275,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": 2188.5888125613346,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 185,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1019,
            "run_time_ns_delta": 2230172,
            "type": "kprobe"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 186,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 187,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "188": {
            "avg_ns_per_run": 5182.0,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 188,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10364,
            "type": "tracepoint"
          },
          "189": {
            "avg_ns_per_run": 539.0,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 189,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1078,
            "type": "kprobe"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 190,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 193,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 195,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 196,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 197,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 198,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 199,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 200,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 202,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 204,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 205,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 208,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 209,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 210,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "211": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 211,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "212": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 212,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 213,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 214,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 215,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 216,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": 405.35254134557107,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 217,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 115490,
            "run_time_ns_delta": 46814165,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 218,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 219,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 220,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 221,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 222,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 223,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": 49.1028227552169,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 224,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 115490,
            "run_time_ns_delta": 5670885,
            "type": "kprobe"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 225,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "avg_ns_per_run": 1316.728100261567,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 226,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 115458,
            "run_time_ns_delta": 152026793,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 227,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 229,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 231,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 232,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 233,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 234,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 235,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 236,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "237": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 237,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 238,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 239,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 240,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 242,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 243,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 244,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": 409.0532253874794,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 245,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 115490,
            "run_time_ns_delta": 47241557,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 246,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 247,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "248": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 248,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": 49.34443674777037,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 249,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 115490,
            "run_time_ns_delta": 5698789,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 250,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 251,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 252,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 254,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 1378.7790538550814,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 256,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 115458,
            "run_time_ns_delta": 159191072,
            "type": "kprobe"
          },
          "257": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 257,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 258,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 259,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 261,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 262,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": 558.2925075981148,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 263,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 113515,
            "run_time_ns_delta": 63374574,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 264,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 265,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 266,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 267,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": 839.8856810275269,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 268,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 377995,
            "run_time_ns_delta": 317472588,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 270,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 272,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 273,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 275,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 276,
            "name": "generic_kprobe_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 278,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 279,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 281,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 283,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 284,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 285,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": 186.5028209977591,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 286,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 377526,
            "run_time_ns_delta": 70409664,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 287,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 288,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 289,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 290,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 291,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 292,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 294,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 486.748130184388,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 296,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 676671,
            "run_time_ns_delta": 329368344,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 297,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 298,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 299,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 300,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": 38.19771765345692,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 301,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 676672,
            "run_time_ns_delta": 25847326,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 302,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 303,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 304,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 305,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 306,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": 7636.313989239047,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 307,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2602,
            "run_time_ns_delta": 19869689,
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
            "avg_ns_per_run": 66.20983858570331,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 310,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2602,
            "run_time_ns_delta": 172278,
            "type": "kprobe"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 311,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 312,
            "name": "generic_retkprobe_output",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 314,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 316,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 317,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 318,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": 7276.125,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 319,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 58209,
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 321,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": 477.25,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 322,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 3818,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 323,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 324,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 325,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 326,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 327,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 328,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 329,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 330,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 331,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 332,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 333,
            "name": "generic_retkprobe_event",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 335,
            "name": "generic_retkprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 338,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 340,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 342,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 343,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 344,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 345,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 346,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 347,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 349,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 350,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 351,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 352,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 353,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 355,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 356,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 358,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 359,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 360,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 361,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 3778.5,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 363,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7557,
            "type": "kprobe"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 364,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 365,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 366,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 367,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 368,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 369,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 370,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "371": {
            "avg_ns_per_run": 1109.3458298898413,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 371,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 5760867,
            "run_time_ns_delta": 6390793783,
            "type": "tracepoint"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 372,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "373": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 373,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 374,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 375,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 376,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 377,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 378,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 379,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "380": {
            "avg_ns_per_run": 5695.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 380,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 11390,
            "type": "raw_tracepoint"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 381,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 382,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 384,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 385,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 458.2957420625154,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 387,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 20315,
            "run_time_ns_delta": 9310278,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 392,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 2792.7630465444286,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 394,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 709,
            "run_time_ns_delta": 1980069,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 395,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 396,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 397,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 399,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 401,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": 428.3977920166248,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 402,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 115490,
            "run_time_ns_delta": 49475661,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 403,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 404,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 405,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 407,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 408,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 409,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": 47.15235951164603,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 410,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 115490,
            "run_time_ns_delta": 5445626,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 411,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 412,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 413,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": 1376.4772991044363,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 414,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 115458,
            "run_time_ns_delta": 158925316,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 415,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 416,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 417,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 418,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 419,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 422,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": 2511.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 423,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 25110,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 424,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 425,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 426,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 427,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 429,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 3103.3333333333335,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 431,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 9310,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 432,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 435,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 436,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 437,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 438,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 439,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": 6636.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 440,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 6636,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 441,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "avg_ns_per_run": 4111.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 442,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4111,
            "type": "kprobe"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 443,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 444,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 445,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 9509.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 447,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 9509,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 450,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 451,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": 3764.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 452,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 11292,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 453,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 454,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 457,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 461,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": 1358.3585773989187,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 462,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 120596,
            "run_time_ns_delta": 163812611,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 463,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 464,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 465,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 466,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "467": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 467,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 468,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 469,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 470,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "471": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 471,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "472": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 472,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1814415950000239,
            "ops_per_sec": 14596486.252881296,
            "ops_total": 17244896.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16985] setting to a 1 secs run per stressor\nstress-ng: info:  [16985] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set, 1 aio, 1 aiol, 1 hdd, 1 io, 1 iomix, 1 io-uring, 1 sync-file, 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [16985] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [16994] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [16985] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16985]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16985] cap               74970      1.00      0.00      0.79     74969.98       94632.33\nstress-ng: metrc: [16985] eventfd           61600      1.00      0.05      0.92     61587.74       63390.33\nstress-ng: metrc: [16985] get                 462      1.00      0.00      0.22       461.74        2059.93\nstress-ng: metrc: [16985] prctl               881      1.00      0.57      0.14       880.96        1246.02\nstress-ng: metrc: [16985] set                6794      1.00      0.01      0.78      6793.89        8635.93\nstress-ng: metrc: [16985] aio                8639      1.00      0.00      0.14      8628.93       59787.12\nstress-ng: metrc: [16985] aiol               1141      1.15      0.01      0.17       991.33        6316.89\nstress-ng: metrc: [16985] hdd               22840      1.00      0.49      0.33     22810.17       27952.79\nstress-ng: metrc: [16985] io                   99      1.00      0.00      0.02        98.76        4308.28\nstress-ng: metrc: [16985] iomix               999      1.01      0.01      0.36       993.78        2677.39\nstress-ng: metrc: [16985] io-uring          10022      1.02      0.00      0.35      9831.46       28982.66\nstress-ng: metrc: [16985] sync-file            13      1.00      0.01      0.67        12.99          19.07\nstress-ng: metrc: [16985] epoll             20276      1.16      0.02      0.92     17457.50       21528.07\nstress-ng: metrc: [16985] netdev            37239      1.00      0.00      0.95     37238.24       38989.10\nstress-ng: metrc: [16985] sctp                294      1.00      0.01      0.00       293.01       54253.55\nstress-ng: metrc: [16985] sock                236      1.00      0.00      0.81       235.34         292.60\nstress-ng: metrc: [16985] sockdiag       16647134      1.00      0.06      0.88  16643725.34    17759007.71\nstress-ng: metrc: [16985] sockfd            92667      1.00      0.03      1.01     92472.90       89276.97\nstress-ng: metrc: [16985] sockpair         103300      1.06      0.01      1.39     97858.03       73644.16\nstress-ng: metrc: [16985] udp-flood        155290      1.00      0.02      0.90    155288.74      169445.11\nstress-ng: info:  [16985] skipped: 0\nstress-ng: info:  [16985] passed: 20: cap (1) eventfd (1) get (1) prctl (1) set (1) aio (1) aiol (1) hdd (1) io (1) iomix (1) io-uring (1) sync-file (1) epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [16985] failed: 0\nstress-ng: info:  [16985] metrics untrustworthy: 0\nstress-ng: info:  [16985] successful run completed in 1.16 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "183": {
            "avg_ns_per_run": 1531.9455388180766,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 183,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 863,
            "run_time_ns_delta": 1322069,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": 2144.818880351262,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 185,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 1953930,
            "type": "kprobe"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 186,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 187,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "188": {
            "avg_ns_per_run": 7107.5,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 188,
            "name": "event_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 14215,
            "type": "tracepoint"
          },
          "189": {
            "avg_ns_per_run": 852.0,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 189,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1704,
            "type": "kprobe"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 190,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 193,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 195,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 196,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 197,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 198,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 199,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 200,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 202,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 204,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 205,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 208,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 209,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 210,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "211": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 211,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "212": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 212,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 213,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 214,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 215,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 216,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": 446.2741940988754,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 217,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 117198,
            "run_time_ns_delta": 52302443,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 218,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 219,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 220,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 221,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 222,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 223,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": 74.08026587484429,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 224,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 117198,
            "run_time_ns_delta": 8682059,
            "type": "kprobe"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 225,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "avg_ns_per_run": 1371.6946787745057,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 226,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 117830,
            "run_time_ns_delta": 161626784,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 227,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 229,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 231,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 232,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 233,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 234,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 235,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 236,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "237": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 237,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 238,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 239,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 240,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 242,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 243,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 244,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": 429.9455366132528,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 245,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 117198,
            "run_time_ns_delta": 50388757,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 246,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 247,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "248": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 248,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": 80.79230874247001,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 249,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 117198,
            "run_time_ns_delta": 9468697,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 250,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 251,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 252,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 254,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 1406.0109988967156,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 256,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 117830,
            "run_time_ns_delta": 165670276,
            "type": "kprobe"
          },
          "257": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 257,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 258,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 259,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 261,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 262,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": 454.4143473233951,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 263,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 227471,
            "run_time_ns_delta": 103366086,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 264,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 265,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 266,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 267,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": 747.3661606306157,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 268,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 453525,
            "run_time_ns_delta": 338949238,
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
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 270,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 272,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 273,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 275,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 276,
            "name": "generic_kprobe_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 278,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 279,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 281,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 283,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 284,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 285,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": 187.82205188679245,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 286,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 347680,
            "run_time_ns_delta": 65301971,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 287,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 288,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 289,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 290,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 291,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 292,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 294,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 540.0739291360487,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 296,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 589524,
            "run_time_ns_delta": 318386543,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 297,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 298,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 299,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 300,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": 39.31123128359708,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 301,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 589523,
            "run_time_ns_delta": 23174875,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 302,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 303,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 304,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 305,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 306,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": 6957.263221153846,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 307,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2496,
            "run_time_ns_delta": 17365329,
            "type": "kprobe"
          },
          "308": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
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
            "avg_ns_per_run": 62.47355769230769,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 310,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2496,
            "run_time_ns_delta": 155934,
            "type": "kprobe"
          },
          "311": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 311,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 312,
            "name": "generic_retkprobe_output",
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
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 314,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 316,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 317,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 318,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": 6607.666666666667,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 319,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 39646,
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
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 321,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": 362.0,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 322,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 2172,
            "type": "kprobe"
          },
          "323": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 323,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "324": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 324,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "325": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 325,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "326": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 326,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "327": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 327,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 328,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "329": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 329,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "330": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 330,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 331,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 332,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 333,
            "name": "generic_retkprobe_event",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 335,
            "name": "generic_retkprobe_filter_arg",
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
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 337,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 338,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 340,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 342,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "343": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 343,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "344": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 344,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "345": {
            "avg_ns_per_run": null,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 345,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "346": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 346,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "347": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 347,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 349,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "350": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 350,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "351": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 351,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 352,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 353,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 355,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "356": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 356,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 358,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "359": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 359,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "360": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 360,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 361,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 6048.0,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 363,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 12096,
            "type": "kprobe"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 364,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "365": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 365,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "366": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 366,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 367,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": null,
            "bytes_jited": 11015,
            "bytes_xlated": 17848,
            "id": 368,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 369,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 370,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "371": {
            "avg_ns_per_run": 1043.8606558436343,
            "bytes_jited": 10815,
            "bytes_xlated": 19224,
            "id": 371,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 6112951,
            "run_time_ns_delta": 6381069040,
            "type": "tracepoint"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 4646,
            "bytes_xlated": 8312,
            "id": 372,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "373": {
            "avg_ns_per_run": null,
            "bytes_jited": 14824,
            "bytes_xlated": 25624,
            "id": 373,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "374": {
            "avg_ns_per_run": null,
            "bytes_jited": 729,
            "bytes_xlated": 1152,
            "id": 374,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "375": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 375,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "376": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 376,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "377": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 377,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "378": {
            "avg_ns_per_run": null,
            "bytes_jited": 16995,
            "bytes_xlated": 29336,
            "id": 378,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 379,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "380": {
            "avg_ns_per_run": 5240.5,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 380,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10481,
            "type": "raw_tracepoint"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 381,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "382": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 382,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 384,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "385": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 385,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 498.2035438625612,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 387,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 24098,
            "run_time_ns_delta": 12005709,
            "type": "kprobe"
          },
          "388": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 388,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 392,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 3455.5909732016926,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 394,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 709,
            "run_time_ns_delta": 2450014,
            "type": "kprobe"
          },
          "395": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 395,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "396": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 396,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 397,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 399,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 401,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "402": {
            "avg_ns_per_run": 437.2789126094302,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 402,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 117198,
            "run_time_ns_delta": 51248214,
            "type": "kprobe"
          },
          "403": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 403,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 404,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "405": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 405,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "406": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 406,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "407": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 407,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "408": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 408,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "409": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 409,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "410": {
            "avg_ns_per_run": 77.93896653526511,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 410,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 117198,
            "run_time_ns_delta": 9134291,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 411,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 412,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 413,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": 1425.5577781549691,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 414,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 117830,
            "run_time_ns_delta": 167973473,
            "type": "kprobe"
          },
          "415": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 415,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "416": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 416,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 417,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "418": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 418,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "419": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 419,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 421,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 422,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": 2826.7,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 423,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 28267,
            "type": "kprobe"
          },
          "424": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 424,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "425": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 425,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "426": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 426,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "427": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 427,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 428,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "429": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 429,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 3442.6666666666665,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 431,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 10328,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 432,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
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
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 435,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 436,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 437,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 438,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "439": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 439,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "440": {
            "avg_ns_per_run": 5157.0,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 440,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 5157,
            "type": "kprobe"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 441,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "442": {
            "avg_ns_per_run": 4480.0,
            "bytes_jited": 13995,
            "bytes_xlated": 24648,
            "id": 442,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4480,
            "type": "kprobe"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 443,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 3701,
            "bytes_xlated": 6568,
            "id": 444,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 445,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 8977.0,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 447,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 8977,
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
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 449,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "450": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 450,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 451,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "452": {
            "avg_ns_per_run": 4244.0,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 452,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 12732,
            "type": "kprobe"
          },
          "453": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 453,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "454": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 454,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 456,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 457,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 459,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 461,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "462": {
            "avg_ns_per_run": 1243.7832915476138,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 462,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 159943,
            "run_time_ns_delta": 198934431,
            "type": "kprobe"
          },
          "463": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 463,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 464,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 465,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "466": {
            "avg_ns_per_run": null,
            "bytes_jited": 1277,
            "bytes_xlated": 2168,
            "id": 466,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "467": {
            "avg_ns_per_run": null,
            "bytes_jited": 17085,
            "bytes_xlated": 29336,
            "id": 467,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 1710,
            "bytes_xlated": 3032,
            "id": 468,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 469,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 11008,
            "bytes_xlated": 17848,
            "id": 470,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "471": {
            "avg_ns_per_run": null,
            "bytes_jited": 4785,
            "bytes_xlated": 8560,
            "id": 471,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "472": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 472,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.230723463000004,
            "ops_per_sec": 18678379.580059998,
            "ops_total": 22987920.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [19274] setting to a 1 secs run per stressor\nstress-ng: info:  [19274] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set, 1 aio, 1 aiol, 1 hdd, 1 io, 1 iomix, 1 io-uring, 1 sync-file, 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [19274] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [19283] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [19274] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [19274]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [19274] cap               91138      1.00      0.02      0.89     91138.74      100658.04\nstress-ng: metrc: [19274] eventfd           45815      1.00      0.01      0.71     45805.99       63260.99\nstress-ng: metrc: [19274] get                 410      1.00      0.02      0.20       409.83        1900.62\nstress-ng: metrc: [19274] prctl               814      1.00      0.49      0.12       813.00        1332.63\nstress-ng: metrc: [19274] set                8499      1.00      0.00      0.89      8499.17        9552.53\nstress-ng: metrc: [19274] aio                8432      1.01      0.02      0.10      8347.10       68722.70\nstress-ng: metrc: [19274] aiol               1202      1.20      0.01      0.17      1002.15        6684.87\nstress-ng: metrc: [19274] hdd               21146      1.00      0.30      0.36     21143.90       32131.26\nstress-ng: metrc: [19274] io                  121      1.01      0.00      0.03       119.61        3498.02\nstress-ng: metrc: [19274] iomix              1042      1.01      0.01      0.30      1029.85        3338.35\nstress-ng: metrc: [19274] io-uring           7542      1.02      0.00      0.37      7418.86       20103.85\nstress-ng: metrc: [19274] sync-file            13      1.01      0.03      0.64        12.88          19.45\nstress-ng: metrc: [19274] epoll             22230      1.13      0.03      1.08     19606.61       19971.95\nstress-ng: metrc: [19274] netdev            33118      1.00      0.04      0.79     33117.55       40121.05\nstress-ng: metrc: [19274] sctp              20451      1.00      0.00      0.35     20423.27       58189.69\nstress-ng: metrc: [19274] sock                313      1.00      0.03      0.94       312.55         320.70\nstress-ng: metrc: [19274] sockdiag       22381109      1.00      0.02      0.92  22371961.38    23868523.80\nstress-ng: metrc: [19274] sockfd            84676      1.01      0.02      0.86     83931.32       95517.09\nstress-ng: metrc: [19274] sockpair         114442      1.06      0.07      1.44    108402.13       75849.58\nstress-ng: metrc: [19274] udp-flood        145407      1.00      0.01      0.91    145404.47      158095.59\nstress-ng: info:  [19274] skipped: 0\nstress-ng: info:  [19274] passed: 20: cap (1) eventfd (1) get (1) prctl (1) set (1) aio (1) aiol (1) hdd (1) io (1) iomix (1) io-uring (1) sync-file (1) epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [19274] failed: 0\nstress-ng: info:  [19274] metrics untrustworthy: 0\nstress-ng: info:  [19274] successful run completed in 1.20 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": true,
        "enabled_passes": [
          "wide_mem"
        ],
        "error": "prog 196: prog 196 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 201: prog 201 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 208: prog 208 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 214: prog 214 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 222: prog 222 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 225: prog 225 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 236: prog 236 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 242: prog 242 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 248: prog 248 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 252: prog 252 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 261: prog 261 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 266: prog 266 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 271: prog 271 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 284: prog 284 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 287: prog 287 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 294: prog 294 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 299: prog 299 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 309: prog 309 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 311: prog 311 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 316: prog 316 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 323: prog 323 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 331: prog 331 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 335: prog 335 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 339: prog 339 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 346: prog 346 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 349: prog 349 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 355: prog 355 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 367: prog 367 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 369: prog 369 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 377: prog 377 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 386: prog 386 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 389: prog 389 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 401: prog 401 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 407: prog 407 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 411: prog 411 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 415: prog 415 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 426: prog 426 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 430: prog 430 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 437: prog 437 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 443: prog 443 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 448: prog 448 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 457: prog 457 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 461: prog 461 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 472: prog 472 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 196 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 196
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
            "error": "prog 208 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 208
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 214 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 214
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 222 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 222
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 225 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 225
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 236 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 236
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 242 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 242
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 248 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 248
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 252 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 252
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 261 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 261
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 266 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 266
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
            "error": "prog 284 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 284
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 287 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 287
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 294 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 294
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 299 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 299
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
            "error": "prog 311 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 311
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 316 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 316
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 323 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 323
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 331 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 331
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 335 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 335
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
            "error": "prog 346 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 346
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 349 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 349
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 355 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 355
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
            "error": "prog 369 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 369
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 377 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 377
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
            "error": "prog 389 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 389
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 401 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 401
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 407 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 407
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 411 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 411
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 415 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 415
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 426 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 426
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 430 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 430
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 437 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 437
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 443 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 443
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 448 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 448
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 457 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 457
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 461 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 461
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 472 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 472
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
          "479": {
            "avg_ns_per_run": 320.1599293130108,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 479,
            "name": "xdp_root",
            "run_cnt_delta": 36216,
            "run_time_ns_delta": 11594912,
            "type": "xdp"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 485,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 487,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0004629510000314,
            "ops_per_sec": 6033.206920822609,
            "ops_total": 6036.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "479": {
            "avg_ns_per_run": 314.38949490486317,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 479,
            "name": "xdp_root",
            "run_cnt_delta": 36211,
            "run_time_ns_delta": 11384358,
            "type": "xdp"
          },
          "485": {
            "avg_ns_per_run": null,
            "bytes_jited": 13581,
            "bytes_xlated": 23744,
            "id": 485,
            "name": "balancer_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 487,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.000557523999987,
            "ops_per_sec": 6031.6372174920325,
            "ops_total": 6035.0,
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
      "selected_workload": "network",
      "status": "ok"
    },
    {
      "app": "tracee/monitor",
      "baseline": {
        "bpf": {
          "502": {
            "avg_ns_per_run": 149.76698042476414,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 502,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 29729910,
            "run_time_ns_delta": 4452558849,
            "type": "raw_tracepoint"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 503,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 504,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "505": {
            "avg_ns_per_run": 294.5453219425619,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 505,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 29729915,
            "run_time_ns_delta": 8756807385,
            "type": "raw_tracepoint"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 506,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 507,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "508": {
            "avg_ns_per_run": 254.19696379841042,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 508,
            "name": "trace_sys_enter",
            "run_cnt_delta": 29729910,
            "run_time_ns_delta": 7557252856,
            "type": "raw_tracepoint"
          },
          "509": {
            "avg_ns_per_run": 252.45125157606404,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 509,
            "name": "trace_sys_exit",
            "run_cnt_delta": 29729915,
            "run_time_ns_delta": 7505354251,
            "type": "raw_tracepoint"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 510,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 511,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 512,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 513,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": 73.51225879617924,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 514,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 1059892,
            "run_time_ns_delta": 77915055,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": 278.42146369630115,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 515,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1059892,
            "run_time_ns_delta": 295096682,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": 221.90639269406392,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 516,
            "name": "trace_dup",
            "run_cnt_delta": 3942,
            "run_time_ns_delta": 874755,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": 879.1050228310502,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 517,
            "name": "trace_ret_dup",
            "run_cnt_delta": 3942,
            "run_time_ns_delta": 3465432,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": 765.75,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 518,
            "name": "trace_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 3063,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": 2545.25,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 519,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 10181,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 520,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 521,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 522,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 523,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 524,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 525,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "526": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 526,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": 2321.7528116774347,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 527,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 4179,
            "run_time_ns_delta": 9702605,
            "type": "raw_tracepoint"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 528,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 529,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 530,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 531,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 532,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 533,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 534,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": 10808.0,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 535,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 21616,
            "type": "raw_tracepoint"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 536,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "537": {
            "avg_ns_per_run": 1363.449462890625,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 537,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 4096,
            "run_time_ns_delta": 5584689,
            "type": "raw_tracepoint"
          },
          "538": {
            "avg_ns_per_run": 907.1206728425159,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 538,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 4102,
            "run_time_ns_delta": 3721009,
            "type": "raw_tracepoint"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 539,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "540": {
            "avg_ns_per_run": 375.7010164546622,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 540,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 1713800,
            "run_time_ns_delta": 643876402,
            "type": "raw_tracepoint"
          },
          "541": {
            "avg_ns_per_run": 16.767294857475928,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 541,
            "name": "trace_filldir64",
            "run_cnt_delta": 552433,
            "run_time_ns_delta": 9262807,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 542,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": 949.248291015625,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 543,
            "name": "trace_do_exit",
            "run_cnt_delta": 4096,
            "run_time_ns_delta": 3888121,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 544,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 545,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 546,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "547": {
            "avg_ns_per_run": 94.49657033434912,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 547,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 4388766,
            "run_time_ns_delta": 414723335,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 548,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 549,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "550": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 550,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 551,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "552": {
            "avg_ns_per_run": 10134.5,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 552,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 20269,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": 534.2702850706995,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 553,
            "name": "trace_security_file_open",
            "run_cnt_delta": 805309,
            "run_time_ns_delta": 430252669,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 554,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": 2026.8032786885246,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 555,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 122,
            "run_time_ns_delta": 247270,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": 230.3472916765261,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 556,
            "name": "trace_commit_creds",
            "run_cnt_delta": 380346,
            "run_time_ns_delta": 87611671,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": 538.762451171875,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 557,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 4096,
            "run_time_ns_delta": 2206771,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": 130.1778706425276,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 558,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2610487,
            "run_time_ns_delta": 339827639,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": 280.62648174803934,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 559,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 755864,
            "run_time_ns_delta": 212115455,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 560,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 561,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 562,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 563,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": 992.5,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 564,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 3970,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": 358.22576026395245,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 565,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 64254,
            "run_time_ns_delta": 23017438,
            "type": "kprobe"
          },
          "566": {
            "avg_ns_per_run": 481.9448227393409,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 566,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 64030,
            "run_time_ns_delta": 30858927,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": 1025.5,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 567,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 4102,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": 1305.7109004739336,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 568,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 211,
            "run_time_ns_delta": 275505,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 569,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 570,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "571": {
            "avg_ns_per_run": 59.86693938453219,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 571,
            "name": "trace_vfs_write",
            "run_cnt_delta": 998590,
            "run_time_ns_delta": 59782527,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": 73.95357454010154,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 572,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 998590,
            "run_time_ns_delta": 73849300,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": 610.9193643036682,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 573,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 998590,
            "run_time_ns_delta": 610057968,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": 33.56837941497511,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 574,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 998590,
            "run_time_ns_delta": 33521048,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 575,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": 413.2037037037037,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 576,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 22313,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": 666.7407407407408,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 577,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 36004,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": 4784.2962962962965,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 578,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 258352,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": 3406.240740740741,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 579,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 183937,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 580,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 581,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 582,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 583,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": null,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 584,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 585,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": 52.27014659667113,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 586,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1340276,
            "run_time_ns_delta": 70056423,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 553.8892519152771,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 587,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1340276,
            "run_time_ns_delta": 742364471,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 588,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": 450.01851851851853,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 589,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 24301,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": 2634.296296296296,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 590,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 54,
            "run_time_ns_delta": 142252,
            "type": "kprobe"
          },
          "591": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 591,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "592": {
            "avg_ns_per_run": 158.87128580946035,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 592,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 7505,
            "run_time_ns_delta": 1192329,
            "type": "kprobe"
          },
          "593": {
            "avg_ns_per_run": 90.50607395541316,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 593,
            "name": "trace_do_mmap",
            "run_cnt_delta": 7491,
            "run_time_ns_delta": 677981,
            "type": "kprobe"
          },
          "594": {
            "avg_ns_per_run": 430.31731411026567,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 594,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 7491,
            "run_time_ns_delta": 3223507,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": 154.10560747663553,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 595,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 7490,
            "run_time_ns_delta": 1154251,
            "type": "kprobe"
          },
          "596": {
            "avg_ns_per_run": 923.0512820512821,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 596,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 39,
            "run_time_ns_delta": 35999,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 597,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "598": {
            "avg_ns_per_run": 248.50988286969255,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 598,
            "name": "trace_security_bpf",
            "run_cnt_delta": 8196,
            "run_time_ns_delta": 2036787,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 599,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 600,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": 236.59125766871165,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 601,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 617030,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": 645.4285714285714,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 602,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 103914,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 603,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 604,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 605,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 606,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 607,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "608": {
            "avg_ns_per_run": 1458.5,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 608,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5834,
            "type": "kprobe"
          },
          "609": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 609,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 610,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 611,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 612,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "613": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 613,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 614,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 615,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": 3145.5,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 616,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 12582,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": 49.94760221422938,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 617,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 3497018,
            "run_time_ns_delta": 174667664,
            "type": "kprobe"
          },
          "618": {
            "avg_ns_per_run": 1012.5691387559808,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 618,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 4180,
            "run_time_ns_delta": 4232539,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 619,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "620": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 620,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 621,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": 950.8021964759836,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 622,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 8286,
            "run_time_ns_delta": 7878347,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 623,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 624,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 2759.31541218638,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 625,
            "name": "trace_do_truncate",
            "run_cnt_delta": 279,
            "run_time_ns_delta": 769849,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 147.67961658774632,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 626,
            "name": "trace_fd_install",
            "run_cnt_delta": 1976254,
            "run_time_ns_delta": 291852433,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 287.31919511816585,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 627,
            "name": "trace_filp_close",
            "run_cnt_delta": 444587,
            "run_time_ns_delta": 127738379,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": 185.53683259244787,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 628,
            "name": "trace_file_update_time",
            "run_cnt_delta": 40942,
            "run_time_ns_delta": 7596249,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": 611.354257241952,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 629,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 40942,
            "run_time_ns_delta": 25030066,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": 117.79657943137799,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 630,
            "name": "trace_file_modified",
            "run_cnt_delta": 389292,
            "run_time_ns_delta": 45857266,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": 491.11117104898125,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 631,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 389292,
            "run_time_ns_delta": 191185650,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 632,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 633,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 634,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 167.0,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 635,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 334,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 6882.5,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 636,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 13765,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": 9414.5,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 637,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 18829,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 638,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": 3973.0,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 639,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7946,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 270.83887954244983,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 640,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 621746,
            "run_time_ns_delta": 168392990,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 641,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 642,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "643": {
            "avg_ns_per_run": 348.49135681318205,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 643,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 370928,
            "run_time_ns_delta": 129265202,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 644,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 645,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": 26.248126582525504,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 646,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 819892,
            "run_time_ns_delta": 21520629,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": 98.45175340166753,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 647,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 819892,
            "run_time_ns_delta": 80719805,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 949.5,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 648,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 3798,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 201.2607247761112,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 649,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 1893909,
            "run_time_ns_delta": 381169498,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": 194.9141634827794,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 650,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 4492412,
            "run_time_ns_delta": 875634727,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": 189.13536614608464,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 651,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 3081871,
            "run_time_ns_delta": 582890800,
            "type": "kprobe"
          },
          "653": {
            "avg_ns_per_run": 300.32897267627203,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 653,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 487159,
            "run_time_ns_delta": 146307962,
            "type": "cgroup_skb"
          },
          "654": {
            "avg_ns_per_run": 191.59181272044447,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 654,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 2346396,
            "run_time_ns_delta": 449550263,
            "type": "cgroup_skb"
          },
          "655": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 655,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "656": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 656,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "657": {
            "avg_ns_per_run": 100.0,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 657,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 200,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 1497.0,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 658,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2994,
            "type": "raw_tracepoint"
          },
          "659": {
            "avg_ns_per_run": 255.83823476454378,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 659,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 805309,
            "run_time_ns_delta": 206028833,
            "type": "lsm"
          },
          "660": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 660,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.346028651999973,
            "ops_per_sec": 17006359.284286242,
            "ops_total": 90916484.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [16850] setting to a 5 secs run per stressor\nstress-ng: info:  [16850] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set, 1 aio, 1 aiol, 1 hdd, 1 io, 1 iomix, 1 io-uring, 1 sync-file, 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [16850] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [16859] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [16850] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [16850]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [16850] cap              516973      5.00      0.11      4.73    103394.72      106847.15\nstress-ng: metrc: [16850] eventfd          242414      5.00      0.17      4.42     48479.96       52843.95\nstress-ng: metrc: [16850] get                1992      5.00      0.08      1.01       398.38        1826.85\nstress-ng: metrc: [16850] prctl              4030      5.00      2.89      0.78       805.94        1097.34\nstress-ng: metrc: [16850] set               40402      5.00      0.07      4.48      8080.38        8888.97\nstress-ng: metrc: [16850] aio               59887      5.00      0.05      1.00     11974.48       57258.55\nstress-ng: metrc: [16850] aiol              11328      5.10      0.24      0.79      2221.61       11034.89\nstress-ng: metrc: [16850] hdd              109864      5.00      2.14      1.87     21957.73       27378.34\nstress-ng: metrc: [16850] io                  564      5.01      0.01      0.13       112.59        3889.20\nstress-ng: metrc: [16850] iomix              6403      5.01      0.07      0.77      1277.06        7631.12\nstress-ng: metrc: [16850] io-uring          78842      5.02      0.00      2.61     15702.05       30157.07\nstress-ng: metrc: [16850] sync-file            75      5.00      0.15      3.69        15.00          19.53\nstress-ng: metrc: [16850] epoll             64107      5.31      0.08      2.41     12080.46       25723.82\nstress-ng: metrc: [16850] netdev           182340      5.00      0.10      4.73     36462.67       37716.50\nstress-ng: metrc: [16850] sctp               1314      5.00      0.01      0.00       262.78      109985.77\nstress-ng: metrc: [16850] sock               3103      5.00      0.10      6.83       620.49         447.51\nstress-ng: metrc: [16850] sockdiag       87865315      5.00      0.20      4.54  17572194.93    18536118.14\nstress-ng: metrc: [16850] sockfd           426316      5.00      0.24      5.18     85232.54       78669.76\nstress-ng: metrc: [16850] sockpair         365401      5.03      0.09      6.36     72702.82       56675.33\nstress-ng: metrc: [16850] udp-flood        935814      5.00      0.09      4.75    187164.02      193239.77\nstress-ng: info:  [16850] skipped: 0\nstress-ng: info:  [16850] passed: 20: cap (1) eventfd (1) get (1) prctl (1) set (1) aio (1) aiol (1) hdd (1) io (1) iomix (1) io-uring (1) sync-file (1) epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [16850] failed: 0\nstress-ng: info:  [16850] metrics untrustworthy: 0\nstress-ng: info:  [16850] successful run completed in 5.31 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "502": {
            "avg_ns_per_run": 152.80916095140142,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 502,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 28688374,
            "run_time_ns_delta": 4383846360,
            "type": "raw_tracepoint"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 503,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 504,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "505": {
            "avg_ns_per_run": 291.77108344113833,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 505,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 28688379,
            "run_time_ns_delta": 8370439423,
            "type": "raw_tracepoint"
          },
          "506": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 506,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 507,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "508": {
            "avg_ns_per_run": 250.97843492280182,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 508,
            "name": "trace_sys_enter",
            "run_cnt_delta": 28688374,
            "run_time_ns_delta": 7200163207,
            "type": "raw_tracepoint"
          },
          "509": {
            "avg_ns_per_run": 251.65376227775016,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 509,
            "name": "trace_sys_exit",
            "run_cnt_delta": 28688379,
            "run_time_ns_delta": 7219538509,
            "type": "raw_tracepoint"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 510,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 511,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 512,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "513": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 513,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "514": {
            "avg_ns_per_run": 67.62128948515412,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 514,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 1046216,
            "run_time_ns_delta": 70746475,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": 276.755750246603,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 515,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 1046216,
            "run_time_ns_delta": 289546294,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": 215.6111811685582,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 516,
            "name": "trace_dup",
            "run_cnt_delta": 4758,
            "run_time_ns_delta": 1025878,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": 893.0926860025221,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 517,
            "name": "trace_ret_dup",
            "run_cnt_delta": 4758,
            "run_time_ns_delta": 4249335,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": 594.25,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 518,
            "name": "trace_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 2377,
            "type": "kprobe"
          },
          "519": {
            "avg_ns_per_run": 1767.25,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 519,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 7069,
            "type": "kprobe"
          },
          "520": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 520,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 521,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 522,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 523,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 524,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 525,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "526": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 526,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "527": {
            "avg_ns_per_run": 3474.744379276637,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 527,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 4092,
            "run_time_ns_delta": 14218654,
            "type": "raw_tracepoint"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 528,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 529,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 530,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 531,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 532,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 533,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 534,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": 11522.0,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 535,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 23044,
            "type": "raw_tracepoint"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 536,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "537": {
            "avg_ns_per_run": 1383.5395647873393,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 537,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 4044,
            "run_time_ns_delta": 5595034,
            "type": "raw_tracepoint"
          },
          "538": {
            "avg_ns_per_run": 933.1275964391691,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 538,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 4044,
            "run_time_ns_delta": 3773568,
            "type": "raw_tracepoint"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 539,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "540": {
            "avg_ns_per_run": 382.1614920641386,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 540,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 1767672,
            "run_time_ns_delta": 675536169,
            "type": "raw_tracepoint"
          },
          "541": {
            "avg_ns_per_run": 16.720179516018487,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 541,
            "name": "trace_filldir64",
            "run_cnt_delta": 455224,
            "run_time_ns_delta": 7611427,
            "type": "kprobe"
          },
          "542": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 542,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "543": {
            "avg_ns_per_run": 826.0724530168151,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 543,
            "name": "trace_do_exit",
            "run_cnt_delta": 4044,
            "run_time_ns_delta": 3340637,
            "type": "kprobe"
          },
          "544": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 544,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "545": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 545,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "546": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 546,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "547": {
            "avg_ns_per_run": 97.61409499944438,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 547,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 4418489,
            "run_time_ns_delta": 431306805,
            "type": "kprobe"
          },
          "548": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 548,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "549": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 549,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "550": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 550,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "551": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 551,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "552": {
            "avg_ns_per_run": 10655.5,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 552,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 21311,
            "type": "kprobe"
          },
          "553": {
            "avg_ns_per_run": 536.8758367288905,
            "bytes_jited": 22949,
            "bytes_xlated": 37088,
            "id": 553,
            "name": "trace_security_file_open",
            "run_cnt_delta": 801783,
            "run_time_ns_delta": 430457919,
            "type": "kprobe"
          },
          "554": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 554,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "555": {
            "avg_ns_per_run": 2116.0725806451615,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 555,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 124,
            "run_time_ns_delta": 262393,
            "type": "kprobe"
          },
          "556": {
            "avg_ns_per_run": 232.3749274462851,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 556,
            "name": "trace_commit_creds",
            "run_cnt_delta": 397981,
            "run_time_ns_delta": 92480806,
            "type": "kprobe"
          },
          "557": {
            "avg_ns_per_run": 534.3677052423343,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 557,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 4044,
            "run_time_ns_delta": 2160983,
            "type": "kprobe"
          },
          "558": {
            "avg_ns_per_run": 130.9248586615252,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 558,
            "name": "trace_cap_capable",
            "run_cnt_delta": 2649314,
            "run_time_ns_delta": 346861061,
            "type": "kprobe"
          },
          "559": {
            "avg_ns_per_run": 274.3507876756751,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 559,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 755514,
            "run_time_ns_delta": 207275861,
            "type": "kprobe"
          },
          "560": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 560,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "561": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 561,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "562": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 562,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "563": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 563,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "564": {
            "avg_ns_per_run": 1345.75,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 564,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5383,
            "type": "kprobe"
          },
          "565": {
            "avg_ns_per_run": 324.1104643382845,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 565,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 14946,
            "run_time_ns_delta": 4844155,
            "type": "kprobe"
          },
          "566": {
            "avg_ns_per_run": 589.2031466536235,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 566,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 12267,
            "run_time_ns_delta": 7227755,
            "type": "kprobe"
          },
          "567": {
            "avg_ns_per_run": 1580.5,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 567,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 6322,
            "type": "kprobe"
          },
          "568": {
            "avg_ns_per_run": 1071.2396694214876,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 568,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 242,
            "run_time_ns_delta": 259240,
            "type": "kprobe"
          },
          "569": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 569,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "570": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 570,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "571": {
            "avg_ns_per_run": 63.19148597297094,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 571,
            "name": "trace_vfs_write",
            "run_cnt_delta": 1023417,
            "run_time_ns_delta": 64671241,
            "type": "kprobe"
          },
          "572": {
            "avg_ns_per_run": 81.80284087522486,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 572,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 1023417,
            "run_time_ns_delta": 83718418,
            "type": "kprobe"
          },
          "573": {
            "avg_ns_per_run": 668.178880163218,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 573,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 1023417,
            "run_time_ns_delta": 683825625,
            "type": "kprobe"
          },
          "574": {
            "avg_ns_per_run": 38.46015065217795,
            "bytes_jited": 23768,
            "bytes_xlated": 36720,
            "id": 574,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 1023417,
            "run_time_ns_delta": 39360772,
            "type": "kprobe"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 575,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "576": {
            "avg_ns_per_run": 435.3272727272727,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 576,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 55,
            "run_time_ns_delta": 23943,
            "type": "kprobe"
          },
          "577": {
            "avg_ns_per_run": 647.6363636363636,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 577,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 55,
            "run_time_ns_delta": 35620,
            "type": "kprobe"
          },
          "578": {
            "avg_ns_per_run": 5025.945454545455,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 578,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 55,
            "run_time_ns_delta": 276427,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": 4030.3454545454547,
            "bytes_jited": 24504,
            "bytes_xlated": 37576,
            "id": 579,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 55,
            "run_time_ns_delta": 221669,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 580,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 581,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 582,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 583,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": null,
            "bytes_jited": 23768,
            "bytes_xlated": 36720,
            "id": 584,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 585,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": 59.34982602602085,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 586,
            "name": "trace_vfs_read",
            "run_cnt_delta": 1315714,
            "run_time_ns_delta": 78087397,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 585.7562152565071,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 587,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 1315714,
            "run_time_ns_delta": 770687653,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 588,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": 463.92727272727274,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 589,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 55,
            "run_time_ns_delta": 25516,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": 2928.5454545454545,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 590,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 55,
            "run_time_ns_delta": 161070,
            "type": "kprobe"
          },
          "591": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 591,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "592": {
            "avg_ns_per_run": 160.6126582278481,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 592,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 7505,
            "run_time_ns_delta": 1205398,
            "type": "kprobe"
          },
          "593": {
            "avg_ns_per_run": 89.83073020958483,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 593,
            "name": "trace_do_mmap",
            "run_cnt_delta": 7491,
            "run_time_ns_delta": 672922,
            "type": "kprobe"
          },
          "594": {
            "avg_ns_per_run": 432.7364837805366,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 594,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 7491,
            "run_time_ns_delta": 3241629,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": 161.24032042723633,
            "bytes_jited": 36948,
            "bytes_xlated": 60816,
            "id": 595,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 7490,
            "run_time_ns_delta": 1207690,
            "type": "kprobe"
          },
          "596": {
            "avg_ns_per_run": 846.6153846153846,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 596,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 39,
            "run_time_ns_delta": 33018,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 597,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "598": {
            "avg_ns_per_run": 242.38299170326988,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 598,
            "name": "trace_security_bpf",
            "run_cnt_delta": 8196,
            "run_time_ns_delta": 1986571,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 599,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 600,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": 234.85237730061348,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 601,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 2608,
            "run_time_ns_delta": 612495,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": 654.3664596273292,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 602,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 161,
            "run_time_ns_delta": 105353,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 603,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 604,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "605": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 605,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "606": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 606,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "607": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 607,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "608": {
            "avg_ns_per_run": 1342.0,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 608,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 5368,
            "type": "kprobe"
          },
          "609": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 609,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 610,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 611,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 612,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "613": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 613,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 614,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 615,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": 3679.5,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 616,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 14718,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": 49.881890551594594,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 617,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 3538142,
            "run_time_ns_delta": 176489212,
            "type": "kprobe"
          },
          "618": {
            "avg_ns_per_run": 930.0796996124031,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 618,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 4128,
            "run_time_ns_delta": 3839369,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 619,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "620": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 620,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 621,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": 950.3660474211684,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 622,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 8182,
            "run_time_ns_delta": 7775895,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 623,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 624,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 2768.6408450704225,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 625,
            "name": "trace_do_truncate",
            "run_cnt_delta": 284,
            "run_time_ns_delta": 786294,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 145.58296100165305,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 626,
            "name": "trace_fd_install",
            "run_cnt_delta": 1938236,
            "run_time_ns_delta": 282174136,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 279.9061140759478,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 627,
            "name": "trace_filp_close",
            "run_cnt_delta": 453838,
            "run_time_ns_delta": 127032031,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": 186.66049808958246,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 628,
            "name": "trace_file_update_time",
            "run_cnt_delta": 43446,
            "run_time_ns_delta": 8109652,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": 643.0117387101229,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 629,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 43446,
            "run_time_ns_delta": 27936288,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": 121.76515478976316,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 630,
            "name": "trace_file_modified",
            "run_cnt_delta": 402546,
            "run_time_ns_delta": 49016076,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": 491.6928077784899,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 631,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 402546,
            "run_time_ns_delta": 197928973,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 632,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 633,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 634,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 426.5,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 635,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 853,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": 8286.0,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 636,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 16572,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": 9956.5,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 637,
            "name": "trace_execute_finished",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 19913,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 638,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "639": {
            "avg_ns_per_run": 2963.0,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 639,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 5926,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 261.524738925255,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 640,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 656900,
            "run_time_ns_delta": 171795601,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 641,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 642,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "643": {
            "avg_ns_per_run": 350.8770538367418,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 643,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 366144,
            "run_time_ns_delta": 128471528,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 644,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 645,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": 24.304609790056773,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 646,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 767779,
            "run_time_ns_delta": 18660569,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": 97.19739143685878,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 647,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 767779,
            "run_time_ns_delta": 74626116,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": 597.6,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 648,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 2988,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": 203.54440543835787,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 649,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 1888879,
            "run_time_ns_delta": 384470753,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": 191.86343087978273,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 650,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 4644249,
            "run_time_ns_delta": 891061547,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": 186.56751961800168,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 651,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 3306402,
            "run_time_ns_delta": 616867220,
            "type": "kprobe"
          },
          "653": {
            "avg_ns_per_run": 299.7602896731521,
            "bytes_jited": 18427,
            "bytes_xlated": 29120,
            "id": 653,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 517825,
            "run_time_ns_delta": 155223372,
            "type": "cgroup_skb"
          },
          "654": {
            "avg_ns_per_run": 183.80737686514007,
            "bytes_jited": 18427,
            "bytes_xlated": 29120,
            "id": 654,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 2583184,
            "run_time_ns_delta": 474808275,
            "type": "cgroup_skb"
          },
          "655": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 655,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "656": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 656,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "657": {
            "avg_ns_per_run": 192.5,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 657,
            "name": "empty_kprobe",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 385,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": 1943.5,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 658,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3887,
            "type": "raw_tracepoint"
          },
          "659": {
            "avg_ns_per_run": 254.81604997861018,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 659,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 801783,
            "run_time_ns_delta": 204307177,
            "type": "lsm"
          },
          "660": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 660,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 5.148884967000072,
            "ops_per_sec": 14391956.991646454,
            "ops_total": 74102531.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [25525] setting to a 5 secs run per stressor\nstress-ng: info:  [25525] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set, 1 aio, 1 aiol, 1 hdd, 1 io, 1 iomix, 1 io-uring, 1 sync-file, 1 epoll, 1 netdev, 1 sctp, 1 sock, 1 sockdiag, 1 sockfd, 1 sockpair, 1 udp-flood\nstress-ng: info:  [25525] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [25534] io: this is a legacy I/O sync stressor, consider using iomix instead\nstress-ng: metrc: [25525] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25525]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25525] cap              430544      5.00      0.10      4.09     86108.46      102758.64\nstress-ng: metrc: [25525] eventfd          229162      5.00      0.16      4.51     45829.64       49101.97\nstress-ng: metrc: [25525] get                2246      5.00      0.04      1.14       449.10        1904.28\nstress-ng: metrc: [25525] prctl              3978      5.00      2.89      0.79       795.52        1079.99\nstress-ng: metrc: [25525] set               42405      5.00      0.09      4.68      8480.85        8884.52\nstress-ng: metrc: [25525] aio               65774      5.00      0.05      1.13     13146.47       56078.91\nstress-ng: metrc: [25525] aiol              11671      5.08      0.14      0.92      2299.18       10962.54\nstress-ng: metrc: [25525] hdd              112640      5.00      2.21      2.02     22509.93       26668.22\nstress-ng: metrc: [25525] io                  517      5.01      0.00      0.15       103.28        3554.10\nstress-ng: metrc: [25525] iomix              6180      5.02      0.05      0.75      1231.24        7783.97\nstress-ng: metrc: [25525] io-uring          95162      5.02      0.03      2.76     18943.25       34171.27\nstress-ng: metrc: [25525] sync-file            76      5.00      0.18      3.73        15.19          19.44\nstress-ng: metrc: [25525] epoll             14787      5.12      0.02      0.54      2887.49       26488.37\nstress-ng: metrc: [25525] netdev           183772      5.00      0.16      4.68     36754.30       37950.74\nstress-ng: metrc: [25525] sctp               1794      5.00      0.01      0.00       358.75      129962.33\nstress-ng: metrc: [25525] sock               3081      5.00      0.09      6.94       615.83         437.99\nstress-ng: metrc: [25525] sockdiag       71016825      5.00      0.11      4.64  14203063.62    14938893.37\nstress-ng: metrc: [25525] sockfd           434891      5.02      0.12      5.27     86710.70       80597.07\nstress-ng: metrc: [25525] sockpair         411352      5.04      0.20      6.91     81655.25       57859.34\nstress-ng: metrc: [25525] udp-flood       1035674      5.00      0.07      4.80    207134.07      212671.27\nstress-ng: info:  [25525] skipped: 0\nstress-ng: info:  [25525] passed: 20: cap (1) eventfd (1) get (1) prctl (1) set (1) aio (1) aiol (1) hdd (1) io (1) iomix (1) io-uring (1) sync-file (1) epoll (1) netdev (1) sctp (1) sock (1) sockdiag (1) sockfd (1) sockpair (1) udp-flood (1)\nstress-ng: info:  [25525] failed: 0\nstress-ng: info:  [25525] metrics untrustworthy: 0\nstress-ng: info:  [25525] successful run completed in 5.12 secs"
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
      "baseline": null,
      "error": "name 'script_spec' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "stress_ng_os",
      "status": "error"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline": null,
      "error": "name 'script_spec' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "fio_randrw",
      "status": "error"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline": null,
      "error": "name 'script_spec' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "stress_ng_filesystem",
      "status": "error"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline": null,
      "error": "name 'script_spec' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "stress_ng_scheduler",
      "status": "error"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline": null,
      "error": "name 'script_spec' is not defined",
      "post_rejit": null,
      "rejit_result": null,
      "runner": "bpftrace",
      "selected_workload": "tcp_connect",
      "status": "error"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline": null,
      "error": "name 'script_spec' is not defined",
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
    "losses": 80,
    "per_program_geomean": 1.0643138312318157,
    "program_count": 142,
    "wins": 62
  },
  "workload_seconds": 1.0
}
```
