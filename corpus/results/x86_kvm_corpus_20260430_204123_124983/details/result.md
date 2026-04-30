# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-04-30T20:51:18.819625+00:00",
  "kinsn_modules": {
    "captured_at": "2026-04-30T20:41:23.156549+00:00",
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
      "invoked_at": "2026-04-30T20:41:23.156468+00:00",
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
        "captured_at": "2026-04-30T20:41:23.156459+00:00",
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
      "captured_at": "2026-04-30T20:41:23.140680+00:00",
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
      "baseline_avg_ns_per_run": 250.4598474546207,
      "baseline_run_cnt_delta": 84565,
      "baseline_run_time_ns_delta": 21180137,
      "post_rejit_avg_ns_per_run": 285.93199499070244,
      "post_rejit_run_cnt_delta": 79053,
      "post_rejit_run_time_ns_delta": 22603782,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 1.1416280808943187,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 300.22222222222223,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 2702,
      "post_rejit_avg_ns_per_run": 383.77777777777777,
      "post_rejit_run_cnt_delta": 9,
      "post_rejit_run_time_ns_delta": 3454,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 1.2783123612139156,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 140.33333333333334,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 1263,
      "post_rejit_avg_ns_per_run": 190.55555555555554,
      "post_rejit_run_cnt_delta": 9,
      "post_rejit_run_time_ns_delta": 1715,
      "program": "do_ret_sys_execve",
      "program_id": 10,
      "ratio": 1.3578780680918445,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 1116.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 2233,
      "post_rejit_avg_ns_per_run": 823.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 1646,
      "program": "bindsnoop_entry",
      "program_id": 13,
      "ratio": 0.7371249440214958,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/bindsnoop",
      "baseline_avg_ns_per_run": 4242.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 8484,
      "post_rejit_avg_ns_per_run": 3164.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 6328,
      "program": "bindsnoop_v4_return",
      "program_id": 14,
      "ratio": 0.7458745874587459,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 408.5668013764405,
      "baseline_run_cnt_delta": 49984,
      "baseline_run_time_ns_delta": 20421803,
      "post_rejit_avg_ns_per_run": 416.3528159061429,
      "post_rejit_run_cnt_delta": 51653,
      "post_rejit_run_time_ns_delta": 21505872,
      "program": "trace_pid_start_tp",
      "program_id": 18,
      "ratio": 1.0190568947439482,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 368.9091909190919,
      "baseline_run_cnt_delta": 49995,
      "baseline_run_time_ns_delta": 18443615,
      "post_rejit_avg_ns_per_run": 384.3260099494783,
      "post_rejit_run_cnt_delta": 51661,
      "post_rejit_run_time_ns_delta": 19854666,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 1.0417902817546436,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 180.8855137383514,
      "baseline_run_cnt_delta": 50006,
      "baseline_run_time_ns_delta": 9045361,
      "post_rejit_avg_ns_per_run": 192.9898383818833,
      "post_rejit_run_cnt_delta": 51665,
      "post_rejit_run_time_ns_delta": 9970820,
      "program": "trace_req_completion_tp",
      "program_id": 20,
      "ratio": 1.066917048211172,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 61.60260384376937,
      "baseline_run_cnt_delta": 4839,
      "baseline_run_time_ns_delta": 298095,
      "post_rejit_avg_ns_per_run": 56.6012015744769,
      "post_rejit_run_cnt_delta": 4827,
      "post_rejit_run_time_ns_delta": 273214,
      "program": "vfs_create",
      "program_id": 23,
      "ratio": 0.9188118365584587,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 108.75586854460094,
      "baseline_run_cnt_delta": 213,
      "baseline_run_time_ns_delta": 23165,
      "post_rejit_avg_ns_per_run": 92.21491228070175,
      "post_rejit_run_cnt_delta": 228,
      "post_rejit_run_time_ns_delta": 21025,
      "program": "kfunc__vmlinux__vfs_fsync_range",
      "program_id": 24,
      "ratio": 0.8479074602110716,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 47.990075957727875,
      "baseline_run_cnt_delta": 60560,
      "baseline_run_time_ns_delta": 2906279,
      "post_rejit_avg_ns_per_run": 48.866910444565235,
      "post_rejit_run_cnt_delta": 60711,
      "post_rejit_run_time_ns_delta": 2966759,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 1.0182711627214285,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 39.681156746311125,
      "baseline_run_cnt_delta": 205957,
      "baseline_run_time_ns_delta": 8172612,
      "post_rejit_avg_ns_per_run": 40.480029213505325,
      "post_rejit_run_cnt_delta": 202646,
      "post_rejit_run_time_ns_delta": 8203116,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 1.0201322877833814,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 38.56474913934444,
      "baseline_run_cnt_delta": 226281,
      "baseline_run_time_ns_delta": 8726470,
      "post_rejit_avg_ns_per_run": 37.81941997738806,
      "post_rejit_run_cnt_delta": 228198,
      "post_rejit_run_time_ns_delta": 8630316,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 0.9806733045439161,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 569.2065217391304,
      "baseline_run_cnt_delta": 92,
      "baseline_run_time_ns_delta": 52367,
      "post_rejit_avg_ns_per_run": 1005.3541666666666,
      "post_rejit_run_cnt_delta": 96,
      "post_rejit_run_time_ns_delta": 96514,
      "program": "__x64_sys_open",
      "program_id": 30,
      "ratio": 1.7662379615661263,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 763.0593785721709,
      "baseline_run_cnt_delta": 48115,
      "baseline_run_time_ns_delta": 36714602,
      "post_rejit_avg_ns_per_run": 757.1724306888244,
      "post_rejit_run_cnt_delta": 48982,
      "post_rejit_run_time_ns_delta": 37087820,
      "program": "kretfunc__vmlinux____x64_sys_openat",
      "program_id": 31,
      "ratio": 0.9922850723696469,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 573.9285714285714,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 8035,
      "post_rejit_avg_ns_per_run": 1190.5,
      "post_rejit_run_cnt_delta": 6,
      "post_rejit_run_time_ns_delta": 7143,
      "program": "kretfunc__vmlinux____x64_sys_openat2",
      "program_id": 32,
      "ratio": 2.0742999377722464,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 72.86713489882828,
      "baseline_run_cnt_delta": 1972241,
      "baseline_run_time_ns_delta": 143711551,
      "post_rejit_avg_ns_per_run": 72.92660924746153,
      "post_rejit_run_cnt_delta": 2002582,
      "post_rejit_run_time_ns_delta": 146041515,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 35,
      "ratio": 1.0008162026504241,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 69.22508513179964,
      "baseline_run_cnt_delta": 1972236,
      "baseline_run_time_ns_delta": 136528205,
      "post_rejit_avg_ns_per_run": 68.96204212991513,
      "post_rejit_run_cnt_delta": 2002615,
      "post_rejit_run_time_ns_delta": 138104420,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 36,
      "ratio": 0.9962001779935165,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 779.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 779,
      "post_rejit_avg_ns_per_run": 745.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 745,
      "program": "trace_connect_entry",
      "program_id": 39,
      "ratio": 0.9563543003851092,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 3206.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 3206,
      "post_rejit_avg_ns_per_run": 4658.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 4658,
      "program": "trace_connect_v4_return",
      "program_id": 40,
      "ratio": 1.4529008109794137,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 25.261182108626198,
      "baseline_run_cnt_delta": 2504,
      "baseline_run_time_ns_delta": 63254,
      "post_rejit_avg_ns_per_run": 22.954762698677335,
      "post_rejit_run_cnt_delta": 8997,
      "post_rejit_run_time_ns_delta": 206524,
      "program": "tracepoint__sock__inet_sock_set_state",
      "program_id": 44,
      "ratio": 0.9086970910533413,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_network"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 118.42492912402095,
      "baseline_run_cnt_delta": 104055,
      "baseline_run_time_ns_delta": 12322706,
      "post_rejit_avg_ns_per_run": 123.59516204983314,
      "post_rejit_run_cnt_delta": 97686,
      "post_rejit_run_time_ns_delta": 12073517,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 1.043658315559536,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 190.6069287270344,
      "baseline_run_cnt_delta": 51871,
      "baseline_run_time_ns_delta": 9886972,
      "post_rejit_avg_ns_per_run": 189.83675365256312,
      "post_rejit_run_cnt_delta": 47364,
      "post_rejit_run_time_ns_delta": 8991428,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 0.9959593542605462,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 299.40418118466897,
      "baseline_run_cnt_delta": 574,
      "baseline_run_time_ns_delta": 171858,
      "post_rejit_avg_ns_per_run": 266.47451669595785,
      "post_rejit_run_cnt_delta": 569,
      "post_rejit_run_time_ns_delta": 151624,
      "program": "raw_tracepoint__sched_wakeup_new",
      "program_id": 49,
      "ratio": 0.8900160166153441,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 5191.0,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 15573,
      "post_rejit_avg_ns_per_run": 4707.666666666667,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 14123,
      "program": "tracepoint__sched_process_free",
      "program_id": 131,
      "ratio": 0.9068901303538176,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 3241.8320610687024,
      "baseline_run_cnt_delta": 262,
      "baseline_run_time_ns_delta": 849360,
      "post_rejit_avg_ns_per_run": 3310.8122605363983,
      "post_rejit_run_cnt_delta": 261,
      "post_rejit_run_time_ns_delta": 864122,
      "program": "native_tracer_entry",
      "program_id": 132,
      "ratio": 1.0212781532689748,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 242.76187531620664,
      "baseline_run_cnt_delta": 17789,
      "baseline_run_time_ns_delta": 4318491,
      "post_rejit_avg_ns_per_run": 253.92800326330817,
      "post_rejit_run_cnt_delta": 19612,
      "post_rejit_run_time_ns_delta": 4980036,
      "program": "cil_from_netdev",
      "program_id": 235,
      "ratio": 1.0459962172089716,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 882.7568922305765,
      "baseline_run_cnt_delta": 798,
      "baseline_run_time_ns_delta": 704440,
      "post_rejit_avg_ns_per_run": 899.1816009557945,
      "post_rejit_run_cnt_delta": 837,
      "post_rejit_run_time_ns_delta": 752615,
      "program": "event_exit_acct_process",
      "program_id": 251,
      "ratio": 1.0186061517840044,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1770.5208333333333,
      "baseline_run_cnt_delta": 816,
      "baseline_run_time_ns_delta": 1444745,
      "post_rejit_avg_ns_per_run": 1590.0833333333333,
      "post_rejit_run_cnt_delta": 852,
      "post_rejit_run_time_ns_delta": 1354751,
      "program": "event_wake_up_new_task",
      "program_id": 253,
      "ratio": 0.898087897864329,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6442.590909090909,
      "baseline_run_cnt_delta": 22,
      "baseline_run_time_ns_delta": 141737,
      "post_rejit_avg_ns_per_run": 6337.0,
      "post_rejit_run_cnt_delta": 22,
      "post_rejit_run_time_ns_delta": 139414,
      "program": "event_execve",
      "program_id": 256,
      "ratio": 0.983610489850921,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 693.0454545454545,
      "baseline_run_cnt_delta": 22,
      "baseline_run_time_ns_delta": 15247,
      "post_rejit_avg_ns_per_run": 715.0454545454545,
      "post_rejit_run_cnt_delta": 22,
      "post_rejit_run_time_ns_delta": 15731,
      "program": "tg_kp_bprm_committing_creds",
      "program_id": 257,
      "ratio": 1.0317439496294354,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 555.658098552026,
      "baseline_run_cnt_delta": 8909,
      "baseline_run_time_ns_delta": 4950358,
      "post_rejit_avg_ns_per_run": 412.2800563777308,
      "post_rejit_run_cnt_delta": 7095,
      "post_rejit_run_time_ns_delta": 2925127,
      "program": "generic_kprobe_event",
      "program_id": 285,
      "ratio": 0.7419671511169907,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 333.6653945448423,
      "baseline_run_cnt_delta": 8909,
      "baseline_run_time_ns_delta": 2972625,
      "post_rejit_avg_ns_per_run": 120.34742776603241,
      "post_rejit_run_cnt_delta": 7095,
      "post_rejit_run_time_ns_delta": 853865,
      "program": "generic_retkprobe_event",
      "program_id": 292,
      "ratio": 0.36068297681933736,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 778.153144199494,
      "baseline_run_cnt_delta": 11068,
      "baseline_run_time_ns_delta": 8612599,
      "post_rejit_avg_ns_per_run": 617.569333507922,
      "post_rejit_run_cnt_delta": 7637,
      "post_rejit_run_time_ns_delta": 4716377,
      "program": "generic_kprobe_event",
      "program_id": 295,
      "ratio": 0.7936346953185306,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 825.4081011451257,
      "baseline_run_cnt_delta": 109071,
      "baseline_run_time_ns_delta": 90028087,
      "post_rejit_avg_ns_per_run": 938.7762190308687,
      "post_rejit_run_cnt_delta": 72209,
      "post_rejit_run_time_ns_delta": 67788092,
      "program": "generic_kprobe_event",
      "program_id": 306,
      "ratio": 1.137347958819961,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 574.9811426647211,
      "baseline_run_cnt_delta": 8909,
      "baseline_run_time_ns_delta": 5122507,
      "post_rejit_avg_ns_per_run": 432.45285412262155,
      "post_rejit_run_cnt_delta": 7095,
      "post_rejit_run_time_ns_delta": 3068253,
      "program": "generic_kprobe_event",
      "program_id": 311,
      "ratio": 0.7521165861517486,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 351.9374789538669,
      "baseline_run_cnt_delta": 8909,
      "baseline_run_time_ns_delta": 3135411,
      "post_rejit_avg_ns_per_run": 134.27004933051444,
      "post_rejit_run_cnt_delta": 7095,
      "post_rejit_run_time_ns_delta": 952646,
      "program": "generic_retkprobe_event",
      "program_id": 317,
      "ratio": 0.38151676749413493,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 815.4487712323817,
      "baseline_run_cnt_delta": 11068,
      "baseline_run_time_ns_delta": 9025387,
      "post_rejit_avg_ns_per_run": 741.2500982061018,
      "post_rejit_run_cnt_delta": 7637,
      "post_rejit_run_time_ns_delta": 5660927,
      "program": "generic_kprobe_event",
      "program_id": 322,
      "ratio": 0.9090087867639509,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 872.312209508521,
      "baseline_run_cnt_delta": 53573,
      "baseline_run_time_ns_delta": 46732382,
      "post_rejit_avg_ns_per_run": 968.2944300849263,
      "post_rejit_run_cnt_delta": 35207,
      "post_rejit_run_time_ns_delta": 34090742,
      "program": "generic_kprobe_event",
      "program_id": 328,
      "ratio": 1.1100319582027673,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 878.6421853039749,
      "baseline_run_cnt_delta": 55498,
      "baseline_run_time_ns_delta": 48762884,
      "post_rejit_avg_ns_per_run": 954.9582995513756,
      "post_rejit_run_cnt_delta": 37002,
      "post_rejit_run_time_ns_delta": 35335367,
      "program": "generic_kprobe_event",
      "program_id": 332,
      "ratio": 1.0868568747595455,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 212.08784775530174,
      "baseline_run_cnt_delta": 59273,
      "baseline_run_time_ns_delta": 12571083,
      "post_rejit_avg_ns_per_run": 209.05670093811332,
      "post_rejit_run_cnt_delta": 55537,
      "post_rejit_run_time_ns_delta": 11610382,
      "program": "generic_kprobe_event",
      "program_id": 357,
      "ratio": 0.9857080598946639,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 549.2832590900438,
      "baseline_run_cnt_delta": 393975,
      "baseline_run_time_ns_delta": 216403872,
      "post_rejit_avg_ns_per_run": 586.8675864127878,
      "post_rejit_run_cnt_delta": 395254,
      "post_rejit_run_time_ns_delta": 231961761,
      "program": "generic_kprobe_event",
      "program_id": 362,
      "ratio": 1.0684243087710468,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 49.39188695241625,
      "baseline_run_cnt_delta": 393958,
      "baseline_run_time_ns_delta": 19458329,
      "post_rejit_avg_ns_per_run": 53.0990413152881,
      "post_rejit_run_cnt_delta": 395229,
      "post_rejit_run_time_ns_delta": 20986281,
      "program": "generic_retkprobe_event",
      "program_id": 368,
      "ratio": 1.0750559371510404,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3132.719339164237,
      "baseline_run_cnt_delta": 5145,
      "baseline_run_time_ns_delta": 16117841,
      "post_rejit_avg_ns_per_run": 4124.291184682888,
      "post_rejit_run_cnt_delta": 5014,
      "post_rejit_run_time_ns_delta": 20679196,
      "program": "generic_kprobe_event",
      "program_id": 377,
      "ratio": 1.3165211237158538,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 62.15451895043732,
      "baseline_run_cnt_delta": 5145,
      "baseline_run_time_ns_delta": 319785,
      "post_rejit_avg_ns_per_run": 71.57638611886718,
      "post_rejit_run_cnt_delta": 5014,
      "post_rejit_run_time_ns_delta": 358884,
      "program": "generic_retkprobe_event",
      "program_id": 378,
      "ratio": 1.1515878061246512,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5942.227272727273,
      "baseline_run_cnt_delta": 22,
      "baseline_run_time_ns_delta": 130729,
      "post_rejit_avg_ns_per_run": 6074.227272727273,
      "post_rejit_run_cnt_delta": 22,
      "post_rejit_run_time_ns_delta": 133633,
      "program": "generic_kprobe_event",
      "program_id": 435,
      "ratio": 1.0222138928623334,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 601.6046417750324,
      "baseline_run_cnt_delta": 6151009,
      "baseline_run_time_ns_delta": 3700475566,
      "post_rejit_avg_ns_per_run": 604.5464831951234,
      "post_rejit_run_cnt_delta": 5806023,
      "post_rejit_run_time_ns_delta": 3510010786,
      "program": "generic_tracepoint_event",
      "program_id": 439,
      "ratio": 1.0048899912264824,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5758.136363636364,
      "baseline_run_cnt_delta": 22,
      "baseline_run_time_ns_delta": 126679,
      "post_rejit_avg_ns_per_run": 4964.954545454545,
      "post_rejit_run_cnt_delta": 22,
      "post_rejit_run_time_ns_delta": 109229,
      "program": "generic_rawtp_event",
      "program_id": 448,
      "ratio": 0.8622502545804749,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 909.8381802476246,
      "baseline_run_cnt_delta": 3473,
      "baseline_run_time_ns_delta": 3159868,
      "post_rejit_avg_ns_per_run": 743.1604054859869,
      "post_rejit_run_cnt_delta": 1677,
      "post_rejit_run_time_ns_delta": 1246280,
      "program": "generic_kprobe_event",
      "program_id": 450,
      "ratio": 0.8168050337080005,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4099.38112827401,
      "baseline_run_cnt_delta": 2978,
      "baseline_run_time_ns_delta": 12207957,
      "post_rejit_avg_ns_per_run": 3947.9811694747273,
      "post_rejit_run_cnt_delta": 3027,
      "post_rejit_run_time_ns_delta": 11950539,
      "program": "generic_kprobe_event",
      "program_id": 457,
      "ratio": 0.9630676060454453,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 580.7429565607812,
      "baseline_run_cnt_delta": 8909,
      "baseline_run_time_ns_delta": 5173839,
      "post_rejit_avg_ns_per_run": 447.1148696264975,
      "post_rejit_run_cnt_delta": 7095,
      "post_rejit_run_time_ns_delta": 3172280,
      "program": "generic_kprobe_event",
      "program_id": 475,
      "ratio": 0.7699014935529434,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 376.1632057469974,
      "baseline_run_cnt_delta": 8909,
      "baseline_run_time_ns_delta": 3351238,
      "post_rejit_avg_ns_per_run": 133.88090204369274,
      "post_rejit_run_cnt_delta": 7095,
      "post_rejit_run_time_ns_delta": 949885,
      "program": "generic_retkprobe_event",
      "program_id": 478,
      "ratio": 0.3559117425582005,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 914.83330321648,
      "baseline_run_cnt_delta": 11068,
      "baseline_run_time_ns_delta": 10125375,
      "post_rejit_avg_ns_per_run": 826.1457378551787,
      "post_rejit_run_cnt_delta": 7637,
      "post_rejit_run_time_ns_delta": 6309275,
      "program": "generic_kprobe_event",
      "program_id": 485,
      "ratio": 0.9030560375868665,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2649.125,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 21193,
      "post_rejit_avg_ns_per_run": 2529.625,
      "post_rejit_run_cnt_delta": 16,
      "post_rejit_run_time_ns_delta": 40474,
      "program": "generic_kprobe_event",
      "program_id": 494,
      "ratio": 0.9548907658189024,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5138.666666666667,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 15416,
      "post_rejit_avg_ns_per_run": 4311.6,
      "post_rejit_run_cnt_delta": 5,
      "post_rejit_run_time_ns_delta": 21558,
      "program": "generic_kprobe_event",
      "program_id": 501,
      "ratio": 0.8390503373118838,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3577.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 3577,
      "post_rejit_avg_ns_per_run": 5096.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 10192,
      "program": "generic_kprobe_event",
      "program_id": 506,
      "ratio": 1.4246575342465753,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3141.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 3141,
      "post_rejit_avg_ns_per_run": 3747.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 7494,
      "program": "generic_retkprobe_event",
      "program_id": 512,
      "ratio": 1.1929321872015282,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7076.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 7076,
      "post_rejit_avg_ns_per_run": 8314.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 16628,
      "program": "generic_kprobe_event",
      "program_id": 514,
      "ratio": 1.1749576031656304,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5168.666666666667,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 15506,
      "post_rejit_avg_ns_per_run": 4501.0,
      "post_rejit_run_cnt_delta": 5,
      "post_rejit_run_time_ns_delta": 22505,
      "program": "generic_kprobe_event",
      "program_id": 520,
      "ratio": 0.8708241970849993,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 576.3601095836799,
      "baseline_run_cnt_delta": 102205,
      "baseline_run_time_ns_delta": 58906885,
      "post_rejit_avg_ns_per_run": 532.7678040381907,
      "post_rejit_run_cnt_delta": 102224,
      "post_rejit_run_time_ns_delta": 54461656,
      "program": "generic_kprobe_event",
      "program_id": 529,
      "ratio": 0.9243661994981278,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 57.5328125,
      "baseline_run_cnt_delta": 640,
      "baseline_run_time_ns_delta": 36821,
      "post_rejit_avg_ns_per_run": 68.638671875,
      "post_rejit_run_cnt_delta": 512,
      "post_rejit_run_time_ns_delta": 35143,
      "program": "balancer_ingress",
      "program_id": 553,
      "ratio": 1.1930352244643003,
      "runner": "katran",
      "type": "xdp",
      "workload": "test_run"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 160.32735187204418,
      "baseline_run_cnt_delta": 2330367,
      "baseline_run_time_ns_delta": 373621570,
      "post_rejit_avg_ns_per_run": 161.24029695250493,
      "post_rejit_run_cnt_delta": 2250865,
      "post_rejit_run_time_ns_delta": 362930141,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 570,
      "ratio": 1.0056942565931568,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 303.0312095123696,
      "baseline_run_cnt_delta": 2330187,
      "baseline_run_time_ns_delta": 706119385,
      "post_rejit_avg_ns_per_run": 302.91174040438324,
      "post_rejit_run_cnt_delta": 2251132,
      "post_rejit_run_time_ns_delta": 681894312,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 573,
      "ratio": 0.9996057531229914,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 276.74220731060365,
      "baseline_run_cnt_delta": 2329876,
      "baseline_run_time_ns_delta": 644775027,
      "post_rejit_avg_ns_per_run": 278.05347673632485,
      "post_rejit_run_cnt_delta": 2251278,
      "post_rejit_run_time_ns_delta": 625975675,
      "program": "trace_sys_enter",
      "program_id": 576,
      "ratio": 1.0047382343245153,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 268.74460447249623,
      "baseline_run_cnt_delta": 2329661,
      "baseline_run_time_ns_delta": 626083824,
      "post_rejit_avg_ns_per_run": 269.91762982993754,
      "post_rejit_run_cnt_delta": 2251349,
      "post_rejit_run_time_ns_delta": 607678786,
      "program": "trace_sys_exit",
      "program_id": 577,
      "ratio": 1.0043648331461157,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 71.00305315067659,
      "baseline_run_cnt_delta": 263007,
      "baseline_run_time_ns_delta": 18674300,
      "post_rejit_avg_ns_per_run": 71.43898831590033,
      "post_rejit_run_cnt_delta": 263007,
      "post_rejit_run_time_ns_delta": 18788954,
      "program": "trace_arch_prctl",
      "program_id": 582,
      "ratio": 1.006139667885811,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 272.203218925732,
      "baseline_run_cnt_delta": 263007,
      "baseline_run_time_ns_delta": 71591352,
      "post_rejit_avg_ns_per_run": 271.2570768078416,
      "post_rejit_run_cnt_delta": 263007,
      "post_rejit_run_time_ns_delta": 71342510,
      "program": "trace_ret_arch_prctl",
      "program_id": 583,
      "ratio": 0.9965241332500606,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 741.8571428571429,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 10386,
      "post_rejit_avg_ns_per_run": 717.8571428571429,
      "post_rejit_run_cnt_delta": 14,
      "post_rejit_run_time_ns_delta": 10050,
      "program": "trace_dup2",
      "program_id": 586,
      "ratio": 0.9676487579433853,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2003.5714285714287,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 28050,
      "post_rejit_avg_ns_per_run": 2140.5714285714284,
      "post_rejit_run_cnt_delta": 14,
      "post_rejit_run_time_ns_delta": 29968,
      "program": "trace_ret_dup2",
      "program_id": 587,
      "ratio": 1.0683778966131907,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2259.7731755424065,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 2291410,
      "post_rejit_avg_ns_per_run": 2419.3984220907296,
      "post_rejit_run_cnt_delta": 1014,
      "post_rejit_run_time_ns_delta": 2453270,
      "program": "tracepoint__sched__sched_process_fork",
      "program_id": 595,
      "ratio": 1.070637729607534,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 5312.571428571428,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 37188,
      "post_rejit_avg_ns_per_run": 6566.571428571428,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 45966,
      "program": "tracepoint__sched__sched_process_exec",
      "program_id": 603,
      "ratio": 1.2360438851242337,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1322.8076923076924,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 1341327,
      "post_rejit_avg_ns_per_run": 1274.1854043392505,
      "post_rejit_run_cnt_delta": 1014,
      "post_rejit_run_time_ns_delta": 1292024,
      "program": "tracepoint__sched__sched_process_exit",
      "program_id": 605,
      "ratio": 0.9632431167045769,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 625.3974358974359,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 634153,
      "post_rejit_avg_ns_per_run": 623.2470472440945,
      "post_rejit_run_cnt_delta": 1016,
      "post_rejit_run_time_ns_delta": 633219,
      "program": "tracepoint__sched__sched_process_free",
      "program_id": 606,
      "ratio": 0.9965615646468782,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 438.2970645376857,
      "baseline_run_cnt_delta": 225961,
      "baseline_run_time_ns_delta": 99038043,
      "post_rejit_avg_ns_per_run": 434.95716131907307,
      "post_rejit_run_cnt_delta": 224400,
      "post_rejit_run_time_ns_delta": 97604387,
      "program": "tracepoint__sched__sched_switch",
      "program_id": 608,
      "ratio": 0.9923798184180505,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 18.549985255086995,
      "baseline_run_cnt_delta": 6782,
      "baseline_run_time_ns_delta": 125806,
      "post_rejit_avg_ns_per_run": 18.605945699984833,
      "post_rejit_run_cnt_delta": 6593,
      "post_rejit_run_time_ns_delta": 122669,
      "program": "trace_filldir64",
      "program_id": 609,
      "ratio": 1.0030167379719341,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 771.491124260355,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 782292,
      "post_rejit_avg_ns_per_run": 750.1272189349113,
      "post_rejit_run_cnt_delta": 1014,
      "post_rejit_run_time_ns_delta": 760629,
      "program": "trace_do_exit",
      "program_id": 611,
      "ratio": 0.972308294089675,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 810.2857142857143,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 17016,
      "post_rejit_avg_ns_per_run": 887.0,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 18627,
      "program": "trace_security_file_ioctl",
      "program_id": 615,
      "ratio": 1.094675599435825,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3513.5714285714284,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 24595,
      "post_rejit_avg_ns_per_run": 4088.4285714285716,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 28619,
      "program": "trace_security_bprm_check",
      "program_id": 620,
      "ratio": 1.1636104899369792,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 621.3379392025266,
      "baseline_run_cnt_delta": 17731,
      "baseline_run_time_ns_delta": 11016943,
      "post_rejit_avg_ns_per_run": 659.0068798285682,
      "post_rejit_run_cnt_delta": 17733,
      "post_rejit_run_time_ns_delta": 11686169,
      "program": "trace_security_file_open",
      "program_id": 621,
      "ratio": 1.0606255279926875,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1536.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 3073,
      "post_rejit_avg_ns_per_run": 1588.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 3177,
      "program": "trace_security_inode_unlink",
      "program_id": 623,
      "ratio": 1.0338431500162708,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 330.22564535955746,
      "baseline_run_cnt_delta": 13016,
      "baseline_run_time_ns_delta": 4298217,
      "post_rejit_avg_ns_per_run": 320.3696704309749,
      "post_rejit_run_cnt_delta": 13017,
      "post_rejit_run_time_ns_delta": 4170252,
      "program": "trace_commit_creds",
      "program_id": 624,
      "ratio": 0.9701538173455574,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 440.1094674556213,
      "baseline_run_cnt_delta": 1014,
      "baseline_run_time_ns_delta": 446271,
      "post_rejit_avg_ns_per_run": 429.81360946745565,
      "post_rejit_run_cnt_delta": 1014,
      "post_rejit_run_time_ns_delta": 435831,
      "program": "trace_switch_task_namespaces",
      "program_id": 625,
      "ratio": 0.9766061429041994,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 179.16655771872485,
      "baseline_run_cnt_delta": 105555,
      "baseline_run_time_ns_delta": 18911926,
      "post_rejit_avg_ns_per_run": 182.52790049487118,
      "post_rejit_run_cnt_delta": 105482,
      "post_rejit_run_time_ns_delta": 19253408,
      "program": "trace_cap_capable",
      "program_id": 626,
      "ratio": 1.018760994344845,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 681.5,
      "baseline_run_cnt_delta": 34,
      "baseline_run_time_ns_delta": 23171,
      "post_rejit_avg_ns_per_run": 746.8235294117648,
      "post_rejit_run_cnt_delta": 34,
      "post_rejit_run_time_ns_delta": 25392,
      "program": "trace_security_socket_create",
      "program_id": 627,
      "ratio": 1.095852574338613,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 751.5454545454545,
      "baseline_run_cnt_delta": 33,
      "baseline_run_time_ns_delta": 24801,
      "post_rejit_avg_ns_per_run": 834.6060606060606,
      "post_rejit_run_cnt_delta": 33,
      "post_rejit_run_time_ns_delta": 27542,
      "program": "trace_security_socket_connect",
      "program_id": 633,
      "ratio": 1.1105197371073747,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3510.4166666666665,
      "baseline_run_cnt_delta": 24,
      "baseline_run_time_ns_delta": 84250,
      "post_rejit_avg_ns_per_run": 3276.521739130435,
      "post_rejit_run_cnt_delta": 23,
      "post_rejit_run_time_ns_delta": 75360,
      "program": "trace_security_socket_accept",
      "program_id": 634,
      "ratio": 0.9333711779125275,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1745.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1745,
      "post_rejit_avg_ns_per_run": 1687.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1687,
      "program": "trace_security_socket_bind",
      "program_id": 635,
      "ratio": 0.9667621776504298,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 115.73903417543909,
      "baseline_run_cnt_delta": 141827,
      "baseline_run_time_ns_delta": 16414920,
      "post_rejit_avg_ns_per_run": 116.36114803499224,
      "post_rejit_run_cnt_delta": 143689,
      "post_rejit_run_time_ns_delta": 16719817,
      "program": "trace_vfs_write",
      "program_id": 639,
      "ratio": 1.0053751430015403,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 44.78651011917354,
      "baseline_run_cnt_delta": 141810,
      "baseline_run_time_ns_delta": 6351175,
      "post_rejit_avg_ns_per_run": 48.3179477544431,
      "post_rejit_run_cnt_delta": 143706,
      "post_rejit_run_time_ns_delta": 6943579,
      "program": "vfs_write_magic_enter",
      "program_id": 640,
      "ratio": 1.078850475865895,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 34.53827111734877,
      "baseline_run_cnt_delta": 141791,
      "baseline_run_time_ns_delta": 4897216,
      "post_rejit_avg_ns_per_run": 34.14554385867259,
      "post_rejit_run_cnt_delta": 143723,
      "post_rejit_run_time_ns_delta": 4907500,
      "program": "trace_ret_vfs_write",
      "program_id": 641,
      "ratio": 0.9886292148978206,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 43.564003075816046,
      "baseline_run_cnt_delta": 141751,
      "baseline_run_time_ns_delta": 6175241,
      "post_rejit_avg_ns_per_run": 43.4930267175838,
      "post_rejit_run_cnt_delta": 143763,
      "post_rejit_run_time_ns_delta": 6252688,
      "program": "vfs_write_magic_return",
      "program_id": 642,
      "ratio": 0.9983707567436187,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 112.92446198385363,
      "baseline_run_cnt_delta": 127459,
      "baseline_run_time_ns_delta": 14393239,
      "post_rejit_avg_ns_per_run": 118.89528740169435,
      "post_rejit_run_cnt_delta": 131732,
      "post_rejit_run_time_ns_delta": 15662314,
      "program": "trace_vfs_read",
      "program_id": 654,
      "ratio": 1.0528745084363957,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 39.25005100039231,
      "baseline_run_cnt_delta": 127450,
      "baseline_run_time_ns_delta": 5002419,
      "post_rejit_avg_ns_per_run": 40.00051617212822,
      "post_rejit_run_cnt_delta": 131739,
      "post_rejit_run_time_ns_delta": 5269628,
      "program": "trace_ret_vfs_read",
      "program_id": 655,
      "ratio": 1.0191201069198206,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 149.9758957654723,
      "baseline_run_cnt_delta": 1535,
      "baseline_run_time_ns_delta": 230213,
      "post_rejit_avg_ns_per_run": 173.9739413680782,
      "post_rejit_run_cnt_delta": 1535,
      "post_rejit_run_time_ns_delta": 267050,
      "program": "trace_mmap_alert",
      "program_id": 660,
      "ratio": 1.1600126839057743,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 121.66959385290889,
      "baseline_run_cnt_delta": 911,
      "baseline_run_time_ns_delta": 110841,
      "post_rejit_avg_ns_per_run": 156.9681668496158,
      "post_rejit_run_cnt_delta": 911,
      "post_rejit_run_time_ns_delta": 142998,
      "program": "trace_do_mmap",
      "program_id": 661,
      "ratio": 1.290118277532682,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 41.57409440175631,
      "baseline_run_cnt_delta": 911,
      "baseline_run_time_ns_delta": 37874,
      "post_rejit_avg_ns_per_run": 44.246981339187705,
      "post_rejit_run_cnt_delta": 911,
      "post_rejit_run_time_ns_delta": 40309,
      "program": "trace_ret_do_mmap",
      "program_id": 662,
      "ratio": 1.0642921265247927,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 555.2612513721185,
      "baseline_run_cnt_delta": 911,
      "baseline_run_time_ns_delta": 505843,
      "post_rejit_avg_ns_per_run": 644.5082327113063,
      "post_rejit_run_cnt_delta": 911,
      "post_rejit_run_time_ns_delta": 587147,
      "program": "trace_security_mmap_file",
      "program_id": 663,
      "ratio": 1.160729712578804,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 857.6755319148937,
      "baseline_run_cnt_delta": 188,
      "baseline_run_time_ns_delta": 161243,
      "post_rejit_avg_ns_per_run": 966.7021276595744,
      "post_rejit_run_cnt_delta": 188,
      "post_rejit_run_time_ns_delta": 181740,
      "program": "trace_security_file_mprotect",
      "program_id": 664,
      "ratio": 1.12711869662559,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 301.4762700306853,
      "baseline_run_cnt_delta": 29330,
      "baseline_run_time_ns_delta": 8842299,
      "post_rejit_avg_ns_per_run": 326.4642869024252,
      "post_rejit_run_cnt_delta": 30059,
      "post_rejit_run_time_ns_delta": 9813190,
      "program": "trace_security_bpf",
      "program_id": 666,
      "ratio": 1.0828855182173924,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 260.79046862589354,
      "baseline_run_cnt_delta": 6295,
      "baseline_run_time_ns_delta": 1641676,
      "post_rejit_avg_ns_per_run": 290.2481334392375,
      "post_rejit_run_cnt_delta": 6295,
      "post_rejit_run_time_ns_delta": 1827112,
      "program": "trace_security_bpf_map",
      "program_id": 669,
      "ratio": 1.112955296903896,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 882.075,
      "baseline_run_cnt_delta": 520,
      "baseline_run_time_ns_delta": 458679,
      "post_rejit_avg_ns_per_run": 1139.6903846153846,
      "post_rejit_run_cnt_delta": 520,
      "post_rejit_run_time_ns_delta": 592639,
      "program": "trace_security_bpf_prog",
      "program_id": 670,
      "ratio": 1.2920561002356767,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1642.2142857142858,
      "baseline_run_cnt_delta": 14,
      "baseline_run_time_ns_delta": 22991,
      "post_rejit_avg_ns_per_run": 1943.5,
      "post_rejit_run_cnt_delta": 14,
      "post_rejit_run_time_ns_delta": 27209,
      "program": "trace_load_elf_phdrs",
      "program_id": 684,
      "ratio": 1.1834630942542734,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 42.55624486548019,
      "baseline_run_cnt_delta": 271447,
      "baseline_run_time_ns_delta": 11551765,
      "post_rejit_avg_ns_per_run": 44.973798811008116,
      "post_rejit_run_cnt_delta": 276705,
      "post_rejit_run_time_ns_delta": 12444475,
      "program": "trace_security_file_permission",
      "program_id": 685,
      "ratio": 1.0568084414677514,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 845.7651006711409,
      "baseline_run_cnt_delta": 1043,
      "baseline_run_time_ns_delta": 882133,
      "post_rejit_avg_ns_per_run": 810.5637583892617,
      "post_rejit_run_cnt_delta": 1043,
      "post_rejit_run_time_ns_delta": 845418,
      "program": "tracepoint__task__task_rename",
      "program_id": 686,
      "ratio": 0.958379292011522,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 709.4953703703703,
      "baseline_run_cnt_delta": 2592,
      "baseline_run_time_ns_delta": 1839012,
      "post_rejit_avg_ns_per_run": 693.1412037037037,
      "post_rejit_run_cnt_delta": 2592,
      "post_rejit_run_time_ns_delta": 1796622,
      "program": "trace_do_sigaction",
      "program_id": 690,
      "ratio": 0.976949579448095,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 339.74481946624803,
      "baseline_run_cnt_delta": 25480,
      "baseline_run_time_ns_delta": 8656698,
      "post_rejit_avg_ns_per_run": 389.8672552481852,
      "post_rejit_run_cnt_delta": 25485,
      "post_rejit_run_time_ns_delta": 9935767,
      "program": "trace_fd_install",
      "program_id": 694,
      "ratio": 1.1475296543466988,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1102.9742313323572,
      "baseline_run_cnt_delta": 3415,
      "baseline_run_time_ns_delta": 3766657,
      "post_rejit_avg_ns_per_run": 1128.443045387994,
      "post_rejit_run_cnt_delta": 3415,
      "post_rejit_run_time_ns_delta": 3853633,
      "program": "trace_filp_close",
      "program_id": 695,
      "ratio": 1.0230910327114997,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 213.94444444444446,
      "baseline_run_cnt_delta": 288,
      "baseline_run_time_ns_delta": 61616,
      "post_rejit_avg_ns_per_run": 223.31944444444446,
      "post_rejit_run_cnt_delta": 288,
      "post_rejit_run_time_ns_delta": 64316,
      "program": "trace_file_update_time",
      "program_id": 696,
      "ratio": 1.043819787068294,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 36.447916666666664,
      "baseline_run_cnt_delta": 288,
      "baseline_run_time_ns_delta": 10497,
      "post_rejit_avg_ns_per_run": 37.05902777777778,
      "post_rejit_run_cnt_delta": 288,
      "post_rejit_run_time_ns_delta": 10673,
      "program": "trace_ret_file_update_time",
      "program_id": 697,
      "ratio": 1.0167666952462608,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 140.71428571428572,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 985,
      "post_rejit_avg_ns_per_run": 149.71428571428572,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 1048,
      "program": "trace_exec_binprm",
      "program_id": 703,
      "ratio": 1.063959390862944,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3657.1428571428573,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 25600,
      "post_rejit_avg_ns_per_run": 4435.571428571428,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 31049,
      "program": "trace_security_bprm_creds_for_exec",
      "program_id": 704,
      "ratio": 1.2128515624999998,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 4691.857142857143,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 32843,
      "post_rejit_avg_ns_per_run": 4690.714285714285,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 32835,
      "program": "trace_execute_finished",
      "program_id": 705,
      "ratio": 0.9997564168924884,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 3061.0,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 21427,
      "post_rejit_avg_ns_per_run": 3440.714285714286,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 24085,
      "program": "trace_set_fs_pwd",
      "program_id": 707,
      "ratio": 1.124049096933775,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 278.1142335396165,
      "baseline_run_cnt_delta": 19714,
      "baseline_run_time_ns_delta": 5482744,
      "post_rejit_avg_ns_per_run": 271.6712488586791,
      "post_rejit_run_cnt_delta": 19714,
      "post_rejit_run_time_ns_delta": 5355727,
      "program": "trace_security_task_setrlimit",
      "program_id": 708,
      "ratio": 0.9768333155806654,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 355.9416180512553,
      "baseline_run_cnt_delta": 92049,
      "baseline_run_time_ns_delta": 32764070,
      "post_rejit_avg_ns_per_run": 350.16265250029875,
      "post_rejit_run_cnt_delta": 92049,
      "post_rejit_run_time_ns_delta": 32232122,
      "program": "trace_security_task_prctl",
      "program_id": 711,
      "ratio": 0.983764288136364,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 192.68965517241378,
      "baseline_run_cnt_delta": 58,
      "baseline_run_time_ns_delta": 11176,
      "post_rejit_avg_ns_per_run": 192.4561403508772,
      "post_rejit_run_cnt_delta": 57,
      "post_rejit_run_time_ns_delta": 10970,
      "program": "trace_sock_alloc_file",
      "program_id": 714,
      "ratio": 0.9987881299526555,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1203.9310344827586,
      "baseline_run_cnt_delta": 58,
      "baseline_run_time_ns_delta": 69828,
      "post_rejit_avg_ns_per_run": 1062.2631578947369,
      "post_rejit_run_cnt_delta": 57,
      "post_rejit_run_time_ns_delta": 60549,
      "program": "trace_ret_sock_alloc_file",
      "program_id": 715,
      "ratio": 0.8823289104355665,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 995.5714285714286,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 6969,
      "post_rejit_avg_ns_per_run": 262.6,
      "post_rejit_run_cnt_delta": 5,
      "post_rejit_run_time_ns_delta": 1313,
      "program": "trace_security_socket_recvmsg",
      "program_id": 717,
      "ratio": 0.26376811594202904,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 2116.0,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 6348,
      "post_rejit_avg_ns_per_run": 389.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 389,
      "program": "trace_security_socket_sendmsg",
      "program_id": 718,
      "ratio": 0.1838374291115312,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1298.4615384615386,
      "baseline_run_cnt_delta": 13,
      "baseline_run_time_ns_delta": 16880,
      "post_rejit_avg_ns_per_run": 211.25,
      "post_rejit_run_cnt_delta": 4,
      "post_rejit_run_time_ns_delta": 845,
      "program": "cgroup_bpf_run_filter_skb",
      "program_id": 719,
      "ratio": 0.1626925355450237,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 99.57142857142857,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 697,
      "post_rejit_avg_ns_per_run": 169.14285714285714,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 1184,
      "program": "empty_kprobe",
      "program_id": 725,
      "ratio": 1.6987087517934003,
      "runner": "tracee",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 1059.7142857142858,
      "baseline_run_cnt_delta": 7,
      "baseline_run_time_ns_delta": 7418,
      "post_rejit_avg_ns_per_run": 1268.2857142857142,
      "post_rejit_run_cnt_delta": 7,
      "post_rejit_run_time_ns_delta": 8878,
      "program": "tracepoint__exec_test",
      "program_id": 726,
      "ratio": 1.1968185494742516,
      "runner": "tracee",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "tracee/monitor",
      "baseline_avg_ns_per_run": 267.2237703068592,
      "baseline_run_cnt_delta": 17728,
      "baseline_run_time_ns_delta": 4737343,
      "post_rejit_avg_ns_per_run": 284.4238989454689,
      "post_rejit_run_cnt_delta": 17733,
      "post_rejit_run_time_ns_delta": 5043689,
      "program": "lsm_file_open_test",
      "program_id": 727,
      "ratio": 1.0643660128695078,
      "runner": "tracee",
      "type": "lsm",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 246.29166714339652,
      "baseline_run_cnt_delta": 87401,
      "baseline_run_time_ns_delta": 21526138,
      "post_rejit_avg_ns_per_run": 283.09601190405897,
      "post_rejit_run_cnt_delta": 84677,
      "post_rejit_run_time_ns_delta": 23971721,
      "program": "cap_capable",
      "program_id": 734,
      "ratio": 1.1494339828364317,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 653.7496375936216,
      "baseline_run_cnt_delta": 49668,
      "baseline_run_time_ns_delta": 32470437,
      "post_rejit_avg_ns_per_run": 701.4787145407657,
      "post_rejit_run_cnt_delta": 50410,
      "post_rejit_run_time_ns_delta": 35361542,
      "program": "block_io_start",
      "program_id": 740,
      "ratio": 1.0730081887660075,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 1646.4040574809806,
      "baseline_run_cnt_delta": 49686,
      "baseline_run_time_ns_delta": 81803232,
      "post_rejit_avg_ns_per_run": 1666.4350257834192,
      "post_rejit_run_cnt_delta": 50420,
      "post_rejit_run_time_ns_delta": 84021654,
      "program": "block_io_done",
      "program_id": 741,
      "ratio": 1.0121664959530567,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1444.5,
      "baseline_run_cnt_delta": 10,
      "baseline_run_time_ns_delta": 14445,
      "post_rejit_avg_ns_per_run": 1595.4666666666667,
      "post_rejit_run_cnt_delta": 15,
      "post_rejit_run_time_ns_delta": 23932,
      "program": "1",
      "program_id": 747,
      "ratio": 1.104511364947502,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 51.689582040746245,
      "baseline_run_cnt_delta": 512538,
      "baseline_run_time_ns_delta": 26492875,
      "post_rejit_avg_ns_per_run": 55.8353386626833,
      "post_rejit_run_cnt_delta": 500749,
      "post_rejit_run_time_ns_delta": 27959490,
      "program": "vfs_create",
      "program_id": 748,
      "ratio": 1.080204878009441,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 161.8513327837318,
      "baseline_run_cnt_delta": 50946,
      "baseline_run_time_ns_delta": 8245678,
      "post_rejit_avg_ns_per_run": 174.0483701587835,
      "post_rejit_run_cnt_delta": 47612,
      "post_rejit_run_time_ns_delta": 8286791,
      "program": "sched_wakeup",
      "program_id": 754,
      "ratio": 1.0753595115052255,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 275.96478873239437,
      "baseline_run_cnt_delta": 568,
      "baseline_run_time_ns_delta": 156748,
      "post_rejit_avg_ns_per_run": 291.3651877133106,
      "post_rejit_run_cnt_delta": 586,
      "post_rejit_run_time_ns_delta": 170740,
      "program": "tracepoint_sched_sched_wakeup_new",
      "program_id": 755,
      "ratio": 1.0558056665549826,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 170.241026241114,
      "baseline_run_cnt_delta": 102549,
      "baseline_run_time_ns_delta": 17458047,
      "post_rejit_avg_ns_per_run": 179.78740247462522,
      "post_rejit_run_cnt_delta": 96257,
      "post_rejit_run_time_ns_delta": 17305796,
      "program": "sched_switch",
      "program_id": 756,
      "ratio": 1.0560756501784159,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 1503.125,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 12025,
      "post_rejit_avg_ns_per_run": 1755.625,
      "post_rejit_run_cnt_delta": 8,
      "post_rejit_run_time_ns_delta": 14045,
      "program": "tcp_set_state",
      "program_id": 763,
      "ratio": 1.167983367983368,
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
          "6": {
            "avg_ns_per_run": 250.4598474546207,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 84565,
            "run_time_ns_delta": 21180137,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.8796335860000113,
            "ops_per_sec": 3168.702689908183,
            "ops_total": 5956.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [5078]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5078] get                 200      0.37      0.01      0.17       546.32        1130.55\nstress-ng: info:  [5078] skipped: 0\nstress-ng: info:  [5078] passed: 1: get (1)\nstress-ng: info:  [5078] failed: 0\nstress-ng: info:  [5078] metrics untrustworthy: 0\nstress-ng: info:  [5078] successful run completed in 0.37 secs\nstress-ng: info:  [5080] setting to a 1 secs run per stressor\nstress-ng: info:  [5080] dispatching hogs: 1 prctl\nstress-ng: info:  [5080] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5080] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5080]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5080] prctl               732      1.00      0.70      0.22       731.63         795.46\nstress-ng: info:  [5080] skipped: 0\nstress-ng: info:  [5080] passed: 1: prctl (1)\nstress-ng: info:  [5080] failed: 0\nstress-ng: info:  [5080] metrics untrustworthy: 0\nstress-ng: info:  [5080] successful run completed in 1.00 secs\nstress-ng: info:  [5814] setting to a 1 secs run per stressor\nstress-ng: info:  [5814] dispatching hogs: 1 set\nstress-ng: info:  [5814] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5814] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5814]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5814] set                1000      0.19      0.00      0.19      5196.93        5185.35\nstress-ng: info:  [5814] skipped: 0\nstress-ng: info:  [5814] passed: 1: set (1)\nstress-ng: info:  [5814] failed: 0\nstress-ng: info:  [5814] metrics untrustworthy: 0\nstress-ng: info:  [5814] successful run completed in 0.19 secs\nstress-ng: info:  [5816] setting to a 1 secs run per stressor\nstress-ng: info:  [5816] dispatching hogs: 1 timerfd\nstress-ng: info:  [5816] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5816] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5816]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5816] timerfd            1024      0.02      0.00      0.02     53891.20       52726.43\nstress-ng: info:  [5816] skipped: 0\nstress-ng: info:  [5816] passed: 1: timerfd (1)\nstress-ng: info:  [5816] failed: 0\nstress-ng: info:  [5816] metrics untrustworthy: 0\nstress-ng: info:  [5816] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 285.93199499070244,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 79053,
            "run_time_ns_delta": 22603782,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.9136953720000065,
            "ops_per_sec": 3077.8148320672117,
            "ops_total": 5890.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [5377]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5377] get                 200      0.41      0.03      0.15       490.77        1062.85\nstress-ng: info:  [5377] skipped: 0\nstress-ng: info:  [5377] passed: 1: get (1)\nstress-ng: info:  [5377] failed: 0\nstress-ng: info:  [5377] metrics untrustworthy: 0\nstress-ng: info:  [5377] successful run completed in 0.41 secs\nstress-ng: info:  [5379] setting to a 1 secs run per stressor\nstress-ng: info:  [5379] dispatching hogs: 1 prctl\nstress-ng: info:  [5379] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [5379] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [5379]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [5379] prctl               666      1.00      0.70      0.23       665.55         719.01\nstress-ng: info:  [5379] skipped: 0\nstress-ng: info:  [5379] passed: 1: prctl (1)\nstress-ng: info:  [5379] failed: 0\nstress-ng: info:  [5379] metrics untrustworthy: 0\nstress-ng: info:  [5379] successful run completed in 1.00 secs\nstress-ng: info:  [6047] setting to a 1 secs run per stressor\nstress-ng: info:  [6047] dispatching hogs: 1 set\nstress-ng: info:  [6047] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6047] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6047]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6047] set                1000      0.20      0.00      0.20      5061.53        5050.35\nstress-ng: info:  [6047] skipped: 0\nstress-ng: info:  [6047] passed: 1: set (1)\nstress-ng: info:  [6047] failed: 0\nstress-ng: info:  [6047] metrics untrustworthy: 0\nstress-ng: info:  [6047] successful run completed in 0.20 secs\nstress-ng: info:  [6049] setting to a 1 secs run per stressor\nstress-ng: info:  [6049] dispatching hogs: 1 timerfd\nstress-ng: info:  [6049] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6049] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6049]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6049] timerfd            1024      0.02      0.00      0.02     44215.11       51318.03\nstress-ng: info:  [6049] skipped: 0\nstress-ng: info:  [6049] passed: 1: timerfd (1)\nstress-ng: info:  [6049] failed: 0\nstress-ng: info:  [6049] metrics untrustworthy: 0\nstress-ng: info:  [6049] successful run completed in 0.03 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 6
          }
        ],
        "program_counts": {
          "applied": 0,
          "not_applied": 1,
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
            "avg_ns_per_run": 300.22222222222223,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 2702,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 140.33333333333334,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 1263,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.620384924999996,
            "ops_per_sec": 4385.996839758196,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [6711]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6711] sem-sysv           1001      0.01      0.01      0.01    105280.93       71627.91\nstress-ng: info:  [6711] skipped: 0\nstress-ng: info:  [6711] passed: 1: sem-sysv (1)\nstress-ng: info:  [6711] failed: 0\nstress-ng: info:  [6711] metrics untrustworthy: 0\nstress-ng: info:  [6711] successful run completed in 0.01 secs\nstress-ng: info:  [6715] setting to a 1 secs run per stressor\nstress-ng: info:  [6715] dispatching hogs: 1 switch\nstress-ng: info:  [6715] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6715] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6715]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6715] switch             1000      0.00      0.00      0.01    264041.80      133707.71\nstress-ng: info:  [6715] skipped: 0\nstress-ng: info:  [6715] passed: 1: switch (1)\nstress-ng: info:  [6715] failed: 0\nstress-ng: info:  [6715] metrics untrustworthy: 0\nstress-ng: info:  [6715] successful run completed in 0.01 secs\nstress-ng: info:  [6718] setting to a 1 secs run per stressor\nstress-ng: info:  [6718] dispatching hogs: 1 vfork\nstress-ng: info:  [6718] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6718] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6718]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6718] vfork               200      0.07      0.00      0.01      3046.15       18132.37\nstress-ng: info:  [6718] skipped: 0\nstress-ng: info:  [6718] passed: 1: vfork (1)\nstress-ng: info:  [6718] failed: 0\nstress-ng: info:  [6718] metrics untrustworthy: 0\nstress-ng: info:  [6718] successful run completed in 0.08 secs\nstress-ng: info:  [6920] setting to a 1 secs run per stressor\nstress-ng: info:  [6920] dispatching hogs: 1 yield\nstress-ng: info:  [6920] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6920] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6920]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6920] yield              4992      1.01      0.02      0.00      4938.66      217810.55\nstress-ng: info:  [6920] skipped: 0\nstress-ng: info:  [6920] passed: 1: yield (1)\nstress-ng: info:  [6920] failed: 0\nstress-ng: info:  [6920] metrics untrustworthy: 0\nstress-ng: info:  [6920] successful run completed in 1.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 383.77777777777777,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 3454,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 190.55555555555554,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 1715,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.6142931349999117,
            "ops_per_sec": 4396.217029426728,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [6969]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6969] sem-sysv           1001      0.01      0.00      0.01    101171.07       68721.68\nstress-ng: info:  [6969] skipped: 0\nstress-ng: info:  [6969] passed: 1: sem-sysv (1)\nstress-ng: info:  [6969] failed: 0\nstress-ng: info:  [6969] metrics untrustworthy: 0\nstress-ng: info:  [6969] successful run completed in 0.01 secs\nstress-ng: info:  [6973] setting to a 1 secs run per stressor\nstress-ng: info:  [6973] dispatching hogs: 1 switch\nstress-ng: info:  [6973] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6973] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6973]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6973] switch             1000      0.01      0.00      0.01    179358.73      104569.70\nstress-ng: info:  [6973] skipped: 0\nstress-ng: info:  [6973] passed: 1: switch (1)\nstress-ng: info:  [6973] failed: 0\nstress-ng: info:  [6973] metrics untrustworthy: 0\nstress-ng: info:  [6973] successful run completed in 0.01 secs\nstress-ng: info:  [6976] setting to a 1 secs run per stressor\nstress-ng: info:  [6976] dispatching hogs: 1 vfork\nstress-ng: info:  [6976] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6976] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6976]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6976] vfork               200      0.01      0.00      0.01     20875.49       19043.99\nstress-ng: info:  [6976] skipped: 0\nstress-ng: info:  [6976] passed: 1: vfork (1)\nstress-ng: info:  [6976] failed: 0\nstress-ng: info:  [6976] metrics untrustworthy: 0\nstress-ng: info:  [6976] successful run completed in 0.01 secs\nstress-ng: info:  [7179] setting to a 1 secs run per stressor\nstress-ng: info:  [7179] dispatching hogs: 1 yield\nstress-ng: info:  [7179] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7179] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7179]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7179] yield              4992      1.00      0.03      0.00      4987.20      178025.03\nstress-ng: info:  [7179] skipped: 0\nstress-ng: info:  [7179] passed: 1: yield (1)\nstress-ng: info:  [7179] failed: 0\nstress-ng: info:  [7179] metrics untrustworthy: 0\nstress-ng: info:  [7179] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 9
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 10
          }
        ],
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
          "13": {
            "avg_ns_per_run": 1116.5,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2233,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 4242.0,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 8484,
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
            "duration_s": 1.0264439929999867,
            "ops_per_sec": 5002.708413726444,
            "ops_total": 5135.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7009]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7009] sockdiag           1034      0.00      0.00      0.00   1686857.38      958294.72\nstress-ng: info:  [7009] skipped: 0\nstress-ng: info:  [7009] passed: 1: sockdiag (1)\nstress-ng: info:  [7009] failed: 0\nstress-ng: info:  [7009] metrics untrustworthy: 0\nstress-ng: info:  [7009] successful run completed in 0.00 secs\nstress-ng: info:  [7011] setting to a 1 secs run per stressor\nstress-ng: info:  [7011] dispatching hogs: 1 sockfd\nstress-ng: info:  [7011] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7011] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7011]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7011] sockfd              200      0.00      0.01      0.00     50201.13       30455.31\nstress-ng: info:  [7011] skipped: 0\nstress-ng: info:  [7011] passed: 1: sockfd (1)\nstress-ng: info:  [7011] failed: 0\nstress-ng: info:  [7011] metrics untrustworthy: 0\nstress-ng: info:  [7011] successful run completed in 0.01 secs\nstress-ng: info:  [7014] setting to a 1 secs run per stressor\nstress-ng: info:  [7014] dispatching hogs: 1 sockpair\nstress-ng: info:  [7014] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7014] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7014]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7014] sockpair            500      0.05      0.01      0.06      9120.23        7357.49\nstress-ng: info:  [7014] skipped: 0\nstress-ng: info:  [7014] passed: 1: sockpair (1)\nstress-ng: info:  [7014] failed: 0\nstress-ng: info:  [7014] metrics untrustworthy: 0\nstress-ng: info:  [7014] successful run completed in 0.06 secs\nstress-ng: info:  [7018] setting to a 1 secs run per stressor\nstress-ng: info:  [7018] dispatching hogs: 1 udp-flood\nstress-ng: info:  [7018] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7018] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7018]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7018] udp-flood          1000      0.02      0.00      0.02     64080.18       61992.44\nstress-ng: info:  [7018] skipped: 0\nstress-ng: info:  [7018] passed: 1: udp-flood (1)\nstress-ng: info:  [7018] failed: 0\nstress-ng: info:  [7018] metrics untrustworthy: 0\nstress-ng: info:  [7018] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "13": {
            "avg_ns_per_run": 823.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 13,
            "name": "bindsnoop_entry",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1646,
            "type": "kprobe"
          },
          "14": {
            "avg_ns_per_run": 3164.0,
            "bytes_jited": 721,
            "bytes_xlated": 1160,
            "id": 14,
            "name": "bindsnoop_v4_return",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 6328,
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
            "duration_s": 1.2960458200000176,
            "ops_per_sec": 3974.3965224932635,
            "ops_total": 5151.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7248]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7248] sockdiag           1034      0.00      0.00      0.00   1338965.83      753095.41\nstress-ng: info:  [7248] skipped: 0\nstress-ng: info:  [7248] passed: 1: sockdiag (1)\nstress-ng: info:  [7248] failed: 0\nstress-ng: info:  [7248] metrics untrustworthy: 0\nstress-ng: info:  [7248] successful run completed in 0.00 secs\nstress-ng: info:  [7250] setting to a 1 secs run per stressor\nstress-ng: info:  [7250] dispatching hogs: 1 sockfd\nstress-ng: info:  [7250] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7250] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7250]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7250] sockfd              200      0.01      0.00      0.00     20451.54       35676.06\nstress-ng: info:  [7250] skipped: 0\nstress-ng: info:  [7250] passed: 1: sockfd (1)\nstress-ng: info:  [7250] failed: 0\nstress-ng: info:  [7250] metrics untrustworthy: 0\nstress-ng: info:  [7250] successful run completed in 0.02 secs\nstress-ng: info:  [7253] setting to a 1 secs run per stressor\nstress-ng: info:  [7253] dispatching hogs: 1 sockpair\nstress-ng: info:  [7253] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7253] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7253]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7253] sockpair            500      0.05      0.00      0.06     10963.09        8658.91\nstress-ng: info:  [7253] skipped: 0\nstress-ng: info:  [7253] passed: 1: sockpair (1)\nstress-ng: info:  [7253] failed: 0\nstress-ng: info:  [7253] metrics untrustworthy: 0\nstress-ng: info:  [7253] successful run completed in 0.05 secs\nstress-ng: info:  [7257] setting to a 1 secs run per stressor\nstress-ng: info:  [7257] dispatching hogs: 1 udp-flood\nstress-ng: info:  [7257] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7257] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7257]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7257] udp-flood          1000      0.03      0.00      0.03     38582.15       38034.38\nstress-ng: info:  [7257] skipped: 0\nstress-ng: info:  [7257] passed: 1: udp-flood (1)\nstress-ng: info:  [7257] failed: 0\nstress-ng: info:  [7257] metrics untrustworthy: 0\nstress-ng: info:  [7257] successful run completed in 0.03 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 13
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 14
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 15
          }
        ],
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
      "app": "bcc/biosnoop",
      "baseline": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 408.5668013764405,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 49984,
            "run_time_ns_delta": 20421803,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 368.9091909190919,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 49995,
            "run_time_ns_delta": 18443615,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 180.8855137383514,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 50006,
            "run_time_ns_delta": 9045361,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 11.147819137999988,
            "ops_per_sec": 5939.726791430483,
            "ops_total": 66215.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_us\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 40.238023,\n        \"20\" : 9.142508,\n        \"50\" : 0.573695,\n        \"100\" : 0.054928,\n        \"250\" : 24.626182,\n        \"500\" : 23.503204,\n        \"750\" : 1.019225,\n        \"1000\" : 0.140372\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.073238,\n        \"4\" : 0.457736,\n        \"10\" : 0.122063,\n        \"20\" : 0.036619,\n        \"50\" : 0.012206,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 416.3528159061429,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 51653,
            "run_time_ns_delta": 21505872,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 384.3260099494783,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 51661,
            "run_time_ns_delta": 19854666,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 192.9898383818833,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 51665,
            "run_time_ns_delta": 9970820,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 14.28343187400003,
            "ops_per_sec": 4873.4086187443845,
            "ops_total": 69609.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_us\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 44.359676,\n        \"20\" : 5.154039,\n        \"50\" : 0.297012,\n        \"100\" : 0.069885,\n        \"250\" : 23.236853,\n        \"500\" : 24.564673,\n        \"750\" : 1.403529,\n        \"1000\" : 0.448430\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.361074,\n        \"4\" : 0.029119,\n        \"10\" : 0.064061,\n        \"20\" : 0.011648,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 18
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 19
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 20
          }
        ],
        "program_counts": {
          "applied": 0,
          "not_applied": 3,
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
            "avg_ns_per_run": 61.60260384376937,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 4839,
            "run_time_ns_delta": 298095,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 108.75586854460094,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 213,
            "run_time_ns_delta": 23165,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 47.990075957727875,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 60560,
            "run_time_ns_delta": 2906279,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 39.681156746311125,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 205957,
            "run_time_ns_delta": 8172612,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 38.56474913934444,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 226281,
            "run_time_ns_delta": 8726470,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 8.850445019999995,
            "ops_per_sec": 933.286403263822,
            "ops_total": 8260.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [8745]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8745] open                100      0.06      0.01      0.00      1551.07       13885.03\nstress-ng: info:  [8745] skipped: 0\nstress-ng: info:  [8745] passed: 1: open (1)\nstress-ng: info:  [8745] failed: 0\nstress-ng: info:  [8745] metrics untrustworthy: 0\nstress-ng: info:  [8745] successful run completed in 0.07 secs\nstress-ng: info:  [8747] setting to a 1 secs run per stressor\nstress-ng: info:  [8747] dispatching hogs: 1 rename\nstress-ng: info:  [8747] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8747] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8747]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8747] rename              100      0.56      0.00      0.01       179.57       10640.56\nstress-ng: info:  [8747] skipped: 0\nstress-ng: info:  [8747] passed: 1: rename (1)\nstress-ng: info:  [8747] failed: 0\nstress-ng: info:  [8747] metrics untrustworthy: 0\nstress-ng: info:  [8747] successful run completed in 0.56 secs\nstress-ng: info:  [8749] setting to a 1 secs run per stressor\nstress-ng: info:  [8749] dispatching hogs: 1 touch\nstress-ng: info:  [8749] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8749] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8749]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8749] touch               200      0.03      0.00      0.01      7371.88       11348.81\nstress-ng: info:  [8749] skipped: 0\nstress-ng: info:  [8749] passed: 1: touch (1)\nstress-ng: info:  [8749] failed: 0\nstress-ng: info:  [8749] metrics untrustworthy: 0\nstress-ng: info:  [8749] successful run completed in 0.03 secs\nstress-ng: info:  [8755] setting to a 1 secs run per stressor\nstress-ng: info:  [8755] dispatching hogs: 1 utime\nstress-ng: info:  [8755] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8755] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8755]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8755] utime               200      0.03      0.01      0.02      7286.58        7070.14\nstress-ng: info:  [8755] skipped: 0\nstress-ng: info:  [8755] passed: 1: utime (1)\nstress-ng: info:  [8755] failed: 0\nstress-ng: info:  [8755] metrics untrustworthy: 0\nstress-ng: info:  [8755] successful run completed in 0.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "23": {
            "avg_ns_per_run": 56.6012015744769,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 4827,
            "run_time_ns_delta": 273214,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 92.21491228070175,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 228,
            "run_time_ns_delta": 21025,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 48.866910444565235,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 60711,
            "run_time_ns_delta": 2966759,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 40.480029213505325,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 202646,
            "run_time_ns_delta": 8203116,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 37.81941997738806,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 228198,
            "run_time_ns_delta": 8630316,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 8.986405583999954,
            "ops_per_sec": 919.9451240793276,
            "ops_total": 8267.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [8983]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8983] open                100      0.10      0.01      0.00       974.81       13306.72\nstress-ng: info:  [8983] skipped: 0\nstress-ng: info:  [8983] passed: 1: open (1)\nstress-ng: info:  [8983] failed: 0\nstress-ng: info:  [8983] metrics untrustworthy: 0\nstress-ng: info:  [8983] successful run completed in 0.10 secs\nstress-ng: info:  [8985] setting to a 1 secs run per stressor\nstress-ng: info:  [8985] dispatching hogs: 1 rename\nstress-ng: info:  [8985] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8985] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8985]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8985] rename              100      0.57      0.00      0.00       174.51       11284.13\nstress-ng: info:  [8985] skipped: 0\nstress-ng: info:  [8985] passed: 1: rename (1)\nstress-ng: info:  [8985] failed: 0\nstress-ng: info:  [8985] metrics untrustworthy: 0\nstress-ng: info:  [8985] successful run completed in 0.58 secs\nstress-ng: info:  [8987] setting to a 1 secs run per stressor\nstress-ng: info:  [8987] dispatching hogs: 1 touch\nstress-ng: info:  [8987] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8987] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8987]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8987] touch               200      0.02      0.02      0.00      8000.58       12269.94\nstress-ng: info:  [8987] skipped: 0\nstress-ng: info:  [8987] passed: 1: touch (1)\nstress-ng: info:  [8987] failed: 0\nstress-ng: info:  [8987] metrics untrustworthy: 0\nstress-ng: info:  [8987] successful run completed in 0.03 secs\nstress-ng: info:  [8993] setting to a 1 secs run per stressor\nstress-ng: info:  [8993] dispatching hogs: 1 utime\nstress-ng: info:  [8993] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8993] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8993]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8993] utime               200      0.03      0.00      0.03      7482.28        7322.25\nstress-ng: info:  [8993] skipped: 0\nstress-ng: info:  [8993] passed: 1: utime (1)\nstress-ng: info:  [8993] failed: 0\nstress-ng: info:  [8993] metrics untrustworthy: 0\nstress-ng: info:  [8993] successful run completed in 0.03 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 23
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 24
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 25
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 26
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 27
          }
        ],
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
          "30": {
            "avg_ns_per_run": 569.2065217391304,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 92,
            "run_time_ns_delta": 52367,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 763.0593785721709,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 48115,
            "run_time_ns_delta": 36714602,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 573.9285714285714,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 8035,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 9.596323708,
            "ops_per_sec": 859.2873949349688,
            "ops_total": 8246.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [10457]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10457] open                100      0.30      0.01      0.00       333.93       13042.91\nstress-ng: info:  [10457] skipped: 0\nstress-ng: info:  [10457] passed: 1: open (1)\nstress-ng: info:  [10457] failed: 0\nstress-ng: info:  [10457] metrics untrustworthy: 0\nstress-ng: info:  [10457] successful run completed in 0.30 secs\nstress-ng: info:  [10459] setting to a 1 secs run per stressor\nstress-ng: info:  [10459] dispatching hogs: 1 rename\nstress-ng: info:  [10459] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10459] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10459]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10459] rename              100      0.99      0.00      0.01       101.27        9659.04\nstress-ng: info:  [10459] skipped: 0\nstress-ng: info:  [10459] passed: 1: rename (1)\nstress-ng: info:  [10459] failed: 0\nstress-ng: info:  [10459] metrics untrustworthy: 0\nstress-ng: info:  [10459] successful run completed in 0.99 secs\nstress-ng: info:  [10461] setting to a 1 secs run per stressor\nstress-ng: info:  [10461] dispatching hogs: 1 touch\nstress-ng: info:  [10461] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10461] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10461]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10461] touch               200      0.04      0.01      0.00      4488.84       13491.64\nstress-ng: info:  [10461] skipped: 0\nstress-ng: info:  [10461] passed: 1: touch (1)\nstress-ng: info:  [10461] failed: 0\nstress-ng: info:  [10461] metrics untrustworthy: 0\nstress-ng: info:  [10461] successful run completed in 0.05 secs\nstress-ng: info:  [10467] setting to a 1 secs run per stressor\nstress-ng: info:  [10467] dispatching hogs: 1 utime\nstress-ng: info:  [10467] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10467] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10467]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10467] utime               200      0.03      0.00      0.03      7838.65        7705.05\nstress-ng: info:  [10467] skipped: 0\nstress-ng: info:  [10467] passed: 1: utime (1)\nstress-ng: info:  [10467] failed: 0\nstress-ng: info:  [10467] metrics untrustworthy: 0\nstress-ng: info:  [10467] successful run completed in 0.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 1005.3541666666666,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 96,
            "run_time_ns_delta": 96514,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 757.1724306888244,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 48982,
            "run_time_ns_delta": 37087820,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 1190.5,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 6,
            "run_time_ns_delta": 7143,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 10.541376077999985,
            "ops_per_sec": 779.5946126190387,
            "ops_total": 8218.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [10703]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10703] open                100      0.50      0.00      0.01       200.61        9661.84\nstress-ng: info:  [10703] skipped: 0\nstress-ng: info:  [10703] passed: 1: open (1)\nstress-ng: info:  [10703] failed: 0\nstress-ng: info:  [10703] metrics untrustworthy: 0\nstress-ng: info:  [10703] successful run completed in 0.50 secs\nstress-ng: info:  [10705] setting to a 1 secs run per stressor\nstress-ng: info:  [10705] dispatching hogs: 1 rename\nstress-ng: info:  [10705] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10705] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10705]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10705] rename              100      0.69      0.00      0.01       145.78       10180.19\nstress-ng: info:  [10705] skipped: 0\nstress-ng: info:  [10705] passed: 1: rename (1)\nstress-ng: info:  [10705] failed: 0\nstress-ng: info:  [10705] metrics untrustworthy: 0\nstress-ng: info:  [10705] successful run completed in 0.69 secs\nstress-ng: info:  [10707] setting to a 1 secs run per stressor\nstress-ng: info:  [10707] dispatching hogs: 1 touch\nstress-ng: info:  [10707] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10707] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10707]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10707] touch               200      0.03      0.00      0.01      7126.08       13759.89\nstress-ng: info:  [10707] skipped: 0\nstress-ng: info:  [10707] passed: 1: touch (1)\nstress-ng: info:  [10707] failed: 0\nstress-ng: info:  [10707] metrics untrustworthy: 0\nstress-ng: info:  [10707] successful run completed in 0.03 secs\nstress-ng: info:  [10713] setting to a 1 secs run per stressor\nstress-ng: info:  [10713] dispatching hogs: 1 utime\nstress-ng: info:  [10713] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [10713] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [10713]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [10713] utime               200      0.02      0.00      0.02     12917.28       12606.37\nstress-ng: info:  [10713] skipped: 0\nstress-ng: info:  [10713] passed: 1: utime (1)\nstress-ng: info:  [10713] failed: 0\nstress-ng: info:  [10713] metrics untrustworthy: 0\nstress-ng: info:  [10713] successful run completed in 0.02 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 30
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 31
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 32
          }
        ],
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
          "35": {
            "avg_ns_per_run": 72.86713489882828,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 1972241,
            "run_time_ns_delta": 143711551,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 69.22508513179964,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 1972236,
            "run_time_ns_delta": 136528205,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.8842260659999965,
            "ops_per_sec": 3152.487966908325,
            "ops_total": 5940.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [11249]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11249] get                 200      0.39      0.00      0.16       511.38        1178.42\nstress-ng: info:  [11249] skipped: 0\nstress-ng: info:  [11249] passed: 1: get (1)\nstress-ng: info:  [11249] failed: 0\nstress-ng: info:  [11249] metrics untrustworthy: 0\nstress-ng: info:  [11249] successful run completed in 0.39 secs\nstress-ng: info:  [11251] setting to a 1 secs run per stressor\nstress-ng: info:  [11251] dispatching hogs: 1 prctl\nstress-ng: info:  [11251] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11251] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11251]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11251] prctl               716      1.00      0.72      0.22       715.81         762.25\nstress-ng: info:  [11251] skipped: 0\nstress-ng: info:  [11251] passed: 1: prctl (1)\nstress-ng: info:  [11251] failed: 0\nstress-ng: info:  [11251] metrics untrustworthy: 0\nstress-ng: info:  [11251] successful run completed in 1.00 secs\nstress-ng: info:  [11969] setting to a 1 secs run per stressor\nstress-ng: info:  [11969] dispatching hogs: 1 set\nstress-ng: info:  [11969] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11969] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11969]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11969] set                1000      0.18      0.01      0.17      5438.88        5422.46\nstress-ng: info:  [11969] skipped: 0\nstress-ng: info:  [11969] passed: 1: set (1)\nstress-ng: info:  [11969] failed: 0\nstress-ng: info:  [11969] metrics untrustworthy: 0\nstress-ng: info:  [11969] successful run completed in 0.20 secs\nstress-ng: info:  [11971] setting to a 1 secs run per stressor\nstress-ng: info:  [11971] dispatching hogs: 1 timerfd\nstress-ng: info:  [11971] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11971] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11971]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11971] timerfd            1024      0.02      0.00      0.03     41233.14       40451.92\nstress-ng: info:  [11971] skipped: 0\nstress-ng: info:  [11971] passed: 1: timerfd (1)\nstress-ng: info:  [11971] failed: 0\nstress-ng: info:  [11971] metrics untrustworthy: 0\nstress-ng: info:  [11971] successful run completed in 0.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 72.92660924746153,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 2002582,
            "run_time_ns_delta": 146041515,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 68.96204212991513,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 2002615,
            "run_time_ns_delta": 138104420,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.8697331209999675,
            "ops_per_sec": 3184.946521573708,
            "ops_total": 5955.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [11467]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11467] get                 200      0.35      0.00      0.17       564.32        1189.22\nstress-ng: info:  [11467] skipped: 0\nstress-ng: info:  [11467] passed: 1: get (1)\nstress-ng: info:  [11467] failed: 0\nstress-ng: info:  [11467] metrics untrustworthy: 0\nstress-ng: info:  [11467] successful run completed in 0.36 secs\nstress-ng: info:  [11469] setting to a 1 secs run per stressor\nstress-ng: info:  [11469] dispatching hogs: 1 prctl\nstress-ng: info:  [11469] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [11469] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [11469]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [11469] prctl               731      1.00      0.74      0.21       730.08         763.11\nstress-ng: info:  [11469] skipped: 0\nstress-ng: info:  [11469] passed: 1: prctl (1)\nstress-ng: info:  [11469] failed: 0\nstress-ng: info:  [11469] metrics untrustworthy: 0\nstress-ng: info:  [11469] successful run completed in 1.00 secs\nstress-ng: info:  [12202] setting to a 1 secs run per stressor\nstress-ng: info:  [12202] dispatching hogs: 1 set\nstress-ng: info:  [12202] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12202] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12202]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12202] set                1000      0.20      0.01      0.18      5117.62        5126.21\nstress-ng: info:  [12202] skipped: 0\nstress-ng: info:  [12202] passed: 1: set (1)\nstress-ng: info:  [12202] failed: 0\nstress-ng: info:  [12202] metrics untrustworthy: 0\nstress-ng: info:  [12202] successful run completed in 0.20 secs\nstress-ng: info:  [12204] setting to a 1 secs run per stressor\nstress-ng: info:  [12204] dispatching hogs: 1 timerfd\nstress-ng: info:  [12204] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12204] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12204]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12204] timerfd            1024      0.03      0.00      0.03     40674.74       39617.75\nstress-ng: info:  [12204] skipped: 0\nstress-ng: info:  [12204] passed: 1: timerfd (1)\nstress-ng: info:  [12204] failed: 0\nstress-ng: info:  [12204] metrics untrustworthy: 0\nstress-ng: info:  [12204] successful run completed in 0.03 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 35
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 36
          }
        ],
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
          "39": {
            "avg_ns_per_run": 779.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 779,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 3206.0,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3206,
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
            "duration_s": 1.277931667999951,
            "ops_per_sec": 4026.8193745083695,
            "ops_total": 5146.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [12008]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12008] sockdiag           1034      0.00      0.00      0.00   1274811.97      721563.15\nstress-ng: info:  [12008] skipped: 0\nstress-ng: info:  [12008] passed: 1: sockdiag (1)\nstress-ng: info:  [12008] failed: 0\nstress-ng: info:  [12008] metrics untrustworthy: 0\nstress-ng: info:  [12008] successful run completed in 0.00 secs\nstress-ng: info:  [12010] setting to a 1 secs run per stressor\nstress-ng: info:  [12010] dispatching hogs: 1 sockfd\nstress-ng: info:  [12010] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12010] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12010]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12010] sockfd              200      0.00      0.00      0.00     65174.49       40642.15\nstress-ng: info:  [12010] skipped: 0\nstress-ng: info:  [12010] passed: 1: sockfd (1)\nstress-ng: info:  [12010] failed: 0\nstress-ng: info:  [12010] metrics untrustworthy: 0\nstress-ng: info:  [12010] successful run completed in 0.00 secs\nstress-ng: info:  [12013] setting to a 1 secs run per stressor\nstress-ng: info:  [12013] dispatching hogs: 1 sockpair\nstress-ng: info:  [12013] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12013] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12013]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12013] sockpair            500      0.04      0.00      0.05     11592.88        8993.13\nstress-ng: info:  [12013] skipped: 0\nstress-ng: info:  [12013] passed: 1: sockpair (1)\nstress-ng: info:  [12013] failed: 0\nstress-ng: info:  [12013] metrics untrustworthy: 0\nstress-ng: info:  [12013] successful run completed in 0.05 secs\nstress-ng: info:  [12017] setting to a 1 secs run per stressor\nstress-ng: info:  [12017] dispatching hogs: 1 udp-flood\nstress-ng: info:  [12017] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12017] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12017]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12017] udp-flood          1000      0.01      0.00      0.01    114657.99      110827.88\nstress-ng: info:  [12017] skipped: 0\nstress-ng: info:  [12017] passed: 1: udp-flood (1)\nstress-ng: info:  [12017] failed: 0\nstress-ng: info:  [12017] metrics untrustworthy: 0\nstress-ng: info:  [12017] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 745.0,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 745,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 4658.0,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4658,
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
            "duration_s": 1.409659046999991,
            "ops_per_sec": 3717.2109178823534,
            "ops_total": 5240.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [12241]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12241] sockdiag           1034      0.00      0.00      0.00   1114600.45      703401.36\nstress-ng: info:  [12241] skipped: 0\nstress-ng: info:  [12241] passed: 1: sockdiag (1)\nstress-ng: info:  [12241] failed: 0\nstress-ng: info:  [12241] metrics untrustworthy: 0\nstress-ng: info:  [12241] successful run completed in 0.00 secs\nstress-ng: info:  [12243] setting to a 1 secs run per stressor\nstress-ng: info:  [12243] dispatching hogs: 1 sockfd\nstress-ng: info:  [12243] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12243] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12243]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12243] sockfd              200      0.00      0.00      0.00     68316.70       42078.69\nstress-ng: info:  [12243] skipped: 0\nstress-ng: info:  [12243] passed: 1: sockfd (1)\nstress-ng: info:  [12243] failed: 0\nstress-ng: info:  [12243] metrics untrustworthy: 0\nstress-ng: info:  [12243] successful run completed in 0.00 secs\nstress-ng: info:  [12246] setting to a 1 secs run per stressor\nstress-ng: info:  [12246] dispatching hogs: 1 sockpair\nstress-ng: info:  [12246] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12246] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12246]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12246] sockpair            500      0.07      0.00      0.06      7419.90        8182.10\nstress-ng: info:  [12246] skipped: 0\nstress-ng: info:  [12246] passed: 1: sockpair (1)\nstress-ng: info:  [12246] failed: 0\nstress-ng: info:  [12246] metrics untrustworthy: 0\nstress-ng: info:  [12246] successful run completed in 0.07 secs\nstress-ng: info:  [12250] setting to a 1 secs run per stressor\nstress-ng: info:  [12250] dispatching hogs: 1 udp-flood\nstress-ng: info:  [12250] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12250] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12250]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12250] udp-flood          1000      0.01      0.00      0.01     92022.73       88534.75\nstress-ng: info:  [12250] skipped: 0\nstress-ng: info:  [12250] passed: 1: udp-flood (1)\nstress-ng: info:  [12250] failed: 0\nstress-ng: info:  [12250] metrics untrustworthy: 0\nstress-ng: info:  [12250] successful run completed in 0.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 39
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 40
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 41
          }
        ],
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
          "44": {
            "avg_ns_per_run": 25.261182108626198,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 2504,
            "run_time_ns_delta": 63254,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.127936496000018,
            "ops_per_sec": 4653.630783837955,
            "ops_total": 5249.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [12054]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12054] sockdiag           1034      0.00      0.00      0.00   1611036.53      940000.00\nstress-ng: info:  [12054] skipped: 0\nstress-ng: info:  [12054] passed: 1: sockdiag (1)\nstress-ng: info:  [12054] failed: 0\nstress-ng: info:  [12054] metrics untrustworthy: 0\nstress-ng: info:  [12054] successful run completed in 0.00 secs\nstress-ng: info:  [12056] setting to a 1 secs run per stressor\nstress-ng: info:  [12056] dispatching hogs: 1 sockfd\nstress-ng: info:  [12056] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12056] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12056]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12056] sockfd              200      0.00      0.01      0.00     46549.07       29308.32\nstress-ng: info:  [12056] skipped: 0\nstress-ng: info:  [12056] passed: 1: sockfd (1)\nstress-ng: info:  [12056] failed: 0\nstress-ng: info:  [12056] metrics untrustworthy: 0\nstress-ng: info:  [12056] successful run completed in 0.01 secs\nstress-ng: info:  [12059] setting to a 1 secs run per stressor\nstress-ng: info:  [12059] dispatching hogs: 1 sockpair\nstress-ng: info:  [12059] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12059] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12059]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12059] sockpair            500      0.07      0.00      0.06      7413.84        8082.38\nstress-ng: info:  [12059] skipped: 0\nstress-ng: info:  [12059] passed: 1: sockpair (1)\nstress-ng: info:  [12059] failed: 0\nstress-ng: info:  [12059] metrics untrustworthy: 0\nstress-ng: info:  [12059] successful run completed in 0.07 secs\nstress-ng: info:  [12063] setting to a 1 secs run per stressor\nstress-ng: info:  [12063] dispatching hogs: 1 udp-flood\nstress-ng: info:  [12063] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12063] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12063]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12063] udp-flood          1000      0.01      0.00      0.01    113276.91      108014.69\nstress-ng: info:  [12063] skipped: 0\nstress-ng: info:  [12063] passed: 1: udp-flood (1)\nstress-ng: info:  [12063] failed: 0\nstress-ng: info:  [12063] metrics untrustworthy: 0\nstress-ng: info:  [12063] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 22.954762698677335,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 8997,
            "run_time_ns_delta": 206524,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.3091356639999958,
            "ops_per_sec": 4011.0434268942327,
            "ops_total": 5251.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [12287]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12287] sockdiag           1034      0.00      0.00      0.00   1005077.71      650723.73\nstress-ng: info:  [12287] skipped: 0\nstress-ng: info:  [12287] passed: 1: sockdiag (1)\nstress-ng: info:  [12287] failed: 0\nstress-ng: info:  [12287] metrics untrustworthy: 0\nstress-ng: info:  [12287] successful run completed in 0.00 secs\nstress-ng: info:  [12289] setting to a 1 secs run per stressor\nstress-ng: info:  [12289] dispatching hogs: 1 sockfd\nstress-ng: info:  [12289] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12289] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12289]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12289] sockfd              200      0.00      0.00      0.01     47576.04       29171.53\nstress-ng: info:  [12289] skipped: 0\nstress-ng: info:  [12289] passed: 1: sockfd (1)\nstress-ng: info:  [12289] failed: 0\nstress-ng: info:  [12289] metrics untrustworthy: 0\nstress-ng: info:  [12289] successful run completed in 0.01 secs\nstress-ng: info:  [12292] setting to a 1 secs run per stressor\nstress-ng: info:  [12292] dispatching hogs: 1 sockpair\nstress-ng: info:  [12292] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12292] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12292]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12292] sockpair            500      0.06      0.00      0.07      8424.77        6644.87\nstress-ng: info:  [12292] skipped: 0\nstress-ng: info:  [12292] passed: 1: sockpair (1)\nstress-ng: info:  [12292] failed: 0\nstress-ng: info:  [12292] metrics untrustworthy: 0\nstress-ng: info:  [12292] successful run completed in 0.06 secs\nstress-ng: info:  [12296] setting to a 1 secs run per stressor\nstress-ng: info:  [12296] dispatching hogs: 1 udp-flood\nstress-ng: info:  [12296] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12296] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12296]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12296] udp-flood          1000      0.01      0.00      0.01    110469.45      104986.88\nstress-ng: info:  [12296] skipped: 0\nstress-ng: info:  [12296] passed: 1: udp-flood (1)\nstress-ng: info:  [12296] failed: 0\nstress-ng: info:  [12296] metrics untrustworthy: 0\nstress-ng: info:  [12296] successful run completed in 0.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 44
          }
        ],
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
          "47": {
            "avg_ns_per_run": 118.42492912402095,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 104055,
            "run_time_ns_delta": 12322706,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 190.6069287270344,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 51871,
            "run_time_ns_delta": 9886972,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 299.40418118466897,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 574,
            "run_time_ns_delta": 171858,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.5534254080000096,
            "ops_per_sec": 4501.012625625113,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [12952]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12952] sem-sysv           1001      0.01      0.00      0.01    104085.54       71617.66\nstress-ng: info:  [12952] skipped: 0\nstress-ng: info:  [12952] passed: 1: sem-sysv (1)\nstress-ng: info:  [12952] failed: 0\nstress-ng: info:  [12952] metrics untrustworthy: 0\nstress-ng: info:  [12952] successful run completed in 0.01 secs\nstress-ng: info:  [12956] setting to a 1 secs run per stressor\nstress-ng: info:  [12956] dispatching hogs: 1 switch\nstress-ng: info:  [12956] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12956] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12956]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12956] switch             1000      0.01      0.00      0.01    183759.21       95383.44\nstress-ng: info:  [12956] skipped: 0\nstress-ng: info:  [12956] passed: 1: switch (1)\nstress-ng: info:  [12956] failed: 0\nstress-ng: info:  [12956] metrics untrustworthy: 0\nstress-ng: info:  [12956] successful run completed in 0.01 secs\nstress-ng: info:  [12959] setting to a 1 secs run per stressor\nstress-ng: info:  [12959] dispatching hogs: 1 vfork\nstress-ng: info:  [12959] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [12959] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [12959]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [12959] vfork               200      0.01      0.01      0.01     14999.48       13375.24\nstress-ng: info:  [12959] skipped: 0\nstress-ng: info:  [12959] passed: 1: vfork (1)\nstress-ng: info:  [12959] failed: 0\nstress-ng: info:  [12959] metrics untrustworthy: 0\nstress-ng: info:  [12959] successful run completed in 0.02 secs\nstress-ng: info:  [13161] setting to a 1 secs run per stressor\nstress-ng: info:  [13161] dispatching hogs: 1 yield\nstress-ng: info:  [13161] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13161] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13161]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13161] yield              4992      1.00      0.02      0.01      4989.10      195734.00\nstress-ng: info:  [13161] skipped: 0\nstress-ng: info:  [13161] passed: 1: yield (1)\nstress-ng: info:  [13161] failed: 0\nstress-ng: info:  [13161] metrics untrustworthy: 0\nstress-ng: info:  [13161] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 123.59516204983314,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 97686,
            "run_time_ns_delta": 12073517,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 189.83675365256312,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 47364,
            "run_time_ns_delta": 8991428,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 266.47451669595785,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 569,
            "run_time_ns_delta": 151624,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.5324809300000197,
            "ops_per_sec": 4538.23752978859,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [13198]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13198] sem-sysv           1001      0.01      0.01      0.01    109315.97       74523.53\nstress-ng: info:  [13198] skipped: 0\nstress-ng: info:  [13198] passed: 1: sem-sysv (1)\nstress-ng: info:  [13198] failed: 0\nstress-ng: info:  [13198] metrics untrustworthy: 0\nstress-ng: info:  [13198] successful run completed in 0.01 secs\nstress-ng: info:  [13202] setting to a 1 secs run per stressor\nstress-ng: info:  [13202] dispatching hogs: 1 switch\nstress-ng: info:  [13202] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13202] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13202]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13202] switch             1000      0.00      0.01      0.00    212498.94      115606.94\nstress-ng: info:  [13202] skipped: 0\nstress-ng: info:  [13202] passed: 1: switch (1)\nstress-ng: info:  [13202] failed: 0\nstress-ng: info:  [13202] metrics untrustworthy: 0\nstress-ng: info:  [13202] successful run completed in 0.01 secs\nstress-ng: info:  [13205] setting to a 1 secs run per stressor\nstress-ng: info:  [13205] dispatching hogs: 1 vfork\nstress-ng: info:  [13205] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13205] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13205]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13205] vfork               200      0.01      0.01      0.00     23633.21       20667.56\nstress-ng: info:  [13205] skipped: 0\nstress-ng: info:  [13205] passed: 1: vfork (1)\nstress-ng: info:  [13205] failed: 0\nstress-ng: info:  [13205] metrics untrustworthy: 0\nstress-ng: info:  [13205] successful run completed in 0.01 secs\nstress-ng: info:  [13407] setting to a 1 secs run per stressor\nstress-ng: info:  [13407] dispatching hogs: 1 yield\nstress-ng: info:  [13407] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [13407] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [13407]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [13407] yield              4992      1.00      0.02      0.00      4977.07      220592.13\nstress-ng: info:  [13407] skipped: 0\nstress-ng: info:  [13407] passed: 1: yield (1)\nstress-ng: info:  [13407] failed: 0\nstress-ng: info:  [13407] metrics untrustworthy: 0\nstress-ng: info:  [13407] successful run completed in 1.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 47
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 48
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 49
          }
        ],
        "program_counts": {
          "applied": 0,
          "not_applied": 3,
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
            "duration_s": 1.0052023589999521,
            "ops_per_sec": 3293.8641362660765,
            "ops_total": 3311.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     2.13ms    3.35ms  37.70ms   95.69%\n    Req/Sec     1.66k   640.90     2.58k    55.00%\n  3311 requests in 1.00s, 501.18KB read\nRequests/sec:   3307.08\nTransfer/sec:    500.58KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "102": {
            "avg_ns_per_run": 278309.0,
            "bytes_jited": 865,
            "bytes_xlated": 1544,
            "id": 102,
            "name": "conntrack_cleanup",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 278309,
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
            "duration_s": 1.1060564570000224,
            "ops_per_sec": 3281.9301194133586,
            "ops_total": 3630.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     3.89ms   16.24ms 206.62ms   97.22%\n    Req/Sec     1.74k   735.34     3.61k    85.71%\n  3630 requests in 1.10s, 549.60KB read\nRequests/sec:   3300.48\nTransfer/sec:    499.71KB"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 102
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 105
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 113
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 114
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 116
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 117
          }
        ],
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
            "avg_ns_per_run": 5191.0,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 15573,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 3241.8320610687024,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_entry",
            "run_cnt_delta": 262,
            "run_time_ns_delta": 849360,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 0.7327986340000052,
            "ops_per_sec": 2736.085886317285,
            "ops_total": 2005.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [20208] setting to a 5 secs run per stressor\nstress-ng: info:  [20208] dispatching hogs: 1 cpu\nstress-ng: info:  [20208] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20208] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20208]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20208] cpu                2005      0.69      0.69      0.00      2891.78        2889.42\nstress-ng: info:  [20208] skipped: 0\nstress-ng: info:  [20208] passed: 1: cpu (1)\nstress-ng: info:  [20208] failed: 0\nstress-ng: info:  [20208] metrics untrustworthy: 0\nstress-ng: info:  [20208] successful run completed in 0.70 secs"
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
            "avg_ns_per_run": 4707.666666666667,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 131,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 14123,
            "type": "tracepoint"
          },
          "132": {
            "avg_ns_per_run": 3310.8122605363983,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 132,
            "name": "native_tracer_entry",
            "run_cnt_delta": 261,
            "run_time_ns_delta": 864122,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 0.7479363410000133,
            "ops_per_sec": 2680.7094268467486,
            "ops_total": 2005.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [20860] setting to a 5 secs run per stressor\nstress-ng: info:  [20860] dispatching hogs: 1 cpu\nstress-ng: info:  [20860] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [20860] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [20860]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [20860] cpu                2005      0.70      0.70      0.00      2864.49        2862.90\nstress-ng: info:  [20860] skipped: 0\nstress-ng: info:  [20860] passed: 1: cpu (1)\nstress-ng: info:  [20860] failed: 0\nstress-ng: info:  [20860] metrics untrustworthy: 0\nstress-ng: info:  [20860] successful run completed in 0.70 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 120
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 121
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 122
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 123
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 124
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 125
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 126
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 127
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 128
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 129
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 130
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 131
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 132
          }
        ],
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
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 140,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "141": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 141,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 213,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 214,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 215,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 218,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 219,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 220,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 222,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 225,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 227,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 228,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 229,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 230,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 231,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "235": {
            "avg_ns_per_run": 242.76187531620664,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 235,
            "name": "cil_from_netdev",
            "run_cnt_delta": 17789,
            "run_time_ns_delta": 4318491,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.015934360000017,
            "ops_per_sec": 3353.563117995087,
            "ops_total": 3407.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     1.76ms    1.58ms  20.89ms   97.41%\n    Req/Sec     1.70k   185.68     1.87k    80.00%\n  3407 requests in 1.01s, 515.71KB read\nRequests/sec:   3363.21\nTransfer/sec:    509.08KB"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 167,
            "bytes_xlated": 280,
            "id": 140,
            "name": "dump_bpf_map",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "141": {
            "avg_ns_per_run": null,
            "bytes_jited": 740,
            "bytes_xlated": 520,
            "id": 141,
            "name": "dump_bpf_prog",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracing"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 213,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 214,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 215,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 218,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 219,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 220,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 222,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 532,
            "bytes_xlated": 960,
            "id": 225,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 227,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 228,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 229,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 230,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 231,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "235": {
            "avg_ns_per_run": 253.92800326330817,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 235,
            "name": "cil_from_netdev",
            "run_cnt_delta": 19612,
            "run_time_ns_delta": 4980036,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1045299270000442,
            "ops_per_sec": 3389.677281238438,
            "ops_total": 3744.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 10 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency     2.03ms    3.05ms  30.97ms   96.29%\n    Req/Sec     1.71k   356.28     2.12k    77.27%\n  3744 requests in 1.10s, 566.85KB read\nRequests/sec:   3403.60\nTransfer/sec:    515.32KB"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 140
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 141
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 213
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 214
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 215
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 218
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 219
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 220
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 222
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 225
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 227
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 228
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 229
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 230
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 231
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 235
          }
        ],
        "program_counts": {
          "applied": 0,
          "not_applied": 16,
          "requested": 16
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
          "251": {
            "avg_ns_per_run": 882.7568922305765,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 251,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 798,
            "run_time_ns_delta": 704440,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 1770.5208333333333,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 253,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 816,
            "run_time_ns_delta": 1444745,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 254,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "255": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 255,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "256": {
            "avg_ns_per_run": 6442.590909090909,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 256,
            "name": "event_execve",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 141737,
            "type": "tracepoint"
          },
          "257": {
            "avg_ns_per_run": 693.0454545454545,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 257,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 15247,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 258,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "261": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 261,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 263,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 266,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 268,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 269,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 270,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 271,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 273,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 275,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 277,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 278,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 279,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 280,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 281,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 283,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 555.658098552026,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 285,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8909,
            "run_time_ns_delta": 4950358,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 286,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 287,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 289,
            "name": "generic_retkprobe_filter_arg",
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 291,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": 333.6653945448423,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 292,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8909,
            "run_time_ns_delta": 2972625,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 293,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 294,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": 778.153144199494,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 295,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 11068,
            "run_time_ns_delta": 8612599,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 296,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 298,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 300,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 301,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 302,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 304,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 305,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": 825.4081011451257,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 306,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 109071,
            "run_time_ns_delta": 90028087,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 307,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 309,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 574.9811426647211,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 311,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8909,
            "run_time_ns_delta": 5122507,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 312,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 313,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 316,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": 351.9374789538669,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 317,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8909,
            "run_time_ns_delta": 3135411,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 318,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 319,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 321,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": 815.4487712323817,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 322,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 11068,
            "run_time_ns_delta": 9025387,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 324,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 327,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": 872.312209508521,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 328,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 53573,
            "run_time_ns_delta": 46732382,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 330,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 331,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": 878.6421853039749,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 332,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 55498,
            "run_time_ns_delta": 48762884,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 333,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 334,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 335,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 336,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 337,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 338,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 339,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 344,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 347,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 349,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 351,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 352,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 353,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 212.08784775530174,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 357,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 59273,
            "run_time_ns_delta": 12571083,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 360,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 361,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": 549.2832590900438,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 362,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 393975,
            "run_time_ns_delta": 216403872,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 363,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 364,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 366,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 367,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": 49.39188695241625,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 368,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 393958,
            "run_time_ns_delta": 19458329,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 369,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 370,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 371,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 372,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 375,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 3132.719339164237,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 377,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 5145,
            "run_time_ns_delta": 16117841,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": 62.15451895043732,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 378,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 5145,
            "run_time_ns_delta": 319785,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 379,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 380,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 381,
            "name": "generic_retkprobe_output",
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
            "avg_ns_per_run": 6632.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 383,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 6632,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 388,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": 433.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 389,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 433,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 390,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 391,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 392,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 393,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 394,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 396,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 397,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 399,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 400,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 401,
            "name": "generic_retkprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 403,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 404,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 406,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 408,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 410,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 411,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 412,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 413,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 414,
            "name": "generic_retkprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 416,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 417,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 421,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 422,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 423,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 425,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 427,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 428,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 430,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 431,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 432,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 433,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 5942.227272727273,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 435,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 130729,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 436,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 437,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 438,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "439": {
            "avg_ns_per_run": 601.6046417750324,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 439,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 6151009,
            "run_time_ns_delta": 3700475566,
            "type": "tracepoint"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 440,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 441,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 442,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 443,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 444,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 445,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 446,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 447,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "448": {
            "avg_ns_per_run": 5758.136363636364,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 126679,
            "type": "raw_tracepoint"
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
            "avg_ns_per_run": 909.8381802476246,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 450,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3473,
            "run_time_ns_delta": 3159868,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 451,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 455,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 456,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": 4099.38112827401,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 457,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2978,
            "run_time_ns_delta": 12207957,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 460,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 463,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 464,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 465,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 467,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 468,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 469,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 470,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 472,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 474,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": 580.7429565607812,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 475,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8909,
            "run_time_ns_delta": 5173839,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 476,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 477,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": 376.1632057469974,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 478,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 8909,
            "run_time_ns_delta": 3351238,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 479,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "480": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 480,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "481": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 481,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "482": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 482,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "483": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 483,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "484": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 484,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": 914.83330321648,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 485,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 11068,
            "run_time_ns_delta": 10125375,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 486,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 487,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 488,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 489,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 490,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 491,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 493,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "494": {
            "avg_ns_per_run": 2649.125,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 494,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 21193,
            "type": "kprobe"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 495,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 496,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 497,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 498,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 499,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "500": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 500,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "501": {
            "avg_ns_per_run": 5138.666666666667,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 501,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 15416,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 502,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 503,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 504,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 3577.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 506,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3577,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 507,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 508,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 509,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 510,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 511,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": 3141.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 512,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3141,
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
            "avg_ns_per_run": 7076.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 514,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 7076,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 515,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 516,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 517,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 518,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 5168.666666666667,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 520,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 15506,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 521,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 522,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 523,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 524,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 525,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 527,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 528,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": 576.3601095836799,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 529,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 102205,
            "run_time_ns_delta": 58906885,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 530,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 531,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 532,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 533,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 534,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 535,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 536,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 537,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 538,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 539,
            "name": "generic_kprobe_output",
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
          }
        },
        "workloads": [
          {
            "duration_s": 7.057588210999995,
            "ops_per_sec": 1697.4637286612879,
            "ops_total": 11980.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [28659]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [28659] sockdiag           1034      0.00      0.00      0.00   1739635.11      976392.82\nstress-ng: info:  [28659] skipped: 0\nstress-ng: info:  [28659] passed: 1: sockdiag (1)\nstress-ng: info:  [28659] failed: 0\nstress-ng: info:  [28659] metrics untrustworthy: 0\nstress-ng: info:  [28659] successful run completed in 0.00 secs\nstress-ng: info:  [28661] setting to a 1 secs run per stressor\nstress-ng: info:  [28661] dispatching hogs: 1 sockfd\nstress-ng: info:  [28661] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [28661] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [28661]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [28661] sockfd              200      0.00      0.00      0.00     67167.97       41220.12\nstress-ng: info:  [28661] skipped: 0\nstress-ng: info:  [28661] passed: 1: sockfd (1)\nstress-ng: info:  [28661] failed: 0\nstress-ng: info:  [28661] metrics untrustworthy: 0\nstress-ng: info:  [28661] successful run completed in 0.00 secs\nstress-ng: info:  [28664] setting to a 1 secs run per stressor\nstress-ng: info:  [28664] dispatching hogs: 1 sockpair\nstress-ng: info:  [28664] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [28664] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [28664]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [28664] sockpair            500      0.04      0.00      0.06     11297.00        8902.34\nstress-ng: info:  [28664] skipped: 0\nstress-ng: info:  [28664] passed: 1: sockpair (1)\nstress-ng: info:  [28664] failed: 0\nstress-ng: info:  [28664] metrics untrustworthy: 0\nstress-ng: info:  [28664] successful run completed in 0.05 secs\nstress-ng: info:  [28668] setting to a 1 secs run per stressor\nstress-ng: info:  [28668] dispatching hogs: 1 udp-flood\nstress-ng: info:  [28668] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [28668] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [28668]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [28668] udp-flood          1000      0.01      0.00      0.01    111848.11      104210.09\nstress-ng: info:  [28668] skipped: 0\nstress-ng: info:  [28668] passed: 1: udp-flood (1)\nstress-ng: info:  [28668] failed: 0\nstress-ng: info:  [28668] metrics untrustworthy: 0\nstress-ng: info:  [28668] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "251": {
            "avg_ns_per_run": 899.1816009557945,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 251,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 837,
            "run_time_ns_delta": 752615,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 1590.0833333333333,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 253,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 852,
            "run_time_ns_delta": 1354751,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 254,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "255": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 255,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "256": {
            "avg_ns_per_run": 6337.0,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 256,
            "name": "event_execve",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 139414,
            "type": "tracepoint"
          },
          "257": {
            "avg_ns_per_run": 715.0454545454545,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 257,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 15731,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 258,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "261": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 261,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 263,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 266,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 268,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 269,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 270,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 271,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 273,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 275,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 277,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 278,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 279,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 280,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 281,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 283,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": 412.2800563777308,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 285,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7095,
            "run_time_ns_delta": 2925127,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 286,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 287,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 289,
            "name": "generic_retkprobe_filter_arg",
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 291,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": 120.34742776603241,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 292,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 7095,
            "run_time_ns_delta": 853865,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 293,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 294,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": 617.569333507922,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 295,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7637,
            "run_time_ns_delta": 4716377,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 296,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 298,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 300,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 301,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 302,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 304,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 305,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": 938.7762190308687,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 306,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 72209,
            "run_time_ns_delta": 67788092,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 307,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 309,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 432.45285412262155,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 311,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7095,
            "run_time_ns_delta": 3068253,
            "type": "kprobe"
          },
          "312": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 312,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "313": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 313,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 316,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "317": {
            "avg_ns_per_run": 134.27004933051444,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 317,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 7095,
            "run_time_ns_delta": 952646,
            "type": "kprobe"
          },
          "318": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 318,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "319": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 319,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 321,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "322": {
            "avg_ns_per_run": 741.2500982061018,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 322,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7637,
            "run_time_ns_delta": 5660927,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 324,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 327,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "328": {
            "avg_ns_per_run": 968.2944300849263,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 328,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 35207,
            "run_time_ns_delta": 34090742,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 330,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "331": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 331,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "332": {
            "avg_ns_per_run": 954.9582995513756,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 332,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 37002,
            "run_time_ns_delta": 35335367,
            "type": "kprobe"
          },
          "333": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 333,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "334": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 334,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "335": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 335,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "336": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 336,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "337": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 337,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "338": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 338,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "339": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 339,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 344,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 347,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 349,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 351,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "352": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 352,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "353": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 353,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 209.05670093811332,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 357,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 55537,
            "run_time_ns_delta": 11610382,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 360,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "361": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 361,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "362": {
            "avg_ns_per_run": 586.8675864127878,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 362,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 395254,
            "run_time_ns_delta": 231961761,
            "type": "kprobe"
          },
          "363": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 363,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "364": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 364,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 366,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "367": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 367,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "368": {
            "avg_ns_per_run": 53.0990413152881,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 368,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 395229,
            "run_time_ns_delta": 20986281,
            "type": "kprobe"
          },
          "369": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 369,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "370": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 370,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "371": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 371,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "372": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 372,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 375,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 4124.291184682888,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 377,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 5014,
            "run_time_ns_delta": 20679196,
            "type": "kprobe"
          },
          "378": {
            "avg_ns_per_run": 71.57638611886718,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 378,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 5014,
            "run_time_ns_delta": 358884,
            "type": "kprobe"
          },
          "379": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 379,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "380": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 380,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "381": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 381,
            "name": "generic_retkprobe_output",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 383,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 388,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "389": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 389,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "390": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 390,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "391": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 391,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "392": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 392,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "393": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 393,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "394": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 394,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 396,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "397": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 397,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 399,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "400": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 400,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "401": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 401,
            "name": "generic_retkprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 403,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "404": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 404,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 406,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 408,
            "name": "generic_kprobe_filter_arg",
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
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 410,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "411": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 411,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "412": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 412,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "413": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 413,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "414": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 414,
            "name": "generic_retkprobe_filter_arg",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 416,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "417": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 417,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 421,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "422": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 422,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "423": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 423,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 425,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 427,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "428": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 428,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 430,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "431": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 431,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "432": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 432,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "433": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 433,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 6074.227272727273,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 435,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 133633,
            "type": "kprobe"
          },
          "436": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 436,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "437": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 437,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "438": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 438,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "439": {
            "avg_ns_per_run": 604.5464831951234,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 439,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 5806023,
            "run_time_ns_delta": 3510010786,
            "type": "tracepoint"
          },
          "440": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 440,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "441": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 441,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "442": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 442,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "443": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 443,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "444": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 444,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "445": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 445,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "446": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 446,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "447": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 447,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "448": {
            "avg_ns_per_run": 4964.954545454545,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 448,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 22,
            "run_time_ns_delta": 109229,
            "type": "raw_tracepoint"
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
            "avg_ns_per_run": 743.1604054859869,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 450,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1677,
            "run_time_ns_delta": 1246280,
            "type": "kprobe"
          },
          "451": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 451,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 455,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "456": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 456,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "457": {
            "avg_ns_per_run": 3947.9811694747273,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 457,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3027,
            "run_time_ns_delta": 11950539,
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 460,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 463,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "464": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 464,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "465": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 465,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 467,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "468": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 468,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "469": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 469,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "470": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 470,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 472,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 474,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "475": {
            "avg_ns_per_run": 447.1148696264975,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 475,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7095,
            "run_time_ns_delta": 3172280,
            "type": "kprobe"
          },
          "476": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 476,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "477": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 477,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "478": {
            "avg_ns_per_run": 133.88090204369274,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 478,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 7095,
            "run_time_ns_delta": 949885,
            "type": "kprobe"
          },
          "479": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 479,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "480": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 480,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "481": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 481,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "482": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 482,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "483": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 483,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "484": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 484,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "485": {
            "avg_ns_per_run": 826.1457378551787,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 485,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7637,
            "run_time_ns_delta": 6309275,
            "type": "kprobe"
          },
          "486": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 486,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "487": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 487,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "488": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 488,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "489": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 489,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "490": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 490,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "491": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 491,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 493,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "494": {
            "avg_ns_per_run": 2529.625,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 494,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 16,
            "run_time_ns_delta": 40474,
            "type": "kprobe"
          },
          "495": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 495,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "496": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 496,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "497": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 497,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "498": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 498,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "499": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 499,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "500": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 500,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "501": {
            "avg_ns_per_run": 4311.6,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 501,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 21558,
            "type": "kprobe"
          },
          "502": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 502,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "503": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 503,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "504": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 504,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 5096.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 506,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 10192,
            "type": "kprobe"
          },
          "507": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 507,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "508": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 508,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "509": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 509,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "510": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 510,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "511": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 511,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "512": {
            "avg_ns_per_run": 3747.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 512,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 7494,
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
            "avg_ns_per_run": 8314.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 514,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 16628,
            "type": "kprobe"
          },
          "515": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 515,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "516": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 516,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "517": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 517,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "518": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 518,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": 4501.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 520,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 22505,
            "type": "kprobe"
          },
          "521": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 521,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "522": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 522,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "523": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 523,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "524": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 524,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "525": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 525,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 527,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "528": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 528,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "529": {
            "avg_ns_per_run": 532.7678040381907,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 529,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 102224,
            "run_time_ns_delta": 54461656,
            "type": "kprobe"
          },
          "530": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 530,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "531": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 531,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "532": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 532,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "533": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 533,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "534": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 534,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "535": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 535,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "536": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 536,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "537": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 537,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "538": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 538,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "539": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 539,
            "name": "generic_kprobe_output",
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
          }
        },
        "workloads": [
          {
            "duration_s": 6.785766151999951,
            "ops_per_sec": 1773.1232893214042,
            "ops_total": 12032.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [29716]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29716] sockdiag           1034      0.00      0.00      0.00   1141893.19      711141.68\nstress-ng: info:  [29716] skipped: 0\nstress-ng: info:  [29716] passed: 1: sockdiag (1)\nstress-ng: info:  [29716] failed: 0\nstress-ng: info:  [29716] metrics untrustworthy: 0\nstress-ng: info:  [29716] successful run completed in 0.00 secs\nstress-ng: info:  [29718] setting to a 1 secs run per stressor\nstress-ng: info:  [29718] dispatching hogs: 1 sockfd\nstress-ng: info:  [29718] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29718] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29718]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29718] sockfd              200      0.00      0.01      0.00     51378.75       30520.37\nstress-ng: info:  [29718] skipped: 0\nstress-ng: info:  [29718] passed: 1: sockfd (1)\nstress-ng: info:  [29718] failed: 0\nstress-ng: info:  [29718] metrics untrustworthy: 0\nstress-ng: info:  [29718] successful run completed in 0.01 secs\nstress-ng: info:  [29721] setting to a 1 secs run per stressor\nstress-ng: info:  [29721] dispatching hogs: 1 sockpair\nstress-ng: info:  [29721] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29721] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29721]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29721] sockpair            500      0.04      0.00      0.06     11195.68        8823.17\nstress-ng: info:  [29721] skipped: 0\nstress-ng: info:  [29721] passed: 1: sockpair (1)\nstress-ng: info:  [29721] failed: 0\nstress-ng: info:  [29721] metrics untrustworthy: 0\nstress-ng: info:  [29721] successful run completed in 0.05 secs\nstress-ng: info:  [29725] setting to a 1 secs run per stressor\nstress-ng: info:  [29725] dispatching hogs: 1 udp-flood\nstress-ng: info:  [29725] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29725] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29725]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29725] udp-flood          1000      0.01      0.00      0.01    108430.38      102690.49\nstress-ng: info:  [29725] skipped: 0\nstress-ng: info:  [29725] passed: 1: udp-flood (1)\nstress-ng: info:  [29725] failed: 0\nstress-ng: info:  [29725] metrics untrustworthy: 0\nstress-ng: info:  [29725] successful run completed in 0.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 251
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 253
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 254
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 255
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 256
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 257
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 258
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 261
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 262
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 263
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 264
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 265
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 266
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 267
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 268
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 269
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 270
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 271
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 272
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 273
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 274
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 275
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 276
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 277
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 278
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 279
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 280
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 281
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 282
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 283
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 284
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 285
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 286
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 287
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 288
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 289
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 290
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 291
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 292
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 293
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 294
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 295
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 296
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 297
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 298
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 299
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 300
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 301
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 302
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 303
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 304
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 305
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 306
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 307
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 308
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 309
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 310
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 311
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 312
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 313
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 314
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 315
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 316
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 317
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 318
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 319
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 320
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 321
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 322
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 323
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 324
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 325
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 326
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 327
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 328
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 329
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 330
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 331
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 332
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 333
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 334
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 335
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 336
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 337
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 338
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 339
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 340
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 341
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 342
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 343
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 344
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 345
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 346
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 347
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 348
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 349
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 350
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 351
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 352
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 353
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 354
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 355
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 356
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 357
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 358
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 359
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 360
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 361
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 362
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 363
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 364
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 365
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 366
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 367
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 368
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 369
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 370
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 371
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 372
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 373
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 374
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 375
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 376
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 377
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 378
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 379
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 380
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 381
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 382
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 383
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 384
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 385
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 386
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 387
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 388
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 389
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 390
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 391
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 392
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 393
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 394
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 395
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 396
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 397
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 398
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 399
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 400
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 401
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 402
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 403
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 404
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 405
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 406
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 407
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 408
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 409
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 410
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 411
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 412
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 413
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 414
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 415
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 416
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 417
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 418
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 419
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 420
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 421
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 422
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 423
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 424
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 425
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 426
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 427
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 428
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 429
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 430
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 431
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 432
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 433
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 434
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 435
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 436
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 437
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 438
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 439
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 440
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 441
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 442
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 443
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 444
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 445
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 446
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 447
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 448
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 449
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 450
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 451
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 452
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 453
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 454
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 455
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 456
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 457
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 458
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 459
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 460
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 461
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 462
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 463
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 464
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 465
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 466
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 467
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 468
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 469
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 470
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 471
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 472
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 473
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 474
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 475
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 476
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 477
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 478
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 479
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 480
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 481
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 482
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 483
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 484
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 485
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 486
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 487
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 488
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 489
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 490
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 491
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 492
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 493
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 494
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 495
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 496
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 497
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 498
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 499
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 500
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 501
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 502
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 503
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 504
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 505
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 506
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 507
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 508
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 509
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 510
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 511
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 512
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 513
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 514
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 515
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 516
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 517
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 518
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 519
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 520
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 521
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 522
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 523
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 524
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 525
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 526
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 527
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 528
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 529
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 530
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 531
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 532
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 533
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 534
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 535
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 536
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 537
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 538
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 539
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 540
          }
        ],
        "program_counts": {
          "applied": 0,
          "not_applied": 287,
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
          "547": {
            "avg_ns_per_run": null,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 547,
            "name": "xdp_root",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "553": {
            "avg_ns_per_run": 57.5328125,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 640,
            "run_time_ns_delta": 36821,
            "type": "xdp"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 555,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.119600704999982,
            "ops_per_sec": 571.6323660228584,
            "ops_total": 640.0,
            "stderr": "{'retval': 2, 'duration_ns': 76, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "547": {
            "avg_ns_per_run": null,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 547,
            "name": "xdp_root",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "xdp"
          },
          "553": {
            "avg_ns_per_run": 68.638671875,
            "bytes_jited": 13629,
            "bytes_xlated": 23840,
            "id": 553,
            "name": "balancer_ingress",
            "run_cnt_delta": 512,
            "run_time_ns_delta": 35143,
            "type": "xdp"
          },
          "555": {
            "avg_ns_per_run": null,
            "bytes_jited": 541,
            "bytes_xlated": 1000,
            "id": 555,
            "name": "healthcheck_encap",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0311476030000222,
            "ops_per_sec": 496.5341513769576,
            "ops_total": 512.0,
            "stderr": "{'retval': 2, 'duration_ns': 135, 'repeat': 128, 'data_size_in': 64, 'data_size_out': 84, 'data_out_preview_hex': '02000000000b02000000000a0800450000460000000040045a62ac1069780ac8', 'packet_path': '/home/yunwei37/workspace/bpf-benchmark/corpus/inputs/katran_vip_packet_64.bin', 'expected_retval': 3, 'expected_action': 'XDP_TX', 'action': 'XDP_PASS', 'ok': False}",
            "stdout": ""
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 547
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 553
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 555
          }
        ],
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
          "570": {
            "avg_ns_per_run": 160.32735187204418,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 2330367,
            "run_time_ns_delta": 373621570,
            "type": "raw_tracepoint"
          },
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 571,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "572": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 572,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "573": {
            "avg_ns_per_run": 303.0312095123696,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 2330187,
            "run_time_ns_delta": 706119385,
            "type": "raw_tracepoint"
          },
          "574": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 574,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 575,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "576": {
            "avg_ns_per_run": 276.74220731060365,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 2329876,
            "run_time_ns_delta": 644775027,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 268.74460447249623,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 2329661,
            "run_time_ns_delta": 626083824,
            "type": "raw_tracepoint"
          },
          "578": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 578,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 579,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 580,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 581,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 71.00305315067659,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 263007,
            "run_time_ns_delta": 18674300,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 272.203218925732,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 583,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 263007,
            "run_time_ns_delta": 71591352,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 584,
            "name": "trace_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 585,
            "name": "trace_ret_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": 741.8571428571429,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 10386,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 2003.5714285714287,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 28050,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 588,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 589,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 590,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "591": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 591,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "592": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 592,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "593": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 593,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "594": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 594,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": 2259.7731755424065,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 595,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 2291410,
            "type": "raw_tracepoint"
          },
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 596,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 597,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 598,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 599,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 600,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 601,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 602,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": 5312.571428571428,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 603,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 37188,
            "type": "raw_tracepoint"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 604,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "605": {
            "avg_ns_per_run": 1322.8076923076924,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 605,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 1341327,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 625.3974358974359,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 634153,
            "type": "raw_tracepoint"
          },
          "607": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 607,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "608": {
            "avg_ns_per_run": 438.2970645376857,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 608,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 225961,
            "run_time_ns_delta": 99038043,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 18.549985255086995,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 6782,
            "run_time_ns_delta": 125806,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 610,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 771.491124260355,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 782292,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 612,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 613,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 614,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": 810.2857142857143,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 615,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 17016,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 616,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 617,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "618": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 618,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 619,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 3513.5714285714284,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 620,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 24595,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 621.3379392025266,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 17731,
            "run_time_ns_delta": 11016943,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 622,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": 1536.5,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 623,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3073,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 330.22564535955746,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 624,
            "name": "trace_commit_creds",
            "run_cnt_delta": 13016,
            "run_time_ns_delta": 4298217,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 440.1094674556213,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 625,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 446271,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 179.16655771872485,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 626,
            "name": "trace_cap_capable",
            "run_cnt_delta": 105555,
            "run_time_ns_delta": 18911926,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 681.5,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 627,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 34,
            "run_time_ns_delta": 23171,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 628,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 629,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 630,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 631,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": null,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 632,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 751.5454545454545,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 633,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 33,
            "run_time_ns_delta": 24801,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 3510.4166666666665,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 634,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 24,
            "run_time_ns_delta": 84250,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1745.0,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 635,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1745,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": null,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 636,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 637,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 638,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "639": {
            "avg_ns_per_run": 115.73903417543909,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 141827,
            "run_time_ns_delta": 16414920,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 44.78651011917354,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 141810,
            "run_time_ns_delta": 6351175,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 34.53827111734877,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 641,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 141791,
            "run_time_ns_delta": 4897216,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 43.564003075816046,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 642,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 141751,
            "run_time_ns_delta": 6175241,
            "type": "kprobe"
          },
          "643": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 643,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 644,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 645,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": null,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 646,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": null,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 647,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 648,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 649,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 650,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 651,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "652": {
            "avg_ns_per_run": null,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 652,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "653": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 653,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "654": {
            "avg_ns_per_run": 112.92446198385363,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 127459,
            "run_time_ns_delta": 14393239,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 39.25005100039231,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 655,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 127450,
            "run_time_ns_delta": 5002419,
            "type": "kprobe"
          },
          "656": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 656,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "657": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 657,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": null,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 658,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 659,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": 149.9758957654723,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 660,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 1535,
            "run_time_ns_delta": 230213,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 121.66959385290889,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 110841,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 41.57409440175631,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 662,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 37874,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 555.2612513721185,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 505843,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 857.6755319148937,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 188,
            "run_time_ns_delta": 161243,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 665,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "666": {
            "avg_ns_per_run": 301.4762700306853,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 666,
            "name": "trace_security_bpf",
            "run_cnt_delta": 29330,
            "run_time_ns_delta": 8842299,
            "type": "kprobe"
          },
          "667": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 667,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "668": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 668,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "669": {
            "avg_ns_per_run": 260.79046862589354,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 669,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 6295,
            "run_time_ns_delta": 1641676,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 882.075,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 670,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 520,
            "run_time_ns_delta": 458679,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 671,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "672": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 672,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "673": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 673,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "674": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 674,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 675,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": null,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 676,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "677": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 677,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "678": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 678,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 679,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "680": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 680,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "681": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 681,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "682": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 682,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 683,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 1642.2142857142858,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 684,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 22991,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 42.55624486548019,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 685,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 271447,
            "run_time_ns_delta": 11551765,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 845.7651006711409,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 686,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 1043,
            "run_time_ns_delta": 882133,
            "type": "raw_tracepoint"
          },
          "687": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 687,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 688,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "689": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 689,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "690": {
            "avg_ns_per_run": 709.4953703703703,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 2592,
            "run_time_ns_delta": 1839012,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 691,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "692": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 692,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "693": {
            "avg_ns_per_run": null,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 693,
            "name": "trace_do_truncate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 339.74481946624803,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 694,
            "name": "trace_fd_install",
            "run_cnt_delta": 25480,
            "run_time_ns_delta": 8656698,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 1102.9742313323572,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 695,
            "name": "trace_filp_close",
            "run_cnt_delta": 3415,
            "run_time_ns_delta": 3766657,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 213.94444444444446,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 696,
            "name": "trace_file_update_time",
            "run_cnt_delta": 288,
            "run_time_ns_delta": 61616,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 36.447916666666664,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 697,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 288,
            "run_time_ns_delta": 10497,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": null,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 698,
            "name": "trace_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": null,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 699,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 700,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 701,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "702": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 702,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "703": {
            "avg_ns_per_run": 140.71428571428572,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 703,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 985,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 3657.1428571428573,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 25600,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 4691.857142857143,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 705,
            "name": "trace_execute_finished",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 32843,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 706,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": 3061.0,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 707,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 21427,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 278.1142335396165,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 708,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 19714,
            "run_time_ns_delta": 5482744,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 709,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 710,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 355.9416180512553,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 92049,
            "run_time_ns_delta": 32764070,
            "type": "kprobe"
          },
          "712": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 712,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "713": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 713,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "714": {
            "avg_ns_per_run": 192.68965517241378,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 714,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 58,
            "run_time_ns_delta": 11176,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1203.9310344827586,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 715,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 58,
            "run_time_ns_delta": 69828,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": null,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 995.5714285714286,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 717,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 6969,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 2116.0,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 718,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 6348,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 1298.4615384615386,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 719,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 13,
            "run_time_ns_delta": 16880,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": 962.6,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 721,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 4813,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": 1636.8,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 722,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 8184,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 723,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 724,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 99.57142857142857,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 697,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 1059.7142857142858,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 726,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 7418,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 267.2237703068592,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 727,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 17728,
            "run_time_ns_delta": 4737343,
            "type": "lsm"
          },
          "728": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 728,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.2462540430000217,
            "ops_per_sec": 2770.835302175988,
            "ops_total": 6224.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [29702]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29702] get                 200      0.35      0.02      0.16       565.71        1136.34\nstress-ng: info:  [29702] skipped: 0\nstress-ng: info:  [29702] passed: 1: get (1)\nstress-ng: info:  [29702] failed: 0\nstress-ng: info:  [29702] metrics untrustworthy: 0\nstress-ng: info:  [29702] successful run completed in 0.36 secs\nstress-ng: info:  [29704] setting to a 5 secs run per stressor\nstress-ng: info:  [29704] dispatching hogs: 1 prctl\nstress-ng: info:  [29704] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [29704] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [29704]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [29704] prctl              1000      1.41      1.03      0.30       709.75         751.06\nstress-ng: info:  [29704] skipped: 0\nstress-ng: info:  [29704] passed: 1: prctl (1)\nstress-ng: info:  [29704] failed: 0\nstress-ng: info:  [29704] metrics untrustworthy: 0\nstress-ng: info:  [29704] successful run completed in 1.41 secs\nstress-ng: info:  [30706] setting to a 5 secs run per stressor\nstress-ng: info:  [30706] dispatching hogs: 1 set\nstress-ng: info:  [30706] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [30706] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [30706]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [30706] set                1000      0.20      0.00      0.20      4954.91        4951.03\nstress-ng: info:  [30706] skipped: 0\nstress-ng: info:  [30706] passed: 1: set (1)\nstress-ng: info:  [30706] failed: 0\nstress-ng: info:  [30706] metrics untrustworthy: 0\nstress-ng: info:  [30706] successful run completed in 0.20 secs\nstress-ng: info:  [30708] setting to a 5 secs run per stressor\nstress-ng: info:  [30708] dispatching hogs: 1 timerfd\nstress-ng: info:  [30708] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [30708] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [30708]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [30708] timerfd            1024      0.02      0.00      0.02     55411.78       54154.11\nstress-ng: info:  [30708] skipped: 0\nstress-ng: info:  [30708] passed: 1: timerfd (1)\nstress-ng: info:  [30708] failed: 0\nstress-ng: info:  [30708] metrics untrustworthy: 0\nstress-ng: info:  [30708] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "570": {
            "avg_ns_per_run": 161.24029695250493,
            "bytes_jited": 234,
            "bytes_xlated": 264,
            "id": 570,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 2250865,
            "run_time_ns_delta": 362930141,
            "type": "raw_tracepoint"
          },
          "571": {
            "avg_ns_per_run": null,
            "bytes_jited": 2513,
            "bytes_xlated": 4552,
            "id": 571,
            "name": "sys_enter_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "572": {
            "avg_ns_per_run": null,
            "bytes_jited": 17446,
            "bytes_xlated": 30376,
            "id": 572,
            "name": "sys_enter_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "573": {
            "avg_ns_per_run": 302.91174040438324,
            "bytes_jited": 263,
            "bytes_xlated": 320,
            "id": 573,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 2251132,
            "run_time_ns_delta": 681894312,
            "type": "raw_tracepoint"
          },
          "574": {
            "avg_ns_per_run": null,
            "bytes_jited": 2093,
            "bytes_xlated": 3800,
            "id": 574,
            "name": "sys_exit_init",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "575": {
            "avg_ns_per_run": null,
            "bytes_jited": 11583,
            "bytes_xlated": 19880,
            "id": 575,
            "name": "sys_exit_submit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "576": {
            "avg_ns_per_run": 278.05347673632485,
            "bytes_jited": 8156,
            "bytes_xlated": 13688,
            "id": 576,
            "name": "trace_sys_enter",
            "run_cnt_delta": 2251278,
            "run_time_ns_delta": 625975675,
            "type": "raw_tracepoint"
          },
          "577": {
            "avg_ns_per_run": 269.91762982993754,
            "bytes_jited": 8189,
            "bytes_xlated": 13744,
            "id": 577,
            "name": "trace_sys_exit",
            "run_cnt_delta": 2251349,
            "run_time_ns_delta": 607678786,
            "type": "raw_tracepoint"
          },
          "578": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 578,
            "name": "trace_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "579": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 579,
            "name": "trace_ret_ptrace",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "580": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 580,
            "name": "trace_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "581": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 581,
            "name": "trace_ret_process_vm_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "582": {
            "avg_ns_per_run": 71.43898831590033,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 582,
            "name": "trace_arch_prctl",
            "run_cnt_delta": 263007,
            "run_time_ns_delta": 18788954,
            "type": "kprobe"
          },
          "583": {
            "avg_ns_per_run": 271.2570768078416,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 583,
            "name": "trace_ret_arch_prctl",
            "run_cnt_delta": 263007,
            "run_time_ns_delta": 71342510,
            "type": "kprobe"
          },
          "584": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 584,
            "name": "trace_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "585": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 585,
            "name": "trace_ret_dup",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "586": {
            "avg_ns_per_run": 717.8571428571429,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 586,
            "name": "trace_dup2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 10050,
            "type": "kprobe"
          },
          "587": {
            "avg_ns_per_run": 2140.5714285714284,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 587,
            "name": "trace_ret_dup2",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 29968,
            "type": "kprobe"
          },
          "588": {
            "avg_ns_per_run": null,
            "bytes_jited": 2356,
            "bytes_xlated": 4424,
            "id": 588,
            "name": "trace_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "589": {
            "avg_ns_per_run": null,
            "bytes_jited": 11319,
            "bytes_xlated": 19504,
            "id": 589,
            "name": "trace_ret_dup3",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "590": {
            "avg_ns_per_run": null,
            "bytes_jited": 20734,
            "bytes_xlated": 31992,
            "id": 590,
            "name": "syscall__execve_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "591": {
            "avg_ns_per_run": null,
            "bytes_jited": 20705,
            "bytes_xlated": 32008,
            "id": 591,
            "name": "syscall__execve_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "592": {
            "avg_ns_per_run": null,
            "bytes_jited": 20997,
            "bytes_xlated": 32400,
            "id": 592,
            "name": "syscall__execveat_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "593": {
            "avg_ns_per_run": null,
            "bytes_jited": 20965,
            "bytes_xlated": 32408,
            "id": 593,
            "name": "syscall__execveat_exit",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "594": {
            "avg_ns_per_run": null,
            "bytes_jited": 12292,
            "bytes_xlated": 18744,
            "id": 594,
            "name": "sys_dup_exit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "595": {
            "avg_ns_per_run": 2419.3984220907296,
            "bytes_jited": 19722,
            "bytes_xlated": 32248,
            "id": 595,
            "name": "tracepoint__sched__sched_process_fork",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 2453270,
            "type": "raw_tracepoint"
          },
          "596": {
            "avg_ns_per_run": null,
            "bytes_jited": 59266,
            "bytes_xlated": 108072,
            "id": 596,
            "name": "lkm_seeker_modtree_loop",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "597": {
            "avg_ns_per_run": null,
            "bytes_jited": 6232,
            "bytes_xlated": 10320,
            "id": 597,
            "name": "uprobe_lkm_seeker_submitter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "598": {
            "avg_ns_per_run": null,
            "bytes_jited": 4339,
            "bytes_xlated": 7784,
            "id": 598,
            "name": "uprobe_lkm_seeker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "599": {
            "avg_ns_per_run": null,
            "bytes_jited": 62309,
            "bytes_xlated": 111768,
            "id": 599,
            "name": "lkm_seeker_kset_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "600": {
            "avg_ns_per_run": null,
            "bytes_jited": 652,
            "bytes_xlated": 1048,
            "id": 600,
            "name": "lkm_seeker_mod_tree_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "601": {
            "avg_ns_per_run": null,
            "bytes_jited": 57791,
            "bytes_xlated": 102120,
            "id": 601,
            "name": "lkm_seeker_proc_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "602": {
            "avg_ns_per_run": null,
            "bytes_jited": 3889,
            "bytes_xlated": 6456,
            "id": 602,
            "name": "lkm_seeker_new_mod_only_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "603": {
            "avg_ns_per_run": 6566.571428571428,
            "bytes_jited": 20556,
            "bytes_xlated": 35424,
            "id": 603,
            "name": "tracepoint__sched__sched_process_exec",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 45966,
            "type": "raw_tracepoint"
          },
          "604": {
            "avg_ns_per_run": null,
            "bytes_jited": 24434,
            "bytes_xlated": 38432,
            "id": 604,
            "name": "sched_process_exec_event_submit_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "605": {
            "avg_ns_per_run": 1274.1854043392505,
            "bytes_jited": 8700,
            "bytes_xlated": 14536,
            "id": 605,
            "name": "tracepoint__sched__sched_process_exit",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 1292024,
            "type": "raw_tracepoint"
          },
          "606": {
            "avg_ns_per_run": 623.2470472440945,
            "bytes_jited": 248,
            "bytes_xlated": 440,
            "id": 606,
            "name": "tracepoint__sched__sched_process_free",
            "run_cnt_delta": 1016,
            "run_time_ns_delta": 633219,
            "type": "raw_tracepoint"
          },
          "607": {
            "avg_ns_per_run": null,
            "bytes_jited": 9155,
            "bytes_xlated": 13888,
            "id": 607,
            "name": "syscall__accept4",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "608": {
            "avg_ns_per_run": 434.95716131907307,
            "bytes_jited": 8945,
            "bytes_xlated": 14912,
            "id": 608,
            "name": "tracepoint__sched__sched_switch",
            "run_cnt_delta": 224400,
            "run_time_ns_delta": 97604387,
            "type": "raw_tracepoint"
          },
          "609": {
            "avg_ns_per_run": 18.605945699984833,
            "bytes_jited": 8201,
            "bytes_xlated": 13776,
            "id": 609,
            "name": "trace_filldir64",
            "run_cnt_delta": 6593,
            "run_time_ns_delta": 122669,
            "type": "kprobe"
          },
          "610": {
            "avg_ns_per_run": null,
            "bytes_jited": 23523,
            "bytes_xlated": 36784,
            "id": 610,
            "name": "trace_call_usermodehelper",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "611": {
            "avg_ns_per_run": 750.1272189349113,
            "bytes_jited": 7959,
            "bytes_xlated": 13408,
            "id": 611,
            "name": "trace_do_exit",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 760629,
            "type": "kprobe"
          },
          "612": {
            "avg_ns_per_run": null,
            "bytes_jited": 56303,
            "bytes_xlated": 97056,
            "id": 612,
            "name": "uprobe_syscall_table_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "613": {
            "avg_ns_per_run": null,
            "bytes_jited": 6788,
            "bytes_xlated": 11256,
            "id": 613,
            "name": "uprobe_seq_ops_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "614": {
            "avg_ns_per_run": null,
            "bytes_jited": 6553,
            "bytes_xlated": 10976,
            "id": 614,
            "name": "uprobe_mem_dump_trigger",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "615": {
            "avg_ns_per_run": 887.0,
            "bytes_jited": 11476,
            "bytes_xlated": 18328,
            "id": 615,
            "name": "trace_security_file_ioctl",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 18627,
            "type": "kprobe"
          },
          "616": {
            "avg_ns_per_run": null,
            "bytes_jited": 9747,
            "bytes_xlated": 15688,
            "id": 616,
            "name": "trace_tracepoint_probe_register_prio_may_exist",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "617": {
            "avg_ns_per_run": null,
            "bytes_jited": 8649,
            "bytes_xlated": 14440,
            "id": 617,
            "name": "tracepoint__cgroup__cgroup_attach_task",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "618": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 618,
            "name": "tracepoint__cgroup__cgroup_mkdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "619": {
            "avg_ns_per_run": null,
            "bytes_jited": 8624,
            "bytes_xlated": 14416,
            "id": 619,
            "name": "tracepoint__cgroup__cgroup_rmdir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "620": {
            "avg_ns_per_run": 4088.4285714285716,
            "bytes_jited": 33399,
            "bytes_xlated": 52904,
            "id": 620,
            "name": "trace_security_bprm_check",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 28619,
            "type": "kprobe"
          },
          "621": {
            "avg_ns_per_run": 659.0068798285682,
            "bytes_jited": 22985,
            "bytes_xlated": 37160,
            "id": 621,
            "name": "trace_security_file_open",
            "run_cnt_delta": 17733,
            "run_time_ns_delta": 11686169,
            "type": "kprobe"
          },
          "622": {
            "avg_ns_per_run": null,
            "bytes_jited": 18653,
            "bytes_xlated": 30680,
            "id": 622,
            "name": "trace_security_sb_mount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "623": {
            "avg_ns_per_run": 1588.5,
            "bytes_jited": 9997,
            "bytes_xlated": 16416,
            "id": 623,
            "name": "trace_security_inode_unlink",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 3177,
            "type": "kprobe"
          },
          "624": {
            "avg_ns_per_run": 320.3696704309749,
            "bytes_jited": 10745,
            "bytes_xlated": 16960,
            "id": 624,
            "name": "trace_commit_creds",
            "run_cnt_delta": 13017,
            "run_time_ns_delta": 4170252,
            "type": "kprobe"
          },
          "625": {
            "avg_ns_per_run": 429.81360946745565,
            "bytes_jited": 10034,
            "bytes_xlated": 16552,
            "id": 625,
            "name": "trace_switch_task_namespaces",
            "run_cnt_delta": 1014,
            "run_time_ns_delta": 435831,
            "type": "kprobe"
          },
          "626": {
            "avg_ns_per_run": 182.52790049487118,
            "bytes_jited": 8199,
            "bytes_xlated": 13760,
            "id": 626,
            "name": "trace_cap_capable",
            "run_cnt_delta": 105482,
            "run_time_ns_delta": 19253408,
            "type": "kprobe"
          },
          "627": {
            "avg_ns_per_run": 746.8235294117648,
            "bytes_jited": 8478,
            "bytes_xlated": 14176,
            "id": 627,
            "name": "trace_security_socket_create",
            "run_cnt_delta": 34,
            "run_time_ns_delta": 25392,
            "type": "kprobe"
          },
          "628": {
            "avg_ns_per_run": null,
            "bytes_jited": 9217,
            "bytes_xlated": 15344,
            "id": 628,
            "name": "trace_security_inode_symlink",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "629": {
            "avg_ns_per_run": null,
            "bytes_jited": 8301,
            "bytes_xlated": 13904,
            "id": 629,
            "name": "trace_proc_create",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "630": {
            "avg_ns_per_run": null,
            "bytes_jited": 9523,
            "bytes_xlated": 15840,
            "id": 630,
            "name": "trace_debugfs_create_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "631": {
            "avg_ns_per_run": null,
            "bytes_jited": 9235,
            "bytes_xlated": 15424,
            "id": 631,
            "name": "trace_debugfs_create_dir",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "632": {
            "avg_ns_per_run": null,
            "bytes_jited": 10837,
            "bytes_xlated": 16632,
            "id": 632,
            "name": "trace_security_socket_listen",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "633": {
            "avg_ns_per_run": 834.6060606060606,
            "bytes_jited": 10093,
            "bytes_xlated": 15472,
            "id": 633,
            "name": "trace_security_socket_connect",
            "run_cnt_delta": 33,
            "run_time_ns_delta": 27542,
            "type": "kprobe"
          },
          "634": {
            "avg_ns_per_run": 3276.521739130435,
            "bytes_jited": 11320,
            "bytes_xlated": 17368,
            "id": 634,
            "name": "trace_security_socket_accept",
            "run_cnt_delta": 23,
            "run_time_ns_delta": 75360,
            "type": "kprobe"
          },
          "635": {
            "avg_ns_per_run": 1687.0,
            "bytes_jited": 10606,
            "bytes_xlated": 16152,
            "id": 635,
            "name": "trace_security_socket_bind",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1687,
            "type": "kprobe"
          },
          "636": {
            "avg_ns_per_run": null,
            "bytes_jited": 11072,
            "bytes_xlated": 17024,
            "id": 636,
            "name": "trace_security_socket_setsockopt",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "637": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 637,
            "name": "send_bin",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "638": {
            "avg_ns_per_run": null,
            "bytes_jited": 949,
            "bytes_xlated": 1568,
            "id": 638,
            "name": "send_bin_tp",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "639": {
            "avg_ns_per_run": 116.36114803499224,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 639,
            "name": "trace_vfs_write",
            "run_cnt_delta": 143689,
            "run_time_ns_delta": 16719817,
            "type": "kprobe"
          },
          "640": {
            "avg_ns_per_run": 48.3179477544431,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 640,
            "name": "vfs_write_magic_enter",
            "run_cnt_delta": 143706,
            "run_time_ns_delta": 6943579,
            "type": "kprobe"
          },
          "641": {
            "avg_ns_per_run": 34.14554385867259,
            "bytes_jited": 19139,
            "bytes_xlated": 31808,
            "id": 641,
            "name": "trace_ret_vfs_write",
            "run_cnt_delta": 143723,
            "run_time_ns_delta": 4907500,
            "type": "kprobe"
          },
          "642": {
            "avg_ns_per_run": 43.4930267175838,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 642,
            "name": "vfs_write_magic_return",
            "run_cnt_delta": 143763,
            "run_time_ns_delta": 6252688,
            "type": "kprobe"
          },
          "643": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 643,
            "name": "trace_ret_vfs_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "644": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 644,
            "name": "trace_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "645": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 645,
            "name": "vfs_writev_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "646": {
            "avg_ns_per_run": null,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 646,
            "name": "trace_ret_vfs_writev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "647": {
            "avg_ns_per_run": null,
            "bytes_jited": 24540,
            "bytes_xlated": 37648,
            "id": 647,
            "name": "vfs_writev_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "648": {
            "avg_ns_per_run": null,
            "bytes_jited": 29845,
            "bytes_xlated": 51680,
            "id": 648,
            "name": "trace_ret_vfs_writev_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "649": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 649,
            "name": "trace_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "650": {
            "avg_ns_per_run": null,
            "bytes_jited": 279,
            "bytes_xlated": 432,
            "id": 650,
            "name": "kernel_write_magic_enter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "651": {
            "avg_ns_per_run": null,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 651,
            "name": "trace_ret_kernel_write",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "652": {
            "avg_ns_per_run": null,
            "bytes_jited": 23804,
            "bytes_xlated": 36792,
            "id": 652,
            "name": "kernel_write_magic_return",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "653": {
            "avg_ns_per_run": null,
            "bytes_jited": 29921,
            "bytes_xlated": 51704,
            "id": 653,
            "name": "trace_ret_kernel_write_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "654": {
            "avg_ns_per_run": 118.89528740169435,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 654,
            "name": "trace_vfs_read",
            "run_cnt_delta": 131732,
            "run_time_ns_delta": 15662314,
            "type": "kprobe"
          },
          "655": {
            "avg_ns_per_run": 40.00051617212822,
            "bytes_jited": 19142,
            "bytes_xlated": 31808,
            "id": 655,
            "name": "trace_ret_vfs_read",
            "run_cnt_delta": 131739,
            "run_time_ns_delta": 5269628,
            "type": "kprobe"
          },
          "656": {
            "avg_ns_per_run": null,
            "bytes_jited": 17164,
            "bytes_xlated": 29848,
            "id": 656,
            "name": "trace_ret_vfs_read_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "657": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 657,
            "name": "trace_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "658": {
            "avg_ns_per_run": null,
            "bytes_jited": 19138,
            "bytes_xlated": 31800,
            "id": 658,
            "name": "trace_ret_vfs_readv",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "659": {
            "avg_ns_per_run": null,
            "bytes_jited": 17892,
            "bytes_xlated": 30816,
            "id": 659,
            "name": "trace_ret_vfs_readv_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "660": {
            "avg_ns_per_run": 173.9739413680782,
            "bytes_jited": 20742,
            "bytes_xlated": 32864,
            "id": 660,
            "name": "trace_mmap_alert",
            "run_cnt_delta": 1535,
            "run_time_ns_delta": 267050,
            "type": "kprobe"
          },
          "661": {
            "avg_ns_per_run": 156.9681668496158,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 661,
            "name": "trace_do_mmap",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 142998,
            "type": "kprobe"
          },
          "662": {
            "avg_ns_per_run": 44.246981339187705,
            "bytes_jited": 19582,
            "bytes_xlated": 31944,
            "id": 662,
            "name": "trace_ret_do_mmap",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 40309,
            "type": "kprobe"
          },
          "663": {
            "avg_ns_per_run": 644.5082327113063,
            "bytes_jited": 36984,
            "bytes_xlated": 60888,
            "id": 663,
            "name": "trace_security_mmap_file",
            "run_cnt_delta": 911,
            "run_time_ns_delta": 587147,
            "type": "kprobe"
          },
          "664": {
            "avg_ns_per_run": 966.7021276595744,
            "bytes_jited": 34612,
            "bytes_xlated": 59616,
            "id": 664,
            "name": "trace_security_file_mprotect",
            "run_cnt_delta": 188,
            "run_time_ns_delta": 181740,
            "type": "kprobe"
          },
          "665": {
            "avg_ns_per_run": null,
            "bytes_jited": 622,
            "bytes_xlated": 1000,
            "id": 665,
            "name": "syscall__init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "666": {
            "avg_ns_per_run": 326.4642869024252,
            "bytes_jited": 15620,
            "bytes_xlated": 26984,
            "id": 666,
            "name": "trace_security_bpf",
            "run_cnt_delta": 30059,
            "run_time_ns_delta": 9813190,
            "type": "kprobe"
          },
          "667": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 667,
            "name": "trace_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "668": {
            "avg_ns_per_run": null,
            "bytes_jited": 8826,
            "bytes_xlated": 14712,
            "id": 668,
            "name": "trace_ret_register_kprobe",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "669": {
            "avg_ns_per_run": 290.2481334392375,
            "bytes_jited": 8362,
            "bytes_xlated": 13992,
            "id": 669,
            "name": "trace_security_bpf_map",
            "run_cnt_delta": 6295,
            "run_time_ns_delta": 1827112,
            "type": "kprobe"
          },
          "670": {
            "avg_ns_per_run": 1139.6903846153846,
            "bytes_jited": 9601,
            "bytes_xlated": 15520,
            "id": 670,
            "name": "trace_security_bpf_prog",
            "run_cnt_delta": 520,
            "run_time_ns_delta": 592639,
            "type": "kprobe"
          },
          "671": {
            "avg_ns_per_run": null,
            "bytes_jited": 6376,
            "bytes_xlated": 10616,
            "id": 671,
            "name": "trace_bpf_check",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "672": {
            "avg_ns_per_run": null,
            "bytes_jited": 6612,
            "bytes_xlated": 11096,
            "id": 672,
            "name": "trace_check_map_func_compatibility",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "673": {
            "avg_ns_per_run": null,
            "bytes_jited": 6618,
            "bytes_xlated": 11104,
            "id": 673,
            "name": "trace_check_helper_call",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "674": {
            "avg_ns_per_run": null,
            "bytes_jited": 18650,
            "bytes_xlated": 30720,
            "id": 674,
            "name": "trace_security_kernel_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "675": {
            "avg_ns_per_run": null,
            "bytes_jited": 17285,
            "bytes_xlated": 30536,
            "id": 675,
            "name": "trace_security_kernel_post_read_file",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "676": {
            "avg_ns_per_run": null,
            "bytes_jited": 9251,
            "bytes_xlated": 15432,
            "id": 676,
            "name": "trace_security_inode_mknod",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "677": {
            "avg_ns_per_run": null,
            "bytes_jited": 8685,
            "bytes_xlated": 14440,
            "id": 677,
            "name": "trace_device_add",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "678": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 678,
            "name": "trace___register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "679": {
            "avg_ns_per_run": null,
            "bytes_jited": 8828,
            "bytes_xlated": 14704,
            "id": 679,
            "name": "trace_ret__register_chrdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "680": {
            "avg_ns_per_run": null,
            "bytes_jited": 19884,
            "bytes_xlated": 32720,
            "id": 680,
            "name": "tracepoint__module__module_load",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "681": {
            "avg_ns_per_run": null,
            "bytes_jited": 9004,
            "bytes_xlated": 15024,
            "id": 681,
            "name": "tracepoint__module__module_free",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "682": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 682,
            "name": "trace_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "683": {
            "avg_ns_per_run": null,
            "bytes_jited": 14587,
            "bytes_xlated": 24016,
            "id": 683,
            "name": "trace_ret_do_init_module",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "684": {
            "avg_ns_per_run": 1943.5,
            "bytes_jited": 18493,
            "bytes_xlated": 30424,
            "id": 684,
            "name": "trace_load_elf_phdrs",
            "run_cnt_delta": 14,
            "run_time_ns_delta": 27209,
            "type": "kprobe"
          },
          "685": {
            "avg_ns_per_run": 44.973798811008116,
            "bytes_jited": 8719,
            "bytes_xlated": 14592,
            "id": 685,
            "name": "trace_security_file_permission",
            "run_cnt_delta": 276705,
            "run_time_ns_delta": 12444475,
            "type": "kprobe"
          },
          "686": {
            "avg_ns_per_run": 810.5637583892617,
            "bytes_jited": 8512,
            "bytes_xlated": 14208,
            "id": 686,
            "name": "tracepoint__task__task_rename",
            "run_cnt_delta": 1043,
            "run_time_ns_delta": 845418,
            "type": "raw_tracepoint"
          },
          "687": {
            "avg_ns_per_run": null,
            "bytes_jited": 9837,
            "bytes_xlated": 16448,
            "id": 687,
            "name": "trace_security_inode_rename",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "688": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 688,
            "name": "trace_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "689": {
            "avg_ns_per_run": null,
            "bytes_jited": 8431,
            "bytes_xlated": 14104,
            "id": 689,
            "name": "trace_ret_kallsyms_lookup_name",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "690": {
            "avg_ns_per_run": 693.1412037037037,
            "bytes_jited": 10070,
            "bytes_xlated": 16296,
            "id": 690,
            "name": "trace_do_sigaction",
            "run_cnt_delta": 2592,
            "run_time_ns_delta": 1796622,
            "type": "kprobe"
          },
          "691": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 691,
            "name": "trace_vfs_utimes",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "692": {
            "avg_ns_per_run": null,
            "bytes_jited": 18577,
            "bytes_xlated": 30600,
            "id": 692,
            "name": "trace_utimes_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "693": {
            "avg_ns_per_run": null,
            "bytes_jited": 9550,
            "bytes_xlated": 15896,
            "id": 693,
            "name": "trace_do_truncate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "694": {
            "avg_ns_per_run": 389.8672552481852,
            "bytes_jited": 17005,
            "bytes_xlated": 27568,
            "id": 694,
            "name": "trace_fd_install",
            "run_cnt_delta": 25485,
            "run_time_ns_delta": 9935767,
            "type": "kprobe"
          },
          "695": {
            "avg_ns_per_run": 1128.443045387994,
            "bytes_jited": 16933,
            "bytes_xlated": 27416,
            "id": 695,
            "name": "trace_filp_close",
            "run_cnt_delta": 3415,
            "run_time_ns_delta": 3853633,
            "type": "kprobe"
          },
          "696": {
            "avg_ns_per_run": 223.31944444444446,
            "bytes_jited": 469,
            "bytes_xlated": 784,
            "id": 696,
            "name": "trace_file_update_time",
            "run_cnt_delta": 288,
            "run_time_ns_delta": 64316,
            "type": "kprobe"
          },
          "697": {
            "avg_ns_per_run": 37.05902777777778,
            "bytes_jited": 20045,
            "bytes_xlated": 31224,
            "id": 697,
            "name": "trace_ret_file_update_time",
            "run_cnt_delta": 288,
            "run_time_ns_delta": 10673,
            "type": "kprobe"
          },
          "698": {
            "avg_ns_per_run": null,
            "bytes_jited": 483,
            "bytes_xlated": 800,
            "id": 698,
            "name": "trace_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "699": {
            "avg_ns_per_run": null,
            "bytes_jited": 20180,
            "bytes_xlated": 31400,
            "id": 699,
            "name": "trace_ret_file_modified",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "700": {
            "avg_ns_per_run": null,
            "bytes_jited": 152,
            "bytes_xlated": 232,
            "id": 700,
            "name": "trace_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "701": {
            "avg_ns_per_run": null,
            "bytes_jited": 18061,
            "bytes_xlated": 30032,
            "id": 701,
            "name": "trace_ret_inotify_find_inode",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "702": {
            "avg_ns_per_run": null,
            "bytes_jited": 12887,
            "bytes_xlated": 20216,
            "id": 702,
            "name": "process_execute_failed_tail",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "703": {
            "avg_ns_per_run": 149.71428571428572,
            "bytes_jited": 16503,
            "bytes_xlated": 28960,
            "id": 703,
            "name": "trace_exec_binprm",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 1048,
            "type": "kprobe"
          },
          "704": {
            "avg_ns_per_run": 4435.571428571428,
            "bytes_jited": 16714,
            "bytes_xlated": 29144,
            "id": 704,
            "name": "trace_security_bprm_creds_for_exec",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 31049,
            "type": "kprobe"
          },
          "705": {
            "avg_ns_per_run": 4690.714285714285,
            "bytes_jited": 24495,
            "bytes_xlated": 38400,
            "id": 705,
            "name": "trace_execute_finished",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 32835,
            "type": "kprobe"
          },
          "706": {
            "avg_ns_per_run": null,
            "bytes_jited": 18408,
            "bytes_xlated": 30272,
            "id": 706,
            "name": "trace_security_path_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "707": {
            "avg_ns_per_run": 3440.714285714286,
            "bytes_jited": 18267,
            "bytes_xlated": 30048,
            "id": 707,
            "name": "trace_set_fs_pwd",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 24085,
            "type": "kprobe"
          },
          "708": {
            "avg_ns_per_run": 271.6712488586791,
            "bytes_jited": 8645,
            "bytes_xlated": 14424,
            "id": 708,
            "name": "trace_security_task_setrlimit",
            "run_cnt_delta": 19714,
            "run_time_ns_delta": 5355727,
            "type": "kprobe"
          },
          "709": {
            "avg_ns_per_run": null,
            "bytes_jited": 8670,
            "bytes_xlated": 14480,
            "id": 709,
            "name": "trace_security_settime64",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "710": {
            "avg_ns_per_run": null,
            "bytes_jited": 17596,
            "bytes_xlated": 29272,
            "id": 710,
            "name": "trace_chmod_common",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "711": {
            "avg_ns_per_run": 350.16265250029875,
            "bytes_jited": 47182,
            "bytes_xlated": 76688,
            "id": 711,
            "name": "trace_security_task_prctl",
            "run_cnt_delta": 92049,
            "run_time_ns_delta": 32232122,
            "type": "kprobe"
          },
          "712": {
            "avg_ns_per_run": null,
            "bytes_jited": 14930,
            "bytes_xlated": 24112,
            "id": 712,
            "name": "syscall_checker",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "713": {
            "avg_ns_per_run": null,
            "bytes_jited": 9521,
            "bytes_xlated": 15856,
            "id": 713,
            "name": "trace_security_sb_umount",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "714": {
            "avg_ns_per_run": 192.4561403508772,
            "bytes_jited": 331,
            "bytes_xlated": 528,
            "id": 714,
            "name": "trace_sock_alloc_file",
            "run_cnt_delta": 57,
            "run_time_ns_delta": 10970,
            "type": "kprobe"
          },
          "715": {
            "avg_ns_per_run": 1062.2631578947369,
            "bytes_jited": 8648,
            "bytes_xlated": 13456,
            "id": 715,
            "name": "trace_ret_sock_alloc_file",
            "run_cnt_delta": 57,
            "run_time_ns_delta": 60549,
            "type": "kprobe"
          },
          "716": {
            "avg_ns_per_run": null,
            "bytes_jited": 344,
            "bytes_xlated": 592,
            "id": 716,
            "name": "trace_security_sk_clone",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "717": {
            "avg_ns_per_run": 262.6,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 717,
            "name": "trace_security_socket_recvmsg",
            "run_cnt_delta": 5,
            "run_time_ns_delta": 1313,
            "type": "kprobe"
          },
          "718": {
            "avg_ns_per_run": 389.0,
            "bytes_jited": 8895,
            "bytes_xlated": 13696,
            "id": 718,
            "name": "trace_security_socket_sendmsg",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 389,
            "type": "kprobe"
          },
          "719": {
            "avg_ns_per_run": 211.25,
            "bytes_jited": 5668,
            "bytes_xlated": 8808,
            "id": 719,
            "name": "cgroup_bpf_run_filter_skb",
            "run_cnt_delta": 4,
            "run_time_ns_delta": 845,
            "type": "kprobe"
          },
          "721": {
            "avg_ns_per_run": null,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 721,
            "name": "cgroup_skb_ingress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "cgroup_skb"
          },
          "722": {
            "avg_ns_per_run": null,
            "bytes_jited": 19660,
            "bytes_xlated": 31088,
            "id": 722,
            "name": "cgroup_skb_egress",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "cgroup_skb"
          },
          "723": {
            "avg_ns_per_run": null,
            "bytes_jited": 928,
            "bytes_xlated": 1584,
            "id": 723,
            "name": "cgroup_mkdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "724": {
            "avg_ns_per_run": null,
            "bytes_jited": 910,
            "bytes_xlated": 1544,
            "id": 724,
            "name": "cgroup_rmdir_signal",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "725": {
            "avg_ns_per_run": 169.14285714285714,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 725,
            "name": "empty_kprobe",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 1184,
            "type": "kprobe"
          },
          "726": {
            "avg_ns_per_run": 1268.2857142857142,
            "bytes_jited": 58693,
            "bytes_xlated": 96032,
            "id": 726,
            "name": "tracepoint__exec_test",
            "run_cnt_delta": 7,
            "run_time_ns_delta": 8878,
            "type": "raw_tracepoint"
          },
          "727": {
            "avg_ns_per_run": 284.4238989454689,
            "bytes_jited": 7328,
            "bytes_xlated": 13360,
            "id": 727,
            "name": "lsm_file_open_test",
            "run_cnt_delta": 17733,
            "run_time_ns_delta": 5043689,
            "type": "lsm"
          },
          "728": {
            "avg_ns_per_run": null,
            "bytes_jited": 5384,
            "bytes_xlated": 9160,
            "id": 728,
            "name": "uprobe__features_fallback_arena",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 2.156022060000055,
            "ops_per_sec": 2886.797920796711,
            "ops_total": 6224.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [30758]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [30758] get                 200      0.35      0.01      0.15       570.95        1216.97\nstress-ng: info:  [30758] skipped: 0\nstress-ng: info:  [30758] passed: 1: get (1)\nstress-ng: info:  [30758] failed: 0\nstress-ng: info:  [30758] metrics untrustworthy: 0\nstress-ng: info:  [30758] successful run completed in 0.35 secs\nstress-ng: info:  [30760] setting to a 5 secs run per stressor\nstress-ng: info:  [30760] dispatching hogs: 1 prctl\nstress-ng: info:  [30760] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [30760] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [30760]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [30760] prctl              1000      1.33      1.00      0.29       752.90         774.35\nstress-ng: info:  [30760] skipped: 0\nstress-ng: info:  [30760] passed: 1: prctl (1)\nstress-ng: info:  [30760] failed: 0\nstress-ng: info:  [30760] metrics untrustworthy: 0\nstress-ng: info:  [30760] successful run completed in 1.33 secs\nstress-ng: info:  [31762] setting to a 5 secs run per stressor\nstress-ng: info:  [31762] dispatching hogs: 1 set\nstress-ng: info:  [31762] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31762] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31762]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31762] set                1000      0.20      0.00      0.20      5114.02        5114.59\nstress-ng: info:  [31762] skipped: 0\nstress-ng: info:  [31762] passed: 1: set (1)\nstress-ng: info:  [31762] failed: 0\nstress-ng: info:  [31762] metrics untrustworthy: 0\nstress-ng: info:  [31762] successful run completed in 0.20 secs\nstress-ng: info:  [31764] setting to a 5 secs run per stressor\nstress-ng: info:  [31764] dispatching hogs: 1 timerfd\nstress-ng: info:  [31764] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31764] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31764]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31764] timerfd            1024      0.02      0.00      0.02     55137.20       54208.58\nstress-ng: info:  [31764] skipped: 0\nstress-ng: info:  [31764] passed: 1: timerfd (1)\nstress-ng: info:  [31764] failed: 0\nstress-ng: info:  [31764] metrics untrustworthy: 0\nstress-ng: info:  [31764] successful run completed in 0.02 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 570
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 571
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 572
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 573
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 574
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 575
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 576
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 577
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 578
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 579
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 580
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 581
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 582
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 583
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 584
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 585
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 586
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 587
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 588
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 589
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 590
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 591
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 592
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 593
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 594
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 595
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 596
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 597
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 598
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 599
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 600
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 601
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 602
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 603
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 604
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 605
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 606
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 607
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 608
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 609
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 610
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 611
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 612
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 613
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 614
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 615
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 616
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 617
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 618
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 619
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 620
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 621
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 622
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 623
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 624
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 625
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 626
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 627
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 628
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 629
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 630
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 631
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 632
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 633
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 634
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 635
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 636
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 637
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 638
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 639
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 640
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 641
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 642
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 643
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 644
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 645
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 646
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 647
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 648
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 649
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 650
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 651
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 652
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 653
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 654
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 655
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 656
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 657
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 658
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 659
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 660
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 661
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 662
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 663
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 664
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 665
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 666
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 667
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 668
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 669
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 670
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 671
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 672
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 673
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 674
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 675
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 676
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 677
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 678
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 679
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 680
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 681
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 682
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 683
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 684
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 685
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 686
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 687
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 688
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 689
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 690
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 691
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 692
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 693
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 694
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 695
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 696
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 697
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 698
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 699
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 700
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 701
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 702
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 703
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 704
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 705
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 706
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 707
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 708
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 709
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 710
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 711
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 712
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 713
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 714
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 715
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 716
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 717
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 718
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 719
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 721
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 722
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 723
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 724
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 725
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 726
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 727
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 728
          }
        ],
        "program_counts": {
          "applied": 0,
          "not_applied": 158,
          "requested": 158
        }
      },
      "runner": "tracee",
      "selected_workload": "stress_ng_os",
      "status": "ok"
    },
    {
      "app": "bpftrace/capable",
      "baseline": {
        "bpf": {
          "734": {
            "avg_ns_per_run": 246.29166714339652,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 87401,
            "run_time_ns_delta": 21526138,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.8046654319999789,
            "ops_per_sec": 3325.2700991504726,
            "ops_total": 6001.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [31454]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31454] get                 200      0.37      0.01      0.15       534.97        1320.05\nstress-ng: info:  [31454] skipped: 0\nstress-ng: info:  [31454] passed: 1: get (1)\nstress-ng: info:  [31454] failed: 0\nstress-ng: info:  [31454] metrics untrustworthy: 0\nstress-ng: info:  [31454] successful run completed in 0.38 secs\nstress-ng: info:  [31456] setting to a 1 secs run per stressor\nstress-ng: info:  [31456] dispatching hogs: 1 prctl\nstress-ng: info:  [31456] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31456] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31456]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31456] prctl               777      1.00      0.77      0.23       776.29         783.16\nstress-ng: info:  [31456] skipped: 0\nstress-ng: info:  [31456] passed: 1: prctl (1)\nstress-ng: info:  [31456] failed: 0\nstress-ng: info:  [31456] metrics untrustworthy: 0\nstress-ng: info:  [31456] successful run completed in 1.00 secs\nstress-ng: info:  [32235] setting to a 1 secs run per stressor\nstress-ng: info:  [32235] dispatching hogs: 1 set\nstress-ng: info:  [32235] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [32235] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [32235]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32235] set                1000      0.19      0.01      0.18      5347.59        5336.01\nstress-ng: info:  [32235] skipped: 0\nstress-ng: info:  [32235] passed: 1: set (1)\nstress-ng: info:  [32235] failed: 0\nstress-ng: info:  [32235] metrics untrustworthy: 0\nstress-ng: info:  [32235] successful run completed in 0.19 secs\nstress-ng: info:  [32237] setting to a 1 secs run per stressor\nstress-ng: info:  [32237] dispatching hogs: 1 timerfd\nstress-ng: info:  [32237] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [32237] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [32237]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32237] timerfd            1024      0.02      0.00      0.02     55208.78       54059.76\nstress-ng: info:  [32237] skipped: 0\nstress-ng: info:  [32237] passed: 1: timerfd (1)\nstress-ng: info:  [32237] failed: 0\nstress-ng: info:  [32237] metrics untrustworthy: 0\nstress-ng: info:  [32237] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "734": {
            "avg_ns_per_run": 283.09601190405897,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 734,
            "name": "cap_capable",
            "run_cnt_delta": 84677,
            "run_time_ns_delta": 23971721,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.8488683739999487,
            "ops_per_sec": 3226.83868895048,
            "ops_total": 5966.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [32518]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32518] get                 200      0.34      0.02      0.15       586.73        1238.99\nstress-ng: info:  [32518] skipped: 0\nstress-ng: info:  [32518] passed: 1: get (1)\nstress-ng: info:  [32518] failed: 0\nstress-ng: info:  [32518] metrics untrustworthy: 0\nstress-ng: info:  [32518] successful run completed in 0.34 secs\nstress-ng: info:  [32520] setting to a 1 secs run per stressor\nstress-ng: info:  [32520] dispatching hogs: 1 prctl\nstress-ng: info:  [32520] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [32520] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [32520]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [32520] prctl               742      1.00      0.76      0.21       741.85         767.60\nstress-ng: info:  [32520] skipped: 0\nstress-ng: info:  [32520] passed: 1: prctl (1)\nstress-ng: info:  [32520] failed: 0\nstress-ng: info:  [32520] metrics untrustworthy: 0\nstress-ng: info:  [32520] successful run completed in 1.00 secs\nstress-ng: info:  [808] setting to a 1 secs run per stressor\nstress-ng: info:  [808] dispatching hogs: 1 set\nstress-ng: info:  [808] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [808] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [808]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [808] set                1000      0.20      0.00      0.20      5099.19        5091.70\nstress-ng: info:  [808] skipped: 0\nstress-ng: info:  [808] passed: 1: set (1)\nstress-ng: info:  [808] failed: 0\nstress-ng: info:  [808] metrics untrustworthy: 0\nstress-ng: info:  [808] successful run completed in 0.20 secs\nstress-ng: info:  [810] setting to a 1 secs run per stressor\nstress-ng: info:  [810] dispatching hogs: 1 timerfd\nstress-ng: info:  [810] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [810] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [810]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [810] timerfd            1024      0.02      0.01      0.02     42472.70       41382.10\nstress-ng: info:  [810] skipped: 0\nstress-ng: info:  [810] passed: 1: timerfd (1)\nstress-ng: info:  [810] failed: 0\nstress-ng: info:  [810] metrics untrustworthy: 0\nstress-ng: info:  [810] successful run completed in 0.03 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 734
          }
        ],
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
          "740": {
            "avg_ns_per_run": 653.7496375936216,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 49668,
            "run_time_ns_delta": 32470437,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 1646.4040574809806,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 49686,
            "run_time_ns_delta": 81803232,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 14.347554693999996,
            "ops_per_sec": 4579.038128878801,
            "ops_total": 65698.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_us\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 43.521736,\n        \"20\" : 6.054509,\n        \"50\" : 0.402414,\n        \"100\" : 0.243888,\n        \"250\" : 24.626547,\n        \"500\" : 23.291263,\n        \"750\" : 1.213341,\n        \"1000\" : 0.152430\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.189013,\n        \"4\" : 0.164624,\n        \"10\" : 0.060972,\n        \"20\" : 0.073166,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.010000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "740": {
            "avg_ns_per_run": 701.4787145407657,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 740,
            "name": "block_io_start",
            "run_cnt_delta": 50410,
            "run_time_ns_delta": 35361542,
            "type": "tracepoint"
          },
          "741": {
            "avg_ns_per_run": 1666.4350257834192,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 741,
            "name": "block_io_done",
            "run_cnt_delta": 50420,
            "run_time_ns_delta": 84021654,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 10.833234392999998,
            "ops_per_sec": 6187.256507928122,
            "ops_total": 67028.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_us\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 42.565667,\n        \"20\" : 6.809071,\n        \"50\" : 0.526536,\n        \"100\" : 0.029917,\n        \"250\" : 24.813020,\n        \"500\" : 23.646263,\n        \"750\" : 1.011189,\n        \"1000\" : 0.263268\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.239335,\n        \"4\" : 0.029917,\n        \"10\" : 0.017950,\n        \"20\" : 0.023933,\n        \"50\" : 0.023933,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 740
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 741
          }
        ],
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
          "747": {
            "avg_ns_per_run": 1444.5,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 10,
            "run_time_ns_delta": 14445,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 51.689582040746245,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 512538,
            "run_time_ns_delta": 26492875,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 9.415301890999956,
            "ops_per_sec": 876.658029190754,
            "ops_total": 8254.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [1548]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1548] open                100      0.67      0.01      0.00       148.22       13980.15\nstress-ng: info:  [1548] skipped: 0\nstress-ng: info:  [1548] passed: 1: open (1)\nstress-ng: info:  [1548] failed: 0\nstress-ng: info:  [1548] metrics untrustworthy: 0\nstress-ng: info:  [1548] successful run completed in 0.68 secs\nstress-ng: info:  [1550] setting to a 1 secs run per stressor\nstress-ng: info:  [1550] dispatching hogs: 1 rename\nstress-ng: info:  [1550] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1550] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1550]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1550] rename              100      0.67      0.01      0.00       149.08       11106.18\nstress-ng: info:  [1550] skipped: 0\nstress-ng: info:  [1550] passed: 1: rename (1)\nstress-ng: info:  [1550] failed: 0\nstress-ng: info:  [1550] metrics untrustworthy: 0\nstress-ng: info:  [1550] successful run completed in 0.67 secs\nstress-ng: info:  [1552] setting to a 1 secs run per stressor\nstress-ng: info:  [1552] dispatching hogs: 1 touch\nstress-ng: info:  [1552] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1552] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1552]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1552] touch               200      0.02      0.02      0.00      8259.19       12926.58\nstress-ng: info:  [1552] skipped: 0\nstress-ng: info:  [1552] passed: 1: touch (1)\nstress-ng: info:  [1552] failed: 0\nstress-ng: info:  [1552] metrics untrustworthy: 0\nstress-ng: info:  [1552] successful run completed in 0.03 secs\nstress-ng: info:  [1558] setting to a 1 secs run per stressor\nstress-ng: info:  [1558] dispatching hogs: 1 utime\nstress-ng: info:  [1558] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1558] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1558]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1558] utime               200      0.03      0.00      0.03      7477.41        7336.76\nstress-ng: info:  [1558] skipped: 0\nstress-ng: info:  [1558] passed: 1: utime (1)\nstress-ng: info:  [1558] failed: 0\nstress-ng: info:  [1558] metrics untrustworthy: 0\nstress-ng: info:  [1558] successful run completed in 0.03 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "747": {
            "avg_ns_per_run": 1595.4666666666667,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 747,
            "name": "1",
            "run_cnt_delta": 15,
            "run_time_ns_delta": 23932,
            "type": "perf_event"
          },
          "748": {
            "avg_ns_per_run": 55.8353386626833,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 748,
            "name": "vfs_create",
            "run_cnt_delta": 500749,
            "run_time_ns_delta": 27959490,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 14.99657549899996,
            "ops_per_sec": 546.7914992023888,
            "ops_total": 8200.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [2697]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2697] open                100      0.22      0.00      0.01       462.60        6931.45\nstress-ng: info:  [2697] skipped: 0\nstress-ng: info:  [2697] passed: 1: open (1)\nstress-ng: info:  [2697] failed: 0\nstress-ng: info:  [2697] metrics untrustworthy: 0\nstress-ng: info:  [2697] successful run completed in 0.22 secs\nstress-ng: info:  [2699] setting to a 1 secs run per stressor\nstress-ng: info:  [2699] dispatching hogs: 1 rename\nstress-ng: info:  [2699] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2699] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2699]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2699] rename              100      0.56      0.00      0.01       178.44       11145.79\nstress-ng: info:  [2699] skipped: 0\nstress-ng: info:  [2699] passed: 1: rename (1)\nstress-ng: info:  [2699] failed: 0\nstress-ng: info:  [2699] metrics untrustworthy: 0\nstress-ng: info:  [2699] successful run completed in 0.56 secs\nstress-ng: info:  [2701] setting to a 1 secs run per stressor\nstress-ng: info:  [2701] dispatching hogs: 1 touch\nstress-ng: info:  [2701] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2701] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2701]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2701] touch               200      0.05      0.01      0.00      4253.28       11638.06\nstress-ng: info:  [2701] skipped: 0\nstress-ng: info:  [2701] passed: 1: touch (1)\nstress-ng: info:  [2701] failed: 0\nstress-ng: info:  [2701] metrics untrustworthy: 0\nstress-ng: info:  [2701] successful run completed in 0.05 secs\nstress-ng: info:  [2707] setting to a 1 secs run per stressor\nstress-ng: info:  [2707] dispatching hogs: 1 utime\nstress-ng: info:  [2707] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2707] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2707]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2707] utime               200      0.02      0.00      0.02     12915.49       12426.22\nstress-ng: info:  [2707] skipped: 0\nstress-ng: info:  [2707] passed: 1: utime (1)\nstress-ng: info:  [2707] failed: 0\nstress-ng: info:  [2707] metrics untrustworthy: 0\nstress-ng: info:  [2707] successful run completed in 0.02 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 747
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 748
          }
        ],
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
          "754": {
            "avg_ns_per_run": 161.8513327837318,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 50946,
            "run_time_ns_delta": 8245678,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 275.96478873239437,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 568,
            "run_time_ns_delta": 156748,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 170.241026241114,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 102549,
            "run_time_ns_delta": 17458047,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.548578544999941,
            "ops_per_sec": 4509.572609621206,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [2577]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2577] sem-sysv           1001      0.01      0.00      0.01     94973.61       70132.42\nstress-ng: info:  [2577] skipped: 0\nstress-ng: info:  [2577] passed: 1: sem-sysv (1)\nstress-ng: info:  [2577] failed: 0\nstress-ng: info:  [2577] metrics untrustworthy: 0\nstress-ng: info:  [2577] successful run completed in 0.01 secs\nstress-ng: info:  [2581] setting to a 1 secs run per stressor\nstress-ng: info:  [2581] dispatching hogs: 1 switch\nstress-ng: info:  [2581] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2581] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2581]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2581] switch             1000      0.01      0.00      0.01    191040.95       98561.01\nstress-ng: info:  [2581] skipped: 0\nstress-ng: info:  [2581] passed: 1: switch (1)\nstress-ng: info:  [2581] failed: 0\nstress-ng: info:  [2581] metrics untrustworthy: 0\nstress-ng: info:  [2581] successful run completed in 0.01 secs\nstress-ng: info:  [2584] setting to a 1 secs run per stressor\nstress-ng: info:  [2584] dispatching hogs: 1 vfork\nstress-ng: info:  [2584] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2584] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2584]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2584] vfork               200      0.01      0.01      0.01     18928.22       17232.47\nstress-ng: info:  [2584] skipped: 0\nstress-ng: info:  [2584] passed: 1: vfork (1)\nstress-ng: info:  [2584] failed: 0\nstress-ng: info:  [2584] metrics untrustworthy: 0\nstress-ng: info:  [2584] successful run completed in 0.01 secs\nstress-ng: info:  [2851] setting to a 1 secs run per stressor\nstress-ng: info:  [2851] dispatching hogs: 1 yield\nstress-ng: info:  [2851] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2851] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2851]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2851] yield              4992      1.00      0.02      0.00      4987.33      204029.92\nstress-ng: info:  [2851] skipped: 0\nstress-ng: info:  [2851] passed: 1: yield (1)\nstress-ng: info:  [2851] failed: 0\nstress-ng: info:  [2851] metrics untrustworthy: 0\nstress-ng: info:  [2851] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "754": {
            "avg_ns_per_run": 174.0483701587835,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 754,
            "name": "sched_wakeup",
            "run_cnt_delta": 47612,
            "run_time_ns_delta": 8286791,
            "type": "tracepoint"
          },
          "755": {
            "avg_ns_per_run": 291.3651877133106,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 755,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 586,
            "run_time_ns_delta": 170740,
            "type": "tracepoint"
          },
          "756": {
            "avg_ns_per_run": 179.78740247462522,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 756,
            "name": "sched_switch",
            "run_cnt_delta": 96257,
            "run_time_ns_delta": 17305796,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 2.5799123199999485,
            "ops_per_sec": 4454.8025570110185,
            "ops_total": 11493.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [3706]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3706] sem-sysv           1001      0.01      0.01      0.01    117224.10       77077.08\nstress-ng: info:  [3706] skipped: 0\nstress-ng: info:  [3706] passed: 1: sem-sysv (1)\nstress-ng: info:  [3706] failed: 0\nstress-ng: info:  [3706] metrics untrustworthy: 0\nstress-ng: info:  [3706] successful run completed in 0.01 secs\nstress-ng: info:  [3710] setting to a 1 secs run per stressor\nstress-ng: info:  [3710] dispatching hogs: 1 switch\nstress-ng: info:  [3710] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [3710] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3710]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3710] switch             1000      0.01      0.00      0.01    171609.34       93879.08\nstress-ng: info:  [3710] skipped: 0\nstress-ng: info:  [3710] passed: 1: switch (1)\nstress-ng: info:  [3710] failed: 0\nstress-ng: info:  [3710] metrics untrustworthy: 0\nstress-ng: info:  [3710] successful run completed in 0.01 secs\nstress-ng: info:  [3713] setting to a 1 secs run per stressor\nstress-ng: info:  [3713] dispatching hogs: 1 vfork\nstress-ng: info:  [3713] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [3713] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3713]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3713] vfork               200      0.01      0.01      0.00     19968.12       18372.22\nstress-ng: info:  [3713] skipped: 0\nstress-ng: info:  [3713] passed: 1: vfork (1)\nstress-ng: info:  [3713] failed: 0\nstress-ng: info:  [3713] metrics untrustworthy: 0\nstress-ng: info:  [3713] successful run completed in 0.01 secs\nstress-ng: info:  [3915] setting to a 1 secs run per stressor\nstress-ng: info:  [3915] dispatching hogs: 1 yield\nstress-ng: info:  [3915] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [3915] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3915]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3915] yield              4992      1.00      0.02      0.01      4988.04      174740.97\nstress-ng: info:  [3915] skipped: 0\nstress-ng: info:  [3915] passed: 1: yield (1)\nstress-ng: info:  [3915] failed: 0\nstress-ng: info:  [3915] metrics untrustworthy: 0\nstress-ng: info:  [3915] successful run completed in 1.00 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 754
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 755
          },
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 756
          }
        ],
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
          "763": {
            "avg_ns_per_run": 1503.125,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 12025,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2865610950000246,
            "ops_per_sec": 4042.559673390326,
            "ops_total": 5201.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [2920]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2920] sockdiag           1034      0.00      0.00      0.00   1123260.90      688415.45\nstress-ng: info:  [2920] skipped: 0\nstress-ng: info:  [2920] passed: 1: sockdiag (1)\nstress-ng: info:  [2920] failed: 0\nstress-ng: info:  [2920] metrics untrustworthy: 0\nstress-ng: info:  [2920] successful run completed in 0.00 secs\nstress-ng: info:  [2922] setting to a 1 secs run per stressor\nstress-ng: info:  [2922] dispatching hogs: 1 sockfd\nstress-ng: info:  [2922] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2922] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2922]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2922] sockfd              200      0.00      0.00      0.00     71642.39       42345.97\nstress-ng: info:  [2922] skipped: 0\nstress-ng: info:  [2922] passed: 1: sockfd (1)\nstress-ng: info:  [2922] failed: 0\nstress-ng: info:  [2922] metrics untrustworthy: 0\nstress-ng: info:  [2922] successful run completed in 0.00 secs\nstress-ng: info:  [2925] setting to a 1 secs run per stressor\nstress-ng: info:  [2925] dispatching hogs: 1 sockpair\nstress-ng: info:  [2925] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2925] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2925]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2925] sockpair            500      0.06      0.00      0.07      8289.24        6695.59\nstress-ng: info:  [2925] skipped: 0\nstress-ng: info:  [2925] passed: 1: sockpair (1)\nstress-ng: info:  [2925] failed: 0\nstress-ng: info:  [2925] metrics untrustworthy: 0\nstress-ng: info:  [2925] successful run completed in 0.06 secs\nstress-ng: info:  [2929] setting to a 1 secs run per stressor\nstress-ng: info:  [2929] dispatching hogs: 1 udp-flood\nstress-ng: info:  [2929] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2929] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2929]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2929] udp-flood          1000      0.02      0.00      0.02     63113.05       61158.34\nstress-ng: info:  [2929] skipped: 0\nstress-ng: info:  [2929] passed: 1: udp-flood (1)\nstress-ng: info:  [2929] failed: 0\nstress-ng: info:  [2929] metrics untrustworthy: 0\nstress-ng: info:  [2929] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "763": {
            "avg_ns_per_run": 1755.625,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 763,
            "name": "tcp_set_state",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 14045,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 0.8703340129999333,
            "ops_per_sec": 5941.3971219810255,
            "ops_total": 5171.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [3996]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3996] sockdiag           1034      0.00      0.00      0.00   1069257.97      709190.67\nstress-ng: info:  [3996] skipped: 0\nstress-ng: info:  [3996] passed: 1: sockdiag (1)\nstress-ng: info:  [3996] failed: 0\nstress-ng: info:  [3996] metrics untrustworthy: 0\nstress-ng: info:  [3996] successful run completed in 0.00 secs\nstress-ng: info:  [3998] setting to a 1 secs run per stressor\nstress-ng: info:  [3998] dispatching hogs: 1 sockfd\nstress-ng: info:  [3998] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [3998] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [3998]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [3998] sockfd              200      0.00      0.01      0.00     49059.06       29647.20\nstress-ng: info:  [3998] skipped: 0\nstress-ng: info:  [3998] passed: 1: sockfd (1)\nstress-ng: info:  [3998] failed: 0\nstress-ng: info:  [3998] metrics untrustworthy: 0\nstress-ng: info:  [3998] successful run completed in 0.01 secs\nstress-ng: info:  [4001] setting to a 1 secs run per stressor\nstress-ng: info:  [4001] dispatching hogs: 1 sockpair\nstress-ng: info:  [4001] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4001] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4001]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4001] sockpair            500      0.06      0.00      0.08      7843.43        6323.91\nstress-ng: info:  [4001] skipped: 0\nstress-ng: info:  [4001] passed: 1: sockpair (1)\nstress-ng: info:  [4001] failed: 0\nstress-ng: info:  [4001] metrics untrustworthy: 0\nstress-ng: info:  [4001] successful run completed in 0.08 secs\nstress-ng: info:  [4005] setting to a 1 secs run per stressor\nstress-ng: info:  [4005] dispatching hogs: 1 udp-flood\nstress-ng: info:  [4005] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4005] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4005]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4005] udp-flood          1000      0.01      0.00      0.01    108945.79      104942.81\nstress-ng: info:  [4005] skipped: 0\nstress-ng: info:  [4005] passed: 1: udp-flood (1)\nstress-ng: info:  [4005] failed: 0\nstress-ng: info:  [4005] metrics untrustworthy: 0\nstress-ng: info:  [4005] successful run completed in 0.01 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 763
          }
        ],
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
          "769": {
            "avg_ns_per_run": null,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.2450294330000133,
            "ops_per_sec": 4229.618883234822,
            "ops_total": 5266.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [2966]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2966] sockdiag           1034      0.00      0.00      0.00   1686857.38     1073727.93\nstress-ng: info:  [2966] skipped: 0\nstress-ng: info:  [2966] passed: 1: sockdiag (1)\nstress-ng: info:  [2966] failed: 0\nstress-ng: info:  [2966] metrics untrustworthy: 0\nstress-ng: info:  [2966] successful run completed in 0.00 secs\nstress-ng: info:  [2968] setting to a 5 secs run per stressor\nstress-ng: info:  [2968] dispatching hogs: 1 sockfd\nstress-ng: info:  [2968] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2968] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2968]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2968] sockfd              200      0.00      0.01      0.00     66555.13       37195.46\nstress-ng: info:  [2968] skipped: 0\nstress-ng: info:  [2968] passed: 1: sockfd (1)\nstress-ng: info:  [2968] failed: 0\nstress-ng: info:  [2968] metrics untrustworthy: 0\nstress-ng: info:  [2968] successful run completed in 0.01 secs\nstress-ng: info:  [2971] setting to a 5 secs run per stressor\nstress-ng: info:  [2971] dispatching hogs: 1 sockpair\nstress-ng: info:  [2971] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2971] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2971]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2971] sockpair            500      0.07      0.00      0.08      7644.74        6162.26\nstress-ng: info:  [2971] skipped: 0\nstress-ng: info:  [2971] passed: 1: sockpair (1)\nstress-ng: info:  [2971] failed: 0\nstress-ng: info:  [2971] metrics untrustworthy: 0\nstress-ng: info:  [2971] successful run completed in 0.07 secs\nstress-ng: info:  [2975] setting to a 5 secs run per stressor\nstress-ng: info:  [2975] dispatching hogs: 1 udp-flood\nstress-ng: info:  [2975] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [2975] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [2975]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [2975] udp-flood          1000      0.02      0.00      0.02     63085.52       61057.52\nstress-ng: info:  [2975] skipped: 0\nstress-ng: info:  [2975] passed: 1: udp-flood (1)\nstress-ng: info:  [2975] failed: 0\nstress-ng: info:  [2975] metrics untrustworthy: 0\nstress-ng: info:  [2975] successful run completed in 0.02 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "769": {
            "avg_ns_per_run": null,
            "bytes_jited": 968,
            "bytes_xlated": 1640,
            "id": 769,
            "name": "kprobe_tcp_retransmit_skb",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.3890467859999944,
            "ops_per_sec": 3919.9543563826523,
            "ops_total": 5445.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [4042]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4042] sockdiag           1034      0.00      0.00      0.00   1806293.35      915854.74\nstress-ng: info:  [4042] skipped: 0\nstress-ng: info:  [4042] passed: 1: sockdiag (1)\nstress-ng: info:  [4042] failed: 0\nstress-ng: info:  [4042] metrics untrustworthy: 0\nstress-ng: info:  [4042] successful run completed in 0.00 secs\nstress-ng: info:  [4044] setting to a 5 secs run per stressor\nstress-ng: info:  [4044] dispatching hogs: 1 sockfd\nstress-ng: info:  [4044] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4044] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4044]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4044] sockfd              200      0.00      0.01      0.00     62676.39       37327.36\nstress-ng: info:  [4044] skipped: 0\nstress-ng: info:  [4044] passed: 1: sockfd (1)\nstress-ng: info:  [4044] failed: 0\nstress-ng: info:  [4044] metrics untrustworthy: 0\nstress-ng: info:  [4044] successful run completed in 0.01 secs\nstress-ng: info:  [4047] setting to a 5 secs run per stressor\nstress-ng: info:  [4047] dispatching hogs: 1 sockpair\nstress-ng: info:  [4047] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4047] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4047]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4047] sockpair            500      0.06      0.00      0.07      8923.56        7143.98\nstress-ng: info:  [4047] skipped: 0\nstress-ng: info:  [4047] passed: 1: sockpair (1)\nstress-ng: info:  [4047] failed: 0\nstress-ng: info:  [4047] metrics untrustworthy: 0\nstress-ng: info:  [4047] successful run completed in 0.06 secs\nstress-ng: info:  [4051] setting to a 5 secs run per stressor\nstress-ng: info:  [4051] dispatching hogs: 1 udp-flood\nstress-ng: info:  [4051] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4051] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4051]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4051] udp-flood          1000      0.03      0.00      0.03     37935.19       37334.33\nstress-ng: info:  [4051] skipped: 0\nstress-ng: info:  [4051] passed: 1: udp-flood (1)\nstress-ng: info:  [4051] failed: 0\nstress-ng: info:  [4051] metrics untrustworthy: 0\nstress-ng: info:  [4051] successful run completed in 0.03 secs"
          }
        ]
      },
      "rejit_result": {
        "applied": false,
        "changed": false,
        "enabled_passes": [
          "prefetch"
        ],
        "error": "",
        "exit_code": 0,
        "noop_programs": [
          {
            "applied": false,
            "changed": false,
            "exit_code": 0,
            "passes": [
              {
                "pass_name": "prefetch",
                "sites_applied": 0,
                "sites_matched": 0,
                "sites_skipped": 0,
                "skip_reasons": {}
              }
            ],
            "prog_id": 769
          }
        ],
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
  "status": "ok",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 78,
    "per_program_geomean": 0.9787464124683913,
    "program_count": 132,
    "wins": 54
  },
  "workload_seconds": 1.0
}
```
