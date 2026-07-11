# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T02:55:29.144334+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T02:50:04.754095+00:00",
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
      "invoked_at": "2026-05-05T02:50:04.754010+00:00",
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
        "captured_at": "2026-05-05T02:50:04.753992+00:00",
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
      "captured_at": "2026-05-05T02:50:04.738048+00:00",
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
      "baseline_avg_ns_per_run": 335.91925927944624,
      "baseline_run_cnt_delta": 1100820,
      "baseline_run_time_ns_delta": 369786639,
      "post_rejit_avg_ns_per_run": 337.1058198233413,
      "post_rejit_run_cnt_delta": 1048915,
      "post_rejit_run_time_ns_delta": 353595351,
      "program": "cap_capable",
      "program_id": 6,
      "ratio": 1.0035322789959713,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 795.5,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 1591,
      "post_rejit_avg_ns_per_run": 1069.0,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 2138,
      "program": "syscall__execve",
      "program_id": 9,
      "ratio": 1.343808925204274,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/execsnoop",
      "baseline_avg_ns_per_run": 168.0,
      "baseline_run_cnt_delta": 2,
      "baseline_run_time_ns_delta": 336,
      "post_rejit_avg_ns_per_run": 193.5,
      "post_rejit_run_cnt_delta": 2,
      "post_rejit_run_time_ns_delta": 387,
      "program": "do_ret_sys_execve",
      "program_id": 10,
      "ratio": 1.1517857142857142,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "stress_ng_process"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 212.1921271517959,
      "baseline_run_cnt_delta": 1644208,
      "baseline_run_time_ns_delta": 348887993,
      "post_rejit_avg_ns_per_run": 208.2073184336767,
      "post_rejit_run_cnt_delta": 1694133,
      "post_rejit_run_time_ns_delta": 352730889,
      "program": "trace_pid_start_tp",
      "program_id": 18,
      "ratio": 0.9812207513464033,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 203.60542276024225,
      "baseline_run_cnt_delta": 1644218,
      "baseline_run_time_ns_delta": 334771701,
      "post_rejit_avg_ns_per_run": 197.89288684603366,
      "post_rejit_run_cnt_delta": 1694143,
      "post_rejit_run_time_ns_delta": 335258849,
      "program": "trace_req_start",
      "program_id": 19,
      "ratio": 0.9719431052632844,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/biosnoop",
      "baseline_avg_ns_per_run": 93.61814242958528,
      "baseline_run_cnt_delta": 1644223,
      "baseline_run_time_ns_delta": 153929103,
      "post_rejit_avg_ns_per_run": 92.58619908059981,
      "post_rejit_run_cnt_delta": 1694148,
      "post_rejit_run_time_ns_delta": 156854724,
      "program": "trace_req_completion_tp",
      "program_id": 20,
      "ratio": 0.9889771007819169,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 60.59567061972352,
      "baseline_run_cnt_delta": 140482,
      "baseline_run_time_ns_delta": 8512601,
      "post_rejit_avg_ns_per_run": 60.980426513641575,
      "post_rejit_run_cnt_delta": 136971,
      "post_rejit_run_time_ns_delta": 8352550,
      "program": "vfs_create",
      "program_id": 23,
      "ratio": 1.0063495607851696,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 67.39313572542902,
      "baseline_run_cnt_delta": 641,
      "baseline_run_time_ns_delta": 43199,
      "post_rejit_avg_ns_per_run": 69.20913461538461,
      "post_rejit_run_cnt_delta": 832,
      "post_rejit_run_time_ns_delta": 57582,
      "program": "kfunc__vmlinux__vfs_fsync_range",
      "program_id": 24,
      "ratio": 1.0269463480279992,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 45.73734039717152,
      "baseline_run_cnt_delta": 1357902,
      "baseline_run_time_ns_delta": 62106826,
      "post_rejit_avg_ns_per_run": 45.8616860443142,
      "post_rejit_run_cnt_delta": 1375812,
      "post_rejit_run_time_ns_delta": 63097058,
      "program": "vfs_open",
      "program_id": 25,
      "ratio": 1.0027186899383063,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 44.76397655909465,
      "baseline_run_cnt_delta": 61943,
      "baseline_run_time_ns_delta": 2772815,
      "post_rejit_avg_ns_per_run": 43.6314842088038,
      "post_rejit_run_cnt_delta": 61110,
      "post_rejit_run_time_ns_delta": 2666320,
      "program": "vfs_read",
      "program_id": 26,
      "ratio": 0.9747008099515957,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/vfsstat",
      "baseline_avg_ns_per_run": 52.397965340927136,
      "baseline_run_cnt_delta": 94463,
      "baseline_run_time_ns_delta": 4949669,
      "post_rejit_avg_ns_per_run": 51.82690252516514,
      "post_rejit_run_cnt_delta": 98251,
      "post_rejit_run_time_ns_delta": 5092045,
      "program": "vfs_write",
      "program_id": 27,
      "ratio": 0.9891014314764632,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 400.45485720710593,
      "baseline_run_cnt_delta": 17788,
      "baseline_run_time_ns_delta": 7123291,
      "post_rejit_avg_ns_per_run": 378.94069153668227,
      "post_rejit_run_cnt_delta": 16861,
      "post_rejit_run_time_ns_delta": 6389319,
      "program": "__x64_sys_open",
      "program_id": 30,
      "ratio": 0.9462756780615174,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 441.55316835126496,
      "baseline_run_cnt_delta": 543453,
      "baseline_run_time_ns_delta": 239963394,
      "post_rejit_avg_ns_per_run": 369.7887196134002,
      "post_rejit_run_cnt_delta": 599483,
      "post_rejit_run_time_ns_delta": 221682051,
      "program": "kretfunc__vmlinux____x64_sys_openat",
      "program_id": 31,
      "ratio": 0.8374726898556085,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/opensnoop",
      "baseline_avg_ns_per_run": 412.91504090623033,
      "baseline_run_cnt_delta": 3178,
      "baseline_run_time_ns_delta": 1312244,
      "post_rejit_avg_ns_per_run": 407.24661746617465,
      "post_rejit_run_cnt_delta": 3252,
      "post_rejit_run_time_ns_delta": 1324366,
      "program": "kretfunc__vmlinux____x64_sys_openat2",
      "program_id": 32,
      "ratio": 0.9862721797985001,
      "runner": "bcc",
      "type": "tracing",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 55.99023080159683,
      "baseline_run_cnt_delta": 9744300,
      "baseline_run_time_ns_delta": 545585606,
      "post_rejit_avg_ns_per_run": 58.66586780464091,
      "post_rejit_run_cnt_delta": 9485159,
      "post_rejit_run_time_ns_delta": 556455084,
      "program": "tracepoint__raw_syscalls__sys_enter",
      "program_id": 35,
      "ratio": 1.0477875687372193,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/syscount",
      "baseline_avg_ns_per_run": 55.986532127856066,
      "baseline_run_cnt_delta": 9744301,
      "baseline_run_time_ns_delta": 545549621,
      "post_rejit_avg_ns_per_run": 55.82537532313635,
      "post_rejit_run_cnt_delta": 9485160,
      "post_rejit_run_time_ns_delta": 529512617,
      "program": "tracepoint__raw_syscalls__sys_exit",
      "program_id": 36,
      "ratio": 0.99712150764488,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "stress_ng_os"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 758.6410256410256,
      "baseline_run_cnt_delta": 312,
      "baseline_run_time_ns_delta": 236696,
      "post_rejit_avg_ns_per_run": 790.3887043189369,
      "post_rejit_run_cnt_delta": 301,
      "post_rejit_run_time_ns_delta": 237907,
      "program": "trace_connect_entry",
      "program_id": 39,
      "ratio": 1.041848091000728,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 3783.596153846154,
      "baseline_run_cnt_delta": 156,
      "baseline_run_time_ns_delta": 590241,
      "post_rejit_avg_ns_per_run": 3822.9139072847684,
      "post_rejit_run_cnt_delta": 151,
      "post_rejit_run_time_ns_delta": 577260,
      "program": "trace_connect_v4_return",
      "program_id": 40,
      "ratio": 1.0103916358511589,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcpconnect",
      "baseline_avg_ns_per_run": 3936.8653846153848,
      "baseline_run_cnt_delta": 156,
      "baseline_run_time_ns_delta": 614151,
      "post_rejit_avg_ns_per_run": 3927.9533333333334,
      "post_rejit_run_cnt_delta": 150,
      "post_rejit_run_time_ns_delta": 589193,
      "program": "trace_connect_v6_return",
      "program_id": 41,
      "ratio": 0.9977362570442774,
      "runner": "bcc",
      "type": "kprobe",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/tcplife",
      "baseline_avg_ns_per_run": 825.888343156516,
      "baseline_run_cnt_delta": 3054,
      "baseline_run_time_ns_delta": 2522263,
      "post_rejit_avg_ns_per_run": 907.948069241012,
      "post_rejit_run_cnt_delta": 3004,
      "post_rejit_run_time_ns_delta": 2727476,
      "program": "tracepoint__sock__inet_sock_set_state",
      "program_id": 44,
      "ratio": 1.0993593465320828,
      "runner": "bcc",
      "type": "tracepoint",
      "workload": "tcp_connect"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 187.4924329936921,
      "baseline_run_cnt_delta": 14088002,
      "baseline_run_time_ns_delta": 2641393771,
      "post_rejit_avg_ns_per_run": 192.28204949511576,
      "post_rejit_run_cnt_delta": 13717798,
      "post_rejit_run_time_ns_delta": 2637686314,
      "program": "sched_switch",
      "program_id": 47,
      "ratio": 1.0255456522961905,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 60.90894532244698,
      "baseline_run_cnt_delta": 679383,
      "baseline_run_time_ns_delta": 41380502,
      "post_rejit_avg_ns_per_run": 85.67916620936633,
      "post_rejit_run_cnt_delta": 492018,
      "post_rejit_run_time_ns_delta": 42155692,
      "program": "sched_wakeup",
      "program_id": 48,
      "ratio": 1.4066762403418385,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bcc/runqlat",
      "baseline_avg_ns_per_run": 221.51121361539685,
      "baseline_run_cnt_delta": 12574,
      "baseline_run_time_ns_delta": 2785282,
      "post_rejit_avg_ns_per_run": 186.90176425049913,
      "post_rejit_run_cnt_delta": 24543,
      "post_rejit_run_time_ns_delta": 4587130,
      "program": "raw_tracepoint__sched_wakeup_new",
      "program_id": 49,
      "ratio": 0.8437575741651208,
      "runner": "bcc",
      "type": "raw_tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 4319.333333333333,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 12958,
      "post_rejit_avg_ns_per_run": 3338.0,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 10014,
      "program": "tracepoint__sched_process_free",
      "program_id": 63,
      "ratio": 0.7728044451304215,
      "runner": "otelcol-ebpf-profiler",
      "type": "tracepoint",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "otelcol-ebpf-profiler/profiling",
      "baseline_avg_ns_per_run": 971.4754810676599,
      "baseline_run_cnt_delta": 1611,
      "baseline_run_time_ns_delta": 1565047,
      "post_rejit_avg_ns_per_run": 1096.2716584158416,
      "post_rejit_run_cnt_delta": 1616,
      "post_rejit_run_time_ns_delta": 1771575,
      "program": "native_tracer_entry",
      "program_id": 64,
      "ratio": 1.128460449882924,
      "runner": "otelcol-ebpf-profiler",
      "type": "perf_event",
      "workload": "stress_ng_cpu"
    },
    {
      "app": "cilium/agent",
      "baseline_avg_ns_per_run": 1215.3669527896996,
      "baseline_run_cnt_delta": 466,
      "baseline_run_time_ns_delta": 566361,
      "post_rejit_avg_ns_per_run": 907.5634328358209,
      "post_rejit_run_cnt_delta": 536,
      "post_rejit_run_time_ns_delta": 486454,
      "program": "cil_from_netdev",
      "program_id": 166,
      "ratio": 0.7467402587775156,
      "runner": "cilium",
      "type": "sched_cls",
      "workload": "network_lossy_multi"
    },
    {
      "app": "katran",
      "baseline_avg_ns_per_run": 321.95190852530686,
      "baseline_run_cnt_delta": 35682,
      "baseline_run_time_ns_delta": 11487888,
      "post_rejit_avg_ns_per_run": 308.92791842475384,
      "post_rejit_run_cnt_delta": 36972,
      "post_rejit_run_time_ns_delta": 11421683,
      "program": "xdp_root",
      "program_id": 479,
      "ratio": 0.9595467839895433,
      "runner": "katran",
      "type": "xdp",
      "workload": "network"
    },
    {
      "app": "bpftrace/capable",
      "baseline_avg_ns_per_run": 155.13150655637315,
      "baseline_run_cnt_delta": 1234524,
      "baseline_run_time_ns_delta": 191513568,
      "post_rejit_avg_ns_per_run": 194.70016117650133,
      "post_rejit_run_cnt_delta": 1147810,
      "post_rejit_run_time_ns_delta": 223478792,
      "program": "cap_capable",
      "program_id": 666,
      "ratio": 1.2550652378648133,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_os"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 413.7717113316827,
      "baseline_run_cnt_delta": 1374006,
      "baseline_run_time_ns_delta": 568524814,
      "post_rejit_avg_ns_per_run": 431.3846375697659,
      "post_rejit_run_cnt_delta": 1418135,
      "post_rejit_run_time_ns_delta": 611761653,
      "program": "block_io_start",
      "program_id": 673,
      "ratio": 1.042566772342647,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/biosnoop",
      "baseline_avg_ns_per_run": 815.9124256470607,
      "baseline_run_cnt_delta": 1374021,
      "baseline_run_time_ns_delta": 1121080807,
      "post_rejit_avg_ns_per_run": 782.1932369636498,
      "post_rejit_run_cnt_delta": 1418150,
      "post_rejit_run_time_ns_delta": 1109267339,
      "program": "block_io_done",
      "program_id": 674,
      "ratio": 0.9586730295758521,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "fio_randrw"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 1928.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1928,
      "post_rejit_avg_ns_per_run": 1972.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1972,
      "program": "1",
      "program_id": 681,
      "ratio": 1.0228215767634854,
      "runner": "bpftrace",
      "type": "perf_event",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/vfsstat",
      "baseline_avg_ns_per_run": 32.87256543011347,
      "baseline_run_cnt_delta": 1565831,
      "baseline_run_time_ns_delta": 51472882,
      "post_rejit_avg_ns_per_run": 32.49736491543806,
      "post_rejit_run_cnt_delta": 1559153,
      "post_rejit_run_time_ns_delta": 50668364,
      "program": "vfs_create",
      "program_id": 682,
      "ratio": 0.9885862113356173,
      "runner": "bpftrace",
      "type": "kprobe",
      "workload": "stress_ng_filesystem"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 59.53326303789666,
      "baseline_run_cnt_delta": 970191,
      "baseline_run_time_ns_delta": 57758636,
      "post_rejit_avg_ns_per_run": 112.34781299138484,
      "post_rejit_run_cnt_delta": 451530,
      "post_rejit_run_time_ns_delta": 50728408,
      "program": "sched_wakeup",
      "program_id": 689,
      "ratio": 1.887143543935571,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 157.00933589353107,
      "baseline_run_cnt_delta": 30206,
      "baseline_run_time_ns_delta": 4742624,
      "post_rejit_avg_ns_per_run": 158.10074650673133,
      "post_rejit_run_cnt_delta": 31346,
      "post_rejit_run_time_ns_delta": 4955826,
      "program": "tracepoint_sched_sched_wakeup_new",
      "program_id": 690,
      "ratio": 1.0069512466057455,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/runqlat",
      "baseline_avg_ns_per_run": 134.69188669969594,
      "baseline_run_cnt_delta": 11338222,
      "baseline_run_time_ns_delta": 1527166513,
      "post_rejit_avg_ns_per_run": 130.32663358179587,
      "post_rejit_run_cnt_delta": 12781270,
      "post_rejit_run_time_ns_delta": 1665739892,
      "program": "sched_switch",
      "program_id": 691,
      "ratio": 0.9675908235836604,
      "runner": "bpftrace",
      "type": "tracepoint",
      "workload": "stress_ng_scheduler"
    },
    {
      "app": "bpftrace/tcplife",
      "baseline_avg_ns_per_run": 900.1810995328782,
      "baseline_run_cnt_delta": 2783,
      "baseline_run_time_ns_delta": 2505204,
      "post_rejit_avg_ns_per_run": 955.973674170164,
      "post_rejit_run_cnt_delta": 2621,
      "post_rejit_run_time_ns_delta": 2505607,
      "program": "tcp_set_state",
      "program_id": 699,
      "ratio": 1.061979278021098,
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
            "avg_ns_per_run": 335.91925927944624,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 1100820,
            "run_time_ns_delta": 369786639,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0114809300000047,
            "ops_per_sec": 1486164.4499812694,
            "ops_total": 1503227.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [6186] setting to a 1 secs run per stressor\nstress-ng: info:  [6186] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [6186] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [6186] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6186]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6186] cap             1280520      1.00      0.25      0.75   1280413.15     1281165.71\nstress-ng: metrc: [6186] eventfd          149259      1.00      0.07      0.64    149207.52      210046.14\nstress-ng: metrc: [6186] get                1005      1.00      0.01      0.11      1004.60        8256.72\nstress-ng: metrc: [6186] prctl              4229      1.00      0.62      0.38      4228.21        4234.34\nstress-ng: metrc: [6186] set               68214      1.00      0.11      0.86     68213.01       70232.63\nstress-ng: info:  [6186] skipped: 0\nstress-ng: info:  [6186] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [6186] failed: 0\nstress-ng: info:  [6186] metrics untrustworthy: 0\nstress-ng: info:  [6186] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "6": {
            "avg_ns_per_run": 337.1058198233413,
            "bytes_jited": 203,
            "bytes_xlated": 344,
            "id": 6,
            "name": "cap_capable",
            "run_cnt_delta": 1048915,
            "run_time_ns_delta": 353595351,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0147855749999906,
            "ops_per_sec": 1438918.7587732645,
            "ops_total": 1460194.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [14432] setting to a 1 secs run per stressor\nstress-ng: info:  [14432] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [14432] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [14432] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [14432]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [14432] cap             1235585      1.00      0.28      0.72   1235584.41     1236346.59\nstress-ng: metrc: [14432] eventfd          154334      1.00      0.09      0.62    154312.73      217623.48\nstress-ng: metrc: [14432] get                 961      1.00      0.03      0.10       960.70        7746.44\nstress-ng: metrc: [14432] prctl              3983      1.00      0.63      0.36      3982.05        4027.52\nstress-ng: metrc: [14432] set               65331      1.00      0.14      0.84     65331.70       67095.06\nstress-ng: info:  [14432] skipped: 0\nstress-ng: info:  [14432] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [14432] failed: 0\nstress-ng: info:  [14432] metrics untrustworthy: 0\nstress-ng: info:  [14432] successful run completed in 1.00 secs"
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
            "avg_ns_per_run": 795.5,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 1591,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 168.0,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 336,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.022909820999999,
            "ops_per_sec": 24122131.290007457,
            "ops_total": 24674765.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8863] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [8863] setting to a 1 secs run per stressor\nstress-ng: info:  [8863] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [8863] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [8863] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8863]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8863] clone               969      1.01      0.20      0.88       961.47         897.26\nstress-ng: metrc: [8863] fork               2683      1.00      0.23      0.28      2682.70        5282.15\nstress-ng: metrc: [8863] futex            492892      2.00      0.24      1.22    246423.06      337386.28\nstress-ng: metrc: [8863] sem              955616      1.00      0.16      0.49    955588.89     1481019.52\nstress-ng: metrc: [8863] sem-sysv        4077883      1.00      0.13      0.80   4074847.97     4421624.51\nstress-ng: metrc: [8863] switch           507282      1.00      0.18      0.71    507201.34      568196.66\nstress-ng: metrc: [8863] vfork             21808      1.00      0.16      0.22     21808.06       57627.41\nstress-ng: metrc: [8863] yield          18615632      1.01      3.82      6.23  18400718.07     1853052.68\nstress-ng: info:  [8863] skipped: 1: exec (1)\nstress-ng: info:  [8863] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [8863] failed: 0\nstress-ng: info:  [8863] metrics untrustworthy: 0\nstress-ng: info:  [8863] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "9": {
            "avg_ns_per_run": 1069.0,
            "bytes_jited": 2677,
            "bytes_xlated": 4144,
            "id": 9,
            "name": "syscall__execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 2138,
            "type": "kprobe"
          },
          "10": {
            "avg_ns_per_run": 193.5,
            "bytes_jited": 492,
            "bytes_xlated": 704,
            "id": 10,
            "name": "do_ret_sys_execve",
            "run_cnt_delta": 2,
            "run_time_ns_delta": 387,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0173335669999943,
            "ops_per_sec": 23493382.873898756,
            "ops_total": 23900607.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [28414] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [28414] setting to a 1 secs run per stressor\nstress-ng: info:  [28414] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [28414] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [28414] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [28414]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [28414] clone               789      1.00      0.18      0.75       785.84         857.12\nstress-ng: metrc: [28414] fork               3906      1.00      0.33      0.45      3905.88        5032.38\nstress-ng: metrc: [28414] futex            338144      2.00      0.15      1.12    169055.35      266317.40\nstress-ng: metrc: [28414] sem             1084646      1.00      0.20      0.45   1084608.50     1682748.76\nstress-ng: metrc: [28414] sem-sysv        3865820      1.00      0.12      0.77   3863931.47     4338937.77\nstress-ng: metrc: [28414] switch           594924      1.00      0.10      0.62    594765.89      829093.04\nstress-ng: metrc: [28414] vfork             22395      1.00      0.19      0.28     22395.17       48055.98\nstress-ng: metrc: [28414] yield          17989983      1.01      3.90      6.29  17875513.85     1764978.86\nstress-ng: info:  [28414] skipped: 1: exec (1)\nstress-ng: info:  [28414] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [28414] failed: 0\nstress-ng: info:  [28414] metrics untrustworthy: 0\nstress-ng: info:  [28414] successful run completed in 1.01 secs"
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
      "baseline": null,
      "error": "stress_ng_network workload failed: /usr/bin/stress-ng: option '--bind' is ambiguous; possibilities: '--bind-mount' '--bind-mount-ops' '--binderfs' '--binderfs-opts'",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bcc",
      "selected_workload": "stress_ng_network",
      "status": "error"
    },
    {
      "app": "bcc/biosnoop",
      "baseline": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 212.1921271517959,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1644208,
            "run_time_ns_delta": 348887993,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 203.60542276024225,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1644218,
            "run_time_ns_delta": 334771701,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 93.61814242958528,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1644223,
            "run_time_ns_delta": 153929103,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.33624569600002,
            "ops_per_sec": 413551.61019932013,
            "ops_total": 2206813.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.270037,\n        \"1000\" : 17.757961\n      },\n      \"latency_us\" : {\n        \"2\" : 29.732714,\n        \"4\" : 1.661404,\n        \"10\" : 15.139947,\n        \"20\" : 31.569587,\n        \"50\" : 3.004302,\n        \"100\" : 0.614964,\n        \"250\" : 0.239426,\n        \"500\" : 0.010000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 208.2073184336767,
            "bytes_jited": 267,
            "bytes_xlated": 448,
            "id": 18,
            "name": "trace_pid_start_tp",
            "run_cnt_delta": 1694133,
            "run_time_ns_delta": 352730889,
            "type": "tracepoint"
          },
          "19": {
            "avg_ns_per_run": 197.89288684603366,
            "bytes_jited": 335,
            "bytes_xlated": 616,
            "id": 19,
            "name": "trace_req_start",
            "run_cnt_delta": 1694143,
            "run_time_ns_delta": 335258849,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 92.58619908059981,
            "bytes_jited": 550,
            "bytes_xlated": 856,
            "id": 20,
            "name": "trace_req_completion_tp",
            "run_cnt_delta": 1694148,
            "run_time_ns_delta": 156854724,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.338654323999975,
            "ops_per_sec": 425862.747805061,
            "ops_total": 2273534.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.090697,\n        \"1000\" : 15.671798\n      },\n      \"latency_us\" : {\n        \"2\" : 32.027703,\n        \"4\" : 1.569897,\n        \"10\" : 17.388681,\n        \"20\" : 29.651418,\n        \"50\" : 2.922052,\n        \"100\" : 0.485774,\n        \"250\" : 0.182099,\n        \"500\" : 0.010000,\n        \"750\" : 0.010000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
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
            "avg_ns_per_run": 60.59567061972352,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 140482,
            "run_time_ns_delta": 8512601,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 67.39313572542902,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 641,
            "run_time_ns_delta": 43199,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 45.73734039717152,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 1357902,
            "run_time_ns_delta": 62106826,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 44.76397655909465,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 61943,
            "run_time_ns_delta": 2772815,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 52.397965340927136,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 94463,
            "run_time_ns_delta": 4949669,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1075391219999915,
            "ops_per_sec": 2628598.793641551,
            "ops_total": 2911276.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [6743] setting to a 1 secs run per stressor\nstress-ng: info:  [6743] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [6743] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [6760] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [6748] dentry: 107182 dentries allocated\nstress-ng: metrc: [6743] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6743]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6743] access            11033      1.00      0.22      1.48     11022.03        6487.25\nstress-ng: metrc: [6743] chdir                49      1.08      0.10      0.79        45.49          55.46\nstress-ng: metrc: [6743] chmod               144      1.02      0.00      0.03       140.94        4879.21\nstress-ng: metrc: [6743] chown               159      1.02      0.01      0.00       155.65       19265.72\nstress-ng: metrc: [6743] dentry            12564      1.02      0.02      0.40     12302.15       30207.01\nstress-ng: metrc: [6743] dir                8193      1.09      0.03      0.95      7530.83        8347.48\nstress-ng: metrc: [6743] dirmany            9983      1.02      0.02      0.23      9823.25       40988.35\nstress-ng: metrc: [6743] fallocate             1      1.02      0.00      0.00         0.98         230.47\nstress-ng: metrc: [6743] file-ioctl        80520      1.00      0.12      0.72     80456.28       95334.96\nstress-ng: metrc: [6743] filename           3944      1.01      0.02      0.77      3891.66        5006.87\nstress-ng: metrc: [6743] flock           2403128      1.01      0.37      0.70   2371699.32     2235197.60\nstress-ng: metrc: [6743] fpunch             1893      1.02      0.00      0.27      1854.51        7006.44\nstress-ng: metrc: [6743] fstat              2120      1.00      0.12      0.56      2119.90        3145.73\nstress-ng: metrc: [6743] getdent          210017      1.00      0.05      0.95    210012.49      210833.56\nstress-ng: metrc: [6743] hdd               29626      1.02      0.36      0.29     29020.69       45987.04\nstress-ng: metrc: [6743] inotify               2      1.00      0.00      0.00         2.00         730.19\nstress-ng: metrc: [6743] open              19456      1.02      0.02      0.26     19144.80       69458.92\nstress-ng: metrc: [6743] rename              441      1.02      0.00      0.01       431.97       29147.39\nstress-ng: metrc: [6743] touch             69533      1.02      0.08      1.67     68176.62       39661.86\nstress-ng: metrc: [6743] utime             48470      1.00      0.01      0.80     48467.58       60178.36\nstress-ng: info:  [6743] skipped: 0\nstress-ng: info:  [6743] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [6743] failed: 0\nstress-ng: info:  [6743] metrics untrustworthy: 0\nstress-ng: info:  [6743] successful run completed in 1.10 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "23": {
            "avg_ns_per_run": 60.980426513641575,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 23,
            "name": "vfs_create",
            "run_cnt_delta": 136971,
            "run_time_ns_delta": 8352550,
            "type": "tracing"
          },
          "24": {
            "avg_ns_per_run": 69.20913461538461,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 24,
            "name": "kfunc__vmlinux__vfs_fsync_range",
            "run_cnt_delta": 832,
            "run_time_ns_delta": 57582,
            "type": "tracing"
          },
          "25": {
            "avg_ns_per_run": 45.8616860443142,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 25,
            "name": "vfs_open",
            "run_cnt_delta": 1375812,
            "run_time_ns_delta": 63097058,
            "type": "tracing"
          },
          "26": {
            "avg_ns_per_run": 43.6314842088038,
            "bytes_jited": 87,
            "bytes_xlated": 136,
            "id": 26,
            "name": "vfs_read",
            "run_cnt_delta": 61110,
            "run_time_ns_delta": 2666320,
            "type": "tracing"
          },
          "27": {
            "avg_ns_per_run": 51.82690252516514,
            "bytes_jited": 90,
            "bytes_xlated": 144,
            "id": 27,
            "name": "vfs_write",
            "run_cnt_delta": 98251,
            "run_time_ns_delta": 5092045,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1298280549999902,
            "ops_per_sec": 2384251.2921136688,
            "ops_total": 2693794.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [24546] setting to a 1 secs run per stressor\nstress-ng: info:  [24546] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [24546] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [24565] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [24551] dentry: 78687 dentries allocated\nstress-ng: metrc: [24546] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24546]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24546] access            11072      1.00      0.19      1.45     11054.86        6734.98\nstress-ng: metrc: [24546] chdir                52      1.08      0.12      0.80        48.20          56.56\nstress-ng: metrc: [24546] chmod               171      1.01      0.00      0.04       169.20        4381.25\nstress-ng: metrc: [24546] chown               207      1.00      0.01      0.00       206.61       31387.41\nstress-ng: metrc: [24546] dentry            14336      1.02      0.08      0.39     14009.12       30585.36\nstress-ng: metrc: [24546] dir                8193      1.10      0.13      0.90      7463.56        7960.13\nstress-ng: metrc: [24546] dirmany           11827      1.00      0.02      0.25     11817.08       43135.11\nstress-ng: metrc: [24546] fallocate             2      1.01      0.01      0.00         1.98         337.10\nstress-ng: metrc: [24546] file-ioctl        82119      1.00      0.06      0.71     82063.83      105531.61\nstress-ng: metrc: [24546] filename           3816      1.01      0.02      0.69      3779.98        5389.31\nstress-ng: metrc: [24546] flock           2186233      1.01      0.42      0.58   2166578.18     2192604.71\nstress-ng: metrc: [24546] fpunch             2064      1.01      0.00      0.25      2044.52        8087.58\nstress-ng: metrc: [24546] fstat              2074      1.00      0.11      0.60      2072.38        2930.01\nstress-ng: metrc: [24546] getdent          212618      1.00      0.06      0.94    212614.65      212998.42\nstress-ng: metrc: [24546] hdd               27925      1.02      0.40      0.31     27321.87       38964.07\nstress-ng: metrc: [24546] inotify               2      1.05      0.00      0.00         1.91         566.57\nstress-ng: metrc: [24546] open              20053      1.02      0.00      0.28     19608.42       72390.10\nstress-ng: metrc: [24546] rename              582      1.01      0.00      0.02       576.69       34051.02\nstress-ng: metrc: [24546] touch             63404      1.02      0.04      1.52     62044.63       40794.45\nstress-ng: metrc: [24546] utime             47044      1.00      0.04      0.73     47027.94       61383.25\nstress-ng: info:  [24546] skipped: 0\nstress-ng: info:  [24546] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [24546] failed: 0\nstress-ng: info:  [24546] metrics untrustworthy: 0\nstress-ng: info:  [24546] successful run completed in 1.11 secs"
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
            "avg_ns_per_run": 400.45485720710593,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 17788,
            "run_time_ns_delta": 7123291,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 441.55316835126496,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 543453,
            "run_time_ns_delta": 239963394,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 412.91504090623033,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 3178,
            "run_time_ns_delta": 1312244,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1171844980000003,
            "ops_per_sec": 2830459.0742719015,
            "ops_total": 3162145.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [8307] setting to a 1 secs run per stressor\nstress-ng: info:  [8307] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [8307] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [8324] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [8312] dentry: 104173 dentries allocated\nstress-ng: metrc: [8307] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [8307]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [8307] access            10167      1.00      0.11      1.40     10143.74        6715.43\nstress-ng: metrc: [8307] chdir                49      1.08      0.15      0.74        45.27          55.12\nstress-ng: metrc: [8307] chmod               151      1.02      0.00      0.03       148.29        5178.15\nstress-ng: metrc: [8307] chown               167      1.02      0.00      0.01       163.94       20266.99\nstress-ng: metrc: [8307] dentry            12875      1.04      0.05      0.40     12430.86       28532.43\nstress-ng: metrc: [8307] dir                8192      1.09      0.04      0.86      7498.37        9157.44\nstress-ng: metrc: [8307] dirmany           10495      1.02      0.00      0.25     10312.62       42395.65\nstress-ng: metrc: [8307] fallocate             2      1.02      0.01      0.00         1.96         385.58\nstress-ng: metrc: [8307] file-ioctl        67302      1.00      0.13      0.57     67297.62       95877.94\nstress-ng: metrc: [8307] filename           2884      1.02      0.04      0.54      2835.94        5044.83\nstress-ng: metrc: [8307] flock           2703898      1.00      0.46      0.55   2693167.85     2674666.57\nstress-ng: metrc: [8307] fpunch             1737      1.02      0.00      0.38      1707.00        4575.71\nstress-ng: metrc: [8307] fstat              1734      1.00      0.13      0.47      1733.92        2874.17\nstress-ng: metrc: [8307] getdent          187022      1.00      0.04      0.89    187017.76      200143.40\nstress-ng: metrc: [8307] hdd               26624      1.02      0.40      0.30     26188.25       37937.60\nstress-ng: metrc: [8307] inotify               3      1.02      0.00      0.00         2.94         728.33\nstress-ng: metrc: [8307] open              19456      1.03      0.01      0.27     18941.64       69997.19\nstress-ng: metrc: [8307] rename              480      1.02      0.00      0.02       471.52       28220.35\nstress-ng: metrc: [8307] touch             63165      1.02      0.04      1.41     61657.01       43577.85\nstress-ng: metrc: [8307] utime             45742      1.00      0.05      0.69     45740.08       61490.85\nstress-ng: info:  [8307] skipped: 0\nstress-ng: info:  [8307] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [8307] failed: 0\nstress-ng: info:  [8307] metrics untrustworthy: 0\nstress-ng: info:  [8307] successful run completed in 1.10 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "30": {
            "avg_ns_per_run": 378.94069153668227,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 30,
            "name": "__x64_sys_open",
            "run_cnt_delta": 16861,
            "run_time_ns_delta": 6389319,
            "type": "tracing"
          },
          "31": {
            "avg_ns_per_run": 369.7887196134002,
            "bytes_jited": 517,
            "bytes_xlated": 600,
            "id": 31,
            "name": "kretfunc__vmlinux____x64_sys_openat",
            "run_cnt_delta": 599483,
            "run_time_ns_delta": 221682051,
            "type": "tracing"
          },
          "32": {
            "avg_ns_per_run": 407.24661746617465,
            "bytes_jited": 590,
            "bytes_xlated": 640,
            "id": 32,
            "name": "kretfunc__vmlinux____x64_sys_openat2",
            "run_cnt_delta": 3252,
            "run_time_ns_delta": 1324366,
            "type": "tracing"
          }
        },
        "workloads": [
          {
            "duration_s": 1.112535944000001,
            "ops_per_sec": 2665830.2736149593,
            "ops_total": 2965832.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [24093] setting to a 1 secs run per stressor\nstress-ng: info:  [24093] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [24093] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [24112] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [24098] dentry: 74895 dentries allocated\nstress-ng: metrc: [24093] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24093]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24093] access             9027      1.00      0.22      1.37      9020.62        5682.48\nstress-ng: metrc: [24093] chdir                51      1.07      0.08      0.84        47.49          55.37\nstress-ng: metrc: [24093] chmod               152      1.01      0.00      0.03       150.65        4747.18\nstress-ng: metrc: [24093] chown               165      1.01      0.00      0.01       163.10       19970.95\nstress-ng: metrc: [24093] dentry            12288      1.03      0.03      0.37     11959.36       30271.97\nstress-ng: metrc: [24093] dir                8192      1.09      0.04      0.83      7537.56        9451.54\nstress-ng: metrc: [24093] dirmany           12833      1.01      0.01      0.29     12694.58       43064.63\nstress-ng: metrc: [24093] fallocate             2      1.01      0.00      0.00         1.98         428.82\nstress-ng: metrc: [24093] file-ioctl        71952      1.01      0.08      0.72     71162.68       90647.85\nstress-ng: metrc: [24093] filename           3328      1.01      0.05      0.61      3300.37        4978.48\nstress-ng: metrc: [24093] flock           2492611      1.01      0.42      0.56   2466477.87     2539345.11\nstress-ng: metrc: [24093] fpunch             2218      1.01      0.02      0.28      2194.01        7596.31\nstress-ng: metrc: [24093] fstat              1813      1.00      0.09      0.49      1812.10        3086.88\nstress-ng: metrc: [24093] getdent          200947      1.00      0.10      0.88    200942.88      204396.39\nstress-ng: metrc: [24093] hdd               27284      1.01      0.31      0.33     26997.41       42391.01\nstress-ng: metrc: [24093] inotify               2      1.01      0.00      0.00         1.98         625.98\nstress-ng: metrc: [24093] open              18529      1.01      0.02      0.26     18308.96       65457.54\nstress-ng: metrc: [24093] rename              456      1.01      0.00      0.02       451.38       29026.10\nstress-ng: metrc: [24093] touch             62692      1.01      0.02      1.46     62005.22       42291.02\nstress-ng: metrc: [24093] utime             41290      1.01      0.06      0.64     40994.42       59489.16\nstress-ng: info:  [24093] skipped: 0\nstress-ng: info:  [24093] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [24093] failed: 0\nstress-ng: info:  [24093] metrics untrustworthy: 0\nstress-ng: info:  [24093] successful run completed in 1.10 secs"
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
            "avg_ns_per_run": 55.99023080159683,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 9744300,
            "run_time_ns_delta": 545585606,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 55.986532127856066,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 9744301,
            "run_time_ns_delta": 545549621,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0153049859999896,
            "ops_per_sec": 631177.8321159614,
            "ops_total": 640838.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [1818] setting to a 1 secs run per stressor\nstress-ng: info:  [1818] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [1818] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [1818] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [1818]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [1818] cap              466917      1.00      0.12      0.88    466916.22      466960.43\nstress-ng: metrc: [1818] eventfd          129603      1.00      0.04      0.79    129568.96      156092.53\nstress-ng: metrc: [1818] get                 994      1.00      0.04      0.12       993.28        6264.57\nstress-ng: metrc: [1818] prctl              2843      1.00      0.65      0.33      2842.25        2895.56\nstress-ng: metrc: [1818] set               40481      1.00      0.09      0.90     40481.21       40927.44\nstress-ng: info:  [1818] skipped: 0\nstress-ng: info:  [1818] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [1818] failed: 0\nstress-ng: info:  [1818] metrics untrustworthy: 0\nstress-ng: info:  [1818] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "35": {
            "avg_ns_per_run": 58.66586780464091,
            "bytes_jited": 72,
            "bytes_xlated": 112,
            "id": 35,
            "name": "tracepoint__raw_syscalls__sys_enter",
            "run_cnt_delta": 9485159,
            "run_time_ns_delta": 556455084,
            "type": "tracepoint"
          },
          "36": {
            "avg_ns_per_run": 55.82537532313635,
            "bytes_jited": 236,
            "bytes_xlated": 400,
            "id": 36,
            "name": "tracepoint__raw_syscalls__sys_exit",
            "run_cnt_delta": 9485160,
            "run_time_ns_delta": 529512617,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0134209859999999,
            "ops_per_sec": 618089.6277590999,
            "ops_total": 626385.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [7427] setting to a 1 secs run per stressor\nstress-ng: info:  [7427] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [7427] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7427] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7427]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7427] cap              453699      1.00      0.13      0.87    453699.11      453739.84\nstress-ng: metrc: [7427] eventfd          129569      1.00      0.03      0.81    129543.30      155442.20\nstress-ng: metrc: [7427] get                 967      1.00      0.03      0.13       966.99        5879.96\nstress-ng: metrc: [7427] prctl              2699      1.00      0.66      0.32      2698.35        2777.00\nstress-ng: metrc: [7427] set               39451      1.00      0.06      0.92     39450.17       40111.43\nstress-ng: info:  [7427] skipped: 0\nstress-ng: info:  [7427] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [7427] failed: 0\nstress-ng: info:  [7427] metrics untrustworthy: 0\nstress-ng: info:  [7427] successful run completed in 1.00 secs"
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
            "avg_ns_per_run": 758.6410256410256,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 312,
            "run_time_ns_delta": 236696,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 3783.596153846154,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 590241,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 3936.8653846153848,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 156,
            "run_time_ns_delta": 614151,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0017805969999927,
            "ops_per_sec": 311.4454411817703,
            "ops_total": 312.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "39": {
            "avg_ns_per_run": 790.3887043189369,
            "bytes_jited": 75,
            "bytes_xlated": 120,
            "id": 39,
            "name": "trace_connect_entry",
            "run_cnt_delta": 301,
            "run_time_ns_delta": 237907,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": 3822.9139072847684,
            "bytes_jited": 480,
            "bytes_xlated": 720,
            "id": 40,
            "name": "trace_connect_v4_return",
            "run_cnt_delta": 151,
            "run_time_ns_delta": 577260,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": 3927.9533333333334,
            "bytes_jited": 477,
            "bytes_xlated": 712,
            "id": 41,
            "name": "trace_connect_v6_return",
            "run_cnt_delta": 150,
            "run_time_ns_delta": 589193,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0027336059999925,
            "ops_per_sec": 300.1794277153231,
            "ops_total": 301.0,
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
            "avg_ns_per_run": 825.888343156516,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 3054,
            "run_time_ns_delta": 2522263,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0000757489999899,
            "ops_per_sec": 304.9768983049334,
            "ops_total": 305.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "44": {
            "avg_ns_per_run": 907.948069241012,
            "bytes_jited": 1067,
            "bytes_xlated": 1672,
            "id": 44,
            "name": "tracepoint__sock__inet_sock_set_state",
            "run_cnt_delta": 3004,
            "run_time_ns_delta": 2727476,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0002105290000145,
            "ops_per_sec": 299.93685459393487,
            "ops_total": 300.0,
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
            "avg_ns_per_run": 187.4924329936921,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 14088002,
            "run_time_ns_delta": 2641393771,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 60.90894532244698,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 679383,
            "run_time_ns_delta": 41380502,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 221.51121361539685,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 12574,
            "run_time_ns_delta": 2785282,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0177844419999929,
            "ops_per_sec": 19016923.624776863,
            "ops_total": 19355129.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15316] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [15316] setting to a 1 secs run per stressor\nstress-ng: info:  [15316] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [15316] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15316] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15316]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15316] clone               600      1.01      0.17      0.72       596.82         675.56\nstress-ng: metrc: [15316] fork               2358      1.00      0.19      0.26      2357.95        5254.17\nstress-ng: metrc: [15316] futex            288348      2.01      0.09      1.13    143681.75      236212.19\nstress-ng: metrc: [15316] sem             1470628      1.00      0.21      0.75   1470278.51     1530107.88\nstress-ng: metrc: [15316] sem-sysv        2618063      1.00      0.21      0.75   2617060.93     2717919.36\nstress-ng: metrc: [15316] switch           475674      1.00      0.08      0.70    475586.01      612440.55\nstress-ng: metrc: [15316] vfork              9522      1.00      0.07      0.11      9521.10       52039.61\nstress-ng: metrc: [15316] yield          14489936      1.00      2.74      7.67  14437436.28     1391744.34\nstress-ng: info:  [15316] skipped: 1: exec (1)\nstress-ng: info:  [15316] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [15316] failed: 0\nstress-ng: info:  [15316] metrics untrustworthy: 0\nstress-ng: info:  [15316] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "47": {
            "avg_ns_per_run": 192.28204949511576,
            "bytes_jited": 662,
            "bytes_xlated": 1168,
            "id": 47,
            "name": "sched_switch",
            "run_cnt_delta": 13717798,
            "run_time_ns_delta": 2637686314,
            "type": "raw_tracepoint"
          },
          "48": {
            "avg_ns_per_run": 85.67916620936633,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 48,
            "name": "sched_wakeup",
            "run_cnt_delta": 492018,
            "run_time_ns_delta": 42155692,
            "type": "raw_tracepoint"
          },
          "49": {
            "avg_ns_per_run": 186.90176425049913,
            "bytes_jited": 149,
            "bytes_xlated": 248,
            "id": 49,
            "name": "raw_tracepoint__sched_wakeup_new",
            "run_cnt_delta": 24543,
            "run_time_ns_delta": 4587130,
            "type": "raw_tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.074259197999993,
            "ops_per_sec": 16604568.09046574,
            "ops_total": 17837610.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [25056] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [25056] setting to a 1 secs run per stressor\nstress-ng: info:  [25056] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [25056] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [25056] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [25056]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [25056] clone               484      1.06      0.14      0.52       455.56         729.27\nstress-ng: metrc: [25056] fork               3050      1.00      0.26      0.34      3049.85        5056.20\nstress-ng: metrc: [25056] futex            283342      2.00      0.11      1.15    141655.67      225953.80\nstress-ng: metrc: [25056] sem              767882      1.00      0.16      0.61    767855.82      991195.34\nstress-ng: metrc: [25056] sem-sysv        1880700      1.00      0.23      0.50   1879670.60     2575377.06\nstress-ng: metrc: [25056] switch           233777      1.00      0.08      0.60    233725.12      344858.26\nstress-ng: metrc: [25056] vfork             20925      1.00      0.19      0.20     20925.36       54132.01\nstress-ng: metrc: [25056] yield          14647450      1.00      3.13      7.71  14598666.01     1352059.74\nstress-ng: info:  [25056] skipped: 1: exec (1)\nstress-ng: info:  [25056] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [25056] failed: 0\nstress-ng: info:  [25056] metrics untrustworthy: 0\nstress-ng: info:  [25056] successful run completed in 1.06 secs"
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
            "avg_ns_per_run": 4319.333333333333,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 63,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 12958,
            "type": "tracepoint"
          },
          "64": {
            "avg_ns_per_run": 971.4754810676599,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 64,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1611,
            "run_time_ns_delta": 1565047,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.015039238000014,
            "ops_per_sec": 3063.5852026009525,
            "ops_total": 15364.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [17299] setting to a 5 secs run per stressor\nstress-ng: info:  [17299] dispatching hogs: 1 cpu\nstress-ng: info:  [17299] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17299] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17299]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17299] cpu               15364      5.00      5.00      0.00      3072.62        3072.86\nstress-ng: info:  [17299] skipped: 0\nstress-ng: info:  [17299] passed: 1: cpu (1)\nstress-ng: info:  [17299] failed: 0\nstress-ng: info:  [17299] metrics untrustworthy: 0\nstress-ng: info:  [17299] successful run completed in 5.00 secs"
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
            "avg_ns_per_run": 3338.0,
            "bytes_jited": 788,
            "bytes_xlated": 1320,
            "id": 63,
            "name": "tracepoint__sched_process_free",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 10014,
            "type": "tracepoint"
          },
          "64": {
            "avg_ns_per_run": 1096.2716584158416,
            "bytes_jited": 3532,
            "bytes_xlated": 5496,
            "id": 64,
            "name": "native_tracer_entry",
            "run_cnt_delta": 1616,
            "run_time_ns_delta": 1771575,
            "type": "perf_event"
          }
        },
        "workloads": [
          {
            "duration_s": 5.020273429999975,
            "ops_per_sec": 2945.257904010235,
            "ops_total": 14786.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [17338] setting to a 5 secs run per stressor\nstress-ng: info:  [17338] dispatching hogs: 1 cpu\nstress-ng: info:  [17338] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [17338] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [17338]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [17338] cpu               14786      5.00      5.00      0.00      2956.25        2956.67\nstress-ng: info:  [17338] skipped: 0\nstress-ng: info:  [17338] passed: 1: cpu (1)\nstress-ng: info:  [17338] failed: 0\nstress-ng: info:  [17338] metrics untrustworthy: 0\nstress-ng: info:  [17338] successful run completed in 5.00 secs"
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
          "97": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 97,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 100,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 101,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 102,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 104,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "105": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 105,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 106,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "107": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 107,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "108": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 108,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "110": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 110,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "111": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 111,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "112": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 112,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 113,
            "name": "tail_handle_ipv4_from_host",
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
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 117,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 118,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 119,
            "name": "cil_host_policy",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 121,
            "name": "tail_handle_ipv4_from_host",
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
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 125,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 128,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
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
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 132,
            "name": "tail_drop_notify",
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
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 135,
            "name": "cil_to_netdev",
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
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 138,
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
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 141,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "142": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 142,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 144,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "145": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 145,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 146,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "147": {
            "avg_ns_per_run": 1087.0,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 147,
            "name": "cil_from_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1087,
            "type": "sched_cls"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 148,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 149,
            "name": "cil_to_host",
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
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 151,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 152,
            "name": "cil_to_netdev",
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
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 154,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 155,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 156,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "157": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 157,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "158": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 158,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "159": {
            "avg_ns_per_run": 634.0,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 159,
            "name": "cil_to_host",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 634,
            "type": "sched_cls"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 160,
            "name": "cil_from_netdev",
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
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 162,
            "name": "cil_from_host",
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
          "165": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 165,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "166": {
            "avg_ns_per_run": 1215.3669527896996,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 166,
            "name": "cil_from_netdev",
            "run_cnt_delta": 466,
            "run_time_ns_delta": 566361,
            "type": "sched_cls"
          },
          "167": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 167,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "168": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 168,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.013262305000012,
            "ops_per_sec": 180.6047645283694,
            "ops_total": 183.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 20 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   121.10ms  127.02ms 845.80ms   87.21%\n    Req/Sec    99.61     40.57   191.00     83.33%\n  183 requests in 1.00s, 29.86KB read\nRequests/sec:    182.64\nTransfer/sec:     29.80KB"
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
          "97": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 97,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 100,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 101,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 102,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 104,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "105": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 105,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 106,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "107": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 107,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "108": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 108,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "110": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 110,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "111": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 111,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "112": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 112,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 113,
            "name": "tail_handle_ipv4_from_host",
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
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 117,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 118,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 119,
            "name": "cil_host_policy",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 121,
            "name": "tail_handle_ipv4_from_host",
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
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 125,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 128,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
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
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 132,
            "name": "tail_drop_notify",
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
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 135,
            "name": "cil_to_netdev",
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
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 138,
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
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 141,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "142": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 142,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "144": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 144,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "145": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 145,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 146,
            "name": "cil_host_policy",
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
            "bytes_jited": 1183,
            "bytes_xlated": 1976,
            "id": 148,
            "name": "tail_handle_ipv4_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 149,
            "name": "cil_to_host",
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
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 151,
            "name": "cil_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 152,
            "name": "cil_to_netdev",
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
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 154,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 382,
            "bytes_xlated": 592,
            "id": 155,
            "name": "tail_handle_ipv4_from_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 156,
            "name": "cil_from_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "157": {
            "avg_ns_per_run": null,
            "bytes_jited": 1236,
            "bytes_xlated": 2056,
            "id": 157,
            "name": "cil_to_netdev",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "158": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 158,
            "name": "tail_drop_notify",
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
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 160,
            "name": "cil_from_netdev",
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
            "bytes_jited": 3340,
            "bytes_xlated": 5952,
            "id": 162,
            "name": "cil_from_host",
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
          "165": {
            "avg_ns_per_run": null,
            "bytes_jited": 526,
            "bytes_xlated": 952,
            "id": 165,
            "name": "cil_to_host",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "166": {
            "avg_ns_per_run": 907.5634328358209,
            "bytes_jited": 3094,
            "bytes_xlated": 5368,
            "id": 166,
            "name": "cil_from_netdev",
            "run_cnt_delta": 536,
            "run_time_ns_delta": 486454,
            "type": "sched_cls"
          },
          "167": {
            "avg_ns_per_run": null,
            "bytes_jited": 364,
            "bytes_xlated": 672,
            "id": 167,
            "name": "tail_drop_notify",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          },
          "168": {
            "avg_ns_per_run": null,
            "bytes_jited": 16,
            "bytes_xlated": 16,
            "id": 168,
            "name": "cil_host_policy",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "sched_cls"
          }
        },
        "workloads": [
          {
            "duration_s": 1.112901447000013,
            "ops_per_sec": 194.08726674069774,
            "ops_total": 216.0,
            "stderr": "",
            "stdout": "Running 1s test @ http://198.18.0.2:18080/\n  2 threads and 20 connections\n  Thread Stats   Avg      Stdev     Max   +/- Stdev\n    Latency   113.08ms  127.05ms 917.34ms   88.49%\n    Req/Sec   110.58     36.83   180.00     73.68%\n  216 requests in 1.10s, 34.58KB read\nRequests/sec:    196.22\nTransfer/sec:     31.41KB"
          }
        ]
      },
      "rejit_result": {
        "applied": true,
        "changed": false,
        "enabled_passes": [
          "wide_mem"
        ],
        "error": "prog 73: prog 73 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8ef20803797a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8ef20803799a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0; prog 111: prog 111 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd401c0422049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd401c0422004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd401c042203c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd401c042205c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8ef204204800\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 150: prog 150 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd401c085e004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd401c085e03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd401c085e004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8ef211929400\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8ef211929400\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8ef203fad800\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd401c085e004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd401c085e03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd401c085e004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...; prog 153: prog 153 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd401c099e004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+118\n     13: 0.....67.. (18) r1 = 0xffffd401c099e03c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd401c099e004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+95\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8ef208a18000\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+43\n     51: 0.....67.9 (18) r1 = 0xffffd401c099e004\n     53: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     54: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     55: 012...67.9 (54) w1 &= 3\n     56: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     57: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     58: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     59: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     60: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     61: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     62: 0.23..67.9 (a6) if w3 < 0x2 goto pc+95\n     63: 0.23..67.9 (bf) r8 = r0\n     64: ..23..6789 (bc) w4 = w3\n     65: ..234.6789 (04) w4 += -1\n     66: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     67: ..234.678. (04) w2 += 10\n     68: ..234.678. (54) w4 &= 255\n     69: ..234.678. (bf) r1 = r6\n     70: .1234.678. (b4) w5 = 2\n     71: .12345678. (85) call bpf_l3_csum_replace#10\n     72: 0.....678. (c6) if w0 s< 0x0 goto pc+105\n     73: ......678. (bf) r3 = r10\n     74: ...3..678. (07) r3 += -40\n     75: ...3..678. (bf) r1 = r6\n     76: .1.3..678. (b4) w2 = 6\n     77: .123..678. (b4) w4 = 6\n     78: .1234.678. (b4) w5 = 0\n     79: .12345678. (85) call bpf_skb_store_bytes#9\n     80: 0.....678. (bc) w1 = w0\n     81: .1....678. (b4) w0 = -141\n     82: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     83: ......678. (bf) r3 = r10\n     84: ...3..678. (07) r3 += -48\n     85: ...3..678. (bf) r1 = r6\n     86: .1.3..678. (b4) w2 = 0\n     87: .123..678. (b4) w4 = 6\n     88: .1234.678. (b4) w5 = 0\n     89: .12345678. (85) call bpf_skb_store_bytes#9\n     90: 0.....678. (bc) w1 = w0\n     91: .1....678. (b4) w0 = -141\n     92: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     93: ......678. (05) goto pc+88\n     94: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     95: .1....678. (b4) w2 = 0\n     96: .12...678. (63) *(u32 *)(r10 -12) = r2\n     97: .12...678. (63) *(u32 *)(r10 -16) = r2\n     98: .12...678. (63) *(u32 *)(r10 -20) = r2\n     99: .1....678. (63) *(u32 *)(r10 -24) = r1\n    100: ......678. (b4) w1 = 64\n    101: .1....678. (63) *(u32 *)(r10 -32) = r1\n    102: ......678. (b4) w1 = 16777216\n    103: .1....678\n... verifier log truncated ...; prog 158: prog 158 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd401c099e049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd401c099e004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd401c099e03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd401c099e05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8ef204204800\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...; prog 167: prog 167 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd401c0ab6049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd401c0ab6004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd401c0ab603c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd401c0ab605c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8ef204204800\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 73 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 13: Permission denied (os error 13)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (79) r2 = *(u64 *)(r1 +0)\n      1: .12....... (79) r6 = *(u64 *)(r2 +0)\n      2: .12...6... (79) r1 = *(u64 *)(r1 +8)\n      3: .12...6... (15) if r1 == 0x0 goto pc+59\n      4: .12...6... (79) r7 = *(u64 *)(r1 +0)\n      5: ..2...67.. (79) r1 = *(u64 *)(r2 +16)\n      6: .1....67.. (55) if r1 != 0x0 goto pc+8\n      7: ......67.. (bf) r4 = r10\n      8: ....4.67.. (07) r4 += -48\n      9: ....4.67.. (bf) r1 = r6\n     10: .1..4.67.. (18) r2 = 0xffff8ef20803797a\n     12: .12.4.67.. (b7) r3 = 32\n     13: .1234.67.. (b7) r5 = 0\n     14: .1234567.. (85) call bpf_seq_printf#126\n     15: ......67.. (7b) *(u64 *)(r10 -56) = r6\n     16: .......7.. (61) r1 = *(u32 *)(r7 +0)\n     17: .1.....7.. (7b) *(u64 *)(r10 -48) = r1\n     18: .......7.. (b7) r3 = 4\n     19: ...3...7.. (bf) r9 = r7\n     20: ...3...7.9 (0f) r9 += r3\n     21: ...3...7.9 (79) r1 = *(u64 *)(r7 +40)\n     22: .1.3...7.9 (79) r8 = *(u64 *)(r7 +48)\n     23: .1.3...789 (15) if r8 == 0x0 goto pc+24\n     24: .1.....789 (b7) r2 = 0\n     25: .12....789 (0f) r1 += r2\n     26: .1.....789 (61) r1 = *(u32 *)(r1 +4)\n     27: .1.....789 (79) r3 = *(u64 *)(r8 +8)\n     28: .1.3...789 (67) r1 <<= 3\n     29: .1.3...789 (0f) r3 += r1\n     30: ...3...789 (79) r6 = *(u64 *)(r8 +0)\n     31: ...3..6789 (bf) r1 = r10\n     32: .1.3..6789 (07) r1 += -8\n     33: .1.3..6789 (b7) r2 = 8\n     34: .123..6789 (85) call bpf_probe_read_kernel#113\n     35: ......6789 (b7) r1 = 0\n     36: .1....6789 (79) r3 = *(u64 *)(r10 -8)\n     37: .1.3..6789 (0f) r3 += r1\n     38: ...3..6789 (bf) r1 = r10\n     39: .1.3..6789 (07) r1 += -12\n     40: .1.3..6789 (b7) r2 = 4\n     41: .123..6789 (85) call bpf_probe_read_kernel#113\n     42: ......6789 (b7) r3 = 4\n     43: ...3..6789 (61) r1 = *(u32 *)(r10 -12)\n     44: .1.3..6789 (61) r2 = *(u32 *)(r8 +16)\n     45: .123..67.9 (3d) if r1 >= r2 goto pc+2\n     46: .1.3..67.. (0f) r6 += r1\n     47: ...3..67.. (bf) r9 = r6\n     48: ...3...7.9 (7b) *(u64 *)(r10 -40) = r9\n     49: ...3...7.. (79) r1 = *(u64 *)(r7 +24)\n     50: .1.3...7.. (7b) *(u64 *)(r10 -32) = r1\n     51: ...3...7.. (79) r1 = *(u64 *)(r7 +32)\n     52: .1.3...... (79) r1 = *(u64 *)(r1 +0)\n     53: .1.3...... (0f) r1 += r3\n     54: .1........ (7b) *(u64 *)(r10 -24) = r1\n     55: .......... (bf) r4 = r10\n     56: ....4..... (07) r4 += -48\n     57: ....4..... (79) r1 = *(u64 *)(r10 -56)\n     58: .1..4..... (18) r2 = 0xffff8ef20803799a\n     60: .12.4..... (b7) r3 = 17\n     61: .1234..... (b7) r5 = 32\n     62: .12345.... (85) call bpf_seq_printf#126\n     63: .......... (b7) r0 = 0\n     64: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (79) r2 = *(u64 *)(r1 +0)\nfunc 'bpf_iter_bpf_prog' arg0 has btf_id 70962 type STRUCT 'bpf_iter_meta'\n1: R1=ctx() R2=trusted_ptr_bpf_iter_meta()\n1: (79) r6 = *(u64 *)(r2 +0)          ; R2=trusted_ptr_bpf_iter_meta() R6=trusted_ptr_seq_file()\n2: (79) r1 = *(u64 *)(r1 +8)          ; R1=ptr_or_null_bpf_prog(id=1)\n3: (15) if r1 == 0x0 goto pc+59       ; R1=ptr_bpf_prog()\n4: (79) r7 = *(u64 *)(r1 +0)\naccess beyond the end of member pages (mend:2) in struct bpf_prog with off 0 size 8\nprocessed 5 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0",
            "exit_code": 1,
            "prog_id": 73
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 111 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd401c0422049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd401c0422004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd401c042203c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd401c042205c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8ef204204800\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 111
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 150 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (61) r2 = *(u32 *)(r1 +48)\n      1: .12....... (b4) w3 = 0\n      2: .123...... (63) *(u32 *)(r1 +48) = r3\n      3: .12....... (18) r3 = 0xffffd401c085e004\n      5: .123...... (71) r3 = *(u8 *)(r3 +0)\n      6: .123...... (61) r4 = *(u32 *)(r1 +80)\n      7: .1234..... (61) r5 = *(u32 *)(r1 +76)\n      8: .12345.... (0f) r5 += r3\n      9: .12.45.... (b4) w0 = -134\n     10: 012.45.... (07) r5 += 20\n     11: 012.45.... (2d) if r5 > r4 goto pc+12\n     12: 012....... (18) r3 = 0xffffd401c085e03c\n     14: 0123...... (61) r3 = *(u32 *)(r3 +0)\n     15: 012....... (18) r3 = 0xffffd401c085e004\n     17: 0123...... (71) r3 = *(u8 *)(r3 +0)\n     18: 0123...... (61) r4 = *(u32 *)(r1 +80)\n     19: 01234..... (61) r5 = *(u32 *)(r1 +76)\n     20: 012345.... (0f) r5 += r3\n     21: 012.45.... (07) r5 += 20\n     22: 012.45.... (2d) if r5 > r4 goto pc+1\n     23: .12....... (b4) w0 = 0\n     24: 012....... (66) if w0 s> 0xffffffff goto pc+44\n     25: 012....... (b4) w3 = 62980354\n     26: 0123...... (63) *(u32 *)(r1 +64) = r3\n     27: 012....... (b4) w3 = 0\n     28: 0123...... (63) *(u32 *)(r1 +60) = r3\n     29: 0123...... (63) *(u32 *)(r1 +52) = r3\n     30: 012....... (63) *(u32 *)(r1 +48) = r2\n     31: 01........ (84) w0 = -w0\n     32: 01........ (63) *(u32 *)(r1 +56) = r0\n     33: 01........ (bf) r6 = r1\n     34: 01....6... (61) r7 = *(u32 *)(r1 +0)\n     35: 0.....67.. (18) r1 = 0x103c10100\n     37: 01....67.. (7b) *(u64 *)(r10 -24) = r1\n     38: 0.....67.. (73) *(u8 *)(r10 -24) = r0\n     39: ......67.. (bf) r2 = r10\n     40: ..2...67.. (07) r2 += -24\n     41: ..2...67.. (18) r1 = 0xffff8ef211929400\n     43: .12...67.. (85) call bpf_map_lookup_elem#1\n     44: 0.....67.. (15) if r0 == 0x0 goto pc+7\n     45: 0.....67.. (79) r1 = *(u64 *)(r0 +0)\n     46: 01....67.. (07) r1 += 1\n     47: 01....67.. (7b) *(u64 *)(r0 +0) = r1\n     48: 0.....67.. (79) r1 = *(u64 *)(r0 +8)\n     49: 01....67.. (0f) r1 += r7\n     50: 01....6... (7b) *(u64 *)(r0 +8) = r1\n     51: ......6... (05) goto pc+11\n     52: ......67.. (7b) *(u64 *)(r10 -8) = r7\n     53: ......6... (b7) r1 = 1\n     54: .1....6... (7b) *(u64 *)(r10 -16) = r1\n     55: ......6... (bf) r2 = r10\n     56: ..2...6... (07) r2 += -24\n     57: ..2...6... (bf) r3 = r10\n     58: ..23..6... (07) r3 += -16\n     59: ..23..6... (18) r1 = 0xffff8ef211929400\n     61: .123..6... (b4) w4 = 0\n     62: .1234.6... (85) call bpf_map_update_elem#2\n     63: ......6... (bf) r1 = r6\n     64: .1........ (18) r2 = 0xffff8ef203fad800\n     66: .12....... (b7) r3 = 1\n     67: .123...... (85) call bpf_tail_call#12\n     68: .......... (b4) w0 = 2\n     69: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (61) r2 = *(u32 *)(r1 +48)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n1: (b4) w3 = 0                        ; R3=0\n2: (63) *(u32 *)(r1 +48) = r3         ; R1=ctx() R3=0\n3: (18) r3 = 0xffffd401c085e004       ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n5: (71) r3 = *(u8 *)(r3 +0)           ; R3=14\n6: (61) r4 = *(u32 *)(r1 +80)         ; R1=ctx() R4=pkt_end()\n7: (61) r5 = *(u32 *)(r1 +76)         ; R1=ctx() R5=pkt(r=0)\n8: (0f) r5 += r3\nmark_precise: frame0: last_idx 8 first_idx 0 subseq_idx -1 \nmark_precise: frame0: regs=r3 stack= before 7: (61) r5 = *(u32 *)(r1 +76)\nmark_precise: frame0: regs=r3 stack= before 6: (61) r4 = *(u32 *)(r1 +80)\nmark_precise: frame0: regs=r3 stack= before 5: (71) r3 = *(u8 *)(r3 +0)\n9: R3=14 R5=pkt(off=14,r=0)\n9: (b4) w0 = -134                     ; R0=0xffffff7a\n10: (07) r5 += 20                     ; R5=pkt(off=34,r=0)\n11: (2d) if r5 > r4 goto pc+12        ; R4=pkt_end() R5=pkt(off=34,r=34)\n12: (18) r3 = 0xffffd401c085e03c      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=60)\n14: (61) r3 = *(u32 *)(r3 +0)         ; R3=128\n15: (18) r3 = 0xffffd401c085e004      ; R3=map_value(map=.rodata.config,ks=4,vs=156,off=4)\n17: (71) r3 = *(u8 *)(r3 +0)          ; R3=14\n18: (61) r4 = *(u32 *)(r1 +80)        ; R1=ctx() R4=pkt_end()\n19: (61) r5 = *(u32 *)(r1 +76)        ; R1=ctx() R5=pkt(r=0)\n20: (0f) r5 += r3\nmark_precis\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 150
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 153 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (61) r7 = *(u32 *)(r6 +48)\n      2: ......67.. (b4) w1 = 0\n      3: .1....67.. (63) *(u32 *)(r6 +48) = r1\n      4: ......67.. (18) r1 = 0xffffd401c099e004\n      6: .1....67.. (71) r1 = *(u8 *)(r1 +0)\n      7: .1....67.. (61) r2 = *(u32 *)(r6 +80)\n      8: .12...67.. (61) r3 = *(u32 *)(r6 +76)\n      9: .123..67.. (0f) r3 += r1\n     10: ..23..67.. (b4) w0 = -134\n     11: 0.23..67.. (07) r3 += 20\n     12: 0.23..67.. (2d) if r3 > r2 goto pc+118\n     13: 0.....67.. (18) r1 = 0xffffd401c099e03c\n     15: 01....67.. (61) r1 = *(u32 *)(r1 +0)\n     16: 0.....67.. (61) r1 = *(u32 *)(r6 +44)\n     17: 01....67.. (63) *(u32 *)(r10 -32) = r1\n     18: 01....67.. (61) r2 = *(u32 *)(r10 -32)\n     19: 012...67.. (63) *(u32 *)(r10 -32) = r1\n     20: 0.2...67.. (54) w2 &= 1\n     21: 0.2...67.. (61) r1 = *(u32 *)(r10 -32)\n     22: 012...67.. (54) w1 &= 2\n     23: 012...67.. (4c) w1 |= w2\n     24: 01....67.. (b4) w8 = 1\n     25: 01....678. (56) if w1 != 0x0 goto pc+1\n     26: 0.....67.. (b4) w8 = 0\n     27: 0.....678. (18) r1 = 0xffffd401c099e004\n     29: 01....678. (71) r1 = *(u8 *)(r1 +0)\n     30: 01....678. (61) r2 = *(u32 *)(r6 +80)\n     31: 012...678. (61) r9 = *(u32 *)(r6 +76)\n     32: 012...6789 (0f) r9 += r1\n     33: 0.2...6789 (bf) r1 = r9\n     34: 012...6789 (07) r1 += 20\n     35: 012...6789 (2d) if r1 > r2 goto pc+95\n     36: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     37: .1....6789 (b7) r2 = 0\n     38: .12...6789 (63) *(u32 *)(r10 -16) = r2\n     39: .12...6789 (63) *(u32 *)(r10 -20) = r2\n     40: .12...6789 (63) *(u32 *)(r10 -24) = r2\n     41: .12...6789 (63) *(u32 *)(r10 -28) = r2\n     42: .1....6789 (63) *(u32 *)(r10 -32) = r1\n     43: ......6789 (b4) w1 = 1\n     44: .1....6789 (73) *(u8 *)(r10 -16) = r1\n     45: ......6789 (bf) r2 = r10\n     46: ..2...6789 (07) r2 += -32\n     47: ..2...6789 (18) r1 = 0xffff8ef208a18000\n     49: .12...6789 (85) call bpf_map_lookup_elem#1\n     50: 0.....6789 (15) if r0 == 0x0 goto pc+43\n     51: 0.....67.9 (18) r1 = 0xffffd401c099e004\n     53: 01....67.9 (71) r2 = *(u8 *)(r1 +0)\n     54: 0.2...67.9 (61) r1 = *(u32 *)(r0 +8)\n     55: 012...67.9 (54) w1 &= 3\n     56: 012...67.9 (56) if w1 != 0x0 goto pc+62\n     57: 0.2...67.9 (79) r1 = *(u64 *)(r0 +24)\n     58: 012...67.9 (7b) *(u64 *)(r10 -40) = r1\n     59: 0.2...67.9 (79) r1 = *(u64 *)(r0 +16)\n     60: 012...67.9 (7b) *(u64 *)(r10 -48) = r1\n     61: 0.2...67.9 (71) r3 = *(u8 *)(r9 +8)\n     62: 0.23..67.9 (a6) if w3 < 0x2 goto pc+95\n     63: 0.23..67.9 (bf) r8 = r0\n     64: ..23..6789 (bc) w4 = w3\n     65: ..234.6789 (04) w4 += -1\n     66: ..234.6789 (73) *(u8 *)(r9 +8) = r4\n     67: ..234.678. (04) w2 += 10\n     68: ..234.678. (54) w4 &= 255\n     69: ..234.678. (bf) r1 = r6\n     70: .1234.678. (b4) w5 = 2\n     71: .12345678. (85) call bpf_l3_csum_replace#10\n     72: 0.....678. (c6) if w0 s< 0x0 goto pc+105\n     73: ......678. (bf) r3 = r10\n     74: ...3..678. (07) r3 += -40\n     75: ...3..678. (bf) r1 = r6\n     76: .1.3..678. (b4) w2 = 6\n     77: .123..678. (b4) w4 = 6\n     78: .1234.678. (b4) w5 = 0\n     79: .12345678. (85) call bpf_skb_store_bytes#9\n     80: 0.....678. (bc) w1 = w0\n     81: .1....678. (b4) w0 = -141\n     82: 01....678. (c6) if w1 s< 0x0 goto pc+48\n     83: ......678. (bf) r3 = r10\n     84: ...3..678. (07) r3 += -48\n     85: ...3..678. (bf) r1 = r6\n     86: .1.3..678. (b4) w2 = 0\n     87: .123..678. (b4) w4 = 6\n     88: .1234.678. (b4) w5 = 0\n     89: .12345678. (85) call bpf_skb_store_bytes#9\n     90: 0.....678. (bc) w1 = w0\n     91: .1....678. (b4) w0 = -141\n     92: 01....678. (c6) if w1 s< 0x0 goto pc+38\n     93: ......678. (05) goto pc+88\n     94: ......6789 (61) r1 = *(u32 *)(r9 +16)\n     95: .1....678. (b4) w2 = 0\n     96: .12...678. (63) *(u32 *)(r10 -12) = r2\n     97: .12...678. (63) *(u32 *)(r10 -16) = r2\n     98: .12...678. (63) *(u32 *)(r10 -20) = r2\n     99: .1....678. (63) *(u32 *)(r10 -24) = r1\n    100: ......678. (b4) w1 = 64\n    101: .1....678. (63) *(u32 *)(r10 -32) = r1\n    102: ......678. (b4) w1 = 16777216\n    103: .1....678\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 153
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 158 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd401c099e049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd401c099e004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd401c099e03c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd401c099e05c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8ef204204800\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 158
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 167 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 16: Device or resource busy (os error 16)\nverifier log summary:\nfunc#0 @0\nLive regs before insn:\n      0: .1........ (b7) r4 = 0\n      1: .1..4..... (61) r2 = *(u32 *)(r1 +56)\n      2: .12.4..... (63) *(u32 *)(r10 -56) = r2\n      3: .1..4..... (18) r3 = 0xffffd401c0ab6049\n      5: .1.34..... (71) r3 = *(u8 *)(r3 +0)\n      6: .1.34..... (16) if w3 == 0x0 goto pc+12\n      7: .1........ (bf) r6 = r1\n      8: ......6... (b4) w1 = 0\n      9: .1....6... (63) *(u32 *)(r10 -48) = r1\n     10: ......6... (bf) r2 = r10\n     11: ..2...6... (07) r2 += -48\n     12: ..2...6... (18) r1 = 0xdeadc0de\n     14: .12...6... (85) call bpf_map_lookup_elem#1\n     15: 0.....6... (b7) r4 = 0\n     16: 0...4.6... (15) if r0 == 0x0 goto pc+1\n     17: 0.....6... (79) r4 = *(u64 *)(r0 +0)\n     18: ....4.6... (bf) r1 = r6\n     19: .1..4..... (61) r0 = *(u32 *)(r1 +16)\n     20: 01..4..... (54) w0 &= 65535\n     21: 01..4..... (b4) w3 = 1\n     22: 01.34..... (16) if w0 == 0xdd86 goto pc+1\n     23: .1..4..... (b4) w3 = 0\n     24: .1.34..... (7b) *(u64 *)(r10 -64) = r4\n     25: .1.3...... (61) r6 = *(u32 *)(r1 +64)\n     26: .1.3..6... (61) r2 = *(u32 *)(r1 +0)\n     27: .123..6... (63) *(u32 *)(r10 -80) = r2\n     28: .1.3..6... (18) r0 = 0xffffd401c0ab6004\n     30: 01.3..6... (71) r0 = *(u8 *)(r0 +0)\n     31: 01.3..6... (b4) w8 = 1\n     32: 01.3..6.8. (16) if w0 == 0x0 goto pc+1\n     33: .1.3..6... (b4) w8 = 0\n     34: .1.3..6.8. (64) w8 <<= 1\n     35: .1.3..6.8. (4c) w8 |= w3\n     36: .1....6.8. (18) r3 = 0xffffd401c0ab603c\n     38: .1.3..6.8. (61) r3 = *(u32 *)(r3 +0)\n     39: .1.3..6.8. (61) r2 = *(u32 *)(r1 +0)\n     40: .123..6.8. (63) *(u32 *)(r10 -72) = r2\n     41: .1.3..6.8. (18) r5 = 0xffffd401c0ab605c\n     43: .1.3.56.8. (69) r5 = *(u16 *)(r5 +0)\n     44: .1.3.56.8. (61) r7 = *(u32 *)(r1 +40)\n     45: .1.3.5678. (61) r4 = *(u32 *)(r1 +60)\n     46: .1.345678. (61) r2 = *(u32 *)(r1 +52)\n     47: .12345678. (61) r9 = *(u32 *)(r1 +48)\n     48: .123456789 (61) r0 = *(u32 *)(r1 +68)\n     49: 0123456789 (6b) *(u16 *)(r10 -46) = r5\n     50: 01234.6789 (63) *(u32 *)(r10 -44) = r0\n     51: .1234.6789 (b4) w5 = 0\n     52: .123456789 (73) *(u8 *)(r10 -10) = r5\n     53: .123456789 (73) *(u8 *)(r10 -11) = r5\n     54: .123456789 (73) *(u8 *)(r10 -9) = r5\n     55: .1234.6789 (b4) w5 = 1\n     56: .123456789 (73) *(u8 *)(r10 -48) = r5\n     57: .1234.6789 (61) r5 = *(u32 *)(r10 -80)\n     58: .123456789 (63) *(u32 *)(r10 -40) = r5\n     59: .1234.6789 (63) *(u32 *)(r10 -32) = r9\n     60: .1234.678. (63) *(u32 *)(r10 -28) = r2\n     61: .1.34.678. (63) *(u32 *)(r10 -24) = r4\n     62: .1.3..678. (63) *(u32 *)(r10 -16) = r7\n     63: .1.3..6.8. (73) *(u8 *)(r10 -12) = r8\n     64: .1.3..6... (79) r2 = *(u64 *)(r10 -64)\n     65: .123..6... (7b) *(u64 *)(r10 -8) = r2\n     66: .1.3..6... (61) r4 = *(u32 *)(r10 -56)\n     67: .1.34.6... (bc) w2 = w4\n     68: .1234.6... (74) w2 >>= 8\n     69: .1234.6... (73) *(u8 *)(r10 -17) = r2\n     70: .1.34.6... (bc) w2 = w6\n     71: .1234.6... (74) w2 >>= 8\n     72: .1234.6... (73) *(u8 *)(r10 -18) = r2\n     73: .1.34.6... (bc) w2 = w6\n     74: .1234.6... (74) w2 >>= 16\n     75: .1234.6... (6b) *(u16 *)(r10 -20) = r2\n     76: .1.34.6... (73) *(u8 *)(r10 -47) = r4\n     77: .1.3..6... (b4) w2 = 3\n     78: .123..6... (6b) *(u16 *)(r10 -34) = r2\n     79: .1.3..6... (61) r2 = *(u32 *)(r10 -72)\n     80: .123..6... (ae) if w3 < w2 goto pc+1\n     81: .12...6... (bc) w3 = w2\n     82: .1.3..6... (6b) *(u16 *)(r10 -36) = r3\n     83: .1.3..6... (67) r3 <<= 32\n     84: .1.3..6... (18) r2 = 0xffffffff\n     86: .123..6... (4f) r3 |= r2\n     87: .1.3..6... (bf) r4 = r10\n     88: .1.34.6... (07) r4 += -48\n     89: .1.34.6... (18) r2 = 0xffff8ef204204800\n     91: .1234.6... (b4) w5 = 48\n     92: .123456... (85) call bpf_perf_event_output#25\n     93: ......6... (54) w6 &= 255\n     94: ......6... (bc) w0 = w6\n     95: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (b7) r4 = 0                        ; R4=0\n1: (61) r2 = *(u32 *)(r1 +56)         ; R1=ctx() R2=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\n2: (63) *(u32 *)(r10 -56) = r2        ; R2=scalar(id=1,smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) R10=\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 167
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 55,
          "not_applied": 6,
          "requested": 61
        }
      },
      "runner": "cilium",
      "selected_workload": "network_lossy_multi",
      "status": "ok"
    },
    {
      "app": "tetragon/observer",
      "baseline": null,
      "error": "stress_ng_os_io_network workload failed: /usr/bin/stress-ng: option '--bind' is ambiguous; possibilities: '--bind-mount' '--bind-mount-ops' '--binderfs' '--binderfs-opts'",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "tetragon",
      "selected_workload": "stress_ng_os_io_network",
      "status": "error"
    },
    {
      "app": "katran",
      "baseline": {
        "bpf": {
          "479": {
            "avg_ns_per_run": 321.95190852530686,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 479,
            "name": "xdp_root",
            "run_cnt_delta": 35682,
            "run_time_ns_delta": 11487888,
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
            "duration_s": 1.00108101699999,
            "ops_per_sec": 5940.578134047326,
            "ops_total": 5947.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "479": {
            "avg_ns_per_run": 308.92791842475384,
            "bytes_jited": 176,
            "bytes_xlated": 136,
            "id": 479,
            "name": "xdp_root",
            "run_cnt_delta": 36972,
            "run_time_ns_delta": 11421683,
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
            "duration_s": 1.0006393770000273,
            "ops_per_sec": 6158.062676360009,
            "ops_total": 6162.0,
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
      "baseline": null,
      "error": "stress_ng_os_io_network workload failed: /usr/bin/stress-ng: option '--bind' is ambiguous; possibilities: '--bind-mount' '--bind-mount-ops' '--binderfs' '--binderfs-opts'",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "tracee",
      "selected_workload": "stress_ng_os_io_network",
      "status": "error"
    },
    {
      "app": "bpftrace/capable",
      "baseline": {
        "bpf": {
          "666": {
            "avg_ns_per_run": 155.13150655637315,
            "bytes_jited": 769,
            "bytes_xlated": 1360,
            "id": 666,
            "name": "cap_capable",
            "run_cnt_delta": 1234524,
            "run_time_ns_delta": 191513568,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.01653127000003,
            "ops_per_sec": 1473483.447292237,
            "ops_total": 1497842.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [15065] setting to a 1 secs run per stressor\nstress-ng: info:  [15065] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [15065] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [15065] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [15065]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [15065] cap             1260786      1.00      0.24      0.76   1260792.01     1261204.72\nstress-ng: metrc: [15065] eventfd          143350      1.00      0.04      0.68    143324.13      200704.53\nstress-ng: metrc: [15065] get                 959      1.00      0.03      0.13       958.07        5777.28\nstress-ng: metrc: [15065] prctl              2984      1.00      0.59      0.38      2983.54        3055.97\nstress-ng: metrc: [15065] set               89763      1.00      0.14      0.83     89750.89       92564.46\nstress-ng: info:  [15065] skipped: 0\nstress-ng: info:  [15065] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [15065] failed: 0\nstress-ng: info:  [15065] metrics untrustworthy: 0\nstress-ng: info:  [15065] successful run completed in 1.00 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "666": {
            "avg_ns_per_run": 194.70016117650133,
            "bytes_jited": 697,
            "bytes_xlated": 1216,
            "id": 666,
            "name": "cap_capable",
            "run_cnt_delta": 1147810,
            "run_time_ns_delta": 223478792,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0172290259999954,
            "ops_per_sec": 1498654.6402383202,
            "ops_total": 1524475.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [21258] setting to a 1 secs run per stressor\nstress-ng: info:  [21258] dispatching hogs: 1 cap, 1 eventfd, 1 get, 1 prctl, 1 set\nstress-ng: info:  [21258] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [21258] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [21258]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [21258] cap             1298694      1.00      0.29      0.71   1298698.03     1299001.86\nstress-ng: metrc: [21258] eventfd          143129      1.00      0.12      0.59    143060.92      201064.26\nstress-ng: metrc: [21258] get                 989      1.00      0.03      0.13       988.85        6319.65\nstress-ng: metrc: [21258] prctl              3485      1.00      0.57      0.41      3483.79        3534.34\nstress-ng: metrc: [21258] set               78178      1.00      0.12      0.85     78119.00       81072.36\nstress-ng: info:  [21258] skipped: 0\nstress-ng: info:  [21258] passed: 5: cap (1) eventfd (1) get (1) prctl (1) set (1)\nstress-ng: info:  [21258] failed: 0\nstress-ng: info:  [21258] metrics untrustworthy: 0\nstress-ng: info:  [21258] successful run completed in 1.00 secs"
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
          "673": {
            "avg_ns_per_run": 413.7717113316827,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 673,
            "name": "block_io_start",
            "run_cnt_delta": 1374006,
            "run_time_ns_delta": 568524814,
            "type": "tracepoint"
          },
          "674": {
            "avg_ns_per_run": 815.9124256470607,
            "bytes_jited": 931,
            "bytes_xlated": 1576,
            "id": 674,
            "name": "block_io_done",
            "run_cnt_delta": 1374021,
            "run_time_ns_delta": 1121080807,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.365433431000042,
            "ops_per_sec": 342567.6645954431,
            "ops_total": 1838024.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.099400,\n        \"1000\" : 10.851373\n      },\n      \"latency_us\" : {\n        \"2\" : 36.545374,\n        \"4\" : 1.839552,\n        \"10\" : 9.466750,\n        \"20\" : 36.464939,\n        \"50\" : 2.423526,\n        \"100\" : 1.859606,\n        \"250\" : 0.416564,\n        \"500\" : 0.032915,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.000000,\n        \"4\" : 0.000000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "673": {
            "avg_ns_per_run": 431.3846375697659,
            "bytes_jited": 222,
            "bytes_xlated": 408,
            "id": 673,
            "name": "block_io_start",
            "run_cnt_delta": 1418135,
            "run_time_ns_delta": 611761653,
            "type": "tracepoint"
          },
          "674": {
            "avg_ns_per_run": 782.1932369636498,
            "bytes_jited": 883,
            "bytes_xlated": 1480,
            "id": 674,
            "name": "block_io_done",
            "run_cnt_delta": 1418150,
            "run_time_ns_delta": 1109267339,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 5.352217678999978,
            "ops_per_sec": 355271.7983539264,
            "ops_total": 1901492.0,
            "stderr": "",
            "stdout": "        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.089607,\n        \"1000\" : 11.841754\n      },\n      \"latency_us\" : {\n        \"2\" : 35.420299,\n        \"4\" : 1.889102,\n        \"10\" : 10.469678,\n        \"20\" : 36.104339,\n        \"50\" : 2.301587,\n        \"100\" : 1.585575,\n        \"250\" : 0.271555,\n        \"500\" : 0.022507,\n        \"750\" : 0.010000,\n        \"1000\" : 0.010000\n      },\n      \"latency_ms\" : {\n        \"2\" : 0.010000,\n        \"4\" : 0.010000,\n        \"10\" : 0.000000,\n        \"20\" : 0.000000,\n        \"50\" : 0.000000,\n        \"100\" : 0.000000,\n        \"250\" : 0.000000,\n        \"500\" : 0.000000,\n        \"750\" : 0.000000,\n        \"1000\" : 0.000000,\n        \"2000\" : 0.000000,\n        \">=2000\" : 0.000000\n      },\n      \"latency_depth\" : 1,\n      \"latency_target\" : 0,\n      \"latency_percentile\" : 100.000000,\n      \"latency_window\" : 0\n    }\n  ]\n}"
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
          "681": {
            "avg_ns_per_run": 1928.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 681,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1928,
            "type": "perf_event"
          },
          "682": {
            "avg_ns_per_run": 32.87256543011347,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 682,
            "name": "vfs_create",
            "run_cnt_delta": 1565831,
            "run_time_ns_delta": 51472882,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.1119343080000021,
            "ops_per_sec": 2627271.2146588378,
            "ops_total": 2921353.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [6251] setting to a 1 secs run per stressor\nstress-ng: info:  [6251] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [6251] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [6268] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [6256] dentry: 112252 dentries allocated\nstress-ng: metrc: [6251] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [6251]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [6251] access            10615      1.00      0.15      1.68     10582.60        5804.49\nstress-ng: metrc: [6251] chdir                45      1.07      0.08      0.77        41.97          52.98\nstress-ng: metrc: [6251] chmod               153      1.01      0.00      0.03       150.91        4680.76\nstress-ng: metrc: [6251] chown               170      1.01      0.00      0.01       168.05       12637.53\nstress-ng: metrc: [6251] dentry            15416      1.02      0.06      0.44     15064.23       31190.69\nstress-ng: metrc: [6251] dir                8192      1.09      0.09      0.84      7516.84        8850.72\nstress-ng: metrc: [6251] dirmany            9727      1.01      0.03      0.18      9599.11       47189.13\nstress-ng: metrc: [6251] fallocate             2      1.01      0.00      0.00         1.97         434.78\nstress-ng: metrc: [6251] file-ioctl        78356      1.00      0.06      0.76     78211.82       96089.63\nstress-ng: metrc: [6251] filename           4148      1.01      0.02      0.77      4100.01        5244.10\nstress-ng: metrc: [6251] flock           2430701      1.00      0.49      0.53   2425066.63     2386376.44\nstress-ng: metrc: [6251] fpunch             1590      1.01      0.00      0.29      1571.89        5553.85\nstress-ng: metrc: [6251] fstat              2290      1.00      0.12      0.55      2289.93        3426.60\nstress-ng: metrc: [6251] getdent          201932      1.00      0.06      0.94    201928.68      202106.01\nstress-ng: metrc: [6251] hdd               27161      1.01      0.38      0.23     26866.83       44314.46\nstress-ng: metrc: [6251] inotify               2      1.05      0.00      0.00         1.90         686.58\nstress-ng: metrc: [6251] open              15360      1.01      0.03      0.20     15181.08       68595.31\nstress-ng: metrc: [6251] rename              477      1.00      0.00      0.01       476.18       33026.38\nstress-ng: metrc: [6251] touch             66071      1.01      0.08      1.75     65371.71       36193.79\nstress-ng: metrc: [6251] utime             48945      1.00      0.02      0.81     48927.81       58900.55\nstress-ng: info:  [6251] skipped: 0\nstress-ng: info:  [6251] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [6251] failed: 0\nstress-ng: info:  [6251] metrics untrustworthy: 0\nstress-ng: info:  [6251] successful run completed in 1.10 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "681": {
            "avg_ns_per_run": 1972.0,
            "bytes_jited": 362,
            "bytes_xlated": 680,
            "id": 681,
            "name": "1",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1972,
            "type": "perf_event"
          },
          "682": {
            "avg_ns_per_run": 32.49736491543806,
            "bytes_jited": 140,
            "bytes_xlated": 224,
            "id": 682,
            "name": "vfs_create",
            "run_cnt_delta": 1559153,
            "run_time_ns_delta": 50668364,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.138674667000032,
            "ops_per_sec": 2507294.7372420286,
            "ops_total": 2854993.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [24356] setting to a 1 secs run per stressor\nstress-ng: info:  [24356] dispatching hogs: 1 access, 1 chdir, 1 chmod, 1 chown, 1 dentry, 1 dir, 1 dirmany, 1 fallocate, 1 file-ioctl, 1 filename, 1 flock, 1 fpunch, 1 fstat, 1 getdent, 1 hdd, 1 inotify, 1 open, 1 rename, 1 touch, 1 utime\nstress-ng: info:  [24356] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: info:  [24375] open: using a maximum of 1024 file descriptors\nstress-ng: info:  [24361] dentry: 104333 dentries allocated\nstress-ng: metrc: [24356] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [24356]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [24356] access            11165      1.00      0.20      1.49     11153.93        6598.91\nstress-ng: metrc: [24356] chdir                50      1.08      0.08      0.84        46.39          54.60\nstress-ng: metrc: [24356] chmod               107      1.02      0.00      0.02       105.08        4287.55\nstress-ng: metrc: [24356] chown               119      1.02      0.00      0.01       116.86       13382.82\nstress-ng: metrc: [24356] dentry            12288      1.02      0.05      0.38     12067.33       28346.67\nstress-ng: metrc: [24356] dir                8193      1.11      0.02      0.93      7359.90        8679.02\nstress-ng: metrc: [24356] dirmany           11075      1.00      0.01      0.24     11060.87       43606.65\nstress-ng: metrc: [24356] fallocate             1      1.02      0.00      0.01         0.98         147.80\nstress-ng: metrc: [24356] file-ioctl        77531      1.00      0.12      0.73     77527.77       90847.84\nstress-ng: metrc: [24356] filename           3912      1.01      0.05      0.70      3861.22        5169.11\nstress-ng: metrc: [24356] flock           2370598      1.01      0.44      0.67   2339926.21     2135943.27\nstress-ng: metrc: [24356] fpunch             1162      1.02      0.01      0.20      1138.57        5665.72\nstress-ng: metrc: [24356] fstat              2164      1.00      0.17      0.50      2163.79        3211.52\nstress-ng: metrc: [24356] getdent          196770      1.00      0.10      0.90    196548.54      197608.06\nstress-ng: metrc: [24356] hdd               27294      1.02      0.32      0.31     26822.69       43472.17\nstress-ng: metrc: [24356] inotify               2      1.02      0.00      0.00         1.96         756.72\nstress-ng: metrc: [24356] open              16240      1.02      0.02      0.23     15952.43       64819.99\nstress-ng: metrc: [24356] rename              339      1.01      0.00      0.02       334.77       19314.04\nstress-ng: metrc: [24356] touch             67223      1.02      0.06      1.60     66081.08       40557.45\nstress-ng: metrc: [24356] utime             48760      1.00      0.07      0.75     48757.97       58984.85\nstress-ng: info:  [24356] skipped: 0\nstress-ng: info:  [24356] passed: 20: access (1) chdir (1) chmod (1) chown (1) dentry (1) dir (1) dirmany (1) fallocate (1) file-ioctl (1) filename (1) flock (1) fpunch (1) fstat (1) getdent (1) hdd (1) inotify (1) open (1) rename (1) touch (1) utime (1)\nstress-ng: info:  [24356] failed: 0\nstress-ng: info:  [24356] metrics untrustworthy: 0\nstress-ng: info:  [24356] successful run completed in 1.12 secs"
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
          "689": {
            "avg_ns_per_run": 59.53326303789666,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 689,
            "name": "sched_wakeup",
            "run_cnt_delta": 970191,
            "run_time_ns_delta": 57758636,
            "type": "tracepoint"
          },
          "690": {
            "avg_ns_per_run": 157.00933589353107,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 690,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 30206,
            "run_time_ns_delta": 4742624,
            "type": "tracepoint"
          },
          "691": {
            "avg_ns_per_run": 134.69188669969594,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 691,
            "name": "sched_switch",
            "run_cnt_delta": 11338222,
            "run_time_ns_delta": 1527166513,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.0226711359999854,
            "ops_per_sec": 22096294.89337648,
            "ops_total": 22597243.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [31247] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [31247] setting to a 1 secs run per stressor\nstress-ng: info:  [31247] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [31247] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [31247] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [31247]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [31247] clone               733      1.01      0.22      0.91       729.12         651.77\nstress-ng: metrc: [31247] fork               3748      1.00      0.38      0.40      3747.86        4820.15\nstress-ng: metrc: [31247] futex            320270      2.00      0.12      1.13    160080.67      256531.02\nstress-ng: metrc: [31247] sem             1016973      1.00      0.21      0.57   1016935.18     1312213.07\nstress-ng: metrc: [31247] sem-sysv        4171558      1.00      0.19      0.76   4170183.95     4397427.46\nstress-ng: metrc: [31247] switch           576912      1.00      0.08      0.86    576784.80      612522.85\nstress-ng: metrc: [31247] vfork             25428      1.00      0.24      0.33     25427.66       44428.29\nstress-ng: metrc: [31247] yield          16481621      1.01      2.53      6.80  16314412.34     1768361.52\nstress-ng: info:  [31247] skipped: 1: exec (1)\nstress-ng: info:  [31247] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [31247] failed: 0\nstress-ng: info:  [31247] metrics untrustworthy: 0\nstress-ng: info:  [31247] successful run completed in 1.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "689": {
            "avg_ns_per_run": 112.34781299138484,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 689,
            "name": "sched_wakeup",
            "run_cnt_delta": 451530,
            "run_time_ns_delta": 50728408,
            "type": "tracepoint"
          },
          "690": {
            "avg_ns_per_run": 158.10074650673133,
            "bytes_jited": 86,
            "bytes_xlated": 136,
            "id": 690,
            "name": "tracepoint_sched_sched_wakeup_new",
            "run_cnt_delta": 31346,
            "run_time_ns_delta": 4955826,
            "type": "tracepoint"
          },
          "691": {
            "avg_ns_per_run": 130.32663358179587,
            "bytes_jited": 515,
            "bytes_xlated": 896,
            "id": 691,
            "name": "sched_switch",
            "run_cnt_delta": 12781270,
            "run_time_ns_delta": 1665739892,
            "type": "tracepoint"
          }
        },
        "workloads": [
          {
            "duration_s": 1.023949856999991,
            "ops_per_sec": 19866775.566140033,
            "ops_total": 20342582.0,
            "stderr": "",
            "stdout": "stress-ng: info:  [14992] exec stressor must not run as root, skipping the stressor\nstress-ng: info:  [14992] setting to a 1 secs run per stressor\nstress-ng: info:  [14992] dispatching hogs: 1 clone, 1 fork, 1 futex, 1 sem, 1 sem-sysv, 1 switch, 1 vfork, 1 yield\nstress-ng: info:  [14992] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [14992] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [14992]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [14992] clone               738      1.01      0.21      0.85       729.45         692.82\nstress-ng: metrc: [14992] fork               2960      1.00      0.26      0.35      2959.75        4836.66\nstress-ng: metrc: [14992] futex            236888      2.00      0.10      1.13    118430.01      192109.72\nstress-ng: metrc: [14992] sem             1276089      1.00      0.25      0.53   1276060.10     1644624.73\nstress-ng: metrc: [14992] sem-sysv        2675766      1.00      0.27      0.73   2674725.27     2689058.01\nstress-ng: metrc: [14992] switch           205156      1.00      0.08      0.55    205119.86      327915.91\nstress-ng: metrc: [14992] vfork             27460      1.00      0.21      0.38     27452.56       46286.31\nstress-ng: metrc: [14992] yield          15917525      1.01      3.04      6.78  15748813.88     1622309.51\nstress-ng: info:  [14992] skipped: 1: exec (1)\nstress-ng: info:  [14992] passed: 8: clone (1) fork (1) futex (1) sem (1) sem-sysv (1) switch (1) vfork (1) yield (1)\nstress-ng: info:  [14992] failed: 0\nstress-ng: info:  [14992] metrics untrustworthy: 0\nstress-ng: info:  [14992] successful run completed in 1.01 secs"
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
          "699": {
            "avg_ns_per_run": 900.1810995328782,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 699,
            "name": "tcp_set_state",
            "run_cnt_delta": 2783,
            "run_time_ns_delta": 2505204,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.001887288999967,
            "ops_per_sec": 308.4179262404138,
            "ops_total": 309.0,
            "stderr": "",
            "stdout": ""
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "699": {
            "avg_ns_per_run": 955.973674170164,
            "bytes_jited": 2017,
            "bytes_xlated": 3384,
            "id": 699,
            "name": "tcp_set_state",
            "run_cnt_delta": 2621,
            "run_time_ns_delta": 2505607,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 1.001794469999993,
            "ops_per_sec": 290.4787446071668,
            "ops_total": 291.0,
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
      "runner": "bpftrace",
      "selected_workload": "tcp_connect",
      "status": "ok"
    },
    {
      "app": "bpftrace/tcpretrans",
      "baseline": null,
      "error": "network_lossy_multi requires network_device",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "bpftrace",
      "selected_workload": "network_lossy_multi",
      "status": "error"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 19,
    "per_program_geomean": 1.0268933993326241,
    "program_count": 36,
    "wins": 17
  },
  "workload_seconds": 1.0
}
```
